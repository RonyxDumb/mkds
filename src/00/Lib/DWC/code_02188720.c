#include "00/Lib/DWC/code_02188720.h"
#include "00/Lib/DWC/code_021884d8.h"
#include "00/unk_021b4000.h"
#include "00/Lib/DWC/code_02188008.h"
#include "00/Lib/DWC/code_02188694.h"
#include "00/Lib/DWC/code_02189478.h"
#include "00/Lib/DWC/code_0218a658.h"
#include "00/code_0218a000.h"
#include "00/unk_021b2000.h"
#include "string.h"
#include "code_02134398.h"
#include "00/Lib/DWC/code_0218a67c.h"
#include "00/Lib/DWC/code_021892f4.h"
#include "code_0200fc8c.h"
#include "code_02139f70.h"
#include "code_0214d018.h"
#include "Main/Save/nvram_first_three.h"
#include "00/Lib/NitroWiFi/code_021a4b98.h"

ACHOLD *gAcHold;
ACWORK *gAcWork;
void *gWcmBuffer;
void *gSocConfig;
DWCNetcheckParam *gNetCheck;

void DWCi_AC_CallBackWCM(WifiReportArgument *notice) {
    ACWORK *work;

    work = (ACWORK *) DWCi_AC_GetMemPtr(0x10);
    if (notice->mNotify == WIFI_NOTIFY_CONNECT_REQUEST) {
        if (notice->mResult != WIFI_REPORT_SUCCEEDED) {
            switch (notice->mUnk_08) {
                case WIFI_REPORT_CODE_RETRY_AUTH_FALLBACK:
                    work->mConnectResult = AUTO_CONNECT_RESULT_RETRY_AUTH_FALLBACK;
                    break;
                case WIFI_REPORT_CODE_ERROR_51100:
                    work->mConnectResult = AUTO_CONNECT_RESULT_ERROR_51100;
                    break;
                case WIFI_REPORT_CODE_ERROR_51200:
                    work->mConnectResult = AUTO_CONNECT_RESULT_ERROR_51200;
                    break;
                default:
                    work->mConnectResult = AUTO_CONNECT_RESULT_OTHER;
                    break;
            }
        }
    } else if (notice->mNotify == WIFI_NOTIFY_SEARCH_FOUND) {
        DWCi_AC_GetBeacon(notice->mUnk_04);
    }
}

void DWCi_AC_GetBeacon(WMBssDesc *bssdesc) {
    ACWORK *work;
    s32 type;
    u32 phase;

    type = -1;
    work = (ACWORK *) DWCi_AC_GetMemPtr(0x10);
    ((ACHOLD *) DWCi_AC_GetMemPtr(1))->mUnk_0b = 1;
    phase = DWCi_AC_GetPhase();
    switch (phase) {
        case 3:
            if (bssdesc->mSsidLength == 0 || bssdesc->mSsid[0] == 0) {
                DWCi_AC_SetStealthChannel(bssdesc->mChannel);
            } else if (bssdesc->mSsidLength == 1 || bssdesc->mSsid[0] == 0x20) {
                DWCi_AC_SetStealthChannel(bssdesc->mChannel);
                type = CompareList(bssdesc, work->mSearchListNum, work->mSearchList);
            } else {
                type = CompareList(bssdesc, work->mSearchListNum, work->mSearchList);
            }
            break;
        case 4:
        case 5:
            type = CompareList(bssdesc, 1, work->mSearchList + work->mSearchListNo);
            if (type >= 0) {
                work->mSearchList[work->mSearchListNo].mUnk_00_lo = 1;
            }
            break;
        default:
            return;
    }
    if (type >= 0) {
        SortList(AddList(type, bssdesc, work), work);
    }
}

s32 DWCi_AC_CheckNintendoSSID(WMBssDesc *bssdesc) {
    ACWORK *work;
    u8 nintendoFlag;

    work = (ACWORK *) DWCi_AC_GetMemPtr(0x10);
    if (work->mConnectType == 0 || work->mConnectType == 4) {
        nintendoFlag = bssdesc->mCapaInfo >> 4 & 1;
        if (nintendoFlag == 1) {
            if (DWCi_AC_CheckNintendoUsbAP((const u8 *) bssdesc->mSsid) == 1) {
                return 6;
            }
        }
    }
    if (work->mConnectType == 0 || work->mConnectType == 5) {
        nintendoFlag = bssdesc->mCapaInfo >> 4 & 1;
        if (nintendoFlag == 1) {
            if (DWCi_AC_CheckNintendoShopAP((const u8 *) bssdesc->mSsid) == 1) {
                return 7;
            }
        }
    }
    return -1;
}

s32 CompareList(WMBssDesc *bssdesc, s32 num, ACSL *list) {
    s32 listIndex;
    s32 checkResult;
    u16 ssidLength;

    if (bssdesc->mSsidLength == 0x20) {
        checkResult = DWCi_AC_CheckNintendoSSID(bssdesc);
        if (checkResult > 0) {
            return checkResult;
        }
    }
    listIndex = 0;
    if (num > 0) {
        ssidLength = bssdesc->mSsidLength;
        do {
            if ((u8) ssidLength == list->mSsidLength) {
                if (strncmp((const char *) bssdesc->mSsid, (const char *) list->mSsid, ssidLength) == 0) {
                    return list->mApType;
                }
            }
            list++;
            listIndex++;
        } while (listIndex < num);
    }
    return -1;
}

s32 AddList(u32 type, WMBssDesc *bssdesc, ACWORK *work) {
    s32 findIndex;
    s32 found;
    u8 *entryBssid;
    s32 findListNum;

    findIndex = 0;
    found = -1;
    findListNum = work->mFindListNum;
    if (findListNum > 0) {
        entryBssid = work->mBssDesc[0].mBssid;
        do {
            if (bssdesc->mBssid[0] == entryBssid[0] && bssdesc->mBssid[1] == entryBssid[1] &&
                bssdesc->mBssid[2] == entryBssid[2] && bssdesc->mBssid[3] == entryBssid[3] &&
                bssdesc->mBssid[4] == entryBssid[4] && bssdesc->mBssid[5] == entryBssid[5]) {
                found = findIndex;
                break;
            }
            entryBssid += 0xc0;
            findIndex++;
        } while (findIndex < work->mFindListNum);
    }
    if (found == -1) {
        SetDataListTail(type, bssdesc, work);
        if (work->mFindListNum < 10) {
            work->mFindListNum++;
        }
        found = 10;
    } else {
        UpDateList(found, bssdesc, work);
    }
    return found;
}

void SetDataListTail(u8 type, WMBssDesc *bssdesc, ACWORK *work) {
    ACFL *tailFind;
    WMBssDesc *tailBss;
    u16 rssiWord;

    tailFind = &work->mFindList[10];
    tailBss = &work->mBssDesc[10];
    tailFind->mApType = type;
    rssiWord = bssdesc->mRssi;
    tailFind->mRssi = (rssiWord & 2) != 0 ? (u8) (rssiWord >> 2) : (u8) ((rssiWord >> 2) + 0x19);
    tailFind->mChannel = work->mSearchChannel + 1;
    MIi_CpuCopy32(bssdesc, tailBss, 0xc0);
}

void UpDateList(u32 listIndex, WMBssDesc *bssdesc, ACWORK *work) {
    ACFL *findEntry;
    WMBssDesc *bssEntry;
    u16 rssiWord;
    u8 rssiLevelByte;
    s32 rssiLevel;

    findEntry = &work->mFindList[listIndex];
    bssEntry = &work->mBssDesc[listIndex];
    rssiWord = bssdesc->mRssi;
    rssiLevel = (rssiWord & 2) != 0 ? (u8) (rssiWord >> 2) : (u8) ((rssiWord >> 2) + 0x19);
    rssiLevelByte = rssiLevel;
    if (rssiLevelByte > findEntry->mRssi) {
        findEntry->mRssi = rssiLevelByte;
        findEntry->mChannel = work->mSearchChannel + 1;
    }
    MIi_CpuCopy32(bssdesc, bssEntry, 0xc0);
}

void SortList(u32 listIndex, ACWORK *work) {
    ACFL *findList;
    WMBssDesc *bssDescList;
    ACFL *previousFind;
    WMBssDesc *previousBss;
    ACFL swapFind;
    WMBssDesc swapBss;
    s32 previousIndex;

    findList = work->mFindList;
    bssDescList = work->mBssDesc;
    previousIndex = listIndex - 1;
    if (previousIndex >= 0) {
        previousFind = &findList[previousIndex];
        previousBss = &bssDescList[previousIndex];
        do {
            if (findList[listIndex].mRssi < previousFind->mRssi) {
                break;
            }
            MIi_CpuCopy32(previousFind, &swapFind, 4);
            MIi_CpuCopy32(&findList[listIndex], previousFind, 4);
            MIi_CpuCopy32(&swapFind, &findList[listIndex], 4);
            MIi_CpuCopy32(previousBss, &swapBss, 0xc0);
            MIi_CpuCopy32(&bssDescList[listIndex], previousBss, 0xc0);
            MIi_CpuCopy32(&swapBss, &bssDescList[listIndex], 0xc0);
            listIndex = previousIndex;
            previousFind--;
            previousBss--;
            previousIndex--;
        } while (previousIndex >= 0);
    }
    findList += 10;
    func_0214d018_inline(findList, 4);
    func_0214d018_inline(bssDescList + 10, 0xc0);
}

BOOL DWC_AC_Create(DWCACConfig *config) {
    ACHOLD *hold;
    ACWORK *work;
    DWCNetcheckParam *netCheckParam;
    s32 result;

    gAcHold = config->mAlloc(1, 0x18);
    func_0214d018_inline(gAcHold, 0x18);
    hold = gAcHold;
    hold->mAlloc = config->mAlloc;
    hold->mFree = config->mFree;
    hold->mPhase = 1;
    hold->mEndSequence = 1;
    hold->mAllocState = 1;
    gAcWork = DWCi_AC_Alloc(0x10, 0xd18);
    gWcmBuffer = DWCi_AC_Alloc(2, 0x2300);
    gSocConfig = DWCi_AC_Alloc(4, 0x58);
    gNetCheck = DWCi_AC_Alloc(8, 0xc);
    func_0214d018_inline(gAcWork, 0xd18);
    func_0214d018_inline(gWcmBuffer, 0x2300);
    func_0214d018_inline(gSocConfig, 0x58);
    func_0214d018_inline(gNetCheck, 0xc);
    work = gAcWork;
    work->mDmaNo = config->mDmaNo;
    work->mPowerMode = config->mPowerMode;
    netCheckParam = gNetCheck;
    netCheckParam->mAlloc = config->mAlloc;
    netCheckParam->mFree = config->mFree;
    netCheckParam->mBmworkarea = 0;
    work->mConnectType = config->mConnectType;
    work->mSkipNetCheck = config->mSkipNetCheck;
    ReadNvramFirstThreeEntries(work);
    result = WCM_Init(gWcmBuffer, 0x2300);
    if (result == 1 || result >= 4) {
        DWCi_AC_FreeAll();
        return 0;
    }
    return 1;
}

s32 DWC_AC_Process(void) {
    u8 phase;
    u32 interruptState;
    s32 duplicateResult;

    phase = DWCi_AC_GetPhase();
    if (phase == 1) {
        phase = DWCi_AC_Start();
    } else if (phase < 7) {
        interruptState = OS_DisableInterrupts();
        phase = ((u8(*)(void)) DWCi_AC_SearchAP)();
        DWCi_AC_SetPhase(phase);
        OS_RestoreInterrupts(interruptState);
    } else if (phase < 9) {
        phase = ((u8(*)(void)) DWCi_AC_ConnectAP)();
    } else if (phase < 10) {
        phase = ((u8(*)(void)) DWCi_AC_ConnectRetryAP)();
    } else if (phase < 16) {
        phase = ((u8(*)(void)) DWCi_AC_ConnectTest)();
    } else if (phase == 17) {
        phase = DWCi_AC_Error();
    }
    DWCi_AC_SetPhase(phase);
    if (phase == 16) {
        duplicateResult = CheckDuplicate();
        FreeDisused();
        return duplicateResult;
    }
    if (phase == 18) {
        FreeDisused();
        return -1;
    }
    return 0;
}

u32 DWC_AC_GetStatus(void) {
    u32 phase;

    phase = DWCi_AC_GetPhase();
    if (phase <= 1) {
        return 0;
    }
    if (phase < 7) {
        return 1;
    }
    if (phase == 9) {
        return 4;
    }
    if (phase < 10) {
        return 2;
    }
    if (phase == 11) {
        return 4;
    }
    if (phase < 16) {
        return 3;
    }
    if (phase == 16) {
        return 5;
    }
    if (phase == 17) {
        return 4;
    }
    return DWCi_AC_GetResult();
}

BOOL DWC_AC_Destroy(void) {
    u8 phase;

    phase = DWCi_AC_GetPhase();
    if (phase == 0 || phase == 0x12) {
        DWCi_AC_FreeAll();
        return 1;
    }
    DWCi_AC_CloseNetwork(&phase);
    DWCi_AC_SetPhase(phase);
    return 0;
}
