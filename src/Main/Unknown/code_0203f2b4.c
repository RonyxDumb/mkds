#include "Main/Unknown/code_0203f2b4.h"
#include "Main/Unknown/code_020f36d8.h"

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
