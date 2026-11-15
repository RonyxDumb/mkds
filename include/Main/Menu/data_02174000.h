#pragma once
#include "types.h"
#include "Main/Race/data_02029930.h" // MissionFileRow
#include "Main/System/interpolation_value.h" // Interpolation
#include "Main/System/heap_call.h" // HeapCall
#include "Main/Menu/data_02153000.h" // SelectCharacterRow
#include "code_02022aa8.h"
#include "Main/Graphics/cell_file_set.h"
#include "Main/Graphics/font_and_player_character.h" // Ncgr, Nscr, Nclr
#include "Main/Graphics/layout_entry_angle.h" // LayoutTableEntry, LayoutEntryTable
#include "Main/Graphics/locate_bmg_sections.h" // Bmg
#include "Main/Menu/multi_select_member_group.h"
#include "Main/Race/data_021759c0.h" // MinuteSecondMillisecondTime
#include "tp.h"
#include "Main/Save/buddy_record_time.h" // KartAppear
#include "g2d_CellTransferManager.h"

typedef struct GhostRecord GhostRecord;

typedef struct SlotGhostRecord SlotGhostRecord;

typedef struct GhostRecordHead GhostRecordHead;

typedef struct GhostListEntry GhostListEntry;

// Screen kinds of the player entry list (SetupPlayerEntryList's second argument, PlayerEntryList.mScreenKind).
#define PLAYER_ENTRY_LIST_CHARACTER 0

#define PLAYER_ENTRY_LIST_KART 1

#define PLAYER_ENTRY_LIST_RACE_RULE 2

// Values of PlayerEntryList.mMode (SetupPlayerEntryList's first argument): the same three sources as SelectKartMode.
typedef enum PlayerEntryListMode {
    PLAYER_ENTRY_LIST_MODE_NO_CONNECTION = 0,
    PLAYER_ENTRY_LIST_MODE_CONNECTION = 1,
    PLAYER_ENTRY_LIST_MODE_WIFI_SESSION = 2,
} PlayerEntryListMode;

// One entry of mEntries: character, kart, team and player kind; mUnk_10 is passed on as SetNextRaceEntry's sixth
// argument. 0x18-byte elements of the table at member 0 of RaceSetupCopy.
typedef struct RaceSetupCopyEntry {
    /* 00 */ s32 mCharacterIndex;
    /* 04 */ s32 mKartIndex;
    /* 08 */ s32 mPlayerKind;
    /* 0c */ s32 mTeamIndex;
    /* 10 */ s32 mListedCpuSlot;
    // 1 where the entry's kart index is stored, 0 where the entry is cleared and on copy-in.
    /* 14 */ s32 mKartStored;
} RaceSetupCopyEntry;

// Values of RaceSetupCopy.mEntryTransition: how the character or kart screen is entered. The character screen stores
// FROM_CHARACTER when it leaves forward (FRESH in battle mode, which has no kart screen) and FRESH when it leaves back;
// the kart screen stores FROM_KART when it leaves back and FRESH when it leaves forward.
#define ENTRY_TRANSITION_FRESH 0
#define ENTRY_TRANSITION_FROM_CHARACTER 1
#define ENTRY_TRANSITION_FROM_KART 2

// Copy of the race setup that the screens edit: filled from the current half of gRaceSetup (or from the Wi-Fi
// session), written to the next half by SetNextRaceSetupFromCopy or SetNextRaceSetupFromKartMask. Object behind
// gRaceSetupCopy, returned by GetRaceSetupCopy.
typedef struct RaceSetupCopy {
    /* 00 */ RaceSetupCopyEntry mEntries[8];
    /* c0 */ s32 mCpuDifficulty;
    /* c4 */ s32 mKartCount;
    // A MODE_* value of unk_021759c0.h: copied from the current mode (3 for most modes in a Wi-Fi race), set by the
    // select screens, stored as the next mode by SetNextRaceSetupFromCopy.
    /* c8 */ s32 mMode;
    /* cc */ s32 mCupIndex;
    /* d0 */ s32 mCourseId;
    /* d4 */ s32 mEngineIndex;
    /* d8 */ s32 mMirrorMode;
    /* dc */ s32 mUseTeams;
    /* e0 */ s32 mGhostRecordIndex;
    /* e4 */ s32 mBattleKind;
    /* e8 */ u16 mCourseCount;
    /* ea */ u8 mUnk_ea[2];
    /* ec */ s32 mRuleKind;
    /* f0 */ s32 mCourseListMode;
    /* f4 */ u8 *mMissionFile;
    /* f8 */ MissionFileRow *mMissionFileRows;
    /* fc */ s8 mMissionTableRow;
    /* fd */ s8 mMissionTableColumn;
    /* fe */ u8 mUnk_fe[6];
    // Set by SetMissionFileRowIndex from the mission table cell value minus 1: a 0-based position in mMissionFileRows.
    /* 104 */ u16 mMissionFileRowIndex;
    /* 106 */ u8 mUnk_106[2];
    /* 108 */ s32 mEntryTransition;
    /* 10c */ u8 mEntryIndex;
    /* 10d */ u8 mSessionKartCount;
} RaceSetupCopy;

// Value of SelectKart.mMode: the same three sources as SelectCharacterMode.
typedef enum SelectKartMode {
    SELECT_KART_MODE_NO_CONNECTION = 0,
    SELECT_KART_MODE_CONNECTION = 1,
    SELECT_KART_MODE_WIFI_SESSION = 2,
} SelectKartMode;

// Values of SelectKart.mState. SEND_KART is the multiboot child's way in; CONFIRM waits 5 frames after the kart is
// chosen, HOLD 60 frames after everyone has chosen.
typedef enum SelectKartState {
    SELECT_KART_STATE_SLIDE_IN,
    SELECT_KART_STATE_SEND_KART,
    SELECT_KART_STATE_CHOOSE,
    SELECT_KART_STATE_SLIDE_CELL,
    SELECT_KART_STATE_CONFIRM,
    SELECT_KART_STATE_WAIT_OTHERS,
    SELECT_KART_STATE_HOLD,
    SELECT_KART_STATE_SLIDE_OUT,
    SELECT_KART_STATE_DONE,
} SelectKartState;

// Steps of the cell slide in state SLIDE_CELL, steps state CONFIRM and state HOLD run; mStateFrames counts them.
#define SELECT_KART_SLIDE_CELL_STEPS 6
#define SELECT_KART_CONFIRM_STEPS 5
#define SELECT_KART_HOLD_STEPS 60
// SelectKart.mTouchRect of the confirm touch area, and SelectKart.mSlidingCellIndex while the cell slides left or
// right.
#define SELECT_KART_TOUCH_RECT_CONFIRM 2
#define SELECT_KART_SLIDING_CELL_LEFT 2
#define SELECT_KART_SLIDING_CELL_RIGHT 3

// 0x24-byte part of ResultsBattle (at 0x00 and 0x24) and of SelectKart, filled by LoadScreenMapFileSet.
typedef struct ScreenMapFileSet {
    /* 00 */ Ncgr *mChars[4];
    /* 10 */ Nclr *mPalette;
    /* 14 */ Nscr *mScreenMaps[4];
} ScreenMapFileSet;

// 0x118-byte object that gSelectKart points to.
typedef struct SelectKart {
    /* 000 */ u8 mUnk_000[0x24];
    /* 024 */ ScreenMapFileSet mSelectKartSBParts;
    /* 048 */ CellFileSet mSelectCharacterGpMParts;
    /* 064 */ CellFileSet mSelectKartSParts;
    /* 080 */ void *mMainOam;
    /* 084 */ void *mSubOam;
    /* 088 */ struct Bmg *mKartSelectMessages;
    /* 08c */ void *mHeap;
    /* 090 */ s32 mStateFrames; /* counts only in the SLIDE_CELL, CONFIRM and HOLD states */
    /* 094 */ s32 mState;
    /* 098 */ KartAppear *mKartAppear;
    // Position of the kart in the table gKartIndexTable that the player steps through; mKartIndex is the kart at that
    // position, -1 when the kart is not in the table.
    /* 09c */ s32 mKartTableIndex;
    // Index of the entry (element of the array behind gRaceSetupCopy) whose character and kart this screen edits.
    /* 0a0 */ s32 mEntryIndex;
    /* 0a4 */ s32 mCharacterIndex;
    /* 0a8 */ s32 mKartIndex;
    /* ac */ Interpolation mInterpolations[5];
    /* 0fc */ s32 mMode;
    /* 100 */ s32 mResult;
    /* 104 */ BOOL mEntryListUsed;
    /* 108 */ BOOL mTouchHeld;
    /* 10c */ s32 mTouchHeldFrames;
    /* 110 */ s32 mTouchRect;
    /* 114 */ u16 mSlidingCellIndex;
    /* 116 */ u8 mUnk_116[2];
} SelectKart;

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

// Object behind gPlayerEntryList.
typedef enum SelectCharacterState {
    SELECT_CHARACTER_STATE_WAIT_FADE = 0,
    SELECT_CHARACTER_STATE_SCALE_IN = 1,
    SELECT_CHARACTER_STATE_PICK_FIXED = 2,
    SELECT_CHARACTER_STATE_CHOOSE = 3,
    SELECT_CHARACTER_STATE_WAIT_MOVE = 4,
    SELECT_CHARACTER_STATE_WAIT_PICK = 5,
    SELECT_CHARACTER_STATE_WAIT_OTHERS = 6,
    SELECT_CHARACTER_STATE_WAIT_HOLD = 7,
    SELECT_CHARACTER_STATE_SCALE_OUT = 8,
    SELECT_CHARACTER_STATE_DONE = 9,
} SelectCharacterState;

typedef enum SelectCharacterMode {
    SELECT_CHARACTER_MODE_NO_CONNECTION = 0,
    SELECT_CHARACTER_MODE_CONNECTION = 1,
    SELECT_CHARACTER_MODE_WIFI_SESSION = 2,
} SelectCharacterMode;

// SelectCharacter.mResult once the player entry list timer has run out: the screen after this one is reached as for
// MENU_SCREEN_RESULT_NEXT.
#define SELECT_CHARACTER_RESULT_TIME_UP 3

// The byte of the data sharing to the others while no character is picked.
#define SELECT_CHARACTER_SEND_BYTE_NONE 0xff

// Steps of the scale in and scale out.
#define SELECT_CHARACTER_SCALE_STEPS 10
// Steps the moved or picked row settles for before the state moves on.
#define SELECT_CHARACTER_SETTLE_STEPS 5
// Steps the picked character is held in state WAIT_HOLD.
#define SELECT_CHARACTER_HOLD_STEPS 60

// Object behind gSelectCharacter.
typedef struct SelectCharacter {
    /* 000 */ CellFileSet mGpMParts;
    /* 01c */ CellFileSet mSParts;
    /* 038 */ CellFileSet mGpNameMParts;
    /* 054 */ void *mMainOam;
    /* 058 */ void *mSubOam;
    /* 05c */ void *mHeap;
    /* 060 */ s32 mTableIndex;
    /* 064 */ s32 mPreviousTableIndex;
    /* 068 */ s32 mStateFrames;
    /* 06c */ s32 mState;
    /* 070 */ s32 mScale;
    /* 074 */ u16 mAngle;
    /* 076 */ u8 mUnk_076[2];
    /* 078 */ s32 mEntryIndex;
    /* 07c */ s32 mTableRowCount;
    /* 080 */ s32 mMode;
    // Row to move to on up, down, right and left; 0xffff means stay on the row.
    /* 84 */ s16 mTableIndexByKey[4];
    /* 08c */ s32 mResult;
    /* 090 */ SelectCharacterRow mRows[12];
    /* 0f0 */ s32 mCharacterIndex;
    /* 0f4 */ s32 mKartIndex;
    /* f8 */ Interpolation mInterpolations[3];
    /* 128 */ BOOL mUsePlayerEntryList;
} SelectCharacter;

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
    /* 1ac */ s32 mEmptySlotSoundPlayed[4];
    /* 1bc */ s32 mCharacterShown[8];
    /* 1dc */ s32 mKartShown[8];
    /* 1fc */ BOOL mSetupRequested;
    /* 200 */ s32 mTimerEnabled;
    /* 204 */ s32 mUseTeams;
    /* 208 */ s32 mShowAllEntries;
    /* 20c */ BOOL mMoveInnerPending;
    /* 210 */ Interpolation mInterpolations[4];
    /* 250 */ s32 mMode;
    /* 254 */ s32 mScreenKind; // PLAYER_ENTRY_LIST_CHARACTER / _KART / _RACE_RULE
} PlayerEntryList;

// 0xc-byte entries from 0xe4 of ResultsBattle.
typedef struct ResultsBattleEntry {
    /* 00 */ s32 mRank;
    /* 04 */ s32 mScore;
    /* 08 */ s32 mOrderIndex;
} ResultsBattleEntry;

// Values of ResultsBattle.mState: the two data-sharing sync steps, a wait for a frame count, waiting for the confirm
// key (or the timer), waiting for the choice, waiting for the Wi-Fi continue result, ending the connection, and done
// (the next scene is set).
typedef enum {
    RESULTS_BATTLE_STATE_START_SYNC,
    RESULTS_BATTLE_STATE_FINISH_SYNC,
    RESULTS_BATTLE_STATE_WAIT_FRAMES,
    RESULTS_BATTLE_STATE_WAIT_CONFIRM,
    RESULTS_BATTLE_STATE_WAIT_CHOICE,
    RESULTS_BATTLE_STATE_WAIT_WIFI_CONTINUE,
    RESULTS_BATTLE_STATE_END_CONNECTION,
    RESULTS_BATTLE_STATE_DONE
} ResultsBattleState;

// Values of ResultsBattle.mFileSetKind: the row of gResultsBattleVictoryFileNames, named after the files it loads.
typedef enum {
    RESULTS_BATTLE_FILES_VICTORY,
    RESULTS_BATTLE_FILES_LOSE,
    RESULTS_BATTLE_FILES_DRAW,
    RESULTS_BATTLE_FILES_VS_BLUE,
    RESULTS_BATTLE_FILES_VS_RED
} ResultsBattleFiles;

// ResultsBattle.mTimer counts down from the start value in the Wi-Fi mode. The shown number steps once per
// RESULTS_BATTLE_TIMER_STEP_FRAMES frames, and the choices open by themselves once the timer is below the choice value.
#define RESULTS_BATTLE_TIMER_START_FRAMES 0x384
#define RESULTS_BATTLE_TIMER_CHOICE_FRAMES 0x12c
#define RESULTS_BATTLE_TIMER_STEP_FRAMES 0x3c

// 0x154 bytes.
typedef struct ResultsBattle {
    /* 000 */ ScreenMapFileSet mScreenMapFileSets[2];
    /* 048 */ CellFileSet mCellFileSets[4];
    /* 0b8 */ void *mOamLists[2];
    /* 0c0 */ Nclr *mCellFileSet2ShyguyPalette;
    /* 0c4 */ Nclr *mCellFileSet3ShyguyPalette;
    /* 0c8 */ struct Bmg *mCommonMessages;
    /* 0cc */ u16 mTimerDigitCellBase;
    /* 0ce */ u16 mTimerTensCell;
    /* 0d0 */ s32 mOwnEntryIndex;
    /* 0d4 */ s32 mIconKartCount;
    /* 0d8 */ s32 mKartCount;
    /* 0dc */ s32 mFileSetKind;
    /* 0e0 */ s32 mMode;
    /* 0e4 */ ResultsBattleEntry mEntries[8];
    /* 144 */ s32 mSyncAndWaitFrames;
    /* 148 */ BOOL mUseTimer;
    /* 14c */ s32 mTimer;
    /* 150 */ s32 mState;
} ResultsBattle;

// 0x28-byte part of the entries from 0x9c of TimeAttackGhostGetScan; AdvanceTimeAttackGhostGetScan fills one on the
// stack through TryGetScanGhostInfo and AreGhostRecordInfosDifferent compares two.
typedef struct GhostRecordInfo {
    /* 00 */ u16 mName[11];
    /* 16 */ u8 mUnk_16[2];
    /* 18 */ s32 mCharacterIndex;
    /* 1c */ s32 mKartIndex;
    /* 20 */ s32 mCourseId;
    /* 24 */ MinuteSecondMillisecondTime mTime;
} GhostRecordInfo;

// 0x3c-byte entries from 0x9c of TimeAttackGhostGetScan.
typedef struct GhostInfoEntry {
    /* 00 */ GhostRecordInfo mInfo;
    /* 28 */ BOOL mFilled;
    /* 2c */ Interpolation mInterpolation;
} GhostInfoEntry;

// What PrintGhostRecordInfo reads from the three ghost list parts: the two screen file sets, the character file set
// and the common messages.
typedef struct GhostInfoFileSets {
    /* 00 */ CellFileSet mCellFileSets[3];
    /* 54 */ s32 mSelectedIndex;
    /* 58 */ Bmg *mCommonMessages;
} GhostInfoFileSets;

typedef enum TimeAttackGhostGetScanState {
    TIME_ATTACK_GHOST_GET_SCAN_STATE_WAIT_FADE = 0,
    TIME_ATTACK_GHOST_GET_SCAN_STATE_SLIDE_IN = 1,
    TIME_ATTACK_GHOST_GET_SCAN_STATE_SCAN_LIST = 2,
    TIME_ATTACK_GHOST_GET_SCAN_STATE_WAIT_PICK = 3,
    TIME_ATTACK_GHOST_GET_SCAN_STATE_WAIT_PICK_ANSWER = 4,
    TIME_ATTACK_GHOST_GET_SCAN_STATE_REQUEST_BLOCK_COUNT = 5,
    TIME_ATTACK_GHOST_GET_SCAN_STATE_RECEIVE_BLOCKS = 6,
    TIME_ATTACK_GHOST_GET_SCAN_STATE_END_CONNECTION_AFTER_RECEIVE = 7,
    TIME_ATTACK_GHOST_GET_SCAN_STATE_CHECK_SLOT = 8,
    TIME_ATTACK_GHOST_GET_SCAN_STATE_WAIT_REPLACE_ANSWER = 9,
    TIME_ATTACK_GHOST_GET_SCAN_STATE_WAIT_MESSAGE_CLOSED = 10,
    TIME_ATTACK_GHOST_GET_SCAN_STATE_WAIT_BACKUP = 11,
    TIME_ATTACK_GHOST_GET_SCAN_STATE_END_CONNECTION_LEAVE = 12,
    TIME_ATTACK_GHOST_GET_SCAN_STATE_SLIDE_OUT = 13,
    TIME_ATTACK_GHOST_GET_SCAN_STATE_WAIT_MESSAGE_DONE = 14,
    TIME_ATTACK_GHOST_GET_SCAN_STATE_WAIT_ERROR_MESSAGE = 15,
    TIME_ATTACK_GHOST_GET_SCAN_STATE_DONE = 16,
} TimeAttackGhostGetScanState;

// Steps state WAIT_PICK runs after a ghost was picked.
#define TIME_ATTACK_GHOST_GET_SCAN_PICK_STEPS 5

// Ghost scene part that scans for ghosts, lists them and receives the picked one.
typedef struct TimeAttackGhostGetScan {
    /* 000 */ u8 mUnk_000[0x24];
    /* 024 */ void *mOamLists[2];
    /* 02c */ GhostInfoFileSets mInfoFileSets;
    /* 088 */ Bmg *mGhostMessages;
    /* 08c */ s32 mGhostSlot;
    /* 090 */ s32 mStateFrames;
    /* 094 */ s32 mState;
    /* 098 */ s32 mNextCallbacksIndex;
    /* 09c */ GhostInfoEntry mGhostInfoEntries[4];
    /* 18c */ BOOL mGhostPicked;
    /* 190 */ s32 mFilledCount;
    /* 194 */ Interpolation mInterpolation;
    /* 1a4 */ void *mHeap;
} TimeAttackGhostGetScan;

// Values of TimeAttackGhostSend.mState. The END_CONNECTION states wait for the connection to end before they go on.
enum {
    TIME_ATTACK_GHOST_SEND_STATE_WAIT_NO_GHOST_TEXT = 0,
    TIME_ATTACK_GHOST_SEND_STATE_WAIT_FADE = 1,
    TIME_ATTACK_GHOST_SEND_STATE_SLIDE_IN = 2,
    TIME_ATTACK_GHOST_SEND_STATE_PICK_GHOST = 3,
    TIME_ATTACK_GHOST_SEND_STATE_WAIT_GHOST_READ = 4,
    TIME_ATTACK_GHOST_SEND_STATE_SETUP_CONNECTION = 5,
    TIME_ATTACK_GHOST_SEND_STATE_WAIT_CHILD = 6,
    TIME_ATTACK_GHOST_SEND_STATE_WAIT_RESULT = 7,
    TIME_ATTACK_GHOST_SEND_STATE_WAIT_TEXT_END_CONNECTION = 8,
    TIME_ATTACK_GHOST_SEND_STATE_END_CONNECTION_LEAVE = 9,
    TIME_ATTACK_GHOST_SEND_STATE_END_CONNECTION_SHOW_NAME = 10,
    TIME_ATTACK_GHOST_SEND_STATE_END_CONNECTION_BACK_TO_LIST = 11,
    TIME_ATTACK_GHOST_SEND_STATE_WAIT_NAME_TEXT_LEAVE = 13,
    TIME_ATTACK_GHOST_SEND_STATE_LEAVE = 14,
};

// 0xe0 bytes.
typedef struct TimeAttackGhostSend {
    /* 000 */ ScreenMapFileSet mScreenMapFileSets[2];
    /* 048 */ void *mOamLists[2];
    /* 050 */ GhostInfoFileSets mInfoFileSets;
    /* 0ac */ Bmg *mGhostMessages;
    /* 0b0 */ s32 mState;
    /* 0b4 */ s32 mUnk_0b4;
    /* 0b8 */ u8 mChildName[0x14];
    /* 0cc */ Interpolation mInterpolation;
    /* 0dc */ void *mHeap;
} TimeAttackGhostSend;

struct GhostScene;

// Init, advance and release of one part of the ghost scene, and a fourth function the scene's second per-frame slot
// calls.
typedef struct GhostSceneCallbacks {
    /* 00 */ void (*mInit)(void *heap, void *ghostScene, void *subOam);
    /* 04 */ s32 (*mAdvance)();
    /* 08 */ void (*mRelease)(void);
    /* 0c */ void (*mWriteRegisters)(void);
} GhostSceneCallbacks;

// Object behind gGhostScene, 0x8dc bytes.
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
    /* 8bc */ GhostRecordHead *mCourseGhostRecords;
    // 0x230 bytes per slot.
    /* 8c0 */ GhostListEntry *mSlotGhostRecords;
    /* 8c4 */ GhostSceneCallbacks *mCurrentCallbacks;
    /* 8c8 */ s32 mRequestedCallbacksIndex;
    /* 8cc */ s32 mCurrentCallbacksIndex;
    /* 8d0 */ GhostRecord *mCourseGhostBuffer;
    /* 8d4 */ SlotGhostRecord *mSlotGhostBuffer;
    /* 8d8 */ void *mHeap;
} GhostScene;

extern GhostScene *gGhostScene;

// Values of ScrollList.mState: waiting for input, the selection moves one row, the list scrolls one row, or a row is
// picked.
enum {
    SCROLL_LIST_STATE_IDLE,
    SCROLL_LIST_STATE_SELECT_UP,
    SCROLL_LIST_STATE_SELECT_DOWN,
    SCROLL_LIST_STATE_SCROLL_UP,
    SCROLL_LIST_STATE_SCROLL_DOWN,
    SCROLL_LIST_STATE_PICK,
};

typedef struct ScrollList {
    /* 000 */ s32 mGroupCount;
    /* 004 */ u16 *mGroupFirstEntries;
    /* 008 */ LayoutTableEntry *mEntries;
    /* 00c */ struct LayoutEntryTable *mRects;
    /* 010 */ s32 mUpRectIndex;
    /* 014 */ s32 mDownRectIndex;
    /* 018 */ s32 mFirstRowRectIndex;
    /* 01c */ s32 mTouchRectIndex;
    /* 020 */ s32 mPressedRectIndex;
    /* 024 */ s32 mPickedVisibleRow;
    /* 028 */ void (*mCallback)(int action, int slot, int row, int selectedSlot);
    /* 02c */ u16 mCursorEntry;
    /* 02e */ u16 mScrollEntry;
    /* 030 */ s32 mScrollOffsetRange;
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

struct MultiSelectMember;

typedef enum TimeAttackGhostGetSlotState {
    TIME_ATTACK_GHOST_GET_SLOT_STATE_SLIDE_IN = 0,
    TIME_ATTACK_GHOST_GET_SLOT_STATE_CHOOSE_SLOT = 1,
    TIME_ATTACK_GHOST_GET_SLOT_STATE_WAIT_SAVE_ANSWER = 2,
    TIME_ATTACK_GHOST_GET_SLOT_STATE_WAIT_BACKUP = 3,
    TIME_ATTACK_GHOST_GET_SLOT_STATE_WAIT_MESSAGE_DONE = 4,
    TIME_ATTACK_GHOST_GET_SLOT_STATE_DONE = 5,
} TimeAttackGhostGetSlotState;

// Ghost scene part that lists the slot ghosts and saves the received ghost over the picked one.
typedef struct TimeAttackGhostGetSlot {
    /* 00 */ ScreenMapFileSet mScreenMapFileSet;
    /* 24 */ void *mOamLists[2];
    /* 2c */ GhostInfoFileSets mInfoFileSets;
    /* 88 */ Bmg *mGhostMessages;
    /* 8c */ s32 mState;
    /* 90 */ Interpolation mInterpolation;
    /* a0 */ BOOL mUnk_a0;
    /* a4 */ void *mHeap;
} TimeAttackGhostGetSlot;

struct WLMenuMessage;

// Object at gStartupMemory: mHeap is the pointer GetArenaHeap returns.
typedef struct StartupMemory {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mArm9TextStart;
    /* 08 */ void *mArenaLo;
    /* 0c */ void *mHeap;
    /* 10 */ HeapCall mRootHeapCall;
    /* 24 */ u32 mUnk_24;
} StartupMemory;

extern StartupMemory gStartupMemory;

extern u8 gDwcInitWork[];

// first word of the cell transfer state manager
