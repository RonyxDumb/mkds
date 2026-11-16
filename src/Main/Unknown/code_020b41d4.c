#include "Main/Unknown/code_020b41d4.h"
#include "Main/Unknown/unk_02175000.h"

#pragma thumb on

u32 m2d_arc_isArchiveLoaded(u32 slotIndex) {
    return (gArcData->field0[slotIndex].mLoaded);
}

#pragma thumb off
