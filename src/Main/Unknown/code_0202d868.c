#include "Main/Unknown/code_0202d868.h"

#pragma thumb on

void func_0202d868(s32 a, s32 b, s32 c, s32 d) {
    Unk0202de00_g t;
    u16 s[10];
    Unk02174e14_00 *p;
    s32 i;
    s32 j;
    s32 k;
    p = &data_02174e40->mUnk_050[1];
    if (a == 1) {
        func_0212426c(1, b, p->mUnk_14, func_020b3f7c(data_02174e40->mUnk_0ac, func_02025d74(func_0202db04(c))),
                      p->mUnk_0c, p->mUnk_18);
        func_0202dcf4(c, &t);
        func_02025cd0((short *) s, t.mUnk_02, t.mUnk_03, t.mUnk_00);
        func_02124224(1, b + 7, p->mUnk_14, s, p->mUnk_0c, p->mUnk_18, 7);
        j = func_0202dd80(c) == 0;
        p->mUnk_18[b].mUnk_00 = j;
        k = j == 0;
        p->mUnk_18[b + 7].mUnk_00 = k;
    } else if (a == 0) {
        for (i = 0; i < 7; i++) {
            j = i + 7;
            if (i == d) {
                k = 0xe;
            } else {
                k = 0xf;
            }
            func_02124100(i, k, p->mUnk_14, p->mUnk_18, p->mUnk_0c);
            func_02124100(j, k, p->mUnk_14, p->mUnk_18, p->mUnk_0c);
        }
    } else if (a == 2) {
        if (c >= 0 && c < (s32) func_0202ddc4()) {
            j = func_0202dd80(c) == 0;
            p->mUnk_18[b].mUnk_00 = j;
            k = j == 0;
            p->mUnk_18[b + 7].mUnk_00 = k;
        }
    }
}

#pragma thumb off
