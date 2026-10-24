#include "00/code_021a2e7c.h"

// non-matching: 0x6c bytes, original 0x70; 19 instructions differ; first at +0x4: original `mov r7, r1`, ours `mov r6,
// r1`
void func_ov000_021a2e7c(u32 param_1, u32 param_2, int param_3) {
    int iVar1;
    u32 iVar2;
    u64 uVar3;
    iVar1 = func_ov000_0219b9c4();
    iVar2 = *((int *) ((u32) (&data_ov000_021b5dd0))) + iVar1 * 0x30;
    if ((*(int *) (iVar2 + 4) != 0) && (*(int *) (iVar2 + 8) >= param_3)) {
        func_0214d1fc((const void *) ((u16 *) (u32) (param_2)), (void *) ((u32 *) (u32) (*(int *) (iVar2 + 4))),
                      (u32) (param_3));
        if (*(UnkFunc **) (*((int *) ((u32) (&data_ov000_021b5dd0))) + ((int) 0x00000604u)) != (UnkFunc *) 0x0) {
            (**(UnkFunc **) (*((int *) ((u32) (&data_ov000_021b5dd0))) + ((int) 0x00000604u)))(
                iVar1, *(u32 *) (iVar2 + 4), param_3);
        }
        if ((*(int *) (*((int *) ((u32) (&data_ov000_021b5dd0))) + ((int) 0x00000608u)) != 0) &&
            (*(int *) (iVar2 + 0x2c) != 0)) {
            uVar3 = func_0200f5ac();
            *(u64 *) (iVar2 + 0x24) = uVar3;
        }
    }
    return;
}
