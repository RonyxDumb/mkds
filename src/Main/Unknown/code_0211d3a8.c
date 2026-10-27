#include "Main/Unknown/code_0211d3a8.h"

#pragma thumb on

// non-matching: 0x58 bytes, original 0x4c; 9 instructions differ; first at +0x2: original `ldr r0, [pc, #0x44]
// (->0x48)`, ours `ldr r0, [pc, #0x50] (->0x54)`
u32 func_0211d3a8(void) {
    u32 uVar1;
    u32 uVar2;
    if (*(int *) ((*(int *) &data_0217d368) + 0x6c) != 0) {
        uVar1 = ((short) func_0211d478((int) (0)));
        uVar2 = ((short) func_0211d478((int) (1)));
        if (uVar1 > uVar2) {
            return 0;
        }
        uVar1 = ((short) func_0211d478((int) (0)));
        uVar2 = ((short) func_0211d478((int) (1)));
        if (uVar1 < uVar2) {
            return 1;
        }
    }
    return 2;
}

#pragma thumb off
