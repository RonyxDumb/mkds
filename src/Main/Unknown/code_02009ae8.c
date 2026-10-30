#include "Main/Unknown/code_02009ae8.h"

#pragma thumb on

void func_02009ae8(u32 a) {
    u32 v1;
    u32 v2;
    s32 v3;
    u32 v4;
    func_021436d0(func_0200a7b0, a);
    if (a != 0 && a < 16) {
        v1 = a - 1;
        (*(Unk0216fdac **) &data_0216fdac)->mUnk_148a[v1] = 0;
        func_0214d168((*(Unk0216fdac **) &data_0216fdac)->mUnk_14a8 + v1, 0, 4);
        func_0214d168((*(Unk0216fdac **) &data_0216fdac)->mUnk_1340 + v1 * 0x16, 0, 0x16);
        func_0200c3fc(a);
        v2 = 0;
        (*(Unk0216fdac **) &data_0216fdac)->mUnk_1754[v1] = v2;
        v3 = (*(Unk0216fdac **) &data_0216fdac)->mUnk_1526[v1];
        v2 = ~v2;
        if (v3 != v2) {
            v4 = 1 << a;
            v3 = (u8) v3;
            ((Unk0216fdac *) ((u8 *) *(Unk0216fdac **) &data_0216fdac + v3 * 0x5d4))->mUnk_1d4e &= ~v4;
            ((Unk0216fdac *) ((u8 *) *(Unk0216fdac **) &data_0216fdac + v3 * 0x5d4))->mUnk_1d50 |= v4;
            (*(Unk0216fdac **) &data_0216fdac)->mUnk_1526[a - 1] = v2;
            ((Unk0216fdac *) ((u8 *) *(Unk0216fdac **) &data_0216fdac + v3 * 0x5d4))->mUnk_1d4c &= ~v4;
        }
        if (((*(Unk0216fdac **) &data_0216fdac)->mUnk_1536 & (1 << a)) != 0) {
            (*(Unk0216fdac **) &data_0216fdac)->mUnk_1535--;
            (*(Unk0216fdac **) &data_0216fdac)->mUnk_1536 &= ~(1 << a);
        }
        (*(Unk0216fdac **) &data_0216fdac)->mUnk_14e8[v1] = 0;
    }
}

#pragma thumb off
