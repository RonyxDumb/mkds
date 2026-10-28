#include "01/code_0219a77c.h"
#include "01/code_0219a950.h"
#include "01/code_0219ae30.h"
#include "01/unk_021a6000.h"
#include "01/code_02195a6c.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "01/code_0219c000.h"

void func_ov001_0219a80c(void) {
    s16 a;
    s32 i;
    s32 j;
    s16 b;
    u16 *p;
    s32 idx;

    data_ov001_021a9bf0->mUnk_38++;
    a = func_020ae4c0(1, 0xe0, 0, data_ov001_021a9bf0->mUnk_38, 10);
    b = func_020ae4c0(1, -0xc0, 0, data_ov001_021a9bf0->mUnk_38, 10);
    data_ov001_021a9bf0->mUnk_3c = b;
    idx = data_ov001_021a9bf0->mUnk_04->mUnk_06;
    data_ov001_021a9bf0->mUnk_18[0].mUnk_06 = b;
    data_ov001_021a9bf0->mUnk_18[1].mUnk_06 = b;
    data_ov001_021a9bf0->mUnk_18[idx].mUnk_06 = b;
    for (i = 0; i < 3; i++) {
        data_ov001_021a9bf0->mUnk_18[data_ov001_021a6aac[i]].mUnk_06 = b;
    }
    for (i = 0; i < 3; i++) {
        for (j = 0, p = data_ov001_021a6ae4[i]; j < 3; j++) {
            data_ov001_021a9bf0->mUnk_18[idx + *p].mUnk_06 = b;
            p++;
        }
    }
    for (i = 0; i < 3; i++) {
        data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6ab4[i]].mUnk_04 = a;
        data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6ac4[i]].mUnk_04 = a;
        data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6a9c[i]].mUnk_04 = a;
        data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6aa4[i]].mUnk_04 = a;
    }
    if (data_ov001_021a9bf0->mUnk_38 >= 10) {
        func_ov001_0219ae60();
    }
}

void func_ov001_0219a77c(void) {
    s16 v;
    s32 i;

    data_ov001_021a9bf0->mUnk_38++;
    v = func_020ae488(data_ov001_021a9bf0->mUnk_38);
    for (i = 0; i < 3; i++) {
        data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6ab4[i]].mUnk_04 = v;
        data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6ac4[i]].mUnk_04 = v;
        data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6a9c[i]].mUnk_04 = v;
        data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6aa4[i]].mUnk_04 = v;
    }
    if (data_ov001_021a9bf0->mUnk_38 >= 10) {
        func_ov001_0219ae44();
    }
}
