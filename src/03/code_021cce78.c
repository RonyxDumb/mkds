#include "03/code_021cce78.h"
#include "03/code_021cca74.h"
#include "03/code_021cd000.h"
#include "03/code_021d1790.h"
#include "03/code_021d197c.h"
#include "03/unk_021da000.h"
#include "code_0200fc8c.h"
#include "code_02142eac.h"
#include "03/code_021cd0d0.h"
#include "03/code_021d1000.h"
#include "03/code_021d250c.h"
#include "03/code_021d27d8.h"
#include "03/code_021d3000.h"
#include "03/code_021d3488.h"
#include "string.h"
#include "code_02134398.h"
#include "code_0214d018.h"
#include "code_0200eddc.h"

void ApScanCallback(Unk021425e8 *message) {
    if (message->mResultCode == 0 && *((u8 *) gApScan + 0x1e48) == 0 && message->mCommand == 0x26) {
        switch (message->mUnk_08_0) {
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
    s32 i;
    s32 j;
    DC_InvalidateRange(gApScan->mScanBuf, 0x400);
    for (i = 0; i < scanResult->mBssDescCount; i++) {
        Unk021ccf30_10 *bssDesc = scanResult->mBssDesc[i];
        if (bssDesc->mUnk_0c[0] != 0 && bssDesc->mUnk_3c == 0) {
            ApScanEntry *cursor;
            ApScanEntry *slot;
            j = 0;
            cursor = entries;
            for (; j < 0x14; j++) {
                if (memcmp(bssDesc->mUnk_04, cursor->mBssid, 6) == 0) {
                    break;
                }
                cursor++;
            }
            if (j == 0x14) {
                j = 0;
                cursor = entries;
                for (; j < 0x14; j++) {
                    if (memcmp(cursor->mBssid, gApScanEmptyBssid, 6) == 0) {
                        break;
                    }
                    cursor++;
                }
                if (j == 0x14) {
                    return;
                }
            }
            slot = &entries[j];
            MI_CpuCopy8(bssDesc->mUnk_04, slot->mBssid, 6);
            MI_CpuCopy8(bssDesc->mUnk_0c, slot, 0x20);
            slot->mLinkLevel = scanResult->mLinkLevel[i];
            if ((bssDesc->mUnk_2c & 0x10) == 0) {
                slot->mCapaLevel = 0;
            } else {
                WMOtherElements otherElements;
                s32 elementIndex;
                s32 elementCount;
                slot->mCapaLevel = 1;
                otherElements = WM_GetOtherElements((const u16 *) bssDesc);
                elementIndex = 0;
                elementCount = otherElements.mUnk_00;
                for (; elementIndex < elementCount; elementIndex++) {
                    if (otherElements.mUnk_04[elementIndex].mUnk_00 == 0x30) {
                        slot->mCapaLevel = 2;
                        break;
                    }
                    if (otherElements.mUnk_04[elementIndex].mUnk_00 == 0xdd &&
                        otherElements.mUnk_04[elementIndex].mUnk_01 >= 4 &&
                        memcmp(otherElements.mUnk_04[elementIndex].mUnk_04, gOtherElementPrefix, 4) == 0) {
                        slot->mCapaLevel = 2;
                        break;
                    }
                }
            }
        }
    }
}

void CreateScrollBar(u32 sizeIndex, u32 trackLength, u16 positionX, u16 positionY, u32 offset) {
    (gScrollBar = AllocZeroedExpHeapBlock(0x20, 4))->mSizeIndex = sizeIndex;
    gScrollBar->mTrackLength = trackLength;
    gScrollBar->mOffset = offset;
    SetPosition(positionX, positionY, &gScrollBar->mX);
    gScrollBar->mResource = CreateOamRangeFromNceImage(0, gScrollBarImageIds[sizeIndex], 1);
    SetOamRangePosition(gScrollBar->mResource, -1, positionX, positionY + offset);
    SetOamRangePriority(gScrollBar->mResource, -1, 1);
    gScrollBar->mTask = AddTask(0, AdvanceScrollBar, NULL, 0x80);
}

void ReleaseScrollBar(void) {
    RemoveTaskEntryWrapper(0, gScrollBar->mTask);
    DeleteOamRange(gScrollBar->mResource);
    FreeExpHeapBlockAndClearPointer(&gScrollBar);
}
