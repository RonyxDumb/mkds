#include "Main/Unknown/code_02007014.h"
#include "Main/Unknown/code_02007034.h"

#pragma thumb on

Unk02007014 *func_02007014(u32 a) {
    Unk02007014 *v1;
    for (v1 = func_02007040(); v1 != 0; v1 = v1->mUnk_28) {
        if (v1->mUnk_00 == a) {
            return v1;
        }
    }
    return 0;
}

#pragma thumb off
