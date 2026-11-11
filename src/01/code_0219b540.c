#include "01/code_0219b540.h"

#include "01/unk_021a6000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_020ea000.h"
#include "Main/Unknown/code_02048000.h"
#include "01/unk_021a9000.h"
#include "code_02013740.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02087000.h"
#include "Main/Unknown/code_02088000.h"
#include "code_02134398.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_02116a4c.h"
#include "Main/Unknown/code_021171a0.h"
#include "Main/Unknown/code_0211de00.h"
#include "Main/Unknown/code_0211de34.h"
#include "Main/Unknown/code_0211e0c4.h"
#include "Main/Unknown/code_021277ac.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_02128244.h"
#include "Main/Unknown/code_0212775c.h"
#include "01/code_0219c000.h"
#include "Main/Unknown/code_0212b000.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_0212b1a8.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/code_0201ea58.h"
#include "Main/Unknown/code_02117218.h"
#include "registers.h"
#include "Main/Unknown/code_02116000.h"
#include "Main/Unknown/code_02117000.h"
#include "Main/Unknown/code_0211d000.h"
#include "Main/Unknown/code_0211e000.h"
#include "code_02148950.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"
#include "01/unk_021a8000.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_0211732c.h"

SelectGhost *gSelectGhost;

void LoadSelectGhostAndKartIconData(void) {
    Ncgr *selectGhostSONcgr = NULL;
    Unk02021dc8 *selectGhostSONcer = NULL;
    Nclr *selectGhostSONclr = NULL;
    Ncgr *selectGhostSBNcgr = NULL;
    Nclr *selectGhostSBNclr = NULL;
    Nscr *selectGhostSNscr = NULL;

    LoadNcgrData(&selectGhostSBNcgr, FindSceneFile(gSelectGhostSBNcgrName));
    LoadNscrData(&selectGhostSNscr, FindSceneFile(gSelectGhostSNscrName));
    LoadNclrData(&selectGhostSBNclr, FindSceneFile(gSelectGhostSBNclrName));
    LoadNcgrData2(&selectGhostSONcgr, FindSceneFile(gSelectGhostSONcgrName));
    LoadNcerData(&selectGhostSONcer, FindSceneFile(gSelectGhostSONcerName));
    LoadNclrData(&selectGhostSONclr, FindSceneFile(gSelectGhostSONclrName));
    LoadCommonKartIconData();
}

void LocateAndQueueSelectGhost(void) {
    Ncgr *selectGhostSONcgr;
    Ncgr *selectGhostSBNcgr;
    Nclr *selectGhostSBNclr;
    Nscr *selectGhostSNscr;

    selectGhostSONcgr = NULL;
    selectGhostSBNcgr = NULL;
    selectGhostSBNclr = NULL;
    selectGhostSNscr = NULL;
    LocateNcgr(&selectGhostSBNcgr, FindSceneFile(gSelectGhostSBNcgrName));
    LocateNscr(&selectGhostSNscr, FindSceneFile(gSelectGhostSNscrName));
    LocateNclr(&selectGhostSBNclr, FindSceneFile(gSelectGhostSBNclrName));
    gSelectGhost->mSecondScreenMapBuffer = HeapAlloc(gSelectGhost->mHeap, 0x800);
    gSelectGhost->mSelectCupCourseTaMBncl = FindSceneFile(gSelectCupCourseTaMBnclName);
    gSelectGhost->mSelectCupCourseTaMBnll = FindSceneFile(gSelectCupCourseTaMBnllName);
    LocateNcer(&gSelectGhost->mSelectCupCourseMNcer, FindSceneFile(gSelectCupCourseMNcerName));
    gSelectGhost->mSelectGhostSBncl = FindSceneFile(gSelectGhostSBnclName);
    gSelectGhost->mSelectGhostSBnbl = FindSceneFile(gSelectGhostSBnblName);
    gSelectGhost->mSelectGhostSBnll = FindSceneFile(gSelectGhostSBnllName);
    LocateNcgr2(&selectGhostSONcgr, FindSceneFile(gSelectGhostSONcgrName));
    LocateNcer(&gSelectGhost->mSelectGhostSONcer, FindSceneFile(gSelectGhostSONcerName));
    LocateNclr(&gSelectGhost->mSelectGhostSONclr, FindSceneFile(gSelectGhostSONclrName));
    gSelectGhost->mPlayerCharacterMNcgr = GetPlayerCharacterNcgr(0);
    gSelectGhost->mPlayerCharacterMNcer = GetPlayerCharacterNcer(0);
    gSelectGhost->mPlayerCharacterMONclr = GetPlayerCharacterNclr(0);
    gSelectGhost->mPlayerCharacterMBncl = GetPlayerCharacterBncl(0);
    NNS_GfdRegisterNewVramTransferTask(0x17, 0, selectGhostSBNcgr->mData, selectGhostSBNcgr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x1f, 0, selectGhostSBNclr->mData, 0x20);
    NNS_GfdRegisterNewVramTransferTask(0x1b, 0, selectGhostSNscr->mData, selectGhostSNscr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x1b, 0x800, gSelectGhost->mSecondScreenMapBuffer, 0x800);
    NNS_GfdRegisterNewVramTransferTask(0x23, 0, selectGhostSONcgr->mData, selectGhostSONcgr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x1e, 0, gSelectGhost->mSelectGhostSONclr->mData,
                                       gSelectGhost->mSelectGhostSONclr->mDataSize);
}

void ResetSelectGhost(void) {
    u16 cnt;
    s32 i;

    gSelectGhost->mNextState = 0;
    gSelectGhost->mStateFrames = 0;
    gSelectGhost->mBg0Offset = 0;
    gSelectGhost->mBg3Offset = -0xc0;
    for (i = 0; i < 6; i++) {
        gSelectGhost->mSelectGhostSTable[gSelectGhostSTableIndices[i]].mOffsetY = -0xc0;
    }
    gSelectGhost->mSelectGhostSTable[10].mOffsetY = -0xc0;
    gSelectGhost->mSelectGhostSTable[11].mOffsetY = -0xc0;
    cnt = gSelectGhost->mSelectGhostSBncl->mCount;
    for (i = 0; i < 5; i++) {
        gSelectGhost->mSelectGhostSTable[cnt + gSelectGhostSBnllIndices[i]].mOffsetY = -0xc0;
    }
    gSelectGhost->mSelectGhostSTable[cnt + 5].mOffsetY = -0xc0;
    for (i = 0; i < 2; i++) {
        gSelectGhost->mSelectGhostSTable[gSelectGhostTimerZeroSTableIndices[i]].mOffsetY = -0xc0;
        gSelectGhost->mSelectGhostSTable[gSelectGhostRunningSTableIndices[i]].mOffsetY = -0xc0;
    }
}

// Requests state 1.
void RequestSelectGhostState1(void) {
    gSelectGhost->mNextState = 1;
    gSelectGhost->mStateFrames = 0;
}

// Requests state 2.
void RequestSelectGhostState2(void) {
    gSelectGhost->mNextState = 2;
    gSelectGhost->mStateFrames = 0;
}

void RequestSelectGhostState3(void) {
    gSelectGhost->mNextState = 3;
    gSelectGhost->mStateFrames = 0;
    StopPaletteBlend();
    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 5);
}

void RequestSelectGhostState4(void) {
    gSelectGhost->mNextState = 4;
    gSelectGhost->mStateFrames = 0;
    StartSelectChoises(GetBmgEntry(gSelectGhost->mCommonMessages, 4), GetBmgEntry(gSelectGhost->mCommonMessages, 2), 0);
}

// Requests state 5.
void RequestSelectGhostState5(void) {
    gSelectGhost->mNextState = 5;
    gSelectGhost->mStateFrames = 0;
}

void RequestSelectGhostState6(void) {
    gSelectGhost->mNextState = 6;
    gSelectGhost->mStateFrames = 0;
    RequestSelectChoisesState0();
}

// Requests state 7.
void RequestSelectGhostState7(void) {
    gSelectGhost->mNextState = 7;
    gSelectGhost->mStateFrames = 0;
}

void UpdateSelectGhostCellVisibility(void) {
    gSelectGhost->mSelectGhostSTable[10].mVisible = 1;
    gSelectGhost->mSelectGhostSTable[11].mVisible = 0;
    gSelectGhost->mSelectGhostSTable[gSelectGhostSTableIndices[0]].mVisible = 1;
    gSelectGhost->mSelectGhostSTable[gSelectGhostSTableIndices[1]].mVisible = 0;
    gSelectGhost->mSelectGhostSTable[10].mVisible = 0;
    gSelectGhost->mSelectGhostSTable[11].mVisible = 1;
}

// Stores both offsets and steps both timers; each timer switches its rows on or off.
void AdvanceSelectGhostOffsetTimers(void) {
    s32 i;
    gSelectGhost->mSelectGhostSTable[gSelectGhostRunningSTableIndices[0]].mOffsetX =
        -LookupFrameOffset(6 - gSelectGhost->mOffsetTimers[0]);
    gSelectGhost->mSelectGhostSTable[gSelectGhostRunningSTableIndices[1]].mOffsetX =
        LookupFrameOffset(6 - gSelectGhost->mOffsetTimers[1]);
    for (i = 0; i < 2; i++) {
        if (gSelectGhost->mOffsetTimers[i] > 0) {
            gSelectGhost->mOffsetTimers[i]--;
            gSelectGhost->mSelectGhostSTable[gSelectGhostTimerZeroSTableIndices[i]].mVisible = 0;
            gSelectGhost->mSelectGhostSTable[gSelectGhostRunningSTableIndices[i]].mVisible = 1;
        } else {
            gSelectGhost->mSelectGhostSTable[gSelectGhostTimerZeroSTableIndices[i]].mVisible = 1;
            gSelectGhost->mSelectGhostSTable[gSelectGhostRunningSTableIndices[i]].mVisible = 0;
        }
    }
}

void RefreshSelectGhostForIndex(void) {
    SelectGhost *selectGhost = gSelectGhost;
    LayoutEntryTable *subLayout;
    u16 subLayoutCount;
    u16 characterCellIndex;
    u16 kartCellIndex;
    u16 nameLabelIndex;
    u16 timeLabelIndex;
    u16 *paletteData;
    s32 characterCell;
    s32 ghostRecordSetKartIndex;
    u8 buf14[4];
    u16 buf18[16];

    subLayout = selectGhost->mSelectGhostSBncl;
    subLayoutCount = subLayout->mCount;
    PrintLabelLayoutTextNoFixedAdvance(
        1, gSelectGhostSBnllIndices[4], gSelectGhost->mSelectGhostSBnll,
        GetBmgEntry(selectGhost->mMenuMessages, gSelectGhostMenuMessageIndices[selectGhost->mIndex]), subLayout,
        selectGhost->mSelectGhostSTable);
    if (gSelectGhost->mIndex == 0) {
        gSelectGhost->mSelectGhostSTable[gSelectGhostSTableIndices[2]].mVisible = 0;
        gSelectGhost->mSelectGhostSTable[gSelectGhostSTableIndices[3]].mVisible = 0;
        gSelectGhost->mSelectGhostSTable[gSelectGhostSTableIndices[4]].mVisible = 0;
        gSelectGhost->mSelectGhostSTable[gSelectGhostSTableIndices[5]].mVisible = 0;
        gSelectGhost->mSelectGhostSTable[subLayoutCount + gSelectGhostSBnllIndices[0]].mVisible = 0;
        gSelectGhost->mSelectGhostSTable[subLayoutCount + gSelectGhostSBnllIndices[1]].mVisible = 0;
        gSelectGhost->mSelectGhostSTable[subLayoutCount + gSelectGhostSBnllIndices[2]].mVisible = 0;
        return;
    }
    gSelectGhost->mSelectGhostSTable[gSelectGhostSTableIndices[2]].mVisible = 1;
    gSelectGhost->mSelectGhostSTable[gSelectGhostSTableIndices[3]].mVisible = 1;
    characterCellIndex = gSelectGhostSTableIndices[4];
    gSelectGhost->mSelectGhostSTable[characterCellIndex].mVisible = 1;
    kartCellIndex = gSelectGhostSTableIndices[5];
    gSelectGhost->mSelectGhostSTable[kartCellIndex].mVisible = 1;
    gSelectGhost->mSelectGhostSTable[subLayoutCount + gSelectGhostSBnllIndices[0]].mVisible = 1;
    timeLabelIndex = gSelectGhostSBnllIndices[1];
    gSelectGhost->mSelectGhostSTable[subLayoutCount + timeLabelIndex].mVisible = 1;
    nameLabelIndex = gSelectGhostSBnllIndices[2];
    gSelectGhost->mSelectGhostSTable[subLayoutCount + nameLabelIndex].mVisible = 1;
    characterCell =
        gSelectGhostCharacterCells[GetGhostRecordSetCharacterIndex(gSelectGhostRecordKinds[gSelectGhost->mIndex])];
    QueueCellChars(characterCell, gSelectGhost->mPlayerCharacterMNcer, gSelectGhost->mPlayerCharacterMNcgr,
                   gSelectGhost->mPlayerCharacterMBncl, 1, characterCellIndex, gSelectGhost->mSelectGhostSONcer,
                   gSelectGhost->mSelectGhostSBncl);
    paletteData = gSelectGhost->mPlayerCharacterMONclr->mData;
    NNS_GfdRegisterNewVramTransferTask(0x1e, 0x100,
                                       (u8 *) paletteData +
                                           (GetCellPaletteIndex(characterCell, gSelectGhost->mPlayerCharacterMNcer,
                                                                gSelectGhost->mPlayerCharacterMBncl)
                                            << 5),
                                       0x20);
    ghostRecordSetKartIndex = GetGhostRecordSetKartIndex(gSelectGhostRecordKinds[gSelectGhost->mIndex]);
    QueueKartIcon(ghostRecordSetKartIndex, gSelectGhost->mSelectGhostSONcer, gSelectGhost->mSelectGhostSBncl,
                  kartCellIndex, 9, 1);
    GetGhostRecordSetTime(gSelectGhostRecordKinds[gSelectGhost->mIndex], buf14);
    FormatTimeFullWidth(buf14, buf18);
    PrintLabelLayoutTextFixedDigits(1, timeLabelIndex, gSelectGhost->mSelectGhostSBnll, buf18,
                                    gSelectGhost->mSelectGhostSBncl, gSelectGhost->mSelectGhostSTable, 9);
    GetGhostRecordSetName(gSelectGhostRecordKinds[gSelectGhost->mIndex], buf18);
    PrintLabelLayoutTextNoFixedAdvance(1, nameLabelIndex, gSelectGhost->mSelectGhostSBnll, buf18,
                                       gSelectGhost->mSelectGhostSBncl, gSelectGhost->mSelectGhostSTable);
}

void IncrementSelectGhostIndex(void) {
    BOOL ok = TRUE;
    gSelectGhost->mIndex++;
    if (gSelectGhost->mIndex >= 4) {
        gSelectGhost->mIndex = 0;
    }
    if (IsGhostRecordSetKindSelectable(gSelectGhostRecordKinds[gSelectGhost->mIndex]) == 0) {
        ok = FALSE;
        IncrementSelectGhostIndex();
    }
    gSelectGhost->mOffsetTimers[1] = 6;
    if (ok != FALSE) {
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 1);
        RefreshSelectGhostForIndex();
    }
}

void DecrementSelectGhostIndex(void) {
    BOOL ok = TRUE;
    gSelectGhost->mIndex--;
    if (gSelectGhost->mIndex < 0) {
        gSelectGhost->mIndex = 3;
    }
    if (IsGhostRecordSetKindSelectable(gSelectGhostRecordKinds[gSelectGhost->mIndex]) == 0) {
        ok = FALSE;
        DecrementSelectGhostIndex();
    }
    gSelectGhost->mOffsetTimers[0] = 6;
    if (ok != FALSE) {
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 1);
        RefreshSelectGhostForIndex();
    }
}

void ReadSelectGhostRecords(void) {
    SetRaceSetupCopyGhostRecordIndex(gSelectGhostRecordKinds[gSelectGhost->mIndex]);
    ReadGhostRecordsForKind(gSelectGhostRecordKinds[gSelectGhost->mIndex]);
}

void SetupSelectGhostCupCells(void) {
    u16 n = gSelectGhost->mSelectCupCourseTaMBncl->mCount;

    gSelectGhost->mSelectCupCourseTaMTable[0].mVisible = 1;
    gSelectGhost->mSelectCupCourseTaMTable[2].mVisible = 1;
    gSelectGhost->mSelectCupCourseTaMTable[1].mVisible = 1;
    gSelectGhost->mSelectCupCourseTaMTable[4].mVisible = 1;
    gSelectGhost->mSelectCupCourseTaMTable[3].mVisible = 1;
    gSelectGhost->mSelectCupCourseTaMTable[5].mVisible = 1;
    gSelectGhost->mSelectCupCourseTaMTable[n].mVisible = 1;
    gSelectGhost->mSelectCupCourseTaMTable[n + 1].mVisible = 1;
    gSelectGhost->mSelectCupCourseTaMTable[n + 2].mVisible = 1;
    gSelectGhost->mSelectCupCourseTaMTable[n + 3].mVisible = 1;
    gSelectGhost->mSelectCupCourseTaMTable[n + 4].mVisible = 1;
    gSelectGhost->mSelectCupCourseTaMTable[n + 5].mVisible = 1;
    QueueSelectCupNameM(gSelectGhostCupIndices[GetCupIndex()], gSelectGhost->mSelectCupCourseMNcer,
                        gSelectGhost->mSelectCupCourseTaMBncl, 0, 0);
    QueueCupMark(gSelectGhostCupIndices[GetCupIndex()], gSelectGhost->mSelectCupCourseMNcer,
                 gSelectGhost->mSelectCupCourseTaMBncl, 5,
                 GetCellPaletteIndex(5, gSelectGhost->mSelectCupCourseMNcer, gSelectGhost->mSelectCupCourseTaMBncl), 0);
    PrintLabelLayoutTextNoFixedAdvance(0, 2, gSelectGhost->mSelectCupCourseTaMBnll,
                                       GetBmgEntry(gSelectGhost->mCommonMessages, 0x73),
                                       gSelectGhost->mSelectCupCourseTaMBncl, gSelectGhost->mSelectCupCourseTaMTable);
    PrintLabelLayoutTextNoFixedAdvance(0, 4, gSelectGhost->mSelectCupCourseTaMBnll,
                                       GetBmgEntry(gSelectGhost->mCommonMessages, 0x74),
                                       gSelectGhost->mSelectCupCourseTaMBncl, gSelectGhost->mSelectCupCourseTaMTable);
    SetLabelOamModeXlu(0, 0, gSelectGhost->mSelectCupCourseTaMBnll, gSelectGhost->mSelectCupCourseTaMTable,
                       gSelectGhost->mSelectCupCourseTaMBncl);
    SetLabelOamModeXlu(1, 0, gSelectGhost->mSelectCupCourseTaMBnll, gSelectGhost->mSelectCupCourseTaMTable,
                       gSelectGhost->mSelectCupCourseTaMBncl);
    SetLabelOamModeXlu(2, 0, gSelectGhost->mSelectCupCourseTaMBnll, gSelectGhost->mSelectCupCourseTaMTable,
                       gSelectGhost->mSelectCupCourseTaMBncl);
    SetLabelOamModeXlu(4, 0, gSelectGhost->mSelectCupCourseTaMBnll, gSelectGhost->mSelectCupCourseTaMTable,
                       gSelectGhost->mSelectCupCourseTaMBncl);
}

void InitSelectGhost(void *parentHeap, u32 mainOam, u32 subOam) {
    void *heap;
    s32 rem;
    s32 i;

    reg_G2S_DB_BG0CNT = reg_G2S_DB_BG0CNT & ~3;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & ~3) | 1;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & 0x43) | 0x8300;
    heap = CreateFrmHeapFromMaxFree(parentHeap);
    gSelectGhost = HeapAlloc(heap, 0x70);
    gSelectGhost->mHeap = heap;
    gSelectGhost->mState = 0;
    gSelectGhost->mIndex = 0;
    gSelectGhost->mMainOamList = mainOam;
    gSelectGhost->mSubOamList = subOam;
    gSelectGhost->mResult = 0;
    LocateAndQueueSelectGhost();
    CreateCommonKartIcon(gSelectGhost->mHeap);
    InitLayoutTable(gSelectGhost->mHeap, gSelectGhost->mSelectCupCourseTaMBncl, gSelectGhost->mSelectCupCourseTaMBnll,
                    &gSelectGhost->mSelectCupCourseTaMTable);
    InitLayoutTable(gSelectGhost->mHeap, gSelectGhost->mSelectGhostSBncl, gSelectGhost->mSelectGhostSBnll,
                    &gSelectGhost->mSelectGhostSTable);
    gSelectGhost->mCommonMessages = FindFileInLoadedArchives("common.bmg");
    gSelectGhost->mMenuMessages = FindSceneFile("menu.bmg");
    rem = 0x8000;
    rem -= InitLabelCanvas(gSelectGhost->mHeap, 0, gSelectGhost->mSelectCupCourseTaMBnll, 0xb4, 0xd, 0,
                           gSelectGhost->mSelectCupCourseMNcer, gSelectGhost->mSelectCupCourseTaMBncl,
                           gSelectGhost->mSelectCupCourseTaMTable, rem);
    rem -= InitLabelCanvas(gSelectGhost->mHeap, 1, gSelectGhost->mSelectCupCourseTaMBnll, 0xb4, 0xd, 1,
                           gSelectGhost->mSelectCupCourseMNcer, gSelectGhost->mSelectCupCourseTaMBncl,
                           gSelectGhost->mSelectCupCourseTaMTable, rem);
    rem -= InitLabelCanvas(gSelectGhost->mHeap, 2, gSelectGhost->mSelectCupCourseTaMBnll, 0x96, 0xd, 2,
                           gSelectGhost->mSelectCupCourseMNcer, gSelectGhost->mSelectCupCourseTaMBncl,
                           gSelectGhost->mSelectCupCourseTaMTable, rem);
    rem -= InitLabelCanvas(gSelectGhost->mHeap, 3, gSelectGhost->mSelectCupCourseTaMBnll, 0x50, 0xd, 3,
                           gSelectGhost->mSelectCupCourseMNcer, gSelectGhost->mSelectCupCourseTaMBncl,
                           gSelectGhost->mSelectCupCourseTaMTable, rem);
    rem -= InitLabelCanvas(gSelectGhost->mHeap, 4, gSelectGhost->mSelectCupCourseTaMBnll, 0x96, 0xd, 4,
                           gSelectGhost->mSelectCupCourseMNcer, gSelectGhost->mSelectCupCourseTaMBncl,
                           gSelectGhost->mSelectCupCourseTaMTable, rem);
    InitLabelCanvas(gSelectGhost->mHeap, 5, gSelectGhost->mSelectCupCourseTaMBnll, 0x50, 0xd, 5,
                    gSelectGhost->mSelectCupCourseMNcer, gSelectGhost->mSelectCupCourseTaMBncl,
                    gSelectGhost->mSelectCupCourseTaMTable, rem);
    rem = GX_GetSizeOfSubOBJ();
    for (i = 0; i < 5; i++) {
        rem -= InitLabelCanvas(gSelectGhost->mHeap, gSelectGhostSBnllIndices[i], gSelectGhost->mSelectGhostSBnll,
                               gSelectGhostSLabelWidths[i], gSelectGhostSLabelHeights[i], i,
                               gSelectGhost->mSelectGhostSONcer, gSelectGhost->mSelectGhostSBncl,
                               gSelectGhost->mSelectGhostSTable, rem);
    }
    InitLabelCanvas(gSelectGhost->mHeap, 5, gSelectGhost->mSelectGhostSBnll, 0x32, 0xd, 0xb,
                    gSelectGhost->mSelectGhostSONcer, gSelectGhost->mSelectGhostSBncl, gSelectGhost->mSelectGhostSTable,
                    rem);
    PrintLabelLayoutTextNoFixedAdvance(1, gSelectGhostSBnllIndices[0], gSelectGhost->mSelectGhostSBnll,
                                       GetBmgEntry(gSelectGhost->mMenuMessages, 8), gSelectGhost->mSelectGhostSBncl,
                                       gSelectGhost->mSelectGhostSTable);
    PrintLabelLayoutTextNoFixedAdvance(1, gSelectGhostSBnllIndices[3], gSelectGhost->mSelectGhostSBnll,
                                       GetBmgEntry(gSelectGhost->mMenuMessages, 9), gSelectGhost->mSelectGhostSBncl,
                                       gSelectGhost->mSelectGhostSTable);
    PrintLabelLayoutTextNoFixedAdvance(1, gSelectGhostSBnllIndices[4], gSelectGhost->mSelectGhostSBnll,
                                       GetBmgEntry(gSelectGhost->mMenuMessages, gSelectGhostMenuMessageIndices[0]),
                                       gSelectGhost->mSelectGhostSBncl, gSelectGhost->mSelectGhostSTable);
    PrintLabelLayoutTextNoFixedAdvance(1, 5, gSelectGhost->mSelectGhostSBnll,
                                       GetBmgEntry(gSelectGhost->mCommonMessages, 4), gSelectGhost->mSelectGhostSBncl,
                                       gSelectGhost->mSelectGhostSTable);
    CreateSelectCupNameM(gSelectGhost->mHeap);
    CreateCommonCupMark(gSelectGhost->mHeap);
    InitPaletteBlend(gSelectGhost->mHeap, gSelectGhost->mSelectGhostSONclr, 4);
    ResetPaletteBlendCycle();
    SetupSelectGhostCupCells();
    ResetSelectGhost();
    for (i = 3; i >= 0; i--) {
        if (IsGhostRecordSetKindSelectable(gSelectGhostRecordKinds[i]) != 0) {
            gSelectGhost->mIndex = i;
            break;
        }
    }
    RefreshSelectGhostForIndex();
    FrmHeapShrinkInParent(gSelectGhost->mHeap);
}

void ReleaseSelectGhost(void) {
    if (gSelectGhost->mResult == 1) {
        reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0x1f00) | 0x1800;
    }
    ClearPaletteBlendPointer();
    ClearSelectCupNameMPointer();
    ClearCupMarkPointer();
    ClearKartIconPointer();
    HeapDestroy(gSelectGhost->mHeap);
    gSelectGhost = NULL;
}

void AdvanceSelectGhostState0(void) {
    u16 subLayoutCount;
    s16 offsetY;
    s32 i;

    AdvanceSelectGhostOffsetTimers();
    subLayoutCount = gSelectGhost->mSelectGhostSBncl->mCount;
    gSelectGhost->mStateFrames++;
    offsetY = InterpolateS16(1, ~0xbf, 0, gSelectGhost->mStateFrames, 10);
    gSelectGhost->mBg3Offset = offsetY;
    for (i = 0; i < 6; i++) {
        gSelectGhost->mSelectGhostSTable[gSelectGhostSTableIndices[i]].mOffsetY = offsetY;
    }
    for (i = 0; i < 5; i++) {
        gSelectGhost->mSelectGhostSTable[subLayoutCount + gSelectGhostSBnllIndices[i]].mOffsetY = offsetY;
    }
    for (i = 0; i < 2; i++) {
        gSelectGhost->mSelectGhostSTable[gSelectGhostTimerZeroSTableIndices[i]].mOffsetY = offsetY;
        gSelectGhost->mSelectGhostSTable[gSelectGhostRunningSTableIndices[i]].mOffsetY = offsetY;
    }
    if (gSelectGhost->mStateFrames >= 10) {
        RequestSelectGhostState1();
    }
}

void AdvanceSelectGhostState1(void) {
    u16 subLayoutCount;
    s16 returnOffsetY;

    AdvanceSelectGhostOffsetTimers();
    subLayoutCount = gSelectGhost->mSelectGhostSBncl->mCount;
    gSelectGhost->mStateFrames++;
    returnOffsetY = -LookupSelectReturnState1Bg2Offset(gSelectGhost->mStateFrames);
    gSelectGhost->mSelectGhostSTable[10].mOffsetY = returnOffsetY;
    gSelectGhost->mSelectGhostSTable[11].mOffsetY = returnOffsetY;
    gSelectGhost->mSelectGhostSTable[subLayoutCount + 5].mOffsetY = returnOffsetY;
    if (gSelectGhost->mStateFrames >= 10) {
        RequestSelectGhostState2();
    }
}

void AdvanceSelectGhostState2(void) {
    s32 touchBeganRect;
    BOOL touchBegan;
    BOOL recentlyLost;
    BOOL touchBeganAgain;
    BOOL recentlyLostAgain;
    InputSlotIndex slotIndex;

    touchBeganRect = -1;
    AdvanceSelectGhostOffsetTimers();
    slotIndex = UNK_02175628_INDEX_8;
    touchBegan = FALSE;
    recentlyLost = FALSE;
    if (gInputSlots[slotIndex].mPair.mHasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < 5) {
        recentlyLost = TRUE;
    }
    if (recentlyLost == FALSE && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 &&
        gInputSlots[slotIndex].mPair.mHasPair != 0) {
        touchBegan = TRUE;
    }
    if (touchBegan != FALSE) {
        touchBeganRect = RectTableFindContaining(gSelectGhost->mSelectGhostSBnbl, gInputSlots[slotIndex].mPair.mPairX,
                                                 gInputSlots[slotIndex].mPair.mPairY);
    }
    if ((u16) (gInputSlots[slotIndex].mPressedBits & PAD_KEY_B) == 0) {
        touchBeganAgain = FALSE;
        recentlyLostAgain = FALSE;
        if (gInputSlots[slotIndex].mPair.mHasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < 5) {
            recentlyLostAgain = TRUE;
        }
        if (recentlyLostAgain == FALSE && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 &&
            gInputSlots[slotIndex].mPair.mHasPair != 0) {
            touchBeganAgain = TRUE;
        }
        if (touchBeganAgain == FALSE ||
            IsSelectReturnState2NoState3Or4RequestAndInRect(gInputSlots[slotIndex].mPair.mPairX,
                                                            gInputSlots[slotIndex].mPair.mPairY) == FALSE) {
            goto next;
        }
    }
    SetSelectReturnSoundId(14);
    RequestSelectGhostState7();
    gSelectGhost->mResult = 2;
    RequestSelectReturnState3WithSound(0);
    return;
next:
    if (touchBeganRect == 0) {
        DecrementSelectGhostIndex();
        return;
    }
    if (touchBeganRect == 1) {
        IncrementSelectGhostIndex();
        return;
    }
    if (touchBeganRect == 3) {
        RequestSelectGhostState3();
        return;
    }
    if (touchBeganRect == 2) {
        IncrementSelectGhostIndex();
        return;
    }
    if ((u16) (gInputSlots[slotIndex].mPressedBits & PAD_KEY_A) != 0) {
        RequestSelectGhostState3();
        return;
    }
    if (GetNewOrRepeatBits(8, PAD_KEY_LEFT) != 0) {
        DecrementSelectGhostIndex();
        return;
    }
    if (GetNewOrRepeatBits(8, PAD_KEY_RIGHT) != 0) {
        IncrementSelectGhostIndex();
    }
}

void AdvanceSelectGhostState3(void) {
    AdvanceSelectGhostOffsetTimers();
    gSelectGhost->mStateFrames++;
    if (gSelectGhost->mStateFrames >= 10) {
        RequestSelectGhostState4();
    }
}

void AdvanceSelectGhostState4(void) {
    if (IsSelectChoisesState1NoState0Request() != 0) {
        RequestSelectGhostState5();
    }
}

void AdvanceSelectGhostState5(void) {
    int selectChoisesDone;
    selectChoisesDone = GetSelectChoisesDone();
    if (selectChoisesDone != 0) {
        RequestSelectGhostState6();
    }
}

void AdvanceSelectGhostState6(void) {
    s32 selectChoisesIndex;

    if (IsSelectChoisesState0NoState1Request() == 0) {
        return;
    }
    selectChoisesIndex = GetSelectChoisesIndex();
    switch (selectChoisesIndex) {
        case 0:
            ReadSelectGhostRecords();
            gSelectGhost->mResult = 1;
            RequestSelectGhostState7();
            RequestSelectReturnState4();
            break;
        case -1:
        case 1:
            StartPaletteBlend();
            RequestSelectGhostState2();
            break;
    }
}

void AdvanceSelectGhostState7(void) {
    BOOL resultIsOne;
    s16 offsetY;
    s16 returnOffsetY;
    u16 n;
    s32 i;

    resultIsOne = gSelectGhost->mResult == 1;
    gSelectGhost->mStateFrames++;
    offsetY = InterpolateS16(1, 0, ~0xbf, gSelectGhost->mStateFrames, 10);
    if (resultIsOne) {
        n = gSelectGhost->mSelectCupCourseTaMBncl->mCount;
        gSelectGhost->mBg0Offset = offsetY;
        gSelectGhost->mSelectCupCourseTaMTable[0].mOffsetY = offsetY;
        gSelectGhost->mSelectCupCourseTaMTable[2].mOffsetY = offsetY;
        gSelectGhost->mSelectCupCourseTaMTable[1].mOffsetY = offsetY;
        gSelectGhost->mSelectCupCourseTaMTable[4].mOffsetY = offsetY;
        gSelectGhost->mSelectCupCourseTaMTable[3].mOffsetY = offsetY;
        gSelectGhost->mSelectCupCourseTaMTable[5].mOffsetY = offsetY;
        gSelectGhost->mSelectCupCourseTaMTable[n].mOffsetY = offsetY;
        gSelectGhost->mSelectCupCourseTaMTable[n + 1].mOffsetY = offsetY;
        gSelectGhost->mSelectCupCourseTaMTable[n + 2].mOffsetY = offsetY;
        gSelectGhost->mSelectCupCourseTaMTable[n + 3].mOffsetY = offsetY;
        gSelectGhost->mSelectCupCourseTaMTable[n + 4].mOffsetY = offsetY;
        gSelectGhost->mSelectCupCourseTaMTable[n + 5].mOffsetY = offsetY;
    }
    n = gSelectGhost->mSelectGhostSBncl->mCount;
    returnOffsetY = -LookupSelectReturnState4Bg2Offset(gSelectGhost->mStateFrames);
    gSelectGhost->mBg3Offset = offsetY;
    for (i = 0; i < 6; i++) {
        gSelectGhost->mSelectGhostSTable[gSelectGhostSTableIndices[i]].mOffsetY = offsetY;
    }
    gSelectGhost->mSelectGhostSTable[10].mOffsetY = returnOffsetY;
    gSelectGhost->mSelectGhostSTable[11].mOffsetY = returnOffsetY;
    for (i = 0; i < 5; i++) {
        gSelectGhost->mSelectGhostSTable[n + gSelectGhostSBnllIndices[i]].mOffsetY = offsetY;
    }
    for (i = 0; i < 2; i++) {
        gSelectGhost->mSelectGhostSTable[gSelectGhostTimerZeroSTableIndices[i]].mOffsetY = offsetY;
        gSelectGhost->mSelectGhostSTable[gSelectGhostRunningSTableIndices[i]].mOffsetY = offsetY;
    }
    gSelectGhost->mSelectGhostSTable[n + 5].mOffsetY = returnOffsetY;
}

int AdvanceSelectGhost(void) {
    gSelectGhost->mState = gSelectGhost->mNextState;
    switch (gSelectGhost->mState) {
        case 0:
            AdvanceSelectGhostState0();
            break;
        case 1:
            AdvanceSelectGhostState1();
            break;
        case 2:
            AdvanceSelectGhostState2();
            break;
        case 3:
            AdvanceSelectGhostState3();
            break;
        case 4:
            AdvanceSelectGhostState4();
            break;
        case 5:
            AdvanceSelectGhostState5();
            break;
        case 6:
            AdvanceSelectGhostState6();
            break;
        case 7:
            AdvanceSelectGhostState7();
            break;
    }
    AdvancePaletteBlend();
    UpdateSelectGhostCellVisibility();
    DrawLayoutTable(gSelectGhost->mSelectCupCourseTaMBncl, gSelectGhost->mSelectCupCourseMNcer,
                    gSelectGhost->mSelectCupCourseTaMBnll, (void *) gSelectGhost->mMainOamList,
                    gSelectGhost->mSelectCupCourseTaMTable);
    DrawLayoutTable(gSelectGhost->mSelectGhostSBncl, gSelectGhost->mSelectGhostSONcer, gSelectGhost->mSelectGhostSBnll,
                    (void *) gSelectGhost->mSubOamList, gSelectGhost->mSelectGhostSTable);
    if (gSelectGhost->mState == 7) {
        switch (gSelectGhost->mResult) {
            case 1:
                if (gSelectGhost->mStateFrames >= 10) {
                    if (IsSelectReturnState0NoState1Request() != 0) {
                        return 1;
                    }
                }
                break;
            case 2:
                if (gSelectGhost->mStateFrames >= 10) {
                    return 2;
                }
                break;
        }
    }
    return 0;
}

void WriteSelectGhostRegisters(void) {
    reg_G2_BG0OFS = (-gSelectGhost->mBg0Offset << 16) & 0x1ff0000;
    reg_G2S_DB_BG3OFS = (-gSelectGhost->mBg3Offset << 16) & 0x1ff0000;
}
