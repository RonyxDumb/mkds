#include "Main/Unknown/code_020cc5d8.h"

#include "Main/Unknown/code_020cc6a4.h"
#include "Main/Unknown/code_020cc6dc.h"
#include "Main/Unknown/code_020cc6f0.h"
#include "Main/Unknown/unk_021759c0.h"

u32 GetCurrentCharacterIndex(u32 entryIndex) {
    return gRaceSetup->mCurrentEntries[entryIndex].mCharacterIndex;
}

u32 GetCurrentKartIndex(u32 entryIndex) {
    return gRaceSetup->mCurrentEntries[entryIndex].mKartIndex;
}

u32 GetCurrentPlayerKind(u32 entryIndex) {
    return gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mKind;
}

u32 GetCurrentUseTeams(void) {
    return (gRaceSetup->mUseTeams);
}

u32 GetCurrentTeamIndex(u32 entryIndex) {
    return gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mTeamIndex;
}

u32 func_020cc6a4(u32 entryIndex) {
    return gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mUnk_08;
}

u32 GetCurrentCupIndex(void) {
    return (gRaceSetup->mCupIndex);
}

u32 GetCurrentCpuDifficulty(void) {
    return (gRaceSetup->mCpuDifficulty);
}

u32 GetCurrentKartCount(void) {
    return (gRaceSetup->mKartCount);
}

u32 GetCurrentMode(void) {
    return (gRaceSetup->mMode);
}

u32 GetCurrentCourseId(void) {
    return (gRaceSetup->mCourseId);
}

u32 GetCurrentEngineIndex(void) {
    return (gRaceSetup->mEngineIndex);
}

u32 GetCurrentMirrorMode(void) {
    return (gRaceSetup->mMirrorMode);
}

u32 GetCurrentBattleKind(void) {
    return (gRaceSetup->mBattleKind);
}

u32 GetCurrentCourseCount(void) {
    return (gRaceSetup->mCourseCount);
}

u32 GetCurrentRuleKind(void) {
    return (gRaceSetup->mRuleKind);
}
