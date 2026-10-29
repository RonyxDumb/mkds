#include "code_021471bc.h"

#pragma thumb on

// non-matching: 0x24 bytes, original 0x1a; 17 lines differ; first: original `stmia r0!, {r2}`, ours `str r2, [r0, #0]`
void func_0214726c(s32 *a, s32 b, s32 c) {
    a[0] = c;
    a[1] = b;
    a[2] = 0;
    a[3] = -b;
    a[4] = c;
    a[5] = 0;
    a[6] = 0;
    a[7] = 0;
    a[8] = 0x1000;
    a[9] = 0;
    a[10] = 0;
    a[11] = 0;
}

// non-matching: 0x24 bytes, original 0x1a; 16 lines differ; first: original `movs r3, #0`, ours `str r2, [r0, #0]`
void func_02147250(void *a, s32 b, s32 c) {
    s32 *p;

    p = (s32 *) a;
    p[6] = b;
    p[0] = c;
    p[1] = 0;
    p[2] = -b;
    p[3] = 0;
    p[4] = 0x1000;
    p[5] = 0;
    p[7] = 0;
    p[8] = c;
    p[9] = 0;
    p[10] = 0;
    p[11] = 0;
}

// non-matching: 0x24 bytes, original 0x1e; 14 lines differ; first: original `movs r1, #1`, ours `ldr r1, [pc, #24]`
void func_02147230(s32 *a, s32 b, s32 c) {
    a[5] = b;
    a[7] = -b;
    a[0] = 0x1000;
    a[1] = 0;
    a[2] = 0;
    a[3] = 0;
    a[4] = c;
    a[6] = 0;
    a[8] = c;
    a[9] = 0;
    a[10] = 0;
    a[11] = 0;
}

// non-matching: 0x1c bytes, original 0x16; 14 lines differ; first: original `stmia r0!, {r1}`, ours `str r1, [r0, #0]`
void func_02147218(Unk02012f58 *a, s32 b, s32 c, s32 d) {
    s32 *p;

    p = (s32 *) a;
    p[0] = b;
    p[8] = d;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = c;
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    p[9] = 0;
    p[10] = 0;
    p[11] = 0;
}

#pragma thumb off

// non-matching: 0x7c bytes, original 0x34; 30 lines differ; first: original `stmfd sp!, {r4}`, ours `ldr r2, [r0]`
void func_021471e4(const Unk02012f58 *a, s32 *b) {
    const s32 *s;

    s = (const s32 *) a;
    b[0] = s[0];
    b[1] = s[1];
    b[2] = s[2];
    b[3] = 0;
    b[4] = s[3];
    b[5] = s[4];
    b[6] = s[5];
    b[7] = 0;
    b[8] = s[6];
    b[9] = s[7];
    b[10] = s[8];
    b[11] = 0;
    b[12] = s[9];
    b[13] = s[10];
    b[14] = s[11];
    b[15] = 0x1000;
}

// non-matching: 0x3c bytes, original 0x28; 14 lines differ; first: original `mov r3, #0`, ours `str r2, [r0]`
void func_021471bc(Unk02012f58 *a) {
    s32 *p;

    p = (s32 *) a;
    p[0] = 0x1000;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0x1000;
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    p[8] = 0x1000;
    p[9] = 0;
    p[10] = 0;
    p[11] = 0;
}
