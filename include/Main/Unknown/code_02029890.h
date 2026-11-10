#pragma once

#include "types.h"
#include "Main/Unknown/unk_02174000.h"

typedef struct RaceSetupCopy RaceSetupCopy;

void WiFiSetNextCourseListMode(unsigned int courseListMode);
void WiFiSetNextRuleKind(unsigned int ruleKind);
void WiFiSetNextUseTeams(unsigned int useTeams);
void WiFiSetNextMirrorMode(unsigned int mirrorMode);
void WiFiSetNextEngineIndex(unsigned int engineIndex);
void WiFiSetNextCourseId(unsigned int courseId);
void WiFiSetNextMode(unsigned int mode);
void WiFiSetNextCpuDifficulty(unsigned int cpuDifficulty);
RaceSetupCopy *GetRaceSetupCopy(void);
