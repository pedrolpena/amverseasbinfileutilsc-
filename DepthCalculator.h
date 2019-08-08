/*
 * DepthCalculator.h
 *
 *  Created on: Aug 7, 2019
 *      Author: pedro
 */

#ifndef DEPTHCALCULATOR_H_
#define DEPTHCALCULATOR_H_

#include <vector>

#include "XBTProbe.h"
#include "XBTRecorder.h"
#include "XBTProfile.h"

class DepthCalculator {
public:
	double A = 0.0;
	double B = 0.0;
	double sampleFrequency = 10.0;
	int numberOfMeasurements = 0;
	XBTProfile xBTProfile;

    /**
     * This method sets the coefficients used by the XBT fall rate equation to
     * determine the measurement depths.
     *
     * @return None
     */
    void setProbeCoefficients(int probeType);

    /**
     * This method sets the recorders measurement frequency in Hertz.
     *
     * @return None
     */
    void setRecorderFrequency(int recorderType);

    /**
     * This method returns a double that is the depth where the measurement was
     * made.
     *
     * @param sequenceNumber A number from 0 to n that is the position of the
     * measurement in the list of points.
     * @return This method returns a double that is the depth where the
     * measurement was made.
     */
    double getMeasurementDepth(int sequenceNumber);


    /**
     * This method returns an array of doubles containing the depths where each
     * measurement was made.
     *
     * @return returns an array of doubles containing the depths where each
     * measurement was made.
     */
    std::vector<double > getMeasurementDepths();

    /**
     * This method returns a two dimensional array of doubles containing the
     * depths ad temperatures as measured by the recorder.
     *
     * @return returns a two dimensional array of doubles containing the depths
     * ad temperatures as measured by the recorder.
     */
    std::vector<std::vector<double>>  getDepthsAndTemperaturePoints();


    /**
     * The constructor accepts the recorder type, the probe type and the number
     * of measurements made in order to calculate the measurement depths.
     *
     * @param recorderType <strong>(FXY22068)</strong>-a table value that
     * represents the device that determines the thermistor value in the
     * XBT.<br>
     * e.g. a value of 6 refers to any of the different Sippican MK21 models.
     * @param probeType <strong>(FXY22067)</strong>-a table value that
     * represents the type of probe used to make the measurement.<br>
     * e.g. a value of 52 refers to a Deep Blue XBT.
     * @param xBTProfile XBTProfile object
     *
     */
    DepthCalculator(XBTProfile &xBTProfile, int recorderType, int probeType);

    DepthCalculator(XBTProfile &xBTProfile);

	virtual ~DepthCalculator();
};

#endif /* DEPTHCALCULATOR_H_ */
