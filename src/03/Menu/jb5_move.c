#include "03/Menu/jb5_move.h"
#include "03/Menu/opt_menu.h"
#include "03/Menu/child_wait_message.h"
#include "03/code_021c3000.h"
#include "03/Menu/link_message_next.h"
#include "03/code_021c4000.h"
#include "03/code_021bf000.h"
#include "03/Menu/message_box_create.h"
#include "03/code_021d1dd0.h"
#include "03/unk_021d7000.h"
#include "gx_load2d.h"

#include "03/Graphics/text_canvas.h"
#include "03/Graphics/dispcnt_window.h"
#include "03/System/application.h"
#include "03/Net/child_wait_session.h"
#include "03/Net/child_wait_session_object.h"
#include "03/code_021d1f70.h"
#include "03/unk_021da000.h"
#include "03/Menu/message_box.h"
#include "03/code_021d1000.h"
#include "03/code_021d3000.h"
#include "03/System/tasks.h"
#include "code_0212df7c.h"
#include "03/code_021cdbd0.h"
#include "03/code_021ce000.h"
#include "03/Menu/menu_pair_loading.h"
#include "03/unk_021d5000.h"
#include "03/Menu/sub_screen_message.h"
#include "code_0214cfe4.h"

const Rect gJb5MoveTextRect = {8, 0x35, 0xf8, 0x51};
u8 gJb5MoveNscName[18] = {0x63, 0x68, 0x61, 0x72, 0x2f, 0x6a, 0x62, 0x35, 0x4d,
                          0x6f, 0x76, 0x65, 0x2e, 0x6e, 0x73, 0x63, 0x2e, 0x6c};
u8 gJb5MoveShowNext;
u8 gJb5MoveChildWaitEvent;

void SetupJb5Move(void) {
    u8 *childUserBuffer;
    void *canvas;
    u16 childUserText[12];
    childUserBuffer = GetChildUserBuffer();
    canvas = InitBgTextCanvas(0, 0);
    gJb5MoveShowNext = 0;
    gJb5MoveChildWaitEvent = 0;
    LoadJb5MoveFileAndSetBgCnt();
    childUserText[0] = 0;
    MIi_CpuClear16(childUserText[0], &childUserText[1], 0x16);
    MIi_CpuCopy16(childUserBuffer + 2, &childUserText[1], childUserBuffer[1] * 2);
    DrawCanvasTextRect(canvas, gJb5MoveTextRect.mX, gJb5MoveTextRect.mY, gJb5MoveTextRect.mUnk_04 - gJb5MoveTextRect.mX,
                       gJb5MoveTextRect.mUnk_06 - gJb5MoveTextRect.mY, 2, 0x480, &childUserText[1]);
    RequestBgTextCanvasUpload(canvas);
    SetChildWaitCallback(Jb5MoveChildWaitCallback);
    SetUpdateFunction(StartJb5MoveFadeIn);
}

void LoadJb5MoveFileAndSetBgCnt(void) {
    void *jb5MoveNscName = &gJb5MoveNscName;
    void *loadBg2ScrFunc = &GX_LoadBG2Scr;
    u32 loadFileResult = LoadFileToVram(jb5MoveNscName, loadBg2ScrFunc);
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

void StartJb5MoveFadeIn(void) {
    StartBlendBrightnessFade(2, 0, 0x15, 8);
    CombineDispcntBits(0, 0x15);
    SetUpdateFunction(UpdateJb5MoveFadeIn);
}

void UpdateJb5MoveFadeIn(void) {
    int fadeSlotBusy;
    fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(0);
    if (fadeSlotBusy == 0) {
        CreateMessageBox(0x5f, 4, 0, 0xffffffff, 0);
        SetUpdateFunction(UpdateJb5MoveMessageIn);
    }
}

void UpdateJb5MoveMessageIn(void) {
    int messageAnswer;
    messageAnswer = GetMessageBoxResult();
    if (messageAnswer != -2) {
        SetUpdateFunction(UpdateJb5MoveMessage);
    }
}

void UpdateJb5MoveMessage(void) {
    UpdateJb5MoveMessageInputNop();
    UpdateJb5MoveMessageNop();
    switch (GetMessageBoxResult()) {
        case 0:
            gJb5MoveShowNext = 0;
            StartSoundSeq(7);
            break;
        case 1:
            gJb5MoveShowNext = 1;
            StartSoundSeq(0xe);
            break;
        default:
            return;
    }
    SetChildWaitCallback(NULL);
    CloseMessageBox();
    SetUpdateFunction(UpdateJb5MoveMessageClose);
}

void UpdateJb5MoveMessageInputNop(void) {}

void UpdateJb5MoveMessageNop(void) {}

void UpdateJb5MoveMessageClose(void) {
    int messageOpen;
    messageOpen = IsMessageBoxOpen();
    if (messageOpen == 0) {
        if ((*(u8 *) &gJb5MoveShowNext) == 0) {
            StartBlendBrightnessFade(3, 1, 1, 8);
        }
        StartBlendBrightnessFade(3, 0, 0x15, 8);
        SetUpdateFunction(UpdateJb5MoveFadeOut);
    }
}

void UpdateJb5MoveFadeOut(void) {
    if (IsBlendBrightnessFadeSlotBusy(1) == 0 && IsBlendBrightnessFadeSlotBusy(0) == 0) {
        if (gJb5MoveChildWaitEvent == 0 && gJb5MoveShowNext == 1) {
            ConfirmChildWaitUser();
        } else {
            StartChildWaitStop();
        }
        SetUpdateFunction(UpdateJb5MoveRelease);
    }
}

void UpdateJb5MoveRelease(void) {
    int childWaitReleased;
    if (((gJb5MoveChildWaitEvent == 0) && (gJb5MoveShowNext != 0)) ||
        (childWaitReleased = IsChildWaitSessionReleased(), childWaitReleased != 0)) {
        ReleaseBgTextCanvasOfScreen(0);
        ClearDispcntBits(0, 0x15);
        if (gJb5MoveShowNext == 0) {
            HideSubScreenMessage();
            ClearDispcntBits(1, 1);
        }
        SetPrimaryMenuPair(0, 1);
        if (gJb5MoveChildWaitEvent != 0) {
            SetUpdateFunction(SetupChildWaitMessage);
            return;
        }
        if (gJb5MoveShowNext == 0) {
            ClearDispcntBits(1, 1);
            SetUpdateFunction(SetupOptMenu);
            return;
        }
        SetUpdateFunction(SetupLinkMessage);
    }
}

void Jb5MoveChildWaitCallback(void) {
    gJb5MoveChildWaitEvent = 1;
}
