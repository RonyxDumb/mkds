#include "00/code_021a3f78.h"

void func_ov000_021a3f78(u32 param_1, u8 *param_2) {
    *(u32 *) (param_2 + ((int) 0x00000800u)) = 1;
    *param_2 = 0x5c;
    func_ov000_021a3fc8((int) (param_1), (int) ((int) (u32) (param_2)), (int) (0));
    func_ov000_021a3fc8((int) (param_1), (int) ((int) (u32) (param_2)), (int) (1));
    func_ov000_021a3fc8((int) (param_1), (int) ((int) (u32) (param_2)), (int) (2));
    func_ov000_021a471c((int) ((int) (u32) (param_2)), (u32) &data_ov000_021b43e4);
    *(int *) (param_2 + ((int) 0x00000800u)) = *(int *) (param_2 + ((int) 0x00000800u)) + -1;
    return;
}
