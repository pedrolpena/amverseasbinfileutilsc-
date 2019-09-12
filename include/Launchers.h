/*
 * Launchers.h
 *
 *  Created on: Jul 20, 2019
 *      Author: pedro
 */

#ifndef INCLUDE_LAUNCHERS_H_
#define INCLUDE_LAUNCHERS_H_
#include <string>
class Launchers {
public:
	static constexpr int         UNKNOWN = 0;
	static constexpr const char* UNKNOWN_DESCRIPTION = "Unknown";
	static constexpr int         LM_2A_DECK_MOUNTED = 1;
	static constexpr const char* LM_2A_DECK_MOUNTED_DESCRIPTION = "LM-2A Deck-mounted";
	static constexpr int         LM_3A_HAND_HELD = 2;
	static constexpr const char* LM_3A_HAND_HELD_DESCRIPTION = "LM-3A Hand-Held";
	static constexpr int         LM_4A_THRU_HULL = 3;
	static constexpr const char* LM_4A_THRU_HULL_DESCRIPTION = "LM-4A Thru-Hull";
	static constexpr int         AL_12_TSK_AUTOLAUNCHER = 10;
	static constexpr const char* AL_12_TSK_AUTOLAUNCHER_DESCRIPTION = "AL-12 TSK Autolauncher (up to 12 Probes)";
	static constexpr int         SIO_XBT_AUTOLAUNCHER = 20;
	static constexpr const char* SIO_XBT_AUTOLAUNCHER_DESCRIPTION = "SIO XBT Autolauncher (up to 6 probes)";
	static constexpr int         AOML_XBT_V6_AUTOLAUNCHER = 30;
	static constexpr const char* AOML_XBT_V6_AUTOLAUNCHER_DESCRIPTION = "AOML XBT V6 Autolauncher (up to 6 Deep Blue probes)";
	static constexpr int         AOML_XBT_V8_0_AUTOLAUNCHER = 31;
	static constexpr const char* AOML_XBT_V8_0_AUTOLAUNCHER_DESCRIPTION = "AOML XBT V8.0 Autolauncher (up to 8 Deep Blue probes)";
	static constexpr int         AOML_XBT_V8_1_AUTOLAUNCHER = 32;
	static constexpr const char* AOML_XBT_V8_1_AUTOLAUNCHER_DESCRIPTION = "AOML XBT V8.1 Autolauncher (up to 8 Deep Blue and Fast Deep probes)";
	static constexpr int         CSIRO_DEVIL_AUTOLAUNCHER = 90;
	static constexpr const char* CSIRO_DEVIL_AUTOLAUNCHER_DESCRIPTION = "CSIRO Devil Autolauncher";
	static constexpr int         TURO_CSIRO_QUOLL_AUTOLAUNCHER = 91;
	static constexpr const char* TURO_CSIRO_QUOLL_AUTOLAUNCHER_DESCRIPTION = "TURO/CSIRO Quoll Autolauncher";
	static constexpr int         MFSTEP_AUTOLAUNCHER = 100;
	static constexpr const char* MFSTEP_AUTOLAUNCHER_DESCRIPTION = "MFSTEP Autolauncher (Mediterranean)";
	static constexpr int         MISSING = 255;
	static constexpr const char* MISSING_DESCRIPTION = "Missing";
	Launchers();
	virtual ~Launchers();
	static std::string getLauncherDescription(int);
};

#endif /* INCLUDE_LAUNCHERS_H_ */
