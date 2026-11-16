#include "00/code_0219981c.h"
#include "00/GameSpy/darray.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "string.h"
#include "code_02134398.h"
#include "00/code_021a3678.h"
#include "00/code_021a3690.h"
#include "00/code_02197b34.h"
#include "00/code_02197ddc.h"
#include "00/GameSpy/gt2Callback.h"
#include "00/code_021985ec.h"
#include "00/code_021988e8.h"
#include "00/code_02198a8c.h"
#include "00/code_02199a00.h"
#include "00/code_02199a0c.h"
#include "00/code_0219a014.h"
#include "code_021382a8.h"
#include "Main/Unknown/code_02133000.h"

u32 func_ov000_021998d8(Gt2Connection *a, s32 b, u32 c, const u8 *d, s32 e, s32 *f) {
    Unk0219981cEntry g;
    s32 h;
    s32 i;
    Unk0219981cEntry *j;
    h = DarrayGetCount(a->field5C);
    for (i = 0; i < h; i++) {
        j = DarrayGetElement(a->field5C, i);
        if (j->fieldC == c) {
            *f = 0;
            return 1;
        }
        if (func_ov000_0219a014(j->fieldC, c) > 0) {
            break;
        }
    }
    if (GetBufferUnusedSize(&a->field44) < e) {
        *f = 1;
        return 1;
    }
    g.field0 = a->field44.mLength;
    g.field4 = e;
    g.field8 = b;
    g.fieldC = c;
    DarrayInsertSorted(a->field5C, &g, func_ov000_02199a00);
    if (h + 1 != DarrayGetCount(a->field5C)) {
        *f = 1;
        return 1;
    }
    AppendBufferBytes(&a->field44, d, e);
    if (h == 0) {
        if (func_ov000_02198ba8(a, a->field66, c - 1) == FALSE) {
            return 0;
        }
    } else {
        j = DarrayGetElement(a->field5C, h);
        if (j->fieldC == c) {
            j = DarrayGetElement(a->field5C, h - 1);
            if ((u16) func_ov000_0219a014(c, j->fieldC) > 1) {
                if (func_ov000_02198ba8(a, j->fieldC + 1, c - 1) == FALSE) {
                    return 0;
                }
            }
        }
    }
    *f = 0;
    return 1;
}

void func_ov000_02199878(Gt2Connection *a, Unk0219981cEntry *b, s32 c) {
    s32 d = 0;
    s32 e = b->field0;
    s32 f = b->field4;
    s32 g;
    s32 i;
    Unk0219981cEntry *h;
    DarrayRemove(a->field5C, c);
    g = DarrayGetCount(a->field5C);
    for (i = 0; i < g; i++) {
        h = DarrayGetElement(a->field5C, i);
        if (h->field0 > e) {
            h->field0 -= f;
            if (d <= h->field0 + h->field4) {
                d = h->field0 + h->field4;
            }
        }
    }
    RemoveBufferBytes(&a->field44, e, f);
}

u32 func_ov000_0219981c(Gt2Connection *a) {
    s32 b;
    Unk0219981cEntry *c;
top:
    for (b = DarrayGetCount(a->field5C) - 1; b >= 0; b--) {
        c = DarrayGetElement(a->field5C, b);
        if (c->fieldC == a->field66) {
            if (func_ov000_02199a0c(a, c->field8, a->field44.mData + c->field0, c->field4) == 0) {
                return 0;
            }
            func_ov000_02199878(a, c, b);
            goto top;
        }
    }
    return 1;
}
