#pragma once

#include "types.h"
#include "Main/Unknown/code_020d22c0.h" // RandomState64
#include "code_02004dc0.h" // FSOverlayInfo, FSFile
#include "code_0212d214.h"
#include "os_thread.h"
#include "code_02142eac.h" // Unk021438f0, Unk02143a78, Unk02143c30
#include "code_021445e0.h" // WMDataSharingInfo, WMDataSet
#include "code_02147cd8.h" // Vec3s16
#include "code_0214a748.h" // Unk0214ad4c
#include "code_02012b30.h" // MtxFx43
#include "Main/Unknown/code_02006954.h"
#include "Main/Unknown/code_0207b960.h" // PosCurve
#include "Main/Unknown/code_0207adf8.h" // ShadowModel
#include "Main/Unknown/code_020846c0.h" // Nsbmd
#include "Main/Unknown/code_02087d0c.h" // ModelAnimation
#include "code_02003024.h"

// Values of BackupFirstBlock.mSoundMode.
typedef enum { SOUND_MODE_SURROUND, SOUND_MODE_STEREO, SOUND_MODE_HEADPHONES } SoundMode;

// Objects whose layout isn't known yet.
// The 0x100-byte block read and written at backup offset 0.
typedef struct BackupFirstBlock {
    /* 00 */ u8 field0[0xc];
    /* 0c */ u8 mPlayerName[0x14];
    /* 20 */ u8 mFlags[4];
    /* 24 */ u16 mElo;
    /* 26 */ u8 mCourseGhostBits[0x4];
    /* 2a */ u8 mSlotGhostBits[0x2];
    /* 2c */ u8 field2C[0x5];
    /* 31 */ union {
        u8 field31;
        struct {
            u8 field31_0 : 1;
            u8 mSoundMode : 2;
            u8 field31_3 : 1;
            u8 mLocateFriendOff : 1;
            u8 field31_5 : 3;
        };
    };
    /* 32 */ u8 field32[0x2];
    /* 34 */ u32 field34[6];
    /* 4c */ u8 mUserData[0x4];
    /* 50 */ s32 field50;
    /* 54 */ s32 field54;
    /* 58 */ s32 field58;
    /* 5c */ u8 field5C[0xc];
    /* 68 */ s32 field68;
    /* 6c */ u8 field6C[0x4];
    /* 70 */ s32 field70;
    /* 74 */ u8 field74[0x18];
} BackupFirstBlock;

// The player's saved emblem: a filled flag and the 0x200 emblem bytes.
typedef struct EmblemRecord {
    /* 000 */ u8 field0[0x4];
    /* 004 */ u8 mFilled : 1;
    /* 005 */ u8 field5[0x3];
    /* 008 */ u8 mEmblemData[0x200];
} EmblemRecord;

// One Grand Prix record as saved: the time and the character in bit fields, the name whole.
typedef struct PackedGrandPrixRecord {
    /* 00 */ union {
        u32 field0;
        u8 mUnk_00_b[4];
        struct {
            u32 mFilled : 1;
            u32 mCharacterIndex : 7;
        };
    };
    /* 04 */ union {
        u32 field4;
        u8 mUnk_04_b[4];
        struct {
            u32 field4_0 : 8;
            u32 mMinute : 7;
            u32 mSecond : 7;
            u32 mMillisecond : 10;
        };
    };
    /* 08 */ u8 mName[0x14];
} PackedGrandPrixRecord;

// The saved Grand Prix records: entries by engine class and cup.
typedef struct GrandPrixRecordBlock {
    /* 00 */ u8 field0[4];
    /* 04 */ PackedGrandPrixRecord mRecords[1][8];
} GrandPrixRecordBlock;

// One course time record as saved: the time and the character in bit fields, the name whole.
typedef struct PackedCourseTimeRecord {
    /* 00 */ union {
        u32 field0;
        struct {
            u32 mFilled : 1;
            u32 mCharacterIndex : 7;
            u32 mMinute : 7;
            u32 mSecond : 7;
            u32 mMillisecond : 10;
        };
    };
    /* 04 */ u8 mKartIndex;
    /* 05 */ u8 field5[3];
    /* 08 */ u8 mName[0x14];
} PackedCourseTimeRecord;

// The saved course time records: the best times and the best lap, by course.
typedef struct CourseTimeRecordBlock {
    /* 000 */ u8 field0[4];
    /* 004 */ PackedCourseTimeRecord mRecords[1][0x20];
} CourseTimeRecordBlock;

// One saved mission result: a flag and a seven-bit value.
typedef struct MissionRecord {
    /* 00 */ union {
        u8 field0;
        struct {
            u8 mFilled : 1;
            u8 field0_1 : 7;
        };
    };
} MissionRecord;

// What member 0x10 of Unk0217aa08 points to: bytes from 0x04, read in rows of nine (the count is not shown by the
// code).
typedef struct MissionRecordBlock {
    /* 00 */ u8 field0[4];
    /* 04 */ MissionRecord mRecords[1];
} MissionRecordBlock;

// The 0xe00 bytes behind members 0x14 and 0x18 of Unk0217aa08.
typedef struct GhostRecord {
    /* 00 */ u8 field0[4];
    /* 04 */ union {
        u32 field4;
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
        u32 field8;
        struct {
            u32 mFilled : 1;
            u32 field8_1 : 1;
            u32 field8_2 : 2;
            u32 field8_4 : 4;
            u32 mMinute : 7;
            u32 mSecond : 7;
            u32 mMillisecond : 10;
        };
    };
    /* 0c */ u8 mName[0x14];
    /* 20 */ u8 mLapTimes[0xf];
    /* 2f */ union {
        u8 field2F;
        struct {
            u8 field2F_0 : 2;
        };
    };
    /* 30 */ u8 field30[0xdd0];
} GhostRecord;

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
        u8 field22;
        struct {
            u8 mFilled : 1;
// Set when the buddy was added by friend key; cleared once the library reports a buddy.
            u8 mNotYetBuddy : 1;
            u8 field22_2 : 1;
            u8 mFlagged : 1;
        };
    };
    /* 23 */ u8 field23;
} BuddyRecord;

// 60 BuddyRecord entries from 0x04, then the 60 buddy friend data of 0xc bytes each from 0x874.
typedef struct BuddyRecordBlock {
    /* 00 */ u8 field0[4];
    /* 04 */ BuddyRecord mRecords[1];
} BuddyRecordBlock;

// 0xb00 bytes behind member 0x24 of Unk0217aa08: a byte at 0x04 and five 0x200-byte rows from 0x08.
typedef struct EmblemBlockData {
    /* 000 */ u8 field0[4];
    /* 004 */ u8 mFilledBits;
    /* 005 */ u8 field5[3];
    /* 008 */ u8 mEmblems[5][0x200];
    /* a08 */ u8 fieldA08[0xf8];
} EmblemBlockData;

typedef struct Unk0217aa08 {
    /* 00 */ BackupFirstBlock *mFirstBlock;
    /* 04 */ EmblemRecord *mEmblemRecord;
    /* 08 */ GrandPrixRecordBlock *mGrandPrixRecordBlock;
    /* 0c */ CourseTimeRecordBlock *mCourseTimeRecordBlock;
    /* 10 */ MissionRecordBlock *mMissionRecordBlock;
    /* 14 */ GhostRecord *mGhostRecords[3];
    /* 20 */ BuddyRecordBlock *mBuddyRecordBlock;
    /* 24 */ EmblemBlockData *mEmblemBlockData;
    /* 28 */ u8 mBusy;
    /* 29 */ u8 field29;
    /* 2a */ u16 mFailedBlockBits;
    /* 2c */ s32 mReadStatus;
    /* 30 */ u8 mParticipantAndBits[4];
    /* 34 */ u8 mParticipantOrBits[4];
    /* 38 */ u8 mParticipantMaxValue;
    /* 39 */ u8 mParticipantMinValue;
    /* 3a */ u8 field3A[2];
    /* 3c */ u8 field3C;
    /* 3d */ u8 field3D[3];
    /* 40 */ void *mReadDestination;
    /* 44 */ union {
        s32 field44;
        struct {
            s32 field44_0 : 1;
        };
    };
} Unk0217aa08;

// 0x2c bytes from 0x36 of Unk0217aa00_24_50_0e.
typedef struct Unk0217aa00_24_50_0e_36 {
    /* 00 */ u8 field0[2];
    /* 02 */ u8 field2[0x14];
    /* 16 */ u8 field16[0x16];
} Unk0217aa00_24_50_0e_36;

// 0x62 bytes from 0xe of Unk0217aa00_24_50.
typedef struct Unk0217aa00_24_50_0e {
    /* 00 */ u8 field0[6];
    /* 06 */ union {
        u8 field6;
        struct {
            u8 field6_0 : 4;
            u8 field6_4 : 4;
        };
    };
    /* 07 */ union {
        u8 field7;
        struct {
            u8 field7_0 : 1;
            u8 mKartIndex : 6;
        };
    };
    /* 08 */ u8 field8[2];
    /* 0a */ u8 fieldA[4];
    /* 0e */ u8 fieldE[0x28];
    /* 36 */ Unk0217aa00_24_50_0e_36 field36;
} Unk0217aa00_24_50_0e;

// 0x70 bytes at 0x50 of ScanBlockView; the word at 0x38 of ChildList points to one.
typedef struct Unk0217aa00_24_50 {
    union {
        struct {
            /* 00 */ u8 field0[7];
            /* 07 */ u8 field7;
            /* 08 */ u8 field8[2];
            /* 0a */ u8 fieldA;
            /* 0b */ u8 fieldB[3];
            /* 0e */ Unk0217aa00_24_50_0e fieldE;
        };
        struct {
            /* 00 */ u8 mUnk_00_pad[0x18];
            /* 18 */ union {
                u32 field18;
                struct {
                    u32 mCharacterIndex : 4;
                    u32 mCupCourseIndex : 5;
                    u32 mMinute : 7;
                    u32 mSecond : 6;
                    u32 mMillisecond : 10;
                };
            };
            /* 1c */ u8 field1C[0x54];
        };
    };
} Unk0217aa00_24_50;

// 0xc0 bytes behind member 0x24 of ConnectionWork; the first 0xc0 bytes of each ScanSlot have the same layout.
typedef struct ScanBlockView {
    /* 00 */ u16 field0;
    /* 02 */ u8 field2[0x3a];
    /* 3c */ u16 field3C;
    /* 3e */ u8 field3E[6];
    /* 44 */ u32 field44;
    /* 48 */ u16 field48;
    /* 4a */ u8 field4A;
    /* 4b */ u8 field4B;
    /* 4c */ u8 field4C[4];
    /* 50 */ Unk0217aa00_24_50 field50;
} ScanBlockView;

// Object behind member 0x15c4 of ConnectionWork.
typedef struct Unk0217aa00_15c4 {
    /* 00 */ u16 field0;
    /* 02 */ u16 field2;
    /* 04 */ u8 field4;
    /* 05 */ u8 field5;
    /* 06 */ union {
        u8 field6;
        struct {
            u8 field6_0 : 7;
            u8 field6_7 : 1;
        };
    };
    /* 07 */ u8 field7;
} Unk0217aa00_15c4;

// 8-byte entries from 0x44 of ConnectionWork.
typedef struct ChildEntry {
    /* 00 */ u8 field0[6];
    /* 06 */ u16 mAid;
} ChildEntry;

// 0x44 bytes from 0x44 of ConnectionWork.
typedef struct ChildList {
    /* 00 */ ChildEntry mEntries[7];
    /* 38 */ Unk0217aa00_24_50 *field38;
    /* 3c */ u16 field3C;
    /* 3e */ u16 field3E;
    /* 40 */ u8 mChildCount;
    /* 41 */ s8 mDisconnectingIndex;
    /* 42 */ u8 field42;
    /* 43 */ u8 mChildMask;
} ChildList;

// 8-byte entries behind member 0x1e48 of gStruct217AA00.
typedef struct ScanGhostInfo {
    /* 00 */ u8 mKartIndex;
    /* 01 */ u8 mCharacterIndex;
    /* 02 */ u8 mCourseId;
    /* 03 */ u8 mMinute;
    /* 04 */ u8 mSecond;
    /* 05 */ u8 field5[1];
    /* 06 */ u16 mMillisecond;
} ScanGhostInfo;

// Elements of the array at member 0x1e52 of gStruct217AA00.
typedef struct Unk0217aa00_1e52 {
    /* 00 */ u16 mEntryIndex;
    /* 02 */ u8 field2[6];
} Unk0217aa00_1e52;

// Part of ConnectionWork from 0x1608.
typedef struct MPStateMachine {
    /* 00 */ void *field0;
    /* 04 */ s32 mStateFrames;
    /* 08 */ void *field8;
    /* 0c */ u16 fieldC;
    /* 0e */ u16 mState;
    /* 10 */ u16 mNextState;
    /* 12 */ u16 mNextStateRequested;
    /* 14 */ u16 field14;
    /* 16 */ u16 field16;
    /* 18 */ s16 field18;
    /* 1a */ u8 field1A;
    /* 1b */ u8 field1B[0x1];
} MPStateMachine;

// Object behind gStruct217AA00.
// One of the 12 entries at 0x16a0: a block to offer to the other consoles, or a file path to read in.
typedef struct BlockEntry {
    /* 00 */ BlockListNode mNode;
// First byte of the 0x40-byte path; 0 means the entry is free.
    /* 34 */ u8 mPath;
    /* 35 */ u8 field35[0x3f];
    /* 74 */ u32 *mBuffer;
// Where the uncompressed bytes go; nothing sets it, so a block is allocated for them.
    /* 78 */ void *mUncompressedBuffer;
    /* 7c */ void **mDataOutput;
    /* 80 */ void *mHeap;
    /* 84 */ union {
        s32 field84;
        struct {
            u32 field84_0 : 29;
            s32 mUncompressPending : 1;
            u32 field84_30 : 1;
            u32 field84_31 : 1;
        };
    };
} BlockEntry;

// Members from 0x16a0 of ConnectionWork as one object.
typedef struct Unk0217aa00_16a0_view {
    /* 000 */ BlockEntry mBlockEntries[12];
    /* 660 */ s32 field660;
    /* 664 */ u8 field664[4];
    /* 668 */ u16 mNextLoadIndex;
    /* 66a */ s16 field66A;
    /* 66c */ u8 field66C[0x48];
    /* 6b4 */ u8 field6B4;
    /* 6b5 */ u8 field6B5[3];
    /* 6b8 */ void *mCompressedBuffer;
    /* 6bc */ u8 field6BC[0xdc];
    /* 798 */ BOOL field798;
    /* 79c */ BOOL field79C;
    /* 7a0 */ u16 mGhostBlockCount;
    /* 7a2 */ u16 field7A2;
    /* 7a4 */ u8 field7A4;
    /* 7a5 */ s8 field7A5;
    /* 7a6 */ u8 field7A6;
    /* 7a7 */ u8 field7A7[1];
} Unk0217aa00_16a0_view;

// 0x22c-byte entries from 0x45c of ConnectionWork.
typedef struct Unk0217aa00_45c {
    /* 000 */ u8 field0[0x14];
    /* 014 */ u8 field14;
    /* 015 */ u8 field15[0x1ff];
    /* 214 */ u8 field214;
    /* 215 */ u8 field215;
    /* 216 */ u16 field216;
    /* 218 */ s32 field218;
    /* 21c */ s32 field21C;
    /* 220 */ s32 field220;
    /* 224 */ u8 mBits[4];
    /* 228 */ union {
        u8 field228;
        struct {
            u8 field228_0 : 4;
            u8 field228_4 : 4;
        };
    };
    /* 229 */ u8 field229;
    /* 22a */ u8 field22A[2];
} Unk0217aa00_45c;

// Six bytes, compared and assigned as one object.
typedef struct Unk0217aa00_42c {
    /* 00 */ u8 field0[6];
} Unk0217aa00_42c;

// 0xe0-byte entries from 0xac of ConnectionWork.
typedef struct ScanSlot {
    /* 00 */ u8 field0[0xc0];
    /* c0 */ union {
        u8 fieldC0[6];
        Unk0217aa00_42c mUnk_c0_42c;
    };
    /* c6 */ u8 fieldC6[0x14];
    /* da */ u8 fieldDA;
    /* db */ u8 fieldDB;
    /* dc */ union {
        u8 fieldDC;
        struct {
            u8 fieldDC_0 : 1;
            u8 fieldDC_1 : 4;
            u8 fieldDC_5 : 1;
            u8 fieldDC_6 : 1;
        };
    };
    /* dd */ u8 fieldDD[3];
} ScanSlot;

// The 0x3b0 bytes from 0xac of ConnectionWork as one object: the four entries, then the members up to 0x45c.
typedef struct Unk0217aa00_ac {
    /* 000 */ ScanSlot field0[4];
    /* 380 */ u8 field380[6];
    /* 386 */ u8 field386[2];
    /* 388 */ u16 field388;
    /* 38a */ u16 field38A;
    /* 38c */ u8 field38C;
    /* 38d */ u8 field38D;
    /* 38e */ u8 field38E;
    /* 38f */ s8 field38F;
    /* 390 */ u8 field390[0x20];
} Unk0217aa00_ac;

// 8-byte entries behind member 0xc of DataSharing.
typedef struct Unk0217aa00_15c8 {
    /* 00 */ union {
        u8 field0[6];
        u16 field0_0;
    };
    /* 06 */ union {
        u8 field6;
        struct {
            u8 field6_0 : 7;
            u8 field6_7 : 1;
        };
    };
    /* 07 */ u8 field7;
} Unk0217aa00_15c8;

// Members 0x15bc to 0x1607 of ConnectionWork as one object.
typedef struct DataSharing {
    /* 00 */ WMDataSharingInfo *field0;
    /* 04 */ WMDataSet *field4;
    /* 08 */ void *field8;
    /* 0c */ Unk0217aa00_15c8 *fieldC;
    /* 10 */ s32 mSharedDataCopied[8];
    /* 30 */ u8 field30;
    /* 31 */ u8 field31[3];
    /* 34 */ s32 field34;
    /* 38 */ u16 field38;
    /* 3a */ u8 mParticipantMask;
    /* 3b */ u8 field3B;
    /* 3c */ u16 field3C[7];
    /* 4a */ u8 field4A;
    /* 4b */ u8 field4B[1];
} DataSharing;

// 8-byte entries from 0x1e4c of ConnectionWork.
typedef struct Unk0217aa00_1e4c_00 {
    /* 00 */ u16 field0[3];
    /* 06 */ u16 field6;
} Unk0217aa00_1e4c_00;

// Members 0x1e4c to 0x1ecf of ConnectionWork as one object.
typedef struct Unk0217aa00_1e4c {
    /* 00 */ Unk0217aa00_1e4c_00 field0[8];
    /* 40 */ u8 field40[0x20];
    /* 60 */ u8 field60;
    /* 61 */ u8 field61[7];
    /* 68 */ u8 field68;
    /* 69 */ u8 field69[0x1b];
} Unk0217aa00_1e4c;

// Seed, multiplier and increment of a multiply-add generator, each as a low word and a high word.
typedef struct RandomState {
    /* 00 */ s32 mStateLow;
    /* 04 */ s32 mStateHigh;
    /* 08 */ s32 mMultiplierLow;
    /* 0c */ s32 mMultiplierHigh;
    /* 10 */ s32 mIncrementLow;
    /* 14 */ s32 mIncrementHigh;
} RandomState;

// What member 0x1da0 of ConnectionWork points to.
typedef struct BlockInfo {
    /* 00 */ s32 mBlockId;
    /* 04 */ s32 mSize;
} BlockInfo;

// Members 0x1658 to 0x169f of ConnectionWork as one object.
typedef struct Unk0217aa00_1658 {
    /* 00 */ void *field0;
    /* 04 */ void *field4;
    /* 08 */ s32 field8;
    /* 0c */ void *fieldC;
    /* 10 */ void *field10;
    /* 14 */ s32 field14[8];
    /* 34 */ u32 field34;
    /* 38 */ u16 field38;
    /* 3a */ u16 field3A;
    /* 3c */ u8 field3C;
    /* 3d */ u8 field3D;
    /* 3e */ u8 field3E;
    /* 3f */ u8 field3F;
    /* 40 */ u8 field40;
    /* 41 */ u8 field41;
    /* 42 */ s8 field42;
    /* 43 */ u8 field43;
    /* 44 */ s32 field44;
} Unk0217aa00_1658;

typedef struct ConnectionWork {
    /* 0000 */ u32 field0;
    /* 0004 */ s32 field4;
    /* 0008 */ s32 field8;
    /* 000c */ s32 fieldC;
    /* 0010 */ s32 mRequestPending;
    /* 0014 */ void *field14;
    /* 0018 */ Unk02143c30 *mParentParameter;
    /* 001c */ Unk02143a78 *field1C;
    /* 0020 */ Unk021438f0 *field20;
    /* 0024 */ ScanBlockView *field24;
    /* 0028 */ void *field28;
    /* 002c */ void *field2C;
    /* 0030 */ s32 field30;
    /* 0034 */ void *field34;
    /* 0038 */ s32 field38;
    /* 003c */ void *field3C;
    /* 0040 */ void *field40;
    /* 0044 */ ChildList field44;
    /* 0088 */ s8 field88;
    /* 0089 */ union {
        u8 field89;
        struct {
            u8 field89_0 : 4;
            u8 field89_4 : 4;
        };
    };
    /* 008a */ u8 field8A;
    /* 008b */ u8 field8B;
    /* 008c */ s16 field8C[0xe];
    /* 00a8 */ u8 fieldA8[4];
    /* 00ac */ union {
        struct {
            /* 00ac */ ScanSlot fieldAC[4];
            /* 042c */ u8 field42C;
            /* 042d */ u8 field42D;
            /* 042e */ u8 field42E;
            /* 042f */ u8 field42F;
            /* 0430 */ u8 field430;
            /* 0431 */ u8 field431;
            /* 0432 */ u16 mOwnIndex;
            /* 0434 */ u16 field434;
            /* 0436 */ u16 field436;
            /* 0438 */ u8 field438;
            /* 0439 */ u8 field439;
            /* 043a */ u8 field43A;
            /* 043b */ s8 field43B;
            /* 043c */ u8 field43C;
            /* 043d */ u8 field43D;
            /* 043e */ u8 field43E[0x2];
            /* 0440 */ s32 (*field440)();
            /* 0444 */ s32 (*field444)();
            /* 0448 */ s32 (*field448)();
            /* 044c */ s32 (*field44C)();
            /* 0450 */ s32 (*field450)();
            /* 0454 */ u16 field454;
            /* 0456 */ union {
                u8 field456;
                struct {
                    u8 field456_0 : 1;
                };
            };
            /* 0457 */ u8 field457;
            /* 0458 */ u8 field458;
            /* 0459 */ u8 field459[3];
        };
        Unk0217aa00_ac mUnk_00ac_view;
    };
    /* 045c */ Unk0217aa00_45c field45C[8];
    /* 15bc */ union {
        struct {
            /* 15bc */ WMDataSharingInfo *field15BC;
            /* 15c0 */ WMDataSet *field15C0;
            /* 15c4 */ Unk0217aa00_15c4 *field15C4;
            /* 15c8 */ Unk0217aa00_15c8 *field15C8;
            /* 15cc */ s32 field15CC;
            /* 15d0 */ u8 field15D0[0x1c];
            /* 15ec */ u8 field15EC;
            /* 15ed */ u8 field15ED[0x3];
            /* 15f0 */ s32 field15F0;
            /* 15f4 */ u16 field15F4;
            /* 15f6 */ u8 mParticipantMask;
            /* 15f7 */ u8 field15F7;
            /* 15f8 */ u16 field15F8[7];
            /* 1606 */ u8 field1606;
            /* 1607 */ u8 field1607[0x1];
        };
        DataSharing mUnk_15bc_view;
    };
    /* 1608 */ MPStateMachine field1608;
    /* 1624 */ void *mChunkBuffer;
    /* 1628 */ u8 mEntryChunkIndex;
    /* 1629 */ u8 mEntryChunkSlot;
    /* 162a */ u8 field162A;
    /* 162b */ u8 field162B[0x1];
    /* 162c */ u8 *mChunkReceivedFlags[8];
    /* 164c */ u8 field164C;
    /* 164d */ u8 field164D;
    /* 164e */ u8 field164E;
    /* 164f */ u8 field164F;
    /* 1650 */ void *mCourseId;
    /* 1654 */ void *mMode;
    /* 1658 */ union {
        struct {
            /* 1658 */ void *field1658;
            /* 165c */ void *field165C;
            /* 1660 */ s32 field1660;
            /* 1664 */ void *field1664;
            /* 1668 */ void *field1668;
            /* 166c */ s32 field166C;
            /* 1670 */ u8 field1670[0x1c];
            /* 168c */ u32 field168C;
            /* 1690 */ u16 field1690;
            /* 1692 */ u16 field1692;
            /* 1694 */ u8 field1694;
            /* 1695 */ u8 field1695;
            /* 1696 */ u8 field1696;
            /* 1697 */ u8 field1697;
            /* 1698 */ u8 field1698;
            /* 1699 */ u8 field1699;
            /* 169a */ s8 mScanEntryIndex;
            /* 169b */ u8 field169B[0x1];
            /* 169c */ s32 field169C;
        };
        Unk0217aa00_1658 mUnk_1658_view;
    };
    /* 16a0 */ union {
        struct {
            /* 16a0 */ BlockEntry mBlockEntries[12];
            /* 1d00 */ s32 field1D00;
            /* 1d04 */ void *mHeap;
            /* 1d08 */ u16 mNextLoadIndex;
            /* 1d0a */ u16 field1D0A;
            /* 1d0c */ FSFile mFile;
            /* 1d54 */ u8 field1D54;
            /* 1d55 */ u8 field1D55[0x3];
            /* 1d58 */ void *mCompressedBuffer;
            /* 1d5c */ s16 mBlockIndex;
            /* 1d5e */ u16 mBlockCount;
            /* 1d60 */ u32 *field1D60;
            /* 1d64 */ u8 field1D64[0x3c];
            /* 1da0 */ BlockInfo *mBlockInfos[16];
            /* 1de0 */ void *mChunkBitmaps[16];
            /* 1e20 */ void *mMPSendBuffer;
            /* 1e24 */ void *mMPReceiveBuffer;
            /* 1e28 */ s32 mMPSendBufferSize;
            /* 1e2c */ s32 mMPReceiveBufferSize;
            /* 1e30 */ u8 *mPacketBuffer;
            /* 1e34 */ s32 field1E34;
            /* 1e38 */ s32 field1E38;
            /* 1e3c */ s32 field1E3C;
            /* 1e40 */ u16 mGhostBlockCount;
            /* 1e42 */ u16 mSendTimer;
            /* 1e44 */ u8 field1E44;
            /* 1e45 */ s8 field1E45;
            /* 1e46 */ u8 field1E46;
            /* 1e47 */ u8 field1E47[0x1];
            /* 1e48 */ ScanGhostInfo *mScanGhostInfos;
            /* 1e4c */ union {
                struct {
                    /* 1e4c */ u16 field1E4C;
                    /* 1e4e */ u8 field1E4E[0x4];
                    /* 1e52 */ Unk0217aa00_1e52 field1E52[7];
                    /* 1e8a */ u16 field1E8A;
                    /* 1e8c */ u16 field1E8C[8];
                    /* 1e9c */ u16 mParticipantIndices[8];
                    /* 1eac */ u8 field1EAC[4];
                    /* 1eb0 */ s32 field1EB0;
                    /* 1eb4 */ u8 field1EB4[4];
                    /* 1eb8 */ RandomState mRandom;
                };
                Unk0217aa00_1e4c mUnk_1e4c_view;
            };
            /* 1ed0 */ s32 field1ED0;
            /* 1ed4 */ u16 field1ED4;
            /* 1ed6 */ u16 field1ED6;
            /* 1ed8 */ s32 field1ED8;
            /* 1edc */ u16 field1EDC;
            /* 1ede */ u16 field1EDE;
            /* 1ee0 */ u8 field1EE0[2];
            /* 1ee2 */ u8 field1EE2[6];
        };
        Unk0217aa00_16a0_view mUnk_16a0_view;
    };
    /* 1ee8 */ RandomState64 field1EE8;
} ConnectionWork;

extern ConnectionWork *gStruct217AA00;
extern Unk0217aa08 *gSaveData;
// Object behind gBgWkrState; the OSThread at 0x2c is passed to OS_CreateThread and OS_WakeupThreadDirect.
typedef struct ThreadFunctionQueue {
    /* 00 */ void (*mFunctions[10])(void);
    /* 28 */ u8 mNewestIndex;
    /* 29 */ u8 field29[3];
    /* 2c */ OSThread mThread;
    /* e4 */ u8 fieldE4[0x10];
    /* f4 */ void *mThreadStack;
    /* f8 */ s32 mRunRequested;
} ThreadFunctionQueue;

extern ThreadFunctionQueue *gBgWkrState;
// 0xc-byte entries from 0x08 of OverlayLoader.
typedef struct OverlayLoaderEntry {
    /* 00 */ s32 mOverlayId;
    /* 04 */ u32 mStart;
    /* 08 */ u32 mEnd;
} OverlayLoaderEntry;

struct NNSiFndHeapHead;

// Object behind gOverlayData; UpdateWiFiSession reads the word at 0. The objects at 0x2c and 0x58 are passed to
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

extern OverlayLoader *gOverlayData;
// 0x38-byte entries from 0x14 of Unk0217aa14.
typedef struct Unk0217aa14_014 {
    /* 00 */ u8 field0[4];
    /* 04 */ s32 field4;
    /* 08 */ s32 field8;
    /* 0c */ s32 fieldC;
    /* 10 */ s32 field10;
    /* 14 */ s32 field14;
    /* 18 */ s32 field18;
    /* 1c */ s32 field1C;
    /* 20 */ s32 field20;
    /* 24 */ s32 field24;
    /* 28 */ s32 field28;
    /* 2c */ s32 field2C;
    /* 30 */ BOOL field30;
    /* 34 */ u8 field34;
    /* 35 */ u8 field35;
    /* 36 */ u8 field36;
    /* 37 */ u8 field37;
} Unk0217aa14_014;

// Halfwords from 0x20 of Unk0217aa14_104: bits 7 to 11 and 12 to 13.
typedef struct Unk0217aa14_104_20 {
    /* 00 */ union {
        u16 field0;
        struct {
            u16 : 7;
            u16 field0_7 : 5;
            u16 field0_12 : 2;
        };
    };
} Unk0217aa14_104_20;

// The 0x20 bytes from 0x68 of Unk0217aa14_104.
typedef struct Unk0217aa14_104_68 {
    /* 00 */ s32 field0;
    /* 04 */ s32 field4;
    /* 08 */ s32 field8;
    /* 0c */ u16 fieldC;
    /* 0e */ u16 fieldE;
    /* 10 */ s32 field10;
    /* 14 */ u16 field14;
    /* 16 */ u8 field16[0xa];
} Unk0217aa14_104_68;

// 0x88-byte entries from 0x104 of Unk0217aa14.
typedef struct Unk0217aa14_104 {
    /* 00 */ union {
        s32 field0;
        struct {
            u32 field0_0 : 24;
        };
    };
    /* 04 */ s32 field4;
    /* 08 */ u8 field8[0x18];
    /* 20 */ Unk0217aa14_104_20 field20[4];
    /* 28 */ u8 field28[0x40];
    /* 68 */ union {
        struct {
            /* 68 */ s32 field68;
            /* 6c */ s32 field6C;
            /* 70 */ s32 field70;
            /* 74 */ u16 field74;
            /* 76 */ u16 field76;
            /* 78 */ s32 field78;
            /* 7c */ u16 field7C;
            /* 7e */ u8 field7E[2];
            /* 80 */ s32 field80;
            /* 84 */ u16 field84;
            /* 86 */ union {
                u8 field86;
                struct {
                    u8 field86_0 : 1;
                    u8 mRank : 7;
                };
            };
            /* 87 */ u8 field87;
        };
        Unk0217aa14_104_68 mUnk_68_view;
    };
} Unk0217aa14_104;

// 0xc-byte entries from 0x324 of Unk0217aa14.
typedef struct ItemDataSlot {
    /* 00 */ s32 field0;
    /* 04 */ void *mData;
    /* 08 */ u8 field8;
    /* 09 */ u8 mItemKind;
    /* 0a */ u8 mMessageKind;
    /* 0b */ u8 mDataSize;
} ItemDataSlot;

// Halfword of the table at 0x20 of Unk0217aa14_754_04: bits 0 to 6, 7 to 11 and 12 to 13.
typedef struct Unk0217aa14_754_04_20 {
    /* 00 */ union {
        u16 field0;
        struct {
            u16 field0_0 : 7;
            u16 field0_7 : 5;
            u16 field0_12 : 2;
        };
    };
} Unk0217aa14_754_04_20;

// 0x68 bytes from 0x04 of what member 0x754 of Unk0217aa14 points to.
typedef struct Unk0217aa14_754_04 {
    /* 00 */ union {
        u32 field0;
        u16 mUnk_00_h;
        u8 mUnk_00_b[4];
        struct {
            u32 field0_0 : 24;
        };
    };
    /* 04 */ union {
        u32 field4;
        u8 mUnk_04_b[4];
    };
    /* 08 */ u32 field8;
    /* 0c */ u32 fieldC[5];
    /* 20 */ Unk0217aa14_754_04_20 field20[4];
    /* 28 */ u8 field28[0x10];
    /* 38 */ u8 field38[0x30];
} Unk0217aa14_754_04;

// What member 0x754 of Unk0217aa14 points to.
typedef struct Unk0217aa14_754 {
    /* 00 */ u8 field0[4];
    /* 04 */ Unk0217aa14_754_04 field4;
} Unk0217aa14_754;

// Object behind gStruct217AA14.
typedef struct Unk0217aa14 {
    /* 000 */ void *field0;
    /* 004 */ s32 field4;
    /* 008 */ void *field8;
    /* 00c */ u16 fieldC;
    /* 00e */ u16 fieldE;
    /* 010 */ u16 field10;
    /* 012 */ u16 field12;
    /* 014 */ Unk0217aa14_014 field14[4];
    /* 0f4 */ s32 fieldF4;
    /* 0f8 */ u16 fieldF8;
    /* 0fa */ u8 fieldFA;
    /* 0fb */ u8 fieldFB;
    /* 0fc */ u8 fieldFC;
    /* 0fd */ u8 fieldFD;
    /* 0fe */ u8 fieldFE[6];
    /* 104 */ Unk0217aa14_104 field104[4];
    /* 324 */ ItemDataSlot field324[16];
    /* 3e4 */ ItemDataSlot field3E4[16][4];
    /* 6e4 */ u8 field6E4[16][4];
    /* 724 */ u16 field724;
    /* 726 */ u8 field726[0x2];
    /* 728 */ s32 field728;
    /* 72c */ BOOL field72C;
    /* 730 */ u8 field730[0x4];
    /* 734 */ u16 field734;
    /* 736 */ s16 field736;
    /* 738 */ u16 field738;
    /* 73a */ u8 field73A;
    /* 73b */ u8 field73B;
    /* 73c */ u8 field73C[0x1];
    /* 73d */ u8 field73D;
    /* 73e */ u8 field73E;
    /* 73f */ u8 field73F;
    /* 740 */ u16 field740[4];
    /* 748 */ u8 field748;
    /* 749 */ u8 field749;
    /* 74a */ u8 field74A[4];
    /* 74e */ u8 field74E[4];
    /* 752 */ u8 field752[2];
    /* 754 */ Unk0217aa14_754 *field754;
    /* 758 */ s32 field758;
    /* 75c */ u16 field75C;
} Unk0217aa14;

extern Unk0217aa14 *gStruct217AA14;
// Per-run state of the race scene, one record behind race_sState (0x48 bytes, allocated by race_init on the scene heap and
// never cleared at the end of the scene): frame counters (mUpdateFrames and three phases derived from it), toon-table
// cycle, fog/fade switch, kind flags derived from gRaceMultiConfig->fieldC (also live in the demo and credits kinds 3 to
// 6), a light vector. Not the race setup (gRaceMultiConfig), not the karts.
typedef struct Race {
    // 1 once the race has started, else 0: race_start sets it when UpdateRaceStartSequence reaches its frame 180, and
    // race_init sets it at once for the kinds 5 and 6 of RaceSetup.fieldC, which have no countdown; race_getState
    // returns it.
    /* 00 */ s16 mStarted;
    /* 02 */ u8 field2[2];
    // Counts calls of race_update; in mode 5 held at 128 until mUpdateFramesUnlimited is set
    // (race_setField34).
    /* 04 */ s32 mUpdateFrames;
    // Counts calls of race_render; never read (2 writes, 0 reads).
    /* 08 */ s32 mDrawFrames;
    // Value of mUpdateFrames modulo 8 (its low three bits) as of the end of the latest race_update, 0 at set-up; kart
    // and map object code compare it with an index or a limit to act on one frame out of eight.
    /* 0c */ s32 mUpdateFramesMod8;
    // Value of mUpdateFrames modulo 2 as of the end of the latest race_update, 0 at set-up; compared with 0 or with a
    // bit of the object's own flags to act on every second frame.
    /* 10 */ s32 mUpdateFramesMod2;
    // Value of mUpdateFrames modulo RaceSetup.mKartCount as of the end of the latest race_update, 0 at set-up; its one
    // reader uses it as a kart index.
    /* 14 */ s32 mUpdateFramesModKartCount;
    // Start index (0 to 7) of the 32 entries of race_sToonTable that race_update gives to G3X_SetToonTable on each call;
    // it advances by 1 each time mToonTableFrames passes race_sToonTableUpdateInterval and wraps back to 0 after 7.
    /* 18 */ s32 mToonTableOffset;
    // Counts calls of race_update since mToonTableOffset last changed; when it exceeds race_sToonTableUpdateInterval (2) it restarts at
    // 0 and mToonTableOffset advances (every third call).
    /* 1c */ s32 mToonTableFrames;
    // 1 from the start of a fog fade (race_startDarkening) until race_update ends it, else 0: while it is 1 race_render writes
    // the fade fog into the fog registers instead of the course fog. race_update holds it for 72 calls, then steps
    // race_sDarkeningFogDensity from 72 down to 0 in steps of 4 and clears it. race_render compares it with mDrawnFadeFog.
    /* 20 */ s32 mFadeFog;
    // The value of mFadeFog that race_render last handled; race_render writes the fog registers when it differs from
    // mFadeFog, then copies mFadeFog here. race_startDarkening sets it to 0 when it is 1 so that the next race_render writes the
    // registers again.
    /* 24 */ s32 mDrawnFadeFog;
    // 1 when RaceSetup.fieldC is 3, 4 or 5, else 0. While it is 1, race_init creates the chain cameras, race_update
    // updates them and takes their view, and race_render skips the draw call of driver_renderLabels. The other readers go
    // through race_isCamAnimMode and use it to tell these kinds apart (map objects, balloons, effects, kart
    // set-up).
    /* 28 */ s32 mUseChainCameras;
    // 1 when RaceSetup.fieldC is 4: only the first chain camera is created and updated instead of the pair (read
    // only while mUseChainCameras is non-zero).
    /* 2c */ s32 mUseFirstChainCamera;
    // Mode 5 only: set by race_update when mUpdateFrames reaches 128 while mUpdateFramesUnlimited is FALSE; from then on
    // mUpdateFrames stays put until mUpdateFramesUnlimited is set. Never cleared again.
    /* 30 */ BOOL mUpdateFramesLimitReached;
    // Mode 5 only: FALSE at set-up, set by race_setField34 (called by UpdateRaceStartSequence when it
    // begins counting); once set, race_update counts mUpdateFrames on every call with no stop at 128.
    /* 34 */ BOOL mUpdateFramesUnlimited;
    /* 38 */ s32 mIsAwardOrStaffRoll;
    // Value of mUpdateFrames when the end handler of the kart of the selected entry (RaceSetup.mEntryIndex) first
    // ran, stored by race_20617D8 (in mission run mode that is after the end wait); 0 until then.
    /* 3c */ s32 mUpdateFramesAtEntryEnd;
    // x component of the direction of light 0, the vector race_renderRace gives to NNS_G3dGlbLightVector; set at race_init
    // from data_021653f0 and by race_setLight0Direction.
    /* 40 */ s16 mLightVectorX;
    // y component of the direction of light 0, the vector race_renderRace gives to NNS_G3dGlbLightVector; set at race_init
    // from data_021653f0 and by race_setLight0Direction.
    /* 42 */ s16 mLightVectorY;
    // z component of the direction of light 0, the vector race_renderRace gives to NNS_G3dGlbLightVector; set at race_init
    // from data_021653f0 and by race_setLight0Direction.
    /* 44 */ s16 mLightVectorZ;
} Race;

extern Race *race_sState;
extern s32 race_sDarkeningActive;
struct Unk02077750;

// The viewer of a race: position, look-at point, three axes, view matrix and frustum. One class, several instances:
// cam_sPlayerCamera follows the selected kart, cam_sReplayCamera and cam_sIntroCameraTop / cam_sIntroCameraBottom step through
// CourseMapCamera entries; race_sCurCamera points at the one used this frame.
typedef struct Camera {
    /* 000 */ Vec3 mUp;
    // baseUp x forward, perpendicular to mUp and mForward. Sign not fixed (left or right is not shown); not updated
    // by cam_updateLookAt.
    /* 00c */ Vec3 mSide;
    /* 018 */ Vec3 mLookAt;
    /* 024 */ Vec3 mPos;
    /* 030 */ MtxFx43 mViewMatrix;
    // Half of the vertical field of view, 0x10000 per turn (top = near * tan). The chase camera eases it toward
    // mHalfFovAngleGoal; entry cameras set the pair mHalfFovPairFirst / mHalfFovPairSecond (sin and cos of the angle)
    // directly.
    /* 060 */ s32 mHalfFovAngle;
    // Default cam_sDefaultFov (0x157c, about 30 degrees).
    /* 064 */ s32 mHalfFovAngleGoal;
    // First and second element of the pair FX_SinCosTable_ holds for mHalfFovAngle; mFrustumTop = mNear * first / second.
    /* 068 */ s16 mHalfFovPairFirst;
    /* 06a */ s16 mHalfFovPairSecond;
    /* 06c */ s32 mAspectRatio;
    /* 070 */ s32 mNear;
    // Far plane of the NitroMain projection (course settings value, default 0x640000); field8C is a second far value.
    /* 074 */ s32 mFar;
    // The four extents handed to G3i_FrustumW_ (top, bottom, left, right), 20.12; shifted by mFrustumShift
    // and a kind-6 entry offset, left and right swapped in mirror mode.
    /* 078 */ s32 mFrustumTop;
    /* 07c */ s32 mFrustumBottom;
    /* 080 */ s32 mFrustumLeft;
    /* 084 */ s32 mFrustumRight;
    // Fraction of the Kart's last-frame movement (mPos - mPrevPos) added to the camera position while Kart bit 0x1000
    // of field48 is set; 0x1000 when the camera is placed, times 0xe66/0x1000 per use.
    /* 088 */ s32 mKartMoveScale;
    /* 08c */ s32 field8C;
    /* 090 */ Vec3 mViewLookAt;
    /* 09c */ Vec3 mViewPos;
    /* 0a8 */ Vec3 fieldA8;
    /* 0b4 */ Vec3 fieldB4;
    // The up vector mUp is built from: eased toward world up (or a kart vector); mUp is made perpendicular to
    // mForward from it.
    /* 0c0 */ Vec3 mBaseUp;
    /* 0cc */ s32 mHeldHeight;
    // Set once the kart is above mHeldHeight; then mHeldHeight eases toward the free y.
    /* 0d0 */ BOOL mHeldHeightEasing;
    /* 0d4 */ s32 mLookAtHeight;
    /* 0d8 */ s32 fieldD8;
    /* 0dc */ s32 mFollowDistance;
    /* 0e0 */ s32 fieldE0;
    // Amount the look-at is lowered: +0x1000 per call up to 0xa000 while the Kart has bit 0x10000 of field48, else
    // decays; subtracted from the look-at goal y (cam_20745D4).
    /* 0e4 */ s32 mLookAtLowering;
    /* 0e8 */ s32 mFollowDistanceScale;
    /* 0ec */ s32 fieldEC;
    // 0x1000, or -0x1000 in mode 4 with flag 0x20 of gRaceMultiConfig->field44.
    /* 0f0 */ s32 mFollowDirectionSign;
    /* 0f4 */ Vec3 mShakeLookAtOffsetGoal;
    /* 100 */ Vec3 mShakePosOffsetGoal;
    /* 10c */ Vec3 mShakeLookAtOffset;
    /* 118 */ Vec3 mShakePosOffset;
    // Third look-at shake term: adds -mShakeLookAtOffset times a per-kind factor (1.25 / 2 / 2.75), halved each call;
    // added to the look-at in cam_updateLookAtEx.
    /* 124 */ Vec3 mShakeLookAtCounterOffset;
    /* 130 */ u8 mShakeKind;
    /* 131 */ u8 field131[0x3];
    // mPos of the previous frame; the chase step keeps it while a collision push is active.
    /* 134 */ Vec3 mPrevPos;
    // Set by cam_tryShakePlayerCamera, cleared by cam_updateShake when the amplitude is used up.
    /* 140 */ BOOL mWobbling;
    /* 144 */ s32 field144;
    /* 148 */ s32 mWobbleAmplitude;
    // Added to field144 each frame, times mWobbleDirection.
    /* 14c */ s32 mWobblePerFrame;
    /* 150 */ s16 mWobbleDirection;
    /* 152 */ u8 field152[0x2];
    /* 154 */ s32 mWobbleDecay;
    /* 158 */ s32 mWobbleOffset;
    /* 15c */ Vec3 mForward;
    // Added to the y of the position goal; eased toward a value taken from the Kart's heading y while Kart bit 0x10 of
    // field44 or 0x10000 of field48 is set.
    /* 168 */ s32 mPosGoalYOffset;
    // Eased toward 0, or toward +-0x19000 (sign of Kart.mTurnDirection) while Kart bit 8 of field44 is set.
    /* 16c */ s32 mPosGoalKartOffsetScale;
    // Length of the push-out vector while the push is in state 1 of field254, else 0; mCollisionOffsetLength eases
    // toward it.
    /* 170 */ s32 mCollisionOffsetLengthGoal;
    // Eased mCollisionOffsetLengthGoal; times 3 it shortens the follow distance and raises the position goal
    // (cam_20741A0).
    /* 174 */ s32 mCollisionOffsetLength;
    // Added to the eye height of the view only, not to the look-at.
    /* 178 */ s32 mViewPosYOffset;
    // The push-out vector of the collision test (col_collide) scaled by 3 to 8, kept and eased; added to the position
    // goal.
    /* 17c */ Vec3 mPosGoalCollisionOffset;
    // Kart.field120 (a row of the Kart's matrix) times mPosGoalKartOffsetScale; added to the position goal.
    /* 188 */ Vec3 mPosGoalKartOffset;
    /* 194 */ PosCurve mPosCurve;
    /* 1d0 */ PosCurve field1D0;
    /* 20c */ u16 field20C;
    /* 20e */ u16 field20E;
    // Index into sDrivers the look-at is taken from (entry cameras; the chase camera is handed its Kart).
    /* 210 */ u16 mFollowedKartIndex;
    /* 212 */ u8 field212[0x2];
    // Index mdat_findCameraId last returned for the followed kart; mCourseMapCamera is the entry actually in
    // use.
    /* 214 */ s32 mLastCourseMapCameraIndex;
    /* 218 */ struct CourseMapCamera *mCourseMapCamera;
    /* 21c */ struct Unk02077750 *field21C;
    /* 220 */ struct Unk02077750 *field220;
    /* 224 */ u16 field224;
    /* 226 */ u8 field226[0x2];
    // TRUE from cam_2075EB8 until mKind6EntryFrames reaches 300 (outside mode 2) or cam_2075D08
    // replaces the entry. While TRUE the entry is not replaced by the one picked from the Kart's position; in mode 2
    // cam_updateReplayCamera steps the entry by its kind on every call and only cam_2075D08 clears it.
    /* 228 */ BOOL mKind6EntryRunning;
    // Counts the calls of cam_updateReplayCamera outside mode 2 while mKind6EntryRunning is TRUE; at 300 it clears
    // mKind6EntryRunning. Only cam_init zeroes it, so it carries over a restart.
    /* 22c */ u16 mKind6EntryFrames;
    /* 22e */ u8 field22E[0x2];
    // Set to 1 by cam_2075D08(1), which only does so while the current entry is of kind 5 or 6, and to 0 by
    // cam_2075D08(0) and cam_init. While non-zero cam_updateReplayCamera returns FALSE at once, so the chase camera
    // is shown.
    /* 230 */ s32 mEntryUpdateHold;
    // Set to 1 once by cam_2075CF0 and never cleared (cam_init zeroes it). While set
    // cam_updateReplayCamera returns FALSE at once, so the chase camera is shown.
    /* 234 */ BOOL mEntryUpdateDisabled;
    // Set to TRUE by cam_setupMissionFinishCamera and never cleared (cam_init zeroes it). While set, and after the
    // mEntryUpdateHold and mEntryUpdateDisabled tests, cam_updateReplayCamera runs cam_2074E6C on the current
    // entry and returns TRUE.
    /* 238 */ BOOL mKind8EntryRunning;
    /* 23c */ u16 mCourseMapCameraFrames;
    /* 23e */ u8 field23E[0x2];
    /* 240 */ s32 mFovBlend;
    /* 244 */ s32 mLookAtBlend;
    // Non-zero while the position y is held at mHeldHeight (set by cam_20747F4 for kart state 6).
    /* 248 */ s32 mHeightHold;
    // 0 none; 1 and 2 (cam_sIntroCameraTop / cam_sIntroCameraBottom while the entry is kind 4) shift the window of
    // mFrustumTop and mFrustumBottom up or down by 1.3 of its half height (cam_updateFrustum).
    /* 24c */ s32 mFrustumShift;
    // Which camera this instance is: 0 chase, 1 entry camera, 2 chain camera, 3 entry camera in mode 2 with a kind 7
    // entry; tested by outside code (race_getCameraField250).
    /* 250 */ s32 mKind;
    /* 254 */ s32 field254;
    /* 258 */ BOOL field258;
    /* 25c */ BOOL field25C;
    // driver_getShadowZDirection (row 2 of the Kart's matrix, taken as its heading) of the selected Kart at creation; used instead
    // of the live vector for a Kart with bit 0x20000000 of field4C. cam_init zeroes it.
    /* 260 */ Vec3 mSavedKartForward;
    /* 26c */ s16 mSideDistanceSign;
    /* 26e */ u8 field26E[0x2];
} Camera;

extern Camera *race_sCurCamera;
extern u16 race_sDarkeningFadeFogColor;
extern u16 race_sDarkeningFogColor;
extern s16 race_sStagFogColorG;
extern u16 race_sStagFogColor;
extern s16 race_sStagFogColorB;
extern s16 race_sStagFogColorR;
extern s32 data_0217aa44;
extern s32 race_sStagFogOffset;
extern s32 race_sDarkeningIsFading;
extern s32 race_sStagFogAlpha;
extern s32 data_0217aa58;
extern Camera *race_sReplayCamera;
extern s32 race_sDarkeningFogAlpha;
extern s32 race_sDarkeningFadeFogAlpha;
extern s32 race_sDarkeningFadeFogOffset;
extern void *race_sG3dGeBuffer;
extern s32 data_0217aa78;
extern s32 race_sFogSlope;
extern s32 data_0217aa84;
extern Camera *race_sPlayerCamera;
extern u32 data_0217aa8c[4];
extern u32 race_sDarkeningFogTable[8];
extern u32 race_sStagFogTable[8];
extern u16 race_sToonTable[32];
extern MtxFx43 *race_sCurCameraMtx;
extern u32 data_0217ac10;
extern void *data_0217ac14;
extern void *driver_sColReactionInitTable[15];
extern void *driver_sColReactionHandleTable[15];
extern struct Camera *cam_sPlayerCamera;
// Set to 1 at race set-up and when a camera entry is started or advanced; cleared once per race_update call by
// cam_2073E98. race_update calls mobj_20D50C4 when it is set.
extern s32 gCameraEntryChanged;
// The chain camera whose view matrix the last chain step returned; race_update stores it as the camera in use. Not
// written in races without chain cameras.
extern Camera *cam_sIntroCamera;
// The Camera that picks its CourseMapCamera entry from the position of the followed Kart (mdat_findCameraId)
// and is stepped by cam_updateReplayCamera. mKind is 1, or 3 in mode 2 when CourseMap.mFirstKind7EntryInMode2 is set. The
// Kart code starts its kind 6 and kind 8 entries (cam_2075EB8, cam_setupMissionFinishCamera). The chain
// cameras also run entries but never pick by position.
extern Camera *cam_sReplayCamera;
extern u8 cam_sProjectionMtx[];
// 0x20-byte entries behind member 0x014 of KartModels.
typedef struct HeyhoPalette {
    /* 00 */ u8 field0[4];
    /* 04 */ u16 field4;
    /* 06 */ u8 field6[0x1a];
} HeyhoPalette;

// Object behind gCharKartData (0x144 bytes); the addresses of 0x2c, 0x98 and 0x10c are passed on as objects.
struct KartModelsEntry;

typedef struct KartModels {
    // Array of the per-kart model entries (0xb4 bytes each), allocated by chkrt_init with mKartCount elements;
    // Kart.mKartModelsEntry points into it.
    /* 000 */ struct KartModelsEntry *mKartModelsEntries;
    /* 004 */ u16 *mCourseColors;
    // Number of elements of mKartModelsEntries, copied from gRaceMultiConfig->mKartCount; the loop bound over the
    // entries.
    /* 008 */ u16 mKartCount;
    /* 00a */ u8 fieldA[2];
    /* 00c */ s32 mKartTireMaterialIndex;
    /* 010 */ u16 *mKartAPalette;
    /* 014 */ HeyhoPalette *mHeyhoPalettes;
    /* 018 */ s16 mHeyhoPaletteIndices[8];
    /* 028 */ void *mPFaceanimNsbtpFile;
    /* 02c */ Nsbmd mKillerItem;
    /* 098 */ ShadowModel mKillerItemS;
    /* 10c */ ModelAnimation mKillerItemNsbca;
} KartModels;

extern KartModels *gCharKartData;

typedef struct KartModelAnimationView KartModelAnimationView;

// Object behind member 0x20 of an KartModelMenuSlot: a word at 0x10 and rows of three words from 0x14 and from 0x44.
typedef struct Unk0217ad08_058_20 {
    /* 00 */ u8 field0[0x10];
    /* 10 */ s32 field10;
    /* 14 */ Vec3 field14[4];
    /* 44 */ Vec3 field44[1];
    /* 50 */ u8 field50[0x90];
} Unk0217ad08_058_20;

// 0xb8-byte entries from 0x58 of KartModelMenuData.
typedef struct KartModelMenuSlot {
    /* 00 */ s32 mCharacterIndex;
    /* 04 */ s32 mKartIndex;
    /* 08 */ KartModelAnimationView *mCharacterAnimation;
    /* 0c */ u8 fieldC[4];
    /* 10 */ struct Nsbmd *mCharacterNsbmd;
    /* 14 */ struct Nsbmd *mKartNsbmd;
    /* 18 */ struct Nsbmd *mTireNsbmd;
    /* 1c */ struct ShadowModel *mShadowModel;
    /* 20 */ Unk0217ad08_058_20 *mKartOffsetData;
    /* 24 */ u8 field24[0x8c];
    /* b0 */ s32 fieldB0;
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
    /* 32 */ u8 field32[2];
} KartModelMenuFiles;

// Six halfwords; the 0xc-byte entries behind member 0x1c of KartModelMenuData.
typedef struct KartMenuParams {
    /* 00 */ u16 field0[6];
} KartMenuParams;

// Embedded in KartModelMenuData at 0x24 (0x34 bytes).
typedef struct KartModelMenuView {
    /* 00 */ s32 mCharacterIndex;
    /* 04 */ s32 mKartIndex;
    /* 08 */ s32 mScale;
    /* 0c */ s32 fieldC;
    /* 10 */ s32 field10;
    /* 14 */ u16 mSpinAngle;
    /* 16 */ u16 mYawAngle;
    /* 18 */ s16 field18;
    /* 1a */ u16 field1A;
    /* 1c */ u8 field1C[0x10];
    /* 2c */ s32 mBg0Offset;
    /* 30 */ s32 mBg0Direction;
} KartModelMenuView;

// Object behind gCharKartSelectState.
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
    /* 1c8 */ Unk0217ad08_058_20 *mKartOffsetTable;
    /* 1cc */ struct Nsbmd *mSelectModel;
    /* 1d0 */ void *mKartAPalette;
    /* 1d4 */ void *mEmblemTex;
    /* 1d8 */ s32 field1D8;
    /* 1dc */ BOOL field1DC;
    /* 1e0 */ BOOL mUseEmblemTex;
    /* 1e4 */ s32 mMirrorMode;
    /* 1e8 */ void *mEmblemData;
    /* 1ec */ void *mEmblemPalette;
    /* 1f0 */ s16 field1F0;
    /* 1f2 */ u8 field1F2[2];
    /* 1f4 */ KartModelMenuFiles mFiles[2];
    /* 25c */ s32 mCharacterRequested;
    /* 260 */ s32 mKartRequested;
    /* 264 */ s16 mShownSlotIndex;
    /* 266 */ s16 mLoadSlotIndex;
    /* 268 */ struct KartAppear *mKartAppear;
} KartModelMenuData;

extern KartModelMenuData *gCharKartSelectState;
extern u16 gKillerItemKartIndex;
extern char aCharacterMarioP_mr_lose_nsbca[];
// 1 when this is a mission run and the course has a shape of kind 2, else 0; set by driver_initAll.
extern s32 driver_sCheckMissionEndArea;
extern u32 driver_sClipAreaMask;
extern s32 gKartSpeedLimitReciprocal;
extern s32 gKartForwardSpeedRatio;
struct Unk0201ca6c;

// Two objects returned by ptcm_createEmitter.
typedef struct KartEffectPair {
    union {
        struct {
            /* 00 */ struct Unk0201ca6c *mEffect0;
            /* 04 */ struct Unk0201ca6c *mEffect1;
        };
        struct Unk0201ca6c *mUnk_00_a[2];
    };
} KartEffectPair;

// Effect objects of one Kart: the current effect with its id, and further effect objects with the points they are
// placed at. One record per Kart in rptc_sDriverEffects, indexed by Kart.mIndex. 0x58-byte entries of the table behind
// rptc_sDriverEffects; the pointers at 0x0c and 0x20 to 0x30 hold objects returned by ptcm_createEmitter.
typedef struct KartEffects {
    // Id of the effect in mCurrentEffect, -1 when there is none.
    /* 00 */ s32 mCurrentEffectId;
    // Id of the effect running in entry i of mEffectPairs, -1 when there is none; compared with the wanted id to decide
    // whether to start again.
    /* 04 */ s32 mEffectIds[2];
    // The effect object of this Kart started by rptc_DriveOnSand, whose id is mCurrentEffectId (NULL when none).
    /* 0c */ struct Unk0201ca6c *mCurrentEffect;
    // The effect objects started for mEffectIds: entry i holds the object of side 0 and the object of side 1 (the byte
    // set in each object is the side number); ids in mEffectIds.
    /* 10 */ KartEffectPair mEffectPairs[2];
    union {
        struct {
            /* 20 */ struct Unk0201ca6c *mWaterEffect0;
            /* 24 */ struct Unk0201ca6c *mWaterEffect1;
        };
        struct Unk0201ca6c *mUnk_20_a[2];
    };
    /* 28 */ struct Unk0201ca6c *field28;
    /* 2c */ struct Unk0201ca6c *mKillerEffect;
    /* 30 */ struct Unk0201ca6c *field30;
    // Position in effect units (position / 16) of each side of the Kart: model point 2 or 3 moved by the x offset
    // 0x1800 or -0x1800 of gKartSideOffsetsX, scaled by the Kart scale and transformed by the Kart matrix; written only
    // by rptc_updateDriverEffects.
    /* 34 */ Vec3 mSidePositions[2];
    // Direction vector (halfwords) of the effect on each side of the Kart: the vector of gKartSideDirectionVectors for
    // that side rotated by the Kart matrix; written only by rptc_updateDriverEffects and read as the direction of the
    // effect object.
    /* 4c */ Vec3s16 mSideDirections[2];
} KartEffects;

// Per-Kart effect records, allocated for every Kart by rptc_initForDrivers and indexed by Kart.mIndex.
extern KartEffects *rptc_sDriverEffects;
extern struct KartAiItemUseEntry *enit_sDragItemParamsPtr;
extern struct KartAiItemUseEntry *enit_sSlotItemParamsPtr;
struct PointLinkCursor;
struct KartAi;
struct LinkCursor;
struct Kart;
extern const s32 *data_0217ae58;
extern void (*gAdvanceKartAiPointLinkCursor)(struct PointLinkCursor *p);
extern const s32 *data_0217ae60;
extern void (*gSetKartAiLinkPos)(struct KartAi *p, struct LinkCursor *q, struct Kart *r);
extern const s32 *gKartAiDriftChargeRandomLimits;
extern const s32 *data_0217ae4c;
extern const s32 *gKartAiRaceStartBoostRandomLimits;
extern const s32 *data_0217ae54;
extern u16 rptc_sEffectColor;
extern u16 data_0217ae70;
extern struct Unk0201ca6c **rptc_sDriverSlipstreamEmitters;
// Three objects per entry, 0xc bytes each.
typedef struct KartStarEffects {
    /* 00 */ struct Unk0201ca6c *mEffects[3];
} KartStarEffects;

extern KartStarEffects *rptc_sRainbowEffectEmitters;
extern u16 *rptc_sDriverEffectVariantTable;
extern s32 gOtherKartOddCount;
extern struct Unk0201ca6c **rptc_sDriverSlipstreamBeginEmitters;
extern s32 gOtherKartFullPairCount;

// Entry of the eight 0xc-byte entries at 0xb0 of KartAiShared: a word, then the links of a list.
typedef struct KartAiTableIndexEntry {
    /* 00 */ s32 mTableIndex;
    /* 04 */ u8 field4[8];
} KartAiTableIndexEntry;

// One row of 'kartAIparam.bin'.
typedef struct KartAiParamRow {
    /* 00 */ s32 field0;
    /* 04 */ s32 field4;
    /* 08 */ s32 field8;
} KartAiParamRow;

// State the CPU kart code shares: per-kart tables, the random generator pointer and the team counts.
typedef struct KartAiShared {
    /* 000 */ s32 mRaceProgressScaled[8];
    // Kart index at rank n + 1, -1 when no kart has that rank.
    /* 020 */ s32 mKartAtRank[8];
    /* 040 */ s32 mKind1KartByRank[8];
    /* 060 */ s32 mNonCpuKartByRank[8];
    /* 080 */ s32 field80;
    /* 084 */ s32 field84;
    /* 088 */ s32 field88;
    /* 08c */ s32 field8C;
    /* 090 */ s32 mTableIndex[8];
    /* 0b0 */ KartAiTableIndexEntry mTableIndexEntries[8];
    /* 110 */ s32 field110;
    /* 114 */ s32 field114[2];
    /* 11c */ s32 field11C;
    /* 120 */ s32 field120;
    /* 124 */ s16 field124;
    /* 126 */ u8 field126[2];
    // The race's random generator, or the per-console one in time attack.
    /* 128 */ RandomState64 *mRandom;
    /* 12c */ NNSFndList mTableIndexList;
    /* 138 */ s32 field138;
    /* 13c */ s16 mNonCpuKartCount;
    /* 13e */ s16 mTeamNonCpuKartCounts[3];
} KartAiShared;

extern KartAiShared *gKartAiShared;
// The row of 'kartAIparam.bin' for this race; NULL in battle and when fieldC is 5 or 6.
extern KartAiParamRow *gKartAiParamRow;
extern u8 *gKartEntryNameTexBuffer;
extern u16 *gKartEntryNamePlltBuffer;
extern u8 *data_0217aecc;
extern Vec3 *gKartDistanceLimitsSquared;
extern u16 *gKartEmblemPlltBuffer;
extern s32 data_0217aedc;
extern Unk0214ad4c PlayerLabelProjMtx;

struct KartNameTag;

// Object behind data_0217aed0, 0x194 bytes: tables of eight entries.
typedef struct Unk0217aed0 {
    /* 000 */ struct KartNameTag *mNameTagByKart[8];
    /* 020 */ s32 mNameTagCount;
    /* 024 */ s16 field24[8];
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
    /* 184 */ s32 field184;
    /* 188 */ void *field188;
    /* 18c */ u8 field18C[8];
} Unk0217aed0;

extern Unk0217aed0 *data_0217aed0;
extern const char *ckldr_sLoadBasePath;
extern char ckldr_sPathResult[];

// Entries of the 0x400-byte buffer behind member 0x04 of DispCap.
typedef struct DispCapOamEntry {
    /* 00 */ u32 field0;
    /* 04 */ union {
        u32 field4;
        u16 mUnk_04_h;
    };
} DispCapOamEntry;

// Object behind sDceState.
typedef struct DispCap {
    /* 00 */ s32 mMode;
    /* 04 */ DispCapOamEntry *mOamBuffer;
    /* 08 */ u16 mFlags;
    /* 0a */ u8 mBlendMin;
    /* 0b */ u8 fieldB[0x1];
    /* 0c */ s32 mBlendFactor;
} DispCap;

extern DispCap *sDceState;
// Object behind scproc_sSceneProc, 0x10 bytes.
typedef struct RunScenesState {
    /* 00 */ s32 field0;
    /* 04 */ s32 field4;
    /* 08 */ s16 mSceneNumber;
    /* 0a */ u8 fieldA[2];
    /* 0c */ void *mSndHeapsBuffer;
} RunScenesState;

// 0xc-byte entries of the array behind member 0x00 of ShapeMapObjectCountList.
typedef struct ShapeMapObjectCount {
    /* 00 */ u16 mShapeIndex;
    /* 02 */ u8 field2[2];
    /* 04 */ s32 mRadius;
    /* 08 */ u8 mIncreaseCount;
    /* 09 */ u8 mMapObjectCount;
    /* 0a */ u8 fieldA[2];
} ShapeMapObjectCount;

// Object behind area_sMissionRivalPassAreaStatus, 8 bytes.
typedef struct ShapeMapObjectCountList {
    /* 00 */ ShapeMapObjectCount *mEntries;
    /* 04 */ u16 mEntryCount;
    /* 06 */ u8 field6[2];
} ShapeMapObjectCountList;

extern RunScenesState *scproc_sSceneProc;
extern ShapeMapObjectCountList *area_sMissionRivalPassAreaStatus;
extern u16 race_sDarkeningFadeWaitCounter;
// Set to 1 when cam_updateReplayCamera is entered; cleared once per race_update call by cam_2073E98.
// cam_updateFrustum does not skip the chase camera's projection while it is 1.
extern s32 gEntryCameraUpdateRan;

// Ten bytes: bytes 6 to 9 are signed values read in rows of four.
typedef struct ParticipantKartMap {
    /* 00 */ s8 mParticipantOfKart[4];
    /* 04 */ u8 field4;
    /* 05 */ u8 field5;
    /* 06 */ s8 mKartOfParticipant[4];
} ParticipantKartMap;

extern ParticipantKartMap *gStruct217AA18;
// 0xa-byte elements of the rows (eight each) of the table at member 0 of CupRecords.
typedef struct KartCourseResult {
    /* 00 */ u16 mTotalPoints;
    /* 02 */ u8 field2;
    /* 03 */ u8 field3;
    /* 04 */ u8 field4;
    /* 05 */ u8 mWinCount;
    /* 06 */ u16 field6;
    /* 08 */ u8 field8;
    /* 09 */ u8 field9;
} KartCourseResult;

// 4-byte object, two of which make an element of the table at member 0x144 of CupRecords.
typedef struct Unk0217aa1c_144_00 {
    /* 00 */ u16 field0;
    /* 02 */ u8 field2;
    /* 03 */ union {
        u8 field3;
        struct {
            u8 field3_0 : 1;
        };
    };
} Unk0217aa1c_144_00;

// 8-byte elements of the table at member 0x144 of CupRecords.
typedef struct CourseTeamResults {
    /* 00 */ Unk0217aa1c_144_00 mTeams[2];
} CourseTeamResults;

// The kart results for each course of a cup, and the team results.
typedef struct CupRecords {
    /* 000 */ KartCourseResult mKartResults[4][8];
    /* 140 */ s32 field140;
    /* 144 */ CourseTeamResults mTeamResults[4];
    /* 164 */ union {
        u32 field164;
        struct {
            u32 field164_0 : 1;
        };
    };
} CupRecords;

extern CupRecords *rres_sRaceResults;
extern struct Kart *sDrivers;
extern NNSFndList sModelResList;
// The event counters of the selected entry's Kart, allocated by driver_initAll.
struct EntryKartCounters;
extern struct EntryKartCounters *driver_sPlayerStatistics;

// The Camera (mKind 2) that starts at CourseMap.mSecondChainStartEntry; NULL when only the first chain camera exists.
// While its entry is of kind 4 it is not stepped itself: it copies the field of view, mPos and mLookAt of
// cam_sIntroCameraTop, and its entry advances together with the first one's. Its view is the one used on odd frames.
extern Camera *cam_sIntroCameraBottom;
// The Camera (mKind 2) that starts at CourseMap.mFirstChainStartEntry and follows mNextIndex through its entries; the
// only chain camera when gRaceMultiConfig->fieldC is 4. Created by cam_setupIntroCamSingle or cam_setupIntroCamDouble. With
// two chain cameras its view is the one used on even frames of race_sState->mUpdateFrames.
extern Camera *cam_sIntroCameraTop;
extern void *data_usa_0217aa68;
extern s32 cam_sCameraElevation;
extern s32 cam_sCameraDistance;
extern s32 cam_sMaxTargetElevation;
extern u16 cam_sMgIntroCamCount;
