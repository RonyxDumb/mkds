#pragma once

#include "types.h"
#include "03/Net/essid_packet_steps.h"
#include "00/Lib/wifi_library_work_objects.h"
#include "00/Lib/NitroWiFi/wireless_connection_config.h"
#include "00/Lib/NitroWiFi/wireless_connection_options.h"
#include "00/Lib/DWC/access_point_wep_key.h"

typedef s32 EssidEventCallback();

BOOL InitEssidWcm(EssidEventCallback *callback, u8 *buffer, s32 size);
BOOL ConnectEssidToEntry(RawEntry *record, MelcoBlock *melcoBlock, u32 flags);
BOOL CleanupEssidWcm(void);
BOOL DisconnectEssid(void);
BOOL EndEssidSearch(void);
BOOL StartEssidSearch(const u8 *addressBytes, const u8 *essidBytes, s32 essidLength, u32 option);
s32 CopyEssidScanRecords(RawEntry *records, s32 maxCount);
BOOL StartEssidReturnToIdle(void);
void EssidWcmNotifyCallback(s16 *event);
