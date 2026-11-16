#include "Main/Unknown/code_02034bf4.h"
#include "Main/Unknown/code_0202578c.h"
#include "Main/Unknown/code_0202dd9c.h"
#include "Main/Unknown/code_0202db04.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02025b84.h"
#include "Main/Unknown/code_02025bb4.h"
#include "Main/Unknown/code_02025d5c.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/System/Heap.h"
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

void func_02035114(void) {
    Unk02174e64 *object;
    CellFileSet *subCellFileSet;
    s32 i;

    object = sGhostReceiveState;
    subCellFileSet = &object->mCellFileSets[1];
    if (object->mSelectedIndex < 0) {
        for (i = 0; i < 4; i++) {
            if (object->mGhostInfoEntries[i].mFilled != FALSE) {
                object->mSelectedIndex = i;
                subCellFileSet->mCellTable[4].mVisible = 1;
                func_02025c6c(4, data_02164254[i][3], subCellFileSet->mCellLayout);
                return;
            }
        }
    } else {
        if (object->mFilledCount == 0) {
            subCellFileSet->mCellTable[4].mVisible = 0;
            sGhostReceiveState->mSelectedIndex = -1;
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

void func_02035060(void) {
    CellFileSet *subCellFileSet;
    s32 cellCount;
    s32 i;
    s16 interpolatedValue;
    s16 v;

    subCellFileSet = &sGhostReceiveState->mCellFileSets[1];
    cellCount = subCellFileSet->mCellLayout->field6;
    for (i = 0; i < 4; i++) {
        interp_update(&sGhostReceiveState->mGhostInfoEntries[i].mInterpolation);
        interpolatedValue = interp_interpolate(&sGhostReceiveState->mGhostInfoEntries[i].mInterpolation);
        subCellFileSet->mCellTable[cellCount + data_02164254[i + 4][0]].mOffsetX = interpolatedValue;
        v = subCellFileSet->mCellTable[cellCount + ((const s16(*)[4]) data_02164254)[i + 4][0]].mOffsetX;
        subCellFileSet->mCellTable[cellCount + data_02164254[i][0]].mOffsetX = v;
        v = subCellFileSet->mCellTable[cellCount + data_02164254[i][0]].mOffsetX;
        subCellFileSet->mCellTable[data_02164254[i][3]].mOffsetX = v;
        if (sGhostReceiveState->mSelectedIndex == i) {
            subCellFileSet->mCellTable[4].mOffsetX = interpolatedValue;
        }
    }
}

void func_02034fec(void) {
    CellFileSet *mainCellFileSet;
    CellFileSet *subCellFileSet;
    s32 mainEntryCount;
    s32 subEntryCount;
    s32 i;
    s16 offset;

    mainCellFileSet = &sGhostReceiveState->mCellFileSets[0];
    subCellFileSet = &sGhostReceiveState->mCellFileSets[1];
    mainEntryCount = mainCellFileSet->mCellLayout->field6 + mainCellFileSet->mLabelLayout->field6;
    subEntryCount = subCellFileSet->mCellLayout->field6 + subCellFileSet->mLabelLayout->field6;
    offset = interp_interpolate(&sGhostReceiveState->field194);
    for (i = 0; i < mainEntryCount; i++) {
        mainCellFileSet->mCellTable[i].mOffsetY = -offset;
    }
    for (i = 0; i < subEntryCount; i++) {
        subCellFileSet->mCellTable[i].mOffsetY = offset;
    }
}

void func_02034f60(void) {
    GhostInfoEntry *selectedEntry;
    s32 i;
    CellFileSet *mainCellFileSet;
    s32 entryCount;
    BOOL hasSelection;

    mainCellFileSet = &sGhostReceiveState->mCellFileSets[0];
    selectedEntry = &sGhostReceiveState->mGhostInfoEntries[sGhostReceiveState->mSelectedIndex];
    entryCount = mainCellFileSet->mCellLayout->field6 + mainCellFileSet->mLabelLayout->field6;
    for (i = 0; i < entryCount; i++) {
        if (sGhostReceiveState->mSelectedIndex >= 0) {
            hasSelection = TRUE;
        } else {
            hasSelection = FALSE;
        }
        mainCellFileSet->mCellTable[i].mVisible = hasSelection;
    }
    if (sGhostReceiveState->mSelectedIndex >= 0) {
        PrintGhostRecordInfo((SelectCharacter *) &sGhostReceiveState->mCellFileSets[0], data_02154034, selectedEntry,
                             selectedEntry->mInfo.field18[0], selectedEntry->mInfo.field18[1],
                             selectedEntry->mInfo.field18[2],
                             (MinuteSecondMillisecondTime *) &selectedEntry->mInfo.mMillisecond);
    }
}

void func_02034ef0(void) {
    s32 i;
    CellFileSet *subCellFileSet;
    s32 v;
    s32 w;

    subCellFileSet = &sGhostReceiveState->mCellFileSets[1];
    for (i = 0; i < 4; i++) {
        w = i + 4;
        if (i == sGhostReceiveState->mSelectedIndex) {
            v = 14;
        } else {
            v = 15;
        }
        jn_ui_setLabelColorParam(w, v, subCellFileSet->mLabelLayout, subCellFileSet->mCellTable,
                             subCellFileSet->mCellLayout);
        jn_ui_setLabelColorParam(i, v, subCellFileSet->mLabelLayout, subCellFileSet->mCellTable,
                             subCellFileSet->mCellLayout);
    }
    if (sGhostReceiveState->mSelectedIndex >= 0) {
        func_02025c6c(4, data_02164254[sGhostReceiveState->mSelectedIndex][3], subCellFileSet->mCellLayout);
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
    if (nameDiffers != 0 || storedInfo->field18[1] != newInfo->field18[1] ||
        storedInfo->field18[0] != newInfo->field18[0] || storedInfo->field18[2] != newInfo->field18[2] ||
        storedInfo->mMinute != newInfo->mMinute || storedInfo->mSecond != newInfo->mSecond ||
        storedInfo->mMillisecond != newInfo->mMillisecond) {
        return TRUE;
    }
    return FALSE;
}

void func_02034bf4(void *parentHeap, void *b, void *c) {
    void *heap;
    CellFileSet *cellFileSet;
    u32 remainingObjSize;
    s32 i;
    s32 j;
    s32 assignedCount;
    s32 cellCount;
    s16 *row;
    BOOL z;

    heap = heap_createSubFrmHeap(parentHeap);
    sGhostReceiveState = heap_alloc(heap, 0x1a8);
    MemFillWordsByBlock_inline(sGhostReceiveState, 0x1a8);
    sGhostReceiveState->mHeap = heap;
    sGhostReceiveState->field24[0] = b;
    sGhostReceiveState->field24[1] = c;
    sGhostReceiveState->mCommonMessages = arc_get2dArcFile(aCommon_bmg_34);
    sGhostReceiveState->mGhostMessages = arc_getSceneArcFile(aGhost_bmg_2);
    InitBlockEntries(sGhostReceiveState->mHeap, 2);
    sGhostReceiveState->mSelectedIndex = -1;
    for (i = 0; i < 4; i++) {
        interp_init(&sGhostReceiveState->mGhostInfoEntries[i].mInterpolation, 3, 10, 0x100, 0);
    }
    mutil2_initBgGraphics(0, sGhostReceiveState, aTimeattack_ghost_get_m_b_ncgr, aTimeattack_ghost_get_m_b_nclr, aTimeattack_ghost_get_m_nscr, 0, arc_getSceneArcFile);
    cellFileSet = &sGhostReceiveState->mCellFileSets[0];
    remainingObjSize = GX_GetSizeOfOBJ();
    mutil2_loadLayout(cellFileSet, aTimeattack_ghost_get_m_nce_ncgr_0, aTimeattack_ghost_get_m_nce_ncer_0, aTimeattack_ghost_get_m_o_nclr_0, aTimeattack_ghost_get_m_bncl_0,
                      aTimeattack_ghost_get_m_bnll_0, NULL, arc_getSceneArcFile);
    z = FALSE;
    mutil2_initLayout(0, sGhostReceiveState->mHeap, cellFileSet);
    i = 0;
    if (i < cellFileSet->mLabelLayout->field6) {
        row = (s16 *) data_02154034;
        do {
            remainingObjSize -= mutil2_initLabel(z, sGhostReceiveState->mHeap, cellFileSet, row, remainingObjSize);
            row += 4;
            i++;
        } while (i < cellFileSet->mLabelLayout->field6);
    }
    j = cellFileSet->mCellLayout->field6 + cellFileSet->mLabelLayout->field6;
    for (i = 0; i < j; i++) {
        cellFileSet->mCellTable[i].mVisible = 0;
    }
    cellFileSet = &sGhostReceiveState->mCellFileSets[1];
    remainingObjSize = GX_GetSizeOfSubOBJ();
    assignedCount = 0;
    mutil2_loadLayout(cellFileSet, aTimeattack_ghost_get_s_nce_ncgr_0, aTimeattack_ghost_get_s_nce_ncer_0, aTimeattack_ghost_get_s_o_nclr_0, aTimeattack_ghost_get_s_sel_bncl,
                      aTimeattack_ghost_get_s_sel_bnll, aTimeattack_ghost_get_s_sel_bnbl, arc_getSceneArcFile);
    mutil2_initLayout(1, sGhostReceiveState->mHeap, cellFileSet);
    cellCount = cellFileSet->mCellLayout->field6;
    i = 0;
    if (i < cellFileSet->mLabelLayout->field6) {
        row = (s16 *) data_02164254;
        do {
            if (row[3] < 0) {
                row[3] = cellCount + assignedCount++;
            }
            remainingObjSize -= mutil2_initLabel(1, sGhostReceiveState->mHeap, cellFileSet, data_02164254[i], remainingObjSize);
            row += 4;
            i++;
        } while (i < cellFileSet->mLabelLayout->field6);
    }
    for (j = 0; j < cellCount; j++) {
        jn_ui_setCellPriority(j, 3, cellFileSet->mCells, cellFileSet->mCellLayout);
    }
    cellFileSet->mCellTable[4].mVisible = 0;
    mutil2_loadPortraits(0, &sGhostReceiveState->field64);
    interp_init(&sGhostReceiveState->field194, 3, 10, -0xc0, 0);
    gmenu_setSeqArcIndex(0xf);
    heap_adjustSubFrmHeap(sGhostReceiveState->mHeap);
}

#pragma thumb off
