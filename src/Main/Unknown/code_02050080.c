#include "Main/Unknown/code_02050080.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_02043000.h"
#include "Main/Unknown/code_0204e000.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0217a000.h"

static inline u32 func_02050080_inline(void) {
    if (data_0217aa00 == 0) {
        return 0;
    }
    return data_0217aa00->mUnk_0000;
}

// non-matching: in the second half the original keeps the Unk0217aa00 pointer in ip and does the stores in pairs
// (two loads, then two stores); this source keeps it in r3 and alternates load and store.
u32 func_020501b0(u32 a) {
    u32 r = 0;
    Unk0217aa00_0ac *e;
    Unk0217aa00 *q;
    u32 b;

    if (a >= 4) {
        return 0;
    }
    if ((data_0217aa00->mUnk_0454 & 0x40) != 0) {
        b = r;
        if (func_02050080_inline() != 2) {
            b = 0;
        } else if (*(u16 *) 0x027ffc40 == 2) {
            b = 0;
        } else if (data_0217aa00->mUnk_00ac[a].mUnk_dc_0 != 0) {
            b = 1;
        }
        if (b != 0) {
            func_0204e074();
            r = 1;
        }
    } else {
        data_0217aa00->mUnk_043b = 0;
        data_0217aa00->mUnk_0438 = 0;
        e = &data_0217aa00->mUnk_00ac[a];
        data_0217aa00->mUnk_0436 &= ~1;
        if (e->mUnk_dc_0 != 0) {
            func_0214d1fc(e, data_0217aa00->mUnk_0024, 0xc0);
            func_0200ee58(data_0217aa00->mUnk_0024, 0xc0);
            q = data_0217aa00;
            q->mUnk_042c = e->mUnk_c0[0];
            q->mUnk_042d = e->mUnk_c0[1];
            q->mUnk_042e = e->mUnk_c0[2];
            q->mUnk_042f = e->mUnk_c0[3];
            q->mUnk_0430 = e->mUnk_c0[4];
            q->mUnk_0431 = e->mUnk_c0[5];
            q->mUnk_043c = e->mUnk_dc_1;
            r = 1;
        }
    }
    return r;
}

// non-matching: register choice only; the original keeps the zero in r2 and the func_02050080_inline value in r1,
// and the (1 << i) value in r4 with the loaded byte in r5, this source gives the reverse.
void func_02050080(void) {
    s32 r;
    u16 i;
    u16 n;

    r = 0;
    if (func_02050080_inline() != 0 && data_0217aa00->mUnk_0004 != 13) {
        r = 1;
    }
    if (r == 0) {
        return;
    }
    i = 0;
    n = 0;
    for (; i < 8; i++) {
        if (((1 << i) & data_0217aa00->mUnk_15f6) == 0) {
            data_0217aa00->mUnk_1e52[i].mUnk_00 = 0xffff;
        } else {
            data_0217aa00->mUnk_1e52[i].mUnk_00 = n;
            data_0217aa00->mUnk_1e8c[n] = i;
            data_0217aa00->mUnk_1e9c[n] = i;
            n++;
        }
    }
    for (; n < 8; n++) {
        data_0217aa00->mUnk_1e8c[n] = 0xffff;
        data_0217aa00->mUnk_1e9c[n] = 0xffff;
    }
    if (func_0205e0a0() == 2) {
        func_020431e4();
    } else {
        func_02043410();
    }
}
