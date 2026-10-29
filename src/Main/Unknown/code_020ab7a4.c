#include "Main/Unknown/code_020ab7a4.h"

#pragma thumb on

void func_020ab7a4(const u16 *a) {
    s32 i;

    for (i = 0; i < data_0217b334->mUnk_44; i++) {
        data_0217b334->mUnk_40[i] = 0;
    }
    for (i = 0; i < data_0217b334->mUnk_4a; i++) {
        data_0217b334->mUnk_40[i] = *a;
        if (*a == 0) {
            data_0217b334->mUnk_46 = i;
            data_0217b334->mUnk_48 = data_0217b334->mUnk_46;
            return;
        }
        a++;
    }
    data_0217b334->mUnk_46 = data_0217b334->mUnk_4a - 1;
    data_0217b334->mUnk_48 = data_0217b334->mUnk_46;
    data_0217b334->mUnk_40[data_0217b334->mUnk_4a] = 0;
}

#pragma thumb off
