#pragma once
#include "types.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h" // NNSFndArchive
#include "Main/System/input_slots.h" // InputSlot
#include "frameheap.h" // NNSiFndHeapHead
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h" // RandomState64
#include "pm.h" // PMSleepCallbackInfo
#include "Main/Sound/sound_seq.h" // SoundSetPlayer

// Values of StartupWork.mLanguageIndex and of the language field of the owner info; they match the file name suffixes
// (_fr, _ge, _it, _es) of the language files, 0 and 1 share the files without a suffix.
enum {
    LANGUAGE_UNSUFFIXED,
    LANGUAGE_ENGLISH,
    LANGUAGE_FRENCH,
    LANGUAGE_GERMAN,
    LANGUAGE_ITALIAN,
    LANGUAGE_SPANISH,
};

// Values of StartupWork.mRegion; FormatDate writes the date in the order of each (year first, month first, day first).
enum {
    REGION_JAPAN,
    REGION_AMERICA,
    REGION_EUROPE,
};

// Value of StartupWork.mConnectionKind.
#define CONNECTION_KIND_NONE 0
#define CONNECTION_KIND_MEMBER_SELECT 1 // set by the member select screen
#define CONNECTION_KIND_WL_MENU 2 // set by the title entry of the WL menu and by the member group screen
#define CONNECTION_KIND_WIFI_MENU 3 // set by the title entry of the Wi-Fi menu
#define CONNECTION_KIND_WIFI_TOP_MENU 4 // set by the Wi-Fi top menu before it starts the next scene

// Object behind gStartupWork (0x7c bytes); the 0x14 bytes at 0x2a are the source of a block move into
// gBackupBuffers.
typedef struct StartupWork {
    /* 00 */ s32 mRegion;
    /* 04 */ s32 mLanguageIndex;
    /* 08 */ SoundSetPlayer mSoundSetPlayer;
    /* 1c */ union {
        s32 mUnk_1c;
        struct {
            s32 mSoundSetSeqPlaying : 1;
            s32 mSoundSetPlayerInitialized : 1;
            s32 mMultiSimple : 1;
            s32 mUnk_1c_3 : 1;
        };
    };
    /* 20 */ s32 mConnectionKind;
    /* 24 */ NNSiFndHeapHead *mHeap;
    /* 28 */ s16 mUnk_28;
    /* 2a */ u16 mOwnerText[10];
    /* 3e */ u16 mOwnerCharCount;
    /* 40 */ u8 mFavoriteColor;
    /* 41 */ u8 mUnk_41[0x3];
    /* 44 */ s32 mPickedValue;
    /* 48 */ u32 mFirstBackLightOn;
    /* 4c */ u32 mSecondBackLightOn;
    /* 50 */ u16 mDemoEndedByInput;
    /* 52 */ u8 mUnk_52[0x2];
    /* 54 */ BOOL mUnk_54;
    /* 58 */ s32 mUnk_58;
    /* 5c */ s32 mUnk_5c;
    /* 60 */ RandomState64 mRandom;
    /* 78 */ s32 mUnk_78;
} StartupWork;

// Bit of StartupWork.mUnk_1c: set while the 3D engine uses fast DMA (NNS_G3dGeUseFastDma(1)), cleared with it.
#define STARTUP_FLAG_FAST_DMA 8

// The callbacks of one scene (an entry of gSceneFuncs): mInit once, mUpdate every frame, mRelease once.
typedef struct SceneCallbacks {
    // Called once before the scene's frames with the scene numbers. Allocates the scene's objects
    // from the scene heap (the heap of RunScenes' frame, destroyed when the scene ends).
    /* 00 */ void (*mInit)();
    // One per-frame step, called every pass of the update loops and of the fade-out loop (then with
    // a == NULL), with the scene numbers and mSceneFrames. A second per-frame slot (0x0c) runs
    // after it. Scenes write their next scene into a.mNextScene here; the Menu scene does not
    // (RunScene ends it).
    /* 04 */ void (*mUpdate)();
    // Called once after the loops. Calls the scene's undo functions and clears the scene's globals;
    // it frees nothing by itself except in the WiFi scene (the heap of ReleasePlayerEntryList): the scene
    // heap is destroyed by the caller. The Race slot also writes a save block in kind 6.
    /* 08 */ void (*mRelease)();
    /* 0c */ void (*mPostUpdate)();
    /* 10 */ void (*mPreSleep)(void);
    /* 14 */ void (*mPostSleep)(void);
    /* 18 */ s16 mFadeToClearFrameCount;
    /* 1a */ s16 mFadeToFadedFrameCount;
    /* 1c */ int mSkipWhenSpanned;
} SceneCallbacks;

// Values of SceneRunState.mRunStep.
#define SCENE_RUN_STEP_LOADING 0

#define SCENE_RUN_STEP_SYNC_WAIT 1 // waiting for data sharing to sync

#define SCENE_RUN_STEP_RUNNING 2

#define SCENE_RUN_STEP_FADE_OUT 3

#define SCENE_RUN_STEP_CARD_PULLED_OUT 4 // loop while the card is pulled out

#define SCENE_RUN_STEP_RELEASE 5

#define SCENE_RUN_STEP_IDLE 6

// Values of SceneRunState.mMessageKind (the text the message screen shows); NONE is no message screen requested.
#define MESSAGE_KIND_NONE (-1)
#define MESSAGE_KIND_CONNECTION_ERROR 0
#define MESSAGE_KIND_BACKUP_ERROR_OTHER_STATUS 1
#define MESSAGE_KIND_BACKUP_ERROR_WHILE_WRITING 2
#define MESSAGE_KIND_CARD_PULLED_OUT 3
#define MESSAGE_KIND_WIFI_ERROR 4
#define MESSAGE_KIND_WIFI_NO_INPUT 5
#define MESSAGE_KIND_WIFI_OPPONENT_LEFT 6

// Object behind gSceneRunState.
typedef struct SceneRunState {
    /* 000 */ u8 *mThreadStack;
    /* 004 */ OSThread mThread;
    /* 0c4 */ OSThreadQueue mThreadQueue;
    /* 0cc */ PMSleepCallbackInfo mPreSleepCallback;
    /* 0d8 */ PMSleepCallbackInfo mPostSleepCallback;
    // Passes of RunScene's update loop and fade-out loop since they began (RunScene zeroes it at the start of each);
    // not counted while RunSceneIsDataSharingIncomplete is true (mode 5 with a flag, or the
    // gConnectionWork flag tests). Only the Race slots use it (kind 6: the first 0x708 frames,
    // thresholds 0x5a ...).
    /* 0e4 */ s32 mSceneFrames;
    /* 0e8 */ s32 mPassCount;
    // Copy of the running scene's SceneCallbacks, written once by RunScene; slots 0x10 / 0x14 and
    // the fade lengths are read from it.
    /* 0ec */ SceneCallbacks mSceneCallbacks;
    /* 10c */ s32 mRunStep;
    /* 110 */ BOOL mLcdOff;
    /* 114 */ u8 mUnk_114[4];
    /* 118 */ s32 mMessageKind;
    /* 11c */ s32 mMessageInputEnabled;
    /* 120 */ s8 mNextScene;
} SceneRunState;

// DisplaySettings.mFrameFlags: the frame was finished and waited for; the frame took more than one vblank.
#define DISPLAY_FRAME_FLAG_FINISHED 1
#define DISPLAY_FRAME_FLAG_SPANNED_VBLANK 2
// G3xParams.mClearColor of a 3D scene.
#define DISPLAY_3D_CLEAR_COLOR 0x5000

// Object behind member 0x6c of DisplaySettings.
typedef struct G3xParams {
    /* 00 */ u16 mClearColor;
    /* 02 */ u8 mSortMode;
    /* 03 */ u8 mBufferMode;
} G3xParams;

// Object behind gDisplaySettings.
typedef struct DisplaySettings {
    /* 00 */ u16 mWaitIrqCount;
    /* 02 */ u16 mMainDisplayMask;
    /* 04 */ u16 mSubDisplayMask;
    /* 06 */ u16 mDispMode;
    /* 08 */ u16 mMainBgMode;
    /* 0a */ u16 mBg0As;
    /* 0c */ u16 mSubBgMode;
    /* 0e */ u16 mBankForBG;
    /* 10 */ u16 mBankForOBJ;
    /* 12 */ u16 mBankForBGExtPltt;
    /* 14 */ u16 mBankForOBJExtPltt;
    /* 16 */ u16 mBankForTex;
    /* 18 */ u16 mBankForTexPltt;
    /* 1a */ u16 mBankForClearImage;
    /* 1c */ u16 mBankForSubBG;
    /* 1e */ u16 mBankForSubOBJ;
    /* 20 */ u16 mBankForSubBGExtPltt;
    /* 22 */ u16 mBankForSubOBJExtPltt;
    /* 24 */ u16 mBankForARM7;
    /* 26 */ u16 mBankForLCDC;
    /* 28 */ DisplayBgRecords mMainBgRecords;
    /* 6c */ G3xParams *mG3xParams;
    /* 70 */ DisplayBgRecords mSubBgRecords;
    /* b4 */ u32 mUnk_b4;
    /* b8 */ void (*mIrqCallback)(void);
    /* bc */ u64 mFrameStartTick;
    /* c4 */ u64 mWaitEndTick;
    /* cc */ u32 mTimeBeforeWait;
    /* d0 */ u32 mTimeSinceWaitEnd;
    /* d4 */ u32 mTimeSinceFrameStart;
    /* d8 */ u8 mFrameFlags;
} DisplaySettings;

// Set from the start of a race; recording and playback slots read keys only while set.
#define INPUT_STATE_READ_RACE_KEYS 2

// Set while the pause menu is open during a race; the input slots stop updating.
#define INPUT_STATE_OPEN_DURING_RACE 1

// Set when a scene ends; the input slots then update with no keys.
#define INPUT_STATE_NO_KEYS 8

// Bit of InputState.mFlags: the left and right keys are swapped (mirror mode).
#define INPUT_STATE_FLAG_LEFT_RIGHT_SWAPPED 4

// The pad keys, flags and participant position of the current input, behind gInputState.
typedef struct InputState {
    /* 00 */ u8 mUnk_00[2];
    /* 02 */ u16 mPadKeys;
    /* 04 */ u16 mFlags;
    /* 06 */ u8 mUnk_06[2];
    /* 08 */ s32 mParticipantPosition;
    /* 0c */ BOOL mUnk_0c;
} InputState;

// Entries of 0x0c bytes from 0x9b0 of ArchiveSlots.
typedef struct ArchiveBuffer {
    /* 00 */ void *mHeap;
    /* 04 */ void *mData;
    /* 08 */ union {
        s32 mUnk_08;
        struct {
            u32 mByteSize : 29;
            s32 mUncompress : 1;
            u32 mUnk_08_30 : 1;
            u32 mUnk_08_31 : 1;
        };
    };
} ArchiveBuffer;

// 0x70-byte entries from the start of ArchiveSlots; mLoaded is nonzero while its archive is loaded.
typedef struct ArchiveSlot {
    /* 00 */ NNSFndArchive mArchive;
    /* 68 */ s32 mLoaded;
    /* 6c */ void *mData;
} ArchiveSlot;

// The 0xa0 bytes at 0x8c8 of ArchiveSlots.
typedef struct ArchiveLoadRequest {
    /* 00 */ u8 mPath[0x80];
    /* 80 */ u32 *mSourceData;
    /* 84 */ void *mData;
    /* 88 */ u32 *mReadBuffer;
    /* 8c */ s32 mSlotIndex;
    /* 90 */ s32 mAllocFromHeapEnd;
    /* 94 */ s32 mUncompressSource;
    /* 98 */ s32 mUnk_98;
    /* 9c */ s32 mArchiveBufferSize;
} ArchiveLoadRequest;

// The archive loader: 20 archive slots, the file table, the load request, the buffers and their heaps.
typedef struct ArchiveSlots {
    /* 000 */ ArchiveSlot mSlots[20];
    /* 8c0 */ u32 mFileTableSize;
    /* 8c4 */ void *mFileTable;
    /* 8c8 */ ArchiveLoadRequest mLoadRequest;
    /* 968 */ FSFile mFile;
    /* 9b0 */ ArchiveBuffer mBuffers[16];
    /* a70 */ void *mCourseId;
    /* a74 */ void *mRaceKind;
    /* a78 */ NNSiFndHeapHead *mFirstHeap;
    /* a7c */ NNSiFndHeapHead *mCourseBufferHeap;
    /* a80 */ NNSiFndHeapHead *mLastHeap;
} ArchiveSlots;

extern ArchiveSlots *gArchiveSlots;

extern SceneRunState *gSceneRunState;

extern StartupWork *gStartupWork;

// Object at gFileReadThread: 0x400 bytes (the end of them is the top of the stack of the OSThread) and two words.
typedef struct FileReadThread {
    /* 000 */ u8 mStack[0x400];
    /* 400 */ OSThread mThread;
    /* 4c0 */ s32 mUnk_4c0;
    /* 4c4 */ s32 mUnk_4c4;
} FileReadThread;

extern FileReadThread gFileReadThread;

// Object at gWvrState: a word and a function pointer.
// Values of WvrState.mState.
#define BANK_SHARE_ACTIVE 0 // after WVR_StartUpAsync finished

#define BANK_SHARE_INACTIVE 1 // initial value; after WVR_TerminateAsync finished

#define BANK_SHARE_CHANGING 2 // set while an async start or terminate is running

#define BANK_SHARE_INACTIVE_UNUSED 3 // handled like INACTIVE; nothing writes it

// The state of the wireless bank share and the callback it calls.
typedef struct WvrState {
    /* 00 */ volatile s32 mState;
    /* 04 */ s32 (*mCallback)();
} WvrState;

// Eight halfwords at gUnreadHalfwordGroups: two groups of four.
typedef struct UnreadHalfwordGroups {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u16 mUnk_0e;
} UnreadHalfwordGroups;

// Values of RomArchiveMessage.mKind and RomArchiveParentViewEntry.mKind. The child sends REQUEST (word 04 and value 24
// name the file part) and RELEASE (word 04 is the block id); the parent answers with REPLY (the block id, or value 24
// of 0 to ask for a new sync) and RELEASE_REPLY.
enum {
    ROM_ARCHIVE_MESSAGE_REQUEST,
    ROM_ARCHIVE_MESSAGE_REPLY,
    ROM_ARCHIVE_MESSAGE_RELEASE,
    ROM_ARCHIVE_MESSAGE_RELEASE_REPLY
};

// Entry of the table at 0x440 of gRomArchiveTransfer: a four-bit part in the low bits of the first word, then two
// words.
typedef struct RomArchiveParentViewEntry {
    /* 00 */ u32 mKind : 4;
    /* 00 */ u32 mUnk_00_4 : 28;
    /* 04 */ s32 mBlockId;
    /* 08 */ u8 *mBlockData;
} RomArchiveParentViewEntry;

// Nine bytes that SendRomArchiveMessage builds on the stack and passes to WBT_PutUserData: two four-bit parts, a
// 24-bit part, a word and a byte.
typedef struct RomArchiveMessage {
    /* 00 */ u32 mKind : 4;
    /* 00 */ u32 mPacketSizeHigh : 4;
    /* 00 */ u32 mValue24 : 24;
    /* 04 */ s32 mWord04;
    /* 08 */ u8 mPacketSizeLow;
} RomArchiveMessage;

struct RomArchiveFileNode;

struct FSFile;

// Part of gRomArchiveTransfer from 0x440: the table, then nine words at 0x46cc.
typedef struct RomArchiveParentView {
    /* 0000 */ RomArchiveParentViewEntry mEntries[32];
    /* 0180 */ u8 mUnk_0180[0x97c];
    /* 0afc */ void *mChunkBitmapBuffer;
    /* 0b00 */ u32 mUnk_0b00;
    /* 0b04 */ u32 mUnk_0b04;
    /* 0b08 */ s32 mUnk_0b08;
    /* 0b0c */ u8 mUnk_0b0c[0x3bb4];
    /* 46c0 */ struct RomArchiveFileNode *mFreeHead;
    /* 46c4 */ struct RomArchiveFileNode *mActiveHead;
    /* 46c8 */ struct RomArchiveFileNode *mPendingHead;
    /* 46cc */ s32 mReplySendMask;
    /* 46d0 */ s32 mGroupSendMask;
    /* 46d4 */ BOOL mMessageSendPending;
    /* 46d8 */ s32 mActiveMask;
    /* 46dc */ s32 mRequestMask;
    /* 46e0 */ BOOL mPacketSizeChangePending;
    /* 46e4 */ s32 mQueuedNodeCount;
    /* 46e8 */ s32 mPacketSizeMessageMask;
    /* 46ec */ s32 mNewParentPacketSize;
    /* 46f0 */ u8 mUnk_46f0[0x10];
} RomArchiveParentView;

// Object at gRomArchiveTransfer.
typedef struct RomArchiveTransfer {
    /* 0000 */ u32 mIsParent;
    /* 0004 */ BOOL mSendAllowed;
    /* 0008 */ BOOL mSendPending;
    /* 000c */ s32 mState;
    /* 0010 */ void (*mStateCallback)(s32 unused);
    /* 0014 */ void *(*mAllocFunc)(s32 allocArg, u32 size, void *oldBuffer);
    /* 0018 */ s32 mAllocFuncArg;
    /* 001c */ struct FSFile *mPendingFile;
    /* 0020 */ void *mArchiveBlock;
    /* 0024 */ s32 mArchiveBlockSize;
    /* 0028 */ s32 mParentPacketSize;
    /* 002c */ s32 mChildPacketSize;
    /* 0030 */ u16 mPort;
    /* 0032 */ u8 mUnk_0032[0xe];
    /* 0040 */ u8 mPacketBuffer[0x400];
    /* 0440 */ RomArchiveParentView mParentView;
} RomArchiveTransfer;

extern RomArchiveTransfer gRomArchiveTransfer;

extern void (*gFrameCallback)(s32);

