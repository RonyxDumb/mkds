#pragma once

#include "types.h"

typedef struct RandomState64 RandomState64;

BOOL CopyCourseIdAndAdvanceCourseNumber(void);
s32 AdvanceToNextBattleCourse(void);
s32 AdvanceToNextCourseWrapper(void);
s32 AdvanceToNextCourse(void);
void SetupStaffRollRace(s32 useTrueStaffRoll);
BOOL CopyEntryResultAndSetupAwardRace(void);
void AssignCpuNumbersAndSetupFirstCourse(void);
void BuildCourseList(s32 isVersus);
u32 NextRandomBelowU16(RandomState64 *randomState64, u32 limit);
void AssignCpuNumbers(void);
BOOL IsCupEnabled(s32 cupIndex);
