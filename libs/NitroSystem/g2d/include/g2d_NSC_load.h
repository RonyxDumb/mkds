#pragma once

#include "types.h"

// Header: a tag word at 0, a halfword at 4 and one at 6 (NFTR_Process compares it), a halfword at 0x0c
// (offset of the first part) and a halfword at 0x0e (number of parts). Each part starts with a tag word and its
// size.
typedef struct Unk02021f9c {
    /* 00 */ u32 field0;
    /* 04 */ u16 field4;
    /* 06 */ u16 field6;
    /* 08 */ u8 field8[4];
    /* 0c */ u16 fieldC;
    /* 0e */ u16 fieldE;
} Unk02021f9c;

// Start of each part: a word at 0 that FindPartByTag compares, and the size of the part at 4.
typedef struct Unk02021fd0 {
    /* 00 */ u32 field0;
    /* 04 */ u32 field4;
} Unk02021fd0;

u32 NNS_G2dGetUnpackedScreenData(Unk02021f9c *pNscrFile, Unk02021fd0 **ppScrData);
Unk02021fd0 *FindPartByTag(Unk02021f9c *file, u32 tag);
