#include "01/code_0219b000.h"

// non-matching: 0x1b4 bytes, original 0x1c4; 38 instructions differ; first at +0x0: original `push {r4, lr}`, ours
// `push {r4, r5, lr}`
void func_ov001_0219b000(void) {
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
    uVar1 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_0216cd24))))));
    func_020b4934((Unk020b4934 **) (&local_18), (void *) (uVar1));
    uVar1 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_0216cce8))))));
    func_020b4a44((Unk020b4a44 **) (&local_14), (void *) (uVar1));
    uVar1 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_0216cd10))))));
    func_020b47d8((Unk020b47d8 **) (local_10), (void *) (uVar1));
    uVar1 = ((u32) func_02036bec((void *) (*(u32 *) (*((int *) ((u32) (&data_ov001_021a9bf0))) + 0x2c)),
                                 (u32) (((u32) 0x00000800u))));
    *(u32 *) (*((int *) ((u32) (&data_ov001_021a9bf0))) + 0x28) = uVar1;
    uVar1 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_0216ccdc))))));
    *(u32 *) (*((int *) ((u32) (&data_ov001_021a9bf0))) + 4) = uVar1;
    uVar1 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_0216cd08))))));
    *(u32 *) (*((int *) ((u32) (&data_ov001_021a9bf0))) + 8) = uVar1;
    uVar1 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_0216cce0))))));
    func_020b49bc((Unk020b4934 **) (&local_28), (void *) (uVar1));
    uVar1 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_0216cd30))))));
    func_020b48b4((void **) ((int *) (u32) (*((int *) ((u32) (&data_ov001_021a9bf0))))), (void *) (uVar1));
    uVar1 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_0216ccf4))))));
    func_020b4a44((Unk020b4a44 **) (&local_24), (void *) (uVar1));
    uVar1 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_0216cc88))))));
    *(u32 *) (*((int *) ((u32) (&data_ov001_021a9bf0))) + 0x10) = uVar1;
    uVar1 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_0216cca0))))));
    *(u32 *) (*((int *) ((u32) (&data_ov001_021a9bf0))) + 0x14) = uVar1;
    uVar1 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_0216ccb4))))));
    func_020b49bc((Unk020b4934 **) (&local_20), (void *) (uVar1));
    uVar1 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_0216ccac))))));
    func_020b48b4((void **) ((int *) (u32) (*((int *) ((u32) (&data_ov001_021a9bf0))) + 0xc)), (void *) (uVar1));
    uVar1 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_0216ccf0))))));
    func_020b4a44((Unk020b4a44 **) (&local_1c), (void *) (uVar1));
    iVar2 = *(int *) (local_24 + 0xc);
    ((u32) func_02016468((u32) (4), (u32) (0), (void *) (*(u32 *) (local_18 + 0x14)),
                         (u32) (*(u32 *) (local_18 + 0x10))));
    ((u32) func_02016468((u32) (0xf), (u32) (0), (void *) (*(u32 *) (local_14 + 0xc)), (u32) (0x60)));
    ((u32) func_02016468((u32) (8), (u32) (0), (void *) (local_10[0] + 0xc), (u32) (*(u32 *) (local_10[0] + 8))));
    ((u32) func_02016468((u32) (8), (u32) (((u32) 0x00000800u)),
                         (void *) (*(u32 *) (*((int *) ((u32) (&data_ov001_021a9bf0))) + 0x28)),
                         (u32) (((u32) 0x00000800u))));
    ((u32) func_02016468((u32) (0x13), (u32) (0), (void *) (*(u32 *) (local_28 + 0x14)),
                         (u32) (*(u32 *) (local_28 + 0x10))));
    ((u32) func_02016468((u32) (0xe), (u32) (0), (void *) (*(u32 *) (local_24 + 0xc)), (u32) (((u32) 0x000001a0u))));
    ((u32) func_02016468((u32) (0xe), (u32) (((int) 0x000001c0u)), (void *) (iVar2 + ((int) 0x000001c0u)),
                         (u32) (0x40)));
    ((u32) func_02016468((u32) (0x23), (u32) (0), (void *) (*(u32 *) (local_20 + 0x14)),
                         (u32) (*(u32 *) (local_20 + 0x10))));
    ((u32) func_02016468((u32) (0x1e), (u32) (0), (void *) (*(u32 *) (local_1c + 0xc)),
                         (u32) (*(u32 *) (local_1c + 8))));
    return;
}
