#pragma once

#include "types.h"
#include "00/code_021a88a8.h"

typedef struct HttpsState HttpsState;

#include "00/unk_021b4000.h"
#include "os_thread.h"
#include "mb_data.h"

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

#include "00/Lib/CPS/network.h"
#include "00/unk_021b6380.h"
#include "00/Lib/CPS/code_021ac3e4.h"
#include "00/types_021ab5e4.h"

void CPSi_SslShutdown(CPSSoc *connection);
s32 SendHttpsBytesInChunks(const u8 *firstBytes, u32 firstLength, const u8 *secondBytes, u32 secondLength,
                           CPSSoc *connection);
s32 ReadHttpsRecordIfBufferedAndGetUnreadByteCount(CPSSoc *connection);
void SkipHttpsReceivedBytes(u32 count, CPSSoc *connection);
u8 *ReadHttpsRecordsUntilBytesReceived(u32 *unreadCount, CPSSoc *connection);
BOOL CPSi_SslConnect(CPSSoc *connection);
BOOL RunSetupAfterSendingOfferRecord(CPSSoc *connection);
void RunSetupAfterReadingOfferRecordUntilDone(CPSSoc *connection);
BOOL RunSetupAfterReadingOfferRecord(CPSSoc *connection);
u32 ReadRecordsExpectingStates7And6(CPSSoc *connection);
void send_client_key_exchange(CPSSoc *connection);
void SendOfferRecord(CPSSoc *connection);
void SendOneByteRecordAndMessageDigests(CPSSoc *connection);
u8 SendAnswerRecord(CPSSoc *connection);
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
