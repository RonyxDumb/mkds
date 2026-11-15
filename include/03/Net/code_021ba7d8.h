#pragma once

#include "types.h"
#include "00/code_021a574c.h"
#include "00/Lib/DWC/code_02188de4.h"
#include "code_02142eac.h"

extern u32 gEssidSearchOption;
extern u32 gEssidConnectOption;
extern u8 *gEssidSearchAddress;
extern struct WCMConfig *gEssidWcmConfig;
extern struct WCMWepDesc *gEssidConnectBlock;
extern WCMWork *gEssidWcmWork;
extern u8 *gEssidSearchEssid;
extern s32 gEssidWcmState;
extern EssidEventCallback *gEssidEventCallback;
extern struct WMBssDesc *gEssidConnectRecord;
extern u8 gEssidSearchAddressBytes[6];
extern u8 gEssidSearchEssidBytes[0x20];
