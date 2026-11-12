#include "Main/Graphics/oam_matrix_count.h"
#include "Main/Unknown/code_020c06c4.h"

#pragma thumb on
u32 IncrementOamMatrixCount(RaceHudOamBuffer *oamList) {
    u16 *counterPointer = &oamList->mMatrixCount;
    *counterPointer = *counterPointer + 1;
    return (u32) counterPointer;
}
#pragma thumb off
