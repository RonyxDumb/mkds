#include "00/code_021aa3b8.h"

// non-matching: 44 instructions differ; first at +0x0: original `push {r4, r5, lr}`, ours `push {r4, r5, r6, r7, lr}`
void func_ov000_021aa3b8(int param_1, int param_2) {
    int iVar1;
    u8 auStack_20[20];
    func_0214d1fc((const void *) ((u16 *) (u32) (param_1 + ((int) 0x00000378u))),
                  (void *) ((u32 *) (u32) (param_1 + ((int) 0x000003d0u))), (u32) (0x58));
    func_ov000_021aa50c((int *) ((int *) (u32) (param_1)), (u32) ((u32) (u32) (auStack_20)), (u32) (1));
    func_0214d1fc((const void *) ((u16 *) (u32) (param_1 + ((int) 0x000003d0u))),
                  (void *) ((u32 *) (u32) (param_1 + ((int) 0x00000378u))), (u32) (0x58));
    iVar1 = func_02134d30((const u8 *) (param_2), (const u8 *) ((u32) (u32) (auStack_20)), (int) (0x10));
    if (iVar1 != 0) {
        *(u8 *) (param_1 + ((int) 0x00000429u)) = 9;
        return;
    }
    func_0214d1fc((const void *) ((u16 *) (u32) (param_1 + ((int) 0x000002c0u))),
                  (void *) ((u32 *) (u32) (param_1 + ((int) 0x0000031cu))), (u32) (0x5c));
    func_ov000_021aa468((int *) ((int *) (u32) (param_1)), (u32) ((u32) (u32) (auStack_20)), (u32) (1));
    func_0214d1fc((const void *) ((u16 *) (u32) (param_1 + ((int) 0x0000031cu))),
                  (void *) ((u32 *) (u32) (param_1 + ((int) 0x000002c0u))), (u32) (0x5c));
    iVar1 = func_02134d30((const u8 *) (param_2 + 0x10), (const u8 *) ((u32) (u32) (auStack_20)), (int) (0x14));
    if (iVar1 != 0) {
        *(u8 *) (param_1 + ((int) 0x00000429u)) = 9;
        return;
    }
    *(u8 *) (param_1 + ((int) 0x00000429u)) = 6;
    return;
}
