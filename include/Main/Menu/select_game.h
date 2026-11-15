#pragma once

#include "types.h"
#include "Main/System/interpolation_value.h"
#include "Main/System/heap_call.h"
#include "Main/Menu/menu_label_cell_rows.h"
#include "font_glyph_layout.h"
#include "Main/Graphics/cell_file_set.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Menu/multi_select_member_group.h"
#include "touch_panel_sampling.h"
#include "Main/Save/buddy_record_time.h"
#include "cell_transfer_state.h"

// 6-byte entries of mTable (gSelectGameBattleRows and gSelectGameMultiRows).
typedef struct SelectGameRow {
    /* 00 */ u16 mSelectedCellIndex;
    /* 02 */ u16 mCellIndex;
    /* 04 */ u16 mRectEntryId;
} SelectGameRow;

// Value of SelectGame.mMode.
// Steps of the slide in and out and of the press animation; mStateFrames counts them. The press starts at
// SELECT_GAME_PRESS_START_STEP in state WAIT_PRESS. x offset of the sub screen cells while they are off screen.
#define SELECT_GAME_SLIDE_STEPS 10
#define SELECT_GAME_PRESS_STEPS 10
#define SELECT_GAME_PRESS_START_STEP 5
#define SELECT_GAME_SUB_OFFSCREEN_X 0xee

typedef enum SelectGameMode {
    SELECT_GAME_MODE_NO_CONNECTION = 0,
    SELECT_GAME_MODE_CONNECTION = 1,
} SelectGameMode;

// Values of SelectGame.mState (numbers start at 3): the screen slides in, a row is chosen and pressed, then the
// screen slides out and the result is handed back.
typedef enum SelectGameState {
    SELECT_GAME_STATE_SLIDE_IN = 3,
    SELECT_GAME_STATE_CHOOSE_ROW = 4,
    SELECT_GAME_STATE_WAIT_PRESS = 5,
    SELECT_GAME_STATE_PRESS_ANIMATION = 6,
    SELECT_GAME_STATE_ASK_LEAVE = 7,
    SELECT_GAME_STATE_WAIT_CONNECTION_END = 8,
    SELECT_GAME_STATE_SLIDE_OUT = 9,
    SELECT_GAME_STATE_DONE = 10,
    SELECT_GAME_STATE_RESULT_RETURNED = 11,
} SelectGameState;

// 0x6c bytes.
typedef struct SelectGame {
    /* 00 */ CellFileSet mCellFileSets[2];
    /* 38 */ void *mMainOam;
    /* 3c */ void *mSubOam;
    /* 40 */ void *mHeap;
    /* 44 */ s32 mSelectedIndex;
    /* 48 */ s32 mTableCount;
    /* 4c */ const SelectGameRow *mTable;
    /* 50 */ struct Bmg *mMenuMessages;
    /* 54 */ s32 mState;
    /* 58 */ s32 mStateFrames;
    /* 5c */ s32 mSubOffsetX;
    /* 60 */ s32 mMainOffsetY;
    /* 64 */ s32 mResult;
    /* 68 */ s32 mMode;
} SelectGame;

extern SelectGame *gSelectGame;

// 12-byte entries of gSelectGameFileNames, one per mode.
typedef struct SelectGameFileNames {
    /* 00 */ const char *mCellLayoutName;
    /* 04 */ const char *mRectsName;
    /* 08 */ const char *mScreenMapName;
} SelectGameFileNames;

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

extern const SelectGameRow gSelectGameMultiRows[3];
extern const SelectGameRow gSelectGameBattleRows[2];

extern const SelectGameFileNames gSelectGameFileNames[2];
extern const LabelMessageRow gSelectGameLabelMessageRows[10];
