#include "03/Menu/yb5_multi_next_setup.h"
#include "03/Menu/sub_screen_message.h"
#include "03/Menu/menu_pair_loading.h"
#include "03/Menu/yb5_multi_next_buttons_in.h"
#include "03/Menu/opt_menu.h"
#include "03/Net/ap_entries.h"
#include "03/Sound/sound_seq.h"
#include "03/Graphics/blend_brightness_fade_start.h"
#include "03/Graphics/blend_brightness_fade_slots.h"
#include "03/Graphics/text_canvas.h"
#include "03/Graphics/dispcnt_window.h"
#include "03/System/task_input.h"
#include "03/Menu/wifi_menu_strings.h"
#include "vram_load_2d_graphics.h"

u8 gYb5MultiNscName2[19] = {0x63, 0x68, 0x61, 0x72, 0x2f, 0x79, 0x62, 0x35, 0x4d, 0x75,
                            0x6c, 0x74, 0x69, 0x2e, 0x6e, 0x73, 0x63, 0x2e, 0x6c};

void UpdateJb5InfoInput(void) {
    int allKeysPressed;
    allKeysPressed = AreKeysPressed(2);
    if (allKeysPressed != 0) {
        SetButtonResultIfNone(0);
    }
}

void UpdateJb5InfoNop(void) {}

void UpdateJb5InfoResult(void) {
    int buttonResult;
    buttonResult = GetButtonResult();
    if (buttonResult == 0) {
        StartSoundSeq(7);
        SetUpdateFunction(StartJb5InfoClose);
    }
}

void StartJb5InfoClose(void) {
    DisableButtonTouch();
    StartBlendBrightnessFadeWait(8);
    SetUpdateFunction(UpdateJb5InfoFadeOut);
}

void UpdateJb5InfoFadeOut(void) {
    int fadeSlotBusy;
    fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(1);
    if (fadeSlotBusy == 0) {
        StartSlideButtonsOut();
        StartBlendBrightnessFade(3, 1, 1, 8);
        StartBlendBrightnessFade(3, 0, 0x15, 8);
        SetUpdateFunction(UpdateJb5InfoRelease);
    }
}

void UpdateJb5InfoRelease(void) {
    int queryResult;
    queryResult = IsBlendBrightnessFadeSlotBusy(1);
    if (((queryResult == 0) && (queryResult = IsBlendBrightnessFadeSlotBusy(0), queryResult == 0)) &&
        (queryResult = IsSlideButtonsNotSlidingOut(), queryResult != 0)) {
        ReleaseBgTextCanvasOfScreen(0);
        HideSubScreenMessage();
        ClearDispcntBits(1, 1);
        ClearDispcntBits(0, 0x15);
        SetPrimaryMenuPair(0, 1);
        SetUpdateFunction(SetupOptMenu);
    }
}

void SetupYb5MultiNext(void) {
    LoadYb5MultiNextFileAndSetBgCnt();
    PrintMessage(0x57);
    ResetApEntries();
    SetUpdateFunction(StartYb5MultiNextFadeIn);
}

void LoadYb5MultiNextFileAndSetBgCnt(void) {
    void *yb5MultiNscName2 = &gYb5MultiNscName2;
    void *loadBg2ScrFunc = &TEQSub_Fn10Impl_Fn12Impl;
    u32 loadFileResult = LoadFileToVram(yb5MultiNscName2, loadBg2ScrFunc);
    u32 g2sDbBg0CntAddr = 0x4001008u;
    u32 g2sDbBg0CntOld = (*(u16 *) ((g2sDbBg0CntAddr) + (0)));
    u32 g2sDbBg0CntCleared = ((g2sDbBg0CntOld) & ~(0x3u));
    u32 g2sDbBg0CntNew = ((g2sDbBg0CntCleared) | (0x3u));
    u32 g2sDbBg1CntAddr;
    u32 g2sDbBg1CntOld;
    u32 g2sDbBg1CntCleared;
    u32 g2sDbBg1CntNew;
    u32 g2Bg0CntAddr;
    u32 g2Bg0CntOld;
    u32 g2Bg0CntCleared;
    u32 g2Bg0CntNew;
    u32 g2Bg1CntAddr;
    u32 g2Bg1CntOld;
    u32 g2Bg1CntCleared;
    u32 g2Bg1CntNew;
    u32 g2Bg2CntAddr;
    u32 g2Bg2CntOld;
    u32 g2Bg2CntCleared;
    u32 g2Bg2CntNew;
    *(u16 *) ((g2sDbBg0CntAddr) + (0)) = g2sDbBg0CntNew;
    g2sDbBg1CntAddr = 0x400100au;
    g2sDbBg1CntOld = (*(u16 *) ((g2sDbBg1CntAddr) + (0)));
    g2sDbBg1CntCleared = ((g2sDbBg1CntOld) & ~(0x3u));
    g2sDbBg1CntNew = ((g2sDbBg1CntCleared) | (0x3u));
    *(u16 *) ((g2sDbBg1CntAddr) + (0)) = g2sDbBg1CntNew;
    g2Bg0CntAddr = 0x4000008u;
    g2Bg0CntOld = (*(u16 *) ((g2Bg0CntAddr) + (0)));
    g2Bg0CntCleared = ((g2Bg0CntOld) & ~(0x3u));
    g2Bg0CntNew = ((g2Bg0CntCleared) | (0x3u));
    *(u16 *) ((g2Bg0CntAddr) + (0)) = g2Bg0CntNew;
    g2Bg1CntAddr = 0x400000au;
    g2Bg1CntOld = (*(u16 *) ((g2Bg1CntAddr) + (0)));
    g2Bg1CntCleared = ((g2Bg1CntOld) & ~(0x3u));
    g2Bg1CntNew = ((g2Bg1CntCleared) | (0x3u));
    *(u16 *) ((g2Bg1CntAddr) + (0)) = g2Bg1CntNew;
    g2Bg2CntAddr = 0x400000cu;
    g2Bg2CntOld = (*(u16 *) ((g2Bg2CntAddr) + (0)));
    g2Bg2CntCleared = ((g2Bg2CntOld) & ~(0x3u));
    g2Bg2CntNew = ((g2Bg2CntCleared) | (0x3u));
    *(u16 *) ((g2Bg2CntAddr) + (0)) = g2Bg2CntNew;
}

void StartYb5MultiNextFadeIn(void) {
    StartBlendBrightnessFade(2, 0, 0x15, 8);
    CombineDispcntBits(0, 0x15);
    SetUpdateFunction(UpdateYb5MultiNextFadeIn);
}

void UpdateYb5MultiNextFadeIn(void) {
    int fadeSlotBusy;
    fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(0);
    if (fadeSlotBusy == 0) {
        CreateSlideButtonsForMenuPair(5);
        SetUpdateFunction(UpdateYb5MultiNextButtonsIn);
    }
}
