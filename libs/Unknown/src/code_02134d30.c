#pragma avoid_byte all

#include "code_02134d30.h"

void func_02135010(void) {}

// non-matching: the counter of the 32-byte loop is in r3, the original keeps it in ip
void func_02134f18(u8 *p, int c, u32 n) {
    u32 *w;
    u32 m;
    u32 k;

    c = (u8) c;
    if (n >= 0x20) {
        m = -(u32) p & 3;
        if (m != 0) {
            n -= m;
            do {
                *p++ = (u8) c;
                m--;
            } while (m != 0);
        }
        w = (u32 *) p;
        if (c != 0) {
            c = (c << 24) | (c << 16) | (c << 8) | c;
        }
        for (k = n >> 5; k != 0; k--) {
            w[0] = c;
            w[1] = c;
            w[2] = c;
            w[3] = c;
            w[4] = c;
            w[5] = c;
            w[6] = c;
            w[7] = c;
            w += 8;
        }
        for (k = (n & 0x1f) >> 2; k != 0; k--) {
            *w++ = c;
        }
        n &= 3;
        p = (u8 *) w;
    }
    for (; n != 0; n--) {
        *p++ = (u8) c;
    }
}

void *func_02134eb8(void *dst, const void *src, u32 n) {
    u8 *p = dst;
    const u8 *s = src;

    for (; n != 0; n--) {
        *p++ = *s++;
    }
    return dst;
}

void *func_02134df8(void *a, const void *b, unsigned int n) {
    if (b >= a) {
        unsigned char *d;
        const unsigned char *s;

        for (d = a, s = b; n != 0; n--) {
            *d++ = *s++;
        }
    } else {
        const unsigned char *s;
        unsigned char *d;

        for (s = (const unsigned char *) b + n, d = (unsigned char *) a + n; n != 0; n--) {
            *--d = *--s;
        }
    }
    return a;
}

void *func_02134de0(void *p, int c, u32 n) {
    func_02134f18(p, c, n);
    return p;
}

void *func_02134db0(const u8 *p, int c, u32 n) {
    u8 ch = c;

    for (; n != 0; n--) {
        if (*p++ == ch) {
            return (void *) (p - 1);
        }
    }
    return 0;
}

void *func_02134d80(const void *a, int v, unsigned int n) {
    unsigned char c = v;
    const unsigned char *p = (const unsigned char *) a + n;

    for (; n != 0; n--) {
        if (*--p == c) {
            return (void *) p;
        }
    }
    return 0;
}

int func_02134d30(const u8 *a, const u8 *b, u32 n) {
    for (; n != 0; n--) {
        if (*a++ != *b++) {
            return a[-1] < b[-1] ? -1 : 1;
        }
    }
    return 0;
}
