#pragma once

#include "types.h"
#include "03/Net/poll_entry.h"
#include "03/Net/value_records_request_status.h"
#include "cpu_copy_clear_16.h"
#include "alarm_timer.h"
#include "thread_scheduler.h"
#include "thread_mutex_types.h"

// One socket to poll: its descriptor, the events asked for and the events found.
typedef struct PollEntry {
    /* 00 */ s32 mDescriptor;
    /* 04 */ u16 mAskedBits;
    /* 06 */ u16 mFoundBits;
} PollEntry;

void SetPollEntryForRead(s32 value, PollEntry *object);

// Values of ValueRecordsRequest.mResultCode. REPLY_STATUS_FIRST and SECOND are set from the status words -2 and -3 and
// read nowhere.
enum {
    VALUE_RECORDS_RESULT_OK,
    VALUE_RECORDS_RESULT_NO_ENTRY_FOUND,
    VALUE_RECORDS_RESULT_ENTRY_REJECTED,
    VALUE_RECORDS_RESULT_TIMEOUT_STEP0,
    VALUE_RECORDS_RESULT_TIMEOUT_STEP1,
    VALUE_RECORDS_RESULT_TIMEOUT_STEP2,
    VALUE_RECORDS_RESULT_BAD_RECORDS,
    VALUE_RECORDS_RESULT_REPLY_STATUS_FIRST,
    VALUE_RECORDS_RESULT_REPLY_STATUS_SECOND,
    VALUE_RECORDS_RESULT_FAILED = 0xf,
};

// Steps of the request (the mode of RunValueRecordsRequestSteps): send the item chain, send the wanted mask, send the
// finish packet.
#define ESSID_REQUEST_STEP_ITEM_CHAIN 0
#define ESSID_REQUEST_STEP_WANTED_MASK 1
#define ESSID_REQUEST_STEP_FINISH 2

// Values of gErrorCode, what GetErrorCode reports after a request failed. The three NO_VALID_REPLY codes are set when a
// step has used up its attempts without an accepted reply (poll timeout or rejected replies); REPLY_STATUS_FIRST,
// SECOND and OTHER are the status words -2, -3 and any other; 0x1000 plus the step is set when sending failed.
#define ESSID_ERROR_NONE 1
#define ESSID_ERROR_PACKET_BUFFER 2
#define ESSID_ERROR_ITEM_CHAIN_BUILD 3
#define ESSID_ERROR_SOCKET_OPTION 0xb
#define ESSID_ERROR_START_SOCKETS 0xc
#define ESSID_ERROR_NO_REPLY_ITEM_CHAIN 0xf
#define ESSID_ERROR_NO_REPLY_WANTED_MASK 0x10
#define ESSID_ERROR_NO_REPLY_FINISH 0x11
#define ESSID_ERROR_FIRST_RECORD_NOT_WANTED 0x13
#define ESSID_ERROR_REPLY_STATUS_FIRST 0x14
#define ESSID_ERROR_REPLY_STATUS_SECOND 0x15
#define ESSID_ERROR_ITEM_CHAIN_PARSE 0x16
#define ESSID_ERROR_REPLY_STATUS_OTHER 0x18
#define ESSID_ERROR_SEND_FAILED_BASE 0x1000

// Bits of ValueRecordsRequest.mWantedRecordMask: the two records with the WEP keys and the two single-value records.
#define VALUE_RECORD_MASK_KEY_SET_FIRST 1
#define VALUE_RECORD_MASK_KEY_SET_SECOND 2
#define VALUE_RECORD_MASK_SINGLE_VALUE_FIRST 4
#define VALUE_RECORD_MASK_SINGLE_VALUE_SECOND 8
#define VALUE_RECORD_MASK_ALL 0xf

// Retry count and delay a request uses for a limit of -1, the address the device takes and the address it sends to
// first, and the byte every packet header carries at 0x0f.
#define ESSID_REQUEST_DEFAULT_COUNT 10
#define ESSID_REQUEST_DEFAULT_DELAY_MS 100
#define ESSID_REQUEST_OWN_ADDRESS 0xc0a80b65
#define ESSID_REQUEST_FIRST_DESTINATION_ADDRESS 0xc0a80b01
#define ESSID_PACKET_MAGIC_BYTE 0x11

// A value records request: the wanted record mask, the item, retry and timeout settings and the found records.
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

// The state of a value records request: the item bytes, wanted and found record masks and the address and mask.
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

// A found network entry: its name, channel, address, codes, beacon period and mode.
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

// A list of found network entries: the count and the entries.
typedef struct EssidEntryList {
    /* 00 */ s32 mCount;
    /* 04 */ EssidEntry mEntries[1];
} EssidEntryList;

// A request to find a network by name and connect to it: the network name, whether to use a shared key and the key
// bytes.
typedef struct EssidMelcoRequest {
    /* 00 */ u32 mEssidLength;
    /* 04 */ u8 mEssid[0x20];
    /* 24 */ BOOL mUseSharedKey;
    /* 28 */ s32 mMelcoLength;
    /* 2c */ u8 mMelcoBytes[0x10];
} EssidMelcoRequest;

// A mask paired with a code.
typedef struct MaskCodeEntry {
    u16 mMask;
    u8 mCode;
    u8 pad_3;
} MaskCodeEntry;

// Bit of EssidEntry.mCodes set when the record lists the rate as a basic rate.
#define ESSID_RATE_CODE_BASIC 0x80

// The two low bits of RawEntry.mFlags that EssidEntry.mMode is made from.
#define RAW_ENTRY_MODE_MASK 3

// MelcoBlock.mLengthKind takes the WEP_KEY_MODE_ values.
#define MELCO_LENGTH_KIND_WEP_KEY_5_BYTES 1
#define MELCO_LENGTH_KIND_WEP_KEY_13_BYTES 2
#define MELCO_LENGTH_KIND_WEP_KEY_16_BYTES 3

// The key bytes of a connect request and the mode (key length) that goes with them.
typedef struct MelcoBlock {
    /* 00 */ u8 mLengthKind;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u8 mMelcoBytes[0x5e];
} MelcoBlock;

// How many times to retry and how many milliseconds to wait between tries.
typedef struct RetryLimit {
    /* 0 */ s16 mCount;
    /* 2 */ s16 mDelayMs;
} RetryLimit;

// How long to wait: seconds and microseconds (PollSocketWithTimeout scales both by the same factor).
typedef struct WaitTimeout {
    /* 0 */ s32 mSeconds;
    /* 4 */ s32 mMicroseconds;
} WaitTimeout;

// The tag of a packet: six bytes and a sequence number.
typedef struct PacketTag {
    /* 0 */ u8 mBytes[6];
    /* 6 */ u16 mSequence;
} PacketTag;

// The destination and own address a request writes before each send; nothing reads them.
typedef struct SendPacketScratch {
    /* 00 */ u32 mDestinationAddress;
    /* 04 */ u8 pad_04[0xc];
    /* 10 */ u32 mOwnAddress;
} SendPacketScratch;

// A packet buffer: the socket descriptor, the received length and the packet bytes.
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

#include "03/Net/exchange_result_records.h"
#include "03/Net/essid_packet_socket.h"
#include "03/Net/essid_wcm.h"

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

#include "00/Lib/DWC/socket_config.h"

extern SOCConfig gEssidSocketConfig;
extern u8 gItemTypesToFind[2];
extern s32 gReportedState;
extern s32 gSocketDescriptor;
extern RetryLimit gRetryLimitTemplate;
extern s32 gRandomSeeded;
extern EssidEntryList *gScannedEssidList;
extern s32 gUseKeyStream;
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
