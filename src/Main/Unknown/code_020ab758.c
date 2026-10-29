#include "Main/Unknown/code_020ab758.h"

#pragma thumb on

void func_020ab758(u16 a) {
    data_0217b334->mUnk_4a = a;
    if (data_0217b334->mUnk_46 >= data_0217b334->mUnk_4a - 1) {
        data_0217b334->mUnk_46 = data_0217b334->mUnk_4a - 1;
        data_0217b334->mUnk_48 = data_0217b334->mUnk_46;
        data_0217b334->mUnk_40[data_0217b334->mUnk_4a] = 0;
    }
}

#pragma thumb off
