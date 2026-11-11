#include "03/code_021c391c.h"
#include "03/types_021d299c.h"

#include "03/code_021bf000.h"
#include "03/code_021c3000.h"
#include "03/code_021c2000.h"
#include "03/code_021ce000.h"
#include "03/code_021bf4dc.h"
#include "03/code_021d1440.h"
#include "03/code_021d1dd0.h"
#include "03/unk_021da000.h"
#include "03/code_021bf098.h"
#include "03/code_021bf410.h"
#include "03/code_021bf698.h"
#include "03/code_021c209c.h"
#include "03/code_021c2b28.h"
#include "03/code_021c2c94.h"
#include "03/code_021c30f0.h"
#include "03/code_021c38f0.h"
#include "03/code_021c43f0.h"
#include "code_0212df7c.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d1000.h"
#include "03/code_021d1f70.h"
#include "03/code_021d254c.h"
#include "03/code_021d2ecc.h"
#include "code_02147cd8.h"
#include "code_021510a4.h"
#include "code_02151868.h"
#include "03/code_021d2940.h"
#include "03/code_021d1fd0.h"
#include "03/unk_021d5000.h"
#include "03/code_021bf810.h"
#include "03/code_021d1c18.h"
#include "code_0200eddc.h"
#include "code_0214b824.h"
#include "code_0214d018.h"
#include "03/code_021cc8d4.h"
#include "03/code_021cdcb8.h"
#include "registers.h"

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
                        ((oamEntry->mAttr01 & 0xfe00ff00) | (gOptMenuOamEntryPosition[1] & 0xff));
    oamEntry = gOptMenuOamEntry;
    oamEntry->mAttr2 = (oamEntry->mAttr2 & 0xfffff3ff) | 0xc00;
    PlaceSelectionCorners(
        gOptMenuSelectionLeft[gOptMenuSelectedIndex * 4], gOptMenuSelectionRight[gOptMenuSelectedIndex * 4],
        gOptMenuSelectionTop[gOptMenuSelectedIndex * 4], gOptMenuSelectionBottom[gOptMenuSelectedIndex * 4]);
    SetUpdateFunction(StartOptMenuFadeIn);
}

void LoadOptMenuFilesAndSetBgCnt(void) {
    u8 *palette;
    YbBgOptionNclName ybBgOptionNclName;
    YbBgOption1NclName ybBgOption1NclName;
    DWCWiFiInfo wifiInfo;
    u8 *copyFrom;
    u8 *copyTo;
    s32 i;
    ybBgOptionNclName = gYbBgOptionNclName;
    ybBgOption1NclName = gYbBgOption1NclName;
    LoadFileToVram(gJbBgOptionNcgName, GX_LoadBG2Char);
    LoadFileToVram(gJb5OptMenuNscName, GX_LoadBG2Scr);
    gYbBgOption1Ncl = LoadFile(BuildFilePathWithLanguage(ybBgOption1NclName.mUnk_00), NULL, 4);
    palette = LoadFile(BuildFilePathWithLanguage(ybBgOptionNclName.mUnk_00), NULL, 4);
    DWCi_BM_GetWiFiInfo(&wifiInfo);
    if (wifiInfo.mAttestedUserId == 0) {
        copyFrom = palette + 0xc0;
        copyTo = palette + 0x40;
        for (i = 0; i < 2; i++, copyFrom += 0x20, copyTo += 0x20) {
            MI_CpuCopy8(copyFrom, copyTo, 0x20);
        }
    }
    DC_FlushRange(palette, 0x200);
    GX_LoadBGPltt(palette, 0, 0x200);
    DeleteLoadedFile(palette);
    reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & ~3) | 3;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & ~3) | 3;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & ~3) | 3;
    reg_G2_BG2CNT = (reg_G2_BG2CNT & ~3) | 3;
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
    u32 i;
    for (i = 0; i < 3; i++) {
        if (IsTouchPressedInRect(&gOptMenuRects[i]) != 0) {
            SetButtonResultIfNone(1);
            gOptMenuSelectedIndex = i;
            PlaceSelectionCorners(
                gOptMenuSelectionLeft[gOptMenuSelectedIndex * 4], gOptMenuSelectionRight[gOptMenuSelectedIndex * 4],
                gOptMenuSelectionTop[gOptMenuSelectedIndex * 4], gOptMenuSelectionBottom[gOptMenuSelectedIndex * 4]);
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
        if ((*(u8 *) &gOptMenuEntryChosen) != 0) {
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
        DeleteOamEntry((u32 *) gOptMenuOamEntry);
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
                case 0:
                    SetPrimaryMenuPair(0, 1);
                    SetUpdateFunction(SetupJb5Info);
                    break;
                case 1:
                    SetPrimaryMenuPair(0, 1);
                    SetUpdateFunction(SetupYb5Multi);
                    break;
                case 2:
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
        gOptMenuSelectionLeft[gOptMenuSelectedIndex * 4], gOptMenuSelectionRight[gOptMenuSelectedIndex * 4],
        gOptMenuSelectionTop[gOptMenuSelectedIndex * 4], gOptMenuSelectionBottom[gOptMenuSelectedIndex * 4]);
}

void RequestOptMenuPaletteRowCopy(void) {
    u8 tableByte = gOptMenuPaletteRows[gOptMenuSelectedIndex];
    RequestBgPaletteRowCopy(gYbBgOption1Ncl, tableByte, tableByte);
}
