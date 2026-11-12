#pragma once

#include "types.h"

typedef struct ACSL ACSL;
typedef struct ACFL ACFL;
typedef struct ACWORK ACWORK;

#include "code_02142eac.h"

u8 MakeDifferChannelList(s32 findListNum, ACFL *findList, ACSL *searchList, WMBssDesc *bssDescs);
u8 MakeUserList(ACWORK *object);
u8 MakeStealthList(ACWORK *object);
u8 MakeAroundList(ACWORK *object);
u32 DWCi_AC_CheckFreespot(WMBssDesc *bssDesc);

extern const u8 gWayportSsid[8];
extern const char gFreespotSsid[8];
extern const u8 gNintendoWfcSsid[12];
extern u8 data_ov000_021b20d0[12];
