#include "03/Net/ap_store.h"
#include "03/Net/exchange_essid.h"
#include "03/Net/ap_entries.h"
#include "03/System/exp_heap.h"
#include "03/Menu/wifi_menu_shared.h"
#include "code_020205b0.h"
#include "dwc_backup.h"
#include "code_0213a460.h"
#include "code_0214cfe4.h"
#include "code_0214d018.h"
#include "code_02151fc4.h"
#include "03/Net/essid_packet_steps.h"
#include "03/Menu/wifi_menu_strings.h"
#include "03/Net/exchange_result_records.h"
#include "os_printf.h"
#include "string.h"
#include "code_02134398.h"
#include "03/System/string_length.h"

const u8 gSettingNone[4] = {0, 0, 0, 0};
char gAddressTextFormat[13] = "%3d%3d%3d%3d";
struct ApStore *gApStore;

void CreateApStore(void) {
    ApStore *store;
    store = AllocExpHeapBlock(0x6f8, HEAP_ALIGN_CACHE_LINE);
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
    MI_CpuCopy8(ssid, gApStore->mWorkCopy.mEntry.mSsids[0], sizeof(gApStore->mWorkCopy.mEntry.mSsids[0]));
    gApStore->mWorkCopy.mEntry.mSetType = AP_SET_TYPE_ENTERED;
}

void StoreApWorkWepKey(const u8 *text) {
    s32 charIndex;
    s32 textLength;
    u8 *keyCursor;
    MI_CpuFill8(gApStore->mWorkCopy.mEntry.mWepKeys[0], 0, sizeof(gApStore->mWorkCopy.mEntry.mWepKeys[0]));
    textLength = GetStringLengthWithLimit(text, 0x20);
    switch (textLength) {
        case 0:
        case sizeof(WepKey5) * 2:
        case sizeof(WepKey13) * 2:
        case sizeof(WepKey16) * 2:
            gApStore->mWorkCopy.mEntry.mWepNotation = 0;
            keyCursor = gApStore->mWorkCopy.mEntry.mWepKeys[0];
            charIndex = 0;
            for (; charIndex < textLength;) {
                *keyCursor = (ParseHexDigit(text[charIndex]) << 4) + ParseHexDigit(text[charIndex + 1]);
                charIndex += 2;
                keyCursor++;
            }
            break;
        default:
            gApStore->mWorkCopy.mEntry.mWepNotation = 1;
            MI_CpuCopy8(text, gApStore->mWorkCopy.mEntry.mWepKeys[0], sizeof(gApStore->mWorkCopy.mEntry.mWepKeys[0]));
            break;
    }
    switch (textLength) {
        case 0:
            gApStore->mWorkCopy.mEntry.mWepMode = AP_WEP_MODE_NONE;
            break;
        case sizeof(WepKey5):
        case sizeof(WepKey5) * 2:
            gApStore->mWorkCopy.mEntry.mWepMode = AP_WEP_MODE_KEY_5_BYTES;
            break;
        case sizeof(WepKey13):
        case sizeof(WepKey13) * 2:
            gApStore->mWorkCopy.mEntry.mWepMode = AP_WEP_MODE_KEY_13_BYTES;
            break;
        default:
            gApStore->mWorkCopy.mEntry.mWepMode = AP_WEP_MODE_KEY_16_BYTES;
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
    MI_CpuCopy8(gApStore->mWorkCopy.mEntry.mSsids[0], output, sizeof(gApStore->mWorkCopy.mEntry.mSsids[0]));
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
    return gApStore->mPages[entryIndex].mEntry.mSetType;
}

void CopyApEntryToWorkCopy(s32 entryIndex) {
    ApStore *store = gApStore;
    ApEntry *entry = &store->mPages[entryIndex].mEntry;
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
    ApEntry *entry = &gApStore->mPages[workCopy->mEntryIndex].mEntry;
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
    s32 entryIndex;
    const u8 *sourceKey;
    u8 *destinationKey;
    workCopy = &gApStore->mWorkCopy;
    MI_CpuFill8(workCopy, 0, sizeof(ApEntry) - 1);
    MI_CpuCopy8(exchangeResult, workCopy->mEntry.mSsids[0], sizeof(workCopy->mEntry.mSsids[0]));
    switch (exchangeResult->mKind) {
        case AP_WEP_MODE_KEY_5_BYTES:
            workCopy->mEntry.mWepMode = AP_WEP_MODE_KEY_5_BYTES;
            keyLength = 5;
            break;
        case AP_WEP_MODE_KEY_13_BYTES:
            workCopy->mEntry.mWepMode = AP_WEP_MODE_KEY_13_BYTES;
            keyLength = 0xd;
            break;
        case AP_WEP_MODE_KEY_16_BYTES:
            workCopy->mEntry.mWepMode = AP_WEP_MODE_KEY_16_BYTES;
            keyLength = 0x10;
            break;
        default:
            workCopy->mEntry.mWepMode = AP_WEP_MODE_NONE;
            keyLength = 0;
            break;
    }
    workCopy->mEntry.mWepNotation = 0;
    entryIndex = 0;
    destinationKey = workCopy->mEntry.mWepKeys[0];
    sourceKey = exchangeResult->mValueBytes[0];
    for (; entryIndex < 4; entryIndex++) {
        MI_CpuCopy8(sourceKey, destinationKey, keyLength);
        destinationKey += 0x10;
        sourceKey += 0x20;
    }
    workCopy->mEntry.mSetType = AP_SET_TYPE_EXCHANGED;
    MI_CpuFill8(workCopy->mNetmask, 0, 4);
    workCopy->mIpNone = 1;
    workCopy->mDnsNone = 1;
    WriteApWorkCopy();
}

void WriteApWorkFromAossResult(int response) {
    u32 firstArg = response;
    u32 secondArg;
    u32 thirdArg;
    u32 recordBase;
    u32 responseBase;
    responseBase = (firstArg) + (0u);
    firstArg = (u32) &gApStore;
    secondArg = *(const u32 *) ((firstArg) + 0u);
    firstArg = 0x400u;
    recordBase = (secondArg) + (firstArg);
    firstArg = (recordBase) + (0u);
    secondArg = 0u;
    thirdArg = 239u;
    MI_CpuFill8((void *) firstArg, secondArg, thirdArg);
    firstArg = (responseBase) + (0u);
    secondArg = (recordBase) + (0u);
    secondArg = (secondArg) + 209u;
    thirdArg = 5u;
    MI_CpuCopy8((const void *) firstArg, (void *) secondArg, thirdArg);
    firstArg = (responseBase) + (6u);
    secondArg = (recordBase) + (0u);
    secondArg = (secondArg) + 214u;
    thirdArg = 5u;
    MI_CpuCopy8((const void *) firstArg, (void *) secondArg, thirdArg);
    firstArg = (responseBase) + (0u);
    firstArg = (firstArg) + 12u;
    secondArg = (recordBase) + (0u);
    secondArg = (secondArg) + 219u;
    thirdArg = 5u;
    MI_CpuCopy8((const void *) firstArg, (void *) secondArg, thirdArg);
    firstArg = (responseBase) + (0u);
    firstArg = (firstArg) + 18u;
    secondArg = (recordBase) + (0u);
    secondArg = (secondArg) + 224u;
    thirdArg = 5u;
    MI_CpuCopy8((const void *) firstArg, (void *) secondArg, thirdArg);
    firstArg = (responseBase) + (0u);
    firstArg = (firstArg) + 24u;
    secondArg = (recordBase) + (0u);
    secondArg = (secondArg) + 96u;
    thirdArg = 32u;
    MI_CpuCopy8((const void *) firstArg, (void *) secondArg, thirdArg);
    firstArg = (responseBase) + (0u);
    firstArg = (firstArg) + 57u;
    secondArg = (recordBase) + (0u);
    secondArg = (secondArg) + 128u;
    thirdArg = 13u;
    MI_CpuCopy8((const void *) firstArg, (void *) secondArg, thirdArg);
    firstArg = (responseBase) + (0u);
    firstArg = (firstArg) + 71u;
    secondArg = (recordBase) + (0u);
    secondArg = (secondArg) + 144u;
    thirdArg = 13u;
    MI_CpuCopy8((const void *) firstArg, (void *) secondArg, thirdArg);
    firstArg = (responseBase) + (0u);
    firstArg = (firstArg) + 85u;
    secondArg = (recordBase) + (0u);
    secondArg = (secondArg) + 160u;
    thirdArg = 13u;
    MI_CpuCopy8((const void *) firstArg, (void *) secondArg, thirdArg);
    firstArg = (responseBase) + (0u);
    firstArg = (firstArg) + 99u;
    secondArg = (recordBase) + (0u);
    secondArg = (secondArg) + 176u;
    thirdArg = 13u;
    MI_CpuCopy8((const void *) firstArg, (void *) secondArg, thirdArg);
    responseBase = (responseBase) + 113u;
    firstArg = (responseBase) + (0u);
    secondArg = (recordBase) + (0u);
    secondArg = (secondArg) + 64u;
    thirdArg = 32u;
    MI_CpuCopy8((const void *) firstArg, (void *) secondArg, thirdArg);
    firstArg = (recordBase) + (0u);
    firstArg = (firstArg) + 230u;
    secondArg = *(const u8 *) ((firstArg) + 0u);
    firstArg = 3u;
    secondArg = (secondArg) & ~(firstArg);
    firstArg = 2u;
    secondArg = (secondArg) | (firstArg);
    firstArg = (recordBase) + (0u);
    firstArg = (firstArg) + 230u;
    *(u8 *) ((firstArg) + 0u) = secondArg;
    firstArg = (recordBase) + (0u);
    firstArg = (firstArg) + 230u;
    secondArg = *(const u8 *) ((firstArg) + 0u);
    firstArg = 252u;
    secondArg = (secondArg) & ~(firstArg);
    firstArg = (recordBase) + (0u);
    firstArg = (firstArg) + 230u;
    *(u8 *) ((firstArg) + 0u) = secondArg;
    secondArg = 1u;
    firstArg = (recordBase) + (0u);
    firstArg = (firstArg) + 231u;
    *(u8 *) ((firstArg) + 0u) = secondArg;
    firstArg = (recordBase) + (0u);
    firstArg = (firstArg) + 240u;
    secondArg = 0u;
    thirdArg = 4u;
    MI_CpuFill8((void *) firstArg, secondArg, thirdArg);
    secondArg = 1u;
    firstArg = (recordBase) + (0u);
    firstArg = (firstArg) + 245u;
    *(u8 *) ((firstArg) + 0u) = secondArg;
    recordBase = (recordBase) + 246u;
    *(u8 *) ((recordBase) + 0u) = secondArg;
    WriteApWorkCopy();
}

struct ApStore *GetApStore(void) {
    return gApStore;
}

void ResetApEntry(int entryIndex) {
    ApEntry *entry;
    entry = &gApStore->mPages[entryIndex].mEntry;
    MI_CpuFill8(entry, 0, sizeof(ApEntry) - 1);
    entry->mSetType = AP_SET_TYPE_EMPTY;
    WriteApEntryToNvram(entryIndex);
}

void ResetApEntries(void) {
    volatile u16 zeroValue = 0;
    DWCWiFiInfo wifiInfo;
    u8 *packedWifiInfo;
    s32 entryIndex;
    MIi_CpuClear16(zeroValue, gApStore, 0x400);
    for (entryIndex = 0; entryIndex < 3; entryIndex++) {
        gApStore->mPages[entryIndex].mEntry.mSetType = AP_SET_TYPE_EMPTY;
    }
    DWCi_AUTH_GetNewWiFiInfo(&wifiInfo);
    packedWifiInfo = DWCi_BACKUPlConvWifiInfo(&wifiInfo);
    for (entryIndex = 0; entryIndex < 2; entryIndex++) {
        MI_CpuCopy8(packedWifiInfo, gApStore->mPages[entryIndex].mPackedWiFiInfo, 0xe);
    }
    for (entryIndex = 0; entryIndex < 4; entryIndex++) {
        WriteApEntryToNvram(entryIndex);
    }
}

void WriteApEntryToNvram(s32 entryIndex) {
    u32 setType = gApStore->mPages[entryIndex].mEntry.mSetType;
    u32 entryBit = 1 << entryIndex;
    BOOL stateBitSet = FALSE;
    s32 entryFlags[4];
    void *workBuffer;
    ApStore *store;
    s32 slotIndex;
    MI_CpuFill8(entryFlags, 0, sizeof(entryFlags));
    entryFlags[entryIndex] = 1;
    if (entryIndex <= 2) {
        store = gApStore;
        if ((store->mPages[0].mEntry.mEntrySetBits & entryBit) != 0) {
            stateBitSet = TRUE;
        }
        if (setType == 0xff && stateBitSet != FALSE) {
            store->mPages[0].mEntry.mEntrySetBits = store->mPages[0].mEntry.mEntrySetBits & ~entryBit;
            gApStore->mPages[1].mEntry.mEntrySetBits = gApStore->mPages[1].mEntry.mEntrySetBits & ~entryBit;
            entryFlags[1] = 1;
            entryFlags[0] = 1;
        } else if (setType != 0xff && stateBitSet == FALSE) {
            store->mPages[0].mEntry.mEntrySetBits = store->mPages[0].mEntry.mEntrySetBits | entryBit;
            gApStore->mPages[1].mEntry.mEntrySetBits = gApStore->mPages[1].mEntry.mEntrySetBits | entryBit;
            entryFlags[1] = 1;
            entryFlags[0] = 1;
        }
    }
    for (slotIndex = 0; slotIndex < 4; slotIndex++) {
        if (entryFlags[slotIndex] != 0) {
            gApStore->mPages[slotIndex].mCrc =
                Crc16(&gApStore->mWorkCopy.mCrcTable, gApStore->mPages[slotIndex].mEntry.mIspId, 0xfe);
        }
    }
    workBuffer = AllocExpHeapBlock(0x100, HEAP_ALIGN_CACHE_LINE);
    WriteFlaggedNvramEntries(gApStore, entryFlags, workBuffer);
    FreeExpHeapBlockAndClearPointer(&workBuffer);
}

void ParseAddressText(const char *input, u8 *output) {
    u8 group[4];
    s32 groupIndex;
    s32 charIndex;
    u8 *cursor;
    MI_CpuFill8(group, 0, 4);
    for (groupIndex = 0; groupIndex < 4; groupIndex++) {
        MI_CpuCopy8(input + groupIndex * 3, group, 3);
        charIndex = 0;
        cursor = group;
        for (; charIndex < 3; charIndex++) {
            if (*cursor != 0) {
                break;
            }
            *cursor = ' ';
            cursor++;
        }
        output[groupIndex] = StrtolBase10((const char *) group);
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
