#include "01/code_0219f3a4.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_02105000.h"

void func_ov001_0219f4f8(void) {
    s32 i;
    u16 cnt;
    s32 r;
    cnt = data_ov001_021ca410->mUnk_04->mUnk_06;
    for (i = 0; i < 7; i++) {
        data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][0]].mUnk_00 = 0;
        data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][1]].mUnk_00 = 0;
        data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][2]].mUnk_00 = 0;
        data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][3]].mUnk_00 = 0;
        data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][4]].mUnk_00 = 0;
        data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][5]].mUnk_00 = 0;
        data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][6]].mUnk_00 = 0;
        data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][7]].mUnk_00 = 0;
        data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][8]].mUnk_00 = 0;
        data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][9]].mUnk_00 = 0;
        data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][10]].mUnk_00 = 0;
        data_ov001_021ca410->mUnk_10[cnt + data_ov001_021a6c60[i]].mUnk_00 = 0;
        if (func_ov001_0219f688((s16) i)) {
            data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][0]].mUnk_00 = 1;
            data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][1]].mUnk_00 = 1;
            data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][5]].mUnk_00 = 1;
            r = func_ov001_0219f6a0((s16) i);
            if (r <= 4) {
                data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][7]].mUnk_00 = 1;
                data_ov001_021ca410->mUnk_10[cnt + data_ov001_021a6c60[i]].mUnk_00 = 1;
                func_0212426c(1, data_ov001_021a6c60[i], data_ov001_021ca410->mUnk_0c, data_ov001_021a90e8[r],
                              data_ov001_021ca410->mUnk_04, data_ov001_021ca410->mUnk_10);
            } else if (r <= 7) {
                data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][r + 3]].mUnk_00 = 1;
            }
        } else if (i != 6) {
            data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][0]].mUnk_00 = 1;
            data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][4]].mUnk_00 = 1;
            data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][6]].mUnk_00 = 1;
        }
        func_02124a98(data_ov001_021a6ce0[i][0], 1, data_ov001_021ca410->mUnk_00, data_ov001_021ca410->mUnk_04);
    }
}

void func_ov001_0219f430(void) {
    s32 i;
    for (i = 0; i < 7; i++) {
        data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][1]].mUnk_00 = 0;
        data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][2]].mUnk_00 = 0;
        data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][3]].mUnk_00 = 0;
        data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][4]].mUnk_00 = 0;
        if (data_ov001_021ca410->mUnk_28[i] > 0) {
            data_ov001_021ca410->mUnk_28[i] = data_ov001_021ca410->mUnk_28[i] - 1;
            data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][3]].mUnk_00 = 1;
            data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][3]].mUnk_06 =
                data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][2]].mUnk_06 + 1;
        } else if (data_ov001_021ca410->mUnk_4c == i) {
            data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][2]].mUnk_00 = 1;
        } else if (func_ov001_0219f688((s16) i)) {
            data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][1]].mUnk_00 = 1;
        } else if (i != 6) {
            data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][4]].mUnk_00 = 1;
        }
    }
}

void func_ov001_0219f3a4(void) {
    s32 all = 1;
    s32 i = 0;
    s32 ok;
    s32 j;
    s32 out;
    u8 x;
    data_ov001_021ca410->mUnk_4a = 0;
    for (i = 0; i < 7; i++) {
        ok = 1;
        j = 0;
        x = i + 1;
        for (; j < 9; j++) {
            ok &= func_0205fd78(x, (u8) (j + 1), &out);
            if (!ok || out < 5) {
                all = 0;
            }
        }
        if (ok) {
            if (i == 5) {
                if (all) {
                    data_ov001_021ca410->mUnk_4a = i + 1;
                }
            } else {
                data_ov001_021ca410->mUnk_4a = i + 1;
            }
        }
    }
}
