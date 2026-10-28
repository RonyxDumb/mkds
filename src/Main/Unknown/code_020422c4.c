#include "Main/Unknown/code_020422c4.h"

#pragma thumb on

void func_02042320(void) {
    u16 count;
    u16 i;
    count = 0;
    for (i = 0; i < data_02175620->mUnk_78; i++) {
        if (func_020423fc(i)->mUnk_44 == 4) {
            count++;
        }
    }
    data_02175620->mUnk_102 = count;
}

void func_020422c4(void) {
    u8 count;
    u16 i;
    count = 0;
    if (data_021759c0->mUnk_08 == 4) {
        for (i = 0; i < data_02175620->mUnk_78; i++) {
            if (func_020423fc(i)->mUnk_44 == 2) {
                count++;
            }
        }
    }
    data_02175620->mUnk_10f = count;
}

#pragma thumb off
