#include "00/code_02196914.h"

void func_ov000_02196914(int param_1, int param_2, int param_3) {
    if (param_1 == 0) {
        func_0213442c((u32) (((u32) ((u32) (&data_ov000_021b3b10)))), (u32) (((u32) ((u32) (&data_ov000_021b3a1c)))),
                      (u32) (0), (u32) (0x2f));
    }
    if (param_2 == 0) {
        func_0213442c((u32) (((u32) ((u32) (&data_ov000_021b3b20)))), (u32) (((u32) ((u32) (&data_ov000_021b3a1c)))),
                      (u32) (0), (u32) (0x30));
    }
    func_0213a228((u8 *) ((u32 *) (u32) (param_1)), (const u8 *) (param_2), (int) (param_3));
    *(u8 *) (param_1 + param_3 + -1) = 0;
    return;
}
