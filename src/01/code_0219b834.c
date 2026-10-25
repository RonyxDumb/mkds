#include "01/code_0219b834.h"
#include "01/code_0219bb48.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_02128244.h"
#include "Main/Unknown/unk_02175628.h"
#include "01/code_0219c000.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_02087000.h"
#include "Main/Unknown/code_0212b000.h"

void func_ov001_0219ba3c(void) {
    u16 n;
    s16 v;
    s32 i;

    func_ov001_0219c2a4();
    n = data_ov001_021a9bf4->mUnk_10->mUnk_06;
    data_ov001_021a9bf4->mUnk_50++;
    v = func_020ae4c0(1, ~0xbf, 0, data_ov001_021a9bf4->mUnk_50, 10);
    data_ov001_021a9bf4->mUnk_5c = v;
    for (i = 0; i < 6; i++) {
        data_ov001_021a9bf4->mUnk_34[data_ov001_021a6b6c[i]].mUnk_06 = v;
    }
    for (i = 0; i < 5; i++) {
        data_ov001_021a9bf4->mUnk_34[n + data_ov001_021a6b54[i]].mUnk_06 = v;
    }
    for (i = 0; i < 2; i++) {
        data_ov001_021a9bf4->mUnk_34[data_ov001_021a6b3c[i]].mUnk_06 = v;
        data_ov001_021a9bf4->mUnk_34[data_ov001_021a6b38[i]].mUnk_06 = v;
    }
    if (data_ov001_021a9bf4->mUnk_50 >= 10) {
        func_ov001_0219c46c();
    }
}

void func_ov001_0219b9dc(void) {
    u16 n;
    s16 w;

    func_ov001_0219c2a4();
    n = data_ov001_021a9bf4->mUnk_10->mUnk_06;
    data_ov001_021a9bf4->mUnk_50++;
    w = -func_0212825c(data_ov001_021a9bf4->mUnk_50);
    data_ov001_021a9bf4->mUnk_34[10].mUnk_06 = w;
    data_ov001_021a9bf4->mUnk_34[11].mUnk_06 = w;
    data_ov001_021a9bf4->mUnk_34[n + 5].mUnk_06 = w;
    if (data_ov001_021a9bf4->mUnk_50 >= 10) {
        func_ov001_0219c458();
    }
}

void func_ov001_0219b874(void) {
    s32 r;
    s32 b;
    s32 a;
    s32 d;
    s32 c;
    Unk02175628Index idx;

    r = -1;
    func_ov001_0219c2a4();
    idx = UNK_02175628_INDEX_8;
    b = 0;
    a = 0;
    if (data_02175628[idx].mUnk_4c == 0 && data_02175628[idx].mUnk_58 < 5) {
        a = 1;
    }
    if (a == 0 && data_02175628[idx].mUnk_54 == 0 && data_02175628[idx].mUnk_4c != 0) {
        b = 1;
    }
    if (b != 0) {
        r = func_0201ea84(data_ov001_021a9bf4->mUnk_14, data_02175628[idx].mUnk_48, data_02175628[idx].mUnk_4a);
    }
    if ((u16) (data_02175628[idx].mUnk_00 & 2) == 0) {
        d = 0;
        c = 0;
        if (data_02175628[idx].mUnk_4c == 0 && data_02175628[idx].mUnk_58 < 5) {
            c = 1;
        }
        if (c == 0 && data_02175628[idx].mUnk_54 == 0 && data_02175628[idx].mUnk_4c != 0) {
            d = 1;
        }
        if (d == 0 || func_02128210(data_02175628[idx].mUnk_48, data_02175628[idx].mUnk_4a) == 0) {
            goto next;
        }
    }
    func_021281c8(14);
    func_ov001_0219c3a8();
    data_ov001_021a9bf4->mUnk_6c = 2;
    func_02128310(0);
    return;
next:
    if (r == 0) {
        func_ov001_0219bff4();
        return;
    }
    if (r == 1) {
        func_ov001_0219c058();
        return;
    }
    if (r == 3) {
        func_ov001_0219c428();
        return;
    }
    if (r == 2) {
        func_ov001_0219c058();
        return;
    }
    if ((u16) (data_02175628[idx].mUnk_00 & 1) != 0) {
        func_ov001_0219c428();
        return;
    }
    if (func_020ae408(8, 0x20) != 0) {
        func_ov001_0219bff4();
        return;
    }
    if (func_020ae408(8, 0x10) != 0) {
        func_ov001_0219c058();
    }
}

void func_ov001_0219b84c(void) {
    func_ov001_0219c2a4();
    data_ov001_021a9bf4->mUnk_50++;
    if (data_ov001_021a9bf4->mUnk_50 >= 10) {
        func_ov001_0219c3ec();
    }
}

void func_ov001_0219b834(void) {
    if (func_021277c8() != 0) {
        func_ov001_0219c3d8();
    }
}
