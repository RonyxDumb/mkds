#pragma once

#include "types.h"

typedef struct DGTHash1Context {
    /* 00 */ u32 mState[4];
    /* 10 */ u64 mLength;
    /* 18 */ u8 mBuffer8[0x38];
    /* 50 */ u32 mBitCountLow;
    /* 54 */ u32 mBitCountHigh;
} DGTHash1Context;

// A block is 64 bytes; this masks a byte count down to the position inside the block.
#define HASH_BLOCK_OFFSET_MASK 0x3f

extern u32 gHash1WordOrder[48];
extern u32 gHash1RoundConstants[64];

// Runs the 64 MD5 steps over the block in ctx and adds the result to the state.
void ProcessBlock(DGTHash1Context *ctx);
// Pads the data to a multiple of 64 bytes with the bit count, writes the 16 digest bytes to digest and clears ctx.
void DGT_Hash1GetDigest_R(void *digest, DGTHash1Context *ctx);
// Adds length bytes from input to the data being hashed, processing each full block.
void DGT_Hash1SetSource(DGTHash1Context *ctx, const void *input, u32 length);

void DGT_Hash1Reset(DGTHash1Context *ctx);
