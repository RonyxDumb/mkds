#include "Main/Unknown/code_0200635c.h"
#include "Main/Unknown/code_0200589c.h"

#pragma thumb on

void MarkChunkReceived(WBTPacketBitmap *a, u32 b) {
    a->mCount = a->mCount + 1;
    a->mCurrent = b;
    a->mBitmap[(s32) b >> 5] = a->mBitmap[(s32) b >> 5] | 1 << (b & 0x1f);
}

#pragma thumb off
