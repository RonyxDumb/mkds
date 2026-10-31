#include "Main/Unknown/code_020ab660.h"

#pragma thumb on

void func_020ab660(u16 a, volatile Unk0214e334_b b) {
    u32 t;
    u16 v;

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
        if (b.mUnk_06 != 0) {
            b.mUnk_00 = data_0217b2d8.mUnk_0c[0];
            b.mUnk_02 = data_0217b2d8.mUnk_0c[1];
            b.mUnk_04 = data_0217b2d8.mUnk_0c[2];
            b.mUnk_06 = data_0217b2d8.mUnk_0c[3];
            b.mUnk_04 = 0;
        }
        v = b.mUnk_04;
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
            data_0217b2d8.mUnk_14 = b.mUnk_00;
            data_0217b2d8.mUnk_16 = b.mUnk_02;
        }
        data_0217b2d8.mUnk_20 = v;
        data_0217b2d8.mUnk_0c[0] = b.mUnk_00;
        data_0217b2d8.mUnk_0c[1] = b.mUnk_02;
        data_0217b2d8.mUnk_0c[2] = b.mUnk_04;
        data_0217b2d8.mUnk_0c[3] = b.mUnk_06;
    }
}

#pragma thumb off
