#pragma once

#include "types.h"
#include "thread_mutex_types.h"
#include "wireless_link_control.h"
#include "00/Lib/wifi_library_work_objects.h"
#include "00/Lib/NitroWiFi/rssi_link_level.h"

BOOL WcmCpsifTryLockMutexInIRQ(OSMutex *mutex);

void WcmCpsifKACallback(WirelessMessage *event);
void WcmCpsifWmCallback(WirelessMessage *callback);
s32 WCM_SendDCFData(const void *dstAddr, const void *buf, s32 len);
u32 WCM_SetRecvDCFCallback(WCMRecvInd callback);
u8 *WCM_GetApEssid(u16 *length);
u8 *WCM_GetApMacAddress(void);
void WCMi_CpsifSendNullPacket(void);
void WCMi_CpsifRecvCallback(WMDcfRecvBuf *recv);
void WCMi_InitCpsif(void);
