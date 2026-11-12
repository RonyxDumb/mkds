#include "03/code_021c99a8.h"
#include "03/code_021c9c90.h"
#include "03/code_021bf810.h"
#include "03/code_021c2904.h"
#include "03/code_021be000.h"
#include "03/code_021bf000.h"
#include "03/code_021bf410.h"
#include "03/code_021c2000.h"
#include "03/code_021c9000.h"
#include "03/code_021cb4d0.h"
#include "03/code_021cef90.h"
#include "03/code_021d1dd0.h"
#include "03/unk_021da000.h"
#include "03/code_021bf098.h"
#include "03/code_021ce000.h"
#include "03/code_021bf4dc.h"
#include "03/code_021c209c.h"
#include "03/code_021d1000.h"
#include "03/code_021d1f70.h"
#include "03/unk_021d7000.h"
#include "gx_load2d.h"
#include "03/code_021c9cf4.h"
#include "03/code_021cb000.h"
#include "03/code_021d2940.h"
#include "03/code_021c2938.h"
#include "03/code_021c97c0.h"
#include "03/code_021cd000.h"
#include "code_0212df7c.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d1fd0.h"
#include "03/code_021d254c.h"
#include "os_thread.h"

u32 ExchangeEntryPAD_DetectFold(void) {
    if ((*(vu16 *) 0x027fffa8 & 0x8000) >> 15) {
        return 1;
    }
    return 0;
}

void SetupExchangeEntry(void) {
    *(u8 *) &gExchangeEntryShowNext = 0;
    LoadExchangeEntryFileAndSetBgCnt();
    LoadHlSetScr();
    PrintMessage(0x6a);
    CreateAnimatedIcon(1);
    SetUpdateFunction(StartExchangeEntryFadeIn);
}

void LoadExchangeEntryFileAndSetBgCnt(void) {
    void *xb4MultiNscName = &gXb4MultiNscName3;
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

void StartExchangeEntryFadeIn(void) {
    StartBlendBrightnessFade(2, 0, 0x15, 8);
    CombineDispcntBits(0, 0x15);
    SetUpdateFunction(UpdateExchangeEntryFadeIn);
}

void UpdateExchangeEntryFadeIn(void) {
    int fadeSlotBusy;
    fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(0);
    if (fadeSlotBusy == 0) {
        CreateSlideButtonsForMenuPair(1);
        SetUpdateFunction(UpdateExchangeEntryButtonsIn);
    }
}

void UpdateExchangeEntryButtonsIn(void) {
    int buttonResult;
    buttonResult = GetButtonResult();
    if (buttonResult != -2) {
        EnableButtonTouch();
        SetUpdateFunction(UpdateExchangeEntry);
    }
}

void UpdateExchangeEntry(void) {
    OS_Sleep(0xa);
    UpdateExchangeEntryOutcome();
    UpdateExchangeEntryInput();
    UpdateExchangeEntryNop();
    UpdateExchangeEntryResult();
}

void UpdateExchangeEntryInput(void) {
    int v1;
    v1 = AreKeysPressed(2);
    if (v1 != 0) {
        SetButtonResultIfNone(0);
        return;
    }
    v1 = ExchangeEntryPAD_DetectFold();
    if (v1 != 0) {
        SetButtonResultIfNone(0);
    }
}

void UpdateExchangeEntryNop(void) {}

void UpdateExchangeEntryResult(void) {
    int buttonResult;
    buttonResult = GetButtonResult();
    if (buttonResult == 0) {
        StopSoundSeq();
        StartSoundSeq(7);
        SetUpdateFunction(StartExchangeEntryClose);
    }
}

void StartExchangeEntryClose(void) {
    DisableButtonTouch();
    StartBlendBrightnessFadeWait(8);
    SetUpdateFunction(UpdateExchangeEntryFadeOut);
}

void UpdateExchangeEntryFadeOut(void) {
    int fadeSlotBusy;
    fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(1);
    if (fadeSlotBusy == 0) {
        if (gExchangeEntryShowNext == 0) {
            StartSlideButtonsOut();
        }
        if (gExchangeEntryShowNext == 0) {
            StartBlendBrightnessFade(3, 1, 1, 8);
        }
        StartBlendBrightnessFade(3, 0, 0x15, 8);
        SetUpdateFunction(UpdateExchangeEntryRelease);
    }
}

void UpdateExchangeEntryRelease(void) {
    int v1;
    v1 = IsBlendBrightnessFadeSlotBusy(0);
    if ((v1 == 0) && (((gExchangeEntryShowNext != 0 || (v1 = IsBlendBrightnessFadeSlotBusy(1), v1 == 0)) &&
                       (v1 = IsSlideButtonsNotSlidingOut(), v1 != 0)))) {
        ReleaseAnimatedIcon();
        ReleaseBgTextCanvasOfScreen(0);
        if (gExchangeEntryShowNext == 0) {
            HideSubScreenMessage();
            ClearDispcntBits(1, 1);
        }
        ClearDispcntBits(0, 0x15);
        if (gExchangeEntryShowNext == 0) {
            StopExchangeWithStatusRecord();
            SetPrimaryMenuPair(2, 1);
            SetUpdateFunction(SetupWay);
            return;
        }
        SetPrimaryMenuPair(0, 0);
        SetUpdateFunction(SetupExchangeKey);
    }
}

void UpdateExchangeEntryOutcome(void) {
    switch (GetExchangeOutcome()) {
        case 2:
            gExchangeEntryShowNext = 1;
            SetUpdateFunction(StartExchangeEntryClose);
            break;
        case 4:
            gExchangeEntryShowNext = 0;
            StopSoundSeq();
            StartSoundSeq(9);
            CreateMessageBox(0x41, 1, 1, -1, 0);
            DisableButtonTouch();
            SetUpdateFunction(UpdateExchangeEntryMessageResult);
            break;
    }
}
