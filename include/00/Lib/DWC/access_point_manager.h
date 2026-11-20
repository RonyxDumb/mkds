#pragma once

#include "types.h"
#include "00/Lib/DWC/network_check_status.h"
#include "00/Lib/DWC/network_check_control.h"
#include "00/Lib/DWC/access_point_power_mode.h"
#include "00/Lib/DWC/access_point_state.h"
#include "cpu_copy_fill.h"
#include "00/Lib/NitroWiFi/wireless_connection_options.h"
#include "00/Lib/DWC/access_point_scan.h"
#include "00/Lib/DWC/connect_test_run.h"
#include "00/Lib/DWC/access_point_search.h"
#include "00/Lib/DWC/access_point_connect.h"

// The settings DWC_AC_Create takes: allocator, free function, DMA number, power mode, connection type, net check skip.
typedef struct DWCACConfig {
    /* 00 */ void *(*mAlloc)();
    /* 04 */ void (*mFree)();
    /* 08 */ u8 mDmaNo;
    /* 09 */ u8 mPowerMode;
    /* 0a */ u8 mConnectType;
    /* 0b */ u8 mSkipNetCheck;
} DWCACConfig;

// Values of WifiReportArgument.mReportCode that DWCi_AC_CallBackWCM turns into a connect result when a connect request
// did not succeed.
enum {
    WIFI_REPORT_CODE_RETRY_AUTH_FALLBACK = 0xd,
    WIFI_REPORT_CODE_ERROR_51100 = 0xf,
    WIFI_REPORT_CODE_ERROR_51200 = 0x11,
};

// Argument of DWCi_AC_CallBackWCM.
typedef struct WifiReportArgument {
    /* 00 */ s16 mNotify;
    /* 02 */ s16 mResult;
    /* 04 */ WMBssDesc *mBssDesc;
    /* 08 */ s32 mReportCode;
} WifiReportArgument;

static inline void AccessPointMI_CpuClear32(void *buffer, u32 byteCount) {
    vu32 zero = 0;
    MIi_CpuClear32(zero, buffer, byteCount);
}

BOOL DWC_AC_Destroy(void);
u32 DWC_AC_GetStatus(void);
s32 DWC_AC_Process(void);
BOOL DWC_AC_Create(DWCACConfig *config);
void SortList(u32 listIndex, ACWORK *work);
void UpDateList(u32 listIndex, WMBssDesc *bssdesc, ACWORK *work);
void SetDataListTail(u8 type, WMBssDesc *bssdesc, ACWORK *work);
s32 AddList(u32 type, WMBssDesc *bssdesc, ACWORK *work);
s32 CompareList(WMBssDesc *bssdesc, s32 num, ACSL *list);
s32 DWCi_AC_CheckNintendoSSID(WMBssDesc *bssdesc);
void DWCi_AC_GetBeacon(WMBssDesc *bssdesc);
void DWCi_AC_CallBackWCM(WifiReportArgument *notice);
