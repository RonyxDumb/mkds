#include "01/code_0219cdd4.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_02036000.h"

void func_ov001_0219d03c(void) {
    volatile u16 z;
    Unk020b4934 *a;
    Unk020b4a44 *b;
    Unk020b4a44 *c;
    Unk020b4a44 *d;

    func_020b4934(&a, func_0204799c("mg/select_battle_stage_m_b.ncgr"));
    func_020b47d8(&data_ov001_021a9bf8->mUnk_106c[0], func_0204799c("mg/select_battle_stage_m_00.nscr"));
    func_020b47d8(&data_ov001_021a9bf8->mUnk_106c[1], func_0204799c("mg/select_battle_stage_m_01.nscr"));
    func_020b47d8(&data_ov001_021a9bf8->mUnk_106c[2], func_0204799c("mg/select_battle_stage_m_02.nscr"));
    func_020b4a44(&b, func_0204799c("mg/select_battle_stage_m_b.nclr"));
    data_ov001_021a9bf8->mUnk_1054[0] = func_0204799c("mg/select_battle_stage_m.bncl");
    data_ov001_021a9bf8->mUnk_105c[0] = 0;
    data_ov001_021a9bf8->mUnk_1064[0] = func_0204799c("mg/select_battle_stage_m.bnll");
    data_ov001_021a9bf8->mUnk_1054[1] = func_0204799c("mg/select_battle_stage_s.bncl");
    data_ov001_021a9bf8->mUnk_105c[1] = func_0204799c("mg/select_battle_stage_s.bnbl");
    data_ov001_021a9bf8->mUnk_1064[1] = 0;
    func_020b49bc(&data_ov001_021a9bf8->mUnk_1044, func_0204799c("mg/select_battle_stage_m.nce.ncgr"));
    func_020b48b4(&data_ov001_021a9bf8->mUnk_103c, func_0204799c("mg/select_battle_stage_m.nce.ncer"));
    func_020b4a44(&c, func_0204799c("mg/select_battle_stage_m_o.nclr"));
    func_020b49bc(&data_ov001_021a9bf8->mUnk_1048, func_0204799c("mg/select_battle_stage_s.nce.ncgr"));
    func_020b48b4(&data_ov001_021a9bf8->mUnk_1040, func_0204799c("mg/select_battle_stage_s.nce.ncer"));
    func_020b4a44(&d, func_0204799c("mg/select_battle_stage_s_o.nclr"));
    z = 0;
    func_0214cfe4(z, data_ov001_021a9bf8->mUnk_30, 0x1000);
    func_02016468(6, 0, a->mUnk_14, a->mUnk_10);
    func_02016468(10, 0, data_ov001_021a9bf8->mUnk_30, 0x1000);
    func_02016468(15, 0, b->mUnk_0c, 0x180);
    func_02016468(19, 0, data_ov001_021a9bf8->mUnk_1044->mUnk_14, data_ov001_021a9bf8->mUnk_1044->mUnk_10);
    func_02016468(14, 0, c->mUnk_0c, 0x1a0);
    func_02016468(14, 0x1c0, c->mUnk_0c + 0xe0, 0x40);
    func_02016468(35, 0, data_ov001_021a9bf8->mUnk_1048->mUnk_14, data_ov001_021a9bf8->mUnk_1048->mUnk_10);
    func_02016468(30, 0, d->mUnk_0c, d->mUnk_08);
}

void func_ov001_0219cf60(void) {
    s32 x, y;
    s32 idx = data_ov001_021a9bf8->mUnk_08;
    u8 src = data_ov001_021a6be0[idx];

    for (y = 0; y <= data_ov001_021a6c04[data_ov001_021a9bf8->mUnk_08].mUnk_03 - data_ov001_021a6c04[data_ov001_021a9bf8->mUnk_08].mUnk_02; y++) {
        for (x = 0; x <= data_ov001_021a6c04[data_ov001_021a9bf8->mUnk_08].mUnk_01 - data_ov001_021a6c04[data_ov001_021a9bf8->mUnk_08].mUnk_00; x++) {
            (data_ov001_021a9bf8->mUnk_30[data_ov001_021a6bcc[1] + y] + data_ov001_021a6bcc[0])[x] =
                *((u16 *) data_ov001_021a9bf8->mUnk_106c[src]->mUnk_0c + x + data_ov001_021a6c04[data_ov001_021a9bf8->mUnk_08].mUnk_00 + (data_ov001_021a6c04[data_ov001_021a9bf8->mUnk_08].mUnk_02 + y) * 32);
        }
    }
    func_02016468(10, 0, data_ov001_021a9bf8->mUnk_30, 0x600);
}

// non-matching: only the first statement differs. The original loads the address of data_ov001_021a6bc4 (and its
// pool word) before it reads mUnk_14; the compiled code loads it after mUnk_1034.
void func_ov001_0219cec4(void) {
    s32 i;
    u16 x = data_ov001_021a9bf8->mUnk_1054[0]->mUnk_06;

    data_ov001_021a9bf8->mUnk_1034[0][data_ov001_021a6bc4[0]].mUnk_06 = -data_ov001_021a9bf8->mUnk_14;
    for (i = 0; i < 3; i++) {
        data_ov001_021a9bf8->mUnk_1034[0][data_ov001_021a6bd0[i]].mUnk_06 = data_ov001_021a9bf8->mUnk_1c - data_ov001_021a9bf8->mUnk_14;
    }
    for (i = 0; i < 3; i++) {
        data_ov001_021a9bf8->mUnk_1034[0][data_ov001_021a6bd4[i]].mUnk_04 = data_ov001_021a9bf8->mUnk_18;
    }
    for (i = 0; i < 2; i++) {
        (data_ov001_021a9bf8->mUnk_1034[0] + x)[data_ov001_021a6bc8[i]].mUnk_04 = data_ov001_021a9bf8->mUnk_18;
    }
}

void func_ov001_0219cdd4(void) {
    s32 i, j;

    data_ov001_021a9bf8->mUnk_0c++;
    if (data_ov001_021a9bf8->mUnk_0c > 20) {
        data_ov001_021a9bf8->mUnk_04 = 1;
        data_ov001_021a9bf8->mUnk_0c = 0;
        data_ov001_021a9bf8->mUnk_04 = 1;
        func_02128374();
    } else if (data_ov001_021a9bf8->mUnk_0c > 10) {
        for (i = 0; i < 6; i++) {
            for (j = 0; j < 3; j++) {
                data_ov001_021a9bf8->mUnk_1034[1][data_ov001_021a6bf0[i][j]].mUnk_04 = func_020ae488(data_ov001_021a9bf8->mUnk_0c - 10);
            }
        }
    } else {
        data_ov001_021a9bf8->mUnk_14 = func_020ae4c0(1, 0xa0, 0, data_ov001_021a9bf8->mUnk_0c, 10);
        data_ov001_021a9bf8->mUnk_18 = func_020ae4c0(1, -0x100, 0, data_ov001_021a9bf8->mUnk_0c, 10);
        for (i = 0; i < 6; i++) {
            for (j = 0; j < 3; j++) {
                data_ov001_021a9bf8->mUnk_1034[1][data_ov001_021a6bf0[i][j]].mUnk_04 = func_020ae4c0(1, 0xdc, 0, data_ov001_021a9bf8->mUnk_0c, 10);
            }
        }
    }
}
