#include "code_021329f8.h"
#include "code_02130a70.h"
#include "code_02134008.h"
#include "code_021423e4.h"

// non-matching: hand-written routine (clz, argument registers pushed around calls, a conditional swap through a
// subtraction, branches into the middle of neighbouring routines); this C follows its behaviour only
u32 _fsub(u32 a, u32 b) {
    u32 x;
    u32 y;
    u32 t;
    u32 mx;
    u32 my;
    u32 r;
    u32 sign;
    s32 ex;
    s32 ey;
    s32 d;
    s32 z;
    u32 *p;

    if (((a ^ b) & 0x80000000) != 0) {
        return _fadd(a, b ^ 0x80000000);
    }
    x = a;
    y = b;
    if (x < y) {
        x = b ^ 0x80000000;
        y = a ^ 0x80000000;
    }
    sign = x & 0x80000000;
    ex = (s32) ((x >> 23) & 0xff);
    ey = (s32) ((y >> 23) & 0xff);
    mx = 0x80000000 | (x << 8);
    my = 0x80000000 | (y << 8);
    if (ex == 0xff) {
        if ((x << 9) != 0) {
            if ((x & 0x400000) == 0) {
                goto invalid;
            }
            if (ey == 0xff && (y << 9) != 0 && (y & 0x400000) == 0) {
                goto invalid;
            }
            return 0x7fffffff;
        }
        if (ey == 0xff) {
            if ((y << 9) == 0) {
                goto invalid;
            }
            if ((y & 0x400000) == 0) {
                goto invalid;
            }
            return 0x7fffffff;
        }
        return sign | 0x7f800000;
    }
    if (ex == 0) {
        if ((x << 9) == 0) {
            if (ey == 0xff) {
                if ((y << 9) != 0) {
                    if ((y & 0x400000) == 0) {
                        p = func_02142578();
                        *p |= 1;
                    }
                    return 0x7fffffff;
                }
                return 0x7f8000ff;
            }
            if (ey == 0 && (y << 9) == 0) {
                goto zero;
            }
            return y;
        }
        mx = (x << 9) >> 1;
        ex = 1;
        if (ey == 0) {
            if ((y << 9) == 0) {
                return sign | (x & 0x7fffff);
            }
            my = (y << 9) >> 1;
            ey = 1;
        } else if (ey == 0xff) {
            if ((y << 9) != 0) {
                if ((y & 0x400000) == 0) {
                    goto invalid;
                }
                return 0x7fffffff;
            }
            return (sign ^ 0x80000000) | 0x7f800000;
        }
    } else if (ey == 0) {
        if ((y << 9) == 0) {
            return sign | ((mx + mx) >> 9) | ((u32) ex << 23);
        }
        my = (y << 9) >> 1;
        ey = 1;
    }
    d = ex - ey;
    if (d == 0) {
        r = mx - my;
        if (r == 0) {
            goto zero;
        }
        z = 0;
        while ((r & 0x80000000) == 0) {
            r <<= 1;
            z++;
        }
        ex -= z;
        if (ex <= 0) {
            return sign | (r >> (9 - ex));
        }
        return sign | ((r + r) >> 9) | ((u32) ex << 23);
    }
    if (d >= 28) {
        d = 31;
    }
    t = (my << (32 - d)) != 0;
    my >>= d;
    if (t != 0) {
        my |= 1;
    }
    r = mx - my;
    if ((s32) r < 0) {
        t = r & 0xff;
        r = sign | ((r + r) >> 9) | ((u32) ex << 23);
    } else {
        z = 0;
        while ((r & 0x80000000) == 0) {
            r <<= 1;
            z++;
        }
        ex -= z;
        if (ex <= 0) {
            return sign | (r >> (9 - ex));
        }
        t = r & 0xff;
        r = sign | ((r + r) >> 9) | ((u32) ex << 23);
    }
    if (t == 0) {
        return r;
    }
    p = func_02142578();
    if ((*p & 0x1000) != 0) {
        return func_02134238(r, 0x40000002);
    }
    *p |= 0x10;
    if ((*p & 0x800000) != 0) {
        if ((*p & 0x400000) == 0 && (s32) r < 0) {
            r++;
        }
    } else if ((*p & 0x400000) != 0) {
        if ((s32) r >= 0) {
            r++;
        }
    } else if ((t & 0x80) != 0 && ((t & 0x7f) != 0 || (r & 1) != 0)) {
        r++;
    }
    return r;
zero:
    p = func_02142578();
    if ((*p & 0x800000) == 0 || (*p & 0x400000) != 0) {
        return 0;
    }
    return 0x80000000;
invalid:
    p = func_02142578();
    if ((*p & 0x100) != 0) {
        return func_021340d4(a, b, 0x04000002);
    }
    *p |= 1;
    return 0x7fffffff;
}

// non-matching: hand-written routine (64-bit shift and subtract loop through the carry, a second entry for the
// remainder in the middle); this C follows its behaviour only
u64 _ll_udiv(u64 a, u64 b) {
    u64 q;
    u64 r;
    s32 i;

    if (b == 0) {
        return a;
    }
    q = 0;
    r = 0;
    for (i = 63; i >= 0; i--) {
        r = (r << 1) | ((a >> i) & 1);
        if (r >= b) {
            r -= b;
            q |= (u64) 1 << i;
        }
    }
    return q;
}

// non-matching: hand-written routine (64-bit shift and subtract loop through the carry, a second entry for the
// remainder in the middle); this C follows its behaviour only
u64 _ll_sdiv(u64 a, u64 b) {
    u64 x;
    u64 y;
    u64 q;
    u64 r;
    s32 i;

    if (b == 0) {
        return a;
    }
    x = a;
    y = b;
    if ((s64) x < 0) {
        x = -x;
    }
    if ((s64) y < 0) {
        y = -y;
    }
    q = 0;
    r = 0;
    for (i = 63; i >= 0; i--) {
        r = (r << 1) | ((x >> i) & 1);
        if (r >= y) {
            r -= y;
            q |= (u64) 1 << i;
        }
    }
    if (((a ^ b) & 0x8000000000000000ULL) != 0) {
        q = -q;
    }
    return q;
}

// non-matching: hand-written routine (umull and two multiply-accumulates)
u64 _ll_mul(u64 a, u64 b) {
    u32 lo;
    u32 hi;
    u64 t;

    t = (u64) (u32) a * (u32) b;
    lo = (u32) t;
    hi = (u32) (t >> 32) + (u32) a * (u32) (b >> 32) + (u32) b * (u32) (a >> 32);
    return ((u64) hi << 32) | lo;
}

// non-matching: hand-written routine (division by a computed jump into a run of shift and subtract steps); this C
// runs the steps as a loop
u64 _s32_div_f(u32 param_1, u32 param_2) {
    u32 sign;
    u32 q;
    u32 r;
    s32 i;

    sign = (param_1 ^ param_2) & 0x80000000;
    if ((s32) param_1 < 0) {
        param_1 = -param_1;
        sign++;
    }
    if ((s32) param_2 < 0) {
        param_2 = -param_2;
    }
    if (param_2 == 0) {
        q = param_1;
        r = 0;
    } else if (param_1 < param_2) {
        q = 0;
        r = param_1;
    } else {
        q = 0;
        r = 0;
        for (i = 31; i >= 0; i--) {
            r = (r << 1) | ((param_1 >> i) & 1);
            if (r >= param_2) {
                r -= param_2;
                q |= 1u << i;
            }
        }
    }
    if ((sign & 0x80000000) != 0) {
        q = -q;
    }
    if ((sign & 1) != 0) {
        r = -r;
    }
    return ((u64) r << 32) | q;
}

// non-matching: hand-written routine (division by a computed jump into a run of shift and subtract steps, a second
// entry in the middle); this C runs the steps as a loop
u64 _u32_div_f(u32 a, u32 b) {
    u32 q;
    u32 r;
    s32 i;

    if (b == 0) {
        return a;
    }
    if (a < b) {
        return (u64) a << 32;
    }
    q = 0;
    r = 0;
    for (i = 31; i >= 0; i--) {
        r = (r << 1) | ((a >> i) & 1);
        if (r >= b) {
            r -= b;
            q |= 1u << i;
        }
    }
    return ((u64) r << 32) | q;
}

// non-matching: hand-written routine (shifts a 64-bit value right by an argument masked to 6 bits)
u64 func_02133458(u64 a, u32 b) {
    u32 lo;
    u32 hi;

    lo = (u32) a;
    hi = (u32) (a >> 32);
    b &= 0x3f;
    if (b == 0) {
        return a;
    }
    if (b >= 32) {
        return hi >> (b - 32);
    }
    return ((u64) (hi >> b) << 32) | ((lo >> b) | (hi << (32 - b)));
}
