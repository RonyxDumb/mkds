#pragma once

#include "types.h"
#include "Main/Graphics/layout_entry_angle.h" // LayoutTableEntry, LayoutEntryTable

// Values of RecordTopMenu.mState and mNextState.
enum {
    RECORD_TOP_MENU_STATE_WAIT_FADE,
    RECORD_TOP_MENU_STATE_SLIDE_IN,
    RECORD_TOP_MENU_STATE_ROWS_SETTLE,
    RECORD_TOP_MENU_STATE_WAIT_SELECT_RETURN,
    RECORD_TOP_MENU_STATE_INPUT,
    RECORD_TOP_MENU_STATE_ROW_PRESS,
    RECORD_TOP_MENU_STATE_SLIDE_OUT,
    RECORD_TOP_MENU_STATE_ROWS_SLIDE_OUT,
    RECORD_TOP_MENU_STATE_WAIT_MESSAGE_OPEN,
    RECORD_TOP_MENU_STATE_MESSAGE_INPUT,
    RECORD_TOP_MENU_STATE_WAIT_MESSAGE_CLOSE,
    RECORD_TOP_MENU_STATE_ROWS_SLIDE_IN,
};

// Values of RecordTopMenu.mIndex: the rows in the order of gRecordTopMenuRowRecordScreens; the up key steps mIndex
// back, the down key forward.
enum {
    RECORD_TOP_ROW_GPX,
    RECORD_TOP_ROW_TIME_ATTACK,
    RECORD_TOP_ROW_VS,
    RECORD_TOP_ROW_COUNT,
};

// Frames of the slides in and out (the rows-only slides use them too); the rows travel RECORD_TOP_MENU_SLIDE_DISTANCE
// sideways, the BG0 layer and the main screen cells RECORD_TOP_MENU_BG0_SLIDE_DISTANCE vertically.
#define RECORD_TOP_MENU_SLIDE_FRAMES 10
#define RECORD_TOP_MENU_SLIDE_DISTANCE 224
#define RECORD_TOP_MENU_BG0_SLIDE_DISTANCE 192

// Frames of the press animation (GetSelectedPressOffset) of the pressed row, and of all rows after the slide in; the
// pressed row is switched on at the fifth.
#define RECORD_TOP_MENU_PRESS_FRAMES 10
#define RECORD_TOP_MENU_ROW_ON_FRAME 5

// The record top menu screen: its layout tables, messages, heap, state, selected index and chosen record screen.
typedef struct RecordTopMenu {
    /* 0x00 */ struct NNSG2dCellDataBank *mRecordTopMenuMNcer;
    /* 0x04 */ LayoutEntryTable *mRecordTopMenuMBncl;
    /* 0x08 */ struct LayoutEntryTable *mRecordTopMenuMBnll;
    /* 0x0c */ struct NNSG2dCellDataBank *mRecordTopMenuSNcer;
    /* 0x10 */ struct LayoutEntryTable *mRecordTopMenuSBncl;
    /* 0x14 */ struct LayoutEntryTable *mRecordTopMenuSBnbl;
    // one 0x40-byte record per cell of the Bncl (plus Bnll) members, built by InitLayoutTable
    /* 0x18 */ LayoutTableEntry *mRecordTopMenuMTable;
    // one 0x40-byte record per cell of the Bncl (plus Bnll) members, built by InitLayoutTable
    /* 0x1c */ LayoutTableEntry *mRecordTopMenuSTable;
    /* 0x20 */ void *mCommonMessages;
    /* 0x24 */ struct Bmg *mRecordMessages;
    /* 0x28 */ void *mSecondScreenMapBuffer;
    /* 0x2c */ void *mHeap;
    /* 0x30 */ s32 mState;
    /* 0x34 */ s32 mNextState;
    /* 0x38 */ s32 mStateFrames; /* counted only in states 1, 2, 5, 6, 7, 11 */
    /* 0x3c */ s32 mBg0Offset;
    /* 0x40 */ s32 mIndex;
    /* 0x44 */ s32 mRecordScreen;
} RecordTopMenu;

#include "01/MapObjects/mission_run_map_object_flags.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/Menu/select_return.h"
#include "Main/Scene/display_settings.h"
#include "01/Menu/menu_screen_states_and_file_names.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/System/result_archive_path.h"

void RegisterRecordTopMenuCallbacks(void);
void WriteRecordTopMenuRegisters(void);
void WriteRecordTopMenuBgOffsets(void);
void AdvanceRecordTopMenu(void);
void AdvanceRecordTopMenuRowsSlideIn(void);
void AdvanceRecordTopMenuWaitMessageClose(void);
void AdvanceRecordTopMenuMessageInput(void);
void AdvanceRecordTopMenuWaitMessageOpen(void);
void AdvanceRecordTopMenuRowsSlideOut(void);
void AdvanceRecordTopMenuSlideOut(void);
void AdvanceRecordTopMenuRowPress(void);
void AdvanceRecordTopMenuInput(void);
void AdvanceRecordTopMenuWaitSelectReturn(void);
void AdvanceRecordTopMenuRowsSettle(void);
void AdvanceRecordTopMenuSlideIn(void);
void AdvanceRecordTopMenuWaitFade(void);
void ReleaseRecordTopMenu(void);
void InitRecordTopMenu(void *heap);
void RefreshRecordTopMenuGradeCells(void);
void DecrementRecordTopMenuIndex(void);
void IncrementRecordTopMenuIndex(void);
void RequestRecordTopMenuRowsSlideIn(void);
void RequestRecordTopMenuWaitMessageClose(void);
void RequestRecordTopMenuMessageInput(void);
void RequestRecordTopMenuWaitMessageOpen(void);
void RequestRecordTopMenuRowsSlideOut(void);
void RequestRecordTopMenuSlideOut(void);
void RequestRecordTopMenuRowPress(void);
void RequestRecordTopMenuInput(void);
void RequestRecordTopMenuWaitSelectReturn(void);
void RequestRecordTopMenuRowsSettle(void);
void RequestRecordTopMenuSlideIn(void);
void ResetRecordTopMenu(void);
void SetRecordTopMenuRowOff(s32 row);
void SetRecordTopMenuRowOn(s32 row);
void LocateAndQueueRecordTopMenu(void);

#include "00/Menu/wi_fi_vs_matching.h"

extern const u16 gRecordTopMenuGradeSTableIndices[3];
extern const u16 gRecordTopMenuRowCellIndices[3];
extern const u16 gRecordTopMenuLabelWidths[3][3];
extern const s32 gRecordTopMenuTouchRowIndices[3];
extern const u16 gRecordTopMenuLabelHeights[3][3];
extern const s32 gRecordTopMenuRowRecordScreens[3];
extern const u16 gRecordTopMenuRecordMessageIndices[3];
extern const u16 gRecordTopMenuOffsetSTableIndices[3];
extern const u16 gRecordTopMenuRowSTableIndices[3];
extern const u16 gRecordTopMenuXluCellIndices[3];
extern const u16 gRecordTopMenuLabelIndices[3][3];
