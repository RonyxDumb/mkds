#include "01/code_0219a77c.h"
#include "01/code_0219a950.h"
#include "01/code_0219ae30.h"
#include "01/unk_021a6000.h"
#include "01/code_02195a6c.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "01/code_0219c000.h"

// non-matching: same instructions; the value read from mUnk_04[3] is in r2 (original r1), the object pointer temp is in r1 (original r2), and the stack slots of the outer counter and the row pointer in the nested loop are swapped (sp+4/sp+12)
void func_ov001_0219a80c(void) {
    s16 a;
    s32 i;
    s32 j;
    s32 k;
    s16 b;
    s32 idx;
    s32 m;

    data_ov001_021a9bf0->mUnk_38++;
    a = func_020ae4c0(1, 0xe0, 0, data_ov001_021a9bf0->mUnk_38, 10);
    b = func_020ae4c0(1, -0xc0, 0, data_ov001_021a9bf0->mUnk_38, 10);
    data_ov001_021a9bf0->mUnk_3c = b;
    idx = data_ov001_021a9bf0->mUnk_04[3];
    data_ov001_021a9bf0->mUnk_18[0].mUnk_06 = b;
    data_ov001_021a9bf0->mUnk_18[1].mUnk_06 = b;
    data_ov001_021a9bf0->mUnk_18[idx].mUnk_06 = b;
    for (i = 0; i < 3; i++) {
        data_ov001_021a9bf0->mUnk_18[data_ov001_021a6aac[i]].mUnk_06 = b;
    }
    for (j = 0; j < 3; j++) {
        for (k = 0; k < 3; k++) {
            data_ov001_021a9bf0->mUnk_18[idx + data_ov001_021a6ae4[j][k]].mUnk_06 = b;
        }
    }
    for (m = 0; m < 3; m++) {
        data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6ab4[m]].mUnk_04 = a;
        data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6ac4[m]].mUnk_04 = a;
        data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6a9c[m]].mUnk_04 = a;
        data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6aa4[m]].mUnk_04 = a;
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
