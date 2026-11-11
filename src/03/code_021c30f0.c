#include "03/code_021c30f0.h"
#include "03/code_021bf810.h"
#include "03/code_021c3000.h"
#include "03/code_021c34e8.h"
#include "03/code_021c391c.h"
#include "03/code_021cef90.h"
#include "03/code_021d1000.h"
#include "03/code_021d1dd0.h"
#include "03/code_021d1f70.h"
#include "03/unk_021da000.h"
#include "03/code_021d2940.h"
#include "03/code_021c2000.h"
#include "03/unk_021d7000.h"
#include "code_0214b824.h"

#include "03/code_021c209c.h"
#include "03/code_021c30d4.h"
#include "code_0212df7c.h"
#include "03/code_021cdbd0.h"
#include "03/code_021ce000.h"
#include "03/code_021cea3c.h"
#include "03/code_021d1fd0.h"
#include "03/code_021d254c.h"
#include "03/code_021bf098.h"
#include "03/code_021bf000.h"
#include "03/code_021bf4dc.h"
#include "03/unk_021d5000.h"
#include "03/code_021bf410.h"

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
        SetButtonResultIfNone((u8) 1);
    }
    allKeysPressed = AreKeysPressed(2);
    if (allKeysPressed != 0) {
        SetButtonResultIfNone((u8) 0);
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
            func_ov003_021cefc0(0x56, 0, 1, -1, 0);
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
    int v1;
    v1 = IsBlendBrightnessFadeSlotBusy(0);
    if ((v1 == 0) && (((gYb5MultiShowNext != 0 || (v1 = IsBlendBrightnessFadeSlotBusy(1), v1 == 0)) &&
                       (v1 = IsSlideButtonsNotSlidingOut(), v1 != 0)))) {
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
    switch (func_ov003_021cef80()) {
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
    func_ov003_021cef90();
    SetUpdateFunction(UpdateYb5MultiMessageClose);
}
