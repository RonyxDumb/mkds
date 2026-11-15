#pragma once

#include "types.h"
#include "00/Lib/wifi_library_work_objects.h"
#include "00/Lib/NitroWiFi/wireless_connection_config.h"
#include "wireless_power_mp.h"
#include "00/Lib/DWC/access_point_wep_key.h"
#include "00/Lib/NitroWiFi/wireless_connection_control.h"


u32 WCM_UpdateOption(u32 option);
s32 WCM_TerminateAsync(void);
s32 WCM_ConnectAsync(WMBssDesc *bssDesc, WCMWepDesc *wepDesc, u32 option);
s32 WCM_BeginSearchAsync(const void *bssid, const u8 *essid, u32 option);
s32 WCM_SearchAsync(const void *bssid, const u8 *essid, u32 option);
s32 WCM_StartupAsync(WCMConfig *config, void (*notify)(WCMNotice *));
BOOL WCM_Finish(void);
s32 WCM_Init(WCMWork *buf, u32 len);
void WcmAppendApList(WCMApList *aplist);
WCMApList *WcmSearchIndexedApList(u32 index);
WCMApList *WcmSearchApList(const u8 *bssid);
