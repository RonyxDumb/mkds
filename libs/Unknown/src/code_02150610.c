#include "code_02150610.h"
#include "Main/Unknown/code_02150000.h"
#include "Main/Unknown/code_0214d000.h"

u8 data_0216f0a8 = 0x80;

void func_021506d4(Unk02150610 *ctx, const u8 *src, u32 n) {
    u32 off;
    u32 room;
    int blocks;
    const u8 *p;

    off = (u32) ctx->mUnk_10 & 0x3f;
    ctx->mUnk_10 += n;
    room = 0x40 - off;
    if (room > n) {
        if (n == 0) {
            return;
        }
        func_0214d1fc(src, ctx->mUnk_18 + off, n);
        return;
    }
    func_0214d1fc(src, ctx->mUnk_18 + off, room);
    func_02150228(ctx);
    n -= room;
    blocks = n >> 6;
    p = src + room;
    for (; blocks > 0; blocks--) {
        func_0214d1fc(p, ctx->mUnk_18, 0x40);
        p += 0x40;
        func_02150228(ctx);
    }
    if ((n & 0x3f) == 0) {
        return;
    }
    func_0214d1fc(p, ctx->mUnk_18, n & 0x3f);
}

// non-matching: the byte count is loaded into r1 where the original holds it in r3 (mov r1, #0 for the fill value
// comes before it); 9 words differ from +0x38 on.
void func_02150610(u8 *out, Unk02150610 *ctx) {
    u32 lo;
    u32 hi;
    u32 n;
    u32 m;
    u64 bits;

    bits = ctx->mUnk_10 << 3;
    lo = (u32) bits;
    hi = (u32) (bits >> 32);
    func_021506d4(ctx, &data_0216f0a8, 1);
    n = (u32) ctx->mUnk_10 & 0x3f;
    m = 0x40 - n;
    if (m < 8) {
        func_0214d168(ctx->mUnk_18 + n, 0, m);
        func_02150228(ctx);
        n = 0;
        m = 0x40;
    }
    if (m > 8) {
        func_0214d168(ctx->mUnk_18 + n, 0, m - 8);
    }
    ctx->mUnk_50 = lo;
    ctx->mUnk_54 = hi;
    func_02150228(ctx);
    func_0214d1fc(ctx, out, 0x10);
    func_0214d168(ctx, 0, 0x58);
}
