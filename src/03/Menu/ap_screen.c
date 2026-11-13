#include "03/Menu/ap_screen.h"
#include "03/Menu/code_021cb2a0.h"
#include "03/code_021bf000.h"
#include "03/code_021cb000.h"
#include "03/code_021d1000.h"
#include "03/code_021d1dd0.h"
#include "03/code_021d1f70.h"
#include "03/unk_021da000.h"
#include "03/Menu/slide_buttons.h"
#include "03/Menu/message_box.h"
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
#include "03/Menu/message_box_create.h"
#include "03/code_021d1c18.h"
#include "03/code_021c3000.h"
#include "03/Menu/xb3_multi.h"
#include "03/code_021d1970.h"
#include "03/code_021c2a74.h"
#include "03/code_021cd000.h"

YbBgStep11NclName gYbBgStep11NclName2 = {{0x63, 0x68, 0x61, 0x72, 0x2f, 0x79, 0x62, 0x42, 0x67, 0x53, 0x74,
                                          0x65, 0x70, 0x31, 0x31, 0x2e, 0x6e, 0x63, 0x6c, 0x2e, 0x6c, 0}};
Bytes4 gApEntryIconPalettes = {{0xa, 9, 0xb, 6}};
Bytes4 gApPaletteRows = {{3, 4, 5, 7}};
const u8 gApRects[56] = {8,    0, 0x20, 0, 0x54, 0, 0x56, 0, 0x5a, 0, 0x20, 0, 0xa6, 0, 0x56, 0, 0xac, 0, 0x20, 0,
                         0xf8, 0, 0x56, 0, 8,    0, 0x78, 0, 0xf8, 0, 0xa0, 0, 8,    0, 0x54, 0, 0x54, 0, 0x70, 0,
                         0x5a, 0, 0x54, 0, 0xa6, 0, 0x70, 0, 0xac, 0, 0x54, 0, 0xf8, 0, 0x70, 0};
const Rect gApSelectionRects[7] = {{6, 0x1e, 0x46, 0x48},   {0x58, 0x1e, 0x98, 0x48}, {0xaa, 0x1e, 0xea, 0x48},
                                   {6, 0x76, 0xea, 0x92},   {9, 0x54, 0x43, 0x70},    {0x5b, 0x54, 0x95, 0x70},
                                   {0xad, 0x54, 0xe7, 0x70}};
const ApObjectPosition gApObjectPositions[6] = {{8, 0x30},   {0x5a, 0x30}, {0xac, 0x30},
                                                {0xc, 0x58}, {0x5e, 0x58}, {0xb0, 0x58}};
const s8 gApMessageDigitColumns[6] = {3, 0x2d, 0x27, 0x1d, 0x32, 0x30};
const u8 gApEntryImageIndices[4] = {0x13, 0x14, 0x12, 0x56};
u8 gApSelectedIndex[1];
struct Ap *gAp;

void CreateAp(void) {
    Ap *apObject = AllocZeroedExpHeapBlock(0x20, 4);
    gAp = apObject;
    apObject->mCloseKind = 0;
    LoadApFilesAndSetBgCnt();
    LoadHlScr(1);
    ShowSubScreenMessage(0x7b, -1, 0);
    CreateObjectsForMenuPair(0);
    CreateApEntryObjects();
    PlaceApSelection();
    SetUpdateFunction(StartApFadeIn);
}

void LoadApFilesAndSetBgCnt(void) {
    YbBgStep11NclName ybBgStep11NclName = gYbBgStep11NclName2;
    LoadFileToVram("char/ybObjWay.ncl.l", GX_LoadOBJPltt);
    LoadFileToVram("char/jbBgStep1.ncg.l", GX_LoadBG2Char);
    LoadFileToVram("char/jbBgStep1.ncl.l", GX_LoadBGPltt);
    LoadFileToVram("char/jb2Ap.nsc.l", GX_LoadBG2Scr);
    gAp->mYbBgStep11Ncl = LoadFile(BuildFilePathWithLanguage((u8 *) &ybBgStep11NclName), NULL, 4);
    CombineDispcntBits(1, 0x10);
    reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & ~3) | 3;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & ~3) | 3;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & ~3) | 3;
    reg_G2_BG2CNT = (reg_G2_BG2CNT & ~3) | 3;
}

void CreateApEntryObjects(void) {
    s32 entryIndex;
    u32 entryStatus;
    for (entryIndex = 0; entryIndex < 3; entryIndex++) {
        entryStatus = GetApEntrySetType(entryIndex);
        if (entryStatus == 0xff) {
            entryStatus = 3;
        } else {
            gAp->mResetButtonObjects[entryIndex] = CreateOamRangeFromNceImage(0, 0x11, 1);
            SetOamRangePosition(gAp->mResetButtonObjects[entryIndex], -1, gApObjectPositions[entryIndex + 3].mX,
                                gApObjectPositions[entryIndex + 3].mY);
            SetOamRangePriority(gAp->mResetButtonObjects[entryIndex], -1, 3);
        }
        gAp->mEntryIconObjects[entryIndex] = CreateOamRangeFromNceImage(0, gApEntryImageIndices[entryStatus], 1);
        SetOamRangePosition(gAp->mEntryIconObjects[entryIndex], -1, gApObjectPositions[entryIndex].mX,
                            gApObjectPositions[entryIndex].mY);
        SetOamRangePriority(gAp->mEntryIconObjects[entryIndex], -1, 3);
    }
}

void StartApFadeIn(void) {
    StartBlendBrightnessFade(2, 1, 1, 8);
    StartBlendBrightnessFade(2, 0, 0x14, 8);
    CombineDispcntBits(1, 1);
    CombineDispcntBits(0, 0x14);
    SetUpdateFunction(UpdateApFadeIn);
}

void UpdateApFadeIn(void) {
    int fadeSlotBusy;
    fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(1);
    if ((fadeSlotBusy == 0) && (fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(0), fadeSlotBusy == 0)) {
        CreateSlideButtonsForMenuPair(0);
        SetUpdateFunction(UpdateApButtonsIn);
    }
}

void UpdateApButtonsIn(void) {
    if (GetButtonResult() != -2 && IsMenuPairObjectsSliding() != 1) {
        EnableButtonTouch();
        SetUpdateFunction(UpdateAp);
    }
}

void UpdateAp(void) {
    UpdateApInput();
    UpdateApNop();
    UpdateApResult();
}

void UpdateApInput(void) {
    int touchPressed;
    u32 rectIndex;
    int keysPressed;
    const u8 *rect;
    rectIndex = 0;
    rect = gApRects;
    do {
        touchPressed = IsTouchPressedInRect((const Rect *) rect);
        if (touchPressed != 0) {
            SetButtonResultIfNone((u8) 1);
            *(u8 *) &gApSelectedIndex = (s8) rectIndex;
            PlaceApSelection();
            return;
        }
        rect = rect + 8;
        rectIndex = rectIndex + 1;
    } while (rectIndex < 7);
    keysPressed = AreKeysPressed(1);
    if (keysPressed != 0) {
        SetButtonResultIfNone((u8) 1);
        return;
    }
    keysPressed = AreKeysPressed(2);
    if (keysPressed != 0) {
        SetButtonResultIfNone((u8) 0);
        return;
    }
    keysPressed = AreKeysPressedOrRepeated(0x40);
    if (keysPressed != 0) {
        MoveApSelection(1);
        return;
    }
    keysPressed = AreKeysPressedOrRepeated(0x80);
    if (keysPressed != 0) {
        MoveApSelection(3);
        return;
    }
    keysPressed = AreKeysPressedOrRepeated(0x20);
    if (keysPressed != 0) {
        MoveApSelection(0);
        return;
    }
    keysPressed = AreKeysPressedOrRepeated(0x10);
    if (keysPressed != 0) {
        MoveApSelection(2);
    }
}

void UpdateApNop(void) {}

void UpdateApResult(void) {
    s32 entryIndex;
    u8 selectedIndex;
    switch (GetButtonResult()) {
        case 0:
            switch (GetMode()) {
                case 0:
                    StartSoundSeq(7);
                    gAp->mCloseKind = 2;
                    break;
                case 1:
                    DisableButtonTouch();
                    SetUpdateFunction(StartMainFadeOut);
                    return;
            }
            break;
        case 1:
            gAp->mCloseKind = 1;
            selectedIndex = gApSelectedIndex[0];
            if (selectedIndex >= 4) {
                entryIndex = selectedIndex - 4;
                if (GetApEntrySetType(entryIndex) == 0xff) {
                    StartSoundSeq(9);
                    SetButtonResult(-1);
                    return;
                }
                StartSoundSeq(6);
                CreateMessageBox(0x98, 0, 1, gApMessageDigitColumns[GetLanguageIndex()], entryIndex + 1);
                SetApSelectedButtonImage();
                DisableButtonTouch();
                SetUpdateFunction(UpdateApMessageResult);
                return;
            }
            if (selectedIndex <= 2) {
                CopyApEntryToWorkCopy(selectedIndex);
            }
            StartSoundSeq(6);
            RequestApSelectionPalette();
            break;
        default:
            return;
    }
    SetUpdateFunction(StartApClose);
}

void StartApClose(void) {
    if (gAp->mCloseKind == 2) {
        StartMenuPairObjectsSlideOut();
    }
    DisableButtonTouch();
    StartBlendBrightnessFadeWait(8);
    SetUpdateFunction(UpdateApFadeOut);
}

void UpdateApFadeOut(void) {
    if (IsBlendBrightnessFadeSlotBusy(1) == 0) {
        if (gAp->mCloseKind == 1) {
            if (gApSelectedIndex[0] == 3 || GetApWorkCopy()->mEntry.mSetType != 0xff) {
                StartSlideButtonsOut();
            }
        }
        StartBlendBrightnessFade(3, 1, 1, 8);
        StartBlendBrightnessFade(3, 0, 0x14, 8);
        SetUpdateFunction(UpdateApRelease);
    }
}

void UpdateApRelease(void) {
    u32 entryIndex;
    if (IsBlendBrightnessFadeSlotBusy(1) == 0 && IsBlendBrightnessFadeSlotBusy(0) == 0 &&
        IsMenuPairObjectsNotSlidingOut() != 0 && IsSlideButtonsNotSlidingOut() != 0) {
        for (entryIndex = 0; entryIndex < 3; entryIndex++) {
            if (gAp->mEntryIconObjects[entryIndex] != NULL) {
                DeleteOamRange(gAp->mEntryIconObjects[entryIndex]);
            }
        }
        for (entryIndex = 0; entryIndex < 3; entryIndex++) {
            if (gAp->mResetButtonObjects[entryIndex] != NULL) {
                DeleteOamRange(gAp->mResetButtonObjects[entryIndex]);
            }
        }
        ReleaseSelectionObjectSlots();
        HideSubScreenMessage();
        DeleteLoadedFile(gAp->mYbBgStep11Ncl);
        LoadFileToVram("char/ybObjMain.ncl.l", GX_LoadOBJPltt);
        ClearDispcntBits(1, 1);
        ClearDispcntBits(0, 0x14);
        if (gAp->mCloseKind == 2) {
            SetPrimaryMenuPair(0, 0);
            SetUpdateFunction(SetupJb2Menu);
        } else {
            switch (gApSelectedIndex[0]) {
                case 0:
                case 1:
                case 2:
                    SetPrimaryMenuPair(2, 0);
                    if (GetApWorkCopy()->mEntry.mSetType == 0xff) {
                        SetUpdateFunction(SetupWay);
                    } else {
                        SetSecondaryMenuPair(0, 0);
                        SetJb3ListMode(0);
                        SetUpdateFunction(CreateJb3List);
                    }
                    break;
                case 3:
                    SetPrimaryMenuPair(2, 1);
                    SetUpdateFunction(SetupXb3Multi);
                    break;
            }
        }
        FreeExpHeapBlockAndClearPointer(&gAp);
    }
}

void PlaceApSelection(void) {
    u8 selectedIndex = gApSelectedIndex[0];
    if (selectedIndex < 4) {
        PlaceSelectionCorners(gApSelectionRects[selectedIndex].mX, gApSelectionRects[selectedIndex].mUnk_04,
                              gApSelectionRects[selectedIndex].mY, gApSelectionRects[selectedIndex].mUnk_06);
    } else {
        PlaceSelectionPair(0, gApSelectionRects[selectedIndex].mX, gApSelectionRects[selectedIndex].mUnk_04,
                           gApSelectionRects[selectedIndex].mY);
    }
}

void MoveApSelection(int direction) {
    u32 moved = 1;
    switch (gApSelectedIndex[0]) {
        case 0:
            gAp->mRememberedEntryIndex = 0;
            if (direction == 0) {
                gApSelectedIndex[0] = 2;
            } else if (direction == 2) {
                gApSelectedIndex[0] = 1;
            } else if (direction == 1) {
                gApSelectedIndex[0] = 3;
            } else {
                gApSelectedIndex[0] = 4;
            }
            break;
        case 1:
            gAp->mRememberedEntryIndex = 1;
            if (direction == 0) {
                gApSelectedIndex[0] = 0;
            } else if (direction == 2) {
                gApSelectedIndex[0] = 2;
            } else if (direction == 1) {
                gApSelectedIndex[0] = 3;
            } else {
                gApSelectedIndex[0] = 5;
            }
            break;
        case 2:
            gAp->mRememberedEntryIndex = 2;
            if (direction == 0) {
                gApSelectedIndex[0] = 1;
            } else if (direction == 2) {
                gApSelectedIndex[0] = 0;
            } else if (direction == 1) {
                gApSelectedIndex[0] = 3;
            } else {
                gApSelectedIndex[0] = 6;
            }
            break;
        case 3: {
            u8 rememberedIndex = gAp->mRememberedEntryIndex;
            s32 targetIndex = rememberedIndex + 4;
            if (direction == 1) {
                gApSelectedIndex[0] = targetIndex;
            } else if (direction == 3) {
                gApSelectedIndex[0] = rememberedIndex;
            } else {
                moved = 0;
            }
            break;
        }
        case 4:
            gAp->mRememberedEntryIndex = 0;
            if (direction == 0) {
                gApSelectedIndex[0] = 6;
            } else if (direction == 2) {
                gApSelectedIndex[0] = 5;
            } else if (direction == 1) {
                gApSelectedIndex[0] = 0;
            } else {
                gApSelectedIndex[0] = 3;
            }
            break;
        case 5:
            gAp->mRememberedEntryIndex = 1;
            if (direction == 0) {
                gApSelectedIndex[0] = 4;
            } else if (direction == 2) {
                gApSelectedIndex[0] = 6;
            } else if (direction == 1) {
                gApSelectedIndex[0] = 1;
            } else {
                gApSelectedIndex[0] = 3;
            }
            break;
        case 6:
            gAp->mRememberedEntryIndex = 2;
            if (direction == 0) {
                gApSelectedIndex[0] = 5;
            } else if (direction == 2) {
                gApSelectedIndex[0] = 4;
            } else if (direction == 1) {
                gApSelectedIndex[0] = 2;
            } else {
                gApSelectedIndex[0] = 3;
            }
            break;
    }
    if (moved != 0) {
        StartSoundSeq(8);
        PlaceApSelection();
    }
}

void SetApSelectedButtonImage(void) {
    s32 entryIndex = gApSelectedIndex[0] - 4;
    CopyNceImageToOamEntries(0, 0x32, GetOamRangeEntry(gAp->mResetButtonObjects[entryIndex], 0));
    SetOamRangePosition(gAp->mResetButtonObjects[entryIndex], -1, gApObjectPositions[entryIndex + 3].mX,
                        gApObjectPositions[entryIndex + 3].mY);
    SetOamRangePriority(gAp->mResetButtonObjects[entryIndex], -1, 3);
}

void UpdateApMessageResult(void) {
    s32 entryIndex = gApSelectedIndex[0] - 4;
    switch (GetMessageBoxResult()) {
        case 1:
            StartSoundSeq(0xe);
            ResetApEntry(entryIndex);
            CopyNceImageToOamEntries(0, gApEntryImageIndices[3],
                                     GetOamRangeEntry(gAp->mEntryIconObjects[entryIndex], 0));
            SetOamRangePosition(gAp->mEntryIconObjects[entryIndex], -1, gApObjectPositions[entryIndex].mX,
                                gApObjectPositions[entryIndex].mY);
            SetOamRangePriority(gAp->mEntryIconObjects[entryIndex], -1, 3);
            DeleteOamRange(gAp->mResetButtonObjects[entryIndex]);
            gAp->mResetButtonObjects[entryIndex] = NULL;
            break;
        case 0:
            StartSoundSeq(7);
            CopyNceImageToOamEntries(0, 0x11, GetOamRangeEntry(gAp->mResetButtonObjects[entryIndex], 0));
            SetOamRangePosition(gAp->mResetButtonObjects[entryIndex], -1, gApObjectPositions[entryIndex + 3].mX,
                                gApObjectPositions[entryIndex + 3].mY);
            SetOamRangePriority(gAp->mResetButtonObjects[entryIndex], -1, 3);
            break;
        default:
            return;
    }
    CloseMessageBox();
    SetUpdateFunction(UpdateApMessageClose);
}

void UpdateApMessageClose(void) {
    int messageOpen;
    messageOpen = IsMessageBoxOpen();
    if (messageOpen == 0) {
        EnableButtonTouch();
        SetUpdateFunction(UpdateAp);
    }
}

void RequestApSelectionPalette(void) {
    Bytes4 paletteRows;
    Bytes4 iconPalettes;
    int statusIndex;
    paletteRows = gApPaletteRows;
    iconPalettes = gApEntryIconPalettes;
    if (*(u8 *) &gApSelectedIndex <= 3) {
        RequestBgPaletteRowCopy(gAp->mYbBgStep11Ncl, paletteRows.mBytes[*(u8 *) &gApSelectedIndex],
                                paletteRows.mBytes[*(u8 *) &gApSelectedIndex]);
        if (*(u8 *) &gApSelectedIndex != 3) {
            statusIndex = GetApEntrySetType(*(u8 *) &gApSelectedIndex);
            if (statusIndex > 2) {
                statusIndex = 3;
            }
            SetOamRangeMode(gAp->mEntryIconObjects[*(u8 *) &gApSelectedIndex], -1, 0, iconPalettes.mBytes[statusIndex]);
        }
    }
}
