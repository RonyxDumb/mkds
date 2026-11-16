#pragma once

#include "types.h"

typedef struct RandomState64 RandomState64;

BOOL race_2045874(void);
s32 func_020458cc(void);
s32 func_02045914(void);
s32 AdvanceToNextCourse(void);
void rconf_setupStaffRoll(s32 useTrueStaffRoll);
BOOL rconf_setupAward(void);
void rconf_2045ED0(void);
void BuildCourseList(s32 isVersus);
u32 func_02046524(RandomState64 *randomState64, u32 limit);
void AssignCpuNumbers(void);
BOOL func_02046648(s32 a);
