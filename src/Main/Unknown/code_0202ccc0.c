#include "Main/Unknown/code_0202ccc0.h"
#include "Main/Unknown/code_0202578c.h"
#include "Main/Unknown/code_02025ebc.h"
#include "Main/Unknown/code_0202e4b0.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/code_02036000.h"
#include "code_0212d214.h"
#include "code_0212df7c.h"
#include "code_0214cfe4.h"
#include "code_0214d018.h"
#include "00/code_02181f98.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02025b84.h"
#include "Main/Unknown/code_02025bb4.h"
#include "Main/Unknown/code_0202d990.h"
#include "Main/Unknown/code_0202dd9c.h"
#include "Main/Unknown/code_0202e468.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0204f5e4.h"
#include "Main/Unknown/code_0204f7f4.h"
#include "Main/Unknown/code_02053e74.h"
#include "Main/Unknown/code_02054f58.h"
#include "Main/Unknown/code_02108c04.h"
#include "Main/Unknown/code_02108c1c.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02125f54.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_02126230.h"
#include "Main/Unknown/code_021262f0.h"
#include "Main/Unknown/code_0212775c.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_02128274.h"
#include "code_02148950.h"
#include "Main/Unknown/code_020b3f7c.h"
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
#include "Main/Unknown/code_0202db04.h"
#include "Main/Unknown/unk_02153bec.h"
#include "Main/Unknown/unk_02162c74.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/code_0204ee64.h"
#include "Main/Unknown/code_0203be88.h"
#include "Main/Unknown/code_02126000.h"
#include "Main/Unknown/code_02025cd0.h"
#include "Main/Unknown/code_02025d5c.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_02025edc.h"
#include "Main/Unknown/code_02025f80.h"
#include "Main/Unknown/code_0204ea94.h"
#include "Main/Unknown/code_0204f240.h"
#include "registers.h"

#pragma thumb on

void RefreshGhostListRows(s32 action, s32 slot, s32 row, s32 selectedSlot) {
    MinuteSecondMillisecondTime recordTime;
    s16 text[10];
    CellFileSet *fileSet;
    s32 i;
    s32 j;
    s32 k;
    fileSet = &gTimeAttackGhostSend->mInfoFileSets.mCellFileSets[1];
    if (action == 1) {
        PrintLabelLayoutTextNoFixedAdvance(
            1, slot, fileSet->mLabelLayout,
            GetBmgEntry(gTimeAttackGhostSend->mGhostMessages, GetGhostCourseMessageIndex(GetListedGhostCourseId(row))),
            fileSet->mCellLayout, fileSet->mCellTable);
        GetListedGhostTime(row, &recordTime);
        WriteMinuteSecondMillisecondText(text, recordTime.mMinute, recordTime.mSecond, recordTime.mMillisecond);
        PrintLabelLayoutTextFixedDigits(1, slot + 7, fileSet->mLabelLayout, text, fileSet->mCellLayout,
                                        fileSet->mCellTable, 7);
        j = IsSlotGhostIndex(row) == 0;
        fileSet->mCellTable[slot].mVisible = j;
        k = j == 0;
        fileSet->mCellTable[slot + 7].mVisible = k;
    } else if (action == 0) {
        for (i = 0; i < 7; i++) {
            j = i + 7;
            if (i == selectedSlot) {
                k = 0xe;
            } else {
                k = 0xf;
            }
            SetLabelPaletteIndex(i, k, fileSet->mLabelLayout, fileSet->mCellTable, fileSet->mCellLayout);
            SetLabelPaletteIndex(j, k, fileSet->mLabelLayout, fileSet->mCellTable, fileSet->mCellLayout);
        }
    } else if (action == 2) {
        if (row >= 0 && row < (s32) GetGhostCount()) {
            j = IsSlotGhostIndex(row) == 0;
            fileSet->mCellTable[slot].mVisible = j;
            k = j == 0;
            fileSet->mCellTable[slot + 7].mVisible = k;
        }
    }
}

#pragma thumb off

#pragma thumb on

void SetupGhostSendState8Text(void) {
    void *text;
    void *buttonText;
    text = GetBmgEntry(gTimeAttackGhostSend->mGhostMessages, 0xd);
    buttonText = GetBmgEntry(gTimeAttackGhostSend->mInfoFileSets.mCommonMessages, 4);
    gTimeAttackGhostSend->mState = 8;
    SetupTxtSystemSubTextButton(text, buttonText);
}

#pragma thumb off

#pragma thumb on

void PrintGhostSendCounts(void) {
    u16 text[6];
    CellFileSet *fileSet;
    s32 count;
    fileSet = &gTimeAttackGhostSend->mInfoFileSets.mCellFileSets[1];
    PrintLabelLayoutTextNoFixedAdvance(1, 0xe, fileSet->mLabelLayout,
                                       GetBmgEntry(gTimeAttackGhostSend->mGhostMessages, 0x56), fileSet->mCellLayout,
                                       fileSet->mCellTable);
    PrintLabelLayoutTextNoFixedAdvance(1, 0xf, fileSet->mLabelLayout,
                                       GetBmgEntry(gTimeAttackGhostSend->mGhostMessages, 0x57), fileSet->mCellLayout,
                                       fileSet->mCellTable);
    count = GetCourseGhostCount();
    if (count < 10) {
        text[0] = ' ';
    } else {
        text[0] = count / 10 % 10 + '0';
    }
    text[1] = count % 10 + '0';
    text[2] = '/';
    text[3] = '3';
    text[4] = '2';
    text[5] = 0;
    PrintLabelLayoutTextFixedDigits(1, 0x10, fileSet->mLabelLayout, text, fileSet->mCellLayout, fileSet->mCellTable, 6);
    count = GetSlotGhostCount();
    if (count < 10) {
        text[0] = ' ';
    } else {
        text[0] = count / 10 % 10 + '0';
    }
    text[1] = count % 10 + '0';
    text[2] = '/';
    text[3] = '1';
    text[4] = '0';
    text[5] = 0;
    PrintLabelLayoutTextFixedDigits(1, 0x11, fileSet->mLabelLayout, text, fileSet->mCellLayout, fileSet->mCellTable, 6);
}

void PrintSelectedGhostSendRecord(void) {
    MinuteSecondMillisecondTime recordTime;
    u16 name[10];
    u16 terminatedName[11];
    s32 characterIndex;
    s32 kartIndex;
    GetListedGhostTime(gTimeAttackGhostSend->mInfoFileSets.mSelectedIndex, &recordTime);
    GetListedGhostName(gTimeAttackGhostSend->mInfoFileSets.mSelectedIndex, name);
    MIi_CpuCopy16(name, terminatedName, 0x14);
    terminatedName[10] = 0;
    characterIndex = GetListedGhostCharacterIndex(gTimeAttackGhostSend->mInfoFileSets.mSelectedIndex);
    kartIndex = GetListedGhostKartIndex(gTimeAttackGhostSend->mInfoFileSets.mSelectedIndex);
    PrintGhostRecordInfo(&gTimeAttackGhostSend->mInfoFileSets, gTimeAttackGhostSendMLabelTextRows, terminatedName,
                         characterIndex, kartIndex,
                         GetListedGhostCourseId(gTimeAttackGhostSend->mInfoFileSets.mSelectedIndex), &recordTime);
}

#pragma thumb off

#pragma thumb on

void SetupGhostSendMainText(void) {
    void *text;
    text = GetBmgEntry(gTimeAttackGhostSend->mGhostMessages, 0);
    SetupTxtSystemMainTextShort(text, 0, 0, 0, 0, 0, 0);
}

#pragma thumb off

#pragma thumb on

void SetupGhostSendSubTextWithName(s32 messageIndex, s32 withButton) {
    u16 name[11];
    u16 text[0x100];
    void *message;
    message = GetBmgEntry(gTimeAttackGhostSend->mGhostMessages, messageIndex);
    MIi_CpuCopy16(gTimeAttackGhostSend->mChildName, name, 0x14);
    name[10] = 0;
    FormatMessageWithText(name, message, text, 0x100);
    if (withButton != 0) {
        SetupTxtSystemSubTextButton(text, GetBmgEntry(gTimeAttackGhostSend->mInfoFileSets.mCommonMessages, 4));
    } else {
        SetupTxtSystemSubText(text);
    }
}

void StartReadSelectedGhost(void) {
    StartReadListedGhost(gTimeAttackGhostSend->mInfoFileSets.mSelectedIndex);
    SetupTxtSystemSubText(GetBmgEntry(gTimeAttackGhostSend->mGhostMessages, 9));
    SetSelectReturnSoundId(0xe);
    RequestSelectReturnState4();
}

void SetGhostSendCellsOffsetY(void) {
    CellFileSet *mainFileSet;
    CellFileSet *subFileSet;
    s32 mainEntryCount;
    s32 subEntryCount;
    s32 i;
    s16 subOffsetY;
    mainFileSet = &gTimeAttackGhostSend->mInfoFileSets.mCellFileSets[0];
    subFileSet = &gTimeAttackGhostSend->mInfoFileSets.mCellFileSets[1];
    mainEntryCount = mainFileSet->mCellLayout->mCount + mainFileSet->mLabelLayout->mCount;
    subEntryCount = subFileSet->mCellLayout->mCount + subFileSet->mLabelLayout->mCount;
    subOffsetY = GetInterpolatedValue(&gTimeAttackGhostSend->mInterpolation);
    for (i = 0; i < mainEntryCount; i++) {
        mainFileSet->mCellTable[i].mOffsetY = -subOffsetY;
    }
    for (i = 0; i < subEntryCount; i++) {
        subFileSet->mCellTable[i].mOffsetY = subOffsetY;
    }
}

void InitTimeAttackGhostSend(void *parentHeap, void *mainOam, void *subOam) {
    s16 groupFirstEntries[4];
    s32 cellIndex;
    s32 labelIndex;
    LayoutTableEntry *cellTable;
    CellFileSet *mainFileSet;
    CellFileSet *subFileSet;
    void *heap;
    s32 entryIndex;
    s32 objSizeLeft;
    s32 subCellCount;
    s32 assignedCount;
    heap = CreateFrmHeapFromMaxFree(parentHeap);
    gTimeAttackGhostSend = HeapAlloc(heap, 0xe0);
    MemFillWordsByBlock_inline(gTimeAttackGhostSend, 0xe0);
    gTimeAttackGhostSend->mHeap = heap;
    gTimeAttackGhostSend->mOamLists[0] = mainOam;
    gTimeAttackGhostSend->mOamLists[1] = subOam;
    gTimeAttackGhostSend->mInfoFileSets.mCommonMessages = FindFileInLoadedArchives(data_usa_02162d04);
    gTimeAttackGhostSend->mGhostMessages = FindSceneFile(gGhostBmgName);
    InitBlockEntries(gTimeAttackGhostSend->mHeap, 2);
    LocateAndQueueScreenMapFileSet(0, gTimeAttackGhostSend, gTimeAttackGhostSendMBNcgrName,
                                   gTimeAttackGhostSendMBNclrName, gTimeAttackGhostSendMNscrName, 0, FindSceneFile);
    mainFileSet = &gTimeAttackGhostSend->mInfoFileSets.mCellFileSets[0];
    objSizeLeft = GX_GetSizeOfOBJ();
    LocateCellFileSet(mainFileSet, gTimeAttackGhostSendMNcgrName, gTimeAttackGhostSendMNcerName,
                      gTimeAttackGhostSendMONclrName, gTimeAttackGhostSendMBnclName, gTimeAttackGhostSendMBnllName,
                      NULL, FindSceneFile);
    SetupCellFileSet(0, gTimeAttackGhostSend->mHeap, mainFileSet);
    for (entryIndex = 0; entryIndex < mainFileSet->mLabelLayout->mCount; entryIndex++) {
        objSizeLeft -= SetupLabelCanvas(0, gTimeAttackGhostSend->mHeap, mainFileSet,
                                        gTimeAttackGhostSendMLabelTextRows[entryIndex], objSizeLeft);
    }
    LocateAndQueueScreenMapFileSet(1, &gTimeAttackGhostSend->mScreenMapFileSets[1], gTimeAttackGhostSendSBNcgrName,
                                   gTimeAttackGhostSendSBNclrName, gTimeAttackGhostSendSNscrName, 3, FindSceneFile);
    subFileSet = &gTimeAttackGhostSend->mInfoFileSets.mCellFileSets[1];
    objSizeLeft = GX_GetSizeOfSubOBJ();
    assignedCount = 0;
    LocateCellFileSet(subFileSet, gTimeAttackGhostSendSNcgrName, gTimeAttackGhostSendSNcerName,
                      gTimeAttackGhostSendSONclrName, gTimeAttackGhostSendSBnclName, gTimeAttackGhostSendSBnllName,
                      gTimeAttackGhostSendSBnblName, FindSceneFile);
    SetupCellFileSet(1, gTimeAttackGhostSend->mHeap, subFileSet);
    subCellCount = subFileSet->mCellLayout->mCount;
    for (entryIndex = 0; entryIndex < subFileSet->mLabelLayout->mCount; entryIndex++) {
        if (gTimeAttackGhostSendSLabelTextRows[entryIndex][3] < 0) {
            gTimeAttackGhostSendSLabelTextRows[entryIndex][3] = subCellCount + assignedCount++;
        }
        objSizeLeft -= SetupLabelCanvas(1, gTimeAttackGhostSend->mHeap, subFileSet,
                                        (s16(*)[4]) gTimeAttackGhostSendSLabelTextRows + entryIndex, objSizeLeft);
    }
    PrintGhostSendCounts();
    for (entryIndex = 0; entryIndex < 0xf; entryIndex++) {
        SetCellPriority(entryIndex, 3, subFileSet->mCells, subFileSet->mCellLayout);
    }
    for (entryIndex = 0; entryIndex < 0xe; entryIndex++) {
        SetLabelPriority(entryIndex, 2, subFileSet->mLabelLayout, subFileSet->mCellTable, subFileSet->mCellLayout);
    }
    for (entryIndex = 0; entryIndex < 0xe; entryIndex++) {
        cellIndex = gTimeAttackGhostSendSLabelTextRows[entryIndex][3];
        labelIndex = gTimeAttackGhostSendSLabelTextRows[entryIndex][0];
        cellTable = subFileSet->mCellTable;
        SetLayoutEntryPositionFromCell(cellIndex, &cellTable[cellIndex], subFileSet->mCellLayout);
        SetLayoutEntryPositionFromLabel(labelIndex, cellTable + subCellCount + labelIndex, subFileSet->mLabelLayout);
    }
    SetLayoutEntryPositionFromCell(0xe, &subFileSet->mCellTable[0xe], subFileSet->mCellLayout);
    if (GetGhostCount() != 0) {
        ScreenMapFileSet *screenMapFileSet = &gTimeAttackGhostSend->mScreenMapFileSets[1];
        groupFirstEntries[0] = 0;
        groupFirstEntries[1] = 7;
        groupFirstEntries[2] = subCellCount;
        groupFirstEntries[3] = subCellCount + 7;
        InitScrollList(gTimeAttackGhostSend->mHeap, 4, groupFirstEntries, 0xe, 0xf, 0x7c, subFileSet->mCellTable,
                       subFileSet->mRects, screenMapFileSet->mScreenMaps[3]->mData, 0, 1, 2, GetGhostCount(),
                       RefreshGhostListRows);
    } else {
        for (entryIndex = 0; entryIndex < subCellCount; entryIndex++) {
            subFileSet->mCellTable[entryIndex].mVisible = 0;
        }
        for (entryIndex = 0; entryIndex < 0xe; entryIndex++) {
            subFileSet->mCellTable[subCellCount + entryIndex].mVisible = 0;
        }
    }
    SetPlayerCharacterCellFileSet(0, &gTimeAttackGhostSend->mInfoFileSets.mCellFileSets[2]);
    SetupInterpolation(&gTimeAttackGhostSend->mInterpolation, 3, 10, -0xc0, 0);
    SetSelectReturnSoundId(0xf);
    SendLedPatternWireless();
    gTimeAttackGhostSend->mState = 1;
    FrmHeapShrinkInParent(gTimeAttackGhostSend->mHeap);
}

s32 AdvanceTimeAttackGhostSend(Unk0202cdf4 *advanceArg) {
    u16 slotIndex;
    s32 b;
    s32 a;
    s32 returnTouched;
    s32 hasPair;
    u16 keyB;
    BackupAccess *d;
    CellFileSet *fileSets;
    s32 i;
    slotIndex = GetPadInputSlot();
    returnTouched = 0;
    AdvanceInterpolation(&gTimeAttackGhostSend->mInterpolation);
    b = returnTouched;
    a = b;
    hasPair = gInputSlots[slotIndex].mPair.mHasPair;
    if (hasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < 5) {
        a = 1;
    }
    if (a == 0 && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 && hasPair != 0) {
        b = 1;
    }
    if (b != 0) {
        returnTouched = IsSelectReturnState2NoState3Or4RequestAndInRect(gInputSlots[slotIndex].mPair.mPairX,
                                                                        gInputSlots[slotIndex].mPair.mPairY);
    }
    switch (gTimeAttackGhostSend->mState) {
        case 0:
            if (GetTxtSystemDone() != 0) {
                gMenuShared->mMenuEntryKind = 5;
                if (advanceArg != NULL) {
                    advanceArg->mUnk_04 = 1;
                }
                gTimeAttackGhostSend->mState = 0xe;
            }
            break;
        case 1:
            if (AreBrightnessFadesClear() == 0) {
                if (GetGhostCount() == 0) {
                    SetupTxtSystemSubTextButton(GetBmgEntry(gTimeAttackGhostSend->mGhostMessages, 0x53),
                                                GetBmgEntry(gTimeAttackGhostSend->mInfoFileSets.mCommonMessages, 4));
                    gTimeAttackGhostSend->mState = 0;
                } else {
                    PrintSelectedGhostSendRecord();
                    SetupGhostSendMainText();
                    RequestSelectReturnState1();
                    SetInterpolationStateIfOpposite(&gTimeAttackGhostSend->mInterpolation, 0);
                    gTimeAttackGhostSend->mState = 2;
                }
            }
            break;
        case 2:
            if (gTimeAttackGhostSend->mInterpolation.mState == 1) {
                gTimeAttackGhostSend->mUnk_0b4 = 0;
                gTimeAttackGhostSend->mState = 3;
            } else {
                SetGhostSendCellsOffsetY();
            }
            break;
        case 3:
            if (IsTxtSystemState2NoCloseRequest() != 0) {
                AdvanceScrollList();
                i = GetScrollListSelectedRow();
                if (gTimeAttackGhostSend->mInfoFileSets.mSelectedIndex != i) {
                    gTimeAttackGhostSend->mInfoFileSets.mSelectedIndex = i;
                    PrintSelectedGhostSendRecord();
                }
                if (IsScrollListPickStarted() != 0) {
                    NNS_SndArcSetCurrent(&gOnMemorySndArc);
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 7);
                    NNS_SndArcSetCurrent(&gFileSndArc);
                }
                if (IsScrollListPickFinished() != 0) {
                    StartReadSelectedGhost();
                    StartTimeAttackGhostSendSeq();
                    gTimeAttackGhostSend->mState = 4;
                } else {
                    keyB = gInputSlots[slotIndex].mPressedBits & PAD_KEY_B;
                    if (keyB != 0 || returnTouched != 0) {
                        gMenuShared->mMenuEntryKind = 5;
                        if (advanceArg != NULL) {
                            advanceArg->mUnk_04 = 1;
                        }
                        gTimeAttackGhostSend->mState = 0xe;
                        RequestSelectReturnState3WithSound(0);
                    }
                }
            }
            break;
        case 4:
            d = gBackupAccess;
            if (d->mBackupEnabled != 0) {
                i = d->mCommandRunning;
            } else {
                i = 0;
            }
            if (i == 0 && d->mErrorCode == 0) {
                if (IsSlotGhostIndex(gTimeAttackGhostSend->mInfoFileSets.mSelectedIndex) == 0) {
                    CopyCourseGhostToSlotGhost(GetCourseGhostBuffer(), GetSlotGhostBuffer());
                }
                gTimeAttackGhostSend->mState = 5;
            }
            break;
        case 5:
            i = AdvanceConnectionSetup(1, GetSlotGhostBuffer());
            switch (i) {
                case 1:
                    ResetPendingFiles();
                    AddGhostDataBlockWrapper(GetSlotGhostBuffer(), 0x1000);
                    RequestSelectReturnState1();
                    gTimeAttackGhostSend->mState = 6;
                    break;
                case 2:
                    break;
            }
            break;
        case 6:
            keyB = gInputSlots[slotIndex].mPressedBits & PAD_KEY_B;
            if (keyB != 0 || returnTouched != 0) {
                RequestSelectReturnState3WithSound(0);
                SetSelectReturnSoundId(0xf);
                StopTimeAttackGhostSendSeq();
                gTimeAttackGhostSend->mState = 0xb;
            } else if (CopySingleChildName(gTimeAttackGhostSend->mChildName) != 0) {
                RequestSelectReturnState4();
                StopTimeAttackGhostSendSeq();
                NNS_SndArcSetCurrent(&gOnMemorySndArc);
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 9);
                NNS_SndArcSetCurrent(&gFileSndArc);
                SetupGhostSendSubTextWithName(0xb, 0);
                gTimeAttackGhostSend->mState = 7;
            }
            break;
        case 7:
            i = GetZeroWordResult();
            switch (i) {
                case 1:
                    NNS_SndArcSetCurrent(&gOnMemorySndArc);
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0xa);
                    NNS_SndArcSetCurrent(&gFileSndArc);
                    gTimeAttackGhostSend->mState = 0xa;
                    break;
                case 2:
                    SetupGhostSendState8Text();
                    break;
            }
            break;
        case 8:
            if (IsTxtSystemState2AfterState1() != 0) {
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x15);
            }
            if (GetTxtSystemDone() != 0) {
                gTimeAttackGhostSend->mState = 9;
            }
            break;
        case 9:
            if (AdvanceConnectionEndStopOnError() == 1) {
                SendLedPatternWireless();
                gMenuShared->mMenuEntryKind = 5;
                if (advanceArg != NULL) {
                    advanceArg->mUnk_04 = 1;
                }
                gTimeAttackGhostSend->mState = 0xe;
            }
            break;
        case 10:
            if (AdvanceConnectionEndStopOnError() == 1) {
                SendLedPatternWireless();
                SetupGhostSendSubTextWithName(0xc, 1);
                gTimeAttackGhostSend->mState = 0xd;
            }
            break;
        case 11:
            if (AdvanceConnectionEndStopOnError() == 1) {
                SendLedPatternWireless();
                SetupGhostSendMainText();
                gTimeAttackGhostSend->mState = 3;
            }
            break;
        case 13:
            if (GetTxtSystemDone() != 0) {
                gMenuShared->mMenuEntryKind = 5;
                if (advanceArg != NULL) {
                    advanceArg->mUnk_04 = 1;
                }
                gTimeAttackGhostSend->mState = 0xe;
            }
            break;
    }
    UpdateConnectionSendTimer();
    for (i = 0; i < 2; i++) {
        fileSets = gTimeAttackGhostSend->mInfoFileSets.mCellFileSets;
        DrawLayoutTable(fileSets[i].mCellLayout, fileSets[i].mCells, fileSets[i].mLabelLayout,
                        gTimeAttackGhostSend->mOamLists[i], fileSets[i].mCellTable);
    }
    return -1;
}

#pragma thumb off

#pragma thumb on

void ReleaseTimeAttackGhostSend(void) {
    HeapDestroy(gTimeAttackGhostSend->mHeap);
    *(int *) &gTimeAttackGhostSend = 0;
}

#pragma thumb off

#pragma thumb on

void WriteTimeAttackGhostSendRegisters(void) {
    s16 interpolatedValue = GetInterpolatedValue(&gTimeAttackGhostSend->mInterpolation);
    int negatedValue;
    reg_G2_BG0OFS = ((interpolatedValue << 16) & 0x1ff0000);
    negatedValue = -interpolatedValue;
    reg_G2S_DB_BG3OFS = ((negatedValue << 16) & 0x1ff0000);
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & ~3) | 1;
    if (interpolatedValue != 0) {
        reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffff1fff) | 0x2000;
        reg_G2_WININ = (u32) ((reg_G2_WININ & ~0x3f) | 0x1f) | 0x20;
        reg_G2_WINOUT = (u32) ((reg_G2_WINOUT & ~0x3f) | 0xe) | 0x20;
        reg_G2_WIN0H = 0xff;
        reg_G2_WIN0V = ((negatedValue << 8) & 0xff00) | 0xc0;
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffff1fff) | 0x2000;
        reg_G2S_DB_WININ = (u32) ((reg_G2S_DB_WININ & ~0x3f) | 0x1f) | 0x20;
        reg_G2S_DB_WINOUT = (u32) ((reg_G2S_DB_WINOUT & ~0x3f) | 7) | 0x20;
        reg_G2S_DB_WIN0H = 0xff;
        reg_G2S_DB_WIN0V = (interpolatedValue + 0xc0) & 0xff;
    } else {
        reg_GX_DISPCNT = reg_GX_DISPCNT & 0xffff1fff;
        reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & 0xffff1fff;
    }
}

#pragma thumb off
