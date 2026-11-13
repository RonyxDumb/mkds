#pragma once

#include "types.h"
#include "Main/System/thread_function_queue.h"
#include "Main/System/result_archive_path.h"
#include "Main/Graphics/font_glyph_text.h"
#include "Main/Graphics/oam.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Menu/select_return.h"
#include "player.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "code_0212df7c.h"
#include "Main/Save/buddy_record.h"

typedef struct RecordTAtt {
    /* 00 */ Ncgr *mRecordTAttMNcgr;
    /* 04 */ struct Unk02021dc8 *mRecordTAttMNcer;
    /* 08 */ LayoutEntryTable *mRecordTAttMBncl;
    /* 0c */ u8 mUnk_0c[4];
    /* 10 */ LayoutEntryTable *mRecordTAttMBnll;
    /* 14 */ Ncgr *mRecordTAttSNcgr;
    /* 18 */ struct Unk02021dc8 *mRecordTAttSNcer;
    /* 1c */ LayoutEntryTable *mRecordTAttSBncl;
    /* 20 */ struct LayoutEntryTable *mRecordTAttSBnbl;
    /* 24 */ LayoutEntryTable *mRecordTAttSBnll;
    /* 28 */ void *mPlayerCharacterChars;
    /* 2c */ struct Unk02021dc8 *mPlayerCharacterCells;
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
    /* 6c */ u8 mUnk_6c;
} BackupAccess;

extern const u16 gRecordTAttCharacterKartCellIndices[5][2];

#include "Main/Menu/kart_icon.h"
#include "Main/Menu/record_scene.h"

#include "code_021458c4.h"

extern BackupAccess *gBackupAccess;
extern const s32 gRecordTAttCourseIds[32];
extern RecordTAtt *gRecordTAtt;

void RegisterRecordTAttCallbacks(void);
void WriteRecordTAttRegisters(void);
void WriteRecordTAttBgOffsets(void);
void AdvanceRecordTAtt(void);
void AdvanceRecordTAttState17(void);
void AdvanceRecordTAttState16(void);
void AdvanceRecordTAttState15(void);
void AdvanceRecordTAttState14(void);
void AdvanceRecordTAttState13(void);
void AdvanceRecordTAttState12(void);
void AdvanceRecordTAttState11(void);
void AdvanceRecordTAttState10(void);
void AdvanceRecordTAttState9(void);
void AdvanceRecordTAttState8(void);
void AdvanceRecordTAttState7(void);
void AdvanceRecordTAttState6(void);
void AdvanceRecordTAttState5(void);
void AdvanceRecordTAttState4(void);
void AdvanceRecordTAttState3(void);
void AdvanceRecordTAttState2(void);
void AdvanceRecordTAttState1(void);
void AdvanceRecordTAttState0(void);
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
extern const u16 gRecordTAttButtonSequence[6];
extern const u16 gRecordTAttTimeLabelHeights[5];
extern const u16 gRecordTAttTimeLabelIndices[5];
extern const u16 gRecordTAttOffsetSTableIndices[5];
extern const u16 gRecordTAttTimeLabelWidths[5];
extern const u16 gRecordTAttTimerZeroSTableIndices[2];

extern RecordScreenCallbacks gRecordTAttCallbacks;
