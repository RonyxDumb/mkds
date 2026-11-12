#pragma once

#include "types.h"
#include "01/Race/race_hud_king_cells.h"
#include "01/code_0219b250.h"
#include "01/Menu/nickname_scene.h"
#include "01/Menu/option_select_menu.h"
#include "01/Menu/record_top_menu.h"
#include "01/Menu/select_ghost.h"
#include "01/Menu/record_gpx.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/Menu/data_02180728.h" // TextCanvas

// Four callbacks; the first receives OptionStates.mStateHeap.
typedef struct OptionStateCallbacks {
    /* 00 */ void (*mInit)(void *);
    /* 04 */ UnkFunc *mRelease;
    /* 08 */ UnkFunc *mAdvance;
    /* 0c */ UnkFunc *mPostUpdate;
} OptionStateCallbacks;

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
    /* 20 */ struct Unk02021dc8 *mOptionHensyuMenuSNcer;
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
    /* 18 */ UnkFunc *mCountUpCallback;
    /* 1c */ UnkFunc *mDropCallback;
    /* 20 */ UnkFunc *mBossTransferCallback;
    /* 24 */ UnkFunc *mTimerEndCallback;
    /* 28 */ Vec3 mKartPos;
    /* 34 */ Vec3 mPrevKartPos;
    /* 40 */ u16 mKartHeadingAngle;
    /* 42 */ u16 mPrevKartHeadingAngle;
    /* 44 */ s32 mMapObjectCount;
    /* 48 */ struct MissionRunMapObject *mMapObjects[8];
} MissionRunData;

// A square grid of mSide by mSide cells.
typedef struct EmblemGrid {
    /* 00 */ s32 mSide;
    /* 04 */ s32 mScrSide;
    /* 08 */ s32 mTableCount;
    /* 0c */ BOOL mCopied;
    /* 10 */ s32 mChanged;
    /* 14 */ s32 mSwapped;
    /* 18 */ u16 *mUnk_18;
    /* 1c */ u8 *mBuffers[5];
} EmblemGrid;

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
    /* 002c */ BOOL mUnk_2c;
    /* 0030 */ u16 mSelectBattleStageMNscrCopy[64][32];
    /* 1030 */ void *mHeap;
    /* 1034 */ LayoutTableEntry *mSelectBattleStageTables[2];
    /* 103c */ struct Unk02021dc8 *mSelectBattleStageMNcer;
    /* 1040 */ struct Unk02021dc8 *mSelectBattleStageSNcer;
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
    /* 30 */ void *mUnk_30;
    /* 34 */ LayoutTableEntry *mOptionEmbremSelectSTable;
    /* 38 */ struct Unk02021dc8 *mOptionEmbremSelectSNcer;
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
extern char gMissionRunMSselCommonBmgName[];
extern char gMissionRunMSselMissionBmgName[];
extern char gMissionRunMSselMtblName[];
extern char gMissionRunMSselMissionMrName[];
typedef struct TimeAttackTopMenu {
    /* 00 */ struct Unk02021dc8 *mTimeAttackTopMenuSNcer;
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
    /* 30 */ s32 mSubOamList;
    /* 34 */ s32 mResult;
} TimeAttackTopMenu;

extern RaceHudSubScreenCells *gRaceHudSubScreenKurikingCells;
extern const char *gMissionRunLVselGradeStrings[5];
extern const char *gMissionRunMSselGradeStrings[5];

#include "00/Menu/wi_fi_vs_matching.h"
