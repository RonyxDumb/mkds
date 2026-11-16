#pragma once

#include "types.h"

void SetNextRaceSetupFromCopy(void);

unsigned int GetRaceSetupRequested(void);
void SetResultArchiveDl(unsigned int resultArchiveDl);
void SetNextCourseListMode(unsigned int courseListMode);
void SetNextRuleKind(unsigned int ruleKind);
void SetCourseCount(unsigned int courseCount);
void SetNextUseTeams(unsigned int useTeams);
void SetNextBattleKind(unsigned int battleKind);
void SetNextGhostRecordIndex(unsigned int ghostRecordIndex);
void SetNextMirrorMode(unsigned int mirrorMode);
void SetNextEngineIndex(unsigned int engineIndex);
void SetNextCourseId(unsigned int courseId);
void SetNextCupIndex(unsigned int cupIndex);
void SetNextMode(unsigned int mode);
void SetNextCpuDifficulty(unsigned int cpuDifficulty);

void SetNextRaceEntriesFromRaceSetupCopy(void);

void SetNextRaceEntryNone(u32 entryIndex);

void SetNextTimeAttackEntries(void);

void SetNextGrandPrixEntries(void);
