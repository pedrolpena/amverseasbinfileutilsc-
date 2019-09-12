/*
 * WindInstrument.h
 *
 *  Created on: Aug 14, 2019
 *      Author: pena
 */

#ifndef INCLUDE_WINDINSTRUMENT_H_
#define INCLUDE_WINDINSTRUMENT_H_

#include <string>

class WindInstrument {
public:


	static constexpr int _UNCERTIFIED_INSTRUMENT_MPS = 0;
	static constexpr const char *_UNCERTIFIED_INSTRUMENT_MPS_DESCRIPTION = "Uncertified Instruments meters/sec";

	static constexpr int _CERTIFIED_INSTRUMENT_MPS = 1;
	static constexpr const char *_CERTIFIED_INSTRUMENT_MPS_DESCRIPTION = "Certified Instruments meters/sec";

	static constexpr int _UNCERTIFIED_INSTRUMENT_KNOTS = 2;
	static constexpr const char *_UNCERTIFIED_INSTRUMENT_KNOTS_DESCRIPTION = "Uncertified Instruments knots";

	static constexpr int _CERTIFIED_INSTRUMENT_KNOTS = 3;
	static constexpr const char *_CERTIFIED_INSTRUMENT_KNOTS_DESCRIPTION = "Certified Instruments knots";

	static constexpr int _UNCERTIFIED_INSTRUMENT_KPH = 4;
	static constexpr const char *_UNCERTIFIED_INSTRUMENT_KPH_DESCRIPTION = "Uncertified Instruments kilometers/hour";

	static constexpr int _CERTIFIED_INSTRUMENT_KPH = 5;
	static constexpr const char *_CERTIFIED_INSTRUMENT_KPH_DESCRIPTION = "Certified Instruments kilometers/hour";

	static std::string getInstrumentDescription(int code);

	WindInstrument();
	virtual ~WindInstrument();
};

#endif /* INCLUDE_WINDINSTRUMENT_H_ */
