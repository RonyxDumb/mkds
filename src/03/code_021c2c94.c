#include "03/code_021c2c94.h"
#include "03/code_021c2000.h"
#include "03/code_021bf000.h"
#include "03/code_021cb11c.h"
#include "03/code_021ce000.h"

#include "03/code_021bf410.h"
#include "03/code_021d1440.h"
#include "03/code_021bf698.h"
#include "03/code_021c209c.h"
#include "03/code_021c391c.h"
#include "03/code_021cb000.h"
#include "code_0212df7c.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d1000.h"
#include "03/code_021d1dd0.h"
#include "03/code_021d1f70.h"
#include "03/code_021d254c.h"
#include "03/unk_021da000.h"
#include "03/code_021bf098.h"
#include "03/code_021c2a74.h"
#include "03/code_021d2940.h"
#include "03/code_021bf4dc.h"
#include "03/code_021d1fd0.h"
#include "03/unk_021d5000.h"
#include "03/code_021bf810.h"
#include "gx_load2d.h"
#include "03/code_021cc8d4.h"
#include "03/code_021cdcb8.h"
#include "registers.h"

void SetupJb2Menu(void) {
    LoadJb2MenuFilesAndSetBgCnt();
    LoadHlScr(0);
    ShowSubScreenMessage(0x7a, -1, 0);
    LoadMenuPairScreenMap(4);
    PlaceSelectionCorners(
        gJb2MenuSelectionLeft[gJb2MenuSelectedIndex * 4], gJb2MenuSelectionRight[gJb2MenuSelectedIndex * 4],
        gJb2MenuSelectionTop[gJb2MenuSelectedIndex * 4], gJb2MenuSelectionBottom[gJb2MenuSelectedIndex * 4]);
    SetUpdateFunction(StartJb2MenuFadeIn);
}

void LoadJb2MenuFilesAndSetBgCnt(void) {
    YbBgStep11NclName ybBgStep11NclName;
    ybBgStep11NclName = gYbBgStep11NclName;
    LoadFileToVram(gJbBgStep1NcgName2, GX_LoadBG2Char);
    LoadFileToVram(gJbBgStep1NclName2, GX_LoadBGPltt);
    LoadFileToVram(gJb2MenuNscName, GX_LoadBG2Scr);
    gYbBgStep11Ncl = LoadFile(BuildFilePathWithLanguage(ybBgStep11NclName.mText), NULL, 4);
    reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & ~3) | 3;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & ~3) | 3;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & ~3) | 3;
    reg_G2_BG2CNT = (reg_G2_BG2CNT & ~3) | 3;
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
    u32 i;
    for (i = 0; i < 2; i++) {
        if (IsTouchPressedInRect(&gJb2MenuRects[i]) != 0) {
            SetButtonResultIfNone(1);
            gJb2MenuSelectedIndex = i;
            PlaceSelectionCorners(
                gJb2MenuSelectionLeft[gJb2MenuSelectedIndex * 4], gJb2MenuSelectionRight[gJb2MenuSelectedIndex * 4],
                gJb2MenuSelectionTop[gJb2MenuSelectedIndex * 4], gJb2MenuSelectionBottom[gJb2MenuSelectedIndex * 4]);
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
            gJb2MenuSelectionLeft[gJb2MenuSelectedIndex * 4], gJb2MenuSelectionRight[gJb2MenuSelectedIndex * 4],
            gJb2MenuSelectionTop[gJb2MenuSelectedIndex * 4], gJb2MenuSelectionBottom[gJb2MenuSelectedIndex * 4]);
    }
}

void RequestJb2MenuPaletteRowCopy(void) {
    Jb2MenuPaletteRows paletteRows;
    u8 tableByte;
    paletteRows = gJb2MenuPaletteRows;
    tableByte = paletteRows.mRowIndices[gJb2MenuSelectedIndex];
    RequestBgPaletteRowCopy(gYbBgStep11Ncl, tableByte, tableByte);
}
