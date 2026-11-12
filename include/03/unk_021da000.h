#pragma once

#include "03/code_021be610.h"
#include "03/Graphics/text_canvas.h"
#include "03/System/application.h"
#include "03/Menu/jb5_move.h"
#include "03/Net/wh.h"
#include "types.h"
#include "03/Graphics/nce_oam.h" // OamRange
#include "03/code_021d1d88.h"
#include "03/Graphics/blend_brightness_fade.h"
#include "code_02003024.h" // FSArchive
#include "03/Menu/slide_buttons.h"
#include "03/code_021c2530.h"
#include "03/Net/child_wait_session_object.h"
#include "03/System/exp_heap.h"
#include "03/System/tasks.h"
#include "03/types_021d299c.h"

typedef struct Jb3List {
    /* 00 */ u32 mIdTimerTask;
    /* 04 */ u8 mIdTimer[4];
    /* 08 */ u16 *mJb3ListBackNsc;
    /* 0c */ void *mYbBgStep2NclFiles[2];
    /* 14 */ BgTextCanvas *mBgTextCanvas;
    /* 18 */ OamEntry *mCellOamEntries[7];
    /* 34 */ OamEntry *mSetTypeOamEntry;
    /* 38 */ u32 mScrollTask;
    /* 3c */ u32 mBgOffsetTask;
    /* 40 */ u8 mChosenId;
    /* 41 */ u8 mScrollTimer;
    /* 42 */ u8 mReturnId;
    /* 43 */ u8 mDnsNoneCopy;
    /* 44 */ u8 mBgOffsetPending;
    /* 45 */ u8 mScrollBarDragging;
    /* 46 */ u8 mScrollBarLimitSoundPlayed;
    /* 47 */ u8 mKeyLimitSoundPlayed;
} Jb3List;

// Objects whose layout isn't known yet.
typedef struct UsbScan UsbScan;
typedef struct MultiBootParent MultiBootParent;
extern SlideButtons *gSlideButtons;
extern u8 gSubScreenMessageShown;
extern OamRange **gSelectionObjects;
// Object behind gLinkLevel.
typedef struct LinkLevel {
    /* 00 */ OamEntry *mOamEntry;
    /* 04 */ u32 mTask;
    /* 08 */ s8 mImageRow;
} LinkLevel;

extern LinkLevel *gLinkLevel;

// The on-screen keys of the Edit screen.
typedef struct EditKeyboard {
    /* 000 */ void *mRowTexts[3][4];
    /* 030 */ OamEntry *mKeys[0x2f];
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
extern struct EditAddrKeyboard *gEditAddrKeyboard;
extern u8 gValueRecordsRequestSucceeded[];
struct ValueRecordsRequest;
extern struct ValueRecordsRequest *gValueRecordsRequest;
extern u8 gLanguageIndex[];
extern u8 gQuitFlag[];
extern void *gHeapMemoryBlock;
extern u8 gYb5MultiShowNext;
extern u8 gOptMenuEntryChosen[];
extern u8 gLinkMessageResult[];
extern u8 gOptMenuMessageShowNext;
extern u8 gTimedMessageFrames;
extern u8 gChildWaitMessageSubScreenShown[];
extern u8 gChildWaitMessageShowNext;
extern u8 gJb5MoveShowNext;
extern u8 gChildWaitResult;
extern u8 gValueRecordsShowNext;
extern u8 gValueRecordsNextFrames[];
extern u8 gApListScrollY[];
struct ApList;
extern struct ApList *gApList;
struct Edit;
extern struct Edit *gEdit;
struct EditAddr;
extern struct EditAddr *gEditAddr;
extern u8 gJb4ErrorCode[];
extern u8 gJb3ListSelectedId;
extern u8 gJb3ListMode;
extern u8 gJb3ListSelectedRow;
extern u16 gJb3ListScrollY;
extern Jb3List *gJb3List;
extern u8 gExchangeEntryShowNext;
extern u8 gExchangeKeyShowNext;
extern u8 gExchangeResultFrames[];
extern u8 gExchangeSearchShowNext;
extern u8 gApScanKind[];
extern u16 gApScanFrames;
extern u8 gApSelectedIndex[];
struct Ap;
extern struct Ap *gAp;
extern s8 gWaySavedIndex;
extern s8 gWaySelectedIndex;
extern u8 gWayChosen[];
extern u8 *gYbBgStep21Ncl;
extern u8 gConnectSucceeded;
extern u8 gConnectDoneFrames[];
extern u8 gUsbNextFrames;
extern u8 gXb3MultiChosen;
extern u8 gUsbExitKind;
struct Bg2ScrBuffer;
extern struct Bg2ScrBuffer *gBg2ScrBuffer;
extern u8 gBgPaletteCopyRequest[];
struct ScrollBar;
extern struct ScrollBar *gScrollBar;
struct ApScan;
extern struct ApScan *gApScan;
struct ApStore;
extern struct ApStore *gApStore;
struct SoundData;
extern struct SoundData *gSoundData;
extern void *gMenuPairScreenMap;
struct MenuPairObjects;
extern struct MenuPairObjects *gMenuPairObjects;
extern UsbScan *gUsbScan;
// Object behind gMessageBox: AdvanceMessageBoxSlideOut passes 0x00 to GetOamRangeEntryPosition and reads the byte at
// 0x1e; GetMessageBoxResult reads the byte at 0x1b.
typedef struct MessageBox {
    /* 00 */ OamRange *mBox;
    /* 04 */ OamRange *mText;
    /* 08 */ OamRange *mButtons[2];
    /* 10 */ void *mTextCanvas;
    /* 14 */ u32 mTask;
    /* 18 */ u16 mTimedFrames;
    /* 1a */ s8 mBrightness;
    /* 1b */ s8 mResult;
    /* 1c */ u8 mKind;
    /* 1d */ u8 mCloseWaitFrames;
    /* 1e */ u8 mAdjustBrightness;
} MessageBox;

extern MessageBox *gMessageBox;
extern MultiBootParent *gMultiBootParent;
extern u16 *gMultiBootMaskPointers[];
extern UnkFunc *gWhPrintFunction;
typedef struct ChildWaitSharedEntry {
    /* 00 */ u16 mCode;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u8 mUnk_04[0x40];
} ChildWaitSharedEntry;

// Object behind gChildWaitSessionView.
typedef struct ChildWaitSessionView {
    /* 000 */ u8 pad_000[0x100];
    /* 100 */ ChildWaitSharedEntry mSharedEntries[2];
    /* 188 */ u8 pad_188[0x78];
    /* 200 */ u16 mBlockNumber;
    /* 202 */ u16 mUnk_202;
    /* 204 */ u32 mStallCount;
    /* 208 */ u32 mEntryPresent[16];
    /* 248 */ u8 pad_248[0x400];
    /* 648 */ u16 mTgid;
    /* 64a */ u16 mChannel;
    /* 64c */ u8 mUnk_64c[0x404];
    /* a50 */ u8 mUnk_a50[0x40];
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
    /* ab4 */ u32 mRomFilePathp;
    /* ab8 */ u32 mGameNamep;
    /* abc */ u32 mGameIntroductionp;
    /* ac0 */ u32 mIconCharPathp;
    /* ac4 */ u32 mIconPalettePathp;
    /* ac8 */ u32 mGgid;
    /* acc */ u8 mMaxPlayerNum;
    /* acd */ u8 mUnk_acd[0x33];
    /* b00 */ u8 mUnk_b00[4];
} ChildWaitSessionView;

static inline ChildWaitSharedEntry *GetChildWaitSharedEntry(ChildWaitSessionView *session, u32 entryIndex) {
    return &session->mSharedEntries[entryIndex];
}

extern ChildWaitSessionView *gChildWaitSessionView;
// Object of 0xe8 bytes: a pointer at 0x00, 32 pointers from 0x04, the list of them at 0x84, an FSArchive at 0x88
// and a halfword at 0xe4.
typedef struct DwcArchive {
    /* 00 */ void *mTables;
    /* 04 */ void *mStackStorage[0x20];
    /* 84 */ PointerStack *mUnk_84;
    /* 88 */ FSArchive mArchive;
    /* e4 */ u16 mLockId;
    /* e6 */ u8 mUnk_e6[2];
} DwcArchive;

extern DwcArchive *gDwcArchive;
// Two objects of 0x228 bytes: 32 objects from 0x000, two list heads at 0x200 and 0x210, a pointer at 0x220 and the
// list of the free objects at 0x224.
typedef struct OamRanges {
    /* 000 */ OamRange mRanges[0x20];
    /* 200 */ OamRange mListStart;
    /* 210 */ OamRange mListEnd;
    /* 220 */ void *mNodeList;
    /* 224 */ PointerStack *mFreeRanges;
} OamRanges;

extern OamRanges *gOamRanges;
// Eight-byte records at the start of a resource: a number at 0x00 and the offset of a table at 0x04.
typedef struct NceImage {
    /* 00 */ u16 mEntryCount;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u32 mEntriesOffset;
} NceImage;

extern NceImage *gNceFiles[];
extern BlendBrightnessFadeSlot *gBlendBrightnessFadeSlots;
extern TextCanvases *gTextCanvases;
extern u8 gLcdOff;
extern u8 gTouchRepeatFrames;
extern KeyTouchInput *gKeyTouchInput;
extern u8 gKeyRepeatFrames[];
extern UnkFunc *gSavedIrqFunction;
extern u32 gSavedIrqMask;
struct OamBuffers;
extern struct OamBuffers *gOamBuffers;
struct ObjCharRanges;
extern struct ObjCharRanges *gObjCharRanges;
extern u32 gSavedBankSettings[];
struct TaskList;
extern struct TaskList *gTaskLists;
