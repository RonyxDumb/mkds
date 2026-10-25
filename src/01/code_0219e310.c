#include "01/code_0219e310.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_02037000.h"

void func_ov001_0219e38c(void)
{
    func_020b496c((void **) &data_ov001_021ca400->mUnk_038[0], func_0204799c("logo_end_marioKart_m_b_01.ncgr"));
    func_020b4810((void **) &data_ov001_021ca400->mUnk_040[0], func_0204799c("logo_end_marioKart_m_bg_01.nscr"));
    func_020b4a7c((void **) &data_ov001_021ca400->mUnk_048[0], func_0204799c("logo_end_marioKart_m_b.nclr"));
    switch (data_ov001_021ca400->mUnk_00c) {
    case 0:
        func_020b496c((void **) &data_ov001_021ca400->mUnk_038[1], func_0204799c("thanksYou_m_b_00.ncgr"));
        func_020b4810((void **) &data_ov001_021ca400->mUnk_040[1], func_0204799c("thanksYou_m_bg_00.nscr"));
        func_020b4a7c((void **) &data_ov001_021ca400->mUnk_048[1], func_0204799c("thanksYou_m_b_00.nclr"));
        break;
    case 1:
        func_020b496c((void **) &data_ov001_021ca400->mUnk_038[1], func_0204799c("thanksYou_m_b_01_2.ncgr"));
        func_020b4810((void **) &data_ov001_021ca400->mUnk_040[1], func_0204799c("thanksYou_m_bg_01_2.nscr"));
        func_020b4a7c((void **) &data_ov001_021ca400->mUnk_048[1], func_0204799c("thanksYou_m_b_01.nclr"));
        break;
    }
    func_020b496c((void **) &data_ov001_021ca400->mUnk_050[0], func_0204799c("end_allRightsReserved_s_b.ncgr"));
    func_020b4810((void **) &data_ov001_021ca400->mUnk_058[0], func_0204799c("end_allRightsReserved_s_bg.nscr"));
    func_020b4a7c((void **) &data_ov001_021ca400->mUnk_060[0], func_0204799c("end_allRightsReserved_s_b.nclr"));
    func_020b496c((void **) &data_ov001_021ca400->mUnk_050[1], func_0204799c("logo_end_Nintendo_s_b.ncgr"));
    func_020b4810((void **) &data_ov001_021ca400->mUnk_058[1], func_0204799c("logo_end_Nintendo_s_bg.nscr"));
    func_020b4a7c((void **) &data_ov001_021ca400->mUnk_060[1], func_0204799c("logo_end_Nintendo_s_b.nclr"));
    func_020b48ec(&data_ov001_021ca400->mUnk_024, func_0204799c("thanksYou_m.nce.ncer"));
    func_020b4a7c((void **) &data_ov001_021ca400->mUnk_02c, func_0204799c("thanksYou_m_o_00.nclr"));
    switch (data_ov001_021ca400->mUnk_00c) {
    case 0:
        data_ov001_021ca400->mUnk_030 = func_0204799c("ending_thanks_00.bncl");
        data_ov001_021ca400->mUnk_034 = func_0204799c("ending_thanks_00.bnll");
        break;
    case 1:
        data_ov001_021ca400->mUnk_030 = func_0204799c("ending_thanks_01.bncl");
        data_ov001_021ca400->mUnk_034 = func_0204799c("ending_thanks_01.bnll");
        break;
    }
    if (data_0217b488->mUnk_70 != 0) {
        func_ov001_0219e5a0();
    } else {
        func_ov001_0219e5d4(0);
    }
    func_02016468(0xe, 0, data_ov001_021ca400->mUnk_02c->mUnk_0c, data_ov001_021ca400->mUnk_02c->mUnk_08);
}

void func_ov001_0219e34c(void)
{
    if (func_02036c5c() != 0) {
        if (data_0217b488->mUnk_70 != 0) {
            data_ov001_021ca400->mUnk_004 = 5;
            data_0217b488->mUnk_70 = 0;
            return;
        }
        data_ov001_021ca400->mUnk_004 = 1;
    }
}

void func_ov001_0219e310(void)
{
    data_ov001_021ca400->mUnk_008++;
    if (data_ov001_021ca400->mUnk_008 > data_ov001_021a6c50[data_ov001_021ca400->mUnk_000]) {
        data_ov001_021ca400->mUnk_004 = 2;
        data_ov001_021ca400->mUnk_008 = 0;
        func_02036f10((s16) (data_ov001_021a6c50[2]));
    }
}
