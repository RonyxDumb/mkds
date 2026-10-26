#include "01/code_0219c428.h"
#include "01/code_0219bb48.h"
#include "Main/Unknown/code_0212b000.h"
#include "Main/Unknown/code_0212ecc0.h"
#include "Main/Unknown/unk_0217d068.h"
#include "01/code_0219c000.h"
#include "01/unk_021a6000.h"

void func_ov001_0219c480(void) {
    u16 cnt;
    s32 i;

    data_ov001_021a9bf4->mUnk_4c = 0;
    data_ov001_021a9bf4->mUnk_50 = 0;
    data_ov001_021a9bf4->mUnk_58 = 0;
    data_ov001_021a9bf4->mUnk_5c = -0xc0;
    for (i = 0; i < 6; i++) {
        data_ov001_021a9bf4->mUnk_34[data_ov001_021a6b6c[i]].mUnk_06 = -0xc0;
    }
    data_ov001_021a9bf4->mUnk_34[10].mUnk_06 = -0xc0;
    data_ov001_021a9bf4->mUnk_34[11].mUnk_06 = -0xc0;
    cnt = data_ov001_021a9bf4->mUnk_10->mUnk_06;
    for (i = 0; i < 5; i++) {
        data_ov001_021a9bf4->mUnk_34[cnt + data_ov001_021a6b54[i]].mUnk_06 = -0xc0;
    }
    data_ov001_021a9bf4->mUnk_34[cnt + 5].mUnk_06 = -0xc0;
    for (i = 0; i < 2; i++) {
        data_ov001_021a9bf4->mUnk_34[data_ov001_021a6b3c[i]].mUnk_06 = -0xc0;
        data_ov001_021a9bf4->mUnk_34[data_ov001_021a6b38[i]].mUnk_06 = -0xc0;
    }
}

void func_ov001_0219c46c(void) {
    data_ov001_021a9bf4->mUnk_4c = 1;
    data_ov001_021a9bf4->mUnk_50 = 0;
}

void func_ov001_0219c458(void) {
    data_ov001_021a9bf4->mUnk_4c = 2;
    data_ov001_021a9bf4->mUnk_50 = 0;
}

void func_ov001_0219c428(void) {
    data_ov001_021a9bf4->mUnk_4c = 3;
    data_ov001_021a9bf4->mUnk_50 = 0;
    func_0212b7e8();
    func_0212ecc0(data_0217d068, 0, 5);
}
