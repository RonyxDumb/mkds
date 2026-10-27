#include "00/code_021a998c.h"

// non-matching: 39 instructions differ; first at +0x0: original `push {r4, r5, r6, lr}`, ours `push {r4, r5, r6, r7,
// lr}`
void func_ov000_021a998c(int param_1) {
    u8 *puVar1;
    int iVar2;
    iVar2 = *(int *) (param_1 + 0xc);
    puVar1 = (u8 *) (*(UnkWordFunc *) (*(u32 *) &data_ov000_021b63a4))(0x83);
    if (puVar1 == (u8 *) 0x0) {
        *(u8 *) (iVar2 + ((int) 0x00000429u)) = 9;
        return;
    }
    *puVar1 = 0x14;
    puVar1[1] = 3;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = 1;
    puVar1[5] = 1;
    func_0214d168((void *) ((u32 *) (u32) (iVar2 + ((int) 0x000001a0u))), (u8) (0), (u32) (8));
    puVar1[6] = 0x16;
    puVar1[7] = 3;
    puVar1[8] = 0;
    puVar1[9] = 0;
    puVar1[10] = 0x28;
    puVar1[0xb] = 0x14;
    puVar1[0xc] = 0;
    puVar1[0xd] = 0;
    puVar1[0xe] = 0x24;
    func_0214d1fc((const void *) ((u16 *) (u32) (iVar2 + ((int) 0x00000378u))),
                  (void *) ((u32 *) (u32) (iVar2 + ((int) 0x000003d0u))), (u32) (0x58));
    func_ov000_021aa50c((int *) ((int *) (u32) (iVar2)), (u32) ((u32) (u32) (puVar1 + 0xf)), (u32) (0));
    func_0214d1fc((const void *) ((u16 *) (u32) (iVar2 + ((int) 0x000003d0u))),
                  (void *) ((u32 *) (u32) (iVar2 + ((int) 0x00000378u))), (u32) (0x58));
    func_0214d1fc((const void *) ((u16 *) (u32) (iVar2 + ((int) 0x000002c0u))),
                  (void *) ((u32 *) (u32) (iVar2 + ((int) 0x0000031cu))), (u32) (0x5c));
    func_ov000_021aa468((int *) ((int *) (u32) (iVar2)), (u32) ((u32) (u32) (puVar1 + 0x1f)), (u32) (0));
    func_0214d1fc((const void *) ((u16 *) (u32) (iVar2 + ((int) 0x0000031cu))),
                  (void *) ((u32 *) (u32) (iVar2 + ((int) 0x000002c0u))), (u32) (0x5c));
    func_ov000_021abca0((int) (iVar2 + ((int) 0x000002c0u)), (int) ((int) (u32) (puVar1 + 0xb)), (u32) (0x28));
    func_ov000_021ab728((int) (iVar2 + ((int) 0x00000378u)), (int) ((int) (u32) (puVar1 + 0xb)), (u32) (0x28));
    iVar2 = func_ov000_021aa054((int) (iVar2), (int) ((int) (u32) (puVar1 + 6)));
    func_ov000_021adcec((int) ((int) (u32) (puVar1)), (u32) (iVar2 + 6), (int) (0), (int) (0), (int) (param_1));
    (*(UnkWordFunc *) (*(u32 *) &data_ov000_021b63ac))(puVar1);
    return;
}
