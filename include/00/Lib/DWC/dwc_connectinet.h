#pragma once

#include "types.h"

u32 DWC_GetLinkLevel(void);

// Values of DWCInetControl.mState, which DWC_GetInetStatus also returns (0 without the object): the connect has not
// started, the access point connection is being made, it finished, the link is up, the cleanup has started, the link
// was lost, or the access point connection failed (the code is large or small, as DWC_GetInetStatus sorts it).
enum {
    INET_STATUS_INITIALIZED = 1,
    INET_STATUS_CONNECTING = 2,
    INET_STATUS_CONNECT_FINISHED = 3,
    INET_STATUS_ONLINE = 4,
    INET_STATUS_CLEANING_UP = 5,
    INET_STATUS_LINK_LOST = 6,
    INET_STATUS_FAILED_LARGE_CODE = 7,
    INET_STATUS_FAILED_SMALL_CODE = 8,
};

typedef struct DWCInetControl {
    /* 00 */ s32 mAcState;
    /* 04 */ u16 mState;
    /* 06 */ u16 mOnline;
    /* 08 */ u16 mDmaNo;
    /* 0a */ u16 mPowerMode;
} DWCInetControl;

#include "00/Lib/GameSpy/code_021a3a18.h"

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

extern DWCInetControl *gInetControl;
