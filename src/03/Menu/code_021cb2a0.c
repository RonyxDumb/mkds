#include "03/Menu/code_021cb2a0.h"
#include "03/Menu/ap_screen.h"
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
#include "03/Net/essid_packet_steps.h"
#include "03/code_021cd2e0.h"
#include "03/Graphics/hl_scr.h"
#include "gx_load2d.h"
#include "registers.h"
#include "03/Menu/jb3_list.h"
#include "03/Menu/ap_scan_screen.h"
#include "03/Menu/value_records.h"
#include "03/Menu/exchange_search.h"
#include "03/code_021d1790.h"
#include "03/code_021d197c.h"
#include "03/code_021c5000.h"
#include "03/code_021c9000.h"
#include "03/code_021ca000.h"
#include "03/code_021cc000.h"
#include "os_printf.h"
#include "03/System/exp_heap.h"
#include "03/Graphics/bg2_scr_buffer.h"
#include "03/Menu/jb2_menu.h"
#include "03/code_021cdd28.h"
#include "03/Menu/message_box.h"
#include "03/code_021d1c18.h"
#include "03/code_021c3000.h"
#include "03/Menu/xb3_multi.h"
#include "03/code_021d1970.h"
#include "03/code_021c2a74.h"
#include "03/code_021cd000.h"

const Rect gWayRects[2][4] = {
    {{8, 0x20, 0xf8, 0x5c}, {8, 0x64, 0x7e, 0xa0}, {0, 0, 0, 0}, {0x83, 0x64, 0xf8, 0xa0}},
    {{8, 0x20, 0xf8, 0x5c}, {8, 0x64, 0x64, 0xa0}, {0x68, 0x64, 0xc4, 0xa0}, {0xc8, 0x64, 0xf8, 0xa0}}};
Bytes22 gYbBgStep21NclName2 = {{0x63, 0x68, 0x61, 0x72, 0x2f, 0x79, 0x62, 0x42, 0x67, 0x53, 0x74,
                                0x65, 0x70, 0x32, 0x31, 0x2e, 0x6e, 0x63, 0x6c, 0x2e, 0x6c, 0}};
WayPaletteRows gWayPaletteRows = {{1, 2, 3, 4}};
const s8 gWayMoveTargets[2][4][4] = {{{-1, -2, -1, -2}, {3, 0, 3, 0}, {-1, -1, -1, -1}, {1, 0, 1, 0}},
                                     {{-1, -2, -1, -2}, {3, 0, 2, 0}, {1, 0, 3, 0}, {2, 0, 1, 0}}};
const s8 gWayMessageDigitColumns[6] = {3, -1, -1, -1, -1, -1};
const Rect gWaySelectionRects[2][4] = {
    {{6, 0x1e, 0xea, 0x4e}, {6, 0x62, 0x70, 0x92}, {0, 0, 0, 0}, {0x80, 0x62, 0xea, 0x92}},
    {{6, 0x1e, 0xea, 0x4e}, {6, 0x62, 0x56, 0x92}, {0x66, 0x62, 0xb6, 0x92}, {0xc6, 0x62, 0xea, 0x92}}};
u8 *gYbBgStep21Ncl;
u8 gWayChosen[1];
s8 gWaySelectedIndex;
s8 gWaySavedIndex;

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
    LoadFileToVram("char/jbBgStep2.ncg.l", GX_LoadBG2Char);
    LoadFileToVram("char/ybBgStep2.ncl.l", GX_LoadBGPltt);
    LoadFileToVram("char/jb3Way.nsc.l", GX_LoadBG2Scr);
    gYbBgStep21Ncl = LoadFile(BuildFilePathWithLanguage((u8 *) &ybBgStep21NclName), NULL, 4);
    reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & ~REG_G2S_DB_BG0CNT_PRIORITY_MASK) | 3;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & ~REG_G2S_DB_BG1CNT_PRIORITY_MASK) | 3;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & ~REG_G2_BG1CNT_PRIORITY_MASK) | 3;
    reg_G2_BG2CNT = (reg_G2_BG2CNT & ~REG_G2_BG2CNT_PRIORITY_MASK) | 3;
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
    u32 rectIndex;
    for (rectIndex = 0; rectIndex < 4; rectIndex++) {
        if (IsTouchPressedInRect(&gWayRects[HasModeFlag(1)][rectIndex]) != 0) {
            SetButtonResultIfNone(1);
            gWaySelectedIndex = rectIndex;
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

void UpdateWayRelease(void) {
    if (IsBlendBrightnessFadeSlotBusy(1) == 0 && IsBlendBrightnessFadeSlotBusy(0) == 0 &&
        IsSlideButtonsNotSlidingOut() != 0) {
        ReleaseSelectionObjectSlots();
        HideSubScreenMessage();
        DeleteLoadedFile(gYbBgStep21Ncl);
        ClearDispcntBits(1, 1);
        ClearDispcntBits(0, 0x14);
        if (gWayChosen[0] == 0) {
            SetPrimaryMenuPair(2, 0);
            SetUpdateFunction(CreateAp);
        } else {
            switch (gWaySelectedIndex) {
                case 0:
                    SetPrimaryMenuPair(2, 1);
                    SetUpdateFunction(SetupApScan);
                    break;
                case 1:
                    SetPrimaryMenuPair(2, 1);
                    SetUpdateFunction(SetupValueRecords);
                    break;
                case 2:
                    SetPrimaryMenuPair(2, 1);
                    SetUpdateFunction(SetupExchangeSearch);
                    break;
                case 3:
                    SetPrimaryMenuPair(2, 0);
                    SetSecondaryMenuPair(0, 0);
                    SetJb3ListMode(1);
                    SetUpdateFunction(CreateJb3List);
                    break;
            }
        }
    }
}

void MoveWaySelection(int direction) {
    s32 selectedIndex = gWaySelectedIndex;
    s32 moveTarget = gWayMoveTargets[HasModeFlag(1)][selectedIndex][direction];
    if (moveTarget == -1) {
        return;
    }
    if (moveTarget == 0) {
        gWaySavedIndex = selectedIndex;
    }
    if (moveTarget == -2) {
        gWaySelectedIndex = gWaySavedIndex;
    } else {
        gWaySelectedIndex = moveTarget;
    }
    StartSoundSeq(8);
    PlaceSelectionCorners(gWaySelectionRects[HasModeFlag(1)][gWaySelectedIndex].mX,
                          gWaySelectionRects[HasModeFlag(1)][gWaySelectedIndex].mUnk_04,
                          gWaySelectionRects[HasModeFlag(1)][gWaySelectedIndex].mY,
                          gWaySelectionRects[HasModeFlag(1)][gWaySelectedIndex].mUnk_06);
}

void RequestWayPaletteRowCopy(void) {
    WayPaletteRows paletteRows = gWayPaletteRows;
    RequestBgPaletteRowCopy(gYbBgStep21Ncl, paletteRows.mRowIndices[gWaySelectedIndex],
                            paletteRows.mRowIndices[gWaySelectedIndex]);
}
