#include "Main/Unknown/code_020e4ea8.h"

#include "Main/Unknown/unk_02158000.h"
#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e6000.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/unk_0217b000.h"

Unk020e50dc *func_020e50dc(void) {
    Unk020e50dc *p;
    p = func_02036bec(func_020364e0(func_020364e8()), 0x40);
    *p = *(Unk020e50dc *) data_02159070;
    return p;
}

Unk020e5080 *func_020e5080(void) {
    Unk020e5080 *p;
    p = func_02036bec(func_020364e0(func_020364e8()), 0x2c);
    data_0217b7f8 = p;
    *p = *(Unk020e5080 *) data_02159044;
    func_020d49d8(&data_0217b7f8);
    return data_0217b7f8;
}

Unk020e5024 *func_020e5024(void) {
    Unk020e5024 *p;
    p = func_02036bec(func_020364e0(func_020364e8()), 0x2c);
    data_0217b7fc = p;
    *p = *(Unk020e5024 *) data_02159018;
    func_020d49d8(&data_0217b7fc);
    return data_0217b7fc;
}

Unk020e4fc8 *func_020e4fc8(void) {
    Unk020e4fc8 *p;
    p = func_02036bec(func_020364e0(func_020364e8()), 0x28);
    data_0217b7f4 = p;
    *p = *(Unk020e4fc8 *) data_02158ff0;
    func_020e6f50(&data_0217b7f4);
    return data_0217b7f4;
}

void func_020e4fb0(void) {
    func_020e6a18(data_0217b7f0);
}

void func_020e4ea8(u32 param_1, Unk020e43a8 *p, u32 param_3, u16 param_4) {
    Unk020e6488 *q;
    s32 neg;
    u32 v;

    if (p->mUnk_80.mUnk_0e == 0) {
        Unk02012f58 *r;
        neg = p->mUnk_64 & 1;
        r = func_020e6cf8(&p->mUnk_04);
        q = data_0217b7f0;
        q->mUnk_14 = q->mUnk_14 | 0xc0;
        data_0217b800 = p->mUnk_1c;
        if (neg) {
            data_0217b800.x = -data_0217b800.x;
        }
        func_020e67c4(q, r, &data_0217b800, 0, param_4);
    } else {
        Unk02012f58 *r;
        neg = p->mUnk_64 & 1;
        v = *(u16 *) &p->mUnk_a0.mUnk_0c.x;
        r = func_020e6cf8(&p->mUnk_04);
        q = data_0217b7f0;
        q->mUnk_14 = q->mUnk_14 | 0xc0;
        data_0217b800 = p->mUnk_1c;
        if (neg) {
            data_0217b800.x = -data_0217b800.x;
        }
        func_020e66e4(q, r, v, &data_0217b800, 0, param_4);
    }
}
