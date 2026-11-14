#pragma once

#include "types.h"
#include "g2d_NSC_load.h" // NNSG2dBinaryFileHeader
#include "code_02022aa8.h" // NNSG2dFontInformation

// Bit reader: a pointer to the next byte, the number of unread bits of the current byte at 4 and the byte at 5.
typedef struct NNSiG2dBitReader {
    /* 00 */ u8 *mSrc;
    /* 04 */ s8 mAvailableBits;
    /* 05 */ u8 mBits;
} NNSiG2dBitReader;

// Body of a part of an NNSG2dBinaryFileHeader, which starts 8 bytes after the part: words from 04 are offsets from the
// start of the NNSG2dBinaryFileHeader, relocated by NNSi_G2dUnpackNFT.
typedef struct FontBlockData {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u32 mFileOffsets[4];
} FontBlockData;

void NNSi_G2dUnpackNFT(NNSG2dBinaryFileHeader *file);
u32 NNSi_G2dGetUnpackedFont(NNSG2dBinaryFileHeader *file, NNSG2dFontInformation **fontOut);
u32 NNSi_G2dBitReaderRead(NNSiG2dBitReader *reader, s32 bitCount);
u16 NNSi_G2dSplitChar1Byte(u8 **stringPtr);
u16 NNSi_G2dSplitCharShiftJIS(u8 **stringPtr);
u16 NNSi_G2dSplitCharUTF8(u8 **stringPtr);
u16 NNSi_G2dSplitCharUTF16(u16 **stringPtr);
