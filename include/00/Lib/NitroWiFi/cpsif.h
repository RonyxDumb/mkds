#pragma once

#include "types.h"
#include "code_0200e77c.h"
#include "code_02142eac.h"
#include "00/unk_021b5000.h"
#include "00/Lib/NitroWiFi/util.h"

BOOL WcmCpsifTryLockMutexInIRQ(OSMutex *mutex);

void WcmCpsifKACallback(void);
void WcmCpsifWmCallback(WirelessMessage *callback);
s32 WCM_SendDCFData(const void *dstAddr, const void *buf, s32 len);
u32 WCM_SetRecvDCFCallback(Unk021b5f54Func callback);
u8 *WCM_GetApEssid(u16 *length);
u8 *WCM_GetApMacAddress(void);
void WCMi_CpsifSendNullPacket(void);
void WCMi_CpsifRecvCallback(WMDcfRecvBuf *recv);
void WCMi_InitCpsif(void);
