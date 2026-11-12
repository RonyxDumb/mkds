#include "Main/Race/race_progress_rule.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/Race/data_020f36d8.h"

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
