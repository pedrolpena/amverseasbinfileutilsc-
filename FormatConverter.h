/*
 * FormatConverter.h
 *
 *  Created on: Aug 11, 2019
 *      Author: pedro
 */

#include <string>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>


#include "XBTProfile.h"
#include "DepthCalculator.h"
#include "DataResolution.h"
#include "DataQuality.h"
#include "XBTProbe.h"
#include "XBTRecorder.h"
#include "Launchers.h"
#include "Agency.h"
#include "PressureCalculator.h"
#include "SoundSpeedInSeaWater.h"

#ifndef FORMATCONVERTER_H_
#define FORMATCONVERTER_H_


class FormatConverter {
public:
    XBTProfile *xBTprofile;
    std::string prettyLat;
    std::string prettyLon;


    /**
     * This method returns a String containing the xBTprofile information using
     * the SEAS ASCII format.
     *
     * @return This method returns a String containing the xBTprofile
     * information using the SEAS ASCII format.
     */
    std::string getASCII();

    /**
     * This method returns a String containing the xBTprofile information emulating
     * the Sippican Export Data Format (EDF).
     *
     * @param fileName The filename to display.
     * @param salinity The salinty of the area where the measurement was made.
     * @return This method returns a String containing the xBTprofile
     * information emulating the Sippican Export Data Format (EDF).
     */
    std::string getASCIIEDF(std::string fileName,double salinity);
    std::string decimalDegreesLatToDMSAOML(double lat);
    std::string decimalDegreesLonToDMSAOML(double lon);
    std::string decimalDegreesLatToDMSEDF(double lat);
    std::string decimalDegreesLonToDMSEDF(double lon);


	FormatConverter(XBTProfile &xBTprofile);
	virtual ~FormatConverter();
};

#endif /* FORMATCONVERTER_H_ */
