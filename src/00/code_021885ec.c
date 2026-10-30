#include "00/code_021885ec.h"
#include "00/code_02188008.h"
#include "00/code_021884e4.h"
#include "00/code_02188584.h"

void func_ov000_021885ec(void) {
    Unk021884e4 *p;
    void *q;

    p = (Unk021884e4 *) func_ov000_02188584(1);
    if ((p->mUnk_08 & 0x10) != 0) {
        q = (void *) func_ov000_02188584(0x10);
        p->mUnk_08 &= ~0x10;
        p->mUnk_04(0x10, q, 0xd18);
    }
    if ((p->mUnk_08 & 8) != 0) {
        q = (void *) func_ov000_02188584(8);
        p->mUnk_08 &= ~8;
        p->mUnk_04(8, q, 0xc);
    }
    if ((p->mUnk_08 & 4) != 0) {
        q = (void *) func_ov000_02188584(4);
        p->mUnk_08 &= ~4;
        p->mUnk_04(4, q, 0x58);
    }
    if ((p->mUnk_08 & 2) != 0) {
        q = (void *) func_ov000_02188584(2);
        p->mUnk_08 &= ~2;
        p->mUnk_04(2, q, 0x2300);
    }
    if ((p->mUnk_08 & 1) != 0) {
        p->mUnk_08 &= ~1;
        p->mUnk_04(1, p, 0x18);
    }
}
