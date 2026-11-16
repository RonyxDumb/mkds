#include "Main/Race/race_progress_rule.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/System/init_after_startup.h"

u32 GetCurrentRacerCount(void) {
    return (g_GlobalCO->mKartCount);
}

BOOL IsRacer_Player_Ghost_UnkNet3(u32 kartIndex) {
    BOOL isNonCpu;
    s32 playerKind;
    isNonCpu = FALSE;
    playerKind = g_GlobalCO->mCurrentEntries[kartIndex].mPlayer.mKind;
    if ((u32) playerKind <= 3 && ((1 << playerKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) != 0) {
        isNonCpu = TRUE;
    }
    if (isNonCpu != FALSE) {
        return TRUE;
    }
    return FALSE;
}

BOOL IsRacerFinishStatus4(u32 kartIndex) {
    return g_GlobalMV->mKarts[kartIndex].mStatus == RACE_PROGRESS_KART_STATUS_REMOVED;
}

u32 GetCurrentRaceRules_0(void) {
    return (g_GlobalCO->mRuleKind);
}

u16 GetLeadingKart(void) {
    return g_GlobalMV->mKartAtRank[0];
}
