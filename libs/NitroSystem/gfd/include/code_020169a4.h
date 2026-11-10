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

s32 NNSi_GfdFreeLnkVram(NNSiGfdLnkVramBlock **a, NNSiGfdLnkVramBlock **b, u32 c, u32 d);
s32 NNSi_GfdAllocLnkVramAligned(NNSiGfdLnkVramBlock **a, NNSiGfdLnkVramBlock **b, u32 *c, u32 d, u32 e);
s32 NNSi_GfdAllocLnkVram(NNSiGfdLnkVramBlock **a, NNSiGfdLnkVramBlock **b, u32 *c, u32 d);
s32 NNSi_GfdAddNewFreeBlock(NNSiGfdLnkVramBlock **a, NNSiGfdLnkVramBlock **b, u32 c, u32 d);
NNSiGfdLnkVramBlock *NNSi_GfdInitLnkVramBlockPool(NNSiGfdLnkVramBlock *p, u32 n);
