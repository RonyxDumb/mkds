#include "00/code_0218a6c8.h"

void func_ov000_0218a6f4(u32 param_1, int param_2, int param_3) {
    u8 uVar1;
    int iVar2;
    iVar2 = 0;
    if (0 < param_3) {
        do {
            uVar1 = func_ov000_0218a71c((int) (param_1), (u8) (*(u8 *) (param_2 + iVar2)));
            *(u8 *) (param_2 + iVar2) = uVar1;
            iVar2 = iVar2 + 1;
        } while (iVar2 < param_3);
    }
    return;
}

// non-matching: 0x34 bytes, original 0x2c; 13 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4,
// lr}`
u32 func_ov000_0218a6c8(u32 param_1) {
    int iVar1;
    u8 auStack_20[24];
    func_ov000_0218a5b0((u32) (param_1), (int) ((int) (u32) (auStack_20)));
    iVar1 = func_02134d30((u32) ((u32) (u32) (auStack_20)), (u32) (((u32) ((u32) (&data_ov000_021b2174)))), (int) (8));
    if (iVar1 == 0) {
        return 1;
    }
    return 0;
}
