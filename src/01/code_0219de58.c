#include "01/code_0219de58.h"

// non-matching: 0x100 bytes, original 0x10c; 32 instructions differ; first at +0x0: original `push {lr}`, ours `push
// {r4, lr}`
void func_ov001_0219de58(void) {
    u32 uVar1;
    int local_10;
    int local_c;
    int local_8[1];
    uVar1 = ((int) func_0204799c((const char *) (((u32) ((u32) (&data_ov001_021a8ce0))))));
    func_020b4934((Unk020b4934 **) (&local_10), (void *) (uVar1));
    uVar1 = ((int) func_0204799c((const char *) (((u32) ((u32) (&data_ov001_021a8cfc))))));
    func_020b47d8((Unk020b47d8 **) (&local_c), (void *) (uVar1));
    uVar1 = ((int) func_0204799c((const char *) (((u32) ((u32) (&data_ov001_021a8d14))))));
    func_020b4a44((Unk020b4a44 **) (local_8), (void *) (uVar1));
    uVar1 = ((int) func_0204799c((const char *) (((u32) ((u32) (&data_ov001_021a8d30))))));
    *(u32 *) (*((int *) ((u32) (&data_ov001_021a9bfc))) + 0x44) = uVar1;
    uVar1 = ((int) func_0204799c((const char *) (((u32) ((u32) (&data_ov001_021a8d4c))))));
    *(u32 *) (*((int *) ((u32) (&data_ov001_021a9bfc))) + 0x48) = uVar1;
    uVar1 = ((int) func_0204799c((const char *) (((u32) ((u32) (&data_ov001_021a8d68))))));
    *(u32 *) (*((int *) ((u32) (&data_ov001_021a9bfc))) + 0x4c) = uVar1;
    uVar1 = ((int) func_0204799c((const char *) (((u32) ((u32) (&data_ov001_021a8d84))))));
    func_020b49bc((Unk020b4934 **) ((int *) (u32) (*((int *) ((u32) (&data_ov001_021a9bfc))) + 0x3c)),
                  (void *) (uVar1));
    uVar1 = ((int) func_0204799c((const char *) (((u32) ((u32) (&data_ov001_021a8da4))))));
    func_020b48b4((void **) ((int *) (u32) (*((int *) ((u32) (&data_ov001_021a9bfc))) + 0x38)), (void *) (uVar1));
    uVar1 = ((int) func_0204799c((const char *) (((u32) ((u32) (&data_ov001_021a8dc4))))));
    func_020b4a44((Unk020b4a44 **) ((int *) (u32) (*((int *) ((u32) (&data_ov001_021a9bfc))) + 0x40)),
                  (void *) (uVar1));
    ((u32) func_02016468((u32) (4), (u32) (0), (void *) (*(u32 *) (local_10 + 0x14)),
                         (u32) (*(u32 *) (local_10 + 0x10))));
    ((u32) func_02016468((u32) (8), (u32) (0), (void *) (local_c + 0xc), (u32) (*(u32 *) (local_c + 8))));
    ((u32) func_02016468((u32) (0xf), (u32) (0), (void *) (*(u32 *) (local_8[0] + 0xc)), (u32) (((u32) 0x00000100u))));
    ((u32) func_02016468((u32) (0x23), (u32) (0),
                         (void *) (*(u32 *) (*(int *) (*((int *) ((u32) (&data_ov001_021a9bfc))) + 0x3c) + 0x14)),
                         (u32) (*(u32 *) (*(int *) (*((int *) ((u32) (&data_ov001_021a9bfc))) + 0x3c) + 0x10))));
    ((u32) func_02016468((u32) (0x1e), (u32) (0),
                         (void *) (*(u32 *) (*(int *) (*((int *) ((u32) (&data_ov001_021a9bfc))) + 0x40) + 0xc)),
                         (u32) (*(u32 *) (*(int *) (*((int *) ((u32) (&data_ov001_021a9bfc))) + 0x40) + 8))));
    return;
}
