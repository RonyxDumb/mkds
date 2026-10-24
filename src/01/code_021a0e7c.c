#include "01/code_021a0e7c.h"

// non-matching: 0x220 bytes, original 0x23c; 60 instructions differ; first at +0x0: original `push {r4, lr}`, ours
// `push {r4, r5, lr}`
void func_ov001_021a0e7c(void) {
    u32 uVar1;
    int iVar2;
    int local_28;
    int local_24;
    int local_20;
    int local_1c;
    int local_18;
    int local_14;
    int local_10[2];
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    local_14 = 0;
    local_10[0] = 0;
    uVar1 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_ov001_021a92bc))))));
    func_020b4934((Unk020b4934 **) (&local_1c), (void *) (uVar1));
    uVar1 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_ov001_021a92a8))))));
    func_020b4a44((Unk020b4a44 **) (local_10), (void *) (uVar1));
    uVar1 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_ov001_021a928c))))));
    func_020b47d8((Unk020b47d8 **) (&local_18), (void *) (uVar1));
    uVar1 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_ov001_021a92c0))))));
    func_020b47d8((Unk020b47d8 **) (&local_14), (void *) (uVar1));
    uVar1 = ((u32) func_02036bec((void *) (*(u32 *) (*((int *) ((u32) (&data_ov001_021ca414))) + 0x5c)),
                                 (u32) (((u32) 0x00000800u))));
    *(u32 *) (*((int *) ((u32) (&data_ov001_021ca414))) + 0x48) = uVar1;
    uVar1 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_ov001_021a929c))))));
    *(u32 *) (*((int *) ((u32) (&data_ov001_021ca414))) + 4) = uVar1;
    uVar1 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_ov001_021a92ac))))));
    *(u32 *) (*((int *) ((u32) (&data_ov001_021ca414))) + 8) = uVar1;
    uVar1 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_ov001_021a9278))))));
    func_020b49bc((Unk020b4934 **) (&local_28), (void *) (uVar1));
    uVar1 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_ov001_021a92c4))))));
    func_020b48b4((void **) ((int *) (u32) (*((int *) ((u32) (&data_ov001_021ca414))))), (void *) (uVar1));
    uVar1 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_ov001_021a9298))))));
    func_020b4a44((Unk020b4a44 **) (&local_24), (void *) (uVar1));
    uVar1 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_ov001_021a92a4))))));
    *(u32 *) (*((int *) ((u32) (&data_ov001_021ca414))) + 0x10) = uVar1;
    uVar1 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_ov001_021a92a0))))));
    *(u32 *) (*((int *) ((u32) (&data_ov001_021ca414))) + 0x14) = uVar1;
    uVar1 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_ov001_021a9280))))));
    *(u32 *) (*((int *) ((u32) (&data_ov001_021ca414))) + 0x18) = uVar1;
    uVar1 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_ov001_021a92b0))))));
    func_020b49bc((Unk020b4934 **) (&local_20), (void *) (uVar1));
    uVar1 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_ov001_021a9284))))));
    func_020b48b4((void **) ((int *) (u32) (*((int *) ((u32) (&data_ov001_021ca414))) + 0xc)), (void *) (uVar1));
    uVar1 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_ov001_021a927c))))));
    func_020b4a44((Unk020b4a44 **) ((int *) (u32) (*((int *) ((u32) (&data_ov001_021ca414))) + 0x1c)),
                  (void *) (uVar1));
    iVar2 = *(int *) (local_24 + 0xc);
    ((u32) func_02016468((u32) (4), (u32) (0), (void *) (*(u32 *) (local_1c + 0x14)),
                         (u32) (*(u32 *) (local_1c + 0x10))));
    ((u32) func_02016468((u32) (0xf), (u32) (0), (void *) (*(u32 *) (local_10[0] + 0xc)), (u32) (0x40)));
    ((u32) func_02016468((u32) (8), (u32) (0), (void *) (local_18 + 0xc), (u32) (*(u32 *) (local_18 + 8))));
    ((u32) func_02016468((u32) (8), (u32) (((u32) 0x00000800u)),
                         (void *) (*(u32 *) (*((int *) ((u32) (&data_ov001_021ca414))) + 0x48)),
                         (u32) (((u32) 0x00000800u))));
    ((u32) func_02016468((u32) (8), (u32) (((u32) 0x00001000u)),
                         (void *) (*(u32 *) (*((int *) ((u32) (&data_ov001_021ca414))) + 0x48)),
                         (u32) (((u32) 0x00000800u))));
    ((u32) func_02016468((u32) (8), (u32) (((u32) 0x00001800u)),
                         (void *) (*(u32 *) (*((int *) ((u32) (&data_ov001_021ca414))) + 0x48)),
                         (u32) (((u32) 0x00000800u))));
    ((u32) func_02016468((u32) (9), (u32) (0), (void *) (local_14 + 0xc), (u32) (*(u32 *) (local_14 + 8))));
    ((u32) func_02016468((u32) (9), (u32) (((u32) 0x00000800u)),
                         (void *) (*(u32 *) (*((int *) ((u32) (&data_ov001_021ca414))) + 0x48)),
                         (u32) (((u32) 0x00000800u))));
    ((u32) func_02016468((u32) (0x13), (u32) (0), (void *) (*(u32 *) (local_28 + 0x14)),
                         (u32) (*(u32 *) (local_28 + 0x10))));
    ((u32) func_02016468((u32) (0xe), (u32) (0), (void *) (*(u32 *) (local_24 + 0xc)), (u32) (((u32) 0x000001a0u))));
    ((u32) func_02016468((u32) (0xe), (u32) (((int) 0x000001c0u)), (void *) (iVar2 + ((int) 0x000001c0u)),
                         (u32) (0x40)));
    ((u32) func_02016468((u32) (0x23), (u32) (0), (void *) (*(u32 *) (local_20 + 0x14)),
                         (u32) (*(u32 *) (local_20 + 0x10))));
    ((u32) func_02016468((u32) (0x1e), (u32) (0),
                         (void *) (*(u32 *) (*(int *) (*((int *) ((u32) (&data_ov001_021ca414))) + 0x1c) + 0xc)),
                         (u32) (*(u32 *) (*(int *) (*((int *) ((u32) (&data_ov001_021ca414))) + 0x1c) + 8))));
    return;
}
