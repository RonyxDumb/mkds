#include "Main/Unknown/code_0200635c.h"
#include "Main/Unknown/code_0200589c.h"

#pragma thumb on

void MarkChunkReceived(WBTPacketBitmap *bitmap, u32 chunkIndex) {
    bitmap->mCount = bitmap->mCount + 1;
    bitmap->mCurrent = chunkIndex;
    *GetPacketBitmapWord(bitmap, chunkIndex) = *GetPacketBitmapWord(bitmap, chunkIndex) | 1 << (chunkIndex & 0x1f);
}

#pragma thumb off
