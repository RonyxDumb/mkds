#include "01/code_021910fc.h"

void func_ov001_0219116c(int param_1) {
    func_ov001_02187218((Unk02188950 *) (param_1), (int) (7), (s32 (*)(Unk02188950 *)) ((int) (0)));
    func_ov001_02188d30((Unk02188950 *) (param_1), (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + ((int) 0x00000234u))), (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + ((int) 0x00000238u))), (UnkFunc *) (((u32) ((u32) (&func_ov001_021918c8)))));
    func_ov001_021922e0((int) (param_1));
    return;
}

void func_ov001_02191130(int param_1) {
    func_ov001_02187218((Unk02188950 *) (param_1), (int) (7), (s32 (*)(Unk02188950 *)) ((int) (0)));
    func_ov001_02188d30((Unk02188950 *) (param_1), (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + ((int) 0x0000022cu))), (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + ((int) 0x00000230u))), (UnkFunc *) (((u32) ((u32) (&func_ov001_0219116c)))));
    func_ov001_021921e4((int) (param_1));
    return;
}

s32 func_ov001_021910fc(Unk02188950 *param_1) {
    if ((param_1->mUnk_2c8 & 0x001e34ef) != 0) {
        func_020d2774((int) (param_1), (u32) (0x218));
        param_1->mUnk_158 = 0;
    }
    return 0;
}
