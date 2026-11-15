#pragma once

#include "types.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/Menu/record_vs.h" // RecordScreenCallbacks

// Values of OptionTopMenu.mState and mNextState.
enum {
    OPTION_TOP_STATE_WAIT_FADE,
    OPTION_TOP_STATE_SLIDE_IN,
    OPTION_TOP_STATE_WAIT_SELECT_RETURN,
    OPTION_TOP_STATE_INPUT,
    OPTION_TOP_STATE_PRESS,
    OPTION_TOP_STATE_SLIDE_OUT,
    OPTION_TOP_STATE_ASK_RESET,
    OPTION_TOP_STATE_ASK_RESET_AGAIN,
    OPTION_TOP_STATE_WAIT_RESET_WRITE,
    OPTION_TOP_STATE_RESET_DONE,
};

// Values of OptionTopMenu.mIndex: the rows, top to bottom.
enum {
    OPTION_TOP_ROW_SETTINGS,
    OPTION_TOP_ROW_EDIT,
    OPTION_TOP_ROW_ERASE_DATA,
};

// Object behind gOptionTopMenu.
typedef struct OptionTopMenu {
    /* 00 */ s32 mState;
    /* 04 */ s32 mNextState;
    /* Init leaves it unset when the previous option state is not 1, 2 or 4 (1, 4 -> 0, 2 -> 1) */
    /* 08 */ s32 mIndex;
    /* counted only in states 1, 4, 5; zeroed when 1 and 4 hand over and 5 hands over to 6; state 5 keeps counting
       while it requests the next option state */
    /* 0c */ s32 mStateFrames;
    /* option state passed to RequestOptionState (1, 2 or 4); no initial store, set by the input handler (state 3,
       also state 9), not set for entry 2 (dialog path); also tested inside the screen */
    /* 10 */ s32 mNextOptionState;
    /* 14 */ BOOL mHighlightVisible;
    /* stored to reg_G2_BG0OFS without negation (the other mBg0Offset members are stored negated) */
    /* 18 */ s32 mBg0Offset;
    /* 1c */ void *mHeap;
    // one 0x40-byte record per cell of the Bncl member, built by InitLayoutTable
    /* 20 */ LayoutTableEntry *mOptionTopMenuSTable;
    /* 24 */ struct NNSG2dCellDataBank *mOptionTopMenuSNcer;
    /* 28 */ Ncgr *mOptionTopMenuSNcgr;
    /* 2c */ Nclr *mOptionTopMenuSONclr;
    /* 30 */ struct LayoutEntryTable *mOptionTopMenuSBncl;
    /* 34 */ void *mOptionTopMenuSBnbl;
    /* 38 */ struct Bmg *mOptionMessages;
    /* 3c */ struct Bmg *mCommonMessages;
} OptionTopMenu;

// Values of RecordGpx.mIndex and the cup arguments of the record screen helpers: the cups in the order of their
// names in common.bmg (entries 0x25 to 0x2c, gRecordGpxCupMessageIndices).
enum {
    RECORD_GPX_CUP_MUSHROOM,
    RECORD_GPX_CUP_FLOWER,
    RECORD_GPX_CUP_STAR,
    RECORD_GPX_CUP_SPECIAL,
    RECORD_GPX_CUP_SHELL,
    RECORD_GPX_CUP_BANANA,
    RECORD_GPX_CUP_LEAF,
    RECORD_GPX_CUP_LIGHTNING,
};

// States of RecordGpx.mState and mNextState, in the order of the AdvanceRecordGpxStateN calls.
enum {
    RECORD_GPX_STATE_BG_SLIDE_IN,
    RECORD_GPX_STATE_CELLS_SLIDE_IN,
    RECORD_GPX_STATE_SELECT,
    RECORD_GPX_STATE_PAGE_SLIDE_OUT,
    RECORD_GPX_STATE_PAGE_SLIDE_IN,
    RECORD_GPX_STATE_CELLS_SLIDE_OUT,
    RECORD_GPX_STATE_BG_SLIDE_OUT,
};

// Values of RecordGpx.mIndexMoveDirection and RecordTAtt.mIndexMoveDirection: which way the index moves.
enum {
    RECORD_INDEX_MOVE_NEXT,
    RECORD_INDEX_MOVE_PREVIOUS,
};

// The strip of the sub screen map (offset and size in bytes) that SetupRecordGpx fills from the map when the cup backup
// flag is set and from the zeroed RecordGpx.mZeroBuffer otherwise.
#define RECORD_GPX_MAP_STRIP_OFFSET 0x3c6
#define RECORD_GPX_MAP_STRIP_BYTES 0x134

// Frames of each slide of the screen (cells, pages and the BG0 layer); the cells travel RECORD_GPX_SLIDE_DISTANCE
// sideways, the BG0 layer RECORD_GPX_BG0_SLIDE_DISTANCE.
#define RECORD_GPX_SLIDE_FRAMES 10
#define RECORD_GPX_SLIDE_DISTANCE 256
#define RECORD_GPX_BG0_SLIDE_DISTANCE 192

// RecordGpx.mBg3OffsetY while no cup flag of the backup is set.
#define RECORD_GPX_NO_CUP_BG3_OFFSET_Y 16

// Frames the cells of a row shift after a left or right press (RecordGpx.mOffsetTimers count them down).
#define RECORD_GPX_OFFSET_TIMER_FRAMES 6

// Object behind gRecordGpx.
typedef struct RecordGpx {
    /* 00 */ Ncgr *mRecordGpxMNcgr;
    /* 04 */ struct NNSG2dCellDataBank *mRecordGpxMNcer;
    /* 08 */ LayoutEntryTable *mRecordGpxMBncl;
    /* 0c */ u8 mUnk_0c[4];
    /* 10 */ LayoutEntryTable *mRecordGpxMBnll;
    /* 14 */ Ncgr *mRecordGpxSNcgr;
    /* 18 */ struct NNSG2dCellDataBank *mRecordGpxSNcer;
    /* 1c */ LayoutEntryTable *mRecordGpxSBncl;
    /* 20 */ struct LayoutEntryTable *mRecordGpxSBnbl;
    /* 24 */ LayoutEntryTable *mRecordGpxSBnll;
    /* 28 */ Ncgr *mRecordTrophyONcgr;
    /* 2c */ struct NNSG2dCellDataBank *mRecordTrophyONcer;
    /* 30 */ Nclr *mRecordTrophySONclr;
    /* 34 */ void *mRecordTrophySOBncl;
    /* 38 */ void *mPlayerCharacterMNcgr;
    /* 3c */ struct NNSG2dCellDataBank *mPlayerCharacterMNcer;
    /* 40 */ Nclr *mPlayerCharacterMONclr;
    /* 44 */ struct LayoutEntryTable *mPlayerCharacterMBncl;
    /* 48 */ Nscr *mRecordGpxSNscr;
    /* 4c */ u8 *mZeroBuffer;
    /* 50 */ LayoutTableEntry *mRecordGpxMTable;
    /* 54 */ LayoutTableEntry *mRecordGpxSTable;
    /* 58 */ void *mCommonMessages;
    /* 5c */ void *mHeap;
    /* 60 */ s32 mState;
    /* 64 */ s32 mNextState;
    /* 68 */ s32 mStateFrames;
    // The register receives the negation of this value in its upper half-word.
    /* 6c */ s32 mBg0Offset;
    // X half of reg_G2S_DB_BG3OFS (0x0400101c): the SUB engine's BG3, stored negated; the Y half is mUnk_74 (also the y
    // of the S cells)
    /* 70 */ s32 mBg3OffsetX;
    /* 74 */ s32 mBg3OffsetY;
    /* 78 */ s32 mIndex;
    /* 7c */ s32 mIndexMoveDirection;
    // Set to 6, counted down while above 0; the row member is set to -LookupFrameOffset(6 - timer) for [0] and
    // +LookupFrameOffset(6 - timer) for [1] (stored, not added).
    /* 80 */ s32 mOffsetTimers[2];
    /* 88 */ BOOL mLeftRepeat;
    /* 8c */ BOOL mRightRepeat;
    /* 90 */ s32 mNextScreen;
} RecordGpx;

#include "01/Menu/option_states.h"
#include "01/Menu/option_top_menu.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"
#include "Main/Menu/select_return.h"
#include "player.h"

#include "cpu_copy_clear_16.h"
#include "Main/System/result_archive_path.h"

extern RecordGpx *gRecordGpx;
// Objects whose layout isn't known yet.
extern RecordScreenCallbacks gRecordGpxCallbacks;

void RegisterRecordGpxCallbacks(void);
void WriteRecordGpxRegisters(void);
void WriteRecordGpxBgOffsets(void);
void AdvanceRecordGpx(void);
void AdvanceRecordGpxBgSlideOut(void);
void AdvanceRecordGpxCellsSlideOut(void);
void AdvanceRecordGpxPageSlideIn(void);
void AdvanceRecordGpxPageSlideOut(void);
void AdvanceRecordGpxSelect(void);
void AdvanceRecordGpxCellsSlideIn(void);
void AdvanceRecordGpxBgSlideIn(void);
void ReleaseRecordGpx(void);
void InitRecordGpx(void *heap);
void RequestRecordGpxBgSlideOut(void);
void RequestRecordGpxCellsSlideOut(void);
void RequestRecordGpxPageSlideInAndMoveIndex(void);
void RequestRecordGpxPageSlideOut(void);
void RequestRecordGpxSelect(void);
void RequestRecordGpxCellsSlideInAndSetup(void);
void ResetRecordGpx(void);
u32 IsRecordGpxCupSelectable(u32 cupIndex);
u32 IsRecordGpxCupBackupFlagSet(s32 cupIndex);
void DecrementRecordGpxIndex(void);
void IncrementRecordGpxIndex(void);
void SetupRecordGpx(void);
void AdvanceRecordGpxOffsetTimers(void);
void SetupRecordGpxDashes(s32 row);
void SetupRecordGpxValues(s32 row);
void LocateAndQueueRecordGpx(void);

#include "00/Menu/wi_fi_vs_matching.h"

extern const u16 gRecordGpxRunningSTableIndices[2];
extern const u16 gRecordGpxTotalPointsLabelWidths[4];
extern const u16 gRecordGpxTotalPointsLabelIndices[4];
extern const u16 gRecordGpxCharacterKartCellIndices[4][2];
extern const u16 gRecordGpxGradeLabelHeights[4];
extern const u16 gRecordGpxGradeLabelWidths[4];
extern const u16 gRecordGpxTrophyNclrPaletteIndices[4];
extern const u16 gRecordGpxTotalPointsLabelHeights[4];
extern const u16 gRecordGpxTimeLabelWidths[4];
extern const u16 gRecordGpxTimeLabelHeights[4];
extern const u16 gRecordGpxGradeLabelIndices[4];
extern const u16 gRecordGpxLowSTableIndices[4];
extern const u16 gRecordGpxTrophyPaletteIndices[4];
extern const u16 gRecordGpxTimerZeroSTableIndices[2];
extern const u16 gRecordGpxHighSTableIndices[4];
extern const u16 gRecordGpxTimeLabelIndices[4];
extern const u16 gRecordGpxTrophyCellIndices[4];
