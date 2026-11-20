#include "03/Menu/child_wait.h"
#include "registers.h"
#include "03/Menu/child_wait_fold_detect.h"
#include "03/Menu/opt_menu.h"
#include "03/Menu/child_wait_message.h"
#include "03/Menu/sub_screen_message.h"
#include "03/Sound/sound_seq.h"
#include "03/Graphics/blend_brightness_fade_start.h"
#include "03/System/tasks.h"
#include "03/Net/child_wait_session_object.h"
#include "03/Graphics/blend_brightness_fade_slots.h"
#include "03/Menu/wifi_menu_shared.h"
#include "03/System/task_input.h"
#include "03/Menu/menu_pair_loading.h"
#include "03/Menu/wifi_menu_strings.h"
#include "vram_load_2d_graphics.h"
#include "03/Graphics/text_canvas.h"
#include "03/Graphics/dispcnt_window.h"
#include "03/Menu/slide_buttons.h"
#include "03/System/application.h"

u8 gChildWaitYb5MultiNscName[19] = {0x63, 0x68, 0x61, 0x72, 0x2f, 0x79, 0x62, 0x35, 0x4d, 0x75,
                            0x6c, 0x74, 0x69, 0x2e, 0x6e, 0x73, 0x63, 0x2e, 0x6c};
u8 gChildWaitResult;

BOOL ChildWaitPAD_DetectFold(void) {
    if ((*HW_BUTTON_XY_BUF & PAD_DETECT_FOLD_MASK) >> 15) {
        return 1;
    }
    return 0;
}

void SetupChildWait(void) {
    CreateChildWaitSession(ChildWaitResultCallback);
    gChildWaitResult = 0;
    LoadChildWaitFileAndSetBgCnt();
    PrintMessage(0x5e);
    CreateAnimatedIcon(0);
    StartSoundSeq(0xb);
    SetUpdateFunction(StartChildWaitFadeIn);
}

void LoadChildWaitFileAndSetBgCnt(void) {
    void *nscName = &gChildWaitYb5MultiNscName;
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

void StartChildWaitFadeIn(void) {
    StartBlendBrightnessFade(2, 0, 0x15, 8);
    CombineDispcntBits(0, 0x15);
    SetUpdateFunction(UpdateChildWaitFadeIn);
}

void UpdateChildWaitFadeIn(void) {
    int fadeSlotBusy;
    fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(0);
    if (fadeSlotBusy == 0) {
        CreateSlideButtonsForMenuPair(1);
        SetUpdateFunction(UpdateChildWaitButtonsIn);
    }
}

void UpdateChildWaitButtonsIn(void) {
    if (GetButtonResult() != -2) {
        SetUpdateFunction(UpdateChildWait);
    }
}

void UpdateChildWait(void) {
    UpdateChildWaitInput();
    UpdateChildWaitNop();
    UpdateChildWaitResult();
}

void UpdateChildWaitInput(void) {
    int checkResult;
    checkResult = AreKeysPressed(2);
    if (checkResult != 0) {
        SetButtonResultIfNone(0);
        return;
    }
    checkResult = ChildWaitPAD_DetectFold();
    if (checkResult != 0) {
        SetButtonResultIfNone(0);
    }
}

void UpdateChildWaitNop(void) {}

void UpdateChildWaitResult(void) {
    int buttonResult;
    buttonResult = GetButtonResult();
    if (buttonResult == 0) {
        StopSoundSeq();
        StartSoundSeq(7);
        SetUpdateFunction(StartChildWaitClose);
    }
}

void StartChildWaitClose(void) {
    if (gChildWaitResult == 0) {
        StartChildWaitStop();
    }
    DisableButtonTouch();
    StartBlendBrightnessFadeWait(8);
    SetUpdateFunction(UpdateChildWaitFadeOut);
}

void UpdateChildWaitFadeOut(void) {
    int checkResult;
    checkResult = IsBlendBrightnessFadeSlotBusy(1);
    if ((checkResult == 0) &&
        ((gChildWaitResult != 0 || (checkResult = IsChildWaitSessionReleased(), checkResult != 0)))) {
        StartSlideButtonsOut();
        if (gChildWaitResult == 0) {
            StartBlendBrightnessFade(3, 1, 1, 8);
        }
        StartBlendBrightnessFade(3, 0, 0x15, 8);
        SetUpdateFunction(UpdateChildWaitRelease);
    }
}

void UpdateChildWaitRelease(void) {
    int checkResult;
    checkResult = IsBlendBrightnessFadeSlotBusy(0);
    if (((checkResult == 0) &&
         (((gChildWaitResult != 0 || (checkResult = IsBlendBrightnessFadeSlotBusy(1), checkResult == 0)) &&
           (checkResult = IsSlideButtonsNotSlidingOut(), checkResult != 0)))) &&
        ((gChildWaitResult != 0 || (checkResult = IsChildWaitSessionReleased(), checkResult != 0)))) {
        ReleaseAnimatedIcon();
        ReleaseBgTextCanvasOfScreen(0);
        if (gChildWaitResult == 0) {
            HideSubScreenMessage();
            ClearDispcntBits(1, 1);
        }
        ClearDispcntBits(0, 0x15);
        if (gChildWaitResult == 0) {
            SetPrimaryMenuPair(0, 1);
            SetUpdateFunction(SetupOptMenu);
            return;
        }
        if (gChildWaitResult == 2) {
            SetPrimaryMenuPair(0, 1);
            SetUpdateFunction(SetupChildWaitMessage);
            return;
        }
        SetPrimaryMenuPair(0, 1);
        SetUpdateFunction(SetupJb5Move);
    }
}

void ChildWaitResultCallback(int eventCode) {
    StopSoundSeq();
    if (eventCode == 0) {
        gChildWaitResult = 1;
        StartSoundSeq(0x10);
    } else {
        gChildWaitResult = 2;
        StartSoundSeq(0x12);
    }
    SetChildWaitCallback(NULL);
    SetUpdateFunction(StartChildWaitClose);
}
