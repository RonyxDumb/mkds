#include "03/Menu/opt_menu_message.h"
#include "03/Graphics/hl_scr.h"
#include "03/Menu/opt_menu.h"
#include "03/code_021c43a4.h"
#include "03/code_021c3000.h"
#include "03/code_021c4000.h"
#include "03/code_021c434c.h"
#include "03/code_021d1000.h"
#include "03/code_021d1dd0.h"
#include "03/code_021d1f70.h"
#include "03/unk_021da000.h"
#include "03/System/task_input.h"
#include "03/code_021c2000.h"
#include "03/code_021ce000.h"
#include "03/unk_021d7000.h"
#include "gx_load2d.h"

#include "03/Graphics/text_canvas.h"
#include "03/Graphics/dispcnt_window.h"
#include "03/Menu/slide_buttons.h"
#include "03/System/application.h"
#include "code_0212df7c.h"
#include "03/code_021cdbd0.h"
#include "03/code_021bf000.h"
#include "03/Menu/menu_pair_loading.h"
#include "03/unk_021d5000.h"
#include "03/Menu/sub_screen_message.h"

u8 gYb5MultiNscName4[19] = {0x63, 0x68, 0x61, 0x72, 0x2f, 0x79, 0x62, 0x35, 0x4d, 0x75,
                            0x6c, 0x74, 0x69, 0x2e, 0x6e, 0x73, 0x63, 0x2e, 0x6c};
u8 gOptMenuMessageShowNext;

void SetupOptMenuMessage(void) {
    gOptMenuMessageShowNext = 0;
    LoadOptMenuMessageFileAndSetBgCnt();
    LoadHlScr(19);
    ShowSubScreenMessage(141, -1, 0);
    PrintMessage(93);
    SetUpdateFunction(StartOptMenuMessageFadeIn);
}

void LoadOptMenuMessageFileAndSetBgCnt(void) {
    void *nscName = &gYb5MultiNscName4;
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

void StartOptMenuMessageFadeIn(void) {
    StartBlendBrightnessFade(2, 1, 1, 8);
    StartBlendBrightnessFade(2, 0, 0x15, 8);
    CombineDispcntBits(1, 1);
    CombineDispcntBits(0, 0x15);
    SetUpdateFunction(UpdateOptMenuMessageFadeIn);
}

void UpdateOptMenuMessageFadeIn(void) {
    int fadeSlotBusy;
    fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(0);
    if (fadeSlotBusy == 0) {
        CreateSlideButtonsForMenuPair(3);
        SetUpdateFunction(UpdateOptMenuMessageButtonsIn);
    }
}

void UpdateOptMenuMessageButtonsIn(void) {
    if (GetButtonResult() != -2) {
        EnableButtonTouch();
        SetUpdateFunction(UpdateOptMenuMessage);
    }
}

void UpdateOptMenuMessage(void) {
    UpdateOptMenuMessageInput();
    UpdateOptMenuMessageNop();
    UpdateOptMenuMessageResult();
}

void UpdateOptMenuMessageInput(void) {
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

void UpdateOptMenuMessageNop(void) {}

void UpdateOptMenuMessageResult(void) {
    switch (GetButtonResult()) {
        case 0:
            StartSoundSeq(7);
            break;
        case 1:
            StartSoundSeq(6);
            gOptMenuMessageShowNext = 1;
            break;
        default:
            return;
    }
    SetUpdateFunction(StartOptMenuMessageClose);
}

void StartOptMenuMessageClose(void) {
    DisableButtonTouch();
    StartBlendBrightnessFadeWait(8);
    SetUpdateFunction(UpdateOptMenuMessageFadeOut);
}

void UpdateOptMenuMessageFadeOut(void) {
    int fadeSlotBusy;
    fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(1);
    if (fadeSlotBusy == 0) {
        StartSlideButtonsOut();
        if (gOptMenuMessageShowNext == 0) {
            StartBlendBrightnessFade(3, 1, 1, 8);
        }
        StartBlendBrightnessFade(3, 0, 0x15, 8);
        SetUpdateFunction(UpdateOptMenuMessageRelease);
    }
}

void UpdateOptMenuMessageRelease(void) {
    int checkResult;
    checkResult = IsBlendBrightnessFadeSlotBusy(0);
    if ((checkResult == 0) &&
        (((gOptMenuMessageShowNext != 0 || (checkResult = IsBlendBrightnessFadeSlotBusy(1), checkResult == 0)) &&
          (checkResult = IsSlideButtonsNotSlidingOut(), checkResult != 0)))) {
        ReleaseBgTextCanvasOfScreen(0);
        if (gOptMenuMessageShowNext == 0) {
            HideSubScreenMessage();
            ClearDispcntBits(1, 1);
        }
        ClearDispcntBits(0, 0x15);
        if (gOptMenuMessageShowNext == 0) {
            SetPrimaryMenuPair(0, 1);
            SetUpdateFunction(SetupOptMenu);
            return;
        }
        SetPrimaryMenuPair(0, 1);
        SetUpdateFunction(SetupOptMenuMessageNext);
    }
}

void SetupOptMenuMessageNext(void) {
    OptMenuMessageNextSetBgPriorities();
    PrintMessage(0x5c);
    SetUpdateFunction(StartOptMenuMessageNextFadeIn);
}
