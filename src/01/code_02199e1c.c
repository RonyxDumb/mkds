#include "01/code_02199e1c.h"

// non-matching: 0xf0 bytes, original 0xfc; 30 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4,
// lr}`
void func_ov001_02199e3c(void) {
    u32 uVar1;
    int local_10;
    int local_c;
    int local_8[1];
    uVar1 = ((int) func_0204799c((const char *) (((u32) ((u32) (&data_ov001_021a866c))))));
    func_020b4934((Unk020b4934 **) (&local_10), (void *) (uVar1));
    uVar1 = ((int) func_0204799c((const char *) (((u32) ((u32) (&data_ov001_021a8688))))));
    func_020b47d8((Unk020b47d8 **) (&local_c), (void *) (uVar1));
    uVar1 = ((int) func_0204799c((const char *) (((u32) ((u32) (&data_ov001_021a86a0))))));
    func_020b4a44((Unk020b4a44 **) (local_8), (void *) (uVar1));
    uVar1 = ((int) func_0204799c((const char *) (((u32) ((u32) (&data_ov001_021a86bc))))));
    *(u32 *) (*((int *) ((u32) (&data_ov001_021a9bec))) + 0x2c) = uVar1;
    uVar1 = ((int) func_0204799c((const char *) (((u32) ((u32) (&data_ov001_021a86d8))))));
    *(u32 *) (*((int *) ((u32) (&data_ov001_021a9bec))) + 0x30) = uVar1;
    uVar1 = ((int) func_0204799c((const char *) (((u32) ((u32) (&data_ov001_021a86f4))))));
    func_020b49bc((Unk020b4934 **) ((int *) (u32) (*((int *) ((u32) (&data_ov001_021a9bec))) + 0x24)),
                  (void *) (uVar1));
    uVar1 = ((int) func_0204799c((const char *) (((u32) ((u32) (&data_ov001_021a8714))))));
    func_020b48b4((void **) ((int *) (u32) (*((int *) ((u32) (&data_ov001_021a9bec))) + 0x20)), (void *) (uVar1));
    uVar1 = ((int) func_0204799c((const char *) (((u32) ((u32) (&data_ov001_021a8734))))));
    func_020b4a44((Unk020b4a44 **) ((int *) (u32) (*((int *) ((u32) (&data_ov001_021a9bec))) + 0x28)),
                  (void *) (uVar1));
    ((u32) func_02016468((u32) (4), (u32) (0), (void *) (*(u32 *) (local_10 + 0x14)),
                         (u32) (*(u32 *) (local_10 + 0x10))));
    ((u32) func_02016468((u32) (8), (u32) (0), (void *) (local_c + 0xc), (u32) (*(u32 *) (local_c + 8))));
    ((u32) func_02016468((u32) (0xf), (u32) (0), (void *) (*(u32 *) (local_8[0] + 0xc)), (u32) (((u32) 0x00000100u))));
    ((u32) func_02016468((u32) (0x23), (u32) (0),
                         (void *) (*(u32 *) (*(int *) (*((int *) ((u32) (&data_ov001_021a9bec))) + 0x24) + 0x14)),
                         (u32) (*(u32 *) (*(int *) (*((int *) ((u32) (&data_ov001_021a9bec))) + 0x24) + 0x10))));
    ((u32) func_02016468((u32) (0x1e), (u32) (0),
                         (void *) (*(u32 *) (*(int *) (*((int *) ((u32) (&data_ov001_021a9bec))) + 0x28) + 0xc)),
                         (u32) (*(u32 *) (*(int *) (*((int *) ((u32) (&data_ov001_021a9bec))) + 0x28) + 8))));
    return;
}

void func_ov001_02199e1c(void) {
    int iVar1;
    iVar1 = func_02036c5c();
    if (iVar1 != 0) {
        *(u32 *) (*((int *) ((u32) (&data_ov001_021a9bec))) + 4) = 1;
    }
    return;
}
