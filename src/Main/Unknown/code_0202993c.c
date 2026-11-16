#include "Main/Unknown/code_0202993c.h"
#include "Main/Unknown/code_02029a24.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/unk_02174000.h"

#pragma optimize_for_size on
u16 *menu_MB_GetMultiBootParam(void) {
    return (u16 *) 0x27ffc40;
}

u32 menu_MB_IsMultiBootChild(void) {
    if (*menu_MB_GetMultiBootParam() == 2) {
        return 1;
    }
    return 0;
}

u32 menu_MB_IsMultiBootChild_2(void) {
    return menu_MB_IsMultiBootChild();
}

#pragma thumb on

void menu_initRaceConfig(void) {
    s32 entryIndex;
    menu_MI_CpuClearFast(menu_sRaceConfig, 0x110);
    for (entryIndex = 0; entryIndex < 8; entryIndex++) {
        menu_sRaceConfig->mEntries[entryIndex].mCharacterIndex = -1;
        menu_sRaceConfig->mEntries[entryIndex].mKartIndex = -1;
        menu_sRaceConfig->mEntries[entryIndex].mPlayerKind = 4;
        menu_sRaceConfig->mEntries[entryIndex].mTeamIndex = -1;
        menu_sRaceConfig->mEntries[entryIndex].mUnk_10 = 3;
    }
    menu_sRaceConfig->mMissionTableRow = 1;
    menu_sRaceConfig->mMissionTableColumn = 1;
    if (menu_sysdat_getOverlay() == 0) {
        if (menu_MB_IsMultiBootChild_2() == 0) {
            menu_sRaceConfig->mMissionFile = arc_getSceneArcFile(aMission_mr);
        } else {
            menu_sRaceConfig->mMissionFile = NULL;
        }
        if (menu_sRaceConfig->mMissionFile != NULL) {
            menu_sRaceConfig->mMissionFileRows = (MissionFileRow *) (menu_sRaceConfig->mMissionFile + 8);
        } else {
            menu_sRaceConfig->mMissionFileRows = NULL;
        }
    }
}
