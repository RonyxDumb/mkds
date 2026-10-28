#include "Main/Unknown/code_020f5b84.h"

#include "Main/Unknown/code_020fe000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f1180.h"
#include "Main/Unknown/code_020f11f0.h"
#include "Main/Unknown/code_020f1d70.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f5d6c.h"
#include "Main/Unknown/code_020ee684.h"

void func_020f5b84(Unk020f5d6c *a) {
    func_020f2228(&a->mUnk_000.mUnk_000, 0x8800);
    if (!(a->mUnk_000.mUnk_000.mUnk_000.mUnk_74 & 1)) {
        func_0210ddf4(&data_0217d294, a->mUnk_000.mUnk_000.mUnk_000.mUnk_d4 & ~0xc000001f, func_020f5fb8, a, 0);
    }
    if (a->mUnk_000.mUnk_000.mUnk_000.mUnk_74 & 1) {
        return;
    }
    if (a->mUnk_23c.mUnk_04 > 0x10) {
        if (func_020f11f0((u32) a, 0) == 0) {
            return;
        }
        a->mUnk_23c.mUnk_10 = 4;
        a->mUnk_23c.mUnk_12 = 1;
        if (!(a->mUnk_000.mUnk_000.mUnk_000.mUnk_74 & 0x8000000)) {
            return;
        }
        func_020fe71c(1, a->mUnk_228->mUnk_1f8, a->mUnk_000.mUnk_000.mUnk_000.mUnk_4e);
        return;
    }
    if (a->mUnk_23c.mUnk_04 > 4) {
        if (func_020f1180(a, 0) == 0) {
            return;
        }
        a->mUnk_23c.mUnk_10 = 4;
        a->mUnk_23c.mUnk_12 = 1;
        if (!(a->mUnk_000.mUnk_000.mUnk_000.mUnk_74 & 0x8000000)) {
            return;
        }
        func_020fe71c(1, a->mUnk_228->mUnk_1f8, a->mUnk_000.mUnk_000.mUnk_000.mUnk_4e);
    }
}
