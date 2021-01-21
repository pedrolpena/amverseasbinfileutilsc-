/*
 * FormatConverter.cpp
 *
 *  Created on: Aug 11, 2019
 *      Author: pedro
 */

#include "FormatConverter.h"

FormatConverter::FormatConverter(XBTProfile &xBTprofile) {
	this->xBTprofile = &xBTprofile;

}

FormatConverter::~FormatConverter() {
	// TODO Auto-generated destructor stub
}

std::string FormatConverter::decimalDegreesLatToDMSAOML(double lat) {

    double tmp = std::abs(lat);
    int x = (int) tmp;
    double y = 60 * (tmp - (double) x);
    std::string dir = "N";
    if (lat < 0) {
        dir = "S";
    }//end if
    char buf[18];
    sprintf(buf,"%02d %05.2f " ,x ,y);
    std::string out = buf + dir;
    return out;
}

std::string FormatConverter::decimalDegreesLonToDMSAOML(double lon) {

    double tmp = std::abs(lon);
    int x = (int) tmp;
    double y = 60 * (tmp - (double) x);
    std::string dir = "E";
    if (lon < 0) {
        dir = "W";
    }//end if
    char buf[18];
    sprintf(buf,"%03d %05.2f " ,x ,y);
    std::string out = buf + dir;
    return out;



}

std::string FormatConverter::decimalDegreesLatToDMSEDF(double lat) {

    double tmp = std::abs(lat);
    int x = (int) tmp;
    double y = 60 * (tmp - (double) x);
    std::string dir = "N";
    if (lat < 0) {
        dir = "S";
    }//end if
    char buf[19];
    sprintf(buf,"%02d %07.4f" ,x ,y);
    std::string out = buf + dir;
    return out;

}

std::string FormatConverter::decimalDegreesLonToDMSEDF(double lon) {

    double tmp = std::abs(lon);
    int x = (int) tmp;
    double y = 60 * (tmp - (double) x);
    std::string dir = "E";
    if (lon < 0) {
        dir = "W";
    }//end if
    char buf[19];
    sprintf(buf,"%03d %07.4f" ,x ,y);
    std::string out = buf + dir;
    return out;
}




/**
 * This method returns a String containing the xBTprofile information using
 * the SEAS ASCII format.
 *
 * @return This method returns a String containing the xBTprofile
 * information using the SEAS ASCII format.
 */
std::string FormatConverter::getASCII() {
    std::string tmp = "";
    std::vector<std::vector<double>> depthsAndTemps;  //array of doubles that holds depths & temperature measurements
    DepthCalculator *dc = new DepthCalculator(*xBTprofile);
    depthsAndTemps = dc->getDepthsAndTemperaturePoints();
    //char buf[120];

    tmp += "Call Sign                      | " + xBTprofile->getWMOId() + "\r\n";
    tmp += "Latitude                       | " + decimalDegreesLatToDMSAOML(xBTprofile->getLatitude()) + "\r\n";
    tmp += "Longitude                      | " + decimalDegreesLonToDMSAOML(xBTprofile->getLongitude()) + "\r\n";
    tmp += "Transect Name                  | " + xBTprofile->getSoopLine() + "\r\n";
    tmp += "Transect Number                | " + std::to_string(xBTprofile->getTransectNumber()) + "\r\n";
    tmp += "Sequence Number                | " + std::to_string(xBTprofile->getSequenceNumber()) + "\r\n";
    sprintf(buf,"%02d", xBTprofile->getYear());
    tmp += "Year                           | " + std::string(buf) + "\r\n";
    sprintf(buf,"%02d", xBTprofile->getMonth());
    tmp += "Month                          | " + std::string(buf) + "\r\n";
    sprintf(buf,"%02d", xBTprofile->getDay());
    tmp += "Day                            | " + std::string(buf) + "\r\n";
    sprintf(buf,"%02d", xBTprofile->getHour());
    tmp += "Hour                           | " + std::string(buf) + "\r\n";
    sprintf(buf,"%02d", xBTprofile->getMinute());
    tmp += "Minute                         | " + std::string(buf) + "\r\n";
    tmp += "Ship Name                      | " + xBTprofile->getShipName() + "\r\n";
    tmp += "IMO Number                     | " + std::to_string(xBTprofile->getLloyds()) + "\r\n";
    sprintf(buf,"%x", xBTprofile->getUniqueTag());
    std::string s = std::string(buf);

    for(unsigned int i =0; i < s.size() ; i++) {
		s[i]=std::toupper(s[i]);
	}

    tmp += "SEAS ID                        | " + s + "\r\n";
    tmp += "SEAS Version                   | " + std::to_string(xBTprofile->getSeasVersion()) + "\r\n";
    tmp += "Probe Serial Number            | " + std::to_string(xBTprofile->getProbeSerialNumber()) + "\r\n";
    sprintf(buf,"%02d/%02d/%04d\r\n",
            xBTprofile->getXBTProbeManufacturedMonth(),
            xBTprofile->getXBTProbeManufacturedDay(),
            xBTprofile->getXBTProbeManufacturedYear());
    tmp += "Probe Manufacture Date         | " + std::string(buf);
    tmp += "Data Type                      | " + std::to_string(xBTprofile->getThisDataIs()) + " (" + DataResolution::getDataResolutionDescription(xBTprofile->getThisDataIs()) + ")\r\n";
    tmp += "Data Quality                   | " + std::to_string(xBTprofile->getDataQuality()) + " (" + DataQuality::getDataQualityDescription(xBTprofile->getDataQuality()) + ")\r\n";
    sprintf(buf,"%4.2f", xBTprofile->getLaunchHeight());
    tmp += "Deployment Height (meters)     | " + std::string(buf) + "\r\n";
    sprintf(buf,"%03d", (int) xBTprofile->getShipDirection());
    tmp += "Ship Direction                 | " + std::string(buf) + "\r\n";
    sprintf(buf,"%05.2f", xBTprofile->getShipSpeed() * 1.94384);
    tmp += "Ship Speed (knots)             | " +  std::string(buf) + "\r\n";
    tmp += "Instrument Type                | " + XBTProbe::getProbeDescription(xBTprofile->getInstrumentType())
            + " (Code " + std::to_string(xBTprofile->getInstrumentType()) + ")\r\n";
    tmp += "Recorder Type                  | " + XBTRecorder::getRecorderDescription(xBTprofile->getRecorderType())
            + " (Code " + std::to_string(xBTprofile->getRecorderType()) + ")\r\n";
    tmp += "Wind Instrument Type           | " + std::to_string(xBTprofile->getWindInstrumentType()) + "\r\n";
    sprintf(buf,"%04.1f",  xBTprofile->getWindDirection());
    tmp += "Wind Direction                 | " + std::string(buf) + "\r\n";
    sprintf(buf,"%04.1f",  xBTprofile->getWindSpeed());
    tmp += "Wind Speed (knots)             | " + std::string(buf) + "\r\n";
    sprintf(buf,"%05.2f", xBTprofile->getDryBulbTemperature() - 273.15);
    tmp += "Dry Bulb Temperature (celsius) | " + std::string(buf) + "\r\n";
    tmp += "Current Measurement Method     | " + std::to_string(xBTprofile->getSeaSurfaceCurrentMeasurementMethod()) + "\r\n";
    tmp += "Current Direction              | " + std::to_string(xBTprofile->getSeaSurfaceCurrentDirection()) + "\r\n";
    sprintf(buf,"%2.2f",  xBTprofile->getSeaSurfaceCurrentSpeed());
    tmp += "Current Speed (knots)          | " + std::string(buf) + "\r\n";
    tmp += "Total Water Depth (meters)     | " + std::to_string(xBTprofile->getTotalWaterDepth()) + "\r\n";
    tmp += "XBT Launcher Type              | " + Launchers::getLauncherDescription(xBTprofile->getXBTLauncherType()) + "\r\n";
    tmp += "XBT Recorder Serial Number     | " + xBTprofile->getXBTRecorderSerialNumber() + "\r\n";
    sprintf(buf,"%02d/%02d/%04d\r\n",
            xBTprofile->getXBTRecorderManufacturedMonth(),
            xBTprofile->getXBTRecorderManufacturedDay(),
            xBTprofile->getXBTRecorderManufacturedYear());
    tmp += "XBT Recorder Manufacture Date  | " + std::string(buf);
    tmp += "Agency in charge of Operation  | " + Agency::getAgencyDescription(xBTprofile->getAgencyOwner()) + "\r\n";
    tmp += "Ship Rider                     | " + xBTprofile->getRiderNames() + "\r\n";
    tmp += "Ship Rider Institution         | " + xBTprofile->getRiderInstitutions() + "\r\n";
    tmp += "Ship Rider Email               | " + xBTprofile->getRiderEmails() + "\r\n";
    tmp += "Ship Rider Telephone Number    | " + xBTprofile->getRiderPhones() + "\r\n";
    tmp += "===================================================================\r\n";
    tmp += "Full Resolution Values\r\n";
    tmp += "   Depth       Temperature        \r\n";


    for (std::vector<double> depthsAndTemp : depthsAndTemps) {
    	double depth = depthsAndTemp[0];
    	sprintf(buf," %7.2f       %5.2f\r\n", depth, depthsAndTemp[1]);
    	tmp+= buf;
    } //end for

    delete dc;
    return tmp;

}


/**
 * This method returns a String containing the xBTprofile information emulating
 * the Sippican Export Data Format (EDF).
 *
 * @param fileName The filename to display.
 * @param salinity The salinty of the area where the measurement was made.
 * @return This method returns a String containing the xBTprofile
 * information emulating the Sippican Export Data Format (EDF).
 */
std::string FormatConverter::getASCIIEDF(std::string fileName, double salinity) {

	std::vector<std::vector<double>> depthsAndTemps;               //array of doubles that holds depths & temperature measurements
    DepthCalculator *dc = new DepthCalculator(*xBTprofile);
    depthsAndTemps = dc->getDepthsAndTemperaturePoints();
    //char buf[120];
    std::string tmp = "";
    fileName = fileName.substr(fileName.find_last_of("/\\") + 1); // extract filename from path

    tmp += "// Amverseas EXPORT DATA FILE  (EDF)\r\n";
    tmp += "// File Information\r\n";
    tmp += "Raw Data Filename:  " + fileName + "\r\n";
    tmp += "// System Information\r\n";
    tmp += "Units            :  Metric\r\n";
    tmp += "// Probe Information\r\n";
    tmp += "Probe Type       :  " + XBTProbe::getProbeDescription(xBTprofile->getInstrumentType()) + "\r\n";
    sprintf(buf,"%04.1f",XBTProbe::getMaxDepth(xBTprofile->getInstrumentType()));
    tmp += "Terminal Depth   :  " + std::string(buf) + " m\r\n";
    tmp += "Depth Equation   :  Standard\r\n";
    tmp += "Depth Coeff. 1   :  0.0\r\n";
    sprintf(buf,"%f", XBTProbe::getCoefficientA(xBTprofile->getInstrumentType()));
    tmp += "Depth Coeff. 2   :  " + std::string(buf) + "\r\n";
    sprintf(buf,"%f", XBTProbe::getCoefficientB(xBTprofile->getInstrumentType()) * .001);
    tmp += "Depth Coeff. 3   :  " + std::string(buf) + "\r\n";
    tmp += "Depth Coeff. 4   :  0.0\r\n";
    tmp += "// Launch Information\r\n";
    tmp += "Num Info Fields  :  6\r\n";
    sprintf(buf,"%02d/%02d/%04d\r\n",
            xBTprofile->getMonth(),
            xBTprofile->getDay(),
            xBTprofile->getYear() );
    tmp += "Date of Launch   :  " + std::string(buf);
    sprintf(buf,"%02d:%02d:%02d\r\n",
            xBTprofile->getHour(),
            xBTprofile->getMinute(), 0);
    tmp += "Time of Launch   :  " + std::string(buf);
    tmp += "Sequence Number  :  " + std::to_string(xBTprofile->getSequenceNumber()) + "\r\n";;
    tmp += "Latitude         :  " + decimalDegreesLatToDMSEDF(xBTprofile->getLatitude()) + "\r\n";;
    tmp += "Longitude        :  " + decimalDegreesLonToDMSEDF(xBTprofile->getLongitude()) + "\r\n";;
    tmp += "Serial Number    :  " + xBTprofile->getXBTRecorderSerialNumber() + "\r\n";
    tmp += "// Memo\r\n";
    tmp += xBTprofile->getShipName() + "\r\n";;
    tmp += "// Hardware\r\n";
    tmp += "Recorder Device  : " + XBTRecorder::getRecorderDescription(xBTprofile->getRecorderType()) + "\r\n";
    tmp += "// Information - XBT\r\n";
    sprintf(buf,"%5.2f", salinity);
    tmp += "Salinity          :  " + std::string(buf) + " ppt\r\n";
    tmp += "// Post-Processing\r\n";
    tmp += "Operations       :  None\r\n";
    tmp += "// Data Fields\r\n";
    tmp += "Num Data Fields   :  5\r\n";
    tmp += "Field1            :  Time (sec)\r\n";
    tmp += "Field2            :  Resistance (ohms)\r\n";
    tmp += "Field3            :  Depth (m)\r\n";
    tmp += "Field4            :  Temperature (C)\r\n";
    tmp += "Field5            :  Sound Velocity (m/s)\r\n";
    tmp += "// Data\r\n";
    PressureCalculator pc;
    SoundSpeedInSeaWater ss;
    double pressure;
    double sv ;
    double temp;
    double depth;
    double time = 0.0;
    std::vector<double> resistances = xBTprofile->getResistancePoints();
    double resistance;
    for (unsigned int i = 0; i < depthsAndTemps.size() ; i++) {
        depth = dc->getMeasurementDepth(i-1);
        temp = depthsAndTemps[i][1];
        pressure = pc.getPressure(depth, xBTprofile->getLatitude());
        time = i / XBTRecorder::getRecorderFrequency(xBTprofile->getInstrumentType());
        resistance = -9999.99;
        if (!resistances.empty() && resistances.size() > i )
        resistance =resistances[i] ;
        sv = ss.getSoundSpeedChenMillero(pressure, salinity, temp);
        sprintf(buf,"%5.1f %8.3f    %7.2f   %5.2f   %7.2f",time,resistance, depth, temp , sv);
        tmp += std::string(buf)+"\r\n";
    } //end for
    delete dc;
    return tmp;


}

std::string FormatConverter::getASCIINDC() {

	std::string tmp = "";
	DepthCalculator *dc = new DepthCalculator(*xBTprofile);
	std::vector<std::vector<double>> inflectionPoints = dc->getDepthsAndTemperaturePointsInflectionPoints();
	std::vector<std::vector<double>> twoMeterResolution = dc->getDepthsAndTemperaturePointsTwoMeterResolution();
	std::vector<std::vector<double>> fullResolution = dc->getDepthsAndTemperaturePoints();
	sprintf(buf,"%05.2f",(double)xBTprofile->getSeasVersion()/100.00);
	tmp += " SEAS Version:  "  + std::string(buf) + "\r\n";
	tmp += " Ship Name: "      + xBTprofile->getShipName() + "\r\n";
	tmp += " Call Sign: "      + xBTprofile->getWMOId() + "\r\n";
	tmp += " Lloyds Number:  " + std::to_string(xBTprofile->getLloyds()) + "\r\n";
    sprintf(buf,"%02d/%02d/%04d %02d:%02d GMT\r\n",
            xBTprofile->getDay(),
            xBTprofile->getMonth(),
            xBTprofile->getYear(),
			xBTprofile->getHour(),
			xBTprofile->getMinute());
	tmp += " Date/Time(dd/mm/yyyy): " + std::string(buf);
	tmp += " Latitude(ddd.ddd): " + std::string("0") + decimalDegreesLatToDMSAOML(xBTprofile->getLatitude()) + "\r\n";
	tmp += " Longitude(ddd.ddd): " + decimalDegreesLonToDMSAOML(xBTprofile->getLongitude()) + "\r\n";
	tmp += " Probe Type: " + XBTProbe::getProbeDescription(xBTprofile->getInstrumentType()) + "\r\n";
	tmp += " Probe Code:  " + std::to_string(xBTprofile->getInstrumentType()) + "\r\n";
	tmp += " Probe Serial No: " + std::to_string(xBTprofile->getProbeSerialNumber()) + "\r\n";
	tmp += " Recorder Type: " + XBTRecorder::getRecorderDescription(xBTprofile->getRecorderType()) + "\r\n";
	tmp += " Recorder Code:  " + std::to_string(xBTprofile->getRecorderType()) + "\r\n";
	sprintf(buf,"%05.2f", xBTprofile->getDryBulbTemperature() - 273.15);
	tmp += " Dry Bulb Temp:  " + std::string(buf) + "\r\n";
	tmp += " Wind Instr Type: " + WindInstrument::getInstrumentDescription(xBTprofile->getWindInstrumentType()) + "\r\n";
	sprintf(buf,"%04.1f",  xBTprofile->getWindSpeed());
	tmp += " Wind Speed: " + std::string(buf) + "\r\n";
	sprintf(buf,"%04.1f",  xBTprofile->getWindDirection());
	tmp += " Wind Dir:   " + std::string(buf) + "\r\n";
	tmp += " Current Measurement Method: " +
			SurfaceCurrentInstrument::getInstrumentDescription(
					xBTprofile->getSeaSurfaceCurrentMeasurementMethod()) + "\r\n";
	sprintf(buf,"%2.2f",  xBTprofile->getSeaSurfaceCurrentSpeed());
	tmp += " Current Speed: " + std::string(buf) + "\r\n";
	tmp += " Current Dir:   " + std::to_string(xBTprofile->getSeaSurfaceCurrentDirection()) + "\r\n";
	tmp += " Bottom Depth:    " + std::to_string(xBTprofile->getTotalWaterDepth()) + " M\r\n";

    sprintf(buf,"%x", xBTprofile->getUniqueTag());
    std::string s = std::string(buf);

    for(unsigned int i =0; i < s.size() ; i++) {
		s[i]=std::toupper(s[i]);
	}
	sprintf(buf,"%s","FFFFFFFF");
	tmp += " GTS CRC: " + std::string(buf) + "\r\n";
	tmp += " SEAS ID: " + s + "\r\n";
	sprintf(buf,"%4.2f",  xBTprofile->getShipSpeed() * 1.94384);
	tmp += " Ship Speed at Launch (knots): " + std::string(buf) + "\r\n";
	sprintf(buf,"%02d", (int) xBTprofile->getShipDirection());
	tmp += " Ship Direction at Launch (Degrees):   " + std::string(buf) + "\r\n";
	tmp += " Sequence Number:   "+ std::to_string(xBTprofile->getSequenceNumber()) + "\r\n";
	tmp += " Transect Number:    " + std::to_string(xBTprofile->getTransectNumber()) + "\r\n";
	sprintf(buf,"%4.2f", xBTprofile->getLaunchHeight());
	tmp += " Launch Height (Meters):  " + std::string(buf) +  "\r\n";
	tmp += " SOOP Line: " + xBTprofile->getSoopLine() + "\r\n";
	tmp += " XBT Launcher Type: " + Launchers::getLauncherDescription(xBTprofile->getXBTLauncherType()) + "\r\n";
	tmp += " XBT Recorder Serial Number: " + xBTprofile->getXBTRecorderSerialNumber() + "\r\n";
    sprintf(buf,"%02d/%02d/%04d\r\n",
            xBTprofile->getXBTRecorderManufacturedMonth(),
            xBTprofile->getXBTRecorderManufacturedDay(),
            xBTprofile->getXBTRecorderManufacturedYear());
	tmp += " XBT Recorder Manufacture Date: " + std::string(buf);
    sprintf(buf,"%02d/%02d/%04d\r\n",
            xBTprofile->getXBTProbeManufacturedMonth(),
            xBTprofile->getXBTProbeManufacturedDay(),
            xBTprofile->getXBTProbeManufacturedYear());
	tmp += " Probe Manufacture Date: " + std::string(buf);
	tmp += " Agency in charge of Operation: " + Agency::getAgencyDescription(xBTprofile->getAgencyOwner()) + "\r\n";
	tmp += " Ship Rider: " + xBTprofile->getRiderNames() + "\r\n";
	tmp += " Ship Rider Institution: " + xBTprofile->getRiderInstitutions() + "\r\n";
	tmp += " Ship Rider Email: " + xBTprofile->getRiderEmails() + "\r\n";
	tmp += " Ship Rider Telephone Number: " + xBTprofile->getRiderPhones() + "\r\n";

	if (inflectionPoints.size() > 0) {
		tmp += "\r\n\r\nINFPTS: " + std::to_string(inflectionPoints.size()) ;

		int count = 0;
		for (std::vector<double> inflectionPoint : inflectionPoints) {
			int depth = (int) (inflectionPoint[0] * 10);
			int temp = (int) (inflectionPoint[1] * 100);
			sprintf(buf, " %4d %4d", depth, temp);

			if ((count) % 8 != 0) {
				tmp = tmp + buf;
			} else {
				tmp = tmp + "\r\n" + buf + " ";
			}
			count++;
		} //end for
	}

	if (twoMeterResolution.size() > 0) {
		tmp += "\r\n\r\n\r\nTWOMETER: " + std::to_string(twoMeterResolution.size()) ;

		int count = 0;
		for (std::vector<double> twoMeterProfile : twoMeterResolution) {
			int depth = (int) (twoMeterProfile[0] * 10);
			int temp = (int) (twoMeterProfile[1] * 100 + .5);
			sprintf(buf, " %4d %4d", depth, temp);

			if ((count) % 8 != 0) {
				tmp = tmp + buf;
			} else {
				tmp = tmp + "\r\n" + buf + " ";
			}
			count++;
		} //end for
	}

	if (fullResolution.size() > 0) {
		tmp += "\r\n\r\n\r\nXBT: " + std::to_string(fullResolution.size()) ;

		int count = 0;
		for (std::vector<double> fullProfile : fullResolution) {
			int temp = (int) (fullProfile[1] * 100 + .5);
			sprintf(buf, "%4d", temp);

			if ((count) % 20 != 0) {
				tmp = tmp + buf;
			} else {
				tmp = tmp + "\r\n" + buf ;
			}
			count++;
		} //end for
	}


	// calculating the GTS CRC from the string, weird.......
	uint32_t crc;
	char * GTSCRC = new char [ tmp.size() + 1];
	std:copy(tmp.begin(),tmp.end(),GTSCRC);
	GTSCRC[tmp.size()] = '\0';
	crc = FormatConverter::computeCRC32(GTSCRC,tmp.size() + 1);
	s = FormatConverter::intToHexString(crc);
	tmp.replace(tmp.find("GTS CRC: FFFFFFFF") , 17 , "GTS CRC: " + s);
	 
	 
	 delete[] GTSCRC;
	 delete dc;
	return tmp;

}

/**
 * This method calculates the CRC32 lookup table on the fly
 * and returns the checksum. This way is slower but it's
 * easier to read. This method was posted on stackoverflow
 * https://stackoverflow.com/questions/26049150/calculate-a-32-bit-crc-lookup-table-in-c-c
 */
uint32_t FormatConverter::computeCRC32(char *buf, uint32_t len) {

    uint32_t val, crc;
    uint8_t i;

    crc = 0xFFFFFFFF;
    while(len--){
        val=(crc^*buf++)&0xFF;
        for(i=0; i<8; i++){
            val = val & 1 ? (val>>1)^0xEDB88320 : val>>1;
        }
        crc = val^crc>>8;
    }
    return crc^0xFFFFFFFF;
}
std::string FormatConverter::intToHexString(int int1) {

	char hex_string[20];
	std::string data;
	sprintf(hex_string, "%X", int1);
	data = std::string(hex_string);
	std::for_each(data.begin(), data.end(), [](char & c){
		c = ::toupper(c);
	});
	return data;
}
