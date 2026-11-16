#include "Main/Unknown/code_0202e43c.h"
#include "Main/Unknown/unk_02154000.h"

#pragma thumb on

u32 ghost_getCourseId(s32 cupCourseIndex) {
    return sCupDefs[cupCourseIndex / 4][cupCourseIndex % 4];
}

#pragma thumb off
