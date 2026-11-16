#pragma once

#include "types.h"
#include "reset_interrupts_halt.h"
#include "00/Lib/DWC/auth_http_params.h"
#include "wifi_settings_nvram_backup.h"
#include "wifi_id_and_backup_check.h"
#include "00/Lib/DWC/http_header_build.h"
#include "00/Lib/CPS/tcp_ip_stack.h"
#include "00/Lib/NitroWiFi/rssi_link_level.h"
#include "00/Lib/DWC/shop_access_point_key.h"
#include "00/Lib/NitroWiFi/wifi_stack_bridge.h"
#include "00/Lib/DWC/server_auth.h"
#include "00/Lib/DWC/network_check_control.h"

typedef struct OSThread OSThread;

// The network check: its error and return code, HTTP labels and values, response bodies, thread and mutex.
typedef struct DWCNetcheck {
    /* 000 */ u32 mError;
    /* 004 */ s32 mReturnCode;
    /* 008 */ DWCHttpLabelValue mHttpLabelvalue[0x20];
    /* 108 */ DWCNetcheckParam mParam;
    /* 114 */ void *mBody302;
    /* 118 */ void *mBodyWayport;
    /* 11c */ OSThread mThread;
    /* 1dc */ OSMutex mMutex;
    /* 1f4 */ u8 pad_1f4[0xc];
    /* 200 */ u8 mThreadStackArea[0x1000];
    /* 1200 */ u8 mThreadStack[0x1000];
} DWCNetcheck;

// Server login result: mReturnCode, mToken and mChallenge, filled by DWC_Auth_GetResult.
typedef struct DWCAuthResult {
    /* 000 */ s32 mReturnCode;
    /* 004 */ u8 mUnk_004[0x46];
    /* 04a */ char mToken[0x12d];
    /* 177 */ char mChallenge[0x4d];
} DWCAuthResult;

#include "thread_scheduler.h"


u32 DWC_Netcheck_GetReturnCode(void);
void DWCi_Netcheck_SetError(u32 error);
u32 DWC_Netcheck_GetError(void);
void DWCi_Netcheck_Thread(void);
void UnusedAllocLiterals(void);
void DWC_Netcheck_Abort(void);
