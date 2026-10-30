#include "Main/Unknown/code_0212775c.h"

#pragma thumb on

s32 func_02127794(void) {
    if ((int) data_0217d3f4->mUnk_20 != 0) {
        return 0xffffffff;
    }
    return data_0217d3f4->mUnk_18;
}

unsigned int func_02127788(void) {
    return ((unsigned int) *(
        const unsigned int *) ((unsigned char *) (unsigned int) (((unsigned int) *(
                                   const unsigned int *) ((unsigned char *) (unsigned int) (((u32) (&data_0217d3f4))) +
                                                          0))) +
                               28));
}

void func_0212775c(int param_1, u32 param_2) {
    if (param_1 == -1) {
        *(u32 *) ((*(int *) &data_0217d3f4) + ((int) 0x000008b0u)) = param_2;
        return;
    }
    *(u32 *) ((*(int *) &data_0217d3f4) + param_1 * 4 + ((int) 0x000008a8u)) = param_2;
    return;
}

#pragma thumb off
