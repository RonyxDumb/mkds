#include "01/code_021a1674.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_02105000.h"

// non-matching: same instructions; the stack slots of the loop counter k and of the table pointer are swapped
// (original: pointer at sp+4, k at sp+0xc).
void func_ov001_021a16e4(void) {
    s16 a;
    s16 b;
    s32 k;
    s32 j;
    s32 i;
    s32 nb;
    data_ov001_021ca418->mUnk_2c = data_ov001_021ca418->mUnk_2c + 1;
    a = func_020ae4c0(1, 0xe0, 0, data_ov001_021ca418->mUnk_2c, 10);
    b = func_020ae4c0(1, -0xc0, 0, data_ov001_021ca418->mUnk_2c, 10);
    nb = -b;
    data_ov001_021ca418->mUnk_30 = nb;
    for (i = 0; i < 6; i++) {
        data_ov001_021ca418->mUnk_14[data_ov001_021a6f68[i]].mUnk_06 = nb;
    }
    data_ov001_021ca418->mUnk_14[6].mUnk_06 = b;
    for (k = 0; k < 4; k++) {
        data_ov001_021ca418->mUnk_14[data_ov001_021a6f28[k]].mUnk_06 = nb;
        if (func_02056dec(0x10)) {
            switch (k) {
            case 0:
            case 2:
                for (j = 0; j < 3; j++) {
                    data_ov001_021ca418->mUnk_18[data_ov001_021a6fa0[k][j]].mUnk_04 = -a;
                }
                break;
            case 1:
            case 3:
                for (j = 0; j < 3; j++) {
                    data_ov001_021ca418->mUnk_18[data_ov001_021a6fa0[k][j]].mUnk_04 = a;
                }
                break;
            }
        } else {
            for (j = 0; j < 3; j++) {
                data_ov001_021ca418->mUnk_18[data_ov001_021a6fa0[k][j]].mUnk_04 = a;
            }
        }
    }
    if (data_ov001_021ca418->mUnk_2c >= 10) {
        func_ov001_021a19dc();
    }
}

void func_ov001_021a1674(void) {
    s16 x;
    s32 j;
    data_ov001_021ca418->mUnk_2c = data_ov001_021ca418->mUnk_2c + 1;
    x = func_020ae488(data_ov001_021ca418->mUnk_2c);
    data_ov001_021ca418->mUnk_30 = x;
    for (j = 0; j < 6; j++) {
        data_ov001_021ca418->mUnk_14[data_ov001_021a6f68[j]].mUnk_06 = x;
    }
    for (j = 0; j < 4; j++) {
        data_ov001_021ca418->mUnk_14[data_ov001_021a6f28[j]].mUnk_06 = x;
    }
    if (data_ov001_021ca418->mUnk_2c >= 10) {
        func_ov001_021a19c0();
    }
}
