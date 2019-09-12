/*
 * PressureCalculator.h
 *
 *  Created on: Aug 7, 2019
 *      Author: pedro
 */

#ifndef INCLUDE_PRESSURECALCULATOR_H_
#define INCLUDE_PRESSURECALCULATOR_H_
#include <cmath>

class PressureCalculator {
public:

	/**
	 * This method converts a depth to a pressure using the UNESCO form of the
	 * Leroy and Parthiot equation.
	 *
	 * @param depth The Depth in meters
	 * @param latitude The Latitude in decimal degrees.
	 * @return The pressure at Depth depth and Latitude latitude in KPa (kilo pascal
	 * relative to atmospheric pressure)
	 */
	static double getPressure(double depth, double latitude);
	PressureCalculator();
	virtual ~PressureCalculator();
};

#endif /* INCLUDE_PRESSURECALCULATOR_H_ */
