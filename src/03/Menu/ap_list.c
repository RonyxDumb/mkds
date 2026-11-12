#include "03/Menu/ap_list.h"

#include "03/unk_021d5000.h"
#include "03/unk_021da000.h"
#include "03/Menu/selection_objects.h"
#include "03/Menu/scroll_bar.h"
#include "code_0212df7c.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d3000.h"
#include "03/System/tasks.h"
#include "registers.h"
#include "code_02147cd8.h"
#include "03/System/string_length.h"
#include "code_0214d018.h"
#include "code_02012b30.h"
#include "03/Menu/way.h"
#include "03/code_021cbf60.h"
#include "03/Menu/message_box_create.h"
#include "03/System/dwc_archive.h"
#include "03/code_021d1dd0.h"
#include "03/unk_021d6000.h"
#include "03/code_021c6000.h"
#include "03/code_021c2000.h"
#include "03/Menu/menu_pair_loading.h"
#include "03/Menu/slide_buttons.h"
#include "03/Menu/sub_screen_message.h"
#include "03/System/application.h"
#include "03/code_021cb000.h"
#include "03/Graphics/bg2_scr_buffer.h"
#include "03/code_021cd000.h"
#include "03/Net/ap_scan.h"
#include "03/Net/essid_wcm.h"
#include "03/code_021cd2e0.h"
#include "03/code_021d1000.h"
#include "03/code_021d1f70.h"
#include "03/Graphics/dispcnt_window.h"
#include "03/code_021d2ecc.h"
#include "03/Graphics/text_canvas.h"
#include "03/System/exp_heap.h"
#include "03/code_021bf000.h"
#include "03/code_021c5000.h"
#include "03/code_021ce000.h"
#include "03/unk_021d7000.h"
#include "gx_load2d.h"
#include "03/Menu/value_records_next.h"
#include "03/System/task_input.h"
#include "03/Graphics/hl_scr.h"
#include "os_thread.h"
#include "code_0214cfe4.h"
#include "03/code_021d1c18.h"
#include "03/code_021c6764.h"
#include "03/Menu/ap_scan_screen.h"
#include "03/Net/ap_scan_callback.h"

void CreateApList(void) {
    s32 secondaryPairFirst;
    gApList = AllocZeroedExpHeapBlock(0x5c, 4);
    GetSecondaryMenuPair(&secondaryPairFirst, NULL);
    if (secondaryPairFirst == 0) {
        gApListSelectedRow = 0;
        *(u16 *) &gApListScrollY = 0;
    }
    gApList->mEntryCount = CountApScanEntries((s32 *) gApList);
    LoadApListFilesAndSetBgCnt();
    LoadHlSetScr();
    ShowSubScreenMessage(0x80, -1, 0);
    CreateObjectsForMenuPair(2);
    SetupApListScroll();
    CreateApListRowObjects();
    gApList->mTextCanvas = InitBgTextCanvas(0, 0);
    gApList->mBgOffsetTask = AddTask(1, WriteApListBgOffset, NULL, 0x6e);
    RefreshApList();
    PlaceApListSelection();
    SetUpdateFunction(StartApListFadeIn);
}

void LoadApListFilesAndSetBgCnt(void) {
    u8 xb4ApListBackNscName[0x19] = "char/xb4ApListBack.nsc.l";
    u8 ybBgStep31NclName[0x16] = "char/ybBgStep31.ncl.l";
    LoadFileToVram(gJb4ApListNscName, GX_LoadBG3Scr);
    gApList->mXb4ApListBackNsc = LoadFile(BuildFilePathWithLanguage(xb4ApListBackNscName), NULL, 4);
    CreateBg2ScrBuffer(gApList->mXb4ApListBackNsc);
    RequestBg2ScrUpload();
    gApList->mYbBgStep31Ncl = LoadFile(BuildFilePathWithLanguage(ybBgStep31NclName), NULL, 4);
    reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & ~3) | 3;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & ~3) | 3;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~3) | 3;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & ~3) | 2;
    reg_G2_BG2CNT = (reg_G2_BG2CNT & ~3) | 3;
    reg_G2_BG3CNT = (reg_G2_BG3CNT & ~3) | 2;
}

void SetupApListScroll(void) {
    int entryCountRange;
    u32 offset;
    offset = 0;
    gApList->mScrollYMax = (gApList->mEntryCount - 4) * 0x1c;
    if (gApList->mEntryCount <= 4) {
        entryCountRange = 0;
        gApList->mScrollBarOffsetMax = 0;
    } else if (gApList->mEntryCount <= 8) {
        entryCountRange = 1;
        gApList->mScrollBarOffsetMax = 0x1f;
    } else {
        entryCountRange = 2;
        gApList->mScrollBarOffsetMax = 0x37;
    }
    if (entryCountRange != 0) {
        offset = FX_DivS32(*(u16 *) &gApListScrollY * gApList->mScrollBarOffsetMax, gApList->mScrollYMax);
    }
    CreateScrollBar(entryCountRange, 0x55, 0xec, 0x3f, offset);
}

void CreateApListRowObjects(void) {
    int rowCount;
    int i;
    u32 imageIndex;
    rowCount = gApList->mEntryCount;
    if (rowCount > 5) {
        rowCount = 5;
    }
    for (i = 0; i < rowCount; i++) {
        gApList->mRowLeftOamEntries[i] = CreateOamEntryFromNceImage(0, gApListRowLeftImageIndices[0]);
        gApList->mRowRightOamEntries[i] = CreateOamEntryFromNceImage(0, gApListRowRightImageIndices[0]);
    }
    for (imageIndex = 0; imageIndex < 3; imageIndex++) {
        CopyNceImageToOamEntries(0, gApListRowLeftImageIndices[imageIndex], gApList->mRowLeftOamEntries[0]);
        gApList->mRowLeftTiles[imageIndex] = gApList->mRowLeftOamEntries[0]->mAttr2 & 0x3ff;
    }
    for (imageIndex = 0; imageIndex < 4; imageIndex++) {
        CopyNceImageToOamEntries(0, gApListRowRightImageIndices[imageIndex], gApList->mRowRightOamEntries[0]);
        gApList->mRowRightTiles[imageIndex] = gApList->mRowRightOamEntries[0]->mAttr2 & 0x3ff;
    }
    for (i = 0; i < rowCount; i++) {
        OamEntry *oamEntry;
        oamEntry = gApList->mRowLeftOamEntries[i];
        oamEntry->mAttr2 = (oamEntry->mAttr2 & 0xfffff3ff) | 0xc00;
        oamEntry = gApList->mRowRightOamEntries[i];
        oamEntry->mAttr2 = (oamEntry->mAttr2 & 0xfffff3ff) | 0xc00;
    }
}

void StartApListFadeIn(void) {
    StartBlendBrightnessFade(2, 1, 1, 8);
    StartBlendBrightnessFade(2, 0, 0x1d, 8);
    CombineDispcntBits(1, 1);
    CombineDispcntBits(0, 0x1d);
    SetUpdateFunction(UpdateApListFadeIn);
}

void UpdateApListFadeIn(void) {
    int fadeSlotBusy;
    fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(1);
    if ((fadeSlotBusy == 0) && (fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(0), fadeSlotBusy == 0)) {
        CreateSlideButtonsForMenuPair(0);
        SetUpdateFunction(UpdateApListButtonsIn);
    }
}

void UpdateApListButtonsIn(void) {
    if (GetButtonResult() != -2) {
        EnableButtonTouch();
        SetUpdateFunction(UpdateApList);
    }
}

void UpdateApList(void) {
    UpdateApListInput();
    UpdateApListScroll();
    UpdateApListResult();
}

void UpdateApListInput(void) {
    int row;
    Rect *rowRect;
    if (gApList->mScrollTask != 0) {
        return;
    }
    if (gApList->mScrollBarDragging != 0) {
        return;
    }
    if (IsTouchPressedInRect(&gTouchScreenRect) != 0) {
        row = 0;
        gApList->mHitRow = -1;
        rowRect = gApListRowRects;
        do {
            if (IsTouchPressedInRect(rowRect) != 0) {
                if (row < 4) {
                    gApList->mHitRow = row;
                    break;
                }
                SetButtonResultIfNone(1);
                gApListSelectedRow = row;
                PlaceApListSelection();
                return;
            }
            rowRect++;
            row++;
        } while ((u32) row < 5);
    }
    if (IsTouchReleasedInRect(&gTouchScreenRect) != 0) {
        row = 0;
        rowRect = gApListRowRects;
        do {
            if (IsTouchReleasedInRect(rowRect) != 0) {
                if (gApList->mHitRow != row) {
                    break;
                }
                if (row >= gApList->mEntryCount) {
                    StartSoundSeq(9);
                    break;
                }
                SetButtonResultIfNone(1);
                gApListSelectedRow = row;
                PlaceApListSelection();
                return;
            }
            rowRect++;
            row++;
        } while (row < 4);
    }
    if (AreKeysPressed(1) != 0) {
        SetButtonResultIfNone(1);
        DisableScrollBarInput();
        return;
    }
    if (AreKeysPressed(2) != 0) {
        SetButtonResultIfNone(0);
        return;
    }
    if (AreKeysPressedOrRepeated(0x200) != 0) {
        StartApListScrollYIncrease();
        return;
    }
    if (AreKeysReleased(0x200) != 0) {
        gApList->mKeyBlockedSoundPlayed = 0;
        return;
    }
    if (AreKeysPressedOrRepeated(0x100) != 0) {
        StartApListScrollYDecrease();
        return;
    }
    if (AreKeysReleased(0x100) != 0) {
        gApList->mKeyBlockedSoundPlayed = 0;
        return;
    }
    if (AreKeysPressedOrRepeated(0x40) != 0) {
        MoveApListSelectedRow(1);
        return;
    }
    if (AreKeysReleased(0x40) != 0) {
        gApList->mKeyBlockedSoundPlayed = 0;
        return;
    }
    if (AreKeysPressedOrRepeated(0x80) != 0) {
        MoveApListSelectedRow(3);
        return;
    }
    if (AreKeysReleased(0x80) != 0) {
        gApList->mKeyBlockedSoundPlayed = 0;
    }
}

void UpdateApListScroll(void) {
    ApList *apList;
    int rowOffset;
    apList = gApList;
    if (apList->mScrollTask != 0) {
        return;
    }
    if (apList->mScrollTimer != 0) {
        apList->mScrollTimer--;
    }
    switch (GetScrollBarEvent()) {
        case 1:
            gApList->mScrollBarDragging = 1;
            DisableButtonTouch();
            break;
        case 2:
            if (gApList->mScrollTimer == 0) {
                ReleaseSelectionObjectSlots();
                *(u16 *) &gApListScrollY =
                    FX_DivS32(gApList->mScrollYMax * GetScrollBarOffset(), gApList->mScrollBarOffsetMax);
                RefreshApList();
                gApList->mScrollTimer = 4;
            }
            break;
        case 3:
            gApList->mScrollBarDragging = 0;
            EnableButtonTouch();
            *(u16 *) &gApListScrollY =
                FX_DivS32(gApList->mScrollYMax * GetScrollBarOffset(), gApList->mScrollBarOffsetMax);
            StartSoundSeq(0x13);
            RefreshApList();
            rowOffset = FX_ModS32(*(u16 *) &gApListScrollY, 0x1c);
            if (rowOffset == 0) {
                PlaceApListSelection();
            } else if (rowOffset < 0xe) {
                gApList->mScrollTask = AddTask(0, AdvanceApListScrollYDecrease, NULL, 0x78);
            } else {
                gApList->mScrollTask = AddTask(0, AdvanceApListScrollYIncrease, NULL, 0x78);
            }
            break;
        case 4:
            if (*(u16 *) &gApListScrollY == 0) {
                if (gApList->mBarBlockedSoundPlayed == 0) {
                    StartSoundSeq(9);
                    gApList->mBarBlockedSoundPlayed = 1;
                }
            } else {
                StartSoundSeq(0x13);
                gApList->mScrollTask = AddTask(0, AdvanceApListScrollYDecrease, NULL, 0x78);
            }
            break;
        case 6:
            apList = gApList;
            if (apList->mEntryCount <= 4 || *(u16 *) &gApListScrollY == apList->mScrollYMax) {
                if (apList->mBarBlockedSoundPlayed == 0) {
                    StartSoundSeq(9);
                    gApList->mBarBlockedSoundPlayed = 1;
                }
            } else {
                StartSoundSeq(0x13);
                gApList->mScrollTask = AddTask(0, AdvanceApListScrollYIncrease, NULL, 0x78);
            }
            break;
        case 5:
        case 7:
            gApList->mBarBlockedSoundPlayed = 0;
            break;
    }
}

void UpdateApListResult(void) {
    int entryIndex;
    if (gApList->mScrollTask == 0 && gApList->mScrollBarDragging == 0) {
        switch (GetButtonResult()) {
            case 0:
                StartSoundSeq(7);
                break;
            case 1:
                if (gApListSelectedRow == 4) {
                    gApList->mSelectionMade = 1;
                    StartSoundSeq(6);
                    RequestApListPaletteRowCopy();
                } else {
                    entryIndex = gApListSelectedRow + FX_DivS32(*(u16 *) &gApListScrollY, 0x1c);
                    if ((gApList->mEntries + entryIndex * 0x2a)[0x28] == 2) {
                        StartSoundSeq(9);
                        DisableScrollBarInput();
                        DisableButtonTouch();
                        CreateMessageBox(0x42, 1, 1, -1, 0);
                        SetUpdateFunction(UpdateApListMessageResult);
                        return;
                    }
                    gApList->mSelectionMade = 1;
                    gApList->mEntryIndex = entryIndex;
                    StartSoundSeq(6);
                }
                break;
            default:
                return;
        }
        SetUpdateFunction(StartApListClose);
    }
}

void StartApListClose(void) {
    DisableButtonTouch();
    StartBlendBrightnessFadeWait(8);
    SetUpdateFunction(UpdateApListFadeOut);
}

void UpdateApListFadeOut(void) {
    if (IsBlendBrightnessFadeSlotBusy(1) == 0) {
        if (gApList->mSelectionMade != 0) {
            StartSlideButtonsOut();
        } else {
            DisableButtonTouch();
        }
        StartBlendBrightnessFade(3, 1, 1, 8);
        StartBlendBrightnessFade(3, 0, 0x1d, 8);
        SetUpdateFunction(UpdateApListRelease);
    }
}

void UpdateApListRelease(void) {
    int i;
    ApList *apList;
    if (IsBlendBrightnessFadeSlotBusy(1) != 0) {
        return;
    }
    if (IsBlendBrightnessFadeSlotBusy(0) != 0) {
        return;
    }
    if (IsSlideButtonsNotSlidingOut() == 0) {
        return;
    }
    RemoveTaskEntryWrapper(1, gApList->mBgOffsetTask);
    for (i = 0; i < 5; i++) {
        if (gApList->mRowLeftOamEntries[i] != NULL) {
            DeleteOamEntry((u32 *) gApList->mRowLeftOamEntries[i]);
        }
        if (gApList->mRowRightOamEntries[i] != NULL) {
            DeleteOamEntry((u32 *) gApList->mRowRightOamEntries[i]);
        }
    }
    ReleaseBgTextCanvas(gApList->mTextCanvas);
    ReleaseScrollBar();
    ReleaseSelectionObjectSlots();
    HideSubScreenMessage();
    ReleaseBg2ScrBuffer();
    DeleteLoadedFile(gApList->mXb4ApListBackNsc);
    DeleteLoadedFile(gApList->mYbBgStep31Ncl);
    ClearDispcntBits(1, 1);
    ClearDispcntBits(0, 0x1d);
    reg_G2_BG0OFS = 0;
    reg_G2_BG2OFS = 0;
    apList = gApList;
    if (apList->mSelectionMade == 0) {
        ReleaseApScan();
        CopyApEntryToWorkCopy(GetApWorkCopy()->mEntryIndex);
        SetPrimaryMenuPair(2, 0);
        SetUpdateFunction(SetupWay);
    } else if (gApListSelectedRow == 4) {
        ReleaseApScan();
        SetPrimaryMenuPair(0, 1);
        SetUpdateFunction(SetupApScan);
    } else {
        StoreApWorkSsid(apList->mEntries + apList->mEntryIndex * 0x2a);
        SetPrimaryMenuPair(0, 0);
        if ((gApList->mEntries + gApList->mEntryIndex * 0x2a)[0x28] != 0) {
            SetPrimaryMenuPair(0, 1);
            SetSecondaryMenuPair(1, 1);
            SetUpdateFunction(CreateEdit);
        } else {
            SetPrimaryMenuPair(0, 1);
            SetSecondaryMenuPair(0, 1);
            SetUpdateFunction(SetupConnectMessage);
        }
    }
    FreeExpHeapBlockAndClearPointer(&gApList);
}

void RefreshApList(void) {
    int entryIndex;
    int slot;
    int index;
    int visibleRowCount;
    entryIndex = FX_DivS32(*(u16 *) &gApListScrollY, 0x1c);
    visibleRowCount = gApList->mEntryCount;
    ClearBgTextCanvas(gApList->mTextCanvas, 0);
    if (5 < visibleRowCount) {
        visibleRowCount = 5;
    }
    slot = 0;
    index = entryIndex;
    if (visibleRowCount > 0) {
        do {
            PrintApListEntryText(index, slot);
            slot = slot + 1;
            index = index + 1;
        } while (slot < visibleRowCount);
    }
    index = 0;
    if (visibleRowCount > 0) {
        do {
            SetApListRowTiles(entryIndex, index);
            index = index + 1;
            entryIndex = entryIndex + 1;
        } while (index < visibleRowCount);
    }
    RequestBgTextCanvasUpload(gApList->mTextCanvas);
    RefreshApListRowPositions();
}

void PrintApListEntryText(int entryIndex, int yPos) {
    u16 lineText[17];
    int textLength;
    int entryOffset;
    int i;
    int lineLength;
    entryOffset = entryIndex * 0x2a;
    textLength = GetStringLengthWithLimit(gApList->mEntries + entryOffset, 0x20);
    yPos *= 0x1c;
    if (entryIndex < gApList->mEntryCount) {
        if (textLength <= 0x10) {
            yPos += 6;
        }
        MI_CpuFill8(lineText, 0, 0x22);
        if (textLength <= 0x10) {
            lineLength = textLength;
        } else {
            lineLength = 0x10;
        }
        for (i = 0; i < lineLength; i++) {
            lineText[i] = (gApList->mEntries + entryOffset)[i];
        }
        DrawCharsCentered(gApList->mTextCanvas, 0xa, yPos, 2, 0xa, lineText, 1);
        if (textLength > 0x10) {
            MI_CpuFill8(lineText, 0, 0x22);
            lineLength = textLength - 0x10;
            for (i = 0; i < lineLength; i++) {
                lineText[i] = (gApList->mEntries + entryOffset)[i + 0x10];
            }
            yPos += 0xc;
            DrawCharsCentered(gApList->mTextCanvas, 0xa, yPos, 2, 0xa, lineText, 1);
        }
    }
}

void SetApListRowTiles(int entryIndex, int rowSlot) {
    OamEntry *oamEntry;
    int entryOffset;
    if (entryIndex < gApList->mEntryCount) {
        oamEntry = gApList->mRowLeftOamEntries[rowSlot];
        entryOffset = entryIndex * 0x2a;
        oamEntry->mAttr2 =
            (oamEntry->mAttr2 & ~0x3ff) | gApList->mRowLeftTiles[*(gApList->mEntries + entryOffset + 0x28)];
        oamEntry = gApList->mRowRightOamEntries[rowSlot];
        oamEntry->mAttr2 =
            (oamEntry->mAttr2 & ~0x3ff) | gApList->mRowRightTiles[*(u16 *) (gApList->mEntries + entryOffset + 0x26)];
    }
}

void RefreshApListRowPositions(void) {
    int yPos;
    int rowCount;
    int i;
    yPos = 0x36 - FX_ModS32(*(u16 *) &gApListScrollY, 0x1c);
    rowCount = gApList->mEntryCount;
    if (rowCount > 5) {
        rowCount = 5;
    }
    for (i = 0; i < rowCount; i++, yPos += 0x1c) {
        OamEntry *oamEntry;
        oamEntry = gApList->mRowLeftOamEntries[i];
        oamEntry->mAttr01 = (oamEntry->mAttr01 & 0xfe00ff00) | ((yPos - 2) & 0xff) | 0xb30000;
        oamEntry = gApList->mRowRightOamEntries[i];
        oamEntry->mAttr01 = (oamEntry->mAttr01 & 0xfe00ff00) | ((yPos + 1) & 0xff) | 0xd20000;
    }
    gApList->mBgOffsetPending = 1;
}

void AdvanceApListScrollYDecrease(u32 task) {
    int rowOffset;
    DisableScrollBarInput();
    ReleaseSelectionObjectSlots();
    if (*(u16 *) &gApListScrollY > 4) {
        *(u16 *) &gApListScrollY = *(u16 *) &gApListScrollY - 4;
    } else {
        *(u16 *) &gApListScrollY = 0;
    }
    rowOffset = FX_ModS32(*(u16 *) &gApListScrollY, 0x1c);
    if (rowOffset == 0x18) {
        RefreshApList();
        return;
    }
    if (rowOffset > 0x18) {
        *(u16 *) &gApListScrollY = *(u16 *) &gApListScrollY + (0x1c - rowOffset);
        rowOffset = 0;
    }
    RefreshApListRowPositions();
    if (rowOffset == 0) {
        PlaceScrollBarWrapper(FX_DivS32(*(u16 *) &gApListScrollY * gApList->mScrollBarOffsetMax, gApList->mScrollYMax));
        EnableScrollBarInput();
        PlaceApListSelection();
        gApList->mScrollTask = 0;
        RequestTaskRemoval(0, task);
    }
}

void AdvanceApListScrollYIncrease(u32 task) {
    int rowOffset;
    DisableScrollBarInput();
    ReleaseSelectionObjectSlots();
    *(u16 *) &gApListScrollY = *(u16 *) &gApListScrollY + 4;
    rowOffset = FX_ModS32(*(u16 *) &gApListScrollY, 0x1c);
    if (rowOffset >= 4) {
        RefreshApListRowPositions();
        return;
    }
    *(u16 *) &gApListScrollY = *(u16 *) &gApListScrollY - rowOffset;
    RefreshApList();
    PlaceScrollBarWrapper(FX_DivS32(*(u16 *) &gApListScrollY * gApList->mScrollBarOffsetMax, gApList->mScrollYMax));
    EnableScrollBarInput();
    PlaceApListSelection();
    gApList->mScrollTask = 0;
    RequestTaskRemoval(0, task);
}

void WriteApListBgOffset(void) {
    int rowOffset;
    u32 bgOffset;
    if (gApList->mBgOffsetPending != 0) {
        rowOffset = FX_ModS32(*(u16 *) &gApListScrollY, 0x1c);
        bgOffset = (rowOffset + -0x32) * 0x10000 & (0x01ff0000u);
        reg_G2_BG0OFS = bgOffset;
        reg_G2_BG2OFS = bgOffset;
        gApList->mBgOffsetPending = 0;
    }
}

void PlaceApListSelection(void) {
    u8 selectedRow;
    int pairIndex;
    selectedRow = gApListSelectedRow;
    if (selectedRow < 4) {
        pairIndex = 2;
    } else {
        pairIndex = 3;
    }
    PlaceSelectionPair(pairIndex, gApListSelectionLeftX[selectedRow * 4], gApListSelectionRightX[selectedRow * 4],
                       gApListSelectionYPos[selectedRow * 4]);
}

void MoveApListSelectedRow(int direction) {
    BOOL moved;
    u8 selectedRow;
    moved = TRUE;
    selectedRow = gApListSelectedRow;
    switch (selectedRow) {
        case 0:
            if (direction == 1) {
                if (*(u16 *) &gApListScrollY == 0) {
                    gApListSelectedRow = 4;
                } else {
                    StartSoundSeq(0x13);
                    gApList->mScrollTask = AddTask(0, AdvanceApListScrollYDecrease, NULL, 0x78);
                    return;
                }
            } else if (gApList->mEntryCount > 1) {
                gApListSelectedRow = selectedRow + 1;
            } else {
                moved = FALSE;
            }
            break;
        case 1:
        case 2:
            if (direction == 1) {
                gApListSelectedRow = selectedRow - 1;
            } else if (gApList->mEntryCount > selectedRow + 1) {
                gApListSelectedRow++;
            } else {
                moved = FALSE;
            }
            break;
        case 3:
            if (direction == 1) {
                gApListSelectedRow = selectedRow - 1;
            } else {
                StartApListScrollYIncrease();
                return;
            }
            break;
        case 4:
            if (direction == 1) {
                moved = FALSE;
            } else {
                *(u16 *) &gApListScrollY = 0;
                gApListSelectedRow = 0;
                RefreshApList();
                PlaceScrollBarWrapper(0);
            }
            break;
    }
    if (moved == FALSE) {
        if (gApList->mKeyBlockedSoundPlayed == 0) {
            StartSoundSeq(9);
            gApList->mKeyBlockedSoundPlayed = 1;
        }
    } else {
        StartSoundSeq(8);
        PlaceApListSelection();
    }
}

void StartApListScrollYDecrease(void) {
    if (*(u16 *) &gApListScrollY == 0) {
        if (gApList->mKeyBlockedSoundPlayed == 0) {
            StartSoundSeq(9);
            gApList->mKeyBlockedSoundPlayed = 1;
        }
    } else {
        StartSoundSeq(0x13);
        gApList->mScrollTask = AddTask(0, AdvanceApListScrollYDecrease, NULL, 0x78);
    }
}

void StartApListScrollYIncrease(void) {
    if (*(u16 *) &gApListScrollY == gApList->mScrollYMax || gApList->mEntryCount <= 4) {
        if (gApList->mKeyBlockedSoundPlayed == 0) {
            StartSoundSeq(9);
            gApList->mKeyBlockedSoundPlayed = 1;
        }
    } else {
        StartSoundSeq(0x13);
        gApList->mScrollTask = AddTask(0, AdvanceApListScrollYIncrease, NULL, 0x78);
    }
}

void RequestApListPaletteRowCopy(void) {
    volatile u8 tableByte;
    u8 paletteRow;
    tableByte = gApListPaletteRow[0];
    paletteRow = tableByte;
    RequestBgPaletteRowCopy(gApList->mYbBgStep31Ncl, paletteRow, paletteRow);
}
