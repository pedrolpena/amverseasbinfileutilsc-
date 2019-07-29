/*-
 * Copyright (c) 2013 Zhihao Yuan.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef _BITVECTOR_H
#define _BITVECTOR_H 1

#include "utility.h"
#include "__aux.h"
#include <climits>
#include <stdexcept>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>

namespace stdex {

template <typename Allocator>
struct basic_bitvector
{
	typedef Allocator allocator_type;

private:
	template <typename>
	friend struct basic_bitvector;

	friend struct std::hash<basic_bitvector>;

	typedef std::allocator_traits<allocator_type> _alloc_traits;
	typedef typename _alloc_traits::value_type _block_type;
	static_assert(std::is_unsigned<_block_type>(),
	    "underlying type must be unsigned");

	typedef _block_type* _block_iterator;
	typedef _block_type const* _block_const_iterator;

	struct _blocks
	{
		_block_type* p;
		std::size_t cap;
	};

	static constexpr auto _bits_per_block =
		std::numeric_limits<_block_type>::digits;

	template <int N = _bits_per_block>
	static constexpr std::size_t count_to_bits(std::size_t n)
	{
		return n * N;
	}

	template <int N = _bits_per_block>
	static constexpr std::size_t bits_to_count(std::size_t n)
	{
		return (n + (N - 1)) / N;
	}

	template <int N = _bits_per_block>
	static constexpr std::size_t block_index(std::size_t n)
	{
		return n / N;
	}

	template <int N = _bits_per_block>
	static constexpr std::size_t bit_index(std::size_t n)
	{
		return n % N;
	}

	static constexpr _block_type bit_mask(std::size_t n)
	{
		return _block_type(1) << bit_index(n);
	}

	static constexpr auto _bits_internal =
		count_to_bits<CHAR_BIT>(sizeof(_blocks));
	static constexpr auto _blocks_internal =
		bits_to_count(_bits_internal);
	static constexpr auto _bits_in_use = std::size_t(1) <<
		(std::numeric_limits<std::size_t>::digits - 1);

	using _bits = _block_type[_blocks_internal];
	static_assert(sizeof(_bits) == sizeof(_blocks),
	    "unsupported representation");

	using _zeros = std::integral_constant<_block_type, 0>;
	using _ones = std::integral_constant<_block_type, _block_type(~0)>;

public:

	struct reference
	{
	private:
		typedef typename basic_bitvector::_block_type& _bref_t;
		friend basic_bitvector;

		reference(_bref_t loc, std::size_t mask) :
			loc_(loc),
			mask_(mask)
		{}

	public:
		reference& operator=(bool value) noexcept
		{
			if (value)
				loc_ |= mask_;
			else
				loc_ &= ~mask_;

			return *this;
		}

		reference& operator=(reference other) noexcept
		{
			return (*this) = static_cast<bool>(other);
		}

		operator bool() const noexcept
		{
			return loc_ & mask_;
		}

		bool operator~() const noexcept
		{
			return !(*this);
		}

		reference& flip() noexcept
		{
			loc_ ^= mask_;
			return *this;
		}

	private:
		_bref_t loc_;
		std::size_t mask_;
	};

#define size_	sz_alloc_.first()
#define alloc_	sz_alloc_.second()
#define cap_	st_.blocks.cap
#define p_	st_.blocks.p
#define bits_	st_.bits

	basic_bitvector() noexcept(
	    std::is_nothrow_default_constructible<allocator_type>()) :
		sz_alloc_(_bits_in_use)
	{}

	explicit basic_bitvector(allocator_type const& a) :
		sz_alloc_(_bits_in_use, a)
	{}

	explicit basic_bitvector(std::size_t n,
	    allocator_type const& a = allocator_type()) :
		sz_alloc_(_bits_in_use, a)
	{
		init_to_hold(n);
		size_ ^= n;

		reset();
	}

	basic_bitvector(std::size_t n, bool const& value,
	    allocator_type const& a = allocator_type()) :
		sz_alloc_(_bits_in_use, a)
	{
		init_to_hold(n);
		size_ ^= n;

		assign_to(value);
	}

	basic_bitvector(basic_bitvector const& v) :
		basic_bitvector(v, _alloc_traits::
		    select_on_container_copy_construction(v.alloc_))
	{}

	basic_bitvector(basic_bitvector const& v, allocator_type const& a) :
		sz_alloc_(v.size_, a)
	{
		// internal -> internal
		if (v.using_bits())
			st_ = v.st_;

		// heap -> internal
		else if (v.size() <= _bits_internal)
		{
			std::copy_n(v.p_, _blocks_internal, bits_);
			size_ ^= _bits_in_use;
		}

		// heap -> shrunk heap
		else
		{
			allocate_preferred(v.size());
			copy_to_heap(v);
		}
	}

	template <typename Alloc>
	basic_bitvector(basic_bitvector<Alloc> const& v) :
		basic_bitvector(v, static_cast<allocator_type>(v.alloc_))
	{}

	template <typename Alloc>
	basic_bitvector(basic_bitvector<Alloc> const& v,
	    allocator_type const& a,
	    typename std::enable_if<
	    same_allocator<Allocator, Alloc>::value>::type* = 0) :
		sz_alloc_(_bits_in_use, a)
	{
		auto sz = v.size();

		init_to_hold(sz);
		size_ ^= sz;

		std::memcpy(begin(), v.begin(), bits_to_count<CHAR_BIT>(sz));
	}

	basic_bitvector(basic_bitvector&& v) noexcept(
	    std::is_nothrow_move_constructible<allocator_type>()) :
		st_(v.st_),
		sz_alloc_(std::move(v.sz_alloc_))
	{
		// minimal change to prevent deallocation
		v.size_ = _bits_in_use;
	}

	basic_bitvector(basic_bitvector&& v, allocator_type const& a) :
		sz_alloc_(v.size_, a)
	{
		// exchangeable, or internal -> internal
		if (alloc_ == v.alloc_ or v.using_bits())
		{
			st_ = v.st_;
			// minimal change to prevent deallocation
			v.size_ = _bits_in_use;
		}

		// heap -> internal
		else if (v.size() <= _bits_internal)
		{
			std::copy_n(v.p_, _blocks_internal, bits_);
			size_ ^= _bits_in_use;
		}

		// heap -> heap
		else
		{
			allocate_preferred(v.size());
			copy_to_heap(v);
		}
	}

	template <typename charT, typename traits, typename _Allocator>
	explicit basic_bitvector(std::basic_string<charT, traits, _Allocator>
	    const& str,
	    typename std::basic_string<charT, traits, _Allocator>::
	    size_type pos = 0,
	    typename std::basic_string<charT, traits, _Allocator>::
	    size_type n = (std::basic_string<charT, traits, _Allocator>::npos),
	    charT zero = charT('0'),
	    charT one = charT('1')) :
		basic_bitvector(str, {}, pos, n, zero, one)
	{}

	template <typename charT>
	explicit basic_bitvector(charT const* str,
	    typename std::basic_string<charT>::
	    size_type n = (std::basic_string<charT>::npos),
	    charT zero = charT('0'),
	    charT one = charT('1')) :
		basic_bitvector(str, {}, n, zero, one)
	{}

	template <typename charT, typename traits, typename _Allocator>
	explicit basic_bitvector(std::basic_string<charT, traits, _Allocator>
	    const& str,
	    allocator_type const& a,
	    typename std::basic_string<charT, traits, _Allocator>::
	    size_type pos = 0,
	    typename std::basic_string<charT, traits, _Allocator>::
	    size_type n = (std::basic_string<charT, traits, _Allocator>::npos),
	    charT zero = charT('0'),
	    charT one = charT('1')) :
		sz_alloc_(_bits_in_use, a)
	{
		if (pos > str.size())
			throw std::out_of_range(
			    "basic_bitvector::basic_bitvector");

		auto it = std::begin(str) + pos;
		auto sz = std::min(n, str.size() - pos);

		from_string<traits>(it, sz, zero, one);
	}

	template <typename charT>
	explicit basic_bitvector(charT const* str,
	    allocator_type const& a,
	    typename std::basic_string<charT>::
	    size_type n = (std::basic_string<charT>::npos),
	    charT zero = charT('0'),
	    charT one = charT('1')) :
		sz_alloc_(_bits_in_use, a)
	{
		using traits = typename std::basic_string<charT>::traits_type;
		auto sz = std::min(n, traits::length(str));

		from_string<traits>(str, sz, zero, one);
	}

	~basic_bitvector() noexcept
	{
		if (not using_bits())
			deallocate();
	}

	// WIP: N2525
	basic_bitvector& operator=(basic_bitvector v)
	{
		swap(v);
		return *this;
	}

	void assign(std::size_t n, bool const& value)
	{
		expand_to_hold(n);
		set_size(n);

		assign_to(value);
	}

	allocator_type get_allocator() const noexcept
	{
		return alloc_;
	}

	template <typename Alloc>
	bool operator==(basic_bitvector<Alloc> const& rhs) const
	{
		if (size() != rhs.size())
			return false;
		else
			return equals(rhs);
	}

	template <typename Alloc>
	bool operator!=(basic_bitvector<Alloc> const& rhs) const
	{
		return !(*this == rhs);
	}

	reference operator[](std::size_t pos)
	{
		return { begin()[block_index(pos)], bit_mask(pos) };
	}

	bool operator[](std::size_t pos) const
	{
		return begin()[block_index(pos)] & bit_mask(pos);
	}

	bool test(std::size_t pos) const
	{
		if (pos >= size())
			throw std::out_of_range("basic_bitvector::test");

		return (*this)[pos];
	}

	bool all() const noexcept
	{
		bool r = std::none_of(begin(), filled_end(),
		    [](_block_type v) -> bool
		    {
			return static_cast<_block_type>(~v);
		    });

		if (!r)
			return false;
		else
			return not has_incomplete_block()
				or !dezeroed_last_block();
	}

	bool any() const noexcept
	{
		bool r = std::any_of(begin(), filled_end(),
		    [](_block_type v) -> bool
		    {
			return v;
		    });

		if (r)
			return true;
		else
			return has_incomplete_block() and zeroed_last_block();
	}

	bool none() const noexcept
	{
		return not any();
	}

	std::size_t count() const noexcept
	{
		auto n = std::accumulate(begin(), filled_end(),
		    std::size_t(0),
		    [](std::size_t n, _block_type v)
		    {
			return n + stdex::aux::popcount(v);
		    });

		if (has_incomplete_block())
			return n + stdex::aux::popcount(zeroed_last_block());
		else
			return n;
	}

	bool empty() const noexcept
	{
		return size() == 0;
	}

	std::size_t size() const noexcept
	{
		return actual_size(size_);
	}

	std::size_t max_size() const noexcept
	{
		auto amax = _alloc_traits::max_size(alloc_);
		auto hmax = actual_size(std::numeric_limits<
		    std::size_t>::max());

		if (hmax / _bits_per_block <= amax)
			return hmax;
		else
			return count_to_bits(amax);
	}

	void shrink_to_fit() /* noexcept */
	{
		if (aux::pow2_roundup(size()) < capacity())
			swap_to_fit();
	}

	template <typename Alloc>
	basic_bitvector& operator&=(basic_bitvector<Alloc> const& v)
	{
		if (size() != v.size())
			throw std::invalid_argument(
			    "basic_bitvector::operator&=");

		return transformed_by(bit_and(), v);
	}

	template <typename Alloc>
	basic_bitvector& operator|=(basic_bitvector<Alloc> const& v)
	{
		if (size() != v.size())
			throw std::invalid_argument(
			    "basic_bitvector::operator|=");

		return transformed_by(bit_or(), v);
	}

	template <typename Alloc>
	basic_bitvector& operator^=(basic_bitvector<Alloc> const& v)
	{
		if (size() != v.size())
			throw std::invalid_argument(
			    "basic_bitvector::operator^=");

		return transformed_by(bit_xor(), v);
	}

	template <typename Alloc>
	basic_bitvector operator&(basic_bitvector<Alloc> const& rhs) const
	{
		basic_bitvector v(*this);
		v &= rhs;
		return v;
	}

	template <typename Alloc>
	basic_bitvector operator|(basic_bitvector<Alloc> const& rhs) const
	{
		basic_bitvector v(*this);
		v |= rhs;
		return v;
	}

	template <typename Alloc>
	basic_bitvector operator^(basic_bitvector<Alloc> const& rhs) const
	{
		basic_bitvector v(*this);
		v ^= rhs;
		return v;
	}

	basic_bitvector operator~() const
	{
		basic_bitvector v(*this);
		v.flip();
		return v;
	}

	basic_bitvector& operator<<=(std::size_t pos)
	{
		if (pos >= size())
			reset();
		else
			shift_left(begin(), end(), pos);

		return *this;
	}

	basic_bitvector& operator>>=(std::size_t pos)
	{
		if (pos >= size())
			reset();
		else
		{
			if (has_incomplete_block())
				last_block() = zeroed_last_block();

			shift_right(begin(), end(), pos);
		}

		return *this;
	}

	basic_bitvector operator<<(std::size_t pos) const
	{
		basic_bitvector v(*this);
		v <<= pos;
		return v;
	}

	basic_bitvector operator>>(std::size_t pos) const
	{
		basic_bitvector v(*this);
		v >>= pos;
		return v;
	}

	basic_bitvector& set() noexcept
	{
		std::fill(begin(), end(), _ones());
		return *this;
	}

	basic_bitvector& set(std::size_t pos, bool value = true)
	{
		if (pos >= size())
			throw std::out_of_range("basic_bitvector::set");

		set_bit_to(pos, value);
		return *this;
	}

	basic_bitvector& reset() noexcept
	{
		std::fill(begin(), end(), _zeros());
		return *this;
	}

	basic_bitvector& reset(std::size_t pos)
	{
		if (pos >= size())
			throw std::out_of_range("basic_bitvector::reset");

		unset_bit(pos);
		return *this;
	}

	basic_bitvector& flip() noexcept
	{
		std::transform(begin(), end(),
		    begin(),
		    [](_block_type v)
		    {
			return ~v;
		    });

		return *this;
	}

	basic_bitvector& flip(std::size_t pos)
	{
		if (pos >= size())
			throw std::out_of_range("basic_bitvector::flip");

		flip_bit(pos);
		return *this;
	}

	void clear() noexcept
	{
		size_ &= _bits_in_use;
	}

	void push_back(bool value)
	{
		auto i = size();

		expand_to_hold(i + 1);
		set_bit_to(i, value);
		++size_;
	}

	void pop_back()
	{
		--size_;
	}

	void resize(std::size_t n, bool value = false)
	{
		auto sz = size();
		auto oldn = bits_to_count(sz);
		auto newn = bits_to_count(n);

		expand_to_hold(n);
		if (has_incomplete_block() and sz < n)
			last_block() = value ?
				oned_last_block() :
				zeroed_last_block();

		set_size(n);
		if (oldn < newn)
			std::fill(begin() + oldn, end(),
			    value ? _ones() : _zeros());
	}

	void swap(basic_bitvector& v) noexcept(
	    is_nothrow_swappable<allocator_type>())
	{
		using std::swap;

		swap(alloc_, v.alloc_);
		swap(size_, v.size_);
		swap(st_, v.st_);
	}

	template <typename charT = char,
		  typename traits = std::char_traits<charT>,
		  typename _Allocator = std::allocator<charT>>
	std::basic_string<charT, traits, _Allocator>
	to_string(charT zero = charT('0'), charT one = charT('1')) const
	{
		std::basic_string<charT, traits, _Allocator> s(size(), zero);
		auto it = s.begin();

		if (has_incomplete_block())
		{
			auto extra = extra_size();
			aux::fill_bit1_upto(extra, last_block(), it, one);
			it += extra;
		}

		std::for_each(reverser(filled_end()), reverser(begin()),
		    [&](_block_type v)
		    {
			aux::fill_bit1(v, it, one);
			it += _bits_per_block;
		    });

		return s;
	}

	unsigned long to_ulong() const
	{
		if (size() > std::numeric_limits<unsigned long>::digits)
			throw std::overflow_error("basic_bitvector::to_ulong");

		return as_integral<unsigned long>();
	}

	unsigned long long to_ullong() const
	{
		if (size() > std::numeric_limits<unsigned long long>::digits)
			throw std::overflow_error("basic_bitvector::to_ullong");

		return as_integral<unsigned long long>();
	}

private:
	void set_bit_to(std::size_t pos, bool value)
	{
		if (value)
			set_bit(pos);
		else
			unset_bit(pos);
	}

	void set_bit(std::size_t pos)
	{
		begin()[block_index(pos)] |= bit_mask(pos);
	}

	void unset_bit(std::size_t pos)
	{
		begin()[block_index(pos)] &= ~bit_mask(pos);
	}

	void flip_bit(std::size_t pos)
	{
		begin()[block_index(pos)] ^= bit_mask(pos);
	}

	void assign_to(bool value)
	{
		if (value)
			set();
		else
			reset();
	}

	bool has_incomplete_block() const
	{
		return extra_size() != 0;
	}

	bool has_incomplete_byte() const
	{
		return extra_size<CHAR_BIT>() != 0;
	}

	template <int N = _bits_per_block>
	std::size_t extra_size() const
	{
		return bit_index<N>(size());
	}

	_block_type& last_block()
	{
		return *filled_end();
	}

	_block_type last_block() const
	{
		return *filled_end();
	}

	_block_type zeroed_last_block() const
	{
		return last_block() & extra_mask();
	}

	_block_type dezeroed_last_block() const
	{
		return ~last_block() & extra_mask();
	}

	_block_type oned_last_block() const
	{
		return last_block() | ~extra_mask();
	}

	_block_type extra_mask() const
	{
		return _ones() >> (_bits_per_block - extra_size());
	}

	unsigned char zeroed_last_byte() const
	{
		return begin_of_bytes()[block_index<CHAR_BIT>(size())] &
		    (UCHAR_MAX >> (CHAR_BIT - extra_size<CHAR_BIT>()));
	}

	bool using_bits() const
	{
		return size_ & _bits_in_use;
	}

	std::size_t capacity() const
	{
		if (using_bits())
			return _bits_internal;
		else
			return count_to_bits(cap_);
	}

	void expand_to_hold(std::size_t sz)
	{
		if (sz > capacity()) {
			if (sz > max_size())
				throw std::length_error("bitvector");

			basic_bitvector v(alloc_);
			v.allocate_preferred(sz);
			v.size_ = size();
			v.copy_to_heap(*this);
			swap(v);
		}
	}

	void init_to_hold(std::size_t sz)
	{
		if (sz > _bits_internal) {
			if (sz > max_size())
				throw std::length_error("bitvector");

			allocate_preferred(sz);
			size_ = 0;
		}
	}

	void set_size(std::size_t sz)
	{
		size_ = (size_ & _bits_in_use) ^ sz;
	}

	void copy_to_heap(basic_bitvector const& v)
	{
		std::copy(v.begin(), v.end(), p_);
	}

	void init_after(std::size_t sz)
	{
		auto n = bits_to_count(sz);
		std::fill_n(p_ + n, cap_ - n, _zeros());
	}

	void swap_to_fit()
	try
	{
		basic_bitvector v(*this);
		swap(v);
	}
	catch (...)
	{
	}

	_block_const_iterator begin() const
	{
		return using_bits() ? bits_ : p_;
	}

	_block_const_iterator filled_end() const
	{
		return begin() + block_index(size());
	}

	_block_const_iterator end() const
	{
		return begin() + bits_to_count(size());
	}

	_block_iterator begin()
	{
		return using_bits() ? bits_ : p_;
	}

	_block_iterator filled_end()
	{
		return begin() + block_index(size());
	}

	_block_iterator end()
	{
		return begin() + bits_to_count(size());
	}

	unsigned char* begin_of_bytes()
	{
		return reinterpret_cast<unsigned char *>(begin());
	}

	unsigned char const* begin_of_bytes() const
	{
		return reinterpret_cast<unsigned char const*>(begin());
	}

	void allocate(std::size_t sz)
	{
		auto n = bits_to_count(sz);
		p_ = _alloc_traits::allocate(alloc_, n);
		cap_ = n;
	}

	void allocate_preferred(std::size_t sz)
	{
		allocate(aux::pow2_roundup(sz));
		init_after(sz);
	}

	void deallocate()
	{
		_alloc_traits::deallocate(alloc_, p_, cap_);
	}

	template <typename traits,
		  typename Iter, typename Size, typename charT>
	void from_string(Iter it, Size sz, charT zero, charT one)
	{
		if (not std::all_of(it, it + sz,
		    [=](charT c)
		    {
			return traits::eq(c, zero) or traits::eq(c, one);
		    }))
			throw std::invalid_argument(
			    "basic_bitvector::basic_bitvector");

		init_to_hold(sz);
		size_ ^= sz;

		auto bytes = reverser(begin_of_bytes() +
		    bits_to_count<CHAR_BIT>(sz));

		auto is_one = [=](charT c)
		    {
			return traits::eq(c, one);
		    };

		if (has_incomplete_byte())
		{
			auto extra = extra_size<CHAR_BIT>();
			*bytes = aux::parse_byte(it, it + extra, is_one);
			++bytes;
			it += extra;
		}

		std::generate_n(bytes, block_index<CHAR_BIT>(sz),
		    [&]
		    {
			auto byte = aux::parse_byte(it, is_one);
			it += CHAR_BIT;
			return byte;
		    });
	}

	template <typename R>
	R as_integral() const
	{
		return as_integral<R>(std::integral_constant<bool,
		    std::is_convertible<_block_type, R>()
		    and sizeof(_block_type) >= sizeof(R)>());
	}

	template <typename R>
	R as_integral(std::true_type) const
	{
		return zeroed_last_block();
	}

	template <typename R>
	R as_integral(std::false_type) const
	{
		auto r =
		    std::accumulate(reverser(filled_end()), reverser(begin()),
		    has_incomplete_block() ? R(zeroed_last_block()) : R(0),
		    [](R r, _block_type v)
		    {
			return (r << _bits_per_block) ^ v;
		    });

		return r;
	}

	template <typename _Allocator>
	auto equals(basic_bitvector<_Allocator> const& rhs) const
		-> typename std::enable_if<
		same_allocator<Allocator, _Allocator>::value, bool>::type
	{
		using Block = typename basic_bitvector<_Allocator>::_block_type;

		return equals(rhs, std::integral_constant<bool,
		    std::is_same<_block_type, Block>::value>());
	}

	template <typename _Allocator>
	bool equals(basic_bitvector<_Allocator> const& rhs,
	    std::true_type) const
	{
		auto r = std::equal(begin(), filled_end(), rhs.begin());

		if (has_incomplete_block())
			return r and (zeroed_last_block() ==
			    rhs.zeroed_last_block());
		else
			return r;
	}

	template <typename _Allocator>
	bool equals(basic_bitvector<_Allocator> const& rhs,
	    std::false_type) const
	{
		auto r = !std::memcmp(begin(), rhs.begin(),
		    block_index<CHAR_BIT>(size()));

		if (has_incomplete_byte())
			return r and (zeroed_last_byte() ==
			    rhs.zeroed_last_byte());
		else
			return r;
	}

	template <typename BinaryOperation, typename _Allocator>
	auto transformed_by(BinaryOperation f,
	    basic_bitvector<_Allocator> const& v)
		-> typename std::enable_if<
		same_allocator<Allocator, _Allocator>::value,
		basic_bitvector&>::type
	{
		using Block = typename basic_bitvector<_Allocator>::_block_type;

		transformed_by(f, v, std::integral_constant<bool,
		    std::is_same<_block_type, Block>::value>());

		return *this;
	}

	template <typename BinaryOperation, typename _Allocator>
	void transformed_by(BinaryOperation f,
	    basic_bitvector<_Allocator> const& v,
	    std::true_type)
	{
		std::transform(begin(), end(), v.begin(), begin(), f);
	}

	template <typename BinaryOperation, typename _Allocator>
	void transformed_by(BinaryOperation f,
	    basic_bitvector<_Allocator> const& v,
	    std::false_type)
	{
		auto it = begin_of_bytes();

		std::transform(it, it + bits_to_count<CHAR_BIT>(size()),
		    v.begin_of_bytes(), it, f);
	}

	static void shift_left(_block_iterator first, _block_iterator last,
	    std::size_t pos)
	{
		auto off = pos % _bits_per_block;
		auto diff = _bits_per_block - off;
		auto wipe = pos / _bits_per_block;
		auto nfirst = first + wipe;
		auto nlast = last - wipe;

		if (diff == _bits_per_block)
			std::copy_backward(first, nlast, last);
		else
			backward_difference(first, nlast, last,
			    [=](_block_type cur, _block_type prev)
			    {
				return (cur << off) ^ (prev >> diff);
			    });

		std::fill(first, nfirst, _zeros());
	}

	static void shift_right(_block_iterator first, _block_iterator last,
	    std::size_t pos)
	{
		auto off = pos % _bits_per_block;
		auto diff = _bits_per_block - off;
		auto wipe = pos / _bits_per_block;
		auto nfirst = first + wipe;
		auto nlast = last - wipe;

		if (diff == _bits_per_block)
			std::copy(nfirst, last, first);
		else
			backward_difference(reverser(last), reverser(nfirst),
			    reverser(first),
			    [=](_block_type cur, _block_type prev)
			    {
				return (cur >> off) ^ (prev << diff);
			    });

		std::fill(nlast, last, _zeros());
	}

	struct bit_and {
	template <typename T>
	T operator()(T l, T r) { return l & r; }
	};

	struct bit_or {
	template <typename T>
	T operator()(T l, T r) { return l | r; }
	};

	struct bit_xor {
	template <typename T>
	T operator()(T l, T r) { return l ^ r; }
	};

#undef size_
#undef alloc_
#undef cap_
#undef p_
#undef bits_

	static std::size_t actual_size(std::size_t n)
	{
		return n & ~_bits_in_use;
	}

	union _ut
	{
		_blocks blocks;
		_bits bits;

		_ut() : bits() {}
	} st_;
	compressed_pair<std::size_t, allocator_type> sz_alloc_;
};

template <typename Allocator>
inline void swap(basic_bitvector<Allocator>& a, basic_bitvector<Allocator>& b)
	noexcept(noexcept(a.swap(b)))
{
	a.swap(b);
}

typedef basic_bitvector<std::allocator<unsigned long>> bitvector;

}

namespace std {

template <class Allocator>
struct hash<stdex::basic_bitvector<Allocator>>
	: unary_function<stdex::basic_bitvector<Allocator>, size_t>
{
	size_t operator()(stdex::basic_bitvector<Allocator> const& v) const
		noexcept
	{
		return v.sz_alloc_.first();
	}
};

}

#endif
