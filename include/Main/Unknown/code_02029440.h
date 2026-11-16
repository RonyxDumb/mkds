#pragma once

#include "types.h"

void SetSessionKartCount(unsigned int sessionKartCount);
void SetRaceSetupCopyEntryIndex(unsigned int entryIndex);
void SetMissionFileRowIndex(unsigned int missionFileRowIndex);
void SPM_SetMissionIdx(unsigned int missionTableColumn);
void SPM_SetMissionLevel(unsigned int missionTableRow);
void SPM_SetTTGhost(unsigned int p0);
void func_020294ac(u16 entryIndex, u32 b);
void func_020294c0(u16 entryIndex, u32 b);
void SetPlayerKind(u16 entryIndex, u32 playerKind);
void SPM_SetDriverXKartID(u16 entryIndex, u32 kartIndex);
void SPM_SetDriverXCharacterID(u16 entryIndex, u32 characterIndex);
void SPM_SetDriverXTeam(u16 entryIndex, u32 teamIndex);
void SPM_DisableTeamMode(void);
void SPM_EnableTeamMode(void);
void SPM_SetRules(unsigned int ruleKind);
void SPM_SetNrRacesNrWins(u16 courseCount);
void SPM_SetCourseMode(unsigned int courseListMode);
void SPM_SetCPUMode(unsigned int cpuDifficulty);
void SPM_SetCourse(unsigned int courseId);
void SPM_SetCup(unsigned int cupIndex);
void SPM_DisableMirrorMode(void);
void SPM_EnableMirrorMode(void);
void SPM_SetCCMode(unsigned int engineIndex);
unsigned int GetSessionKartCount(void);
unsigned int menu_getRaceConfigField10C(void);
unsigned int GetMissionTableColumn(void);
unsigned int GetMissionTableRow(void);
unsigned int GetTeamIndex(u16 entryIndex);
unsigned int GetUseTeams(void);
unsigned int GetRuleKind(void);
unsigned int GetRaceSetupCopyCourseCount(void);
unsigned int GetCourseListMode(void);
unsigned int GetCpuDifficulty(void);
unsigned int GetMirrorMode(void);
unsigned int SPM_GetSelectedCup(void);
unsigned int GetEngineIndex(void);
unsigned int GetPlayerKind(u16 entryIndex);
unsigned int SPM_GetDriverXKartID(u16 entryIndex);
unsigned int SPM_GetDriverXCharacterID(u16 entryIndex);
unsigned int SPM_GetSelectedCourse(void);
