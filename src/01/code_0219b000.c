#include "01/code_0219b000.h"

void func_ov001_0219b000(void) {
    Unk020b4934 *a;
    Unk020b4a44 *b;
    Unk020b4934 *c;
    Unk020b4a44 *d;
    Unk020b4934 *e;
    Unk020b4a44 *f;
    Unk020b47d8 *g;
    u16 *q;

    a = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    f = 0;
    g = 0;
    func_020b4934(&e, func_0204799c(data_0216cd24));
    func_020b4a44(&f, func_0204799c(data_0216cce8));
    func_020b47d8(&g, func_0204799c(data_0216cd10));
    data_ov001_021a9bf0->mUnk_28 = func_02036bec(data_ov001_021a9bf0->mUnk_2c, 0x800);
    data_ov001_021a9bf0->mUnk_04 = func_0204799c(data_0216ccdc);
    data_ov001_021a9bf0->mUnk_08 = func_0204799c(data_0216cd08);
    func_020b49bc(&a, func_0204799c(data_0216cce0));
    func_020b48b4(&data_ov001_021a9bf0->mUnk_00, func_0204799c(data_0216cd30));
    func_020b4a44(&b, func_0204799c(data_0216ccf4));
    data_ov001_021a9bf0->mUnk_10 = func_0204799c(data_0216cc88);
    data_ov001_021a9bf0->mUnk_14 = func_0204799c(data_0216cca0);
    func_020b49bc(&c, func_0204799c(data_0216ccb4));
    func_020b48b4(&data_ov001_021a9bf0->mUnk_0c, func_0204799c(data_0216ccac));
    func_020b4a44(&d, func_0204799c(data_0216ccf0));
    q = b->mUnk_0c;
    func_02016468(4, 0, e->mUnk_14, e->mUnk_10);
    func_02016468(15, 0, f->mUnk_0c, 0x60);
    func_02016468(8, 0, g->mUnk_0c, g->mUnk_08);
    func_02016468(8, 0x800, data_ov001_021a9bf0->mUnk_28, 0x800);
    func_02016468(0x13, 0, a->mUnk_14, a->mUnk_10);
    func_02016468(14, 0, b->mUnk_0c, 0x1a0);
    func_02016468(14, 0x1c0, q + 0xe0, 0x40);
    func_02016468(0x23, 0, c->mUnk_14, c->mUnk_10);
    func_02016468(0x1e, 0, d->mUnk_0c, d->mUnk_08);
}
