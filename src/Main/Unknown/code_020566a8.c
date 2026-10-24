#include "Main/Unknown/code_020566a8.h"

#pragma thumb on

// non-matching: 0x50 bytes, original 0x58; 11 instructions differ; first at +0x0: original `push {r4, r5, lr}`, ours
// `push {r4, r5, r6, lr}`
void func_020566a8(u32 param_1, int param_2) {
    int iVar1;
    u32 uVar2;
    uVar2 = *(u32 *) (*((int *) ((u32) (&data_0217aa08))) + 0x18);
    *(u32 *) (param_2 + 8) = *(u32 *) (param_2 + 8) & 0xfffffffe | 1;
    func_0214d1fc((const void *) ((u16 *) (u32) (param_2)), (void *) ((u32 *) (u32) (uVar2)),
                  (u32) (((u32) 0x00001000u)));
    func_02057944((int) (param_1), (u32) (uVar2));
    iVar1 = func_020573c8((u32) (param_1));
    if (iVar1 == 0) {
        func_0205746c(param_1, *(int *) *((int *) ((u32) (&data_0217aa08))) + 0x2a, 2);
        func_020574a0();
    }
    return;
}

#pragma thumb off
