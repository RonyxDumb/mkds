#include "03/code_021ca028.h"
#include "03/code_021bf810.h"
#include "03/code_021bf410.h"
#include "03/code_021c2000.h"
#include "03/code_021ca000.h"
#include "03/code_021cb000.h"
#include "03/code_021cbf60.h"
#include "03/code_021cdbd0.h"
#include "03/code_021cef90.h"
#include "03/code_021d1000.h"
#include "03/code_021bf000.h"
#include "03/code_021be000.h"
#include "03/code_021d1dd0.h"
#include "03/unk_021da000.h"
#include "03/code_021bf098.h"
#include "03/code_021c209c.h"
#include "03/code_021ce000.h"
#include "03/code_021bf4dc.h"
#include "03/code_021c9000.h"
#include "03/code_021d1f70.h"
#include "03/unk_021d7000.h"
#include "gx_load2d.h"
#include "03/code_021c99a8.h"
#include "03/code_021cd000.h"
#include "03/code_021d2940.h"
#include "03/code_021ca20c.h"

#include "03/code_021d1fd0.h"
#include "03/code_021d254c.h"
#include "03/code_021cea3c.h"

void UpdateExchangeSearchMessageResult(void) {
    int messageAnswer;
    messageAnswer = GetMessageBoxResult();
    if (messageAnswer == 0) {
        StartSoundSeq(6);
        CloseMessageBox();
        SetUpdateFunction(UpdateExchangeSearchMessageClose);
    }
}

void UpdateExchangeSearchMessageClose(void) {
    int messageOpen;
    messageOpen = IsMessageBoxOpen();
    if (messageOpen == 0) {
        SetUpdateFunction(StartExchangeSearchClose);
    }
}

void SetupExchangeResult(void) {
    *(u8 *) &gExchangeResultFrames = 0;
    LoadExchangeResultFileAndSetBgCnt();
    LoadHlSetScr();
    PrintMessage(0x6b);
    StartSoundSeq(0x10);
    SetUpdateFunction(StartExchangeResultFadeIn);
}

void LoadExchangeResultFileAndSetBgCnt(void) {
    void *xb4MultiNscName = &gXb4MultiNscName5;
    void *bg2ScrLoader = &GX_LoadBG2Scr;
    u32 bg2ScrLoadResult = LoadFileToVram(xb4MultiNscName, bg2ScrLoader);
    u32 subBg0CntAddress = 0x4001008u;
    u32 subBg0CntValue = (*(u16 *) ((subBg0CntAddress) + (0)));
    u32 subBg0CntCleared = ((subBg0CntValue) & ~(0x3u));
    u32 subBg0CntNew = ((subBg0CntCleared) | (0x3u));
    u32 subBg1CntAddress;
    u32 subBg1CntValue;
    u32 subBg1CntCleared;
    u32 subBg1CntNew;
    u32 mainBg0CntAddress;
    u32 mainBg0CntValue;
    u32 mainBg0CntCleared;
    u32 mainBg0CntNew;
    u32 mainBg1CntAddress;
    u32 mainBg1CntValue;
    u32 mainBg1CntCleared;
    u32 mainBg1CntNew;
    u32 mainBg2CntAddress;
    u32 mainBg2CntValue;
    u32 mainBg2CntCleared;
    u32 mainBg2CntNew;
    *(u16 *) ((subBg0CntAddress) + (0)) = subBg0CntNew;
    subBg1CntAddress = 0x400100au;
    subBg1CntValue = (*(u16 *) ((subBg1CntAddress) + (0)));
    subBg1CntCleared = ((subBg1CntValue) & ~(0x3u));
    subBg1CntNew = ((subBg1CntCleared) | (0x3u));
    *(u16 *) ((subBg1CntAddress) + (0)) = subBg1CntNew;
    mainBg0CntAddress = 0x4000008u;
    mainBg0CntValue = (*(u16 *) ((mainBg0CntAddress) + (0)));
    mainBg0CntCleared = ((mainBg0CntValue) & ~(0x3u));
    mainBg0CntNew = ((mainBg0CntCleared) | (0x3u));
    *(u16 *) ((mainBg0CntAddress) + (0)) = mainBg0CntNew;
    mainBg1CntAddress = 0x400000au;
    mainBg1CntValue = (*(u16 *) ((mainBg1CntAddress) + (0)));
    mainBg1CntCleared = ((mainBg1CntValue) & ~(0x3u));
    mainBg1CntNew = ((mainBg1CntCleared) | (0x3u));
    *(u16 *) ((mainBg1CntAddress) + (0)) = mainBg1CntNew;
    mainBg2CntAddress = 0x400000cu;
    mainBg2CntValue = (*(u16 *) ((mainBg2CntAddress) + (0)));
    mainBg2CntCleared = ((mainBg2CntValue) & ~(0x3u));
    mainBg2CntNew = ((mainBg2CntCleared) | (0x3u));
    *(u16 *) ((mainBg2CntAddress) + (0)) = mainBg2CntNew;
}

void StartExchangeResultFadeIn(void) {
    StartBlendBrightnessFade(2, 0, 0x15, 8);
    CombineDispcntBits(0, 0x15);
    SetUpdateFunction(UpdateExchangeResultFadeIn);
}

void UpdateExchangeResultFadeIn(void) {
    if (IsBlendBrightnessFadeSlotBusy(0) == 0) {
        SetUpdateFunction(UpdateExchangeResult);
    }
}

void UpdateExchangeResult(void) {
    UpdateExchangeResultFrames();
    UpdateExchangeResultNop();
}

void UpdateExchangeResultNop(void) {}

void StartExchangeResultFadeOut(void) {
    StartBlendBrightnessFade(3, 1, 1, 8);
    StartBlendBrightnessFade(3, 0, 0x15, 8);
    SetUpdateFunction(UpdateExchangeResultRelease);
}

void UpdateExchangeResultRelease(void) {
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

void UpdateExchangeResultFrames(void) {
    gExchangeResultFrames[0]++;
    if (gExchangeResultFrames[0] >= 120) {
        SetUpdateFunction(StartExchangeResultFadeOut);
    }
}
