#include "code_02130a70.h"
#include "code_0212f884.h"
#include "code_02134008.h"
#include "code_021423e4.h"
#include "Main/Unknown/code_02130000.h"

// non-matching: hand-written routine (clz, shifts through the carry, argument registers pushed around calls, a
// second entry in the middle of the following routine); this C follows its behaviour only
double func_02130a70(double a) {
    u64 bits;
    u64 res;
    u64 rem;
    u64 root;
    u64 t;
    u32 lo;
    u32 hi;
    u32 *p;
    s32 e;
    s32 ip;
    s32 z;
    u32 m1;
    u32 m0;
    u32 r1;
    u32 r2;
    u32 r4;
    u32 r5;
    u32 r6;
    u32 g;
    u32 i;

    bits = *(u64 *) &a;
    lo = (u32) bits;
    hi = (u32) (bits >> 32);
    if (hi >= 0x7ff00000) {
        if ((hi & 0x80000000) == 0) {
            if (((hi << 12) | lo) == 0) {
                return a;
            }
            if ((hi & 0x80000) != 0) {
                return a;
            }
        } else {
            if (((hi & 0x7fffffff) | lo) == 0) {
                return a;
            }
            if ((hi & 0x7fffffff) >= 0x7ff00000 && ((hi << 12) | lo) != 0 && (hi & 0x80000) != 0) {
                return a;
            }
        }
        p = func_02142578();
        if ((*p & 0x100) != 0) {
            res = func_0213412c(lo, hi, 0x04000097);
            return *(double *) &res;
        }
        *p |= 1;
        res = ((u64) (hi | 0x7ff80000) << 32) | lo;
        return *(double *) &res;
    }
    e = (s32) (hi >> 20);
    if (e == 0) {
        if (hi == 0) {
            if (lo == 0) {
                return a;
            }
            z = 0;
            while ((lo & 0x80000000) == 0) {
                lo <<= 1;
                z++;
            }
            ip = -20 - z;
            m1 = lo >> 11;
            m0 = lo << 21;
        } else {
            z = 0;
            while ((hi & 0x80000000) == 0) {
                hi <<= 1;
                z++;
            }
            m1 = (hi >> 11) | (lo >> (43 - z));
            m0 = lo << (z - 11);
            ip = 12 - z;
        }
    } else {
        m1 = (hi & 0x000fffff) | 0x100000;
        m0 = lo;
        ip = e;
    }
    r4 = (u32) ip & 1;
    ip >>= 1;
    if (r4 == 0) {
        ip--;
        rem = (((u64) m1 << 32) | m0) << 2;
    } else {
        rem = (((u64) m1 << 32) | m0) << 1;
    }
    r2 = 0;
    r4 = 0;
    for (g = 0x200000; g != 0; g >>= 1) {
        r6 = r4 + g;
        r1 = (u32) (rem >> 32);
        if ((s32) r6 <= (s32) r1) {
            r4 = r6 + g;
            rem -= (u64) r6 << 32;
            r2 += g;
        }
        rem <<= 1;
    }
    m0 = 0;
    r5 = 0;
    t = ((u64) r4 << 32) | 0x80000000;
    if (rem >= t) {
        rem -= t;
        r4++;
        m0 = 0x80000000;
    }
    rem <<= 1;
    for (g = 0x40000000; g != 0; g >>= 1) {
        r6 = r5 + g;
        t = ((u64) r4 << 32) | r6;
        if (t <= rem) {
            r5 = r6 + g;
            rem -= t;
            m0 += g;
        }
        rem <<= 1;
    }
    root = ((u64) r2 << 32) | m0;
    p = 0;
    if (rem == 0) {
        root &= ~(u64) 1;
    } else {
        p = func_02142578();
        if ((*p & 0x1000) != 0) {
            res = (root >> 1) + ((u64) (0x1ff00000 + ((u32) ip << 20)) << 32);
            res = func_0213412c((u32) res, (u32) (res >> 32), 0x40000097);
            return *(double *) &res;
        }
        *p |= 0x10;
        if ((*p & 0x800000) != 0) {
            root &= ~(u64) 1;
        } else if ((*p & 0x400000) != 0) {
            root |= 1;
        }
    }
    res = (root >> 1) + (root & 1) + ((u64) (0x1ff00000 + ((u32) ip << 20)) << 32);
    return *(double *) &res;
}

// non-matching: hand-written entry (swaps the two operands, then continues in the next routine)
u64 func_02130cb4(u32 a, u32 b, u32 c, u32 d) {
    return _dsub(c, d, a, b);
}

// non-matching: hand-written routine (clz, shifts through the carry, add/subtract chains, argument registers pushed
// around calls, branches into the middle of other routines); this C follows its behaviour only
u64 _dsub(u32 a, u32 b, u32 c, u32 d) {
    u64 x;
    u64 y;
    u64 t;
    u64 mx;
    u64 my;
    u64 m;
    u32 sign;
    s32 ex;
    s32 ey;
    s32 n;
    u32 *p;

    if (((b ^ d) & 0x80000000) != 0) {
        return _dadd(a, b, c, d ^ 0x80000000);
    }
    sign = b & 0x80000000;
    x = ((u64) b << 32) | a;
    y = ((u64) d << 32) | c;
    if (x < y) {
        t = x;
        x = y;
        y = t;
        sign ^= 0x80000000;
    }
    x &= 0x7fffffffffffffffULL;
    y &= 0x7fffffffffffffffULL;
    ex = (s32) (x >> 52);
    ey = (s32) (y >> 52);
    if (ex == 0x7ff) {
        if ((x << 12) != 0) {
            p = func_02142578();
            if (((x >> 51) & 1) == 0) {
                if ((*p & 0x100) != 0) {
                    return func_0213406c(a, b, c, d, 0x04000092);
                }
                *p |= 1;
            }
            return 0x7fffffffffffffffULL;
        }
        if (ey == 0x7ff) {
            p = func_02142578();
            if ((*p & 0x100) != 0) {
                return func_0213406c(a, b, c, d, 0x04000092);
            }
            *p |= 1;
            return 0x7fffffffffffffffULL;
        }
        return x | ((u64) sign << 32);
    }
    if (y == 0) {
        if (x != 0) {
            return x | ((u64) sign << 32);
        }
        p = func_02142578();
        if ((*p & 0x800000) == 0 || (*p & 0x400000) != 0) {
            return 0;
        }
        return 0x8000000000000000ULL;
    }
    mx = (x << 11) | 0x8000000000000000ULL;
    my = (y << 11) | 0x8000000000000000ULL;
    if (ex == 0) {
        mx = x << 11;
        ex = 1;
    }
    if (ey == 0) {
        my = y << 11;
        ey = 1;
    }
    n = ex - ey;
    if (n > 0) {
        if (n > 63) {
            n = 63;
        }
        my = (my >> n) | ((my << (64 - n)) != 0);
    }
    m = mx - my;
    if (m == 0) {
        p = func_02142578();
        if ((*p & 0x800000) == 0 || (*p & 0x400000) != 0) {
            return 0;
        }
        return 0x8000000000000000ULL;
    }
    while ((m >> 63) == 0 && ex > 1) {
        m <<= 1;
        ex--;
    }
    if ((m >> 63) == 0) {
        ex = 0;
    }
    if ((m & 0x7ff) != 0) {
        p = func_02142578();
        if ((*p & 0x1000) != 0) {
            return func_0213406c(a, b, c, d, 0x40000092);
        }
        *p |= 0x10;
        if ((*p & 0x800000) != 0) {
            if ((*p & 0x400000) == 0) {
                m += 0x800;
            }
        } else if ((*p & 0x400000) != 0) {
            if (sign == 0) {
                m += 0x800;
            }
        } else if ((m & 0x7ff) > 0x400 || ((m & 0x7ff) == 0x400 && (m & 0x800) != 0)) {
            m += 0x800;
        }
    }
    return (((u64) (sign | ((u32) ex << 20)) << 32) + (m >> 11));
}

// non-matching: hand-written routine (add chains through the carry, argument registers pushed around calls, branches
// into the middle of other routines); this C follows its behaviour only
u32 _fadd(u32 a, u32 b) {
    u32 sign;
    u32 x;
    u32 y;
    u32 t;
    u32 mx;
    u32 my;
    u32 r;
    s32 ex;
    s32 ey;
    s32 n;
    u32 *p;

    if (((a ^ b) & 0x80000000) != 0) {
        return _fsub(a, b ^ 0x80000000);
    }
    sign = a & 0x80000000;
    x = a & 0x7fffffff;
    y = b & 0x7fffffff;
    if (x < y) {
        t = x;
        x = y;
        y = t;
    }
    ex = (s32) (x >> 23);
    ey = (s32) (y >> 23);
    if (ex == 0xff) {
        if ((x << 9) != 0) {
            if ((x & 0x400000) == 0) {
                p = func_02142578();
                if ((*p & 0x100) != 0) {
                    return func_021340d4(a, b, 0x04000001);
                }
                *p |= 1;
            }
            return 0x7fffffff;
        }
        if (ey == 0xff && (y << 9) != 0) {
            p = func_02142578();
            if ((*p & 0x100) != 0) {
                return func_021340d4(a, b, 0x04000001);
            }
            *p |= 1;
            return 0x7fffffff;
        }
        return x | sign;
    }
    if (y == 0) {
        return x | sign;
    }
    mx = (x << 8) | 0x80000000;
    my = (y << 8) | 0x80000000;
    if (ex == 0) {
        mx = x << 8;
        ex = 1;
    }
    if (ey == 0) {
        my = y << 8;
        ey = 1;
    }
    n = ex - ey;
    if (n > 0) {
        if (n >= 28) {
            n = 31;
        }
        my = (my >> n) | ((my << (32 - n)) != 0);
    }
    r = mx + my;
    if (r < mx) {
        r = (r >> 1) | (r & 1) | 0x80000000;
        ex++;
        if (ex == 0xff) {
            p = func_02142578();
            if ((*p & 0x400) != 0) {
                return func_02134238((sign | (r >> 8)) + 0x1f000000, 0x10000001);
            }
            *p |= 0x14;
            r = sign | 0x7f800000;
            if ((*p & 0x800000) != 0) {
                r--;
                if ((*p & 0x400000) == 0) {
                    r += sign >> 31;
                }
            } else if ((*p & 0x400000) != 0) {
                r -= sign >> 31;
            }
            return r;
        }
    }
    t = r & 0xff;
    r = ((r + r) >> 9) | ((u32) ex << 23);
    if (t == 0) {
        return r | sign;
    }
    r |= sign;
    p = func_02142578();
    if ((*p & 0x1000) != 0) {
        return func_02134238(r, 0x40000001);
    }
    *p |= 0x10;
    if ((*p & 0x800000) != 0) {
        if ((*p & 0x400000) != 0 || sign == 0) {
            return r;
        }
        r++;
    } else if ((*p & 0x400000) != 0) {
        if (sign != 0) {
            return r;
        }
        r++;
    } else {
        if ((t & 0x80) == 0) {
            return r;
        }
        if ((t & 0x7f) == 0 && (r & 1) == 0) {
            return r;
        }
        r++;
    }
    if ((r << 1) < 0xff000000) {
        return r;
    }
    p = func_02142578();
    if ((*p & 0x400) != 0) {
        return func_02134238(r - 0x60000000, 0x10000001);
    }
    *p |= 0x14;
    return r;
}
