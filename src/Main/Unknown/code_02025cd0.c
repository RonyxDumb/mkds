#include "Main/Unknown/code_02025cd0.h"

#pragma thumb on

void func_02025cd0(short *a, u32 b, u32 c, u32 d) {
    a[0] = (b / 10) % 10 + '0';
    a[1] = b % 10 + '0';
    a[2] = ':';
    a[3] = (c / 10) % 10 + '0';
    a[4] = c % 10 + '0';
    a[5] = ':';
    a[6] = (d / 100) % 10 + '0';
    a[7] = (d / 10) % 10 + '0';
    a[8] = d % 10 + '0';
    a[9] = 0;
}

#pragma thumb off
