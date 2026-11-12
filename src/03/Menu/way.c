#include "03/Menu/way.h"

#include "03/code_021bf000.h"
#include "03/code_021cb000.h"
#include "03/code_021d1000.h"
#include "03/code_021d1dd0.h"
#include "03/code_021d1f70.h"
#include "03/unk_021da000.h"
#include "03/Menu/slide_buttons.h"
#include "03/System/application.h"
#include "03/code_021cb11c.h"
#include "code_0212df7c.h"
#include "03/code_021cdbd0.h"
#include "03/unk_021d6000.h"
#include "03/code_021c2000.h"
#include "03/code_021ce000.h"
#include "03/Menu/menu_pair_loading.h"
#include "03/Menu/selection_objects.h"
#include "03/System/task_input.h"
#include "03/Graphics/dispcnt_window.h"
#include "03/System/dwc_archive.h"
#include "03/unk_021d7000.h"
#include "03/Graphics/text_canvas.h"
#include "03/unk_021d5000.h"
#include "03/Menu/sub_screen_message.h"
#include "03/Net/essid_wcm.h"
#include "03/code_021cd2e0.h"
#include "03/Graphics/hl_scr.h"
#include "gx_load2d.h"
#include "registers.h"

void SetupWay(void) {
    ApWorkCopy *record = GetApWorkCopy();
    gWayChosen[0] = 0;
    if (gWaySavedIndex == 0) {
        gWaySavedIndex = 1;
    }
    if (GetLanguageIndex() != 0) {
        if (gWaySelectedIndex == 2) {
            gWaySelectedIndex = 0;
        }
        if (gWaySavedIndex == 2) {
            gWaySavedIndex = 1;
        }
    }
    LoadWayFilesAndSetBgCnt();
    LoadHlSetScr();
    ShowSubScreenMessage(0x7e, gWayMessageDigitColumns[GetLanguageIndex()], record->mEntryIndex + 1);
    CreateObjectsForMenuPair(1);
    PlaceSelectionCorners(gWaySelectionRects[HasModeFlag(1)][gWaySelectedIndex].mX,
                          gWaySelectionRects[HasModeFlag(1)][gWaySelectedIndex].mUnk_04,
                          gWaySelectionRects[HasModeFlag(1)][gWaySelectedIndex].mY,
                          gWaySelectionRects[HasModeFlag(1)][gWaySelectedIndex].mUnk_06);
    SetUpdateFunction(StartWayFadeIn);
}

void LoadWayFilesAndSetBgCnt(void) {
    Bytes22 ybBgStep21NclName = gYbBgStep21NclName2;
    LoadFileToVram(gJbBgStep2NcgName2, GX_LoadBG2Char);
    LoadFileToVram(gYbBgStep2NclName2, GX_LoadBGPltt);
    LoadFileToVram(gJb3WayNscName, GX_LoadBG2Scr);
    gYbBgStep21Ncl = LoadFile(BuildFilePathWithLanguage((u8 *) &ybBgStep21NclName), NULL, 4);
    reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & ~3) | 3;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & ~3) | 3;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & ~3) | 3;
    reg_G2_BG2CNT = (reg_G2_BG2CNT & ~3) | 3;
}

void StartWayFadeIn(void) {
    StartBlendBrightnessFade(2, 1, 1, 8);
    StartBlendBrightnessFade(2, 0, 0x14, 8);
    CombineDispcntBits(1, 1);
    CombineDispcntBits(0, 0x14);
    SetUpdateFunction(UpdateWayFadeIn);
}

void UpdateWayFadeIn(void) {
    int fadeSlotBusy;
    fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(1);
    if ((fadeSlotBusy == 0) && (fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(0), fadeSlotBusy == 0)) {
        CreateSlideButtonsForMenuPair(0);
        SetUpdateFunction(UpdateWayButtonsIn);
    }
}

void UpdateWayButtonsIn(void) {
    if (GetButtonResult() != -2) {
        EnableButtonTouch();
        SetUpdateFunction(UpdateWay);
    }
}

void UpdateWay(void) {
    UpdateWayInput();
    UpdateWayNop();
    UpdateWayResult();
}

void UpdateWayInput(void) {
    u32 i;
    for (i = 0; i < 4; i++) {
        if (IsTouchPressedInRect(&gWayRects[HasModeFlag(1)][i]) != 0) {
            SetButtonResultIfNone(1);
            gWaySelectedIndex = i;
            PlaceSelectionCorners(gWaySelectionRects[HasModeFlag(1)][gWaySelectedIndex].mX,
                                  gWaySelectionRects[HasModeFlag(1)][gWaySelectedIndex].mUnk_04,
                                  gWaySelectionRects[HasModeFlag(1)][gWaySelectedIndex].mY,
                                  gWaySelectionRects[HasModeFlag(1)][gWaySelectedIndex].mUnk_06);
            return;
        }
    }
    if (AreKeysPressed(1) != 0) {
        SetButtonResultIfNone(1);
    } else if (AreKeysPressed(2) != 0) {
        SetButtonResultIfNone(0);
    } else if (AreKeysPressedOrRepeated(0x40) != 0) {
        MoveWaySelection(1);
    } else if (AreKeysPressedOrRepeated(0x80) != 0) {
        MoveWaySelection(3);
    } else if (AreKeysPressedOrRepeated(0x20) != 0) {
        MoveWaySelection(0);
    } else if (AreKeysPressedOrRepeated(0x10) != 0) {
        MoveWaySelection(2);
    }
}

void UpdateWayNop(void) {}

void UpdateWayResult(void) {
    switch (GetButtonResult()) {
        case 0:
            StartSoundSeq(7);
            break;
        case 1:
            StartSoundSeq(6);
            RequestWayPaletteRowCopy();
            gWayChosen[0] = 1;
            break;
        default:
            return;
    }
    SetUpdateFunction(StartWayClose);
}

void StartWayClose(void) {
    DisableButtonTouch();
    StartBlendBrightnessFadeWait(8);
    SetUpdateFunction(UpdateWayFadeOut);
}

void UpdateWayFadeOut(void) {
    int fadeSlotBusy;
    fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(1);
    if (fadeSlotBusy == 0) {
        if ((*(u8 *) &gWayChosen) != 0) {
            StartSlideButtonsOut();
        }
        StartBlendBrightnessFade(3, 1, 1, 8);
        StartBlendBrightnessFade(3, 0, 0x14, 8);
        SetUpdateFunction(UpdateWayRelease);
    }
}
