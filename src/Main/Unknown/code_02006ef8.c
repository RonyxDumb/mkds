#include "Main/Unknown/code_02006ef8.h"

#pragma thumb on

int func_02006ef8(void) {
    int v1;
    Unk02007014 *v2;
    v1 = 0;
    for (v2 = func_02007040(); v2 != 0; v2 = v2->mUnk_28) {
        v1 = v1 + 1;
    }
    return v1;
}

#pragma thumb off
