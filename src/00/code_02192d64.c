#include "00/code_02192d64.h"

u32 func_ov000_02192d64(int *param_1, u32 param_2) {
    int iVar1;
    iVar1 = *param_1;
    if (0 < *(int *) (iVar1 + ((int) 0x00000448u))) {
        func_ov000_02190b80((unsigned int) ((u32) (u32) (param_1)), (unsigned int) (param_2),
                            (unsigned int) (((u32) ((u32) (&data_ov000_021b3184)))));
        func_ov000_02190b58(param_1, param_2, *(u32 *) (iVar1 + ((int) 0x00000198u)));
        func_ov000_02190b80((unsigned int) ((u32) (u32) (param_1)), (unsigned int) (param_2),
                            (unsigned int) (*(u32 *) (iVar1 + ((int) 0x00000440u))));
        func_ov000_02190b80((unsigned int) ((u32) (u32) (param_1)), (unsigned int) (param_2),
                            (unsigned int) (((u32) ((u32) (&data_ov000_021b2f94)))));
        *(u32 *) (iVar1 + ((int) 0x00000448u)) = 0;
    }
    if (0 < *(int *) (iVar1 + ((int) 0x00000458u))) {
        func_ov000_02190b80((unsigned int) ((u32) (u32) (param_1)), (unsigned int) (param_2),
                            (unsigned int) (((u32) ((u32) (&data_ov000_021b319c)))));
        func_ov000_02190b58(param_1, param_2, *(u32 *) (iVar1 + ((int) 0x00000198u)));
        func_ov000_02190b80((unsigned int) ((u32) (u32) (param_1)), (unsigned int) (param_2),
                            (unsigned int) (*(u32 *) (iVar1 + ((int) 0x00000450u))));
        func_ov000_02190b80((unsigned int) ((u32) (u32) (param_1)), (unsigned int) (param_2),
                            (unsigned int) (((u32) ((u32) (&data_ov000_021b2f94)))));
        *(u32 *) (iVar1 + ((int) 0x00000458u)) = 0;
    }
    return 0;
}
