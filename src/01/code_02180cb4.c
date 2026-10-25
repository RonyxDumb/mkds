#include "01/code_02180cb4.h"
#include "01/code_021811c8.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_0214d000.h"

// non-matching: the fifth parameter stays in its stack slot and dx/dy are in r7/r6 in the original (frame 0x1c, 0x118 bytes);
// here the parameter is in r7 and dx and i are spilled (frame 0x24, 0x120 bytes)
s32 func_ov001_02180eec(s32 p0, s32 p1, s32 p2, s32 p3, s32 p4) {
    s32 changed;
    s32 dx;
    s32 dy;
    s32 stepX;
    s32 stepY;
    s32 n;
    s32 i;
    u8 *ptr;

    changed = 0;
    if ((p2 >> 12) > (p0 >> 12)) {
        dx = p2 - p0;
    } else if ((p0 >> 12) > (p2 >> 12)) {
        dx = p0 - p2;
    } else {
        dx = 0;
    }
    if ((p3 >> 12) > (p1 >> 12)) {
        dy = p3 - p1;
    } else if ((p1 >> 12) > (p3 >> 12)) {
        dy = p1 - p3;
    } else {
        dy = 0;
    }
    if (dx == 0) {
        stepX = 0;
    } else if (dx < dy) {
        stepX = func_02147f34(p2 - p0, dy);
    } else if (p2 > p0) {
        stepX = 0x1000;
    } else {
        stepX = -0x1000;
    }
    if (dy == 0) {
        stepY = 0;
    } else if (dy < dx) {
        stepY = func_02147f34(p3 - p1, dx);
    } else if (p3 > p1) {
        stepY = 0x1000;
    } else {
        stepY = -0x1000;
    }
    if (dx > dy) {
        n = dx >> 12;
    } else {
        n = dy >> 12;
    }
    for (i = 0; i <= n; i++) {
        ptr = func_ov001_02181200(p0 >> 12, p1 >> 12);
        if (ptr != 0 && *ptr != p4) {
            changed = 1;
            func_ov001_021811c8();
            *ptr = p4;
        }
        p0 += stepX;
        p1 += stepY;
    }
    ptr = func_ov001_02181200(p2 >> 12, p3 >> 12);
    if (ptr != 0 && *ptr != p4) {
        changed = 1;
        func_ov001_021811c8();
        *ptr = p4;
    }
    return changed;
}

// non-matching: the original keeps x, y, lim[2] and the two scan bytes in one 6-byte stack area addressed through r4 (sp+0x24),
// walks lim with r5, reads mUnk_2c once per pop and passes a stack zero as the first argument (frame 0x3c, 0x204 bytes);
// here the frame is 0x34, mUnk_2c is reloaded and lim is indexed (0x20c bytes)
s32 func_ov001_02180ce8(s32 p0, s32 p1, s32 p2) {
    s32 result;
    s32 top;
    s32 k;
    s32 m;
    s32 zero;
    u8 *ptr;
    u8 val;
    u8 buf[6];
    s32 py;

    buf[0] = p0;
    buf[1] = p1;
    result = 0;
    ptr = func_ov001_02181200(buf[0], buf[1]);
    if (ptr != 0) {
        val = *ptr;
        if (val != p2) {
            top = 1;
            data_ov001_021a9b88->mUnk_2c[0] = buf[0];
            data_ov001_021a9b88->mUnk_2c[1] = buf[1];
            zero = 0;
            func_0214d05c(zero, data_ov001_021a9b88->mUnk_28, data_ov001_021a9b88->mUnk_00 * data_ov001_021a9b88->mUnk_00);
            do {
                s32 steps[2] = {-1, 1};

                top--;
                buf[0] = data_ov001_021a9b88->mUnk_2c[top * 2];
                buf[1] = data_ov001_021a9b88->mUnk_2c[top * 2 + 1];
                py = buf[1];
                for (k = 0; k < 2; k++) {
                    buf[2 + k] = buf[0];
                    for (;;) {
                        ptr = func_ov001_02181200(buf[2 + k], py);
                        if (ptr != 0 && *ptr == val) {
                            data_ov001_021a9b88->mUnk_28[buf[2 + k] + py * data_ov001_021a9b88->mUnk_00] = 1;
                            buf[2 + k] += steps[k];
                        } else {
                            break;
                        }
                    }
                    buf[2 + k] -= steps[k];
                }
                for (m = 0; m < 2; m++) {
                    buf[5] = py + steps[m];
                    for (buf[4] = buf[2]; buf[4] <= buf[3]; buf[4]++) {
                        ptr = func_ov001_02181200(buf[4], buf[5]);
                        if (ptr != 0 && *ptr == val && data_ov001_021a9b88->mUnk_28[buf[4] + buf[5] * data_ov001_021a9b88->mUnk_00] == 0) {
                            do {
                                buf[4]++;
                                ptr = func_ov001_02181200(buf[4], buf[5]);
                            } while (ptr != 0 && *ptr == val && data_ov001_021a9b88->mUnk_28[buf[4] + buf[5] * data_ov001_021a9b88->mUnk_00] == 0);
                            buf[4]--;
                            data_ov001_021a9b88->mUnk_2c[top * 2] = buf[4];
                            data_ov001_021a9b88->mUnk_2c[top * 2 + 1] = buf[5];
                            top++;
                        }
                    }
                }
            } while (top > 0);
            result = 1;
            func_ov001_021811c8();
            for (buf[1] = 0; buf[1] < data_ov001_021a9b88->mUnk_00; buf[1]++) {
                for (buf[0] = 0; buf[0] < data_ov001_021a9b88->mUnk_00; buf[0]++) {
                    if (data_ov001_021a9b88->mUnk_28[buf[1] * data_ov001_021a9b88->mUnk_00 + buf[0]] != 0) {
                        *func_ov001_02181200(buf[0], buf[1]) = p2;
                    }
                }
            }
        }
    }
    return result;
}

// non-matching: the original indexes the loop (lsls r2,r4,#1; strh r3,[r0,r2]) with push {r4, lr}; this compiles to a pointer walk (0x18 vs 0x1c bytes)
void func_ov001_02180ccc(u16 *p0) {
    s32 i;

    for (i = 0; i < 0x3000; i++) {
        p0[i] = 0;
    }
}

void func_ov001_02180cb4(u16 *p0) {
    u16 i;

    for (i = 0; i < 0x300; i++) {
        p0[i] = i;
    }
}
