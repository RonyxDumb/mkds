#include "Main/Unknown/code_020e4e08.h"

#include "Main/Unknown/code_020e5000.h"
#include "Main/Unknown/code_020e5634.h"

void func_020e4e08(u32 param_1, Unk020e43a8 *p, u32 param_3, u32 param_4) {
    Unk020e4e08 s;

    if (p->mUnk_8e != 0 && p->mUnk_8e != 1) {
        return;
    }
    s.mUnk_00 = p->mUnk_04.y - p->mUnk_a0.mUnk_18.y;
    s.mUnk_00 = 0x1000 - (s.mUnk_00 >> 6);
    s.mUnk_04 = p->mUnk_04;
    s.mUnk_04.y = p->mUnk_f4.z + p->mUnk_100;
    func_020e5634((Unk020e516c *) &p->mUnk_c8, &s.mUnk_04);
    func_020e54e4((Unk020e516c *) &p->mUnk_c8, &s, 0, param_4);
}
