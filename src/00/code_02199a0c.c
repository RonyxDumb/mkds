#include "00/code_02199a0c.h"

u32 func_ov000_02199a0c(int param_1, int param_2, u32 param_3, u32 param_4) {
    int iVar1;
    *(short *) (param_1 + 0x66) = *(unsigned short *) (param_1 + 0x66) + 1;
    if (param_2 == 0) {
        iVar1 = func_ov000_02199dd0((int) (param_1), (u32) (param_3), (u32) (param_4));
        if (iVar1 == 0) {
            return 0;
        }
    } else if (param_2 == 1) {
        iVar1 = func_ov000_02199d4c((int) (param_1), (u32) (param_3), (int) (param_4));
        if (iVar1 == 0) {
            return 0;
        }
    } else if (param_2 == 2) {
        iVar1 = func_ov000_02199c98((int) (param_1), (int) (param_3), (int) (param_4));
        if (iVar1 == 0) {
            return 0;
        }
    } else if (param_2 == 3) {
        iVar1 = func_ov000_02199bb4((u32 *) ((u32 *) (u32) (param_1)), (int) (param_3), (int) (param_4));
        if (iVar1 == 0) {
            return 0;
        }
    } else if (param_2 == 4) {
        iVar1 = func_ov000_02199b70();
        if (iVar1 == 0) {
            return 0;
        }
    } else if (param_2 == 5) {
        iVar1 = func_ov000_02199b14((int) (param_1), (u32) (param_3), (u32) (param_4));
        if (iVar1 == 0) {
            return 0;
        }
    } else if ((param_2 == 6) && (iVar1 = func_ov000_02199ad8(), iVar1 == 0)) {
        return 0;
    }
    return 1;
}
