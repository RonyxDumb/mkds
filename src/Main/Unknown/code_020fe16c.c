#include "Main/Unknown/code_020fe16c.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_020fd83c.h"
#include "Main/Unknown/code_020f2dac.h"
#include "Main/Unknown/code_020f5d6c.h"
#include "Main/Unknown/code_020f9000.h"

void func_020fe16c(Unk020fdae8 *e) {
    s32 v;

    if (e->mUnk_130 != 0) {
        func_020f2df0((Unk0206bcb0 *) e, 0x385, 0xff8, 0x733, (u32 *) &v);
    } else {
        func_020f2df0((Unk0206bcb0 *) e, 0x47b, 0xf91, e->mUnk_134, (u32 *) &v);
    }
    if (e->mUnk_000.mUnk_74 & 0x10) {
        func_020f91fc((Unk0206bcb0 *) e, 0xe5);
    }
    if ((e->mUnk_000.mUnk_74 & 0x8) == 0) {
        return;
    }
    if (e->mUnk_000.mUnk_74 & 0x3) {
        return;
    }
    if (e->mUnk_130 != 0) {
        e->mUnk_000.mUnk_5c.y *= 2;
    }
    func_02109060(&e->mUnk_000.mUnk_00, 0xda);
    func_020f6a6c((Unk0206bcb0 *) e, &v);
    if ((e->mUnk_000.mUnk_74 & 0x180000) == 0) {
        e->mUnk_000.mUnk_120 = (void (*)(Unk020f41c4_A *)) func_020fdae8;
    }
    e->mUnk_194 = 1;
    e->mUnk_196 = 1;
}
