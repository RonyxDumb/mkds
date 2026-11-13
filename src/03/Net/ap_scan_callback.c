#include "03/Net/ap_scan_callback.h"
#include "03/Menu/scroll_bar.h"
#include "03/code_021cd000.h"
#include "03/code_021d1790.h"
#include "03/code_021d197c.h"
#include "03/unk_021da000.h"
#include "code_0200fc8c.h"
#include "code_02142eac.h"
#include "03/Net/ap_scan.h"
#include "03/code_021d1000.h"
#include "03/System/rect.h"
#include "03/System/exp_heap.h"
#include "03/code_021d3000.h"
#include "03/System/tasks.h"
#include "string.h"
#include "code_02134398.h"
#include "code_0214d018.h"
#include "code_0200eddc.h"

const u8 gOtherElementPrefix[4] = {0, 0x50, 0xf2, 1};
const u8 gApScanEmptyBssid[6] = {0, 0, 0, 0, 0, 0};

void ApScanCallback(WirelessMessage *message) {
    if (message->mResultCode == 0 && gApScan->mUnk_1e48 == 0 && message->mCommand == 0x26) {
        switch (message->mReplyState) {
            case 5:
                StoreApScanEntries((WMStartScanExCallback *) message);
                StartApScan();
                break;
            case 4:
                StartApScan();
                break;
            default:
                OS_Terminate();
                break;
        }
    }
}

void StoreApScanEntries(WMStartScanExCallback *scanResult) {
    ApScanEntry *entries = gApScan->mEntries;
    s32 descIndex;
    s32 entryIndex;
    DC_InvalidateRange(gApScan->mScanBuf, 0x400);
    for (descIndex = 0; descIndex < scanResult->mBssDescCount; descIndex++) {
        WMBssDesc *bssDesc = scanResult->mBssDesc[descIndex];
        if (bssDesc->mSsid[0] != 0 && bssDesc->mGameInfoLength == 0) {
            ApScanEntry *cursor;
            ApScanEntry *slot;
            entryIndex = 0;
            cursor = entries;
            for (; entryIndex < 0x14; entryIndex++) {
                if (memcmp(bssDesc->mBssid, cursor->mBssid, 6) == 0) {
                    break;
                }
                cursor++;
            }
            if (entryIndex == 0x14) {
                entryIndex = 0;
                cursor = entries;
                for (; entryIndex < 0x14; entryIndex++) {
                    if (memcmp(cursor->mBssid, gApScanEmptyBssid, 6) == 0) {
                        break;
                    }
                    cursor++;
                }
                if (entryIndex == 0x14) {
                    return;
                }
            }
            slot = &entries[entryIndex];
            MI_CpuCopy8(bssDesc->mBssid, slot->mBssid, 6);
            MI_CpuCopy8(bssDesc->mSsid, slot, 0x20);
            slot->mLinkLevel = scanResult->mLinkLevel[descIndex];
            if ((bssDesc->mCapaInfo & 0x10) == 0) {
                slot->mCapaLevel = 0;
            } else {
                WMOtherElements otherElements;
                s32 elementIndex;
                s32 elementCount;
                slot->mCapaLevel = 1;
                otherElements = WM_GetOtherElements((const u16 *) bssDesc);
                elementIndex = 0;
                elementCount = otherElements.mCount;
                for (; elementIndex < elementCount; elementIndex++) {
                    if (otherElements.mElement[elementIndex].mId == 0x30) {
                        slot->mCapaLevel = 2;
                        break;
                    }
                    if (otherElements.mElement[elementIndex].mId == 0xdd &&
                        otherElements.mElement[elementIndex].mLength >= 4 &&
                        memcmp(otherElements.mElement[elementIndex].mBody, gOtherElementPrefix, 4) == 0) {
                        slot->mCapaLevel = 2;
                        break;
                    }
                }
            }
        }
    }
}
