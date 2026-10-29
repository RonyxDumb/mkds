#include "code_0214d018.h"

// non-matching: hand-written routine (compressed-data expansion with byte stores through swpb); this C follows its
// behaviour only
void func_0214d344(const void *a, void *b) {
    const u8 *s;
    u8 *d;
    s32 n;
    s32 len;
    s32 off;
    s32 i;
    u32 flags;

    s = (const u8 *) a;
    d = (u8 *) b;
    n = (s32) (*(const u32 *) s >> 8);
    s += 4;
    while (n > 0) {
        flags = *s++;
        for (i = 0; i < 8; i++) {
            if ((flags & 0x80) == 0) {
                *d++ = *s++;
                n--;
            } else {
                len = 3 + (s[0] >> 4);
                off = (((s[0] & 15) << 8) | s[1]) + 1;
                s += 2;
                n -= len;
                do {
                    *d = d[-off];
                    d++;
                    len--;
                } while (len > 0);
            }
            if (n <= 0) {
                break;
            }
            flags <<= 1;
        }
    }
}

// non-matching: the original is a single swp instruction
s32 func_0214d33c(s32 a, s32 *b) {
    s32 old;

    old = *b;
    *b = a;
    return old;
}

#pragma thumb on
// non-matching: three stmia stores of three zero words each
void func_0214d32c(s32 *a) {
    s32 i;

    for (i = 0; i < 9; i++) {
        a[i] = 0;
    }
}
#pragma thumb off

// non-matching: hand-written byte copy through halfword loads and stores; this C follows its behaviour only
void func_0214d1fc(const void *a, void *b, u32 c) {
    const u8 *s;
    u8 *d;
    u32 i;

    s = (const u8 *) a;
    d = (u8 *) b;
    for (i = 0; i < c; i++) {
        d[i] = s[i];
    }
}

// non-matching: hand-written byte fill through halfword stores; this C follows its behaviour only
void func_0214d168(void *a, u8 b, u32 c) {
    u8 *p;
    u32 i;

    p = (u8 *) a;
    for (i = 0; i < c; i++) {
        p[i] = b;
    }
}

// non-matching: 0x3c bytes, original 0x2c; 15 lines differ; first: original `ldm r0!, {r2, r3, ip}`, ours `stmfd sp!,
// {lr}`
void func_0214d13c(const void *a, void *b) {
    *(Unk0214d13c *) b = *(const Unk0214d13c *) a;
}

// non-matching: 0x34 bytes, original 0x24; 13 lines differ; first: original `ldm r0!, {r2, r3, ip}`, ours `stmfd sp!,
// {lr}`
void func_0214d118(const void *a, void *b) {
    *(Unk0214d118 *) b = *(const Unk0214d118 *) a;
}

// non-matching: 0x34 bytes, original 0x1c; 13 lines differ; first: original `ldm r0!, {r2, r3, ip}`, ours `stmfd sp!,
// {lr}`
void func_0214d0fc(const void *a, void *b) {
    *(Unk0214d0fc *) b = *(const Unk0214d0fc *) a;
}

// non-matching: 0x2c bytes, original 0x1c; 11 lines differ; first: original `ldm r0!, {r2, r3, ip}`, ours `stmfd sp!,
// {lr}`
void func_0214d0e0(const void *a, void *b) {
    *(Unk0214d0e0 *) b = *(const Unk0214d0e0 *) a;
}

// non-matching: 0x80 bytes, original 0x38; 32 lines differ; first: original `push {r4, r5, r6, r7, r8, r9, sl}`, ours
// `bic r3, r2, #31`
void func_0214d0a8(const void *a, void *b, u32 c) {
    const u32 *s;
    u32 *d;
    u32 *e;
    u32 *f;

    s = (const u32 *) a;
    d = (u32 *) b;
    e = (u32 *) ((u8 *) b + c);
    f = (u32 *) ((u8 *) b + ((c >> 5) << 5));
    while (d < f) {
        d[0] = s[0];
        d[1] = s[1];
        d[2] = s[2];
        d[3] = s[3];
        d[4] = s[4];
        d[5] = s[5];
        d[6] = s[6];
        d[7] = s[7];
        s += 8;
        d += 8;
    }
    while (d < e) {
        *d++ = *s++;
    }
}

// non-matching: 0x58 bytes, original 0x4c; 22 lines differ; first: original `push {r4, r5, r6, r7, r8, r9}`, ours `bic
// r3, r2, #31`
void func_0214d05c(u32 a, void *b, u32 c) {
    u32 *d;
    u32 *e;
    u32 *f;

    d = (u32 *) b;
    e = (u32 *) ((u8 *) b + c);
    f = (u32 *) ((u8 *) b + ((c >> 5) << 5));
    while (d < f) {
        d[0] = a;
        d[1] = a;
        d[2] = a;
        d[3] = a;
        d[4] = a;
        d[5] = a;
        d[6] = a;
        d[7] = a;
        d += 8;
    }
    while (d < e) {
        *d++ = a;
    }
}

// non-matching: 0x20 bytes, original 0x18; 8 lines differ; first: original `add ip, r0, r2`, ours `add r3, r0, r2`
void func_0214d044(const void *a, vu32 *b, u32 c) {
    const u32 *s;
    const u32 *e;

    s = (const u32 *) a;
    e = (const u32 *) ((const u8 *) a + c);
    while (s < e) {
        *b = *s++;
    }
}

// non-matching: 0x20 bytes, original 0x18; 8 lines differ; first: original `add ip, r1, r2`, ours `add r3, r1, r2`
void func_0214d02c(const void *a, void *b, u32 c) {
    const u32 *s;
    u32 *d;
    u32 *e;

    s = (const u32 *) a;
    d = (u32 *) b;
    e = (u32 *) ((u8 *) b + c);
    while (d < e) {
        *d++ = *s++;
    }
}

// non-matching: 0x1c bytes, original 0x14; 7 lines differ; first: original `add ip, r1, r2`, ours `add r2, r1, r2`
void func_0214d018(u32 a, void *b, u32 c) {
    u32 *d;
    u32 *e;

    d = (u32 *) b;
    e = (u32 *) ((u8 *) b + c);
    while (d < e) {
        *d++ = a;
    }
}
