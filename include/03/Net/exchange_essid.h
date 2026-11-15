#pragma once

#include "types.h"
#include "03/Net/exchange_wcm_state.h"
#include "03/Menu/exchange_status_record.h"

typedef struct ExchangeResult ExchangeResult;

typedef void (*ExchangeStatusCallback)(const ExchangeStatus *status);
typedef u32 (*ExchangeAllocFunc)(u32 size);
typedef void (*ExchangeFreeFunc)(void *block);

typedef struct HashContext HashContext;

// Four hash words, two bit-count words and the 0x40-byte block being filled.
typedef struct HashContext {
    /* 00 */ u32 mHashWords[4];
    /* 10 */ u32 mBitCountLow;
    /* 14 */ u32 mBitCountHigh;
    /* 18 */ u8 mBuffer[0x40];
} HashContext;

// Value of the third item of the first reply packet.
typedef struct ExchangeIndexBytes {
    /* 0 */ u8 mBytes[7];
} ExchangeIndexBytes;

// The eight bytes the peer sends for the second key.
typedef struct SecondKeyPart {
    /* 0 */ u8 mBytes[8];
} SecondKeyPart;

// The five, thirteen and sixteen byte WEP keys of an exchanged entry.
typedef struct WepKey5 {
    /* 0 */ u8 mBytes[5];
} WepKey5;

// A thirteen byte WEP key.
typedef struct WepKey13 {
    /* 0 */ u8 mBytes[13];
} WepKey13;

// A sixteen byte WEP key.
typedef struct WepKey16 {
    /* 0 */ u8 mBytes[16];
} WepKey16;

#include "03/Net/exchange_result_records.h"
#include "00/Lib/DWC/code_0218a064.h"
#include "03/Menu/wifi_menu_tables.h"
#include "os_thread.h"
#include "00/Lib/GameSpy/code_0218e2dc.h"

// UDP port the exchange packets are sent to and received on.
#define EXCHANGE_SOCKET_PORT 0x1e6

// Values of gExchangeState, the steps of RunExchange.
#define EXCHANGE_STEP_SEARCH_ENTRY 1
#define EXCHANGE_STEP_CONNECT 2
#define EXCHANGE_STEP_OPEN_SOCKET 3
#define EXCHANGE_STEP_WAIT_FIRST_PACKET 4
#define EXCHANGE_STEP_SEND_FIRST_REPLY 5
#define EXCHANGE_STEP_WAIT_SECOND_KEY 6
#define EXCHANGE_STEP_SEND_KEY_HASH 7
#define EXCHANGE_STEP_WAIT_RESULT 8
#define EXCHANGE_STEP_SEND_RESULT_ACK 9
#define EXCHANGE_STEP_WAIT_ACK_RESEND 10

// Bit of RawEntry.mFlags that is set for an entry with encryption.
#define RAW_ENTRY_FLAG_ENCRYPTED 0x10

// First byte of a one-character SSID that stands for no name.
#define EXCHANGE_SSID_BLANK_CHAR 0x20

// Eight bytes passed by address.
typedef struct SocketAddress {
    /* 0 */ u8 mLength;
    /* 1 */ u8 mFamily;
    /* 2 */ u16 mPort;
    /* 4 */ u32 mAddress;
} SocketAddress;

// One 0x30-byte record cut from a RawEntry: name, its length, address and whether it is secured.
typedef struct EntrySummary {
    /* 00 */ u32 mSsidLength;
    /* 04 */ char mSsid[0x20];
    /* 24 */ u8 mUnk_24[4];
    /* 28 */ MacAddress mAddress;
    /* 2e */ u16 mEncrypted;
} EntrySummary;

// A list of entry summaries: the count and the summaries.
typedef struct EntrySummaryList {
    /* 0 */ u32 mCount;
    /* 4 */ EntrySummary mEntries[1];
} EntrySummaryList;

void CallStatusCallback(void);
u32 CopyExchangeResult(ExchangeResult *output);
u32 GetExchangeStatus(u32 *output);
s32 StopExchange(void);
s32 StartExchange(u32 priority, s32 count, ExchangeStatusCallback callback, ExchangeAllocFunc allocFunction,
                  ExchangeFreeFunc freeFunction, u32 stackSize);
s32 FormatMacAddress(u8 *output, const s8 *address);
s32 FormatByteAsHex(u8 *output, s8 value);
void CallFreeFunction(void *block);
void *CallAllocFunctionAndClear(s32 count, s32 size);
u32 GetTickMilliseconds(void);
void ComputeHash(u8 *digest, const u8 *input, u32 size);
void FillBytesWithLoop(void *buffer, s32 value, u32 count);
void CopyBytesWithLoop(void *destination, const void *source, u32 count);
void CopyBytesToWordsLittleEndian(u32 *output, const u8 *input, u32 size);
void CopyWordsToBytesLittleEndian(u8 *output, const u32 *input, u32 size);
void ProcessHashBlock(HashContext *hashA, const u8 *hashB);
void FinishHash(u8 *digest, HashContext *context);
void AddBytesToHash(HashContext *context, const u8 *bytes, u32 count);
void ResetHashContext(HashContext *context);
void TransformBlockReversed(u32 *keyWords, int lastGroup, u8 *input, u8 *output);
void TransformBlock(u32 *keyWords, int lastGroup, u8 *input, u8 *output);
int ExpandKeyReversedWithTables(u32 *words, u8 *key, int keyBits);
int ExpandKey(u32 *words, u8 *key, int keyBits);
void XorEightBytes(u8 *first, u8 *second, u8 *output);
BOOL TransformBodyReversedWithKey(u8 *output, u8 *input, u32 inputLength, u8 *key, int keyLength);
BOOL TransformBodyWithKey(u8 *output, u8 *input, u32 inputLength, u8 *key, int keyLength);
void RunExchangeThread(void);
int RunExchange(void);
s32 FillExchangeResultFromItems(void);
BOOL ParseHexText(u8 *output, const s8 *text, s32 length);
s32 ParseExchangeResultPacketItems(u8 *body);
s32 StoreMacAddressAndBuildKey(u8 *key, void *unused);
unsigned int GetMacAddress(void *address);
s32 BuildFirstReplyPacket(u8 *packet);
s32 ReadExchangePacketPayloadOfKind(const u8 *packet, u32 kind, u8 *output, const void *key);
BOOL ParseAndCheckFirstExchangePacket(const u8 *packet, u32 *item5Flag);
s32 BuildSingleItemBody(u8 *out, u32 type, const void *value, u32 length);
u8 *AppendItem(u8 *out, u32 type, const void *value, u32 length);
s32 BuildExchangePacket(u8 *packet, u32 kind, u8 *body, u32 length, const void *key);
u8 *ReadFirstItem(const u8 *body, u32 *type, s32 *length);
u8 *ReadNextItem(u8 **cursor, u8 *end, u32 *type, s32 *length);
u8 *ReadExchangePacketAndCheckSum(const u8 *packet, u32 *kind, s32 *length);
s32 SendBytesToAllOnesAddressWrapper(s32 descriptor, const void *unused, const void *data, u32 size);
s32 SendBytesToAllOnesAddress(s32 descriptor, const void *data, u32 size);
s32 SendBytesToAddress(s32 descriptor, const SocketAddress *address, const u8 *unused, const void *data, u32 size);
s32 SearchEntriesAndStoreEntryWithEncryptionRemoved(void);
s32 FindEntryWithEncryptionRemoved(EntrySummaryList *current, EntrySummaryList *previous, u32 *foundIndex);
void DisconnectExchangeAndStopSockets(void);
s32 ConnectExchangeAndStartSockets(void);
u32 ReleaseExchangeWiFi(void);
s32 InitExchangeWiFi(u32 entryCount);
void EnqueueEvent(u32 value);
void EnqueueEventEx(u32 value, u32 unused);
u32 DequeueEvent(void);
void ClearEventQueue(void);
void CallFreeFunctionWithMutex(u32 unused, void *block, s32 size);
u32 CallAllocFunctionWithMutex(u32 unused, s32 size);
u32 GetExchangeWcmState(void);

// Objects whose layout isn't known yet.
extern const u32 gKeyRoundConstants[10];
extern const u32 gSubstitutionTable[256];
extern const u32 gTransformTableByte0[256];
extern const u32 gReversedTableByte0[256];
extern const u32 gTransformTableByte2[256];
extern const u32 gTransformTableByte3[256];
extern const u32 gReversedSubstitutionTable[256];
extern const u32 gTransformTableByte1[256];
extern const u32 gReversedTableByte1[256];
extern const u32 gReversedTableByte3[256];
extern const u32 gReversedTableByte2[256];

extern SOCConfig gExchangeSocketConfig;
extern u32 gFormatAddressesFlag;
extern u32 gThreadStackSize;
extern s32 gTimeoutAtMs;
extern s32 gStartEntryCount;
extern char gSixAsterisksString[7];
extern ExchangeIndexBytes gFirstReplyIndexBytes;
extern u8 gHashPadding[64];
extern u8 gPacketBuffer[0x800];
extern u8 gBodyBuffer[0x800];
extern ExchangeResultItems gExchangeResultItems;
extern ExchangeResult gExchangeResult;
extern OSThread gExchangeThread;
extern char gSelectedEntryName[36];
extern u8 gExchangeSearchEssidBytes[0x20];
extern u8 gSecondKeyHashedPart[24];
extern SecondKeyPart gSecondKeyReceivedPart;
