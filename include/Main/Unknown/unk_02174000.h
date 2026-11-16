#pragma once

#include "types.h"
#include "Main/Unknown/unk_02029930.h" // MissionFileRow
#include "Main/Unknown/code_02025ebc.h" // Interpolation
#include "Main/Unknown/code_02036588.h" // HeapCall
#include "Main/Unknown/unk_02153000.h" // Unk021535b4
#include "Main/Unknown/code_020b4000.h" // Ncgr, Nscr, Nclr
#include "Main/Unknown/code_02124094.h" // LayoutTableEntry, Unk0201ea30
#include "Main/Unknown/code_020b3f7c.h" // Bmg
#include "Main/Unknown/code_0202f688.h"
#include "Main/Unknown/code_0205ee14.h" // KartAppear
#include "code_02022a90.h" // NNSG2dCellTransferState

// Screen kinds of the player entry list (SetupPlayerEntryList's second argument, PlayerEntryList.mScreenKind).
#define PLAYER_ENTRY_LIST_CHARACTER 0
#define PLAYER_ENTRY_LIST_KART 1
#define PLAYER_ENTRY_LIST_RACE_RULE 2

// One entry of mEntries: character, kart, team and player kind; field10 is passed on as rconf_setDriverConfigNext's sixth
// argument. 0x18-byte elements of the table at member 0 of RaceSetupCopy.
typedef struct RaceSetupCopyEntry {
    /* 00 */ s32 mCharacterIndex;
    /* 04 */ s32 mKartIndex;
    /* 08 */ s32 mPlayerKind;
    /* 0c */ s32 mTeamIndex;
    /* 10 */ s32 field10;
    // 1 where the entry's kart index is stored, 0 where the entry is cleared and on copy-in.
    /* 14 */ s32 field14;
} RaceSetupCopyEntry;

// Copy of the race setup that the screens edit: filled from the current half of gRaceMultiConfig (or from the Wi-Fi
// session), written to the next half by menu_configureRace or func_020297bc. Object behind menu_sRaceConfig, returned by
// menu_getRaceConfig.
typedef struct RaceSetupCopy {
    /* 00 */ RaceSetupCopyEntry mEntries[8];
    /* c0 */ s32 mCpuDifficulty;
    /* c4 */ s32 mKartCount;
    // A MODE_* value of unk_021759c0.h: copied from the current mode (3 for most modes in a Wi-Fi race), set by the
    // select screens, stored as the next mode by menu_configureRace.
    /* c8 */ s32 mMode;
    /* cc */ s32 mCupIndex;
    /* d0 */ s32 mCourseId;
    /* d4 */ s32 mEngineIndex;
    /* d8 */ s32 mMirrorMode;
    /* dc */ s32 mUseTeams;
    /* e0 */ s32 fieldE0;
    /* e4 */ s32 mBattleKind;
    /* e8 */ u16 mCourseCount;
    /* ea */ u8 fieldEA[2];
    /* ec */ s32 mRuleKind;
    /* f0 */ s32 mCourseListMode;
    /* f4 */ u8 *mMissionFile;
    /* f8 */ MissionFileRow *mMissionFileRows;
    /* fc */ s8 mMissionTableRow;
    /* fd */ s8 mMissionTableColumn;
    /* fe */ u8 fieldFE[6];
    // Set by SetMissionFileRowIndex from the mission table cell value minus 1: a 0-based position in mMissionFileRows.
    /* 104 */ u16 mMissionFileRowIndex;
    /* 106 */ u8 field106[2];
    /* 108 */ s32 field108;
    /* 10c */ u8 mEntryIndex;
    /* 10d */ u8 mSessionKartCount;
} RaceSetupCopy;

extern RaceSetupCopy *menu_sRaceConfig;

// 0x118-byte object that gSelectKart points to.
typedef struct SelectKart {
    /* 000 */ u8 field0[0x24];
    // The 0x24-byte record of mutil2_initBgGraphics starts here and runs into field40.
    /* 024 */ Unk02174e50_24 mSelectKartSBParts;
    /* 040 */ u8 field40[8];
    /* 048 */ Unk02174e50_24 mSelectCharacterGpMParts;
    /* 064 */ Unk02174e50_24 mSelectKartSParts;
    /* 080 */ void *field80;
    /* 084 */ void *field84;
    /* 088 */ struct Bmg *mKartSelectMessages;
    /* 08c */ void *mHeap;
    /* 090 */ s32 mStateFrames; /* counts only in states 3, 4 and 6 */
    /* 094 */ s32 mState;
    /* 098 */ KartAppear *field98;
    // Position of the kart in the table gKartIndexTable that the player steps through; mKartIndex is the kart at that
    // position, -1 when the kart is not in the table.
    /* 09c */ s32 mKartTableIndex;
    // Index of the entry (element of the array behind menu_sRaceConfig) whose character and kart this screen edits.
    /* 0a0 */ s32 mEntryIndex;
    /* 0a4 */ s32 mCharacterIndex;
    /* 0a8 */ s32 mKartIndex;
    /* ac */ Interpolation mInterpolations[5];
    /* 0fc */ s32 mMode;
    /* 100 */ s32 mResult;
    /* 104 */ BOOL field104;
    /* 108 */ BOOL mTouchHeld;
    /* 10c */ s32 mTouchHeldFrames;
    /* 110 */ s32 mTouchRect;
    /* 114 */ u16 field114;
    /* 116 */ u8 field116[2];
} SelectKart;

extern SelectKart *gSelectKart;

// Four words at 0x04 of PlayerEntryRow.
typedef struct EntrySlotMove {
    /* 00 */ s32 mMoveFrames;
    /* 04 */ s32 mTargetSlot;
    /* 08 */ s32 mFromSlot;
    /* 0c */ s32 mToSlot;
} EntrySlotMove;

// 0x2c-byte entries from 0x4c of PlayerEntryList.
typedef struct PlayerEntryRow {
    /* 00 */ s32 mTeamIndex;
    /* 04 */ EntrySlotMove mSlotMove;
    /* 14 */ u16 mName[0xc];
} PlayerEntryRow;

extern HeapCall sMainProcess;

// 0x1c-byte part of SelectCharacter, at 0x00, 0x1c and 0x38; menucs_init has two on the stack, one filled by
// mutil2_loadPortraits. ResultsBattle has four from 0x48.
typedef struct CellFileSet {
    /* 00 */ struct Unk0212463c_c *mChars;
    /* 04 */ struct Unk0212463c_d *mPalette;
    /* 08 */ struct Unk02021dc8 *mCells;
    /* 0c */ Unk0201ea30 *mCellLayout;
    /* 10 */ struct Unk0201ea30 *mRects;
    /* 14 */ Unk0201ea30 *mLabelLayout;
    /* 18 */ LayoutTableEntry *mCellTable;
} CellFileSet;

// Object behind gPlayerEntryList.
// Object behind sMenuCsState.
typedef struct SelectCharacter {
    /* 000 */ CellFileSet field0;
    /* 01c */ CellFileSet field1C;
    /* 038 */ CellFileSet field38;
    /* 054 */ void *mMainOam;
    /* 058 */ void *field58;
    /* 05c */ void *mHeap;
    /* 060 */ s32 field60;
    /* 064 */ s32 field64;
    /* 068 */ s32 field68;
    /* 06c */ s32 field6C;
    /* 070 */ s32 field70;
    /* 074 */ u16 field74;
    /* 076 */ u8 field76[2];
    /* 078 */ s32 mEntryIndex;
    /* 07c */ s32 field7C;
    /* 080 */ s32 field80;
    // Row to move to on up, down, right and left; 0xffff means stay on the row.
    /* 84 */ s16 mTableIndexByKey[4];
    /* 08c */ s32 field8C;
    /* 090 */ Unk021535b4 field90[12];
    /* 0f0 */ s32 mCharacterIndex;
    /* 0f4 */ s32 mKartIndex;
    /* f8 */ Interpolation mInterpolations[3];
    /* 128 */ BOOL field128;
} SelectCharacter;

extern SelectCharacter *sMenuCsState;

// Object behind gPlayerEntryList, 0x258 bytes (InitPlayerEntryList allocates it).
typedef struct PlayerEntryList {
    /* 000 */ CellFileSet mParts;
    /* 01c */ CellFileSet mTitleParts;
    /* 038 */ void *mMainOam;
    /* 03c */ void *mHeap;
    /* 040 */ s32 mTimer;
    /* 044 */ s32 mEntryIndex;
    /* 048 */ s32 mPlayerCount;
    /* 04c */ PlayerEntryRow mEntries[8];
    /* 1ac */ s32 field1AC[4];
    /* 1bc */ s32 field1BC[8];
    /* 1dc */ s32 field1DC[8];
    /* 1fc */ BOOL mSetupRequested;
    /* 200 */ s32 mTimerEnabled;
    /* 204 */ s32 mUseTeams;
    /* 208 */ s32 field208;
    /* 20c */ BOOL field20C;
    /* 210 */ Interpolation mInterpolations[4];
    /* 250 */ s32 mMode;
    /* 254 */ s32 mScreenKind; // PLAYER_ENTRY_LIST_CHARACTER / _KART / _RACE_RULE
} PlayerEntryList;

extern PlayerEntryList *gPlayerEntryList;

// 0x24-byte part of ResultsBattle, at 0x00 and 0x24, filled by mutil2_loadUnpackBgGraphics.
typedef struct ScreenMapFileSet {
    /* 00 */ Ncgr *mChars[4];
    /* 10 */ Nclr *mPalette;
    /* 14 */ Nscr *mScreenMaps[4];
} ScreenMapFileSet;

// 0xc-byte entries from 0xe4 of ResultsBattle.
typedef struct ResultsBattleEntry {
    /* 00 */ s32 mRank;
    /* 04 */ s32 mScore;
    /* 08 */ s32 mOrderIndex;
} ResultsBattleEntry;

// 0x154 bytes.
typedef struct ResultsBattle {
    /* 000 */ ScreenMapFileSet mScreenMapFileSets[2];
    /* 048 */ CellFileSet mCellFileSets[4];
    /* 0b8 */ s32 fieldB8[2];
    /* 0c0 */ Nclr *fieldC0;
    /* 0c4 */ Nclr *fieldC4;
    /* 0c8 */ struct Bmg *mCommonMessages;
    /* 0cc */ u16 mTimerDigitCellBase;
    /* 0ce */ u16 mTimerTensCell;
    /* 0d0 */ s32 mOwnEntryIndex;
    /* 0d4 */ s32 fieldD4;
    /* 0d8 */ s32 mKartCount;
    /* 0dc */ s32 mFileSetKind;
    /* 0e0 */ s32 mMode;
    /* 0e4 */ ResultsBattleEntry mEntries[8];
    /* 144 */ s32 mState0To2Frames;
    /* 148 */ BOOL mUseTimer;
    /* 14c */ s32 mTimer;
    /* 150 */ s32 mState;
} ResultsBattle;

extern ResultsBattle *bres_sState;

// 0x28-byte part of the entries from 0x9c of Unk02174e64; func_02034370 fills one on the stack through
// TryGetScanGhostInfo and AreGhostRecordInfosDifferent compares two.
typedef struct GhostRecordInfo {
    /* 00 */ u16 mName[11];
    /* 16 */ u8 field16[2];
    /* 18 */ s32 field18[3];
    /* 24 */ u16 mMillisecond;
    /* 26 */ u8 mMinute;
    /* 27 */ u8 mSecond;
} GhostRecordInfo;

// 0x3c-byte entries from 0x9c of Unk02174e64.
typedef struct GhostInfoEntry {
    /* 00 */ GhostRecordInfo mInfo;
    /* 28 */ BOOL mFilled;
    /* 2c */ Interpolation mInterpolation;
} GhostInfoEntry;

// Object behind sGhostReceiveState.
typedef struct Unk02174e64 {
    /* 000 */ u8 field0[0x24];
    /* 024 */ void *field24[2];
    /* 02c */ CellFileSet mCellFileSets[2];
    /* 064 */ u8 field64[0x1c];
    /* 080 */ s32 mSelectedIndex;
    /* 084 */ Bmg *mCommonMessages;
    /* 088 */ Bmg *mGhostMessages;
    /* 08c */ s32 mGhostSlot;
    /* 090 */ s32 mStateFrames;
    /* 094 */ s32 mState;
    /* 098 */ s32 mNextCallbacksIndex;
    /* 09c */ GhostInfoEntry mGhostInfoEntries[4];
    /* 18c */ BOOL field18C;
    /* 190 */ s32 mFilledCount;
    /* 194 */ Interpolation field194;
    /* 1a4 */ void *mHeap;
} Unk02174e64;

extern Unk02174e64 *sGhostReceiveState;

// Objects whose layout isn't known yet.
extern struct ResultScene *result_sState;
extern struct WiFiVSCourseSelect *gWiFiVSCourseSelect;
// 0x20 bytes, then the word at 0x44 the code addresses 0xc past.
typedef struct Unk02174e40_24 {
    /* 00 */ u8 field0[0x20];
    /* 20 */ u8 *field20;
} Unk02174e40_24;

// 0xe0 bytes.
typedef struct TimeAttackGhostSend {
    /* 000 */ u8 field0[0x24];
    /* 024 */ Unk02174e40_24 field24;
    /* 048 */ void *mOamLists[2];
    /* 050 */ CellFileSet field50[3];
    /* 0a4 */ s32 mSelectedIndex;
    /* 0a8 */ Bmg *mCommonMessages;
    /* 0ac */ Bmg *mGhostMessages;
    /* 0b0 */ s32 mState;
    /* 0b4 */ s32 fieldB4;
    /* 0b8 */ u8 fieldB8[0x14];
    /* 0cc */ Interpolation mInterpolation;
    /* 0dc */ void *mHeap;
} TimeAttackGhostSend;

extern TimeAttackGhostSend *sGhostSendState;

struct GhostScene;

// Init, advance and release of one part of the ghost scene, and a fourth function the scene's second per-frame slot
// calls.
typedef struct GhostSceneCallbacks {
    /* 00 */ void (*mInit)(void *a, struct GhostScene *b, void *c);
    /* 04 */ s32 (*mAdvance)(u32 a);
    /* 08 */ void (*mRelease)(void);
    /* 0c */ void (*fieldC)(void);
} GhostSceneCallbacks;

// Object behind sGhostSceneState, 0x8dc bytes.
typedef struct GhostScene {
    /* 000 */ u8 mMainOam[0x404];
    /* 404 */ u8 mSubOam[0x404];
    /* 808 */ s32 mGhostCount;
    // Counts of the filled course ghosts and filled slot ghosts; a ghost's list position counts the course ghosts
    // first.
    /* 80c */ s32 mCourseGhostCount;
    /* 810 */ s32 mSlotGhostCount;
    // Cup positions (0..0x1f) of the filled course ghosts, in list order.
    /* 814 */ s32 mCupCourseIndices[0x20];
    // Slot numbers (0..9) of the filled slot ghosts, in list order.
    /* 894 */ s32 mSlotIndices[10];
    // 0x30 bytes per cup position.
    /* 8bc */ u8 *mCourseGhostRecords;
    // 0x230 bytes per slot.
    /* 8c0 */ u8 *mSlotGhostRecords;
    /* 8c4 */ GhostSceneCallbacks *mCurrentCallbacks;
    /* 8c8 */ s32 mRequestedCallbacksIndex;
    /* 8cc */ s32 mCurrentCallbacksIndex;
    /* 8d0 */ void *mCourseGhostBuffer;
    /* 8d4 */ void *mSlotGhostBuffer;
    /* 8d8 */ void *mHeap;
} GhostScene;

extern GhostScene *sGhostSceneState;
typedef struct ScrollList {
    /* 000 */ s32 mGroupCount;
    /* 004 */ u16 *mGroupFirstEntries;
    /* 008 */ LayoutTableEntry *mEntries;
    /* 00c */ struct Unk0201ea30 *mRects;
    /* 010 */ s32 mUpRectIndex;
    /* 014 */ s32 mDownRectIndex;
    /* 018 */ s32 mFirstRowRectIndex;
    /* 01c */ s32 mTouchRectIndex;
    /* 020 */ s32 mPressedRectIndex;
    /* 024 */ s32 mPickedVisibleRow;
    /* 028 */ void (*mCallback)(int a, int b, int c, int d);
    /* 02c */ u16 mCursorEntry;
    /* 02e */ u16 field2E;
    /* 030 */ s32 field30;
    /* 034 */ s32 mRowCount;
    // Counts down: 10 calls for a pick, mScrollFrameCount calls for a scroll.
    /* 038 */ s32 mTimer;
    /* 03c */ s32 mHiddenTopSlot;
    /* 040 */ s32 mSelectedRow;
    /* 044 */ s32 mSelectedVisibleRow;
    // Frames one scroll step lasts (5 after more than 2 moves in one hold, else 15); also how many held frames start
    // the next move.
    /* 048 */ s32 mScrollFrameCount;
    /* 04c */ s32 mHeldMoveCount;
    // Calls of the step function with the up key or the up rect touched, back to 0 at each move; mDownHeldFrames is the
    // same for the down key and rect.
    /* 050 */ s32 mUpHeldFrames;
    /* 054 */ s32 mDownHeldFrames;
    /* 058 */ u16 mScreenMap[0x300];
    /* 658 */ s32 mRightColumnHighBits;
    /* 65c */ s32 mRightColumnHighBitsTimer;
    /* 660 */ s32 mEnabled;
    /* 664 */ s32 mPickFinished;
    /* 668 */ s32 mPickStarted;
    /* 66c */ BOOL mTouchHeld;
    /* 670 */ s32 mState;
} ScrollList;

extern ScrollList *gScrollList;
extern struct WLMenuScene *gWLMenuScene;
extern struct MultiSelectMemberGroup *gMultiSelectMemberGroup;
extern struct MultiSelectNS *gMultiSelectNS;
struct MultiSelectMember;
extern struct MultiSelectMember *gMultiSelectMember;
// Object behind data_02174e68, 0xa8 bytes.
typedef struct Unk02174e68 {
    /* 00 */ u8 field0[0x20];
    /* 20 */ u8 *field20;
    /* 24 */ void *field24[2];
    /* 2c */ CellFileSet mCellFileSets[2];
    /* 64 */ u8 field64[0x1c];
    /* 80 */ s32 mSelectedIndex;
    /* 84 */ Bmg *mCommonMessages;
    /* 88 */ Bmg *mGhostMessages;
    /* 8c */ s32 mState;
    /* 90 */ Interpolation field90;
    /* a0 */ BOOL fieldA0;
    /* a4 */ void *mHeap;
} Unk02174e68;

extern Unk02174e68 *data_02174e68;
struct WLMenuMessage;
extern struct WLMenuMessage *gWLMenuMessage;
extern HeapCall *sCurProcess;

// Object at gMainHeap: fieldC is the pointer getMainHeapHandle returns; field10 overlaps the first member of
// sMainProcess.
typedef struct Unk02174e78 {
    /* 00 */ u32 field0;
    /* 04 */ u32 mArm9TextStart;
    /* 08 */ void *mArenaLo;
    /* 0c */ void *mHeap;
    /* 10 */ const char *field10;
} Unk02174e78;

extern Unk02174e78 gMainHeap;
extern u8 sDwcWork[];

extern NNSG2dCellTransferState *data_02174e04; // first word of the cell transfer state manager
extern s32 data_02174e08;
extern s32 data_02174e0c;
extern s32 data_02174e10;
