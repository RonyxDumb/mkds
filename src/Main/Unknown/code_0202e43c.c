#include "Main/Unknown/code_0202e43c.h"
#include "Main/Unknown/unk_02154000.h"

#pragma thumb on

u32 GhostSceneGetCupCourseIdAtIndex(s32 cupCourseIndex) {
    return gCupCourseIdTable[cupCourseIndex / 4][cupCourseIndex % 4];
}

#pragma thumb off
