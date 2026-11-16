#pragma once

#include "types.h"

#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "animation_data_unpack.h" // NNSG2dCellDataBank

// A character graphics file: its row and column counts and its tile data.
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

// A screen map file: its data size and the map entries.
typedef struct Nscr {
    /* 0000 */ u8 mUnk_00[8];
    /* 0008 */ u32 mDataSize;
    /* 000c */ u16 mData[1];
} Nscr;

// A palette file: its data size and the colors.
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

void *GetPlayerCharacterBNCL_from_thumb(int index);
NNSG2dCellDataBank *GetPlayerCharacterNceNcer_from_thumb(int index);
Ncgr *GetPlayerCharacterNceNcgr_from_thumb(int index);
void *GetPlayerCharacterPalette_from_thumb(int index);
#include "Main/Graphics/chars_block.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Race/point_along_line.h"
NNSG2dFont *GetLoadedFont_from_thumb(s32 index);
Nclr *GetPlayerCharacterShyGuyPalette_from_thumb(u32 index);

void LoadMA2ContentIfMounted_from_thumb(void);
void CleanupPlayerGfxDataFontsEtc_from_thumb(void);

#include "Main/Race/followed_kart_outside_box.h"
#include "font_glyph_layout.h" // NNSG2dFont
