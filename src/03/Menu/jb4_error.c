#include "03/Menu/jb4_error.h"
#include "03/code_021c7cb0.h"
#include "03/Menu/menu_pair_loading.h"
#include "03/System/application.h"
#include "03/unk_021d7000.h"
#include "gx_load2d.h"
#include "03/code_021bf000.h"
#include "03/Menu/sub_screen_message.h"
#include "03/code_021c2000.h"
#include "03/Menu/jb3_list.h"
#include "03/code_021c9000.h"
#include "03/code_021cb000.h"
#include "03/code_021cb11c.h"
#include "03/code_021cd000.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d1000.h"
#include "03/code_021d1dd0.h"
#include "03/code_021d1f70.h"
#include "03/unk_021da000.h"
#include "03/System/task_input.h"
#include "03/code_021ce000.h"
#include "03/code_021c7000.h"
#include "03/Graphics/text_canvas.h"
#include "03/unk_021d5000.h"
#include "03/code_021c2530.h"
#include "code_0213c9f8.h"
#include "03/Graphics/dispcnt_window.h"
#include "03/Menu/slide_buttons.h"
#include "03/Menu/main_menu.h"

const u8 gJb4ErrorFontIndices[6] = {0, 1, 1, 1, 1, 1};
const u16 gJb4ErrorMessageRect[4] = {0xd, 0x3c, 0xe6, 0x5e};
const u16 gJb4ErrorCodePositions[12] = {0x62, 0x22, 0x62, 0x22, 0x3d, 0x22, 0x65, 0x22, 0x6c, 0x22, 0x34, 0x22};
u16 gDecimalFormat[3] = {0x25, 0x64, 0};
u8 gJb4ErrorCode[1];

void SetupJb4Error(void) {
    LoadJb4ErrorFileAndSetBgCnt();
    PrintJb4Error();
    SetUpdateFunction(StartJb4ErrorFadeIn);
}

void LoadJb4ErrorFileAndSetBgCnt(void) {
    void *filePath = &"char/jb4Error.nsc.l";
    void *loadFunction = &GX_LoadBG2Scr;
    u32 fileToVram = LoadFileToVram(filePath, loadFunction);
    u32 subBg0CntAddress = 0x4001008u;
    u32 subBg0Cnt = (*(u16 *) ((subBg0CntAddress) + (0)));
    u32 subBg0CntCleared = ((subBg0Cnt) & ~(0x3u));
    u32 subBg0CntSet = ((subBg0CntCleared) | (0x3u));
    u32 subBg1CntAddress;
    u32 subBg1Cnt;
    u32 subBg1CntCleared;
    u32 subBg1CntSet;
    u32 mainBg0CntAddress;
    u32 mainBg0Cnt;
    u32 mainBg0CntCleared;
    u32 mainBg0CntSet;
    u32 mainBg1CntAddress;
    u32 mainBg1Cnt;
    u32 mainBg1CntCleared;
    u32 mainBg1CntSet;
    u32 mainBg2CntAddress;
    u32 mainBg2Cnt;
    u32 mainBg2CntCleared;
    u32 mainBg2CntSet;
    *(u16 *) ((subBg0CntAddress) + (0)) = subBg0CntSet;
    subBg1CntAddress = 0x400100au;
    subBg1Cnt = (*(u16 *) ((subBg1CntAddress) + (0)));
    subBg1CntCleared = ((subBg1Cnt) & ~(0x3u));
    subBg1CntSet = ((subBg1CntCleared) | (0x3u));
    *(u16 *) ((subBg1CntAddress) + (0)) = subBg1CntSet;
    mainBg0CntAddress = 0x4000008u;
    mainBg0Cnt = (*(u16 *) ((mainBg0CntAddress) + (0)));
    mainBg0CntCleared = ((mainBg0Cnt) & ~(0x3u));
    mainBg0CntSet = ((mainBg0CntCleared) | (0x3u));
    *(u16 *) ((mainBg0CntAddress) + (0)) = mainBg0CntSet;
    mainBg1CntAddress = 0x400000au;
    mainBg1Cnt = (*(u16 *) ((mainBg1CntAddress) + (0)));
    mainBg1CntCleared = ((mainBg1Cnt) & ~(0x3u));
    mainBg1CntSet = ((mainBg1CntCleared) | (0x3u));
    *(u16 *) ((mainBg1CntAddress) + (0)) = mainBg1CntSet;
    mainBg2CntAddress = 0x400000cu;
    mainBg2Cnt = (*(u16 *) ((mainBg2CntAddress) + (0)));
    mainBg2CntCleared = ((mainBg2Cnt) & ~(0x3u));
    mainBg2CntSet = ((mainBg2CntCleared) | (0x3u));
    *(u16 *) ((mainBg2CntAddress) + (0)) = mainBg2CntSet;
}

void PrintJb4Error(void) {
    s32 errorCode;
    s32 secondaryPairSecond;
    s32 messageIndex;
    void *canvas;
    void *messageEntry;
    u16 codeY;
    u16 codeX;
    u16 codeText[8];
    GetSecondaryMenuPair(NULL, &secondaryPairSecond);
    errorCode = *(s32 *) gJb4ErrorCode;
    if (errorCode >= -0x4e83) {
        messageIndex = 0x0;
    } else if (errorCode >= -0x4e84) {
        messageIndex = 0x15;
    } else if (errorCode >= -0x4e85) {
        messageIndex = 0x4a;
    } else if (errorCode >= -0x4e8b) {
        messageIndex = 0x15;
    } else if (errorCode >= -0x4e8c) {
        messageIndex = 0x49;
    } else if (errorCode >= -0x4e8d) {
        messageIndex = 0x15;
    } else if (errorCode >= -0x4e8e) {
        messageIndex = 0x18;
    } else if (errorCode >= -0x5207) {
        messageIndex = 0x15;
    } else if (errorCode >= -0x59d7) {
        messageIndex = 0x0;
    } else if (errorCode >= -0x5dbf) {
        messageIndex = 0x4a;
    } else if (errorCode >= -0xc34f) {
        messageIndex = 0x0;
    } else if (errorCode >= -0xc352) {
        messageIndex = 0x35;
    } else if (errorCode >= -0xc353) {
        messageIndex = 0x26;
    } else if (errorCode >= -0xc3b2) {
        messageIndex = 0x0;
    } else if (errorCode >= -0xc3b3) {
        if (secondaryPairSecond == 2) {
            messageIndex = 0x26;
        } else {
            messageIndex = 0x35;
        }
    } else if (errorCode >= -0xc79a) {
        messageIndex = 0x0;
    } else if (errorCode >= -0xc79b) {
        if (secondaryPairSecond == 2) {
            messageIndex = 0x26;
        } else {
            messageIndex = 0x36;
        }
    } else if (errorCode >= -0xc79e) {
        messageIndex = 0x37;
    } else if (errorCode >= -0xc79f) {
        messageIndex = 0x26;
    } else if (errorCode >= -0xc7ff) {
        messageIndex = 0x0;
    } else if (errorCode >= -0xc863) {
        messageIndex = 0x4c;
    } else if (errorCode >= -0xc866) {
        messageIndex = 0x4d;
    } else if (errorCode >= -0xc867) {
        messageIndex = 0x25;
    } else if (errorCode >= -0xcb1f) {
        messageIndex = 0x0;
    } else if (errorCode >= -0xcb22) {
        messageIndex = 0x38;
    } else if (errorCode >= -0xcb23) {
        messageIndex = 0x4e;
    } else if (errorCode >= -0xcb83) {
        messageIndex = 0x0;
    } else if (errorCode >= -0xcb87) {
        messageIndex = 0x3b;
    } else if (errorCode >= -0xcbe7) {
        messageIndex = 0x0;
    } else if (errorCode >= -0xcbeb) {
        messageIndex = 0x3b;
    } else if (errorCode >= -0xcc4b) {
        messageIndex = 0x0;
    } else if (errorCode >= -0xccaf) {
        messageIndex = 0x15;
    } else if (errorCode >= -0xcf07) {
        messageIndex = 0x0;
    } else if (errorCode >= -0xd033) {
        messageIndex = 0x15;
    } else {
        messageIndex = 0;
    }
    canvas = InitBgTextCanvas(0, gJb4ErrorFontIndices[GetLanguageIndex()]);
    messageEntry = GetMessageEntry(gMessages, messageIndex);
    swprintf(codeText, 8, gDecimalFormat, -*(s32 *) gJb4ErrorCode);
    codeY = (gJb4ErrorCodePositions + 1)[GetLanguageIndex() * 2];
    codeX = gJb4ErrorCodePositions[GetLanguageIndex() * 2];
    DrawCharsCentered(canvas, codeX, codeY, 2, 0xa, codeText, 0);
    DrawCanvasTextRect(canvas, gJb4ErrorMessageRect[0], gJb4ErrorMessageRect[1], gJb4ErrorMessageRect[2],
                       gJb4ErrorMessageRect[3], 2, GetLanguageTextFlags(), messageEntry);
    RequestBgTextCanvasUpload(canvas);
}

void StartJb4ErrorFadeIn(void) {
    StartBlendBrightnessFade(2, 0, 0x15, 8);
    CombineDispcntBits(0, 0x15);
    SetUpdateFunction(UpdateJb4ErrorFadeIn);
}

void UpdateJb4ErrorFadeIn(void) {
    int fadeSlotBusy;
    fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(1);
    if ((fadeSlotBusy == 0) && (fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(0), fadeSlotBusy == 0)) {
        CreateSlideButtonsForMenuPair(4);
        SetUpdateFunction(UpdateJb4ErrorButtonsIn);
    }
}

void UpdateJb4ErrorButtonsIn(void) {
    if (GetButtonResult() != -2) {
        EnableButtonTouch();
        SetUpdateFunction(UpdateJb4Error);
    }
}

void UpdateJb4Error(void) {
    UpdateJb4ErrorInput();
    UpdateJb4ErrorNop();
    UpdateJb4ErrorResult();
}

void UpdateJb4ErrorInput(void) {
    int keysPressed;
    keysPressed = AreKeysPressed(1);
    if (keysPressed != 0) {
        SetButtonResultIfNone((u8) 0);
    }
}

void UpdateJb4ErrorNop(void) {}

void UpdateJb4ErrorResult(void) {
    int buttonResult;
    buttonResult = GetButtonResult();
    if (buttonResult == 0) {
        StartSoundSeq(6);
        SetUpdateFunction(StartJb4ErrorClose);
    }
}

void StartJb4ErrorClose(void) {
    DisableButtonTouch();
    StartBlendBrightnessFadeWait(8);
    SetUpdateFunction(UpdateJb4ErrorFadeOut);
}

void UpdateJb4ErrorFadeOut(void) {
    int fadeSlotBusy;
    fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(1);
    if (fadeSlotBusy == 0) {
        StartSlideButtonsOut();
        StartBlendBrightnessFade(3, 1, 1, 8);
        StartBlendBrightnessFade(3, 0, 0x15, 8);
        SetUpdateFunction(UpdateJb4ErrorRelease);
    }
}

void UpdateJb4ErrorRelease(void) {
    int checkResult;
    int secondaryPair[1];
    checkResult = IsBlendBrightnessFadeSlotBusy(1);
    if (((checkResult == 0) && (checkResult = IsBlendBrightnessFadeSlotBusy(0), checkResult == 0)) &&
        (checkResult = IsSlideButtonsNotSlidingOut(), checkResult != 0)) {
        ReleaseBgTextCanvasOfScreen(0);
        HideSubScreenMessage();
        ClearDispcntBits(1, 1);
        ClearDispcntBits(0, 0x15);
        GetSecondaryMenuPair(NULL, secondaryPair);
        if (secondaryPair[0] != 0) {
            SetPrimaryMenuPair(2, 1);
            SetUpdateFunction(CreateAp);
            return;
        }
        SetPrimaryMenuPair(2, 0);
        SetSecondaryMenuPair(0, 0);
        SetJb3ListMode(0);
        SetUpdateFunction(CreateJb3List);
    }
}

void SetJb4ErrorCode(u32 errorCode) {
    *(u32 *) &gJb4ErrorCode = errorCode;
}
