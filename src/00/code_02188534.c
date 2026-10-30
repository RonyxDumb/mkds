#include "00/code_02188534.h"
#include "00/code_021884d8.h"
#include "00/code_02188584.h"
#include "00/unk_021b4000.h"

void func_ov000_02188534(u8 a) {
    Unk021884e4 *p;
    Unk02188408 *q;

    p = (Unk021884e4 *) func_ov000_02188584(1);
    q = (Unk02188408 *) func_ov000_02188584(0x10);
    p->mUnk_09 = a;
    if (a < 0x10) {
        if (a > p->mUnk_16) {
            p->mUnk_16 = a;
            if (a > 7) {
                p->mUnk_15 = func_ov000_021884d8(q->mUnk_d0d);
                p->mUnk_14 = q->mUnk_444[q->mUnk_d13].mUnk_00;
            }
        }
    }
}
