#pragma once

#include "types.h"
#include "g2d_NSC_load.h" // Unk02021f9c
#include "code_02022aa8.h" // Unk02022ce4

// Bit reader: a pointer to the next byte, the number of unread bits of the current byte at 4 and the byte at 5.
typedef struct NNSiG2dBitReader {
    /* 00 */ u8 *mSrc;
    /* 04 */ s8 mAvailableBits;
    /* 05 */ u8 mBits;
} NNSiG2dBitReader;

// Body of a part of an Unk02021f9c, which starts 8 bytes after the part: words from 04 are offsets from the start of
// the Unk02021f9c, relocated by NNSi_G2dUnpackNFT.
typedef struct Unk020245a4_08 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u32 mUnk_04[4];
} Unk020245a4_08;

void NNSi_G2dUnpackNFT(Unk02021f9c *a);
u32 NNSi_G2dGetUnpackedFont(Unk02021f9c *a, Unk02022ce4 **b);
u32 NNSi_G2dBitReaderRead(NNSiG2dBitReader *a, s32 b);
u16 NNSi_G2dSplitChar1Byte(u8 **a);
u16 NNSi_G2dSplitCharShiftJIS(u8 **a);
u16 NNSi_G2dSplitCharUTF8(u8 **a);
u16 NNSi_G2dSplitCharUTF16(u16 **a);
