#include "Main/Unknown/code_0202993c.h"
#include "Main/Unknown/code_02029a24.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/code_0211d4a8.h"

#pragma optimize_for_size on
u16 *RaceSetupCopyMB_GetMultiBootParam(void) {
    return &gBootInfo->mBootType;
}

u32 RaceSetupCopyMB_IsMultiBootChild(void) {
    if (*RaceSetupCopyMB_GetMultiBootParam() == 2) {
        return 1;
    }
    return 0;
}

u32 RaceSetupCopyMB_IsMultiBootChildWrapper(void) {
    return RaceSetupCopyMB_IsMultiBootChild();
}

#pragma thumb on

void ResetRaceSetupCopy(void) {
    s32 entryIndex;
    RaceSetupCopyMI_CpuClearFast(gRaceSetupCopy, 0x110);
    for (entryIndex = 0; entryIndex < 8; entryIndex++) {
        gRaceSetupCopy->mEntries[entryIndex].mCharacterIndex = -1;
        gRaceSetupCopy->mEntries[entryIndex].mKartIndex = -1;
        gRaceSetupCopy->mEntries[entryIndex].mPlayerKind = 4;
        gRaceSetupCopy->mEntries[entryIndex].mTeamIndex = -1;
        gRaceSetupCopy->mEntries[entryIndex].mListedCpuSlot = 3;
    }
    gRaceSetupCopy->mMissionTableRow = 1;
    gRaceSetupCopy->mMissionTableColumn = 1;
    if (RaceSetupCopyGetConnectionKind() == 0) {
        if (RaceSetupCopyMB_IsMultiBootChildWrapper() == 0) {
            gRaceSetupCopy->mMissionFile = FindSceneFile(data_usa_0216212c);
        } else {
            gRaceSetupCopy->mMissionFile = NULL;
        }
        if (gRaceSetupCopy->mMissionFile != NULL) {
            gRaceSetupCopy->mMissionFileRows = (MissionFileRow *) (gRaceSetupCopy->mMissionFile + 8);
        } else {
            gRaceSetupCopy->mMissionFileRows = NULL;
        }
    }
}
