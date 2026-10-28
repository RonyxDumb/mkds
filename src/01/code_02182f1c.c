#include "01/code_02182f1c.h"

void func_ov001_02182f1c(Unk02181c3c *p0, Unk0206bcb0 *p1) {
    p0->mUnk_0ac = 0x1e;
    p0->mUnk_000.mUnk_04.x = p1->mUnk_80.x;
    p0->mUnk_000.mUnk_04.y = p1->mUnk_80.y + 0xc000;
    p0->mUnk_000.mUnk_04.z = p1->mUnk_80.z;
    p0->mUnk_000.mUnk_10.y = 0x3000;
    p0->mUnk_0f8 = 1;
    p0->mUnk_0b0 = 0x99a;
    p0->mUnk_0a0 = 0x1f;
    p0->mUnk_000.mUnk_02 = p0->mUnk_000.mUnk_02 | data_ov001_021a6574;
    p0->mUnk_0fc = func_0208b7bc(0x3f5, &p0->mUnk_000.mUnk_04);
    p0->mUnk_100 = 0xd;
}
