#pragma once

#include "types.h"

typedef struct WiFiStateCallbacks WiFiStateCallbacks;

extern WiFiStateCallbacks gWiFiVSSettingCallbacks;

void RegisterWiFiVSSettingCallbacks(void);
void AdvanceWiFiVSSetting(void);

#include "Main/Save/emblem_block.h"
#include "Main/MapObjects/map_object_park.h" // RandomState64
#include "Main/System/backup_net_camera_work.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Kart/karts.h"
#include "Main/Graphics/layout_entry_angle.h" // LayoutTableEntry
#include "Main/Menu/second_menu_scene.h" // StateMachine
#include "friend_data_account_fields.h" // DWCAccFriendData

enum {
    WIFI_VS_SETTING_STATE_WAIT_FADE_IN,
    WIFI_VS_SETTING_STATE_WAIT_CONNECTION_LOST_TEXT,
    WIFI_VS_SETTING_STATE_SLIDE_IN,
    WIFI_VS_SETTING_STATE_SLIDE_IN_RETURN_BUTTON,
    WIFI_VS_SETTING_STATE_WAIT_INPUT,
    WIFI_VS_SETTING_STATE_PRESS_BUTTON,
    WIFI_VS_SETTING_STATE_SLIDE_OUT,
    WIFI_VS_SETTING_STATE_WAIT_NO_BUDDY_LIST_TEXT,
    WIFI_VS_SETTING_STATE_WAIT_NO_BUDDY_SETTING_TEXT,
    WIFI_VS_SETTING_STATE_WAIT_DISCONNECT_ANSWER,
    WIFI_VS_SETTING_STATE_WAIT_DISCONNECT_TEXT,
    WIFI_VS_SETTING_STATE_WAIT_DISCONNECTED_TEXT,
};

// Values of WiFiVSSetting.mRow: the button that opens the buddy list, the setting selector, and the button that starts
// matching.
enum {
    WIFI_VS_SETTING_ROW_BUDDY_LIST,
    WIFI_VS_SETTING_ROW_SETTING,
    WIFI_VS_SETTING_ROW_MATCHING,
};

// WiFiVSSetting.mSettingIndex runs from 0, the setting that needs buddy records, to LAST and wraps; when the kept kart
// type maps to that setting and there are no buddy records, the selector starts at INDEX_REGION.
#define WIFI_VS_SETTING_INDEX_FRIENDS 0
#define WIFI_VS_SETTING_INDEX_REGION 2
#define WIFI_VS_SETTING_INDEX_LAST 3

// Frames the two cell rows take to slide in or out (x offset between 0 and OFFSET_HIDDEN, negated for the second
// row), the frames the matching row's y offset waits before it follows the return button's slide table, the frame
// that follow ends, the press state's length and the frame its highlight shows again, the index timer start, and the
// calls the disconnect text must pass.
#define WIFI_VS_SETTING_SLIDE_FRAMES 10
#define WIFI_VS_SETTING_OFFSET_HIDDEN 0x100
#define WIFI_VS_SETTING_RETURN_DELAY_FRAMES 3
#define WIFI_VS_SETTING_RETURN_SLIDE_END_FRAMES 13
#define WIFI_VS_SETTING_PRESS_FRAMES 10
#define WIFI_VS_SETTING_PRESS_HIGHLIGHT_FRAMES 5
#define WIFI_VS_SETTING_INDEX_TIMER_FRAMES 6
#define WIFI_VS_SETTING_DISCONNECT_WAIT_FRAMES 90

// Allocated by InitWiFiVSSetting and held in gWiFiVSSetting.
typedef struct WiFiVSSetting {
    /* 0000 */ s32 mState;
    /* 0004 */ s32 mNextState;
    // Highlighted row of the 3 rows (0 and 2 are buttons, 1 the setting selector); up/down wrap, touch sets it.
    /* 0008 */ s32 mRow;
    /* 000c */ s32 mSettingIndex;
    /* 0010 */ s32 mStateFrames;
    /* 0014 */ s16 mRowOffsets[3][2];
    /* 0020 */ s32 mPendingWiFiState;
    /* 0024 */ BOOL mHighlightVisible;
    /* 0028 */ BOOL mSelectReturnPending;
    // Count down from WIFI_VS_SETTING_INDEX_TIMER_FRAMES only while mRow is WIFI_VS_SETTING_ROW_SETTING; a left press
    // or touch sets the decrement one, a right press or touch the increment one. Nothing fires at 0: they only set an
    // arrow cell's visible flag and x offset.
    /* 002c */ s32 mIndexDecrementTimer;
    /* 0030 */ s32 mIndexIncrementTimer;
    /* 0034 */ BOOL mConnectionReleased;
    /* 0038 */ u8 mNscrCopy[0x1000];
    /* 1038 */ void *mHeap;
    // One entry per mWiFiVSSettingCellLayout entry, then one per mWiFiVSSettingLabelLayout label; InitLayoutTable
    // allocates it.
    /* 103c */ LayoutTableEntry *mWiFiVSSettingTable;
    /* 1040 */ NNSG2dCellDataBank *mWiFiVSSettingSCells;
    /* 1044 */ Ncgr *mWiFiVSSettingSChars;
    /* 1048 */ Nclr *mWiFiVSSettingSOPalette;
    /* 104c */ LayoutEntryTable *mWiFiVSSettingCellLayout;
    /* 1050 */ LayoutEntryTable *mWiFiVSSettingRects;
    /* 1054 */ struct LayoutEntryTable *mWiFiVSSettingLabelLayout;
    /* 1058 */ struct Bmg *mWiFiMessages;
    /* 105c */ struct Bmg *mCommonMessages;
} WiFiVSSetting;

enum {
    WIFI_VS_MATCHING_STATE_SLIDE_IN,
    WIFI_VS_MATCHING_STATE_WAIT_MATCHING,
    WIFI_VS_MATCHING_STATE_EMBLEM_SHRINK,
    WIFI_VS_MATCHING_STATE_WAIT_PLAYER_LIST_TEXT,
    WIFI_VS_MATCHING_STATE_SCALE_IN_OTHER,
    WIFI_VS_MATCHING_STATE_PAUSE_BETWEEN_OTHERS,
    WIFI_VS_MATCHING_STATE_WAIT_RESULT_SHOWN = 8,
    WIFI_VS_MATCHING_STATE_WAIT_NO_OPPONENTS_BACK,
    WIFI_VS_MATCHING_STATE_SLIDE_OUT,
    WIFI_VS_MATCHING_STATE_WAIT_FADE_OUT,
};

// Frame counts of the matching screen. The slide states count to SLIDE_FRAMES (the slide in adds 2 per call) while
// the table x offset moves between 0 and OFFSET_HIDDEN; a -1 match result is taken only after FAILED_RESULT_MIN_FRAMES;
// BLINK_CYCLE_FRAMES is where the blink counter wraps (the blink repeats 1, 2 or 4 times per cycle with 1, 2 or 3
// other players found), BLEND_CYCLE_FRAMES one round of the palette blend. A scale-in scales the totals over
// TOTAL_SCALE_FRAMES (the length of the scale percent table) and the emblem over EMBLEM_SCALE_FRAMES, which ends it.
#define WIFI_VS_MATCHING_SLIDE_FRAMES 10
#define WIFI_VS_MATCHING_OFFSET_HIDDEN 0x100
#define WIFI_VS_MATCHING_FAILED_RESULT_MIN_FRAMES 0x78
#define WIFI_VS_MATCHING_BLINK_CYCLE_FRAMES 0x50
#define WIFI_VS_MATCHING_BLEND_CYCLE_FRAMES 0x3c
#define WIFI_VS_MATCHING_EMBLEM_SHRINK_FRAMES 0x14
#define WIFI_VS_MATCHING_PAUSE_BEFORE_OTHERS_FRAMES 0x28
#define WIFI_VS_MATCHING_PAUSE_FRAMES 0x50
#define WIFI_VS_MATCHING_TOTAL_SCALE_FRAMES 0x1e
#define WIFI_VS_MATCHING_EMBLEM_SCALE_FRAMES 0x28

// The Wi-Fi VS matching screen: its state, the other players found (indices, emblems), palette blend, heap and layouts.
typedef struct WiFiVSMatching {
    /* 0000 */ s32 mState;
    /* 0004 */ s32 mNextState;
    /* 0008 */ s32 mStateFrames;
    /* 000c */ s32 mBlinkFrames;
    /* 0010 */ s16 mOffset;
    /* 0012 */ s16 mUnk_12[3];
    /* 0018 */ s16 mNameSlideOffsets[4];
    /* 0020 */ s32 mPendingWiFiState;
    /* 0024 */ s32 mOtherFound[3];
    // WiFiSession.mKartCount - 1: participants other than the own index.
    /* 0030 */ s32 mOtherCount;
    // Session indices of those participants; they index WiFiSession.mPlayerRecords through the getters.
    /* 0034 */ u8 mOtherIndices[3];
    /* 0038 */ s32 mShownEntryCount;
    /* 003c */ BOOL mCheckTimeLimit;
    /* 0040 */ BOOL mNoOpponents;
    /* 0044 */ s32 mCurrentOtherIndex;
    /* 0048 */ s32 mBlendFrames;
    /* 004c */ u16 mBlendedColors[5];
    /* 0058 */ s32 mFromChannels[5][3];
    /* 0094 */ s32 mToChannels[5][3];
    /* 00d0 */ void *mHeap;
    /* 00d4 */ u8 mNscrCopy[0x1000];
    // Table of cells built from the Bncl / Bnll by InitLayoutTable.
    /* 10d4 */ LayoutTableEntry *mWiFiVSMatchingTable;
    /* 10d8 */ u8 mOtherEmblems[3][0x200];
    /* 16d8 */ s32 mOtherHasEmblem[3];
    /* 16e4 */ struct NNSG2dCellDataBank *mWiFiVSMatchingSCells;
    /* 16e8 */ Ncgr *mWiFiVSMatchingSChars;
    /* 16ec */ Nclr *mWiFiVSMatchingSOPalette;
    /* 16f0 */ LayoutEntryTable *mWiFiVSMatchingCellLayout;
    /* 16f4 */ void *mWiFiVSMatchingRects;
    /* 16f8 */ struct LayoutEntryTable *mWiFiVSMatchingLabelLayout;
    /* 16fc */ struct Bmg *mWiFiMessages;
    /* 1700 */ void *mCommonMessages;
    /* 1704 */ u8 pad_1704[8];
} WiFiVSMatching;

// One entry's character, kart and player kind.
typedef struct EntryCharacterKartKind {
    /* 00 */ s32 mCharacterIndex;
    /* 04 */ s32 mKartIndex;
    /* 08 */ s32 mPlayerKind;
} EntryCharacterKartKind;

// Values of MenuShared.mWiFiMenuStartKind: the WiFi menu state the scene starts in after a race or a result (the top
// menu, the VS setting, the character select or the VS course select).
#define WIFI_MENU_START_TOP_MENU 0
#define WIFI_MENU_START_VS_SETTING 1
#define WIFI_MENU_START_SELECT_CHARACTER 2
#define WIFI_MENU_START_VS_COURSE_SELECT 3

// State the menu screens pass to each other: entry kind, WiFi menu start kinds, picked characters and karts, cup,
// course times and rankings; allocated by CreateMenuShared and held in gMenuShared.

typedef struct MenuShared {
    /* 000 */ s32 mTitleBlendDone;
    /* 004 */ s32 mRaceSetupRequested;
    /* 008 */ s32 mMenuEntryKind;
    /* 00c */ s32 mGhostSceneInitialCallbacksIndex;
    /* 010 */ s32 mUnfilledNotEliminated;
    /* 014 */ s32 mLVselIndex6Requested;
    /* 018 */ BOOL mOptionReturnsToEmbremSelect;
    /* 01c */ s32 mWiFiMenuStartKind;
    /* 020 */ EntryCharacterKartKind mEntries[4];
    /* 050 */ s32 mWiFiScene8StartKind;
    /* 054 */ u8 mWiFiVSSettingKartType;
    /* 055 */ u8 mUnk_55[0x3];
    /* 058 */ BOOL mWiFiTopMenuRequested;
    /* 05c */ s32 mUnk_5c[4];
    /* 06c */ BOOL mOtherKartCountAdded;
    /* 070 */ s32 mStaffRollEndedEarly;
    /* 074 */ s32 mWLMenuKind;
    /* 078 */ BOOL mResultArchiveDl;
    /* 07c */ s32 mCupRankIndex;
    /* 080 */ s32 mGrade;
    /* 084 */ s32 mCupIndex;
    /* 088 */ s32 mEngineIndex;
    /* 08c */ s32 mMirrorMode;
    /* 090 */ s32 mCharacterIndex;
    /* 094 */ s32 mKartIndex;
    /* 098 */ MinuteSecondMillisecondTime mCourseTimes[4];
    /* 0a8 */ u16 mTotalPoints;
    /* 0aa */ u8 mUnk_aa[0x2];
    /* 0ac */ s32 mCupRankCharacterIndices[8];
    /* 0cc */ s32 mCupRankKartIndices[8];
    /* 0ec */ s32 mOrderIndices[4];
    /* 0fc */ u8 mUnk_fc[0x10];
    /* 10c */ volatile s32 mShuffledIndices[8];
    /* 12c */ s32 mIndicesShuffled;
} MenuShared;

// Values of WiFiSession.mStateMachine.mState: the seven (enter, update) pairs of gWiFiSessionStateTable.
typedef enum WiFiSessionState {
    WIFI_SESSION_STATE_OFF = 0,
    WIFI_SESSION_STATE_LOGIN = 1,
    WIFI_SESSION_STATE_IDLE = 2, // logged in; no search, exchange or race running
    // connecting to other players: by the registered kart keys, or to friends for WIFI_MATCH_TYPE_BUDDIES
    WIFI_SESSION_STATE_SEARCH = 3,
    WIFI_SESSION_STATE_EXCHANGE = 4, // message exchange, one WiFiSessionStep at a time
    WIFI_SESSION_STATE_RACE = 5, // Wi-Fi race in progress: the race sync runs; set by the race scene
    WIFI_SESSION_STATE_UNUSED = 6, // never requested
} WiFiSessionState;

// Values of WiFiSession.mStep: the steps of the exchange; the EXCHANGE_ steps are named after the message kind they
// send.
typedef enum WiFiSessionStep {
    WIFI_SESSION_STEP_EXCHANGE_RECORDS = 0,
    WIFI_SESSION_STEP_EXCHANGE_RECORDS_SENT = 1, // sums the seeds into mRandom and starts the emblem copy
    WIFI_SESSION_STEP_WAIT_BACKUP = 2, // waits until the backup is idle
    WIFI_SESSION_STEP_EXCHANGE_CONTINUE_CHOICES = 3,
    // when only the own kart is left it closes the connections and returns the session to IDLE
    WIFI_SESSION_STEP_CONFIRM_CONTINUE = 4,
    WIFI_SESSION_STEP_EXCHANGE_PICKS = 5, // character and kart picks
    WIFI_SESSION_STEP_EXCHANGE_PICK_MASKS = 6,
    WIFI_SESSION_STEP_EXCHANGE_COURSE_PICKS = 7,
    WIFI_SESSION_STEP_EXCHANGE_COURSE_MASKS = 8, // then tallies the course
    WIFI_SESSION_STEP_VERIFY_RESULT = 9,
    WIFI_SESSION_STEP_VERIFY_DONE = 10,
    WIFI_SESSION_STEP_LEAVING = 11, // connections are being closed
    WIFI_SESSION_STEP_ENDED = 12,
} WiFiSessionStep;

// Values of the mKind member of WiFiSessionMessage, WiFiSessionMessageHeader and WiFiPlayerRecord;
// IsWiFiSessionMessageKindAllowed accepts each kind only in a range of steps. Kinds from
// WIFI_SESSION_MESSAGE_KIND_COUNT up are rejected.
typedef enum WiFiSessionMessageKind {
    WIFI_SESSION_MESSAGE_RECORD_REQUEST = 0,
    WIFI_SESSION_MESSAGE_RECORD = 1,
    WIFI_SESSION_MESSAGE_RECORDS_SENT = 2,
    WIFI_SESSION_MESSAGE_PICKS = 3,
    WIFI_SESSION_MESSAGE_PICK_MASK = 4,
    WIFI_SESSION_MESSAGE_COURSE_PICK = 5,
    WIFI_SESSION_MESSAGE_COURSE_MASK = 6,
    WIFI_SESSION_MESSAGE_RESULT = 7,
    WIFI_SESSION_MESSAGE_CONTINUE_CHOICE = 8,
    WIFI_SESSION_MESSAGE_CONTINUE_CONFIRM = 9,
    WIFI_SESSION_MESSAGE_KIND_COUNT = 10,
} WiFiSessionMessageKind;

// Values of WiFiSessionMessage.mContinueChoice.
#define WIFI_CONTINUE_CHOICE_NONE 0
#define WIFI_CONTINUE_CHOICE_CONTINUE 1
#define WIFI_CONTINUE_CHOICE_QUIT 2

// Results of GetWiFiSessionContinueResult.
#define WIFI_CONTINUE_RESULT_NOT_SETTLED 0
#define WIFI_CONTINUE_RESULT_KARTS_REMAINING 1 // more than one kart is left
#define WIFI_CONTINUE_RESULT_ENDED 2 // one kart left or the run ended

// Indices of WiFiSession.mKeys, named after the key strings registered for the matching.
#define WIFI_MATCH_KEY_REGION 0
#define WIFI_MATCH_KEY_TYPE 1
#define WIFI_MATCH_KEY_FILTER 2
#define WIFI_MATCH_KEY_ELO 3

// Values of the kart type key (mKeys[WIFI_MATCH_KEY_TYPE].mValue and the first argument of RequestWiFiSessionMatching).
#define WIFI_MATCH_TYPE_BUDDIES 0
#define WIFI_MATCH_TYPE_ELO 1
#define WIFI_MATCH_TYPE_REGION 3
#define WIFI_MATCH_TYPE_REGION_ELO 4
// Defaults DWC_GetMatchIntValue returns for a key a candidate has no value for (it also returns them while matching is
// stopped or in error).
#define WIFI_MATCH_TYPE_MISSING 5
#define WIFI_MATCH_REGION_MISSING 3
#define WIFI_MATCH_ELO_MISSING (-1)
// Elo window of the candidates: the elo evaluators score a candidate only when its elo differs from the own elo by less
// than this many points; the filter bounds own elo -/+ this are clamped to 0..WIFI_ELO_MAX.
#define WIFI_ELO_WINDOW 1000
#define WIFI_ELO_MAX 10000
// Base scores the candidate evaluators return; the elo evaluators subtract the elo difference, but ComputeRegionEloEval
// also returns 1 or 2 times WIFI_MATCH_SCORE_HIGH, and ComputeRegionEval returns a flag.
#define WIFI_MATCH_SCORE_HIGH 2000
#define WIFI_MATCH_SCORE_LOW 1000
// Time limit in milliseconds of the minimum-complete option: 1 (no wait) or one minute.
#define WIFI_MATCH_NO_WAIT 1
#define WIFI_MATCH_WAIT_LIMIT 60000

// Values of WiFiSession.mStartStatus, set by RegisterKartKeysAndStart and KartKeysStartCallback.
typedef enum WiFiStartStatus {
    WIFI_START_STATUS_PENDING = 1,
    WIFI_START_STATUS_CANCELED = 2, // the callback result was 0 with its flag set
    WIFI_START_STATUS_CONNECTED = 3,
    WIFI_START_STATUS_FAILED = 4,
} WiFiStartStatus;

// Values of WiFiSession.mDisconnectKind and the results of CheckWiFiSessionDisconnect.
typedef enum WiFiDisconnectKind {
    WIFI_DISCONNECT_NONE = 0,
    WIFI_DISCONNECT_NO_INPUT = 1, // no pad input for 30 seconds while the own kart has not ended
    WIFI_DISCONNECT_OPPONENT_LEFT = 2,
    WIFI_DISCONNECT_ERROR = 3, // result only
} WiFiDisconnectKind;

// Values of WiFiSession.mErrorKind (what DWC_GetLastError returned) that the session code tells apart; 0xb is also
// treated as an error but has no name.
#define WIFI_ERROR_KIND_UNAVAILABLE 3
#define WIFI_ERROR_KIND_TEMPORARILY_UNAVAILABLE 4
#define WIFI_ERROR_KIND_NETWORK 6
#define WIFI_ERROR_KIND_TOO_FEW_BUDDIES 7

// Values of the mode argument of SetupWiFiSession.
typedef enum WiFiSessionSetup {
    // clears the step fields and the message arrays, sets the picks to none, registers the receive buffers and starts
    // at the first step
    WIFI_SESSION_SETUP_FIRST = 0,
    WIFI_SESSION_SETUP_PACK = 1, // packs the indices and counts the karts
    // clears the course picks, repacks the indices and restarts at the course pick step
    WIFI_SESSION_SETUP_COURSE_PICKS = 2,
    WIFI_SESSION_SETUP_CONTINUE_CHOICES = 3, // resets the picks and restarts at the continue choices
} WiFiSessionSetup;

// Smallest number of entries a match needs to complete.
#define WIFI_MATCH_MIN_ENTRIES 2

// Number of kart slots of the session (the size of the per-index tables).
#define WIFI_SESSION_KART_SLOTS 4
// mReceivedMask with every bit set: a message of a later step's kind arrived, so the step counts as received from every
// index.
#define WIFI_SESSION_ALL_RECEIVED 0xff
// Calls PickNextToIndex answers with "no index" at the start of the session and after each pick.
#define WIFI_SESSION_CALLS_AFTER_PICK 2
// Frames without a received message from a kart, counted from the step after WIFI_SESSION_STEP_WAIT_BACKUP up to before
// WIFI_SESSION_STEP_VERIFY_RESULT, after which the kart is marked in mKartRemoveMask and then removed from the session.
#define WIFI_SESSION_KART_TIMEOUT_FRAMES 300
// Entries of WiFiSession.mBuddies and mBuddyStatuses.
#define WIFI_BUDDY_COUNT 0x3c

// Values of WiFiSessionLogin.mStep; FAILED and DONE are the end states. LOGIN_FAILED shuts down first.
enum {
    WIFI_LOGIN_STEP_WAIT_INET = 1,
    WIFI_LOGIN_STEP_WAIT_LOGIN = 2,
    WIFI_LOGIN_STEP_WAIT_BACKUP = 3,
    WIFI_LOGIN_STEP_WAIT_BUDDY_UPDATE = 4,
    WIFI_LOGIN_STEP_DONE = 5,
    WIFI_LOGIN_STEP_LOGIN_FAILED = 6,
    WIFI_LOGIN_STEP_FAILED = 7,
};

// The login part of a Wi-Fi session: the object DWC_InitInet sets up, then mStep, the login step.
typedef struct WiFiSessionLogin {
    /* 00 */ u8 mUnk_00[0xc];
    /* 0c */ s32 mStep;
} WiFiSessionLogin;

// A message between the players of a Wi-Fi session: kind, size, sender, receiver, picked characters, karts and courses.
typedef struct WiFiSessionMessage {
    /* 00 */ s32 mKind;
    /* 04 */ s32 mSize;
    /* 08 */ u8 mFromIndex;
    /* 09 */ u8 mToIndex;
    /* 0a */ u8 mKartMask;
    /* 0b */ u8 mUnk_0b;
    /* 0c */ s32 mCharacterIndices[WIFI_SESSION_KART_SLOTS];
    /* 1c */ s32 mKartIndices[WIFI_SESSION_KART_SLOTS];
    /* 2c */ s32 mTalliedCourseId;
    /* 30 */ s32 mCharacterIndex;
    /* 34 */ s32 mKartIndex;
    /* 38 */ s32 mPickedCourseId;
    /* 3c */ u8 mUnk_3c[0x4];
    /* 40 */ s32 mContinueChoice;
} WiFiSessionMessage;

// A player's record as sent over the net: the message header, the PlayerRecord, the two totals and the seed.
typedef struct WiFiPlayerRecord {
    /* 000 */ s32 mKind;
    /* 004 */ s32 mSize;
    /* 008 */ u8 mFromIndex;
    /* 009 */ u8 mToIndex;
    // The sender's mKartMask; written, not read through this struct.
    /* 00a */ u8 mKartMask;
    /* 00b */ u8 mUnk_00b;
    /* 00c */ PlayerRecord mPlayer;
    /* 238 */ s32 mFirstTotal;
    /* 23c */ s32 mSecondTotal;
    /* 240 */ s32 mSeed;
} WiFiPlayerRecord;

// The minimum-complete match option: a valid flag, the minimum entry count and the time limit.
typedef struct DWCMatchOptMinComplete {
    /* 00 */ u8 mValid;
    /* 01 */ u8 mMinEntry;
    /* 02 */ u8 mUnk_02[2];
    /* 04 */ s32 mTimeLimit;
} DWCMatchOptMinComplete;

// A kart key: a value, a name and an id.
typedef struct KartKey {
    /* 00 */ s32 mValue;
    /* 04 */ char mName[0x10];
    /* 14 */ u8 mId;
} KartKey;

// The Wi-Fi session: its state machine, per-player records, saved buddy list, picks and the karts taking part.
typedef struct WiFiSession {
    /* 0000 */ void *mHeap;
    /* 0004 */ void *mHeapBuffer;
    /* 0008 */ StateMachine mStateMachine;
    /* 001c */ u8 mRecvBuffers[WIFI_SESSION_KART_SLOTS][0x80];
    // One record per index: the message header, the PlayerRecord, the two totals and the seed. The own element is sent
    // (kind RECORD), the others are received into.
    /* 021c */ WiFiPlayerRecord mPlayerRecords[WIFI_SESSION_KART_SLOTS];
    /* 0b2c */ u8 mConnection[0xdb4];
    /* 18e0 */ DWCMatchOptMinComplete mMinCompleteOption;
    /* 18e8 */ s32 mStartStatus;
    /* 18ec */ KartKey mKeys[4];
    /* 194c */ u8 mNumEntry;
    /* 194d */ u8 mStatus4BuddyCount;
    /* 194e */ u8 mEarlyStepTimedOut;
    /* 194f */ u8 mUnk_194f;
    /* 1950 */ s32 mStep;
    /* 1954 */ RandomState64 mRandom;
    /* 196c */ u8 mUnk_196c[0x14];
    // Calls of UpdateWiFiSessionStepTimeout in the current step (none in READY and ENDED); zeroed by every step change
    // except changes to LEAVING that are not timeouts, and by the timeout.
    /* 1980 */ s32 mStepFrames;
    // Per index: zeroed by the receive callback for that index (not for an index outside mKartMask once the step is
    // EXCHANGE_PICKS or later), counted up in every call of UpdateWiFiSessionStep for every other index in mKartMask;
    // above WIFI_SESSION_KART_TIMEOUT_FRAMES it sets the index's bit in mKartRemoveMask, only after WAIT_BACKUP and
    // before VERIFY_RESULT and, in EXCHANGE_CONTINUE_CHOICES, only once the own continue choice is CONTINUE.
    /* 1984 */ s32 mSinceCallbackFrames[WIFI_SESSION_KART_SLOTS];
    /* 1994 */ u8 mUnk_1994[0x5];
    /* 1999 */ u8 mPickStartIndex;
    /* 199a */ u8 mUnk_199a[0x10];
    // Bit i: index i asked for our record (kind 0 message); the send step sends the record and clears the bit.
    /* 19aa */ u8 mSendRecordMask;
    // Bit i: index i's message for the current step (or the next step) has arrived; a PICKS message in EXCHANGE_SEEDS
    // or CONFIRM_CONTINUE and a COURSE_PICK message in EXCHANGE_PICK_MASKS set every bit; zeroed when a step handler
    // moves on to the next step, except WAIT_BACKUP to EXCHANGE_PICKS; changes to LEAVING and LEAVING to ENDED leave it
    // as is.
    /* 19ab */ u8 mReceivedMask;
    /* 19ac */ u8 mCallsSincePick;
    /* 19ad */ u8 mConnectionLost;
    /* 19ae */ u8 mUnk_19ae[2];
    /* 19b0 */ DWCAccUserData mUserData;
    // 0x3c saved buddy entries (12 bytes each), loaded from the save at login and written back; while the session state
    // is not OFF their GP status is polled, one entry per frame.
    /* 19f0 */ DWCAccFriendData mBuddies[WIFI_BUDDY_COUNT];
    // One status byte per mBuddies entry, set by UpdateBuddyStatuses and by SetBuddyStatus; UpdateBuddyStatuses counts
    // the entries equal to FRIEND_STATUS_MATCH_FRIEND into mStatus4BuddyCount.
    /* 1cc0 */ u8 mBuddyStatuses[WIFI_BUDDY_COUNT];
    /* 1cfc */ BOOL mBuddiesChanged;
    // Per index: the buffer the net layer receives the messages after the player record into; the receive callback
    // posts it for that index when the record arrives and copies each message into mIndexMessages; SetupWiFiSession
    // posts it again for two of its modes. mPlayerRecords (the first messages) and mRecvBuffers are also posted as
    // receive buffers.
    /* 1d00 */ WiFiSessionMessage mReceiveBuffers[WIFI_SESSION_KART_SLOTS];
    /* 1e10 */ WiFiSessionMessage mIndexMessages[WIFI_SESSION_KART_SLOTS];
    /* 1f20 */ WiFiSessionLogin mLogin;
    /* 1f30 */ BOOL mHeapCreated;
    // TRUE after ResetWiFiSessionToOff, FALSE after ResetWiFiSession; never read.
    /* 1f34 */ BOOL mUnk_1f34;
    /* 1f38 */ BOOL mRaceSyncEnabled;
    /* 1f3c */ s32 mIrqCallbackCount;
    /* 1f40 */ s32 mDisconnectKind;
    /* 1f44 */ s32 mErrorKind;
    /* 1f48 */ s32 mErrorCode;
    /* 1f4c */ u8 mUnk_1f4c;
    /* 1f4d */ u8 mUnk_1f4d;
    // Per index: its place among the indices set in mKartMask (-1 if absent); ResetWiFiSession zeroes it to 0.
    /* 1f4e */ s8 mPackedIndices[WIFI_SESSION_KART_SLOTS];
    /* 1f52 */ u8 mKartCount;
    /* 1f53 */ u8 mStartKartCount;
    /* 1f54 */ u8 mKartCountCopy;
    /* 1f55 */ u8 mKartMask;
    /* 1f56 */ u8 mKartRemoveMask;
    // Next mBuddies entry UpdateBuddyStatuses polls (wraps at WIFI_BUDDY_COUNT).
    /* 1f57 */ u8 mBuddyPollIndex;
} WiFiSession;

void InitWiFiVSSetting(void *heap);
void RegisterWiFiVSMatchingCallbacks(void);
void AdvanceWiFiVSMatching(void);

#include "Main/Graphics/nibble_tiles.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "Main/Net/player_record.h"
#include "Main/Net/wifi_session.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Graphics/text_draw.h"
#include "Main/Menu/txt_system.h"
#include "Main/Menu/select_return.h"
#include "Main/Graphics/palette_blend.h"

#include "Main/Menu/player_entry_list.h"
#include "Main/Menu/message_screen.h"
#include "sound_archive_load_result.h"
#include "Main/Scene/display_settings.h"

#include "00/Scene/wi_fi_menu_scene.h"
#include "00/Lib/wifi_library_globals.h"
#include "00/Menu/wi_fi_state_machine.h"
#include "00/Lib/DWC/friends_match_session.h"
#include "Main/System/result_archive_path.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "cpu_copy_clear_16.h"
#include "sound_player_control.h"
#include "vram_transfer_queue.h"

void WriteWiFiVSSettingRegisters(void);
void AdvanceWiFiVSSettingIndexTimers(void);
void UpdateWiFiVSSettingHighlight(void);
void UpdateWiFiVSSettingOffsets(void);
void AdvanceWiFiVSSettingWaitDisconnectedText(void);
void AdvanceWiFiVSSettingWaitDisconnectingText(void);
void AdvanceWiFiVSSettingWaitDisconnectAnswer(void);
void AdvanceWiFiVSSettingWaitNoBuddySettingText(void);
void AdvanceWiFiVSSettingWaitNoBuddyListText(void);
void AdvanceWiFiVSSettingSlideOut(void);
void AdvanceWiFiVSSettingPressButton(void);
void AdvanceWiFiVSSettingWaitInput(void);
void AdvanceWiFiVSSettingSlideInReturnButton(void);
void AdvanceWiFiVSSettingSlideIn(void);
void AdvanceWiFiVSSettingWaitConnectionLostText(void);
void AdvanceWiFiVSSettingWaitFadeIn(void);
void SetupWiFiVSSettingText(void);
void LocateAndQueueWiFiVSSetting(void);
void ReleaseWiFiVSSetting(void);
BOOL HasBuddyRecords(void);

extern const u8 gWiFiVSSettingTimerTableIndices[3][2];
extern const u8 gWiFiVSSettingLabelIndices[3];
extern const u8 gWiFiVSSettingOffsetTableIndices[3][9];
extern const s32 gWiFiVSSettingOffsetCellCounts[3];
extern const u8 gWiFiVSSettingKartTypes[4];
extern const u8 gWiFiVSSettingIndexByKartType[5];
extern const s32 gWiFiVSSettingMessageIndices[3][4];
extern WiFiVSSetting *gWiFiVSSetting;
