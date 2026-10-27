#include "Main/Unknown/code_020e5b88.h"

#include "Main/Unknown/code_020ec000.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_020e337c.h"

void func_020e5bd4(u32 param_1, Unk020e43a8 *p) {
    Unk0210b7a8 s;
    s32 n;

    *(u16 *) &p->mUnk_a0.mUnk_18 = *(u16 *) &p->mUnk_a0.mUnk_18 + 1;
    if ((*(u16 *) &p->mUnk_a0.mUnk_18 & 0x1f) == 0 && (p->mUnk_78 & 4) == 0) {
        if (p->mUnk_70 == data_0217ca6c[2].mUnk_20) {
            n = 2;
        } else if (p->mUnk_70 == data_0217ca6c[3].mUnk_20) {
            n = 3;
        } else {
            n = 4;
        }
        s.mUnk_00 = 0x163;
        s.mUnk_04 = (s32) &p->mUnk_04;
        s.mUnk_08 = n;
        s.mUnk_0c = func_020d4ef4(&p->mUnk_04);
        func_0210b7a8(&s);
    }
    func_02046b40((u32) &p->mUnk_80);
}

u8 func_020e5ba0(Unk020e43a8 *p, void *param_2, u8 *param_3, u8 *param_4) {
    if (func_020ec450(p, param_2, param_3) != 0) {
        func_020d26f8((int) p, (int) param_2);
    }
    return *param_4;
}

u8 func_020e5b88(Unk020e43a8 *p, void *param_2, u8 *param_3, u8 *param_4) {
    func_020ec41c(p, param_2, param_3);
    return *param_4;
}
