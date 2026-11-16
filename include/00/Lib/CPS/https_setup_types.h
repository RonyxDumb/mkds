#pragma once

#include "types.h"
#include "00/Lib/DWC/ca_info.h"
#include "00/Lib/CPS/md5_internal_hash.h"
#include "00/Lib/CPS/sha1_update.h"

#define MD5_DIGEST_SIZE 0x10
#define SHA1_DIGEST_SIZE 0x14

typedef struct HttpsEntry HttpsEntry;
typedef struct CPSPrivateKey CPSPrivateKey;

// Length and pointer of the item list an answer record sends (mItemList).
typedef struct ItemList {
    /* 0 */ u32 mLength;
    /* 4 */ u8 *mBytes;
} ItemList;

// Values of HttpsState.mSetupState; the record handlers set the ones between START and COMPLETE. OFFER and ANSWER are
// the handshake messages of type 1 and 2; ANSWER_END is the message of type 0xe, which has no body and ends the answer
// record.
typedef enum HttpsSetupState {
    HTTPS_SETUP_START = 0,
    HTTPS_SETUP_OFFER_RECEIVED = 1,
    HTTPS_SETUP_ANSWER_RECEIVED = 2,
    HTTPS_SETUP_ITEM_LIST_CHECKED = 3,
    HTTPS_SETUP_ANSWER_END_RECEIVED = 4,
    HTTPS_SETUP_KEYS_DERIVED = 5,
    HTTPS_SETUP_DIGESTS_MATCHED = 6,
    HTTPS_SETUP_CIPHER_RECORD_RECEIVED = 7,
    HTTPS_SETUP_COMPLETE = 8,
    HTTPS_SETUP_FAILED = 9,
} HttpsSetupState;

struct HttpsState;
typedef u32 (*HttpsCheckFlagsCallback)(u32 flags, struct HttpsState *httpsState, s32 itemIndex);

// Values of HttpsState.mCommonValue, the two values in gOfferedValues: the record digest is made with the MD5 code (16
// bytes) or the 20-byte hash code.
enum {
    HTTPS_COMMON_VALUE_MD5 = 4,
    HTTPS_COMMON_VALUE_HASH20,
};

// The https layer state of one connection: its entry, setup blocks, key streams, hashes and certificate checks.
typedef struct HttpsState {
    // The entry in use, or NULL; may be gUncachedHttpsEntry, which is not in the table.
    /* 000 */ HttpsEntry *mEntry;
    /* 004 */ u8 mReusedEntry;
    /* 005 */ u8 mUnk_005;
    /* 006 */ u16 mCommonValue;
    /* 008 */ u8 mOfferBlock[0x20];
    /* 028 */ u8 mAnswerBlock[0x20];
    /* 048 */ u8 mDerivedBytes[0x48];
    /* 090 */ u8 *mSendDigestBytes;
    /* 094 */ u8 *mSendKeyStreamBytes;
    /* 098 */ u8 *mUnk_098;
    /* 09c */ u8 mSendKeyStreamState[0x104];
    /* 1a0 */ u8 mSendRecordCount[8];
    /* 1a8 */ u8 *mReceiveDigestBytes;
    /* 1ac */ u8 *mReceiveKeyStreamBytes;
    /* 1b0 */ u8 *mUnk_1b0;
    /* 1b4 */ u8 mReceiveKeyStreamState[0x104];
    /* 2b8 */ u8 mReceiveRecordCount[8];
    /* 2c0 */ Hash20Context mMessageHash20;
    /* 31c */ Hash20Context mScratchHash20;
    /* 378 */ CPSMd5Ctx mMessageHash16;
    /* 3d0 */ CPSMd5Ctx mScratchHash16;
    // 1 on the side that receives the type 1 message, 0 on the side that sends it.
    /* 428 */ u8 mReceivesOfferRecord;
    /* 429 */ u8 mSetupState;
    /* 42c */ s32 mDigestKind;
    // Table position (1 or 2) stored by ParseTaggedItem for the first item of a list; -1 when none was stored, which
    // makes the flags carry 4.
    /* 430 */ s32 mTaggedItemPrefixIndex;
    /* 434 */ u8 *mDigestStart;
    /* 438 */ u8 *mDigestEnd;
    /* 43c */ u8 mRangeDigest[SHA1_DIGEST_SIZE];
    /* 450 */ s32 mRangeDigestLength;
    /* 454 */ CPSCaInfo mItemRecord;
    /* 468 */ u8 mFirstValue[0x100];
    /* 568 */ u32 mFirstValueLength;
    /* 56c */ u8 mSecondValue[8];
    /* 574 */ u32 mSecondValueLength;
    /* 578 */ u8 *mCheckedBytes;
    /* 57c */ s32 mCheckedBytesLength;
    /* 580 */ u8 mDatesSeen;
    /* 581 */ u8 mCaptureValues;
    /* 582 */ u8 mCopyNextText;
    /* 583 */ u8 mDateInRange;
    /* 584 */ s8 mAuthorityName[0x100];
    // Text items seen after the dates, joined with ', '; written, never read.
    /* 684 */ s8 mCommaSeparatedText[0x100];
    /* 784 */ s8 mHostPattern[0x50];
    /* 7d4 */ s8 *mHost;
    /* 7d8 */ u8 *mItemBytes;
    /* 7dc */ s32 mItemLength;
    /* 7e0 */ u32 mCurrentDate;
    /* 7e4 */ HttpsCheckFlagsCallback mCheckFlagsCallback;
    /* 7e8 */ CPSCaInfo **mAuthorities;
    /* 7ec */ u32 mAuthorityCount;
    /* 7f0 */ CPSPrivateKey *mPrivateKey;
    /* 7f4 */ ItemList *mItemList;
    /* 7f8 */ u8 *mReceivedBlock;
    /* 7fc */ u32 mReceivedBlockEnd;
    /* 800 */ u32 mReceivedBlockOffset;
} HttpsState;
