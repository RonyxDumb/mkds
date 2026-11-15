#pragma once

#include "types.h"
#include "00/Lib/DWC/access_point_power_mode.h"
#include "00/Lib/NitroWiFi/wireless_connection_config.h"
#include "00/Lib/NitroWiFi/wireless_connection_options.h"

u32 SearchEndCheck(ACWORK *object, u32 phase);
u32 NextSearchCheck(ACWORK *object, u32 phase);
u32 SearchStealth(ACWORK *object);
u32 SearchDifferChannel(ACWORK *object);
u32 SearchAround2ndLap(ACWORK *object);
u32 SearchAround(ACWORK *object);
u32 SearchStart(ACWORK *object);
void DWCi_AC_SearchReStart(u32 phase);
s8 DWCi_AC_GetStealthChannel(s32 index);
void DWCi_AC_SetStealthChannel(u32 channel);
u32 DWCi_AC_SearchAP(void);
u8 DWCi_AC_Start(void);
void CheckSetDNS(ACWORK *object);
u32 ConvNetMask(s32 prefixLength);
