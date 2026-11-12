#pragma once

#include "types.h"
#include "00/unk_021b5000.h"
#include "00/code_021a574c.h"
#include "code_02142eac.h"
#include "00/Lib/DWC/code_02188de4.h"
#include "00/Lib/NitroWiFi/code_021a4b98.h"


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
