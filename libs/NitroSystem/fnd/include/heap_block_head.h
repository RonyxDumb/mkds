#pragma once

#include "types.h"

// A free region smaller than this cannot hold the header of a block and is dropped.
#define EXP_HEAP_MIN_FREE_BLOCK_SIZE 0x10

// The header before each block of an Exp heap, linking the blocks through mMBHeadPrev and mMBHeadNext.
// mAttribute holds the group ID, the offset to the start of the block and the end of the heap the block was taken from.
typedef struct NNSiFndExpHeapMBlockHead {
    /* 00 */ u16 mSignature;
    /* 02 */ u16 mAttribute;
    /* 04 */ u32 mBlockSize;
    /* 08 */ struct NNSiFndExpHeapMBlockHead *mMBHeadPrev;
    /* 0c */ struct NNSiFndExpHeapMBlockHead *mMBHeadNext;
} NNSiFndExpHeapMBlockHead;

// Start and end of a block of memory: Mem_GetMemoryBlockRegion writes the start of a block (minus its offset) and the end of
// its data.
typedef struct NNSiMemRegion {
    /* 00 */ void *mStart;
    /* 04 */ void *mEnd;
} NNSiMemRegion;

NNSiFndExpHeapMBlockHead *Mem_Exp_InitializeMemoryBlock(const NNSiMemRegion *region, u16 signature);
