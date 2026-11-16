#include "Main/Unknown/code_020cc994.h"
#include "00/code_02181f98.h"

void SetNextCPUMode(u32 cpuDifficulty) {
    gRaceMultiConfig->mNextHeader.mCpuDifficulty = cpuDifficulty;
}

void SetNextRaceMode(u32 mode) {
    gRaceMultiConfig->mNextHeader.mMode = mode;
}

void SetNextCup(u32 cupIndex) {
    gRaceMultiConfig->mNextHeader.mCupIndex = cupIndex;
}

void SetNextCourse(u32 courseId) {
    gRaceMultiConfig->mNextHeader.mCourseId = courseId;
}

void SetNextCCMode(u32 engineIndex) {
    gRaceMultiConfig->mNextHeader.mEngineIndex = engineIndex;
}

void SetNextMirrorMode(u32 mirrorMode) {
    gRaceMultiConfig->mNextHeader.mMirrorMode = (u8) mirrorMode;
}

void SetNextTTGhost(u32 p0) {
    gRaceMultiConfig->mNextHeader.mGhostRecordIndex = p0;
}

void SetNextBattleMode(u32 battleKind) {
    gRaceMultiConfig->mNextHeader.mBattleKind = battleKind;
}

void SetNextTeamMode(u32 useTeams) {
    gRaceMultiConfig->mNextHeader.mUseTeams = useTeams;
}

void SetNextNrRacesNrWins(u32 courseCount) {
    gRaceMultiConfig->mCourseCount = courseCount;
}

void SetNextRules(u32 ruleKind) {
    gRaceMultiConfig->mNextHeader.mRuleKind = ruleKind;
}

void SetNextCourseMode(u32 courseListMode) {
    gRaceMultiConfig->mNextHeader.mCourseListMode = courseListMode;
}

void func_020cc9a8(u32 p0) {
    gStruct217B488->mUnk_78 = p0;
}

u32 func_020cc994(void) {
    return (gStruct217B488->mUnk_04);
}
