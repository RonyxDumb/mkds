#include "03/Menu/opt_menu.h"
#include "03/System/touch_key_input.h"

#include "03/Menu/menu_pair_loading.h"
#include "03/System/wifi_utility_archive.h"
#include "03/Graphics/blend_brightness_fade_start.h"
#include "03/Menu/wifi_menu_shared.h"
#include "03/Menu/slide_buttons.h"
#include "03/Menu/sub_screen_message.h"
#include "03/Menu/selection_objects.h"
#include "03/System/application.h"
#include "03/Menu/main_menu_load_files.h"
#include "03/Menu/jb2_menu.h"
#include "03/Menu/yb5_multi_update.h"
#include "03/Menu/jb5_info_setup.h"
#include "03/Menu/opt_menu_message.h"
#include "sound_archive_load_result.h"
#include "03/Sound/sound_seq.h"
#include "03/Graphics/blend_brightness_fade_slots.h"
#include "03/Graphics/dispcnt_window.h"
#include "03/Graphics/oam_buffer_entries.h"
#include "fixed_vector_math.h"
#include "wifi_settings_nvram_backup.h"
#include "03/System/task_input.h"
#include "03/Graphics/text_canvas.h"
#include "03/Graphics/hl_scr.h"
#include "03/Graphics/nce_file.h"
#include "arena_cache_init.h"
#include "vram_load_2d_graphics.h"
#include "cpu_copy_fill.h"
#include "03/Graphics/bg2_scr_buffer.h"
#include "03/Menu/menu_pair_objects.h"
#include "registers.h"

YbBgOption1NclName gYbBgOption1NclName = {{0x63, 0x68, 0x61, 0x72, 0x2f, 0x79, 0x62, 0x42, 0x67, 0x4f, 0x70, 0x74,
                                           0x69, 0x6f, 0x6e, 0x31, 0x2e, 0x6e, 0x63, 0x6c, 0x2e, 0x6c, 0}};
YbBgOptionNclName gYbBgOptionNclName = {{0x63, 0x68, 0x61, 0x72, 0x2f, 0x79, 0x62, 0x42, 0x67, 0x4f, 0x70,
                                         0x74, 0x69, 0x6f, 0x6e, 0x2e, 0x6e, 0x63, 0x6c, 0x2e, 0x6c, 0}};
const Rect gOptMenuSelectionRects[3] = {{6, 0x22, 0xea, 0x36}, {6, 0x4e, 0xea, 0x62}, {6, 0x7a, 0xea, 0x8e}};
const Rect gOptMenuRects[3] = {{8, 0x24, 0xf8, 0x44}, {8, 0x50, 0xf8, 0x70}, {8, 0x7c, 0xf8, 0x9c}};
const u16 gOptMenuOamEntryPosition[2] = {0xe0, 0x84};
const u8 gOptMenuPaletteRows[3] = {1, 2, 3};
u8 gOptMenuSelectedIndex;
u8 gOptMenuEntryChosen[4];
OamEntry *gOptMenuOamEntry;
void *gYbBgOption1Ncl;

void SetupOptMenu(void) {
    OamEntry *oamEntry;
    gOptMenuEntryChosen[0] = 0;
    LoadOptMenuFilesAndSetBgCnt();
    LoadHlScr(0x10);
    LoadMenuPairScreenMap(3);
    ShowSubScreenMessage(0x88, -1, 0);
    gOptMenuOamEntry = CreateOamEntryFromNceImage(0, 0x5b);
    oamEntry = gOptMenuOamEntry;
    oamEntry->mAttr01 = ((gOptMenuOamEntryPosition[0] & 0x1ff) << 16) |
                        ((oamEntry->mAttr01 & OAM_ATTR01_NOT_POSITION_MASK) | (gOptMenuOamEntryPosition[1] & 0xff));
    oamEntry = gOptMenuOamEntry;
    oamEntry->mAttr2 = (oamEntry->mAttr2 & OAM_ATTR2_NOT_PRIORITY_MASK) | 0xc00;
    PlaceSelectionCorners(
        gOptMenuSelectionRects[gOptMenuSelectedIndex].mX, gOptMenuSelectionRects[gOptMenuSelectedIndex].mRight,
        gOptMenuSelectionRects[gOptMenuSelectedIndex].mY, gOptMenuSelectionRects[gOptMenuSelectedIndex].mBottom);
    SetUpdateFunction(StartOptMenuFadeIn);
}

void LoadOptMenuFilesAndSetBgCnt(void) {
    u8 *palette;
    YbBgOptionNclName ybBgOptionNclName;
    YbBgOption1NclName ybBgOption1NclName;
    DWCWiFiInfo wifiInfo;
    u8 *copyFrom;
    u8 *copyTo;
    s32 index;
    ybBgOptionNclName = gYbBgOptionNclName;
    ybBgOption1NclName = gYbBgOption1NclName;
    LoadFileToVram("char/jbBgOption.ncg.l", GX_LoadBG2Char);
    LoadFileToVram("char/jb5OptMenu.nsc.l", GX_LoadBG2Scr);
    gYbBgOption1Ncl = LoadFile(BuildFilePathWithLanguage(ybBgOption1NclName.mText), NULL, 4);
    palette = LoadFile(BuildFilePathWithLanguage(ybBgOptionNclName.mText), NULL, 4);
    DWCi_BM_GetWiFiInfo(&wifiInfo);
    if (wifiInfo.mAttestedUserId == 0) {
        copyFrom = palette + 0xc0;
        copyTo = palette + 0x40;
        for (index = 0; index < 2; index++, copyFrom += 0x20, copyTo += 0x20) {
            MI_CpuCopy8(copyFrom, copyTo, 0x20);
        }
    }
    DC_FlushRange(palette, 0x200);
    GX_LoadBGPltt(palette, 0, 0x200);
    DeleteLoadedFile(palette);
    reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & ~REG_G2S_DB_BG0CNT_PRIORITY_MASK) | 3;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & ~REG_G2S_DB_BG1CNT_PRIORITY_MASK) | 3;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & ~REG_G2_BG1CNT_PRIORITY_MASK) | 3;
    reg_G2_BG2CNT = (reg_G2_BG2CNT & ~REG_G2_BG2CNT_PRIORITY_MASK) | 3;
}

void StartOptMenuFadeIn(void) {
    StartBlendBrightnessFade(2, 1, 1, 8);
    StartBlendBrightnessFade(2, 0, 0x14, 8);
    CombineDispcntBits(1, 1);
    CombineDispcntBits(0, 0x14);
    SetUpdateFunction(UpdateOptMenuFadeIn);
}

void UpdateOptMenuFadeIn(void) {
    int fadeSlotBusy;
    fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(1);
    if ((fadeSlotBusy == 0) && (fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(0), fadeSlotBusy == 0)) {
        CreateSlideButtonsForMenuPair(0);
        SetUpdateFunction(UpdateOptMenuButtonsIn);
    }
}

void UpdateOptMenuButtonsIn(void) {
    if (GetButtonResult() != -2) {
        EnableButtonTouch();
        SetUpdateFunction(UpdateOptMenu);
    }
}

void UpdateOptMenu(void) {
    UpdateOptMenuInput();
    UpdateOptMenuNop();
    UpdateOptMenuResult();
}

void UpdateOptMenuInput(void) {
    u32 rectIndex;
    for (rectIndex = 0; rectIndex < 3; rectIndex++) {
        if (IsTouchPressedInRect(&gOptMenuRects[rectIndex]) != 0) {
            SetButtonResultIfNone(1);
            gOptMenuSelectedIndex = rectIndex;
            PlaceSelectionCorners(gOptMenuSelectionRects[gOptMenuSelectedIndex].mX,
                                  gOptMenuSelectionRects[gOptMenuSelectedIndex].mRight,
                                  gOptMenuSelectionRects[gOptMenuSelectedIndex].mY,
                                  gOptMenuSelectionRects[gOptMenuSelectedIndex].mBottom);
            return;
        }
    }
    if (AreKeysPressed(1) != 0) {
        SetButtonResultIfNone(1);
    } else if (AreKeysPressed(2) != 0) {
        SetButtonResultIfNone(0);
    } else if (AreKeysPressedOrRepeated(0x40) != 0) {
        MoveOptMenuSelection(1);
    } else if (AreKeysPressedOrRepeated(0x80) != 0) {
        MoveOptMenuSelection(3);
    }
}

void UpdateOptMenuNop(void) {}

void UpdateOptMenuResult(void) {
    DWCWiFiInfo wifiInfo;
    switch (GetButtonResult()) {
        case 0:
            StartSoundSeq(7);
            break;
        case 1:
            DWCi_BM_GetWiFiInfo(&wifiInfo);
            if (gOptMenuSelectedIndex != 0 && wifiInfo.mAttestedUserId == 0) {
                StartSoundSeq(9);
                SetButtonResult(-1);
                return;
            }
            StartSoundSeq(6);
            RequestOptMenuPaletteRowCopy();
            gOptMenuEntryChosen[0] = 1;
            break;
        default:
            return;
    }
    SetUpdateFunction(StartOptMenuClose);
}

void StartOptMenuClose(void) {
    DisableButtonTouch();
    StartBlendBrightnessFadeWait(8);
    SetUpdateFunction(UpdateOptMenuFadeOut);
}

void UpdateOptMenuFadeOut(void) {
    int fadeSlotBusy;
    fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(1);
    if (fadeSlotBusy == 0) {
        if (gOptMenuEntryChosen[0] != 0) {
            StartSlideButtonsOut();
        }
        StartBlendBrightnessFade(3, 1, 1, 8);
        StartBlendBrightnessFade(3, 0, 0x14, 8);
        SetUpdateFunction(UpdateOptMenuRelease);
    }
}

void UpdateOptMenuRelease(void) {
    if (IsBlendBrightnessFadeSlotBusy(1) == 0 && IsBlendBrightnessFadeSlotBusy(0) == 0 &&
        IsSlideButtonsNotSlidingOut() != 0) {
        DeleteOamEntry(gOptMenuOamEntry);
        ReleaseSelectionObjectSlots();
        HideSubScreenMessage();
        DeleteLoadedFile(gYbBgOption1Ncl);
        ClearDispcntBits(1, 1);
        ClearDispcntBits(0, 0x14);
        if (gOptMenuEntryChosen[0] == 0) {
            SetPrimaryMenuPair(0, 0);
            SetUpdateFunction(SetupJb2Menu);
        } else {
            switch (gOptMenuSelectedIndex) {
                case OPT_MENU_SELECTED_INFO:
                    SetPrimaryMenuPair(0, 1);
                    SetUpdateFunction(SetupJb5Info);
                    break;
                case OPT_MENU_SELECTED_MULTI:
                    SetPrimaryMenuPair(0, 1);
                    SetUpdateFunction(SetupYb5Multi);
                    break;
                case OPT_MENU_SELECTED_MESSAGE:
                    SetPrimaryMenuPair(0, 1);
                    SetUpdateFunction(SetupOptMenuMessage);
                    break;
            }
        }
    }
}

void MoveOptMenuSelection(s32 direction) {
    if (direction == 1) {
        gOptMenuSelectedIndex = FX_ModS32(gOptMenuSelectedIndex + 2, 3);
    } else {
        gOptMenuSelectedIndex = FX_ModS32(gOptMenuSelectedIndex + 1, 3);
    }
    StartSoundSeq(8);
    PlaceSelectionCorners(
        gOptMenuSelectionRects[gOptMenuSelectedIndex].mX, gOptMenuSelectionRects[gOptMenuSelectedIndex].mRight,
        gOptMenuSelectionRects[gOptMenuSelectedIndex].mY, gOptMenuSelectionRects[gOptMenuSelectedIndex].mBottom);
}

void RequestOptMenuPaletteRowCopy(void) {
    u8 tableByte = gOptMenuPaletteRows[gOptMenuSelectedIndex];
    RequestBgPaletteRowCopy(gYbBgOption1Ncl, tableByte, tableByte);
}
