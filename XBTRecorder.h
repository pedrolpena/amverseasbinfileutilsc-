/**
 * This class contains constants that hold the value for the type of XBT
 * recorder and the frequency at which the XBT recorder samples.
 *
 * @author Pedro Pena
 * @version 1.0
 *
 */

#ifndef XBTRECORDER_H_
#define XBTRECORDER_H_
#include <string>

class XBTRecorder {
public:
    static constexpr int          SIPPICAN_STRIP_CHART_RECORDER = 1;
    static constexpr double      _SIPPICAN_STRIP_CHART_RECORDER_SAMPLE_FREQUENCY = 10.0;
    static constexpr const char* _SIPPICAN_STRIP_CHART_RECORDER_DESCRIPTION = "Sippican Strip Chart Recorder";

    static constexpr int          SIPPICAN_MK2A_SSQ61 = 2;
    static constexpr double      _SIPPICAN_MK2A_SSQ61_SAMPLE_FREQUENCY = 10.0;
    static constexpr const char* _SIPPICAN_MK2A_SSQ61_DESCRIPTION = "Sippican MK2A/SSQ-61";

    static constexpr int          SIPPICAN_MK_9 = 3;
    static constexpr double      _SIPPICAN_MK_9_SAMPLE_FREQUENCY = 10.0;
    static constexpr const char* _SIPPICAN_MK_9_DESCRIPTION = "Sippican MK-9";

    static constexpr int          SIPPICAN_AN_BHQ7_MK8 = 4;
    static constexpr double      _SIPPICAN_AN_BHQ7_MK8_SAMPLE_FREQUENCY = 10.0;
    static constexpr const char* _SIPPICAN_AN_BHQ7_MK8_DESCRIPTION = "Sippican AN/BHQ-7/MK8";

    static constexpr int          SIPPICAN_MK_12 = 5;
    static constexpr double      _SIPPICAN_MK_12_SAMPLE_FREQUENCY = 10.0;
    static constexpr const char* _SIPPICAN_MK_12_DESCRIPTION = "Sippican MK-12";

    static constexpr int          SIPPICAN_MK_21 = 6;
    static constexpr double      _SIPPICAN_MK_21_SAMPLE_FREQUENCY = 10.0;
    static constexpr const char* _SIPPICAN_MK_21_DESCRIPTION = "Sippican MK-21";

    static constexpr int          SPARTON_SOC_BT_SV_PROCESSOR_MODEL10 = 10;
    static constexpr double      _SPARTON_SOC_BT_SV_PROCESSOR_MODEL10_SAMPLE_FREQUENCY = 10.0;
    static constexpr const char* _SPARTON_SOC_BT_SV_PROCESSOR_MODEL10_DESCRIPTION = "Sparton SOC BT/SV Processor Model 10";

    static constexpr int          LOCKHEED_SANDERS_MODEL_QL5005 = 11;
    static constexpr double      _LOCKHEED_SANDERS_MODEL_QL5005_SAMPLE_FREQUENCY = 10.0;
    static constexpr const char* _LOCKHEED_SANDERS_MODEL_QL5005_DESCRIPTION = "Lockheed-Sanders Model QL5005";

    static constexpr int          ARGOS_XBT_ST = 20;
    static constexpr double      _ARGOS_XBT_ST_SAMPLE_FREQUENCY = 10.0;
    static constexpr const char* _ARGOS_XBT_ST_DESCRIPTION = "ARGOS XBT-ST";

    static constexpr int          CLS_ARGOS_PROTECNO_XBT_ST_MODEL_1 = 21;
    static constexpr double      _CLS_ARGOS_PROTECNO_XBT_ST_MODEL_1_SAMPLE_FREQUENCY = 10.0;
    static constexpr const char* _CLS_ARGOS_PROTECNO_XBT_ST_MODEL_1_DESCRIPTION = "CLS-ARGOS/Protecno XBT-ST Model-1";

    static constexpr int          CLS_ARGOS_PROTECNO_XBT_ST_MODEL_2 = 22;
    static constexpr double      _CLS_ARGOS_PROTECNO_XBT_ST_MODEL_2_SAMPLE_FREQUENCY = 10.0;
    static constexpr const char* _CLS_ARGOS_PROTECNO_XBT_ST_MODEL_2_DESCRIPTION = "CLS-ARGOS/Protecno XBT-ST Model-2";

    static constexpr int          BATHY_SYSTEMS_SA_810 = 30;
    static constexpr double      _BATHY_SYSTEMS_SA_810_SAMPLE_FREQUENCY = 10.0;
    static constexpr const char* _BATHY_SYSTEMS_SA_810_DESCRIPTION = "Bathy Systems SA-810";

    static constexpr int          SCRIPPS_METROBYTE_CONTROLLER = 31;
    static constexpr double      _SCRIPPS_METROBYTE_CONTROLLER_SAMPLE_FREQUENCY = 10.0;
    static constexpr const char* _SCRIPPS_METROBYTE_CONTROLLER_DESCRIPTION = "Scripps Metrobyte Controller";

    static constexpr int          MURAYAMA_DENKI_Z_60_16_III = 32;
    static constexpr double      _MURAYAMA_DENKI_Z_60_16_III_SAMPLE_FREQUENCY = 10.0;
    static constexpr const char* _MURAYAMA_DENKI_Z_60_16_III_DESCRIPTION = "Murayama Denki Z-60-16 III";

    static constexpr int          MURAYAMA_DENKI_Z_60_16_II = 33;
    static constexpr double      _MURAYAMA_DENKI_Z_60_16_II_SAMPLE_FREQUENCY = 10.0;
    static constexpr const char* _MURAYAMA_DENKI_Z_60_16_II_DESCRIPTION = "Murayama Denki Z-60-16 II";

    static constexpr int          PROTECNO_ETSM2 = 34;
    static constexpr double      _PROTECNO_ETSM2_SAMPLE_FREQUENCY = 10.0;
    static constexpr const char* _PROTECNO_ETSM2_DESCRIPTION = "Protecno ETSM2";

    static constexpr int          NAUTILUS_MARINE_SERVICE_NMS_XBT = 35;
    static constexpr double      _NAUTILUS_MARINE_SERVICE_NMS_XBT_SAMPLE_FREQUENCY = 10.0;
    static constexpr const char* _NAUTILUS_MARINE_SERVICE_NMS_XBT_DESCRIPTION = "Nautilus Marine Service NMS-XBT";

    static constexpr int          TSK_MK_2A = 40;
    static constexpr double      _TSK_MK_2A_SAMPLE_FREQUENCY = 10.0;
    static constexpr const char* _TSK_MK_2A_DESCRIPTION = "TSK MK-2A";

    static constexpr int          TSK_MK_2S = 41;
    static constexpr double      _TSK_MK_2S_SAMPLE_FREQUENCY = 10.0;
    static constexpr const char* _TSK_MK_2S_DESCRIPTION = "TSK MK-2S";

    static constexpr int          TSK_MK_30 = 42;
    static constexpr double      _TSK_MK_30_SAMPLE_FREQUENCY = 10.0;
    static constexpr const char* _TSK_MK_30_DESCRIPTION = "SK MK-30";

    static constexpr int          TSK_MK_30N = 43;
    static constexpr double      _TSK_MK_30N_SAMPLE_FREQUENCY = 10.0;
    static constexpr const char* _TSK_MK_30N_DESCRIPTION = "TSK MK-30N";

    static constexpr int          TSK_MK_100 = 45;
    static constexpr double      _TSK_MK_100_SAMPLE_FREQUENCY = 10.0;
    static constexpr const char* _TSK_MK_100_DESCRIPTION = "TSK MK-100";

    static constexpr int          TSK_MK_130 = 46;
    static constexpr double      _TSK_MK_130_SAMPLE_FREQUENCY = 10.0;
    static constexpr const char* _TSK_MK_130_DESCRIPTION = "TSK MK-130";

    static constexpr int          TSK_AXBT_RECEIVER_MK_300 = 48;
    static constexpr double      _TSK_AXBT_RECEIVER_MK_300_SAMPLE_FREQUENCY = 10.0;
    static constexpr const char* _TSK_AXBT_RECEIVER_MK_300_DESCRIPTION = "TSK AXBT Receiver MK-300";

    static constexpr int          JMA_ASTOS = 50;
    static constexpr double      _JMA_ASTOS_SAMPLE_FREQUENCY = 10.0;
    static constexpr const char* _JMA_ASTOS_DESCRIPTION = "JMA ASTOS";

    static constexpr int          ARGOS_COMMUNICATIONS_SAMPLING_ON_UP_TRANSIT = 60;
    static constexpr double      _ARGOS_COMMUNICATIONS_SAMPLING_ON_UP_TRANSIT_SAMPLE_FREQUENCY = 10.0;
    static constexpr const char* _ARGOS_COMMUNICATIONS_SAMPLING_ON_UP_TRANSIT_DESCRIPTION = "ARGOS Communications, Sampling on up transit";

    static constexpr int          ARGOS_COMMUNICATIONS_SAMPLING_ON_DOWN_TRANSIT = 61;
    static constexpr double      _ARGOS_COMMUNICATIONS_SAMPLING_ON_DOWN_TRANSIT_SAMPLE_FREQUENCY = 10.0;
    static constexpr const char* _ARGOS_COMMUNICATIONS_SAMPLING_ON_DOWN_TRANSIT_DESCRIPTION = "ARGOS Communications, Sampling on down transit";

    static constexpr int          ORBCOMM_COMMUNICATIONS_SAMPLING_ON_UP_TRANSIT = 62;
    static constexpr double      _ORBCOMM_COMMUNICATIONS_SAMPLING_ON_UP_TRANSIT_SAMPLE_FREQUENCY = 10.0;
    static constexpr const char* _ORBCOMM_COMMUNICATIONS_SAMPLING_ON_UP_TRANSIT_DESCRIPTION = "Orbcomm Communications, Sampling on up transit";

    static constexpr int          ORBCOMM_COMMUNICATIONS_SAMPLING_ON_DOWN_TRANSIT = 63;
    static constexpr double      _ORBCOMM_COMMUNICATIONS_SAMPLING_ON_DOWN_TRANSIT_SAMPLE_FREQUENCY = 10.0;
    static constexpr const char* _ORBCOMM_COMMUNICATIONS_SAMPLING_ON_DOWN_TRANSIT_DESCRIPTION = "Orbcomm Communications, Sampling on down transit";

    static constexpr int          CSIRO_DEVIL_1 = 70;
    static constexpr double      _CSIRO_DEVIL_1_SAMPLE_FREQUENCY = 10.0;
    static constexpr const char* _CSIRO_DEVIL_1_DESCRIPTION = "CSIRO Devil-1";

    static constexpr int          CSIRO_DEVIL_2 = 71;
    static constexpr double      _CSIRO_DEVIL_2_SAMPLE_FREQUENCY = 10.0;
    static constexpr const char* _CSIRO_DEVIL_2_DESCRIPTION = "CSIRO Devil-2";

    static constexpr int          UNKNOWN = 99;
    static constexpr double      _UNKNOWN_SAMPLE_FREQUENCY = 10.0;
    static constexpr const char* _UNKNOWN_DESCRIPTION = "Unknown";

	XBTRecorder();
	virtual ~XBTRecorder();
	static double getRecorderFrequency(int);
	static std::string getRecorderDescription(int);
};

#endif /* XBTRECORDER_H_ */
