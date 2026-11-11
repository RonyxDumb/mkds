#include "03/code_021cef90.h"
#include "03/code_021bf4dc.h"
#include "03/code_021d1790.h"
#include "03/code_021d197c.h"
#include "03/code_021d1fd0.h"
#include "03/unk_021d5000.h"
#include "03/unk_021da000.h"
#include "03/code_021bf410.h"
#include "03/code_021c250c.h"
#include "03/code_021cea3c.h"
#include "03/code_021d1000.h"
#include "03/code_021d27d8.h"
#include "03/code_021d3488.h"
#include "03/unk_021d6000.h"
#include "03/unk_021d7000.h"
#include "code_0214a390.h"
#include "registers.h"
#include "03/code_021b94b8.h"
#include "Main/Unknown/code_02009000.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_0200fc8c.h"
#include "Main/Unknown/unk_0216f000.h"
#include "code_02009928.h"
#include "03/code_021cf260.h"

#pragma opt_dead_assignments off

u16 GetRecordValueByMacAddress(u8 *macAddress) {
    u16 i;
    u16 mask;
    MultiBootParent *records;

    i = 1;
    records = gMultiBootParent;
    mask = records->mMask;
    for (; i < 2; i++) {
        if ((mask & (1 << i)) != 0) {
            u8 *firstRecordMac;
            u8 *recordMac;
            s32 byteOffset;

            byteOffset = (i - 1) * 0x1e;
            firstRecordMac = records->mRecords[0].mMacAddress;
            recordMac = firstRecordMac + byteOffset;
            if (macAddress[0] == firstRecordMac[byteOffset] && macAddress[1] == recordMac[1] &&
                macAddress[2] == recordMac[2] && macAddress[3] == recordMac[3] && macAddress[4] == recordMac[4] &&
                macAddress[5] == recordMac[5]) {
                return records->mRecords[i - 1].mAid;
            }
        }
    }
    return 0;
}

void CreateMessageBox(u32 messageIndex, s32 kind, s32 adjustBrightness, u32 column, u32 value) {
    Bytes6 windowExtraBitFlags;
    void *messageText;
    s32 i;
    u32 entryCount;

    windowExtraBitFlags = gMessageBoxWindowExtraBitFlags;
    messageText = GetMessageEntryAndWriteDigit(gMessages, messageIndex, column, value);
    gMessageBox = AllocZeroedExpHeapBlock(0x20, 4);
    gMessageBox->mKind = kind;
    gMessageBox->mResult = -2;
    gMessageBox->mAdjustBrightness = adjustBrightness;
    G2x_SetBlendBrightness_(&reg_G2_BLDCNT, 0x1f, 0);
    gMessageBox->mBox = CreateOamRangeFromNceImage(0, gMessageBoxImageIds[kind], 0);
    SetOamRangePosition(gMessageBox->mBox, -1, 0x100, 0);
    SetOamRangePriority(gMessageBox->mBox, -1, 0);
    for (i = 0; i < gMessageBoxButtonCounts[kind]; i++) {
        gMessageBox->mButtons[i] = CreateOamRangeFromNceImage(0, gMessageBoxButtonImageIds[kind][i], 0);
        SetOamRangePosition(gMessageBox->mButtons[i], -1, 0x100, 0);
        SetOamRangePriority(gMessageBox->mButtons[i], -1, 0);
    }
    gMessageBox->mTextCanvas = CreateObjTextCanvas(0, 0x20, 0xc, 1, &entryCount, 0);
    gMessageBox->mText = CreateOamRange(0, entryCount, 0);
    DrawCanvasTextRect(gMessageBox->mTextCanvas, 0, 0, gMessageBoxTextSizes[kind][0], gMessageBoxTextSizes[kind][1], 2,
                       GetLanguageTextFlags(), messageText);
    ArrangeObjTextCanvasRange(gMessageBox->mTextCanvas, 0x100, 0, gMessageBox->mText, 0);
    WriteWinInOutBits(0, 0, 0x1f, 0);
    WriteWinInOutBits(0, 1, 0x1f, windowExtraBitFlags.mBytes[gMessageBox->mKind]);
    WriteWinInOutBits(0, 3, 0x1f, 1);
    WriteWinRect(0, 1, gMessageBoxWindowRect);
    PlaceMessageBox(0xc0);
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffff1fff) | 0x6000;
    if (adjustBrightness != 0) {
        gMessageBox->mTask = AddTask(1, AdvanceMessageBoxBrightnessDown, NULL, 0x78);
    } else {
        gMessageBox->mTask = AddTask(1, AdvanceMessageBoxSlideIn, NULL, 0x78);
    }
}

void CloseMessageBox(void) {
    RequestTaskRemoval(0, gMessageBox->mTask);
    gMessageBox->mTask = AddTask(1, AdvanceMessageBoxCloseWait, NULL, 0x78);
}
