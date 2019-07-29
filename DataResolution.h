/*
 * DataResolution.h
 *
 *  Created on: Jul 19, 2019
 *      Author: pedro
 */

#ifndef DATARESOLUTION_H_
#define DATARESOLUTION_H_
#include <string>

class DataResolution {
public:
static constexpr int         FULL_RESOLUTION = 1;
static constexpr const char* FULL_RESOLUTION_DESCRIPTION = "Full Resolution";
static constexpr int         METER_RESOLUTION = 2;
static constexpr const char* METER_RESOLUTION_DESCRIPTION = "2 Meter Resolution";
static constexpr int         INFLECTION_POINTS = 3;
static constexpr const char* INFLECTION_POINTS_DESCRIPTION = "Inflection Points";
	DataResolution();
	virtual ~DataResolution();
	static std::string getDataResolutionDescription(int);
};

#endif /* DATARESOLUTION_H_ */
