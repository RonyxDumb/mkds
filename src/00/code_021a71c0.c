#include "00/code_021a71c0.h"
#include "00/code_021a70b0.h"
#include "00/code_021a71a4.h"
#include "00/unk_021b5000.h"

u8 *func_ov000_021a71c0(Unk021a6fa8 *param_1, Unk021b49b8 *param_2) {
    u8 *a;
    Unk021a71c0 *b;
    Unk021a722a *c;

    param_1->mUnk_73 = param_2->mUnk_00;
    param_1->mUnk_72 = param_2->mUnk_01;
    a = (u8 *) &param_1->mUnk_80;
    if (param_2->mUnk_02 != 0) {
        b = &param_1->mUnk_80;
        param_1->mUnk_64 = a;
        b->mUnk_fc = param_2->mUnk_04;
        a = func_ov000_021a7154(b->mUnk_114, &b->mUnk_00, &param_2->mUnk_10);
        a = func_ov000_021a71a4(a, &param_1->mUnk_3c, param_2->mUnk_02);
        a = func_ov000_021a71a4(a, &param_1->mUnk_50, param_2->mUnk_08);
        b->mUnk_10a = param_2->mUnk_0e;
        b->mUnk_10c.mUnk_04 = 0;
        b->mUnk_10c.mUnk_00 = b->mUnk_10c.mUnk_04;
    }
    if (param_2->mUnk_06 != 0) {
        c = (Unk021a722a *) a;
        param_1->mUnk_68 = a;
        c->mUnk_10c = param_1;
        a = func_ov000_021a7154(c->mUnk_110, &c->mUnk_00, &param_2->mUnk_14);
        a = func_ov000_021a71a4(a, &param_1->mUnk_48, param_2->mUnk_06);
        a = func_ov000_021a71a4(a, &param_1->mUnk_58, param_2->mUnk_0a);
        a = func_ov000_021a71a4(a, &c->mUnk_f8, param_2->mUnk_0c);
        c->mUnk_108 = 0;
        c->mUnk_104 = c->mUnk_108;
    } else {
        param_1->mUnk_68 = data_ov000_021b5fa4->mUnk_68;
    }
    return a;
}
