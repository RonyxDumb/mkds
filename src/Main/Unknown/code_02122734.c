#include "Main/Unknown/code_02122734.h"

s32 func_02122778(s32 param_1) {
    return data_0217d384->mUnk_1f4e[param_1];
}

s32 func_02122734(s32 param_1) {
    s8 i;
    for (i = 0; i < 4; i++) {
        if (param_1 == data_0217d384->mUnk_1f4e[i]) {
            return i;
        }
    }
    return -1;
}
