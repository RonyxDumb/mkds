#pragma once

#include "types.h"

#include "Main/MapObjects/data_0217b000.h"
#include "g2d_NAN_load.h" // NNSG2dCellDataBank

// Objects stored through the first parameter: Nscr by LocateNscr and LoadNscrData, Ncgr by
// LocateNcgr, LoadNcgrData, LocateNcgr2 and LoadNcgrData2, Nclr by LocateNclr and LoadNclrData,
// AnimBank by LoadNanrData, NNSG2dCellDataBank by LocateNcer and LoadNcerData (LoadNanrData passes it to
// NNS_G2dUnpackNAN, LoadNcerData to NNS_G2dUnpackNCE; LocateNcer looks up the same block tag as LoadNcerData).
typedef struct Ncgr {
    /* 0000 */ u16 mRowCount;
    /* 0002 */ u16 mColumnCount;
    /* 0004 */ u8 mUnk_04[0xc];
    /* 0010 */ u32 mDataSize;
    union {
        /* 0014 */ u16 *mData;
        u8 *mBytes;
        struct CharTile *mTiles;
    };
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
    union {
        /* 000c */ u16 *mData;
        u8 *mBytes;
    };
} Nclr;

// One stack word whose address the functions above store different pointer types through.
typedef union LoadedPartPointer {
    Ncgr *mNcgr;
    Nscr *mNscr;
    Nclr *mNclr;
    NNSG2dCellDataBank *mNcer;
} LoadedPartPointer;

void *GetPlayerCharacterBncl(int index);
NNSG2dCellDataBank *GetPlayerCharacterNcer(int index);
Ncgr *GetPlayerCharacterNcgr(int index);
void *GetPlayerCharacterNclr(int index);
#include "Main/Graphics/chars_block.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/point_along_line.h"
NNSG2dFont *GetFontByIndex(s32 index);
Nclr *GetPlayerCharacterShyguyNclr(u32 index);

void LoadFontAndPlayerCharacterData(void);
void ClearFontAndPlayerCharacterTables(void);

#include "Main/Race/followed_kart_outside_box.h"
#include "code_02022aa8.h" // NNSG2dFont
