#include "Main/Unknown/code_020ca6c4.h"
#include "Main/Unknown/code_020ca670.h"
#include "Main/Unknown/code_020caba4.h"
#include "Main/Unknown/code_02023000.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_020b47b4.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020ca820.h"
#include "Main/Unknown/unk_0217b000.h"

void func_020ca808(Unk02180728 *a, void *b, void *c, s32 d, s32 e) {
    a->mUnk_00 = b;
    a->mUnk_04 = c;
    a->mUnk_08 = d;
    a->mUnk_0c = e;
}

u32 func_020ca7e0(Unk02180728 *a, s32 b, s32 c, u32 d, u32 e, void *f) {
    return func_02024340(a, b, c, d, e, f);
}

#pragma thumb on
#pragma optimize_for_size on
void func_020ca6c4(void) {
    Unk0217b438 *p;

    data_0217b438 = func_02036bec(func_020ca820(), 0x6c);
    data_0217b438->mUnk_00 = 0;
    data_0217b438->mUnk_04 = 1;
    data_0217b438->mUnk_08 = 0;
    data_0217b438->mUnk_0c = 0;
    func_020cac9c();
    data_0217b438->mUnk_24 = 0;
    data_0217b438->mUnk_10 = 0;
    data_0217b438->mUnk_14 = 0;
    data_0217b438->mUnk_18 = 0;
    data_0217b438->mUnk_28 = 3;
    func_020b4a7c(&data_0217b438->mUnk_60, func_020b47c0("choises_s_b.NCLR"));
    func_020b496c(&data_0217b438->mUnk_64, func_020b47c0("choises_s_b.NCGR"));
    func_020b4810(&data_0217b438->mUnk_68, func_020b47c0("choises_s_3.NSCR"));
    data_0217b438->mUnk_2c = func_020b403c(2);
    func_02023408(&data_0217b438->mUnk_30, data_0217b438->mUnk_64->mUnk_14, 0x20, 0xc, 4);
    p = data_0217b438;
    func_020ca808(&p->mUnk_50, &p->mUnk_30, p->mUnk_2c, func_020b4acc(), 0);
    {
        s32 v[3] = {2, 0, 1};
        s32 i;

        for (i = 0; i < data_0217b438->mUnk_28; i++) {
            func_020ca7e0(&data_0217b438->mUnk_50, 0x90, i * 16 + 9, 12, 0x412,
                          func_020b3f7c(func_020b47c0("emblem.bmg"), v[i]));
        }
    }
}
#pragma thumb off
