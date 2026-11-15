#include "03/Net/ap_scan.h"
#include "03/Menu/wifi_menu_tables.h"
#include "string.h"
#include "print_memory_multibyte_write.h"

#include "03/types_021da26c.h"
#include "03/Net/ap_scan_callback.h"
#include "wireless_link_control.h"
#include "cpu_copy_clear_16.h"
#include "03/System/exp_heap.h"
#include "03/Menu/wifi_menu_shared.h"

const ScanExParam gApScanParamTemplate = {
    NULL,
    0x400,
    0x3fff,
    0,
    {0xff, 0xff, 0xff, 0xff, 0xff, 0xff},
    0,
    0,
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    0,
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

struct ApScan *gApScan;

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
    MIi_CpuClear16(zeroValue, gApScan->mEntries, 0x348);
    if (WM_Initialize(gApScan, ApScanCallback, 3) != 2) {
        return 0;
    }
    do {
        WM_ReadStatus(&gApScan->mStatus);
    } while (gApScan->mStatus.mState != WIRELESS_UNIT_STATE_POWERED_ON);
    apScan = gApScan;
    apScan->mScanParam = gApScanParamTemplate;
    apScan->mScanParam.mScanBuf = apScan->mScanBuf;
    gApScan->mScanParam.mMaxChannelTime = WM_GetDispersionScanPeriod();
    if (StartApScan() != 0) {
        return 1;
    }
    return 0;
}

BOOL StartApScan(void) {
    int startResult;
    startResult = WM_StartScanEx(ApScanCallback, &gApScan->mScanParam);
    if (startResult == 2) {
        return 1;
    }
    return 0;
}

BOOL StopApScan(void) {
    gApScan->mStopRequested = 1;
    WM_ReadStatus(&gApScan->mStatus);
    if (gApScan->mStatus.mState != WIRELESS_UNIT_STATE_POWERED_ON) {
        if (WM_Reset(ApScanCallback) != 2) {
            return 0;
        }
        do {
            WM_ReadStatus(&gApScan->mStatus);
        } while (gApScan->mStatus.mState != WIRELESS_UNIT_STATE_POWERED_ON);
    }
    if (WM_End(ApScanCallback) != 2) {
        return 0;
    }
    return 1;
}

int CountApScanEntries(ApScanEntry **entriesOut) {
    int slotIndex;
    int entryCount;
    ApScanEntry *entry;
    int bssidDiff;
    entryCount = 0;
    *entriesOut = gApScan->mEntries;
    slotIndex = 0;
    entry = *entriesOut;
    do {
        bssidDiff = memcmp(entry->mBssid, gApScanEmptyBssid, 6);
        if (bssidDiff != 0) {
            entryCount = entryCount + 1;
        }
        entry++;
        slotIndex = slotIndex + 1;
    } while (slotIndex < 0x14);
    return entryCount;
}
