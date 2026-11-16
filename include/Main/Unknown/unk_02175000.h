#pragma once

#include "types.h"
#include "Main/Unknown/code_02036c5c.h"
#include "code_020182c0.h" // Unk020182c0
#include "Main/Unknown/unk_02175628.h" // InputSlot
#include "frameheap.h" // NNSiFndHeapHead
#include "os_thread.h"
#include "Main/Unknown/code_020d22c0.h" // RandomState64
#include "pm.h" // PMSleepCallbackInfo
#include "Main/Unknown/code_02105ec0.h" // SoundSetPlayer

// Object behind gSystemData (0x7c bytes); the 0x14 bytes at 0x2a are the source of a block move into
// gSaveData.
typedef struct Unk021759d0 {
    /* 00 */ s32 field0;
    /* 04 */ s32 mLanguageIndex;
    /* 08 */ SoundSetPlayer mSoundSetPlayer;
    /* 1c */ union {
        s32 field1C;
        struct {
            s32 mSoundSetSeqPlaying : 1;
            s32 mSoundSetPlayerInitialized : 1;
            s32 field1C_2 : 1;
            s32 field1C_3 : 1;
        };
    };
    /* 20 */ s32 field20;
    /* 24 */ NNSiFndHeapHead *mHeap;
    /* 28 */ s16 field28;
    /* 2a */ u8 mOwnerText[0x14];
    /* 3e */ u16 mOwnerCharCount;
    /* 40 */ u8 field40;
    /* 41 */ u8 field41[0x3];
    /* 44 */ s32 field44;
    /* 48 */ u32 mFirstBackLightOn;
    /* 4c */ u32 mSecondBackLightOn;
    /* 50 */ u16 field50;
    /* 52 */ u8 field52[0x2];
    /* 54 */ BOOL field54;
    /* 58 */ s32 field58;
    /* 5c */ s32 field5C;
    /* 60 */ RandomState64 mRandom;
    /* 78 */ s32 field78;
} Unk021759d0;

// The callbacks of one scene (0x20 bytes). scene_runScene copies it to mSceneCallbacks and calls mInit
// once, then mUpdate and the unnamed slot 0x0c every frame, then mRelease once. 0x0c is the second
// per-frame slot (it runs after mUpdate in the same pass and mostly copies the two 2D lists). 0x10
// and 0x14 are called from two library callbacks registered in scene_init; 0x18 and 0x1a are
// fade lengths passed to mbright_fadeIn / mbright_fadeToWhite; 0x1c is a flag for dc_2037658; all stay
// unnamed. One instance per scene (the 16 entries of scproc_sSceneTable): seven tables are named, the
// others are unnamed tables or stack literals.
typedef struct SceneCallbacks {
    // Called once before the scene's frames with the scene numbers. Allocates the scene's objects
    // from the scene heap (the heap of scproc_sceneProcMain' frame, destroyed when the scene ends).
    /* 00 */ void (*mInit)();
    // One per-frame step, called every pass of the update loops and of the fade-out loop (then with
    // a == NULL), with the scene numbers and mSceneFrames. A second per-frame slot (0x0c) runs
    // after it. Scenes write their next scene into a->mNextScene here; the Menu scene does not
    // (scene_runScene ends it).
    /* 04 */ void (*mUpdate)();
    // Called once after the loops. Calls the scene's undo functions and clears the scene's globals;
    // it frees nothing by itself except in the WiFi scene (the heap of ReleasePlayerEntryList): the scene
    // heap is destroyed by the caller. The Race slot also writes a save block in kind 6.
    /* 08 */ void (*mRelease)();
    /* 0c */ void (*fieldC)();
    /* 10 */ void (*mPreSleep)(void);
    /* 14 */ void (*mPostSleep)(void);
    /* 18 */ s16 mFadeToClearFrameCount;
    /* 1a */ s16 mFadeToFadedFrameCount;
    /* 1c */ int field1C;
} SceneCallbacks;

// Object behind scene_sSceneState.
typedef struct SceneRunState {
    /* 000 */ void *mThreadStack;
    /* 004 */ OSThread mThread;
    /* 0bc */ u8 fieldBC[8];
    /* 0c4 */ OSThreadQueue mThreadQueue;
    /* 0cc */ PMSleepCallbackInfo mPreSleepCallback;
    /* 0d8 */ PMSleepCallbackInfo mPostSleepCallback;
    // Passes of scene_runScene's update loop and fade-out loop since they began (scene_runScene zeroes it at
    // :192 and :376); not counted while func_020487fc_inline6 is true (mode 5 with a flag, or the
    // gStruct217AA00 flag tests). Only the Race slots use it (kind 6: the first 0x708 frames,
    // thresholds 0x5a ...).
    /* 0e4 */ s32 mSceneFrames;
    /* 0e8 */ s32 mPassCount;
    // Copy of the running scene's SceneCallbacks, written once by scene_runScene; slots 0x10 / 0x14 and
    // the fade lengths are read from it (code_0204984c.c:125, :132, :431-438).
    /* 0ec */ SceneCallbacks mSceneCallbacks;
    /* 10c */ s32 field10C;
    /* 110 */ BOOL mLcdOff;
    /* 114 */ u8 field114[4];
    /* 118 */ s32 field118;
    /* 11c */ s32 field11C;
    /* 120 */ s8 mNextScene;
} SceneRunState;

// Part of DisplaySettings at 0x28, 0x38, 0x70 and 0x80: seven halfwords.
typedef struct Bg01Cnt {
    /* 00 */ u16 mBgCntLow2;
    /* 02 */ u16 mBgCntBit6;
    /* 04 */ u16 mBgCntVal14;
    /* 06 */ u16 mBgCntVal7;
    /* 08 */ u16 mBgCntVal8;
    /* 0a */ u16 mBgCntVal2;
    /* 0c */ u16 mBgCntVal13;
    /* 0e */ u8 fieldE[0x2];
} Bg01Cnt;

// Object behind member 0x6c of DisplaySettings.
typedef struct G3xParams {
    /* 00 */ u16 mClearColor;
    /* 02 */ u8 mSwapBit0;
    /* 03 */ u8 mSwapBit1;
} G3xParams;

// Object behind gCurDisplayConfig.
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
    /* 28 */ Bg01Cnt mMainBg0;
    /* 38 */ Bg01Cnt mMainBg1;
    /* 48 */ Bg23Cnt mMainBg2;
    /* 58 */ Bg23Cnt mMainBg3;
    /* 68 */ u16 field68;
    /* 6a */ u16 field6A;
    /* 6c */ G3xParams *mG3xParams;
    /* 70 */ Bg01Cnt mSubBg0;
    /* 80 */ Bg01Cnt mSubBg1;
    /* 90 */ Bg23Cnt mSubBg2;
    /* a0 */ Bg23Cnt mSubBg3;
    /* b0 */ u16 fieldB0;
    /* b2 */ u16 fieldB2;
    /* b4 */ u32 fieldB4;
    /* b8 */ void (*mIrqCallback)(void);
    /* bc */ u64 mFrameStartTick;
    /* c4 */ u64 mWaitEndTick;
    /* cc */ u32 mTimeBeforeWait;
    /* d0 */ u32 mTimeSinceWaitEnd;
    /* d4 */ u32 mTimeSinceFrameStart;
    /* d8 */ u8 mFrameFlags;
} DisplaySettings;

// Objects whose layout isn't known yet.
extern DisplaySettings *gCurDisplayConfig;
extern InputSlot g_GlobalG;
// Set from the start of a race; recording and playback slots read keys only while set.
#define INPUT_STATE_READ_RACE_KEYS 2
// Set while the pause menu is open during a race; the input slots stop updating.
#define INPUT_STATE_OPEN_DURING_RACE 1
typedef struct InputState {
    /* 00 */ u8 field0[2];
    /* 02 */ u16 mPadKeys;
    /* 04 */ u16 mFlags;
    /* 06 */ u8 field6[2];
    /* 08 */ s32 field8;
    /* 0c */ BOOL fieldC;
} InputState;

extern InputState *input_sPadData;
// 0x5c-byte entries; driver_handleCannon writes the halfword at 0x00 of entry Kart.mEntryIndex.
typedef struct Unk0217566a {
    /* 00 */ u16 mBitMask;
    /* 02 */ u8 field2[0x5a];
} Unk0217566a;

extern Unk0217566a data_0217566a[];
// Entries of 0x0c bytes from 0x9b0 of Unk021759c8.
typedef struct ArchiveBuffer {
    /* 00 */ void *mHeap;
    /* 04 */ void *mData;
    /* 08 */ union {
        s32 field8;
        struct {
            u32 field8_0 : 29;
            s32 mUncompress : 1;
            u32 field8_30 : 1;
            u32 field8_31 : 1;
        };
    };
} ArchiveBuffer;

// 0x70-byte entries from the start of Unk021759c8; mLoaded is nonzero while its archive is loaded.
typedef struct ArchiveSlot {
    /* 00 */ Unk020182c0 mArchive;
    /* 68 */ s32 mLoaded;
    /* 6c */ Unk02018344 *mData;
} ArchiveSlot;

// The 0xa0 bytes at 0x8c8 of Unk021759c8.
typedef struct ArchiveLoadRequest {
    /* 00 */ u8 mPath[0x80];
    /* 80 */ u32 *mSourceData;
    /* 84 */ void *mData;
    /* 88 */ u32 *mReadBuffer;
    /* 8c */ s32 mSlotIndex;
    /* 90 */ s32 field90;
    /* 94 */ s32 mUncompressSource;
    /* 98 */ s32 field98;
    /* 9c */ s32 field9C;
} ArchiveLoadRequest;

typedef struct Unk021759c8 {
    union {
        ArchiveSlot field0[20];
        struct {
            /* 00 */ u8 mUnk_00_pad[0xd8];
            /* d8 */ s32 fieldD8;
            /* 0dc */ u8 fieldDC[0x6c];
            /* 148 */ s32 field148;
            /* 14c */ u8 field14C[0x1bc];
            /* 308 */ s32 field308;
            /* 30c */ u8 field30C[0x6c];
            /* 378 */ s32 field378;
            /* 37c */ u8 field37C[0x6c];
            /* 3e8 */ s32 field3E8;
            /* 3ec */ u8 field3EC[0x6c];
            /* 458 */ s32 field458;
            /* 45c */ u8 field45C[0xdc];
            /* 538 */ s32 field538;
            /* 53c */ u8 field53C[0x6c];
            /* 5a8 */ s32 field5A8;
            /* 5ac */ u8 field5AC[0xdc];
            /* 688 */ s32 field688;
            /* 68c */ u8 field68C[0x6c];
            /* 6f8 */ s32 field6F8;
            /* 6fc */ u8 field6FC[0x6c];
            /* 768 */ s32 field768;
            /* 76c */ u8 field76C[0x6c];
            /* 7d8 */ s32 field7D8;
            /* 7dc */ u8 field7DC[0x70];
            /* 84c */ void *field84C;
            /* 850 */ Unk020182c0 field850;
            /* 8b8 */ s32 field8B8;
            /* 8bc */ void *field8BC;
        };
    };
    /* 8c0 */ u32 mFileTableSize;
    /* 8c4 */ void *mFileTable;
    /* 8c8 */ ArchiveLoadRequest field8C8;
    /* 968 */ FSFile mFile;
    /* 9b0 */ ArchiveBuffer mBuffers[16];
    /* a70 */ void *fieldA70;
    /* a74 */ void *fieldA74;
    /* a78 */ NNSiFndHeapHead *fieldA78;
    /* a7c */ NNSiFndHeapHead *mCourseBufferHeap;
    /* a80 */ NNSiFndHeapHead *fieldA80;
} Unk021759c8;

extern Unk021759c8 *gArcData;
extern SceneRunState *scene_sSceneState;
extern Unk021759d0 *gSystemData;

// Object at gFileReadThread: 0x400 bytes (the end of them is the top of the stack of the OSThread) and two words.
typedef struct FileReadThread {
    /* 000 */ u8 mStack[0x400];
    /* 400 */ OSThread mThread;
    /* 4b8 */ u8 field4B8[8];
    /* 4c0 */ s32 field4C0;
    /* 4c4 */ s32 field4C4;
} FileReadThread;

extern FileReadThread gFileReadThread;
extern vu16 data_021758e8[];
extern vu16 data_02175928[];
extern u8 data_02175dd8[];
// Object at gVramWvrStatus: a word and a function pointer.
typedef struct WvrState {
    /* 00 */ volatile s32 field0;
    /* 04 */ s32 (*mCallback)();
} WvrState;

extern WvrState gVramWvrStatus;

// Eight halfwords at g_GlobalHN: two groups of four.
typedef struct Unk021755e4 {
    /* 00 */ u16 field0;
    /* 02 */ u16 field2;
    /* 04 */ u16 field4;
    /* 06 */ u16 field6;
    /* 08 */ u16 field8;
    /* 0a */ u16 fieldA;
    /* 0c */ u16 fieldC;
    /* 0e */ u16 fieldE;
} Unk021755e4;

extern Unk021755e4 g_GlobalHN;

// Object irec_isAlmostAtPlayBufferEnd to irec_startRecording take: a buffer, two halfword counters and two words. The buffer holds a
// word at 0x00 and byte pairs from 0x04; its size is 0xdcc bytes.
extern KeyRecording data_02175650[];

// Entry of the table at 0x440 of gRomArchiveTransfer: a four-bit part in the low bits of the first word, then two
// words.
typedef struct RomArchiveParentViewEntry {
    /* 00 */ u32 field0_0 : 4;
    /* 00 */ u32 field0_4 : 28;
    /* 04 */ s32 field4;
    /* 08 */ u8 *field8;
} RomArchiveParentViewEntry;

// Nine bytes that WFSi_SendAck builds on the stack and passes to RequestSendBytes: two four-bit parts, a
// 24-bit part, a word and a byte.
typedef struct RomArchiveMessage {
    /* 00 */ u32 mKind : 4;
    /* 00 */ u32 mPacketSizeHigh : 4;
    /* 00 */ u32 field0_8 : 24;
    /* 04 */ s32 field4;
    /* 08 */ u8 mPacketSizeLow;
} RomArchiveMessage;

struct RomArchiveFileNode;
struct FSFile;

// Part of gRomArchiveTransfer from 0x440: the table, then nine words at 0x46cc.
typedef struct RomArchiveParentView {
    /* 0000 */ RomArchiveParentViewEntry field0[32];
    /* 0180 */ u8 field180[0x97c];
    /* 0afc */ void *fieldAFC;
    /* 0b00 */ u32 fieldB00;
    /* 0b04 */ u32 fieldB04;
    /* 0b08 */ s32 fieldB08;
    /* 0b0c */ u8 fieldB0C[0x3bb4];
    /* 46c0 */ struct RomArchiveFileNode *mFreeHead;
    /* 46c4 */ struct RomArchiveFileNode *mActiveHead;
    /* 46c8 */ struct RomArchiveFileNode *mPendingHead;
    /* 46cc */ s32 field46CC;
    /* 46d0 */ s32 field46D0;
    /* 46d4 */ BOOL mMessageSendPending;
    /* 46d8 */ s32 field46D8;
    /* 46dc */ s32 field46DC;
    /* 46e0 */ BOOL field46E0;
    /* 46e4 */ s32 field46E4;
    /* 46e8 */ s32 field46E8;
    /* 46ec */ s32 field46EC;
} RomArchiveParentView;

// Object at gRomArchiveTransfer.
typedef struct RomArchiveTransfer {
    /* 0000 */ u32 mIsParent;
    /* 0004 */ BOOL field4;
    /* 0008 */ BOOL mSendPending;
    /* 000c */ s32 mState;
    /* 0010 */ void (*mStateCallback)(s32 a);
    /* 0014 */ void *(*mAllocFunc)(s32 a, u32 b, void *c);
    /* 0018 */ s32 mAllocFuncArg;
    /* 001c */ struct FSFile *mPendingFile;
    /* 0020 */ void *mArchiveBlock;
    /* 0024 */ s32 mArchiveBlockSize;
    /* 0028 */ s32 mParentPacketSize;
    /* 002c */ s32 mChildPacketSize;
    /* 0030 */ u16 mPort;
    /* 0032 */ u8 field32[0xe];
    /* 0040 */ u8 mPacketBuffer[0x400];
    /* 0440 */ RomArchiveParentView field440;
} RomArchiveTransfer;

extern RomArchiveTransfer gRomArchiveTransfer;
extern void (*gFrameCallback)(s32);
extern s32 gRomArchiveStarted;
extern s32 data_02175ea0;
