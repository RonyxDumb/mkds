#include "wifi_id_info.h"
#include "wifi_settings_nvram_backup.h"
#include "wifi_id_auth.h"
#include "tick_counter.h"
#include "cpu_copy_fill.h"
#include "clock_chip_access.h"
#include "reset_interrupts_halt.h"
#include "friend_user_data.h"
#include "time_to_seconds.h"

const u8 DWCi_util_wifiid_exctable[8] = {1, 2, 0, 4, 3, 5, 6, 7};
const u8 DWCi_util_wifiid_ttable[16] = {5, 9, 1, 14, 12, 2, 10, 0, 11, 13, 3, 4, 8, 6, 15, 7};

#pragma thumb on

// Seconds since 2000-01-01, or -1 for a bad date.
s64 DateTimeToSeconds(const RTCDate *date, const RTCTime *time) {
    s32 day;
    s32 sec;
    day = DateToDayCount(date);
    if (day == -1) {
        return -1;
    }
    sec = TimeToSeconds(time);
    return (s64) sec + (s64) day * 0x15180;
}

u64 DWCi_Util_WiFiId_scrambleUid(u16 rand, u32 mac, u8 vend, u8 mainunit) {
    union {
        u64 bits;
        u8 bytes[8];
    } value;
    u8 copy[8];
    s32 byteIndex;
    u8 *src;
    u8 *dst;
    const u8 *order;
    value.bits = (((u64) rand & 0xffff) << 27) |
              ((((u64) mac & 0xffffff) << 3) | (((u64) mainunit & 3) | (((u64) vend & 1) << 2)));
    src = value.bytes;
    for (byteIndex = 0; byteIndex < 6; byteIndex++) {
        *src ^= 0xd6;
        src++;
    }
    byteIndex = 0;
    src = value.bytes;
    for (; byteIndex < 5; byteIndex++) {
        *src = (DWCi_util_wifiid_ttable[(*src >> 4) & 0xf] << 4) | DWCi_util_wifiid_ttable[*src & 0xf];
        src++;
    }
    MI_CpuCopy8(value.bytes, copy, 8);
    byteIndex = 0;
    dst = copy;
    order = DWCi_util_wifiid_exctable;
    for (; byteIndex < 5; byteIndex++) {
        value.bytes[*order] = *dst;
        dst++;
        order++;
    }
    value.bytes[7] = 0;
    value.bytes[6] = 0;
    value.bytes[5] &= 7;
    value.bits <<= 1;
    value.bytes[0] |= (value.bytes[5] >> 3) & 1;
    src = value.bytes;
    for (byteIndex = 0; byteIndex < 6; byteIndex++) {
        *src ^= 0x67;
        src++;
    }
    value.bytes[7] = 0;
    value.bytes[6] = 0;
    value.bytes[5] &= 7;
    return value.bits;
}

BOOL DWCi_AUTH_GetNewWiFiInfo(DWCWiFiInfo *info) {
    u8 vendor;
    u32 macLow;
    u8 mac[6];
    RTCDate date;
    RTCTime time;
    s64 seconds;
    u32 seed;
    DWCi_BM_GetWiFiInfo(info);
    RTC_Init();
    if (RTC_GetDate(&date) != 0) {
        return 0;
    }
    if (RTC_GetTime(&time) != 0) {
        return 0;
    }
    seconds = DateTimeToSeconds(&date, &time);
    seed = seconds;
    if (seconds < 0) {
        return 0;
    }
    if (OS_IsTickAvailable() != 0) {
        seed += (u32) OS_GetTick;
    }
    OS_GetMacAddress(mac);
    vendor = (mac[0] << 16 | mac[1] << 8 | mac[2]) != 0x9bf;
    macLow = mac[5];
    macLow |= (mac[3] << 16 | mac[4] << 8);
    seed = seed * 0x5d588b65 + 0x269ec3;
    info->mPass = ((seed >> 16) * 1000) >> 16;
    info->mAttestedUserId = 0;
    if (info->mRandomHistory == 0) {
        info->mNotAttestedId = 0;
        while (info->mNotAttestedId == 0) {
            seed = seed * 0x5d588b65 + 0x269ec3;
            while (seed == 0) {
                seed = seed * 0x5d588b65 + 0x269ec3;
            }
            info->mRandomHistory = seed;
            info->mNotAttestedId = DWCi_Util_WiFiId_scrambleUid(info->mRandomHistory, macLow, vendor, 0);
        }
    } else {
        info->mNotAttestedId = 0;
        while (info->mNotAttestedId == 0) {
            info->mRandomHistory++;
            info->mNotAttestedId = DWCi_Util_WiFiId_scrambleUid(info->mRandomHistory, macLow, vendor, 0);
        }
    }
    return 1;
}

#pragma thumb off
