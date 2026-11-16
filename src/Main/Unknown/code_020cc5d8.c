#include "Main/Unknown/code_020cc5d8.h"

#include "Main/Unknown/code_020cc6a4.h"
#include "Main/Unknown/code_020cc6dc.h"
#include "Main/Unknown/code_020cc6f0.h"
#include "Main/Unknown/unk_021759c0.h"

u32 GetCurrentCharacterIndex(u32 entryIndex) {
    u32 value0 = entryIndex;
    u32 value1;
    u32 value2;
    value2 = (u32) &gRaceMultiConfig;
    value1 = 0x30u;
    value2 = *(const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = *(const u32 *) ((value1) + (104));
    return value0;
}

u32 GetCurrentKartIndex(u32 entryIndex) {
    u32 value0 = entryIndex;
    u32 value1;
    u32 value2;
    value2 = (u32) &gRaceMultiConfig;
    value1 = 0x30u;
    value2 = *(const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = *(const u32 *) ((value1) + (108));
    return value0;
}

u32 GetCurrentPlayerKind(u32 entryIndex) {
    u32 value0 = entryIndex;
    u32 value1;
    u32 value2;
    value2 = (u32) &gRaceMultiConfig;
    value1 = 0x30u;
    value2 = *(const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = *(const u32 *) ((value1) + (112));
    return value0;
}

u32 RData_GetCurrentTeamMode(void) {
    return (gRaceMultiConfig->mUseTeams);
}

u32 GetCurrentTeamIndex(u32 entryIndex) {
    u32 value0 = entryIndex;
    u32 value1;
    u32 value2;
    value2 = (u32) &gRaceMultiConfig;
    value1 = 0x30u;
    value2 = *(const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = *(const u32 *) ((value1) + (116));
    return value0;
}

u32 sub_20CC6A4(u32 entryIndex) {
    u32 value0 = entryIndex;
    u32 value1;
    u32 value2;
    value2 = (u32) &gRaceMultiConfig;
    value1 = 0x30u;
    value2 = *(const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = *(const u32 *) ((value1) + (120));
    return value0;
}

u32 RData_GetCurrentCup(void) {
    return (gRaceMultiConfig->mCupIndex);
}

u32 RData_GetCurrentCPUMode(void) {
    return (gRaceMultiConfig->mCpuDifficulty);
}

u32 menu_race_getNrDrivers(void) {
    return (gRaceMultiConfig->mKartCount);
}

u32 RData_GetCurrentRaceMode(void) {
    return (gRaceMultiConfig->mMode);
}

u32 RData_GetCurrentCourse(void) {
    return (gRaceMultiConfig->mCourseId);
}

u32 RData_GetCurrentCCMode(void) {
    return (gRaceMultiConfig->mEngineIndex);
}

u32 RData_GetCurrentMirrorMode(void) {
    return (gRaceMultiConfig->mMirrorMode);
}

u32 RData_GetBattleMode(void) {
    return (gRaceMultiConfig->mBattleKind);
}

u32 RData_GetNrRacesNrWins(void) {
    return (gRaceMultiConfig->mCourseCount);
}

u32 RData_GetRules(void) {
    return (gRaceMultiConfig->mRuleKind);
}
