/*
 * WindInstrument.cpp
 *
 *  Created on: Aug 14, 2019
 *      Author: pena
 */

#include "WindInstrument.h"


	 constexpr int _UNCERTIFIED_INSTRUMENT_MPS = 0;
	 constexpr const char *_UNCERTIFIED_INSTRUMENT_MPS_DESCRIPTION = "Uncertified Instruments meters/sec";

	 constexpr int _CERTIFIED_INSTRUMENT_MPS = 1;
	 constexpr const char *_CERTIFIED_INSTRUMENT_MPS_DESCRIPTION = "Certified Instruments meters/sec";

	 constexpr int _UNCERTIFIED_INSTRUMENT_KNOTS = 2;
	 constexpr const char *_UNCERTIFIED_INSTRUMENT_KNOTS_DESCRIPTION = "Uncertified Instruments knots";

	 constexpr int _CERTIFIED_INSTRUMENT_KNOTS = 3;
	 constexpr const char *_CERTIFIED_INSTRUMENT_KNOTS_DESCRIPTION = "Certified Instruments knots";

	 constexpr int _UNCERTIFIED_INSTRUMENT_KPH = 4;
	 constexpr const char *_UNCERTIFIED_INSTRUMENT_KPH_DESCRIPTION = "Uncertified Instruments kilometers/hour";

	 constexpr int _CERTIFIED_INSTRUMENT_KPH = 5;
	 constexpr const char *_CERTIFIED_INSTRUMENT_KPH_DESCRIPTION = "Certified Instruments kilometers/hour";

WindInstrument::WindInstrument() {
	// TODO Auto-generated constructor stub

}

std::string WindInstrument::getInstrumentDescription(int code) {

    const char* description =  "Missing";
    switch (code) {

    case _UNCERTIFIED_INSTRUMENT_MPS:
        description =  _UNCERTIFIED_INSTRUMENT_MPS_DESCRIPTION;
        break;

    case _CERTIFIED_INSTRUMENT_MPS:
        description =  _CERTIFIED_INSTRUMENT_MPS_DESCRIPTION;
        break;

    case _UNCERTIFIED_INSTRUMENT_KNOTS:
        description =  _UNCERTIFIED_INSTRUMENT_KNOTS_DESCRIPTION;
        break;

    case _CERTIFIED_INSTRUMENT_KNOTS:
        description =  _CERTIFIED_INSTRUMENT_KNOTS_DESCRIPTION;
        break;

    case _UNCERTIFIED_INSTRUMENT_KPH:
        description =  _UNCERTIFIED_INSTRUMENT_KPH_DESCRIPTION;
        break;

    case _CERTIFIED_INSTRUMENT_KPH:
        description =  _CERTIFIED_INSTRUMENT_KPH_DESCRIPTION;
        break;

    }

return description;

}

WindInstrument::~WindInstrument() {
	// TODO Auto-generated destructor stub
}

