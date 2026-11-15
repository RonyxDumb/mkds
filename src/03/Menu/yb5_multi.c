#include "03/Menu/yb5_multi.h"
#include "03/code_021c30f0.h"
#include "03/Graphics/hl_scr.h"
#include "03/code_021c3000.h"
#include "03/Menu/yb5_multi_next_setup.h"
#include "03/Menu/opt_menu.h"
#include "03/Menu/message_box_create.h"
#include "03/code_021d1000.h"
#include "03/code_021d1dd0.h"
#include "03/code_021d1f70.h"
#include "03/unk_021da000.h"
#include "03/System/task_input.h"
#include "03/code_021c2000.h"
#include "03/unk_021d7000.h"
#include "gx_load2d.h"
#include "03/System/application.h"
#include "code_0212df7c.h"
#include "03/code_021cdbd0.h"
#include "03/code_021ce000.h"
#include "03/Menu/message_box.h"
#include "03/Graphics/text_canvas.h"
#include "03/Graphics/dispcnt_window.h"
#include "03/Menu/slide_buttons.h"
#include "03/code_021bf000.h"
#include "03/Menu/menu_pair_loading.h"
#include "03/unk_021d5000.h"
#include "03/Menu/sub_screen_message.h"

u8 gYb5MultiNscName[19] = {0x63, 0x68, 0x61, 0x72, 0x2f, 0x79, 0x62, 0x35, 0x4d, 0x75,
                           0x6c, 0x74, 0x69, 0x2e, 0x6e, 0x73, 0x63, 0x2e, 0x6c};
u8 gYb5MultiShowNext;

void SetupYb5Multi(void) {
    gYb5MultiShowNext = 0;
    LoadYb5MultiFileAndSetBgCnt();
    LoadHlScr(18);
    ShowSubScreenMessage(140, -1, 0);
    PrintMessage(85);
    SetUpdateFunction(StartYb5MultiFadeIn);
}

void LoadYb5MultiFileAndSetBgCnt(void) {
    void *yb5MultiNscName = &gYb5MultiNscName;
    void *loadBg2ScrFunc = &GX_LoadBG2Scr;
    u32 loadFileResult = LoadFileToVram(yb5MultiNscName, loadBg2ScrFunc);
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

void StartYb5MultiFadeIn(void) {
    StartBlendBrightnessFade(2, 1, 1, 8);
    StartBlendBrightnessFade(2, 0, 0x15, 8);
    CombineDispcntBits(1, 1);
    CombineDispcntBits(0, 0x15);
    SetUpdateFunction(UpdateYb5MultiFadeIn);
}

void UpdateYb5MultiFadeIn(void) {
    int fadeSlotBusy;
    fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(1);
    if ((fadeSlotBusy == 0) && (fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(0), fadeSlotBusy == 0)) {
        CreateSlideButtonsForMenuPair(3);
        SetUpdateFunction(UpdateYb5MultiButtonsIn);
    }
}

void UpdateYb5MultiButtonsIn(void) {
    if (GetButtonResult() != -2) {
        EnableButtonTouch();
        SetUpdateFunction(UpdateYb5Multi);
    }
}

void UpdateYb5Multi(void) {
    UpdateYb5MultiInput();
    UpdateYb5MultiNop();
    UpdateYb5MultiResult();
}

void UpdateYb5MultiInput(void) {
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

void UpdateYb5MultiNop(void) {}

void UpdateYb5MultiResult(void) {
    switch (GetButtonResult()) {
        case 0:
            StartSoundSeq(7);
            SetUpdateFunction(StartYb5MultiClose);
            break;
        case 1:
            StartSoundSeq(6);
            CreateMessageBox(0x56, 0, 1, -1, 0);
            DisableButtonTouch();
            SetUpdateFunction(UpdateYb5MultiMessageResult);
            break;
    }
}

void StartYb5MultiClose(void) {
    DisableButtonTouch();
    StartBlendBrightnessFadeWait(8);
    SetUpdateFunction(UpdateYb5MultiFadeOut);
}

void UpdateYb5MultiFadeOut(void) {
    int fadeSlotBusy;
    fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(1);
    if (fadeSlotBusy == 0) {
        StartSlideButtonsOut();
        if (gYb5MultiShowNext == 0) {
            StartBlendBrightnessFade(3, 1, 1, 8);
        }
        StartBlendBrightnessFade(3, 0, 0x15, 8);
        SetUpdateFunction(UpdateYb5MultiRelease);
    }
}

void UpdateYb5MultiRelease(void) {
    int checkResult;
    checkResult = IsBlendBrightnessFadeSlotBusy(0);
    if ((checkResult == 0) &&
        (((gYb5MultiShowNext != 0 || (checkResult = IsBlendBrightnessFadeSlotBusy(1), checkResult == 0)) &&
          (checkResult = IsSlideButtonsNotSlidingOut(), checkResult != 0)))) {
        ReleaseBgTextCanvasOfScreen(0);
        if (gYb5MultiShowNext == 0) {
            HideSubScreenMessage();
            ClearDispcntBits(1, 1);
        }
        ClearDispcntBits(0, 0x15);
        if (gYb5MultiShowNext == 0) {
            SetPrimaryMenuPair(0, 1);
            SetUpdateFunction(SetupOptMenu);
            return;
        }
        SetPrimaryMenuPair(0, 1);
        SetUpdateFunction(SetupYb5MultiNext);
    }
}

void UpdateYb5MultiMessageResult(void) {
    switch (GetMessageBoxResult()) {
        case 1:
            StartSoundSeq(0xe);
            gYb5MultiShowNext = 1;
            break;
        case 0:
            StartSoundSeq(7);
            break;
        default:
            return;
    }
    CloseMessageBox();
    SetUpdateFunction(UpdateYb5MultiMessageClose);
}

void UpdateYb5MultiMessageClose(void) {
    int messageOpen;
    messageOpen = IsMessageBoxOpen();
    if (messageOpen == 0) {
        SetUpdateFunction(StartYb5MultiClose);
    }
}
