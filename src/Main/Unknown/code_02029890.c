#include "Main/Unknown/code_02029890.h"
#include "Main/Unknown/unk_021759c0.h"

#pragma thumb on

RaceSetupCopy *GetRaceSetupCopy(void) {
    return gRaceSetupCopy;
}

#pragma thumb off

void WiFiSetNextCpuDifficulty(u32 cpuDifficulty) {
    gRaceSetup->mNextHeader.mCpuDifficulty = cpuDifficulty;
}

void WiFiSetNextMode(u32 mode) {
    gRaceSetup->mNextHeader.mMode = mode;
}

void WiFiSetNextCourseId(u32 courseId) {
    gRaceSetup->mNextHeader.mCourseId = courseId;
}

void WiFiSetNextEngineIndex(u32 engineIndex) {
    gRaceSetup->mNextHeader.mEngineIndex = engineIndex;
}

void WiFiSetNextMirrorMode(u32 mirrorMode) {
    gRaceSetup->mNextHeader.mMirrorMode = (u8) mirrorMode;
}

void WiFiSetNextUseTeams(u32 useTeams) {
    gRaceSetup->mNextHeader.mUseTeams = useTeams;
}

void WiFiSetNextRuleKind(u32 ruleKind) {
    gRaceSetup->mNextHeader.mRuleKind = ruleKind;
}

void WiFiSetNextCourseListMode(u32 courseListMode) {
    gRaceSetup->mNextHeader.mCourseListMode = courseListMode;
}
