#pragma once

#include "types.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/unk_02153000.h" // LabelMessageRow

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
typedef struct Unk02153e08 {
    /* 00 */ const char *mUnk_00;
    /* 04 */ const char *mUnk_04;
    /* 08 */ const char *mUnk_08;
} Unk02153e08;

extern SelectGameRow data_02153de8[];
extern SelectGameRow data_02153df4[];
extern Unk02153e08 data_02153e08[];
extern Unk02153e08 data_02153e0c[];
extern Unk02153e08 data_02153e10[];
extern LabelMessageRow gSelectGameLabelMessageRows[];

extern const char aCommonSelect_game_m_b_ncgr[];
extern const char aCommonSelect_game_m_nce_ncgr[];
extern const char aCommonSelect_game_m_nce_ncer[];
extern const char aCommonSelect_game_m_b_nclr[];
extern const char aCommonSelect_game_m_o_nclr[];
extern const char aCommonSelect_game_m_multi_nscr[];
extern const char aCommonSelect_game_m_single_nscr[];
extern const char aCommonSelect_game_s_nce_ncgr[];
extern const char aCommonSelect_game_s_nce_ncer[];
extern const char aCommonSelect_game_s_o_nclr[];
extern u8 data_02163aec[];
extern u8 data_02163af0[];
extern const char aMenu_bmg_0[];
extern const char aCommonSelect_game_m_b_ncgr_0[];
extern const char aCommonSelect_game_m_b_nclr_0[];
extern const char aCommonSelect_game_m_nce_ncgr_0[];
extern const char aCommonSelect_game_m_nce_ncer_0[];
extern const char aCommonSelect_game_m_o_nclr_0[];
extern const char aCommonSelect_game_m_bncl[];
extern const char aCommonSelect_game_m_bnll[];
extern const char aCommonSelect_game_s_nce_ncgr_0[];
extern const char aCommonSelect_game_s_nce_ncer_0[];
extern const char aCommonSelect_game_s_o_nclr_0[];

void func_02032138(void);
void LoadSelectGameData(void);
void ReleaseSelectGame(void);
s32 AdvanceSelectGame(void);
void SPM_LoadBattleMenu(void *parentHeap, s32 mode, void *mainOam, void *subOam);
void SetSelectGameSubCellsVisible(s32 visible);
void SetSelectGameSelectedRowVisible(s32 showSelected);
void SetSelectGameCellTableOffsets(void);
void SetSelectGameRowOffsetX(void);
void SetSelectGameRowCellsVisible(s32 visible);
void func_02032a20(void);
