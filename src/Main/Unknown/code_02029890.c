#include "Main/Unknown/code_02029890.h"
#include "Main/Unknown/unk_021759c0.h"

#pragma thumb on

RaceSetupCopy *menu_getRaceConfig(void) {
    return menu_sRaceConfig;
}

#pragma thumb off

void func_0202991c(u32 cpuDifficulty) {
    gRaceMultiConfig->mNextHeader.mCpuDifficulty = cpuDifficulty;
}

void func_02029908(u32 mode) {
    gRaceMultiConfig->mNextHeader.mMode = mode;
}

void func_020298f4(u32 courseId) {
    gRaceMultiConfig->mNextHeader.mCourseId = courseId;
}

void func_020298e0(u32 engineIndex) {
    gRaceMultiConfig->mNextHeader.mEngineIndex = engineIndex;
}

void func_020298cc(u32 mirrorMode) {
    gRaceMultiConfig->mNextHeader.mMirrorMode = (u8) mirrorMode;
}

void func_020298b8(u32 useTeams) {
    gRaceMultiConfig->mNextHeader.mUseTeams = useTeams;
}

void func_020298a4(u32 ruleKind) {
    gRaceMultiConfig->mNextHeader.mRuleKind = ruleKind;
}

void func_02029890(u32 courseListMode) {
    gRaceMultiConfig->mNextHeader.mCourseListMode = courseListMode;
}
