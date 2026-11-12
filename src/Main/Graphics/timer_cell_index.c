#include "Main/Graphics/timer_cell_index.h"
#include "Main/Unknown/code_0211d4a8.h"

#pragma thumb on

s32 GetTimerTensCellIndex(void) {
    if (gBootInfo->mBootType == 2) {
        return 0x38;
    }
    return 0x39;
}

s32 GetTimerOnesCellIndex(void) {
    if (gBootInfo->mBootType == 2) {
        return 0x39;
    }
    return 0x3a;
}

#pragma thumb off
