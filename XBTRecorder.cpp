/**
 * This class contains constants that hold the value for the type of XBT
 * recorder and the frequency at which the XBT recorder samples.
 *
 * @author Pedro Pena
 * @version 1.0
 *
 */

#include "XBTRecorder.h"

constexpr int          SIPPICAN_STRIP_CHART_RECORDER = 1;
constexpr double      _SIPPICAN_STRIP_CHART_RECORDER_SAMPLE_FREQUENCY = 10.0;
constexpr const char* _SIPPICAN_STRIP_CHART_RECORDER_DESCRIPTION = "Sippican Strip Chart Recorder";

constexpr int          SIPPICAN_MK2A_SSQ61 = 2;
constexpr double      _SIPPICAN_MK2A_SSQ61_SAMPLE_FREQUENCY = 10.0;
constexpr const char* _SIPPICAN_MK2A_SSQ61_DESCRIPTION = "Sippican MK2A/SSQ-61";

constexpr int          SIPPICAN_MK_9 = 3;
constexpr double      _SIPPICAN_MK_9_SAMPLE_FREQUENCY = 10.0;
constexpr const char* _SIPPICAN_MK_9_DESCRIPTION = "Sippican MK-9";

constexpr int          SIPPICAN_AN_BHQ7_MK8 = 4;
constexpr double      _SIPPICAN_AN_BHQ7_MK8_SAMPLE_FREQUENCY = 10.0;
constexpr const char* _SIPPICAN_AN_BHQ7_MK8_DESCRIPTION = "Sippican AN/BHQ-7/MK8";

constexpr int          SIPPICAN_MK_12 = 5;
constexpr double      _SIPPICAN_MK_12_SAMPLE_FREQUENCY = 10.0;
constexpr const char* _SIPPICAN_MK_12_DESCRIPTION = "Sippican MK-12";

constexpr int          SIPPICAN_MK_21 = 6;
constexpr double      _SIPPICAN_MK_21_SAMPLE_FREQUENCY = 10.0;
constexpr const char* _SIPPICAN_MK_21_DESCRIPTION = "Sippican MK-21";

constexpr int          SPARTON_SOC_BT_SV_PROCESSOR_MODEL10 = 10;
constexpr double      _SPARTON_SOC_BT_SV_PROCESSOR_MODEL10_SAMPLE_FREQUENCY = 10.0;
constexpr const char* _SPARTON_SOC_BT_SV_PROCESSOR_MODEL10_DESCRIPTION = "Sparton SOC BT/SV Processor Model 10";

constexpr int          LOCKHEED_SANDERS_MODEL_QL5005 = 11;
constexpr double      _LOCKHEED_SANDERS_MODEL_QL5005_SAMPLE_FREQUENCY = 10.0;
constexpr const char* _LOCKHEED_SANDERS_MODEL_QL5005_DESCRIPTION = "Lockheed-Sanders Model QL5005";

constexpr int          ARGOS_XBT_ST = 20;
constexpr double      _ARGOS_XBT_ST_SAMPLE_FREQUENCY = 10.0;
constexpr const char* _ARGOS_XBT_ST_DESCRIPTION = "ARGOS XBT-ST";

constexpr int          CLS_ARGOS_PROTECNO_XBT_ST_MODEL_1 = 21;
constexpr double      _CLS_ARGOS_PROTECNO_XBT_ST_MODEL_1_SAMPLE_FREQUENCY = 10.0;
constexpr const char* _CLS_ARGOS_PROTECNO_XBT_ST_MODEL_1_DESCRIPTION = "CLS-ARGOS/Protecno XBT-ST Model-1";

constexpr int          CLS_ARGOS_PROTECNO_XBT_ST_MODEL_2 = 22;
constexpr double      _CLS_ARGOS_PROTECNO_XBT_ST_MODEL_2_SAMPLE_FREQUENCY = 10.0;
constexpr const char* _CLS_ARGOS_PROTECNO_XBT_ST_MODEL_2_DESCRIPTION = "CLS-ARGOS/Protecno XBT-ST Model-2";

constexpr int          BATHY_SYSTEMS_SA_810 = 30;
constexpr double      _BATHY_SYSTEMS_SA_810_SAMPLE_FREQUENCY = 10.0;
constexpr const char* _BATHY_SYSTEMS_SA_810_DESCRIPTION = "Bathy Systems SA-810";

constexpr int          SCRIPPS_METROBYTE_CONTROLLER = 31;
constexpr double      _SCRIPPS_METROBYTE_CONTROLLER_SAMPLE_FREQUENCY = 10.0;
constexpr const char* _SCRIPPS_METROBYTE_CONTROLLER_DESCRIPTION = "Scripps Metrobyte Controller";

constexpr int          MURAYAMA_DENKI_Z_60_16_III = 32;
constexpr double      _MURAYAMA_DENKI_Z_60_16_III_SAMPLE_FREQUENCY = 10.0;
constexpr const char* _MURAYAMA_DENKI_Z_60_16_III_DESCRIPTION = "Murayama Denki Z-60-16 III";

constexpr int          MURAYAMA_DENKI_Z_60_16_II = 33;
constexpr double      _MURAYAMA_DENKI_Z_60_16_II_SAMPLE_FREQUENCY = 10.0;
constexpr const char* _MURAYAMA_DENKI_Z_60_16_II_DESCRIPTION = "Murayama Denki Z-60-16 II";

constexpr int          PROTECNO_ETSM2 = 34;
constexpr double      _PROTECNO_ETSM2_SAMPLE_FREQUENCY = 10.0;
constexpr const char* _PROTECNO_ETSM2_DESCRIPTION = "Protecno ETSM2";

constexpr int          NAUTILUS_MARINE_SERVICE_NMS_XBT = 35;
constexpr double      _NAUTILUS_MARINE_SERVICE_NMS_XBT_SAMPLE_FREQUENCY = 10.0;
constexpr const char* _NAUTILUS_MARINE_SERVICE_NMS_XBT_DESCRIPTION = "Nautilus Marine Service NMS-XBT";

constexpr int          TSK_MK_2A = 40;
constexpr double      _TSK_MK_2A_SAMPLE_FREQUENCY = 10.0;
constexpr const char* _TSK_MK_2A_DESCRIPTION = "TSK MK-2A";

constexpr int          TSK_MK_2S = 41;
constexpr double      _TSK_MK_2S_SAMPLE_FREQUENCY = 10.0;
constexpr const char* _TSK_MK_2S_DESCRIPTION = "TSK MK-2S";

constexpr int          TSK_MK_30 = 42;
constexpr double      _TSK_MK_30_SAMPLE_FREQUENCY = 10.0;
constexpr const char* _TSK_MK_30_DESCRIPTION = "SK MK-30";

constexpr int          TSK_MK_30N = 43;
constexpr double      _TSK_MK_30N_SAMPLE_FREQUENCY = 10.0;
constexpr const char* _TSK_MK_30N_DESCRIPTION = "TSK MK-30N";

constexpr int          TSK_MK_100 = 45;
constexpr double      _TSK_MK_100_SAMPLE_FREQUENCY = 10.0;
constexpr const char* _TSK_MK_100_DESCRIPTION = "TSK MK-100";

constexpr int          TSK_MK_130 = 46;
constexpr double      _TSK_MK_130_SAMPLE_FREQUENCY = 10.0;
constexpr const char* _TSK_MK_130_DESCRIPTION = "TSK MK-130";

constexpr int          TSK_AXBT_RECEIVER_MK_300 = 48;
constexpr double      _TSK_AXBT_RECEIVER_MK_300_SAMPLE_FREQUENCY = 10.0;
constexpr const char* _TSK_AXBT_RECEIVER_MK_300_DESCRIPTION = "TSK AXBT Receiver MK-300";

constexpr int          JMA_ASTOS = 50;
constexpr double      _JMA_ASTOS_SAMPLE_FREQUENCY = 10.0;
constexpr const char* _JMA_ASTOS_DESCRIPTION = "JMA ASTOS";

constexpr int          ARGOS_COMMUNICATIONS_SAMPLING_ON_UP_TRANSIT = 60;
constexpr double      _ARGOS_COMMUNICATIONS_SAMPLING_ON_UP_TRANSIT_SAMPLE_FREQUENCY = 10.0;
constexpr const char* _ARGOS_COMMUNICATIONS_SAMPLING_ON_UP_TRANSIT_DESCRIPTION = "ARGOS Communications, Sampling on up transit";

constexpr int          ARGOS_COMMUNICATIONS_SAMPLING_ON_DOWN_TRANSIT = 61;
constexpr double      _ARGOS_COMMUNICATIONS_SAMPLING_ON_DOWN_TRANSIT_SAMPLE_FREQUENCY = 10.0;
constexpr const char* _ARGOS_COMMUNICATIONS_SAMPLING_ON_DOWN_TRANSIT_DESCRIPTION = "ARGOS Communications, Sampling on down transit";

constexpr int          ORBCOMM_COMMUNICATIONS_SAMPLING_ON_UP_TRANSIT = 62;
constexpr double      _ORBCOMM_COMMUNICATIONS_SAMPLING_ON_UP_TRANSIT_SAMPLE_FREQUENCY = 10.0;
constexpr const char* _ORBCOMM_COMMUNICATIONS_SAMPLING_ON_UP_TRANSIT_DESCRIPTION = "Orbcomm Communications, Sampling on up transit";

constexpr int          ORBCOMM_COMMUNICATIONS_SAMPLING_ON_DOWN_TRANSIT = 63;
constexpr double      _ORBCOMM_COMMUNICATIONS_SAMPLING_ON_DOWN_TRANSIT_SAMPLE_FREQUENCY = 10.0;
constexpr const char* _ORBCOMM_COMMUNICATIONS_SAMPLING_ON_DOWN_TRANSIT_DESCRIPTION = "Orbcomm Communications, Sampling on down transit";

constexpr int          CSIRO_DEVIL_1 = 70;
constexpr double      _CSIRO_DEVIL_1_SAMPLE_FREQUENCY = 10.0;
constexpr const char* _CSIRO_DEVIL_1_DESCRIPTION = "CSIRO Devil-1";

constexpr int          CSIRO_DEVIL_2 = 71;
constexpr double      _CSIRO_DEVIL_2_SAMPLE_FREQUENCY = 10.0;
constexpr const char* _CSIRO_DEVIL_2_DESCRIPTION = "CSIRO Devil-2";

constexpr int          UNKNOWN = 99;
constexpr double      _UNKNOWN_SAMPLE_FREQUENCY = 10.0;
constexpr const char* _UNKNOWN_DESCRIPTION = "Unknown";
XBTRecorder::XBTRecorder() {
	// TODO Auto-generated constructor stub

}

XBTRecorder::~XBTRecorder() {
	// TODO Auto-generated destructor stub
}

double XBTRecorder::getRecorderFrequency(int recorderType) {
        double sampleFrequency =  10.00;
        switch (recorderType) {

            case SIPPICAN_STRIP_CHART_RECORDER:
                sampleFrequency =  _SIPPICAN_STRIP_CHART_RECORDER_SAMPLE_FREQUENCY;
                break;
            case SIPPICAN_MK2A_SSQ61:
                sampleFrequency =  _SIPPICAN_MK2A_SSQ61_SAMPLE_FREQUENCY;
                break;

            case SIPPICAN_MK_9:
                sampleFrequency =  _SIPPICAN_MK_9_SAMPLE_FREQUENCY;
                break;

            case SIPPICAN_AN_BHQ7_MK8:
                sampleFrequency =  _SIPPICAN_AN_BHQ7_MK8_SAMPLE_FREQUENCY;
                break;

            case SIPPICAN_MK_12:
                sampleFrequency =  _SIPPICAN_MK_12_SAMPLE_FREQUENCY;
                break;

            case SIPPICAN_MK_21:
                sampleFrequency =  _SIPPICAN_MK_21_SAMPLE_FREQUENCY;
                break;

            case SPARTON_SOC_BT_SV_PROCESSOR_MODEL10:
                sampleFrequency =  _SPARTON_SOC_BT_SV_PROCESSOR_MODEL10_SAMPLE_FREQUENCY;
                break;

            case LOCKHEED_SANDERS_MODEL_QL5005:
                sampleFrequency =  _LOCKHEED_SANDERS_MODEL_QL5005_SAMPLE_FREQUENCY;
                break;

            case ARGOS_XBT_ST:
                sampleFrequency =  _ARGOS_XBT_ST_SAMPLE_FREQUENCY;
                break;

            case CLS_ARGOS_PROTECNO_XBT_ST_MODEL_1:
                sampleFrequency =  _CLS_ARGOS_PROTECNO_XBT_ST_MODEL_1_SAMPLE_FREQUENCY;
                break;

            case CLS_ARGOS_PROTECNO_XBT_ST_MODEL_2:
                sampleFrequency =  _CLS_ARGOS_PROTECNO_XBT_ST_MODEL_2_SAMPLE_FREQUENCY;
                break;

            case BATHY_SYSTEMS_SA_810:
                sampleFrequency =  _BATHY_SYSTEMS_SA_810_SAMPLE_FREQUENCY;
                break;

            case SCRIPPS_METROBYTE_CONTROLLER:
                sampleFrequency =  _SCRIPPS_METROBYTE_CONTROLLER_SAMPLE_FREQUENCY;
                break;

            case MURAYAMA_DENKI_Z_60_16_III:
                sampleFrequency =  _MURAYAMA_DENKI_Z_60_16_III_SAMPLE_FREQUENCY;
                break;

            case MURAYAMA_DENKI_Z_60_16_II:
                sampleFrequency =  _MURAYAMA_DENKI_Z_60_16_II_SAMPLE_FREQUENCY;
                break;

            case PROTECNO_ETSM2:
                sampleFrequency =  _PROTECNO_ETSM2_SAMPLE_FREQUENCY;
                break;

            case NAUTILUS_MARINE_SERVICE_NMS_XBT:
                sampleFrequency =  _NAUTILUS_MARINE_SERVICE_NMS_XBT_SAMPLE_FREQUENCY;
                break;

            case TSK_MK_2A:
                sampleFrequency =  _TSK_MK_2A_SAMPLE_FREQUENCY;
                break;
            case TSK_MK_2S:
                sampleFrequency =  _TSK_MK_2S_SAMPLE_FREQUENCY;
                break;
            case TSK_MK_30:
                sampleFrequency =  _TSK_MK_30_SAMPLE_FREQUENCY;
                break;

            case TSK_MK_30N:
                sampleFrequency =  _TSK_MK_30N_SAMPLE_FREQUENCY;
                break;

            case TSK_MK_100:
                sampleFrequency =  _TSK_MK_100_SAMPLE_FREQUENCY;
                break;

            case TSK_MK_130:
                sampleFrequency =  _TSK_MK_130_SAMPLE_FREQUENCY;
                break;

            case TSK_AXBT_RECEIVER_MK_300:
                sampleFrequency =  _TSK_AXBT_RECEIVER_MK_300_SAMPLE_FREQUENCY;
                break;

            case JMA_ASTOS:
                sampleFrequency =  _JMA_ASTOS_SAMPLE_FREQUENCY;
                break;

            case ARGOS_COMMUNICATIONS_SAMPLING_ON_UP_TRANSIT:
                sampleFrequency =  _ARGOS_COMMUNICATIONS_SAMPLING_ON_UP_TRANSIT_SAMPLE_FREQUENCY;
                break;

            case ARGOS_COMMUNICATIONS_SAMPLING_ON_DOWN_TRANSIT:
                sampleFrequency =  _ARGOS_COMMUNICATIONS_SAMPLING_ON_DOWN_TRANSIT_SAMPLE_FREQUENCY;
                break;
            case ORBCOMM_COMMUNICATIONS_SAMPLING_ON_UP_TRANSIT:
                sampleFrequency =  _ORBCOMM_COMMUNICATIONS_SAMPLING_ON_UP_TRANSIT_SAMPLE_FREQUENCY;
                break;

            case ORBCOMM_COMMUNICATIONS_SAMPLING_ON_DOWN_TRANSIT:
                sampleFrequency =  _ORBCOMM_COMMUNICATIONS_SAMPLING_ON_DOWN_TRANSIT_SAMPLE_FREQUENCY;
                break;

            case CSIRO_DEVIL_1:
                sampleFrequency =  _CSIRO_DEVIL_1_SAMPLE_FREQUENCY;
                break;

            case CSIRO_DEVIL_2:
                sampleFrequency =  _CSIRO_DEVIL_2_SAMPLE_FREQUENCY;
                break;

            case UNKNOWN:
                sampleFrequency =  _UNKNOWN_SAMPLE_FREQUENCY;
                break;

        }//end switch
        return sampleFrequency;
    }//end method
std::string XBTRecorder::getRecorderDescription(int recorderType) {
        const char* description =  "Unknown";
        switch (recorderType) {

            case SIPPICAN_STRIP_CHART_RECORDER:
                description =  _SIPPICAN_STRIP_CHART_RECORDER_DESCRIPTION;
                break;
            case SIPPICAN_MK2A_SSQ61:
                description =  _SIPPICAN_MK2A_SSQ61_DESCRIPTION;
                break;

            case SIPPICAN_MK_9:
                description =  _SIPPICAN_MK_9_DESCRIPTION;
                break;

            case SIPPICAN_AN_BHQ7_MK8:
                description =  _SIPPICAN_AN_BHQ7_MK8_DESCRIPTION;
                break;

            case SIPPICAN_MK_12:
                description =  _SIPPICAN_MK_12_DESCRIPTION;
                break;

            case SIPPICAN_MK_21:
                description =  _SIPPICAN_MK_21_DESCRIPTION;
                break;

            case SPARTON_SOC_BT_SV_PROCESSOR_MODEL10:
                description =  _SPARTON_SOC_BT_SV_PROCESSOR_MODEL10_DESCRIPTION;
                break;

            case LOCKHEED_SANDERS_MODEL_QL5005:
                description =  _LOCKHEED_SANDERS_MODEL_QL5005_DESCRIPTION;
                break;

            case ARGOS_XBT_ST:
                description =  _ARGOS_XBT_ST_DESCRIPTION;
                break;

            case CLS_ARGOS_PROTECNO_XBT_ST_MODEL_1:
                description =  _CLS_ARGOS_PROTECNO_XBT_ST_MODEL_1_DESCRIPTION;
                break;

            case CLS_ARGOS_PROTECNO_XBT_ST_MODEL_2:
                description =  _CLS_ARGOS_PROTECNO_XBT_ST_MODEL_2_DESCRIPTION;
                break;

            case BATHY_SYSTEMS_SA_810:
                description =  _BATHY_SYSTEMS_SA_810_DESCRIPTION;
                break;

            case SCRIPPS_METROBYTE_CONTROLLER:
                description =  _SCRIPPS_METROBYTE_CONTROLLER_DESCRIPTION;
                break;

            case MURAYAMA_DENKI_Z_60_16_III:
                description =  _MURAYAMA_DENKI_Z_60_16_III_DESCRIPTION;
                break;

            case MURAYAMA_DENKI_Z_60_16_II:
                description =  _MURAYAMA_DENKI_Z_60_16_II_DESCRIPTION;
                break;

            case PROTECNO_ETSM2:
                description =  _PROTECNO_ETSM2_DESCRIPTION;
                break;

            case NAUTILUS_MARINE_SERVICE_NMS_XBT:
                description =  _NAUTILUS_MARINE_SERVICE_NMS_XBT_DESCRIPTION;
                break;

            case TSK_MK_2A:
                description =  _TSK_MK_2A_DESCRIPTION;
                break;
            case TSK_MK_2S:
                description =  _TSK_MK_2S_DESCRIPTION;
                break;
            case TSK_MK_30:
                description =  _TSK_MK_30_DESCRIPTION;
                break;

            case TSK_MK_30N:
                description =  _TSK_MK_30N_DESCRIPTION;
                break;

            case TSK_MK_100:
                description =  _TSK_MK_100_DESCRIPTION;
                break;

            case TSK_MK_130:
                description =  _TSK_MK_130_DESCRIPTION;
                break;

            case TSK_AXBT_RECEIVER_MK_300:
                description =  _TSK_AXBT_RECEIVER_MK_300_DESCRIPTION;
                break;

            case JMA_ASTOS:
                description =  _JMA_ASTOS_DESCRIPTION;
                break;

            case ARGOS_COMMUNICATIONS_SAMPLING_ON_UP_TRANSIT:
                description =  _ARGOS_COMMUNICATIONS_SAMPLING_ON_UP_TRANSIT_DESCRIPTION;
                break;

            case ARGOS_COMMUNICATIONS_SAMPLING_ON_DOWN_TRANSIT:
                description =  _ARGOS_COMMUNICATIONS_SAMPLING_ON_DOWN_TRANSIT_DESCRIPTION;
                break;
            case ORBCOMM_COMMUNICATIONS_SAMPLING_ON_UP_TRANSIT:
                description =  _ORBCOMM_COMMUNICATIONS_SAMPLING_ON_UP_TRANSIT_DESCRIPTION;
                break;

            case ORBCOMM_COMMUNICATIONS_SAMPLING_ON_DOWN_TRANSIT:
                description =  _ORBCOMM_COMMUNICATIONS_SAMPLING_ON_DOWN_TRANSIT_DESCRIPTION;
                break;

            case CSIRO_DEVIL_1:
                description =  _CSIRO_DEVIL_1_DESCRIPTION;
                break;

            case CSIRO_DEVIL_2:
                description =  _CSIRO_DEVIL_2_DESCRIPTION;
                break;

            case UNKNOWN:
                description =  _UNKNOWN_DESCRIPTION;
                break;

        }//end switch
        return std::string(description);
    }//end method
