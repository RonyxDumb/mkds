#include "01/code_02181630.h"

// non-matching: 0x2c bytes, original 0x30; 13 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4,
// lr}`
void func_ov001_02181630(short param_1) {
    u16 uVar1;
    u32 uVar2;
    *(short *) (*((int *) ((u32) (&data_ov001_021a9b90))) + 6) =
        *(unsigned short *) (*((int *) ((u32) (&data_ov001_021a9b90))) + 6) + param_1;
    uVar2 = func_ov001_0218180c();
    if (*(u16 *) (*((int *) ((u32) (&data_ov001_021a9b90))) + 6) > uVar2) {
        uVar1 = func_ov001_0218180c();
        *(u16 *) (*((int *) ((u32) (&data_ov001_021a9b90))) + 6) = uVar1;
    }
    return;
}
