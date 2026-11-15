#pragma once

#include "types.h"
#include "00/Lib/DWC/code_02187484.h"
#include "00/Lib/DWC/code_02188008.h"
#include "00/Lib/DWC/code_02188ec0.h"
#include "00/Lib/DWC/code_021884d8.h"
#include "code_0214d018.h"
#include "00/Lib/NitroWiFi/code_021a5b3c.h"
#include "00/Lib/DWC/code_0218973c.h"
#include "00/Lib/DWC/code_0218a294.h"
#include "00/Lib/DWC/code_021898dc.h"
#include "00/Lib/DWC/code_02188ee0.h"

// Argument of DWC_AC_Create: the first two words go to the ACHOLD and the DWCNetcheckParam it sets up, the
// bytes at 8 to 0xb to the object at gAcWork.
typedef struct DWCACConfig {
    /* 00 */ void *(*mAlloc)();
    /* 04 */ void (*mFree)();
    /* 08 */ u8 mDmaNo;
    /* 09 */ u8 mPowerMode;
    /* 0a */ u8 mConnectType;
    /* 0b */ u8 mSkipNetCheck;
} DWCACConfig;

// Values of WifiReportArgument.mReportCode that DWCi_AC_CallBackWCM turns into a connect result.
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

static inline void ClearBuffer32(void *buffer, u32 byteCount) {
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
