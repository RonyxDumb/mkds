#include "03/Menu/connect_done.h"
#include "03/Menu/menu_pair_loading.h"
#include "03/Menu/jb2_menu.h"
#include "03/Menu/jb3_list.h"
#include "03/Menu/connect.h"
#include "03/Menu/sub_screen_message.h"
#include "03/Sound/sound_seq.h"
#include "03/Menu/menu_pair_objects_slide_out.h"
#include "03/Menu/message_box_create.h"
#include "03/Graphics/blend_brightness_fade_start.h"
#include "03/Menu/wifi_menu_strings.h"
#include "vram_load_2d_graphics.h"

#include "03/Menu/wifi_menu_shared.h"
#include "03/System/application.h"
#include "03/Menu/main_menu_fade_out.h"
#include "03/Graphics/text_canvas.h"
#include "03/Graphics/dispcnt_window.h"
#include "03/Graphics/blend_brightness_fade_slots.h"
#include "03/Menu/message_box.h"

u8 gXb4MultiNscName9[19] = {0x63, 0x68, 0x61, 0x72, 0x2f, 0x78, 0x62, 0x34, 0x4d, 0x75,
                            0x6c, 0x74, 0x69, 0x2e, 0x6e, 0x73, 0x63, 0x2e, 0x6c};
u8 gConnectDoneFrames;

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
    gConnectDoneFrames = 0;
    LoadConnectDoneFileAndSetBgCnt();
    PrintMessage(0x77);
    SetUpdateFunction(StartConnectDoneFadeIn);
}

void LoadConnectDoneFileAndSetBgCnt(void) {
    void *nscName = &gXb4MultiNscName9;
    void *loadBg2ScrFunc = &TEQSub_Fn10Impl_Fn12Impl;
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
    int queryResult;
    int secondaryPairSecond[1];
    queryResult = IsBlendBrightnessFadeSlotBusy(1);
    if (((queryResult == 0) && (queryResult = IsBlendBrightnessFadeSlotBusy(0), queryResult == 0)) &&
        (queryResult = IsMenuPairObjectsNotSlidingOut(), queryResult != 0)) {
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
    gConnectDoneFrames++;
    if (gConnectDoneFrames >= 0xb4) {
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
