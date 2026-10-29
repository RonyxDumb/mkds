#include "code_0212f884.h"
#include "code_021423e4.h"
#include "code_02134008.h"

// non-matching: hand-written routine (clz); this C follows its behaviour only
u64 _dflt(s32 a) {
    u32 sign;
    u32 m;
    u32 e;

    sign = (u32) a & 0x80000000;
    if (a < 0) {
        a = -a;
    }
    if (a == 0) {
        return 0;
    }
    m = (u32) a;
    e = 0x41e;
    while ((m & 0x80000000) == 0) {
        m <<= 1;
        e--;
    }
    return ((u64) (sign | ((m + m) >> 12) | (e << 20)) << 32) | (m << 21);
}

// non-matching: hand-written routine (clz); this C follows its behaviour only
u64 _dfltu(u32 a) {
    u32 e;

    if (a == 0) {
        return 0;
    }
    e = 0x41e;
    while ((a & 0x80000000) == 0) {
        a <<= 1;
        e--;
    }
    return ((u64) (((a + a) >> 12) | (e << 20)) << 32) | (a << 21);
}

// non-matching: hand-written routine (push of the argument registers around calls, branches into the middle of
// neighbouring routines); this C follows its behaviour only
u64 func_02130198(u32 a, u32 b) {
    s32 n;
    u32 *p;
    u64 m;
    u64 r;

    if ((b & 0x80000000) != 0) {
        if (b > 0xfff00000 || (b == 0xfff00000 && a != 0)) {
            n = -1;
        } else {
            return 0;
        }
    } else {
        n = 0x43e - (s32) (b >> 20);
    }
    if (n < 0) {
        p = func_02142578();
        if ((*p & 0x100) != 0) {
            return func_0213412c(a, b, 0x04c000f8);
        }
        *p |= 1;
        return ~(u64) 0;
    }
    if (n >= 64) {
        if ((a | b) != 0) {
            p = func_02142578();
            if ((*p & 0x1000) != 0) {
                return func_0213412c(0, 0, 0x40c000f8);
            }
            *p |= 0x10;
        }
        return 0;
    }
    m = ((u64) ((b << 11) | 0x80000000 | (a >> 21)) << 32) | (a << 11);
    r = m >> n;
    if (n != 0 && (m << (64 - n)) != 0) {
        p = func_02142578();
        if ((*p & 0x1000) != 0) {
            return func_0213412c((u32) r, (u32) (r >> 32), 0x40c000f8);
        }
        *p |= 0x10;
    }
    return r;
}

// non-matching: hand-written routine (entered from the middle of the preceding routine with its values in registers,
// branches into the following routine); this C follows its behaviour only
u32 func_0212ff40(u32 a, u32 b, u32 c) {
    u32 *p;

    p = func_02142578();
    if ((*p & 0x800) != 0) {
        return func_021341e0(a & 0xe0000000, b + 0x0c000000, 0x20000088);
    }
    if ((*p & 0x1000) != 0) {
        return func_02134238(c, 0x40000088);
    }
    *p |= 0x18;
    if ((*p & 0x800000) != 0) {
        if ((*p & 0x400000) == 0) {
            return c + (c >> 31);
        }
        return c;
    }
    if ((*p & 0x400000) != 0) {
        if (c == 0) {
            return c + 1;
        }
        return c;
    }
    if (a != 0 || b != 0) {
        return c + 1;
    }
    return c;
}

// non-matching: hand-written routine (push of the argument registers around the call); this C follows its behaviour
// only
u32 func_0212ff0c(u32 a, u32 b) {
    u32 *p;

    p = func_02142578();
    if ((*p & 0x100) != 0) {
        return func_021341e0(a, b, 0x04000088);
    }
    *p |= 1;
    return 0x7fffffff;
}

// non-matching: hand-written routine (push of the argument registers around calls, branches into the middle of the
// following routines); this C follows its behaviour only
u32 _d2f(u32 a, u32 b) {
    u32 sign;
    s32 e;
    u32 r;
    u32 *p;

    sign = b & 0x80000000;
    e = (s32) ((b >> 20) & 0x7ff);
    if (e == 0) {
        if (((b << 12) | a) == 0) {
            return sign;
        }
        return func_0212ff40(a, b, sign);
    }
    if (e == 0x7ff) {
        if (((b << 12) | a) == 0) {
            return sign | 0x7f800000;
        }
        if ((b & 0x80000) == 0) {
            return func_0212ff0c(a, b);
        }
        return 0x7fffffff;
    }
    e -= 0x380;
    if (e <= 0) {
        return func_0212ff40(a, b, sign);
    }
    if (e >= 0xff) {
        p = func_02142578();
        if ((*p & 0x400) != 0) {
            return func_021341e0(sign, 0xf0000000 + b, 0x10000088);
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
    r = sign | ((b << 12) >> 9) | (a >> 29) | ((u32) e << 23);
    if ((a << 3) == 0) {
        return r;
    }
    p = func_02142578();
    if ((*p & 0x1000) != 0) {
        return func_02134238(r, 0x40000088);
    }
    *p |= 0x10;
    if ((*p & 0x800000) != 0) {
        if ((*p & 0x400000) == 0) {
            if ((a << 3) < 0x80000000) {
                return r;
            }
            r++;
        } else if (sign == 0) {
            r++;
        }
    } else if ((*p & 0x400000) != 0) {
        if (sign == 0) {
            r++;
        }
    } else if ((a << 3) >= 0x80000000) {
        if ((a << 4) != 0 || (r & 1) != 0) {
            r++;
        }
    }
    return r;
}

// non-matching: hand-written routine (add/carry chains, branches into the middle of other routines, argument
// registers pushed around calls); this C follows its behaviour only
u64 _dadd(u32 a, u32 b, u32 c, u32 d) {
    u64 x;
    u64 y;
    u64 t;
    u32 sign;
    s32 ex;
    s32 ey;
    s32 n;
    u32 *p;
    u64 mx;
    u64 my;
    u64 m;

    if (((b ^ d) & 0x80000000) != 0) {
        return _dsub(a, b, c, d ^ 0x80000000);
    }
    sign = b & 0x80000000;
    x = ((u64) (b & 0x7fffffff) << 32) | a;
    y = ((u64) (d & 0x7fffffff) << 32) | c;
    if (x < y) {
        t = x;
        x = y;
        y = t;
    }
    ex = (s32) (x >> 52);
    ey = (s32) (y >> 52);
    if (ex == 0x7ff) {
        if ((x << 12) != 0 || (ey == 0x7ff && (y << 12) != 0)) {
            if (((x >> 51) & 1) == 0) {
                p = func_02142578();
                if ((*p & 0x100) != 0) {
                    return func_0213412c((u32) x, (u32) (x >> 32), 0x04000091);
                }
                *p |= 1;
            }
            return 0x7fffffffffffffffULL;
        }
        return x | ((u64) sign << 32);
    }
    if (y == 0) {
        return x | ((u64) sign << 32);
    }
    mx = ((x << 11) | 0x8000000000000000ULL);
    my = ((y << 11) | 0x8000000000000000ULL);
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
    m = mx + my;
    if (m < mx) {
        m = (m >> 1) | (m & 1) | 0x8000000000000000ULL;
        ex++;
        if (ex >= 0x7ff) {
            p = func_02142578();
            if ((*p & 0x400) != 0) {
                return func_0213412c(0, 0, 0x10000091);
            }
            *p |= 0x14;
            return ((u64) (sign | 0x7ff00000) << 32);
        }
    }
    if ((m & 0x7ff) != 0) {
        p = func_02142578();
        if ((*p & 0x1000) != 0) {
            return func_0213412c((u32) (m >> 11), (u32) (m >> 43), 0x40000091);
        }
        *p |= 0x10;
        if ((m & 0x7ff) > 0x400 || ((m & 0x7ff) == 0x400 && (m & 0x800) != 0)) {
            m += 0x800;
        }
    }
    return (((u64) (sign | ((u32) (ex - 1) << 20)) << 32) + (m >> 11));
}
