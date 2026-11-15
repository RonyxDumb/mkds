#include "03/Menu/jb2_menu.h"
#include "03/code_021c2000.h"
#include "03/code_021bf000.h"
#include "03/code_021cb11c.h"
#include "03/code_021ce000.h"

#include "03/Menu/sub_screen_message.h"
#include "03/System/dwc_archive.h"
#include "03/Menu/selection_objects.h"
#include "03/System/application.h"
#include "03/Menu/opt_menu.h"
#include "03/code_021cb000.h"
#include "code_0212df7c.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d1000.h"
#include "03/code_021d1dd0.h"
#include "03/code_021d1f70.h"
#include "03/Graphics/dispcnt_window.h"
#include "03/unk_021da000.h"
#include "03/Menu/slide_buttons.h"
#include "03/code_021c2a74.h"
#include "03/System/task_input.h"
#include "03/Menu/menu_pair_loading.h"
#include "03/Graphics/text_canvas.h"
#include "03/unk_021d5000.h"
#include "03/Graphics/hl_scr.h"
#include "gx_load2d.h"
#include "03/Graphics/bg2_scr_buffer.h"
#include "03/Menu/menu_pair_objects.h"
#include "registers.h"

const Rect gJb2MenuRects[2] = {{8, 0x20, 0xac, 0xa0}, {0xb4, 0x20, 0xf8, 0xa0}};
const Rect gJb2MenuSelectionRects[2] = {{6, 0x1e, 0x9e, 0x92}, {0xb2, 0x1e, 0xea, 0x92}};
Jb2MenuPaletteRows gJb2MenuPaletteRows = {{1, 2}};
YbBgStep11NclName gYbBgStep11NclName = {{0x63, 0x68, 0x61, 0x72, 0x2f, 0x79, 0x62, 0x42, 0x67, 0x53, 0x74,
                                         0x65, 0x70, 0x31, 0x31, 0x2e, 0x6e, 0x63, 0x6c, 0x2e, 0x6c, 0}};
u8 gJb2MenuSelectedIndex;
void *gYbBgStep11Ncl;

void SetupJb2Menu(void) {
    LoadJb2MenuFilesAndSetBgCnt();
    LoadHlScr(0);
    ShowSubScreenMessage(0x7a, -1, 0);
    LoadMenuPairScreenMap(4);
    PlaceSelectionCorners(
        gJb2MenuSelectionRects[gJb2MenuSelectedIndex].mX, gJb2MenuSelectionRects[gJb2MenuSelectedIndex].mRight,
        gJb2MenuSelectionRects[gJb2MenuSelectedIndex].mY, gJb2MenuSelectionRects[gJb2MenuSelectedIndex].mBottom);
    SetUpdateFunction(StartJb2MenuFadeIn);
}

void LoadJb2MenuFilesAndSetBgCnt(void) {
    YbBgStep11NclName ybBgStep11NclName;
    ybBgStep11NclName = gYbBgStep11NclName;
    LoadFileToVram("char/jbBgStep1.ncg.l", GX_LoadBG2Char);
    LoadFileToVram("char/jbBgStep1.ncl.l", GX_LoadBGPltt);
    LoadFileToVram("char/jb2Menu.nsc.l", GX_LoadBG2Scr);
    gYbBgStep11Ncl = LoadFile(BuildFilePathWithLanguage(ybBgStep11NclName.mText), NULL, 4);
    reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & ~REG_G2S_DB_BG0CNT_PRIORITY_MASK) | 3;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & ~REG_G2S_DB_BG1CNT_PRIORITY_MASK) | 3;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & ~REG_G2_BG1CNT_PRIORITY_MASK) | 3;
    reg_G2_BG2CNT = (reg_G2_BG2CNT & ~REG_G2_BG2CNT_PRIORITY_MASK) | 3;
}

void StartJb2MenuFadeIn(void) {
    StartBlendBrightnessFade(2, 1, 1, 8);
    StartBlendBrightnessFade(2, 0, 0x14, 8);
    CombineDispcntBits(1, 1);
    CombineDispcntBits(0, 0x14);
    SetUpdateFunction(UpdateJb2MenuFadeIn);
}

void UpdateJb2MenuFadeIn(void) {
    int fadeSlotBusy;
    fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(1);
    if ((fadeSlotBusy == 0) && (fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(0), fadeSlotBusy == 0)) {
        CreateSlideButtonsForMenuPair(0);
        SetUpdateFunction(UpdateJb2MenuButtonsIn);
    }
}

void UpdateJb2MenuButtonsIn(void) {
    if (GetButtonResult() != -2) {
        EnableButtonTouch();
        SetUpdateFunction(UpdateJb2Menu);
    }
}

void UpdateJb2Menu(void) {
    UpdateJb2MenuInput();
    UpdateJb2MenuNop();
    UpdateJb2MenuResult();
}

void UpdateJb2MenuInput(void) {
    u32 rectIndex;
    for (rectIndex = 0; rectIndex < 2; rectIndex++) {
        if (IsTouchPressedInRect(&gJb2MenuRects[rectIndex]) != 0) {
            SetButtonResultIfNone(1);
            gJb2MenuSelectedIndex = rectIndex;
            PlaceSelectionCorners(gJb2MenuSelectionRects[gJb2MenuSelectedIndex].mX,
                                  gJb2MenuSelectionRects[gJb2MenuSelectedIndex].mRight,
                                  gJb2MenuSelectionRects[gJb2MenuSelectedIndex].mY,
                                  gJb2MenuSelectionRects[gJb2MenuSelectedIndex].mBottom);
            return;
        }
    }
    if (AreKeysPressed(1) != 0) {
        SetButtonResultIfNone(1);
    } else if (AreKeysPressed(2) != 0) {
        SetButtonResultIfNone(0);
    } else if (AreKeysPressedOrRepeated(0x40) != 0) {
        MoveJb2MenuSelection(1);
    } else if (AreKeysPressedOrRepeated(0x80) != 0) {
        MoveJb2MenuSelection(3);
    } else if (AreKeysPressedOrRepeated(0x20) != 0) {
        MoveJb2MenuSelection(0);
    } else if (AreKeysPressedOrRepeated(0x10) != 0) {
        MoveJb2MenuSelection(2);
    }
}

void UpdateJb2MenuNop(void) {}

void UpdateJb2MenuResult(void) {
    switch (GetButtonResult()) {
        case 0:
            StartSoundSeq(7);
            SetUpdateFunction(StartMainFadeOut);
            break;
        case 1:
            StartSoundSeq(6);
            RequestJb2MenuPaletteRowCopy();
            SetUpdateFunction(StartJb2MenuClose);
            break;
    }
}

void StartJb2MenuClose(void) {
    DisableButtonTouch();
    StartBlendBrightnessFadeWait(8);
    SetUpdateFunction(UpdateJb2MenuFadeOut);
}

void UpdateJb2MenuFadeOut(void) {
    int fadeSlotBusy;
    fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(1);
    if (fadeSlotBusy == 0) {
        StartBlendBrightnessFade(3, 1, 1, 8);
        StartBlendBrightnessFade(3, 0, 0x14, 8);
        SetUpdateFunction(UpdateJb2MenuRelease);
    }
}

void UpdateJb2MenuRelease(void) {
    if (IsBlendBrightnessFadeSlotBusy(1) == 0 && IsBlendBrightnessFadeSlotBusy(0) == 0) {
        ReleaseSelectionObjectSlots();
        HideSubScreenMessage();
        DeleteLoadedFile(gYbBgStep11Ncl);
        ClearDispcntBits(1, 1);
        ClearDispcntBits(0, 0x14);
        switch (gJb2MenuSelectedIndex) {
            case 0:
                SetPrimaryMenuPair(1, 0);
                SetUpdateFunction(CreateAp);
                break;
            case 1:
                SetPrimaryMenuPair(0, 0);
                SetUpdateFunction(SetupOptMenu);
                break;
        }
    }
}

void MoveJb2MenuSelection(s32 direction) {
    if (direction != 1 && direction != 3) {
        gJb2MenuSelectedIndex ^= 1;
        StartSoundSeq(8);
        PlaceSelectionCorners(
            gJb2MenuSelectionRects[gJb2MenuSelectedIndex].mX, gJb2MenuSelectionRects[gJb2MenuSelectedIndex].mRight,
            gJb2MenuSelectionRects[gJb2MenuSelectedIndex].mY, gJb2MenuSelectionRects[gJb2MenuSelectedIndex].mBottom);
    }
}

void RequestJb2MenuPaletteRowCopy(void) {
    Jb2MenuPaletteRows paletteRows;
    u8 tableByte;
    paletteRows = gJb2MenuPaletteRows;
    tableByte = paletteRows.mRowIndices[gJb2MenuSelectedIndex];
    RequestBgPaletteRowCopy(gYbBgStep11Ncl, tableByte, tableByte);
}
