#include "01/code_02188158.h"

void func_ov001_02188200(int param_1, u32 param_2) {
    *(u32 *) (param_1 + ((int) 0x000002d4u)) = param_2;
    return;
}

void func_ov001_021881f4(int param_1, u32 param_2) {
    *(u32 *) (param_1 + ((int) 0x000002dcu)) = param_2;
    return;
}

u32 func_ov001_021881a8(int param_1, u32 param_2, int param_3, int param_4) {
    int iVar1;
    if ((((param_3 != 0) || (param_4 != 0)) &&
         ((param_3 == 0 || (iVar1 = func_ov001_02188f04((Unk02188950 *) (param_1), (Vec3 *) (param_2), (s32) (param_3)), iVar1 != 0)))) &&
        ((param_4 == 0 ||
          (iVar1 = func_ov001_02188eac((Unk02188950 *) ((int) (param_1)), (s32) ((int) (*(u32 *) (param_1 + ((int) 0x000001a8u)))), (Vec3 *) ((int *) ((int *) (u32) (param_2))), (s32) ((int) (param_4))),
           iVar1 != 0)))) {
        return 1;
    }
    return 0;
}

int func_ov001_02188158(u32 param_1, u32 param_2, u32 param_3) {
    int iVar1;
    int iVar2;
    int iVar3;
    int iVar4;
    iVar1 = func_020fd7f0();
    iVar4 = 0;
    if (0 < iVar1) {
        do {
            iVar2 = func_020fd7a4((int) (iVar4));
            if ((iVar2 != 0) &&
                (iVar3 = func_ov001_021881a8((int) (param_1), (u32) (iVar2 + 0x50), (int) (param_2), (int) (param_3)),
                 iVar3 != 0)) {
                return iVar2;
            }
            iVar4 = iVar4 + 1;
        } while (iVar4 < iVar1);
    }
    return 0;
}
