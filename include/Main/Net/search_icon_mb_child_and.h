#pragma once

#include "types.h"
#include "Main/MapObjects/data_0217b000.h"
#include "tp.h"
#include "Main/Race/race_goal_times.h"
#include "Main/Graphics/font_and_player_character.h"

// Object behind gDownloadScreenFiles, allocated 0x2c bytes long by CreateSearchIconMBChildAndMultiDownload.
typedef struct DownloadScreenFiles {
    /* 00 */ void *mSearchIconCellLayout;
    /* 04 */ void *mSearchIconLayoutCellLayout;
    /* 08 */ Ncgr *mSearchIconChars;
    /* 0c */ Unk02021dc8 *mSearchIconCells;
    /* 10 */ Nclr *mSearchIconPalette;
    /* 14 */ void *mMBChildFont;
    /* 18 */ u8 mUnk_18[8];
    /* 20 */ struct Bmg *mUnk_20;
    /* 24 */ Ncgr *mMultiDownloadChars;
    /* 28 */ Nclr *mMultiDownloadPalette;
} DownloadScreenFiles;

void CreateSearchIconMBChildAndMultiDownload(void *heap);

extern struct DownloadScreenFiles *gDownloadScreenFiles;
