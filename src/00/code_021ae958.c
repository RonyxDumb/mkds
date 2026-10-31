#include "00/code_021ae958.h"

void func_ov000_021ae958(const Unk021ae3f0 *param_1, const Unk021ae87c *param_2) {
    Unk021a998c *p;

    p = func_ov000_021af090(param_1, param_2);
    if (p != 0) {
        func_0200dd94();
        p->mUnk_08 = 0;
        if (p->mUnk_04 - 1 <= 1) {
            p->mUnk_04 = 0;
            func_0200df68(p->mUnk_00);
        }
    }
}
