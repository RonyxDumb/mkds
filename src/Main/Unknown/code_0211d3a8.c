#include "Main/Unknown/code_0211d3a8.h"

#pragma thumb on

u32 func_0211d3a8(void) {
    u32 a;
    u32 b;
    if (data_0217d368->mUnk_68[1] != 0) {
        a = func_0211d478(0);
        b = func_0211d478(1);
        if (a > b) {
            return 0;
        }
        a = func_0211d478(0);
        b = func_0211d478(1);
        if (a < b) {
            return 1;
        }
    }
    return 2;
}

#pragma thumb off
