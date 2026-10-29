#include "Main/Unknown/code_02009974.h"

#pragma thumb on

u8 func_02009974(void) {
    Unk0216fda8 *v1;
    u32 v2;
    u32 v3;
    u32 v4;
    u32 v5;
    v1 = *(Unk0216fda8 **) &data_0216fda8;
    if (v1->mUnk_012 != 0) {
        v2 = 2;
    } else {
        v2 = 0;
    }
    if (v1->mUnk_00e != 0) {
        v3 = 1;
    } else {
        v3 = 0;
    }
    if (v1->mUnk_014 != 0) {
        v4 = 4;
    } else {
        v4 = 0;
    }
    if (v1->mUnk_016 != 0) {
        v5 = 8;
    } else {
        v5 = 0;
    }
    return v5 | (v4 | (v3 | v2));
}

#pragma thumb off
