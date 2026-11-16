#pragma once

#include "types.h"

typedef struct RandomState64 RandomState64;

BOOL race_2045874(void);
s32 sub_20458CC(void);
s32 sub_2045914(void);
s32 AdvanceToNextCourse(void);
void rconf_setupStaffRoll(s32 useTrueStaffRoll);
BOOL rconf_setupAward(void);
void rconf_2045ED0(void);
void BuildCourseList(s32 isVersus);
u32 sub_2046524(RandomState64 *randomState64, u32 limit);
void AssignCpuNumbers(void);
BOOL HasSomeSecretFlag(s32 a);
