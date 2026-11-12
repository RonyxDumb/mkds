#pragma once

#include "types.h"
#include "code_0214d93c.h" // RTCDate, RTCTime

typedef struct DWCWiFiInfo DWCWiFiInfo;

extern const u8 DWCi_util_wifiid_exctable[];
extern const u8 DWCi_util_wifiid_ttable[];

BOOL DWCi_AUTH_GetNewWiFiInfo(DWCWiFiInfo *info);
u64 DWCi_Util_WiFiId_scrambleUid(u16 rand, u32 mac, u8 vend, u8 mainunit);
s64 DateTimeToSeconds(const RTCDate *date, const RTCTime *time);
