#include "01/code_021874c4.h"

void func_ov001_021875c0(int param_1, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6) {
    int iVar1;
    int iVar2;
    iVar2 = 0;
    iVar1 = param_1;
    do {
        if (*(int *) (iVar1 + 0xd0) == 0) {
            *(u32 *) (param_1 + iVar2 * 0x18 + 0xbc) = 1;
            func_ov001_02187614((Unk02188950 *) (param_1), (s32) (iVar2), (s32) (param_2), (s32) (param_3), (s32) (param_4), (u32) (param_5), (s32) (param_6));
            return;
        }
        iVar1 = iVar1 + 0x18;
        iVar2 = iVar2 + 1;
    } while (iVar2 < 5);
    return;
}

void func_ov001_0218756c(int param_1, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6) {
    int iVar1;
    int iVar2;
    iVar2 = 0;
    iVar1 = param_1;
    do {
        if (*(int *) (iVar1 + 0xd0) == 0) {
            *(u32 *) (param_1 + iVar2 * 0x18 + 0xbc) = 2;
            func_ov001_02187614((Unk02188950 *) (param_1), (s32) (iVar2), (s32) (param_2), (s32) (param_3), (s32) (param_4), (u32) (param_5), (s32) (param_6));
            return;
        }
        iVar1 = iVar1 + 0x18;
        iVar2 = iVar2 + 1;
    } while (iVar2 < 5);
    return;
}

void func_ov001_02187518(int param_1, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6) {
    int iVar1;
    int iVar2;
    iVar2 = 0;
    iVar1 = param_1;
    do {
        if (*(int *) (iVar1 + 0xd0) == 0) {
            *(u32 *) (param_1 + iVar2 * 0x18 + 0xbc) = 4;
            func_ov001_02187614((Unk02188950 *) (param_1), (s32) (iVar2), (s32) (param_2), (s32) (param_3), (s32) (param_4), (u32) (param_5), (s32) (param_6));
            return;
        }
        iVar1 = iVar1 + 0x18;
        iVar2 = iVar2 + 1;
    } while (iVar2 < 5);
    return;
}

void func_ov001_021874c4(int param_1, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6) {
    int iVar1;
    int iVar2;
    iVar2 = 0;
    iVar1 = param_1;
    do {
        if (*(int *) (iVar1 + 0xd0) == 0) {
            *(u32 *) (param_1 + iVar2 * 0x18 + 0xbc) = 5;
            func_ov001_02187614((Unk02188950 *) (param_1), (s32) (iVar2), (s32) (param_2), (s32) (param_3), (s32) (param_4), (u32) (param_5), (s32) (param_6));
            return;
        }
        iVar1 = iVar1 + 0x18;
        iVar2 = iVar2 + 1;
    } while (iVar2 < 5);
    return;
}
