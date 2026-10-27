#include "Main/Unknown/code_021128cc.h"

#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_02112b48.h"
#include "Main/Unknown/code_021137a8.h"
#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/unk_0217d000.h"

#pragma thumb on

void func_02112a0c(void) {
    u16 b;
    u16 a;
    s32 i;
    s32 j;
    s16 v;
    data_0217d348->mUnk_54 = data_0217d348->mUnk_54 + 1;
    v = func_020ae4c0(1, -192, 0, data_0217d348->mUnk_54, 10);
    data_0217d348->mUnk_5c = v;
    data_0217d348->mUnk_64 = v;
    a = data_0217d348->mUnk_08->mUnk_06;
    data_0217d348->mUnk_14[0].mUnk_06 = v;
    data_0217d348->mUnk_14[1].mUnk_06 = v;
    data_0217d348->mUnk_14[2].mUnk_06 = v;
    data_0217d348->mUnk_14[3].mUnk_06 = v;
    data_0217d348->mUnk_14[a].mUnk_06 = v;
    data_0217d348->mUnk_14[a + 1].mUnk_06 = v;
    data_0217d348->mUnk_14[a + 11].mUnk_06 = v;
    data_0217d348->mUnk_14[a + 12].mUnk_06 = v;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            data_0217d348->mUnk_14[a + data_0215c410[i][j]].mUnk_06 = v;
        }
    }
    b = data_0217d348->mUnk_18->mUnk_06;
    data_0217d348->mUnk_24[1].mUnk_06 = v;
    data_0217d348->mUnk_24[0].mUnk_06 = v;
    data_0217d348->mUnk_24[b].mUnk_06 = v;
    data_0217d348->mUnk_24[b + 1].mUnk_06 = v;
    data_0217d348->mUnk_24[b + 14].mUnk_06 = v;
    for (j = 0; j < 12; j++) {
        data_0217d348->mUnk_24[b + data_0215c478[j]].mUnk_06 = v;
    }
    if (data_0217d348->mUnk_54 >= 10) {
        func_0211349c();
    }
}

void func_021128cc(void) {
    s16 v;
    s32 i;
    u16 x;
    func_021137f4();
    data_0217d348->mUnk_54 = data_0217d348->mUnk_54 + 1;
    v = func_020ae4c0(1, 0x100, 0, data_0217d348->mUnk_54, 10);
    x = data_0217d348->mUnk_30->mUnk_06;
    data_0217d348->mUnk_3c[20].mUnk_04 = v;
    data_0217d348->mUnk_3c[21].mUnk_04 = v;
    data_0217d348->mUnk_3c[24].mUnk_04 = v;
    data_0217d348->mUnk_3c[25].mUnk_04 = v;
    data_0217d348->mUnk_3c[26].mUnk_04 = v;
    data_0217d348->mUnk_3c[x + 5].mUnk_04 = v;
    for (i = 0; i < 5; i++) {
        data_0217d348->mUnk_3c[data_0215c3e0[i]].mUnk_04 = v;
        data_0217d348->mUnk_3c[data_0215c3ec[i]].mUnk_04 = v;
        data_0217d348->mUnk_3c[data_0215c3f8[i]].mUnk_04 = v;
        data_0217d348->mUnk_3c[data_0215c404[i]].mUnk_04 = v;
        data_0217d348->mUnk_3c[x + data_0215c3bc[i]].mUnk_04 = v;
    }
    if (data_0217d348->mUnk_54 >= 10) {
        func_02113480();
    }
    if (data_0217d348->mUnk_54 == 4) {
        data_0217d348->mUnk_3c[24].mUnk_00 = 1;
        data_0217d348->mUnk_3c[25].mUnk_00 = 0;
    }
}

#pragma thumb off
