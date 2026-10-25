#include "01/code_02199f38.h"
#include "01/unk_021a6000.h"

void func_ov001_02199f44(void *heap) {
    s32 i;
    s32 j;
    void *a;
    data_ov001_021a9bec = func_02036bec(heap, 0x34);
    data_ov001_021a9bec->mUnk_18 = heap;
    data_ov001_021a9bec->mUnk_00 = 0;
    data_ov001_021a9bec->mUnk_04 = 0;
    switch (func_ov001_02192e94()) {
    case 0:
    case 5:
        data_ov001_021a9bec->mUnk_08 = 0;
        break;
    case 3:
    case 6:
        data_ov001_021a9bec->mUnk_08 = 1;
        break;
    }
    data_ov001_021a9bec->mUnk_0c = 0;
    data_ov001_021a9bec->mUnk_14 = 1;
    func_ov001_02199e3c();
    for (i = 0; i < 2; i++) {
        func_02124a98(data_ov001_021a6a84[i], 1, data_ov001_021a9bec->mUnk_20, data_ov001_021a9bec->mUnk_2c);
    }
    a = func_ov001_0219e920();
    func_020ae6d4(a, func_ov001_0219e90c());
    func_02124ed0(heap, data_ov001_021a9bec->mUnk_2c, 0, &data_ov001_021a9bec->mUnk_1c);
    for (i = 0; i < 2; i++) {
        for (j = 0; j < data_ov001_021a6a8c[i]; j++) {
            if (i == 1) {
                data_ov001_021a9bec->mUnk_1c[data_ov001_021a6a94[i][j]].mUnk_04 = 0xfa;
            } else {
                data_ov001_021a9bec->mUnk_1c[data_ov001_021a6a94[i][j]].mUnk_04 = -0xfa;
            }
        }
    }
    func_021281c8(0xe);
}

void func_ov001_02199f38(void) {
    data_ov001_021a9bec = 0;
}
