#pragma once

#include "types.h"

#include "Main/MapObjects/data_0217b000.h"
#include "g2d_NAN_load.h" // NNSG2dCellDataBank

// Objects stored through the first parameter: Nscr by LocateNscr and LoadNscrData, Ncgr by
// LocateNcgr, LoadNcgrData, LocateNcgr2 and LoadNcgrData2, Nclr by LocateNclr and LoadNclrData,
// AnimBank by LoadNanrData, NNSG2dCellDataBank by LocateNcer and LoadNcerData (LoadNanrData passes it to
// NNS_G2dUnpackNAN, LoadNcerData to NNS_G2dUnpackNCE; LocateNcer looks up the same block tag as LoadNcerData).
typedef struct Ncgr {
    /* 0000 */ u16 mUnk_00;
    /* 0002 */ u16 mUnk_02;
    /* 0004 */ u8 mUnk_04[0xc];
    /* 0010 */ u32 mDataSize;
    /* 0014 */ u16 *mData;
} Ncgr;

typedef struct Nscr {
    /* 0000 */ u8 mUnk_00[8];
    /* 0008 */ u32 mDataSize;
    /* 000c */ u16 mData[1];
} Nscr;

typedef struct Nclr {
    /* 0000 */ u8 mUnk_00[4];
    /* 0004 */ s32 mUnk_04;
    /* 0008 */ u32 mDataSize;
    /* 000c */ u16 *mData;
} Nclr;

// One stack word whose address the functions above store different pointer types through.
typedef union LoadedPartPointer {
    Ncgr *mNcgr;
    Nscr *mNscr;
    Nclr *mNclr;
    NNSG2dCellDataBank *mNcer;
} LoadedPartPointer;

void *GetPlayerCharacterBncl(int param_1);
NNSG2dCellDataBank *GetPlayerCharacterNcer(int param_1);
Ncgr *GetPlayerCharacterNcgr(int param_1);
void *GetPlayerCharacterNclr(int param_1);
#include "Main/Graphics/chars_block.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/point_along_line.h"
NNSG2dFont *GetFontByIndex(s32 index);
Nclr *GetPlayerCharacterShyguyNclr(u32 index);

void LoadFontAndPlayerCharacterData(void);
void ClearFontAndPlayerCharacterTables(void);

#include "Main/Race/followed_kart_outside_box.h"
#include "code_02022aa8.h" // NNSG2dFont
