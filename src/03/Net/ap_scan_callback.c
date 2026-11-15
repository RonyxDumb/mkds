#include "03/Net/ap_scan_callback.h"
#include "03/Menu/scroll_bar.h"
#include "03/Graphics/oam_range_set.h"
#include "03/Graphics/oam_range.h"
#include "03/Menu/wifi_menu_shared.h"
#include "reset_interrupts_halt.h"
#include "wireless_link_control.h"
#include "03/Net/ap_scan.h"
#include "03/System/rect.h"
#include "03/System/exp_heap.h"
#include "03/System/tasks.h"
#include "string.h"
#include "print_memory_multibyte_write.h"
#include "cpu_copy_fill.h"
#include "arena_cache_init.h"

const u8 gOtherElementPrefix[4] = {0, 0x50, 0xf2, 1};
const u8 gApScanEmptyBssid[6] = {0, 0, 0, 0, 0, 0};

void ApScanCallback(WirelessMessage *message) {
    if (message->mResultCode == 0 && gApScan->mStopRequested == 0 &&
        message->mCommand == WIRELESS_REQUEST_BEGIN_SEARCH_CHANNELS) {
        switch (message->mReplyState) {
            case WIRELESS_STATE_HOST_SIGHTED:
                StoreApScanEntries((WMStartScanExCallback *) message);
                StartApScan();
                break;
            case WIRELESS_STATE_SEARCH_EMPTY:
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
            MI_CpuCopy8(bssDesc->mSsid, slot, sizeof(bssDesc->mSsid));
            slot->mLinkLevel = scanResult->mLinkLevel[descIndex];
            if ((bssDesc->mCapaInfo & AP_SCAN_CAPA_INFO_ENCRYPTED) == 0) {
                slot->mCapaLevel = AP_CAPA_LEVEL_OPEN;
            } else {
                WMOtherElements otherElements;
                s32 elementIndex;
                s32 elementCount;
                slot->mCapaLevel = AP_CAPA_LEVEL_ENCRYPTED;
                otherElements = WM_GetOtherElements((const u16 *) bssDesc);
                elementIndex = 0;
                elementCount = otherElements.mCount;
                for (; elementIndex < elementCount; elementIndex++) {
                    if (otherElements.mElement[elementIndex].mId == AP_SCAN_ELEMENT_ID_SECURITY) {
                        slot->mCapaLevel = AP_CAPA_LEVEL_SECURITY_ELEMENT;
                        break;
                    }
                    if (otherElements.mElement[elementIndex].mId == AP_SCAN_ELEMENT_ID_VENDOR &&
                        otherElements.mElement[elementIndex].mLength >= sizeof(gOtherElementPrefix) &&
                        memcmp(otherElements.mElement[elementIndex].mBody, gOtherElementPrefix, 4) == 0) {
                        slot->mCapaLevel = AP_CAPA_LEVEL_SECURITY_ELEMENT;
                        break;
                    }
                }
            }
        }
    }
}
