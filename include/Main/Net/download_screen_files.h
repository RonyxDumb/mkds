#pragma once

#include "types.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "touch_panel_sampling.h"
#include "Main/Race/race_goal_times.h"
#include "Main/Graphics/font_and_player_character.h"

// The loaded files of the download screen: the search icon, the multiboot child font and messages, the download chars.
typedef struct DownloadScreenFiles {
    /* 00 */ void *mSearchIconCellLayout;
    /* 04 */ void *mSearchIconLayoutCellLayout;
    /* 08 */ Ncgr *mSearchIconChars;
    /* 0c */ NNSG2dCellDataBank *mSearchIconCells;
    /* 10 */ Nclr *mSearchIconPalette;
    /* 14 */ void *mMBChildFont;
    /* 18 */ u8 mUnk_18[8];
    /* 20 */ struct Bmg *mMBChildMessages;
    /* 24 */ Ncgr *mMultiDownloadChars;
    /* 28 */ Nclr *mMultiDownloadPalette;
} DownloadScreenFiles;

void LoadStatic2DContents(void *heap);

extern struct DownloadScreenFiles *g_Global2D;
