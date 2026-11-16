#pragma once

#include "types.h"
#include "00/Lib/wifi_library_work_objects.h"
#include "00/Lib/NitroWiFi/wireless_connection_options.h"
#include "thread_mutex_types.h"

WCMApList *WcmAllocApList(void);
void WCMi_EntryApList(WMBssDesc *bssDesc, u16 linkLevel);
u8 *WCM_PointApList(u16 index);
u32 WCM_LockApList(u32 lock);
u32 WCM_CountApList(void);
void WCM_ClearApList(void);
void WcmCpsifUnlockMutexInIRQ(OSMutex *mutex);
