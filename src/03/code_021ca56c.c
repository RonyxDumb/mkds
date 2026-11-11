#include "03/code_021ca56c.h"
#include "03/code_021c5724.h"
#include "03/code_021be000.h"
#include "03/code_021bf000.h"
#include "03/code_021c2000.h"
#include "03/code_021c6000.h"
#include "03/code_021cb000.h"
#include "03/code_021cb4d0.h"
#include "03/code_021cd000.h"
#include "03/code_021b94b8.h"
#include "03/code_021cd2e0.h"
#include "03/code_021cef90.h"
#include "03/code_021d1000.h"
#include "03/code_021d1dd0.h"
#include "03/code_021d1f70.h"
#include "03/unk_021da000.h"
#include "03/code_021d2940.h"
#include "03/code_021ca000.h"
#include "03/unk_021d7000.h"
#include "code_0214b824.h"
#include "03/unk_021d6000.h"
#include "03/code_021ca940.h"

#include "03/code_021cea3c.h"
#include "03/code_021d1fd0.h"
#include "03/code_021d254c.h"
#include "03/code_021bf098.h"
#include "03/code_021c209c.h"
#include "03/code_021cd0d0.h"
#include "03/code_021cdbd0.h"
#include "03/code_021ce000.h"
#include "03/code_021bf4dc.h"
#include "03/code_021bf410.h"
#include "03/code_021bf810.h"
#include "03/code_021be610.h"

void SetupApScan(void) {
    gApScanFrames = 0;
    *(u8 *) &gApScanKind = 0;
    LoadApScanFilesAndSetBgCnt();
    ShowSubScreenMessage(0x7f, -1, 0);
    LoadHlSetScr();
    CreateObjectsForMenuPair(2);
    PrintMessage(0x7f);
    CreateAnimatedIcon(0);
    CreateApScan();
    InitApScan();
    StartSoundSeq(0xa);
    SetUpdateFunction(StartApScanFadeIn);
}

void LoadApScanFilesAndSetBgCnt(void) {
    void *ncgName = &gJbBgStep3NcgName6;
    void *loadBg2CharFunc = &GX_LoadBG2Char;
    u32 bg2CharLoadResult = LoadFileToVram(ncgName, loadBg2CharFunc);
    void *nclName = &gYbBgStep3NclName6;
    void *loadBgPlttFunc = &GX_LoadBGPltt;
    u32 bgPlttLoadResult = LoadFileToVram(nclName, loadBgPlttFunc);
    void *nscName = &gXb4MultiNscName7;
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

void StartApScanFadeIn(void) {
    StartBlendBrightnessFade(2, 1, 1, 8);
    StartBlendBrightnessFade(2, 0, 0x15, 8);
    CombineDispcntBits(1, 1);
    CombineDispcntBits(0, 0x15);
    SetUpdateFunction(UpdateApScanFadeIn);
}

void UpdateApScanFadeIn(void) {
    int fadeSlotBusy;
    fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(1);
    if ((fadeSlotBusy == 0) && (fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(0), fadeSlotBusy == 0)) {
        CreateSlideButtonsForMenuPair(1);
        SetUpdateFunction(UpdateApScanButtonsIn);
    }
}

void UpdateApScanButtonsIn(void) {
    if (GetButtonResult() != -2) {
        EnableButtonTouch();
        SetUpdateFunction(UpdateApScan);
    }
}

void UpdateApScan(void) {
    UpdateApScanInput();
    UpdateApScanNop();
    UpdateApScanResult();
    UpdateApScanFrames();
}

void UpdateApScanFrames(void) {
    int entryCount;
    int entries;
    int i;
    gApScanFrames++;
    if (gApScanFrames >= 0x12c) {
        StopSoundSeq();
        entryCount = CountApScanEntries(&entries);
        if (entryCount == 0) {
            *(u8 *) &gApScanKind = 2;
            CreateMessageBox(0x43, 1, 1, -1, 0);
            StartSoundSeq(0x12);
            DisableButtonTouch();
            SetUpdateFunction(UpdateApScanMessageResult);
            return;
        }
        for (i = 0; i < entryCount; i++) {
            if (*(u8 *) (entries + i * 0x2a + 0x28) != 2) {
                break;
            }
        }
        if (i == entryCount) {
            *(u8 *) &gApScanKind = 3;
            CreateMessageBox(0x42, 1, 1, -1, 0);
            StartSoundSeq(0x12);
            DisableButtonTouch();
            SetUpdateFunction(UpdateApScanMessageResult);
        } else {
            *(u8 *) &gApScanKind = 1;
            StartSoundSeq(0xf);
            SetUpdateFunction(StartApScanClose);
        }
    }
}

void UpdateApScanInput(void) {
    int keysPressed;
    keysPressed = AreKeysPressed(2);
    if (keysPressed != 0) {
        StopSoundSeq();
        SetButtonResultIfNone((u8) 0);
    }
}

void UpdateApScanNop(void) {}

void UpdateApScanResult(void) {
    int buttonResult;
    buttonResult = GetButtonResult();
    if (buttonResult == 0) {
        StopSoundSeq();
        StartSoundSeq(7);
        SetUpdateFunction(StartApScanClose);
    }
}

void StartApScanClose(void) {
    DisableButtonTouch();
    StartBlendBrightnessFadeWait(8);
    SetUpdateFunction(UpdateApScanFadeOut);
}

void UpdateApScanFadeOut(void) {
    int fadeSlotBusy;
    fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(1);
    if (fadeSlotBusy == 0) {
        StartSlideButtonsOut();
        StartBlendBrightnessFade(3, 1, 1, 8);
        StartBlendBrightnessFade(3, 0, 0x15, 8);
        SetUpdateFunction(UpdateApScanRelease);
    }
}

void UpdateApScanRelease(void) {
    int v1;
    v1 = IsBlendBrightnessFadeSlotBusy(1);
    if (((v1 == 0) && (v1 = IsBlendBrightnessFadeSlotBusy(0), v1 == 0)) &&
        (v1 = IsSlideButtonsNotSlidingOut(), v1 != 0)) {
        do {
            v1 = StopApScan();
        } while (v1 == 0);
        ReleaseAnimatedIcon();
        ReleaseBgTextCanvasOfScreen(0);
        HideSubScreenMessage();
        ClearDispcntBits(1, 1);
        ClearDispcntBits(0, 0x15);
        if ((*(u8 *) &gApScanKind) != 1) {
            ReleaseApScan();
            CopyApEntryToWorkCopy(GetApWorkCopy()->mEntryIndex);
            SetPrimaryMenuPair(2, 1);
            SetUpdateFunction(SetupWay);
            return;
        }
        SetPrimaryMenuPair(0, 1);
        SetSecondaryMenuPair(0, 0);
        SetUpdateFunction(CreateApList);
    }
}

void UpdateApScanMessageResult(void) {
    int messageAnswer;
    messageAnswer = GetMessageBoxResult();
    if (messageAnswer == 0) {
        StartSoundSeq(6);
        CloseMessageBox();
        SetUpdateFunction(UpdateApScanMessageClose);
    }
}

void UpdateApScanMessageClose(void) {
    int messageOpen;
    messageOpen = IsMessageBoxOpen();
    if (messageOpen == 0) {
        SetUpdateFunction(StartApScanClose);
    }
}
