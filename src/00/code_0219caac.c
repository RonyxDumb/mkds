#include "00/code_0219caac.h"

u32 func_ov000_0219caf4(void) {
    return *(u32 *) ((*(int *) &data_ov000_021b5664) + 0x20);
}

void func_ov000_0219caac(Unk021b565c *a, Unk02152500 *b, Unk0218f960 *c, u32 d, u32 e, void (*f)(), void *g) {
    data_ov000_021b565c = a;
    func_0214d168(a, 0, 0x264);
    data_ov000_021b565c->mUnk_00 = c;
    data_ov000_021b565c->mUnk_04 = 0;
    data_ov000_021b565c->mUnk_08 = d;
    data_ov000_021b565c->mUnk_0c = e;
    data_ov000_021b565c->mUnk_18 = f;
    data_ov000_021b565c->mUnk_1c = g;
    data_ov000_021b565c->mUnk_20 = b;
}
