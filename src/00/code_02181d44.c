#include "00/code_02181d44.h"

void func_ov000_02181d44(void) {
    s32 v = 0;
    s32 i;
    s32 j;

    data_ov000_021b4c6c->mUnk_0c = data_ov000_021b4c6c->mUnk_0c + 1;
    if (data_ov000_021b4c6c->mUnk_0c >= 20) {
        data_ov000_021b4c6c->mUnk_04 = 2;
        data_ov000_021b4c6c->mUnk_0c = v;
        func_02128374();
    } else if (data_ov000_021b4c6c->mUnk_0c >= 10) {
        v = func_020ae488(data_ov000_021b4c6c->mUnk_0c - 10);
    } else {
        v = func_020ae4c0(1, 0xdc, v, data_ov000_021b4c6c->mUnk_0c, 10);
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < data_ov000_021b05cc[i]; j++) {
            data_ov000_021b4c6c->mUnk_1c[data_ov000_021b05d8[i][j]].mUnk_04 = v;
        }
    }
}
