#include "03/code_021cb11c.h"
#include "03/code_021c7d30.h"
#include "03/code_021ca56c.h"
#include "03/code_021c50f8.h"
#include "03/code_021ca20c.h"
#include "03/code_021d1790.h"
#include "03/code_021d197c.h"
#include "03/unk_021da000.h"
#include "03/code_021bf098.h"
#include "03/code_021bf410.h"
#include "03/code_021bf000.h"
#include "03/code_021c2000.h"
#include "03/code_021ce000.h"
#include "03/code_021bf4dc.h"
#include "03/code_021bf698.h"
#include "03/code_021d1440.h"
#include "03/unk_021d5000.h"
#include "03/code_021bf810.h"
#include "03/code_021c209c.h"
#include "03/code_021c5000.h"
#include "03/code_021c9000.h"
#include "03/code_021ca000.h"
#include "03/unk_021d6000.h"
#include "03/unk_021d7000.h"
#include "03/code_021ca940.h"
#include "03/code_021cb000.h"
#include "03/code_021cc000.h"
#include "os_printf.h"
#include "03/code_021cd2e0.h"
#include "code_0212df7c.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d1000.h"
#include "03/code_021d1f70.h"
#include "03/code_021d254c.h"
#include "03/code_021d27d8.h"
#include "code_0214b824.h"
#include "03/code_021cc8d4.h"
#include "registers.h"

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
    PlaceSelectionCorners(gWaySelectionRects[HasModeFlag(1)][gWaySelectedIndex].mUnk_00,
                          gWaySelectionRects[HasModeFlag(1)][gWaySelectedIndex].mUnk_04,
                          gWaySelectionRects[HasModeFlag(1)][gWaySelectedIndex].mUnk_02,
                          gWaySelectionRects[HasModeFlag(1)][gWaySelectedIndex].mUnk_06);
}

void RequestWayPaletteRowCopy(void) {
    WayPaletteRows paletteRows = gWayPaletteRows;
    RequestBgPaletteRowCopy(gYbBgStep21Ncl, paletteRows.mUnk_00[gWaySelectedIndex],
                            paletteRows.mUnk_00[gWaySelectedIndex]);
}

void CreateAp(void) {
    Ap *apObject = AllocZeroedExpHeapBlock(0x20, 4);
    gAp = apObject;
    apObject->mUnk_1d = 0;
    LoadApFilesAndSetBgCnt();
    LoadHlScr(1);
    ShowSubScreenMessage(0x7b, -1, 0);
    CreateObjectsForMenuPair(0);
    CreateApEntryObjects();
    PlaceApSelection();
    SetUpdateFunction(StartApFadeIn);
}

void LoadApFilesAndSetBgCnt(void) {
    Unk021d75c8 ybBgStep11NclName = gYbBgStep11NclName2;
    LoadFileToVram(gYbObjWayNclName, GX_LoadOBJPltt);
    LoadFileToVram(gJbBgStep1NcgName3, GX_LoadBG2Char);
    LoadFileToVram(gJbBgStep1NclName3, GX_LoadBGPltt);
    LoadFileToVram(gJb2ApNscName, GX_LoadBG2Scr);
    gAp->mYbBgStep11Ncl = LoadFile(BuildFilePathWithLanguage((u8 *) &ybBgStep11NclName), NULL, 4);
    CombineDispcntBits(1, 0x10);
    reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & ~3) | 3;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & ~3) | 3;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & ~3) | 3;
    reg_G2_BG2CNT = (reg_G2_BG2CNT & ~3) | 3;
}

void CreateApEntryObjects(void) {
    s32 i;
    u32 entryStatus;
    for (i = 0; i < 3; i++) {
        entryStatus = func_ov003_021cd844(i);
        if (entryStatus == 0xff) {
            entryStatus = 3;
        } else {
            gAp->mUnk_10[i] = CreateOamRangeFromNceImage(0, 0x11, 1);
            SetOamRangePosition(gAp->mUnk_10[i], -1, gApObjectPositions[i + 3].mX, gApObjectPositions[i + 3].mY);
            func_ov003_021d1790(gAp->mUnk_10[i], -1, 3);
        }
        gAp->mUnk_04[i] = CreateOamRangeFromNceImage(0, gApEntryImageIndices[entryStatus], 1);
        SetOamRangePosition(gAp->mUnk_04[i], -1, gApObjectPositions[i].mX, gApObjectPositions[i].mY);
        func_ov003_021d1790(gAp->mUnk_04[i], -1, 3);
    }
}
