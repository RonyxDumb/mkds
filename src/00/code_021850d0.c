#include "00/code_021850d0.h"
#include "00/code_02184bec.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/code_020ae428.h"

void func_ov000_021850d0(void) {
    s32 a;
    s32 i;
    s32 j;

    data_ov000_021b4c84->mUnk_0c = data_ov000_021b4c84->mUnk_0c + 1;
    a = func_020ae4c0(1, 0xfa, 0, data_ov000_021b4c84->mUnk_0c, 10);
    for (i = 0; i < 2; i++) {
        for (j = 0; j < data_ov000_021b06c8[i]; j++) {
            if (i == 1) {
                data_ov000_021b4c84->mUnk_1c[data_ov000_021b06d0[i][j]].mUnk_04 = a;
            } else {
                data_ov000_021b4c84->mUnk_1c[data_ov000_021b06d0[i][j]].mUnk_04 = -a;
            }
        }
    }
    if (data_ov000_021b4c84->mUnk_0c >= 10) {
        data_ov000_021b4c84->mUnk_04 = 2;
        data_ov000_021b4c84->mUnk_0c = 0;
        func_02128374();
    }
}
