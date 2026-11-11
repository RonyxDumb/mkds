#pragma once

#include "types.h"

typedef struct DWCInetControl {
    /* 00 */ s32 mAcState;
    /* 04 */ u16 mState;
    /* 06 */ u16 mOnline;
    /* 08 */ u16 mDmaNo;
    /* 0a */ u16 mPowerMode;
} DWCInetControl;

#include "00/code_021a3a18.h"

extern DWCInetControl *gInetControl;

u32 DWCi_CheckDisconnected(void);
BOOL DWC_CleanupInetAsync(void);
void DWC_CleanupInet(void);
u32 DWC_GetInetStatus(void);
void DWC_ProcessInet(void);
u32 DWC_CheckInet(void);
void DWC_ConnectInetAsync(void);
void DWC_SetAuthServer(s32 type);
void DWC_InitInet(void *inetCntl);
void DWC_InitInetEx(DWCInetControl *inetCntl, u16 dmaNo, u32 powerMode, u32 sslThreadPriority);
