#pragma once

#include "03/Net/exchange_wcm_state.h"
#include "multiboot_game_entry.h"
#include "03/Graphics/text_canvas.h"
#include "03/System/application.h"
#include "03/Menu/jb5_move.h"
#include "03/Net/wh.h"
#include "types.h"
#include "03/Graphics/nce_oam.h" // OamRange
#include "03/System/pointer_stack_create.h"
#include "03/Graphics/blend_brightness_fade.h"
#include "file_command_handlers.h" // FSArchive
#include "03/Menu/slide_buttons.h"
#include "03/Graphics/message_pool.h"
#include "03/Net/child_wait_session_object.h"
#include "03/System/exp_heap.h"
#include "03/System/tasks.h"
#include "03/System/touch_key_input.h"

// The list of the fields of the access point work copy (SSID, WEP key, IP, netmask, gateway, DNS): its text canvas,
// cell objects, scroll, background offset and id timer tasks, id timers, chosen and return id and scroll bar flags.
typedef struct Jb3List {
    /* 00 */ TaskEntry *mIdTimerTask;
    /* 04 */ u8 mIdTimer[4];
    /* 08 */ u16 *mJb3ListBackNsc;
    /* 0c */ void *mYbBgStep2NclFiles[2];
    /* 14 */ BgTextCanvas *mBgTextCanvas;
    /* 18 */ OamEntry *mCellOamEntries[7];
    /* 34 */ OamEntry *mSetTypeOamEntry;
    /* 38 */ TaskEntry *mScrollTask;
    /* 3c */ TaskEntry *mBgOffsetTask;
    /* 40 */ u8 mChosenId;
    /* 41 */ u8 mScrollTimer;
    /* 42 */ u8 mReturnId;
    /* 43 */ u8 mDnsNoneCopy;
    /* 44 */ u8 mBgOffsetPending;
    /* 45 */ u8 mScrollBarDragging;
    /* 46 */ u8 mScrollBarLimitSoundPlayed;
    /* 47 */ u8 mKeyLimitSoundPlayed;
} Jb3List;

typedef struct UsbScan UsbScan;
typedef struct MultiBootParent MultiBootParent;
// A link level icon: its OAM entry, task and image row.
typedef struct LinkLevel {
    /* 00 */ OamEntry *mOamEntry;
    /* 04 */ TaskEntry *mTask;
    /* 08 */ s8 mImageRow;
} LinkLevel;

// The on-screen keys of the Edit screen. Key index of the grid key at a row and column (rows are 12 apart; the last row
// has 11 keys).
#define EDIT_KEY(row, col) ((row) * 12 + (col))
#define EDIT_KEY_MAIN_COUNT 0x2f
// Keys after the grid: four extra keys, then the two bottom keys.
enum {
    EDIT_KEY_PAGE2_TOGGLE = EDIT_KEY_MAIN_COUNT,
    EDIT_KEY_PAGE1_TOGGLE,
    EDIT_KEY_SPACE,
    EDIT_KEY_REMOVE,
    EDIT_KEY_BOTTOM_LEFT,
    EDIT_KEY_BOTTOM_RIGHT,
};
// Values of EditKeyboard.mPage, and of EditKeyboard.mInput besides the characters (NOT_READY until the keyboard slid
// in), the number of calls a held remove key waits before its first repeat (later ones wait 7 fewer), the text glyph of
// a space and the longest text.
#define EDIT_KEYBOARD_PAGE0 0
#define EDIT_KEYBOARD_PAGE1 1
#define EDIT_KEYBOARD_PAGE2 2
#define EDIT_KEYBOARD_INPUT_REMOVE_CHAR 0x80
#define EDIT_KEYBOARD_INPUT_CANCEL 0x82
#define EDIT_KEYBOARD_INPUT_OK 0x83
#define EDIT_KEYBOARD_INPUT_NOT_READY 0xff
#define EDIT_KEYBOARD_REPEAT_DELAY_CALLS 0x28
#define EDIT_TEXT_GLYPH_SPACE 0xe01d
#define EDIT_TEXT_MAX_CHARS 0x20
// Values the cursor move table holds in place of a key index.
enum {
    EDIT_KEY_UP_FROM_LAST_GRID_KEY = -1,
    EDIT_KEY_UP_FROM_BOTTOM_LEFT = -2,
    EDIT_KEY_UP_FROM_BOTTOM_RIGHT = -3,
    EDIT_KEY_DOWN_FROM_BOTTOM_LEFT = -4,
    EDIT_KEY_DOWN_FROM_BOTTOM_RIGHT = -5,
};

// The text entry keyboard: its key objects, cursor, step task, mInput, current page, the pressed, highlighted, previous
// and cursor keys, mRepeatCalls and the mRemoveCharEnabled and mAddCharEnabled flags.
typedef struct EditKeyboard {
    /* 000 */ void *mRowTexts[3][4];
    /* 030 */ OamEntry *mKeys[EDIT_KEY_MAIN_COUNT];
    /* 0ec */ OamEntry *mExtraKeys[4];
    /* 0fc */ OamRange *mRow4Keys[2];
    /* 104 */ void *mRowTextRanges[4];
    /* 114 */ OamRange *mCursor;
    /* 118 */ TaskEntry *mStepTask;
    /* 11c */ u8 mInput;
    /* 11d */ u8 mPage;
    /* 11e */ s8 mPressedKeyIndex;
    /* 11f */ s8 mHighlightedKeyIndex;
    /* 120 */ s8 mPreviousKeyIndex;
    /* 121 */ s8 mCursorKeyIndex;
    /* 122 */ u8 mRepeatCalls;
    /* 123 */ u8 mRemoveCharEnabled;
    /* 124 */ u8 mAddCharEnabled;
    /* 125 */ u8 mRemoveDisabledSoundPlayed;
} EditKeyboard;

extern EditKeyboard *gEditKeyboard;
struct EditAddrKeyboard;
struct ValueRecordsRequest;
extern u8 gLanguageIndex[];
extern u8 gQuitFlag[];
extern void *gHeapMemoryBlock;
struct ApList;
struct Edit;
struct EditAddr;
struct Ap;
struct Bg2ScrBuffer;
struct ScrollBar;
struct ApScan;
extern struct ApScan *gApScan;
struct ApStore;
struct SoundData;
struct MenuPairObjects;
extern UsbScan *gUsbScan;
// The on-screen message box: its box, text and button OAM ranges, text canvas, task, mKind, the timed and close wait
// counters and mResult (-2 unset, -1 none yet, else the button index).
typedef struct MessageBox {
    /* 00 */ OamRange *mBox;
    /* 04 */ OamRange *mText;
    /* 08 */ OamRange *mButtons[2];
    /* 10 */ void *mTextCanvas;
    /* 14 */ TaskEntry *mTask;
    /* 18 */ u16 mTimedFrames;
    /* 1a */ s8 mBrightness;
    /* 1b */ s8 mResult;
    /* 1c */ u8 mKind;
    /* 1d */ u8 mCloseWaitFrames;
    /* 1e */ u8 mAdjustBrightness;
} MessageBox;

extern MultiBootParent *gMultiBootParent;
extern WhPrintFunction gWhPrintFunction;
// Values of ChildWaitSessionView.mState.
enum {
    CHILD_WAIT_STATE_IDLE = 1,
    CHILD_WAIT_STATE_WH_START,
    CHILD_WAIT_STATE_MULTIBOOT_START,
    CHILD_WAIT_STATE_MULTIBOOT_WAIT,
    CHILD_WAIT_STATE_CHILD_JOINED,
    CHILD_WAIT_STATE_DOWNLOADING,
    CHILD_WAIT_STATE_DATA_CONNECT,
    CHILD_WAIT_STATE_DATA_SHARING,
    CHILD_WAIT_STATE_SHARING_HANDSHAKE_ACKED,
    CHILD_WAIT_STATE_SHARING_BLOCK_ACKED,
    CHILD_WAIT_STATE_FINAL_REPLY,
    CHILD_WAIT_STATE_FINAL_REPLY_DONE,
    CHILD_WAIT_STATE_CHILD_LEFT,
    CHILD_WAIT_STATE_STOP_MULTIBOOT = 16,
    CHILD_WAIT_STATE_STOP_MULTIBOOT_WAIT,
    CHILD_WAIT_STATE_DOWNLOAD_STARTED_NONE,
    CHILD_WAIT_STATE_END_WH_WAIT,
    CHILD_WAIT_STATE_END_WH_DONE,
    CHILD_WAIT_STATE_CLOSE_NO_RESTART_FINALIZE,
    CHILD_WAIT_STATE_CLOSE_NO_RESTART_WAIT,
    CHILD_WAIT_STATE_CLOSE_NO_RESTART_DONE,
    CHILD_WAIT_STATE_CLOSE_RESTARTABLE_FINALIZE,
    CHILD_WAIT_STATE_CLOSE_RESTARTABLE_WAIT,
    CHILD_WAIT_STATE_CLOSE_RESTARTABLE_DONE,
    CHILD_WAIT_STATE_ABORT_FINALIZE,
    CHILD_WAIT_STATE_ABORT_WAIT,
    CHILD_WAIT_STATE_ABORT_DONE,
    CHILD_WAIT_STATE_FINALIZE_ONLY,
    CHILD_WAIT_STATE_ERROR,
    CHILD_WAIT_STATE_STOP_FINALIZE,
    CHILD_WAIT_STATE_STOP_WAIT,
    CHILD_WAIT_STATE_ENDED,
};

// Values of ChildWaitSessionView.mRequest.
enum {
    CHILD_WAIT_REQUEST_NONE,
    CHILD_WAIT_REQUEST_START,
    CHILD_WAIT_REQUEST_STOP,
};

// Values of ChildWaitSharedEntry.mCode. 0x70 and 0xff also abort (both go to ABORT_FINALIZE); they stay bare.
enum {
    CHILD_WAIT_CODE_NONE = 0,
    CHILD_WAIT_CODE_BLOCK_ACK = 0x10,
    CHILD_WAIT_CODE_BLOCK_ACK_NO_ADVANCE = 0x20,
    CHILD_WAIT_CODE_FINAL_REPLY = 0x40,
    CHILD_WAIT_CODE_CLOSE_NO_RESTART = 0x50,
    CHILD_WAIT_CODE_CLOSE_RESTARTABLE = 0x60,
    CHILD_WAIT_CODE_HANDSHAKE_REQUEST = 0xbc,
    CHILD_WAIT_CODE_HANDSHAKE_ACK = 0xbd,
};

// One entry of the child wait session: a code, a value and the payload bytes.
typedef struct ChildWaitSharedEntry {
    /* 00 */ u16 mCode;
    /* 02 */ u16 mValue;
    /* 04 */ u8 mPayload[0x40];
} ChildWaitSharedEntry;

// The session view of the child wait session: its shared entries, block number, channel, state, handshake and multiboot
// game registry.
typedef struct ChildWaitSessionView {
    /* 000 */ ChildWaitSharedEntry mSendEntryStorage;
    /* 044 */ u8 pad_44[0xbc];
    /* 100 */ ChildWaitSharedEntry mSharedEntries[2];
    /* 188 */ u8 pad_188[0x78];
    /* 200 */ u16 mBlockNumber;
    /* 202 */ u16 mUnk_202;
    /* 204 */ u32 mStallCount;
    /* 208 */ u32 mEntryPresent[16];
    /* 248 */ u8 pad_248[0x400];
    /* 648 */ u16 mTgid;
    /* 64a */ u16 mChannel;
    /* 64c */ u8 mNvramEntries[0x404];
    /* a50 */ u8 mApStoreFirstBlockCopy[0x40];
    /* a90 */ u8 mState;
    /* a91 */ u8 mPrevState;
    /* a92 */ u8 mHandshakeByte;
    /* a93 */ u8 mHandshakeDone;
    /* a94 */ u32 mReplyCount;
    /* a98 */ u32 mMultiBootInitFrames;
    /* a9c */ u32 mEndWaitFrames;
    /* aa0 */ u8 *mUnk_aa0[2];
    /* aa8 */ u8 mUnk_aa8[4];
    /* aac */ u8 mRequest;
    /* aad */ u8 mUnk_aad[3];
    /* ab0 */ ChildWaitSharedEntry *mSendEntry;
    /* ab4 */ MBGameRegistry mGameRegistry;
    /* af0 */ u8 pad_af0[0x10];
    /* b00 */ u8 mMultiBootParent[4];
} ChildWaitSessionView;

// The child wait session: the session view, the child user, the event callback, step task and event and stop flags.
typedef struct ChildWaitSession {
    /* 00000 */ ChildWaitSessionView mSessionView;
    /* 00b04 */ u8 mMultiBootParentTail[0x1e280 - 0xb04];
    /* 1e280 */ u8 mChildUser[0x18];
    /* 1e298 */ void (*mCallback)(s32 event);
    /* 1e29c */ TaskEntry *mStepTask;
    /* 1e2a0 */ u8 mEventPending;
    /* 1e2a1 */ u8 mStopRequested;
} ChildWaitSession;

static inline ChildWaitSharedEntry *GetChildWaitSharedEntry(ChildWaitSessionView *session, u32 entryIndex) {
    return &session->mSharedEntries[entryIndex];
}

// An FSArchive named dwc, loaded from rom:/dwc/utility.bin, with its tables, a stack of 32 pointers and the lock id.
typedef struct DwcArchive {
    /* 00 */ void *mTables;
    /* 04 */ void *mStackStorage[0x20];
    /* 84 */ PointerStack *mStack;
    /* 88 */ FSArchive mArchive;
    /* e4 */ u16 mLockId;
    /* e6 */ u8 mUnk_e6[2];
} DwcArchive;

// The OamRange objects of one screen (gOamRanges holds two): 32 ranges, the start and end nodes of the list of ranges
// in use, the node list and the stack of free ranges.
typedef struct OamRanges {
    /* 000 */ OamRange mRanges[0x20];
    /* 200 */ OamRange mListStart;
    /* 210 */ OamRange mListEnd;
    /* 220 */ void *mNodeList;
    /* 224 */ PointerStack *mFreeRanges;
} OamRanges;

// One image of an NCE file: the number of its OAM entries and the offset of the entry data; the file starts with one of
// these per image index.
typedef struct NceImage {
    /* 00 */ u16 mEntryCount;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u32 mEntriesOffset;
} NceImage;

struct OamBuffers;
extern struct OamBuffers *gOamBuffers;
struct ObjCharRanges;
struct TaskList;
