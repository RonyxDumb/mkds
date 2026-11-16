#include "03/Menu/ap_scan_screen.h"
#include "03/Menu/ap_list.h"
#include "03/Menu/ap_screen.h"
#include "03/Menu/way_select.h"
#include "03/Net/essid_packet_steps.h"
#include "03/Net/ap_entries.h"
#include "03/Menu/message_box_create.h"
#include "03/Graphics/blend_brightness_fade_start.h"
#include "03/Graphics/blend_brightness_fade_slots.h"
#include "03/Menu/wifi_menu_shared.h"
#include "03/System/task_input.h"
#include "03/Menu/wifi_menu_strings.h"
#include "vram_load_2d_graphics.h"
#include "03/Menu/wifi_menu_tables.h"

#include "03/Menu/message_box.h"
#include "03/Graphics/text_canvas.h"
#include "03/Graphics/dispcnt_window.h"
#include "03/Menu/slide_buttons.h"
#include "03/System/application.h"
#include "03/Net/ap_scan.h"
#include "03/Sound/sound_seq.h"
#include "03/Menu/menu_pair_loading.h"
#include "03/Menu/sub_screen_message.h"
#include "03/Graphics/hl_scr.h"
#include "03/Net/exchange_wcm_state.h"

u8 gApScanKind;
u16 gApScanFrames;

void SetupApScan(void) {
    gApScanFrames = 0;
    gApScanKind = 0;
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
    void *ncgName = &"char/jbBgStep3.ncg.l";
    void *loadBg2CharFunc = &CopyBgData_Bg2_Top;
    u32 bg2CharLoadResult = LoadFileToVram(ncgName, loadBg2CharFunc);
    void *nclName = &"char/ybBgStep3.ncl.l";
    void *loadBgPlttFunc = &CopyPaletteTop;
    u32 bgPlttLoadResult = LoadFileToVram(nclName, loadBgPlttFunc);
    void *nscName = &"char/xb4Multi.nsc.l";
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
    ApScanEntry *entries;
    int entryIndex;
    gApScanFrames++;
    if (gApScanFrames >= 0x12c) {
        StopSoundSeq();
        entryCount = CountApScanEntries(&entries);
        if (entryCount == 0) {
            gApScanKind = 2;
            CreateMessageBox(0x43, 1, 1, -1, 0);
            StartSoundSeq(0x12);
            DisableButtonTouch();
            SetUpdateFunction(UpdateApScanMessageResult);
            return;
        }
        for (entryIndex = 0; entryIndex < entryCount; entryIndex++) {
            if (entries[entryIndex].mCapaLevel != AP_CAPA_LEVEL_SECURITY_ELEMENT) {
                break;
            }
        }
        if (entryIndex == entryCount) {
            gApScanKind = 3;
            CreateMessageBox(0x42, 1, 1, -1, 0);
            StartSoundSeq(0x12);
            DisableButtonTouch();
            SetUpdateFunction(UpdateApScanMessageResult);
        } else {
            gApScanKind = 1;
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
        SetButtonResultIfNone(0);
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
    int queryResult;
    queryResult = IsBlendBrightnessFadeSlotBusy(1);
    if (((queryResult == 0) && (queryResult = IsBlendBrightnessFadeSlotBusy(0), queryResult == 0)) &&
        (queryResult = IsSlideButtonsNotSlidingOut(), queryResult != 0)) {
        do {
            queryResult = StopApScan();
        } while (queryResult == 0);
        ReleaseAnimatedIcon();
        ReleaseBgTextCanvasOfScreen(0);
        HideSubScreenMessage();
        ClearDispcntBits(1, 1);
        ClearDispcntBits(0, 0x15);
        if (gApScanKind != 1) {
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
