#include "01/code_0219e0b8.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_02037000.h"

void func_ov001_0219e1f8(void)
{
    Unk02175628Index idx = UNK_02175628_INDEX_8;
    u16 flags;
    s32 a;
    s32 b;
    u16 x;

    data_ov001_021ca400->mUnk_008++;
    if (data_ov001_021ca400->mUnk_008 > data_ov001_021a6c50[data_ov001_021ca400->mUnk_000]) {
        data_ov001_021ca400->mUnk_008 = data_ov001_021a6c50[data_ov001_021ca400->mUnk_000];
        flags = data_02175628[idx].mUnk_00 & 0xc0f;
        if (flags == 0) {
            a = 0;
            b = 0;
            x = data_02175628[idx].mUnk_4c;
            if (x == 0 && data_02175628[idx].mUnk_58 < 5) {
                b = 1;
            }
            if (b == 0 && data_02175628[idx].mUnk_54 == 0 && x != 0) {
                a = 1;
            }
            if (a == 0) {
                return;
            }
        }
        data_ov001_021ca400->mUnk_004 = 6;
        data_ov001_021ca400->mUnk_008 = 0;
        func_02036f10((s16) (data_ov001_021a6c50[6]));
    }
}

void func_ov001_0219e1d4(void)
{
    if (func_02036d08() != 0) {
        data_ov001_021ca400->mUnk_004 = 7;
        data_ov001_021ca400->mUnk_008 = 0;
    }
}

void func_ov001_0219e1b0(void)
{
    data_ov001_021ca400->mUnk_008++;
    if (data_ov001_021ca400->mUnk_008 > data_ov001_021a6c50[7]) {
        data_ov001_021ca400->mUnk_014 = 0;
    }
}

void func_ov001_0219e118(void)
{
    data_ov001_021ca400->mUnk_000 = data_ov001_021ca400->mUnk_004;
    func_020ae6ac((void *) (data_ov001_021ca400->mUnk_068), (void *) (0));
    switch (data_ov001_021ca400->mUnk_000) {
    case 0:
        func_ov001_0219e34c();
        break;
    case 1:
        func_ov001_0219e310();
        break;
    case 2:
        func_ov001_0219e2f0();
        break;
    case 3:
        func_ov001_0219e2b4();
        break;
    case 4:
        func_ov001_0219e294();
        break;
    case 5:
        func_ov001_0219e1f8();
        break;
    case 6:
        func_ov001_0219e1d4();
        break;
    case 7:
        func_ov001_0219e1b0();
        break;
    }
    func_02124c30(data_ov001_021ca400->mUnk_030, data_ov001_021ca400->mUnk_024, data_ov001_021ca400->mUnk_034,
                  data_ov001_021ca400->mUnk_068, data_ov001_021ca400->mUnk_020);
    func_020ae630((void *) (data_ov001_021ca400->mUnk_068), (void *) (0));
}

void func_ov001_0219e0d4(void)
{
    u32 bits;

    if (data_ov001_021ca400->mUnk_018 != 0) {
        bits = (*(vu32 *) 0x4000000 & 0x1f00) >> 8;
        *(vu32 *) 0x4000000 = (*(vu32 *) 0x4000000 & 0xffffe0ff) | ((bits | 0x10) << 8);
    }
    func_020ae5f0((void *) (data_ov001_021ca400->mUnk_068), (void *) (0));
}

void func_ov001_0219e0c4(void)
{
    data_0217b488->mUnk_70 = 1;
}

s32 func_ov001_0219e0b8(void)
{
    return data_0217b488->mUnk_70;
}
