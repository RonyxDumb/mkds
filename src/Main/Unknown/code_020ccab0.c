#include "Main/Unknown/code_020ccab0.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020ccb48.h"

#pragma optimize_for_size on
#pragma thumb on
void SetNextRaceEntriesFromRaceSetupCopy(void) {
    u8 i;
    s32 teamIndex;

    for (i = 0; i < 8; i++) {
        if (menu_getRaceConfig()->mCpuDifficulty == 0 && menu_getRaceConfig()->mEntries[i].mPlayerKind == 1) {
            SetNextRaceEntryNone(i);
        } else {
            teamIndex = menu_getRaceConfig()->mUseTeams != 0 ? menu_getRaceConfig()->mEntries[i].mTeamIndex : -1;
            rconf_setDriverConfigNext(i, menu_getRaceConfig()->mEntries[i].mCharacterIndex,
                             menu_getRaceConfig()->mEntries[i].mKartIndex, menu_getRaceConfig()->mEntries[i].mPlayerKind,
                             teamIndex, menu_getRaceConfig()->mEntries[i].field10);
        }
    }
}
#pragma thumb off
