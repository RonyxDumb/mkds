#include "03/Menu/exchange_entry.h"
#include "registers.h"
#include "03/Menu/exchange_entry_fold_detect.h"
#include "03/Graphics/hl_scr.h"
#include "03/Menu/exchange_status_record.h"
#include "03/Menu/sub_screen_message.h"
#include "03/Menu/way_select.h"
#include "03/Menu/message_box_create.h"
#include "03/Graphics/blend_brightness_fade_start.h"
#include "03/Menu/wifi_menu_shared.h"
#include "03/Menu/slide_buttons.h"
#include "03/Menu/menu_pair_loading.h"
#include "03/System/application.h"
#include "03/Graphics/blend_brightness_fade_slots.h"
#include "03/Menu/wifi_menu_strings.h"
#include "gx_load2d.h"
#include "03/Menu/exchange_key_update.h"
#include "03/System/task_input.h"
#include "03/Menu/record_saved.h"
#include "code_0212df7c.h"
#include "03/Sound/sound_seq.h"
#include "03/Graphics/text_canvas.h"
#include "03/Graphics/dispcnt_window.h"
#include "os_thread.h"

u8 gXb4MultiNscName3[19] = {0x63, 0x68, 0x61, 0x72, 0x2f, 0x78, 0x62, 0x34, 0x4d, 0x75,
                            0x6c, 0x74, 0x69, 0x2e, 0x6e, 0x73, 0x63, 0x2e, 0x6c};
u8 gExchangeEntryShowNext;

u32 ExchangeEntryPAD_DetectFold(void) {
    if ((*HW_BUTTON_XY_BUF & PAD_DETECT_FOLD_MASK) >> 15) {
        return 1;
    }
    return 0;
}

void SetupExchangeEntry(void) {
    gExchangeEntryShowNext = 0;
    LoadExchangeEntryFileAndSetBgCnt();
    LoadHlSetScr();
    PrintMessage(0x6a);
    CreateAnimatedIcon(1);
    SetUpdateFunction(StartExchangeEntryFadeIn);
}

void LoadExchangeEntryFileAndSetBgCnt(void) {
    void *xb4MultiNscName = &gXb4MultiNscName3;
    void *bg2ScrLoader = &GX_LoadBG2Scr;
    u32 bg2ScrLoadResult = LoadFileToVram(xb4MultiNscName, bg2ScrLoader);
    u32 subBg0CntAddress = 0x4001008u;
    u32 subBg0CntValue = (*(u16 *) ((subBg0CntAddress) + (0)));
    u32 subBg0CntCleared = ((subBg0CntValue) & ~(0x3u));
    u32 subBg0CntNew = ((subBg0CntCleared) | (0x3u));
    u32 subBg1CntAddress;
    u32 subBg1CntValue;
    u32 subBg1CntCleared;
    u32 subBg1CntNew;
    u32 mainBg0CntAddress;
    u32 mainBg0CntValue;
    u32 mainBg0CntCleared;
    u32 mainBg0CntNew;
    u32 mainBg1CntAddress;
    u32 mainBg1CntValue;
    u32 mainBg1CntCleared;
    u32 mainBg1CntNew;
    u32 mainBg2CntAddress;
    u32 mainBg2CntValue;
    u32 mainBg2CntCleared;
    u32 mainBg2CntNew;
    *(u16 *) ((subBg0CntAddress) + (0)) = subBg0CntNew;
    subBg1CntAddress = 0x400100au;
    subBg1CntValue = (*(u16 *) ((subBg1CntAddress) + (0)));
    subBg1CntCleared = ((subBg1CntValue) & ~(0x3u));
    subBg1CntNew = ((subBg1CntCleared) | (0x3u));
    *(u16 *) ((subBg1CntAddress) + (0)) = subBg1CntNew;
    mainBg0CntAddress = 0x4000008u;
    mainBg0CntValue = (*(u16 *) ((mainBg0CntAddress) + (0)));
    mainBg0CntCleared = ((mainBg0CntValue) & ~(0x3u));
    mainBg0CntNew = ((mainBg0CntCleared) | (0x3u));
    *(u16 *) ((mainBg0CntAddress) + (0)) = mainBg0CntNew;
    mainBg1CntAddress = 0x400000au;
    mainBg1CntValue = (*(u16 *) ((mainBg1CntAddress) + (0)));
    mainBg1CntCleared = ((mainBg1CntValue) & ~(0x3u));
    mainBg1CntNew = ((mainBg1CntCleared) | (0x3u));
    *(u16 *) ((mainBg1CntAddress) + (0)) = mainBg1CntNew;
    mainBg2CntAddress = 0x400000cu;
    mainBg2CntValue = (*(u16 *) ((mainBg2CntAddress) + (0)));
    mainBg2CntCleared = ((mainBg2CntValue) & ~(0x3u));
    mainBg2CntNew = ((mainBg2CntCleared) | (0x3u));
    *(u16 *) ((mainBg2CntAddress) + (0)) = mainBg2CntNew;
}

void StartExchangeEntryFadeIn(void) {
    StartBlendBrightnessFade(2, 0, 0x15, 8);
    CombineDispcntBits(0, 0x15);
    SetUpdateFunction(UpdateExchangeEntryFadeIn);
}

void UpdateExchangeEntryFadeIn(void) {
    int fadeSlotBusy;
    fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(0);
    if (fadeSlotBusy == 0) {
        CreateSlideButtonsForMenuPair(1);
        SetUpdateFunction(UpdateExchangeEntryButtonsIn);
    }
}

void UpdateExchangeEntryButtonsIn(void) {
    int buttonResult;
    buttonResult = GetButtonResult();
    if (buttonResult != -2) {
        EnableButtonTouch();
        SetUpdateFunction(UpdateExchangeEntry);
    }
}

void UpdateExchangeEntry(void) {
    OS_Sleep(0xa);
    UpdateExchangeEntryOutcome();
    UpdateExchangeEntryInput();
    UpdateExchangeEntryNop();
    UpdateExchangeEntryResult();
}

void UpdateExchangeEntryInput(void) {
    int queryResult;
    queryResult = AreKeysPressed(2);
    if (queryResult != 0) {
        SetButtonResultIfNone(0);
        return;
    }
    queryResult = ExchangeEntryPAD_DetectFold();
    if (queryResult != 0) {
        SetButtonResultIfNone(0);
    }
}

void UpdateExchangeEntryNop(void) {}

void UpdateExchangeEntryResult(void) {
    int buttonResult;
    buttonResult = GetButtonResult();
    if (buttonResult == 0) {
        StopSoundSeq();
        StartSoundSeq(7);
        SetUpdateFunction(StartExchangeEntryClose);
    }
}

void StartExchangeEntryClose(void) {
    DisableButtonTouch();
    StartBlendBrightnessFadeWait(8);
    SetUpdateFunction(UpdateExchangeEntryFadeOut);
}

void UpdateExchangeEntryFadeOut(void) {
    int fadeSlotBusy;
    fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(1);
    if (fadeSlotBusy == 0) {
        if (gExchangeEntryShowNext == 0) {
            StartSlideButtonsOut();
        }
        if (gExchangeEntryShowNext == 0) {
            StartBlendBrightnessFade(3, 1, 1, 8);
        }
        StartBlendBrightnessFade(3, 0, 0x15, 8);
        SetUpdateFunction(UpdateExchangeEntryRelease);
    }
}

void UpdateExchangeEntryRelease(void) {
    int queryResult;
    queryResult = IsBlendBrightnessFadeSlotBusy(0);
    if ((queryResult == 0) &&
        (((gExchangeEntryShowNext != 0 || (queryResult = IsBlendBrightnessFadeSlotBusy(1), queryResult == 0)) &&
          (queryResult = IsSlideButtonsNotSlidingOut(), queryResult != 0)))) {
        ReleaseAnimatedIcon();
        ReleaseBgTextCanvasOfScreen(0);
        if (gExchangeEntryShowNext == 0) {
            HideSubScreenMessage();
            ClearDispcntBits(1, 1);
        }
        ClearDispcntBits(0, 0x15);
        if (gExchangeEntryShowNext == 0) {
            StopExchangeWithStatusRecord();
            SetPrimaryMenuPair(2, 1);
            SetUpdateFunction(SetupWay);
            return;
        }
        SetPrimaryMenuPair(0, 0);
        SetUpdateFunction(SetupExchangeKey);
    }
}

void UpdateExchangeEntryOutcome(void) {
    switch (GetExchangeOutcome()) {
        case EXCHANGE_OUTCOME_FIRST_PACKET_ACCEPTED:
            gExchangeEntryShowNext = 1;
            SetUpdateFunction(StartExchangeEntryClose);
            break;
        case EXCHANGE_OUTCOME_ENDED_WITHOUT_RESULT:
            gExchangeEntryShowNext = 0;
            StopSoundSeq();
            StartSoundSeq(9);
            CreateMessageBox(0x41, 1, 1, -1, 0);
            DisableButtonTouch();
            SetUpdateFunction(UpdateExchangeEntryMessageResult);
            break;
    }
}
