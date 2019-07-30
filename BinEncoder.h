/*
 * BinEncoder.h
 *
 *  Created on: Jul 27, 2019
 *      Author: pedro
 */
#include "XBTProfile.h"
#include "bitvector.h"
#include "XBTProfileDataRanges.h"
#include "MessageType.h"
#include <array>
#include <cmath>

#ifndef BINENCODER_H_
#define BINENCODER_H_

class BinEncoder {
public:
	BinEncoder();
	BinEncoder(XBTProfile &xBTProfile);
	virtual ~BinEncoder();
	stdex::bitvector bits; //holds bits from file
	int newMessageType;
	stdex::bitvector changeEndian(stdex::bitvector);
	void setBitWithinBits(stdex::bitvector, stdex::bitvector,int);

	void integerToBits(stdex::bitvector , int, std::array<int,2>);
	void stringToBits(stdex::bitvector, std::string,std::array<int,2>);
	void encodeCommentBlocks(stdex::bitvector,std::string,std::array<int,2>,int);
	void encodeProfile(XBTProfile &xBTProfile);


};

#endif /* BINENCODER_H_ */
