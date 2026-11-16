#include "Main/Menu/current.h"

#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"

u32 GetRacerCharacterId(u32 entryIndex) {
    return g_GlobalCO->mCurrentEntries[entryIndex].mCharacterIndex;
}

u32 GetRacerKartId(u32 entryIndex) {
    return g_GlobalCO->mCurrentEntries[entryIndex].mKartIndex;
}

u32 GetRacerType_0(u32 entryIndex) {
    return g_GlobalCO->mCurrentEntries[entryIndex].mPlayer.mKind;
}

u32 GetIsTeams(void) {
    return (g_GlobalCO->mUseTeams);
}

u32 GetRacerTeam(u32 entryIndex) {
    return g_GlobalCO->mCurrentEntries[entryIndex].mPlayer.mTeamIndex;
}

u32 GetCurrentListedCpuSlot(u32 entryIndex) {
    return g_GlobalCO->mCurrentEntries[entryIndex].mPlayer.mListedCpuSlot;
}

u32 GetCurrentCupIndex(void) {
    return (g_GlobalCO->mCupIndex);
}

u32 GetCurrentRaceCpuMode(void) {
    return (g_GlobalCO->mCpuDifficulty);
}

u32 GetRacerCount(void) {
    return (g_GlobalCO->mKartCount);
}

u32 GetCurrentRaceMode(void) {
    return (g_GlobalCO->mMode);
}

u32 GetCurrentInternalCourseId_1(void) {
    return (g_GlobalCO->mCourseId);
}

u32 GetCurrrentCcType(void) {
    return (g_GlobalCO->mEngineIndex);
}

u32 GetIsMirror(void) {
    return (g_GlobalCO->mMirrorMode);
}

u32 GetCurrentBattleType(void) {
    return (g_GlobalCO->mBattleKind);
}

u32 GetMaybeNextRuleParam(void) {
    return (g_GlobalCO->mCourseCount);
}

u32 GetCurrentRaceRules(void) {
    return (g_GlobalCO->mRuleKind);
}
