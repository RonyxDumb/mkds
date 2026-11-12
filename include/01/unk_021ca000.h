#pragma once

#include "types.h"
#include "Main/Race/mission_table_value.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/Race/data_02029930.h" // MissionFileRow

typedef struct EndingScene {
    /* 000 */ s32 mState;
    /* 004 */ s32 mNextState;
    /* 008 */ s32 mStateFrames;
    /* 00c */ s32 mKind;
    /* 010 */ void *mHeap;
    /* 014 */ s16 mNextScene;
    /* 016 */ u8 mUnk_016[0x2];
    /* 018 */ BOOL mIndex1Queued;
    /* 01c */ void *mUnk_01c;
    /* 020 */ LayoutTableEntry *mEndingThanksTable;
    /* 024 */ struct Unk02021dc8 *mThanksYouMNcer;
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

// Objects whose layout isn't known yet.
// Object behind gMissionRunLVsel.
typedef struct MissionRunLVsel {
    /* 00 */ struct Unk02021dc8 *mMissionRunLVselSNcer;
    // mr/Mission_run_LVsel_s_7.bncl when mUnk_4a >= 6, else _s_6; Bnbl and Bnll follow the same test
    // (mUnk_4a is the highest level number whose conditions hold)
    /* 04 */ LayoutEntryTable *mMissionRunLVselS7Or6Bncl;
    // same variant as mMissionRunLVselS7Or6Bncl (.bnbl)
    /* 08 */ void *mMissionRunLVselS7Or6Bnbl;
    // same variant as mMissionRunLVselS7Or6Bncl (.bnll)
    /* 0c */ struct LayoutEntryTable *mMissionRunLVselS7Or6Bnll;
    // cell records of mMissionRunLVselS7Or6Bncl and Bnll
    /* 10 */ LayoutTableEntry *mMissionRunLVselS7Or6Table;
    /* 14 */ void *mUnk_14;
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
    /* 58 */ s32 mResult; /* 1 = level chosen, 2 = Back; also read by ReleaseMissionRunLVsel for the sound */
} MissionRunLVsel;

// Object behind gMissionRunMSsel.
typedef struct MissionRunMSsel {
    /* 00 */ struct Unk02021dc8 *mMissionRunMSselMNcer;
    /* 04 */ LayoutEntryTable *mMissionRunMSselMBncl;
    /* 08 */ struct LayoutEntryTable *mMissionRunMSselMBnll;
    /* 0c */ struct Unk02021dc8 *mMissionRunMSselSNcer;
    /* 10 */ LayoutEntryTable *mMissionRunMSselSBncl;
    /* 14 */ void *mMissionRunMSselSBnbl;
    /* 18 */ struct LayoutEntryTable *mMissionRunMSselSBnll;
    /* 1c */ Nclr *mMissionRunMSselSOPalette;
    /* 20 */ u16 mBlendedPalette[0x10];
    // one 0x40-byte record per cell of the Bncl (plus Bnll) members, built by InitLayoutTable
    /* 40 */ LayoutTableEntry *mMissionRunMSselMTable;
    // one 0x40-byte record per cell of the Bncl (plus Bnll) members, built by InitLayoutTable
    /* 44 */ LayoutTableEntry *mMissionRunMSselSTable;
    /* 48 */ void *mUnk_48;
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
    // X half of reg_G2_BG0OFS (0x04000010, main engine BG0), stored negated
    /* 90 */ s32 mBg0OffsetX;
    // Y half of reg_G2_BG0OFS (0x04000010, main engine BG0), stored negated
    /* 94 */ s32 mBg0OffsetY;
    // Y half of reg_G2_BG1OFS (0x04000014, main engine BG1), stored negated; X is not written
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
    /* bc */ s32 mResult; /* 1 = mission chosen, 2 = Back; also read by ReleaseMissionRunMSsel for the sound */
} MissionRunMSsel;

// Object behind gSelectEngine.
typedef struct SelectEngine {
    /* 00 */ struct Unk02021dc8 *mSelectEngineMNcer;
    /* 04 */ struct LayoutEntryTable *mSelectEngineMBncl;
    /* 08 */ struct Unk02021dc8 *mSelectEngineSNcer;
    // gp/select_engine_B_s.bncl when IsBackupFlagSet(0x10) != 0, else gp/select_engine_A_s.bncl; the same flag hides
    // item 3 (A layout has no fourth item); the cells of item 3 are zeroed when
    // IsBackupFlagSet(0x10) is 0
    /* 0c */ struct LayoutEntryTable *mSelectEngineAOrBSBncl;
    // same variant as mSelectEngineAOrBSBncl (.bnbl)
    /* 10 */ void *mSelectEngineAOrBSBnbl;
    // one 0x40-byte record per cell of the Bncl (plus Bnll) members, built by InitLayoutTable
    /* 14 */ LayoutTableEntry *mSelectEngineMTable;
    // cell records of mSelectEngineAOrBSBncl (variant chosen by IsBackupFlagSet(0x10))
    /* 18 */ LayoutTableEntry *mSelectEngineAOrBSTable;
    /* 1c */ void *mUnk_1c;
    /* 20 */ void *mHeap;
    /* 24 */ s32 mState;
    /* 28 */ s32 mNextState;
    /* 2c */ s32 mStateFrames; /* counted only in states 1, 2, 5, 6; zeroed by the next-state setter */
    /* 30 */ s32 mBg0Offset;
    /* 34 */ s32 mIndex;
    /* 38 */ BOOL mUnk_38;
    /* 3c */ s32 mIndexChangeFramesRemaining;
    /* 40 */ s16 mLastChangeIndex;
    /* 42 */ u8 mUnk_42[0x2];
    /* 44 */ void *mMainOamList;
    /* 48 */ void *mSubOamList;
    /* 4c */ s32 mResult;
} SelectEngine;

// Object behind gEmblemCursor, allocated by CreateEmblemCursorAndGrid.
typedef struct EmblemCursor {
    /* 00 */ s32 mMode;
    /* 04 */ s32 mSizeIndex;
    /* 08 */ u8 mCellValue;
    /* 09 */ u8 mUnk_09[0x3];
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

typedef struct MissionRunBossIcon {
    /* 00 */ Ncgr *mNcgr;
    /* 04 */ struct Unk02021dc8 *mNcer;
    /* 08 */ Nclr *mNclr;
    /* 0c */ void *mBncl;
} MissionRunBossIcon;

extern u8 *gNicknameBuffers;
extern u8 *gOptionBuffers;

#include "00/Menu/wi_fi_vs_matching.h"
