#include "01/code_0219c544.h"

// non-matching: 0x190 bytes, original 0x1ac; 52 instructions differ; first at +0x0: original `push {lr}`, ours `push
// {r4, lr}`
void func_ov001_0219c544(void) {
    u32 uVar1;
    int local_18;
    int local_14;
    int local_10;
    int local_c[1];
    local_18 = 0;
    local_14 = 0;
    local_10 = 0;
    local_c[0] = 0;
    uVar1 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_ov001_021a87b8))))));
    func_020b4934((Unk020b4934 **) (&local_14), (void *) (uVar1));
    uVar1 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_ov001_021a8794))))));
    func_020b47d8((Unk020b47d8 **) (local_c), (void *) (uVar1));
    uVar1 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_ov001_021a87a8))))));
    func_020b4a44((Unk020b4a44 **) (&local_10), (void *) (uVar1));
    uVar1 = ((u32) func_02036bec((void *) (*(u32 *) (*((int *) ((u32) (&data_ov001_021a9bf4))) + 0x44)),
                                 (u32) (((u32) 0x00000800u))));
    *(u32 *) (*((int *) ((u32) (&data_ov001_021a9bf4))) + 0x40) = uVar1;
    uVar1 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_ov001_021a879c))))));
    *(u32 *) (*((int *) ((u32) (&data_ov001_021a9bf4))) + 4) = uVar1;
    uVar1 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_ov001_021a87b0))))));
    *(u32 *) (*((int *) ((u32) (&data_ov001_021a9bf4))) + 8) = uVar1;
    uVar1 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_ov001_021a87bc))))));
    func_020b48b4((void **) ((int *) (u32) (*((int *) ((u32) (&data_ov001_021a9bf4))))), (void *) (uVar1));
    uVar1 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_ov001_021a8790))))));
    *(u32 *) (*((int *) ((u32) (&data_ov001_021a9bf4))) + 0x10) = uVar1;
    uVar1 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_ov001_021a87a0))))));
    *(u32 *) (*((int *) ((u32) (&data_ov001_021a9bf4))) + 0x14) = uVar1;
    uVar1 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_ov001_021a87ac))))));
    *(u32 *) (*((int *) ((u32) (&data_ov001_021a9bf4))) + 0x18) = uVar1;
    uVar1 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_ov001_021a87a4))))));
    func_020b49bc((Unk020b4934 **) (&local_18), (void *) (uVar1));
    uVar1 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_ov001_021a87b4))))));
    func_020b48b4((void **) ((int *) (u32) (*((int *) ((u32) (&data_ov001_021a9bf4))) + 0xc)), (void *) (uVar1));
    uVar1 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_ov001_021a8798))))));
    func_020b4a44((Unk020b4a44 **) ((int *) (u32) (*((int *) ((u32) (&data_ov001_021a9bf4))) + 0x1c)),
                  (void *) (uVar1));
    uVar1 = func_020b4018((int) (0));
    *(u32 *) (*((int *) ((u32) (&data_ov001_021a9bf4))) + 0x20) = uVar1;
    uVar1 = func_020b400c((int) (0));
    *(u32 *) (*((int *) ((u32) (&data_ov001_021a9bf4))) + 0x24) = uVar1;
    uVar1 = func_020b4030((int) (0));
    *(u32 *) (*((int *) ((u32) (&data_ov001_021a9bf4))) + 0x28) = uVar1;
    uVar1 = func_020b4000((int) (0));
    *(u32 *) (*((int *) ((u32) (&data_ov001_021a9bf4))) + 0x2c) = uVar1;
    ((u32) func_02016468((u32) (0x17), (u32) (0), (void *) (*(u32 *) (local_14 + 0x14)),
                         (u32) (*(u32 *) (local_14 + 0x10))));
    ((u32) func_02016468((u32) (0x1f), (u32) (0), (void *) (*(u32 *) (local_10 + 0xc)), (u32) (0x20)));
    ((u32) func_02016468((u32) (0x1b), (u32) (0), (void *) (local_c[0] + 0xc), (u32) (*(u32 *) (local_c[0] + 8))));
    ((u32) func_02016468((u32) (0x1b), (u32) (((u32) 0x00000800u)),
                         (void *) (*(u32 *) (*((int *) ((u32) (&data_ov001_021a9bf4))) + 0x40)),
                         (u32) (((u32) 0x00000800u))));
    ((u32) func_02016468((u32) (0x23), (u32) (0), (void *) (*(u32 *) (local_18 + 0x14)),
                         (u32) (*(u32 *) (local_18 + 0x10))));
    ((u32) func_02016468((u32) (0x1e), (u32) (0),
                         (void *) (*(u32 *) (*(int *) (*((int *) ((u32) (&data_ov001_021a9bf4))) + 0x1c) + 0xc)),
                         (u32) (*(u32 *) (*(int *) (*((int *) ((u32) (&data_ov001_021a9bf4))) + 0x1c) + 8))));
    return;
}
