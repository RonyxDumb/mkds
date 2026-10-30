#include "00/code_0219c79c.h"

void func_ov000_0219c80c(char *param_1, char *param_2) {
    func_ov000_0219c79c(param_1, param_2, func_ov000_0219c824, 2);
    return;
}

void func_ov000_0219c79c(char *param_1, char *param_2, void (*param_3)(), s32 param_4) {
    u32 *puVar1;
    u32 iVar2;
    u64 uVar3;
    func_0213a2d0((char *) ((u32 *) (u32) ((*(int *) &data_ov000_021b565c) + 0x4c)), (const u8 *) (param_1));
    func_0213a2d0((char *) ((u32 *) (u32) ((*(int *) &data_ov000_021b565c) + ((int) 0x0000014cu))),
                  (const u8 *) (param_2));
    iVar2 = *(int *) &data_ov000_021b565c;
    uVar3 = func_0200f5ac();
    *(u64 *) (iVar2 + 0x38) = uVar3;
    *(u32 *) (iVar2 + 0x34) = 1;
    puVar1 = (u32 *) (*(int *) &data_ov000_021b565c);
    iVar2 = func_ov000_0219c8dc(func_ov000_0218f15c((int *) (u32) (*puVar1), (s8 *) (void *) (puVar1 + 0x13),
                                                    (s8 *) (u32) ((int) puVar1 + ((int) 0x0000014cu)), 1, 0, param_3, 0));
    if (iVar2 == 0) {
        *(u32 *) ((*(int *) &data_ov000_021b565c) + 4) = param_4;
    }
    return;
}
