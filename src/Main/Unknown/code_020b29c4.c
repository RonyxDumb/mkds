#include "Main/Unknown/code_020b29c4.h"
#include "Main/Unknown/code_02055730.h"
#include "Main/Unknown/code_020a126c.h"
#include "Main/Unknown/code_02055000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020b252c.h"
#include "Main/Unknown/code_020b2a4c.h"
#include "Main/Unknown/code_020b2ec0.h"
#include "Main/Unknown/code_020b33d8.h"
#include "Main/Unknown/unk_021759c0.h"

#pragma thumb on
#pragma optimize_for_size on
BOOL IsChoisesSOpenAllowedDuringRace(void) {
    u32 result = 0;
    u32 modeAllowsOpen = 0;
    u32 raceInProgress = 0;
    u32 noMissionWinner;

    if (IsRaceStartSequenceDone() != 0 && GetRaceStartSequenceFrames() > 0xf0 && GetRaceDone() == 0 &&
        (ChoisesSGetCurrentMode() != MODE_BATTLE || IsWinnerDecided() == FALSE)) {
        noMissionWinner = 1;
        if (ChoisesSGetCurrentMode() == MODE_MISSION_RUN) {
            if ((ChoisesSGetCurrentMode() == MODE_MISSION_RUN ? IsWinnerDecided() : 0) != FALSE) {
                noMissionWinner = 0;
            }
        }
        if (noMissionWinner != 0) {
            raceInProgress = 1;
        }
    }
    if (raceInProgress != 0) {
        if (ChoisesSGetCurrentMode() != 5) {
            modeAllowsOpen = 1;
        }
    }
    if (modeAllowsOpen != 0) {
        if (GetChoisesSOpenDuringRace() != 0 || func_02055b1c() == FALSE) {
            result = 1;
        }
    }
    return result;
}
#pragma thumb off
