/*
 * DepthCalculator.cpp
 *
 *  Created on: Aug 7, 2019
 *      Author: pedro
 */

#include "DepthCalculator.h"

DepthCalculator::DepthCalculator(XBTProfile &xBTProfile) {

    this->xBTProfile = xBTProfile;
    numberOfMeasurements = xBTProfile.getTemperaturePoints().size();
    setRecorderFrequency(xBTProfile.getRecorderType());
    setProbeCoefficients(xBTProfile.getInstrumentType());

}

DepthCalculator::~DepthCalculator() {
	// TODO Auto-generated destructor stub
}

/**
 * This method sets the coefficients used by the XBT fall rate equation to
 * determine the measurement depths.
 *
 * @return None
 */
void DepthCalculator::setProbeCoefficients(int probeType) {
    A = XBTProbe::getCoefficientA(probeType);
    B = XBTProbe::getCoefficientB(probeType);
}

/**
 * This method sets the recorders measurement frequency in Hertz.
 *
 * @return None
 */
void DepthCalculator::setRecorderFrequency(int recorderType) {

	sampleFrequency = XBTRecorder::getRecorderFrequency(recorderType);

}


/**
 * This method returns a double that is the depth where the measurement was
 * made.
 *
 * @param sequenceNumber A number from 0 to n that is the position of the
 * measurement in the list of points.
 * @return This method returns a double that is the depth where the
 * measurement was made.
 */
double DepthCalculator::getMeasurementDepth(int sequenceNumber) {

    double depth;
    double time;

    time = ((double) sequenceNumber + 1) / sampleFrequency;
    depth = (A * time) + (.001 * B * time * time);

    return depth;

}


/**
 * This method returns an array of doubles containing the depths where each
 * measurement was made.
 *
 * @return returns an array of doubles containing the depths where each
 * measurement was made.
 */
std::vector<double> DepthCalculator::getMeasurementDepths() {
	std::vector<double> depths(numberOfMeasurements);
    double time;
    for (int i = 0; i < numberOfMeasurements; i++) {
        time = ((double) i + 1) / sampleFrequency;
        depths[i] = (A * time) + (.001 * B * time * time);

    }//end for
    return depths;

}


/**
 * This method returns a two dimensional array of doubles containing the
 * depths ad temperatures as measured by the recorder.
 *
 * @return returns a two dimensional array of doubles containing the depths
 * ad temperatures as measured by the recorder.
 */
std::vector<std::vector<double> > DepthCalculator::getDepthsAndTemperaturePoints() {

    double time;
    std::vector<std::vector<double> > depthsAndTemps(numberOfMeasurements,std::vector<double>(2));
    std::vector<double> temps = xBTProfile.getTemperaturePoints();

    for (int i = 0; i < numberOfMeasurements; i++) {
        time = ((double) i + 1) / sampleFrequency;
        depthsAndTemps[i][0] = (A * time) + (.001 * B * time * time);
        depthsAndTemps[i][1] = temps[i];
    }//end for

    return depthsAndTemps;

}

DepthCalculator::DepthCalculator(XBTProfile &xBTProfile, int recorderType, int probeType) {

    this->xBTProfile = xBTProfile;
    numberOfMeasurements = xBTProfile.getTemperaturePoints().size();
    setRecorderFrequency(recorderType);
    setProbeCoefficients(probeType);

}
/**
 * This method returns a two dimensional array of doubles containing the
 * depths ad temperatures with a resolution of two meters. A linear
 * interpolation is performed to get the depths at 1 meter increments.
 *
 * @return returns a two dimensional array of doubles containing the depths
 * ad temperatures with a resolution of two meters. A linear interpolation
 * is performed to get the depths at 1 meter increments.
 */
std::vector<std::vector<double> > DepthCalculator::getDepthsAndTemperaturePointsOneMeterResolution() {
	std::vector<std::vector<double> > depthsAndTemps = getDepthsAndTemperaturePoints();
	double inputTemps[numberOfMeasurements];
	double inputDepths[numberOfMeasurements];
	int finalDepth = (int) depthsAndTemps[numberOfMeasurements - 1][0];
	std::vector<std::vector<double> > depthsAndTempsOneMeterResolution(
			finalDepth, std::vector<double>(2));

	// copy depths and temps to arrays needed for the interpolator
	for (int i = 0; i < numberOfMeasurements; i++) {

		inputDepths[i] = depthsAndTemps[i][0];
		inputTemps[i] = depthsAndTemps[i][1];
	} //end for

	double oneMeterDepths[finalDepth];

	//generate array of depths used by the interpolator to generate temps
	for (int i = 0; i < finalDepth; i++) { // place depths
		oneMeterDepths[i] = (double) (i + 1);

	} //end for

	// holds the result
	double oneMeterTemps[finalDepth];

	// this one element array holds the number of points
	int inputSize[] = { numberOfMeasurements };

	//interpoalte
	mlinterp::interp(

	inputSize, finalDepth, inputTemps, oneMeterTemps, inputDepths,
			oneMeterDepths);

	//copy results to a 2 dimensional vector;
	for (int i = 0; i < finalDepth; i++) {

		depthsAndTempsOneMeterResolution[i][1] = oneMeterTemps[i];
		depthsAndTempsOneMeterResolution[i][0] = oneMeterDepths[i];
	}

	return depthsAndTempsOneMeterResolution;
}


/**
 * This method returns a two dimensional array of doubles containing the
 * depths ad temperatures with a resolution of two meters. A linear
 * interpolation is performed to get the depths at 2 meter increments.
 *
 * @return returns a two dimensional array of doubles containing the depths
 * ad temperatures with a resolution of two meters. A linear interpolation
 * is performed to get the depths at 2 meter increments.
 */
std::vector<std::vector<double> > DepthCalculator::getDepthsAndTemperaturePointsTwoMeterResolution() {
	std::vector<std::vector<double> > depthsAndTemps =
			getDepthsAndTemperaturePointsOneMeterResolution();
	int finalDepth = (int) depthsAndTemps[depthsAndTemps.size() - 1][0];

	if (finalDepth % 2 != 0) {
		finalDepth--;
	}

	std::vector<std::vector<double> > depthsAndTempsTwoMeterResolution(
			finalDepth / 2, std::vector<double>(2));

	for (int i = 0; i < finalDepth / 2; i++) {

		depthsAndTempsTwoMeterResolution[i][1] = depthsAndTemps[(2 * i) + 1][1];
		depthsAndTempsTwoMeterResolution[i][0] = depthsAndTemps[(2 * i) + 1][0];
	}

	return depthsAndTempsTwoMeterResolution;

}
