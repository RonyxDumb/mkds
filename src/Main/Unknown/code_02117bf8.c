#include "Main/Unknown/code_02117bf8.h"
#include "Main/Unknown/code_02118000.h"
#include "Main/Unknown/code_02118148.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/unk_0217d000.h"

#pragma thumb on

void func_02117bf8(void) {
    u16 v;
    s16 a;
    s16 b;
    s16 c;
    int i;
    int j;

    data_0217d360->mUnk_38 = data_0217d360->mUnk_38 + 1;
    if (*(vu16 *) 0x027ffc40 != 2) {
        v = data_0217d360->mUnk_04->mUnk_06;
        a = func_020ae4c0(1, 0xe0, 0, data_0217d360->mUnk_38, 0xa);
        b = func_020ae4c0(1, -192, 0, data_0217d360->mUnk_38, 0xa);
        if (func_020cccb4() != 0x18 && func_020cccb4() != 0xc) {
            data_0217d360->mUnk_40 = b;
            data_0217d360->mUnk_18[19].mUnk_06 = b;
            data_0217d360->mUnk_18[2].mUnk_06 = b;
            data_0217d360->mUnk_18[1].mUnk_06 = b;
            data_0217d360->mUnk_18[0].mUnk_06 = b;
            for (i = 0; i < 8; i++) {
                data_0217d360->mUnk_18[data_0215c83c[i]].mUnk_06 = b;
            }
            for (i = 0; i < 4; i++) {
                data_0217d360->mUnk_18[data_0215c7c8[i]].mUnk_06 = b;
            }
            for (i = 0; i < 4; i++) {
                data_0217d360->mUnk_18[data_0215c7d0[i]].mUnk_06 = b;
                data_0217d360->mUnk_18[v + data_0215c7d8[i]].mUnk_06 = b;
            }
        }
        data_0217d360->mUnk_18[20].mUnk_06 = b;
        c = -a;
        data_0217d360->mUnk_1c[0].mUnk_04 = c;
        data_0217d360->mUnk_1c[1].mUnk_04 = a;
        data_0217d360->mUnk_1c[2].mUnk_04 = c;
        data_0217d360->mUnk_1c[3].mUnk_04 = a;
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 6; j++) {
                data_0217d360->mUnk_1c[data_0215c9bc[i][j]].mUnk_04 = -a;
            }
        }
        for (i = 4; i < 8; i++) {
            for (j = 0; j < 6; j++) {
                data_0217d360->mUnk_1c[data_0215c9bc[i][j]].mUnk_04 = a;
            }
        }
    }
    if (data_0217d360->mUnk_38 >= 0xa) {
        func_021181cc();
    }
}

#pragma thumb off
