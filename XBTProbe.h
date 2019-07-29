/**
 * This class contains constants that hold the value for the type of XBT Probe
 * , the A and B coefficients used in the XBT fall rate equation, The Maximum
 * Depth for the probe and a Description of the probe. There are methods to
 * get the vales for each probe type.
 * To calculate the depth, use the following equation.
 * Z = A*t + .001 * B*t*t
 * Z is depth and t is time elapsed in seconds.
 * This values were copied from
 * https://www.nodc.noaa.gov/GTSPP/document/codetbls/wmocodes/table1770.html
 *
 * @author Pedro Pena
 * @version 1.0
 *
 */

#ifndef XBTPROBE_H_
#define XBTPROBE_H_
#include <string>
class XBTProbe {
public:
	static constexpr int         SIPPICAN_T4_OLD = 1;
	static constexpr int         SIPPICAN_T4 = 2;
	static constexpr int         SIPPICAN_T5 = 11;
	static constexpr int         SIPPICAN_FAST_DEEP = 21;
	static constexpr int         SIPPICAN_T6_OLD = 31;
	static constexpr int         SIPPICAN_T6 = 32;
	static constexpr int         SIPPICAN_T7_OLD = 41;
	static constexpr int         SIPPICAN_T7 = 42;
	static constexpr int         SIPPICAN_DEEP_BLUE_OLD = 51;
	static constexpr int         SIPPICAN_DEEP_BLUE = 52;
	static constexpr int         SIPPICAN_T10 = 61;
	static constexpr int         SIPPICAN_T11 = 71;
	static constexpr int         SIPPICAN_AXBT = 81;
	static constexpr int         TSK_T4_OLD = 201;
	static constexpr int         TSK_T4 = 202;
	static constexpr int         TSK_T6_OLD = 211;
	static constexpr int         TSK_T6 = 212;
	static constexpr int         TSK_T7_OLD = 221;
	static constexpr int         TSK_T7 = 222;
	static constexpr int         TSK_T5 = 231;
	static constexpr int         TSK_T10 = 241;
	static constexpr int         TSK_DEEP_BLUE_OLD = 251;
	static constexpr int         TSK_DEEP_BLUE = 252;
	static constexpr int         TSK_AXBT = 261;
	static constexpr int         SPARTON_XBT1 = 401;
	static constexpr int         SPARTON_XBT3 = 411;
	static constexpr int         SPARTON_XBT4 = 421;
	static constexpr int         SPARTON_XBT5 = 431;
	static constexpr int         SPARTON_XBT5DB = 441;
	static constexpr int         SPARTON_XBT6 = 451;
	static constexpr int         SPARTON_XBT7_OLD = 461;
	static constexpr int         SPARTON_XBT7 = 462;
	static constexpr int         SPARTON_XBT7DB = 471;
	static constexpr int         SPARTON_XBT10 = 481;
	static constexpr int         SPARTON_XBT20 = 491;
	static constexpr int         SPARTON_XBT20DB = 501;
	static constexpr int         SPARTON_536AXBT = 510;
	static constexpr int         SIPPICAN_12 = 900;


	XBTProbe();
	virtual ~XBTProbe();
	static double getCoefficientA(int);
	static double getCoefficientB(int);
	static double getMaxDepth(int);
	static std::string getProbeDescription(int);

private:
    static constexpr double      _SIPPICAN_T4_OLD_COEFFICIENT_A = 6.472;
    static constexpr double      _SIPPICAN_T4_OLD_COEFFICIENT_B = -2.16;
    static constexpr double      _SIPPICAN_T4_OLD_MAX_DEPTH = 460.00;
    static constexpr const char* _SIPPICAN_T4_OLD_DESCRIPTION = "Sippican T-4";

    static constexpr double      _SIPPICAN_T4_COEFFICIENT_A = 6.691;
    static constexpr double      _SIPPICAN_T4_COEFFICIENT_B = -2.25;
    static constexpr double      _SIPPICAN_T4_MAX_DEPTH = 460.00;
    static constexpr const char* _SIPPICAN_T4_DESCRIPTION = "Sippican T-4";

    static constexpr double      _SIPPICAN_T5_COEFFICIENT_A = 6.828;
    static constexpr double      _SIPPICAN_T5_COEFFICIENT_B = -1.82;
    static constexpr double      _SIPPICAN_T5_MAX_DEPTH = 1830.00;
    static constexpr const char* _SIPPICAN_T5_DESCRIPTION = "Sippican T-5";

    static constexpr double      _SIPPICAN_FAST_DEEP_COEFFICIENT_A = 6.390;
    static constexpr double      _SIPPICAN_FAST_DEEP_COEFFICIENT_B = -1.82;
    static constexpr double      _SIPPICAN_FAST_DEEP_MAX_DEPTH = 1000.00;
    static constexpr const char* _SIPPICAN_FAST_DEEP_DESCRIPTION = "Sippican Fast Deep";

    static constexpr double      _SIPPICAN_T6_OLD_COEFFICIENT_A = 6.472;
    static constexpr double      _SIPPICAN_T6_OLD_COEFFICIENT_B = -2.16;
    static constexpr double      _SIPPICAN_T6_OLD_MAX_DEPTH = 460.00;
    static constexpr const char* _SIPPICAN_T6_OLD_DESCRIPTION = "Sippican T-6";

    static constexpr double      _SIPPICAN_T6_COEFFICIENT_A = 6.691;
    static constexpr double      _SIPPICAN_T6_COEFFICIENT_B = -2.25;
    static constexpr double      _SIPPICAN_T6_MAX_DEPTH = 460.00;
    static constexpr const char* _SIPPICAN_T6_DESCRIPTION = "Sippican T-6";

    static constexpr double      _SIPPICAN_T7_OLD_COEFFICIENT_A = 6.472;
    static constexpr double      _SIPPICAN_T7_OLD_COEFFICIENT_B = -2.16;
    static constexpr double      _SIPPICAN_T7_OLD_MAX_DEPTH = 760.00;
    static constexpr const char* _SIPPICAN_T7_OLD_DESCRIPTION = "Sippican T-7";

    static constexpr double      _SIPPICAN_T7_COEFFICIENT_A = 6.691;
    static constexpr double      _SIPPICAN_T7_COEFFICIENT_B = -2.25;
    static constexpr double      _SIPPICAN_T7_MAX_DEPTH = 760.00;
    static constexpr const char* _SIPPICAN_T7_DESCRIPTION = "Sippican T-7";

    static constexpr double      _SIPPICAN_DEEP_BLUE_OLD_COEFFICIENT_A = 6.472;
    static constexpr double      _SIPPICAN_DEEP_BLUE_OLD_COEFFICIENT_B = -2.16;
    static constexpr double      _SIPPICAN_DEEP_BLUE_OLD_MAX_DEPTH = 760.00;
    static constexpr const char* _SIPPICAN_DEEP_BLUE_OLD_DESCRIPTION = "Sippican Deep Blue";

    static constexpr double      _SIPPICAN_DEEP_BLUE_COEFFICIENT_A = 6.691;
    static constexpr double      _SIPPICAN_DEEP_BLUE_COEFFICIENT_B = -2.25;
    static constexpr double      _SIPPICAN_DEEP_BLUE_MAX_DEPTH = 760.00;
    static constexpr const char* _SIPPICAN_DEEP_BLUE_DESCRIPTION = "Sippican Deep Blue";

    static constexpr double      _SIPPICAN_T10_COEFFICIENT_A = 6.301;
    static constexpr double      _SIPPICAN_T10_COEFFICIENT_B = -2.16;
    static constexpr double      _SIPPICAN_T10_MAX_DEPTH = 200.00;
    static constexpr const char* _SIPPICAN_T10_DESCRIPTION = "Sippican T-10";

    static constexpr double      _SIPPICAN_T11_COEFFICIENT_A = 1.779;
    static constexpr double      _SIPPICAN_T11_COEFFICIENT_B = -0.255;
    static constexpr double      _SIPPICAN_T11_MAX_DEPTH = 460.00;
    static constexpr const char* _SIPPICAN_T11_DESCRIPTION = "Sippican T-11";

    static constexpr double      _SIPPICAN_AXBT_COEFFICIENT_A = 1.52;
    static constexpr double      _SIPPICAN_AXBT_COEFFICIENT_B = 0.0;
    static constexpr double      _SIPPICAN_AXBT_MAX_DEPTH = 460.00;
    static constexpr const char* _SIPPICAN_AXBT_DESCRIPTION = "Sippican AXBT";

    static constexpr double      _TSK_T4_OLD_COEFFICIENT_A = 6.472;
    static constexpr double      _TSK_T4_OLD_COEFFICIENT_B = -2.16;
    static constexpr double      _TSK_T4_OLD_MAX_DEPTH = 460.00;
    static constexpr const char* _TSK_T4_OLD_DESCRIPTION = "TSK T-4";

    static constexpr double      _TSK_T4_COEFFICIENT_A = 6.691;
    static constexpr double      _TSK_T4_COEFFICIENT_B = -2.25;
    static constexpr double      _TSK_T4_MAX_DEPTH = 460.00;
    static constexpr const char* _TSK_T4_DESCRIPTION = "TSK T-4";

    static constexpr double      _TSK_T6_OLD_COEFFICIENT_A = 6.472;
    static constexpr double      _TSK_T6_OLD_COEFFICIENT_B = -2.16;
    static constexpr double      _TSK_T6_OLD_MAX_DEPTH = 460.00;
    static constexpr const char* _TSK_T6_OLD_DESCRIPTION = "TSK T-6";

    static constexpr double      _TSK_T6_COEFFICIENT_A = 6.691;
    static constexpr double      _TSK_T6_COEFFICIENT_B = -2.25;
    static constexpr double      _TSK_T6_MAX_DEPTH = 460.00;
    static constexpr const char* _TSK_T6_DESCRIPTION = "TSK T-6";

    static constexpr double      _TSK_T7_OLD_COEFFICIENT_A = 6.472;
    static constexpr double      _TSK_T7_OLD_COEFFICIENT_B = -2.16;
    static constexpr double      _TSK_T7_OLD_MAX_DEPTH = 760.00;
    static constexpr const char* _TSK_T7_OLD_DESCRIPTION = "TSK T-7";

    static constexpr double      _TSK_T7_COEFFICIENT_A = 6.691;
    static constexpr double      _TSK_T7_COEFFICIENT_B = -2.25;
    static constexpr double      _TSK_T7_MAX_DEPTH = 760.00;
    static constexpr const char* _TSK_T7_DESCRIPTION = "TSK T-7";

    static constexpr double      _TSK_T5_COEFFICIENT_A = 6.828;
    static constexpr double      _TSK_T5_COEFFICIENT_B = -1.82;
    static constexpr double      _TSK_T5_MAX_DEPTH = 1830.00;
    static constexpr const char* _TSK_T5_DESCRIPTION = "TSK T-5";

    static constexpr double      _TSK_T10_COEFFICIENT_A = 6.301;
    static constexpr double      _TSK_T10_COEFFICIENT_B = -2.16;
    static constexpr double      _TSK_T10_MAX_DEPTH = 200.00;
    static constexpr const char* _TSK_T10_DESCRIPTION = "TSK T-10";

    static constexpr double      _TSK_DEEP_BLUE_OLD_COEFFICIENT_A = 6.472;
    static constexpr double      _TSK_DEEP_BLUE_OLD_COEFFICIENT_B = -2.16;
    static constexpr double      _TSK_DEEP_BLUE_OLD_MAX_DEPTH = 760.00;
    static constexpr const char* _TSK_DEEP_BLUE_OLD_DESCRIPTION = "TSK Deep Blue";

    static constexpr double      _TSK_DEEP_BLUE_COEFFICIENT_A = 6.691;
    static constexpr double      _TSK_DEEP_BLUE_COEFFICIENT_B = -2.25;
    static constexpr double      _TSK_DEEP_BLUE_MAX_DEPTH = 760.00;
    static constexpr const char* _TSK_DEEP_BLUE_DESCRIPTION = "TSK Deep Blue";

    static constexpr double      _TSK_AXBT_COEFFICIENT_A = -1;
    static constexpr double      _TSK_AXBT_COEFFICIENT_B = -1;
    static constexpr double      _TSK_AXBT_MAX_DEPTH = 4000.00;
    static constexpr const char* _TSK_AXBT_DESCRIPTION = "TSK AXBT";

    static constexpr double      _SPARTON_XBT1_COEFFICIENT_A = 6.301;
    static constexpr double      _SPARTON_XBT1_COEFFICIENT_B = -2.16;
    static constexpr double      _SPARTON_XBT1_MAX_DEPTH = 4000.00;
    static constexpr const char* _SPARTON_XBT1_DESCRIPTION = "Sparton XBT-1";

    static constexpr double      _SPARTON_XBT3_COEFFICIENT_A = 5.861;
    static constexpr double      _SPARTON_XBT3_COEFFICIENT_B = -0.0904;
    static constexpr double      _SPARTON_XBT3_MAX_DEPTH = 4000.00;
    static constexpr const char* _SPARTON_XBT3_DESCRIPTION = "Sparton XBT-3";

    static constexpr double      _SPARTON_XBT4_COEFFICIENT_A = 6.472;
    static constexpr double      _SPARTON_XBT4_COEFFICIENT_B = -2.16;
    static constexpr double      _SPARTON_XBT4_MAX_DEPTH = 4000.00;
    static constexpr const char* _SPARTON_XBT4_DESCRIPTION = "Sparton XBT-4";

    static constexpr double      _SPARTON_XBT5_COEFFICIENT_A = 6.828;
    static constexpr double      _SPARTON_XBT5_COEFFICIENT_B = -1.82;
    static constexpr double      _SPARTON_XBT5_MAX_DEPTH = 4000.00;
    static constexpr const char* _SPARTON_XBT5_DESCRIPTION = "Sparton XBT-5";

    static constexpr double      _SPARTON_XBT5DB_COEFFICIENT_A = 6.828;
    static constexpr double      _SPARTON_XBT5DB_COEFFICIENT_B = -1.82;
    static constexpr double      _SPARTON_XBT5DB_MAX_DEPTH = 4000.00;
    static constexpr const char* _SPARTON_XBT5DB_DESCRIPTION = "Sparton XBT-5DB";

    static constexpr double      _SPARTON_XBT6_COEFFICIENT_A = 6.472;
    static constexpr double      _SPARTON_XBT6_COEFFICIENT_B = -2.16;
    static constexpr double      _SPARTON_XBT6_MAX_DEPTH = 4000.00;
    static constexpr const char* _SPARTON_XBT6_DESCRIPTION = "Sparton XBT-6";

    static constexpr double      _SPARTON_XBT7_OLD_COEFFICIENT_A = 6.472;
    static constexpr double      _SPARTON_XBT7_OLD_COEFFICIENT_B = -2.16;
    static constexpr double      _SPARTON_XBT7_OLD_MAX_DEPTH = 4000.00;
    static constexpr const char* _SPARTON_XBT7_OLD_DESCRIPTION = "Sparton XBT-7";

    static constexpr double      _SPARTON_XBT7_COEFFICIENT_A = 6.705;
    static constexpr double      _SPARTON_XBT7_COEFFICIENT_B = -2.28;
    static constexpr double      _SPARTON_XBT7_MAX_DEPTH = 4000.00;
    static constexpr const char* _SPARTON_XBT7_DESCRIPTION = "Sparton XBT-7";

    static constexpr double      _SPARTON_XBT7DB_COEFFICIENT_A = 6.472;
    static constexpr double      _SPARTON_XBT7DB_COEFFICIENT_B = -2.16;
    static constexpr double      _SPARTON_XBT7DB_MAX_DEPTH = 4000.00;
    static constexpr const char* _SPARTON_XBT7DB_DESCRIPTION = "Sparton XBT-7DB";

    static constexpr double      _SPARTON_XBT10_COEFFICIENT_A = 6.301;
    static constexpr double      _SPARTON_XBT10_COEFFICIENT_B = -2.16;
    static constexpr double      _SPARTON_XBT10_MAX_DEPTH = 4000.00;
    static constexpr const char* _SPARTON_XBT10_DESCRIPTION = "Sparton XBT-10";

    static constexpr double      _SPARTON_XBT20_COEFFICIENT_A = 6.472;
    static constexpr double      _SPARTON_XBT20_COEFFICIENT_B = -2.16;
    static constexpr double      _SPARTON_XBT20_MAX_DEPTH = 4000.00;
    static constexpr const char* _SPARTON_XBT20_DESCRIPTION = "Sparton XBT-20";

    static constexpr double      _SPARTON_XBT20DB_COEFFICIENT_A = 6.472;
    static constexpr double      _SPARTON_XBT20DB_COEFFICIENT_B = -2.16;
    static constexpr double      _SPARTON_XBT20DB_MAX_DEPTH = 4000.00;
    static constexpr const char* _SPARTON_XBT20DB_DESCRIPTION = "Sparton XBT-20DB";

    static constexpr double      _SPARTON_536AXBT_COEFFICIENT_A = 1.524;
    static constexpr double      _SPARTON_536AXBT_COEFFICIENT_B = 0.0;
    static constexpr double      _SPARTON_536AXBT_MAX_DEPTH = 4000.00;
    static constexpr const char* _SPARTON_536AXBT_DESCRIPTION = "Sparton 536 AXBT-7";

    static constexpr double      _SIPPICAN_12_COEFFICIENT_A = 9.727;
    static constexpr double      _SIPPICAN_12_COEFFICIENT_B = -0.0000473;
    static constexpr double      _SIPPICAN_12_MAX_DEPTH = 2000.00;
    static constexpr const char* _SIPPICAN_12_DESCRIPTION = "Sippican T-12 (LMP5-T1)";

};

#endif /* XBTPROBE_H_ */
