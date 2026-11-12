#pragma once

#include "types.h"
#include "Main/System/interpolation_value.h"
#include "Main/System/heap_call.h"
#include "Main/Menu/data_02153000.h"
#include "code_02022aa8.h"
#include "Main/Graphics/cell_file_set.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Menu/multi_select_member_group.h"
#include "tp.h"
#include "Main/Save/buddy_record_time.h"
#include "g2d_CellTransferManager.h"

// 6-byte entries of mTable (data_02153de8 and data_02153df4).
typedef struct SelectGameRow {
    /* 00 */ u16 mSelectedCellIndex;
    /* 02 */ u16 mCellIndex;
    /* 04 */ u16 mRectEntryId;
} SelectGameRow;

// 0x6c bytes.
typedef struct SelectGame {
    /* 00 */ CellFileSet mCellFileSets[2];
    /* 38 */ void *mMainOam;
    /* 3c */ void *mSubOam;
    /* 40 */ void *mHeap;
    /* 44 */ s32 mSelectedIndex;
    /* 48 */ s32 mTableCount;
    /* 4c */ SelectGameRow *mTable;
    /* 50 */ struct Bmg *mMenuMessages;
    /* 54 */ s32 mState;
    /* 58 */ s32 mStateFrames;
    /* 5c */ s32 mSubOffsetX;
    /* 60 */ s32 mMainOffsetY;
    /* 64 */ s32 mResult;
    /* 68 */ s32 mMode;
} SelectGame;

extern SelectGame *gSelectGame;

// 12-byte entries of the tables data_02153e08, data_02153e0c and data_02153e10.
typedef struct SelectGameFileNames {
    /* 00 */ const char *mUnk_00;
    /* 04 */ const char *mUnk_04;
    /* 08 */ const char *mUnk_08;
} SelectGameFileNames;

extern SelectGameRow data_02153de8[];
extern SelectGameRow data_02153df4[];
extern SelectGameFileNames data_02153e08[];
extern SelectGameFileNames data_02153e0c[];
extern SelectGameFileNames data_02153e10[];
extern LabelMessageRow gSelectGameLabelMessageRows[];

extern const char gSelectGameMBNcgrName[];
extern const char gSelectGameMNceNcgrName[];
extern const char gSelectGameMNceNcerName[];
extern const char gSelectGameMBNclrName[];
extern const char gSelectGameMONclrName[];
extern const char gSelectGameMMultiNscrName[];
extern const char gSelectGameMSingleNscrName[];
extern const char gSelectGameSNceNcgrName[];
extern const char gSelectGameSNceNcerName[];
extern const char gSelectGameSONclrName[];
extern u8 data_02163aec[];
extern u8 data_02163af0[];
extern const char gMenuBmgName[];
extern const char gSelectGameMBNcgrName2[];
extern const char gSelectGameMBNclrName2[];
extern const char gSelectGameMNceNcgrName2[];
extern const char gSelectGameMNceNcerName2[];
extern const char gSelectGameMONclrName2[];
extern const char gSelectGameMBnclName[];
extern const char gSelectGameMBnllName[];
extern const char gSelectGameSNceNcgrName2[];
extern const char gSelectGameSNceNcerName2[];
extern const char gSelectGameSONclrName2[];

void WriteSelectGameMainRegisters(void);
void LoadSelectGameData(void);
void ReleaseSelectGame(void);
s32 AdvanceSelectGame(void);
void InitSelectGame(void *parentHeap, s32 mode, void *mainOam, void *subOam);
void SetSelectGameSubCellsVisible(s32 visible);
void SetSelectGameSelectedRowVisible(s32 showSelected);
void SetSelectGameCellTableOffsets(void);
void SetSelectGameRowOffsetX(void);
void SetSelectGameRowCellsVisible(s32 visible);
void WriteSelectGameRowToRaceSetupCopy(void);
