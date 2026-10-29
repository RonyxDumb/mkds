#include "Main/Unknown/code_020b3b08.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0205d000.h"
#include "Main/Unknown/code_0205dc7c.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217b35c.h"

void func_020b3cd8(void) {
    Unk021759c0 *d = data_021759c0;
    s32 a[8];
    s32 b[8];
    u16 i;
    u16 j;
    s32 n = -1;
    s32 g;
    s32 k;
    s32 m;
    s32 v;
    s32 f;
    Unk0217aa1c_00 *q;

    if (d->mUnk_08 == 1) {
        return;
    }
    if (d->mUnk_08 == 4) {
        return;
    }
    for (i = 0; i < (u32) data_021759c0->mUnk_3d0; i++) {
        if (data_021759c0->mUnk_1c == 1 || data_021759c0->mUnk_08 == 2) {
            f = 0;
            if ((u32) data_021759c0->mUnk_70[i].mUnk_00 <= 3) {
                if ((1 << data_021759c0->mUnk_70[i].mUnk_00) & 0xd) {
                    f = 1;
                }
            }
            g = f != 0 ? 1 : 0;
            k = func_0205dc7c(i);
            m = func_0205db28();
            v = data_0217aa1c->mUnk_000[m][func_0205dc7c(k)].mUnk_05;
            a[i] = (v << 4) + (g << 3) + 8 - func_0203c8dc(i);
        } else {
            f = 0;
            if ((u32) data_021759c0->mUnk_70[i].mUnk_00 <= 3) {
                if ((1 << data_021759c0->mUnk_70[i].mUnk_00) & 0xd) {
                    f = 1;
                }
            }
            g = f != 0 ? 1 : 0;
            k = func_0205dc7c(i);
            m = func_0205db28();
            q = &data_0217aa1c->mUnk_000[m][func_0205dc7c(k)];
            v = q->mUnk_00;
            a[i] = (v << 4) + (g << 3) + 8 - func_0203c8dc(i);
        }
    }
    for (i = 0; i < (u32) data_021759c0->mUnk_3d0; i++) {
        b[i] = i;
        a[i] = a[i] * n;
    }
    func_020ae770(b, a, data_021759c0->mUnk_3d0);
    for (i = 0; i < (u32) data_021759c0->mUnk_3d0; i++) {
        for (j = 0; j < (u32) data_021759c0->mUnk_3d0; j++) {
            if (i == b[j]) {
                func_0205d76c(i, j + 1);
                break;
            }
        }
    }
}

// non-matching: the byte reads from the table at 0x144 are made in the original through a separate pointer add
// (add r0, r0, #0 / add r0, r0, #4, then ldrb [r0, #2]); the second condition is kept as a value in a register
// (mov r2, #1 ... movne r2, #0; cmp r2, #0) instead of branching
static inline Unk0217aa1c_144_00 *func_020b3b58_inline(s32 j) {
    return &data_0217aa1c->mUnk_144[func_0205db28()].mUnk_00[j];
}

static inline Unk0217aa1c_144 *func_020b3b58_inline2(void) {
    return &data_0217aa1c->mUnk_144[func_0205db28()];
}

void func_020b3b58(void) {
    Unk021759c0 *d = data_021759c0;
    s32 a;
    s32 b;
    s32 c;
    u16 i;
    Unk0217aa1c_144_00 *q;

    if (d->mUnk_58 == 0) {
        return;
    }
    if (d->mUnk_1c == 1 || d->mUnk_08 == 2) {
        a = func_020b3b58_inline(0)->mUnk_02;
    } else {
        q = &data_0217aa1c->mUnk_144[func_0205db28()].mUnk_00[0];
        a = q->mUnk_00;
    }
    d = data_021759c0;
    c = 1;
    if (d->mUnk_1c != 1 && d->mUnk_08 != 2) {
        c = 0;
    }
    if (c) {
        b = func_020b3b58_inline(1)->mUnk_02;
    } else {
        b = func_020b3b58_inline2()->mUnk_00[1].mUnk_00;
    }
    if (a > b) {
        func_0205d6d0(0);
        return;
    }
    if (b > a) {
        func_0205d6d0(1);
        return;
    }
    for (i = 0; i < (u32) data_021759c0->mUnk_3d0; i++) {
        if (func_0203c8dc(i) == 1) {
            break;
        }
    }
    func_0205d6d0(data_021759c0->mUnk_70[i].mUnk_04);
}

void func_020b3b08(void) {
    data_0217b35c = func_02036bec(func_020364e0(func_020364e8()), 0x10);
    data_0217b35c->mUnk_00 = 0;
    data_0217b35c->mUnk_04 = 0;
    data_0217b35c->mUnk_08 = 0;
    data_0217b35c->mUnk_0c = 0;
}
