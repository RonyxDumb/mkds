#include "digest_hmac_overlay_hash.h"

#include "cpu_copy_fill.h"
#include "digest_hash_block.h"

s32 sMonthStartDay[12] = {0, 0x1f, 0x3b, 0x5a, 0x78, 0x97, 0xb5, 0xd4, 0xf3, 0x111, 0x130, 0x14e};
void (*DGTi_Hash2ProcessMessageBlockFunc)(DGTHash2Context *ctx, u8 *source, int length) = DGTi_hash2_arm4_small;
u32 DGTi_OverlayTableMode;

// Selects the block routine DGT_Hash2SetSource and DGT_Hash2GetDigest call: the overlay-table one when flag is
// nonzero. Returns the previous flag.
u32 DGT_SetOverlayTableMode(u32 flag) {
    u32 prev;

    prev = DGTi_OverlayTableMode;
    DGTi_OverlayTableMode = flag;
    if (flag != 0) {
        DGTi_Hash2ProcessMessageBlockFunc = DGTi_Hash2ProcessMessageBlock;
    } else {
        DGTi_Hash2ProcessMessageBlockFunc = DGTi_hash2_arm4_small;
    }
    return prev;
}

// Starts a SHA-1 computation.
void DGT_Hash2Reset(DGTHash2Context *ctx) {
    ctx->mWords[0] = 0x67452301u;
    ctx->mWords[1] = 0xefcdab89u;
    ctx->mWords[2] = 0x98badcfeu;
    ctx->mWords[3] = 0x10325476u;
    ctx->mWords[4] = 0xc3d2e1f0u;
    ctx->mBitCountLow = 0x0u;
    ctx->mBitCountHigh = 0x0u;
    ctx->mBufferLen = 0x0u;
}

// Adds length bytes of input to the SHA-1 computation, hashing each full 64-byte block as it fills.
void DGT_Hash2SetSource(DGTHash2Context *ctx, const u8 *input, u32 length) {
    u8 *buffer;
    u32 lowSum;
    u32 buffered;
    u32 chunk;

    buffer = ctx->mMessageBlock;
    if (length == 0) {
        return;
    }
    lowSum = ctx->mBitCountLow + (length << 3);
    if (lowSum < ctx->mBitCountLow) {
        ctx->mBitCountHigh++;
    }
    ctx->mBitCountHigh += length >> 29;
    ctx->mBitCountLow = lowSum;
    buffered = ctx->mBufferLen;
    if (buffered != 0) {
        if (buffered + length >= 0x40) {
            chunk = 0x40 - buffered;
            MI_CpuCopy8(input, buffer + buffered, chunk);
            length -= chunk;
            input += chunk;
            DGTi_Hash2ProcessMessageBlockFunc(ctx, buffer, 0x40);
            ctx->mBufferLen = 0;
        } else {
            MI_CpuCopy8(input, buffer + buffered, length);
            ctx->mBufferLen += length;
            return;
        }
    }
    if (length >= 0x40) {
        chunk = length & ~0x3f;
        length -= chunk;
        if (((u32) input & 3) == 0) {
            DGTi_Hash2ProcessMessageBlockFunc(ctx, (u8 *) input, chunk);
            input += chunk;
        } else {
            do {
                MI_CpuCopy8(input, buffer, 0x40);
                input += 0x40;
                DGTi_Hash2ProcessMessageBlockFunc(ctx, buffer, 0x40);
                chunk -= 0x40;
            } while ((int) chunk > 0);
        }
    }
    ctx->mBufferLen = length;
    if (length == 0) {
        return;
    }
    MI_CpuCopy8(input, buffer, length);
}

// Pads the last block with 0x80, zeros and the bit count (hashing the block first if 56 or more bytes are buffered),
// then writes the 20 digest bytes of the five state words to digest.
void DGT_Hash2GetDigest(DGTHash2Context *ctx, u8 *digest, ...) {
    volatile u32 zero;
    u32 *blockWords;
    u8 *blockBytes;
    int len;
    int wordIndex;
    u32 value;

    len = ctx->mBufferLen;
    blockWords = (u32 *) ctx->mMessageBlock;
    wordIndex = len >> 2;
    if ((len & 3) == 0) {
        blockWords[wordIndex] = 0;
    }
    blockBytes = ctx->mMessageBlock;
    blockBytes[len] = 0x80;
    len++;
    while ((len & 3) != 0) {
        blockBytes[len] = 0;
        len++;
    }
    wordIndex++;
    if (ctx->mBufferLen >= DGT_HASH2_LENGTH_OFFSET) {
        for (; wordIndex < 16; wordIndex++) {
            blockWords[wordIndex] = 0;
        }
        DGTi_Hash2ProcessMessageBlockFunc(ctx, (u8 *) blockWords, 0x40);
        wordIndex = 0;
    }
    for (; wordIndex < 14; wordIndex++) {
        blockWords[wordIndex] = 0;
    }
    value = ctx->mBitCountLow;
    blockBytes[0x3f] = value;
    blockBytes[0x3e] = value >> 8;
    blockBytes[0x3d] = value >> 16;
    blockBytes[0x3c] = value >> 24;
    value = ctx->mBitCountHigh;
    blockBytes[0x3b] = value;
    blockBytes[0x3a] = value >> 8;
    blockBytes[0x39] = value >> 16;
    blockBytes[0x38] = value >> 24;
    DGTi_Hash2ProcessMessageBlockFunc(ctx, (u8 *) blockWords, 0x40);
    value = ctx->mWords[0];
    digest[0] = value >> 24;
    digest[1] = value >> 16;
    digest[2] = value >> 8;
    digest[3] = value;
    value = ctx->mWords[1];
    digest[4] = value >> 24;
    digest[5] = value >> 16;
    digest[6] = value >> 8;
    digest[7] = value;
    value = ctx->mWords[2];
    digest[8] = value >> 24;
    digest[9] = value >> 16;
    digest[10] = value >> 8;
    digest[11] = value;
    value = ctx->mWords[3];
    digest[12] = value >> 24;
    digest[13] = value >> 16;
    digest[14] = value >> 8;
    digest[15] = value;
    value = ctx->mWords[4];
    digest[16] = value >> 24;
    digest[17] = value >> 16;
    digest[18] = value >> 8;
    digest[19] = value;
    ctx->mBufferLen = 0;
    zero = 0;
    MIi_CpuClear32(zero, &ctx, 4);
}

// Hashes the length / 64 whole blocks of source, with the words at offsets 0x18 and 0x38 of each block set to 0 while
// it is hashed and restored afterwards.
void DGTi_Hash2ProcessMessageBlock(DGTHash2Context *ctx, u8 *source, int length) {
    u32 saved18;
    u32 saved38;
    u32 *words;
    int blockIndex;
    int blocks;

    blocks = length / 64;
    for (blockIndex = 0; blockIndex < blocks; blockIndex++) {
        words = (u32 *) source;
        saved18 = words[6];
        saved38 = words[14];
        words[6] = 0;
        words[14] = 0;
        DGTi_hash2_arm4_small(ctx, source, 0x40);
        words[6] = saved18;
        words[14] = saved38;
        source += 0x40;
    }
}

// HMAC-SHA-1 of bin with key, written to digest; a key longer than 64 bytes is hashed down first. Does nothing if
// digest, bin or key is NULL or binLen or keyLen is 0.
void DGT_Hash2CalcHmac(u8 *digest, const u8 *binPtr, u32 binLen, const u8 *keyPtr, s32 keyLen) {
    u8 innerKeyBlock[0x40];
    u8 outerKeyBlock[0x40];
    u8 tempDigest[0x14];
    DGTHash2Context ctx;
    u8 *tempDigestPtr;
    s32 keyIndex;

    tempDigestPtr = tempDigest;
    if (digest == 0 || binPtr == 0 || binLen == 0 || keyPtr == 0 || keyLen == 0) {
        return;
    }
    if (keyLen > 0x40) {
        DGT_Hash2Reset(&ctx);
        DGT_Hash2SetSource(&ctx, keyPtr, keyLen);
        DGT_Hash2GetDigest(&ctx, tempDigestPtr);
        keyPtr = tempDigestPtr;
        keyLen = 0x14;
    }
    for (keyIndex = 0; keyIndex < keyLen; keyIndex++) {
        innerKeyBlock[keyIndex] = *keyPtr ^ 0x36;
        outerKeyBlock[keyIndex] = *keyPtr++ ^ 0x5c;
    }
    for (; keyIndex < 0x40; keyIndex++) {
        innerKeyBlock[keyIndex] = 0x36;
        outerKeyBlock[keyIndex] = 0x5c;
    }
    DGT_Hash2Reset(&ctx);
    DGT_Hash2SetSource(&ctx, innerKeyBlock, 0x40);
    DGT_Hash2SetSource(&ctx, binPtr, binLen);
    DGT_Hash2GetDigest(&ctx, tempDigestPtr);
    DGT_Hash2Reset(&ctx);
    DGT_Hash2SetSource(&ctx, outerKeyBlock, 0x40);
    DGT_Hash2SetSource(&ctx, tempDigestPtr, 0x14);
    DGT_Hash2GetDigest(&ctx, digest);
}
