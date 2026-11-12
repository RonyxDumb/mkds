#include "03/code_021cc144.h"
#include "03/code_021bf810.h"
#include "03/code_021cb11c.h"
#include "03/code_021cb000.h"
#include "03/code_021cc000.h"
#include "03/code_021cc410.h"
#include "03/code_021cd000.h"
#include "03/code_021d1000.h"
#include "03/code_021d1dd0.h"
#include "03/code_021d1f70.h"
#include "03/unk_021d7000.h"
#include "gx_load2d.h"
#include "03/unk_021da000.h"
#include "03/code_021d2940.h"
#include "03/code_021c2000.h"
#include "03/code_021ce000.h"

#include "03/code_021d1fd0.h"
#include "03/code_021d254c.h"
#include "03/code_021bf098.h"
#include "03/code_021c209c.h"
#include "code_0212df7c.h"
#include "03/code_021cdbd0.h"
#include "03/code_021bf000.h"
#include "03/code_021bf4dc.h"
#include "03/unk_021d5000.h"
#include "03/code_021bf410.h"

void SetupXb3Multi(void) {
    gXb3MultiChosen = 0;
    LoadXb3MultiFilesAndSetBgCnt();
    LoadHlScr(8);
    ShowSubScreenMessage(0x85, -1, 0);
    CreateObjectsForMenuPair(1);
    PrintMessage(0x6c);
    SetUpdateFunction(StartXb3MultiFadeIn);
}

void LoadXb3MultiFilesAndSetBgCnt(void) {
    void *ncgName = &gJbBgStep2NcgName3;
    void *loadBg2CharFunc = &GX_LoadBG2Char;
    u32 bg2CharLoadResult = LoadFileToVram(ncgName, loadBg2CharFunc);
    void *nclName = &gYbBgStep2NclName3;
    void *loadBgPlttFunc = &GX_LoadBGPltt;
    u32 bgPlttLoadResult = LoadFileToVram(nclName, loadBgPlttFunc);
    void *nscName = &gXb3MultiNscName;
    void *loadBg2ScrFunc = &GX_LoadBG2Scr;
    u32 bg2ScrLoadResult = LoadFileToVram(nscName, loadBg2ScrFunc);
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

void StartXb3MultiFadeIn(void) {
    StartBlendBrightnessFade(2, 1, 1, 8);
    StartBlendBrightnessFade(2, 0, 0x15, 8);
    CombineDispcntBits(1, 1);
    CombineDispcntBits(0, 0x15);
    SetUpdateFunction(UpdateXb3MultiFadeIn);
}

void UpdateXb3MultiFadeIn(void) {
    int fadeSlotBusy;
    fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(1);
    if ((fadeSlotBusy == 0) && (fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(0), fadeSlotBusy == 0)) {
        CreateSlideButtonsForMenuPair(6);
        SetUpdateFunction(UpdateXb3MultiButtonsIn);
    }
}

void UpdateXb3MultiButtonsIn(void) {
    if (GetButtonResult() != -2) {
        EnableButtonTouch();
        SetUpdateFunction(UpdateXb3Multi);
    }
}

void UpdateXb3Multi(void) {
    UpdateXb3MultiInput();
    UpdateXb3MultiNop();
    UpdateXb3MultiResult();
}

void UpdateXb3MultiInput(void) {
    int keysPressed;
    keysPressed = AreKeysPressed(1);
    if (keysPressed != 0) {
        SetButtonResultIfNone((u8) 1);
    }
    keysPressed = AreKeysPressed(2);
    if (keysPressed != 0) {
        SetButtonResultIfNone((u8) 0);
    }
}

void UpdateXb3MultiNop(void) {}

void UpdateXb3MultiResult(void) {
    switch (GetButtonResult()) {
        case 0:
            StartSoundSeq(7);
            break;
        case 1:
            StartSoundSeq(6);
            gXb3MultiChosen = 1;
            break;
        default:
            return;
    }
    SetUpdateFunction(StartXb3MultiClose);
}

void StartXb3MultiClose(void) {
    DisableButtonTouch();
    StartBlendBrightnessFadeWait(8);
    SetUpdateFunction(UpdateXb3MultiFadeOut);
}

void UpdateXb3MultiFadeOut(void) {
    int fadeSlotBusy;
    fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(1);
    if (fadeSlotBusy == 0) {
        StartSlideButtonsOut();
        if (gXb3MultiChosen == 0) {
            StartBlendBrightnessFade(3, 1, 1, 8);
        }
        StartBlendBrightnessFade(3, 0, 0x15, 8);
        SetUpdateFunction(UpdateXb3MultiRelease);
    }
}

void UpdateXb3MultiRelease(void) {
    int v1;
    v1 = IsBlendBrightnessFadeSlotBusy(0);
    if ((v1 == 0) && (((gXb3MultiChosen != 0 || (v1 = IsBlendBrightnessFadeSlotBusy(1), v1 == 0)) &&
                       (v1 = IsSlideButtonsNotSlidingOut(), v1 != 0)))) {
        ReleaseBgTextCanvasOfScreen(0);
        if (gXb3MultiChosen == 0) {
            HideSubScreenMessage();
            ClearDispcntBits(1, 1);
        }
        ClearDispcntBits(0, 0x15);
        if (gXb3MultiChosen == 0) {
            SetPrimaryMenuPair(2, 1);
            SetUpdateFunction(CreateAp);
            return;
        }
        SetPrimaryMenuPair(2, 1);
        SetUpdateFunction(SetupUsb);
    }
}
