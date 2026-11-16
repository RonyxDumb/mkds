#pragma once

#include "types.h"
#include "Main/Graphics/oam_lists.h"
#include "Main/Race/mission_table_value.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/Race/mission_file_row.h" // MissionFileRow

// Values of EndingScene.mKind: which staff roll the scene follows (course ids COURSE_ID_STAFFROLL and
// COURSE_ID_STAFFROLLTRUE).
enum {
    ENDING_KIND_STAFFROLL,
    ENDING_KIND_STAFFROLL_TRUE,
};

// Values of EndingScene.mState and mNextState; gEndingSceneStateTable holds how long each lasts.
enum {
    ENDING_SCENE_STATE_WAIT_FADE_IN,
    ENDING_SCENE_STATE_SHOW_LOGO,
    ENDING_SCENE_STATE_FADE_OUT,
    ENDING_SCENE_STATE_HOLD_FADED,
    ENDING_SCENE_STATE_FADE_IN,
    ENDING_SCENE_STATE_WAIT_INPUT,
    ENDING_SCENE_STATE_FADE_OUT_TO_LEAVE,
    ENDING_SCENE_STATE_HOLD_THEN_LEAVE,
};

// The ending scene: its state, heap, thanks layout, logo graphics and NtrMain screen OAM.
typedef struct EndingScene {
    /* 000 */ s32 mState;
    /* 004 */ s32 mNextState;
    /* 008 */ s32 mStateFrames;
    /* 00c */ s32 mKind;
    /* 010 */ void *mHeap;
    /* 014 */ s16 mNextScene;
    /* 016 */ u8 mUnk_016[0x2];
    /* 018 */ BOOL mIndex1Queued;
    /* 01c */ void *mSceneDisplaySettings;
    /* 020 */ LayoutTableEntry *mEndingThanksTable;
    /* 024 */ struct NNSG2dCellDataBank *mThanksYouMNcer;
    /* 028 */ u8 mUnk_028[0x4];
    /* 02c */ Nclr *mThanksYouMO00Nclr;
    /* 030 */ struct LayoutEntryTable *mEndingThanksBncl;
    /* 034 */ struct LayoutEntryTable *mEndingThanksBnll;
    /* 038 */ Ncgr *mLogoEndMarioKartMBAndThanksYouMBNcgrs[2];
    /* 040 */ Nscr *mLogoEndMarioKartMBgAndThanksYouMBgNscrs[2];
    /* 048 */ Nclr *mLogoEndMarioKartMBAndThanksYouMBNclrs[2];
    /* 050 */ Ncgr *mEndAllRightsReservedSBAndLogoEndNintendoSBNcgrs[2];
    /* 058 */ Nscr *mEndAllRightsReservedSBgAndLogoEndNintendoSBgNscrs[2];
    /* 060 */ Nclr *mEndAllRightsReservedSBAndLogoEndNintendoSBNclrs[2];
    /* 068 */ u8 mMainOam[0x404];
    /* 46c */ struct Bmg *mCommonMessages;
} EndingScene;

// States of MissionRunLVsel.mState and mNextState.
enum {
    MISSION_RUN_LVSEL_STATE_WAIT_FADE,
    MISSION_RUN_LVSEL_STATE_SLIDE_IN,
    MISSION_RUN_LVSEL_STATE_WAIT_SELECT_RETURN,
    MISSION_RUN_LVSEL_STATE_SELECT,
    MISSION_RUN_LVSEL_STATE_HOLD_CHOSEN,
    MISSION_RUN_LVSEL_STATE_SLIDE_OUT,
};

// Values of MissionRunLVsel.mResult.
enum {
    MISSION_RUN_LVSEL_RESULT_NONE,
    MISSION_RUN_LVSEL_RESULT_LEVEL_CHOSEN,
    MISSION_RUN_LVSEL_RESULT_BACK,
};

// Index of the last level (MissionRunLVsel.mIndex is the level number minus one); a reached level of this index selects
// the layout with seven levels.
#define MISSION_RUN_LVSEL_LAST_LEVEL_INDEX 6

// Frames of the slide in and the slide out (the BG0 layer travels MISSION_RUN_LVSEL_BG0_SLIDE_DISTANCE), of the hold
// after a level was chosen, and of the highlight timer a chosen or moved-to level gets.
#define MISSION_RUN_LVSEL_SLIDE_FRAMES 10
#define MISSION_RUN_LVSEL_BG0_SLIDE_DISTANCE 192
#define MISSION_RUN_LVSEL_HOLD_FRAMES 5
#define MISSION_RUN_LVSEL_HIGHLIGHT_FRAMES 5

// The mission run level select screen: its state, highlight timers, reached level, index, result, heap and layout
// tables.
typedef struct MissionRunLVsel {
    /* 00 */ struct NNSG2dCellDataBank *mMissionRunLVselSNcer;
    // mr/Mission_run_LVsel_s_7.bncl when mUnk_4a >= 6, else _s_6; Bnbl and Bnll follow the same test
    // (mUnk_4a is the highest level number whose conditions hold)
    /* 04 */ LayoutEntryTable *mMissionRunLVselS7Or6Bncl;
    // same variant as mMissionRunLVselS7Or6Bncl (.bnbl)
    /* 08 */ void *mMissionRunLVselS7Or6Bnbl;
    // same variant as mMissionRunLVselS7Or6Bncl (.bnll)
    /* 0c */ struct LayoutEntryTable *mMissionRunLVselS7Or6Bnll;
    // cell records of mMissionRunLVselS7Or6Bncl and Bnll
    /* 10 */ LayoutTableEntry *mMissionRunLVselS7Or6Table;
    /* 14 */ void *mVramTransferBuffer;
    /* 18 */ void *mHeap;
    /* 1c */ s32 mState;
    /* 20 */ s32 mNextState;
    /* 24 */ s32 mStateFrames; /* counted only in states 1, 4, 5; zeroed by the next-state setter */
    /* 28 */ s32 mHighlightTimers[7];
    /* 44 */ s32 mBg0Offset;
    /* 48 */ s16 mSlideOffsetX;
    /* 4a */ s16 mReachedLevel;
    /* 4c */ s16 mIndex; /* level number - 1 */
    /* 4e */ u8 mUnk_4e[0x2];
    /* 50 */ void *mMainOam;
    /* 54 */ void *mSubOam;
    /* 58 */ s32 mResult; /* also read by ReleaseMissionRunLVsel for the sound */
} MissionRunLVsel;

// Values of MissionRunMSsel.mResult.
enum {
    MISSION_RUN_MSSEL_RESULT_NONE,
    MISSION_RUN_MSSEL_RESULT_MISSION_CHOSEN,
    MISSION_RUN_MSSEL_RESULT_BACK,
};

// Values of MissionRunMSsel.mState and mNextState.
enum {
    MSSEL_STATE_WAIT_FADE,
    MSSEL_STATE_SLIDE_IN,
    MSSEL_STATE_WAIT_SELECT_RETURN,
    MSSEL_STATE_INPUT,
    MSSEL_STATE_PRESS_MISSION,
    MSSEL_STATE_CHOISES_OPEN,
    MSSEL_STATE_CHOISES_INPUT,
    MSSEL_STATE_CHOISES_CLOSE,
    MSSEL_STATE_SLIDE_OUT,
};

// MissionRunMSsel.mIndex of the boss entry, which is shown differently until the boss was recorded and cannot be
// picked before all missions are recorded.
#define MISSION_RUN_MSSEL_BOSS_INDEX 8

// Frames of the slide in and the slide out, of the hold before the choices open, of the index change animation, and of
// the highlight timer of a picked or moved-to entry; the palette blend of the boss entry repeats every
// MISSION_RUN_MSSEL_BLEND_PERIOD_FRAMES, and the VRAM transfer queued during the slide in starts at its fifth frame.
#define MISSION_RUN_MSSEL_SLIDE_FRAMES 10
#define MISSION_RUN_MSSEL_HOLD_FRAMES 5
#define MISSION_RUN_MSSEL_INDEX_CHANGE_FRAMES 7
#define MISSION_RUN_MSSEL_HIGHLIGHT_FRAMES 5
#define MISSION_RUN_MSSEL_BLEND_PERIOD_FRAMES 100
#define MISSION_RUN_MSSEL_VRAM_TRANSFER_FRAME 5

// The mission run mission select screen: its state, shown mission, mission table and rows, palette blend and result.
typedef struct MissionRunMSsel {
    /* 00 */ struct NNSG2dCellDataBank *mMissionRunMSselMNcer;
    /* 04 */ LayoutEntryTable *mMissionRunMSselMBncl;
    /* 08 */ struct LayoutEntryTable *mMissionRunMSselMBnll;
    /* 0c */ struct NNSG2dCellDataBank *mMissionRunMSselSNcer;
    /* 10 */ LayoutEntryTable *mMissionRunMSselSBncl;
    /* 14 */ void *mMissionRunMSselSBnbl;
    /* 18 */ struct LayoutEntryTable *mMissionRunMSselSBnll;
    /* 1c */ Nclr *mMissionRunMSselSOPalette;
    /* 20 */ u16 mBlendedPalette[0x10];
    // one 0x40-byte record per cell of the Bncl (plus Bnll) members, built by InitLayoutTable
    /* 40 */ LayoutTableEntry *mMissionRunMSselMTable;
    // one 0x40-byte record per cell of the Bncl (plus Bnll) members, built by InitLayoutTable
    /* 44 */ LayoutTableEntry *mMissionRunMSselSTable;
    /* 48 */ void *mVramTransferBuffer;
    // missionTable.mtbl; GetMissionTableValue(table, row, column) returns the mission number
    /* 4c */ MissionTable *mMissionTableMtbl;
    /* 50 */ MissionFileRow *mMissionFileRows;
    /* 54 */ struct Bmg *mCommonMessages;
    /* 58 */ void *mMissionMessages;
    /* 5c */ void *mHeap;
    /* 60 */ u32 mState;
    /* 64 */ s32 mNextState;
    /* 68 */ s32 mStateFrames; /* counted only in states 1, 4, 8; zeroed by the next-state setter */
    /* 6c */ s32 mIndexCellTimers[9];
    // X half of reg_G2_BG0OFS (0x04000010, NtrMain engine BG0), stored negated
    /* 90 */ s32 mBg0OffsetX;
    // Y half of reg_G2_BG0OFS (0x04000010, NtrMain engine BG0), stored negated
    /* 94 */ s32 mBg0OffsetY;
    // Y half of reg_G2_BG1OFS (0x04000014, NtrMain engine BG1), stored negated; X is not written
    /* 98 */ s32 mBg1Offset;
    /* 9c */ s16 mExitOffsetX;
    /* 9e */ s16 mIndex; /* mission number - 1, 8 = ninth mission */
    /* a0 */ s32 mAllRecorded;
    /* a4 */ BOOL mBossRecorded;
    /* a8 */ s32 mPaletteBlendFrame;
    /* ac */ s32 mIndexChangeTimer;
    /* b0 */ s16 mShownIndex;
    /* b2 */ u8 mUnk_b2[0x2];
    /* b4 */ void *mMainOamList;
    /* b8 */ void *mSubOamList;
    /* bc */ s32 mResult; /* MISSION_RUN_MSSEL_RESULT_*; also read by ReleaseMissionRunMSsel for the sound */
} MissionRunMSsel;

// Values of SelectEngine.mState and mNextState.
enum {
    SELECT_ENGINE_STATE_WAIT_FADE,
    SELECT_ENGINE_STATE_SLIDE_IN,
    SELECT_ENGINE_STATE_SETTLE,
    SELECT_ENGINE_STATE_WAIT_SELECT_RETURN,
    SELECT_ENGINE_STATE_INPUT,
    SELECT_ENGINE_STATE_PRESS,
    SELECT_ENGINE_STATE_SLIDE_OUT,
};

// Values of SelectEngine.mIndex: the entries, in the order of the engine classes (EngineClass) and then the mirror
// entry (SetEngineFromSelectEngine sets the fast engine class and mirror mode for it).
enum {
    SELECT_ENGINE_ENTRY_SLOW,
    SELECT_ENGINE_ENTRY_MEDIUM,
    SELECT_ENGINE_ENTRY_FAST,
    SELECT_ENGINE_ENTRY_MIRROR,
};

// Values of SelectEngine.mResult, returned by AdvanceSelectEngine: an entry was pressed, or the return button.
enum {
    SELECT_ENGINE_RESULT_NONE,
    SELECT_ENGINE_RESULT_CHOSEN,
    SELECT_ENGINE_RESULT_RETURN,
};

// Frames of the slide in and the slide out, of the press and settle animation (GetSelectedPressOffset) with its
// highlight at the fifth, and of an index change (SelectEngine.mIndexChangeFramesRemaining counts them down). The
// cells slide in from SELECT_ENGINE_SLIDE_IN_DISTANCE_X, out to SELECT_ENGINE_SLIDE_OUT_DISTANCE_X, and vertically by
// SELECT_ENGINE_SLIDE_DISTANCE_Y.
#define SELECT_ENGINE_SLIDE_FRAMES 10
#define SELECT_ENGINE_PRESS_FRAMES 10
#define SELECT_ENGINE_HIGHLIGHT_FRAME 5
#define SELECT_ENGINE_INDEX_CHANGE_FRAMES 7
#define SELECT_ENGINE_SLIDE_IN_DISTANCE_X 224
#define SELECT_ENGINE_SLIDE_OUT_DISTANCE_X 192
#define SELECT_ENGINE_SLIDE_DISTANCE_Y 192

// The engine class select screen: its state, selected index, the alternate cell, layout tables and result.
typedef struct SelectEngine {
    /* 00 */ struct NNSG2dCellDataBank *mSelectEngineMNcer;
    /* 04 */ struct LayoutEntryTable *mSelectEngineMBncl;
    /* 08 */ struct NNSG2dCellDataBank *mSelectEngineSNcer;
    // gp/select_engine_B_s.bncl when CheckSavedSecretFlag_from_thumb(0x10) != 0, else gp/select_engine_A_s.bncl; the same flag hides
    // item 3 (A layout has no fourth item); the cells of item 3 are zeroed when
    // CheckSavedSecretFlag_from_thumb(0x10) is 0
    /* 0c */ struct LayoutEntryTable *mSelectEngineAOrBSBncl;
    // same variant as mSelectEngineAOrBSBncl (.bnbl)
    /* 10 */ void *mSelectEngineAOrBSBnbl;
    // one 0x40-byte record per cell of the Bncl (plus Bnll) members, built by InitLayoutTable
    /* 14 */ LayoutTableEntry *mSelectEngineMTable;
    // cell records of mSelectEngineAOrBSBncl (variant chosen by CheckSavedSecretFlag_from_thumb(0x10))
    /* 18 */ LayoutTableEntry *mSelectEngineAOrBSTable;
    /* 1c */ void *mVramTransferBuffer;
    /* 20 */ void *mHeap;
    /* 24 */ s32 mState;
    /* 28 */ s32 mNextState;
    /* 2c */ s32 mStateFrames; /* counted only in states 1, 2, 5, 6; zeroed by the next-state setter */
    /* 30 */ s32 mBg0Offset;
    /* 34 */ s32 mIndex;
    /* 38 */ BOOL mAlternateCellShown;
    /* 3c */ s32 mIndexChangeFramesRemaining;
    /* 40 */ s16 mLastChangeIndex;
    /* 42 */ u8 mUnk_42[0x2];
    /* 44 */ void *mMainOamList;
    /* 48 */ void *mSubOamList;
    /* 4c */ s32 mResult;
} SelectEngine;

// Values of EmblemCursor.mMode: what the cell under the cursor does when pressed.
enum {
    EMBLEM_CURSOR_MODE_DRAW,
    EMBLEM_CURSOR_MODE_ERASE,
    EMBLEM_CURSOR_MODE_FILL,
    EMBLEM_CURSOR_MODE_PICK_VALUE,
};

// Values of EmblemCursor.mSizeIndex: the square of cells one press writes.
enum {
    EMBLEM_BRUSH_1X1,
    EMBLEM_BRUSH_2X2,
    EMBLEM_BRUSH_3X3,
};

// Entries of the emblem screen's sub layout (the entryIndex of ActivateEmblemEntry and the entries of
// gEmblemColorLldEntries): the draw and erase brushes of three sizes each, the fill and pick value modes, the template,
// swap, camera and choices buttons, the colors and the button that toggles the frame of entry
// EMBLEM_ENTRY_TOGGLED_BY_BUTTON.
enum {
    EMBLEM_ENTRY_DRAW_BRUSH_FIRST = 0xe,
    EMBLEM_ENTRY_ERASE_BRUSH_FIRST = 0x11,
    EMBLEM_ENTRY_FILL = 0x14,
    EMBLEM_ENTRY_PICK_VALUE = 0x15,
    EMBLEM_ENTRY_TEMPLATE_BUTTON = 0x16,
    EMBLEM_ENTRY_SWAP_CELLS = 0x17,
    EMBLEM_ENTRY_TOGGLED_BY_BUTTON = 0x18,
    EMBLEM_ENTRY_CAMERA = 0x19,
    EMBLEM_ENTRY_CHOISES = 0x1a,
    EMBLEM_ENTRY_COLOR_FIRST = 0x1b,
    EMBLEM_ENTRY_TOGGLE_BUTTON = 0x2a,
};

// Calls of the callbacks that animate an emblem entry (LldEntry.mCallbackCallCount): the first phase (shrink) and the
// second phase (grow, or hold) each take EMBLEM_BUTTON_PHASE_CALLS, together EMBLEM_BUTTON_BOUNCE_CALLS; the color
// cursor grow runs the pending transition at EMBLEM_BUTTON_TRANSITION_CALL and ends after EMBLEM_BUTTON_FINISH_CALLS.
// Each call of the shrink or grow changes the scale by EMBLEM_BUTTON_SCALE_STEP.
#define EMBLEM_BUTTON_PHASE_CALLS 5
#define EMBLEM_BUTTON_BOUNCE_CALLS 10
#define EMBLEM_BUTTON_TRANSITION_CALL 11
#define EMBLEM_BUTTON_FINISH_CALLS 20
#define EMBLEM_BUTTON_SCALE_STEP 0x19a

// Colors the cursor can pick from the color entries (Emblem.mColorCursorIndex runs one past them to the toggle
// button).
#define EMBLEM_COLOR_COUNT 15

// Entries of the template screen: the back button, then one entry per template from EMBLEM_TEMPLATE_ENTRY_FIRST on.
enum {
    EMBLEM_TEMPLATE_ENTRY_BACK = 0,
    EMBLEM_TEMPLATE_ENTRY_FIRST = 3,
};

// Emblem.mCursorSizeIndex while the grid is pressed: no brush frame is shown.
#define EMBLEM_BRUSH_NONE (-1)

// The emblem editor cursor: its mode and size, the origin, the current and previous cell and the side.
typedef struct EmblemCursor {
    /* 00 */ s32 mMode;
    /* 04 */ s32 mSizeIndex;
    /* 08 */ u8 mCellValue;
    /* 09 */ u8 mDiffAmb[0x3];
    /* 0c */ s32 mCellShift;
    /* 10 */ s32 mOriginX;
    /* 14 */ s32 mOriginY;
    /* 18 */ s32 mSide;
    /* 1c */ u8 mUnk_1c[0xc];
    /* 28 */ s32 mPrevX;
    /* 2c */ s32 mPrevY;
    /* 30 */ s32 mPrevDown;
    /* 34 */ s32 mCellX;
    /* 38 */ s32 mCellY;
    /* 3c */ s32 mPrevCellX;
    /* 40 */ s32 mPrevCellY;
} EmblemCursor;

// A mission run boss icon: its character data, cell bank, palette and layout.
typedef struct MissionRunBossIcon {
    /* 00 */ Ncgr *mNcgr;
    /* 04 */ struct NNSG2dCellDataBank *mNcer;
    /* 08 */ Nclr *mNclr;
    /* 0c */ void *mBncl;
} MissionRunBossIcon;

extern OamEntryList *gNicknameBuffers;
extern OamEntryList *gOptionBuffers;

#include "00/Menu/wi_fi_vs_matching.h"
