#include "03/code_021ce5b8.h"
#include "03/unk_021d6000.h"

#include "03/code_021ce000.h"
#include "03/unk_021da000.h"
#include "code_02142eac.h"
#include "string.h"
#include "code_02134398.h"
#include "code_0200eddc.h"
#include "code_0200fc8c.h"
#include "code_0214d018.h"
#include "03/code_021d3488.h"
#include "03/code_021d27d8.h"
#include "code_0200f5ac.h"
#include "registers.h"
#include "03/code_021ce110.h"

BOOL InitUsbScan(void (*callback)(u32)) {
    UsbScan *scan;
    Unk0200fddc ownerInfo;
    u64 tick;

    gUsbScan = AllocZeroedExpHeapBlock(0x1ba0, 0x20);
    gUsbScan->mUnk_1370 = callback;
    scan = gUsbScan;
    tick = OS_GetTick();
    scan->mUnk_1b74 = tick;
    scan->mUnk_1b78 = tick >> 32;
    if (WM_Initialize(scan, UsbScanCallback, 3) == 2) {
        do {
            WM_ReadStatus(&gUsbScan->mUnk_13b8);
        } while (gUsbScan->mUnk_13b8.mState != 2);
        scan = gUsbScan;
        *(Bytes68 *) &scan->mUnk_1374 = gUsbScanParamTemplate;
        scan->mUnk_1374.mUnk_00 = scan->mUnk_0f00;
        gUsbScan->mUnk_1374.mUnk_08 = WM_GetDispersionScanPeriod();
        OS_GetOwnerInfo(&ownerInfo);
        MI_CpuCopy8(gUsbSsidPrefix, &gUsbScan->mUnk_1374.mUnk_14[0], 8);
        gUsbScan->mUnk_1374.mUnk_14[9] = 1;
        MI_CpuCopy8(ownerInfo.mUnk_04, &gUsbScan->mUnk_1374.mUnk_14[0xc], ownerInfo.mUnk_18 * 2);
        if (StartUsbScan() != 0) {
            gUsbScan->mUnk_1b7c = AddTask(0, AdvanceUsbScanReport, NULL, 0x78);
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
    if (gUsbScan->mUnk_13b8.mState != 2) {
        if (WM_Reset(UsbScanCallback) != 2) {
            return 0;
        }
        do {
            WM_ReadStatus(&gUsbScan->mUnk_13b8);
        } while (gUsbScan->mUnk_13b8.mState != 2);
    }
    if (WM_End(UsbScanCallback) != 2) {
        return 0;
    }
    scan = gUsbScan;
    if (scan->mUnk_1b7c != 0) {
        RemoveTaskEntryWrapper(0, scan->mUnk_1b7c);
    }
    scan = gUsbScan;
    while (*(vu8 *) &scan->mUnk_1b80 != 2) {
    }
    FreeExpHeapBlockAndClearPointer(&gUsbScan);
    return 1;
}

void SetUsbScanCallback(u32 callback) {
    gUsbScan->mUnk_1370 = (void (*)(u32)) callback;
}

void UsbScanCallback(Unk021425e8 *message) {
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
    switch (message->mUnk_08_0) {
        case 5:
            if (scan->mUnk_1b82 != 0) {
                CheckUsbScanEntries((Unk021ce5b8 *) message);
            } else {
                StoreUsbScanEntries((Unk021ce5b8 *) message);
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

void StoreUsbScanEntries(Unk021ce5b8 *scanResult) {
    s32 i;

    for (i = 0; i < scanResult->mUnk_0e; i++) {
        Unk021ce5b8_10 *bssDesc;
        s32 j;
        u8 *slotBssid;
        u8 *freeSlotBssid;
        s32 k;
        UsbScan *scan;

        bssDesc = scanResult->mUnk_10[i];
        DC_InvalidateRange(bssDesc, 0xc0);
        if (memcmp(bssDesc->mUnk_0c, gUsbSsidPrefix, 8) != 0) {
            continue;
        }
        j = 0;
        scan = gUsbScan;
        slotBssid = scan->mUnk_1300[0].mBssid;
        for (; j < 16; j++) {
            if (memcmp(bssDesc->mUnk_04, slotBssid, 6) == 0) {
                if (scan->mUnk_1300[j].mFlag != 0) {
                    goto next;
                }
                if ((bssDesc->mUnk_15 & 1) == 0) {
                    goto next;
                }
                if (scan->mUnk_1370 != NULL) {
                    scan->mUnk_1370(1);
                }
                return;
            }
            slotBssid += 7;
        }
        k = 0;
        freeSlotBssid = scan->mUnk_1300[0].mBssid;
        for (; k < 16; k++) {
            if (memcmp(freeSlotBssid, gUsbScanEmptyBssid, 6) == 0) {
                MI_CpuCopy8(bssDesc->mUnk_04, scan->mUnk_1300[k].mBssid, 6);
                gUsbScan->mUnk_1300[k].mFlag = (bssDesc->mUnk_15 & 1) ? 1 : 0;
                goto next;
            }
            freeSlotBssid += 7;
        }
    next:;
    }
}

void CheckUsbScanEntries(Unk021ce5b8 *scanResult) {
    s32 i;
    UsbScan *q;
    s32 resultCount;
    UsbScan *scan;

    scan = gUsbScan;
    if (scan->mUnk_1b81 != 0) {
        if (scan->mUnk_1370 != NULL) {
            scan->mUnk_1370(scan->mUnk_1b81);
        }
        return;
    }
    DC_InvalidateRange(scan->mUnk_0f00, 0x400);
    i = 0;
    resultCount = scanResult->mUnk_0e;
    if (resultCount > 0) {
        q = gUsbScan;
        do {
            s32 j;
            u8 *slotBssid;
            Unk021ce5b8_10 *bssDesc;

            bssDesc = scanResult->mUnk_10[i];
            if (memcmp(bssDesc->mUnk_0c, gUsbSsidPrefix, 8) != 0) {
                continue;
            }
            if ((bssDesc->mUnk_15 & 1) == 0) {
                continue;
            }
            for (j = 0, slotBssid = q->mUnk_1300[0].mBssid; j < 16; j++) {
                if (memcmp(bssDesc->mUnk_04, slotBssid, 6) == 0) {
                    if (q->mUnk_1300[j].mFlag != 0) {
                        break;
                    }
                    if (q->mUnk_1370 != NULL) {
                        q->mUnk_1370(1);
                        return;
                    }
                    q->mUnk_1b81 = 1;
                    return;
                }
                slotBssid += 7;
            }
        } while (++i < resultCount);
    }
}
