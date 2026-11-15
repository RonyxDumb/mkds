#pragma once

#include "types.h"

// Values of ApEntry.mWepMode: none, or the key length in bytes (a key is also written as twice that many hex digits).
enum {
    AP_WEP_MODE_NONE,
    AP_WEP_MODE_KEY_5_BYTES,
    AP_WEP_MODE_KEY_13_BYTES,
    AP_WEP_MODE_KEY_16_BYTES,
};

// Values of ApEntry.mSetType: ENTERED is stored with the SSID by hand, EXCHANGED by the received settings.
enum {
    AP_SET_TYPE_ENTERED,
    AP_SET_TYPE_EXCHANGED = 2,
    AP_SET_TYPE_EMPTY = 0xff,
};

// 0xf0 bytes; the object at gApStore holds four of them at a stride of 0x100.
typedef struct ApEntry {
    /* 00 */ u8 mIspId[0x20];
    /* 20 */ u8 mIspPass[0x20];
    /* 40 */ u8 mSsids[2][0x20];
    /* 80 */ u8 mWepKeys[4][0x10];
    /* c0 */ u8 mIp[4];
    /* c4 */ u8 mGateway[4];
    /* c8 */ u8 mDns[8];
    /* d0 */ u8 mNetmaskCidr;
    /* d1 */ u8 mWep2Keys[4][5];
    /* e5 */ u8 mAuthType;
    /* e6 */ u8 mWepMode : 2;
    /* e6 */ u8 mWepNotation : 6;
    /* e7 */ u8 mSetType;
    /* e8 */ u8 mReserved[7];
    /* ef */ u8 mEntrySetBits;
} ApEntry;

// Entry at offset 0x400 of the object at gApStore, and the bytes after it.
typedef struct ApWorkCopy {
    /* 00 */ ApEntry mEntry;
    /* f0 */ u8 mNetmask[4];
    /* f4 */ u8 mEntryIndex;
    /* f5 */ u8 mIpNone;
    /* f6 */ u8 mDnsNone;
    /* f7 */ u8 pad_f7;
    /* f8 */ u16 mCrcTable;
} ApWorkCopy;

// Object at gApStore, as far as WriteApWorkFromExchangeResult through CopyApEntryToWorkCopy use it.
typedef struct ApStore {
    /* 000 */ struct {
        ApEntry mEntry;
        u8 mPackedWiFiInfo[0xe];
        u16 mCrc;
    } mPages[4];
    /* 400 */ ApWorkCopy mWorkCopy;
} ApStore;

typedef struct ExchangeResult ExchangeResult;

void ParseAddressText(const char *input, u8 *output);
void WriteApEntryToNvram(s32 entryIndex);
void ResetApEntries(void);
void ResetApEntry(int entryIndex);
struct ApStore *GetApStore(void);
void WriteApWorkFromAossResult(int response);
void WriteApWorkFromExchangeResult(const ExchangeResult *exchangeResult);
void WriteApWorkCopy(void);
void CopyApEntryToWorkCopy(s32 entryIndex);
u8 GetApEntrySetType(int entryIndex);
void FormatApWorkDnsSecondText(char *output);
void FormatApWorkDnsFirstText(char *output);
void FormatApWorkGatewayText(char *output);
void FormatApWorkNetmaskText(char *output);
void FormatApWorkIpText(char *output);
void CopyApWorkSsid(void *output);
void StoreApWorkDnsSecondText(const char *input);
void StoreApWorkDnsFirstText(const char *input);
void StoreApWorkGatewayText(const char *input);
void StoreApWorkNetmaskText(const char *input);
void StoreApWorkIpText(const char *input);
void StoreApWorkWepKey(const u8 *text);
void StoreApWorkSsid(const u8 *ssid);
void SetApWorkDnsNone(u32 dnsNone);
void SetApWorkIpNone(u32 ipNone);
ApWorkCopy *GetApWorkCopy(void);
void ReleaseApStore(void);
void CreateApStore(void);
