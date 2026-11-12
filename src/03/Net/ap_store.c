#include "03/Net/ap_store.h"
#include "03/code_021cd2e0.h"
#include "03/System/exp_heap.h"
#include "03/unk_021da000.h"
#include "code_020205b0.h"
#include "dwc_backup.h"
#include "code_0213a460.h"
#include "code_0214cfe4.h"
#include "code_0214d018.h"
#include "code_02151fc4.h"
#include "03/Net/essid_wcm.h"
#include "03/code_021cd000.h"
#include "03/unk_021d7000.h"
#include "03/unk_021d8000.h"
#include "os_printf.h"
#include "string.h"
#include "code_02134398.h"
#include "03/System/string_length.h"

const u8 gSettingNone[1] = {0};
char gAddressTextFormat[13] = "%3d%3d%3d%3d";
struct ApStore *gApStore;

void CreateApStore(void) {
    ApStore *store;
    store = AllocExpHeapBlock(0x6f8, 0x20);
    gApStore = store;
    Crc16InitTable(&store->mWorkCopy.mCrcTable, 0xa001);
    ReadNvramEntries(gApStore);
}

void ReleaseApStore(void) {
    FreeExpHeapBlockAndClearPointer(&gApStore);
}

ApWorkCopy *GetApWorkCopy(void) {
    return &gApStore->mWorkCopy;
}

void SetApWorkIpNone(u32 ipNone) {
    gApStore->mWorkCopy.mIpNone = ipNone;
}

void SetApWorkDnsNone(u32 dnsNone) {
    gApStore->mWorkCopy.mDnsNone = dnsNone;
}

void StoreApWorkSsid(const u8 *ssid) {
    MI_CpuCopy8(ssid, gApStore->mWorkCopy.mEntry.mSsid, 0x20);
    gApStore->mWorkCopy.mEntry.mSetType = 0;
}

void StoreApWorkWepKey(const u8 *text) {
    s32 i;
    s32 textLength;
    u8 *keyCursor;
    MI_CpuFill8(gApStore->mWorkCopy.mEntry.mWepKeys[0], 0, 0x10);
    textLength = GetStringLengthWithLimit(text, 0x20);
    switch (textLength) {
        case 0:
        case 10:
        case 26:
        case 32:
            gApStore->mWorkCopy.mEntry.mWepNotation = 0;
            keyCursor = gApStore->mWorkCopy.mEntry.mWepKeys[0];
            i = 0;
            for (; i < textLength;) {
                *keyCursor = (ParseHexDigit(text[i]) << 4) + ParseHexDigit(text[i + 1]);
                i += 2;
                keyCursor++;
            }
            break;
        default:
            gApStore->mWorkCopy.mEntry.mWepNotation = 1;
            MI_CpuCopy8(text, gApStore->mWorkCopy.mEntry.mWepKeys[0], 0x10);
            break;
    }
    switch (textLength) {
        case 0:
            gApStore->mWorkCopy.mEntry.mWepMode = 0;
            break;
        case 5:
        case 10:
            gApStore->mWorkCopy.mEntry.mWepMode = 1;
            break;
        case 13:
        case 26:
            gApStore->mWorkCopy.mEntry.mWepMode = 2;
            break;
        default:
            gApStore->mWorkCopy.mEntry.mWepMode = 3;
            break;
    }
}

void StoreApWorkIpText(const char *input) {
    ParseAddressText(input, gApStore->mWorkCopy.mEntry.mIp);
}

void StoreApWorkNetmaskText(const char *input) {
    ParseAddressText(input, gApStore->mWorkCopy.mNetmask);
}

void StoreApWorkGatewayText(const char *input) {
    ParseAddressText(input, gApStore->mWorkCopy.mEntry.mGateway);
}

void StoreApWorkDnsFirstText(const char *input) {
    ParseAddressText(input, gApStore->mWorkCopy.mEntry.mDns);
}

void StoreApWorkDnsSecondText(const char *input) {
    ParseAddressText(input, &gApStore->mWorkCopy.mEntry.mDns[4]);
}

void CopyApWorkSsid(void *output) {
    MI_CpuCopy8(gApStore->mWorkCopy.mEntry.mSsid, output, 0x20);
}

void FormatApWorkIpText(char *output) {
    u8 *addressBytes = gApStore->mWorkCopy.mEntry.mIp;
    u32 thirdByte = (addressBytes[2]);
    u32 fourthByte = (addressBytes[3]);
    const char *format = gAddressTextFormat;
    u32 firstByte = (addressBytes[0]);
    u32 secondByte = (addressBytes[1]);
    u32 length = OS_SPrintf(output, format, firstByte, secondByte, thirdByte, fourthByte);
}

void FormatApWorkNetmaskText(char *output) {
    u8 *addressBytes = gApStore->mWorkCopy.mNetmask;
    u32 thirdByte = (addressBytes[2]);
    u32 fourthByte = (addressBytes[3]);
    const char *format = gAddressTextFormat;
    u32 firstByte = (addressBytes[0]);
    u32 secondByte = (addressBytes[1]);
    u32 length = OS_SPrintf(output, format, firstByte, secondByte, thirdByte, fourthByte);
}

void FormatApWorkGatewayText(char *output) {
    u8 *addressBytes = gApStore->mWorkCopy.mEntry.mGateway;
    u32 thirdByte = (addressBytes[2]);
    u32 fourthByte = (addressBytes[3]);
    const char *format = gAddressTextFormat;
    u32 firstByte = (addressBytes[0]);
    u32 secondByte = (addressBytes[1]);
    u32 length = OS_SPrintf(output, format, firstByte, secondByte, thirdByte, fourthByte);
}

void FormatApWorkDnsFirstText(char *output) {
    u8 *addressBytes = gApStore->mWorkCopy.mEntry.mDns;
    u32 thirdByte = (addressBytes[2]);
    u32 fourthByte = (addressBytes[3]);
    const char *format = gAddressTextFormat;
    u32 firstByte = (addressBytes[0]);
    u32 secondByte = (addressBytes[1]);
    u32 length = OS_SPrintf(output, format, firstByte, secondByte, thirdByte, fourthByte);
}

void FormatApWorkDnsSecondText(char *output) {
    u8 *addressBytes = &gApStore->mWorkCopy.mEntry.mDns[4];
    u32 thirdByte = (addressBytes[2]);
    u32 fourthByte = (addressBytes[3]);
    const char *format = gAddressTextFormat;
    u32 firstByte = (addressBytes[0]);
    u32 secondByte = (addressBytes[1]);
    u32 length = OS_SPrintf(output, format, firstByte, secondByte, thirdByte, fourthByte);
}

u8 GetApEntrySetType(int entryIndex) {
    return gApStore->mUnk_000[entryIndex].mUnk_00.mSetType;
}

void CopyApEntryToWorkCopy(s32 entryIndex) {
    ApStore *store = gApStore;
    ApEntry *entry = &store->mUnk_000[entryIndex].mUnk_00;
    store->mWorkCopy.mEntry = *entry;
    store->mWorkCopy.mEntryIndex = entryIndex;
    if (memcmp(entry->mIp, gSettingNone, 4) != 0) {
        gApStore->mWorkCopy.mIpNone = 0;
    } else {
        gApStore->mWorkCopy.mIpNone = 1;
    }
    if (memcmp(entry->mDns, gSettingNone, 4) != 0 || memcmp(entry->mDns + 4, gSettingNone, 4) != 0) {
        gApStore->mWorkCopy.mDnsNone = 0;
    } else {
        gApStore->mWorkCopy.mDnsNone = 1;
    }
    DWCi_BACKUPlConvMaskAddr(entry->mNetmaskCidr, gApStore->mWorkCopy.mNetmask);
}

void WriteApWorkCopy(void) {
    ApWorkCopy *workCopy = &gApStore->mWorkCopy;
    ApEntry *entry = &gApStore->mUnk_000[workCopy->mEntryIndex].mUnk_00;
    *entry = workCopy->mEntry;
    if (workCopy->mIpNone != 0) {
        MI_CpuFill8(entry->mIp, 0, 4);
        MI_CpuFill8(entry->mGateway, 0, 4);
        entry->mNetmaskCidr = 0;
    } else {
        MI_CpuCopy8(workCopy->mEntry.mIp, entry->mIp, 4);
        MI_CpuCopy8(workCopy->mEntry.mGateway, entry->mGateway, 4);
        entry->mNetmaskCidr = DWCi_BACKUPlConvMaskCidr(workCopy->mNetmask);
    }
    if (workCopy->mDnsNone != 0) {
        MI_CpuFill8(entry->mDns, 0, 8);
    } else {
        MI_CpuCopy8(workCopy->mEntry.mDns, entry->mDns, 8);
    }
    WriteApEntryToNvram(workCopy->mEntryIndex);
}

void WriteApWorkFromExchangeResult(const ExchangeResult *exchangeResult) {
    ApWorkCopy *workCopy;
    u32 keyLength;
    s32 i;
    const u8 *sourceKey;
    u8 *destinationKey;
    workCopy = &gApStore->mWorkCopy;
    MI_CpuFill8(workCopy, 0, 0xef);
    MI_CpuCopy8(exchangeResult, workCopy->mEntry.mSsid, 0x20);
    switch (exchangeResult->mKind) {
        case 1:
            workCopy->mEntry.mWepMode = 1;
            keyLength = 5;
            break;
        case 2:
            workCopy->mEntry.mWepMode = 2;
            keyLength = 0xd;
            break;
        case 3:
            workCopy->mEntry.mWepMode = 3;
            keyLength = 0x10;
            break;
        default:
            workCopy->mEntry.mWepMode = 0;
            keyLength = 0;
            break;
    }
    workCopy->mEntry.mWepNotation = 0;
    i = 0;
    destinationKey = workCopy->mEntry.mWepKeys[0];
    sourceKey = exchangeResult->mValueBytes[0];
    for (; i < 4; i++) {
        MI_CpuCopy8(sourceKey, destinationKey, keyLength);
        destinationKey += 0x10;
        sourceKey += 0x20;
    }
    workCopy->mEntry.mSetType = 2;
    MI_CpuFill8(workCopy->mNetmask, 0, 4);
    workCopy->mIpNone = 1;
    workCopy->mDnsNone = 1;
    WriteApWorkCopy();
}

void WriteApWorkFromAossResult(int response) {
    u32 value0 = response;
    u32 value1;
    u32 value2;
    u32 value4;
    u32 value5;
    value5 = (value0) + (0u);
    value0 = (u32) &gApStore;
    value1 = *(const u32 *) ((value0) + 0u);
    value0 = 0x400u;
    value4 = (value1) + (value0);
    value0 = (value4) + (0u);
    value1 = 0u;
    value2 = 239u;
    MI_CpuFill8((void *) value0, value1, value2);
    value0 = (value5) + (0u);
    value1 = (value4) + (0u);
    value1 = (value1) + 209u;
    value2 = 5u;
    MI_CpuCopy8((const void *) value0, (void *) value1, value2);
    value0 = (value5) + (6u);
    value1 = (value4) + (0u);
    value1 = (value1) + 214u;
    value2 = 5u;
    MI_CpuCopy8((const void *) value0, (void *) value1, value2);
    value0 = (value5) + (0u);
    value0 = (value0) + 12u;
    value1 = (value4) + (0u);
    value1 = (value1) + 219u;
    value2 = 5u;
    MI_CpuCopy8((const void *) value0, (void *) value1, value2);
    value0 = (value5) + (0u);
    value0 = (value0) + 18u;
    value1 = (value4) + (0u);
    value1 = (value1) + 224u;
    value2 = 5u;
    MI_CpuCopy8((const void *) value0, (void *) value1, value2);
    value0 = (value5) + (0u);
    value0 = (value0) + 24u;
    value1 = (value4) + (0u);
    value1 = (value1) + 96u;
    value2 = 32u;
    MI_CpuCopy8((const void *) value0, (void *) value1, value2);
    value0 = (value5) + (0u);
    value0 = (value0) + 57u;
    value1 = (value4) + (0u);
    value1 = (value1) + 128u;
    value2 = 13u;
    MI_CpuCopy8((const void *) value0, (void *) value1, value2);
    value0 = (value5) + (0u);
    value0 = (value0) + 71u;
    value1 = (value4) + (0u);
    value1 = (value1) + 144u;
    value2 = 13u;
    MI_CpuCopy8((const void *) value0, (void *) value1, value2);
    value0 = (value5) + (0u);
    value0 = (value0) + 85u;
    value1 = (value4) + (0u);
    value1 = (value1) + 160u;
    value2 = 13u;
    MI_CpuCopy8((const void *) value0, (void *) value1, value2);
    value0 = (value5) + (0u);
    value0 = (value0) + 99u;
    value1 = (value4) + (0u);
    value1 = (value1) + 176u;
    value2 = 13u;
    MI_CpuCopy8((const void *) value0, (void *) value1, value2);
    value5 = (value5) + 113u;
    value0 = (value5) + (0u);
    value1 = (value4) + (0u);
    value1 = (value1) + 64u;
    value2 = 32u;
    MI_CpuCopy8((const void *) value0, (void *) value1, value2);
    value0 = (value4) + (0u);
    value0 = (value0) + 230u;
    value1 = *(const u8 *) ((value0) + 0u);
    value0 = 3u;
    value1 = (value1) & ~(value0);
    value0 = 2u;
    value1 = (value1) | (value0);
    value0 = (value4) + (0u);
    value0 = (value0) + 230u;
    *(u8 *) ((value0) + 0u) = value1;
    value0 = (value4) + (0u);
    value0 = (value0) + 230u;
    value1 = *(const u8 *) ((value0) + 0u);
    value0 = 252u;
    value1 = (value1) & ~(value0);
    value0 = (value4) + (0u);
    value0 = (value0) + 230u;
    *(u8 *) ((value0) + 0u) = value1;
    value1 = 1u;
    value0 = (value4) + (0u);
    value0 = (value0) + 231u;
    *(u8 *) ((value0) + 0u) = value1;
    value0 = (value4) + (0u);
    value0 = (value0) + 240u;
    value1 = 0u;
    value2 = 4u;
    MI_CpuFill8((void *) value0, value1, value2);
    value1 = 1u;
    value0 = (value4) + (0u);
    value0 = (value0) + 245u;
    *(u8 *) ((value0) + 0u) = value1;
    value4 = (value4) + 246u;
    *(u8 *) ((value4) + 0u) = value1;
    WriteApWorkCopy();
}

struct ApStore *GetApStore(void) {
    return gApStore;
}

void ResetApEntry(int entryIndex) {
    ApEntry *entry;
    entry = &gApStore->mUnk_000[entryIndex].mUnk_00;
    MI_CpuFill8(entry, 0, 0xef);
    entry->mSetType = 0xff;
    WriteApEntryToNvram(entryIndex);
}

void ResetApEntries(void) {
    volatile u16 zeroValue = 0;
    DWCWiFiInfo wifiInfo;
    u8 *packedWifiInfo;
    s32 i;
    MIi_CpuClear16(zeroValue, gApStore, 0x400);
    for (i = 0; i < 3; i++) {
        gApStore->mUnk_000[i].mUnk_00.mSetType = 0xff;
    }
    DWCi_AUTH_GetNewWiFiInfo(&wifiInfo);
    packedWifiInfo = DWCi_BACKUPlConvWifiInfo(&wifiInfo);
    for (i = 0; i < 2; i++) {
        MI_CpuCopy8(packedWifiInfo, gApStore->mUnk_000[i].mUnk_f0, 0xe);
    }
    for (i = 0; i < 4; i++) {
        WriteApEntryToNvram(i);
    }
}

void WriteApEntryToNvram(s32 entryIndex) {
    u32 setType = gApStore->mUnk_000[entryIndex].mUnk_00.mSetType;
    u32 entryBit = 1 << entryIndex;
    BOOL stateBitSet = FALSE;
    s32 entryFlags[4];
    void *workBuffer;
    ApStore *store;
    s32 i;
    MI_CpuFill8(entryFlags, 0, 0x10);
    entryFlags[entryIndex] = 1;
    if (entryIndex <= 2) {
        store = gApStore;
        if ((store->mUnk_000[0].mUnk_00.mUnk_e8[7] & entryBit) != 0) {
            stateBitSet = TRUE;
        }
        if (setType == 0xff && stateBitSet != FALSE) {
            store->mUnk_000[0].mUnk_00.mUnk_e8[7] = store->mUnk_000[0].mUnk_00.mUnk_e8[7] & ~entryBit;
            gApStore->mUnk_000[1].mUnk_00.mUnk_e8[7] = gApStore->mUnk_000[1].mUnk_00.mUnk_e8[7] & ~entryBit;
            entryFlags[1] = 1;
            entryFlags[0] = 1;
        } else if (setType != 0xff && stateBitSet == FALSE) {
            store->mUnk_000[0].mUnk_00.mUnk_e8[7] = store->mUnk_000[0].mUnk_00.mUnk_e8[7] | entryBit;
            gApStore->mUnk_000[1].mUnk_00.mUnk_e8[7] = gApStore->mUnk_000[1].mUnk_00.mUnk_e8[7] | entryBit;
            entryFlags[1] = 1;
            entryFlags[0] = 1;
        }
    }
    for (i = 0; i < 4; i++) {
        if (entryFlags[i] != 0) {
            gApStore->mUnk_000[i].mUnk_fe =
                Crc16(&gApStore->mWorkCopy.mCrcTable, gApStore->mUnk_000[i].mUnk_00.mUnk_00, 0xfe);
        }
    }
    workBuffer = AllocExpHeapBlock(0x100, 0x20);
    WriteFlaggedNvramEntries((s32) gApStore, entryFlags, workBuffer);
    FreeExpHeapBlockAndClearPointer(&workBuffer);
}

void ParseAddressText(const char *input, u8 *output) {
    u8 group[4];
    s32 i;
    s32 j;
    u8 *cursor;
    MI_CpuFill8(group, 0, 4);
    for (i = 0; i < 4; i++) {
        MI_CpuCopy8(input + i * 3, group, 3);
        j = 0;
        cursor = group;
        for (; j < 3; j++) {
            if (*cursor != 0) {
                break;
            }
            *cursor = ' ';
            cursor++;
        }
        output[i] = StrtolBase10((const char *) group);
    }
}

s32 ParseHexDigit(u32 value) {
    if (value <= '9') {
        return value - '0';
    }
    if (value <= 'F') {
        return value - '7';
    }
    return value - 'W';
}
