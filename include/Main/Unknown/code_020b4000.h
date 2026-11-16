#pragma once

#include "types.h"

#include "Main/Unknown/unk_0217b000.h"
#include "g2d_NAN_load.h" // Unk02021dc8

// Objects stored through the first parameter: Nscr by g2du_getScreenData and g2du_unpackScreenData, Ncgr by
// g2du_getCharacterDataBG, g2du_unpackCharacterDataBG, g2du_getCharacterData and g2du_unpackCharacterData, Nclr by g2du_getPaletteData and g2du_unpackPaletteData,
// Unk02021dc8 by g2du_unpackAnimBank, g2du_getCellBankData and g2du_unpackCellBankData (g2du_unpackAnimBank passes it to NNS_G2dUnpackNAN,
// g2du_unpackCellBankData to NNS_G2dUnpackNCE; g2du_getCellBankData looks up the same block tag as g2du_unpackCellBankData).
typedef struct Ncgr {
    /* 0000 */ u16 field0;
    /* 0002 */ u16 field2;
    /* 0004 */ u8 field4[0xc];
    /* 0010 */ u32 mDataSize;
    /* 0014 */ u16 *mData;
} Ncgr;

typedef struct Nscr {
    /* 0000 */ u8 pad_00[8];
    /* 0008 */ u32 mDataSize;
    /* 000c */ u16 mData[1];
} Nscr;

typedef struct Nclr {
    /* 0000 */ u8 pad_00[4];
    /* 0004 */ s32 field4;
    /* 0008 */ u32 mDataSize;
    /* 000c */ u16 *mData;
} Nclr;

// One stack word whose address the functions above store different pointer types through.
typedef union LoadedPartPointer {
    Ncgr *mNcgr;
    Nscr *mNscr;
    Nclr *mNclr;
    Unk02021dc8 *mNcer;
} LoadedPartPointer;

// Declared here until the code that defines them is decompiled.
void *m2d_getPortraitBncl(int param_1);
Unk02021dc8 *m2d_getPortraitNceNcer(int param_1);
Ncgr *m2d_getPortraitNceNcgr(int param_1);
void *m2d_getPortraitONclr(int param_1);
#include "Main/Unknown/code_020b41e8.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b4e70.h"
Unk02022aa8 *m2d_getFont(s32 index);
Nclr *m2d_getPortraitShyGuyONclr(u32 index);
#include "Main/Unknown/code_020b4048.h"
#include "Main/Unknown/code_020b4e0c.h"
#include "code_02022aa8.h" // Unk02022aa8
