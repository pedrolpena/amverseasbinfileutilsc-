/*
 * XBTResistanceToTemperatureConverter.h
 *
 *  Created on: Jul 20, 2019
 *      Author: pedro
 */

#ifndef XBTRESISTANCETOTEMPERATURECONVERTER_H_
#define XBTRESISTANCETOTEMPERATURECONVERTER_H_
#include <vector>
#include <cmath>

class XBTResistanceToTemperatureConverter {
public:
	XBTResistanceToTemperatureConverter();
	virtual ~XBTResistanceToTemperatureConverter();
	double convertResistaceToTemperature(double);
	std::vector<double> convertResistaceToTemperature(std::vector<double>);
};

#endif /* XBTRESISTANCETOTEMPERATURECONVERTER_H_ */
