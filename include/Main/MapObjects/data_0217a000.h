#pragma once

#include "types.h"
#include "Main/MapObjects/map_object_park.h" // RandomState64
#include "code_02004dc0.h" // FSOverlayInfo, FSFile
#include "code_0212d214.h"
#include "os_thread.h"
#include "code_02142eac.h" // ScanExParam, ScanParam, ParentParameter
#include "code_021445e0.h" // WMDataSharingInfo, WMDataSet
#include "code_02147cd8.h" // Vec3s16
#include "code_0214a748.h" // MtxFx44
#include "code_02012b30.h" // MtxFx43
#include "Main/Net/wbt_requests.h"
#include "Main/Kart/point_link_cursor.h" // PosCurve
#include "Main/Kart/shadow_model.h" // ShadowModel
#include "Main/Graphics/nsbmd_render_obj.h" // Nsbmd
#include "Main/Graphics/model_animation.h" // ModelAnimation
#include "code_02003024.h"
#include "Main/Kart/kart_participant_record.h" // ParticipantKartRecord
#include "dwc_account.h" // DWCAccFriendData, DWCAccUserData
#include "Main/Menu/second_menu_scene.h" // StateMachine
#include "Main/Race/data_021759c0.h" // MinuteSecondMillisecondTime
#include "tp.h"
#include "Main/Net/wifi_race_sync_advance.h" // WiFiRaceSyncPacket

// Values of BackupFirstBlock.mSoundMode.
typedef enum { SOUND_MODE_SURROUND, SOUND_MODE_STEREO, SOUND_MODE_HEADPHONES } SoundMode;

// Objects whose layout isn't known yet.
// The 0x100-byte block read and written at backup offset 0.
typedef struct BackupFirstBlock {
    /* 00 */ u8 mUnk_00[0xc];
    /* 0c */ u8 mPlayerName[0x14];
    /* 20 */ u8 mFlags[4];
    /* 24 */ u16 mElo;
    /* 26 */ u8 mCourseGhostBits[0x4];
    /* 2a */ u8 mSlotGhostBits[0x2];
    /* 2c */ u8 mUnk_2c[0x2];
    /* 2e */ u8 mEmblemBlockBits[0x2];
    /* 30 */ u8 mUnk_30[0x1];
    /* 31 */ union {
        u8 mUnk_31;
        struct {
            u8 mHasPlayerName : 1;
            u8 mSoundMode : 2;
            u8 mEmblemOff : 1;
            u8 mLocateFriendOff : 1;
            u8 mUnk_31_5 : 3;
        };
    };
    /* 32 */ u8 mUnk_32[0x2];
    /* 34 */ u32 mTotals[6];
    /* 4c */ DWCAccUserData mUserData;
} BackupFirstBlock;

// The player's saved emblem: a filled flag and the 0x200 emblem bytes.
typedef struct EmblemRecord {
    /* 000 */ u8 mUnk_000[0x4];
    /* 004 */ u8 mFilled : 1;
    /* 005 */ u8 mUnk_005[0x3];
    /* 008 */ u8 mEmblemData[0x200];
} EmblemRecord;

// One Grand Prix record as saved: the time and the character in bit fields, the name whole.
typedef struct PackedGrandPrixRecord {
    /* 00 */ union {
        u32 mUnk_00;
        struct {
            u8 mUnk_00_b0;
            u8 mKartIndex;
            u8 mTotalPoints;
            u8 mGrade;
        };
        struct {
            u32 mFilled : 1;
            u32 mCharacterIndex : 7;
        };
    };
    /* 04 */ union {
        u32 mUnk_04;
        u8 mCupRank;
        struct {
            u32 mUnk_04_0 : 8;
            u32 mMinute : 7;
            u32 mSecond : 7;
            u32 mMillisecond : 10;
        };
    };
    /* 08 */ u8 mName[0x14];
} PackedGrandPrixRecord;

// The saved Grand Prix records: entries by engine class and cup.
typedef struct GrandPrixRecordBlock {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ PackedGrandPrixRecord mRecords[1][8];
} GrandPrixRecordBlock;

// One course time record as saved: the time and the character in bit fields, the name whole.
typedef struct PackedCourseTimeRecord {
    /* 00 */ union {
        u32 mUnk_00;
        struct {
            u32 mFilled : 1;
            u32 mCharacterIndex : 7;
            u32 mMinute : 7;
            u32 mSecond : 7;
            u32 mMillisecond : 10;
        };
    };
    /* 04 */ u8 mKartIndex;
    /* 05 */ u8 mUnk_05[3];
    /* 08 */ u8 mName[0x14];
} PackedCourseTimeRecord;

// The saved course time records: the best times and the best lap, by course.
typedef struct CourseTimeRecordBlock {
    /* 000 */ u8 mUnk_000[4];
    /* 004 */ PackedCourseTimeRecord mRecords[1][0x20];
} CourseTimeRecordBlock;

// One saved mission result: a flag and a seven-bit value.
typedef struct MissionRecord {
    /* 00 */ union {
        u8 mUnk_00;
        struct {
            u8 mFilled : 1;
            u8 mValue : 7;
        };
    };
} MissionRecord;

// What member 0x10 of BackupBuffers points to: bytes from 0x04, read in rows of nine (the count is not shown by the
// code).
typedef struct MissionRecordBlock {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ MissionRecord mRecords[1];
} MissionRecordBlock;

// The first 0x30 bytes of a ghost record.
typedef struct GhostRecordHead {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ union {
        u32 mUnk_04;
        struct {
            u32 mCharacterIndex : 4;
            u32 mKartIndex : 6;
            u32 mCourseId : 6;
            u32 mYear : 7;
            u32 mMonth : 4;
            u32 mDay : 5;
        };
    };
    /* 08 */ union {
        u32 mUnk_08;
        struct {
            u32 mFilled : 1;
            u32 mHasEmblem : 1;
            u32 mRegion : 2;
            u32 mUnk_08_4 : 4;
            u32 mMinute : 7;
            u32 mSecond : 7;
            u32 mMillisecond : 10;
        };
    };
    /* 0c */ u8 mName[0x14];
    /* 20 */ u8 mLapTimes[0xf];
    /* 2f */ union {
        u8 mUnk_2f;
        struct {
            u8 mLowestGrandPrixRecordValue : 2;
        };
    };
} GhostRecordHead;

// One entry of the slot ghost list and of the ghost file list: its head and the emblem; 0x230 bytes each.
typedef struct GhostListEntry {
    /* 000 */ GhostRecordHead mHead;
    /* 030 */ u8 mEmblem[0x200];
} GhostListEntry;

// The 0xe00 bytes behind member 0x14 of BackupBuffers.
typedef struct GhostRecord {
    /* 000 */ GhostRecordHead mHead;
    /* 030 */ u8 mKeyRecordingBuffer[0xdd0];
} GhostRecord;

// The 0x1000 bytes behind members 0x18 and 0x1c of BackupBuffers.
typedef struct SlotGhostRecord {
    /* 000 */ GhostRecordHead mHead;
    /* 030 */ u8 mEmblem[0x200];
    /* 230 */ u8 mKeyRecordingBuffer[0xdcc];
} SlotGhostRecord;

// One buddy: counts per kind of match, the date of the last result, the name and four flags; 60 entries from 0x04 of
// BuddyRecordBlock.
typedef struct BuddyRecord {
// Two counters for each of three kinds of match (VS, Battle and a third kind), each raised by one at the end of a
// race.
    /* 00 */ u16 mResultCounts[3][2];
    /* 0c */ union {
        u16 mDate;
        struct {
            u16 mYear : 7;
            u16 mMonth : 4;
            u16 mDay : 5;
        };
    };
    /* 0e */ u8 mName[0x14];
    /* 22 */ union {
        u8 mUnk_22;
        struct {
            u8 mFilled : 1;
// Set when the buddy was added by friend key; cleared once the library reports a buddy.
            u8 mNotYetBuddy : 1;
            u8 mHasEmblem : 1;
            u8 mFlagged : 1;
        };
    };
    /* 23 */ u8 mUnk_23;
} BuddyRecord;

// 60 BuddyRecord entries from 0x04, then the 60 buddy friend data of 0xc bytes each from 0x874.
typedef struct BuddyRecordBlock {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ BuddyRecord mRecords[60];
    /* 874 */ DWCAccFriendData mFriendData[60];
} BuddyRecordBlock;

// 0xb00 bytes behind member 0x24 of BackupBuffers: a byte at 0x04 and five 0x200-byte rows from 0x08.
typedef struct EmblemBlockData {
    /* 000 */ u8 mUnk_000[4];
    /* 004 */ u8 mFilledBits;
    /* 005 */ u8 mUnk_005[3];
    /* 008 */ u8 mEmblems[5][0x200];
    /* a08 */ u8 mUnk_a08[0xf8];
} EmblemBlockData;

typedef struct BackupBuffers {
    /* 00 */ BackupFirstBlock *mFirstBlock;
    /* 04 */ EmblemRecord *mEmblemRecord;
    /* 08 */ GrandPrixRecordBlock *mGrandPrixRecordBlock;
    /* 0c */ CourseTimeRecordBlock *mCourseTimeRecordBlock;
    /* 10 */ MissionRecordBlock *mMissionRecordBlock;
    /* 14 */ GhostRecord *mCourseGhostRecord;
    /* 18 */ SlotGhostRecord *mSlotGhostRecords[2];
    /* 20 */ BuddyRecordBlock *mBuddyRecordBlock;
    /* 24 */ EmblemBlockData *mEmblemBlockData;
    /* 28 */ u8 mBusy;
    /* 29 */ u8 mUnk_29;
    /* 2a */ u16 mFailedBlockBits;
    /* 2c */ s32 mReadStatus;
    /* 30 */ u8 mParticipantAndBits[4];
    /* 34 */ u8 mParticipantOrBits[4];
    /* 38 */ u8 mParticipantMaxValue;
    /* 39 */ u8 mParticipantMinValue;
    /* 3a */ u8 mUnk_3a[2];
    /* 3c */ u8 mUnk_3c;
    /* 3d */ u8 mUnk_3d[3];
    /* 40 */ void *mReadDestination;
    /* 44 */ union {
        s32 mUnk_44;
        struct {
            s32 mUnk_44_0 : 1;
        };
    };
} BackupBuffers;

// Object behind member 0x15c4 of ConnectionWork.
typedef struct SharingSendRecord {
    /* 00 */ u16 mPadKeys;
    /* 02 */ u16 mTouchPoint;
    /* 04 */ u8 mLeftParticipantMask;
    /* 05 */ u8 mSendByte;
    /* 06 */ union {
        u8 mUnk_06;
        struct {
            u8 mFlags : 7;
            u8 mMicOverThreshold : 1;
        };
    };
    /* 07 */ u8 mUnk_07;
} SharingSendRecord;

// 8-byte entries from 0x44 of ConnectionWork.
typedef struct ChildEntry {
    /* 00 */ u8 mBytes[6];
    /* 06 */ u16 mAid;
} ChildEntry;

// 0x44 bytes from 0x44 of ConnectionWork.
typedef struct ChildList {
    /* 00 */ ChildEntry mEntries[7];
    /* 38 */ UserGameInfo *mGameInfo;
    /* 3c */ u16 mUnk_3c;
// Next player name to send (0 to 7); 8 to 0x2c count a pause, then it restarts at 0.
    /* 3e */ u16 mNameSendIndex;
    /* 40 */ u8 mChildCount;
    /* 41 */ s8 mDisconnectingIndex;
    /* 42 */ u8 mExpectedRecordMask;
    /* 43 */ u8 mChildMask;
} ChildList;

// 8-byte entries behind member 0x1e48 of gConnectionWork.
typedef struct ScanGhostInfo {
    /* 00 */ u8 mKartIndex;
    /* 01 */ u8 mCharacterIndex;
    /* 02 */ u8 mCourseId;
    /* 03 */ u8 mMinute;
    /* 04 */ u8 mSecond;
    /* 05 */ u8 mUnk_05[1];
    /* 06 */ u16 mMillisecond;
} ScanGhostInfo;

// Elements of the array at member 0x1e52 of gConnectionWork.
typedef struct ParticipantPosition {
    /* 00 */ u16 mEntryIndex;
    /* 02 */ u8 mUnk_02[6];
} ParticipantPosition;

// Part of ConnectionWork from 0x1608.
typedef struct MPStateMachine {
    /* 00 */ StateMachine mStateMachine;
    /* 14 */ u16 mChildDataWaitFrames;
    /* 16 */ u16 mEntryWaitFrames;
    /* 18 */ s16 mDelayTimer;
// Only bit 0 is used: set when a chunk may be queued, cleared while one is queued.
    /* 1a */ u8 mChunkSendFlags;
    /* 1b */ u8 mUnk_1b[0x1];
} MPStateMachine;

// Object behind gConnectionWork.
// One of the 12 entries at 0x16a0: a block to offer to the other consoles, or a file path to read in.
typedef struct BlockEntry {
    /* 00 */ WBTBlockInfoList mNode;
// First byte of the 0x40-byte path; 0 means the entry is free.
    /* 34 */ u8 mPath;
    /* 35 */ u8 mUnk_35[0x3f];
    /* 74 */ u32 *mBuffer;
// Where the uncompressed bytes go; nothing sets it, so a block is allocated for them.
    /* 78 */ void *mUncompressedBuffer;
    /* 7c */ void **mDataOutput;
    /* 80 */ void *mHeap;
    /* 84 */ union {
        s32 mUnk_84;
        struct {
            u32 mUnk_84_0 : 29;
            s32 mUncompressPending : 1;
            u32 mUnk_84_30 : 1;
            u32 mUnk_84_31 : 1;
        };
    };
} BlockEntry;

// Members from 0x16a0 of ConnectionWork as one object.
typedef struct BlockTransferView {
    /* 000 */ BlockEntry mBlockEntries[12];
    /* 660 */ s32 mUnk_660;
    /* 664 */ u8 mUnk_664[4];
    /* 668 */ u16 mNextLoadIndex;
    /* 66a */ s16 mUnk_66a;
    /* 66c */ u8 mUnk_66c[0x48];
    /* 6b4 */ u8 mUnk_6b4;
    /* 6b5 */ u8 mUnk_6b5[3];
    /* 6b8 */ void *mCompressedBuffer;
    /* 6bc */ u8 mUnk_6bc[0xdc];
    /* 798 */ BOOL mZeroWordReceived;
    /* 79c */ BOOL mMPSetupActive;
    /* 7a0 */ u16 mGhostBlockCount;
    /* 7a2 */ u16 mUnk_7a2;
    /* 7a4 */ u8 mUnk_7a4;
    /* 7a5 */ s8 mUnk_7a5;
    /* 7a6 */ u8 mUnk_7a6;
    /* 7a7 */ u8 mUnk_7a7[1];
} BlockTransferView;

// 0x22c-byte entries from 0x45c of ConnectionWork; also the tail from 0xc of WiFiPlayerRecord.
typedef struct PlayerRecord {
    /* 000 */ u8 mName[0x14];
    /* 014 */ u8 mEmblem[0x200];
    /* 214 */ u8 mHasEmblem;
    /* 215 */ u8 mUnk_215;
    /* 216 */ s16 mElo;
    /* 218 */ DWCAccFriendData mFriendData;
    /* 224 */ u8 mBits[4];
    /* 228 */ union {
        u8 mUnk_228;
        struct {
            u8 mRegion : 4;
            u8 mLanguageIndex : 4;
        };
    };
    /* 229 */ u8 mLowestGrandPrixRecordValue;
    /* 22a */ u8 mUnk_22a[2];
} PlayerRecord;

// Six bytes, compared and assigned as one object.
typedef struct ScanMacAddress {
    /* 00 */ u8 mBytes[6];
} ScanMacAddress;

// 0xe0-byte entries from 0xac of ConnectionWork.
typedef struct ScanSlot {
    /* 00 */ WMBssDesc mUnk_00;
    /* c0 */ ScanMacAddress mKey;
    /* c6 */ u8 mName[0x14];
    /* da */ u8 mChildCount;
    /* db */ u8 mAge;
    /* dc */ union {
        u8 mUnk_dc;
        struct {
            u8 mInUse : 1;
            u8 mLanguageIndex : 4;
            u8 mMultiBoot : 1;
            u8 mHasGhost : 1;
        };
    };
    /* dd */ u8 mUnk_dd[3];
} ScanSlot;

// The 0x3b0 bytes from 0xac of ConnectionWork as one object: the four entries, then the members up to 0x45c.
typedef struct ScanStateView {
    /* 000 */ ScanSlot mSlots[4];
    /* 380 */ u8 mTargetAddress[6];
    /* 386 */ u8 mUnk_386[2];
    /* 388 */ u16 mSlotCount;
    /* 38a */ u16 mUnk_38a;
    /* 38c */ u8 mTargetRemaining;
    /* 38d */ u8 mChannel;
    /* 38e */ u8 mUnk_38e;
    /* 38f */ s8 mIsRepeat;
    /* 390 */ u8 mUnk_390[0x20];
} ScanStateView;

// 8-byte entries behind member 0xc of DataSharing.
typedef struct SharingReceiveRecord {
    /* 00 */ union {
        u8 mUnk_00[6];
        struct {
            u16 mPadKeys;
            u16 mTouchPoint;
        };
    };
    /* 06 */ union {
        u8 mUnk_06;
        struct {
            u8 mFlags : 7;
            u8 mMicOverThreshold : 1;
        };
    };
    /* 07 */ u8 mUnk_07;
} SharingReceiveRecord;

// Members 0x15bc to 0x1607 of ConnectionWork as one object.
typedef struct DataSharing {
    /* 00 */ WMDataSharingInfo *mUnk_00;
    /* 04 */ WMDataSet *mUnk_04;
    /* 08 */ void *mUnk_08;
    /* 0c */ SharingReceiveRecord *mReceivedRecords;
    /* 10 */ s32 mSharedDataCopied[8];
    /* 30 */ u8 mUnk_30;
    /* 31 */ u8 mUnk_31[3];
    /* 34 */ s32 mSharingPhase;
    /* 38 */ u16 mUnk_38;
    /* 3a */ u8 mParticipantMask;
    /* 3b */ u8 mUnk_3b;
    /* 3c */ u16 mUnk_3c[7];
    /* 4a */ u8 mUnk_4a;
    /* 4b */ u8 mUnk_4b[1];
} DataSharing;

// 8-byte entries from 0x1e4c of ConnectionWork.
typedef struct ParticipantPositionRow {
    /* 00 */ u16 mUnk_00[3];
    /* 06 */ u16 mUnk_06;
} ParticipantPositionRow;

// Members 0x1e4c to 0x1ecf of ConnectionWork as one object.
typedef struct ParticipantTablesView {
    /* 00 */ ParticipantPositionRow mUnk_00[8];
    /* 40 */ u8 mUnk_40[0x20];
    /* 60 */ u8 mLeftParticipantMask;
    /* 61 */ u8 mUnk_61[7];
    /* 68 */ u8 mUnk_68;
    /* 69 */ u8 mUnk_69[0x1b];
} ParticipantTablesView;

// Seed, multiplier and increment of a multiply-add generator, each as a low word and a high word.
typedef struct RandomState {
    /* 00 */ s32 mStateLow;
    /* 04 */ s32 mStateHigh;
    /* 08 */ s32 mMultiplierLow;
    /* 0c */ s32 mMultiplierHigh;
    /* 10 */ s32 mIncrementLow;
    /* 14 */ s32 mIncrementHigh;
} RandomState;

// Members 0x1658 to 0x169f of ConnectionWork as one object.
typedef struct MultiBootStateView {
    /* 00 */ void *mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ void *mUnk_0c;
    /* 10 */ void *mUnk_10;
    /* 14 */ s32 mChildStateCodes[8];
    /* 34 */ u32 mUnk_34;
    /* 38 */ u16 mUnk_38;
    /* 3a */ u16 mUnk_3a;
    /* 3c */ u8 mUnk_3c;
    /* 3d */ u8 mUnk_3d;
    /* 3e */ u8 mUnk_3e;
    /* 3f */ u8 mUnk_3f;
    /* 40 */ u8 mUnk_40;
    /* 41 */ u8 mUnk_41;
    /* 42 */ s8 mUnk_42;
    /* 43 */ u8 mUnk_43;
    /* 44 */ s32 mUnk_44;
} MultiBootStateView;

// ConnectionWork.mFlags: a block transfer is running.
#define CONNECTION_FLAG_BLOCK_TRANSFER 0x200
// ConnectionWork.mFlags: a message may be queued; cleared while one is queued.
#define CONNECTION_FLAG_SEND_READY 1
// ConnectionWork.mFlags: a rom archive transfer is running.
#define CONNECTION_FLAG_ROM_ARCHIVE_TRANSFER 0x100
// ConnectionWork.mFlags: multiboot setup has started.
#define CONNECTION_FLAG_MULTIBOOT_SETUP 0x40
// ConnectionWork.mFlags: set when UpdateDataSharing returned FALSE.
#define CONNECTION_FLAG_SHARING_NOT_UPDATED 0x10
// ConnectionWork.mFlags: set while a scene runs with a live connection.
#define CONNECTION_FLAG_SCENE_RUNNING 4
// ConnectionWork.mFlags: the connection is a race connection.
#define CONNECTION_FLAG_RACE 8
// ConnectionWork.mFlags: the connection is being ended; cleared when the end finishes.
#define CONNECTION_FLAG_ENDING 0x80
// ConnectionWork.mOperationFlags: a disconnect is running.
#define CONNECTION_OPERATION_DISCONNECTING 2
// ConnectionWork.mOperationFlags: a scan is running.
#define CONNECTION_OPERATION_SCANNING 1
// ConnectionWork.mStatusFlags: data sharing sync finished.
#define CONNECTION_STATUS_SHARING_SYNCED 1
// ConnectionWork.mStatusFlags: the child set changed since the game info was last refreshed.
#define CONNECTION_STATUS_CHILDREN_CHANGED 8
// ConnectionWork.mTransferFlags: the parent transfer callback finished its sequence.
#define CONNECTION_TRANSFER_SEQUENCE_DONE 4
// ConnectionWork.mTransferFlags: the sync wait is done.
#define CONNECTION_TRANSFER_SYNC_DONE 2
// ConnectionWork.mStep: the operation in flight, named after the call that starts it.
typedef enum ConnectionStep {
    CONNECTION_STEP_NOTHING = 0, // nothing in flight
    CONNECTION_STEP_STARTING_UP = 1,
    CONNECTION_STEP_RESTARTING = 2,
    CONNECTION_STEP_SETTING_TIMEOUT = 3,
    CONNECTION_STEP_CHECKING_CHANNELS = 4,
    CONNECTION_STEP_CONFIGURING_HOST = 5,
    CONNECTION_STEP_OPENING_HOST = 6,
    CONNECTION_STEP_SEARCHING = 7,
    CONNECTION_STEP_SEARCHING_UNUSED = 8, // never set
    CONNECTION_STEP_STOPPING_SEARCH = 9,
    CONNECTION_STEP_JOINING = 10,
    CONNECTION_STEP_STARTING_EXCHANGE = 11,
    CONNECTION_STEP_SETTING_EXCHANGE_RATE = 12,
    CONNECTION_STEP_REGISTERING_ENTRY = 13,
    CONNECTION_STEP_STARTING_SHARING = 14,
    CONNECTION_STEP_PUBLISHING_GAME_INFO = 15,
    CONNECTION_STEP_DROPPING_CHILDREN = 16,
    CONNECTION_STEP_STOPPING_SHARING = 17,
    CONNECTION_STEP_STOPPING_EXCHANGE = 18,
    CONNECTION_STEP_CLOSING_HOST = 19,
    CONNECTION_STEP_LEAVING = 20,
    CONNECTION_STEP_SHUTTING_DOWN = 21,
    CONNECTION_STEP_MULTIBOOT_START_PARENT = 22,
    CONNECTION_STEP_MULTIBOOT_UNUSED = 23, // never set
    CONNECTION_STEP_MULTIBOOT_SEND_TO_CHILDREN = 24,
    CONNECTION_STEP_MULTIBOOT_BOOT_REQUEST = 25,
    CONNECTION_STEP_MULTIBOOT_READ_PARENT_DESC = 26,
    CONNECTION_STEP_MULTIBOOT_END_TO_IDLE = 27,
    CONNECTION_STEP_SCAN_CONNECT_SETUP = 28,
    CONNECTION_STEP_SCAN_CONNECT_REPEATED_SCAN = 29,
    CONNECTION_STEP_SCAN_CONNECT_FIND_ENTRY = 30,
    CONNECTION_STEP_SCAN_CONNECT_CLOSE = 31,
    CONNECTION_STEP_SCAN_CONNECT_CLOSED = 32, // set once the wait after CONNECTION_STEP_SCAN_CONNECT_CLOSE has passed
    CONNECTION_STEP_SCAN_CONNECT_END_SCAN = 33,
    CONNECTION_STEP_SCAN_CONNECT_CONNECT_ENTRY = 34,
    CONNECTION_STEP_SCAN_CONNECT_READ_PARENT_DESC = 35,
    CONNECTION_STEP_ROM_ARCHIVE_TRANSFER = 36,
    CONNECTION_STEP_ROM_ARCHIVE_SEND = 37,
    CONNECTION_STEP_ROM_ARCHIVE_STOP = 38,
    CONNECTION_STEP_CHILD_ARCHIVE_SYNC = 39,
    CONNECTION_STEP_PARENT_BLOCK_TRANSFER = 40,
    CONNECTION_STEP_CHILD_BLOCK_TRANSFER = 41,
    CONNECTION_STEP_BLOCK_COUNT_REQUEST = 42,
    CONNECTION_STEP_BLOCK_NODE_REQUEST = 43,
    CONNECTION_STEP_BLOCK_DATA_REQUEST = 44,
    CONNECTION_STEP_STOPPING_BLOCK_TRANSFER = 45,
    CONNECTION_STEP_SEND_WORD_REQUEST = 46,
} ConnectionStep;

// ConnectionWork.mState.
typedef enum ConnectionState {
    CONNECTION_STATE_IDLE = 0,
    CONNECTION_STATE_STARTING = 1,
    CONNECTION_STATE_MULTIBOOT_PARENT_READY = 2,
    CONNECTION_STATE_MULTIBOOT_SCAN_READY = 3,
    CONNECTION_STATE_SETUP_SPARE = 4, // never set
    CONNECTION_STATE_MULTIBOOT_PARENT_ACTIVE = 5,
    CONNECTION_STATE_CONNECTED = 6,
    CONNECTION_STATE_SYNC_WAIT = 7,
    CONNECTION_STATE_SYNCED = 8,
    CONNECTION_STATE_SYNCED_RACE = 9,
    CONNECTION_STATE_ENTRY_EXCHANGE = 10,
    CONNECTION_STATE_GATHERING = 11,
    CONNECTION_STATE_MP_ENDING = 12,
    CONNECTION_STATE_ENDED = 13,
} ConnectionState;

// ConnectionWork.mErrorCode; CONNECTION_ERROR_NONE means no error is pending.
typedef enum ConnectionError {
    CONNECTION_ERROR_DISCONNECTED = 0,
    CONNECTION_ERROR_RESET_FAILED = 1,
    CONNECTION_ERROR_MP_FAILED = 2,
    CONNECTION_ERROR_NO_CHANNEL = 3,
    CONNECTION_ERROR_CONNECT_FAILED = 5,
    CONNECTION_ERROR_COMMUNICATION_LOST = 7,
    CONNECTION_ERROR_OPERATION_FAILED = 8,
    CONNECTION_ERROR_NONE = 9,
} ConnectionError;

// ConnectionWork.mConnectionMode.
typedef enum ConnectionMode {
    CONNECTION_MODE_NONE = 0,
    CONNECTION_MODE_PARENT = 1,
    CONNECTION_MODE_CHILD = 2,
} ConnectionMode;

// ConnectionWork.mSyncState values: the handshake that ends when parent and children have finished a shared step.
// The parent goes START, WAIT_CHILDREN, ANNOUNCE, DONE; a child goes START, LOAD, LOAD_WAIT, REPORT, DONE.
enum {
    CONNECTION_SYNC_START,
    CONNECTION_SYNC_DONE,
    CONNECTION_SYNC_CHILD_LOAD,
    CONNECTION_SYNC_CHILD_LOAD_WAIT,
    CONNECTION_SYNC_CHILD_REPORT = 5,
    CONNECTION_SYNC_PARENT_WAIT_CHILDREN,
    CONNECTION_SYNC_PARENT_ANNOUNCE,
};

typedef struct ConnectionWork {
    /* 0000 */ u32 mConnectionMode;
    /* 0004 */ s32 mState;
    /* 0008 */ s32 mErrorCode;
    /* 000c */ s32 mStep;
    /* 0010 */ s32 mRequestPending;
    /* 0014 */ void *mWmWorkBuffer;
    /* 0018 */ ParentParameter *mParentParameter;
    /* 001c */ ScanParam *mScanParams;
    /* 0020 */ ScanExParam *mScanExParams;
    /* 0024 */ WMBssDesc *mParentBssDesc;
    /* 0028 */ void *mScanBssDescBuffer;
    /* 002c */ void *mScanExBuffer;
    /* 0030 */ s32 mStartMPSendBufferSize;
    /* 0034 */ void *mStartMPSendBuffer;
    /* 0038 */ s32 mStartMPReceiveBufferSize;
    /* 003c */ void *mStartMPReceiveBuffer;
    /* 0040 */ void *mMPDataBuffer;
    /* 0044 */ ChildList mChildren;
    /* 0088 */ s8 mParentChannel;
    /* 0089 */ union {
        u8 mMeasureProgress;
        struct {
            u8 mMeasureCount : 4;
            u8 mMeasurePass : 4;
        };
    };
    /* 008a */ u8 mRemovedChildMask;
    /* 008b */ u8 mStatusFlags;
    /* 008c */ s16 mChannelSums[0xe];
    /* 00a8 */ u8 mUnk_00a8[4];
    /* 00ac */ union {
        struct {
            /* 00ac */ ScanSlot mScanSlots[4];
            /* 042c */ ScanMacAddress mRememberedScanKey;
            /* 0432 */ u16 mOwnIndex;
            /* 0434 */ u16 mUnk_0434;
            /* 0436 */ u16 mOperationFlags;
            /* 0438 */ u8 mRememberedScanKeyHeld;
            /* 0439 */ u8 mUnk_0439;
            /* 043a */ u8 mExpectedRecordMask;
            /* 043b */ s8 mKeepScanning;
            /* 043c */ u8 mLanguageIndex;
            /* 043d */ u8 mReceivedNameMask;
            /* 043e */ u8 mUnk_043e[0x2];
            /* 0440 */ s32 (*mScanResultCallback)();
            /* 0444 */ s32 (*mScanFilterCallback)();
            /* 0448 */ void (*mConnectedCallback)();
            /* 044c */ void (*mConnectFailedCallback)();
            /* 0450 */ void (*mDisconnectedCallback)();
            /* 0454 */ u16 mFlags;
            /* 0456 */ union {
                u8 mUnk_0456;
                struct {
                    u8 mUnk_0456_0 : 1;
                };
            };
            /* 0457 */ u8 mGroupSendMask;
            /* 0458 */ u8 mUnk_0458;
            /* 0459 */ u8 mUnk_0459[3];
        };
        ScanStateView mScanState;
    };
    /* 045c */ PlayerRecord mPlayerRecords[8];
    /* 15bc */ union {
        struct {
            /* 15bc */ WMDataSharingInfo *mSharingInfo;
            /* 15c0 */ WMDataSet *mSharingDataSet;
            /* 15c4 */ SharingSendRecord *mSharingSendRecord;
            /* 15c8 */ SharingReceiveRecord *mSharingReceiveRecords;
            /* 15cc */ s32 mUnk_15cc;
            /* 15d0 */ u8 mUnk_15d0[0x1c];
            /* 15ec */ u8 mSyncToggle;
            /* 15ed */ u8 mUnk_15ed[0x3];
            /* 15f0 */ s32 mSharingStepResult;
            /* 15f4 */ u16 mUnk_15f4;
            /* 15f6 */ u8 mParticipantMask;
            /* 15f7 */ u8 mDataSharingSendByte;
            /* 15f8 */ u16 mUnk_15f8[7];
            /* 1606 */ u8 mArrivedMemberMask;
            /* 1607 */ u8 mUnk_1607[0x1];
        };
        DataSharing mDataSharing;
    };
    /* 1608 */ MPStateMachine mMPStateMachine;
    /* 1624 */ void *mChunkBuffer;
    /* 1628 */ u8 mEntryChunkIndex;
    /* 1629 */ u8 mEntryChunkSlot;
    /* 162a */ u8 mRecordReceivedMask;
    /* 162b */ u8 mUnk_162b[0x1];
    /* 162c */ u8 *mChunkReceivedFlags[8];
    /* 164c */ u8 mNamesStoredMask;
    /* 164d */ u8 mBitsReceivedMask;
    /* 164e */ u8 mPlayerSendIndex;
    /* 164f */ u8 mCallbackFailed;
    /* 1650 */ void *mCourseId;
    /* 1654 */ void *mMode;
    /* 1658 */ union {
        struct {
            /* 1658 */ void *mMultiBootSegment;
            /* 165c */ void *mMultiBootWork;
            /* 1660 */ s32 mMultiBootWorkSize;
            /* 1664 */ void *mAllocHeap;
            /* 1668 */ void *mMultiBootScratchBuffer;
            /* 166c */ s32 mUnk_166c;
            /* 1670 */ u8 mUnk_1670[0x1c];
            /* 168c */ u32 mMultiBootSegmentSize;
            /* 1690 */ u16 mParentTgid;
            /* 1692 */ u16 mStepWaitFrames;
            /* 1694 */ u8 mMultiBootRequestFlags;
            /* 1695 */ u8 mMultiBootChildMask;
            /* 1696 */ u8 mWaitToSendMask;
            /* 1697 */ u8 mSendCompleteMask;
            /* 1698 */ u8 mBootRequestDoneMask;
            /* 1699 */ u8 mWaitToSendCount;
            /* 169a */ s8 mScanEntryIndex;
            /* 169b */ u8 mUnk_169b[0x1];
            /* 169c */ s32 mScanConnected;
        };
        MultiBootStateView mMultiBootState;
    };
    /* 16a0 */ union {
        struct {
            /* 16a0 */ BlockEntry mBlockEntries[12];
            /* 1d00 */ s32 mConnectionKind;
            /* 1d04 */ void *mHeap;
            /* 1d08 */ u16 mNextLoadIndex;
            /* 1d0a */ u16 mUnk_1d0a;
            /* 1d0c */ FSFile mFile;
            /* 1d54 */ u8 mSyncDoneChildMask;
            /* 1d55 */ u8 mUnk_1d55[0x3];
            /* 1d58 */ void *mCompressedBuffer;
            /* 1d5c */ s16 mBlockIndex;
            /* 1d5e */ u16 mBlockCount;
            /* 1d60 */ u32 *mCurrentBlockBuffer;
            /* 1d64 */ u8 mUnk_1d64[0x3c];
            /* 1da0 */ WBTBlockInfo *mBlockInfos[16];
            /* 1de0 */ void *mChunkBitmaps[16];
            /* 1e20 */ void *mMPSendBuffer;
            /* 1e24 */ void *mMPReceiveBuffer;
            /* 1e28 */ s32 mMPSendBufferSize;
            /* 1e2c */ s32 mMPReceiveBufferSize;
            /* 1e30 */ u8 *mPacketBuffer;
            /* 1e34 */ s32 mSyncState;
            /* 1e38 */ s32 mZeroWordReceived;
            /* 1e3c */ s32 mMPSetupActive;
            /* 1e40 */ u16 mGhostBlockCount;
            /* 1e42 */ u16 mSendTimer;
            /* 1e44 */ u8 mTransferFlags;
            /* 1e45 */ s8 mSelectedScanEntry;
            /* 1e46 */ u8 mParentTransferStep;
            /* 1e47 */ u8 mUnk_1e47[0x1];
            /* 1e48 */ ScanGhostInfo *mScanGhostInfos;
            /* 1e4c */ union {
                struct {
                    /* 1e4c */ u16 mUnk_1e4c;
                    /* 1e4e */ u8 mUnk_1e4e[0x4];
                    /* 1e52 */ ParticipantPosition mParticipantPosByIndex[7];
                    /* 1e8a */ u16 mUnk_1e8a;
                    /* 1e8c */ u16 mParticipantIndexByPos[8];
                    /* 1e9c */ u16 mParticipantIndices[8];
                    /* 1eac */ u8 mLeftParticipantMask[4];
                    /* 1eb0 */ s32 mRaceSeed;
                    /* 1eb4 */ u8 mUnk_1eb4[4];
                    /* 1eb8 */ RandomState mRandom;
                };
                ParticipantTablesView mParticipantTables;
            };
            /* 1ed0 */ s32 mUnk_1ed0;
            /* 1ed4 */ u16 mUnk_1ed4;
            /* 1ed6 */ u16 mUnk_1ed6;
            /* 1ed8 */ s32 mUnk_1ed8;
            /* 1edc */ u16 mUnk_1edc;
            /* 1ede */ u16 mUnk_1ede;
            /* 1ee0 */ u8 mUnk_1ee0[2];
            /* 1ee2 */ u8 mUnk_1ee2[6];
        };
        BlockTransferView mBlockTransfer;
    };
    /* 1ee8 */ RandomState64 mRandomState;
} ConnectionWork;

extern ConnectionWork *gConnectionWork;

static inline ParticipantPosition *GetParticipantPosByIndex(u16 index) {
    return &gConnectionWork->mParticipantPosByIndex[index];
}

static inline u16 GetParticipantIndexByPos(u16 index) {
    return gConnectionWork->mParticipantIndexByPos[index];
}

static inline PlayerRecord *GetPlayerRecord(u16 index) {
    return &gConnectionWork->mPlayerRecords[index];
}
// Object behind gThreadFunctionQueue; the OSThread at 0x2c is passed to OS_CreateThread and OS_WakeupThreadDirect.
typedef struct ThreadFunctionQueue {
    /* 00 */ void (*mFunctions[10])(void);
    /* 28 */ u8 mNewestIndex;
    /* 29 */ u8 mUnk_29[3];
    /* 2c */ OSThread mThread;
    /* ec */ u8 mUnk_ec[8];
    /* f4 */ void *mThreadStack;
    /* f8 */ s32 mRunRequested;
} ThreadFunctionQueue;

// 0xc-byte entries from 0x08 of OverlayLoader.
typedef struct OverlayLoaderEntry {
    /* 00 */ s32 mOverlayId;
    /* 04 */ u32 mStart;
    /* 08 */ u32 mEnd;
} OverlayLoaderEntry;

struct NNSiFndHeapHead;

// Object behind gOverlayLoader; UpdateWiFiSession reads the word at 0. The objects at 0x2c and 0x58 are passed to
// FS_StartOverlay and FS_InitFile, the pointer at 0xa4 to NNS_FndDestroyExpHeap.
typedef struct OverlayLoader {
    /* 00 */ s32 mCurrentOverlay;
    /* 04 */ s32 mLoadState;
    /* 08 */ OverlayLoaderEntry mEntries[3];
    /* 2c */ FSOverlayInfo mInfo;
    /* 58 */ FSFile mFile;
    /* a0 */ struct NNSiFndHeapHead *mFrmHeap;
    /* a4 */ void *mExpHeap;
    /* a8 */ u32 mLowestStart;
    /* ac */ u32 mHighestEnd;
} OverlayLoader;

#define WIFI_RACE_SYNC_PARTICIPANT_COUNT 4
// Probe replies are collected until a peer has this many samples.
#define WIFI_RACE_SYNC_SAMPLE_COUNT 12
// Bytes of the record that is sent, of a probe packet body, and of the send buffer with its 4-byte packet header.
#define WIFI_RACE_SYNC_RECORD_SIZE 0x68
#define WIFI_RACE_SYNC_PROBE_SIZE 0x28
#define WIFI_RACE_SYNC_SEND_BUFFER_SIZE 0x6c
// Bits of WiFiRaceSync.mFlags.
#define WIFI_RACE_SYNC_FLAG_SENDING 0x4
#define WIFI_RACE_SYNC_FLAG_PEERS_SYNCED 0x100
#define WIFI_RACE_SYNC_FLAG_IDLE_DISCONNECT_SENT 0x200
// Frames without pad input before the idle disconnect, calls without a packet before a peer counts as dropped (600
// while it has no sample), and rejected probe replies before a peer is dropped.
#define WIFI_RACE_SYNC_IDLE_FRAMES 0x708
#define WIFI_RACE_SYNC_TIMEOUT_FRAMES 300
#define WIFI_RACE_SYNC_FIRST_TIMEOUT_FRAMES 600
#define WIFI_RACE_SYNC_MAX_REJECTED_SAMPLES 0x40
// Kart progress word of a participant: bits 0 to 18 time or start rank, 19 to 21 lap count, 22 still racing, 23 to 26
// mask of the participants that finished, and the value a dropped participant gets in the high bits.
#define WIFI_RACE_SYNC_PROGRESS_TIME_MASK 0x7ffff
#define WIFI_RACE_SYNC_PROGRESS_DID_NOT_FINISH 0x7ffff
#define WIFI_RACE_SYNC_PROGRESS_SORT_KEY_MASK 0x3fffff
#define WIFI_RACE_SYNC_PROGRESS_LAPS_MASK 0x380000
#define WIFI_RACE_SYNC_PROGRESS_LAPS_SHIFT 19
#define WIFI_RACE_SYNC_PROGRESS_RACING_MASK 0x400000
#define WIFI_RACE_SYNC_PROGRESS_RACING_SHIFT 22
#define WIFI_RACE_SYNC_PROGRESS_FINISHED_MASK 0x7800000
#define WIFI_RACE_SYNC_PROGRESS_FINISHED_SHIFT 23
#define WIFI_RACE_SYNC_PROGRESS_DROPPED 0x700000

#define ITEM_DATA_SLOT_COUNT 16
// Bytes of ItemDataSlot.mData, and of all item data in one record.
#define ITEM_DATA_SLOT_BUFFER_SIZE 20
#define ITEM_DATA_BYTES 0x30
// Values of ItemDataSlot.mState: free, its data goes out in every record, no longer sent but not yet free.
#define ITEM_DATA_SLOT_STATE_FREE 0
#define ITEM_DATA_SLOT_STATE_SENDING 1
#define ITEM_DATA_SLOT_STATE_SENT 2
// Sync frames a slot is sent for, and kept after that.
#define ITEM_DATA_SLOT_SEND_FRAMES 0x28
#define ITEM_DATA_SLOT_KEEP_FRAMES 30
// ItemDataSlot.mItemKind of a slot that holds nothing; also the header byte sent for it.
#define ITEM_DATA_KIND_NONE 15
// Header byte of a slot in a record: item kind in bits 0 to 4, message kind in bits 5 to 7.
#define ITEM_DATA_HEADER_KIND_MASK 0x1f
#define ITEM_DATA_HEADER_MESSAGE_KIND_MASK 0xe0
#define ITEM_DATA_HEADER_MESSAGE_KIND_SHIFT 5

// Item info index meaning no item, in SlotResultSyncState.
#define SLOT_RESULT_SYNC_NO_ITEM 0x13
// Values of SlotResultSyncState.mState and SlotResultSyncHalfword.mState.
#define SLOT_RESULT_SYNC_STATE_IDLE 0
#define SLOT_RESULT_SYNC_STATE_SENDING 2
#define SLOT_RESULT_SYNC_STATE_COPY_TO_PENDING 3
#define SLOT_RESULT_SYNC_STATE_WAIT_FOR_END 4
// Sync frames a result is sent for, the sends counted before only the frame count decides, and the frames left below
// which the sending stops.
#define SLOT_RESULT_SYNC_SEND_FRAMES 0x78
#define SLOT_RESULT_SYNC_MAX_SENDS 100
#define SLOT_RESULT_SYNC_CLEAR_FRAMES 20

// 0x38-byte entries from 0x14 of WiFiRaceSync.
typedef struct WiFiRaceSyncPeer {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ s32 mProbeSentTickLow;
    /* 08 */ s32 mProbeSentTickHigh;
    /* 0c */ s32 mProbeReceivedTickLow;
    /* 10 */ s32 mProbeReceivedTickHigh;
    /* 14 */ s32 mReplySentTickLow;
    /* 18 */ s32 mReplySentTickHigh;
    /* 1c */ s32 mReplyReceivedTickLow;
    /* 20 */ s32 mReplyReceivedTickHigh;
    /* 24 */ s32 mUnk_24;
    /* 28 */ u64 mRoundTripTotal;
    /* 30 */ BOOL mProbePending;
    /* 34 */ u8 mSampleCount;
    /* 35 */ u8 mRejectedSampleCount;
    /* 36 */ u8 mKind5SendPhase;
    /* 37 */ u8 mUnk_37;
} WiFiRaceSyncPeer;

// Halfword of the tables at 0x20 of WiFiRaceSyncEntry and WiFiRaceSyncRecord: bits 0 to 6, 7 to 11 and 12 to 13.
typedef struct SlotResultSyncHalfword {
    /* 00 */ union {
        u16 mHalfword;
        struct {
            u16 mFramesRemaining : 7;
            u16 mItemInfoIndex : 5;
            u16 mState : 2;
        };
    };
} SlotResultSyncHalfword;

// The 0x20 bytes from 0x68 of WiFiRaceSyncEntry.
typedef struct SlotResultSyncState {
    /* 00 */ s32 mItemInfoIndex;
    /* 04 */ s32 mPendingItemInfoIndex;
    /* 08 */ s32 mEndSyncFrame;
    /* 0c */ u16 mState;
    /* 0e */ u16 mSendCount;
    /* 10 */ s32 mUnk_10;
    /* 14 */ u16 mUnk_14;
    /* 16 */ u8 mUnk_16[0xa];
} SlotResultSyncState;

// 0x88-byte entries from 0x104 of WiFiRaceSync.
typedef struct WiFiRaceSyncEntry {
    /* 00 */ union {
        s32 mHeaderWord;
        struct {
            u32 mSyncFrames : 24;
        };
    };
    /* 04 */ s32 mProgressWord;
    /* 08 */ ParticipantKartRecord mKartRecord;
    /* 20 */ SlotResultSyncHalfword mSlotResultSyncs[WIFI_RACE_SYNC_PARTICIPANT_COUNT];
    /* 28 */ u8 mItemData[0x40];
    /* 68 */ union {
        struct {
            /* 68 */ s32 mItemInfoIndex;
            /* 6c */ s32 mPendingItemInfoIndex;
            /* 70 */ s32 mEndSyncFrame;
            /* 74 */ u16 mState;
            /* 76 */ u16 mSendCount;
            /* 78 */ s32 mUnk_78;
            /* 7c */ u16 mUnk_7c;
            /* 7e */ u8 mUnk_7e[2];
            /* 80 */ s32 mLastProgressWord;
// Average round trip time to this peer in the unit of mCountdownTimer: mean ticks times 64 / 0x82ea,
// divided by 33 and rounded; 0 without samples.
            /* 84 */ u16 mRoundTripAverage;
            /* 86 */ union {
                u8 mReceivedAndRank;
                struct {
                    u8 mRecordReceived : 1;
                    u8 mRank : 7;
                };
            };
            /* 87 */ u8 mUnk_87;
        };
        SlotResultSyncState mSlotResultSyncState;
    };
} WiFiRaceSyncEntry;

// 0xc-byte entries from 0x324 of WiFiRaceSync.
typedef struct ItemDataSlot {
    /* 00 */ s32 mSendUntilSyncFrame;
    /* 04 */ void *mData;
    /* 08 */ u8 mState;
    /* 09 */ u8 mItemKind;
    /* 0a */ u8 mMessageKind;
    /* 0b */ u8 mDataSize;
} ItemDataSlot;

// 0x68 bytes from 0x04 of what member 0x754 of WiFiRaceSync points to.
typedef struct WiFiRaceSyncRecord {
    /* 00 */ union {
        u32 mHeaderWord;
        u16 mLeadHalfword;
        u8 mHeaderBytes[4];
        struct {
            u32 mSyncFrames : 24;
        };
    };
    /* 04 */ union {
        u32 mProgressWord;
        u8 mCountdownBytes[4];
    };
    /* 08 */ union {
        ParticipantKartRecord mKartRecord;
        // The ticks of a probe packet, which has no kart record.
        u32 mProbeWords[6];
    };
    /* 20 */ SlotResultSyncHalfword mSlotResultSyncs[WIFI_RACE_SYNC_PARTICIPANT_COUNT];
    /* 28 */ u8 mItemDataHeaders[ITEM_DATA_SLOT_COUNT];
    /* 38 */ u8 mItemDataBytes[ITEM_DATA_BYTES];
} WiFiRaceSyncRecord;

// What member 0x754 of WiFiRaceSync points to.
typedef struct WiFiRaceSyncSendBuffer {
    union {
        // The first 0x28 bytes are the packet that goes out.
        WiFiRaceSyncPacket mPacket;
        struct {
            /* 00 */ u8 mPacketHeader[4];
            /* 04 */ WiFiRaceSyncRecord mRecord;
        };
    };
} WiFiRaceSyncSendBuffer;

// Object behind gWiFiRaceSync.
typedef struct WiFiRaceSync {
    /* 000 */ StateMachine mStateMachine;
    /* 014 */ WiFiRaceSyncPeer mPeers[WIFI_RACE_SYNC_PARTICIPANT_COUNT];
    /* 0f4 */ s32 mCountdownDrift;
// Participant the next probe goes to in state 1; the last participant sent to in states 2 and 3.
    /* 0f8 */ u16 mSendParticipantIndex;
    /* 0fa */ u8 mReadyMask;
    /* 0fb */ u8 mSampledMask;
    /* 0fc */ u8 mStartParticipantMask;
    /* 0fd */ u8 mUnk_0fd;
    /* 0fe */ u8 mUnk_0fe[6];
    /* 104 */ WiFiRaceSyncEntry mEntries[WIFI_RACE_SYNC_PARTICIPANT_COUNT];
    /* 324 */ ItemDataSlot mItemDataSlots[ITEM_DATA_SLOT_COUNT];
    /* 3e4 */ ItemDataSlot mReceivedItemDataSlots[ITEM_DATA_SLOT_COUNT][WIFI_RACE_SYNC_PARTICIPANT_COUNT];
    /* 6e4 */ u8 mItemDataHandled[ITEM_DATA_SLOT_COUNT][WIFI_RACE_SYNC_PARTICIPANT_COUNT];
    /* 724 */ u16 mUnusedItemDataBytes;
    /* 726 */ u8 mUnk_726[0x2];
// Counted by AdvanceWiFiRaceSyncFrames, one per call, only in states 4 and 5.
    /* 728 */ s32 mSyncFrames;
    /* 72c */ BOOL mFinishRecorded;
    /* 730 */ u8 mUnk_730[0x4];
    /* 734 */ u16 mCountdownSendIndex;
    /* 736 */ s16 mCountdownTimer;
    /* 738 */ u16 mIdleFrames;
    /* 73a */ u8 mRecordSendCursor;
    /* 73b */ u8 mUnk_73b;
    /* 73c */ u8 mUnk_73c[0x1];
    /* 73d */ u8 mUnk_73d;
    /* 73e */ u8 mFinishedMask;
    /* 73f */ u8 mUnk_73f;
// Per participant: calls of RemoveDroppedParticipants since the last packet from it; zeroed on every packet.
    /* 740 */ u16 mTimeoutFrames[WIFI_RACE_SYNC_PARTICIPANT_COUNT];
    /* 748 */ u8 mDroppedParticipantMask;
    /* 749 */ u8 mParticipantMask;
    /* 74a */ u8 mPeerDroppedMasks[WIFI_RACE_SYNC_PARTICIPANT_COUNT];
    /* 74e */ u8 mPeerSharedStates[WIFI_RACE_SYNC_PARTICIPANT_COUNT];
    /* 752 */ u8 mUnk_752[2];
    /* 754 */ WiFiRaceSyncSendBuffer *mSendBuffer;
    /* 758 */ s32 mSharedState;
    /* 75c */ u16 mFlags;
} WiFiRaceSync;

// Per-run state of the race scene, one record behind gRace (0x48 bytes, allocated by InitRace on the scene heap and
// never cleared at the end of the scene): frame counters (mUpdateFrames and three phases derived from it), toon-table
// cycle, fog/fade switch, kind flags derived from gRaceSetup.mRaceKind (also live in the demo and credits kinds 3 to
// 6), a light vector. Not the race setup (gRaceSetup), not the karts.
typedef struct Race {
    // 1 once the race has started, else 0: StartRace sets it when UpdateRaceStartSequence reaches its frame 180, and
    // InitRace sets it at once for the kinds 5 and 6 of RaceSetup.mRaceKind, which have no countdown; IsRaceStarted
    // returns it.
    /* 00 */ s16 mStarted;
    /* 02 */ u8 mUnk_02[2];
    // Counts calls of UpdateRace; in mode 5 held at 128 until mUpdateFramesUnlimited is set
    // (SetRaceUpdateFramesUnlimited).
    /* 04 */ s32 mUpdateFrames;
    // Counts calls of DrawRace; never read (2 writes, 0 reads).
    /* 08 */ s32 mDrawFrames;
    // Value of mUpdateFrames modulo 8 (its low three bits) as of the end of the latest UpdateRace, 0 at set-up; kart
    // and map object code compare it with an index or a limit to act on one frame out of eight.
    /* 0c */ s32 mUpdateFramesMod8;
    // Value of mUpdateFrames modulo 2 as of the end of the latest UpdateRace, 0 at set-up; compared with 0 or with a
    // bit of the object's own flags to act on every second frame.
    /* 10 */ s32 mUpdateFramesMod2;
    // Value of mUpdateFrames modulo RaceSetup.mKartCount as of the end of the latest UpdateRace, 0 at set-up; its one
    // reader uses it as a kart index.
    /* 14 */ s32 mUpdateFramesModKartCount;
    // Start index (0 to 7) of the 32 entries of gToonTable that UpdateRace gives to G3X_SetToonTable on each call;
    // it advances by 1 each time mToonTableFrames passes gToonTableFramesLimit and wraps back to 0 after 7.
    /* 18 */ s32 mToonTableOffset;
    // Counts calls of UpdateRace since mToonTableOffset last changed; when it exceeds gToonTableFramesLimit (2) it
    // restarts at 0 and mToonTableOffset advances (every third call).
    /* 1c */ s32 mToonTableFrames;
    // 1 from the start of a fog fade (StartFadeFog) until UpdateRace ends it, else 0: while it is 1 DrawRace writes
    // the fade fog into the fog registers instead of the course fog. UpdateRace holds it for 72 calls, then steps
    // gFadeFogRemaining from 72 down to 0 in steps of 4 and clears it. DrawRace compares it with mDrawnFadeFog.
    /* 20 */ s32 mFadeFog;
    // The value of mFadeFog that DrawRace last handled; DrawRace writes the fog registers when it differs from
    // mFadeFog, then copies mFadeFog here. StartFadeFog sets it to 0 when it is 1 so that the next DrawRace writes the
    // registers again.
    /* 24 */ s32 mDrawnFadeFog;
    // 1 when RaceSetup.mRaceKind is 3, 4 or 5, else 0. While it is 1, InitRace creates the chain cameras, UpdateRace
    // updates them and takes their view, and DrawRace skips the draw call of DrawKartNameTags. The other readers go
    // through GetRaceUseChainCameras and use it to tell these kinds apart (map objects, balloons, effects, kart
    // set-up).
    /* 28 */ s32 mUseChainCameras;
    // 1 when RaceSetup.mRaceKind is 4: only the first chain camera is created and updated instead of the pair (read
    // only while mUseChainCameras is non-zero).
    /* 2c */ s32 mUseFirstChainCamera;
    // Mode 5 only: set by UpdateRace when mUpdateFrames reaches 128 while mUpdateFramesUnlimited is FALSE; from then on
    // mUpdateFrames stays put until mUpdateFramesUnlimited is set. Never cleared again.
    /* 30 */ BOOL mUpdateFramesLimitReached;
    // Mode 5 only: FALSE at set-up, set by SetRaceUpdateFramesUnlimited (called by UpdateRaceStartSequence when it
    // begins counting); once set, UpdateRace counts mUpdateFrames on every call with no stop at 128.
    /* 34 */ BOOL mUpdateFramesUnlimited;
    /* 38 */ s32 mIsAwardOrStaffRoll;
    // Value of mUpdateFrames when the end handler of the kart of the selected entry (RaceSetup.mEntryIndex) first
    // ran, stored by SetRaceUpdateFramesAtEntryEnd (in mission run mode that is after the end wait); 0 until then.
    /* 3c */ s32 mUpdateFramesAtEntryEnd;
    // x component of the direction of light 0, the vector DrawRaceWorld gives to NNS_G3dGlbLightVector; set at InitRace
    // from gRaceLightVector and by SetRaceLightVector.
    /* 40 */ s16 mLightVectorX;
    // y component of the direction of light 0, the vector DrawRaceWorld gives to NNS_G3dGlbLightVector; set at InitRace
    // from gRaceLightVector and by SetRaceLightVector.
    /* 42 */ s16 mLightVectorY;
    // z component of the direction of light 0, the vector DrawRaceWorld gives to NNS_G3dGlbLightVector; set at InitRace
    // from gRaceLightVector and by SetRaceLightVector.
    /* 44 */ s16 mLightVectorZ;
} Race;

extern Race *gRace;
extern s32 gFadeFogActive;
struct Kind7CameraEntry;

// The viewer of a race: position, look-at point, three axes, view matrix and frustum. One class, several instances:
// gChaseCamera follows the selected kart, gEntryCamera and gFirstChainCamera / gSecondChainCamera step through
// CourseMapCamera entries; gCurrentCamera points at the one used this frame.
// Camera.mCollisionState: neither a length nor an offset is kept.
#define CAMERA_COLLISION_STATE_NONE 3
// Camera.mCollisionState: the hit is kept as a length.
#define CAMERA_COLLISION_STATE_LENGTH 1
// Camera.mCollisionState: the hit is kept as a vector offset.
#define CAMERA_COLLISION_STATE_OFFSET 0
// Values of Camera.mKind.
#define CAMERA_KIND_CHASE 0
#define CAMERA_KIND_ENTRY 1
#define CAMERA_KIND_CHAIN 2
#define CAMERA_KIND_ENTRY_SEQUENCE 3

typedef struct Camera {
    /* 000 */ Vec3 mUp;
    // baseUp x forward, perpendicular to mUp and mForward. Sign not fixed (left or right is not shown); not updated
    // by UpdateCameraViewWithWorldUp.
    /* 00c */ Vec3 mSide;
    /* 018 */ Vec3 mLookAt;
    /* 024 */ Vec3 mPos;
    /* 030 */ MtxFx43 mViewMatrix;
    // Half of the vertical field of view, 0x10000 per turn (top = near * tan). The chase camera eases it toward
    // mHalfFovAngleGoal; entry cameras set the pair mHalfFovPairFirst / mHalfFovPairSecond (sin and cos of the angle)
    // directly.
    /* 060 */ s32 mHalfFovAngle;
    // Default gDefaultHalfFovAngle (0x157c, about 30 degrees).
    /* 064 */ s32 mHalfFovAngleGoal;
    // First and second element of the pair FX_SinCosTable_ holds for mHalfFovAngle; mFrustumTop = mNear * first /
    // second.
    /* 068 */ s16 mHalfFovPairFirst;
    /* 06a */ s16 mHalfFovPairSecond;
    /* 06c */ s32 mAspectRatio;
    /* 070 */ s32 mNear;
    // Far plane of the main projection (course settings value, default 0x640000); mUnk_08c is a second far value.
    /* 074 */ s32 mFar;
    // The four extents handed to G3i_FrustumW_ (top, bottom, left, right), 20.12; shifted by mFrustumShift
    // and a kind-6 entry offset, left and right swapped in mirror mode.
    /* 078 */ s32 mFrustumTop;
    /* 07c */ s32 mFrustumBottom;
    /* 080 */ s32 mFrustumLeft;
    /* 084 */ s32 mFrustumRight;
    // Fraction of the Kart's last-frame movement (mPos - mPrevPos) added to the camera position while
    // KART_DRIVE_RESPAWN_FALL is set in Kart.mDriveFlags; 0x1000 when the camera is placed, times 0xe66/0x1000 per use.
    /* 088 */ s32 mKartMoveScale;
    /* 08c */ s32 mSecondFar;
    /* 090 */ Vec3 mViewLookAt;
    /* 09c */ Vec3 mViewPos;
    /* 0a8 */ Vec3 mPosOffset;
    /* 0b4 */ Vec3 mLookAtOffset;
    // The up vector mUp is built from: eased toward world up (or a kart vector); mUp is made perpendicular to
    // mForward from it.
    /* 0c0 */ Vec3 mBaseUp;
    /* 0cc */ s32 mHeldHeight;
    // Set once the kart is above mHeldHeight; then mHeldHeight eases toward the free y.
    /* 0d0 */ BOOL mHeldHeightEasing;
    /* 0d4 */ s32 mLookAtHeight;
    /* 0d8 */ s32 mUnk_0d8;
    /* 0dc */ s32 mFollowDistance;
    /* 0e0 */ s32 mInitialFollowDistance;
    // Amount the look-at is lowered: +0x1000 per call up to 0xa000 while the Kart has KART_DRIVE_KEYED_PLACEMENT set,
    // else decays; subtracted from the look-at goal y (UpdateChaseCameraLookAt).
    /* 0e4 */ s32 mLookAtLowering;
    /* 0e8 */ s32 mFollowDistanceScale;
    /* 0ec */ s32 mUnk_0ec;
    // 0x1000, or -0x1000 in mode 4 with flag 0x20 of gRaceSetup.mUnk_044.
    /* 0f0 */ s32 mFollowDirectionSign;
    /* 0f4 */ Vec3 mShakeLookAtOffsetGoal;
    /* 100 */ Vec3 mShakePosOffsetGoal;
    /* 10c */ Vec3 mShakeLookAtOffset;
    /* 118 */ Vec3 mShakePosOffset;
    // Third look-at shake term: adds -mShakeLookAtOffset times a per-kind factor (1.25 / 2 / 2.75), halved each call;
    // added to the look-at in UpdateCameraView.
    /* 124 */ Vec3 mShakeLookAtCounterOffset;
    /* 130 */ u8 mShakeKind;
    /* 131 */ u8 mUnk_131[0x3];
    // mPos of the previous frame; the chase step keeps it while a collision push is active.
    /* 134 */ Vec3 mPrevPos;
    // Set by StartCameraWobble, cleared by UpdateCameraWobble when the amplitude is used up.
    /* 140 */ BOOL mWobbling;
    /* 144 */ s32 mFactor;
    /* 148 */ s32 mWobbleAmplitude;
    // Added to mUnk_144 each frame, times mWobbleDirection.
    /* 14c */ s32 mWobblePerFrame;
    /* 150 */ s16 mWobbleDirection;
    /* 152 */ u8 mUnk_152[0x2];
    /* 154 */ s32 mWobbleDecay;
    /* 158 */ s32 mWobbleOffset;
    /* 15c */ Vec3 mForward;
    // Added to the y of the position goal; eased toward a value taken from the Kart's heading y while
    // KART_MOTION_ON_GROUND is set in Kart.mMotionFlags or KART_DRIVE_KEYED_PLACEMENT in Kart.mDriveFlags.
    /* 168 */ s32 mPosGoalYOffset;
    // Eased toward 0, or toward +-0x19000 (sign of Kart.mTurnDirection) while KART_MOTION_DRIFTING is set in
    // Kart.mMotionFlags.
    /* 16c */ s32 mPosGoalKartOffsetScale;
    // Length of the push-out vector while the push is in state 1 of mUnk_254, else 0; mCollisionOffsetLength eases
    // toward it.
    /* 170 */ s32 mCollisionOffsetLengthGoal;
    // Eased mCollisionOffsetLengthGoal; times 3 it shortens the follow distance and raises the position goal
    // (UpdateChaseCameraPos).
    /* 174 */ s32 mCollisionOffsetLength;
    // Added to the eye height of the view only, not to the look-at.
    /* 178 */ s32 mViewPosYOffset;
    // The push-out vector of the collision test (CollideSphereWithCourse) scaled by 3 to 8, kept and eased; added to
    // the position goal.
    /* 17c */ Vec3 mPosGoalCollisionOffset;
    // Kart.mRotationRow0 (a row of the Kart's matrix) times mPosGoalKartOffsetScale; added to the position goal.
    /* 188 */ Vec3 mPosGoalKartOffset;
    /* 194 */ PosCurve mPosCurve;
    /* 1d0 */ PosCurve mReversePosCurve;
    /* 20c */ u16 mUnk_20c;
    /* 20e */ u16 mUnk_20e;
    // Index into gKarts the look-at is taken from (entry cameras; the chase camera is handed its Kart).
    /* 210 */ u16 mFollowedKartIndex;
    /* 212 */ u8 mUnk_212[0x2];
    // Index GetCourseMapCameraIndexAtPos last returned for the followed kart; mCourseMapCamera is the entry actually in
    // use.
    /* 214 */ s32 mLastCourseMapCameraIndex;
    /* 218 */ struct CourseMapCamera *mCourseMapCamera;
    /* 21c */ struct Kind7CameraEntry *mKind7Entries;
    /* 220 */ struct Kind7CameraEntry *mUnk_220;
    /* 224 */ u16 mUnk_224;
    /* 226 */ u8 mUnk_226[0x2];
    // TRUE from StartEntryCameraKind6Entry until mKind6EntryFrames reaches 300 (outside mode 2) or
    // SetEntryCameraUpdateHold replaces the entry. While TRUE the entry is not replaced by the one picked from the
    // Kart's position; in mode 2 TryUpdateEntryCamera steps the entry by its kind on every call and only
    // SetEntryCameraUpdateHold clears it.
    /* 228 */ BOOL mKind6EntryRunning;
    // Counts the calls of TryUpdateEntryCamera outside mode 2 while mKind6EntryRunning is TRUE; at 300 it clears
    // mKind6EntryRunning. Only SetupCamera zeroes it, so it carries over a restart.
    /* 22c */ u16 mKind6EntryFrames;
    /* 22e */ u8 mUnk_22e[0x2];
    // Set to 1 by SetEntryCameraUpdateHold(1), which only does so while the current entry is of kind 5 or 6, and to 0
    // by SetEntryCameraUpdateHold(0) and SetupCamera. While non-zero TryUpdateEntryCamera returns FALSE at once, so the
    // chase camera is shown.
    /* 230 */ s32 mEntryUpdateHold;
    // Set to 1 once by DisableEntryCameraUpdate and never cleared (SetupCamera zeroes it). While set
    // TryUpdateEntryCamera returns FALSE at once, so the chase camera is shown.
    /* 234 */ BOOL mEntryUpdateDisabled;
    // Set to TRUE by StartEntryCameraKind8Entry and never cleared (SetupCamera zeroes it). While set, and after the
    // mEntryUpdateHold and mEntryUpdateDisabled tests, TryUpdateEntryCamera runs UpdateCameraAngleEntry on the current
    // entry and returns TRUE.
    /* 238 */ BOOL mKind8EntryRunning;
    /* 23c */ u16 mCourseMapCameraFrames;
    /* 23e */ u8 mUnk_23e[0x2];
    /* 240 */ s32 mFovBlend;
    /* 244 */ s32 mLookAtBlend;
    // Non-zero while the position y is held at mHeldHeight (set by SetCameraHeightHold for kart state 6).
    /* 248 */ s32 mHeightHold;
    // 0 none; 1 and 2 (gFirstChainCamera / gSecondChainCamera while the entry is kind 4) shift the window of
    // mFrustumTop and mFrustumBottom up or down by 1.3 of its half height (RefreshCameraProjection).
    /* 24c */ s32 mFrustumShift;
    // Which camera this instance is: 0 chase, 1 entry camera, 2 chain camera, 3 entry camera in mode 2 with a kind 7
    // entry; tested by outside code (GetCurrentCameraKind).
    /* 250 */ s32 mKind;
    /* 254 */ s32 mCollisionState;
    /* 258 */ BOOL mCollisionActive;
    /* 25c */ BOOL mCollisionLatch;
    // GetKartForward (row 2 of the Kart's matrix, taken as its heading) of the selected Kart at creation; used instead
    // of the live vector for a Kart with KART_EFFECT_HEADING_SWING set. SetupCamera zeroes it.
    /* 260 */ Vec3 mSavedKartForward;
    /* 26c */ s16 mSideDistanceSign;
    /* 26e */ u8 mUnk_26e[0x2];
} Camera;

extern Camera *gCurrentCamera;
extern u16 gFadeFogColor;
extern u16 gFadeFogFullColor;
extern s16 gCourseFogGreen;
extern u16 gCourseFogColor;
extern s16 gCourseFogBlue;
extern s16 gCourseFogRed;
extern s32 gFadeFogByteBoost;
extern s32 gCourseFogOffset;
extern s32 gFadeFogStepping;
extern s32 gCourseFogAlpha;
extern s32 gCourseFogLastEntry;
extern Camera *gRaceEntryCamera;
extern s32 gFadeFogFullAlpha;
extern s32 gFadeFogAlpha;
extern s32 gFadeFogOffset;
extern void *gGeBuffer;
extern s32 gFadeFogWeight;
extern s32 gCourseFogSlope;
extern s32 gCourseFogWeight;
extern Camera *gRaceChaseCamera;
extern u32 gFadeFogEntryBytes[4];
extern u32 gFadeFogTable[8];
extern u32 gCourseFogTable[8];
extern u16 gToonTable[32];
extern MtxFx43 *gCurrentViewMatrix;
// 0x20-byte entries behind member 0x014 of KartModels.
typedef struct HeyhoPalette {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u16 mColor;
    /* 06 */ u8 mUnk_06[0x1a];
} HeyhoPalette;

// Object behind gKartModels (0x144 bytes); the addresses of 0x2c, 0x98 and 0x10c are passed on as objects.
struct KartModelsEntry;

typedef struct KartModels {
    // Array of the per-kart model entries (0xb4 bytes each), allocated by InitKartModels with mKartCount elements;
    // Kart.mKartModelsEntry points into it.
    /* 000 */ struct KartModelsEntry *mKartModelsEntries;
    /* 004 */ u16 *mCourseColors;
    // Number of elements of mKartModelsEntries, copied from gRaceSetup.mKartCount; the loop bound over the
    // entries.
    /* 008 */ u16 mKartCount;
    /* 00a */ u8 mUnk_00a[2];
    /* 00c */ s32 mKartTireMaterialIndex;
    /* 010 */ u16 *mKartAPalette;
    /* 014 */ HeyhoPalette *mHeyhoPalettes;
    /* 018 */ s16 mHeyhoPaletteIndices[8];
    /* 028 */ void *mPFaceanimNsbtpFile;
    /* 02c */ Nsbmd mKillerItem;
    /* 098 */ ShadowModel mKillerItemS;
    /* 10c */ ModelAnimation mKillerItemNsbca;
} KartModels;

typedef struct ModelAnimation ModelAnimation;
typedef struct KartOffsetData KartOffsetData;

// 0xb8-byte entries from 0x58 of KartModelMenuData.
typedef struct KartModelMenuSlot {
    /* 00 */ s32 mCharacterIndex;
    /* 04 */ s32 mKartIndex;
    /* 08 */ ModelAnimation *mCharacterAnimation;
    /* 0c */ u8 mUnk_0c[4];
    /* 10 */ struct Nsbmd *mCharacterNsbmd;
    /* 14 */ struct Nsbmd *mKartNsbmd;
    /* 18 */ struct Nsbmd *mTireNsbmd;
    /* 1c */ struct ShadowModel *mShadowModel;
    /* 20 */ KartOffsetData *mKartOffsetData;
    /* 24 */ u8 mUnk_24[0x8c];
    /* b0 */ s32 mRegion;
    /* b4 */ struct NNSG3dResTex *mEmblemTex;
} KartModelMenuSlot;

struct NNSG3dResFileHeader;

// 0x34-byte entries from 0x1f4 of KartModelMenuData; the pointers at 0x08 to 0x28 are passed to
// NNS_G3dResDefaultRelease.
typedef struct KartModelMenuFiles {
    /* 00 */ void *mHeapMemory;
    /* 04 */ struct NNSiFndHeapHead *mHeap;
    /* 08 */ struct NNSG3dResFileHeader *mCharacterNsbmdFile;
    /* 0c */ struct NNSG3dResFileHeader *mCharacterNsbtxFile;
    /* 10 */ struct NNSG3dResFileHeader *mEmblemNsbtxFile;
    /* 14 */ void *mCharacterNsbcaFile;
    /* 18 */ struct NNSG3dResFileHeader *mKartNsbmdFile;
    /* 1c */ struct NNSG3dResFileHeader *mKartNsbtxFile;
    /* 20 */ struct NNSG3dResFileHeader *mTireNsbmdFile;
    /* 24 */ struct NNSG3dResFileHeader *mTireNsbtxFile;
    /* 28 */ struct NNSG3dResFileHeader *mKartShadowNsbmdFile;
    /* 2c */ BOOL mLoadRequested;
    /* 30 */ u16 mLoadStep;
    /* 32 */ u8 mUnk_32[2];
} KartModelMenuFiles;

// Six halfwords; the 0xc-byte entries behind member 0x1c of KartModelMenuData.
typedef struct KartMenuParams {
    /* 00 */ u16 mParams[6];
} KartMenuParams;

// Embedded in KartModelMenuData at 0x24 (0x34 bytes).
typedef struct KartModelMenuView {
    /* 00 */ s32 mCharacterIndex;
    /* 04 */ s32 mKartIndex;
    /* 08 */ s32 mScale;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ u16 mSpinAngle;
    /* 16 */ u16 mYawAngle;
    /* 18 */ s16 mTiltAngle;
    /* 1a */ u16 mDrawnTiltAngle;
    /* 1c */ u8 mUnk_1c[0x10];
    /* 2c */ s32 mBg0Offset;
    /* 30 */ s32 mBg0Direction;
} KartModelMenuView;

// Object behind gKartModelMenu.
typedef struct KartModelMenuData {
    /* 000 */ s32 mKartIndex;
    /* 004 */ s32 mKartListPos;
    /* 008 */ s32 mKartListCount;
    /* 00c */ s16 mMenuParams[6];
    /* 018 */ s16 *mCharMenuParams;
    /* 01c */ KartMenuParams *mKartMenuParams;
    /* 020 */ KartModelMenuSlot *mLoadSlot;
    /* 024 */ KartModelMenuView mView;
    /* 058 */ KartModelMenuSlot mSlots[2];
    /* 1c8 */ KartOffsetData *mKartOffsetTable;
    /* 1cc */ struct Nsbmd *mSelectModel;
    /* 1d0 */ void *mKartAPalette;
    /* 1d4 */ void *mEmblemTex;
    /* 1d8 */ s32 mSpinStopped;
    /* 1dc */ BOOL mSpinStopTimed;
    /* 1e0 */ BOOL mUseEmblemTex;
    /* 1e4 */ s32 mMirrorMode;
    /* 1e8 */ void *mEmblemData;
    /* 1ec */ void *mEmblemPalette;
    /* 1f0 */ s16 mSpinStopFrames;
    /* 1f2 */ u8 mUnk_1f2[2];
    /* 1f4 */ KartModelMenuFiles mFiles[2];
    /* 25c */ s32 mCharacterRequested;
    /* 260 */ s32 mKartRequested;
    /* 264 */ s16 mShownSlotIndex;
    /* 266 */ s16 mLoadSlotIndex;
    /* 268 */ struct KartAppear *mKartAppear;
} KartModelMenuData;

struct ParticleEmitter;

// Two objects returned by StartEffect.
typedef struct KartEffectPair {
    union {
        struct {
            /* 00 */ struct ParticleEmitter *mEffect0;
            /* 04 */ struct ParticleEmitter *mEffect1;
        };
        struct ParticleEmitter *mEffects[2];
    };
} KartEffectPair;

// Effect objects of one Kart: the current effect with its id, and further effect objects with the points they are
// placed at. One record per Kart in gKartEffects, indexed by Kart.mIndex. 0x58-byte entries of the table behind
// gKartEffects; the pointers at 0x0c and 0x20 to 0x30 hold objects returned by StartEffect.
typedef struct KartEffects {
    // Id of the effect in mCurrentEffect, -1 when there is none.
    /* 00 */ s32 mCurrentEffectId;
    // Id of the effect running in entry i of mEffectPairs, -1 when there is none; compared with the wanted id to decide
    // whether to start again.
    /* 04 */ s32 mEffectIds[2];
    // The effect object of this Kart started by StartKartCurrentEffect, whose id is mCurrentEffectId (NULL when none).
    /* 0c */ struct ParticleEmitter *mCurrentEffect;
    // The effect objects started for mEffectIds: entry i holds the object of side 0 and the object of side 1 (the byte
    // set in each object is the side number); ids in mEffectIds.
    /* 10 */ KartEffectPair mEffectPairs[2];
    union {
        struct {
            /* 20 */ struct ParticleEmitter *mWaterEffect0;
            /* 24 */ struct ParticleEmitter *mWaterEffect1;
        };
        struct ParticleEmitter *mWaterEffects[2];
    };
    /* 28 */ struct ParticleEmitter *mContactEffect;
    /* 2c */ struct ParticleEmitter *mKillerEffect;
    /* 30 */ struct ParticleEmitter *mSpinFollowEffect;
    // Position in effect units (position / 16) of each side of the Kart: model point 2 or 3 moved by the x offset
    // 0x1800 or -0x1800 of gKartSideOffsetsX, scaled by the Kart scale and transformed by the Kart matrix; written only
    // by ComputeKartSidePoints.
    /* 34 */ Vec3 mSidePositions[2];
    // Direction vector (halfwords) of the effect on each side of the Kart: the vector of gKartSideDirectionVectors for
    // that side rotated by the Kart matrix; written only by ComputeKartSidePoints and read as the direction of the
    // effect object.
    /* 4c */ Vec3s16 mSideDirections[2];
} KartEffects;

struct PointLinkCursor;
struct KartAi;
struct LinkCursor;
struct Kart;
// Three objects per entry, 0xc bytes each.
typedef struct KartStarEffects {
    /* 00 */ struct ParticleEmitter *mEffects[3];
} KartStarEffects;

// Entry of the eight 0xc-byte entries at 0xb0 of KartAiShared: a word, then the links of a list.
typedef struct KartAiTableIndexEntry {
    /* 00 */ s32 mTableIndex;
    /* 04 */ u8 mUnk_04[8];
} KartAiTableIndexEntry;

// One row of 'kartAIparam.bin'.
typedef struct KartAiParamRow {
    /* 00 */ s32 mSpeedLimitAddition;
    /* 04 */ s32 mGapTableScale;
    /* 08 */ s32 mSpeedLimitFloor;
} KartAiParamRow;

// State the CPU kart code shares: per-kart tables, the random generator pointer and the team counts.
// KartAiShared.mPointsGapKind: no large gap, or any mode but Grand Prix.
#define KART_AI_POINTS_GAP_NONE 1
// KartAiShared.mPointsGapKind: the best non-CPU kart is 4 or more points ahead of the best CPU kart (not on easy).
#define KART_AI_POINTS_GAP_NON_CPU_AHEAD 2
// KartAiShared.mPointsGapKind: the best non-CPU kart is 5 or more points behind the best CPU kart (Grand Prix, two
// listed CPU karts).
#define KART_AI_POINTS_GAP_NON_CPU_BEHIND 0
typedef struct KartAiShared {
    /* 000 */ s32 mRaceProgressScaled[8];
    // Kart index at rank n + 1, -1 when no kart has that rank.
    /* 020 */ s32 mKartAtRank[8];
    /* 040 */ s32 mKind1KartByRank[8];
    /* 060 */ s32 mNonCpuKartByRank[8];
    /* 080 */ s32 mLastRankCpuKart;
    /* 084 */ s32 mLastRankNotCpuKart;
    /* 088 */ s32 mFirstRankNotCpuKart;
    /* 08c */ s32 mFirstRankProgressRatio;
    /* 090 */ s32 mTableIndex[8];
    /* 0b0 */ KartAiTableIndexEntry mTableIndexEntries[8];
    /* 110 */ s32 mPointsGapKind;
    /* 114 */ s32 mListedCpuKartPoints[2];
    /* 11c */ s32 mLowerPointsListedCpuIndex;
    /* 120 */ s32 mOneKartNotHumanOrPeer;
    /* 124 */ s16 mNonCpuRank;
    /* 126 */ u8 mUnk_126[2];
    // The race's random generator, or the per-console one in time attack.
    /* 128 */ RandomState64 *mRandom;
    /* 12c */ NNSFndList mTableIndexList;
    /* 138 */ s32 mEngineOrDifficultyIndex;
    /* 13c */ s16 mNonCpuKartCount;
    /* 13e */ s16 mTeamNonCpuKartCounts[3];
} KartAiShared;

struct KartNameTag;

// Object behind gKartNameTags, 0x194 bytes: tables of eight entries.
typedef struct KartNameTags {
    /* 000 */ struct KartNameTag *mNameTagByKart[8];
    /* 020 */ s32 mNameTagCount;
    /* 024 */ s16 mStartOrderIndex[8];
    /* 034 */ s16 mAlongViewOrderOffset[8];
    /* 044 */ u16 mKartIndicesByDistanceAlongView[8];
    /* 054 */ s32 mSortedDistanceAlongView[8];
    /* 074 */ u16 mAlongViewOrderIndex[8];
    /* 084 */ s16 mDistanceSquaredOrderOffset[8];
    /* 094 */ u16 mKartIndicesByDistance[8];
    /* 0a4 */ u32 mSortedDistanceSquared[8];
    /* 0c4 */ struct KartNameTag *mNameTags[8];
    /* 0e4 */ s32 mNameTagBeyondTwoNearest[8];
    /* 104 */ s32 mDistanceAlongViewWithMargin[8];
    /* 124 */ u32 mDistanceSquared[8];
    /* 144 */ void *mEmblemTex[8];
    /* 164 */ void *mEmblemPltt[8];
    /* 184 */ s32 mUnk_184;
    /* 188 */ void *mEmblemPlttData;
    /* 18c */ u8 mUnk_18c[8];
} KartNameTags;

extern struct KartNameTags *gKartNameTags;

static inline void SetKartNameTagSortedDistanceSquared(u16 sortedIndex, u32 distanceSquared) {
    gKartNameTags->mSortedDistanceSquared[sortedIndex] = distanceSquared;
}
extern const char *gKartModelPathPrefix;
extern char gKartModelPathBuffer[];

// Entries of the 0x400-byte buffer behind member 0x04 of DispCap.
typedef struct DispCapOamEntry {
    /* 00 */ u32 mUnk_00;
    /* 04 */ union {
        u32 mUnk_04;
        u16 mUnk_04_h;
    };
} DispCapOamEntry;

// Object behind gDispCap.
typedef struct DispCap {
    /* 00 */ s32 mMode;
    /* 04 */ DispCapOamEntry *mOamBuffer;
    /* 08 */ u16 mFlags;
    /* 0a */ u8 mBlendMin;
    /* 0b */ u8 mUnk_0b[0x1];
    /* 0c */ s32 mBlendFactor;
} DispCap;

// Object behind gRunScenesState, 0x10 bytes.
typedef struct RunScenesState {
    /* 00 */ s32 mKind;
    /* 04 */ s32 mNextKind;
    /* 08 */ s16 mSceneNumber;
    /* 0a */ u8 mUnk_0a[2];
    /* 0c */ void *mSndHeapsBuffer;
} RunScenesState;

// 0xc-byte entries of the array behind member 0x00 of ShapeMapObjectCountList.
typedef struct ShapeMapObjectCount {
    /* 00 */ u16 mShapeIndex;
    /* 02 */ u8 mUnk_02[2];
    /* 04 */ s32 mRadius;
    /* 08 */ u8 mIncreaseCount;
    /* 09 */ u8 mMapObjectCount;
    /* 0a */ u8 mUnk_0a[2];
} ShapeMapObjectCount;

// Object behind gShapeMapObjectCountList, 8 bytes.
typedef struct ShapeMapObjectCountList {
    /* 00 */ ShapeMapObjectCount *mEntries;
    /* 04 */ u16 mEntryCount;
    /* 06 */ u8 mUnk_06[2];
} ShapeMapObjectCountList;

extern u16 gFadeFogHoldFrames;

// Ten bytes: bytes 6 to 9 are signed values read in rows of four.
typedef struct ParticipantKartMap {
    /* 00 */ s8 mParticipantOfKart[4];
    /* 04 */ u8 mParticipantMask;
    /* 05 */ u8 mUnk_05;
    /* 06 */ s8 mKartOfParticipant[4];
} ParticipantKartMap;

extern struct ParticipantKartMap *gParticipantKartMap;

static inline s8 GetParticipantOfKart(u8 kartIndex) {
    return gParticipantKartMap->mParticipantOfKart[kartIndex];
}
// 0xa-byte elements of the rows (eight each) of the table at member 0 of CupRecords.
typedef struct KartCourseResult {
    /* 00 */ u16 mTotalPoints;
    /* 02 */ u8 mCupRank;
    /* 03 */ u8 mRank;
    /* 04 */ u8 mPoints;
    /* 05 */ u8 mWinCount;
    /* 06 */ MinuteSecondMillisecondTime mFinishTime;
} KartCourseResult;

// One team's result for a course: points, win count and a flag. Two make an element of the table at member 0x144 of
// CupRecords.
typedef struct CourseTeamResult {
    /* 00 */ u16 mTotalPoints;
    /* 02 */ u8 mWinCount;
    /* 03 */ union {
        u8 mUnk_03;
        struct {
            u8 mWinning : 1;
        };
    };
} CourseTeamResult;

// 8-byte elements of the table at member 0x144 of CupRecords.
typedef struct CourseTeamResults {
    /* 00 */ CourseTeamResult mTeams[2];
} CourseTeamResults;

// The kart results for each course of a cup, and the team results.
typedef struct CupRecords {
    /* 000 */ KartCourseResult mKartResults[4][8];
    /* 140 */ s32 mScore;
    /* 144 */ CourseTeamResults mTeamResults[4];
    /* 164 */ union {
        u32 mUnk_164;
        struct {
            u32 mUnk_164_0 : 1;
        };
    };
} CupRecords;

extern struct CupRecords *gCupRecords;

static inline KartCourseResult *GetKartCourseResult(u8 course, u8 kartIndex) {
    return &gCupRecords->mKartResults[course][kartIndex];
}

static inline CourseTeamResults *GetCupCourseTeamResults(u8 course) {
    return &gCupRecords->mTeamResults[course];
}

static inline CourseTeamResult *GetCupCourseTeamResult(CourseTeamResults *courseTeams, u32 team) {
    return &courseTeams->mTeams[team];
}
// The event counters of the selected entry's Kart, allocated by InitKarts.
struct EntryKartCounters;

