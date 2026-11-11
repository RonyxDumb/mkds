#include "03/code_021c5548.h"
#include "03/code_021bf4dc.h"
#include "03/code_021bf810.h"
#include "03/code_021bf410.h"
#include "03/code_021c2000.h"
#include "03/code_021c5000.h"
#include "03/code_021cb000.h"
#include "03/code_021cbf60.h"
#include "03/code_021cdbd0.h"
#include "03/code_021cef90.h"
#include "03/code_021d1000.h"
#include "03/code_021bf000.h"
#include "03/code_021bf098.h"
#include "03/code_021c6000.h"
#include "03/code_021c5724.h"
#include "03/code_021d1dd0.h"
#include "03/unk_021da000.h"
#include "03/code_021cca74.h"
#include "03/code_021cd000.h"
#include "03/code_021ce000.h"
#include "03/unk_021d7000.h"
#include "code_0214b824.h"

#include "03/code_021c209c.h"
#include "03/code_021d1fd0.h"
#include "03/code_021d254c.h"
#include "03/code_021d1f70.h"
#include "03/code_021cea3c.h"

void UpdateApListMessageResult(void) {
    int messageAnswer;
    messageAnswer = func_ov003_021cef80();
    if (messageAnswer == 0) {
        StartSoundSeq(6);
        func_ov003_021cef90();
        SetUpdateFunction(UpdateApListMessageClose);
    }
}

void UpdateApListMessageClose(void) {
    int messageOpen;
    messageOpen = func_ov003_021cef6c();
    if (messageOpen == 0) {
        EnableButtonTouch();
        func_ov003_021cce48();
        SetUpdateFunction(UpdateApList);
    }
}

void SetupValueRecordsNext(void) {
    *(u8 *) &gValueRecordsNextFrames = 0;
    LoadValueRecordsNextFileAndSetBgCnt();
    LoadHlSetScr();
    PrintMessage(0x68);
    StartSoundSeq(0x10);
    SetUpdateFunction(StartValueRecordsNextFadeIn);
}

void LoadValueRecordsNextFileAndSetBgCnt(void) {
    void *nscName = &data_ov003_021d7214;
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

void StartValueRecordsNextFadeIn(void) {
    StartBlendBrightnessFade(2, 0, 0x15, 8);
    CombineDispcntBits(0, 0x15);
    SetUpdateFunction(UpdateValueRecordsNextFadeIn);
}

void UpdateValueRecordsNextFadeIn(void) {
    if (IsBlendBrightnessFadeSlotBusy(0) == 0) {
        SetUpdateFunction(UpdateValueRecordsNext);
    }
}

void UpdateValueRecordsNext(void) {
    UpdateValueRecordsNextFrames();
    UpdateValueRecordsNextNop();
}

void UpdateValueRecordsNextNop(void) {}

void StartValueRecordsNextFadeOut(void) {
    StartBlendBrightnessFade(3, 1, 1, 8);
    StartBlendBrightnessFade(3, 0, 0x15, 8);
    SetUpdateFunction(UpdateValueRecordsNextRelease);
}

void UpdateValueRecordsNextRelease(void) {
    int fadeSlotBusy;
    fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(1);
    if ((fadeSlotBusy == 0) && (fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(0), fadeSlotBusy == 0)) {
        ReleaseBgTextCanvasOfScreen(0);
        HideSubScreenMessage();
        ClearDispcntBits(1, 1);
        ClearDispcntBits(0, 0x15);
        SetPrimaryMenuPair(0, 0);
        SetSecondaryMenuPair(0, 1);
        SetUpdateFunction(SetupConnectMessage);
    }
}

void UpdateValueRecordsNextFrames(void) {
    gValueRecordsNextFrames[0]++;
    if (gValueRecordsNextFrames[0] >= 120) {
        SetUpdateFunction(StartValueRecordsNextFadeOut);
    }
}
