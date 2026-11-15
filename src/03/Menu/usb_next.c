#include "03/Menu/usb_next.h"
#include "03/Menu/menu_pair_loading.h"
#include "03/Graphics/hl_scr.h"
#include "03/Menu/connect_message_setup.h"
#include "03/Menu/sub_screen_message.h"
#include "03/Sound/sound_seq.h"
#include "03/Menu/slide_buttons.h"
#include "03/Graphics/blend_brightness_fade_start.h"
#include "03/Menu/wifi_menu_strings.h"
#include "vram_load_2d_graphics.h"

#include "03/System/application.h"
#include "03/Menu/wifi_menu_shared.h"
#include "03/Graphics/text_canvas.h"
#include "03/Graphics/dispcnt_window.h"
#include "03/Graphics/blend_brightness_fade_slots.h"

u8 gXb4MultiNscName10[19] = {0x63, 0x68, 0x61, 0x72, 0x2f, 0x78, 0x62, 0x34, 0x4d, 0x75,
                             0x6c, 0x74, 0x69, 0x2e, 0x6e, 0x73, 0x63, 0x2e, 0x6c};
u8 gUsbNextFrames;

void SetupUsbNext(void) {
    gUsbNextFrames = 0;
    LoadUsbNextFileAndSetBgCnt();
    LoadHlScr(8);
    PrintMessage(0x6f);
    StartSoundSeq(0x10);
    SetUpdateFunction(StartUsbNextFadeIn);
}

void LoadUsbNextFileAndSetBgCnt(void) {
    void *nscName = &gXb4MultiNscName10;
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

void StartUsbNextFadeIn(void) {
    StartBlendBrightnessFade(2, 0, 0x15, 8);
    CombineDispcntBits(0, 0x15);
    SetUpdateFunction(UpdateUsbNextFadeIn);
}

void UpdateUsbNextFadeIn(void) {
    if (IsBlendBrightnessFadeSlotBusy(0) == 0) {
        SetUpdateFunction(UpdateUsbNext);
    }
}

void UpdateUsbNext(void) {
    UpdateUsbNextFrames();
    UpdateUsbNextNop();
}

void UpdateUsbNextNop(void) {}

void StartUsbNextFadeOut(void) {
    StartBlendBrightnessFade(3, 1, 1, 8);
    StartBlendBrightnessFade(3, 0, 0x15, 8);
    SetUpdateFunction(UpdateUsbNextRelease);
}

void UpdateUsbNextRelease(void) {
    int fadeSlotBusy;
    fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(1);
    if ((fadeSlotBusy == 0) && (fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(0), fadeSlotBusy == 0)) {
        ReleaseBgTextCanvasOfScreen(0);
        HideSubScreenMessage();
        ClearDispcntBits(1, 1);
        ClearDispcntBits(0, 0x15);
        SetPrimaryMenuPair(0, 0);
        SetSecondaryMenuPair(0, 2);
        SetUpdateFunction(SetupConnectMessage);
    }
}

void UpdateUsbNextFrames(void) {
    gUsbNextFrames++;
    if (gUsbNextFrames >= 120) {
        SetUpdateFunction(StartUsbNextFadeOut);
    }
}
