#include "03/code_021b7e58.h"

void func_ov003_021b7e94(int param_1, u32 param_2, int param_3) {
    int iVar1;
    iVar1 = _s32_div_f(param_2, 2);
    func_ov003_021b7d90(param_3, param_1 + iVar1, iVar1);
    func_ov003_021b7d90(param_3 + iVar1, param_1, iVar1);
    func_ov003_021b7d90(param_1, param_3, param_2);
    return;
}

u32 func_ov003_021b7e70(u32 param_1, int param_2) {
    u32 uVar1;
    if (0 < param_2) {
        uVar1 = (*(UnkWordFunc *) *((u32 *) ((u32) (&data_ov003_021d8a0c))))(param_2);
        return uVar1;
    }
    return 0;
}

void func_ov003_021b7e58(u32 param_1, u32 param_2) {
    (*(UnkFunc *) *((u32 *) ((u32) (&data_ov003_021d8a18))))(param_2);
    return;
}
