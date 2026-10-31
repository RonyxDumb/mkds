#include "00/code_021a8994.h"
#include "00/code_021a8000.h"
#include "00/code_021a7bfc.h"
#include "00/code_021a8db8.h"
#include "00/code_021a911c.h"
#include "00/unk_021b5000.h"
#include "00/code_021a8960.h"
#include "code_0200fc8c.h"

// the original reloads the halfword at 0x70 for every test; a volatile view of the object is the only spelling found
u32 func_ov000_021a8994(Unk021a6fa8 *a) {
    u32 b = 0;
    u32 c;
    s32 d;
    volatile Unk021a6fa8 *v = a;
    if (func_ov000_021a8a80(a) != 0) {
        b |= 0x80;
    } else {
        if ((v->mUnk_70 & 0x40) != 0) {
            b |= 0x20;
        }
        if (a->mUnk_73 == 1 || (v->mUnk_70 & 4) != 0) {
            c = func_0200fca0();
            if ((s32) func_ov000_021a8960((int) a) > 0) {
                b |= 1;
            }
            if (func_ov000_021a8118(a) > 0) {
                b |= 8;
            }
            func_0200fcb4(c);
        }
        d = 1;
        if (a->mUnk_73 != 0 && a->mUnk_73 != 4) {
            d = 0;
        }
        if (d != 0) {
            if ((v->mUnk_70 & 4) != 0 && a->mUnk_08 != 4 && (b & 1) == 0) {
                v->mUnk_70 &= ~6;
            }
            if ((v->mUnk_70 & 2) == 0 && (v->mUnk_70 & 4) == 0) {
                b |= 0x40;
            }
        }
    }
    return b;
}
