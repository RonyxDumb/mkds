#include "03/Menu/value_records.h"
#include "03/Menu/value_records_fold_detect.h"
#include "03/Menu/ap_screen.h"
#include "03/Menu/way_select.h"
#include "03/Menu/sub_screen_message.h"
#include "03/Net/essid_packet_steps.h"
#include "03/Net/value_records_request_status.h"
#include "03/Menu/message_box_create.h"
#include "03/Graphics/blend_brightness_fade_start.h"
#include "03/Menu/wifi_menu_shared.h"
#include "03/Menu/slide_buttons.h"
#include "03/System/application.h"
#include "03/Menu/ap_list.h"
#include "03/Menu/scroll_bar.h"
#include "03/Menu/wifi_menu_strings.h"
#include "vram_load_2d_graphics.h"
#include "03/Menu/value_records_next.h"
#include "03/Graphics/blend_brightness_fade_slots.h"
#include "03/System/task_input.h"
#include "03/Menu/value_records_buttons_in.h"
#include "03/Sound/sound_seq.h"
#include "03/Menu/message_box.h"
#include "03/Graphics/text_canvas.h"
#include "03/Graphics/dispcnt_window.h"
#include "03/System/tasks.h"
#include "03/Menu/menu_pair_loading.h"
#include "03/System/wifi_utility_archive.h"
#include "03/Net/ap_entries.h"
#include "03/Graphics/hl_scr.h"
#include "03/Net/exchange_wcm_state.h"
#include "sound_archive_load_result.h"
#include "registers.h"

u8 gValueRecordsShowNext;
u16 gValueRecordsFrames;
TaskEntry *gValueRecordsRequestTask;

BOOL ValueRecordsPAD_DetectFold(void) {
    if ((*HW_BUTTON_XY_BUF & PAD_DETECT_FOLD_MASK) >> 15) {
        return 1;
    }
    return 0;
}

void SetupValueRecords(void) {
    gValueRecordsFrames = 0;
    LoadValueRecordsFilesAndSetBgCnt();
    LoadHlSetScr();
    ShowSubScreenMessage(0x82, -1, 0);
    CreateObjectsForMenuPair(2);
    PrintMessage(0x67);
    CreateAnimatedIcon(0);
    InitValueRecordsRequest();
    StartSoundSeq(0xb);
    SetUpdateFunction(StartValueRecordsFadeIn);
}

void LoadValueRecordsFilesAndSetBgCnt(void) {
    LoadFileToVram("char/jbBgStep3.ncg.l", GX_LoadBG2Char);
    LoadFileToVram("char/ybBgStep3.ncl.l", GX_LoadBGPltt);
    LoadFileToVram("char/xb4Multi.nsc.l", GX_LoadBG2Scr);
    reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & ~REG_G2S_DB_BG0CNT_PRIORITY_MASK) | 3;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & ~REG_G2S_DB_BG1CNT_PRIORITY_MASK) | 3;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~REG_G2_BG0CNT_PRIORITY_MASK) | 3;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & ~REG_G2_BG1CNT_PRIORITY_MASK) | 3;
    reg_G2_BG2CNT = (reg_G2_BG2CNT & ~REG_G2_BG2CNT_PRIORITY_MASK) | 3;
}

void StartValueRecordsFadeIn(void) {
    StartBlendBrightnessFade(2, 1, 1, 8);
    StartBlendBrightnessFade(2, 0, 0x15, 8);
    CombineDispcntBits(1, 1);
    CombineDispcntBits(0, 0x15);
    SetUpdateFunction(UpdateValueRecordsFadeIn);
}

void UpdateValueRecordsFadeIn(void) {
    if (IsBlendBrightnessFadeSlotBusy(1) == 0 && IsBlendBrightnessFadeSlotBusy(0) == 0) {
        CreateSlideButtonsForMenuPair(1);
        SetUpdateFunction(UpdateValueRecordsButtonsIn);
    }
}

void UpdateValueRecordsButtonsIn(void) {
    if (GetButtonResult() != -2) {
        gValueRecordsRequestTask = AddTask(1, UpdateValueRecordsDuringRequest, NULL, 0x78);
        SetUpdateFunction(UpdateValueRecords);
    }
}

void UpdateValueRecords(void) {
    int requestStatus;
    UpdateValueRecordsInput();
    UpdateValueRecordsNop();
    UpdateValueRecordsResult();
    requestStatus = RunValueRecordsRequestForStatus();
    switch (requestStatus) {
        case VALUE_RECORDS_STATUS_RETRY:
            break;
        case VALUE_RECORDS_STATUS_SUCCEEDED:
            gValueRecordsShowNext = 1;
            RemoveTaskEntryWrapper(1, gValueRecordsRequestTask);
            gValueRecordsRequestTask = 0;
            SetUpdateFunction(UpdateValueRecordsFrames);
            break;
        case VALUE_RECORDS_STATUS_FAILED:
            StopSoundSeq();
            CreateMessageBox(0x40, 1, 1, -1, 0);
            StartSoundSeq(9);
            DisableButtonTouch();
            RemoveTaskEntryWrapper(1, gValueRecordsRequestTask);
            gValueRecordsRequestTask = 0;
            SetUpdateFunction(UpdateValueRecordsMessageResult);
            break;
    }
}

void UpdateValueRecordsInput(void) {
    int checkResult;
    checkResult = AreKeysDown(2);
    if (checkResult != 0) {
        SetButtonResultIfNone(0);
        return;
    }
    checkResult = ValueRecordsPAD_DetectFold();
    if (checkResult != 0) {
        SetButtonResultIfNone(0);
    }
}

void UpdateValueRecordsNop(void) {}

void UpdateValueRecordsResult(void) {
    int buttonResult;
    buttonResult = GetButtonResult();
    if (buttonResult == 0) {
        DisableButtonTouch();
        SetUpdateFunction(StartValueRecordsCloseWithoutNext);
    }
}

void StartValueRecordsClose(void) {
    DisableButtonTouch();
    if (gValueRecordsRequestTask != 0) {
        RemoveTaskEntryWrapper(1, gValueRecordsRequestTask);
    }
    StartBlendBrightnessFadeWait(8);
    SetUpdateFunction(UpdateValueRecordsFadeOut);
}

void UpdateValueRecordsFadeOut(void) {
    int fadeSlotBusy;
    fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(1);
    if (fadeSlotBusy == 0) {
        StartSlideButtonsOut();
        if (gValueRecordsShowNext == 0) {
            StartBlendBrightnessFade(3, 1, 1, 8);
        }
        StartBlendBrightnessFade(3, 0, 0x15, 8);
        SetUpdateFunction(UpdateValueRecordsRelease);
    }
}

void UpdateValueRecordsRelease(void) {
    int checkResult;
    checkResult = IsBlendBrightnessFadeSlotBusy(0);
    if ((checkResult == 0) &&
        (((gValueRecordsShowNext != 0 || (checkResult = IsBlendBrightnessFadeSlotBusy(1), checkResult == 0)) &&
          (checkResult = IsSlideButtonsNotSlidingOut(), checkResult != 0)))) {
        ReleaseValueRecordsRequest((gValueRecordsShowNext != 0));
        ReleaseAnimatedIcon();
        ReleaseBgTextCanvasOfScreen(0);
        if (gValueRecordsShowNext == 0) {
            HideSubScreenMessage();
            ClearDispcntBits(1, 1);
        }
        ClearDispcntBits(0, 0x15);
        if (gValueRecordsShowNext == 0) {
            SetPrimaryMenuPair(2, 1);
            SetUpdateFunction(SetupWay);
            return;
        }
        SetPrimaryMenuPair(0, 0);
        SetUpdateFunction(SetupValueRecordsNext);
    }
}

void UpdateValueRecordsDuringRequest(TaskEntry *task, void *arg) {
    UpdateKeyTouchInput();
    RunTasksAndRemoveRequested(0);
    UpdateValueRecordsInput();
    UpdateValueRecordsResult();
}

void UpdateValueRecordsMessageResult(void) {
    int messageAnswer;
    messageAnswer = GetMessageBoxResult();
    if (messageAnswer == 0) {
        StartSoundSeq(6);
        CloseMessageBox();
        SetUpdateFunction(UpdateValueRecordsMessageClose);
    }
}

void UpdateValueRecordsMessageClose(void) {
    int messageOpen;
    messageOpen = IsMessageBoxOpen();
    if (messageOpen == 0) {
        SetUpdateFunction(StartValueRecordsClose);
    }
}

void UpdateValueRecordsFrames(void) {
    UpdateValueRecordsInput();
    UpdateValueRecordsNop();
    UpdateValueRecordsResult();
    gValueRecordsFrames = gValueRecordsFrames + 1;
    if (gValueRecordsFrames >= 0x438) {
        StopSoundSeq();
        SetUpdateFunction(StartValueRecordsClose);
    }
}

void StartValueRecordsCloseWithoutNext(void) {
    StopSoundSeq();
    StartSoundSeq(7);
    gValueRecordsShowNext = 0;
    SetUpdateFunction(StartValueRecordsClose);
}
