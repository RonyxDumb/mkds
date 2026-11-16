#include "03/Menu/exchange_search.h"
#include "registers.h"
#include "03/Menu/exchange_search_fold_detect.h"
#include "03/Menu/exchange_status_record.h"
#include "03/Menu/exchange_entry.h"
#include "03/Menu/way_select.h"
#include "03/Menu/message_box_create.h"
#include "03/Graphics/blend_brightness_fade_start.h"
#include "03/Menu/wifi_menu_shared.h"
#include "03/System/task_input.h"
#include "03/Menu/slide_buttons.h"
#include "03/System/application.h"
#include "03/Menu/wifi_menu_strings.h"
#include "vram_load_2d_graphics.h"
#include "03/Menu/exchange_result.h"
#include "sound_archive_load_result.h"
#include "03/Sound/sound_seq.h"
#include "03/Graphics/text_canvas.h"
#include "03/Graphics/dispcnt_window.h"
#include "thread_scheduler.h"
#include "03/Menu/menu_pair_loading.h"
#include "03/Graphics/blend_brightness_fade_slots.h"
#include "03/Menu/sub_screen_message.h"
#include "03/Net/essid_packet_steps.h"
#include "03/Net/ap_entries.h"
#include "03/Graphics/hl_scr.h"
#include "03/Net/exchange_wcm_state.h"

u8 gExchangeSearchShowNext;

u32 ExchangeSearchPAD_DetectFold(void) {
    if ((*HW_BUTTON_XY_BUF & PAD_DETECT_FOLD_MASK) >> 15) {
        return 1;
    }
    return 0;
}

void SetupExchangeSearch(void) {
    gExchangeSearchShowNext = 0;
    LoadExchangeSearchFilesAndSetBgCnt();
    LoadHlSetScr();
    ShowSubScreenMessage(0x83, -1, 0);
    CreateObjectsForMenuPair(2);
    PrintMessage(0x69);
    CreateAnimatedIcon(0);
    StartSoundSeq(0xb);
    SetUpdateFunction(StartExchangeSearchFadeIn);
}

void LoadExchangeSearchFilesAndSetBgCnt(void) {
    void *jbBgStep3NcgName = &"char/jbBgStep3.ncg.l";
    void *bg2CharLoader = &GX_LoadBG2Char;
    u32 bg2CharLoadResult = LoadFileToVram(jbBgStep3NcgName, bg2CharLoader);
    void *ybBgStep3NclName = &"char/ybBgStep3.ncl.l";
    void *bgPlttLoader = &GX_LoadBGPltt;
    u32 bgPlttLoadResult = LoadFileToVram(ybBgStep3NclName, bgPlttLoader);
    void *xb4MultiNscName = &"char/xb4Multi.nsc.l";
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

void StartExchangeSearchFadeIn(void) {
    StartBlendBrightnessFade(2, 1, 1, 8);
    StartBlendBrightnessFade(2, 0, 0x15, 8);
    CombineDispcntBits(1, 1);
    CombineDispcntBits(0, 0x15);
    SetUpdateFunction(UpdateExchangeSearchFadeIn);
}

void UpdateExchangeSearchFadeIn(void) {
    if (IsBlendBrightnessFadeSlotBusy(1) == 0 && IsBlendBrightnessFadeSlotBusy(0) == 0) {
        StartExchangeWithStatusRecord();
        CreateSlideButtonsForMenuPair(1);
        SetUpdateFunction(UpdateExchangeSearchButtonsIn);
    }
}

void UpdateExchangeSearchButtonsIn(void) {
    int buttonResult;
    buttonResult = GetButtonResult();
    if (buttonResult != -2) {
        EnableButtonTouch();
        SetUpdateFunction(UpdateExchangeSearch);
    }
}

void UpdateExchangeSearch(void) {
    OS_Sleep(0xa);
    UpdateExchangeSearchOutcome();
    UpdateExchangeSearchInput();
    UpdateExchangeSearchNop();
    UpdateExchangeSearchResult();
}

void UpdateExchangeSearchInput(void) {
    int queryResult;
    queryResult = AreKeysPressed(2);
    if (queryResult != 0) {
        SetButtonResultIfNone(0);
        return;
    }
    queryResult = ExchangeSearchPAD_DetectFold();
    if (queryResult != 0) {
        SetButtonResultIfNone(0);
    }
}

void UpdateExchangeSearchNop(void) {}

void UpdateExchangeSearchResult(void) {
    int buttonResult;
    buttonResult = GetButtonResult();
    if (buttonResult == 0) {
        StopSoundSeq();
        StartSoundSeq(7);
        SetUpdateFunction(StartExchangeSearchClose);
    }
}

void StartExchangeSearchClose(void) {
    DisableButtonTouch();
    StartBlendBrightnessFadeWait(8);
    SetUpdateFunction(UpdateExchangeSearchFadeOut);
}

void UpdateExchangeSearchFadeOut(void) {
    int fadeSlotBusy;
    fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(1);
    if (fadeSlotBusy == 0) {
        if (gExchangeSearchShowNext == 0) {
            StartSlideButtonsOut();
        }
        if (gExchangeSearchShowNext == 0) {
            StartBlendBrightnessFade(3, 1, 1, 8);
        }
        StartBlendBrightnessFade(3, 0, 0x14, 8);
        SetUpdateFunction(UpdateExchangeSearchRelease);
    }
}

void UpdateExchangeSearchRelease(void) {
    int queryResult;
    queryResult = IsBlendBrightnessFadeSlotBusy(0);
    if ((queryResult == 0) &&
        (((gExchangeSearchShowNext != 0 || (queryResult = IsBlendBrightnessFadeSlotBusy(1), queryResult == 0)) &&
          (queryResult = IsSlideButtonsNotSlidingOut(), queryResult != 0)))) {
        ReleaseAnimatedIcon();
        ReleaseBgTextCanvasOfScreen(0);
        if (gExchangeSearchShowNext == 0) {
            HideSubScreenMessage();
            ClearDispcntBits(1, 1);
        }
        ClearDispcntBits(0, 0x15);
        if (gExchangeSearchShowNext == 0) {
            StopExchangeWithStatusRecord();
            SetPrimaryMenuPair(2, 1);
            SetUpdateFunction(SetupWay);
            return;
        }
        SetPrimaryMenuPair(0, 0);
        SetUpdateFunction(SetupExchangeEntry);
    }
}

void UpdateExchangeSearchOutcome(void) {
    switch (GetExchangeOutcome()) {
        case EXCHANGE_OUTCOME_SEARCH_ROUND_DONE:
            gExchangeSearchShowNext = 1;
            SetUpdateFunction(StartExchangeSearchClose);
            break;
        case EXCHANGE_OUTCOME_ENDED_WITHOUT_RESULT:
            gExchangeSearchShowNext = 0;
            StopSoundSeq();
            StartSoundSeq(9);
            CreateMessageBox(0x41, 1, 1, -1, 0);
            DisableButtonTouch();
            SetUpdateFunction(UpdateExchangeSearchMessageResult);
            break;
    }
}
