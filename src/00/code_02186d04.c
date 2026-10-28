#include "00/code_02186d04.h"

void func_ov000_02186d04(int param_1) {
    if (param_1 != 0) {
        if (*(int *) (param_1 + 0xc) == 0) {
            func_ov000_02186a10((int) (param_1), (int *) ((int *) (u32) (param_1 + ((int) 0x00000938u))));
        }
        func_ov000_02186a10((int) (param_1), (int *) ((int *) (u32) (param_1 + ((int) 0x00000928u))));
        if (*(int *) (param_1 + ((int) 0x0000091cu)) != 0) {
            (**(UnkFunc **) (param_1 + 0x18))((u32) &data_ov000_021b1320, *(int *) (param_1 + ((int) 0x0000091cu)), 0);
            *(u32 *) (param_1 + ((int) 0x0000091cu)) = 0;
        }
        if (*(int *) (param_1 + ((int) 0x00000920u)) != 0) {
            (**(UnkFunc **) (param_1 + 0x18))((u32) &data_ov000_021b1334, *(int *) (param_1 + ((int) 0x00000920u)), 0);
            *(u32 *) (param_1 + ((int) 0x00000920u)) = 0;
        }
        func_0214d168((void *) ((u32 *) (u32) (param_1)), (u8) (0), (u32) (((u32) 0x00001a60u)));
    }
    return;
}
