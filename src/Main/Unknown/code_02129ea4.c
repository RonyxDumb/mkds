#include "Main/Unknown/code_02129ea4.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_020ab848.h"

#pragma thumb on
void func_02129ea4(void) {
    u16 e[2];
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 i;
    s32 j;
    s32 k;
    s32 m;
    s16 v;
    s16 w;
    for (i = 0; i < 2; i++) {
        e[i] = data_0217d400->mUnk_9c[i]->mUnk_06;
        for (j = 0; j < 2; j++) {
            v = -500;
            if (i == 1 || data_0217d400->mUnk_2c[2].mUnk_14 == 0xc) {
                v = data_0217d400->mUnk_86[i][j];
            }
            for (k = 0; k < data_0215d0d8[i]; k++) {
                data_0217d400->mUnk_74[i][j][data_0215d0dc[i][k]].mUnk_06 = v;
            }
            for (k = 0; k < data_0215d0e0[i]; k++) {
                data_0217d400->mUnk_74[i][j][data_0215d14c[i][k]].mUnk_06 = v;
                (data_0217d400->mUnk_74[i][j] + e[i])[data_0215d134[i][k]].mUnk_06 = v;
            }
            v = data_0217d400->mUnk_84;
            for (m = 0; m < 2; m++) {
                for (k = 0; k < 3; k++) {
                    data_0217d400->mUnk_74[i][j][data_0215d128[i][m][k]].mUnk_06 = v;
                }
                (data_0217d400->mUnk_74[i][j] + e[i])[data_0215d0e4[i][m]].mUnk_06 = v;
            }
            w = data_0217d400->mUnk_84;
            func_020ab848(&a, &b, &c, &d);
            data_0217d400->mUnk_74[i][j][data_0215d0f8[i][0]].mUnk_0c = a;
            data_0217d400->mUnk_74[i][j][data_0215d0f8[i][0]].mUnk_0e = w + b + 0x28;
            data_0217d400->mUnk_74[i][j][data_0215d0f8[i][1]].mUnk_0c = a;
            data_0217d400->mUnk_74[i][j][data_0215d0f8[i][1]].mUnk_0e = w + d + 0x28;
            data_0217d400->mUnk_74[i][j][data_0215d0f8[i][2]].mUnk_0c = c;
            data_0217d400->mUnk_74[i][j][data_0215d0f8[i][2]].mUnk_0e = w + b + 0x28;
            data_0217d400->mUnk_74[i][j][data_0215d0f8[i][3]].mUnk_0c = c;
            data_0217d400->mUnk_74[i][j][data_0215d0f8[i][3]].mUnk_0e = w + d + 0x28;
        }
    }
    for (i = 0; i < 2; i++) {
        v = -500;
        if (data_0217d400->mUnk_04 == 1 && i == 1) {
            v = data_0217d400->mUnk_84;
        }
        for (k = 0; k < 10; k++) {
            data_0217d400->mUnk_74[1][i][data_0215d110[k]].mUnk_06 = v;
        }
        v = -500;
        if (data_0217d400->mUnk_04 == 1) {
            v = data_0217d400->mUnk_86[1][i];
        }
        for (k = 0; k < 6; k++) {
            data_0217d400->mUnk_74[1][i][data_0215d0f0[k]].mUnk_06 = v;
        }
    }
}
#pragma thumb off
