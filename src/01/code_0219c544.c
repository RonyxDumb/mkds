#include "01/code_0219c544.h"

void func_ov001_0219c544(void) {
    Unk020b4934 *a;
    Unk020b4934 *b;
    Unk020b4a44 *c;
    Unk020b47d8 *d;

    a = 0;
    b = 0;
    c = 0;
    d = 0;
    func_020b4934(&b, func_0204799c(data_ov001_021a87b8));
    func_020b47d8(&d, func_0204799c(data_ov001_021a8794));
    func_020b4a44(&c, func_0204799c(data_ov001_021a87a8));
    data_ov001_021a9bf4->mUnk_40 = func_02036bec(data_ov001_021a9bf4->mUnk_44, 0x800);
    data_ov001_021a9bf4->mUnk_04 = func_0204799c(data_ov001_021a879c);
    data_ov001_021a9bf4->mUnk_08 = func_0204799c(data_ov001_021a87b0);
    func_020b48b4(&data_ov001_021a9bf4->mUnk_00, func_0204799c(data_ov001_021a87bc));
    data_ov001_021a9bf4->mUnk_10 = func_0204799c(data_ov001_021a8790);
    data_ov001_021a9bf4->mUnk_14 = func_0204799c(data_ov001_021a87a0);
    data_ov001_021a9bf4->mUnk_18 = func_0204799c(data_ov001_021a87ac);
    func_020b49bc(&a, func_0204799c(data_ov001_021a87a4));
    func_020b48b4(&data_ov001_021a9bf4->mUnk_0c, func_0204799c(data_ov001_021a87b4));
    func_020b4a44(&data_ov001_021a9bf4->mUnk_1c, func_0204799c(data_ov001_021a8798));
    data_ov001_021a9bf4->mUnk_20 = func_020b4018(0);
    data_ov001_021a9bf4->mUnk_24 = func_020b400c(0);
    data_ov001_021a9bf4->mUnk_28 = func_020b4030(0);
    data_ov001_021a9bf4->mUnk_2c = func_020b4000(0);
    func_02016468(0x17, 0, b->mUnk_14, b->mUnk_10);
    func_02016468(0x1f, 0, c->mUnk_0c, 0x20);
    func_02016468(0x1b, 0, d->mUnk_0c, d->mUnk_08);
    func_02016468(0x1b, 0x800, data_ov001_021a9bf4->mUnk_40, 0x800);
    func_02016468(0x23, 0, a->mUnk_14, a->mUnk_10);
    func_02016468(0x1e, 0, data_ov001_021a9bf4->mUnk_1c->mUnk_0c, data_ov001_021a9bf4->mUnk_1c->mUnk_08);
}
