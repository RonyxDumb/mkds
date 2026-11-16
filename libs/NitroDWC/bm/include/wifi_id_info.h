#pragma once

#include "types.h"
#include "clock_chip_access.h" // RTCDate, RTCTime

typedef struct DWCWiFiInfo DWCWiFiInfo;

extern const u8 DWCi_util_wifiid_exctable[];
extern const u8 DWCi_util_wifiid_ttable[];

BOOL StructDW_SomeFn_from_thumb(DWCWiFiInfo *info);
u64 DWCi_Util_WiFiId_scrambleUid(u16 rand, u32 mac, u8 vend, u8 mainunit);
s64 ComputeTotalSeconds_EpochMaybe_from_thumb(const RTCDate *date, const RTCTime *time);
