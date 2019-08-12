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
    char buf[10];
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
    char buf[11];
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
    char buf[11];
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
    char buf[12];
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
    char *buf = new char();

    tmp += "Call Sign                      | " + xBTprofile->getWMOId() + "\n";
    tmp += "Latitude                       | " + decimalDegreesLatToDMSAOML(xBTprofile->getLatitude()) + "\n";
    tmp += "Longitude                      | " + decimalDegreesLonToDMSAOML(xBTprofile->getLongitude()) + "\n";
    tmp += "Transect Name                  | " + xBTprofile->getSoopLine() + "\n";
    tmp += "Transect Number                | " + std::to_string(xBTprofile->getTransectNumber()) + "\n";
    tmp += "Sequence Number                | " + std::to_string(xBTprofile->getSequenceNumber()) + "\n";
    sprintf(buf,"%02d", xBTprofile->getYear());
    tmp += "Year                           | " + std::string(buf) + "\n";
    sprintf(buf,"%02d", xBTprofile->getMonth());
    tmp += "Month                          | " + std::string(buf) + "\n";
    sprintf(buf,"%02d", xBTprofile->getDay());
    tmp += "Day                            | " + std::string(buf) + "\n";
    sprintf(buf,"%02d", xBTprofile->getHour());
    tmp += "Hour                           | " + std::string(buf) + "\n";
    sprintf(buf,"%02d", xBTprofile->getMinute());
    tmp += "Minute                         | " + std::string(buf) + "\n";
    tmp += "Ship Name                      | " + xBTprofile->getShipName() + "\n";
    tmp += "IMO Number                     | " + std::to_string(xBTprofile->getLloyds()) + "\n";
    sprintf(buf,"%x", xBTprofile->getUniqueTag());
    std::string s = std::string(buf);

    for(unsigned int i =0; i < s.size() ; i++) {
		s[i]=std::toupper(s[i]);
	}

    tmp += "SEAS ID                        | " + s + "\n";
    tmp += "SEAS Version                   | " + std::to_string(xBTprofile->getSeasVersion()) + "\n";
    tmp += "Probe Serial Number            | " + std::to_string(xBTprofile->getProbeSerialNumber()) + "\n";
    sprintf(buf,"%02d/%02d/%04d\n",
            xBTprofile->getXBTProbeManufacturedMonth(),
            xBTprofile->getXBTProbeManufacturedDay(),
            xBTprofile->getXBTProbeManufacturedYear());
    tmp += "Probe Manufacture Date         | " + std::string(buf);
    tmp += "Data Type                      | " + std::to_string(xBTprofile->getThisDataIs()) + " (" + DataResolution::getDataResolutionDescription(xBTprofile->getThisDataIs()) + ")\n";
    tmp += "Data Quality                   | " + std::to_string(xBTprofile->getDataQuality()) + " (" + DataQuality::getDataQualityDescription(xBTprofile->getDataQuality()) + ")\n";
    sprintf(buf,"%4.2f", xBTprofile->getLaunchHeight());
    tmp += "Deployment Height (meters)     | " + std::string(buf) + "\n";
    sprintf(buf,"%03d", (int) xBTprofile->getShipDirection());
    tmp += "Ship Direction                 | " + std::string(buf) + "\n";
    sprintf(buf,"%05.2f", xBTprofile->getShipSpeed() * 1.94384);
    tmp += "Ship Speed (knots)             | " +  std::string(buf) + "\n";
    tmp += "Instrument Type                | " + XBTProbe::getProbeDescription(xBTprofile->getInstrumentType())
            + " (Code " + std::to_string(xBTprofile->getInstrumentType()) + ")\n";
    tmp += "Recorder Type                  | " + XBTRecorder::getRecorderDescription(xBTprofile->getRecorderType())
            + " (Code " + std::to_string(xBTprofile->getRecorderType()) + ")\n";
    tmp += "Wind Instrument Type           | " + std::to_string(xBTprofile->getWindInstrumentType()) + "\n";
    sprintf(buf,"%04.1f",  xBTprofile->getWindDirection());
    tmp += "Wind Direction                 | " + std::string(buf) + "\n";
    sprintf(buf,"%04.1f",  xBTprofile->getWindSpeed());
    tmp += "Wind Speed (knots)             | " + std::string(buf) + "\n";
    sprintf(buf,"%05.2f", xBTprofile->getDryBulbTemperature() - 273.15);
    tmp += "Dry Bulb Temperature (celsius) | " + std::string(buf) + "\n";
    tmp += "Current Measurement Method     | " + std::to_string(xBTprofile->getSeaSurfaceCurrentMeasurementMethod()) + "\n";
    tmp += "Current Direction              | " + std::to_string(xBTprofile->getSeaSurfaceCurrentDirection()) + "\n";
    sprintf(buf,"%2.2f",  xBTprofile->getSeaSurfaceCurrentSpeed());
    tmp += "Current Speed (knots)          | " + std::string(buf) + "\n";
    tmp += "Total Water Depth (meters)     | " + std::to_string(xBTprofile->getTotalWaterDepth()) + "\n";
    tmp += "XBT Launcher Type              | " + Launchers::getLauncherDescription(xBTprofile->getXBTLauncherType()) + "\n";
    tmp += "XBT Recorder Serial Number     | " + xBTprofile->getXBTRecorderSerialNumber() + "\n";
    sprintf(buf,"%02d/%02d/%04d\n",
            xBTprofile->getXBTRecorderManufacturedMonth(),
            xBTprofile->getXBTRecorderManufacturedDay(),
            xBTprofile->getXBTRecorderManufacturedYear());
    tmp += "XBT Recorder Manufacture Date  | " + std::string(buf);
    tmp += "Agency in charge of Operation  | " + Agency::getAgencyDescription(xBTprofile->getAgencyOwner()) + "\n";
    tmp += "Ship Rider                     | " + xBTprofile->getRiderNames() + "\n";
    tmp += "Ship Rider Institution         | " + xBTprofile->getRiderInstitutions() + "\n";
    tmp += "Ship Rider Email               | " + xBTprofile->getRiderEmails() + "\n";
    tmp += "Ship Rider Telephone Number    | " + xBTprofile->getRiderPhones() + "\n";
    tmp += "===================================================================\n";
    tmp += "Full Resolution Values\n";
    tmp += "   Depth       Temperature        \n";


    for (std::vector<double> depthsAndTemp : depthsAndTemps) {
    	double depth = std::round(depthsAndTemp[0]*100.00)/100.00;
    	sprintf(buf," %7.2f       %5.2f\n", depth, depthsAndTemp[1]);
    	tmp+= buf;
    } //end for

    return tmp;

}
