#include "00/code_021960a4.h"
#include "00/code_0218e80c.h"

int func_ov000_021961e8(int *param_1, u32 param_2, u32 param_3, u32 param_4, u32 param_5) {
    int iVar1;
    int local_14;
    *(int *) (*param_1 + ((int) 0x00000210u)) = *(int *) (*param_1 + ((int) 0x00000210u)) + 1;
    iVar1 = func_ov000_021938cc((int *) (param_1), (int) (3), (int) (param_2), (int *) (&local_14), (int) (param_3),
                                (int) (param_4), (int) (param_5));
    if (((iVar1 == 0) && (iVar1 = func_ov000_021962d4((Unk0218f960 *) (param_1), (Unk021937c0Node *) (local_14)), iVar1 == 0)) &&
        ((*(int *) (local_14 + 8) == 0 ||
          (iVar1 = func_ov000_0218f2e8((int *) (param_1), (int) (*(u32 *) (local_14 + 0x18))), iVar1 == 0)))) {
        iVar1 = 0;
    }
    return iVar1;
}

int func_ov000_021960a4(u32 param_1, s8 *param_2, s8 *param_3, s8 *param_4, s8 *param_5, s8 *param_6, int param_7,
                        int param_8, u32 param_9, u32 param_10, u32 param_11) {
    int iVar1;
    int local_1c[2];
    if ((((((param_2 == (s8 *) 0x0) || (*param_2 == '\0')) && ((param_4 == (s8 *) 0x0 || (*param_4 == '\0')))) &&
          ((param_5 == (s8 *) 0x0 || (*param_5 == '\0')))) &&
         ((param_6 == (s8 *) 0x0 || (*param_6 == '\0')))) &&
        ((param_7 == 0 && ((param_3 == (s8 *) 0x0 || (*param_3 == '\0')))))) {
        func_ov000_02196590((u32 *) (u32) (param_1), data_ov000_021b38ac);
        return 2;
    }
    iVar1 = func_ov000_02196240((Unk0218f960 *) (param_1), (Unk02196240 **) (local_1c), (u32) (1));
    if (iVar1 == 0) {
        if (param_2 == (s8 *) 0x0) {
            *(u8 *) (local_1c[0] + 0x28) = 0;
        } else {
            func_ov000_02196914((u8 *) (local_1c[0] + 0x28), param_2, 0x1f);
        }
        if (param_3 == (s8 *) 0x0) {
            *(u8 *) (local_1c[0] + 0x47) = 0;
        } else {
            func_ov000_02196914((u8 *) (local_1c[0] + 0x47), param_3, 0x15);
        }
        if (param_4 == (s8 *) 0x0) {
            *(u8 *) (local_1c[0] + 0x5c) = 0;
        } else {
            func_ov000_02196914((u8 *) (local_1c[0] + 0x5c), param_4, 0x33);
        }
        func_ov000_0218e850((s8 *) ((s8 *) (u32) (local_1c[0] + 0x5c)));
        if (param_5 == (s8 *) 0x0) {
            *(u8 *) (local_1c[0] + 0x8f) = 0;
        } else {
            func_ov000_02196914((u8 *) (local_1c[0] + 0x8f), param_5, 0x1f);
        }
        if (param_6 == (s8 *) 0x0) {
            *(u8 *) (local_1c[0] + 0xae) = 0;
        } else {
            func_ov000_02196914((u8 *) (local_1c[0] + 0xae), param_6, 0x1f);
        }
        *(int *) (local_1c[0] + ((int) 0x00000130u)) = param_7;
        if (param_8 < 0) {
            param_8 = 0;
        }
        *(int *) (local_1c[0] + ((int) 0x00000134u)) = param_8;
        iVar1 = func_ov000_021961e8((int *) ((int *) (u32) (param_1)), (u32) (local_1c[0]), (u32) (param_9),
                                    (u32) (param_10), (u32) (param_11));
        if (iVar1 == 0) {
            iVar1 = 0;
        }
    }
    return iVar1;
}
