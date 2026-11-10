#include "code_020169a4.h"

NNSiGfdLnkVramBlock *NNSi_GfdInitLnkVramBlockPool(NNSiGfdLnkVramBlock *p, u32 n) {
    u32 i;
    NNSiGfdLnkVramBlock *q;
    u32 m;

    m = n - 1;
    i = 0;
    if (m != 0) {
        q = p;
        do {
            p[i].mPBlkNext = &p[i + 1];
            p[i + 1].mPBlkPrev = q;
            i++;
            q++;
        } while (i < m);
    }
    p->mPBlkPrev = 0;
    (p + n)[-1].mPBlkNext = 0;
    return p;
}

s32 NNSi_GfdAddNewFreeBlock(NNSiGfdLnkVramBlock **a, NNSiGfdLnkVramBlock **b, u32 c, u32 d) {
    NNSiGfdLnkVramBlock *n;

    n = *b;
    if (n != 0) {
        *b = n->mPBlkNext;
    }
    if (n != 0) {
        n->mAddr = c;
        n->mSzByte = d;
        n->mPBlkPrev = 0;
        n->mPBlkNext = 0;
        if (*a != 0) {
            (*a)->mPBlkPrev = n;
        }
        n->mPBlkNext = *a;
        n->mPBlkPrev = 0;
        *a = n;
        return 1;
    }
    return 0;
}

s32 NNSi_GfdAllocLnkVram(NNSiGfdLnkVramBlock **a, NNSiGfdLnkVramBlock **b, u32 *c, u32 d) {
    return NNSi_GfdAllocLnkVramAligned(a, b, c, d, 0);
}

s32 NNSi_GfdAllocLnkVramAligned(NNSiGfdLnkVramBlock **a, NNSiGfdLnkVramBlock **b, u32 *c, u32 d, u32 e) {
    u32 addr;
    u32 need;
    u32 pad;
    NNSiGfdLnkVramBlock *best;
    NNSiGfdLnkVramBlock *n;
    NNSiGfdLnkVramBlock *t;
    NNSiGfdLnkVramBlock *prev;
    NNSiGfdLnkVramBlock *next;

    best = 0;
    for (n = *a; n != 0; n = n->mPBlkNext) {
        if (e > 1) {
            addr = (n->mAddr + (e - 1)) & ~(e - 1);
            pad = addr - n->mAddr;
            need = d + pad;
        } else {
            addr = n->mAddr;
            pad = 0;
            need = d;
        }
        if (n->mSzByte >= need) {
            best = n;
            break;
        }
    }
    if (best == 0) {
        goto fail;
    }
    if (pad != 0) {
        t = *b;
        if (t != 0) {
            *b = t->mPBlkNext;
        }
        if (t == 0) {
            goto fail;
        }
        t->mAddr = best->mAddr;
        t->mSzByte = pad;
        t->mPBlkPrev = 0;
        t->mPBlkNext = 0;
        if (*a != 0) {
            (*a)->mPBlkPrev = t;
        }
        t->mPBlkNext = *a;
        t->mPBlkPrev = 0;
        *a = t;
    }
    best->mSzByte -= need;
    best->mAddr += need;
    if (best->mSzByte == 0) {
        prev = best->mPBlkPrev;
        next = best->mPBlkNext;
        if (prev != 0) {
            prev->mPBlkNext = next;
        } else {
            *a = next;
        }
        if (next != 0) {
            next->mPBlkPrev = prev;
        }
        if (*b != 0) {
            (*b)->mPBlkPrev = best;
        }
        best->mPBlkNext = *b;
        best->mPBlkPrev = 0;
        *b = best;
    }
    *c = addr;
    return 1;
fail:
    *c = 0;
    return 0;
}

s32 NNSi_GfdFreeLnkVram(NNSiGfdLnkVramBlock **a, NNSiGfdLnkVramBlock **b, u32 c, u32 d) {
    u32 r[4];
    u32 *rp;
    NNSiGfdLnkVramBlock *n;
    NNSiGfdLnkVramBlock *next;
    NNSiGfdLnkVramBlock *t;
    NNSiGfdLnkVramBlock *prev;

    r[0] = c;
    r[1] = c + d;
    r[2] = c;
    r[3] = c + d;
    rp = r;
    for (n = *a; n != 0; n = next) {
        next = n->mPBlkNext;
        if (n->mAddr == rp[1]) {
            r[3] = n->mAddr + n->mSzByte;
            prev = n->mPBlkPrev;
            if (prev != 0) {
                prev->mPBlkNext = next;
            } else {
                *a = next;
            }
            if (next != 0) {
                next->mPBlkPrev = prev;
            }
            if (*b != 0) {
                (*b)->mPBlkPrev = n;
            }
            n->mPBlkNext = *b;
            n->mPBlkPrev = 0;
            *b = n;
        }
        if (n->mAddr + n->mSzByte == rp[0]) {
            NNSiGfdLnkVramBlock *p2;
            NNSiGfdLnkVramBlock *q2;

            r[2] = n->mAddr;
            p2 = n->mPBlkPrev;
            q2 = n->mPBlkNext;
            if (p2 != 0) {
                p2->mPBlkNext = q2;
            } else {
                *a = q2;
            }
            if (q2 != 0) {
                q2->mPBlkPrev = p2;
            }
            if (*b != 0) {
                (*b)->mPBlkPrev = n;
            }
            n->mPBlkNext = *b;
            n->mPBlkPrev = 0;
            *b = n;
        }
    }
    t = *b;
    if (t != 0) {
        *b = t->mPBlkNext;
    }
    if (t == 0) {
        return 0;
    }
    t->mAddr = r[2];
    t->mSzByte = r[3] - r[2];
    t->mPBlkPrev = 0;
    t->mPBlkNext = 0;
    if (*a != 0) {
        (*a)->mPBlkPrev = t;
    }
    t->mPBlkNext = *a;
    t->mPBlkPrev = 0;
    *a = t;
    return 1;
}
