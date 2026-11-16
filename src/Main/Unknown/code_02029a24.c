#include "Main/Unknown/code_02029a24.h"
#include "Main/Unknown/code_02029000.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/unk_02174000.h"

#include "Main/Unknown/code_0214d000.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0202993c.h"

#pragma thumb on

void menu_createRaceConfig(void *heap) {
    u32 setupCopyAddress;
    setupCopyAddress = ((u32) heap_alloc(heap, (0x00000110u)));
    *(u32 *) &menu_sRaceConfig = setupCopyAddress;
    menu_initRaceConfig();
}

#pragma thumb off

void menu_MI_CpuFillFast(void *destination, u32 value, u32 size) {
    volatile u32 valueCopy = value;
    MIi_CpuClearFast(valueCopy, destination, size);
}

void menu_MI_CpuClearFast(void *destination, u32 size) {
    menu_MI_CpuFillFast(destination, 0, size);
}

u32 menu_sysdat_getOverlay(void) {
    return (gSystemData->mUnk_20);
}
