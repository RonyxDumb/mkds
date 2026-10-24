#include "Main/Unknown/code_020e4934.h"

u8 func_020e4934(int param_1, u32 param_2, u8 *param_3, u8 *param_4) {
    if (*param_3 == '\x01') {
        func_020ec6e4();
        *(u16 *) (param_1 + 0x90) = 1;
        *(u16 *) (param_1 + 0x92) = 1;
        *(u16 *) (param_1 + 2) = *(u16 *) (param_1 + 2) | *((u16 *) ((u32) (&data_02158fe4)));
        func_020d26f8((int) (param_1), (int) (param_2));
    }
    return *param_4;
}
