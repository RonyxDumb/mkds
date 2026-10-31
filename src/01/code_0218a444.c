#include "01/code_0218a444.h"

void func_ov001_0218a52c(int param_1) {
    func_ov001_02187218((Unk02188950 *) param_1, 7, (s32 (*)(Unk02188950 *)) (0));
    func_ov001_02188d30((Unk02188950 *) param_1, (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x174)), (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x178)), (UnkFunc *) 0);
    func_ov001_021881f4((Unk02188950 *) param_1, (UnkFunc *) &func_ov001_02189ed8);
}

void func_ov001_0218a4d0(int param_1) {
    func_ov001_02187218((Unk02188950 *) param_1, 7,
                        (s32(*)(Unk02188950 *))((int) &func_ov001_0218a568));
    func_ov001_02188d64((Unk02188950 *) param_1, (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x164)), (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x168)));
    func_ov001_02188dcc((Unk02188950 *) (param_1), (UnkFunc *) ((int) &func_ov001_0218a52c));
    func_ov001_02188cec((Unk02188950 *) param_1, 0);
    *(u32 *) (param_1 + 0x2bc) = 1;
    func_ov001_021881f4((Unk02188950 *) param_1, (UnkFunc *) &func_ov001_02189fe0);
}

void func_ov001_0218a4a0(int param_1) {
    func_ov001_02187218((Unk02188950 *) param_1, 7, (s32 (*)(Unk02188950 *)) (0));
    func_ov001_02188d30((Unk02188950 *) param_1, (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x70)), (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x74)), (UnkFunc *) 0);
    func_ov001_021881f4((Unk02188950 *) param_1, (UnkFunc *) &func_ov001_02189ed8);
}

void func_ov001_0218a444(int param_1) {
    func_ov001_02187218((Unk02188950 *) param_1, 7,
                        (s32(*)(Unk02188950 *))((int) &func_ov001_0218a568));
    func_ov001_02188d64((Unk02188950 *) param_1, (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x164)), (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x168)));
    func_ov001_02188dcc((Unk02188950 *) (param_1), (UnkFunc *) ((int) &func_ov001_0218a4a0));
    func_ov001_02188cec((Unk02188950 *) param_1, 0);
    *(u32 *) (param_1 + 0x2bc) = 1;
    func_ov001_021881f4((Unk02188950 *) param_1, (UnkFunc *) &func_ov001_02189fe0);
}
