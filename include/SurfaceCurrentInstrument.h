/*
 * SurfaceCurrentInstrument.h
 *
 *  Created on: Aug 14, 2019
 *      Author: pena
 */

#ifndef INCLUDE_SURFACECURRENTINSTRUMENT_H_
#define INCLUDE_SURFACECURRENTINSTRUMENT_H_

#include <string>

class SurfaceCurrentInstrument {
public:

	static constexpr int _ADCP = 1;
	static constexpr const char *_ADCP_DESCRIPTION =
			"ADCP Acoustic Doppler Current Profiler";

	static constexpr int _GEK = 2;
	static constexpr const char *_GEK_DESCRIPTION =
			"GEK Geomagnetic ElectroKinetograph";

	static constexpr int _DRIFT_FIX_3_6 = 3;
	static constexpr const char *_DRIFT_FIX_3_6_DESCRIPTION =
			"Ship's set and drift determined by fixes 3-6 hours apart";

	static constexpr int _DRIFT_FIX_6_12 = 4;
	static constexpr const char *_DRIFT_FIX_6_12_DESCRIPTION =
			"Ship's set and drift determined by fixes > 6 hours but < 12 hours apart";

	static constexpr int _DRIFT_OF_BUOY = 5;
	static constexpr const char *_DRIFT_OF_BUOY_DESCRIPTION = "Drift of buoy";

	static std::string getInstrumentDescription(int code);

	SurfaceCurrentInstrument();
	virtual ~SurfaceCurrentInstrument();
};

#endif /* INCLUDE_SURFACECURRENTINSTRUMENT_H_ */
