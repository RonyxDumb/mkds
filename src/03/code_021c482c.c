#include "03/code_021c482c.h"
#include "03/code_021c391c.h"
#include "03/code_021bf000.h"
#include "03/code_021c3000.h"
#include "03/code_021c4000.h"
#include "03/code_021be000.h"
#include "03/code_021c2000.h"
#include "03/code_021ce000.h"
#include "03/code_021bf4dc.h"
#include "03/code_021c209c.h"
#include "03/code_021cd000.h"
#include "03/code_021d1000.h"
#include "03/code_021d1dd0.h"
#include "03/code_021d1f70.h"
#include "03/unk_021d7000.h"
#include "03/unk_021da000.h"
#include "code_0214b824.h"
#include "03/code_021c4dd4.h"
#include "03/code_021d2940.h"

#include "03/code_021d1fd0.h"
#include "03/code_021d254c.h"
#include "03/code_021bf098.h"
#include "code_0212df7c.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d3000.h"
#include "03/code_021d3488.h"
#include "03/code_021c25e0.h"
#include "03/unk_021d5000.h"
#include "03/code_021bf410.h"

void SetupChildWaitMessage(void) {
    LoadChildWaitMessageFileAndSetBgCnt();
    PrintMessage(0x62);
    gChildWaitMessageSubScreenShown[0] = ShowSubScreenMessage(0x8d, -1, 0);
    SetUpdateFunction(StartChildWaitMessageFadeIn);
}

void LoadChildWaitMessageFileAndSetBgCnt(void) {
    void *nscName = &data_ov003_021d7194;
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
    if ((*(u8 *) &gChildWaitMessageSubScreenShown) != 0) {
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
        SetButtonResultIfNone((u8) 1);
    }
    allKeysPressed = AreKeysPressed(2);
    if (allKeysPressed != 0) {
        SetButtonResultIfNone((u8) 0);
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
    int v1;
    v1 = IsBlendBrightnessFadeSlotBusy(1);
    if (((v1 == 0) && (v1 = IsBlendBrightnessFadeSlotBusy(0), v1 == 0)) &&
        (v1 = IsSlideButtonsNotSlidingOut(), v1 != 0)) {
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
