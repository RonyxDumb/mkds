#include "01/code_02199e1c.h"

void func_ov001_02199e3c(void) {
    Unk020b4934 *a;
    Unk020b47d8 *b;
    Unk020b4a44 *c;

    func_020b4934(&a, func_0204799c(data_ov001_021a866c));
    func_020b47d8(&b, func_0204799c(data_ov001_021a8688));
    func_020b4a44(&c, func_0204799c(data_ov001_021a86a0));
    data_ov001_021a9bec->mUnk_2c = func_0204799c(data_ov001_021a86bc);
    data_ov001_021a9bec->mUnk_30 = func_0204799c(data_ov001_021a86d8);
    func_020b49bc(&data_ov001_021a9bec->mUnk_24, func_0204799c(data_ov001_021a86f4));
    func_020b48b4(&data_ov001_021a9bec->mUnk_20, func_0204799c(data_ov001_021a8714));
    func_020b4a44(&data_ov001_021a9bec->mUnk_28, func_0204799c(data_ov001_021a8734));
    func_02016468(4, 0, a->mUnk_14, a->mUnk_10);
    func_02016468(8, 0, b->mUnk_0c, b->mUnk_08);
    func_02016468(15, 0, c->mUnk_0c, 0x100);
    func_02016468(0x23, 0, data_ov001_021a9bec->mUnk_24->mUnk_14, data_ov001_021a9bec->mUnk_24->mUnk_10);
    func_02016468(0x1e, 0, data_ov001_021a9bec->mUnk_28->mUnk_0c, data_ov001_021a9bec->mUnk_28->mUnk_08);
}

void func_ov001_02199e1c(void) {
    int iVar1;
    iVar1 = func_02036c5c();
    if (iVar1 != 0) {
        *(u32 *) (*((int *) ((u32) (&data_ov001_021a9bec))) + 4) = 1;
    }
    return;
}
