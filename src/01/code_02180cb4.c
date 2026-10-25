#include "01/code_02180cb4.h"

#pragma optimize_for_size on

void func_ov001_02180ccc(u16 *p0) {
    s32 i;

    for (i = 0; i < 0x3000; i++) {
        p0[i] = 0;
    }
}

void func_ov001_02180cb4(u16 *p0) {
    u16 i;

    for (i = 0; i < 0x300; i++) {
        p0[i] = i;
    }
}
