#include "code_02147954.h"

// non-matching: 0x64 bytes, original 0x34; 25 lines differ; first: original `ldm r0!, {r2, r3, ip}`, ours `ldr r2,
// [r0]`
void func_02147980(const s32 *a, Unk02012f58 *b) {
    s32 *d;

    d = (s32 *) b;
    d[0] = a[0];
    d[1] = a[1];
    d[2] = a[2];
    d[3] = a[4];
    d[4] = a[5];
    d[5] = a[6];
    d[6] = a[8];
    d[7] = a[9];
    d[8] = a[10];
    d[9] = a[12];
    d[10] = a[13];
    d[11] = a[14];
}

// non-matching: 0x4c bytes, original 0x2c; 18 lines differ; first: original `mov r3, #0`, ours `str r2, [r0]`
void func_02147954(s32 *a) {
    a[0] = 0x1000;
    a[1] = 0;
    a[2] = 0;
    a[3] = 0;
    a[4] = 0;
    a[5] = 0x1000;
    a[6] = 0;
    a[7] = 0;
    a[8] = 0;
    a[9] = 0;
    a[10] = 0x1000;
    a[11] = 0;
    a[12] = 0;
    a[13] = 0;
    a[14] = 0;
    a[15] = 0x1000;
}
