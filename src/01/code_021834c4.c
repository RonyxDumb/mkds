#include "01/code_021834c4.h"

u32 func_ov001_021835e0(u16 *param_1) {
    int iVar1;
    if ((*param_1 == ((u32) 0x000001f6u)) &&
        (iVar1 = func_0209b620((int) (*(u32 *) ((int) param_1 + ((int) 0x00000304u)))), iVar1 == 2)) {
        func_ov001_02187af4((int) ((int) (u32) (param_1)));
        func_ov001_021872e0((int) ((int) (u32) (param_1)), (int) (((u32) 0x00001000u)), (int) (0), (int) (0), (int) (0),
                            (u16) (((u32) 0x00000666u)), (int) (((u32) 0xfffff000u)), (int) (((u32) 0x00000428u)),
                            (u32) (0));
        func_ov001_021872e0((int) ((int) (u32) (param_1)), (int) (((u32) 0x00001000u)), (int) (0), (int) (0), (int) (0),
                            (u16) (((u32) 0x00000666u)), (int) (((u32) 0xfffff000u)), (int) (((u32) 0x00000429u)),
                            (u32) (0));
        func_ov001_021872e0((int) ((int) (u32) (param_1)), (int) (((u32) 0x00001000u)), (int) (0), (int) (0), (int) (0),
                            (u16) (((u32) 0x00000800u)), (int) (((u32) 0xfffff000u)), (int) (((u32) 0x0000042au)),
                            (u32) (0));
        func_020d2774((int) ((int) (u32) (param_1)), (u32) (((u32) 0x00000240u)));
    }
    return 0;
}

void func_ov001_021835b8(int param_1) {
    func_ov001_02187218(param_1, 8, ((u32) ((u32) (&func_ov001_02183780))));
    func_ov001_02188d64(param_1, *(u32 *) (*(int *) (param_1 + 0xa0) + 100),
                        *(u32 *) (*(int *) (param_1 + 0xa0) + 0x68));
    return;
}

void func_ov001_0218355c(u16 *param_1) {
    func_ov001_02187218((int) (u32) (param_1), 8, ((u32) ((u32) (&func_ov001_02183690))));
    if (*param_1 == ((u32) 0x000001f6u)) {
        func_ov001_02188d64((int) (u32) (param_1), *(u32 *) (*(int *) (param_1 + 0x50) + 0x58),
                            *(u32 *) (*(int *) (param_1 + 0x50) + 0x5c));
        func_ov001_02188e24((int) ((int) (u32) (param_1)), (u32) (*(u32 *) (*(int *) (param_1 + 0x50) + 0x60)),
                            (int) (((u32) ((u32) (&func_ov001_021835b8)))));
        return;
    }
    func_ov001_02188d30((int) (u32) (param_1), *(u32 *) (*(int *) (param_1 + 0x50) + 0x58),
                        *(u32 *) (*(int *) (param_1 + 0x50) + 0x5c), ((u32) ((u32) (&func_ov001_021835b8))));
    return;
}

void func_ov001_02183524(int param_1) {
    func_ov001_02187218(param_1, 8, ((u32) ((u32) (&func_ov001_021835e0))));
    func_ov001_02188d64(param_1, *(u32 *) (*(int *) (param_1 + 0xa0) + 0x4c),
                        *(u32 *) (*(int *) (param_1 + 0xa0) + 0x50));
    func_ov001_02188e24((int) (param_1), (u32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x54)),
                        (int) (((u32) ((u32) (&func_ov001_0218355c)))));
    return;
}

void func_ov001_021834fc(int param_1) {
    func_ov001_02187218(param_1, 8, ((u32) ((u32) (&func_ov001_021835e0))));
    func_ov001_02188d64(param_1, *(u32 *) (*(int *) (param_1 + 0xa0) + 0x40),
                        *(u32 *) (*(int *) (param_1 + 0xa0) + 0x44));
    return;
}

void func_ov001_021834c4(int param_1) {
    func_ov001_02187218(param_1, 8, ((u32) ((u32) (&func_ov001_021835e0))));
    func_ov001_02188d64(param_1, *(u32 *) (*(int *) (param_1 + 0xa0) + 0x34),
                        *(u32 *) (*(int *) (param_1 + 0xa0) + 0x38));
    func_ov001_02188e24((int) (param_1), (u32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x3c)),
                        (int) (((u32) ((u32) (&func_ov001_021834fc)))));
    return;
}
