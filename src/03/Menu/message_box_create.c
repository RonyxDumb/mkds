#include "03/Menu/message_box_create.h"
#include "03/Menu/menu_pair_loading.h"
#include "03/Graphics/oam_range_set.h"
#include "03/Graphics/oam_range.h"
#include "03/Graphics/text_canvas.h"
#include "03/Menu/wifi_menu_shared.h"
#include "03/Menu/sub_screen_message.h"
#include "03/Graphics/messages.h"
#include "03/Menu/message_box.h"
#include "03/System/exp_heap.h"
#include "03/System/tasks.h"
#include "03/Menu/wifi_menu_tables.h"
#include "03/Menu/wifi_menu_strings.h"
#include "g2.h"
#include "registers.h"
#include "03/Net/essid_packet_steps.h"
#include "reset_interrupt_enable.h"
#include "os_thread.h"
#include "mb_data.h"
#include "multiboot_comm_start.h"
#include "03/Net/multiboot_parent_download.h"
#include "03/Menu/main_menu.h"

#pragma opt_dead_assignments off

u16 GetRecordValueByMacAddress(u8 *macAddress) {
    u16 aid;
    u16 mask;
    MultiBootParent *records;

    aid = 1;
    records = gMultiBootParent;
    mask = records->mHeader.mMask;
    for (; aid < 2; aid++) {
        if (BIT_IS_SET(mask, aid)) {
            u8 *firstRecordMac;
            u8 *recordMac;
            s32 byteOffset;

            byteOffset = (aid - 1) * 0x1e;
            firstRecordMac = records->mRecords[0].mMacAddress;
            recordMac = firstRecordMac + byteOffset;
            if (macAddress[0] == firstRecordMac[byteOffset] && macAddress[1] == recordMac[1] &&
                macAddress[2] == recordMac[2] && macAddress[3] == recordMac[3] && macAddress[4] == recordMac[4] &&
                macAddress[5] == recordMac[5]) {
                return records->mRecords[aid - 1].mAid;
            }
        }
    }
    return 0;
}

void CreateMessageBox(u32 messageIndex, s32 kind, s32 adjustBrightness, u32 column, u32 value) {
    MessageBoxWindowFlags windowExtraBitFlags;
    void *messageText;
    s32 buttonIndex;
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
    for (buttonIndex = 0; buttonIndex < gMessageBoxButtonCounts[kind]; buttonIndex++) {
        gMessageBox->mButtons[buttonIndex] =
            CreateOamRangeFromNceImage(0, gMessageBoxButtonImageIds[kind][buttonIndex], 0);
        SetOamRangePosition(gMessageBox->mButtons[buttonIndex], -1, 0x100, 0);
        SetOamRangePriority(gMessageBox->mButtons[buttonIndex], -1, 0);
    }
    gMessageBox->mTextCanvas = CreateObjTextCanvas(0, 0x20, 0xc, 1, &entryCount, 0);
    gMessageBox->mText = CreateOamRange(0, entryCount, 0);
    DrawCanvasTextRect(gMessageBox->mTextCanvas, 0, 0, gMessageBoxTextSizes[kind][0], gMessageBoxTextSizes[kind][1], 2,
                       GetLanguageTextFlags(), messageText);
    ArrangeObjTextCanvasRange(gMessageBox->mTextCanvas, 0x100, 0, gMessageBox->mText, 0);
    WriteWinInOutBits(0, 0, 0x1f, 0);
    WriteWinInOutBits(0, 1, 0x1f, windowExtraBitFlags.mFlagsByKind[gMessageBox->mKind]);
    WriteWinInOutBits(0, 3, 0x1f, 1);
    WriteWinRect(0, 1, gMessageBoxWindowRect);
    PlaceMessageBox(0xc0);
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~(REG_GX_DISPCNT_OW_MASK | REG_GX_DISPCNT_W1_MASK | REG_GX_DISPCNT_W0_MASK)) |
                     (REG_GX_DISPCNT_W1_MASK | REG_GX_DISPCNT_W0_MASK);
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
