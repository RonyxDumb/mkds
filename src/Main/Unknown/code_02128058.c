#include "Main/Unknown/code_02128058.h"
#include "Main/Unknown/code_02023000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_02127a84.h"
#include "Main/Unknown/code_021281b4.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0212802c.h"

#pragma thumb on
s32 func_02128058(void *a, s32 b, s32 c) {
    s32 i;
    s32 r;
    Unk0217d3f0_2098 *q;
    Unk0217d3f0_2178 *e;
    u32 t;
    data_0217d3f4 = func_02036bec(a, 0x8b4);
    if (*(vu16 *) 0x27ffc40 != 2) {
        func_0212802c();
        c = func_02127f14(c);
        data_0217d3f4->mUnk_8a4 = 1;
    } else {
        data_0217d3f4->mUnk_8a4 = 0;
        t = (*(vu32 *) 0x4001000 & 0x1f00) >> 8;
        t &= ~1;
        *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & 0xffffe0ff) | (t << 8);
    }
    for (i = 0; i < 2; i++) {
        data_0217d3f4->mUnk_894[i] = func_02036bec(a, 0x800);
        func_02023408(&data_0217d3f4->mUnk_834[i], data_0217d3f4->mUnk_894[i], 0x20, 2, 4);
        q = &data_0217d3f4->mUnk_834[i];
        q->mUnk_18(q, 0);
        r = func_020b4acc();
        e = &data_0217d3f4->mUnk_874[i];
        e->mUnk_00 = &data_0217d3f4->mUnk_834[i];
        e->mUnk_04 = b;
        e->mUnk_08 = r;
        e->mUnk_0c = 0;
    }
    func_021281b4();
    data_0217d3f4->mUnk_00 = 1;
    data_0217d3f4->mUnk_04 = 0;
    data_0217d3f4->mUnk_08 = 0;
    data_0217d3f4->mUnk_0c = 0;
    data_0217d3f4->mUnk_10 = 0;
    data_0217d3f4->mUnk_14 = 1;
    data_0217d3f4->mUnk_24 = 0;
    data_0217d3f4->mUnk_28 = 0;
    data_0217d3f4->mUnk_1c = 0;
    data_0217d3f4->mUnk_20 = 0;
    data_0217d3f4->mUnk_8a8[0] = 7;
    data_0217d3f4->mUnk_8a8[1] = 0x10;
    data_0217d3f4->mUnk_8b0 = 0x10;
    return c;
}
#pragma thumb off
