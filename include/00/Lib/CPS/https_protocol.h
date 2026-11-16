#pragma once

#include "types.h"
#include "00/Lib/CPS/socket_status_resolve.h"

// Tags of the items the certificate reader walks through (the type bits of the tag byte).
enum {
    ITEM_TAG_INTEGER = 0x02,
    ITEM_TAG_SKIP_FIRST_BYTE = 0x03,
    ITEM_TAG_PREFIX_LOOKUP = 0x06,
    ITEM_TAG_SEQUENCE = 0x10,
    ITEM_TAG_SET = 0x11,
    ITEM_TAG_DATE_TWO_DIGIT_YEAR = 0x17,
    ITEM_TAG_DATE_FOUR_DIGIT_YEAR = 0x18,
};

// Values of the mode argument of ParseTaggedItem: 0 keeps the first and second value of the first item, 1 keeps
// neither, 2 stores modulus and exponent in mItemRecord.
enum {
    TAGGED_ITEM_MODE_KEEP_VALUES = 0,
    TAGGED_ITEM_MODE_SKIP_VALUES = 1,
    TAGGED_ITEM_MODE_ITEM_RECORD = 2,
};

// Positions in gTaggedItemPrefixes, the byte prefixes the walk looks for.
enum {
    TAGGED_ITEM_NONE,
    TAGGED_ITEM_RSA_ENCRYPTION,
    TAGGED_ITEM_RSA_ALGORITHM,
    TAGGED_ITEM_MD5_WITH_RSA,
    TAGGED_ITEM_SHA1_WITH_RSA,
    TAGGED_ITEM_COMMON_NAME,
};

// Types of a record, the types of the handshake messages inside a handshake record, and the length of the record
// header.
enum {
    TLS_RECORD_TYPE_CIPHER = 0x14,
    TLS_RECORD_TYPE_STATUS = 0x15,
    TLS_RECORD_TYPE_HANDSHAKE = 0x16,
    TLS_RECORD_TYPE_DATA = 0x17,
};

enum {
    TLS_HANDSHAKE_OFFER = 1,
    TLS_HANDSHAKE_ANSWER = 2,
    TLS_HANDSHAKE_CERTIFICATE = 0x0b,
    TLS_HANDSHAKE_REPLY_END = 0x0e,
    TLS_HANDSHAKE_CLIENT_KEY_EXCHANGE = 0x10,
    TLS_HANDSHAKE_DIGESTS = 0x14,
};

#define TLS_RECORD_HEADER_SIZE 5

typedef struct HttpsState HttpsState;

#include "00/Lib/wifi_library_globals.h"
#include "thread_scheduler.h"
#include "multiboot_piece_buffers.h"

typedef struct CPSSoc CPSSoc;

typedef struct HttpsState HttpsState;

typedef struct HttpsState HttpsState;

typedef struct HttpsState HttpsState;

typedef struct HttpsState HttpsState;

typedef struct HttpsState HttpsState;

typedef struct HttpsState HttpsState;

typedef struct HttpsState HttpsState;

// Six length and pointer pairs.
typedef struct CPSPrivateKey {
    /* 00 */ u32 mModulusLength;
    /* 04 */ const u8 *mModulus;
    /* 08 */ u32 mPrime1Length;
    /* 0c */ const u8 *mPrime1;
    /* 10 */ u32 mPrime2Length;
    /* 14 */ const u8 *mPrime2;
    /* 18 */ u32 mExponent1Length;
    /* 1c */ const u8 *mExponent1;
    /* 20 */ u32 mExponent2Length;
    /* 24 */ const u8 *mExponent2;
    /* 28 */ u32 mCoefficientLength;
    /* 2c */ const u8 *mCoefficient;
} CPSPrivateKey;

typedef struct HttpsState HttpsState;

typedef struct CPSCaInfo CPSCaInfo;
typedef struct HttpsState HttpsState;

typedef struct HttpsState HttpsState;

typedef struct HttpsEntry HttpsEntry;

#include "00/Lib/CPS/tcp_ip_stack.h"
#include "00/Lib/CPS/network_state.h"
#include "00/Lib/CPS/big_integer_power_and_rc4.h"
#include "00/Lib/CPS/https_entry.h"

void CPSi_SslShutdown(CPSSoc *connection);
s32 SendHttpsBytesInChunks(const u8 *firstBytes, u32 firstLength, const u8 *secondBytes, u32 secondLength,
                           CPSSoc *connection);
s32 ReadHttpsRecordIfBufferedAndGetUnreadByteCount(CPSSoc *connection);
void SkipHttpsReceivedBytes(u32 count, CPSSoc *connection);
u8 *ReadHttpsRecordsUntilBytesReceived(u32 *unreadCount, CPSSoc *connection);
BOOL CPSi_SslConnect(CPSSoc *connection);
BOOL RunSetupBySendingOfferRecord(CPSSoc *connection);
void RunSetupByReadingOfferRecordUntilDone(CPSSoc *connection);
BOOL RunSetupByReadingOfferRecord(CPSSoc *connection);
u32 ReadRecordsExpectingStates7And6(CPSSoc *connection);
void send_client_key_exchange(CPSSoc *connection);
void SendOfferRecord(CPSSoc *connection);
void SendOneByteRecordAndMessageDigests(CPSSoc *connection);
u8 SendReplyRecord(CPSSoc *connection);
void MixBytesIntoRandomState(void *bytes, u32 byteCount);
void FillNonzeroRandomBytes(u8 *out, s32 count);
u8 ReadHttpsRecordAndSetState(CPSSoc *connection);
u32 ReadExactReceivedBytes(u8 *dest, s32 count, CPSSoc *connection);
s32 AppendDigestAndXorSentRecordWithKeyStream(void *rawHttpsState, u8 *recordArg);
s32 XorReceivedRecordWithKeyStreamAndCheckDigest(HttpsState *httpsState, u8 *record);
unsigned int XorReceivedBytesWithKeyStream(HttpsState *httpsState, u8 *bytes, unsigned int count);
void IncrementBigEndianBytes(u8 *bytes, s32 count);
void CheckMessageDigestsAndSetState(HttpsState *httpsState, u8 *receivedDigests);
void ComputeLabeledMessageDigest20(HttpsState *httpsState, u8 *digest, u32 fromOtherSide);
void ComputeLabeledMessageDigest16(HttpsState *httpsState, u8 *digest, u32 fromOtherSide);
void rcv_client_key_exchange(HttpsState *httpsState, const u8 *encryptedSecret);
void DeriveBytesAndInitKeyStreamStates(HttpsState *httpsState);
void ReplaceEntryBytesWithLabeledDigests(HttpsState *httpsState);
void ComputeLabeledDigest16(u8 *digest, const u8 *label, HttpsState *httpsState);
void decrypt_premaster_secret(u8 *secret, const u8 *encrypted, CPSPrivateKey *privateKey);
void ParseOfferMessage(HttpsState *httpsState, const u8 *message);
void ParseOfferMessageWithThreeByteValues(HttpsState *httpsState, u8 *message);
u32 IsFirstArgumentThree(int value, int unusedArgument);
u32 FindOfferedValueInList(const u8 *list, s32 count, s32 width);
BOOL IsBigEndianValueInList(const u8 *list, s32 count, s32 width, u32 value);
void ParseAnswerMessage(HttpsState *httpsState, u8 *message);
void ParseAndCheckItemListMessage(HttpsState *httpsState, u8 *cursor);
BOOL CompareTextWithWildcard(const s8 *text, const s8 *pattern);
s32 GetTextLengthUpToDot(const s8 *text);
u32 ComputeParsedItemCheckFlags(HttpsState *httpsState);
u32 CheckTransformedBytesHoldPaddedDigest(HttpsState *httpsState, CPSCaInfo *authority);
BOOL ParseTaggedItem(HttpsState *httpsState, u8 **position, s32 depth, s32 index, s32 mode);
u32 ParseDateText(const u8 *digits, u32 tag);
void AppendCommaSeparatedText(s8 *dest, const s8 *source, s32 count);
s32 ReadLengthAndAdvance(u8 **position);
CPSCaInfo *FindAuthorityByName(HttpsState *httpsState, const s8 *name);
void SetAuthorityTable(CPSCaInfo **table, u32 count);
u32 GetRtcSecondsPlusFixedOffset(void);
HttpsEntry *AddEntryOrReplaceLongestUnused(const u8 *bytes);
HttpsEntry *FindEntryByValuePairAndSetLastUseTime(u32 firstValue, u32 secondValue);
HttpsEntry *FindEntryByBytesAndSetLastUseTime(const u8 *wantedBytes);

// Set to 1 once bytes have been mixed into gRandomByteState.
extern u8 gRandomByteStateMixed;
// Counts the entries made while sending the kind 2 record; its value is written as the last four bytes of each new
// entry's first 0x20 bytes.
extern u32 gNewEntryIdCount;
extern u8 gRandomByteState[0x14];
extern HttpsEntry gUncachedHttpsEntry;
extern HttpsEntry gHttpsEntries[4];
