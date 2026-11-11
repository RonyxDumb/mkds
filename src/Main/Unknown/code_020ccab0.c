#include "Main/Unknown/code_020ccab0.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020ccb48.h"

#pragma optimize_for_size on
#pragma thumb on
void SetNextRaceEntriesFromRaceSetupCopy(void) {
    u8 entryIndex;
    s32 teamIndex;

    for (entryIndex = 0; entryIndex < 8; entryIndex++) {
        if (GetRaceSetupCopy()->mCpuDifficulty == 0 && GetRaceSetupCopy()->mEntries[entryIndex].mPlayerKind == 1) {
            SetNextRaceEntryNone(entryIndex);
        } else {
            teamIndex = GetRaceSetupCopy()->mUseTeams != 0 ? GetRaceSetupCopy()->mEntries[entryIndex].mTeamIndex : -1;
            SetNextRaceEntry(entryIndex, GetRaceSetupCopy()->mEntries[entryIndex].mCharacterIndex,
                             GetRaceSetupCopy()->mEntries[entryIndex].mKartIndex,
                             GetRaceSetupCopy()->mEntries[entryIndex].mPlayerKind, teamIndex,
                             GetRaceSetupCopy()->mEntries[entryIndex].mListedCpuSlot);
        }
    }
}
#pragma thumb off
