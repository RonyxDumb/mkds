#include "00/code_02186634.h"
#include "code_0214d018.h"
#include "code_02139f70.h"

s32 func_ov000_02186634(Unk021868a4Entry *a, s32 b, const u8 *c, char *d, s32 e) {
    const u8 *f = func_ov000_021866b8(a, b, c);
    if (f == 0) {
        return 0;
    }
    if ((s32) func_0213a434(f) >= e) {
        return 0;
    }
    func_0213a2d0(d, f);
    return 1;
}

s32 func_ov000_02186674(Unk021868a4Entry *a, s32 b, const u8 *c, char *d, u32 e) {
    const u8 *f = func_ov000_021866b8(a, b, c);
    u32 g;
    if (f == 0) {
        return 0;
    }
    g = func_ov000_021881d0(f, func_0213a434(f), d, e);
    if (g != -1 && g < e) {
        d[g] = 0;
    }
    return g;
}

void *func_ov000_021866b8(Unk021868a4Entry *a, s32 b, const u8 *c) {
    s32 e;
    for (e = 0; e < b; e++) {
        if (a[e].mFirst == 0) {
            break;
        }
        if (func_0213a074(c, a[e].mFirst) == 0) {
            return a[e].mSecond;
        }
    }
    return 0;
}

// non-matching: the two line pointers of the second loop are swapped, r4 and r5 (original: the first in r5, the second in r4); 9 words
// differ only by that register choice
s32 func_ov000_021866fc(Unk021868a4Entry *a, s32 b, s32 c, const u8 *d) {
    u8 *e;
    u8 *f;
    Unk021868a4 g;
    u8 *j;
    s8 *h;
    s8 *i;
    g.mEntries = a;
    g.mCapacity = b;
    g.mCount = 0;
    func_0214d168(a, 0, b * 8);
    e = (u8 *) func_02139f70(d, data_ov000_021b1230);
    if (e == 0) {
        return 0;
    }
    f = e + 4 + func_0213a434(e + 4);
    i = (s8 *) func_02139f70(d, data_ov000_021b1238);
    if (i == 0) {
        return 0;
    }
    h = i + 1;
    h[3] = 0;
    if (func_ov000_021868a4(&g, data_ov000_021b123c, h) != 1) {
        return 0;
    }
    if (c == 1 || func_0213a038((const u8 *) h, data_ov000_021b1248, 3) != 0) {
        if (func_ov000_021868a4(&g, data_ov000_021b124c, e + 4) != 1) {
            return 0;
        }
        return 1;
    }
    i = (s8 *) func_02139f70((const u8 *) (h + 4), data_ov000_021b1258);
    if (i == 0) {
        return 0;
    }
    h = i + 2;
    while (h[0] != 0xd && h[1] != 0xa) {
        i = (s8 *) func_02139f70((const u8 *) h, data_ov000_021b125c);
        if (i == 0) {
            break;
        }
        i[0] = i[1] = 0;
        j = (u8 *) (i + 2);
        i = (s8 *) func_02139f70(j, data_ov000_021b1258);
        if (i == 0) {
            break;
        }
        i[0] = i[1] = 0;
        if (func_ov000_021868a4(&g, h, j) != 1) {
            return 0;
        }
        h = (s8 *) (j + func_0213a434(j) + 2);
    }
    j = e + 4;
    if (j < f) {
        do {
            i = (s8 *) func_02139f70(j, data_ov000_021b1260);
            if (i == 0) {
                break;
            }
            i[0] = 0;
            h = i + 1;
            i = (s8 *) func_02139f70((const u8 *) h, data_ov000_021b1264);
            if (i == 0) {
                i = (s8 *) func_02139f70((const u8 *) h, data_ov000_021b1258);
            }
            if (i != 0) {
                i[0] = 0;
            }
            if (func_ov000_021868a4(&g, j, h) != 1) {
                return 0;
            }
            j = (u8 *) h + func_0213a434((const u8 *) h) + 1;
        } while (j < f);
    }
    return 1;
}
