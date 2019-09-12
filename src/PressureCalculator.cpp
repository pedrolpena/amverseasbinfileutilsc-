/*
 * PressureCalculator.cpp
 *
 *  Created on: Aug 7, 2019
 *      Author: pedro
 */

#include "PressureCalculator.h"

PressureCalculator::PressureCalculator() {
	// TODO Auto-generated constructor stub

}

PressureCalculator::~PressureCalculator() {
	// TODO Auto-generated destructor stub
}
/**
 * This method converts a depth to a pressure using the UNESCO form of the
 * Leroy and Parthiot equation.
 *
 * @param depth The Depth in meters
 * @param latitude The Latitude in decimal degrees.
 * @return The pressure at Depth depth and Latitude latitude in KPa (kilo pascal
 * relative to atmospheric pressure)
 */
double PressureCalculator::getPressure(double depth, double latitude) {

    double thyh0Z = (.01* depth) / (depth + 100) + 6.2e-6 * depth;
    double gLat = 9.7803 * (1 + 5.3e-3 * std::sin(latitude) * std::sin(latitude));
    double k = (gLat - 2e-5 * depth) / (9.80612 - 2e-5 * depth);
    double h45 = 1.00818e-2 * depth + 2.465e-8 * depth * depth - 1.25e-13 * depth * depth * depth + 2.8e-19 * depth * depth * depth * depth;
    double hzLat = h45 * k;


    return 1000*(hzLat - thyh0Z);


}
