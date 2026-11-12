#pragma once

#include "types.h"

void SetupGhostRecordSetForCupCourse(void);
void SetCourseIdFromSelectCupCourse(void);
void RefreshSelectCupCourseForIndex(void);
void AdvanceSelectCupCourseHighlight(void);
void SetupSelectCupCourseObjects(void);
void LocateAndQueueSelectCupCourse(void);
void LoadSelectCupCourseData(void);
void WriteSelectRaceRuleRegisters(void);
s32 AdvanceSelectRaceRule(void);
void DrawSelectRaceRuleRowOffsetLabels(s32 row);
void DrawSelectRaceRuleOffsetLabel(s32 labelIndex);
void AdvanceSelectRaceRuleState8(void);
void AdvanceSelectRaceRuleState7(void);
void AdvanceSelectRaceRuleState6(void);
