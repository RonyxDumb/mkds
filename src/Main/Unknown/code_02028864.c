#include "Main/Unknown/code_02028864.h"
#include "Main/Unknown/code_0202578c.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02025df4.h"
#include "Main/Unknown/code_02025e28.h"
#include "Main/Unknown/code_02028d9c.h"
#include "Main/Unknown/code_02028f20.h"
#include "Main/Unknown/code_02027e78.h"
#include "Main/Unknown/code_020291f0.h"
#include "Main/Unknown/code_02029440.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Unknown/code_0202bb80.h"
#include "Main/Unknown/code_0202c000.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_02056444.h"
#include "Main/Unknown/code_02148000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02077bc0.h"
#include "Main/Unknown/code_02078000.h"
#include "Main/Unknown/code_0211f394.h"
#include "Main/Unknown/code_0211f4b0.h"
#include "Main/Unknown/code_02116ec0.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_0212775c.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/code_0212b928.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "code_02148950.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/code_02025f80.h"
#include "Main/Unknown/unk_02174000.h"

#pragma optimize_for_size on

#pragma thumb on
void InitSelectKart(void *parentHeap, s32 mode, void *mainOam, void *subOam) {
    void *heap;
    CellFileSet *cellFileSet;
    CellFileSet titleFileSet;
    CellFileSet nameFileSet;
    SelectKart *selectKart;
    s32 index;
    s32 listKind;
    s32 value;
    u32 entryListUsed;
    void *text;
    heap = CreateFrmHeapFromMaxFree(parentHeap);
    gSelectKart = HeapAlloc(heap, 0x118);
    SelectKartMI_CpuClearFast(gSelectKart, 0x118);
    gSelectKart->mHeap = heap;
    gSelectKart->mMode = mode;
    gSelectKart->mTouchRect = -1;
    switch (GetRaceSetupCopy()->mEntryTransition) {
        case 1:
            SetupInterpolation(&gSelectKart->mInterpolations[0], 1, 10, -0x80, 0);
            SetupInterpolation(&gSelectKart->mInterpolations[2], 1, 10, 0x60, 0);
            break;
        case 0:
            SetupInterpolation(&gSelectKart->mInterpolations[0], 0, 10, -0x80, 0);
            SetupInterpolation(&gSelectKart->mInterpolations[2], 0, 10, 0x60, 0);
            if (SelectKartMB_IsMultiBootChildWrapper() == 0) {
                StartKartModelMenuBg0Increase();
                SetKartModelMenuSpinStopped(0);
            }
            break;
    }
    SetupInterpolation(&gSelectKart->mInterpolations[1], 0, 10, -0x40, 0);
    SetupInterpolation(&gSelectKart->mInterpolations[3], 0, 10, 0x40, 0);
    SetupInterpolation(&gSelectKart->mInterpolations[4], 0, 10, -0xc0, 0);
    gSelectKart->mMainOam = mainOam;
    gSelectKart->mSubOam = subOam;
    if (gSelectKart->mMode != 0 || GetRaceSetupCopy()->mMode == 3 || GetRaceSetupCopy()->mMode == 2) {
        entryListUsed = 1;
    } else {
        entryListUsed = 0;
    }
    gSelectKart->mEntryListUsed = entryListUsed;
    if (gSelectKart->mEntryListUsed != FALSE) {
        switch (gSelectKart->mMode) {
            case 0:
                listKind = 0;
                break;
            case 1:
                listKind = 1;
                break;
            case 2:
                listKind = 2;
                break;
        }
        SetupPlayerEntryList(listKind, PLAYER_ENTRY_LIST_KART);
    }
    switch (gSelectKart->mMode) {
        case 0:
            gSelectKart->mEntryIndex = 0;
            break;
        case 1:
            gSelectKart->mEntryIndex = GetOwnEntryIndex();
            break;
        case 2:
            gSelectKart->mEntryIndex = GetRaceSetupCopyEntryIndex();
            break;
    }
    if (SelectKartMB_IsMultiBootChildWrapper() == 0) {
        gSelectKart->mKartSelectMessages = FindFileInLoadedArchives(gKartSelectBmgName);
        gSelectKart->mKartAppear = CreateKartAppear(gSelectKart->mHeap);
    }
    selectKart = gSelectKart;
    selectKart->mCharacterIndex = GetRaceSetupCopy()->mEntries[selectKart->mEntryIndex].mCharacterIndex;
    selectKart = gSelectKart;
    selectKart->mKartIndex = GetRaceSetupCopy()->mEntries[selectKart->mEntryIndex].mKartIndex;
    if (gSelectKart->mCharacterIndex == -1) {
        gSelectKart->mCharacterIndex = 0;
    }
    if (gSelectKart->mKartIndex == -1) {
        gSelectKart->mKartIndex = 0;
    }
    GetRaceSetupCopy()->mEntries[gSelectKart->mEntryIndex].mKartIndex = -1;
    GetRaceSetupCopy()->mEntries[gSelectKart->mEntryIndex].mKartStored = 0;
    gSelectKart->mKartTableIndex = FindKartTableIndex(gSelectKart->mKartIndex);
    if (SelectKartMB_IsMultiBootChildWrapper() == 0) {
        selectKart = gSelectKart;
        if (selectKart->mEntryListUsed == FALSE) {
            cellFileSet = &selectKart->mSelectCharacterGpMParts;
            LocateCellFileSet(cellFileSet, gSelectCharacterGpMNcgrName2, gSelectCharacterGpMNcerName2,
                              gSelectCharacterGpMONclrName2, gSelectCharacterGpMBnclName2, NULL, NULL,
                              FindFileInLoadedArchives);
            SetupCellFileSet(0, gSelectKart->mHeap, cellFileSet);
            LocateCellFileSet(&titleFileSet, gSelectCharacterGpTitleMNcgrName2, gSelectCharacterGpTitleMNcerName2, NULL,
                              gSelectCharacterGpTitleMBnclName2, NULL, NULL, FindFileInLoadedArchives);
            QueueCellChars(1, titleFileSet.mCells, titleFileSet.mChars, titleFileSet.mCellLayout, 0, 0,
                           cellFileSet->mCells, cellFileSet->mCellLayout);
            LocateCellFileSet(&nameFileSet, gSelectCharacterGpNameMNcgrName2, gSelectCharacterGpNameMNcerName2, NULL,
                              gSelectCharacterGpNameMBnclName2, NULL, NULL, FindFileInLoadedArchives);
            QueueCellChars(data_usa_021537dc[gSelectKart->mCharacterIndex], nameFileSet.mCells, nameFileSet.mChars,
                           nameFileSet.mCellLayout, 0, 2, cellFileSet->mCells, cellFileSet->mCellLayout);
            QueueCellChars(data_usa_021537dc[gSelectKart->mCharacterIndex], nameFileSet.mCells, nameFileSet.mChars,
                           nameFileSet.mCellLayout, 0, 1, cellFileSet->mCells, cellFileSet->mCellLayout);
        }
    }
    if (SelectKartMB_IsMultiBootChildWrapper() == 0) {
        LocateAndQueueScreenMapFileSet(1, &gSelectKart->mSelectKartSBParts, gSelectKartSBNcgrName,
                                       gSelectKartSBNclrName, gSelectKartSNscrName, 3, FindFileInLoadedArchives);
    }
    if (SelectKartMB_IsMultiBootChildWrapper() == 0) {
        value = GX_GetSizeOfSubOBJ();
        cellFileSet = &gSelectKart->mSelectKartSParts;
        LocateCellFileSet(cellFileSet, gSelectKartSNcgrName, gSelectKartSNcerName, gSelectKartSONclrName,
                          gSelectKartSBnclName, gSelectKartSBnllName, gSelectKartSBnblName, FindFileInLoadedArchives);
        SetupCellFileSet(1, gSelectKart->mHeap, cellFileSet);
        for (index = 0; index < 9; index++) {
            value -= SetupLabelCanvas(1, gSelectKart->mHeap, cellFileSet, &data_usa_021537f4[index], value);
        }
        for (index = 0; index < 6; index++) {
            text = GetBmgEntry(gSelectKart->mKartSelectMessages, data_usa_021537f4[index].mUnk_08);
            value = data_usa_021537f4[index].mUnk_00;
            PrintLabelLayoutTextNoFixedAdvance(1, value, cellFileSet->mLabelLayout, text, cellFileSet->mCellLayout,
                                               cellFileSet->mCellTable);
            SetLabelPriority(value, 1, cellFileSet->mLabelLayout, cellFileSet->mCellTable, cellFileSet->mCellLayout);
        }
        text = GetBmgEntry(FindFileInLoadedArchives(gCommonBmgName2), data_usa_021537f4[6].mUnk_08);
        index = data_usa_02153834[4];
        PrintLabelLayoutTextNoFixedAdvance(1, index, cellFileSet->mLabelLayout, text, cellFileSet->mCellLayout,
                                           cellFileSet->mCellTable);
        SetLabelPaletteIndex(index, 1, cellFileSet->mLabelLayout, cellFileSet->mCellTable, cellFileSet->mCellLayout);
        InitPaletteBlend(gSelectKart->mHeap, cellFileSet->mPalette, 1);
        cellFileSet->mCellTable[2].mVisible = 0;
        cellFileSet->mCellTable[3].mVisible = cellFileSet->mCellTable[2].mVisible;
    } else {
        InitSelectRaceRuleWait(gSelectKart->mHeap, gSelectKart->mSubOam);
        SlideInSelectRaceRuleWait();
    }
    RefreshKartMenuParamElements();
    SetSelectKartPositionDigits();
    PrintSelectKartMessage();
    if (SelectKartMB_IsMultiBootChildWrapper() == 0) {
        RequestSelectReturnState1();
    }
    if (SelectKartGetConnectionKind() == 2) {
        SetSelectReturnDisplayBitOn();
    }
    if (gSelectKart->mMode == 0) {
        ClearNonParticipantKartIndices();
    }
    FrmHeapShrinkInParent(heap);
}
#pragma thumb off
