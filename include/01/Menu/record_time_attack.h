#pragma once

#include "types.h"
#include "Main/System/thread_function_queue.h"
#include "Main/System/result_archive_path.h"
#include "Main/Graphics/font_glyph_text.h"
#include "Main/Graphics/oam.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Menu/select_return.h"
#include "sound_player_control.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "sound_archive_load_result.h"
#include "Main/Save/buddy_record.h"

enum {
    RECORD_TATT_STATE_SLIDE_IN_TOP,
    RECORD_TATT_STATE_SLIDE_IN_RIGHT,
    RECORD_TATT_STATE_WAIT_INPUT,
    RECORD_TATT_STATE_SLIDE_OUT_SIDE,
    RECORD_TATT_STATE_SLIDE_IN_SIDE,
    RECORD_TATT_STATE_SLIDE_OUT_RIGHT,
    RECORD_TATT_STATE_SLIDE_OUT_TOP,
    RECORD_TATT_STATE_PRESS_BUTTON,
    RECORD_TATT_STATE_SLIDE_OUT_FOR_CLEAR_PROMPT,
    RECORD_TATT_STATE_WAIT_CLEAR_PROMPT_OPEN,
    RECORD_TATT_STATE_WAIT_CLEAR_ANSWER,
    RECORD_TATT_STATE_WAIT_CLEAR_PROMPT_CLOSE,
    RECORD_TATT_STATE_SLIDE_IN_AFTER_CLEAR_PROMPT,
    RECORD_TATT_STATE_SLIDE_OUT_FOR_TIME_TEXT,
    RECORD_TATT_STATE_WAIT_TIME_TEXT_OPEN,
    RECORD_TATT_STATE_WAIT_TIME_TEXT_INPUT,
    RECORD_TATT_STATE_WAIT_TIME_TEXT_CLOSE,
    RECORD_TATT_STATE_SLIDE_IN_AFTER_TIME_TEXT,
};

// Frames of each slide of the screen (cells and BG layers); the cells travel RECORD_TATT_SLIDE_DISTANCE sideways, the
// top layer RECORD_TATT_TOP_SLIDE_DISTANCE.
#define RECORD_TATT_SLIDE_FRAMES 10
#define RECORD_TATT_SLIDE_DISTANCE 256
#define RECORD_TATT_TOP_SLIDE_DISTANCE 192

// Frames of the press animation of a row (GetSelectedPressOffset).
#define RECORD_TATT_PRESS_FRAMES 10

// Frames into the slide out that hides the cells 12 and 13 of the sub layout table, and into the slide in that shows
// cell 12 again, when the clear prompt or the time text opens or closes.
#define RECORD_TATT_HIDE_CELLS_FRAME 7
#define RECORD_TATT_SHOW_CELL_FRAME 2

// Frames the cells of a row shift after a left or right press (RecordTAtt.mOffsetTimers count them down).
#define RECORD_TATT_OFFSET_TIMER_FRAMES 6

// Entries of gRecordTAttCourseIds, the courses RecordTAtt.mIndex walks through.
#define RECORD_TATT_COURSE_COUNT 32

// Length of the button sequence that gRecordTAttButtonSequence lists and mButtonSequenceIndex walks.
#define RECORD_TATT_BUTTON_SEQUENCE_LENGTH 6

// The record time attack screen: its layout tables, messages, heap, state and the button sequence progress.
typedef struct RecordTAtt {
    /* 00 */ Ncgr *mRecordTAttMNcgr;
    /* 04 */ struct NNSG2dCellDataBank *mRecordTAttMNcer;
    /* 08 */ LayoutEntryTable *mRecordTAttMBncl;
    /* 0c */ u8 mUnk_0c[4];
    /* 10 */ LayoutEntryTable *mRecordTAttMBnll;
    /* 14 */ Ncgr *mRecordTAttSNcgr;
    /* 18 */ struct NNSG2dCellDataBank *mRecordTAttSNcer;
    /* 1c */ LayoutEntryTable *mRecordTAttSBncl;
    /* 20 */ struct LayoutEntryTable *mRecordTAttSBnbl;
    /* 24 */ LayoutEntryTable *mRecordTAttSBnll;
    /* 28 */ void *mPlayerCharacterChars;
    /* 2c */ struct NNSG2dCellDataBank *mPlayerCharacterCells;
    /* 30 */ Nclr *mPlayerCharacterPalette;
    /* 34 */ struct LayoutEntryTable *mPlayerCharacterCellLayout;
    // one 0x40-byte record per cell of the Bncl (plus Bnll) members, built by InitLayoutTable
    /* 38 */ LayoutTableEntry *mRecordTAttMTable;
    // one 0x40-byte record per cell of the Bncl (plus Bnll) members, built by InitLayoutTable
    /* 3c */ LayoutTableEntry *mRecordTAttSTable;
    /* 40 */ struct Bmg *mCommonMessages;
    /* 44 */ void *mGhostMessages;
    /* 48 */ struct Bmg *mRecordMessages;
    /* 4c */ void *mHeap;
    /* 50 */ s32 mState;
    /* 54 */ s32 mNextState;
    /* 58 */ s32 mStateFrames; /* counted only in states 0, 1, 3-8, 11, 12, 13, 17 */
    /* 5c */ s32 mBg0Offset;
    // X half of reg_G2_BG1OFS (0x04000014, main engine BG1), stored negated
    /* 60 */ s32 mBg1OffsetX;
    // Y half of reg_G2_BG1OFS (0x04000014, main engine BG1), stored negated
    /* 64 */ s32 mBg1OffsetY;
    // X half of reg_G2S_DB_BG3OFS (0x0400101c): the SUB engine's BG3, stored negated; Y is not written
    /* 68 */ s32 mBg3OffsetX;
    /* 6c */ s32 mIndex;
    /* 70 */ s32 mIndexMoveDirection;
    /* 74 */ BOOL mClearChosen;
    /* 78 */ s32 mOffsetTimers[2];
    /* 80 */ s16 mButtonSequenceIndex;
    /* 82 */ u8 mUnk_82[2];
    /* 84 */ BOOL mUnk_84;
    /* 88 */ BOOL mLeftRepeat;
    /* 8c */ BOOL mRightRepeat;
    /* 90 */ s32 mNextScreen;
} RecordTAtt;

// Values of BackupAccess.mStatus. No code sets the second writing value; EndBackupAccessWithError treats it as writing.
enum {
    BACKUP_STATUS_IDLE,
    BACKUP_STATUS_WRITING,
    BACKUP_STATUS_WRITING_UNUSED,
    BACKUP_STATUS_READING,
    BACKUP_STATUS_FAILED,
};

// Values of BackupAccess.mErrorCode: a failed card command, a card that is not there (which switches the backup off),
// data that fails the xor or crc check, and a block prefix that does not match.
enum {
    BACKUP_ERROR_NONE,
    BACKUP_ERROR_ACCESS_FAILED,
    BACKUP_ERROR_UNAVAILABLE,
    BACKUP_ERROR_BAD_DATA,
    BACKUP_ERROR_BAD_PREFIX,
};

// Values of BackupAccess.mCopyPass: one copy, or the first or second of the two copies of a block.
enum { BACKUP_COPY_PASS_SINGLE, BACKUP_COPY_PASS_FIRST, BACKUP_COPY_PASS_SECOND };

// Object behind gBackupAccess.
typedef struct BackupAccess {
    /* 00 */ s32 mStatus;
    /* 04 */ s32 mErrorCode;
    /* 08 */ s32 mLockId;
    /* 0c */ s32 mBackupEnabled;
    /* 10 */ s32 mCommandRunning;
    /* 14 */ s32 mCopyPass;
    /* 18 */ u32 mSecondPassAddress;
    /* 1c */ s32 mFirstPassResult;
    /* 20 */ u32 *mFirstPassBuffer;
    /* 24 */ u16 mFirstPassTailHalfword;
    /* 26 */ u8 mUnk_26[0x2];
    /* 28 */ u32 *mReadDestination;
    /* 2c */ u32 mReadAddress;
    /* 30 */ u32 mReadSize;
    /* 34 */ u32 mExpectedFirstWord;
    /* 38 */ s32 mReadHasPrefix;
    /* 3c */ u8 mUnk_3c[0x4];
    /* 40 */ u32 *mWriteSource;
    /* 44 */ u32 mWriteAddress;
    /* 48 */ u32 mWriteSize;
    /* 4c */ u8 mUnk_4c[0x4];
    /* 50 */ s32 mWriteHasPrefix;
    /* 54 */ void (*mWriteCallback)(u32 *, u32);
    /* 58 */ s32 mUnk_58;
    /* 5c */ s32 mUnk_5c;
    /* 60 */ void *mBuffer;
    /* 64 */ void *mOneByteReadBuffer;
    /* 68 */ void *mReadTarget;
    /* 6c */ u8 mSlotGhostIndex;
} BackupAccess;

extern const u16 gRecordTAttCharacterKartCellIndices[5][2];

#include "Main/Menu/kart_icon.h"
#include "Main/Menu/record_scene.h"

#include "card_rom_backup_access.h"

extern BackupAccess *gBackupAccess;
extern const s32 gRecordTAttCourseIds[RECORD_TATT_COURSE_COUNT];
extern RecordTAtt *gRecordTAtt;

void RegisterRecordTAttCallbacks(void);
void WriteRecordTAttRegisters(void);
void WriteRecordTAttBgOffsets(void);
void AdvanceRecordTAtt(void);
void AdvanceRecordTAttSlideInAfterTimeText(void);
void AdvanceRecordTAttWaitTimeTextClose(void);
void AdvanceRecordTAttWaitTimeTextInput(void);
void AdvanceRecordTAttWaitTimeTextOpen(void);
void AdvanceRecordTAttSlideOutForTimeText(void);
void AdvanceRecordTAttSlideInAfterClearPrompt(void);
void AdvanceRecordTAttWaitClearPromptClose(void);
void AdvanceRecordTAttWaitClearAnswer(void);
void AdvanceRecordTAttWaitClearPromptOpen(void);
void AdvanceRecordTAttSlideOutForClearPrompt(void);
void AdvanceRecordTAttPressButton(void);
void AdvanceRecordTAttSlideOutTop(void);
void AdvanceRecordTAttSlideOutRight(void);
void AdvanceRecordTAttSlideInSide(void);
void AdvanceRecordTAttSlideOutSide(void);
void AdvanceRecordTAttWaitInput(void);
void AdvanceRecordTAttSlideInRight(void);
void AdvanceRecordTAttSlideInTop(void);
void ReleaseRecordTAtt(void);
void InitRecordTAtt(void *heap);
BOOL AdvanceRecordTAttButtonSequence(void);
void AdvanceRecordTAttOffsetTimers(void);

#include "00/Menu/wi_fi_vs_matching.h"
#include "Main/Menu/record_vs.h"

extern const u16 gRecordTAttRunningSTableIndices[2];
extern const u16 gRecordTAttNameLabelIndices[5];
extern const u16 gRecordTAttNameLabelWidths[5];
extern const u16 gRecordTAttNameLabelHeights[5];
extern const u16 gRecordTAttButtonSequence[RECORD_TATT_BUTTON_SEQUENCE_LENGTH];
extern const u16 gRecordTAttTimeLabelHeights[5];
extern const u16 gRecordTAttTimeLabelIndices[5];
extern const u16 gRecordTAttOffsetSTableIndices[5];
extern const u16 gRecordTAttTimeLabelWidths[5];
extern const u16 gRecordTAttTimerZeroSTableIndices[2];

extern RecordScreenCallbacks gRecordTAttCallbacks;
