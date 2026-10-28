#include "Main/Unknown/code_0211de40.h"

#pragma thumb on

void func_0211ded0(u32 param_1, void *param_2, void *param_3, u32 param_4, u16 param_5, s32 param_6) {
    u32 *p;
    u8 *dst;
    u32 v0 = 14;
    u32 id;
    u32 n;

    if (param_6 != 0) {
        if (param_6 == 1) {
            v0 = 30;
        }
    }
    id = ((u16 *) data_0215cee4)[param_1];
    p = *(u32 **) data_0217d370;
    func_02124748(id, (void *) p[1], (void *) p[0], (void *) p[3], param_6, param_4, param_2, param_3);
    p = *(u32 **) data_0217d370;
    dst = *(u8 **) (p[2] + 0xc);
    n = func_02124a68(id, (void *) p[1], (void *) p[3]);
    func_02016468(v0, param_5 << 5, dst + (n << 5), 32);
}

void func_0211de98(void) {
    u32 uVar1;
    Unk020b4934 *local_10;
    u32 local_c[1];
    local_10 = 0;
    local_c[0] = 0;
    uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216de54))));
    func_020b49f4(&local_10, (void *) (uVar1));
    uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216de58))));
    func_020b48ec((Unk02021dc8 **) (local_c), (void *) (uVar1));
    return;
}

void func_0211de40(void *param_1) {
    int iVar1;
    u32 uVar2;
    iVar1 = ((u32) func_02036bec((void *) (param_1), (u32) (0xc)));
    *(int *) &data_0217d36c = iVar1;
    uVar2 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216de54))));
    func_020b49bc((Unk020b4934 **) ((int *) (u32) ((*(int *) &data_0217d36c))), (void *) (uVar2));
    uVar2 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216de58))));
    func_020b48b4((Unk02021dc8 **) ((int *) (u32) ((*(int *) &data_0217d36c) + 4)), (void *) (uVar2));
    uVar2 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216de50))));
    *(u32 *) ((*(int *) &data_0217d36c) + 8) = uVar2;
    return;
}

#pragma thumb off
