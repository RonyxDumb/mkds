#include "Main/Race/race_progress_rule.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/System/init_after_startup.h"

u32 RaceProgressGetCurrentKartCount(void) {
    return (gRaceSetup->mKartCount);
}

BOOL IsKartNonCpu(u32 kartIndex) {
    BOOL isNonCpu;
    s32 playerKind;
    isNonCpu = FALSE;
    playerKind = gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mKind;
    if ((u32) playerKind <= 3 && ((1 << playerKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) != 0) {
        isNonCpu = TRUE;
    }
    if (isNonCpu != FALSE) {
        return TRUE;
    }
    return FALSE;
}

BOOL IsRaceProgressKartRemoved(u32 kartIndex) {
    return gRaceProgress->mKarts[kartIndex].mStatus == RACE_PROGRESS_KART_STATUS_REMOVED;
}

u32 RaceProgressGetCurrentRuleKind(void) {
    return (gRaceSetup->mRuleKind);
}

u16 GetLeadingKart(void) {
    return gRaceProgress->mKartAtRank[0];
}
