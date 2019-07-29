/*
 * DataQuality.cpp
 *
 *  Created on: Jul 19, 2019
 *      Author: pedro
 */

#include "DataQuality.h"

constexpr  int                   DATA_NOT_SUSPECT = 0;
constexpr const char* DATA_NOT_SUSPECT_DESCRIPTION = "Data Not Suspect";

constexpr  int   DATA_SLIGHTLY_SUSPECT = 1;
constexpr  const char* DATA_SLIGHTLY_SUSPECT_DESCRIPTION = "Data Slightly Suspect";

constexpr  int   DATA_HIGHLY_SUSPECT = 2;
constexpr const char* DATA_HIGHLY_SUSPECT_DESCRIPTION = "Data Highly Suspect";

constexpr  int   DATA_UNFIT_FOR_USE = 3;
constexpr const char* DATA_UNFIT_FOR_USE_DESCRIPTION = "Data Unfit For Use";

DataQuality::DataQuality() {
	// TODO Auto-generated constructor stub

}

DataQuality::~DataQuality() {
	// TODO Auto-generated destructor stub
}

/**
* <strong>(FXY33003)</strong>-This method returns a String representation
* of the data quality for the data resolution recorded in the profile.
* This method accepts an int as a parameter. The parameter is the value
* of dataquality field in the XBT profile.
*
* @return <strong>(FXY33003)</strong>-This method returns a String representation
* of the data quality for the data resolution recorded in the profile.
* This method accepts an int as a parameter. The parameter is the value
* of dataquality field in the XBT profile.
* @param dataType the quality assigned to the profile.
*/
std::string DataQuality::getDataQualityDescription(int dataType) {

    const char * description = "Unknown";
    switch (dataType) {
        case DATA_NOT_SUSPECT:
            description = DATA_NOT_SUSPECT_DESCRIPTION;
            break;
        case DATA_SLIGHTLY_SUSPECT:
            description = DATA_SLIGHTLY_SUSPECT_DESCRIPTION;
            break;
        case DATA_HIGHLY_SUSPECT:
            description = DATA_HIGHLY_SUSPECT_DESCRIPTION;
            break;
        case DATA_UNFIT_FOR_USE:
            description = DATA_UNFIT_FOR_USE_DESCRIPTION;
            break;
    }// end switch

    return std::string(description);
}
