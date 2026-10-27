#include "Main/Unknown/code_020dac74.h"
#include "Main/Unknown/code_01ffdee4.h"
#include "Main/Unknown/code_020d7000.h"
#include "code_02147cd8.h"

void func_020dac74(Unk020da494 *p) {
    u32 f;
    Vec3 v;
    Vec3 w;
    Vec3 x;
    if (p->mUnk_f0 < 0xa || (p->mUnk_f0 >= 0x14 && p->mUnk_f0 < 0x1e)) {
        if (p->mUnk_f0 == 0 || p->mUnk_f0 == 0x14) {
            p->mUnk_102--;
            if (p->mUnk_102 < 0) {
                p->mUnk_102 = 3;
                p->mUnk_104 = p->mUnk_104 == 0;
            }
        }
    }
    p->mUnk_10.y -= 0x400;
    p->mUnk_04.y += p->mUnk_10.y;
    v = p->mUnk_04;
    v.y += 0xa000;
    if (func_01ffdee4(&v, 0, 0, 0xa000, 8, -2, &w, &x, 0, &f, 0, 0, 0, 0) != 0) {
        func_02148504(&p->mUnk_04, &w, &p->mUnk_04);
        p->mUnk_10.y = 0;
        if ((f & 0x1e34ef) != 0) {
            func_020d7b88(&x, &p->mUnk_b4);
            p->mUnk_02 &= ~1;
        }
    }
    func_020d759c(&p->mUnk_a4, &p->mUnk_b4, &p->mUnk_a4, p->mUnk_f8);
    if (p->mUnk_f8 > 0xb4) {
        p->mUnk_f8 = 0xb4;
    }
}
