#pragma once

#include "types.h"

// Header: a tag word at 0, a halfword at 4 and one at 6 (NNSi_G2dGetUnpackedFont compares it), a halfword at 0x0c
// (offset of the first part) and a halfword at 0x0e (number of parts). Each part starts with a tag word and its
// size.
typedef struct NNSG2dBinaryFileHeader {
    /* 00 */ u32 mSignature;
    /* 04 */ u16 mByteOrder;
    /* 06 */ u16 mVersion;
    /* 08 */ u8 mUnk_08[4];
    /* 0c */ u16 mHeaderSize;
    /* 0e */ u16 mDataBlocks;
} NNSG2dBinaryFileHeader;

// Start of each part: a word at 0 that FindPartByTag compares, and the size of the part at 4.
typedef struct NNSG2dBinaryBlockHeader {
    /* 00 */ u32 mKind;
    /* 04 */ u32 mSize;
} NNSG2dBinaryBlockHeader;

u32 NNS_G2dGetUnpackedScreenData(NNSG2dBinaryFileHeader *pNscrFile, NNSG2dBinaryBlockHeader **ppScrData);
NNSG2dBinaryBlockHeader *FindPartByTag(NNSG2dBinaryFileHeader *file, u32 tag);
