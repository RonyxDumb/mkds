#include "03/code_021cbc00.h"
#include "03/code_021bf4dc.h"
#include "03/code_021c2c94.h"
#include "03/code_021c7d30.h"
#include "03/code_021cb8d8.h"
#include "03/code_021bf410.h"
#include "03/code_021c2000.h"
#include "03/code_021c3000.h"
#include "03/code_021c9000.h"
#include "03/code_021cb000.h"
#include "03/code_021cdbd0.h"
#include "03/code_021cdd28.h"
#include "03/code_021ce000.h"
#include "03/code_021cef90.h"
#include "03/code_021d1000.h"
#include "03/code_021bf000.h"
#include "03/code_021cd000.h"
#include "03/code_021d1dd0.h"
#include "03/unk_021d7000.h"
#include "code_0214b824.h"

#include "03/unk_021da000.h"
#include "03/code_021c209c.h"
#include "03/code_021c2a74.h"
#include "03/code_021d1fd0.h"
#include "03/code_021d254c.h"
#include "03/code_021d1f70.h"
#include "03/code_021cea3c.h"

void UpdateConnectMessage(void) {
    int messageAnswer;
    UpdateConnectMessageInputNop();
    UpdateConnectMessageNop();
    messageAnswer = GetMessageBoxResult();
    if (messageAnswer == 0) {
        StartSoundSeq(6);
        CloseMessageBox();
        StartSoundSeq(6);
        SetUpdateFunction(UpdateConnectMessageClose);
    }
}

void UpdateConnectMessageInputNop(void) {}

void UpdateConnectMessageNop(void) {}

void UpdateConnectMessageClose(void) {
    int messageOpen;
    messageOpen = IsMessageBoxOpen();
    if (messageOpen == 0) {
        StartBlendBrightnessFade(3, 0, 0x14, 8);
        SetUpdateFunction(UpdateConnectMessageFadeOut);
    }
}

void UpdateConnectMessageFadeOut(void) {
    int fadeSlotBusy;
    fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(0);
    if (fadeSlotBusy == 0) {
        ClearDispcntBits(0, 0x14);
        SetPrimaryMenuPair(0, 1);
        SetUpdateFunction(SetupConnect);
    }
}

void SetupConnectDone(void) {
    *(u8 *) &gConnectDoneFrames = 0;
    LoadConnectDoneFileAndSetBgCnt();
    PrintMessage(0x77);
    SetUpdateFunction(StartConnectDoneFadeIn);
}

void LoadConnectDoneFileAndSetBgCnt(void) {
    void *nscName = &gXb4MultiNscName9;
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

void StartConnectDoneFadeIn(void) {
    StartBlendBrightnessFade(2, 0, 0x15, 8);
    CombineDispcntBits(0, 0x15);
    SetUpdateFunction(UpdateConnectDoneFadeIn);
}

void UpdateConnectDoneFadeIn(void) {
    if (IsBlendBrightnessFadeSlotBusy(0) == 0) {
        SetUpdateFunction(UpdateConnectDone);
    }
}

void UpdateConnectDone(void) {
    UpdateConnectDoneFrames();
    UpdateConnectDoneNop();
}

void UpdateConnectDoneNop(void) {}

void StartConnectDoneFadeOut(void) {
    int secondaryPairSecond[1];
    GetSecondaryMenuPair(NULL, secondaryPairSecond);
    if (secondaryPairSecond[0] != 0) {
        StartMenuPairObjectsSlideOut();
    }
    StartBlendBrightnessFade(3, 1, 1, 8);
    StartBlendBrightnessFade(3, 0, 0x15, 8);
    SetUpdateFunction(UpdateConnectDoneRelease);
}

void UpdateConnectDoneRelease(void) {
    int v1;
    int secondaryPairSecond[1];
    v1 = IsBlendBrightnessFadeSlotBusy(1);
    if (((v1 == 0) && (v1 = IsBlendBrightnessFadeSlotBusy(0), v1 == 0)) &&
        (v1 = IsMenuPairObjectsNotSlidingOut(), v1 != 0)) {
        ReleaseBgTextCanvasOfScreen(0);
        HideSubScreenMessage();
        ClearDispcntBits(1, 1);
        ClearDispcntBits(0, 0x15);
        SetPrimaryMenuPair(2, 1);
        GetSecondaryMenuPair(NULL, secondaryPairSecond);
        if (secondaryPairSecond[0] == 0) {
            SetSecondaryMenuPair(0, 0);
            SetUpdateFunction(CreateJb3List);
            return;
        }
        SetUpdateFunction(SetupJb2Menu);
    }
}

void UpdateConnectDoneFrames(void) {
    s32 secondaryPairSecond;
    gConnectDoneFrames[0]++;
    if (gConnectDoneFrames[0] >= 0xb4) {
        GetSecondaryMenuPair(NULL, &secondaryPairSecond);
        switch (GetMode()) {
            case 0:
                break;
            case 1:
                if (secondaryPairSecond != 0) {
                    SetUpdateFunction(StartMainFadeOut);
                    return;
                }
                break;
        }
        SetUpdateFunction(StartConnectDoneFadeOut);
    }
}
