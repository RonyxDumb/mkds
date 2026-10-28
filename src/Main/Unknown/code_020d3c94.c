#include "Main/Unknown/code_020d3c94.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_020d2c2c.h"
#include "Main/Unknown/code_020e6fd4.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020d94dc.h"
#include "Main/Unknown/code_020d2000.h"

s32 func_020d3d48(s32 param_1) {
    if (data_0217b4e4 != 0 && data_0217b4e4->mUnk_170 != 0) {
        return param_1 - data_0217b4e4->mUnk_04;
    }
    return data_0217b4d8 != 0 ? param_1 - data_0217b4d8->mUnk_00 : 0x270f000;
}

s32 func_020d3d10(s32 param_1) {
    s32 a;
    a = 0;
    if (data_0217b4d8 != 0) {
        if (param_1 - data_0217b4d8->mUnk_00 < -0x32000) {
            a = 1;
        }
    }
    return a;
}

void func_020d3cc8(void) {
    s32 i;
    s32 n;
    Unk0217b4f0 *q;
    Unk020e6fd4 **p;
    i = 0;
    q = data_0217b4f0;
    n = q->mUnk_174;
    p = q->mUnk_134;
    for (; i < n; i++) {
        func_020e6fd4(p[i]);
    }
}

s32 func_020d3c94(Unk020e71a0 *param_1, s32 param_2, Vec3 *param_3) {
    return func_020d2c2c(&param_1->mUnk_04, &param_1->mUnk_10, param_1->mUnk_58.x, param_1->mUnk_64, param_2, param_3);
}
