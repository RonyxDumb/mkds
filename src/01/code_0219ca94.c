#include "01/code_0219ca94.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_02037000.h"

void func_ov001_0219cba0(void)
{
    Unk02175628Index idx = UNK_02175628_INDEX_8;
    s32 res = -1;
    s32 sel = -4;
    s32 b = 0;
    s32 a;
    s32 i;
    s32 prev;
    u16 x;

    a = 0;
    x = data_02175628[idx].mUnk_4c;
    if (x == 0 && data_02175628[idx].mUnk_58 < 5) {
        a = 1;
    }
    if (a == 0 && data_02175628[idx].mUnk_54 == 0 && x != 0) {
        b = 1;
    }
    if (b != 0) {
        res = func_0201ea84(data_ov001_021a9bf8->mUnk_105c[1], data_02175628[idx].mUnk_48, data_02175628[idx].mUnk_4a);
    }
    for (i = 0; i < 6; i++) {
        if (res == data_ov001_021a6be8[i]) {
            sel = i;
        }
    }
    if ((u16) (data_02175628[idx].mUnk_00 & 2) == 0) {
        b = 0;
        a = 0;
        x = data_02175628[idx].mUnk_4c;
        if (x == 0 && data_02175628[idx].mUnk_58 < 5) {
            a = 1;
        }
        if (a == 0 && data_02175628[idx].mUnk_54 == 0 && x != 0) {
            b = 1;
        }
        if (b == 0 || func_02128210(data_02175628[idx].mUnk_48, data_02175628[idx].mUnk_4a) == 0) {
            goto next;
        }
    }
    if (data_0217b488->mUnk_08 == 2) {
        data_ov001_021a9bf8->mUnk_04 = 4;
        func_02128310(0);
        data_ov001_021a9bf8->mUnk_2c = 0;
        return;
    }
    data_ov001_021a9bf8->mUnk_04 = 6;
    data_ov001_021a9bf8->mUnk_28 = -3;
    if (data_021759d0->mUnk_20 == 0) {
        func_02128310(0);
        data_ov001_021a9bf8->mUnk_2c = 0;
        return;
    }
    func_02128310(1);
    data_ov001_021a9bf8->mUnk_2c = 1;
    return;
next:
    if ((u16) (data_02175628[idx].mUnk_00 & 1) != 0 || sel != -4) {
        prev = data_ov001_021a9bf8->mUnk_08;
        if ((u16) (data_02175628[idx].mUnk_00 & 1) == 0) {
            data_ov001_021a9bf8->mUnk_08 = sel;
        }
        if (data_ov001_021a9bf8->mUnk_08 == prev) {
            data_ov001_021a9bf8->mUnk_20 = 0;
        }
        data_ov001_021a9bf8->mUnk_28 = data_ov001_021a9bf8->mUnk_08;
        data_ov001_021a9bf8->mUnk_04 = 3;
        data_ov001_021a9bf8->mUnk_10 = 6;
        func_02105ac0(5);
        return;
    }
    if (func_020ae408(8, 0x40) != 0) {
        data_ov001_021a9bf8->mUnk_08--;
        if (data_ov001_021a9bf8->mUnk_08 < 0) {
            data_ov001_021a9bf8->mUnk_08 = 5;
        }
        data_ov001_021a9bf8->mUnk_10 = 6;
        func_02105ac0(0);
        return;
    }
    if (func_020ae408(8, 0x80) != 0) {
        data_ov001_021a9bf8->mUnk_08++;
        if (data_ov001_021a9bf8->mUnk_08 >= 6) {
            data_ov001_021a9bf8->mUnk_08 = 0;
        }
        data_ov001_021a9bf8->mUnk_10 = 6;
        func_02105ac0(0);
    }
}

void func_ov001_0219caf4(void)
{
    s32 i;
    s16 v;

    data_ov001_021a9bf8->mUnk_0c++;
    v = func_020ae488(data_ov001_021a9bf8->mUnk_0c);
    for (i = 0; i < 3; i++) {
        data_ov001_021a9bf8->mUnk_1034[1][data_ov001_021a6bf0[data_ov001_021a9bf8->mUnk_08][i]].mUnk_04 = v;
    }
    if (data_ov001_021a9bf8->mUnk_0c >= 10) {
        data_ov001_021a9bf8->mUnk_04 = 5;
        data_ov001_021a9bf8->mUnk_0c = 0;
        func_021277f8((void *) (func_020b3f7c(data_ov001_021a9bf8->mUnk_1084, 4)), (void *) (func_020b3f7c(data_ov001_021a9bf8->mUnk_1084, 2)), (int) (0));
        func_0212775c(0, 7);
        func_0212775c(1, 0x10);
    } else if (data_ov001_021a9bf8->mUnk_0c >= 5) {
        data_ov001_021a9bf8->mUnk_20 = 1;
    }
}

void func_ov001_0219ca94(void)
{
    if (func_02128294() != 0) {
        data_ov001_021a9bf8->mUnk_28 = -2;
        func_021277f8((void *) (func_020b3f7c(data_ov001_021a9bf8->mUnk_1080, 0x14)), (void *) (func_020b3f7c(data_ov001_021a9bf8->mUnk_1080, 0x15)), (int) (0));
        func_0212775c(0, 5);
        func_0212775c(1, 0xc);
        data_ov001_021a9bf8->mUnk_04 = 5;
    }
}
