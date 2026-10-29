#include "code_02132200.h"
#include "code_02134008.h"
#include "code_021423e4.h"

// non-matching: hand-written routine (clz, shifts through the carry, argument registers pushed around calls, branches
// into neighbouring routines); this C follows its behaviour only
u64 _f2d(u32 a) {
    u32 sign;
    u32 m;
    s32 e;
    s32 z;
    u32 *p;

    sign = a & 0x80000000;
    m = a << 9;
    e = (s32) ((a >> 23) & 0xff);
    if (e == 0) {
        if (m == 0) {
            return (u64) sign << 32;
        }
        m >>= 1;
        z = 0;
        while ((m & 0x80000000) == 0) {
            m <<= 1;
            z++;
        }
        m += m;
        e = 1 - z;
    } else if (e == 0xff) {
        if (m == 0) {
            return (u64) (sign | 0x7ff00000) << 32;
        }
        if ((m & 0x80000000) == 0) {
            p = func_02142578();
            if ((*p & 0x100) != 0) {
                return func_02134188(a, 0x04000018);
            }
            *p |= 1;
        }
        return 0x7fffffffffffffffULL;
    }
    e += 0x380;
    return ((u64) (sign | (m >> 12) | ((u32) e << 20)) << 32) | (m << 20);
}

// non-matching: hand-written routine (argument registers pushed around calls, branches into neighbouring routines)
s32 _ffix(u32 a) {
    u32 x;
    u32 m;
    u32 r;
    s32 n;
    u32 *p;

    x = a & 0x7fffffff;
    n = 0x9e - (s32) (x >> 23);
    if (n <= 0) {
        if (a == 0xcf000000) {
            return 0x80000000;
        }
        return func_02132364((s32) a);
    }
    if (n >= 32) {
        if (x == 0) {
            return 0;
        }
        p = func_02142578();
        if ((*p & 0x1000) != 0) {
            return func_02134238(0, 0x40c00048);
        }
        *p |= 0x10;
        return 0;
    }
    m = (x << 8) | 0x80000000;
    r = m >> n;
    if ((s32) a < 0) {
        r = -r;
    }
    if ((m << (32 - n)) == 0) {
        return r;
    }
    p = func_02142578();
    if ((*p & 0x1000) != 0) {
        return func_02134238(r, 0x40c00048);
    }
    *p |= 0x10;
    return r;
}

// non-matching: entry stub of the float to integer overflow case, reached by branches from the routine before it
s32 func_02132364(s32 a) {
    u32 *p;

    p = func_02142578();
    if ((*p & 0x100) != 0) {
        return func_02134238(a, 0x04c00048);
    }
    *p |= 1;
    return ~(a >> 31) + 0x80000000;
}

// non-matching: hand-written routine (clz, argument registers pushed around calls, a second entry for the signed
// conversion in the middle)
u32 func_021323c4(u32 a) {
    u32 r;
    u32 t;
    s32 e;
    s32 z;
    u32 *p;

    if (a == 0) {
        return 0;
    }
    e = 0x9e;
    if ((s32) a >= 0) {
        z = 0;
        while ((a & 0x80000000) == 0) {
            a <<= 1;
            z++;
        }
        e -= z;
    }
    t = a & 0xff;
    r = ((a + a) >> 9) | ((u32) e << 23);
    if (t == 0) {
        return r;
    }
    p = func_02142578();
    if ((*p & 0x1000) != 0) {
        return func_02134238(r, 0x40000308);
    }
    *p |= 0x10;
    if ((*p & 0x800000) != 0) {
        return r;
    }
    if ((*p & 0x400000) != 0) {
        return r + 1;
    }
    if ((t & 0x80) == 0) {
        return r;
    }
    if ((t & 0x7f) != 0 || (r & 1) != 0) {
        r++;
    }
    return r;
}

// non-matching: the signed entry in the middle of the routine before it, written as a routine of its own
u32 _fflt(s32 a) {
    u32 sign;
    u32 x;
    u32 r;
    u32 t;
    s32 e;
    s32 z;
    u32 *p;

    sign = (u32) a & 0x80000000;
    x = (u32) a;
    if ((s32) x < 0) {
        x = -x;
    }
    if (x == 0) {
        return 0;
    }
    z = 0;
    while ((x & 0x80000000) == 0) {
        x <<= 1;
        z++;
    }
    e = 0x9e - z;
    t = x & 0xff;
    r = sign | ((x + x) >> 9) | ((u32) e << 23);
    if (t == 0) {
        return r;
    }
    p = func_02142578();
    if ((*p & 0x1000) != 0) {
        return func_02134238(r, 0x40000208);
    }
    *p |= 0x10;
    if ((*p & 0x800000) != 0) {
        if ((*p & 0x400000) == 0) {
            r += sign >> 31;
        }
        return r;
    }
    if ((*p & 0x400000) != 0) {
        if (sign == 0) {
            r++;
        }
        return r;
    }
    if ((t & 0x80) == 0) {
        return r;
    }
    if ((t & 0x7f) != 0 || (r & 1) != 0) {
        r++;
    }
    return r;
}

// non-matching: hand-written routine (umull, argument registers pushed around calls, branches to many shared tails);
// this C follows its behaviour only
u32 func_0213250c(u32 a, u32 b) {
    u32 sign;
    u32 ma;
    u32 mb;
    u32 hi;
    u32 lo;
    u32 t;
    s32 ea;
    s32 eb;
    s32 e;
    s32 z;
    u32 r;
    u32 *p;
    u64 prod;

    sign = (a ^ b) & 0x80000000;
    ea = (s32) ((a >> 23) & 0xff);
    eb = (s32) ((b >> 23) & 0xff);
    ma = a << 8;
    mb = b << 8;
    if (ea == 0 || ea == 0xff) {
        if (ea == 0) {
            if ((ma << 1) == 0) {
                if (eb == 0xff) {
                    if ((mb << 1) != 0) {
                        goto b_nan;
                    }
                    goto invalid;
                }
                return sign;
            }
            ma = (ma << 1) >> 1;
            z = 0;
            while ((ma & 0x80000000) == 0) {
                ma <<= 1;
                z++;
            }
            ea = 1 - z;
        } else {
            if ((ma << 1) != 0) {
                if ((ma & 0x80000000) == 0) {
                    goto invalid;
                }
                if (eb == 0xff && (mb << 1) != 0) {
                    if ((mb << 1 & 0x80000000) == 0) {
                        goto invalid;
                    }
                }
                return 0x7fffffff;
            }
            if (eb == 0 && (mb << 1) == 0) {
                goto invalid;
            }
            if (eb == 0xff && (mb << 1) != 0) {
                goto b_nan;
            }
            return sign | 0x7f800000;
        }
    } else {
        ma |= 0x80000000;
    }
    if (eb == 0 || eb == 0xff) {
        if (eb == 0xff) {
            if ((mb << 1) != 0) {
                goto b_nan;
            }
            return sign | 0x7f800000;
        }
        if ((mb << 1) == 0) {
            return sign;
        }
        mb = (mb << 1) >> 1;
        z = 0;
        while ((mb & 0x80000000) == 0) {
            mb <<= 1;
            z++;
        }
        eb = 1 - z;
    } else {
        mb |= 0x80000000;
    }
    e = ea + eb;
    prod = (u64) ma * mb;
    lo = (u32) prod;
    hi = (u32) (prod >> 32);
    if (lo != 0) {
        hi |= 1;
    }
    if ((hi & 0x80000000) == 0) {
        hi += hi;
        e -= 1;
    }
    e -= 127;
    if (e < 0) {
        p = func_02142578();
        if ((*p & 0x800) != 0) {
            return func_02134238((sign | (hi >> 8)) + ((u32) (e + 0xc0) << 23), 0x20000003);
        }
        if (e == -24) {
            t = hi << 1;
            r = sign;
        } else if (e < -24) {
            t = 0;
            r = sign;
            if ((*p & 0x1000) != 0) {
                return func_02134238(r, 0x40000003);
            }
            *p |= 0x18;
            if ((*p & 0x800000) != 0) {
                if ((*p & 0x400000) == 0) {
                    r += sign >> 31;
                }
            } else if ((*p & 0x400000) != 0 && sign == 0) {
                r = 1;
            }
            return r;
        } else {
            t = hi << (24 + e);
            r = sign | ((hi >> 8) >> -e);
            if (t == 0) {
                return r;
            }
            if ((*p & 0x1000) != 0) {
                return func_02134238(r, 0x40000003);
            }
            *p |= 0x18;
            if ((*p & 0x800000) != 0) {
                if ((*p & 0x400000) == 0) {
                    r += sign >> 31;
                }
            } else if ((*p & 0x400000) != 0) {
                if (sign == 0) {
                    r++;
                }
            } else if ((t & 0x80000000) != 0 && ((t << 1) != 0 || (r & 1) != 0)) {
                r++;
            }
            return r;
        }
        if ((*p & 0x1000) != 0) {
            return func_02134238(r, 0x40000003);
        }
        *p |= 0x18;
        if ((*p & 0x800000) != 0) {
            if ((*p & 0x400000) == 0) {
                r += sign >> 31;
            }
        } else if ((*p & 0x400000) != 0) {
            if (sign == 0) {
                r++;
            }
        } else if (t != 0) {
            r++;
        }
        return r;
    }
    if (e >= 254) {
        p = func_02142578();
        if ((*p & 0x400) != 0) {
            return func_02134238((sign | (hi >> 8)) + ((u32) (e - 0xc0) << 23), 0x10000003);
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
    t = hi & 0xff;
    r = (sign | (hi >> 8)) + ((u32) e << 23);
    if (t == 0) {
        return r;
    }
    p = func_02142578();
    if ((*p & 0x1000) != 0) {
        return func_02134238(r, 0x40000003);
    }
    *p |= 0x10;
    if ((*p & 0x800000) != 0) {
        if ((*p & 0x400000) != 0 || sign == 0) {
            return r;
        }
    } else if ((*p & 0x400000) != 0) {
        if (sign != 0) {
            return r;
        }
    } else {
        if ((t & 0x80) == 0) {
            return r;
        }
        if ((t & 0x7f) == 0 && (r & 1) == 0) {
            return r;
        }
    }
    r++;
    if ((r << 1) < 0xff000000) {
        return r;
    }
    if ((*p & 0x400) != 0) {
        return func_02134238(r - 0x60000000, 0x10000003);
    }
    *p |= 0x14;
    return r;
b_nan:
    if ((mb << 1 & 0x80000000) == 0) {
        goto invalid;
    }
    return 0x7fffffff;
invalid:
    p = func_02142578();
    if ((*p & 0x100) != 0) {
        return func_021340d4(a, b, 0x04000003);
    }
    *p |= 1;
    return 0x7fffffff;
}
