#include "01/code_0218b770.h"

u32 func_ov001_0218b8d4(u32 param_1) {
    int iVar1;
    iVar1 = func_02061fec();
    if (iVar1 == 1) {
        func_ov001_02188e88((Unk02188950 *) ((u32) (param_1)));
    }
    return 0;
}

u32 func_ov001_0218b850(int param_1) {
    int iVar1;
    iVar1 = func_0209b620((int) (*(u32 *) (param_1 + ((int) 0x00000304u))));
    if (iVar1 == 0x4d) {
        func_ov001_02187af4((int) (param_1));
        func_ov001_02187518((int) (param_1), (u32) (((u32) 0xfffff99au)), (u32) (0), (u32) (((u32) 0xfffff99au)),
                            (u32) (((u32) 0x0000042bu)), (u32) (0));
        func_020d2774((int) (param_1), (u32) (((u32) 0x0000021eu)));
    } else {
        iVar1 = func_0209b620((int) (*(u32 *) (param_1 + ((int) 0x00000304u))));
        if (iVar1 == 0x68) {
            func_ov001_02187af4((int) (param_1));
            func_ov001_02187518((int) (param_1), (u32) (((u32) 0xfffff99au)), (u32) (0), (u32) (((u32) 0xfffff99au)),
                                (u32) (((u32) 0x0000042cu)), (u32) (0));
            func_020d2774((int) (param_1), (u32) (((u32) 0x0000021fu)));
        }
    }
    return 0;
}

void func_ov001_0218b828(int param_1) {
    func_ov001_02187218((Unk02188950 *) (param_1), (int) (8), (s32 (*)(Unk02188950 *)) ((int) (((u32) ((u32) (&func_ov001_0218b8d4))))));
    func_ov001_02188d64(param_1, *(u32 *) (*(int *) (param_1 + 0xa0) + 100),
                        *(u32 *) (*(int *) (param_1 + 0xa0) + 0x68));
    return;
}

void func_ov001_0218b7fc(int param_1) {
    func_ov001_02187218((Unk02188950 *) (param_1), (int) (8), (s32 (*)(Unk02188950 *)) ((int) (((u32) ((u32) (&func_ov001_0218b850))))));
    func_ov001_02188d30(param_1, *(u32 *) (*(int *) (param_1 + 0xa0) + 0x58),
                        *(u32 *) (*(int *) (param_1 + 0xa0) + 0x5c), ((u32) ((u32) (&func_ov001_0218b828))));
    return;
}

void func_ov001_0218b7c8(int param_1) {
    func_ov001_02187218((Unk02188950 *) (param_1), (int) (8), (s32 (*)(Unk02188950 *)) ((int) (0)));
    func_ov001_02188d64(param_1, *(u32 *) (*(int *) (param_1 + 0xa0) + 0x4c),
                        *(u32 *) (*(int *) (param_1 + 0xa0) + 0x50));
    func_ov001_02188e24((Unk02188950 *) ((int) (param_1)), (s32) ((u32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x54))), (UnkFunc *) ((int) (((u32) ((u32) (&func_ov001_0218b7fc))))));
    return;
}

void func_ov001_0218b7a4(int param_1) {
    func_ov001_02187218((Unk02188950 *) (param_1), (int) (8), (s32 (*)(Unk02188950 *)) ((int) (0)));
    func_ov001_02188d64(param_1, *(u32 *) (*(int *) (param_1 + 0xa0) + 0x40),
                        *(u32 *) (*(int *) (param_1 + 0xa0) + 0x44));
    return;
}

void func_ov001_0218b770(int param_1) {
    func_ov001_02187218((Unk02188950 *) (param_1), (int) (8), (s32 (*)(Unk02188950 *)) ((int) (0)));
    func_ov001_02188d64(param_1, *(u32 *) (*(int *) (param_1 + 0xa0) + 0x34),
                        *(u32 *) (*(int *) (param_1 + 0xa0) + 0x38));
    func_ov001_02188e24((Unk02188950 *) ((int) (param_1)), (s32) ((u32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x3c))), (UnkFunc *) ((int) (((u32) ((u32) (&func_ov001_0218b7a4))))));
    return;
}
