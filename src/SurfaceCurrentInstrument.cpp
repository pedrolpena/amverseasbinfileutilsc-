/*
 * SurfaceCurrentInstrument.cpp
 *
 *  Created on: Aug 14, 2019
 *      Author: pena
 *
 *From https://www.nodc.noaa.gov/GTSPP/document/codetbls/wmocodes/table2266.html
 */

#include "SurfaceCurrentInstrument.h"


constexpr int _ADCP = 1;
constexpr const char *_ADCP_DESCRIPTION =
		"ADCP Acoustic Doppler Current Profiler";

constexpr int _GEK = 2;
constexpr const char *_GEK_DESCRIPTION = "GEK Geomagnetic ElectroKinetograph";

constexpr int _DRIFT_FIX_3_6 = 3;
constexpr const char *_DRIFT_FIX_3_6_DESCRIPTION =
		"Ship's set and drift determined by fixes 3-6 hours apart";

constexpr int _DRIFT_FIX_6_12 = 4;
constexpr const char *_DRIFT_FIX_6_12_DESCRIPTION =
		"Ship's set and drift determined by fixes > 6 hours but < 12 hours apart";

constexpr int _DRIFT_OF_BUOY = 5;
constexpr const char *_DRIFT_OF_BUOY_DESCRIPTION = "Drift of buoy";



SurfaceCurrentInstrument::SurfaceCurrentInstrument() {


}

std::string SurfaceCurrentInstrument::getInstrumentDescription(int code) {

    const char* description =  "Missing";
    switch (code) {

    case _ADCP:
        description =  _ADCP_DESCRIPTION;
        break;

    case _GEK:
        description =  _GEK_DESCRIPTION;
        break;

    case _DRIFT_FIX_3_6:
        description =  _DRIFT_FIX_3_6_DESCRIPTION;
        break;

    case _DRIFT_FIX_6_12:
        description =  _DRIFT_FIX_6_12_DESCRIPTION;
        break;

    case _DRIFT_OF_BUOY:
        description =  _DRIFT_OF_BUOY_DESCRIPTION;
        break;
    }

return description;
}



SurfaceCurrentInstrument::~SurfaceCurrentInstrument() {

}

