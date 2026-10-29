#include "code_02150e1c.h"

// non-matching: hand-written routine (word-sized rotations folded into the operands, a 16-word window of the schedule
// kept in a 32-word stack area); this C follows its behaviour only
void func_02150e1c(Unk02150a10 *ctx, u8 *data, int n) {
    u32 w[80];
    u32 a;
    u32 b;
    u32 c;
    u32 d;
    u32 e;
    u32 t;
    u32 x;
    int i;

    a = ctx->mUnk_00[0];
    b = ctx->mUnk_00[1];
    c = ctx->mUnk_00[2];
    d = ctx->mUnk_00[3];
    e = ctx->mUnk_00[4];
    do {
        for (i = 0; i < 16; i++) {
            x = ((u32 *) data)[i];
            w[i] = (x << 24) | ((x & 0xff00) << 8) | ((x >> 8) & 0xff00) | (x >> 24);
        }
        data += 0x40;
        for (i = 16; i < 80; i++) {
            x = w[i - 3] ^ w[i - 8] ^ w[i - 14] ^ w[i - 16];
            w[i] = (x << 1) | (x >> 31);
        }
        for (i = 0; i < 80; i++) {
            if (i < 20) {
                t = (((c ^ d) & b) ^ d) + 0x5a827999;
            } else if (i < 40) {
                t = (b ^ c ^ d) + 0x6ed9eba1;
            } else if (i < 60) {
                t = (((b | c) & d) | (b & c)) + 0x8f1bbcdc;
            } else {
                t = (b ^ c ^ d) + 0xca62c1d6;
            }
            t += ((a << 5) | (a >> 27)) + e + w[i];
            e = d;
            d = c;
            c = (b << 30) | (b >> 2);
            b = a;
            a = t;
        }
        ctx->mUnk_00[0] += a;
        ctx->mUnk_00[1] += b;
        ctx->mUnk_00[2] += c;
        ctx->mUnk_00[3] += d;
        ctx->mUnk_00[4] += e;
        a = ctx->mUnk_00[0];
        b = ctx->mUnk_00[1];
        c = ctx->mUnk_00[2];
        d = ctx->mUnk_00[3];
        e = ctx->mUnk_00[4];
        n -= 64;
    } while (n > 0);
}
