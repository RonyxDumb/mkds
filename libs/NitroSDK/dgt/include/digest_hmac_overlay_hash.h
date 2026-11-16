#pragma once

#include "types.h"

// Offset in the last block where the 64-bit bit count goes; padding that starts at or past it needs one more block.
#define DGT_HASH2_LENGTH_OFFSET 0x38

// The running state of a hash: five mWords, the bit count, the buffered bytes (mBufferLen) and the 64-byte mBlock.
typedef struct DGTHash2Context {
    /* 00 */ u32 mWords[5];
    /* 14 */ u32 mBitCountLow;
    /* 18 */ u32 mBitCountHigh;
    /* 1c */ int mBufferLen;
    /* 20 */ u8 mBlock[0x40];
    /* 60 */ u8 mUnk_60[8];
} DGTHash2Context;

typedef struct DGTHash2Context DGTHash2Context;

void DGT_Hash2CalcHmac(u8 *digest, const u8 *bin, u32 binLen, const u8 *key, s32 keyLen);
void DGTi_Hash2ProcessMessageBlock(DGTHash2Context *ctx, u8 *source, int length);
void DGT_Hash2GetDigest(DGTHash2Context *ctx, u8 *digest, ...);
void DGT_Hash2SetSource(DGTHash2Context *ctx, const u8 *input, u32 length);
void DGT_Hash2Reset(DGTHash2Context *ctx);
u32 DGT_SetOverlayTableMode(u32 flag);

// Days before each month in a non-leap year (DWC copy of the RTC table).
extern s32 sMonthStartDay[12];
// Function pointer that DGT_SetOverlayTableMode switches between DGTi_Hash2ProcessMessageBlock and
// DGTi_hash2_arm4_small.
extern void (*DGTi_Hash2ProcessMessageBlockFunc)(DGTHash2Context *ctx, u8 *source, int length);
