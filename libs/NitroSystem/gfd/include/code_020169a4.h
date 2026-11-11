#pragma once

#include "types.h"

// 16 bytes: an address and a size, linked through two pointers to other NNSiGfdLnkVramBlock (NNSi_GfdFreeLnkVram and
// NNSi_GfdAllocLnkVramAligned unlink and relink them).
typedef struct NNSiGfdLnkVramBlock {
    /* 00 */ u32 mAddr;
    /* 04 */ u32 mSzByte;
    /* 08 */ struct NNSiGfdLnkVramBlock *mPBlkPrev;
    /* 0c */ struct NNSiGfdLnkVramBlock *mPBlkNext;
} NNSiGfdLnkVramBlock;

s32 NNSi_GfdFreeLnkVram(NNSiGfdLnkVramBlock **freeListHead, NNSiGfdLnkVramBlock **spareListHead, u32 addr, u32 size);
s32 NNSi_GfdAllocLnkVramAligned(NNSiGfdLnkVramBlock **freeListHead, NNSiGfdLnkVramBlock **spareListHead, u32 *outAddr,
                                u32 size, u32 alignment);
s32 NNSi_GfdAllocLnkVram(NNSiGfdLnkVramBlock **freeListHead, NNSiGfdLnkVramBlock **spareListHead, u32 *outAddr,
                         u32 size);
s32 NNSi_GfdAddNewFreeBlock(NNSiGfdLnkVramBlock **freeListHead, NNSiGfdLnkVramBlock **spareListHead, u32 addr,
                            u32 size);
NNSiGfdLnkVramBlock *NNSi_GfdInitLnkVramBlockPool(NNSiGfdLnkVramBlock *blocks, u32 count);
