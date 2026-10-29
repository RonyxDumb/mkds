#include "code_02146cbc.h"

#pragma thumb on

// non-matching: 0x20 bytes, original 0x18; 15 lines differ; first: original `stmia r0!, {r2}`, ours `str r2, [r0, #0]`
void func_02146d60(s32 *a, s32 b, s32 c) {
    a[0] = c;
    a[1] = b;
    a[2] = 0;
    a[3] = -b;
    a[4] = c;
    a[5] = 0;
    a[6] = 0;
    a[7] = 0;
    a[8] = 0x1000;
}

// non-matching: 0x20 bytes, original 0x1c; 13 lines differ; first: original `movs r3, #0`, ours `movs r2, #0`
void func_02146d44(s32 *a, s32 b, s32 c) {
    a[0] = c;
    a[8] = c;
    a[1] = 0;
    a[3] = 0;
    a[5] = 0;
    a[7] = 0;
    a[6] = b;
    a[2] = -b;
    a[4] = 0x1000;
}

// non-matching: 0x20 bytes, original 0x1c; 15 lines differ; first: original `movs r3, #1`, ours `ldr r3, [pc, #24]`
void func_02146d28(s32 *a, s32 b, s32 c) {
    a[0] = 0x1000;
    a[1] = 0;
    a[2] = 0;
    a[3] = 0;
    a[4] = c;
    a[5] = b;
    a[6] = 0;
    a[7] = -b;
    a[8] = c;
}

#pragma thumb off

// non-matching: 0x4c bytes, original 0x1c; 19 lines differ; first: original `push {r4, r5, r6, r7, r8, r9}`, ours `ldr
// r2, [r0]`
void func_02146d0c(const void *a, void *b) {
    const s32 *s;
    s32 *d;

    s = (const s32 *) a;
    d = (s32 *) b;
    d[0] = s[0];
    d[1] = s[3];
    d[2] = s[6];
    d[3] = s[1];
    d[4] = s[4];
    d[5] = s[7];
    d[6] = s[2];
    d[7] = s[5];
    d[8] = s[8];
}

// non-matching: 0x5c bytes, original 0x2c; 23 lines differ; first: original `ldm r0!, {r2, r3, ip}`, ours `ldr r3,
// [r0]`
void func_02146ce0(const s32 *a, s32 *b) {
    b[0] = a[0];
    b[1] = a[1];
    b[2] = a[2];
    b[3] = a[3];
    b[4] = a[4];
    b[5] = a[5];
    b[6] = a[6];
    b[7] = a[7];
    b[8] = a[8];
    b[9] = 0;
    b[10] = 0;
    b[11] = 0;
}

// non-matching: 0x30 bytes, original 0x24; 11 lines differ; first: original `str r2, [r0, #32]`, ours `str r2, [r0]`
void func_02146cbc(Unk02012f58 *a) {
    a->mUnk_00.x = 0x1000;
    a->mUnk_00.y = 0;
    a->mUnk_00.z = 0;
    a->mUnk_0c.x = 0;
    a->mUnk_0c.y = 0x1000;
    a->mUnk_0c.z = 0;
    a->mUnk_18.x = 0;
    a->mUnk_18.y = 0;
    a->mUnk_18.z = 0x1000;
}
