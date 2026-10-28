#include "Main/Unknown/code_0205950c.h"

#pragma thumb on

void func_0205950c(void *param_1, void *param_2) {
    Unk0217aa00_1608 *part;
    data_0217aa00->mUnk_1e34 = 0;
    data_0217aa00->mUnk_1e44 &= ~2;
    part = &data_0217aa00->mUnk_1608;
    part->mUnk_10 = 0x10;
    part->mUnk_12 = 1;
    data_0217aa00->mUnk_1650 = param_1;
    data_0217aa00->mUnk_1654 = param_2;
}

#pragma thumb off
