#include "03/code_021c50f8.h"

#include "03/code_021c5000.h"
#include "03/code_021c5528.h"
#include "03/code_021cb4d0.h"
#include "03/code_021cd000.h"
#include "03/code_021be000.h"
#include "03/code_021bf000.h"
#include "03/code_021bf410.h"
#include "03/code_021b94b8.h"
#include "03/code_021c1f34.h"
#include "03/code_021cef90.h"
#include "03/code_021d1dd0.h"
#include "03/unk_021da000.h"
#include "03/code_021bf098.h"
#include "03/code_021c209c.h"
#include "03/code_021c6000.h"
#include "03/code_021c5724.h"
#include "03/code_021cca74.h"
#include "03/code_021ce000.h"
#include "03/code_021d1000.h"
#include "03/unk_021d7000.h"
#include "code_0214b824.h"
#include "03/code_021c5548.h"
#include "03/code_021cb000.h"
#include "03/code_021d1f70.h"
#include "03/code_021d3000.h"
#include "03/code_021d2940.h"
#include "03/code_021c53b4.h"
#include "03/code_021cdbd0.h"
#include "03/code_021cea3c.h"
#include "03/code_021d1fd0.h"
#include "03/code_021d254c.h"
#include "03/code_021d3488.h"
#include "03/code_021c2000.h"
#include "03/code_021bf4dc.h"
#include "03/code_021d1440.h"
#include "03/unk_021d5000.h"
#include "03/code_021cd2e0.h"
#include "03/code_021bf810.h"
#include "03/code_021be610.h"
#include "code_0212df7c.h"
#include "registers.h"

void SetupValueRecords(void) {
    gValueRecordsFrames = 0;
    LoadValueRecordsFilesAndSetBgCnt();
    LoadHlSetScr();
    ShowSubScreenMessage(0x82, -1, 0);
    CreateObjectsForMenuPair(2);
    PrintMessage(0x67);
    CreateAnimatedIcon(0);
    InitValueRecordsRequest();
    StartSoundSeq(0xb);
    SetUpdateFunction(StartValueRecordsFadeIn);
}

void LoadValueRecordsFilesAndSetBgCnt(void) {
    LoadFileToVram(gJbBgStep3NcgName, GX_LoadBG2Char);
    LoadFileToVram(gYbBgStep3NclName, GX_LoadBGPltt);
    LoadFileToVram(gXb4MultiNscName, GX_LoadBG2Scr);
    reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & ~3) | 3;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & ~3) | 3;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~3) | 3;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & ~3) | 3;
    reg_G2_BG2CNT = (reg_G2_BG2CNT & ~3) | 3;
}

void StartValueRecordsFadeIn(void) {
    StartBlendBrightnessFade(2, 1, 1, 8);
    StartBlendBrightnessFade(2, 0, 0x15, 8);
    CombineDispcntBits(1, 1);
    CombineDispcntBits(0, 0x15);
    SetUpdateFunction(UpdateValueRecordsFadeIn);
}

void UpdateValueRecordsFadeIn(void) {
    if (IsBlendBrightnessFadeSlotBusy(1) == 0 && IsBlendBrightnessFadeSlotBusy(0) == 0) {
        CreateSlideButtonsForMenuPair(1);
        SetUpdateFunction(UpdateValueRecordsButtonsIn);
    }
}

void UpdateValueRecordsButtonsIn(void) {
    if (GetButtonResult() != -2) {
        gValueRecordsRequestTask = AddTask(1, UpdateValueRecordsDuringRequest, NULL, 0x78);
        SetUpdateFunction(UpdateValueRecords);
    }
}

void UpdateValueRecords(void) {
    int requestStatus;
    UpdateValueRecordsInput();
    UpdateValueRecordsNop();
    UpdateValueRecordsResult();
    requestStatus = RunValueRecordsRequestForStatus();
    switch (requestStatus) {
        case 0:
            break;
        case 1:
            gValueRecordsShowNext = 1;
            RemoveTaskEntryWrapper(1, gValueRecordsRequestTask);
            gValueRecordsRequestTask = 0;
            SetUpdateFunction(UpdateValueRecordsFrames);
            break;
        case 2:
            StopSoundSeq();
            func_ov003_021cefc0(0x40, 1, 1, -1, 0);
            StartSoundSeq(9);
            DisableButtonTouch();
            RemoveTaskEntryWrapper(1, gValueRecordsRequestTask);
            gValueRecordsRequestTask = 0;
            SetUpdateFunction(UpdateValueRecordsMessageResult);
            break;
    }
}

void UpdateValueRecordsInput(void) {
    int v1;
    v1 = AreKeysDown(2);
    if (v1 != 0) {
        SetButtonResultIfNone((u8) 0);
        return;
    }
    v1 = ValueRecordsPAD_DetectFold();
    if (v1 != 0) {
        SetButtonResultIfNone((u8) 0);
    }
}

void UpdateValueRecordsNop(void) {}

void UpdateValueRecordsResult(void) {
    int buttonResult;
    buttonResult = GetButtonResult();
    if (buttonResult == 0) {
        DisableButtonTouch();
        SetUpdateFunction(StartValueRecordsCloseWithoutNext);
    }
}

void StartValueRecordsClose(void) {
    DisableButtonTouch();
    if (gValueRecordsRequestTask != 0) {
        RemoveTaskEntryWrapper(1, gValueRecordsRequestTask);
    }
    StartBlendBrightnessFadeWait(8);
    SetUpdateFunction(UpdateValueRecordsFadeOut);
}

void UpdateValueRecordsFadeOut(void) {
    int fadeSlotBusy;
    fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(1);
    if (fadeSlotBusy == 0) {
        StartSlideButtonsOut();
        if (gValueRecordsShowNext == 0) {
            StartBlendBrightnessFade(3, 1, 1, 8);
        }
        StartBlendBrightnessFade(3, 0, 0x15, 8);
        SetUpdateFunction(UpdateValueRecordsRelease);
    }
}

void UpdateValueRecordsRelease(void) {
    int v1;
    v1 = IsBlendBrightnessFadeSlotBusy(0);
    if ((v1 == 0) && (((gValueRecordsShowNext != 0 || (v1 = IsBlendBrightnessFadeSlotBusy(1), v1 == 0)) &&
                       (v1 = IsSlideButtonsNotSlidingOut(), v1 != 0)))) {
        ReleaseValueRecordsRequest((gValueRecordsShowNext != 0));
        ReleaseAnimatedIcon();
        ReleaseBgTextCanvasOfScreen(0);
        if (gValueRecordsShowNext == 0) {
            HideSubScreenMessage();
            ClearDispcntBits(1, 1);
        }
        ClearDispcntBits(0, 0x15);
        if (gValueRecordsShowNext == 0) {
            SetPrimaryMenuPair(2, 1);
            SetUpdateFunction(SetupWay);
            return;
        }
        SetPrimaryMenuPair(0, 0);
        SetUpdateFunction(SetupValueRecordsNext);
    }
}

void UpdateValueRecordsDuringRequest(void) {
    UpdateKeyTouchInput();
    RunTasksAndRemoveRequested(0);
    UpdateValueRecordsInput();
    UpdateValueRecordsResult();
}

void UpdateValueRecordsMessageResult(void) {
    int messageAnswer;
    messageAnswer = func_ov003_021cef80();
    if (messageAnswer == 0) {
        StartSoundSeq(6);
        func_ov003_021cef90();
        SetUpdateFunction(UpdateValueRecordsMessageClose);
    }
}

void UpdateValueRecordsMessageClose(void) {
    int messageOpen;
    messageOpen = func_ov003_021cef6c();
    if (messageOpen == 0) {
        SetUpdateFunction(StartValueRecordsClose);
    }
}

void UpdateValueRecordsFrames(void) {
    UpdateValueRecordsInput();
    UpdateValueRecordsNop();
    UpdateValueRecordsResult();
    gValueRecordsFrames = gValueRecordsFrames + 1;
    if (gValueRecordsFrames >= 0x438) {
        StopSoundSeq();
        SetUpdateFunction(StartValueRecordsClose);
    }
}

void StartValueRecordsCloseWithoutNext(void) {
    StopSoundSeq();
    StartSoundSeq(7);
    *(u8 *) &gValueRecordsShowNext = 0;
    SetUpdateFunction(StartValueRecordsClose);
}
