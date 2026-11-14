#include "03/Net/usb_scan.h"
#include "03/Net/ap_scan_callback.h"
#include "03/unk_021d6000.h"

#include "03/code_021ce000.h"
#include "03/unk_021da000.h"
#include "code_02142eac.h"
#include "string.h"
#include "code_02134398.h"
#include "code_0200eddc.h"
#include "code_0200fc8c.h"
#include "code_0214d018.h"
#include "03/System/tasks.h"
#include "03/System/exp_heap.h"
#include "os_tick.h"
#include "registers.h"
#include "03/code_021ce110.h"

const u8 gUsbScanEmptyBssid[6] = {0, 0, 0, 0, 0, 0};
const u8 gUsbSsidPrefix[9] = {0x4e, 0x57, 0x43, 0x55, 0x53, 0x42, 0x41, 0x50, 0};
const Bytes68 gUsbScanParamTemplate = {
    {0, 0x3fff0400, 0xffff0000, 0xffffffff, 0x200002, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0}};

UsbScan *gUsbScan;

BOOL InitUsbScan(void (*callback)(u32)) {
    UsbScan *scan;
    OwnerInfo ownerInfo;
    u64 tick;

    gUsbScan = AllocZeroedExpHeapBlock(0x1ba0, 0x20);
    gUsbScan->mResultCallback = callback;
    scan = gUsbScan;
    tick = OS_GetTick();
    scan->mStartTickLow = tick;
    scan->mStartTickHigh = tick >> 32;
    if (WM_Initialize(scan, UsbScanCallback, 3) == 2) {
        do {
            WM_ReadStatus(&gUsbScan->mUnk_13b8);
        } while (gUsbScan->mUnk_13b8.mState != WIRELESS_UNIT_STATE_POWERED_ON);
        scan = gUsbScan;
        *(Bytes68 *) &scan->mUnk_1374 = gUsbScanParamTemplate;
        scan->mUnk_1374.mScanBuf = scan->mUnk_0f00;
        gUsbScan->mUnk_1374.mMaxChannelTime = WM_GetDispersionScanPeriod();
        OS_GetOwnerInfo(&ownerInfo);
        MI_CpuCopy8(gUsbSsidPrefix, &gUsbScan->mUnk_1374.mSsid[0], 8);
        gUsbScan->mUnk_1374.mSsid[9] = 1;
        MI_CpuCopy8(ownerInfo.mNickName, &gUsbScan->mUnk_1374.mSsid[0xc], ownerInfo.mNickNameLength * 2);
        if (StartUsbScan() != 0) {
            gUsbScan->mReportTask = AddTask(0, AdvanceUsbScanReport, NULL, 0x78);
            return 1;
        }
    }
    FreeExpHeapBlockAndClearPointer(&gUsbScan);
    return 0;
}

BOOL StartUsbScan(void) {
    int startResult;
    startResult = WM_StartScanEx(UsbScanCallback, &gUsbScan->mUnk_1374);
    if (startResult == 2) {
        return 1;
    }
    return 0;
}

BOOL ReleaseUsbScan(void) {
    UsbScan *scan;

    gUsbScan->mUnk_1b80 = 1;
    WM_ReadStatus(&gUsbScan->mUnk_13b8);
    if (gUsbScan->mUnk_13b8.mState != WIRELESS_UNIT_STATE_POWERED_ON) {
        if (WM_Reset(UsbScanCallback) != 2) {
            return 0;
        }
        do {
            WM_ReadStatus(&gUsbScan->mUnk_13b8);
        } while (gUsbScan->mUnk_13b8.mState != WIRELESS_UNIT_STATE_POWERED_ON);
    }
    if (WM_End(UsbScanCallback) != 2) {
        return 0;
    }
    scan = gUsbScan;
    if (scan->mReportTask != 0) {
        RemoveTaskEntryWrapper(0, scan->mReportTask);
    }
    scan = gUsbScan;
    while (*(vu8 *) &scan->mUnk_1b80 != 2) {
    }
    FreeExpHeapBlockAndClearPointer(&gUsbScan);
    return 1;
}

void SetUsbScanCallback(u32 callback) {
    gUsbScan->mResultCallback = (void (*)(u32)) callback;
}

void UsbScanCallback(WirelessMessage *message) {
    UsbScan *scan;

    if (message->mResultCode != 0) {
        return;
    }
    scan = gUsbScan;
    if (scan->mUnk_1b80 != 0) {
        if (message->mCommand == 2) {
            scan->mUnk_1b80 = 2;
        }
        return;
    }
    if (message->mCommand != 0x26) {
        return;
    }
    switch (message->mReplyState) {
        case 5:
            if (scan->mReported != 0) {
                CheckUsbScanEntries((WMStartScanExCallback *) message);
            } else {
                StoreUsbScanEntries((WMStartScanExCallback *) message);
            }
            StartUsbScan();
            break;
        case 4:
            StartUsbScan();
            break;
        default:
            OS_Terminate();
            break;
    }
}

void StoreUsbScanEntries(WMStartScanExCallback *scanResult) {
    s32 descIndex;

    for (descIndex = 0; descIndex < scanResult->mBssDescCount; descIndex++) {
        WMBssDesc *bssDesc;
        s32 entryIndex;
        u8 *slotBssid;
        u8 *freeSlotBssid;
        s32 emptyEntryIndex;
        UsbScan *scan;

        bssDesc = scanResult->mBssDesc[descIndex];
        DC_InvalidateRange(bssDesc, 0xc0);
        if (memcmp(bssDesc->mSsid, gUsbSsidPrefix, 8) != 0) {
            continue;
        }
        entryIndex = 0;
        scan = gUsbScan;
        slotBssid = scan->mEntries[0].mBssid;
        for (; entryIndex < 16; entryIndex++) {
            if (memcmp(bssDesc->mBssid, slotBssid, 6) == 0) {
                if (scan->mEntries[entryIndex].mFlag != 0) {
                    goto next;
                }
                if ((bssDesc->mSsid[9] & 1) == 0) {
                    goto next;
                }
                if (scan->mResultCallback != NULL) {
                    scan->mResultCallback(1);
                }
                return;
            }
            slotBssid += 7;
        }
        emptyEntryIndex = 0;
        freeSlotBssid = scan->mEntries[0].mBssid;
        for (; emptyEntryIndex < 16; emptyEntryIndex++) {
            if (memcmp(freeSlotBssid, gUsbScanEmptyBssid, 6) == 0) {
                MI_CpuCopy8(bssDesc->mBssid, scan->mEntries[emptyEntryIndex].mBssid, 6);
                gUsbScan->mEntries[emptyEntryIndex].mFlag = (bssDesc->mSsid[9] & 1) ? 1 : 0;
                goto next;
            }
            freeSlotBssid += 7;
        }
    next:;
    }
}

void CheckUsbScanEntries(WMStartScanExCallback *scanResult) {
    s32 descIndex;
    UsbScan *usbScan;
    s32 resultCount;
    UsbScan *scan;

    scan = gUsbScan;
    if (scan->mUnk_1b81 != 0) {
        if (scan->mResultCallback != NULL) {
            scan->mResultCallback(scan->mUnk_1b81);
        }
        return;
    }
    DC_InvalidateRange(scan->mUnk_0f00, 0x400);
    descIndex = 0;
    resultCount = scanResult->mBssDescCount;
    if (resultCount > 0) {
        usbScan = gUsbScan;
        do {
            s32 entryIndex;
            u8 *slotBssid;
            WMBssDesc *bssDesc;

            bssDesc = scanResult->mBssDesc[descIndex];
            if (memcmp(bssDesc->mSsid, gUsbSsidPrefix, 8) != 0) {
                continue;
            }
            if ((bssDesc->mSsid[9] & 1) == 0) {
                continue;
            }
            for (entryIndex = 0, slotBssid = usbScan->mEntries[0].mBssid; entryIndex < 16; entryIndex++) {
                if (memcmp(bssDesc->mBssid, slotBssid, 6) == 0) {
                    if (usbScan->mEntries[entryIndex].mFlag != 0) {
                        break;
                    }
                    if (usbScan->mResultCallback != NULL) {
                        usbScan->mResultCallback(1);
                        return;
                    }
                    usbScan->mUnk_1b81 = 1;
                    return;
                }
                slotBssid += 7;
            }
        } while (++descIndex < resultCount);
    }
}
