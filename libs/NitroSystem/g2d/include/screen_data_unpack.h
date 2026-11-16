#pragma once

#include "types.h"

// Value of NNSG2dBinaryFileHeader.mSignature of a font file.
#define G2D_FONT_SIGNATURE 0x4e465452

// The header of a G2D binary file: signature, byte order, version, size, header size and block count.
typedef struct NNSG2dBinaryFileHeader {
    /* 00 */ u32 mSignature;
    /* 04 */ u16 mByteOrder;
    /* 06 */ u16 mVersion;
    /* 08 */ u8 mFileSize[4];
    /* 0c */ u16 mHeaderSize;
    /* 0e */ u16 mDataBlocks;
} NNSG2dBinaryFileHeader;

// The header of each part of a binary file: its kind, which FindPartByTag compares, and its size.
typedef struct NNSG2dBinaryBlockHeader {
    /* 00 */ u32 mKind;
    /* 04 */ u32 mSize;
} NNSG2dBinaryBlockHeader;

u32 NNS_G2dGetUnpackedScreenData(NNSG2dBinaryFileHeader *pNscrFile, NNSG2dBinaryBlockHeader **ppScrData);
NNSG2dBinaryBlockHeader *FindPartByTag(NNSG2dBinaryFileHeader *file, u32 tag);
