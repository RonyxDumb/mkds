#include "Main/Unknown/code_0211d44c.h"

#pragma thumb on

unsigned short func_0211d478(int param_1) {
    int iVar1;
    iVar1 = *((int *) ((u32) (&data_0217d368)));
    if (*(int *) (iVar1 + 0x6c) == 0) {
        return *(unsigned short *) (iVar1 + param_1 * 2 + 0xac);
    }
    iVar1 = iVar1 + param_1 * 2;
    return *(unsigned short *) (iVar1 + 0xac) + *(unsigned short *) (iVar1 + 0xb0);
}

// non-matching: 0x30 bytes, original 0x2c; 4 instructions differ; first at +0x4: original `ldr r1, [pc, #0x20]
// (->0x28)`, ours `ldr r1, [pc, #0x24] (->0x2c)`
u32 func_0211d44c(int param_1) {
    int iVar1;
    iVar1 = ((short) func_0211d478((int) (*(u32 *) (*((int *) ((u32) (&data_0217d368))) + param_1 * 4 + 0x8c))));
    if (iVar1 != 1) {
        return 1;
    }
    return 0;
}

#pragma thumb off
