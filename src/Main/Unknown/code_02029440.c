#include "Main/Unknown/code_02029440.h"
#include "Main/Unknown/unk_02174000.h"

#pragma thumb on

u32 SPM_GetSelectedCourse(void) {
    return (menu_sRaceConfig->mCourseId);
}

u32 SPM_GetDriverXCharacterID(u16 entryIndex) {
    return (menu_sRaceConfig->mEntries[entryIndex].mCharacterIndex);
}

u32 SPM_GetDriverXKartID(u16 entryIndex) {
    return (menu_sRaceConfig->mEntries[entryIndex].mKartIndex);
}

u32 GetPlayerKind(u16 entryIndex) {
    return (menu_sRaceConfig->mEntries[entryIndex].mPlayerKind);
}

u32 GetEngineIndex(void) {
    return (menu_sRaceConfig->mEngineIndex);
}

u32 SPM_GetSelectedCup(void) {
    return (menu_sRaceConfig->mCupIndex);
}

u32 GetMirrorMode(void) {
    return (menu_sRaceConfig->mMirrorMode);
}

u32 GetCpuDifficulty(void) {
    return (menu_sRaceConfig->mCpuDifficulty);
}

u32 GetCourseListMode(void) {
    return (menu_sRaceConfig->mCourseListMode);
}

u32 GetRaceSetupCopyCourseCount(void) {
    return (menu_sRaceConfig->mCourseCount);
}

u32 GetRuleKind(void) {
    return (menu_sRaceConfig->mRuleKind);
}

u32 GetUseTeams(void) {
    return (menu_sRaceConfig->mUseTeams);
}

u32 GetTeamIndex(u16 entryIndex) {
    return (menu_sRaceConfig->mEntries[entryIndex].mTeamIndex);
}

u32 GetMissionTableRow(void) {
    return (menu_sRaceConfig->mMissionTableRow);
}

u32 GetMissionTableColumn(void) {
    return (menu_sRaceConfig->mMissionTableColumn);
}

u32 menu_getRaceConfigField10C(void) {
    return (menu_sRaceConfig->mEntryIndex);
}

u32 GetSessionKartCount(void) {
    return (menu_sRaceConfig->mSessionKartCount);
}

void SPM_SetCCMode(u32 engineIndex) {
    menu_sRaceConfig->mEngineIndex = engineIndex;
}

void SPM_EnableMirrorMode(void) {
    menu_sRaceConfig->mMirrorMode = 1;
}

void SPM_DisableMirrorMode(void) {
    menu_sRaceConfig->mMirrorMode = 0;
}

void SPM_SetCup(u32 cupIndex) {
    menu_sRaceConfig->mCupIndex = cupIndex;
}

void SPM_SetCourse(u32 courseId) {
    menu_sRaceConfig->mCourseId = courseId;
}

void SPM_SetCPUMode(u32 cpuDifficulty) {
    menu_sRaceConfig->mCpuDifficulty = cpuDifficulty;
}

void SPM_SetCourseMode(u32 courseListMode) {
    menu_sRaceConfig->mCourseListMode = courseListMode;
}

void SPM_SetNrRacesNrWins(u16 courseCount) {
    menu_sRaceConfig->mCourseCount = courseCount;
}

void SPM_SetRules(u32 ruleKind) {
    menu_sRaceConfig->mRuleKind = ruleKind;
}

void SPM_EnableTeamMode(void) {
    menu_sRaceConfig->mUseTeams = 1;
}

void SPM_DisableTeamMode(void) {
    menu_sRaceConfig->mUseTeams = 0;
}

#pragma thumb off

#pragma thumb on

void SPM_SetDriverXTeam(u16 entryIndex, u32 teamIndex) {
    menu_sRaceConfig->mEntries[entryIndex].mTeamIndex = teamIndex;
}

void SPM_SetDriverXCharacterID(u16 entryIndex, u32 characterIndex) {
    menu_sRaceConfig->mEntries[entryIndex].mCharacterIndex = characterIndex;
}

void SPM_SetDriverXKartID(u16 entryIndex, u32 kartIndex) {
    menu_sRaceConfig->mEntries[entryIndex].mKartIndex = kartIndex;
}

void SetPlayerKind(u16 entryIndex, u32 playerKind) {
    menu_sRaceConfig->mEntries[entryIndex].mPlayerKind = playerKind;
}

void func_020294c0(u16 entryIndex, u32 b) {
    menu_sRaceConfig->mEntries[entryIndex].field10 = b;
}

void func_020294ac(u16 entryIndex, u32 b) {
    menu_sRaceConfig->mEntries[entryIndex].field14 = b;
}

#pragma thumb off

#pragma thumb on

void SPM_SetTTGhost(u32 p0) {
    menu_sRaceConfig->fieldE0 = p0;
}

void SPM_SetMissionLevel(u32 missionTableRow) {
    menu_sRaceConfig->mMissionTableRow = (u8) missionTableRow;
}

void SPM_SetMissionIdx(u32 missionTableColumn) {
    menu_sRaceConfig->mMissionTableColumn = (u8) missionTableColumn;
}

void SetMissionFileRowIndex(u32 missionFileRowIndex) {
    menu_sRaceConfig->mMissionFileRowIndex = missionFileRowIndex;
}

void SetRaceSetupCopyEntryIndex(u32 entryIndex) {
    menu_sRaceConfig->mEntryIndex = entryIndex;
}

void SetSessionKartCount(u32 sessionKartCount) {
    menu_sRaceConfig->mSessionKartCount = sessionKartCount;
}

#pragma thumb off
