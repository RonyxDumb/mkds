#include "Main/Unknown/code_020dadfc.h"
#include "Main/Unknown/code_020d8c74.h"
#include "Main/Unknown/code_020d8cac.h"

void func_020dadfc(Unk020da494 *p) {
    if (p->mUnk_f0 >= 0xa && (p->mUnk_f0 < 0x14 || p->mUnk_f0 >= 0x1e)) {
        func_020d8cc8(&p->mUnk_cc);
    }
    func_020d8c74(&p->mUnk_cc, &p->mUnk_04);
    if (p->mUnk_c4 == 0x1000 && p->mUnk_c8 == 0) {
        return;
    }
    p->mUnk_c8 += (s32) (((s64) (0x1000 - p->mUnk_c4) * 0x200) >> 12);
    p->mUnk_c8 = (s32) (((s64) p->mUnk_c8 * 0xd99) >> 12);
    p->mUnk_c4 += p->mUnk_c8;
    if (p->mUnk_c4 > 0xfd7 && p->mUnk_c4 < 0x1029 && p->mUnk_c8 > -0x29 && p->mUnk_c8 < 0x29) {
        p->mUnk_c4 = 0x1000;
        p->mUnk_c8 = 0;
    }
}
