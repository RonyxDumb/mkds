#include "Main/Unknown/code_020fe268.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_020f2dac.h"
#include "Main/Unknown/code_020f9000.h"
#include "Main/Unknown/unk_02159000.h"

s32 func_020fe268(Unk020edb8c *a, Unk020fdae8 *e) {
    func_020f9114((Unk0206bcb0 *) e);
    e->mUnk_000.mUnk_78 |= data_02159f3c;
    e->mUnk_134 = (s32) (((s64) a->mUnk_68 * 0x1ec) >> 12) + 0x333;
    if (e->mUnk_134 > 0xccd) {
        e->mUnk_134 = 0xccd;
    }
    if (a->mUnk_0c->mUnk_1ec & 0x20) {
        func_020f3150((Unk0206bcb0 *) e, a, 2, 0, 0x7800, 0x5000, 0x219a);
        e->mUnk_170 = 0x5a;
        e->mUnk_130 = 0;
        return e->mUnk_130;
    }
    if (a->mUnk_0c->mUnk_1ec & 0x10) {
        func_020f3150((Unk0206bcb0 *) e, a, 3, 1, 0x9800, 0x5000, 0x59a);
    } else {
        func_020f3150((Unk0206bcb0 *) e, a, 3, 1, 0x6000, 0x5000, 0x59a);
    }
    func_021090c4(e, 0xda, 0x7f, 0);
    e->mUnk_130 = 1;
    return e->mUnk_130;
}
