#include "01/code_0219ca2c.h"

// non-matching: 0x5c bytes, original 0x68; 18 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4,
// lr}`
void func_ov001_0219ca2c(void) {
    int iVar1;
    iVar1 = func_02127788();
    if (iVar1 != 0) {
        if (*(int *) (*((int *) ((u32) (&data_ov001_021a9bf8))) + 0x28) + 2U <= 1) {
            iVar1 = func_02127794();
            if (iVar1 == 1) {
                *(u32 *) (*((int *) ((u32) (&data_ov001_021a9bf8))) + 4) = 6;
            } else {
                *(u32 *) (*((int *) ((u32) (&data_ov001_021a9bf8))) + 4) = 2;
            }
        } else {
            iVar1 = func_02127794();
            if (iVar1 == 0) {
                *(u32 *) (*((int *) ((u32) (&data_ov001_021a9bf8))) + 4) = 6;
                func_021282c8();
                *(u32 *) (*((int *) ((u32) (&data_ov001_021a9bf8))) + 0x2c) = 1;
            } else {
                *(u32 *) (*((int *) ((u32) (&data_ov001_021a9bf8))) + 4) = 2;
            }
        }
        func_021277e4();
    }
    return;
}
