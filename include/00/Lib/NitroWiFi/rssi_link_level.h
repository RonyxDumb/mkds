#pragma once

#include "types.h"

typedef struct WMDcfRecvBuf {
    /* 00 */ u8 mRenderObj[6];
    /* 06 */ u16 mLength;
    /* 08 */ u8 mRender1Mat1Shp[0x10];
    /* 18 */ u8 mDestAdrs[6];
    /* 1e */ u8 mSrcAdrs[0xe];
    /* 2c */ u8 mData[1];
} WMDcfRecvBuf;

void WCMi_ShelterRssi(u8 rssi);
s32 WcmGetLinkLevel(void);
u8 WCMi_GetRssiAverage(void);

u32 WCM_GetLinkLevel(void);

extern u8 gWcmRssiIndex;
extern u8 gWcmRssi[16];
