#include "Main/Unknown/code_021287cc.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_021285b0.h"

#pragma thumb on
s32 func_021287cc(void *a, s32 b) {
    u32 t;
    data_0217d3f8 = func_02036bec(a, 0x828);
    if (*(vu16 *) 0x27ffc40 != 2) {
        func_02128778();
        b = func_021286a0(b);
        data_0217d3f8->mUnk_820 = 1;
    } else {
        data_0217d3f8->mUnk_820 = 0;
        t = (*(vu32 *) 0x4001000 & 0x1f00) >> 8;
        t &= ~4;
        *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & 0xffffe0ff) | (t << 8);
    }
    data_0217d3f8->mUnk_00 = 1;
    data_0217d3f8->mUnk_04 = 0;
    data_0217d3f8->mUnk_08 = 0;
    data_0217d3f8->mUnk_0c = 0;
    data_0217d3f8->mUnk_810 = 0;
    data_0217d3f8->mUnk_818 = 0;
    data_0217d3f8->mUnk_81c = -0x28;
    data_0217d3f8->mUnk_824 = 0xe;
    return b;
}
#pragma thumb off
