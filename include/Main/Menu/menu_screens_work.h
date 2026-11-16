#pragma once
#include "types.h"
#include "sound_player_control.h"
#include "sound_player_type.h" // NNSSndPlayer
#include "sound_stream_control.h" // NNSSndStrmChannel
#include "sound_capture_effect.h" // CaptureParam, EffectInfo
#include "Main/Graphics/layout_rect_table.h" // LayoutEntryTable
#include "Main/Graphics/layout_entry_angle.h" // LayoutTableEntry
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h" // ScenePlayersSeqInfo
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h" // RaceHudOamBuffer
#include "sound_archive_load.h"
#include "Main/Graphics/text_canvas.h" // TextCanvas
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h" // SoundHandlePool

// Bytes of the second screen map buffer; the buffer is allocated with this size and transferred to a map by
// NNS_GfdRegisterNewVramTransferTask.
#define SECOND_SCREEN_MAP_BYTES 0x800

// Calls of the index change: the first rebuilds the page for the new mShownIndex, the other six move the cells by
// LookupIndexChangeOffset; mIndexChangeTimer counts down from this.
#define MENU_INDEX_CHANGE_FRAMES 7

// Frames the page button cells of the VS record screens shift after a page change was requested by the button or the
// left or right key; mOffsetTimers counts down from this.
#define RECORD_VS_OFFSET_TIMER_FRAMES 6
// Steps of the slide in and out of the VS record screens (RecordVS and RecordVSErase); mStateFrames counts them.
#define RECORD_VS_SLIDE_STEPS 10
// mStateFrames at which the sub screen cells 24 and 25 of the versus record screen change: AdvanceRecordVSSlideInSub
// shows 24 and hides 25, the two slide outs hide both, AdvanceRecordVSSubSlideInFromErase shows 24 and hides 25 again.
#define RECORD_VS_SLIDE_IN_SUB_SWAP_STEP 4
#define RECORD_VS_SUB_SLIDE_OUT_HIDE_STEP 6
#define RECORD_VS_SUB_RESLIDE_SWAP_STEP 2

typedef struct OSMessageQueue OSMessageQueue;

// Three words derived from a halfword.
typedef struct PaletteColorFields {
    /* 00 */ s32 mBits0To4;
    /* 04 */ s32 mBits5To9;
    /* 08 */ s32 mBits10To14;
} PaletteColorFields;

// A palette blend: the cycle frames, the palette in use, the from and to colors and their channel values.
typedef struct PaletteBlend {
    /* 00 */ s32 mCycleFrames;
    /* 04 */ BOOL mStopped;
    /* 08 */ u8 mPaletteIndex;
    /* 09 */ u8 mUnk_09;
    /* 0a */ u16 mPalette[5];
    /* 14 */ u16 mFromColors[4];
    /* 1c */ u16 mToColors[4];
    /* 24 */ u16 mUnk_24[3];
    /* 2a */ u8 mUnk_2a[2];
    /* 2c */ PaletteColorFields mBlendFrom[4];
    /* 5c */ PaletteColorFields mBlendTo[4];
    /* 8c */ BOOL mFirstBlend;
} PaletteBlend;

typedef struct CharacterKartPicks CharacterKartPicks;

// Holds the pointer to the character and kart picks.
typedef struct PicksHolder {
    /* 00 */ CharacterKartPicks *mPicks;
} PicksHolder;

struct Nclr;

// The files of a kart icon: its Ncgr, Ncer, three Nclr palettes and the Bncl.
typedef struct KartIcon {
    /* 00 */ struct Ncgr *mNcgr;
    /* 04 */ struct NNSG2dCellDataBank *mNcer;
    /* 08 */ struct Nclr *mNclrs[3];
    /* 14 */ void *mBncl;
} KartIcon;

struct NNSSndArc;

struct NNSSndStrmThread;

struct Ncgr;

struct Nscr;

// Calls each frame of the wait animation stays, and the frames it cycles through.
#define WAIT_FRAME_INDEX_CHANGE_FRAMES 4
#define WAIT_FRAME_INDEX_COUNT 3

// The wait animation: its loaded cell, graphics, palette and layout files, and the frame it shows.
typedef struct Wait {
    /* 00 */ struct NNSG2dCellDataBank *mNcer;
    /* 04 */ struct Ncgr *mNcgr;
    /* 08 */ struct Nclr *mNclr;
    /* 0c */ void *mBncl;
    /* 10 */ struct NNSG2dCellDataBank *mDestinationNcer;
    /* 14 */ struct LayoutEntryTable *mDestinationBncl;
    /* 18 */ u32 mDestinationBnclIndex;
    /* 1c */ u16 mPaletteIndex;
    /* 20 */ s32 mQueueSelector;
    /* 24 */ u16 mFrameIndex;
    /* 28 */ s32 mFrameIndexFrames;
} Wait;

// Values of RecordVSErase.mState and mNextState: intro text, the lower screen slides in, the page is browsed, a row is
// picked and the confirm text answered, then the objects slide back or the screen is left.
enum {
    RECORD_VS_ERASE_STATE_OPEN_INTRO_TEXT,
    RECORD_VS_ERASE_STATE_WAIT_INTRO_TEXT,
    RECORD_VS_ERASE_STATE_CLOSE_INTRO_TEXT,
    RECORD_VS_ERASE_STATE_SLIDE_IN_SUB,
    RECORD_VS_ERASE_STATE_BROWSE,
    RECORD_VS_ERASE_STATE_PAGE_SLIDE_OUT,
    RECORD_VS_ERASE_STATE_PAGE_SLIDE_IN,
    RECORD_VS_ERASE_STATE_SUB_SLIDE_OUT,
    RECORD_VS_ERASE_STATE_OPEN_CONFIRM_TEXT,
    RECORD_VS_ERASE_STATE_WAIT_CONFIRM_ANSWER,
    RECORD_VS_ERASE_STATE_CLOSE_CONFIRM_SLIDE_OUT_MAIN,
    RECORD_VS_ERASE_STATE_SLIDE_IN_AFTER_CONFIRM,
    RECORD_VS_ERASE_STATE_SUB_SLIDE_OUT_TO_SCREEN,
};

// Values of RecordVS.mPageDecrement: which way the page change goes.
enum {
    RECORD_VS_PAGE_INCREMENT,
    RECORD_VS_PAGE_DECREMENT,
};

// Values of RecordVSErase.mPageDecrement: which way the page change goes.
enum {
    RECORD_VS_ERASE_PAGE_INCREMENT,
    RECORD_VS_ERASE_PAGE_DECREMENT,
};

// Values of RecordVSErase.mTransientDrawn: the layout drawn for the shown record; TRANSIENT when the record has a
// friend key text.
enum {
    RECORD_VS_ERASE_VIEW_RECORD,
    RECORD_VS_ERASE_VIEW_TRANSIENT,
};

// The record VS erase screen: its loaded files, state, scroll offsets and the emblem it shows.
typedef struct RecordVSErase {
    /* 00 */ struct Ncgr *mRecordVSMNcgr;
    /* 04 */ struct NNSG2dCellDataBank *mRecordVSMNcer;
    /* 08 */ LayoutEntryTable *mRecordVSMBncl;
    /* 0c */ struct LayoutEntryTable *mRecordVSMBnll;
    /* 10 */ struct Nscr *mRecordVSM02Nscr;
    /* 14 */ LayoutTableEntry *mRecordVSMTable;
    /* 18 */ LayoutEntryTable *mRecordVSMTransientBncl;
    /* 1c */ struct LayoutEntryTable *mRecordVSMTransientBnll;
    /* 20 */ struct Nscr *mRecordVSM03Nscr;
    /* 24 */ LayoutTableEntry *mRecordVSMTransientTable;
    /* 28 */ struct Ncgr *mRecordVSSNcgr;
    /* 2c */ struct NNSG2dCellDataBank *mRecordVSSNcer;
    /* 30 */ LayoutEntryTable *mRecordVSSEraseBncl;
    /* 34 */ struct LayoutEntryTable *mRecordVSSEraseBnbl;
    /* 38 */ struct LayoutEntryTable *mRecordVSSEraseBnll;
    /* 3c */ LayoutTableEntry *mRecordVSSEraseTable;
    /* 40 */ s32 mTransientDrawn; /* RECORD_VS_ERASE_VIEW_* */
    /* 44 */ struct Bmg *mCommonMessages;
    /* 48 */ struct Bmg *mRecordMessages;
    /* 4c */ void *mSecondScreenMapBuffer;
    /* 50 */ void *mHeap;
    /* 54 */ s32 mState;
    /* 58 */ s32 mNextState;
    /* 5c */ s32 mStateFrames;
    /* 60 */ s32 mBg0OffsetX;
    /* 64 */ s32 mBg0OffsetY;
    /* 68 */ s32 mBg1OffsetX;
    /* 6c */ s32 mBg1OffsetY;
    /* 70 */ s32 mBg3Offset;
    /* 74 */ s16 mIndex;
    /* 76 */ s16 mPageIndex;
    /* 78 */ s32 mPageDecrement;
    /* 7c */ s32 mIndexChangeTimer;
    /* 80 */ s16 mShownIndex;
    /* 82 */ u8 mUnk_82[2];
    /* 84 */ u32 mErased;
    /* 88 */ struct EmblemData *mEmblem;
    /* 8c */ void *mEmblemConverted;
    /* 90 */ s32 mOffsetTimers[2];
    /* 98 */ BOOL mPageDecrementRepeat;
    /* 9c */ BOOL mPageIncrementRepeat;
    /* a0 */ s32 mNextScreen;
} RecordVSErase;

// The graphics, cell and layout files of the cup name objects.
typedef struct SelectCupNameM {
    /* 00 */ struct Ncgr *mNcgr;
    /* 04 */ struct NNSG2dCellDataBank *mNcer;
    /* 08 */ void *mBncl;
} SelectCupNameM;

// The files of a cup mark: its Ncgr, Ncer, Nclr and Bncl.
typedef struct CupMark {
    /* 00 */ struct Ncgr *mNcgr;
    /* 04 */ struct NNSG2dCellDataBank *mNcer;
    /* 08 */ struct Nclr *mNclr;
    /* 0c */ struct LayoutEntryTable *mBncl;
} CupMark;

// The scene's sequence players: its progress, sound state, sound row and the two sequence players.
typedef struct ScenePlayers {
    /* 00 */ s32 mProgress;
    /* 04 */ SceneSoundState *mSceneSoundState;
    /* 08 */ u8 mSoundRowIndex;
    /* 09 */ ScenePlayersSeqInfo mSeqInfo;
    /* 0c */ NNSSndSeqPlayer *mSeqPlayer;
    /* 10 */ NNSSndSeqPlayer *mSecondSeqPlayer;
} ScenePlayers;

// The scene sound mode: the scene players, the current and saved mode, the sequence start switch and the sound switch.
typedef struct SoundModeHolder {
    /* 00 */ ScenePlayers *mScenePlayers;
    /* 04 */ u32 mMode;
    /* 08 */ u32 mSavedMode;
    /* 0c */ u32 mSeqStartEnabled;
    /* 10 */ u32 mSoundsEnabled;
    /* 14 */ u32 mUnk_14;
    /* 18 */ NNSSndSeqPlayer **mKartStarSeqPlayer;
} SoundModeHolder;

// Values of SeqRowState.mFinishResult: the selected kart ends the race with the won flag, with neither flag, or with
// the lost flag.
enum {
    FINISH_RESULT_WON,
    FINISH_RESULT_NEITHER,
    FINISH_RESULT_LOST
};

// The state of a loaded sequence row: its loaded index, sequence heap, row and the finish result.
typedef struct SeqRowState {
    /* 00 */ s32 mLoadedIndex;
    /* 04 */ NNSSndHeap *mSeqHeap;
    /* 08 */ u32 *mSeqRow;
    // FINISH_RESULT_*
    /* 0c */ u32 mFinishResult;
} SeqRowState;

// Values of RecordVS.mState: the main screen slides in, the lower screen rows slide in, the page is browsed, and the
// reverse on leaving. SLIDE_OUT states move the objects off screen, SLIDE_IN states move them back.
enum {
    RECORD_VS_STATE_WAIT_FADE,
    RECORD_VS_STATE_SLIDE_IN_MAIN,
    RECORD_VS_STATE_SLIDE_IN_SUB,
    RECORD_VS_STATE_WAIT_RETURN_BUTTON,
    RECORD_VS_STATE_BROWSE,
    RECORD_VS_STATE_PAGE_SLIDE_OUT,
    RECORD_VS_STATE_PAGE_SLIDE_IN,
    RECORD_VS_STATE_SUB_SLIDE_OUT,
    RECORD_VS_STATE_MAIN_SLIDE_OUT,
    RECORD_VS_STATE_PRESS_BUTTON,
    RECORD_VS_STATE_SUB_SLIDE_OUT_REQUEST_SCREEN,
    RECORD_VS_STATE_SUB_SLIDE_IN,
};

// X offset of one screen width: an object moved by it (or its negative) is off screen.
#define RECORD_VS_OFFSCREEN_X 0x100

// The VS record screen: its state, page and highlighted index, scroll offsets, layout tables and messages.
typedef struct RecordVS {
    /* 00 */ struct Ncgr *mRecordVSMNcgr;
    /* 04 */ struct NNSG2dCellDataBank *mRecordVSMNcer;
    /* 08 */ LayoutEntryTable *mRecordVSMBncl;
    /* 0c */ struct LayoutEntryTable *mRecordVSMBnll;
    /* 10 */ struct Nscr *mRecordVSM02Nscr;
    // Object table of the main part of the screen (files mRecordVSMBncl / mRecordVSMBnll).
    /* 14 */ LayoutTableEntry *mRecordVSMTable;
    /* 18 */ LayoutEntryTable *mRecordVSMTransientBncl;
    /* 1c */ struct LayoutEntryTable *mRecordVSMTransientBnll;
    /* 20 */ struct Nscr *mRecordVSM03Nscr;
    // Object table of the transient part of the main screen (files mRecordVSMTransientBncl / mRecordVSMTransientBnll).
    /* 24 */ LayoutTableEntry *mRecordVSMTransientTable;
    /* 28 */ struct Ncgr *mRecordVSSNcgr;
    /* 2c */ struct NNSG2dCellDataBank *mRecordVSSNcer;
    /* 30 */ LayoutEntryTable *mRecordVSSBncl;
    /* 34 */ LayoutEntryTable *mRecordVSSBnbl;
    /* 38 */ struct LayoutEntryTable *mRecordVSSBnll;
    // Object table of the sub screen (files mRecordVSSBncl / mRecordVSSBnll).
    /* 3c */ LayoutTableEntry *mRecordVSSTable;
    /* 40 */ BOOL mShowsFriendKey;
    /* 44 */ struct Bmg *mRecordMessages;
    /* 48 */ void *mHeap;
    /* 4c */ s32 mState;
    /* 50 */ s32 mNextState;
    /* 54 */ s32 mStateFrames; /* counts only in states 1, 2, 5 to 11 */
    // X half of reg_G2_BG0OFS (0x04000010, main engine BG0), stored negated
    /* 58 */ s32 mBg0OffsetX;
    // Y half of reg_G2_BG0OFS (0x04000010, main engine BG0), stored negated
    /* 5c */ s32 mBg0OffsetY;
    // X half of reg_G2_BG1OFS (0x04000014, main engine BG1), stored negated
    /* 60 */ s32 mBg1OffsetX;
    // Y half of reg_G2_BG1OFS (0x04000014, main engine BG1), stored negated
    /* 64 */ s32 mBg1OffsetY;
    // Position of the highlight among the six items: 0 to 4 are the records of the page, 5 the extra item; -1 can be
    // stored (count % 5 - 1 in RefreshRecordVSPage).
    /* 68 */ s16 mIndex;
    /* 6a */ s16 mPageIndex;
    /* 6c */ s32 mPageDecrement;
    // Counts 7 down to 0 after mIndex changed: AdvanceRecordVSIndexChange sets 7 when mIndex differs from mShownIndex,
    // rebuilds the page text through PrintRecordVSShownRecord at 7 and moves the objects while it runs;
    // IsRecordVSIndexChangeRunning tells whether it is non-zero.
    /* 70 */ s32 mIndexChangeTimer;
    // mIndex the page text was last built for: PrintRecordVSShownRecord builds the text of the record mShownIndex, and
    // AdvanceRecordVSIndexChange starts mIndexChangeTimer when mIndex differs from it.
    /* 74 */ s16 mShownIndex;
    /* 76 */ u8 mUnk_76[2];
    /* 78 */ struct EmblemData *mEmblem;
    /* 7c */ void *mEmblemConverted;
    /* 80 */ s32 mOffsetTimers[2];
    /* 88 */ BOOL mPageDecrementRepeat;
    /* 8c */ BOOL mPageIncrementRepeat;
    // Screen to request when the exit ends; 6 sets the next scene instead.
    /* 90 */ s32 mNextScreen;
} RecordVS;

typedef enum SelectCupGridState {
    SELECT_CUP_GRID_STATE_WAIT_FADE = 0,
    SELECT_CUP_GRID_STATE_SLIDE_IN = 1,
    SELECT_CUP_GRID_STATE_WAIT_RETURN = 2,
    SELECT_CUP_GRID_STATE_CHOOSE = 3,
    SELECT_CUP_GRID_STATE_WAIT_CHOSEN = 4,
    SELECT_CUP_GRID_STATE_WAIT_CONFIRM_OPEN = 5,
    SELECT_CUP_GRID_STATE_WAIT_CONFIRM_CHOICES = 6,
    SELECT_CUP_GRID_STATE_WAIT_CONFIRM_ANSWER = 7,
    SELECT_CUP_GRID_STATE_WAIT_EXIT_OPEN = 8,
    SELECT_CUP_GRID_STATE_WAIT_EXIT_CHOICES = 9,
    SELECT_CUP_GRID_STATE_WAIT_EXIT_ANSWER = 10,
    SELECT_CUP_GRID_STATE_SLIDE_OUT = 11,
} SelectCupGridState;

typedef enum SelectCupGridMode {
    SELECT_CUP_GRID_MODE_SHOW_RECORDS = 0,
    SELECT_CUP_GRID_MODE_NO_RECORDS = 1,
    SELECT_CUP_GRID_MODE_NO_CONNECTION = 2,
    SELECT_CUP_GRID_MODE_MULTI_SIMPLE = 3,
    SELECT_CUP_GRID_MODE_MULTI_OTHER = 4,
} SelectCupGridMode;

// Steps of the slide in and out; mStateFrames counts them.
#define SELECT_CUP_GRID_SLIDE_STEPS 10
// X offset of the cup cells while they are off screen: this value off the right edge, its negative off the left edge.
#define SELECT_CUP_GRID_OFFSCREEN_X 0xe0
// mShownCourseFrames at which the shown course of the cup changes to the next.
#define SELECT_CUP_GRID_COURSE_SHOW_FRAMES 0x4b
// mStateFrames at which state WAIT_CHOSEN shows the highlight.
#define SELECT_CUP_GRID_HIGHLIGHT_STEP 5

// The screen that picks one of eight cups; choosing stores the cup index and the cup's first course id in
// gRaceSetupCopy.
typedef struct SelectCupGrid {
    /* 00 */ struct NNSG2dCellDataBank *mSelectCupMNcer;
    /* 04 */ LayoutEntryTable *mSelectCupMBncl;
    /* 08 */ struct LayoutEntryTable *mSelectCupMBnll;
    /* 0c */ struct NNSG2dCellDataBank *mSelectCupSNcer;
    /* 10 */ struct LayoutEntryTable *mSelectCupSBncl;
    /* 14 */ LayoutEntryTable *mSelectCupSBnbl;
    /* 18 */ LayoutTableEntry *mSelectCupMTable;
    /* 1c */ LayoutTableEntry *mSelectCupSTable;
    /* 20 */ void *mSecondScreenMapBuffer;
    /* 24 */ struct Bmg *mCommonMessages;
    /* 28 */ struct Bmg *mMenuMessages;
    /* 2c */ void *mHeap;
    /* 30 */ s32 mState;
    /* 34 */ s32 mNextState;
    /* 38 */ s32 mStateFrames;
    /* 3c */ s32 mMode;
    // Negated and shifted into the upper half-word of the BG0 offset register.
    /* 40 */ s32 mBg0Offset;
    /* 44 */ s32 mIndex;
    // One entry per cup: non-zero when the cup can be chosen, filled once at InitSelectCupGrid from
    // GetSelectCupGridCupEnabled; a disabled cup shows its other cells, plays the error sound when touched and is
    // skipped by the direction keys.
    /* 48 */ s32 mCupsEnabled[8];
    /* 68 */ BOOL mHighlightShown;
    // Counts 7 down to 0 after mIndex changed: AdvanceSelectCupGridIndexChange sets 7 when mIndex differs from
    // mShownIndex, rebuilds the cells at 7 and moves them while it runs; IsSelectCupGridIndexChangeRunning tells
    // whether it is non-zero.
    /* 6c */ s32 mIndexChangeTimer;
    // mIndex that the cells were last built for: AdvanceSelectCupGridIndexChange copies mIndex here when it rebuilds
    // them and starts mIndexChangeTimer when mIndex differs from it.
    /* 70 */ s32 mShownIndex;
    // Calls of AdvanceSelectCupGridShownCourse since the shown course changed; at 0x4b the next course is shown and it
    // restarts at 0.
    /* 74 */ s32 mShownCourseFrames;
    // Position 0 to 3 of the course of the cup at mIndex whose picture is shown: indexes
    // gSelectCupGridCourseIds[mIndex]; AdvanceSelectCupGrid also shows the cell of that position differently from the
    // other three.
    /* 78 */ s16 mShownCourseIndex;
    /* 7a */ u8 mUnk_7a[2];
    // Set when the cup picture was asked for; AdvanceSelectCupGrid queues its data once it is ready.
    /* 7c */ BOOL mCupPicturePending;
    /* 80 */ void *mMainOam;
    /* 84 */ void *mSubOam;
    /* 88 */ s32 mResult;
} SelectCupGrid;

// Value of SelectCupCourse.mMode.
typedef enum SelectCupCourseMode {
    SELECT_CUP_COURSE_MODE_WITH_GHOSTS = 0,
    SELECT_CUP_COURSE_MODE_NO_CONNECTION = 1,
    SELECT_CUP_COURSE_MODE_MULTI_SIMPLE = 2,
    SELECT_CUP_COURSE_MODE_MULTI_OTHER = 3,
} SelectCupCourseMode;

// Steps of the slide in and out; mStateFrames counts them.
#define SELECT_CUP_COURSE_SLIDE_STEPS 10
// mStateFrames at which state CONFIRM_PICK shows the highlight.
#define SELECT_CUP_COURSE_HIGHLIGHT_STEP 5
// Steps state CONFIRM_PICK runs before it moves on, once the index change has finished.
#define SELECT_CUP_COURSE_CONFIRM_STEPS 10
// Calls that states WAIT_CHOICES and CLOSE_CHOICES wait in mode MULTI_SIMPLE before its choices are looked at.
#define SELECT_CUP_COURSE_MULTI_SIMPLE_WAIT_FRAMES 0xf

// The cup course select screen: its state, mode, highlighted course, scroll offsets, layout tables, OAM lists, result.
typedef struct SelectCupCourse {
    /* 00 */ struct NNSG2dCellDataBank *mSelectCupCourseMNcer;
    /* 04 */ LayoutEntryTable *mSelectCupCourseTaOrVsMBncl; /* ta_m file when mMode == 0, vs_m otherwise */
    /* 08 */ struct LayoutEntryTable *mSelectCupCourseTaOrVsMBnll; /* ta_m file when mMode == 0, vs_m otherwise */
    /* 0c */ struct NNSG2dCellDataBank *mSelectCupMNcer;
    /* 10 */ LayoutEntryTable *mSelectCupMBncl;
    /* 14 */ LayoutEntryTable *mSelectCupMBnbl;
    /* 18 */ struct LayoutEntryTable *mSelectCupMBnll;
    // one 0x40-byte record per cell of the Bncl (plus Bnll) members, built by InitLayoutTable; assigned only when
    // mBootType is not BOOT_TYPE_MULTIBOOT
    /* 1c */ LayoutTableEntry *mSelectCupCourseTaOrVsMTable;
    // one 0x40-byte record per cell of the Bncl (plus Bnll) members, built by InitLayoutTable; assigned only when
    // mBootType is not BOOT_TYPE_MULTIBOOT
    /* 20 */ LayoutTableEntry *mSelectCupMTable;
    /* 24 */ void *mSecondScreenMapBuffer;
    /* 28 */ struct Bmg *mCommonMessages;
    /* 2c */ void *mGhostMessages;
    /* 30 */ void *mHeap;
    /* 34 */ s32 mState;
    /* 38 */ s32 mNextState;
    /* 3c */ s32 mStateFrames; /* counts only in states 1, 4, 5, 7, 8 */
    /* 40 */ s32 mMode;
    /* 44 */ s32 mBg0Offset;
    /* 48 */ s32 mBg3Offset; /* the sub engine's BG3 offset (0x0400101c); mBg0Offset is the main engine's */
    /* 4c */ u8 mUnk_4c[4];
    /* 50 */ s16
        mIndex; /* 0..3 position among the four courses of the cup: the course is gCupRowCourseIds[row][mIndex] */
    /* 52 */ u8 mUnk_52[2];
    /* 54 */ BOOL mHighlightShown;
    // Counts 7 down to 0 after mIndex changed: AdvanceSelectCupCourseIndexChange sets 7 when mIndex differs from
    // mShownIndex, rebuilds the page through RefreshSelectCupCourseForIndex at 7 and moves the objects while it runs;
    // IsSelectCupCourseIndexChangeRunning tells whether it is non-zero.
    /* 58 */ s32 mIndexChangeTimer;
    // mIndex the page was last built for: AdvanceSelectCupCourseIndexChange copies mIndex here when
    // RefreshSelectCupCourseForIndex rebuilds the page, and starts mIndexChangeTimer when mIndex differs from it.
    /* 5c */ s16 mShownIndex;
    /* 5e */ u8 mUnk_5e[2];
    // Set when the cup picture was asked for; the step queues its data once it is ready.
    /* 60 */ BOOL mCupPicturePending;
    /* 64 */ void *mMainOam;
    /* 68 */ void *mSubOam;
    /* 6c */ s32 mResult;
} SelectCupCourse;

// Option of the rules row with a race counter (mRaceCount).
#define SELECT_RACE_RULE_RACE 1

// Option of the rules row with a win counter (mWinCount).
#define SELECT_RACE_RULE_WIN 0

// Option of the rules row with no counter.
#define SELECT_RACE_RULE_FREE 2

typedef enum SelectRaceRuleState {
    SELECT_RACE_RULE_STATE_WAIT_FADE = 0,
    SELECT_RACE_RULE_STATE_SLIDE_IN = 1,
    SELECT_RACE_RULE_STATE_WAIT_RETURN = 2,
    SELECT_RACE_RULE_STATE_CHOOSE = 3,
    SELECT_RACE_RULE_STATE_WAIT_PRESS = 4,
    SELECT_RACE_RULE_STATE_WAIT_CONFIRM_OPEN = 5,
    SELECT_RACE_RULE_STATE_WAIT_CONFIRM_CHOICES = 6,
    SELECT_RACE_RULE_STATE_WAIT_CONFIRM_ANSWER = 7,
    SELECT_RACE_RULE_STATE_SLIDE_OUT = 8,
} SelectRaceRuleState;

typedef enum SelectRaceRuleMode {
    SELECT_RACE_RULE_MODE_VS_NO_CONNECTION = 0,
    SELECT_RACE_RULE_MODE_BATTLE_NO_CONNECTION = 1,
    SELECT_RACE_RULE_MODE_VS_MULTI_SIMPLE = 2,
    SELECT_RACE_RULE_MODE_BATTLE_MULTI_SIMPLE = 3,
    SELECT_RACE_RULE_MODE_VS_MULTI = 4,
    SELECT_RACE_RULE_MODE_BATTLE_MULTI = 5,
} SelectRaceRuleMode;

typedef enum SelectRaceRuleRow {
    SELECT_RACE_RULE_ROW_ENGINE = 0,
    SELECT_RACE_RULE_ROW_CPU_DIFFICULTY = 1,
    SELECT_RACE_RULE_ROW_COURSE_LIST = 2,
    SELECT_RACE_RULE_ROW_RULE_KIND = 3,
    SELECT_RACE_RULE_ROW_TEAMS = 4,
} SelectRaceRuleRow;

// Number of rows of the race rule screen: one entry each in mRowValues and mRowChangeTimers.
#define SELECT_RACE_RULE_ROW_COUNT 5

// Value of the engine row that races mirrored: the engine index of value 2 is set and SetMirrorMode is called.
#define SELECT_RACE_RULE_ENGINE_MIRROR 3
// Value of the teams row where each player picks the team: the team change cells show and each entry's L, R or touch on
// the change cells moves its team.
#define SELECT_RACE_RULE_TEAMS_PLAYER_PICKS 2

// Steps of the slide in and out; mStateFrames counts them.
#define SELECT_RACE_RULE_SLIDE_STEPS 10
// Steps state WAIT_PRESS runs after the button was pressed.
#define SELECT_RACE_RULE_PRESS_STEPS 10
// mStateFrames at which state WAIT_PRESS shows the pressed button.
#define SELECT_RACE_RULE_HIGHLIGHT_STEP 5

// The race rule select screen: its mode, state, highlighted row, the value of each row, change timers and layout files.
typedef struct SelectRaceRule {
    /* 00 */ struct NNSG2dCellDataBank *mNcer;
    /* 04 */ LayoutEntryTable *mBncl;
    /* 08 */ LayoutEntryTable *mBnbl;
    /* 0c */ struct LayoutEntryTable *mBnll;
    /* 10 */ struct Nclr *mNclr; /* the _o palette */
    // Object table allocated for the bncl / bnll of this screen.
    /* 14 */ LayoutTableEntry *mTable;
    // Messages of common.bmg.
    /* 18 */ struct Bmg *mCommonMessages;
    // Messages of rule.bmg.
    /* 1c */ struct Bmg *mRuleMessages;
    /* 20 */ struct Nscr *mNscr; /* multi_simple_s (mMode == 3) or s_menu, two files */
    /* 24 */ void *mSecondScreenMapBuffer;
    /* 28 */ void *mHeap;
    /* 2c */ s32 mMode;
    /* 30 */ s32 mState;
    /* 34 */ s32 mNextState;
    /* 38 */ s32 mStateFrames;
    // Set to 6 when the row's value is stepped ([row][0] down, [row][1] up), counted down each step; moves the row's
    // pair of objects.
    /* 3c */ s16 mRowChangeTimers[SELECT_RACE_RULE_ROW_COUNT][2];
    // Same shape for the row 3 count ([0][0] down, [0][1] up) and the row 4 teams ([1][0] and [1][1] by the team a
    // player lands in).
    /* 50 */ s16 mCountTeamChangeTimers[2][2];
    // Vertical shift in lines of the whole layout, 0 or -0x1c by mode; added to the positions of the objects and taken
    // off the touch y.
    /* 58 */ s16 mOffsetY;
    /* 5a */ u8 mUnk_5a[0x02];
    // Offset stored negated into the sub engine's BG3 offset register.
    /* 5c */ s32 mBg3Offset;
    // Row (0 to 4) the highlight is on; the value of row n is mRowValues[n].
    /* 60 */ s32 mRow;
    // Row at the start of the step, to see whether it changed.
    /* 64 */ s32 mPrevRow;
    // Value of each row, 0 up to the row's count minus 1; stepped up and down with wrap.
    /* 68 */ s32 mRowValues[SELECT_RACE_RULE_ROW_COUNT];
    // Non-zero while the highlight is on the button below the rows instead of on a row.
    /* 7c */ s32 mOnButton;
    // mOnButton at the start of the step.
    /* 80 */ s32 mPrevOnButton;
    // 0 while the pressed button is drawn plain, back to 1 five calls into state 4.
    // Decides which of the button's two objects shows.
    /* 84 */ u32 mButtonHighlightShown;
    // Count of the win option of row 3, kept from 1 to 10.
    /* 88 */ s16 mWinCount;
    // Count of the race option of row 3, kept from 1 to 0x20.
    /* 8a */ s16 mRaceCount;
    // Team index of each of the 8 entries.
    /* 8c */ u32 mPlayerTeamIndices[8];
    // Per team: how many of the first entries are in it.
    /* ac */ u16 mTeamHumanCounts[2];
    // Per team: how many of the entries after the first ones are in it; counted into a team's size only while row 1 is
    // not 0.
    /* b0 */ u16 mTeamNonHumanCounts[2];
    /* b4 */ void *mOamList;
    // Result AdvanceSelectRaceRule returns in state 8 once the state has run 10 calls: 1 or 2; 0 until set.
    /* b8 */ vu32 mResult;
} SelectRaceRule;

// The files of a trophy icon: its Ncgr, Ncer, Nclr and Bncl.
typedef struct TrophyIcon {
    /* 00 */ struct Ncgr *mNcgr;
    /* 04 */ struct NNSG2dCellDataBank *mNcer;
    /* 08 */ struct Nclr *mNclr;
    /* 0c */ void *mBncl;
} TrophyIcon;

// SelectRaceRuleWait.mState and mNextState values: moving up into view, resting, moving down out of view.
typedef enum SelectRaceRuleWaitState {
    SELECT_RACE_RULE_WAIT_SLIDE_IN = 0,
    SELECT_RACE_RULE_WAIT_REST = 1,
    SELECT_RACE_RULE_WAIT_SLIDE_OUT = 2,
} SelectRaceRuleWaitState;

// y offset of the wait cells while they are off screen, and steps of the slide; mStateFrames counts them.
#define SELECT_RACE_RULE_WAIT_OFFSCREEN_Y 0xc0
#define SELECT_RACE_RULE_WAIT_SLIDE_STEPS 10

// The wait cells that the cup, cup grid, character and kart screens show in connected modes, built from the race rule
// screen files: its layout files, messages, OAM list and state.
typedef struct SelectRaceRuleWait {
    /* 00 */ struct NNSG2dCellDataBank *mNcer;
    /* 04 */ LayoutEntryTable *mBncl;
    /* 08 */ u8 mUnk_08[0x4];
    /* 0c */ struct LayoutEntryTable *mBnll;
    /* 10 */ LayoutTableEntry *mTable;
    /* 14 */ void *mCommonMessages;
    /* 18 */ void *mOamList;
    /* 1c */ s32 mState;
    /* 20 */ s32 mNextState;
    /* 24 */ s32 mStateFrames;
} SelectRaceRuleWait;

// Values of SeqPlayerControl.mVolumeOverride: normal volume, volume target 0, volume target full.
#define SEQ_VOLUME_OVERRIDE_NONE 0
#define SEQ_VOLUME_OVERRIDE_ZERO 1
#define SEQ_VOLUME_OVERRIDE_FULL 2

// Bits of SeqPlayerControl.mFlags (SEQ_PLAYER_BIT_ is the bit number): the selected Kart is small from the Thunder
// item, a Teresa effect runs on it, and the scene seq restarted (pitch 0x40 and a volume target 10 lower, only while
// the race runs and the Thunder bit is clear).
#define SEQ_PLAYER_BIT_THUNDER_SHRINK 1
#define SEQ_PLAYER_BIT_TERESA 2
#define SEQ_PLAYER_BIT_RESTARTED 3
#define SEQ_PLAYER_FLAG_THUNDER_SHRINK (1 << SEQ_PLAYER_BIT_THUNDER_SHRINK)
#define SEQ_PLAYER_FLAG_TERESA (1 << SEQ_PLAYER_BIT_TERESA)
#define SEQ_PLAYER_FLAG_RESTARTED (1 << SEQ_PLAYER_BIT_RESTARTED)

// The control values of a sequence player: a volume override, a pitch angle, sound flags and the near-kart value.
typedef struct SeqPlayerControl {
    /* 00 */ s32 mVolumeOverride;
    /* 04 */ s32 mPitchAngle;
    // Mask 2 is set while the selected Kart is small from the Thunder item (SetThunderShrinkSoundFlag); mask 4 while a
    // Teresa effect runs on it (SetTeresaSoundFlag).
    /* 08 */ s32 mFlags;
    /* 0c */ u32 mKartNear;
} SeqPlayerControl;

// SeqQueue: the number of entries, the pair stored to clear an entry (an entry is empty when its mPairNo is the first
// of them), and the frames to wait after a start.
#define SEQ_QUEUE_LENGTH 14
#define SEQ_QUEUE_EMPTY_PAIR_NO 13
#define SEQ_QUEUE_EMPTY_PAIR_SIDE 2
#define SEQ_QUEUE_START_DELAY_FRAMES 0x19

// Object at gSeqQueue.
typedef struct SeqQueue {
    // 14 queued pairs; 13 in mPairNo and 2 in mPairSide mark an empty entry.
    /* 00 */ s32 mPairNo[SEQ_QUEUE_LENGTH];
    /* 38 */ s32 mPairSide[SEQ_QUEUE_LENGTH];
    /* 70 */ s32 mWriteIndex;
    /* 74 */ s32 mReadIndex;
    /* 78 */ s32 mNextStartTimer;
} SeqQueue;

// A set of ghost records: those of the course, of the slot and of the ghost file, with the course id and slot index.
typedef struct GhostRecordSet {
    /* 00 */ struct GhostRecordHead *mCourseGhostRecords;
    /* 04 */ struct GhostListEntry *mSlotGhostRecords;
    /* 08 */ struct GhostListEntry *mGhostFileRecords;
    /* 0c */ u32 mCourseId;
    /* 10 */ s16 mSlotIndex;
} GhostRecordSet;

// Y offset of one screen height: the main objects slide down by it and the lower objects start its negative. The lower
// objects end the slide at SELECT_CUP_M_SUB_END_OFFSET_Y.
#define SELECT_CUP_M_OFFSCREEN_Y 0xc0
#define SELECT_CUP_M_SUB_END_OFFSET_Y (-0x20)

// Values of SelectCupM.mState and mNextState: the main objects slide down off the screen while the sub objects come in
// from above (SCROLL_DOWN), or the same slide runs backwards (SCROLL_UP); in the multiboot boot type nothing moves and
// only mStateFrames counts.
enum {
    SELECT_CUP_M_STATE_SCROLL_DOWN,
    SELECT_CUP_M_STATE_SCROLL_UP,
};

// Steps of the scroll in either direction; mStateFrames counts them and the state ends once it is above this.
#define SELECT_CUP_M_SCROLL_STEPS 10

// The cup select screen: its main and sub layout files, state and scroll offsets.
typedef struct SelectCupM {
    /* 00 */ struct NNSG2dCellDataBank *mMainNcer;
    /* 04 */ LayoutEntryTable *mMainBncl;
    /* 08 */ struct LayoutEntryTable *mMainBnll;
    /* 0c */ struct NNSG2dCellDataBank *mSubNcer;
    /* 10 */ LayoutEntryTable *mSubBncl;
    /* 14 */ struct LayoutEntryTable *mSubBnll;
    /* 18 */ LayoutTableEntry *mMainTable;
    /* 1c */ LayoutTableEntry *mSubTable;
    /* 20 */ void *mSecondScreenMapBuffer;
    /* 24 */ struct Bmg *mCommonMessages;
    /* 28 */ void *mHeap;
    /* 2c */ s32 mState;
    /* 30 */ s32 mNextState;
    /* 34 */ s32 mStateFrames;
    /* 38 */ BOOL mCupPicturePending;
    /* 3c */ s32 mBg0Offset;
    /* 40 */ s32 mBg3Offset;
    /* 44 */ u8 mUnk_44[0x04];
    /* 48 */ void *mMainOam;
    /* 4c */ void *mSubOam;
    /* 50 */ s32 mUnk_50;
} SelectCupM;

// One slot number of the table.
typedef struct RecordListEntry {
    /* 00 */ u16 mRecordIndex;
} RecordListEntry;

// The used slots in display order, with the emblem block and the emblem2.bin picture.
typedef struct RecordList {
    /* 00 */ u16 mRecordCount;
    /* 02 */ u8 mUnk_02[2];
    /* 04 */ RecordListEntry *mEntries;
    /* 08 */ struct EmblemBlock *mEmblemBlock;
    /* 0c */ void *mEmblem2Bin;
} RecordList;

// The scene text state: which of TxtSystem, SelectChoises and SelectReturn are used, the back screen kind, its screen
// map copy and the sub char offset.
typedef struct SceneText {
    /* 000 */ BOOL mUseTxtSystem;
    /* 004 */ BOOL mUseSelectChoises;
    /* 008 */ BOOL mUseSelectReturn;
    /* 00c */ s32 mBackScreenKind;
    /* 010 */ u16 mBackScreenSNscrCopy[0x400];
    /* 810 */ s32 mSubCharOffset;
} SceneText;

// Values of TxtSystem.mState, mNextState and mPrevState: the box is closed, slides in, takes input, shows a pressed
// button, or slides out.
enum {
    TXT_SYSTEM_STATE_CLOSED,
    TXT_SYSTEM_STATE_OPENING,
    TXT_SYSTEM_STATE_OPEN,
    TXT_SYSTEM_STATE_BUTTON_PRESSED,
    TXT_SYSTEM_STATE_CLOSING,
};

// Steps of the opening and closing slide; mStateFrames counts them.
#define TXT_SYSTEM_SLIDE_STEPS 15
// Steps state BUTTON_PRESSED runs; the button colors are queued on each step from TXT_SYSTEM_PRESS_COLOR_STEP up to the
// one before the last.
#define TXT_SYSTEM_PRESS_STEPS 10
#define TXT_SYSTEM_PRESS_COLOR_STEP 5
// Sound ids of the first button, of the second button and of the opening of a text box.
#define TXT_SYSTEM_INPUT_SOUND_ID 5
#define TXT_SYSTEM_SECOND_INPUT_SOUND_ID 0x10
#define TXT_SYSTEM_OPEN_SOUND_ID 0x23
// Calls each frame of the text box animation stays, and the number of frames it cycles through.
#define TXT_SYSTEM_ANIM_FRAME_TICKS 4
#define TXT_SYSTEM_ANIM_FRAME_COUNT 3

// Values of TxtSystem.mMode: which input slot the text box reads touches from.
#define TXT_SYSTEM_MODE_PAD_OR_PARTICIPANT 0
#define TXT_SYSTEM_MODE_PAD_AND_TOUCH 1

// The text box system InitTxtSystem allocates: its state, requests, screen buffers, offsets, blend settings, canvases.
typedef struct TxtSystem {
    /* 0000 */ u32 mState;
    /* 0004 */ u32 mNextState;
    /* 0008 */ u32 mPrevState;
    /* 000c */ s32 mStateFrames;
    /* 0010 */ s32 mAnimFrameIndexFrames;
    /* 0014 */ s32 mAnimFrameIndex;
    /* 0018 */ u32 mAnimVisible[2];
    /* 0020 */ u32 mAnimRequested[2];
    /* 0028 */ s32 mExtraCanvasCount;
    /* 002c */ u32 mSelectedIndex;
    /* 0030 */ u32 mDone;
    /* 0034 */ u32 mOpenRequested;
    /* 0038 */ u32 mCloseRequested;
    /* 003c */ u32 mOpenFromIndex;
    /* 0040 */ u32 mCloseToIndex;
    /* 0044 */ u32 mUseCanvas1;
    /* 0048 */ u32 mUseCanvas2;
    /* 004c */ u32 mUseCanvas3;
    /* 0050 */ u32 mEnabled;
    /* 0054 */ u16 mMainScreenBuffer[0x800];
    /* 1054 */ u16 mSubScreenBuffer[0x800];
    /* 2054 */ s32 mBgOffset[2];
    /* 205c */ s32 mBgOffsetAtOpen[2];
    /* 2064 */ s32 mBgOffsetRequested[2];
    /* 206c */ s32 mBlendPlanesEnabled[2];
    /* 2074 */ u32 mBlendPlanesRequested[2];
    /* 207c */ s32 mBrightness;
    /* 2080 */ u32 mBlendPlanes[2];
    /* 2088 */ u32 mBlendEv1[2];
    /* 2090 */ u32 mBlendEv2[2];
    /* 2098 */ NNSG2dCharCanvas mCharCanvases[7];
    /* 2178 */ TextCanvas mTextCanvases[7];
    /* 21e8 */ void *mCharBuffers[7];
    /* 2204 */ u32 mCanvasInUse[7];
    /* 2220 */ u32 mCanvasFileCharIndex[7];
    /* 223c */ u32 mB01CharIndex[2];
    /* 2244 */ u16 mUnselectedButtonColor;
    /* 2246 */ u16 mSelectedButtonColor;
    /* 2248 */ u32 mMode;
    /* 224c */ u32 mInputAccepted;
    /* 2250 */ s32 mInputSoundId;
    /* 2254 */ s32 mSecondInputSoundId;
    /* 2258 */ s32 mOpenSoundId;
    /* 225c */ struct Nscr *mBgNscrs[7];
} TxtSystem;

// Bytes of each SelectChoises.mCharBuffers entry: the tiles of one 32 by 2 tile canvas.
#define SELECT_CHOISES_CHAR_BUFFER_BYTES 0x800

// Values of SelectChoises.mState and mNextState: the two choices are hidden, waiting for a choice, or showing the
// choice made.
enum {
    SELECT_CHOISES_STATE_HIDDEN,
    SELECT_CHOISES_STATE_CHOOSE,
    SELECT_CHOISES_STATE_CHOSEN,
};

// Frames the chosen choice is shown (mChosenFrames); choosing none (the B key) starts it at NONE_START_FRAME so it ends
// sooner.
#define SELECT_CHOISES_CHOSEN_FRAMES 0xf
#define SELECT_CHOISES_NONE_START_FRAME 0xb
// mToggleFrames above which the toggle mark flips: ON while it is shown, OFF while it is hidden.
#define SELECT_CHOISES_TOGGLE_ON_LIMIT 0x1e
#define SELECT_CHOISES_TOGGLE_OFF_LIMIT 0x14
// GetSelectChoisesIndex result when no choice was made.
#define SELECT_CHOISES_INDEX_NONE -1
// Sound ids of the first choice, the second choice and none (the B key).
#define SELECT_CHOISES_FIRST_SOUND_ID 7
#define SELECT_CHOISES_SECOND_SOUND_ID 0x10
#define SELECT_CHOISES_NONE_SOUND_ID 0x10

// A pair of choice buttons: its state, chosen index, screen map copy, text canvases and sound ids.
typedef struct SelectChoises {
    /* 000 */ u32 mEnabled;
    /* 004 */ s32 mState;
    /* 008 */ u32 mNextState;
    /* 00c */ u32 mChosenFrames;
    /* 010 */ s32 mToggleFrames;
    /* 014 */ u32 mToggleOn;
    /* 018 */ u32 mIndex;
    /* 01c */ u32 mDone;
    /* 020 */ u32 mIndexNone;
    /* 024 */ u32 mChooseRequested;
    /* 028 */ u32 mHiddenRequested;
    /* 02c */ u16 mNscrCopy[0x400];
    /* 82c */ u32 mToggleOnFirstTile;
    /* 830 */ u32 mToggleOffFirstTile;
    /* 834 */ NNSG2dCharCanvas mCharCanvases[2];
    /* 874 */ TextCanvas mTextCanvases[2];
    /* 894 */ u8 *mCharBuffers[2];
    /* 89c */ s32 mFirstTileIndex;
    /* 8a0 */ u32 mUseCharBuffers;
    // Non-zero when the display bit was set at init; also gates the choice sounds.
    /* 8a4 */ u32 mDisplayBitOn;
    /* 8a8 */ s32 mSoundIds[2];
    /* 8b0 */ s32 mIndexNoneSoundId;
} SelectChoises;

// Object behind gSelectReturn: 0x828 bytes allocated by InitSelectReturn.
// Values of SelectReturn.mState and mNextState: the return button is hidden, slides in, waits, plays its press, or
// slides out.
enum {
    SELECT_RETURN_STATE_HIDDEN,
    SELECT_RETURN_STATE_SLIDE_IN,
    SELECT_RETURN_STATE_SHOWN,
    SELECT_RETURN_STATE_PRESS,
    SELECT_RETURN_STATE_SLIDE_OUT,
};

// Steps the return button slides in and out, and steps its press runs; mStateFrames counts them.
#define SELECT_RETURN_SLIDE_STEPS 10
#define SELECT_RETURN_PRESS_STEPS 9
// Sound id of the return button.
#define SELECT_RETURN_SOUND_ID 0xe

// The return button: its state, slide and press requests, screen map copy and sound id.
typedef struct SelectReturn {
    /* 000 */ BOOL mEnabled; /* only ever set to 1 by InitSelectReturn; the off path does not run in this build */
    /* 004 */ s32 mState;
    /* 008 */ s32 mNextState;
    /* 00c */ s32 mStateFrames; /* counts only in states 1, 3, 4 */
    /* 010 */ u16 mScreenMapCopy[0x400];
    /* 810 */ BOOL mSlideInRequested;
    /* 814 */ BOOL mPressRequested;
    /* 818 */ BOOL mSlideOutRequested;
    /* 81c */ s32 mBg2Offset;
    /* 820 */ BOOL mDisplayBitOn;
    /* 824 */ s32 mSoundId;
} SelectReturn;

// One OAM record of a link level icon: its position and size bits and its char and palette bits.
typedef struct LinkLevelIconOam {
    /* 00 */ u32 mPositionAndSizeBits;
    /* 04 */ u16 mCharAndPaletteBits;
    /* 06 */ u8 mUnk_06[2];
} LinkLevelIconOam;

// The OAM lists of the keyboard scene: one for the main and one for the sub screen.
typedef struct KeyboardScene {
    /* 000 */ RaceHudOamBuffer mMainOam;
    /* 404 */ RaceHudOamBuffer mSubOam;
} KeyboardScene;

// A record of the keyboard text: characters, plus the first button, mode and next scene in the third record.
typedef struct KeyboardRecord {
    /* 00 */ union {
        u16 mChars[12];
        struct {
            /* 00 */ u16 mUnk_00_0[8];
            /* 10 */ s32 mFirstButtonChosen;
            // Mode of the screen as passed in by the scene (0xc, 7 or 0xb); element 2 of Keyboard.mRecords only: in
            // element 0 these bytes are character 10 of the text.
            /* 14 */ s16 mMode;
            // Scene to run when the keyboard ends, -1 until set; element 2 of Keyboard.mRecords only: in element 0
            // these bytes are character 11 of the text.
            /* 16 */ s16 mNextScene;
        };
    };
} KeyboardRecord;

// Values of Keyboard.mState and mNextState. The friend code states come first, the name states from
// KEYBOARD_STATE_WAIT_FADE_NAME on. The screen starts at the first friend code state when it asks for a friend code
// and at KEYBOARD_STATE_WAIT_FADE_NAME otherwise.
typedef enum KeyboardState {
    KEYBOARD_STATE_WAIT_FADE_FRIEND_KEY = 0,
    KEYBOARD_STATE_SLIDE_IN_FRIEND_KEY = 1,
    KEYBOARD_STATE_ENTER_FRIEND_KEY = 2,
    KEYBOARD_STATE_SLIDE_OUT_FRIEND_KEY = 3,
    KEYBOARD_STATE_SHOW_FRIEND_KEY_ERROR = 4,
    KEYBOARD_STATE_WAIT_FADE_NAME = 5,
    KEYBOARD_STATE_SLIDE_IN_NAME = 6,
    KEYBOARD_STATE_ENTER_NAME = 7,
    KEYBOARD_STATE_SLIDE_OUT_NAME = 8,
    KEYBOARD_STATE_SLIDE_IN_CONFIRM = 9,
    KEYBOARD_STATE_ANSWER_CONFIRM = 10,
    KEYBOARD_STATE_SHOW_SAVING = 11,
    KEYBOARD_STATE_WAIT_BACKUP = 12,
    KEYBOARD_STATE_ASK_EMBLEM = 13,
} KeyboardState;

// Values of Keyboard.mKind: what the text being entered is.
typedef enum KeyboardKind {
    KEYBOARD_KIND_FRIEND_KEY = 0,
    KEYBOARD_KIND_NAME = 1,
} KeyboardKind;

// Elements of Keyboard.mRecords: the text of each kind, then the record that holds the screen's mode, chosen button and
// next scene.
#define KEYBOARD_RECORD_STATUS 2

// Value of KeyboardRecord.mNextScene while the screen has no scene to run yet.
#define KEYBOARD_NEXT_SCENE_NONE (-1)

// Frames the slide in and slide out states take, and the offset in lines of the screen slid out of view.
#define KEYBOARD_SLIDE_FRAMES 0xf
#define KEYBOARD_OFFSET_HIDDEN 0xc0
// Offset that moves an object far off the screen.
#define KEYBOARD_OBJECT_HIDDEN_OFFSET (-500)
// Frames the friend code error message stays, and the shortest time the saving message stays.
#define KEYBOARD_ERROR_FRAMES 0x78
#define KEYBOARD_SAVING_FRAMES 0x5a

// The on-screen keyboard screen: its heap, state, records, object tables, offsets, background files and messages.
typedef struct Keyboard {
    // Heap the screen's objects are allocated from.
    /* 00 */ void *mHeap;
    // Which of the two sets (background files, text records, cell counts, object tables) the screen works on, 0 or 1;
    // set from the mode argument at start, to 1 in state 3 and back to 0 in state 8.
    /* 04 */ s32 mKind;
    /* 08 */ s32 mLayout;
    /* 0c */ s32 mState;
    /* 10 */ s32 mNextState;
    /* 14 */ BOOL mCursorOnButton[2];
    // Per button: non-zero while the button accepts its input; button 0 needs text entered.
    /* 1c */ BOOL mButtonEnabled[2];
    /* 24 */ BOOL mTextEntryEnabled;
    // Calls spent in the current state: counted up by the handlers of states 1, 3, 4, 6, 8, 9 and 11, and by state 10
    // only while GetTxtSystemDone or IsTxtSystemClosedNoOpenRequest returns non-zero; zeroed by the handler that
    // leaves; the slide states hold it at 0xf.
    /* 28 */ s32 mStateFrames;
    /* 2c */ KeyboardRecord mRecords[3];
    // Object tables of the keyboard, indexed by kind and by the buffer they are drawn to.
    /* 74 */ LayoutTableEntry *mTables[2][2];
    // Vertical shift in lines of the whole screen (0xc0 = slid out of view, 0 = in place); also stored negated into the
    // vertical half of the sub engine's BG3 offset.
    /* 84 */ s16 mOffsetY;
    /* 86 */ s16 mTextOffsetY[2][2];
    /* 8e */ u8 mUnk_8e[2];
    /* 90 */ struct NNSG2dCellDataBank *mNcer;
    /* 94 */ struct Ncgr *mNcgr;
    /* 98 */ struct Nclr *mNclr;
    /* 9c */ LayoutEntryTable *mBncls[2];
    /* a4 */ LayoutEntryTable *mBnbls[2];
    /* ac */ void *mBnlls[2];
    /* b4 */ struct Nscr *mNscrs[2]; /* [0] flame02, [1] flame01 */
    /* bc */ void *mDisplaySettings;
    // Messages of common.bmg.
    /* c0 */ struct Bmg *mCommonMessages;
} Keyboard;

// One character tile of an Ncgr.
typedef struct CharTile {
    /* 00 */ u8 mUnk_00[0x20];
} CharTile;

// The x and y position of one link level icon.
typedef struct LinkLevelIconPos {
    /* 00 */ s32 mX;
    /* 04 */ s32 mY;
} LinkLevelIconPos;

// Icons of LinkLevelIcons (the index of mIconEnabled and the value of mIconKind): the wireless link level, the Wi-Fi
// link level and the Wi-Fi buddy mark.
#define LINK_LEVEL_ICON_WIRELESS 0
#define LINK_LEVEL_ICON_WIFI 1
#define LINK_LEVEL_ICON_WIFI_BUDDY 4
// Last frame of the blink cycle of the buddy mark (it goes back to 0 after it), and the frame it is hidden from.
#define LINK_LEVEL_ICON_CYCLE_LAST_FRAME 0x78
#define LINK_LEVEL_ICON_HIDDEN_FROM_FRAME 0x69

// The link level icons: which are enabled, their kinds, levels and positions, the OAM list, chars and OAM records.
typedef struct LinkLevelIcons {
    /* 000 */ s32 mIconEnabled[5];
    /* 014 */ s32 mIconKind[2];
    /* 01c */ s32 mIconLevel[2];
    /* 024 */ s32 mCycleFrames;
    /* 028 */ LinkLevelIconPos mIconPositions[2];
    /* 038 */ RaceHudOamBuffer *mOamList;
    /* 03c */ u8 mZeroChars[0x20];
    /* 05c */ u8 mUnk_05c[0x60];
    /* 0bc */ CharTile *mIconChars[5][4];
    /* 10c */ LinkLevelIconOam mOamRecords[2];
} LinkLevelIcons;

// The message screen: its kind, whether input is enabled, text, open flag and result, with the char canvas, text
// canvas, char buffer and screen map it draws to.
typedef struct MessageScreen {
    /* 0000 */ s32 mKind;
    /* 0004 */ s32 mInputEnabled;
    /* 0008 */ void *mText;
    /* 000c */ BOOL mOpen;
    /* 0010 */ s32 mResult;
    /* 0014 */ u8 mCharCanvas[0x20];
    /* 0034 */ TextCanvas mTextCanvas;
    /* 0044 */ u16 mCharBuffer[0xa00];
    /* 1444 */ u16 mScreenMap[0x300];
} MessageScreen;

// A tag in the staff roll text stream: a character, its size, kind, variant and argument.
typedef struct StaffRollTag {
    /* 00 */ u16 mCharacter;
    /* 02 */ u8 mSize;
    /* 03 */ u8 mKind;
    /* 04 */ u16 mVariant;
    /* 06 */ u16 mArgument;
} StaffRollTag;

// StaffRollTag.mVariant values of a tag with mKind 1: set the line alignment (argument below), end the line and skip
// argument lines, set the text color, store the character spacing, set the scroll speed (percent of 1.0 per frame,
// fixed point), change nothing, end of the text.
typedef enum StaffRollTagVariant {
    STAFF_ROLL_TAG_ALIGN = 0,
    STAFF_ROLL_TAG_SKIP_LINES = 1,
    STAFF_ROLL_TAG_COLOR = 2,
    STAFF_ROLL_TAG_CHAR_SPACING = 3,
    STAFF_ROLL_TAG_SCROLL_SPEED = 4,
    STAFF_ROLL_TAG_NO_EFFECT = 5,
    STAFF_ROLL_TAG_END = 0x63,
} StaffRollTagVariant;

// Argument of STAFF_ROLL_TAG_ALIGN.
typedef enum StaffRollAlign {
    STAFF_ROLL_ALIGN_LEFT = 0,
    STAFF_ROLL_ALIGN_CENTER = 1,
    STAFF_ROLL_ALIGN_RIGHT = 2,
} StaffRollAlign;

// Scroll speed before the first speed tag (fixed point per frame); scroll distance left to run after the end tag.
#define STAFF_ROLL_SCROLL_Y_PER_FRAME_DEFAULT 0x70a
#define STAFF_ROLL_END_SCROLL_Y 0xd0000
// Frames of one full palette blend cycle: 0x1e frames blending from mBlendTo to mBlendFrom, 0x1e holding mBlendFrom,
// 0x1e blending back.
#define PALETTE_BLEND_CYCLE_FRAMES 0x5a

// mState and mNextState values: waiting for the start, scrolling the text, scrolled all of it.
typedef enum StaffRollTextState {
    STAFF_ROLL_TEXT_IDLE = 0,
    STAFF_ROLL_TEXT_SCROLLING = 1,
    STAFF_ROLL_TEXT_SCROLL_DONE = 2,
} StaffRollTextState;

// The staff roll text: its state, scroll position and speed, text position, char canvas and char buffer.
typedef struct StaffRollText {
    /* 000 */ s32 mState;
    /* 004 */ s32 mNextState;
    /* 008 */ s32 mScrollYFixed;
    /* 00c */ s32 mScrollYPerFrame;
    /* 010 */ s32 mNextReadScrollY;
    /* 014 */ s32 mScrollYRemaining;
    /* 018 */ u8 *mTextPosition;
    /* 01c */ s8 mCharSpacing;
    /* 01d */ u8 mUnk_01d[3];
    /* 020 */ u8 mCharCanvas[0x20];
    /* 040 */ TextCanvas mTextCanvas;
    /* 050 */ u8 mCharBuffer[0x800];
    /* 850 */ s8 mTextColor;
    /* 851 */ u8 mUnk_851[3];
    /* 854 */ s32 mAlignFlags;
    /* 858 */ void *mHeap;
} StaffRollText;

typedef struct SoundParams SoundParams;

extern u32 sIsThreadCreated;

extern CaptureParam sCapParam;

extern NNSSndSeqPlayer sSeqPlayer[16];

extern NNSSndPlayer sPlayer[32];

extern s32 sCurEffectInfo;

extern OSMessageQueue sMesgQ;

extern EffectInfo sEffectInfoBuffer[8];

extern struct NNSSndArc *sCurrent;

extern SeqQueue gSeqQueue;
