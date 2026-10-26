#include "code_0214a390.h"

// non-matching: 8 words differ; the two shifts left by 12 in each half write r5/r4 in place, the ROM writes ip/lr
void func_0214a428(u32 *param_1, const s32 *param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6) {
    s32 a;
    s32 b;
    s32 c;
    s32 d;

    a = param_2[0];
    b = param_2[1];
    c = a << 12;
    d = b << 12;
    a = c >> 16;
    b = d >> 16;
    c = (u16) a;
    d = (u16) b;
    param_1[0] = c | (d << 16);
    a = param_2[2];
    b = param_2[3];
    c = a << 12;
    d = b << 12;
    a = c >> 16;
    b = d >> 16;
    c = (u16) a;
    d = (u16) b;
    param_1[1] = c | (d << 16);
    a = param_2[0] * (param_5 - param_3) + param_2[1] * (param_6 - param_4) + (param_3 << 12);
    b = param_2[2] * (param_5 - param_3) + param_2[3] * (param_6 - param_4) + (param_4 << 12);
    param_1[2] = a >> 4;
    param_1[3] = b >> 4;
}

void func_0214a40c(u32 *param_1, u32 param_2, int param_3, u32 param_4, int param_5) {
    *param_1 = (param_2 | 0x40 | (param_3 << 8)) | ((param_4 | (param_5 << 8)) << 16);
}

void func_0214a3e8(u16 *param_1, u32 param_2, s32 param_3) {
    if (param_3 < 0) {
        param_1[0] = param_2 | 0xc0;
        param_1[2] = -param_3;
    } else {
        param_1[0] = param_2 | 0x80;
        param_1[2] = param_3;
    }
}

void func_0214a390(u16 *param_1, u32 param_2, u32 param_3, u32 param_4, u32 param_5, s32 param_6) {
    param_1[1] = param_4 | (param_5 << 8);
    if (param_6 < 0) {
        param_1[0] = param_2 | 0xc0 | (param_3 << 8);
        param_1[2] = -param_6;
    } else {
        param_1[0] = param_2 | 0x80 | (param_3 << 8);
        param_1[2] = param_6;
    }
}
