/*
 * SoundSpeedInSeaWater.cpp
 *
 *  Created on: Aug 7, 2019
 *      Author: pedro
 */

#include "SoundSpeedInSeaWater.h"
// from
//http://resource.npl.co.uk/acoustics/techguides/soundseawater/content.html
constexpr double A00 = 1.389;
constexpr double A01 = -1.262e-2;
constexpr double A02 = 7.166e-5;
constexpr double A03 = 2.008e-6;
constexpr double A04 = -3.21e-8;
constexpr double A10 = 9.4742e-5;
constexpr double A11 = -1.2583e-5;
constexpr double A12 = -6.4928e-8;
constexpr double A13 = 1.0515e-8;
constexpr double A14 = -2.0142e-10;
constexpr double A20 = -3.9064e-7;
constexpr double A21 = 9.1061e-9;
constexpr double A22 = -1.6009e-10;
constexpr double A23 = 7.994e-12;
constexpr double A30 = 1.100e-10;
constexpr double A31 = 6.651e-12;
constexpr double A32 = -3.391e-13;
constexpr double B00 = -1.922e-2;
constexpr double B01 = -4.42e-5;
constexpr double B10 = 7.3637e-5;
constexpr double B11 = 1.7950e-7;
constexpr double C00 = 1402.388;
constexpr double C01 = 5.03830;
constexpr double C02 = -5.81090e-2;
constexpr double C03 = 3.3432e-4;
constexpr double C04 = -1.47797e-6;
constexpr double C05 = 3.1419e-9;
constexpr double C10 = 0.153563;
constexpr double C11 = 6.8999e-4;
constexpr double C12 = -8.1829e-6;
constexpr double C13 = 1.3632e-7;
constexpr double C14 = -6.1260e-10;
constexpr double C20 = 3.1260e-5;
constexpr double C21 = -1.7111e-6;
constexpr double C22 = 2.5986e-8;
constexpr double C23 = -2.5353e-10;
constexpr double C24 = 1.0415e-12;
constexpr double C30 = -9.7729e-9;
constexpr double C31 = 3.8513e-10;
constexpr double C32 = -2.3654e-12;
constexpr double D00 = 1.727e-3;
constexpr double D10 = -7.9836e-6;

SoundSpeedInSeaWater::SoundSpeedInSeaWater() {
	// TODO Auto-generated constructor stub

}

SoundSpeedInSeaWater::~SoundSpeedInSeaWater() {
	// TODO Auto-generated destructor stub
}


/**
 * This method returns the sound speed at a point using the UNESCO form of the
 * Chen and Millero equation.
 *
 * @param pressure The pressure in KPa (kilo pascal).
 * @param salinity The salinity in parts per thousand.
 * @param temp The temperature in degrees celcius.
 * @return The sound speed in meters per second.
 */
double SoundSpeedInSeaWater::getSoundSpeedChenMillero(double pressure, double salinity, double temp) {
    double P = pressure * 1e-2; // convert from Kpa to bar
    double T = temp;
    double S = salinity;
    double D = D00 + D10 * P;
    double B = B00 + B01 * T + (B10 + B11 * T) * P;
    double A = (A00 + A01 * T + A02 * T * T + A03 * T * T * T + A04 * T * T * T * T)
            + (A10 + A11 * T + A12 * T * T + A13 * T * T * T + A14 * T * T * T * T) * P
            + (A20 + A21 * T + A22 * T * +A23 * T * T * T) * P * P
            + (A30 + A31 * T + A32 * T * T) * P * P * P;
    double C = (C00 + C01 * T + C02 * T * T + C03 * T * T * T + C04 * T * T * T * T + C05 * T * T * T * T * T)
            + (C10 + C11 * T + C12 * T * T + C13 * T * T * T + C14 * T * T * T * T) * P
            + (C20 + C21 * T + C22 * T * T + C23 * T * T * T + C24 * T * T * T * T) * P * P
            + (C30 + C31 * T + C32 * T * T) * P * P * P;

    return C + A * S + B * std::pow(S, 1.5) + D * S * S;
}
