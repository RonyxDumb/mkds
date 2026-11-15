#pragma once

#include "types.h"
#include "03/code_021b7ba8.h"
#include "03/code_021c1f34.h"
#include "code_0214cfe4.h"
#include "code_0200f790.h"
#include "os_thread.h"
#include "code_0200e77c.h"

typedef struct PollEntry {
    /* 00 */ s32 mDescriptor;
    /* 04 */ u16 mAskedBits;
    /* 06 */ u16 mFoundBits;
} PollEntry;

void SetPollEntryForRead(s32 value, PollEntry *object);

// Values of ValueRecordsRequest.mResultCode. 7 and 8 are set from the status words -2 and -3 and read nowhere.
enum {
    VALUE_RECORDS_RESULT_OK,
    VALUE_RECORDS_RESULT_NO_ENTRY_FOUND,
    VALUE_RECORDS_RESULT_ENTRY_REJECTED,
    VALUE_RECORDS_RESULT_TIMEOUT_STEP0,
    VALUE_RECORDS_RESULT_TIMEOUT_STEP1,
    VALUE_RECORDS_RESULT_TIMEOUT_STEP2,
    VALUE_RECORDS_RESULT_BAD_RECORDS,
    VALUE_RECORDS_RESULT_FAILED = 0xf,
};

typedef struct ValueRecordsRequest {
    /* 000 */ u16 mWantedRecordMask; // input mask; on return, the wanted records that were found
    /* 002 */ ValueRecordsRequestItem mItem;
    /* 106 */ s16 mScanRetryLimit;
    /* 108 */ s16 mScanRetryDelayMs;
    /* 10a */ s16 mSendAttemptLimit;
    /* 10c */ s16 mSendAttemptDelayMs;
    /* 10e */ s16 mReceiveTimeoutMs;
    /* 110 */ u8 mMacAddress[6];
    /* 116 */ u8 mResultCode;
    /* 117 */ u8 mRecordBytes[0x154];
} ValueRecordsRequest;

typedef struct RequestState {
    /* 00 */ u8 *mItemBytes;
    /* 04 */ u32 mItemLength;
    /* 08 */ u32 mWantedRecordMask;
    /* 0c */ s32 mFoundRecordMask;
    /* 10 */ u32 mDestinationAddress;
    /* 14 */ u32 mAddressMask;
    /* 18 */ s8 mAddressApplied;
    /* 19 */ s8 mItemType;
    /* 1a */ u8 pad_1a[2];
} RequestState;

typedef struct RawEntry RawEntry;

typedef struct EssidEntry {
    /* 00 */ u32 mEssidLength;
    /* 04 */ u8 mEssid[0x20];
    /* 24 */ u32 mChannel;
    /* 28 */ u8 pad_28[8];
    /* 30 */ u8 mAddress[6];
    /* 38 */ u32 mCodeCount;
    /* 3c */ u8 mCodes[0x10]; // bit 0x80 set when the record's second bit list has the same bit
    /* 4c */ u32 mBeaconPeriod;
    /* 50 */ u32 mMode;
} EssidEntry;

typedef struct EssidEntryList {
    /* 00 */ s32 mCount;
    /* 04 */ EssidEntry mEntries[1];
} EssidEntryList;

/* Search request handed to RunEssidMelcoRequest. */
typedef struct EssidMelcoRequest {
    /* 00 */ u32 mEssidLength;
    /* 04 */ u8 mEssid[0x20];
    /* 24 */ BOOL mUseSharedKey;
    /* 28 */ s32 mMelcoLength;
    /* 2c */ u8 mMelcoBytes[0x10];
} EssidMelcoRequest;

typedef struct MaskCodeEntry {
    u16 mMask;
    u8 mCode;
    u8 pad_3;
} MaskCodeEntry;

// Bit of EssidEntry.mCodes set when the record lists the rate as a basic rate.
#define ESSID_RATE_CODE_BASIC 0x80

// The two low bits of RawEntry.mFlags that EssidEntry.mMode is made from.
#define RAW_ENTRY_MODE_MASK 3

// Values of MelcoBlock.mLengthKind: the length of the key bytes.
#define MELCO_LENGTH_KIND_WEP_KEY_5_BYTES 1
#define MELCO_LENGTH_KIND_WEP_KEY_13_BYTES 2
#define MELCO_LENGTH_KIND_WEP_KEY_16_BYTES 3

typedef struct MelcoBlock {
    /* 00 */ u8 mLengthKind;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u8 mMelcoBytes[0x5e];
} MelcoBlock;

typedef struct RetryLimit {
    /* 0 */ s16 mCount;
    /* 2 */ s16 mDelayMs;
} RetryLimit;

typedef struct WaitTimeout {
    /* 0 */ s32 mSeconds;
    /* 4 */ s32 mMicroseconds;
} WaitTimeout;

typedef struct PacketTag {
    /* 0 */ u8 mBytes[6];
    /* 6 */ u16 mSequence;
} PacketTag;

typedef struct SendPacketScratch {
    /* 00 */ u32 mDestinationAddress;
    /* 04 */ u8 pad_04[0xc];
    /* 10 */ u32 mOwnAddress;
} SendPacketScratch;

typedef struct PacketBuffer {
    /* 00 */ s32 mDescriptor;
    /* 04 */ u32 mReceivedLength; // stored byte-swapped; never read
    /* 08 */ u8 pad_08[4];
    /* 0c */ u8 mBytes[0x5ec];
} PacketBuffer;

void SetErrorCode(s32 code);
void InitRequestState(ValueRecordsRequest *req);
void ReleaseEssidEntryLists(void);
u32 GetNextAddressInMask(u32 addr, u32 mask);
s32 RunValueRecordsRequestSteps(ValueRecordsRequest *req);
s32 RunValueRecordsRequest(ValueRecordsRequest *req);
void CallEssidFreeFunction(void *ptr);
void *CallEssidAllocFunction(u32 size);
s32 CallStateChangeCallback(s32 state);
void EssidSleepWrapper(u32 ms);
s32 RunEssidMelcoRequest(EssidMelcoRequest *request, EssidEntryList *out);
s32 ScanEssidEntries(EssidEntryList **out);
s32 DisconnectEssidAndWait(void);
s32 ReleaseEssidWiFi(void);
s32 InitEssidWiFi(void *(*alloc)(u32), void (*release)(void *));
s32 AlarmSendQueueMessage(void *msg);
s32 SendQueueMessage(void *msg);
void FillEssidEntryListFromRecord(EssidEntryList *list, RawEntry *src, s32 count);
void SetRecordEssidFromRequest(EssidMelcoRequest *request, RawEntry *rec);
void ConvertRecordToEssidEntry(RawEntry *src, EssidEntry *dst);

#include "03/code_021b7000.h"
#include "03/unk_021d8000.h"
#include "03/code_021b7bb4.h"
#include "03/code_021ba818.h"

// Item whose payload starts with the chain of its sub-items.
typedef struct ItemContainerView {
    union {
        PacketItem mItem;
        struct {
            /* 0 */ u8 mType;
            /* 1 */ u8 mUnk_01;
            /* 2 */ u16 mLength;
            union {
                /* 4 */ u32 mFirstWord;
                PacketItem mFirstItem;
            };
        };
    };
} ItemContainerView;

#include "00/Lib/DWC/code_0218a064.h"

extern SOCConfig gEssidSocketConfig;
extern u8 gItemTypesToFind[2];
extern s32 gReportedState;
extern s32 gSocketDescriptor;
extern RetryLimit gRetryLimitTemplate;
extern s32 gRandomSeeded;
extern EssidEntryList *gScannedEssidList;
extern s32 gKeyStreamAccepted;
extern EssidEntryList *gRequestedEssidList;
extern PacketBuffer *gRequestPacketBuffer;
extern s32 gErrorCode;
extern u8 gSavedTagBytes[8];
extern u32 gRandomState[3];
extern RequestState gRequestState;
extern u8 gKeyStreamKey[0x64];
extern u8 gItemSlots[0x280];
extern u32 gCrcTable[0x100];
extern ParsedItems gParsedItems[2];
