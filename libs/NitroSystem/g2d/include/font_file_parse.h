#pragma once

#include "types.h"
#include "screen_data_unpack.h" // NNSG2dBinaryFileHeader
#include "font_glyph_layout.h" // NNSG2dFontInformation

// Bit reader: a pointer to the next byte, the number of unread bits of the current byte at 4 and the byte at 5.
typedef struct NNSiG2dBitReader {
    /* 00 */ u8 *mSrc;
    /* 04 */ s8 mAvailableBits;
    /* 05 */ u8 mBits;
} NNSiG2dBitReader;

// Values of NNSG2dBinaryBlockHeader.mKind in a font file: the four block name letters read as one word.
enum {
    FONT_BLOCK_INFO = 0x46494e46,
    FONT_BLOCK_WIDTHS = 0x43574448,
    FONT_BLOCK_CHAR_MAP = 0x434d4150,
    FONT_BLOCK_GLYPHS = 0x43474c50,
};

// The body of a font file part: file offsets that NFTR_MakeAbsoluteOffsets relocates to addresses.
typedef struct FontBlockData {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u32 mFileOffsets[4];
} FontBlockData;

void NFTR_MakeAbsoluteOffsets(NNSG2dBinaryFileHeader *file);
u32 NFTR_Process(NNSG2dBinaryFileHeader *file, NNSG2dFontInformation **fontOut);
u32 NNSi_G2dBitReaderRead(NNSiG2dBitReader *reader, s32 bitCount);
u16 FontEncoding_CP1252_NextCharacter(u8 **stringPtr);
u16 FontEncoding_SJIS_NextCharacter(u8 **stringPtr);
u16 FontEncoding_UTF8_NextCharacter(u8 **stringPtr);
u16 FontEncoding_Unicode_NextCharacter(u16 **stringPtr);
