#include "Main/Unknown/code_0205c7a0.h"

void func_0205c7a0(u32 param_1) {
    u8 index;
    if (param_1 == 0xffffffff) {
        return;
    }
    index = param_1;
    if (data_0217aa14->mUnk_749 & (1 << index)) {
        if (func_0205c340(index, 1, 8) != 0) {
            data_0217aa14->mUnk_0f8 = index;
        }
    }
}
