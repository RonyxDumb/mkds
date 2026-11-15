#include "03/Menu/jb5_info.h"
#include "03/Menu/jb5_info_setup.h"
#include "03/Graphics/hl_scr.h"
#include "03/Menu/menu_pair_loading.h"
#include "03/Graphics/text_canvas.h"
#include "03/Menu/wifi_menu_shared.h"
#include "03/Menu/sub_screen_message.h"
#include "03/System/application.h"
#include "03/Menu/jb5_info_fade_in.h"
#include "03/Menu/jb5_info_print.h"
#include "03/Menu/jb5_info_load_files.h"
#include "03/Menu/wifi_menu_strings.h"
#include "gx_load2d.h"
#include "reset_interrupt_enable.h"
#include "wide_print.h"
#include "dwc_backup.h"
#include "03/Menu/jb5_info_buttons_in.h"
#include "03/Graphics/blend_brightness_fade_start.h"
#include "03/Graphics/blend_brightness_fade_slots.h"
#include "03/Graphics/dispcnt_window.h"
#include "03/Menu/slide_buttons.h"
#include "03/Menu/yb5_multi_next_setup.h"

const OriginSizeRect gJb5InfoMacAddressRect = {8, 0x40, 0xf0, 0x1c};
const OriginSizeRect gJb5InfoUserIdRect = {8, 0x78, 0xf0, 0x1c};

void SetupJb5Info(void) {
    LoadJb5InfoFileAndSetBgCnt();
    LoadHlScr(0x11);
    ShowSubScreenMessage(0x89, -1, 0);
    PrintJb5Info();
    SetUpdateFunction(StartJb5InfoFadeIn);
}

void LoadJb5InfoFileAndSetBgCnt(void) {
    void *filePath = &"char/jb5Info.nsc.l";
    void *loadFunction = &GX_LoadBG2Scr;
    u32 fileToVram = LoadFileToVram(filePath, loadFunction);
    u32 subBg0CntAddress = 0x4001008u;
    u32 subBg0Cnt = (*(u16 *) ((subBg0CntAddress) + (0)));
    u32 subBg0CntCleared = ((subBg0Cnt) & ~(0x3u));
    u32 subBg0CntSet = ((subBg0CntCleared) | (0x3u));
    u32 subBg1CntAddress;
    u32 subBg1Cnt;
    u32 subBg1CntCleared;
    u32 subBg1CntSet;
    u32 mainBg0CntAddress;
    u32 mainBg0Cnt;
    u32 mainBg0CntCleared;
    u32 mainBg0CntSet;
    u32 mainBg1CntAddress;
    u32 mainBg1Cnt;
    u32 mainBg1CntCleared;
    u32 mainBg1CntSet;
    u32 mainBg2CntAddress;
    u32 mainBg2Cnt;
    u32 mainBg2CntCleared;
    u32 mainBg2CntSet;
    *(u16 *) ((subBg0CntAddress) + (0)) = subBg0CntSet;
    subBg1CntAddress = 0x400100au;
    subBg1Cnt = (*(u16 *) ((subBg1CntAddress) + (0)));
    subBg1CntCleared = ((subBg1Cnt) & ~(0x3u));
    subBg1CntSet = ((subBg1CntCleared) | (0x3u));
    *(u16 *) ((subBg1CntAddress) + (0)) = subBg1CntSet;
    mainBg0CntAddress = 0x4000008u;
    mainBg0Cnt = (*(u16 *) ((mainBg0CntAddress) + (0)));
    mainBg0CntCleared = ((mainBg0Cnt) & ~(0x3u));
    mainBg0CntSet = ((mainBg0CntCleared) | (0x3u));
    *(u16 *) ((mainBg0CntAddress) + (0)) = mainBg0CntSet;
    mainBg1CntAddress = 0x400000au;
    mainBg1Cnt = (*(u16 *) ((mainBg1CntAddress) + (0)));
    mainBg1CntCleared = ((mainBg1Cnt) & ~(0x3u));
    mainBg1CntSet = ((mainBg1CntCleared) | (0x3u));
    *(u16 *) ((mainBg1CntAddress) + (0)) = mainBg1CntSet;
    mainBg2CntAddress = 0x400000cu;
    mainBg2Cnt = (*(u16 *) ((mainBg2CntAddress) + (0)));
    mainBg2CntCleared = ((mainBg2Cnt) & ~(0x3u));
    mainBg2CntSet = ((mainBg2CntCleared) | (0x3u));
    *(u16 *) ((mainBg2CntAddress) + (0)) = mainBg2CntSet;
}

void PrintJb5Info(void) {
    void *canvas;
    u8 macAddress[8];
    DWCWiFiInfo wifiInfo;
    u32 idGroups[4];
    u16 text[20];
    u64 userId;
    s32 groupIndex;
    canvas = InitBgTextCanvas(0, 0);
    OS_GetMacAddress(macAddress);
    swprintf(text, 0x14, L"%02X-%02X-%02X-%02X-%02X-%02X", macAddress[0], macAddress[1], macAddress[2], macAddress[3],
             macAddress[4], macAddress[5]);
    DrawCanvasTextRect(canvas, gJb5InfoMacAddressRect.mX, gJb5InfoMacAddressRect.mY, gJb5InfoMacAddressRect.mWidth,
                       gJb5InfoMacAddressRect.mHeight, 2, 0x480, text);
    DWCi_BM_GetWiFiInfo(&wifiInfo);
    userId = wifiInfo.mAttestedUserId;
    if (userId != 0) {
        idGroups[3] = (userId % 10) * 1000;
        userId = userId / 10;
        for (groupIndex = 0; groupIndex < 3; groupIndex++) {
            idGroups[2 - groupIndex] = userId % 10000;
            userId = userId / 10000;
        }
        swprintf(text, 0x14, L"%04d-%04d-%04d-%04d", idGroups[0], idGroups[1], idGroups[2], idGroups[3]);
    } else {
        swprintf(text, 0x14, L"-------------------");
    }
    DrawCanvasTextRect(canvas, gJb5InfoUserIdRect.mX, gJb5InfoUserIdRect.mY, gJb5InfoUserIdRect.mWidth,
                       gJb5InfoUserIdRect.mHeight, 2, 0x480, text);
    RequestBgTextCanvasUpload(canvas);
}

void StartJb5InfoFadeIn(void) {
    StartBlendBrightnessFade(2, 1, 1, 8);
    StartBlendBrightnessFade(2, 0, 0x15, 8);
    CombineDispcntBits(1, 1);
    CombineDispcntBits(0, 0x15);
    SetUpdateFunction(UpdateJb5InfoFadeIn);
}

void UpdateJb5InfoFadeIn(void) {
    int fadeSlotBusy;
    fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(1);
    if ((fadeSlotBusy == 0) && (fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(0), fadeSlotBusy == 0)) {
        CreateSlideButtonsForMenuPair(2);
        SetUpdateFunction(UpdateJb5InfoButtonsIn);
    }
}

void UpdateJb5InfoButtonsIn(void) {
    if (GetButtonResult() != -2) {
        EnableButtonTouch();
        SetUpdateFunction(UpdateJb5Info);
    }
}

void UpdateJb5Info(void) {
    UpdateJb5InfoInput();
    UpdateJb5InfoNop();
    UpdateJb5InfoResult();
}
