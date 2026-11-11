#include "03/code_021cd0d0.h"
#include "03/unk_021d6000.h"
#include "string.h"
#include "code_02134398.h"
#include "03/code_021cd000.h"

#include "03/types_021da26c.h"
#include "03/code_021cce78.h"
#include "code_02142eac.h"
#include "code_0214cfe4.h"
#include "03/code_021d27d8.h"
#include "03/unk_021da000.h"

void CreateApScan(void) {
    if (gApScan == NULL) {
        gApScan = AllocZeroedExpHeapBlock(0x1e60, 32);
    }
}

void ReleaseApScan(void) {
    if (gApScan != NULL) {
        while (WM_GetAllowedChannel() != 0x8000) {
        }
        FreeExpHeapBlockAndClearPointer(&gApScan);
    }
}

BOOL InitApScan(void) {
    ApScan *apScan;
    volatile u16 zeroValue = 0;
    MIi_CpuClear16(zeroValue, gApScan->mUnk_1300, 0x348);
    if (WM_Initialize(gApScan, ApScanCallback, 3) != 2) {
        return 0;
    }
    do {
        WM_ReadStatus(&gApScan->mUnk_168c);
    } while (gApScan->mUnk_168c.mState != 2);
    apScan = gApScan;
    apScan->mUnk_1648 = gApScanParamTemplate;
    apScan->mUnk_1648.mUnk_00.mUnk_00 = apScan->mUnk_0f00;
    gApScan->mUnk_1648.mUnk_00.mUnk_08 = WM_GetDispersionScanPeriod();
    if (StartApScan() != 0) {
        return 1;
    }
    return 0;
}

BOOL StartApScan(void) {
    int startResult;
    startResult = WM_StartScanEx(ApScanCallback, &gApScan->mUnk_1648.mUnk_00);
    if (startResult == 2) {
        return 1;
    }
    return 0;
}

BOOL StopApScan(void) {
    gApScan->mUnk_1e48 = 1;
    WM_ReadStatus(&gApScan->mUnk_168c);
    if (gApScan->mUnk_168c.mState != 2) {
        if (WM_Reset(ApScanCallback) != 2) {
            return 0;
        }
        do {
            WM_ReadStatus(&gApScan->mUnk_168c);
        } while (gApScan->mUnk_168c.mState != 2);
    }
    if (WM_End(ApScanCallback) != 2) {
        return 0;
    }
    return 1;
}

int CountApScanEntries(int *entriesOut) {
    int slotIndex;
    int entryCount;
    int entryAddress;
    int bssidDiff;
    entryCount = 0;
    *entriesOut = (s32) gApScan->mUnk_1300;
    slotIndex = 0;
    entryAddress = *entriesOut;
    do {
        bssidDiff = memcmp((const u8 *) (entryAddress + 0x20), gApScanEmptyBssid, 6);
        if (bssidDiff != 0) {
            entryCount = entryCount + 1;
        }
        entryAddress = entryAddress + 0x2a;
        slotIndex = slotIndex + 1;
    } while (slotIndex < 0x14);
    return entryCount;
}
