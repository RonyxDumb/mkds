#pragma once

#include "types.h"
#include "g2d_NSC_load.h" // Unk02021f9c
#include "code_02022aa8.h" // Unk02022ce4

// Bit reader: a pointer to the next byte, the number of unread bits of the current byte at 4 and the byte at 5.
typedef struct Unk020247fc {
    /* 00 */ u8 *field0;
    /* 04 */ s8 field4;
    /* 05 */ u8 field5;
} Unk020247fc;

// Body of a part of an Unk02021f9c, which starts 8 bytes after the part: words from 04 are offsets from the start of
// the Unk02021f9c, relocated by NFTR_MakeAbsoluteOffsets.
typedef struct Unk020245a4_08 {
    /* 00 */ u8 field0[4];
    /* 04 */ u32 field4[4];
} Unk020245a4_08;

void NFTR_MakeAbsoluteOffsets(Unk02021f9c *a);
u32 NFTR_Process(Unk02021f9c *a, Unk02022ce4 **b);
u32 BitStreamReadBits(Unk020247fc *a, s32 b);
u16 CharReadByte(u8 **a);
u16 CharReadByteOrPair(u8 **a);
u16 CharReadOneToThreeBytes(u8 **a);
u16 CharReadHalfword(u16 **a);
