#include "Main/Unknown/code_020ffdd4.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_020ea000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0215a000.h"

Unk02100004 *func_02100004(void) {
    Unk02100004 *p;

    p = func_02036bec(func_020364e0(func_020364e8()), 0x40);
    {
        Unk02100004 v1 = {0};

        *p = v1;
    }
    return p;
}

Unk020fffa8 *func_020fffa8(void) {
    Unk020fffa8 *p;

    p = func_02036bec(func_020364e0(func_020364e8()), 0x28);
    data_0217c624 = p;
    *p = data_0215a12c;
    func_020e6f50(&data_0217c624);
    return data_0217c624;
}

Unk020fff4c *func_020fff4c(void) {
    Unk020fff4c *p;

    p = func_02036bec(func_020364e0(func_020364e8()), 0x2c);
    data_0217c62c = p;
    *p = data_0215a100;
    func_020d49d8(&data_0217c62c);
    return data_0217c62c;
}

void func_020ffeb8(void *a, Unk020ffb1c *e, void *c, s32 d) {
    Unk02012f58 *q;
    s32 v;

    q = &e->mUnk_00.mUnk_28;
    v = (u16) (-(s32) e->mUnk_a6) >> 4;
    func_02146d28((s32 *) q, data_0215d4b4[v * 2], data_0215d4b4[v * 2 + 1]);
    q->mUnk_24.x = e->mUnk_00.mUnk_04.x >> 4;
    q->mUnk_24.y = e->mUnk_00.mUnk_04.y >> 4;
    q->mUnk_24.z = e->mUnk_00.mUnk_04.z >> 4;
    func_020ea8a8(data_0217c628, q, &e->mUnk_00.mUnk_1c, d);
}

// non-matching: the table-row address after the 64-bit product-and-sum differs in
// register numbering and scheduling only - this build loads the high word of
// q->mUnk_00 into r1 and the constant 6 into r2 (umull r3,ip,r1,r2;
// mla r6,r1,r2,r3, table base loaded before the test of n) where the original
// uses r2 for the high word and r1 for 6 (umull r3,ip,r2,r1; mla r6,r3,r1,r2,
// base loaded after `cmp r4,#0`); 13 words from +0x70, 0xe4 bytes in both.
void func_020ffdd4(Unk020e6fd4 *v1) {
    Unk020f41c4_B *q;
    void **arr;
    Unk020ffb1c *e;
    u16 *v2;
    s32 n, i;

    n = v1->mUnk_04;
    arr = v1->mUnk_00;
    for (i = 0; i < n; i++) {
        e = arr[i];
        if (e->mUnk_00.mUnk_80.mUnk_0e != 1) {
            return;
        }
    }
    q = func_020d22d0();
    q->mUnk_00 = q->mUnk_08 * q->mUnk_00 + q->mUnk_10;
    v2 = (u16 *) data_0215a0a8[(u16) (((u64) (u32) (q->mUnk_00 >> 32) * 6) >> 32)];
    for (i = 0; i < n; i++) {
        e = arr[i];
        e->mUnk_a8 = e->mUnk_b4[v2[i]];
        e->mUnk_00.mUnk_80.mUnk_10 = 0;
        e->mUnk_00.mUnk_80.mUnk_12 = 1;
    }
}
