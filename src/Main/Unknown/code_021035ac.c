#include "Main/Unknown/code_021035ac.h"

#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02103890.h"

void func_0210366c(Unk021035ac *p) {
    s32 i;
    s32 a;
    s32 b;
    s32 vb;
    s32 va;
    s32 j;
    s16(*q)[2] = p->mUnk_10;

    for (i = 0; i < 4; i++) {
        q[i][0] = 0;
        q[i][1] = 0;
    }
    for (i = 0; i < 4; i++) {
        a = p->mUnk_00[i][0];
        b = p->mUnk_00[i][1];
        if (a > 0) {
            if (a > 0x4cd) {
                va = (s32) (((s64) a * a) >> 12);
            } else {
                va = 0x171;
            }
        } else {
            if (a < 0x4cd) {
                va = -(s32) (((s64) a * a) >> 12);
            } else {
                va = -0x171;
            }
        }
        if (b > 0) {
            if (b > 0x4cd) {
                vb = (s32) (((s64) b * b) >> 12);
            } else {
                vb = 0x171;
            }
        } else {
            if (b < 0x4cd) {
                vb = -(s32) (((s64) b * b) >> 12);
            } else {
                vb = -0x171;
            }
        }
        for (j = 0; j < 4; j++) {
            if (i == j) {
                q[j][0] += (s32) (((s64) va * 12) >> 12);
                q[j][1] += (s32) (((s64) vb * 12) >> 12);
            } else {
                q[j][0] += (s32) (((s64) va * 8) >> 12);
                q[j][1] += (s32) (((s64) vb * 8) >> 12);
            }
        }
    }
    for (i = 0; i < 4; i++) {
        if (q[i][1] < 0) {
            q[i][1] = 0;
        }
    }
    p->mUnk_28 = 1;
}

void func_021035ac(int b2) {
    Unk021035ac *e;
    s32 i;
    s32 n;
    s32 a;
    s32 b;

    if (b2 != data_021759c0->mUnk_62) {
        return;
    }
    n = *(s32 *) data_0217c658;
    if (n == 0) {
        return;
    }
    a = *(s32 *) data_0217c644;
    b = *(s32 *) data_0217c650;
    if (b < a) {
        *(s32 *) data_0217c650 = a;
    }
    i = 0;
    if (n <= 0) {
        return;
    }
    do {
        e = &((Unk021035ac *) data_0217c654)[i];
        if (e->mUnk_28 == 0 && e->mUnk_24 == (void *) func_0210465c) {
            func_0210366c(e);
        }
        i++;
    } while (i < *(s32 *) data_0217c658);
}
