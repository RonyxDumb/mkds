#include "01/code_02199d88.h"
#include "01/unk_021a6000.h"

void func_ov001_02199d88(void) {
    s32 i;
    s32 j;
    s32 v;
    data_ov001_021a9bec->mUnk_0c++;
    v = func_020ae4c0(1, 0xfa, 0, data_ov001_021a9bec->mUnk_0c, 10);
    for (i = 0; i < 2; i++) {
        for (j = 0; j < data_ov001_021a6a8c[i]; j++) {
            if (i == 1) {
                data_ov001_021a9bec->mUnk_1c[data_ov001_021a6a94[i][j]].mUnk_04 = v;
            } else {
                data_ov001_021a9bec->mUnk_1c[data_ov001_021a6a94[i][j]].mUnk_04 = -v;
            }
        }
    }
    if (data_ov001_021a9bec->mUnk_0c >= 10) {
        data_ov001_021a9bec->mUnk_04 = 2;
        data_ov001_021a9bec->mUnk_0c = 0;
        func_02128374();
    }
}
