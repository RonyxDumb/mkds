#include "01/code_0219ae30.h"
#include "01/unk_021a6000.h"
#include "00/code_02182fdc.h"
#include "Main/Unknown/code_02124000.h"
#include "01/code_0219b834.h"
#include "01/code_0219c000.h"
#include "Main/Unknown/code_02087000.h"
#include "Main/Unknown/code_0212b000.h"

void func_ov001_0219afc8(s32 a) {
    data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6a9c[a]].mUnk_00 = 1;
    func_02124a20(data_ov001_021a6aa4[a], 14, data_ov001_021a9bf0->mUnk_0c, data_ov001_021a9bf0->mUnk_10);
}

void func_ov001_0219af90(s32 a) {
    data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6a9c[a]].mUnk_00 = 0;
    func_02124a20(data_ov001_021a6aa4[a], 15, data_ov001_021a9bf0->mUnk_0c, data_ov001_021a9bf0->mUnk_10);
}

// non-matching: registers only; the value read from mUnk_04[3] is in r3 and the object pointer temporary in r2, the original has them the other way round
void func_ov001_0219ae88(void) {
    s32 i;
    s32 j;
    s32 k;
    s32 n;
    data_ov001_021a9bf0->mUnk_34 = 0;
    data_ov001_021a9bf0->mUnk_38 = 0;
    data_ov001_021a9bf0->mUnk_3c = ~0xbf;
    n = data_ov001_021a9bf0->mUnk_04[3];
    data_ov001_021a9bf0->mUnk_18[0].mUnk_06 = ~0xbf;
    data_ov001_021a9bf0->mUnk_18[1].mUnk_06 = ~0xbf;
    data_ov001_021a9bf0->mUnk_18[n].mUnk_06 = ~0xbf;
    for (i = 0; i < 3; i++) {
        data_ov001_021a9bf0->mUnk_18[data_ov001_021a6aac[i]].mUnk_06 = ~0xbf;
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            data_ov001_021a9bf0->mUnk_18[n + data_ov001_021a6ae4[i][j]].mUnk_06 = ~0xbf;
        }
    }
    for (k = 0; k < 3; k++) {
        data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6ab4[k]].mUnk_04 = 0xe0;
        data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6ac4[k]].mUnk_04 = 0xe0;
        data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6a9c[k]].mUnk_04 = 0xe0;
        data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6aa4[k]].mUnk_04 = 0xe0;
        func_ov001_0219af90(k);
    }
}

void func_ov001_0219ae74(void) {
    data_ov001_021a9bf0->mUnk_34 = 1;
    data_ov001_021a9bf0->mUnk_38 = 0;
}

void func_ov001_0219ae60(void) {
    data_ov001_021a9bf0->mUnk_34 = 2;
    data_ov001_021a9bf0->mUnk_38 = 0;
}

void func_ov001_0219ae44(void) {
    data_ov001_021a9bf0->mUnk_34 = 3;
    data_ov001_021a9bf0->mUnk_38 = 0;
    func_02128374();
}

void func_ov001_0219ae30(void) {
    data_ov001_021a9bf0->mUnk_34 = 4;
    data_ov001_021a9bf0->mUnk_38 = 0;
}
