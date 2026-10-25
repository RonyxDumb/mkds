#include "01/code_0219d2c0.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_02036000.h"

void func_ov001_0219d2c0(void *param_1, s32 param_2, void *param_3, void *param_4) {
    s32 i, j;
    void *heap;
    void *p;

    heap = func_020369fc(param_1);
    data_ov001_021a9bf8 = func_02036bec(heap, 0x1088);
    data_ov001_021a9bf8->mUnk_1030 = heap;
    data_ov001_021a9bf8->mUnk_00 = 0;
    data_ov001_021a9bf8->mUnk_04 = 0;
    data_ov001_021a9bf8->mUnk_08 = 0;
    data_ov001_021a9bf8->mUnk_0c = 0;
    data_ov001_021a9bf8->mUnk_10 = 0;
    data_ov001_021a9bf8->mUnk_1c = 0;
    data_ov001_021a9bf8->mUnk_20 = 1;
    data_ov001_021a9bf8->mUnk_24 = -4;
    data_ov001_021a9bf8->mUnk_1080 = func_0204799c("menu.bmg");
    data_ov001_021a9bf8->mUnk_1084 = func_02047a28("common.bmg");
    func_ov001_0219d03c();
    func_ov001_0219cf60();
    for (i = 0; i < 6; i++) {
        func_02124a98(data_ov001_021a6bf0[i][0], 1, data_ov001_021a9bf8->mUnk_1040, data_ov001_021a9bf8->mUnk_1054[1]);
    }
    data_ov001_021a9bf8->mUnk_1078 = param_3;
    data_ov001_021a9bf8->mUnk_107c = param_4;
    func_020ae6d4(param_3, param_4);
    for (i = 0; i < 2; i++) {
        func_02124ed0(data_ov001_021a9bf8->mUnk_1030, data_ov001_021a9bf8->mUnk_1054[i], data_ov001_021a9bf8->mUnk_1064[i], &data_ov001_021a9bf8->mUnk_1034[i]);
    }
    data_ov001_021a9bf8->mUnk_1034[0][0].mUnk_06 = -0xa0;
    data_ov001_021a9bf8->mUnk_14 = 0xa0;
    func_ov001_0219cec4();
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 3; j++) {
            data_ov001_021a9bf8->mUnk_1034[1][data_ov001_021a6bf0[i][j]].mUnk_04 = 0xdc;
        }
    }
    {
        u8 a[2] = {0, 1};
        u8 b[2] = {5, 6};
        s32 rem = 0x8000;

        p = func_020b3f7c(data_ov001_021a9bf8->mUnk_1080, 6);
        if (param_2 == 0) {
            p = func_020b3f7c(data_ov001_021a9bf8->mUnk_1080, 7);
        }
        for (i = 0; i < 2; i++) {
            rem -= func_021243ac(data_ov001_021a9bf8->mUnk_1030, a[i], data_ov001_021a9bf8->mUnk_1064[0], 0xa8, 13, b[i], data_ov001_021a9bf8->mUnk_103c, data_ov001_021a9bf8->mUnk_1054[0], data_ov001_021a9bf8->mUnk_1034[0], rem);
            func_0212426c(0, a[i], data_ov001_021a9bf8->mUnk_1064[0], p, data_ov001_021a9bf8->mUnk_1054[0], data_ov001_021a9bf8->mUnk_1034[0]);
        }
        if (param_2 == 1) {
            data_ov001_021a9bf8->mUnk_1034[0][5].mUnk_00 = 0;
        } else {
            data_ov001_021a9bf8->mUnk_1034[0][6].mUnk_00 = 0;
        }
    }
    *(vu16 *) 0x0400000c = (*(vu16 *) 0x0400000c & 0x43) | 0x9e10;
    func_021281c8(14);
}
