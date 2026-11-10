#include "Main/Unknown/code_020351c8.h"

#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_02125000.h"
#include "Main/Unknown/code_02125ed0.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_02126000.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_0212658c.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02126230.h"
#include "Main/Unknown/code_0202578c.h"
#include "Main/Unknown/code_0202d990.h"
#include "Main/Unknown/code_0202dd9c.h"
#include "Main/Unknown/code_0202e4b0.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0202db04.h"
#include "Main/Unknown/code_0202e468.h"
#include "Main/Unknown/code_02025b84.h"
#include "Main/Unknown/code_02025bb4.h"
#include "Main/Unknown/code_0203434c.h"
#include "Main/Unknown/unk_0217a000.h" // GhostRecord
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0204f7f4.h"
#include "Main/Unknown/code_020566a8.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02124f4c.h"
#include "Main/Unknown/code_02125ee8.h"
#include "Main/Unknown/code_02125f2c.h"
#include "Main/Unknown/code_02125f54.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/code_0212775c.h"
#include "code_02148950.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02153000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "00/code_02181f98.h"
#include "code_0212d214.h"
#include "code_0214cfe4.h"
#include "Main/Unknown/code_02025d5c.h"
#include "01/code_021956dc.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_02025edc.h"
#include "Main/Unknown/code_02025f80.h"
#include "Main/Unknown/code_02025cd0.h"
#include "registers.h"

#pragma thumb on

void RefreshSlotGhostListRows(s32 action, s32 slot, s32 listIndex, s32 selectedSlot) {
    CellFileSet *subCellFileSet;
    s32 i;
    s32 paletteIndex;
    s32 timeLabelIndex;
    MinuteSecondMillisecondTime time;
    s16 timeText[12];

    subCellFileSet = &gTimeAttackGhostGetSlot->mCellFileSets[1];
    if (action == 1) {
        listIndex += GetCourseGhostCount();
        PrintLabelLayoutTextNoFixedAdvance(1, slot, subCellFileSet->mLabelLayout,
                                           GetBmgEntry(gTimeAttackGhostGetSlot->mGhostMessages,
                                                       GetGhostCourseMessageIndex(GetListedGhostCourseId(listIndex))),
                                           subCellFileSet->mCellLayout, subCellFileSet->mCellTable);
        GetListedGhostTime(listIndex, &time);
        WriteMinuteSecondMillisecondText(timeText, time.mMinute, time.mSecond, time.mMillisecond);
        PrintLabelLayoutTextFixedDigits(1, slot + 7, subCellFileSet->mLabelLayout, timeText,
                                        subCellFileSet->mCellLayout, subCellFileSet->mCellTable, 7);
    } else if (action == 0) {
        for (i = 0; i < 7; i++) {
            timeLabelIndex = i + 7;
            if (i == selectedSlot) {
                paletteIndex = 14;
            } else {
                paletteIndex = 15;
            }
            SetLabelPaletteIndex(i, paletteIndex, subCellFileSet->mLabelLayout, subCellFileSet->mCellTable,
                                 subCellFileSet->mCellLayout);
            SetLabelPaletteIndex(timeLabelIndex, paletteIndex, subCellFileSet->mLabelLayout, subCellFileSet->mCellTable,
                                 subCellFileSet->mCellLayout);
        }
    }
}

#pragma thumb off

#pragma thumb on

void SetupGhostMainTextEx(void) {
    void *message;
    message = GetBmgEntry(gTimeAttackGhostGetSlot->mGhostMessages, 3);
    SetTxtSystemBgOffsetRequested(0xfffffff4, 0);
    SetupTxtSystemMainTextEx(message, 0, 0, 0, 0, 0, 0);
}

#pragma thumb off

#pragma thumb on

static inline s32 func_0203551c_inline(void) {
    BackupAccess *p = gBackupAccess;
    if (p->mBackupEnabled != 0) {
        return p->mCommandRunning;
    }
    return 0;
}

static inline s32 func_0203551c_inline_2(void) {
    if (data_0217aa08->mBusy == 0) {
        return func_0203551c_inline();
    }
    return 1;
}

void SetupGhostNameSubTextTwoButtons(void) {
    void *formatText;
    void *firstButtonText;
    void *secondButtonText;
    u8 ghostName[0x14];
    u16 nameText[11];
    u16 formattedText[0x100];

    formatText = GetBmgEntry(gTimeAttackGhostGetSlot->mGhostMessages, 0x12);
    firstButtonText = GetBmgEntry(gTimeAttackGhostGetSlot->mCommonMessages, 0);
    secondButtonText = GetBmgEntry(gTimeAttackGhostGetSlot->mCommonMessages, 1);
    GetListedGhostName(gTimeAttackGhostGetSlot->mSelectedIndex + GetCourseGhostCount(), ghostName);
    MIi_CpuCopy16(ghostName, nameText, 0x14);
    nameText[10] = 0;
    FormatMessageWithText(nameText, formatText, formattedText, 0x100);
    SetTxtSystemSoundId(0, -1);
    SetupTxtSystemSubTextTwoButtonsEx(formattedText, firstButtonText, secondButtonText, 1, 0, 1, 1, 0);
}

void UpdateSlotSlideOffsets(void) {
    CellFileSet *mainCellFileSet;
    CellFileSet *subCellFileSet;
    s32 mainEntryCount;
    s32 subEntryCount;
    s32 i;
    s16 offset;

    mainCellFileSet = &gTimeAttackGhostGetSlot->mCellFileSets[0];
    subCellFileSet = &gTimeAttackGhostGetSlot->mCellFileSets[1];
    mainEntryCount = mainCellFileSet->mCellLayout->mCount + mainCellFileSet->mLabelLayout->mCount;
    subEntryCount = subCellFileSet->mCellLayout->mCount + subCellFileSet->mLabelLayout->mCount;
    offset = GetInterpolatedValue(&gTimeAttackGhostGetSlot->mInterpolation);
    for (i = 0; i < mainEntryCount; i++) {
        mainCellFileSet->mCellTable[i].mOffsetY = -offset;
    }
    for (i = 0; i < subEntryCount; i++) {
        subCellFileSet->mCellTable[i].mOffsetY = offset;
    }
}

void PrintSelectedGhostRecord(void) {
    s32 listIndex;
    u32 characterIndex;
    u32 kartIndex;
    u32 courseId;
    MinuteSecondMillisecondTime time;
    u8 ghostName[0x14];
    u16 nameText[11];

    listIndex = GetCourseGhostCount() + gTimeAttackGhostGetSlot->mSelectedIndex;
    GetListedGhostTime(listIndex, &time);
    GetListedGhostName(listIndex, ghostName);
    MIi_CpuCopy16(ghostName, nameText, 0x14);
    nameText[10] = 0;
    characterIndex = GetListedGhostCharacterIndex(listIndex);
    kartIndex = GetListedGhostKartIndex(listIndex);
    courseId = GetListedGhostCourseId(listIndex);
    PrintGhostRecordInfo((SelectCharacter *) &gTimeAttackGhostGetSlot->mCellFileSets[0],
                         gTimeAttackGhostGetSlotMLabelTextRows, nameText, characterIndex, kartIndex, courseId, &time);
}

void InitTimeAttackGhostGetSlot(void *parentHeap, void *mainOam, void *subOam) {
    void *heap;
    CellFileSet *cellFileSet;
    s32 i;
    u32 remainingObjSize;
    s32 j;
    s32 assignedCount;
    s32 cellCount;
    s32 cellIndex;
    s32 labelIndex;
    s32 secondLabelIndex;
    s16 *row;
    LayoutTableEntry *cellTable;
    u16 groupFirstEntries[3];

    heap = CreateFrmHeapFromMaxFree(parentHeap);
    gTimeAttackGhostGetSlot = HeapAlloc(heap, 0xa8);
    MemFillWordsByBlock_inline(gTimeAttackGhostGetSlot, 0xa8);
    gTimeAttackGhostGetSlot->mHeap = heap;
    gTimeAttackGhostGetSlot->mOamLists[0] = mainOam;
    gTimeAttackGhostGetSlot->mOamLists[1] = subOam;
    gTimeAttackGhostGetSlot->mCommonMessages = FindFileInLoadedArchives(data_021644e0);
    gTimeAttackGhostGetSlot->mGhostMessages = FindSceneFile(data_021644ec);
    cellFileSet = &gTimeAttackGhostGetSlot->mCellFileSets[0];
    remainingObjSize = GX_GetSizeOfOBJ();
    LocateCellFileSet(cellFileSet, data_021644f8, data_02164518, data_02164538, data_02164558, data_02164574, NULL,
                      FindSceneFile);
    SetupCellFileSet(0, gTimeAttackGhostGetSlot->mHeap, cellFileSet);
    for (i = 0; i < cellFileSet->mLabelLayout->mCount; i++) {
        remainingObjSize -= SetupLabelCanvas(0, gTimeAttackGhostGetSlot->mHeap, cellFileSet,
                                             gTimeAttackGhostGetSlotMLabelTextRows[i], remainingObjSize);
    }
    LocateAndQueueScreenMapFileSet(1, gTimeAttackGhostGetSlot, data_02164590, data_021645b0, data_021645d0, 3,
                                   FindSceneFile);
    cellFileSet = &gTimeAttackGhostGetSlot->mCellFileSets[1];
    remainingObjSize = GX_GetSizeOfSubOBJ();
    assignedCount = 0;
    LocateCellFileSet(cellFileSet, data_021645ec, data_0216460c, data_0216462c, gTimeAttackGhostGetSBnclName,
                      gTimeAttackGhostGetSBnllName, gTimeAttackGhostGetSBnblName, FindSceneFile);
    SetupCellFileSet(1, gTimeAttackGhostGetSlot->mHeap, cellFileSet);
    cellCount = cellFileSet->mCellLayout->mCount;
    j = 0;
    if (j < cellFileSet->mLabelLayout->mCount) {
        row = gTimeAttackGhostGetSlotSLabelTextRows[0];
        do {
            if (row[3] < 0) {
                row[3] = cellCount + assignedCount++;
            }
            remainingObjSize -= SetupLabelCanvas(1, gTimeAttackGhostGetSlot->mHeap, cellFileSet,
                                                 gTimeAttackGhostGetSlotSLabelTextRows[j], remainingObjSize);
            row += 4;
            j++;
        } while (j < cellFileSet->mLabelLayout->mCount);
    }
    for (i = 0; i < 8; i++) {
        SetCellPriority(i, 3, cellFileSet->mCells, cellFileSet->mCellLayout);
    }
    for (j = 0, row = gTimeAttackGhostGetSlotSLabelTextRows[0]; j < 7; j++) {
        cellIndex = row[3];
        labelIndex = row[0];
        secondLabelIndex = gTimeAttackGhostGetSlotSLabelTextRows[j + 7][0];
        cellTable = cellFileSet->mCellTable;
        SetLayoutEntryPositionFromCell(cellIndex, &cellTable[cellIndex], cellFileSet->mCellLayout);
        SetLayoutEntryPositionFromLabel(labelIndex, &cellTable[labelIndex] + cellCount, cellFileSet->mLabelLayout);
        SetLayoutEntryPositionFromLabel(secondLabelIndex, &cellTable[secondLabelIndex] + cellCount,
                                        cellFileSet->mLabelLayout);
        row += 4;
    }
    SetLayoutEntryPositionFromCell(7, &cellFileSet->mCellTable[7], cellFileSet->mCellLayout);
    groupFirstEntries[0] = 0;
    groupFirstEntries[1] = cellCount;
    groupFirstEntries[2] = cellCount + 7;
    InitScrollList(gTimeAttackGhostGetSlot->mHeap, 3, groupFirstEntries, 7, 8, 0x7c, cellFileSet->mCellTable,
                   cellFileSet->mRects, gTimeAttackGhostGetSlot->mUnk_20 + 0xc, 0, 1, 2, 10, RefreshSlotGhostListRows);
    SetPlayerCharacterCellFileSet(0, &gTimeAttackGhostGetSlot->mCharacterCellFileSet);
    PrintSelectedGhostRecord();
    SetupInterpolation(&gTimeAttackGhostGetSlot->mInterpolation, 0, 10, -0xc0, 0);
    RequestSelectReturnState1();
    SetSelectReturnSoundId(0xf);
    SetupGhostMainTextEx();
    FrmHeapShrinkInParent(gTimeAttackGhostGetSlot->mHeap);
}

s32 AdvanceTimeAttackGhostGetSlot(u16 *sceneNumbers) {
    TimeAttackGhostGetSlot *object;
    enum { K0 = -1 } result;
    s32 touchInReturnRect;
    BOOL pairIsNew;
    BOOL pairRecentlyGone;
    s32 i;
    u16 slotIndex;
    u16 hasPair;
    void *message;
    CellFileSet *cellFileSets;
    void *buttonText;

    result = K0;
    slotIndex = GetPadInputSlot();
    touchInReturnRect = 0;
    AdvanceInterpolation(&gTimeAttackGhostGetSlot->mInterpolation);
    pairIsNew = FALSE;
    pairRecentlyGone = FALSE;
    hasPair = data_02175674[slotIndex].mPressedBits;
    if (hasPair == 0 && data_02175680[slotIndex].mPressedBits < 5) {
        pairRecentlyGone = TRUE;
    }
    if (pairRecentlyGone == FALSE && data_0217567c[slotIndex].mPressedBits == 0 && hasPair != 0) {
        pairIsNew = TRUE;
    }
    if (pairIsNew != FALSE) {
        touchInReturnRect = IsSelectReturnState2NoState3Or4RequestAndInRect(data_02175670[slotIndex].mPressedBits,
                                                                            data_02175672[slotIndex].mPressedBits);
    }
    object = gTimeAttackGhostGetSlot;
    switch (object->mState) {
        case 0:
            if (object->mInterpolation.mState == 1) {
                object->mState = 1;
            } else {
                UpdateSlotSlideOffsets();
            }
            break;
        case 1:
            if (IsTxtSystemState0NoOpenRequest() != 0) {
                SetupGhostMainTextEx();
            }
            AdvanceScrollList();
            i = GetScrollListSelectedRow();
            if (gTimeAttackGhostGetSlot->mSelectedIndex != i) {
                gTimeAttackGhostGetSlot->mSelectedIndex = i;
                PrintSelectedGhostRecord();
            }
            if (IsScrollListPickStarted() != 0) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 5);
            }
            if (IsScrollListPickFinished() != 0) {
                SetupGhostNameSubTextTwoButtons();
                RequestSelectReturnState4();
                gTimeAttackGhostGetSlot->mState = 2;
            } else if ((u16) (gInputSlots[slotIndex].mPressedBits & PAD_KEY_B) != 0 || touchInReturnRect != 0) {
                message = GetBmgEntry(gTimeAttackGhostGetSlot->mGhostMessages, 0x54);
                buttonText = GetBmgEntry(gTimeAttackGhostGetSlot->mCommonMessages, 4);
                SetTxtSystemSoundId(0, 5);
                SetupTxtSystemSubTextButton(message, buttonText);
                RequestSelectReturnState3WithSound(1);
                gTimeAttackGhostGetSlot->mUnk_a0 = FALSE;
                gTimeAttackGhostGetSlot->mState = 4;
            }
            break;
        case 2:
            if (GetTxtSystemInputAccepted() != 0 && GetTxtSystemSelectedIndex() == 0) {
                NNS_SndArcSetCurrent(&gOnMemorySndArc);
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 10);
                NNS_SndArcSetCurrent(&gFileSndArc);
            }
            if (GetTxtSystemDone() != 0) {
                if (GetTxtSystemSelectedIndex() == 0) {
                    GetSlotGhostBuffer()->mHead.mFilled = 1;
                    WriteSlotGhostRecord((u8) gTimeAttackGhostGetSlot->mSelectedIndex, GetSlotGhostBuffer());
                    gTimeAttackGhostGetSlot->mState = 3;
                } else {
                    RequestSelectReturnState1();
                    gTimeAttackGhostGetSlot->mState = 1;
                }
                RequestTxtSystemClose();
            }
            break;
        case 3:
            if (func_0203551c_inline_2() != 0) {
                message = GetBmgEntry(object->mGhostMessages, 0x10);
                buttonText = GetBmgEntry(gTimeAttackGhostGetSlot->mCommonMessages, 4);
                SetTxtSystemSoundId(0, 5);
                SetupTxtSystemSubTextButton(message, buttonText);
                gTimeAttackGhostGetSlot->mUnk_a0 = FALSE;
                gTimeAttackGhostGetSlot->mState = 4;
            }
            break;
        case 4:
            if (GetTxtSystemDone() != 0) {
                data_0217b488->mMenuEntryKind = 5;
                if (sceneNumbers != NULL) {
                    sceneNumbers[2] = 1;
                }
                gTimeAttackGhostGetSlot->mState = 5;
            }
            break;
    }
    for (i = 0; i < 2; i++) {
        cellFileSets = gTimeAttackGhostGetSlot->mCellFileSets;
        DrawLayoutTable(cellFileSets[i].mCellLayout, cellFileSets[i].mCells, cellFileSets[i].mLabelLayout,
                        gTimeAttackGhostGetSlot->mOamLists[i], cellFileSets[i].mCellTable);
    }
    return result;
}

#pragma thumb off

#pragma thumb on

void ReleaseTimeAttackGhostGetSlot(void) {
    HeapDestroy(gTimeAttackGhostGetSlot->mHeap);
    *(int *) &gTimeAttackGhostGetSlot = 0;
}

#pragma thumb off

#pragma thumb on

void WriteGhostGetSlotRegisters(void) {
    s32 offset;
    s32 negatedOffset;

    offset = GetInterpolatedValue(&gTimeAttackGhostGetSlot->mInterpolation);
    reg_G2_BG0OFS = (offset << 16) & 0x1ff0000;
    negatedOffset = -offset;
    reg_G2S_DB_BG3OFS = (negatedOffset << 16) & 0x1ff0000;
    if (offset != 0) {
        reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffff1fff) | 0x2000;
        reg_G2_WININ = (u32) ((reg_G2_WININ & ~0x3f) | 0x1f) | 0x20;
        reg_G2_WINOUT = (u32) ((reg_G2_WINOUT & ~0x3f) | 0xe) | 0x20;
        reg_G2_WIN0H = 0xff;
        reg_G2_WIN0V = ((negatedOffset << 8) & 0xff00) | 0xc0;
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffff1fff) | 0x2000;
        reg_G2S_DB_WININ = (u32) ((reg_G2S_DB_WININ & ~0x3f) | 0x1f) | 0x20;
        reg_G2S_DB_WINOUT = (u32) ((reg_G2S_DB_WINOUT & ~0x3f) | 7) | 0x20;
        reg_G2S_DB_WIN0H = 0xff;
        reg_G2S_DB_WIN0V = (offset + 0xc0) & 0xff;
    } else {
        reg_GX_DISPCNT = reg_GX_DISPCNT & 0xffff1fff;
        reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & 0xffff1fff;
    }
}

void StartTimeAttackGhostGetScanState15(void) {
    void *message;
    void *buttonText;

    message = GetBmgEntry(gTimeAttackGhostGetScan->mGhostMessages, 0x11);
    buttonText = GetBmgEntry(gTimeAttackGhostGetScan->mCommonMessages, 4);
    SetTxtSystemSoundId(0, 5);
    SetupTxtSystemSubTextButton(message, buttonText);
    gTimeAttackGhostGetScan->mStateFrames = 0;
    gTimeAttackGhostGetScan->mState = 15;
}

#pragma thumb off

#pragma thumb on

void SetupGhostMainTextShort(void) {
    void *message;
    message = GetBmgEntry(gTimeAttackGhostGetScan->mGhostMessages, 1);
    SetupTxtSystemMainTextShort(message, 0, 0, 0, 0, 0, 0);
}

#pragma thumb off

#pragma thumb on

// Selects the previous filled entry whose counter has run up to its end; a nonzero argument wraps from the first entry
// to the last.
void MoveSelectedGhostUp(s32 wrap) {
    BOOL found;
    s32 startIndex;
    s32 index;
    TimeAttackGhostGetScan *object;

    found = FALSE;
    object = gTimeAttackGhostGetScan;
    startIndex = object->mSelectedIndex;
    index = startIndex - 1;
    if (index < 0) {
        if (wrap == 0) {
            return;
        }
        index = 3;
    }
    if (index != startIndex) {
        do {
            if (object->mGhostInfoEntries[index].mFilled == TRUE &&
                object->mGhostInfoEntries[index].mInterpolation.mState == 1) {
                found = TRUE;
                object->mSelectedIndex = index;
                break;
            }
            index--;
            if (index < 0) {
                if (wrap == 0) {
                    return;
                }
                index = 3;
            }
        } while (index != object->mSelectedIndex);
    }
    if (found != FALSE) {
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0);
    }
}

// Selects the next filled entry whose counter has run up to its end; a nonzero argument wraps from the last entry to
// the first.
void MoveSelectedGhostDown(s32 wrap) {
    BOOL found;
    s32 startIndex;
    s32 index;
    TimeAttackGhostGetScan *object;

    found = FALSE;
    object = gTimeAttackGhostGetScan;
    startIndex = object->mSelectedIndex;
    index = startIndex + 1;
    if (index >= 4) {
        if (wrap == 0) {
            return;
        }
        index = 0;
    }
    if (index != startIndex) {
        do {
            if (object->mGhostInfoEntries[index].mFilled == TRUE &&
                object->mGhostInfoEntries[index].mInterpolation.mState == 1) {
                found = TRUE;
                object->mSelectedIndex = index;
                break;
            }
            index++;
            if (index >= 4) {
                if (wrap == 0) {
                    return;
                }
                index = 0;
            }
        } while (index != object->mSelectedIndex);
    }
    if (found != FALSE) {
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0);
    }
}

void SetScanSelectedEntryHighlight(s32 cursorVisible) {
    CellFileSet *subCellFileSet;
    s32 selectedIndex;
    s32 courseLabelIndex;
    s32 paletteIndex;

    subCellFileSet = &gTimeAttackGhostGetScan->mCellFileSets[1];
    selectedIndex = gTimeAttackGhostGetScan->mSelectedIndex;
    courseLabelIndex = selectedIndex + 4;
    if (cursorVisible != 0) {
        paletteIndex = 0xe;
    } else {
        paletteIndex = 0xf;
    }
    subCellFileSet->mCellTable[4].mVisible = cursorVisible;
    SetLabelPaletteIndex(courseLabelIndex, paletteIndex, subCellFileSet->mLabelLayout, subCellFileSet->mCellTable,
                         subCellFileSet->mCellLayout);
    SetLabelPaletteIndex(selectedIndex, paletteIndex, subCellFileSet->mLabelLayout, subCellFileSet->mCellTable,
                         subCellFileSet->mCellLayout);
}

#pragma thumb off

#pragma thumb on

void SetupGhostSubTextTwoButtons(void) {
    void *message;
    void *firstButtonText;
    void *secondButtonText;
    message = GetBmgEntry(gTimeAttackGhostGetScan->mGhostMessages, 8);
    firstButtonText = GetBmgEntry(gTimeAttackGhostGetScan->mCommonMessages, 0);
    secondButtonText = GetBmgEntry(gTimeAttackGhostGetScan->mCommonMessages, 1);
    SetTxtSystemSoundId(0, 5);
    SetupTxtSystemSubTextTwoButtonsEx(message, firstButtonText, secondButtonText, 0, 0, 1, 1, 0);
}

#pragma thumb off
