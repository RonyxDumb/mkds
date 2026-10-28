#include "Main/Unknown/code_02125ee8.h"

#pragma thumb on

void func_02125ee8(int a, int b) {
    if (a < -0x96) {
        a = -0x96;
    }
    if (a > 0x96) {
        a = 0x96;
    }
    if (b < -0x96) {
        b = -0x96;
    }
    if (b > 0x96) {
        b = 0x96;
    }
    data_0217d3f0->mUnk_2064[0] = a;
    data_0217d3f0->mUnk_2064[1] = b;
}

#pragma thumb off
