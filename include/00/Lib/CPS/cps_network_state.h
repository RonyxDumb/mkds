#pragma once

#include "types.h"
#include "00/Lib/CPS/code_021a88a8.h"

typedef struct CPSArpCache {
    /* 00 */ u32 mIp;
    /* 04 */ u8 mMac[6];
    /* 0a */ u16 mWhen;
} CPSArpCache;

typedef struct CPSFragTable {
    /* 00 */ u32 mIpFrom;
    /* 04 */ u16 mFrags;
    /* 06 */ u16 mId;
    /* 08 */ u16 mLast;
    /* 0a */ u16 mSize;
    /* 0c */ u16 mFrom[8];
    /* 1c */ u16 mTo[8];
    /* 2c */ u32 mWhen;
    /* 30 */ u8 *mOfs0;
    /* 34 */ u8 *mBuf;
} CPSFragTable;

extern u64 CPSiRand32ctx[3];
extern u32 CPSDhcpServerIp;
extern u32 gSleepSave;
extern u32 gScavengerForceExit;
extern u32 gLeaseTime;
extern u32 gOfferedMyIp;
extern u32 gCPSMode;
extern u16 CPSMyMac[3];
extern void (*gDhcpCallback)(void);
extern u8 gDhcpHostname[];
extern u8 gScavengerReceiveBuffer[];
extern u8 gScavengerSendBuffer[];
extern CPSArpCache gArpCache[8];
extern CPSFragTable gFragTable[8];
extern CPSSoc gScavengerSoc;
