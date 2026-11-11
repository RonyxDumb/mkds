#include "Main/Unknown/code_0211e4e8.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020d0e3c.h"
#include "Main/Unknown/code_020d0efc.h"
#include "registers.h"

#include "Main/Unknown/code_0211f394.h"
#include "Main/Unknown/code_0211f4b0.h"
#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/unk_0216d000.h"
#include "Main/Unknown/unk_0216e000.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_0211d000.h"
#include "Main/Unknown/code_0211f000.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_02029440.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_020d0000.h"
#include "Main/Unknown/code_0211de34.h"
#include "Main/Unknown/code_0211de00.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_0211f380.h"
#include "Main/Unknown/code_0211f498.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/code_0212426c.h"
#include "code_02148950.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_02016468.h"

#pragma thumb on

void LocateAndQueueSelectCupM(void) {
    Ncgr *mainCellChars;
    Nclr *mainCellPalette;
    Ncgr *subCellChars;
    Nclr *subCellPalette;
    Ncgr *firstBgChars;
    Nscr *firstBgScreenMap;
    Nclr *firstBgPalette;
    Ncgr *secondBgChars;
    Nscr *secondBgScreenMap;
    Nclr *secondBgPalette;
    u16 *mainCellPaletteData;

    mainCellChars = NULL;
    mainCellPalette = NULL;
    subCellChars = NULL;
    subCellPalette = NULL;
    firstBgChars = NULL;
    firstBgScreenMap = NULL;
    firstBgPalette = NULL;
    secondBgChars = NULL;
    secondBgScreenMap = NULL;
    secondBgPalette = NULL;
    if (gBootInfo->mBootType == 2) {
        return;
    }
    LocateNcgr(&firstBgChars, FindSceneFile(gSelectCupMBNcgrName3));
    LocateNclr(&firstBgPalette, FindSceneFile(gSelectCupMBNclrName3));
    LocateNscr(&firstBgScreenMap, FindSceneFile(gSelectCupMNscrName3));
    LocateNcgr(&secondBgChars, FindSceneFile(gSelectCupMBNcgrName3));
    LocateNclr(&secondBgPalette, FindSceneFile(gSelectCupMBNclrName3));
    LocateNscr(&secondBgScreenMap, FindSceneFile(gSelectCupMNscrName3));
    gSelectCupM->mSecondScreenMapBuffer = HeapAlloc(gSelectCupM->mHeap, 0x800);
    gSelectCupM->mMainBncl = FindSceneFile(gSelectCupMBnclName3);
    gSelectCupM->mMainBnll = FindSceneFile(gSelectCupMBnllName3);
    LocateNcgr2(&mainCellChars, FindSceneFile(gSelectCupMNcgrName3));
    LocateNcer(&gSelectCupM->mMainNcer, FindSceneFile(gSelectCupMNcerName3));
    LocateNclr(&mainCellPalette, FindSceneFile(gSelectCupMONclrName3));
    gSelectCupM->mSubBncl = FindSceneFile(gSelectCupMBnclName3);
    gSelectCupM->mSubBnll = FindSceneFile(gSelectCupMBnllName3);
    LocateNcgr2(&subCellChars, FindSceneFile(gSelectCupMNcgrName3));
    LocateNcer(&gSelectCupM->mSubNcer, FindSceneFile(gSelectCupMNcerName3));
    LocateNclr(&subCellPalette, FindSceneFile(gSelectCupMONclrName3));
    mainCellPaletteData = mainCellPalette->mData;
    if (!(GetPreviousMenuScreenNumber() == 0x17 || GetPreviousMenuScreenNumber() == 0xb)) {
        NNS_GfdRegisterNewVramTransferTask(4, 0, firstBgChars->mData, firstBgChars->mDataSize);
        NNS_GfdRegisterNewVramTransferTask(0xf, 0, firstBgPalette->mData, 0x140);
        NNS_GfdRegisterNewVramTransferTask(8, 0, firstBgScreenMap->mData, firstBgScreenMap->mDataSize);
        NNS_GfdRegisterNewVramTransferTask(8, 0x800, gSelectCupM->mSecondScreenMapBuffer, 0x800);
    }
    if (!(GetPreviousMenuScreenNumber() == 0x19 || GetPreviousMenuScreenNumber() == 0xd)) {
        NNS_GfdRegisterNewVramTransferTask(0x17, 0, secondBgChars->mData, secondBgChars->mDataSize);
        NNS_GfdRegisterNewVramTransferTask(0x1f, 0, secondBgPalette->mData, 0x140);
        NNS_GfdRegisterNewVramTransferTask(0x1b, 0, secondBgScreenMap->mData, secondBgScreenMap->mDataSize);
        NNS_GfdRegisterNewVramTransferTask(0x1b, 0x800, gSelectCupM->mSecondScreenMapBuffer, 0x800);
    }
    NNS_GfdRegisterNewVramTransferTask(0x13, 0, mainCellChars->mData, mainCellChars->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0xe, 0, mainCellPalette->mData, 0x1a0);
    NNS_GfdRegisterNewVramTransferTask(0xe, 0x1c0, mainCellPaletteData + 0xe0, 0x40);
    NNS_GfdRegisterNewVramTransferTask(0x23, 0, subCellChars->mData, subCellChars->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x1e, 0, subCellPalette->mData, subCellPalette->mDataSize);
}

void InitSelectCupMCellsAndRequestCupPicture(void) {
    s32 cellIndex;
    u16 mainCellCount;
    u16 subCellCount;
    s32 courseIndex;
    BOOL screenId;
    BOOL visible;
    s32 nextCourseIndex;
    s32 firstCellIndex;

    if (gBootInfo->mBootType == 2) {
        return;
    }
    mainCellCount = gSelectCupM->mMainBncl->mCount;
    subCellCount = gSelectCupM->mSubBncl->mCount;
    visible = FALSE;
    for (cellIndex = 0; cellIndex < 8; cellIndex++) {
        gSelectCupM->mMainTable[data_0215cf1c[cellIndex]].mVisible = visible;
        gSelectCupM->mSubTable[data_0215cf1c[cellIndex]].mVisible = visible;
    }
    for (cellIndex = 0; cellIndex < 4; cellIndex++) {
        gSelectCupM->mMainTable[data_0215cefc[cellIndex]].mVisible = 0;
        gSelectCupM->mSubTable[data_0215cefc[cellIndex]].mVisible = 0;
    }
    for (cellIndex = 0; cellIndex < 4; cellIndex++) {
        gSelectCupM->mMainTable[gSelectCupMCourseCells[cellIndex]].mVisible = 0;
        gSelectCupM->mMainTable[mainCellCount + gSelectCupMCourseLabels[cellIndex]].mVisible = 1;
        gSelectCupM->mSubTable[gSelectCupMCourseCells[cellIndex]].mVisible = 0;
        gSelectCupM->mSubTable[subCellCount + gSelectCupMCourseLabels[cellIndex]].mVisible = 1;
    }
    gSelectCupM->mMainTable[20].mVisible = 0;
    gSelectCupM->mMainTable[19].mVisible = 1;
    gSelectCupM->mSubTable[20].mVisible = 0;
    gSelectCupM->mSubTable[19].mVisible = 1;
    QueueSelectCupNameM(data_0215cf2c[GetCupIndex()], gSelectCupM->mMainNcer, gSelectCupM->mMainBncl, 0x13, 0);
    QueueSelectCupNameM(data_0215cf2c[GetCupIndex()], gSelectCupM->mSubNcer, gSelectCupM->mSubBncl, 0x13, 1);
    screenId = FALSE;
    for (courseIndex = 0; courseIndex < 4; courseIndex++) {
        PrintLabelLayoutTextNoFixedAdvance(
            screenId, gSelectCupMCourseLabels[courseIndex], gSelectCupM->mMainBnll,
            GetBmgEntry(gSelectCupM->mCommonMessages, data_0215cf4c[data_0215cf2c[GetCupIndex()]][courseIndex]),
            gSelectCupM->mMainBncl, gSelectCupM->mMainTable);
        PrintLabelLayoutTextNoFixedAdvance(
            1, gSelectCupMCourseLabels[courseIndex], gSelectCupM->mSubBnll,
            GetBmgEntry(gSelectCupM->mCommonMessages, data_0215cf4c[data_0215cf2c[GetCupIndex()]][courseIndex]),
            gSelectCupM->mSubBncl, gSelectCupM->mSubTable);
    }
    firstCellIndex = gSelectCupMCourseCells[0];
    gSelectCupM->mMainTable[firstCellIndex].mVisible = 1;
    courseIndex = gSelectCupMCourseLabels[0];
    SetLabelPaletteIndex(courseIndex, 0xe, gSelectCupM->mMainBnll, gSelectCupM->mMainTable, gSelectCupM->mMainBncl);
    gSelectCupM->mSubTable[firstCellIndex].mVisible = 1;
    SetLabelPaletteIndex(courseIndex, 0xe, gSelectCupM->mSubBnll, gSelectCupM->mSubTable, gSelectCupM->mSubBncl);
    for (nextCourseIndex = 1; nextCourseIndex < 4; nextCourseIndex++) {
        gSelectCupM->mMainTable[gSelectCupMCourseCells[nextCourseIndex]].mVisible = 0;
        SetLabelPaletteIndex(gSelectCupMCourseLabels[nextCourseIndex], 0xf, gSelectCupM->mMainBnll,
                             gSelectCupM->mMainTable, gSelectCupM->mMainBncl);
        gSelectCupM->mSubTable[gSelectCupMCourseCells[nextCourseIndex]].mVisible = 0;
        SetLabelPaletteIndex(gSelectCupMCourseLabels[nextCourseIndex], 0xf, gSelectCupM->mSubBnll,
                             gSelectCupM->mSubTable, gSelectCupM->mSubBncl);
    }
    TrySetCupPictureIndexAndQueueLoads(data_0215cf8c[data_0215cf2c[GetCupIndex()]][0]);
    gSelectCupM->mCupPicturePending = TRUE;
}

void StartSelectCupMState0(void) {
    s32 cellIndex;
    u16 mainCellCount;
    u16 subCellCount;

    gSelectCupM->mNextState = 0;
    gSelectCupM->mStateFrames = 0;
    if (gBootInfo->mBootType == 2) {
        return;
    }
    mainCellCount = gSelectCupM->mMainBncl->mCount;
    subCellCount = gSelectCupM->mSubBncl->mCount;
    gSelectCupM->mBg0Offset = 0;
    gSelectCupM->mMainTable[20].mOffsetY = 0;
    gSelectCupM->mMainTable[19].mOffsetY = 0;
    gSelectCupM->mMainTable[2].mOffsetY = 0;
    gSelectCupM->mMainTable[1].mOffsetY = 0;
    gSelectCupM->mMainTable[0].mOffsetY = 0;
    for (cellIndex = 0; cellIndex < 8; cellIndex++) {
        gSelectCupM->mMainTable[data_0215cf1c[cellIndex]].mOffsetY = 0;
    }
    for (cellIndex = 0; cellIndex < 4; cellIndex++) {
        gSelectCupM->mMainTable[gSelectCupMCourseCells[cellIndex]].mOffsetY = 0;
        gSelectCupM->mMainTable[mainCellCount + gSelectCupMCourseLabels[cellIndex]].mOffsetY = 0;
    }
    gSelectCupM->mBg3Offset = ~0xbf;
    gSelectCupM->mSubTable[20].mOffsetY = ~0xbf;
    gSelectCupM->mSubTable[19].mOffsetY = ~0xbf;
    gSelectCupM->mSubTable[2].mOffsetY = ~0xbf;
    gSelectCupM->mSubTable[1].mOffsetY = ~0xbf;
    gSelectCupM->mSubTable[0].mOffsetY = ~0xbf;
    for (cellIndex = 0; cellIndex < 8; cellIndex++) {
        gSelectCupM->mSubTable[data_0215cf1c[cellIndex]].mOffsetY = ~0xbf;
    }
    for (cellIndex = 0; cellIndex < 4; cellIndex++) {
        gSelectCupM->mSubTable[gSelectCupMCourseCells[cellIndex]].mOffsetY = ~0xbf;
        gSelectCupM->mSubTable[subCellCount + gSelectCupMCourseLabels[cellIndex]].mOffsetY = ~0xbf;
    }
}

void StartSelectCupMState1(void) {
    s32 cellIndex;
    u16 mainCellCount;
    u16 subCellCount;

    gSelectCupM->mNextState = 1;
    gSelectCupM->mStateFrames = 0;
    if (gBootInfo->mBootType == 2) {
        return;
    }
    mainCellCount = gSelectCupM->mMainBncl->mCount;
    subCellCount = gSelectCupM->mSubBncl->mCount;
    gSelectCupM->mBg0Offset = 0xc0;
    gSelectCupM->mMainTable[20].mOffsetY = 0xc0;
    gSelectCupM->mMainTable[19].mOffsetY = 0xc0;
    gSelectCupM->mMainTable[2].mOffsetY = 0xc0;
    gSelectCupM->mMainTable[1].mOffsetY = 0xc0;
    gSelectCupM->mMainTable[0].mOffsetY = 0xc0;
    for (cellIndex = 0; cellIndex < 8; cellIndex++) {
        gSelectCupM->mMainTable[data_0215cf1c[cellIndex]].mOffsetY = 0xc0;
    }
    for (cellIndex = 0; cellIndex < 4; cellIndex++) {
        gSelectCupM->mMainTable[gSelectCupMCourseCells[cellIndex]].mOffsetY = 0xc0;
        gSelectCupM->mMainTable[mainCellCount + gSelectCupMCourseLabels[cellIndex]].mOffsetY = 0xc0;
    }
    gSelectCupM->mBg3Offset = ~0x1f;
    gSelectCupM->mSubTable[20].mOffsetY = ~0x1f;
    gSelectCupM->mSubTable[19].mOffsetY = ~0x1f;
    gSelectCupM->mSubTable[2].mOffsetY = ~0x1f;
    gSelectCupM->mSubTable[1].mOffsetY = ~0x1f;
    gSelectCupM->mSubTable[0].mOffsetY = ~0x1f;
    for (cellIndex = 0; cellIndex < 8; cellIndex++) {
        gSelectCupM->mSubTable[data_0215cf1c[cellIndex]].mOffsetY = ~0x1f;
    }
    for (cellIndex = 0; cellIndex < 4; cellIndex++) {
        gSelectCupM->mSubTable[gSelectCupMCourseCells[cellIndex]].mOffsetY = ~0x1f;
        gSelectCupM->mSubTable[subCellCount + gSelectCupMCourseLabels[cellIndex]].mOffsetY = ~0x1f;
    }
}

void InitSelectCupM(void *parentHeap, void *mainOamList, void *subOamList) {
    void *heap;
    s32 index;
    s32 remainingSize;

    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~3) | 1;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & ~3) | 1;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & 0x43) | 0x9004;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & 0x43) | 0x8300;
    heap = CreateFrmHeapFromMaxFree(parentHeap);
    gSelectCupM = HeapAlloc(heap, 0x54);
    gSelectCupM->mHeap = heap;
    gSelectCupM->mCupPicturePending = FALSE;
    gSelectCupM->mMainOam = mainOamList;
    gSelectCupM->mSubOam = subOamList;
    gSelectCupM->mUnk_50 = 0;
    if (GetPreviousMenuScreenNumber() == 0x19 || GetPreviousMenuScreenNumber() == 0xd) {
        gSelectCupM->mState = 1;
    } else {
        gSelectCupM->mState = 0;
    }
    LocateAndQueueSelectCupM();
    gSelectCupM->mCommonMessages = FindFileInLoadedArchives(data_0216e09c);
    if (gBootInfo->mBootType != 2) {
        InitLayoutTable(gSelectCupM->mHeap, gSelectCupM->mMainBncl, gSelectCupM->mMainBnll, &gSelectCupM->mMainTable);
        InitLayoutTable(gSelectCupM->mHeap, gSelectCupM->mSubBncl, gSelectCupM->mSubBnll, &gSelectCupM->mSubTable);
        remainingSize = 0x8000;
        for (index = 0; index < 4; index++) {
            remainingSize -=
                InitLabelCanvas(gSelectCupM->mHeap, gSelectCupMCourseLabels[index], gSelectCupM->mMainBnll,
                                data_0215cef4[index], data_0215cf14[index], gSelectCupMCourseCells[index],
                                gSelectCupM->mMainNcer, gSelectCupM->mMainBncl, gSelectCupM->mMainTable, remainingSize);
        }
        index = GX_GetSizeOfSubOBJ();
        for (remainingSize = 0; remainingSize < 4; remainingSize++) {
            index -= InitLabelCanvas(gSelectCupM->mHeap, gSelectCupMCourseLabels[remainingSize], gSelectCupM->mSubBnll,
                                     data_0215cef4[remainingSize], data_0215cf14[remainingSize],
                                     gSelectCupMCourseCells[remainingSize], gSelectCupM->mSubNcer,
                                     gSelectCupM->mSubBncl, gSelectCupM->mSubTable, index);
        }
        CreateSelectCupNameM(gSelectCupM->mHeap);
    } else {
        InitSelectRaceRuleWait(gSelectCupM->mHeap, gSelectCupM->mSubOam);
        PlaceSelectRaceRuleWait();
    }
    InitSelectCupMCellsAndRequestCupPicture();
    if (GetPreviousMenuScreenNumber() == 0x19 || GetPreviousMenuScreenNumber() == 0xd) {
        StartSelectCupMState1();
    } else {
        StartSelectCupMState0();
    }
    FrmHeapShrinkInParent(gSelectCupM->mHeap);
}

void ReleaseSelectCupM(void) {
    if (gBootInfo->mBootType != 2) {
        ClearSelectCupNameMPointer();
    } else {
        ClearSelectRaceRuleWaitPointer();
    }
    HeapDestroy(gSelectCupM->mHeap);
    gSelectCupM = NULL;
}

void AdvanceSelectCupMState0(void) {
    s32 cellIndex;
    s16 mainOffset;
    s16 subOffset;
    u16 mainCellCount;
    u16 subCellCount;

    gSelectCupM->mStateFrames++;
    if (gBootInfo->mBootType == 2) {
        return;
    }
    mainOffset = InterpolateS16(1, 0, 0xc0, gSelectCupM->mStateFrames, 0xa);
    subOffset = InterpolateS16(1, ~0xbf, ~0x1f, gSelectCupM->mStateFrames, 0xa);
    mainCellCount = gSelectCupM->mMainBncl->mCount;
    gSelectCupM->mBg0Offset = mainOffset;
    gSelectCupM->mMainTable[20].mOffsetY = mainOffset;
    gSelectCupM->mMainTable[19].mOffsetY = mainOffset;
    gSelectCupM->mMainTable[2].mOffsetY = mainOffset;
    gSelectCupM->mMainTable[1].mOffsetY = mainOffset;
    gSelectCupM->mMainTable[0].mOffsetY = mainOffset;
    for (cellIndex = 0; cellIndex < 8; cellIndex++) {
        gSelectCupM->mMainTable[data_0215cf1c[cellIndex]].mOffsetY = mainOffset;
    }
    for (cellIndex = 0; cellIndex < 4; cellIndex++) {
        gSelectCupM->mMainTable[gSelectCupMCourseCells[cellIndex]].mOffsetY = mainOffset;
        gSelectCupM->mMainTable[mainCellCount + gSelectCupMCourseLabels[cellIndex]].mOffsetY = mainOffset;
    }
    subCellCount = gSelectCupM->mSubBncl->mCount;
    gSelectCupM->mBg3Offset = subOffset;
    gSelectCupM->mSubTable[20].mOffsetY = subOffset;
    gSelectCupM->mSubTable[19].mOffsetY = subOffset;
    gSelectCupM->mSubTable[2].mOffsetY = subOffset;
    gSelectCupM->mSubTable[1].mOffsetY = subOffset;
    gSelectCupM->mSubTable[0].mOffsetY = subOffset;
    for (cellIndex = 0; cellIndex < 8; cellIndex++) {
        gSelectCupM->mSubTable[data_0215cf1c[cellIndex]].mOffsetY = subOffset;
    }
    for (cellIndex = 0; cellIndex < 4; cellIndex++) {
        gSelectCupM->mSubTable[gSelectCupMCourseCells[cellIndex]].mOffsetY = subOffset;
        gSelectCupM->mSubTable[subCellCount + gSelectCupMCourseLabels[cellIndex]].mOffsetY = subOffset;
    }
}

void AdvanceSelectCupMState1(void) {
    s32 cellIndex;
    s16 mainOffset;
    s16 subOffset;
    u16 mainCellCount;
    u16 subCellCount;

    gSelectCupM->mStateFrames++;
    if (gBootInfo->mBootType == 2) {
        return;
    }
    mainOffset = InterpolateS16(1, 0xc0, 0, gSelectCupM->mStateFrames, 0xa);
    subOffset = InterpolateS16(1, ~0x1f, ~0xbf, gSelectCupM->mStateFrames, 0xa);
    mainCellCount = gSelectCupM->mMainBncl->mCount;
    gSelectCupM->mBg0Offset = mainOffset;
    gSelectCupM->mMainTable[20].mOffsetY = mainOffset;
    gSelectCupM->mMainTable[19].mOffsetY = mainOffset;
    gSelectCupM->mMainTable[2].mOffsetY = mainOffset;
    gSelectCupM->mMainTable[1].mOffsetY = mainOffset;
    gSelectCupM->mMainTable[0].mOffsetY = mainOffset;
    for (cellIndex = 0; cellIndex < 8; cellIndex++) {
        gSelectCupM->mMainTable[data_0215cf1c[cellIndex]].mOffsetY = mainOffset;
    }
    for (cellIndex = 0; cellIndex < 4; cellIndex++) {
        gSelectCupM->mMainTable[gSelectCupMCourseCells[cellIndex]].mOffsetY = mainOffset;
        gSelectCupM->mMainTable[mainCellCount + gSelectCupMCourseLabels[cellIndex]].mOffsetY = mainOffset;
    }
    subCellCount = gSelectCupM->mSubBncl->mCount;
    gSelectCupM->mBg3Offset = subOffset;
    gSelectCupM->mSubTable[20].mOffsetY = subOffset;
    gSelectCupM->mSubTable[19].mOffsetY = subOffset;
    gSelectCupM->mSubTable[2].mOffsetY = subOffset;
    gSelectCupM->mSubTable[1].mOffsetY = subOffset;
    gSelectCupM->mSubTable[0].mOffsetY = subOffset;
    for (cellIndex = 0; cellIndex < 8; cellIndex++) {
        gSelectCupM->mSubTable[data_0215cf1c[cellIndex]].mOffsetY = subOffset;
    }
    for (cellIndex = 0; cellIndex < 4; cellIndex++) {
        gSelectCupM->mSubTable[gSelectCupMCourseCells[cellIndex]].mOffsetY = subOffset;
        gSelectCupM->mSubTable[subCellCount + gSelectCupMCourseLabels[cellIndex]].mOffsetY = subOffset;
    }
}

s32 AdvanceSelectCupM(void) {
    s32 index;
    u16 *cupPictureScreenMap;
    s32 screenMapIndex;
    s32 transferKind;
    s32 transferSize;

    gSelectCupM->mState = gSelectCupM->mNextState;
    switch (gSelectCupM->mState) {
        case 0:
            AdvanceSelectCupMState0();
            break;
        case 1:
            AdvanceSelectCupMState1();
            break;
    }
    if (gBootInfo->mBootType != 2) {
        if (gSelectCupM->mCupPicturePending != FALSE && IsCupPictureReady() != FALSE) {
            cupPictureScreenMap = GetCupPictureNscrData();
            NNS_GfdRegisterNewVramTransferTask(0xf, 0, GetCupPictureNclrData(), 0xe0);
            NNS_GfdRegisterNewVramTransferTask(4, 0x20, GetCupPictureNcgrData(), 0xdc0);
            transferKind = 8;
            transferSize = 0x14;
            for (index = 0; index < 0xb; index++) {
                screenMapIndex = ((index + 8) << 5) + 0x16;
                NNS_GfdRegisterNewVramTransferTask(transferKind, screenMapIndex << 1,
                                                   cupPictureScreenMap + screenMapIndex, transferSize);
            }
            NNS_GfdRegisterNewVramTransferTask(0x1f, 0, GetCupPictureNclrData(), 0xe0);
            NNS_GfdRegisterNewVramTransferTask(0x17, 0x20, GetCupPictureNcgrData(), 0xdc0);
            transferKind = 0x1b;
            for (index = 0; index < 0xb; index++) {
                screenMapIndex = ((index + 8) << 5) + 0x16;
                NNS_GfdRegisterNewVramTransferTask(transferKind, screenMapIndex << 1,
                                                   cupPictureScreenMap + screenMapIndex, transferSize);
            }
            gSelectCupM->mCupPicturePending = FALSE;
        }
        DrawLayoutTable(gSelectCupM->mMainBncl, gSelectCupM->mMainNcer, gSelectCupM->mMainBnll, gSelectCupM->mMainOam,
                        gSelectCupM->mMainTable);
        DrawLayoutTable(gSelectCupM->mSubBncl, gSelectCupM->mSubNcer, gSelectCupM->mSubBnll, gSelectCupM->mSubOam,
                        gSelectCupM->mSubTable);
    } else {
        AdvanceSelectRaceRuleWait();
    }
    if (gSelectCupM->mState == 0 && gSelectCupM->mStateFrames > 0xa) {
        return 1;
    }
    if (gSelectCupM->mState == 1 && gSelectCupM->mStateFrames > 0xa) {
        return 2;
    }
    return 0;
}

void WriteSelectCupMBgOffsets(void) {
    reg_G2_BG0OFS = (-gSelectCupM->mBg0Offset << 16) & 0x1ff0000;
    reg_G2S_DB_BG3OFS = (-gSelectCupM->mBg3Offset << 16) & 0x1ff0000;
}

#pragma thumb off
