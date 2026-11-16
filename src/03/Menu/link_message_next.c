#include "03/Menu/link_message_next.h"
#include "03/Menu/menu_pair_loading.h"
#include "03/Menu/link_level.h"
#include "03/Menu/link_message_fade_in.h"
#include "03/Sound/sound_seq.h"
#include "03/Graphics/blend_brightness_fade_start.h"
#include "03/Graphics/blend_brightness_fade_slots.h"
#include "03/Graphics/dispcnt_window.h"
#include "03/System/task_input.h"
#include "03/Menu/wifi_menu_strings.h"
#include "reset_interrupts_halt.h"
#include "vram_load_2d_graphics.h"
#include "power_management_commands.h"

u8 gLinkMessageNextYb5MultiNscName[19] = {0x63, 0x68, 0x61, 0x72, 0x2f, 0x79, 0x62, 0x35, 0x4d, 0x75,
                            0x6c, 0x74, 0x69, 0x2e, 0x6e, 0x73, 0x63, 0x2e, 0x6c};

void UpdateLinkMessageNextInput(void) {
    int allKeysPressed;
    allKeysPressed = AreKeysPressed(1);
    if (allKeysPressed != 0) {
        SetButtonResultIfNone(0);
    }
}

void UpdateLinkMessageNextNop(void) {}

void UpdateLinkMessageNextResult(void) {
    int buttonResult;
    buttonResult = GetButtonResult();
    if (buttonResult == 0) {
        StartSoundSeq(6);
        SetUpdateFunction(StartLinkMessageNextClose);
    }
}

void StartLinkMessageNextClose(void) {
    DisableButtonTouch();
    StartBlendBrightnessFadeWait(8);
    SetUpdateFunction(UpdateLinkMessageNextFadeOut);
}

void UpdateLinkMessageNextFadeOut(void) {
    int fadeSlotBusy;
    fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(1);
    if (fadeSlotBusy == 0) {
        StartBlendBrightnessFade(3, 1, 0x3f, 0x40);
        StartBlendBrightnessFade(3, 0, 0x3f, 0x40);
        SetUpdateFunction(UpdateLinkMessageNextPowerOff);
    }
}

void UpdateLinkMessageNextPowerOff(void) {
    int fadeSlotBusy;
    fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(1);
    if ((fadeSlotBusy == 0) && (fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(0), fadeSlotBusy == 0)) {
        OS_SpinWait((0x01000000u));
        PM_ForceToPowerOff();
    }
}

void SetupLinkMessage(void) {
    LoadLinkMessageFileAndSetBgCnt();
    PrintMessage(0x60);
    CreateAnimatedIcon(0);
    CreateLinkLevel(1);
    StartSoundSeq(0xb);
    SetUpdateFunction(StartLinkMessageFadeIn);
}

void LoadLinkMessageFileAndSetBgCnt(void) {
    void *nscName = &gLinkMessageNextYb5MultiNscName;
    void *loadBg2ScrFunc = &GX_LoadBG2Scr;
    u32 loadFileResult = LoadFileToVram(nscName, loadBg2ScrFunc);
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

void StartLinkMessageFadeIn(void) {
    StartBlendBrightnessFade(2, 0, 0x15, 8);
    CombineDispcntBits(0, 0x15);
    SetUpdateFunction(UpdateLinkMessageFadeIn);
}
