#pragma once

#include "types.h"

void SetNextRaceSetupFromCopy(void);

unsigned int GetRaceSetupRequested(void);
void SetResultArchiveDl(unsigned int resultArchiveDl);
void SetNextCourseMode(unsigned int courseListMode);
void SetNextRules(unsigned int ruleKind);
void MaybeSetNextRuleParam(unsigned int courseCount);
void SetNextTeamMode(unsigned int useTeams);
void SetNextBattleMode(unsigned int battleKind);
void SetNextTimeTrialGhost(unsigned int ghostRecordIndex);
void SetNextMirrorMode(unsigned int mirrorMode);
void SetNextCcMode(unsigned int engineIndex);
void SetNextCourse(unsigned int courseId);
void SetNextCupId(unsigned int cupIndex);
void SetNextRaceMode(unsigned int mode);
void SetNextCpuMode(unsigned int cpuDifficulty);

void SetNextRaceEntriesFromRaceSetupCopy(void);

void SetNextRaceEntryNone(u32 entryIndex);

void SetNextTimeAttackEntries(void);

void SetNextGrandPrixEntries(void);
