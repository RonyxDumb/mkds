#include "code_020205b0.h"

void func_020207a8(u8 *a, u32 b) {
    u32 v;
    u32 i;
    u32 j;

    for (i = 0; i < 0x100; i++) {
        v = i;
        for (j = 0; j < 8; j++) {
            if (v & 0x80) {
                v = b ^ (v << 1);
            } else {
                v = v << 1;
            }
        }
        a[i] = v;
    }
}

void func_02020768(const u8 *a, u8 *b, const u8 *c, u32 d) {
    u32 v;
    u32 i;

    v = *b;
    for (i = 0; i < d; i++) {
        v = a[(v ^ *c) & 0xff];
        c++;
    }
    *b = v;
}

void func_02020720(u16 *a, u32 b) {
    u32 v;
    u32 i;
    u32 j;

    for (i = 0; i < 0x100; i++) {
        v = i;
        for (j = 0; j < 8; j++) {
            if (v & 1) {
                v = b ^ (v >> 1);
            } else {
                v = v >> 1;
            }
        }
        a[i] = v;
    }
}

void func_020206d8(const u16 *a, u16 *b, const u8 *c, u32 d) {
    u32 v;
    u32 i;

    v = *b;
    for (i = 0; i < d; i++) {
        v = a[(v ^ *c) & 0xff] ^ (v >> 8);
        c++;
    }
    *b = v;
}

void func_02020694(u32 *a, u32 b) {
    u32 v;
    u32 i;
    u32 j;

    for (i = 0; i < 0x100; i++) {
        v = i;
        for (j = 0; j < 8; j++) {
            if (v & 1) {
                v = b ^ (v >> 1);
            } else {
                v = v >> 1;
            }
        }
        a[i] = v;
    }
}

void func_02020650(const u32 *a, u32 *b, const u8 *c, u32 d) {
    u32 v;
    u32 i;

    v = *b;
    for (i = 0; i < d; i++) {
        v = a[(v ^ *c) & 0xff] ^ (v >> 8);
        c++;
    }
    *b = v;
}

u8 func_0202061c(const u8 *a, const u8 *b, u32 c) {
    u8 v;

    v = 0;
    func_02020768(a, &v, b, c);
    return v;
}

u16 func_020205e8(const u16 *a, const u8 *b, u32 c) {
    u16 v;

    v = 0;
    func_020206d8(a, &v, b, c);
    return v;
}

u32 func_020205b0(const u32 *a, const u8 *b, u32 c) {
    u32 v;

    v = -1;
    func_02020650(a, &v, b, c);
    return ~v;
}
