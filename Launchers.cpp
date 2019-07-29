/*
 * Launchers.cpp
 *
 *  Created on: Jul 20, 2019
 *      Author: pedro
 */

#include "Launchers.h"

constexpr  int         UNKNOWN = 0;
constexpr  const char* UNKNOWN_DESCRIPTION = "Unknown";
constexpr  int         LM_2A_DECK_MOUNTED = 1;
constexpr  const char* LM_2A_DECK_MOUNTED_DESCRIPTION = "LM-2A Deck-mounted";
constexpr  int         LM_3A_HAND_HELD = 2;
constexpr  const char* LM_3A_HAND_HELD_DESCRIPTION = "LM-3A Hand-Held";
constexpr  int         LM_4A_THRU_HULL = 3;
constexpr  const char* LM_4A_THRU_HULL_DESCRIPTION = "LM-4A Thru-Hull";
constexpr  int         AL_12_TSK_AUTOLAUNCHER = 10;
constexpr  const char* AL_12_TSK_AUTOLAUNCHER_DESCRIPTION = "AL-12 TSK Autolauncher (up to 12 Probes)";
constexpr  int         SIO_XBT_AUTOLAUNCHER = 20;
constexpr  const char* SIO_XBT_AUTOLAUNCHER_DESCRIPTION = "SIO XBT Autolauncher (up to 6 probes)";
constexpr  int         AOML_XBT_V6_AUTOLAUNCHER = 30;
constexpr  const char* AOML_XBT_V6_AUTOLAUNCHER_DESCRIPTION = "AOML XBT V6 Autolauncher (up to 6 Deep Blue probes)";
constexpr  int         AOML_XBT_V8_0_AUTOLAUNCHER = 31;
constexpr  const char* AOML_XBT_V8_0_AUTOLAUNCHER_DESCRIPTION = "AOML XBT V8.0 Autolauncher (up to 8 Deep Blue probes)";
constexpr  int         AOML_XBT_V8_1_AUTOLAUNCHER = 32;
constexpr  const char* AOML_XBT_V8_1_AUTOLAUNCHER_DESCRIPTION = "AOML XBT V8.1 Autolauncher (up to 8 Deep Blue and Fast Deep probes)";
constexpr  int         CSIRO_DEVIL_AUTOLAUNCHER = 90;
constexpr  const char* CSIRO_DEVIL_AUTOLAUNCHER_DESCRIPTION = "CSIRO Devil Autolauncher";
constexpr  int         TURO_CSIRO_QUOLL_AUTOLAUNCHER = 91;
constexpr  const char* TURO_CSIRO_QUOLL_AUTOLAUNCHER_DESCRIPTION = "TURO/CSIRO Quoll Autolauncher";
constexpr  int         MFSTEP_AUTOLAUNCHER = 100;
constexpr  const char* MFSTEP_AUTOLAUNCHER_DESCRIPTION = "MFSTEP Autolauncher (Mediterranean)";
constexpr  int         MISSING = 255;
constexpr  const char* MISSING_DESCRIPTION = "Missing";

Launchers::Launchers() {
	// TODO Auto-generated constructor stub

}

Launchers::~Launchers() {
	// TODO Auto-generated destructor stub
}

std::string Launchers::getLauncherDescription(int launcher) {
    const char* description = "Missing value";
    switch (launcher) {

        case UNKNOWN:
            description = UNKNOWN_DESCRIPTION;
            break;
        case LM_2A_DECK_MOUNTED:
            description = LM_2A_DECK_MOUNTED_DESCRIPTION;
            break;
        case LM_3A_HAND_HELD:
            description = LM_3A_HAND_HELD_DESCRIPTION;
            break;
        case LM_4A_THRU_HULL:
            description = LM_4A_THRU_HULL_DESCRIPTION;
            break;
        case AL_12_TSK_AUTOLAUNCHER:
            description = AL_12_TSK_AUTOLAUNCHER_DESCRIPTION;
            break;
        case SIO_XBT_AUTOLAUNCHER:
            description = SIO_XBT_AUTOLAUNCHER_DESCRIPTION;
            break;
        case AOML_XBT_V6_AUTOLAUNCHER:
            description = AOML_XBT_V6_AUTOLAUNCHER_DESCRIPTION;
            break;
        case AOML_XBT_V8_0_AUTOLAUNCHER:
            description = AOML_XBT_V8_0_AUTOLAUNCHER_DESCRIPTION;
            break;
        case AOML_XBT_V8_1_AUTOLAUNCHER:
            description = AOML_XBT_V8_1_AUTOLAUNCHER_DESCRIPTION;
            break;
        case CSIRO_DEVIL_AUTOLAUNCHER:
            description = CSIRO_DEVIL_AUTOLAUNCHER_DESCRIPTION;
            break;
        case TURO_CSIRO_QUOLL_AUTOLAUNCHER:
            description = TURO_CSIRO_QUOLL_AUTOLAUNCHER_DESCRIPTION;
            break;
        case MFSTEP_AUTOLAUNCHER:
            description = MFSTEP_AUTOLAUNCHER_DESCRIPTION;
            break;
        case MISSING:
            description = MISSING_DESCRIPTION;
            break;
        }
        return std::string(description);
    }

