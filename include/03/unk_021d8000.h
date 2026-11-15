#pragma once

#include "types.h"
#include "os_thread.h"
#include "03/unk_021d6000.h"
#include "00/code_021a574c.h"
#include "00/code_021a5b3c.h"
#include "00/Lib/DWC/code_02188de4.h"

// Six bytes moved as one value.
typedef struct MacAddress {
    /* 0 */ u8 mBytes[6];
} MacAddress;

// 0x40 bytes moved as one value.
typedef struct Words16 {
    /* 0 */ u32 mWords[16];
} Words16;

// Values of ExchangeResult.mKind: which value set FillExchangeResultFromItems stored; the three WEP_KEY ones hold
// keys of 5, 13 or 16 bytes (given as text of that many characters or twice as many hex digits).
enum {
    EXCHANGE_RESULT_KIND_NONE,
    EXCHANGE_RESULT_KIND_WEP_KEY_5_BYTES,
    EXCHANGE_RESULT_KIND_WEP_KEY_13_BYTES,
    EXCHANGE_RESULT_KIND_WEP_KEY_16_BYTES,
    EXCHANGE_RESULT_KIND_WORDS_A,
    EXCHANGE_RESULT_KIND_WORDS_B,
};

// 0xe8 bytes.
typedef struct ExchangeResult {
    /* 00 */ char mText[0x20];
    /* 20 */ s32 mKind;
    /* 24 */ s32 mItem205Value;
    /* 28 */ u8 mValueBytes[4][0x20];
    /* a8 */ Words16 mItem20aWords;
} ExchangeResult;

// Values of ExchangeResultRecord.mItem202Value: what the record carries. 2 and 3 (bare) carry words and set the result
// kind to 4 and 5.
enum {
    KIND5_ITEM202_NONE,
    KIND5_ITEM202_VALUE_TEXTS,
    KIND5_ITEM202_WORDS_A,
    KIND5_ITEM202_WORDS_B,
};

// 0x60 bytes.
typedef struct ExchangeResultRecord {
    /* 00 */ char mText[0x2c];
    /* 2c */ u32 mItem202Value;
    /* 30 */ s32 mItem205Value;
    /* 34 */ u8 mUnk_34[0x28];
    /* 5c */ s32 mStoreValuesAsHex;
} ExchangeResultRecord;

// 0x48 bytes.
typedef struct ExchangeResultItem20a {
    /* 00 */ Words16 mBytes;
    /* 40 */ u32 mUnk_40[2];
} ExchangeResultItem20a;

// Entry of the list at gRawEntries, 0xc0 bytes.
typedef struct RawEntry {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ MacAddress mAddress;
    /* 0a */ u16 mSsidLength;
    /* 0c */ u8 mSsid[0x20];
    /* 2c */ u16 mFlags;
    /* 2e */ u16 mBasicRateSet;
    /* 30 */ u16 mSupportRateSet;
    /* 32 */ u16 mBeaconPeriod;
    /* 34 */ u16 mUnk_34;
    /* 36 */ u16 mChannel;
    /* 38 */ u8 pad_38[0x88];
} RawEntry;

// The items of the result packet, 0x254 bytes. The words below the record are only cleared with the rest; the values are
// four 0x28-byte slots (0x20 characters, then two words that items 0x203 and 0x204 store) addressed from the byte
// array.
typedef struct ExchangeResultItems {
    /* 000 */ u32 mWords[0x40];
    /* 100 */ ExchangeResultRecord mRecord;
    /* 160 */ u8 mUnk_160[4];
    /* 164 */ u8 mValues[0x98];
    /* 1fc */ ExchangeResultItem20a mItem20a;
    /* 244 */ u8 mUnk_244[0x10];
} ExchangeResultItems;

#include "03/Net/essid_packet_steps.h"
