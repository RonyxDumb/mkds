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

// WiFiVSSetting.mSettingIndex runs from 0, the setting that needs buddy records, to LAST and wraps; without buddy
// records the selector starts at NO_BUDDY_DEFAULT.
#define WIFI_VS_SETTING_INDEX_BUDDIES 0
#define WIFI_VS_SETTING_INDEX_NO_BUDDY_DEFAULT 2
#define WIFI_VS_SETTING_INDEX_LAST 3

// Frames the cell rows take to slide in or out (x offset between 0 and OFFSET_HIDDEN), the return button's delay and
// the frame its slide ends, the press state lasts and where its highlight shows again, the frames the arrow timers
// count down from, and the frames the disconnect text waits at least.
#define WIFI_VS_SETTING_SLIDE_FRAMES 10
#define WIFI_VS_SETTING_OFFSET_HIDDEN 0x100
#define WIFI_VS_SETTING_RETURN_DELAY_FRAMES 3
#define WIFI_VS_SETTING_RETURN_SLIDE_END_FRAMES 13
#define WIFI_VS_SETTING_PRESS_FRAMES 10
#define WIFI_VS_SETTING_PRESS_HIGHLIGHT_FRAMES 5
#define WIFI_VS_SETTING_INDEX_TIMER_FRAMES 6
#define WIFI_VS_SETTING_DISCONNECT_MIN_FRAMES 90

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
    // Count down from 6 only while mUnk_08 == 1; a press sets them to 6. Nothing fires at 0: the cell flag and offset
    // they drive stop there.
    /* 002c */ s32 mIndexDecrementTimer;
    /* 0030 */ s32 mIndexIncrementTimer;
    /* 0034 */ BOOL mConnectionReleased;
    /* 0038 */ u8 mNscrCopy[0x1000];
    /* 1038 */ void *mHeap;
    // Table of cells built from the Bncl / Bnll by InitLayoutTable.
    /* 103c */ LayoutTableEntry *mWiFiVSSettingTable;
    /* 1040 */ NNSG2dCellDataBank *mWiFiVSSettingSNcer;
    /* 1044 */ Ncgr *mWiFiVSSettingSNcgr;
    /* 1048 */ Nclr *mWiFiVSSettingSONclr;
    /* 104c */ LayoutEntryTable *mWiFiVSSettingBncl;
    /* 1050 */ LayoutEntryTable *mWiFiVSSettingBnbl;
    /* 1054 */ struct LayoutEntryTable *mWiFiVSSettingBnll;
    /* 1058 */ struct Bmg *mWiFiMessages;
    /* 105c */ struct Bmg *mCommonMessages;
} WiFiVSSetting;

enum {
    WIFI_VS_MATCHING_STATE_SLIDE_IN,
    WIFI_VS_MATCHING_STATE_WAIT_MATCHING,
    WIFI_VS_MATCHING_STATE_EMBLEM_SCALE_IN,
    WIFI_VS_MATCHING_STATE_WAIT_PLAYER_LIST_TEXT,
    WIFI_VS_MATCHING_STATE_SCALE_IN_OTHER,
    WIFI_VS_MATCHING_STATE_PAUSE_BETWEEN_OTHERS,
    WIFI_VS_MATCHING_STATE_WAIT_RESULT_SHOWN = 8,
    WIFI_VS_MATCHING_STATE_WAIT_NO_OPPONENTS_BACK,
    WIFI_VS_MATCHING_STATE_SLIDE_OUT,
    WIFI_VS_MATCHING_STATE_WAIT_FADE_OUT,
};

// Frame counts of the matching screen. The slide states last SLIDE_FRAMES, with the table x offset moving between 0
// and OFFSET_HIDDEN; waiting for a match result gives up after RESULT_WAIT_FRAMES; BLINK_CYCLE_FRAMES is one blink
// round of the found-opponent cells (shared by the opponents seen), BLEND_CYCLE_FRAMES one round of the palette blend.
// An opponent's scale-in shows the totals for TOTAL_SCALE_FRAMES frames (the length of the scale percent table) and
// the emblem for EMBLEM_SCALE_FRAMES, which ends the state.
#define WIFI_VS_MATCHING_SLIDE_FRAMES 10
#define WIFI_VS_MATCHING_OFFSET_HIDDEN 0x100
#define WIFI_VS_MATCHING_RESULT_WAIT_FRAMES 0x78
#define WIFI_VS_MATCHING_BLINK_CYCLE_FRAMES 0x50
#define WIFI_VS_MATCHING_BLEND_CYCLE_FRAMES 0x3c
#define WIFI_VS_MATCHING_EMBLEM_SCALE_IN_FRAMES 0x14
#define WIFI_VS_MATCHING_PLAYER_LIST_TEXT_FRAMES 0x28
#define WIFI_VS_MATCHING_PAUSE_FRAMES 0x50
#define WIFI_VS_MATCHING_TOTAL_SCALE_FRAMES 0x1e
#define WIFI_VS_MATCHING_EMBLEM_SCALE_FRAMES 0x28

// Object behind gWiFiVSMatching; mState selects the handler run by AdvanceWiFiVSMatching.
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
    // mKartCount - 1: participants other than the own index.
    /* 0030 */ s32 mOtherCount;
    // Session indices of those participants (u8[3]); they index mPlayerRecords through the getters.
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
    /* 16e4 */ struct NNSG2dCellDataBank *mWiFiVSMatchingSNcer;
    /* 16e8 */ Ncgr *mWiFiVSMatchingSNcgr;
    /* 16ec */ Nclr *mWiFiVSMatchingSONclr;
    /* 16f0 */ LayoutEntryTable *mWiFiVSMatchingBncl;
    /* 16f4 */ void *mWiFiVSMatchingBnbl;
    /* 16f8 */ struct LayoutEntryTable *mWiFiVSMatchingBnll;
    /* 16fc */ struct Bmg *mWiFiMessages;
    /* 1700 */ void *mCommonMessages;
    /* 1704 */ u8 pad_1704[8];
} WiFiVSMatching;

// 0xc-byte element of the array at member 0x20 of MenuShared.
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
// Values of MenuShared.mWLMenuKind: which callbacks the WL menu scene starts with (the member group, or the message
// that leads on to the race, the result or the menu).
#define WL_MENU_KIND_MEMBER_GROUP 0
#define WL_MENU_KIND_TO_RACE 1
#define WL_MENU_KIND_TO_RESULT 2
#define WL_MENU_KIND_TO_MENU 3

// Object behind gMenuShared, 0x130 bytes (CreateMenuShared allocates it).

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
    WIFI_SESSION_STATE_IDLE = 2, // logged in, nothing running
    WIFI_SESSION_STATE_SEARCH = 3, // partner search with the registered keys
    WIFI_SESSION_STATE_EXCHANGE = 4, // message exchange, one WiFiSessionStep at a time
    WIFI_SESSION_STATE_RACE = 5, // running match, set by the race
    WIFI_SESSION_STATE_UNUSED = 6, // never requested
} WiFiSessionState;

// Values of WiFiSession.mStep: the exchange steps, named after what the step's message carries.
typedef enum WiFiSessionStep {
    WIFI_SESSION_STEP_EXCHANGE_RECORDS = 0,
    WIFI_SESSION_STEP_EXCHANGE_SEEDS = 1, // sums the seeds into mRandom and starts the emblem copy
    WIFI_SESSION_STEP_WAIT_BACKUP = 2, // waits until the backup is idle
    WIFI_SESSION_STEP_EXCHANGE_CONTINUE_CHOICES = 3,
    WIFI_SESSION_STEP_CONFIRM_CONTINUE = 4, // ends the session when one kart is left
    WIFI_SESSION_STEP_EXCHANGE_PICKS = 5, // character and kart picks
    WIFI_SESSION_STEP_EXCHANGE_PICK_MASKS = 6,
    WIFI_SESSION_STEP_EXCHANGE_COURSE_PICKS = 7,
    WIFI_SESSION_STEP_EXCHANGE_COURSE_MASKS = 8, // then tallies the course
    WIFI_SESSION_STEP_VERIFY_RESULT = 9,
    WIFI_SESSION_STEP_READY = 10,
    WIFI_SESSION_STEP_LEAVING = 11, // connections are being closed
    WIFI_SESSION_STEP_ENDED = 12,
} WiFiSessionStep;

// Values of the mKind member of WiFiSessionMessage, WiFiSessionMessageHeader and WiFiPlayerRecord; each kind belongs
// to one step (IsWiFiSessionMessageKindAllowed). Kinds from WIFI_SESSION_MESSAGE_KIND_COUNT up are rejected.
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
#define WIFI_CONTINUE_RESULT_KARTS_LEFT 1 // more than one kart is left
#define WIFI_CONTINUE_RESULT_ENDED 2 // one kart left or the run ended

// Indices of WiFiSession.mKeys, named after the key strings registered for the matching.
#define WIFI_MATCH_KEY_REGION 0
#define WIFI_MATCH_KEY_TYPE 1
#define WIFI_MATCH_KEY_FILTER 2
#define WIFI_MATCH_KEY_ELO 3

// Values of the kart type key (mKeys[WIFI_MATCH_KEY_TYPE].mValue and the first argument of RequestWiFiSessionMatching).
#define WIFI_MATCH_TYPE_FRIENDS 0
#define WIFI_MATCH_TYPE_ELO 1
#define WIFI_MATCH_TYPE_REGION 3
#define WIFI_MATCH_TYPE_REGION_ELO 4
// Defaults for the keys a candidate did not register.
#define WIFI_MATCH_TYPE_MISSING 5
#define WIFI_MATCH_REGION_MISSING 3
#define WIFI_MATCH_ELO_MISSING (-1)
// Elo window of the candidates: a key must be within this many points of the own elo (clamped to 0..WIFI_ELO_MAX).
#define WIFI_ELO_WINDOW 1000
#define WIFI_ELO_MAX 10000
// Scores the candidate evaluators return (the elo difference is subtracted).
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
    WIFI_DISCONNECT_NO_INPUT = 1, // no input for 30 seconds
    WIFI_DISCONNECT_OPPONENT_LEFT = 2,
    WIFI_DISCONNECT_ERROR = 3, // result only
} WiFiDisconnectKind;

// Values of WiFiSession.mErrorKind (what DWC_GetLastError returned) that the session code tells apart.
#define WIFI_ERROR_KIND_MATCHING_CLOSED 3
#define WIFI_ERROR_KIND_HTTP_CLOSED 4
#define WIFI_ERROR_KIND_LINK_DROPPED 6
#define WIFI_ERROR_KIND_UNRECOVERABLE 7

// Values of the mode argument of SetupWiFiSession.
typedef enum WiFiSessionSetup {
    WIFI_SESSION_SETUP_FIRST = 0, // resets masks, records and picks and starts at the first step
    WIFI_SESSION_SETUP_PACK = 1, // packs the indices and counts the karts
    WIFI_SESSION_SETUP_COURSE_PICKS = 2, // resets the picks and restarts at the course picks
    WIFI_SESSION_SETUP_CONTINUE_CHOICES = 3, // resets the picks and restarts at the continue choices
} WiFiSessionSetup;

// Smallest number of entries a match needs to complete.
#define WIFI_MATCH_MIN_ENTRIES 2

// Number of kart slots of the session (the size of the per-index tables).
#define WIFI_SESSION_KART_SLOTS 4
// mReceivedMask with every bit set: a message of this kind arrived once for all indices.
#define WIFI_SESSION_ALL_RECEIVED 0xff
// Calls PickNextToIndex returns "no index" for after it picked one.
#define WIFI_SESSION_CALLS_AFTER_PICK 2
// Value of the buddy status bytes the poll counts, and the one it skips.
// Frames without a callback from a participant before its kart is removed from the session.
#define WIFI_SESSION_KART_TIMEOUT_FRAMES 300
// Entries of WiFiSession.mBuddies and mBuddyStatuses.
#define WIFI_BUDDY_COUNT 0x3c
#define WIFI_BUDDY_STATUS_NOT_COUNTED 2
#define WIFI_BUDDY_STATUS_COUNTED 4

// Values of WiFiSessionLogin.mStep; FAILED and DONE are the end states. LOGIN_FAILED shuts down first.
enum {
    WIFI_LOGIN_STEP_WAIT_INET = 1,
    WIFI_LOGIN_STEP_WAIT_LOGIN = 2,
    WIFI_LOGIN_STEP_WAIT_BACKUP = 3,
    WIFI_LOGIN_STEP_UPDATE_BUDDIES = 4,
    WIFI_LOGIN_STEP_DONE = 5,
    WIFI_LOGIN_STEP_LOGIN_FAILED = 6,
    WIFI_LOGIN_STEP_FAILED = 7,
};

// 0x10-byte object at member 0x1f20 of WiFiSession.
typedef struct WiFiSessionLogin {
    /* 00 */ u8 mUnk_00[0xc];
    /* 0c */ s32 mStep;
} WiFiSessionLogin;

// 0x44-byte elements of the tables at members 0x1d00 and 0x1e10 of WiFiSession.
typedef struct WiFiSessionMessage {
    /* 00 */ s32 mKind;
    /* 04 */ s32 mSize;
    /* 08 */ u8 mFromIndex;
    /* 09 */ u8 mToIndex;
    /* 0a */ u8 mKartMask;
    /* 0b */ u8 mUnk_0b;
    /* 0c */ s32 mCharacterIndices[4];
    /* 1c */ s32 mKartIndices[4];
    /* 2c */ s32 mTalliedCourseId;
    /* 30 */ s32 mCharacterIndex;
    /* 34 */ s32 mKartIndex;
    /* 38 */ s32 mPickedCourseId;
    /* 3c */ u8 mUnk_3c[0x4];
    /* 40 */ s32 mContinueChoice;
} WiFiSessionMessage;

// 0x244-byte elements of the table at member 0x21c of WiFiSession.
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

// 8-byte object at member 0x18e0 of WiFiSession.
typedef struct DWCMatchOptMinComplete {
    /* 00 */ u8 mValid;
    /* 01 */ u8 mMinEntry;
    /* 02 */ u8 mUnk_02[2];
    /* 04 */ s32 mTimeLimit;
} DWCMatchOptMinComplete;

// 0x18-byte elements of the table at member 0x18ec of WiFiSession.
typedef struct KartKey {
    /* 00 */ s32 mValue;
    /* 04 */ char mName[0x10];
    /* 14 */ u8 mId;
} KartKey;

// Online session object behind gWiFiSession: 0x1f58 bytes allocated once at boot (InitWiFiSession; not created when
// 0x027ffc40 is 2) and never freed. mStateMachine is its state machine, 7 states each with an (enter, update) pair in
// gWiFiSessionStateTable: 0 off, 1 login, 2 logged in and idle, 3 partner search with the registered keys, 4 message
// exchange (mStep 0..12), 5 running match (set by the race), 6 never requested. mState != 0 means a session is running;
// its own heap exists only while the WiFi scene group runs. Holds the saved buddy list, the per-index records and
// picks, and the roster (mKartMask, mKartCount) read by the matching screens and the race.
typedef struct WiFiSession {
    /* 0000 */ void *mHeap;
    /* 0004 */ void *mHeapBuffer;
    /* 0008 */ StateMachine mStateMachine;
    /* 001c */ u8 mRecvBuffers[4][0x80];
    // One 0x244-byte record per index: a 12-byte message header, then the player's name (0x14 bytes) and emblem
    // (0x200), elo, region and seed. The own element is sent (kind 1), the others are received into.
    /* 021c */ WiFiPlayerRecord mPlayerRecords[4];
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
    // Calls of the step function in the current step; zeroed by every normal step change and by the timeout
    // (changes to step 11 that are not timeouts leave it as is).
    /* 1980 */ s32 mStepFrames;
    // Per kart: zeroed by the callback for that kart, counted up each step for every other kart in mKartMask; above
    // 300 it sets the kart's bit in mKartRemoveMask (while 2 < mStep < 9).
    /* 1984 */ s32 mSinceCallbackFrames[4];
    /* 1994 */ u8 mUnk_1994[0x5];
    /* 1999 */ u8 mPickStartIndex;
    /* 199a */ u8 mUnk_199a[0x10];
    // Bit i: index i asked for our record (kind 0 message); the send step sends the record and clears the bit.
    /* 19aa */ u8 mSendRecordMask;
    // Bit i: the message of the current step has arrived from index i (kinds 3 and 5 set 0xff); zeroed at every step
    // change.
    /* 19ab */ u8 mReceivedMask;
    /* 19ac */ u8 mCallsSincePick;
    /* 19ad */ u8 mConnectionLost;
    /* 19ae */ u8 mUnk_19ae[2];
    /* 19b0 */ DWCAccUserData mUserData;
    // 0x3c saved buddy entries (12 bytes each), loaded from the save at login and written back; their GP status is
    // polled one per frame.
    /* 19f0 */ DWCAccFriendData mBuddies[WIFI_BUDDY_COUNT];
    // One status byte per mBuddies entry (poll or the buddy status callback). Meaning of the values not decoded.
    /* 1cc0 */ u8 mBuddyStatuses[WIFI_BUDDY_COUNT];
    /* 1cfc */ BOOL mBuddiesChanged;
    // 0x44-byte buffers the net layer receives the kind 0..9 messages into (re-posted by the receive callback). The
    // 0x244 profile records (mPlayerRecords) and mRecvBuffers (0x80 bytes) are also posted as receive buffers.
    /* 1d00 */ WiFiSessionMessage mReceiveBuffers[4];
    /* 1e10 */ WiFiSessionMessage mIndexMessages[4];
    /* 1f20 */ WiFiSessionLogin mLogin;
    /* 1f30 */ BOOL mHeapCreated;
    /* 1f34 */ BOOL mResetToOff;
    /* 1f38 */ BOOL mRaceSyncEnabled;
    /* 1f3c */ s32 mIrqCallbackCount;
    /* 1f40 */ s32 mDisconnectKind;
    /* 1f44 */ s32 mErrorKind;
    /* 1f48 */ s32 mErrorCode;
    /* 1f4c */ u8 mUnk_1f4c;
    /* 1f4d */ u8 mUnk_1f4d;
    // Per index: its place among the indices set in mKartMask (-1 if absent); ResetWiFiSession zeroes it to 0.
    /* 1f4e */ s8 mPackedIndices[4];
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
#include "Main/Sound/sound_seq.h"
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
void AdvanceWiFiVSSettingWaitDisconnectText(void);
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

// Objects whose layout isn't known yet.
extern const u8 gWiFiVSSettingTimerTableIndices[3][2];
extern const u8 gWiFiVSSettingLabelIndices[3];
extern const u8 gWiFiVSSettingOffsetTableIndices[3][9];
// Objects whose layout isn't known yet.
extern const s32 gWiFiVSSettingOffsetCellCounts[3];
extern const u8 gWiFiVSSettingKartTypes[4];
extern const u8 gWiFiVSSettingIndexByKartType[5];
extern const s32 gWiFiVSSettingMessageIndices[3][4];
extern WiFiVSSetting *gWiFiVSSetting;
