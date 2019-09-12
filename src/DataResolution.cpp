/*
 * DataResolution.cpp
 *
 *  Created on: Jul 19, 2019
 *      Author: pedro
 */

#include "DataResolution.h"

DataResolution::DataResolution() {
	// TODO Auto-generated constructor stub

}

DataResolution::~DataResolution() {
	// TODO Auto-generated destructor stub
}

std::string DataResolution::getDataResolutionDescription(int dataType) {

    const char* description = "Unknown";
    switch (dataType) {
        case FULL_RESOLUTION:
            description = FULL_RESOLUTION_DESCRIPTION;
            break;
        case METER_RESOLUTION:
            description = METER_RESOLUTION_DESCRIPTION;
            break;
        case INFLECTION_POINTS:
            description = INFLECTION_POINTS_DESCRIPTION;
            break;
    }// end switch

    return std::string(description);
}
