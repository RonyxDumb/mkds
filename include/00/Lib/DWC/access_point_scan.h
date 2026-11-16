#pragma once

#include "types.h"


u8 DWCi_AC_MakeSearchList(u32 type);
u32 DWCi_AC_ConnectRetryAP(void);
void ScanStart(const u8 *bssid, const u8 *essid, s32 channel, u32 mode);
