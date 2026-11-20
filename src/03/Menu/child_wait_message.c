#include "03/Menu/child_wait_message.h"
#include "03/Menu/opt_menu.h"
#include "03/Menu/menu_pair_loading.h"
#include "03/System/application.h"
#include "03/Graphics/blend_brightness_fade_start.h"
#include "03/Graphics/blend_brightness_fade_slots.h"
#include "03/Menu/wifi_menu_strings.h"
#include "03/Menu/wifi_menu_shared.h"
#include "vram_load_2d_graphics.h"
#include "03/Menu/child_wait.h"
#include "03/System/task_input.h"

#include "03/Graphics/text_canvas.h"
#include "03/Graphics/dispcnt_window.h"
#include "03/Menu/slide_buttons.h"
#include "sound_archive_load_result.h"
#include "03/Sound/sound_seq.h"
#include "03/System/tasks.h"
#include "03/Net/child_wait_session_object.h"
#include "03/Menu/sub_screen_message.h"

u8 gChildWaitMessageYb5MultiNscName[19] = {0x63, 0x68, 0x61, 0x72, 0x2f, 0x79, 0x62, 0x35, 0x4d, 0x75,
                            0x6c, 0x74, 0x69, 0x2e, 0x6e, 0x73, 0x63, 0x2e, 0x6c};
u8 gChildWaitMessageShowNext;
u8 gChildWaitMessageSubScreenShown;

void SetupChildWaitMessage(void) {
    LoadChildWaitMessageFileAndSetBgCnt();
    PrintMessage(0x62);
    gChildWaitMessageSubScreenShown = ShowSubScreenMessage(0x8d, -1, 0);
    SetUpdateFunction(StartChildWaitMessageFadeIn);
}

void LoadChildWaitMessageFileAndSetBgCnt(void) {
    void *nscName = &gChildWaitMessageYb5MultiNscName;
    void *loadBg2ScrFunc = &GX_LoadBG2Scr;
    u32 loadFileResult = LoadFileToVram(nscName, loadBg2ScrFunc);
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

void StartChildWaitMessageFadeIn(void) {
    StartBlendBrightnessFade(2, 0, 0x15, 8);
    CombineDispcntBits(0, 0x15);
    if (gChildWaitMessageSubScreenShown != 0) {
        StartBlendBrightnessFade(2, 1, 1, 8);
        CombineDispcntBits(1, 1);
    }
    SetUpdateFunction(UpdateChildWaitMessageFadeIn);
}

void UpdateChildWaitMessageFadeIn(void) {
    int fadeSlotBusy;
    fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(1);
    if ((fadeSlotBusy == 0) && (fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(0), fadeSlotBusy == 0)) {
        CreateSlideButtonsForMenuPair(3);
        SetUpdateFunction(UpdateChildWaitMessageButtonsIn);
    }
}

void UpdateChildWaitMessageButtonsIn(void) {
    if (GetButtonResult() != -2 && IsChildWaitSessionReleased() != 0) {
        EnableButtonTouch();
        SetUpdateFunction(UpdateChildWaitMessage);
    }
}

void UpdateChildWaitMessage(void) {
    UpdateChildWaitMessageInput();
    UpdateChildWaitMessageNop();
    UpdateChildWaitMessageResult();
}

void UpdateChildWaitMessageInput(void) {
    int allKeysPressed;
    allKeysPressed = AreKeysPressed(1);
    if (allKeysPressed != 0) {
        SetButtonResultIfNone(1);
    }
    allKeysPressed = AreKeysPressed(2);
    if (allKeysPressed != 0) {
        SetButtonResultIfNone(0);
    }
}

void UpdateChildWaitMessageNop(void) {}

void UpdateChildWaitMessageResult(void) {
    switch (GetButtonResult()) {
        case 1:
            gChildWaitMessageShowNext = 1;
            StartSoundSeq(6);
            break;
        case 0:
            gChildWaitMessageShowNext = 0;
            StartSoundSeq(7);
            break;
        default:
            return;
    }
    SetUpdateFunction(StartChildWaitMessageClose);
}

void StartChildWaitMessageClose(void) {
    DisableButtonTouch();
    StartBlendBrightnessFadeWait(8);
    SetUpdateFunction(UpdateChildWaitMessageFadeOut);
}

void UpdateChildWaitMessageFadeOut(void) {
    int fadeSlotBusy;
    fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(1);
    if (fadeSlotBusy == 0) {
        StartSlideButtonsOut();
        if (gChildWaitMessageShowNext == 0) {
            StartBlendBrightnessFade(3, 1, 1, 8);
        }
        StartBlendBrightnessFade(3, 0, 0x15, 8);
        SetUpdateFunction(UpdateChildWaitMessageRelease);
    }
}

void UpdateChildWaitMessageRelease(void) {
    int checkResult;
    checkResult = IsBlendBrightnessFadeSlotBusy(1);
    if (((checkResult == 0) && (checkResult = IsBlendBrightnessFadeSlotBusy(0), checkResult == 0)) &&
        (checkResult = IsSlideButtonsNotSlidingOut(), checkResult != 0)) {
        ReleaseBgTextCanvasOfScreen(0);
        if (gChildWaitMessageShowNext == 0) {
            HideSubScreenMessage();
            ClearDispcntBits(1, 1);
        }
        ClearDispcntBits(0, 0x15);
        if (gChildWaitMessageShowNext == 0) {
            SetPrimaryMenuPair(0, 1);
            SetUpdateFunction(SetupOptMenu);
            return;
        }
        SetPrimaryMenuPair(0, 1);
        SetUpdateFunction(SetupChildWait);
    }
}
