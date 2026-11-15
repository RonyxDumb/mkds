#pragma once

#include "types.h"
#include "Main/System/interpolation_value.h"
#include "Main/Menu/multi_select_member_group.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Graphics/font_and_player_character.h"

// Frames a message of the member setup stays before the setup goes on, and frames after the setup started before the
// sequence zero loop is started.
#define MULTI_SELECT_MEMBER_MESSAGE_FRAMES 0x78
#define MULTI_SELECT_MEMBER_SEQ_LOOP_START_FRAMES 0x96

unsigned int MultiSelectNSGetLabelLayoutCount(LayoutEntryTable *labelLayout);
unsigned int MultiSelectNSGetCellLayoutCount(LayoutEntryTable *cellLayout);

// 0xc-byte elements from 0xe0 of MultiSelectMember.
typedef enum MultiSelectMemberState {
    MULTI_SELECT_MEMBER_STATE_SLIDE_IN = 0,
    MULTI_SELECT_MEMBER_STATE_WAIT_INPUT = 1,
    MULTI_SELECT_MEMBER_STATE_START_PRESSED = 2,
    MULTI_SELECT_MEMBER_STATE_WAIT_SETUP_DONE = 3,
    MULTI_SELECT_MEMBER_STATE_SLIDE_OUT = 4,
    MULTI_SELECT_MEMBER_STATE_WAIT_ERROR_MESSAGE = 5,
    MULTI_SELECT_MEMBER_STATE_DONE = 6,
    MULTI_SELECT_MEMBER_STATE_SCENE_REQUESTED = 7,
} MultiSelectMemberState;

typedef enum MultiSelectMemberSetup {
    MULTI_SELECT_MEMBER_SETUP_SETUP = 0,
    MULTI_SELECT_MEMBER_SETUP_WAIT_START = 1,
    MULTI_SELECT_MEMBER_SETUP_CONNECT = 2,
    MULTI_SELECT_MEMBER_SETUP_START_BOOT = 3,
    MULTI_SELECT_MEMBER_SETUP_RUN_COMMUNICATION = 4,
    MULTI_SELECT_MEMBER_SETUP_FINISH_BACKUP = 6,
    MULTI_SELECT_MEMBER_SETUP_END_CONNECTION_RETURN = 7,
    MULTI_SELECT_MEMBER_SETUP_END_CONNECTION_ERROR = 8,
    MULTI_SELECT_MEMBER_SETUP_DONE = 11,
} MultiSelectMemberSetup;

typedef enum MultiSelectMemberRowState {
    MULTI_SELECT_MEMBER_ROW_EMPTY = 0,
    MULTI_SELECT_MEMBER_ROW_BLINKING = 1,
    MULTI_SELECT_MEMBER_ROW_SHOWN = 2,
} MultiSelectMemberRowState;

// Steps a name blinks while its row appears.
#define MULTI_SELECT_MEMBER_BLINK_STEPS 20
// Steps state START_PRESSED waits before it checks that the setup is done.
#define MULTI_SELECT_MEMBER_START_STEPS 5

typedef struct MultiSelectMemberRow {
    /* 00 */ s32 mState;
    /* 04 */ s32 mStateFrames;
    /* 08 */ u16 mFirstCellIndex;
    /* 0a */ u16 mSecondCellIndex;
} MultiSelectMemberRow;

// 0x154 bytes.
typedef struct MultiSelectMember {
    /* 00 */ u8 mUnk_00[0x24];
    /* 24 */ CellFileSet mCellFileSets[2];
    /* 5c */ void *mMainOam;
    /* 60 */ void *mSubOam;
    /* 64 */ Bmg *mBannerMessages;
    /* 68 */ Bmg *mCommonMessages;
    /* 6c */ s32 mResult;
    /* 70 */ s32 mSetupState;
    /* 74 */ s32 mChildCount;
    /* 78 */ BOOL mStartPending;
    /* 7c */ BOOL mReturnPending;
    /* 80 */ BOOL mNameLabelDone;
    /* 84 */ s32 mIsMultiBoot;
    /* 88 */ BOOL mSkipChildCountSound;
    /* 8c */ BOOL mConnectionNamesDone;
    /* 90 */ s32 mStarted;
    /* 94 */ s32 mState;
    /* 98 */ s32 mStartPressedFrames;
    /* 9c */ s32 mTimer;
    /* a0 */ Interpolation mInterpolations[4];
    /* e0 */ MultiSelectMemberRow mRows[8];
    /* 140 */ s32 mCycleIndex;
    /* 144 */ s32 mCycleFrames;
    /* 148 */ BOOL mSeqZeroLoopStartPending;
    /* 14c */ s32 mSeqZeroLoopStartFrames;
    /* 150 */ void *mHeap;
} MultiSelectMember;

typedef struct SceneNumbers SceneNumbers;

#include "Main/Menu/select_kart_ghost_work.h"
#include "Main/System/heap_call.h"
#include "code_02022aa8.h"
#include "Main/Graphics/cell_file_set.h"
#include "tp.h"
#include "Main/Save/buddy_record_time.h"
#include "g2d_CellTransferManager.h"
#include "Main/Menu/wl_menu_scene.h"

void WriteMultiSelectMemberRegisters(void);
void ReleaseMultiSelectMember(void);
s32 AdvanceMultiSelectMemberNoKeyStart(SceneNumbers *sceneNumbers);
s32 AdvanceMultiSelectMemberKeyStart(SceneNumbers *sceneNumbers);
void DrawMultiSelectMember(void);
BOOL MultiSelectMemberIsSubSlideOutDone(void);
BOOL MultiSelectMemberIsSubSlideInDone(void);
void InitMultiSelectMemberNoKeyStart(void *parentHeap, void *mainOam, void *subOam);
void InitMultiSelectMemberKeyStart(void *parentHeap, void *mainOam, void *subOam);
void InitMultiSelectMember(void *parentHeap, void *mainOam, void *subOam);
void UpdateMultiSelectMemberNoKeySetup(void);
void UpdateMultiSelectMemberKeySetup(void);
void SetMultiSelectMemberSubCellVisible(s32 visible);
void SetMultiSelectChildCountCellsVisible(void);
void UpdateMultiSelectMemberCells(void);
void PrintMultiSelectConnectionNames(void);
void PrintMultiSelectMemberNames(void);
s32 CountMultiSelectChildren(void);
void SetupMultiSelectMemberSubTextButton(void);

extern struct WLMenuCallbacks gMemberKeyStartCallbacks;
extern struct WLMenuCallbacks gMemberNoKeyStartCallbacks;
extern struct MultiSelectMember *gMultiSelectMember;

extern const s16 gMultiSelectKeyStartLabelData[22];
