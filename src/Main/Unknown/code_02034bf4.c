#include "Main/Unknown/code_02034bf4.h"
#include "Main/Unknown/code_0202578c.h"
#include "Main/Unknown/code_0202dd9c.h"
#include "Main/Unknown/code_0202db04.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02025b84.h"
#include "Main/Unknown/code_02025bb4.h"
#include "Main/Unknown/code_02025d5c.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02125ed0.h"
#include "Main/Unknown/code_02126230.h"
#include "Main/Unknown/code_0212775c.h"
#include "code_02148950.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02153000.h"
#include "Main/Unknown/unk_02163000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/unk_02174000.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_02025edc.h"
#include "Main/Unknown/code_02025f80.h"
#include "Main/Unknown/code_0204f240.h"

#pragma thumb on

void UpdateScanSelectedIndex(void) {
    TimeAttackGhostGetScan *object;
    CellFileSet *subCellFileSet;
    s32 i;

    object = gTimeAttackGhostGetScan;
    subCellFileSet = &object->mCellFileSets[1];
    if (object->mSelectedIndex < 0) {
        for (i = 0; i < 4; i++) {
            if (object->mGhostInfoEntries[i].mFilled != FALSE) {
                object->mSelectedIndex = i;
                subCellFileSet->mCellTable[4].mVisible = 1;
                CopyCellLayoutEntryPosition(4, gTimeAttackGhostGetScanSSelLabelTextRows[i][3],
                                            subCellFileSet->mCellLayout);
                return;
            }
        }
    } else {
        if (object->mFilledCount == 0) {
            subCellFileSet->mCellTable[4].mVisible = 0;
            gTimeAttackGhostGetScan->mSelectedIndex = -1;
            return;
        }
        if (object->mGhostInfoEntries[object->mSelectedIndex].mFilled == FALSE) {
            for (i = 0; i < 4; i++) {
                if (object->mGhostInfoEntries[i].mFilled != FALSE) {
                    object->mSelectedIndex = i;
                    return;
                }
            }
        }
    }
}

void UpdateScanEntryOffsetX(void) {
    CellFileSet *subCellFileSet;
    s32 cellCount;
    s32 i;
    s16 interpolatedValue;
    s16 offsetX;

    subCellFileSet = &gTimeAttackGhostGetScan->mCellFileSets[1];
    cellCount = subCellFileSet->mCellLayout->mUnk_06;
    for (i = 0; i < 4; i++) {
        AdvanceInterpolation(&gTimeAttackGhostGetScan->mGhostInfoEntries[i].mInterpolation);
        interpolatedValue = GetInterpolatedValue(&gTimeAttackGhostGetScan->mGhostInfoEntries[i].mInterpolation);
        subCellFileSet->mCellTable[cellCount + gTimeAttackGhostGetScanSSelLabelTextRows[i + 4][0]].mOffsetX =
            interpolatedValue;
        offsetX = subCellFileSet
                      ->mCellTable[cellCount + ((const s16(*)[4]) gTimeAttackGhostGetScanSSelLabelTextRows)[i + 4][0]]
                      .mOffsetX;
        subCellFileSet->mCellTable[cellCount + gTimeAttackGhostGetScanSSelLabelTextRows[i][0]].mOffsetX = offsetX;
        offsetX = subCellFileSet->mCellTable[cellCount + gTimeAttackGhostGetScanSSelLabelTextRows[i][0]].mOffsetX;
        subCellFileSet->mCellTable[gTimeAttackGhostGetScanSSelLabelTextRows[i][3]].mOffsetX = offsetX;
        if (gTimeAttackGhostGetScan->mSelectedIndex == i) {
            subCellFileSet->mCellTable[4].mOffsetX = interpolatedValue;
        }
    }
}

void UpdateScanSlideOffsets(void) {
    CellFileSet *mainCellFileSet;
    CellFileSet *subCellFileSet;
    s32 mainEntryCount;
    s32 subEntryCount;
    s32 i;
    s16 offset;

    mainCellFileSet = &gTimeAttackGhostGetScan->mCellFileSets[0];
    subCellFileSet = &gTimeAttackGhostGetScan->mCellFileSets[1];
    mainEntryCount = mainCellFileSet->mCellLayout->mUnk_06 + mainCellFileSet->mLabelLayout->mUnk_06;
    subEntryCount = subCellFileSet->mCellLayout->mUnk_06 + subCellFileSet->mLabelLayout->mUnk_06;
    offset = GetInterpolatedValue(&gTimeAttackGhostGetScan->mInterpolation);
    for (i = 0; i < mainEntryCount; i++) {
        mainCellFileSet->mCellTable[i].mOffsetY = -offset;
    }
    for (i = 0; i < subEntryCount; i++) {
        subCellFileSet->mCellTable[i].mOffsetY = offset;
    }
}

void RefreshScanSelectedGhostInfo(void) {
    GhostInfoEntry *selectedEntry;
    s32 i;
    CellFileSet *mainCellFileSet;
    s32 entryCount;
    BOOL hasSelection;

    mainCellFileSet = &gTimeAttackGhostGetScan->mCellFileSets[0];
    selectedEntry = &gTimeAttackGhostGetScan->mGhostInfoEntries[gTimeAttackGhostGetScan->mSelectedIndex];
    entryCount = mainCellFileSet->mCellLayout->mUnk_06 + mainCellFileSet->mLabelLayout->mUnk_06;
    for (i = 0; i < entryCount; i++) {
        if (gTimeAttackGhostGetScan->mSelectedIndex >= 0) {
            hasSelection = TRUE;
        } else {
            hasSelection = FALSE;
        }
        mainCellFileSet->mCellTable[i].mVisible = hasSelection;
    }
    if (gTimeAttackGhostGetScan->mSelectedIndex >= 0) {
        PrintGhostRecordInfo((SelectCharacter *) &gTimeAttackGhostGetScan->mCellFileSets[0],
                             gTimeAttackGhostGetScanMLabelTextRows, selectedEntry, selectedEntry->mInfo.mUnk_18[0],
                             selectedEntry->mInfo.mUnk_18[1], selectedEntry->mInfo.mUnk_18[2],
                             &selectedEntry->mInfo.mTime);
    }
}

void RefreshScanEntryPalettes(void) {
    s32 i;
    CellFileSet *subCellFileSet;
    s32 paletteIndex;
    s32 courseLabelIndex;

    subCellFileSet = &gTimeAttackGhostGetScan->mCellFileSets[1];
    for (i = 0; i < 4; i++) {
        courseLabelIndex = i + 4;
        if (i == gTimeAttackGhostGetScan->mSelectedIndex) {
            paletteIndex = 14;
        } else {
            paletteIndex = 15;
        }
        SetLabelPaletteIndex(courseLabelIndex, paletteIndex, subCellFileSet->mLabelLayout, subCellFileSet->mCellTable,
                             subCellFileSet->mCellLayout);
        SetLabelPaletteIndex(i, paletteIndex, subCellFileSet->mLabelLayout, subCellFileSet->mCellTable,
                             subCellFileSet->mCellLayout);
    }
    if (gTimeAttackGhostGetScan->mSelectedIndex >= 0) {
        CopyCellLayoutEntryPosition(
            4, gTimeAttackGhostGetScanSSelLabelTextRows[gTimeAttackGhostGetScan->mSelectedIndex][3],
            subCellFileSet->mCellLayout);
    }
}

BOOL AreGhostRecordInfosDifferent(GhostRecordInfo *storedInfo, GhostRecordInfo *newInfo) {
    s32 i;
    s32 nameDiffers;
    BOOL halfwordDiffers;

    nameDiffers = 0;
    for (i = 0; i < 11; i++) {
        if (storedInfo->mName[i] != newInfo->mName[i]) {
            halfwordDiffers = TRUE;
        } else {
            halfwordDiffers = FALSE;
        }
        nameDiffers |= halfwordDiffers;
    }
    if (nameDiffers != 0 || storedInfo->mUnk_18[1] != newInfo->mUnk_18[1] ||
        storedInfo->mUnk_18[0] != newInfo->mUnk_18[0] || storedInfo->mUnk_18[2] != newInfo->mUnk_18[2] ||
        storedInfo->mTime.mMinute != newInfo->mTime.mMinute || storedInfo->mTime.mSecond != newInfo->mTime.mSecond ||
        storedInfo->mTime.mMillisecond != newInfo->mTime.mMillisecond) {
        return TRUE;
    }
    return FALSE;
}

void InitTimeAttackGhostGetScan(void *parentHeap, void *mainOam, void *subOam) {
    void *heap;
    CellFileSet *cellFileSet;
    u32 remainingObjSize;
    s32 i;
    s32 j;
    s32 assignedCount;
    s32 cellCount;
    s16 *row;
    BOOL screen;

    heap = CreateFrmHeapFromMaxFree(parentHeap);
    gTimeAttackGhostGetScan = HeapAlloc(heap, 0x1a8);
    MemFillWordsByBlock_inline(gTimeAttackGhostGetScan, 0x1a8);
    gTimeAttackGhostGetScan->mHeap = heap;
    gTimeAttackGhostGetScan->mOamLists[0] = mainOam;
    gTimeAttackGhostGetScan->mOamLists[1] = subOam;
    gTimeAttackGhostGetScan->mCommonMessages = FindFileInLoadedArchives(data_02164294);
    gTimeAttackGhostGetScan->mGhostMessages = FindSceneFile(data_021642a0);
    InitBlockEntries(gTimeAttackGhostGetScan->mHeap, 2);
    gTimeAttackGhostGetScan->mSelectedIndex = -1;
    for (i = 0; i < 4; i++) {
        SetupInterpolation(&gTimeAttackGhostGetScan->mGhostInfoEntries[i].mInterpolation, 3, 10, 0x100, 0);
    }
    LocateAndQueueScreenMapFileSet(0, gTimeAttackGhostGetScan, data_021642ac, data_021642cc, data_021642ec, 0,
                                   FindSceneFile);
    cellFileSet = &gTimeAttackGhostGetScan->mCellFileSets[0];
    remainingObjSize = GX_GetSizeOfOBJ();
    LocateCellFileSet(cellFileSet, data_02164308, data_02164328, data_02164348, gTimeAttackGhostGetMBnclName,
                      gTimeAttackGhostGetMBnllName, NULL, FindSceneFile);
    screen = FALSE;
    SetupCellFileSet(0, gTimeAttackGhostGetScan->mHeap, cellFileSet);
    i = 0;
    if (i < cellFileSet->mLabelLayout->mUnk_06) {
        row = (s16 *) gTimeAttackGhostGetScanMLabelTextRows;
        do {
            remainingObjSize -=
                SetupLabelCanvas(screen, gTimeAttackGhostGetScan->mHeap, cellFileSet, row, remainingObjSize);
            row += 4;
            i++;
        } while (i < cellFileSet->mLabelLayout->mUnk_06);
    }
    j = cellFileSet->mCellLayout->mUnk_06 + cellFileSet->mLabelLayout->mUnk_06;
    for (i = 0; i < j; i++) {
        cellFileSet->mCellTable[i].mVisible = 0;
    }
    cellFileSet = &gTimeAttackGhostGetScan->mCellFileSets[1];
    remainingObjSize = GX_GetSizeOfSubOBJ();
    assignedCount = 0;
    LocateCellFileSet(cellFileSet, data_021643a0, data_021643c0, data_021643e0, gTimeAttackGhostGetSSelBnclName,
                      gTimeAttackGhostGetSSelBnllName, gTimeAttackGhostGetSSelBnblName, FindSceneFile);
    SetupCellFileSet(1, gTimeAttackGhostGetScan->mHeap, cellFileSet);
    cellCount = cellFileSet->mCellLayout->mUnk_06;
    i = 0;
    if (i < cellFileSet->mLabelLayout->mUnk_06) {
        row = (s16 *) gTimeAttackGhostGetScanSSelLabelTextRows;
        do {
            if (row[3] < 0) {
                row[3] = cellCount + assignedCount++;
            }
            remainingObjSize -= SetupLabelCanvas(1, gTimeAttackGhostGetScan->mHeap, cellFileSet,
                                                 gTimeAttackGhostGetScanSSelLabelTextRows[i], remainingObjSize);
            row += 4;
            i++;
        } while (i < cellFileSet->mLabelLayout->mUnk_06);
    }
    for (j = 0; j < cellCount; j++) {
        SetCellPriority(j, 3, cellFileSet->mCells, cellFileSet->mCellLayout);
    }
    cellFileSet->mCellTable[4].mVisible = 0;
    SetPlayerCharacterCellFileSet(0, &gTimeAttackGhostGetScan->mCharacterCellFileSet);
    SetupInterpolation(&gTimeAttackGhostGetScan->mInterpolation, 3, 10, -0xc0, 0);
    SetSelectReturnSoundId(0xf);
    FrmHeapShrinkInParent(gTimeAttackGhostGetScan->mHeap);
}

#pragma thumb off
