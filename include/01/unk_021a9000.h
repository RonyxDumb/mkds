#pragma once

#include "types.h"
#include "01/Race/race_hud_king_cells.h"
#include "01/code_0219b250.h"
#include "01/Menu/nickname_scene.h"
#include "01/Menu/option_select_menu.h"
#include "01/Menu/record_top_menu.h"
#include "01/Menu/select_ghost.h"
#include "01/Menu/emblem_grid.h"
#include "01/Menu/record_gpx.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/Menu/data_02180728.h" // TextCanvas

typedef void (*OptionStateCallback)(void);

// Four callbacks; the first receives OptionStates.mStateHeap.
typedef struct OptionStateCallbacks {
    /* 00 */ void (*mInit)(void *);
    /* 04 */ OptionStateCallback mRelease;
    /* 08 */ OptionStateCallback mAdvance;
    /* 0c */ OptionStateCallback mPostUpdate;
} OptionStateCallbacks;

// States of OptionHensyuMenu.mState and mNextState, in the order of the AdvanceOptionHensyuMenuStateN calls.
enum {
    OPTION_HENSYU_MENU_STATE_WAIT_FADE,
    OPTION_HENSYU_MENU_STATE_SLIDE_IN,
    OPTION_HENSYU_MENU_STATE_WAIT_SELECT_RETURN,
    OPTION_HENSYU_MENU_STATE_SELECT,
    OPTION_HENSYU_MENU_STATE_HOLD_CHOSEN,
    OPTION_HENSYU_MENU_STATE_SLIDE_OUT,
};

// Frames of the slide in and the slide out and the distance the cells travel sideways (mOffsetX).
#define OPTION_HENSYU_MENU_SLIDE_FRAMES 10
#define OPTION_HENSYU_MENU_SLIDE_DISTANCE 250

// Frames the chosen row is shown before the slide out; the highlight comes back at the fifth.
#define OPTION_HENSYU_MENU_PRESS_FRAMES 10
#define OPTION_HENSYU_MENU_HIGHLIGHT_FRAME 5

// Object behind gOptionHensyuMenu.
typedef struct OptionHensyuMenu {
    /* 00 */ s32 mState;
    /* 04 */ s32 mNextState;
    /* Init leaves it unset when the previous option state is not 0, 3, 5 or 6 (0, 5 -> 0, 3, 6 -> 1) */
    /* 08 */ s32 mIndex;
    /* counted only in states 1, 4, 5; zeroed when 1 and 4 hand over; state 5 keeps counting while it requests the
       next option state */
    /* 0c */ s32 mStateFrames;
    /* option state passed to RequestOptionState (0, 3, 5 or 6); no initial store, set by the input handler (state
       3); also tested inside the screen */
    /* 10 */ s32 mNextOptionState;
    /* 14 */ BOOL mHighlightVisible;
    /* 18 */ void *mHeap;
    // one 0x40-byte record per cell of the Bncl member, built by InitLayoutTable
    /* 1c */ LayoutTableEntry *mOptionHensyuMenuSTable;
    /* 20 */ struct NNSG2dCellDataBank *mOptionHensyuMenuSNcer;
    /* 24 */ Ncgr *mOptionHensyuMenuSNcgr;
    /* 28 */ Nclr *mOptionHensyuMenuSONclr;
    /* 2c */ struct LayoutEntryTable *mOptionHensyuMenuSBncl;
    /* 30 */ void *mOptionHensyuMenuSBnbl;
} OptionHensyuMenu;

// Allocated by InitOptionStates and held in gOptionStates.
typedef struct OptionStates {
    /* 00 */ void *mHeap;
    /* 04 */ void *mStateHeap;
    /* 08 */ s32 mState;
    /* 0c */ s32 mNextState;
    /* 10 */ s32 mPrevState;
    /* 14 */ s16 mNextScene;
    /* 16 */ u8 mUnk_16[2];
    /* 18 */ OptionStateCallbacks mCallbacks;
    /* 28 */ void *mSceneDisplaySettings;
} OptionStates;

typedef void (*MissionRunEventCallback)(void);

typedef struct MissionRunData {
    /* 00 */ s32 mSinceHitCallbackFrames;
    /* 04 */ u16 mCount;
    /* 06 */ u16 mBossCount;
    /* 08 */ u16 mPendingCountUp;
    /* 0a */ u16 mPendingDrop;
    /* 0c */ u16 mPendingBossTransfer;
    /* 0e */ u16 mTimer;
    /* 10 */ u16 mTimerStart;
    /* 12 */ u16 mTimerMax;
    /* 14 */ u16 mCountUpTimerAdd;
    /* 16 */ u16 mBossTransferTimerAdd;
    /* 18 */ MissionRunEventCallback mCountUpCallback;
    /* 1c */ MissionRunEventCallback mDropCallback;
    /* 20 */ MissionRunEventCallback mBossTransferCallback;
    /* 24 */ MissionRunEventCallback mTimerEndCallback;
    /* 28 */ Vec3 mKartPos;
    /* 34 */ Vec3 mPrevKartPos;
    /* 40 */ u16 mKartHeadingAngle;
    /* 42 */ u16 mPrevKartHeadingAngle;
    /* 44 */ s32 mMapObjectCount;
    /* 48 */ struct MissionRunMapObject *mMapObjects[8];
} MissionRunData;

// Bytes of one 8 by 8 tile of cells; CreateEmblemGrid allocates the cell buffers one tile longer than the grid.
#define EMBLEM_GRID_TILE_BYTES 0x40

// A square grid of mSide by mSide cells.
typedef struct EmblemGrid {
    /* 00 */ s32 mSide;
    /* 04 */ s32 mScrSide;
    /* 08 */ s32 mTableCount;
    /* 0c */ BOOL mCopied;
    /* 10 */ s32 mChanged;
    /* 14 */ s32 mSwapped;
    /* 18 */ u16 *mUnk_18;
    /* 1c */ u8 *mBuffers[4];
    /* 2c */ EmblemGridPoint *mPointStack;
} EmblemGrid;

// The variant argument of InitSelectBattleStage: the battle kind the screen is opened for.
typedef enum SelectBattleStageVariant {
    SELECT_BATTLE_STAGE_VARIANT_SHINE = 0,
    SELECT_BATTLE_STAGE_VARIANT_BALLOON = 1,
} SelectBattleStageVariant;

// Values of SelectBattleStage.mState and mNextState.
enum {
    SELECT_BATTLE_STAGE_STATE_SLIDE_IN,
    SELECT_BATTLE_STAGE_STATE_WAIT_SELECT_RETURN,
    SELECT_BATTLE_STAGE_STATE_INPUT,
    SELECT_BATTLE_STAGE_STATE_PRESS_STAGE,
    SELECT_BATTLE_STAGE_STATE_WAIT_SELECT_RETURN_THEN_CHOISES,
    SELECT_BATTLE_STAGE_STATE_CHOISES,
    SELECT_BATTLE_STAGE_STATE_SLIDE_OUT,
};

// Allocated by InitSelectBattleStage and held in gSelectBattleStage.
typedef struct SelectBattleStage {
    /* 0000 */ s32 mState;
    /* 0004 */ s32 mNextState;
    /* 0008 */ s32 mIndex;
    /* 000c */ s32 mStateFrames;
    /* 0010 */ s32 mOffsetTimer;
    /* 0014 */ s32 mSlideOffsetY;
    /* 0018 */ s32 mSlideOffsetX;
    /* 001c */ s32 mOffset;
    /* 0020 */ BOOL mHighlightVisible;
    /* 0024 */ s32 mResult;
    /* 0028 */ s32 mPendingResult;
    /* 002c */ BOOL mWaitForReturnHidden;
    /* 0030 */ u16 mSelectBattleStageMNscrCopy[64][32];
    /* 1030 */ void *mHeap;
    /* 1034 */ LayoutTableEntry *mSelectBattleStageTables[2];
    /* 103c */ struct NNSG2dCellDataBank *mSelectBattleStageMNcer;
    /* 1040 */ struct NNSG2dCellDataBank *mSelectBattleStageSNcer;
    /* 1044 */ Ncgr *mSelectBattleStageMNcgr;
    /* 1048 */ Ncgr *mSelectBattleStageSNcgr;
    /* 104c */ u8 pad_104c[8];
    /* 1054 */ LayoutEntryTable *mSelectBattleStageBncls[2];
    /* 105c */ void *mSelectBattleStageBnbls[2];
    /* 1064 */ void *mSelectBattleStageBnlls[2];
    /* 106c */ Nscr *mSelectBattleStageMNscrs[3];
    /* 1078 */ void *mMainOamList;
    /* 107c */ void *mSubOamList;
    /* 1080 */ struct Bmg *mMenuMessages;
    /* 1084 */ struct Bmg *mCommonMessages;
} SelectBattleStage;

// Values of TestScene.mState. State 0 is the emblem choises screen; states 1 to 3 show one character table per font.
enum {
    TEST_SCENE_STATE_CHOISES,
    TEST_SCENE_STATE_CHAR_TABLE_0,
    TEST_SCENE_STATE_CHAR_TABLE_1,
    TEST_SCENE_STATE_CHAR_TABLE_2,
    TEST_SCENE_STATE_COUNT = 4,
};

// Object that InitTestSceneObject allocates and gTestScene points to.
typedef struct TestScene {
    /* 0000 */ s32 mUnk_0000;
    /* 0004 */ s32 mState;
    /* 0008 */ s32 mStateChanged;
    /* 000c */ void *mFonts[3];
    /* 0018 */ u8 mCharCanvases[3][0x20];
    /* 0078 */ TextCanvas mTextCanvases[3];
    /* 00a8 */ u16 mChars[0x3000];
    /* 60a8 */ u16 mScreenMap[0x300];
} TestScene;

// Objects whose layout isn't known yet.
extern const char *gMissionRunMSselMNcgrName;
extern const char *gMissionRunMSselSONclrName;
extern const char *gMissionRunMSselSBnllName;
extern const char *gMissionRunMSselSNcerName;
extern const char *gMissionRunMSselMWNscrName;
extern const char *gMissionRunMSselMONclrName;
extern const char *gMissionRunMSselMBnclName;
extern const char *gMissionRunMSselSBnblName;
extern const char *gMissionRunMSselSBnclName;
extern const char *gMissionRunMSselMBNclrName;
extern const char *gMissionRunMSselMBnllName;
extern const char *gMissionRunMSselSNcgrName;
extern const char *gMissionRunMSselMBNcgrName;
extern const char *gMissionRunMSselMNscrName;
extern const char *gMissionRunMSselMNcerName;
extern TestScene *gTestScene;
extern SelectBattleStage *gSelectBattleStage;
// One pair of halfwords of the object behind gOptionEmbremSelect.
typedef struct OptionEmbremSelectOffset {
    /* 00 */ s16 mOffsetX;
    /* 02 */ s16 mOffsetY;
} OptionEmbremSelectOffset;

// States of OptionEmbremSelect.mState and mNextState, in the order of the AdvanceOptionEmbremSelectStateN calls.
enum {
    OPTION_EMBREM_SELECT_STATE_WAIT_FADE,
    OPTION_EMBREM_SELECT_STATE_SLIDE_IN,
    OPTION_EMBREM_SELECT_STATE_WAIT_SELECT_RETURN,
    OPTION_EMBREM_SELECT_STATE_SELECT,
    OPTION_EMBREM_SELECT_STATE_HOLD_CHOSEN,
    OPTION_EMBREM_SELECT_STATE_SLIDE_OUT,
    OPTION_EMBREM_SELECT_STATE_WAIT_MESSAGE,
};

// Frames of the slide in and the slide out and the distance the cells travel sideways (mOffsetX).
#define OPTION_EMBREM_SELECT_SLIDE_FRAMES 10
#define OPTION_EMBREM_SELECT_SLIDE_DISTANCE 250

// Frames the chosen row is shown before the slide out; the highlight comes back at the fifth.
#define OPTION_EMBREM_SELECT_PRESS_FRAMES 10
#define OPTION_EMBREM_SELECT_HIGHLIGHT_FRAME 5

// Frames the cells of a row shift after its choice changed (OptionEmbremSelect.mOffsetTimers count them down).
#define OPTION_EMBREM_SELECT_OFFSET_TIMER_FRAMES 6

// Object behind gOptionEmbremSelect.
typedef struct OptionEmbremSelect {
    /* 00 */ s32 mState;
    /* 04 */ s32 mNextState;
    /* 08 */ s32 mSelectedRow;
    /* 0c */ s32 mEmblemOffChoice;
    /* 10 */ s32 mEmblemOffAtOpen;
    /* 14 */ s32 mStateFrames;
    /* 18 */ OptionEmbremSelectOffset mCellGroupOffsets[2];
    /* 20 */ s32 mNextOptionState;
    /* 24 */ BOOL mHighlightVisible;
    // Set to 6 by a press; counts down to 0 only while mUnk_08 == 1. 6 - timer indexes a table through
    // LookupFrameOffset (a displacement that returns to 0); [0] is subtracted from a row member, [1] added to one.
    /* 28 */ s32 mOffsetTimers[2];
    /* 30 */ void *mHeap;
    /* 34 */ LayoutTableEntry *mOptionEmbremSelectSTable;
    /* 38 */ struct NNSG2dCellDataBank *mOptionEmbremSelectSNcer;
    /* 3c */ Ncgr *mOptionEmbremSelectSNcgr;
    /* 40 */ Nclr *mOptionEmbremSelectSONclr;
    /* 44 */ LayoutEntryTable *mOptionEmbremSelectSBncl;
    /* 48 */ void *mOptionEmbremSelectSBnbl;
    /* 4c */ struct LayoutEntryTable *mOptionEmbremSelectSBnll;
    /* 50 */ struct Bmg *mOptionMessages;
    /* 54 */ void *mCommonMessages;
} OptionEmbremSelect;

extern const char *gMissionRunLVselMBNcgrName;
extern const char *gMissionRunLVselMNscrName;
extern const char *gMissionRunLVselMBNclrName;
extern const char *gMissionRunLVselS7BnclName;
extern const char *gMissionRunLVselS7BnblName;
extern const char *gMissionRunLVselS7BnllName;
extern const char *gMissionRunLVselS6BnclName;
extern const char *gMissionRunLVselS6BnblName;
extern const char *gMissionRunLVselS6BnllName;
extern const char *gMissionRunLVselSNcgrName;
extern const char *gMissionRunLVselSNcerName;
extern const char *gMissionRunLVselSONclrName;
extern s32 gTestSceneCharTableIndex;
extern u16 gTestSceneCharText[];
// Values of TimeAttackTopMenu.mIndex: the rows, top to bottom.
enum {
    TIME_ATTACK_TOP_ROW_TIME_TRIALS,
    TIME_ATTACK_TOP_ROW_SEND_GHOST,
    TIME_ATTACK_TOP_ROW_RECEIVE_GHOST,
};

// Values of TimeAttackTopMenu.mResult, returned by AdvanceTimeAttackTopMenu once the slide out is done: the row that
// was chosen, or the return button.
enum {
    TIME_ATTACK_TOP_RESULT_NONE,
    TIME_ATTACK_TOP_RESULT_TIME_TRIALS,
    TIME_ATTACK_TOP_RESULT_SEND_GHOST,
    TIME_ATTACK_TOP_RESULT_RECEIVE_GHOST,
    TIME_ATTACK_TOP_RESULT_RETURN,
};

// Values of TimeAttackTopMenu.mState and mNextState.
enum {
    TIME_ATTACK_TOP_STATE_SLIDE_IN,
    TIME_ATTACK_TOP_STATE_SETTLE,
    TIME_ATTACK_TOP_STATE_WAIT_SELECT_RETURN,
    TIME_ATTACK_TOP_STATE_INPUT,
    TIME_ATTACK_TOP_STATE_PRESS,
    TIME_ATTACK_TOP_STATE_SLIDE_OUT,
};

typedef struct TimeAttackTopMenu {
    /* 00 */ struct NNSG2dCellDataBank *mTimeAttackTopMenuSNcer;
    /* 04 */ struct LayoutEntryTable *mTimeAttackTopMenuSBncl;
    /* 08 */ void *mTimeAttackTopMenuSBnbl;
    // one 0x40-byte record per cell of the Bncl member, built by InitLayoutTable
    /* 0c */ LayoutTableEntry *mTimeAttackTopMenuSTable;
    /* 10 */ void *mSecondScreenMapBuffer;
    /* 14 */ void *mHeap;
    /* 18 */ s32 mState;
    /* 1c */ s32 mNextState;
    /* 20 */ s32 mStateFrames; /* counted only in states 0, 1, 4, 5; zeroed by the next-state setter */
    /* 24 */ s32 mBg0Offset;
    /* 28 */ s32 mIndex;
    /* 2c */ void *mMainOamList;
    /* 30 */ void *mSubOamList;
    /* 34 */ s32 mResult;
} TimeAttackTopMenu;

extern RaceHudSubScreenCells *gRaceHudSubScreenKurikingCells;
extern u16 *gMissionRunLVselGradeStrings[5];
extern u16 *gMissionRunMSselGradeStrings[5];

#include "00/Menu/wi_fi_vs_matching.h"
