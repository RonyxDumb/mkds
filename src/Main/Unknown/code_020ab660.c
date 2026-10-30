#include "Main/Unknown/code_020ab660.h"

#pragma thumb on

// non-matching: the original reads the second argument in place from the argument area (add r0, sp, #0 with offsets
// 4 to 10) and keeps the data pointer in r1; here the copy lives at sp+4 with a second base register.
void func_020ab660(u16 a, Unk0214e334_b b) {
    u32 t;
    u16 v;
    volatile Unk0214e334_b *p;

    t = a ^ data_0217b2d8.mUnk_06;
    data_0217b2d8.mUnk_04 = a & t;
    data_0217b2d8.mUnk_08 = ~a & t;
    data_0217b2d8.mUnk_06 = a;
    if ((data_0217b2d8.mUnk_06 & data_0217b2d8.mUnk_0a) != 0) {
        data_0217b2d8.mUnk_00++;
    } else {
        data_0217b2d8.mUnk_00 = 0;
    }
    if (data_0217b2d8.mUnk_24 != 0) {
        p = &b;
        if (p->mUnk_06 != 0) {
            p->mUnk_00 = data_0217b2d8.mUnk_0c[0];
            p->mUnk_02 = data_0217b2d8.mUnk_0c[1];
            p->mUnk_04 = data_0217b2d8.mUnk_0c[2];
            p->mUnk_06 = data_0217b2d8.mUnk_0c[3];
            p->mUnk_04 = 0;
        }
        v = p->mUnk_04;
        if (v != data_0217b2d8.mUnk_0c[2]) {
            data_0217b2d8.mUnk_1c = v != 0 ? 1 : 3;
            data_0217b2d8.mUnk_18 = 0;
        } else if (v != 0) {
            data_0217b2d8.mUnk_1c = 2;
            data_0217b2d8.mUnk_18++;
        } else {
            data_0217b2d8.mUnk_1c = 0;
        }
        if (v != 0) {
            data_0217b2d8.mUnk_14 = p->mUnk_00;
            data_0217b2d8.mUnk_16 = p->mUnk_02;
        }
        data_0217b2d8.mUnk_20 = v;
        data_0217b2d8.mUnk_0c[0] = p->mUnk_00;
        data_0217b2d8.mUnk_0c[1] = p->mUnk_02;
        data_0217b2d8.mUnk_0c[2] = p->mUnk_04;
        data_0217b2d8.mUnk_0c[3] = p->mUnk_06;
    }
}

#pragma thumb off
