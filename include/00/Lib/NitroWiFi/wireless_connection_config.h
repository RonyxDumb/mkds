#pragma once

#include "types.h"
#include "00/Lib/NitroWiFi/wireless_connection_control.h"

typedef struct WCMNotice WCMNotice;
typedef struct WCMWork WCMWork;

typedef struct WCMConfig {
    /* 00 */ u32 mDmaNo;
    /* 04 */ u8 *mPbdBuffer;
    /* 08 */ u32 mNbdBuffer;
    /* 0c */ u32 mNbdMode;
} WCMConfig;

void WcmWmReset(void);
void WcmKeepAliveAlarm(void *arg);
void WCMi_ResetKeepAliveAlarm(void);
void WcmSetPhase(u32 phase);
void WcmNotifyEx(s16 notify, u32 result, void *para0, u32 para1, u32 para2);
void WcmNotify(u32 result, const void *para0, u32 para1, u32 para2);
u16 WcmGetNextScanChannel(u16 channel);
void WcmInitOption(void);
void WcmEditScanExParam(const void *bssid, const u8 *essid, u32 option);
void WcmConfigure(WCMConfig *config, void (*notify)(WCMNotice *));
WCMWork *WCMi_GetSystemWork(void);
