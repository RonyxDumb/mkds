#include "00/code_021a2e7c.h"

void func_ov000_021a2e7c(Unk0219887c *param_1, u32 param_2, int param_3) {
    int iVar1;
    u32 iVar2;
    u64 uVar3;
    iVar1 = func_ov000_0219b9c4(param_1);
    iVar2 = (*(int *) &data_ov000_021b5dd0) + iVar1 * 0x30;
    if ((*(int *) (iVar2 + 4) != 0) && (*(int *) (iVar2 + 8) >= param_3)) {
        func_0214d1fc((const void *) ((u16 *) (u32) (param_2)), (void *) ((u32 *) (u32) (*(int *) (iVar2 + 4))),
                      (u32) (param_3));
        if (*(UnkFunc **) ((*(int *) &data_ov000_021b5dd0) + ((int) 0x00000604u)) != (UnkFunc *) 0x0) {
            (**(UnkFunc **) ((*(int *) &data_ov000_021b5dd0) + ((int) 0x00000604u)))(iVar1, *(u32 *) (iVar2 + 4),
                                                                                     param_3);
        }
        if ((*(int *) ((*(int *) &data_ov000_021b5dd0) + ((int) 0x00000608u)) != 0) && (*(int *) (iVar2 + 0x2c) != 0)) {
            uVar3 = func_0200f5ac();
            *(u64 *) (iVar2 + 0x24) = uVar3;
        }
    }
    return;
}
