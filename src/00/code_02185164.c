#include "00/code_02185164.h"

// non-matching: 0x84 bytes, original 0x90; 27 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4,
// lr}`
void func_ov000_021851a0(void) {
    u32 uVar1;
    uVar1 = ((int) func_0204799c((const char *) (((u32) ((u32) (&data_ov000_021b0e70))))));
    *(u32 *) (*((int *) ((u32) (&data_ov000_021b4c84))) + 0x2c) = uVar1;
    uVar1 = ((int) func_0204799c((const char *) (((u32) ((u32) (&data_ov000_021b0e84))))));
    *(u32 *) (*((int *) ((u32) (&data_ov000_021b4c84))) + 0x30) = uVar1;
    uVar1 = ((int) func_0204799c((const char *) (((u32) ((u32) (&data_ov000_021b0e98))))));
    func_020b49bc((Unk020b4934 **) ((int *) (u32) (*((int *) ((u32) (&data_ov000_021b4c84))) + 0x24)),
                  (void *) (uVar1));
    uVar1 = ((int) func_0204799c((const char *) (((u32) ((u32) (&data_ov000_021b0eb4))))));
    func_020b48b4((void **) ((int *) (u32) (*((int *) ((u32) (&data_ov000_021b4c84))) + 0x20)), (void *) (uVar1));
    uVar1 = ((int) func_0204799c((const char *) (((u32) ((u32) (&data_ov000_021b0ed0))))));
    func_020b4a44((Unk020b4a44 **) ((int *) (u32) (*((int *) ((u32) (&data_ov000_021b4c84))) + 0x28)),
                  (void *) (uVar1));
    func_0214bea4((u32) (*(u32 *) (*(int *) (*((int *) ((u32) (&data_ov000_021b4c84))) + 0x24) + 0x14)), (int) (0),
                  (u32) (*(u32 *) (*(int *) (*((int *) ((u32) (&data_ov000_021b4c84))) + 0x24) + 0x10)));
    func_0214c028((u32) (*(u32 *) (*(int *) (*((int *) ((u32) (&data_ov000_021b4c84))) + 0x28) + 0xc)), (int) (0),
                  (u32) (*(u32 *) (*(int *) (*((int *) ((u32) (&data_ov000_021b4c84))) + 0x28) + 8)));
    return;
}

// non-matching: 0x20 bytes, original 0x1c; 2 instructions differ; first at +0x8: original nothing, ours `lsl r0, #0x18`
u32 func_ov000_02185184(void) {
    u32 uVar1;
    uVar1 = ((s8) func_0205e548());
    if (60 <= uVar1) {
        return 1;
    }
    return 0;
}

void func_ov000_02185164(void) {
    int iVar1;
    iVar1 = func_02036c5c();
    if (iVar1 != 0) {
        *(u32 *) (*((int *) ((u32) (&data_ov000_021b4c84))) + 4) = 1;
    }
    return;
}
