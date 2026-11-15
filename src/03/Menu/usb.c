#include "03/Menu/usb.h"
#include "registers.h"
#include "03/Menu/usb_fold_detect.h"
#include "03/Menu/message_box_create.h"
#include "03/Graphics/blend_brightness_fade_start.h"
#include "03/Menu/wifi_menu_shared.h"
#include "03/System/task_input.h"
#include "03/Menu/wifi_menu_strings.h"
#include "vram_load_2d_graphics.h"
#include "03/Menu/message_box.h"
#include "03/System/application.h"
#include "sound_archive_load_result.h"
#include "03/Sound/sound_seq.h"
#include "03/Menu/slide_buttons.h"
#include "03/Menu/sub_screen_message.h"
#include "03/Menu/way_ap_setup.h"
#include "03/Menu/xb3_multi.h"
#include "03/Menu/usb_next.h"
#include "03/Net/usb_scan.h"
#include "03/Graphics/blend_brightness_fade_slots.h"
#include "03/Graphics/text_canvas.h"
#include "03/Graphics/dispcnt_window.h"
#include "03/Net/exchange_wcm_state.h"
#include "03/Menu/menu_pair_loading.h"
#include "03/System/dwc_archive.h"
#include "03/Graphics/hl_scr.h"
#include "reset_interrupts_halt.h"
#include "cpu_copy_clear_16.h"

u8 gUsbExitKind;

BOOL UsbPAD_DetectFold(void) {
    s32 flags = (*HW_BUTTON_XY_BUF & PAD_DETECT_FOLD_MASK) >> 15;
    if (flags != 0) {
        return 1;
    }
    return 0;
}

void SetupUsb(void) {
    u16 ownerText[12];
    OwnerInfo ownerInfo;
    gUsbExitKind = 0;
    LoadUsbFilesAndSetBgCnt();
    LoadHlScr(8);
    CreateObjectsForMenuPair(2);
    OS_GetOwnerInfo(&ownerInfo);
    ownerText[0] = 0;
    MIi_CpuClear16(ownerText[0], &ownerText[1], 0x16);
    MIi_CpuCopy16(ownerInfo.mNickName, &ownerText[1], ownerInfo.mNickNameLength * 2);
    PrintMessageAndText(&ownerText[1], 0x6d);
    CreateAnimatedIcon(0);
    InitUsbScan(UsbEventCallback);
    StartSoundSeq(0xb);
    SetUpdateFunction(StartUsbFadeIn);
}

void LoadUsbFilesAndSetBgCnt(void) {
    void *ncgName = &"char/jbBgStep3.ncg.l";
    void *loadBg2CharFunc = &GX_LoadBG2Char;
    u32 bg2CharLoadResult = LoadFileToVram(ncgName, loadBg2CharFunc);
    void *nclName = &"char/ybBgStep3.ncl.l";
    void *loadBgPlttFunc = &GX_LoadBGPltt;
    u32 bgPlttLoadResult = LoadFileToVram(nclName, loadBgPlttFunc);
    void *nscName = &"char/jb4Usb.nsc.l";
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

void StartUsbFadeIn(void) {
    StartBlendBrightnessFade(2, 0, 0x15, 8);
    CombineDispcntBits(0, 0x15);
    SetUpdateFunction(UpdateUsbFadeIn);
}

void UpdateUsbFadeIn(void) {
    int fadeSlotBusy;
    fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(0);
    if (fadeSlotBusy == 0) {
        CreateSlideButtonsForMenuPair(2);
        SetUpdateFunction(UpdateUsbButtonsIn);
    }
}

void UpdateUsbButtonsIn(void) {
    if (GetButtonResult() != -2) {
        EnableButtonTouch();
        SetUpdateFunction(UpdateUsb);
    }
}

void UpdateUsb(void) {
    UpdateUsbInput();
    UpdateUsbNop();
    UpdateUsbResult();
}

void UpdateUsbInput(void) {
    int queryResult;
    queryResult = AreKeysPressed(2);
    if (queryResult != 0) {
        SetButtonResultIfNone(0);
        return;
    }
    queryResult = UsbPAD_DetectFold();
    if (queryResult != 0) {
        SetButtonResultIfNone(0);
    }
}

void UpdateUsbNop(void) {}

void UpdateUsbResult(void) {
    int buttonResult;
    if ((gUsbExitKind == 0) && (buttonResult = GetButtonResult(), buttonResult == 0)) {
        gUsbExitKind = 2;
        StopSoundSeq();
        StartSoundSeq(7);
        SetUpdateFunction(StartUsbClose);
    }
}

void StartUsbClose(void) {
    DisableButtonTouch();
    StartBlendBrightnessFadeWait(8);
    SetUpdateFunction(UpdateUsbFadeOut);
}

void UpdateUsbFadeOut(void) {
    if (IsBlendBrightnessFadeSlotBusy(1) == 0) {
        StartSlideButtonsOut();
        if ((u8) (gUsbExitKind + 0xfe) <= 1) {
            StartBlendBrightnessFade(3, 1, 1, 8);
        }
        StartBlendBrightnessFade(3, 0, 0x15, 8);
        SetUpdateFunction(UpdateUsbRelease);
    }
}

void UpdateUsbRelease(void) {
    if (IsBlendBrightnessFadeSlotBusy(0) == 0 && (gUsbExitKind != 2 || IsBlendBrightnessFadeSlotBusy(1) == 0) &&
        IsSlideButtonsNotSlidingOut() != 0) {
        ReleaseUsbScan();
        ReleaseAnimatedIcon();
        ReleaseBgTextCanvasOfScreen(0);
        if (gUsbExitKind == 2 || gUsbExitKind == 3) {
            HideSubScreenMessage();
            ClearDispcntBits(1, 1);
        }
        ClearDispcntBits(0, 0x15);
        if (gUsbExitKind == 2) {
            SetPrimaryMenuPair(2, 1);
            SetUpdateFunction(CreateAp);
        } else if (gUsbExitKind == 3) {
            SetPrimaryMenuPair(2, 1);
            SetUpdateFunction(SetupXb3Multi);
        } else {
            SetPrimaryMenuPair(0, 0);
            SetUpdateFunction(SetupUsbNext);
        }
    }
}

void UsbEventCallback(u32 eventCode) {
    if (gUsbExitKind == 0) {
        switch (eventCode) {
            case USB_SCAN_RESULT_NONE:
                gUsbExitKind = 3;
                StopSoundSeq();
                StartSoundSeq(0x12);
                CreateMessageBox(0x45, 1, 1, -1, 0);
                DisableButtonTouch();
                SetUpdateFunction(UpdateUsbMessageResult);
                break;
            case USB_SCAN_RESULT_FLAGGED:
                gUsbExitKind = 1;
                StopSoundSeq();
                SetUpdateFunction(StartUsbClose);
                break;
            case USB_SCAN_RESULT_MIXED:
                StopSoundSeq();
                SetUsbScanCallback(0);
                CreateMessageBox(0x47, 0, 1, -1, 0);
                DisableButtonTouch();
                SetUpdateFunction(UpdateUsbChoiceMessageResult);
                break;
            case USB_SCAN_RESULT_NEVER_REPORTED:
                gUsbExitKind = 2;
                StopSoundSeq();
                StartSoundSeq(9);
                SetUpdateFunction(StartUsbClose);
                break;
        }
    }
}

void UpdateUsbMessageResult(void) {
    int messageAnswer;
    messageAnswer = GetMessageBoxResult();
    if (messageAnswer == 0) {
        StartSoundSeq(6);
        CloseMessageBox();
        SetUpdateFunction(UpdateUsbMessageClose);
    }
}

void UpdateUsbMessageClose(void) {
    int messageOpen;
    messageOpen = IsMessageBoxOpen();
    if (messageOpen == 0) {
        SetUpdateFunction(StartUsbClose);
    }
}

void UpdateUsbChoiceMessageResult(void) {
    switch (GetMessageBoxResult()) {
        case 1:
            gUsbExitKind = 3;
            StartSoundSeq(6);
            break;
        case 0:
            gUsbExitKind = 1;
            StartSoundSeq(7);
            break;
        default:
            return;
    }
    CloseMessageBox();
    SetUpdateFunction(UpdateUsbChoiceMessageClose);
}

void UpdateUsbChoiceMessageClose(void) {
    int messageOpen;
    messageOpen = IsMessageBoxOpen();
    if (messageOpen == 0) {
        if (gUsbExitKind == 1) {
            SetUpdateFunction(StartUsbClose);
            return;
        }
        StartSoundSeq(0xb);
        EnableButtonTouch();
        gUsbExitKind = 0;
        SetUsbScanCallback(UsbEventCallback);
        SetUpdateFunction(UpdateUsb);
    }
}
