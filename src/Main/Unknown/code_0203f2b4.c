#include "Main/Unknown/code_0203f2b4.h"
#include "Main/Unknown/code_020f36d8.h"

BOOL rstat_rconf_isDriverValidAndNoEnemy(u32 a) {
    BOOL f;
    s32 s;
    f = FALSE;
    s = gRaceMultiConfig->mCurrentEntries[a].mPlayer.mKind;
    if ((u32) s <= 3 && ((1 << s) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) != 0) {
        f = TRUE;
    }
    if (f != FALSE) {
        return TRUE;
    }
    return FALSE;
}

BOOL rstat_203F2B4(u32 a) {
    return gRaceStatus->mUnk_000[a].mStatus == 4;
}
