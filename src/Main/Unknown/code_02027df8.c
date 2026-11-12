#include "Main/Unknown/code_02027df8.h"
#include "Main/Unknown/code_02029008.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02028724.h"
#include "Main/Unknown/code_02028774.h"
#include "Main/Unknown/code_020291c4.h"
#include "Main/Unknown/code_020291f0.h"
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
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/code_02028ff8.h"
#include "Main/Unknown/code_02028f20.h"
#include "Main/Unknown/code_02025d5c.h"
#include "Main/Unknown/code_02027e78.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Unknown/code_0202b604.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02028d9c.h"
#include "Main/Unknown/code_02077bc0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02028000.h"
#include "Main/Unknown/code_02078000.h"
#include "Main/Unknown/code_0201e000.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_0201ea30.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_02028864.h"
#include "Main/Unknown/code_0202578c.h"
#include "Main/Unknown/code_02025df4.h"
#include "Main/Unknown/code_02025e28.h"
#include "Main/Unknown/code_02029440.h"
#include "Main/Unknown/code_0202bb80.h"
#include "Main/Unknown/code_0202c000.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_02056444.h"
#include "Main/Unknown/code_02148000.h"
#include "Main/Unknown/code_0211f394.h"
#include "Main/Unknown/code_0211f4b0.h"
#include "Main/Unknown/code_02116ec0.h"
#include "Main/Unknown/code_0212775c.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/code_0212b928.h"
#include "code_02148950.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/code_02025f80.h"
#include "Main/Unknown/code_0202881c.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/code_02028130.h"
#include "Main/Unknown/code_02025eb0.h"
#include "Main/Unknown/code_0202b000.h"
#include "Main/Unknown/code_020adb04.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_021105a0.h"
#include "Main/Unknown/code_021106a8.h"
#include "Main/Unknown/code_0211f378.h"
#include "Main/Unknown/code_02120610.h"
#include "Main/Unknown/code_02121e84.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_0212b1a8.h"
#include "Main/Unknown/code_02025edc.h"
#include "registers.h"
#include "Main/Unknown/code_021281fc.h"
#include "Main/Unknown/code_0214a000.h"
#include "Main/Unknown/code_0211f498.h"
#include "Main/Unknown/code_02128000.h"
#include "Main/Unknown/code_0212b000.h"
#include "code_0214a390.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_020b4000.h"

#pragma optimize_for_size on
#pragma thumb on
s32 UpdateSelectKartTouchHold(void) {
    s32 result = -1;
    CellFileSet *cellFileSet = &gSelectKart->mSelectKartSParts;
    u16 slotIndex = GetPadInputSlot();
    s32 pairX;
    s32 pairY;
    s32 rectIndex;
    if (gSelectKart->mTouchHeld != FALSE) {
        if (SelectKartSlotHasPairOrLost(slotIndex) != 0) {
            pairX = SelectKartGetSlotPairX(slotIndex);
            pairY = SelectKartGetSlotPairY(slotIndex);
            rectIndex = FindRectContainingPoint(pairX, pairY, cellFileSet->mRects);
            if (rectIndex != gSelectKart->mTouchRect) {
                gSelectKart->mTouchHeld = FALSE;
                gSelectKart->mTouchHeldFrames = 0;
            } else {
                gSelectKart->mTouchHeldFrames++;
                result = rectIndex;
            }
        } else {
            gSelectKart->mTouchHeld = FALSE;
            gSelectKart->mTouchHeldFrames = 0;
        }
    } else if (SelectKartIsSlotPairNew(slotIndex) != 0) {
        result = FindRectContainingPoint(SelectKartGetSlotPairX(slotIndex), SelectKartGetSlotPairY(slotIndex),
                                         cellFileSet->mRects);
        gSelectKart->mTouchHeld = TRUE;
        gSelectKart->mTouchHeldFrames = 0;
    }
    return result;
}

u32 IsSelectKartTouchRepeat(s32 rectIndex) {
    u32 result = 0;
    u32 repeatDue;
    SelectKart *selectKart = gSelectKart;
    s32 heldFrames;
    if (selectKart->mTouchRect == rectIndex) {
        heldFrames = selectKart->mTouchHeldFrames;
        result |= (heldFrames == 0);
        repeatDue = 0;
        if (heldFrames >= 0x3c) {
            if ((heldFrames - 0x3c) % 0xf == 0) {
                repeatDue = 1;
            }
        }
        result |= repeatDue;
    }
    return result;
}

void SetSelectKartGpMPartsOffsets(void) {
    SelectKart *selectKart = gSelectKart;
    CellFileSet *gpMParts;
    if (selectKart->mEntryListUsed == FALSE) {
        gpMParts = &selectKart->mSelectCharacterGpMParts;
        gpMParts->mCellTable[1].mOffsetX = GetInterpolatedValue(&selectKart->mInterpolations[0]);
        gpMParts->mCellTable[2].mOffsetX = gpMParts->mCellTable[1].mOffsetX;
        gpMParts->mCellTable[0].mOffsetY = GetInterpolatedValue(&gSelectKart->mInterpolations[1]);
        gpMParts->mCellTable[3].mOffsetY = GetInterpolatedValue(&gSelectKart->mInterpolations[2]);
        gpMParts->mCellTable[9].mOffsetY = GetInterpolatedValue(&gSelectKart->mInterpolations[3]);
        gpMParts->mCellTable[8].mOffsetY = gpMParts->mCellTable[9].mOffsetY;
        gpMParts->mCellTable[7].mOffsetY = gpMParts->mCellTable[8].mOffsetY;
        gpMParts->mCellTable[6].mOffsetY = gpMParts->mCellTable[7].mOffsetY;
        gpMParts->mCellTable[5].mOffsetY = gpMParts->mCellTable[6].mOffsetY;
        gpMParts->mCellTable[4].mOffsetY = gpMParts->mCellTable[5].mOffsetY;
    }
}
#pragma thumb off

u32 GetCellLayoutCount(void *cellLayout) {
    return *OFFSET_PTR(const u16, cellLayout, 6);
}

u32 GetLabelLayoutCount(void *labelLayout) {
    return *OFFSET_PTR(const u16, labelLayout, 6);
}

#pragma optimize_for_size on
#pragma thumb on
void SetSelectKartSPartsOffsetY(void) {
    CellFileSet *parts;
    s32 cellIndex;
    s32 count;
    if (SelectKartMB_IsMultiBootChildWrapper() == 0) {
        parts = &gSelectKart->mSelectKartSParts;
        count = GetCellLayoutCount(parts->mCellLayout) + GetLabelLayoutCount(parts->mLabelLayout);
        for (cellIndex = 0; cellIndex < count; cellIndex++) {
            parts->mCellTable[cellIndex].mOffsetY = GetInterpolatedValue(&gSelectKart->mInterpolations[4]);
        }
    }
}

u32 IsSelectKartModeAndTimerZero(void) {
    u32 result = 0;
    if (gSelectKart->mMode != 0 && IsPlayerEntryListTimerZero() != 0) {
        result = 1;
    }
    return result;
}

void PrintSelectKartMessage(void) {
    s32 labelIndex;
    CellFileSet *parts;
    void *message;
    if (SelectKartMB_IsMultiBootChildWrapper() == 0) {
        message = GetBmgEntry(gSelectKart->mKartSelectMessages, GetKartMessageIndex(gSelectKart->mKartIndex));
        parts = &gSelectKart->mSelectKartSParts;
        for (labelIndex = 8; labelIndex >= 7; labelIndex--) {
            PrintLabelLayoutTextNoFixedAdvance(1, data_usa_021537f4[labelIndex].mLabelIndex, parts->mLabelLayout,
                                               message, parts->mCellLayout, parts->mCellTable);
        }
    }
}
#pragma thumb off

void *GetCellLayoutEntrySwapped(s32 index, LayoutEntryTable *cellLayout) {
    return GetCellLayoutEntry(cellLayout, index);
}

#pragma thumb on

void SetKartMenuParamElementOffset(s32 elementIndex, s32 endCellIndex, s32 paramValue, CellFileSet *parts) {
    LayoutAxis *startCell = GetCellLayoutEntrySwapped(elementIndex, parts->mCellLayout);
    LayoutAxis *endCell = GetCellLayoutEntrySwapped(endCellIndex, parts->mCellLayout);
    parts->mCellTable[elementIndex].mOffsetX = (100 - paramValue) * (endCell->mUnk_00_0 - startCell->mUnk_00_0) / 100;
}

#pragma thumb off

#pragma thumb on

void RefreshKartMenuParamElements(void) {
    int result;
    CellFileSet *parts;
    short *params;
    result = SelectKartMB_IsMultiBootChildWrapper();
    if (result == 0) {
        params = ComputeKartMenuParams(gSelectKart->mKartIndex, gSelectKart->mCharacterIndex);
        parts = &gSelectKart->mSelectKartSParts;
        SetKartMenuParamElementOffset(10, 0x10, *params, parts);
        SetKartMenuParamElementOffset(9, 0xf, params[1], parts);
        SetKartMenuParamElementOffset(8, 0xe, params[2], parts);
        SetKartMenuParamElementOffset(7, 0xd, params[3], parts);
        SetKartMenuParamElementOffset(6, 0xc, params[4], parts);
        SetKartMenuParamElementOffset(5, 0xb, params[5], parts);
    }
}

#pragma thumb off

void SelectKartMI_CpuFillFast(void *destination, u32 value, u32 size) {
    volatile u32 valueCopy = value;
    MIi_CpuClearFast(valueCopy, destination, size);
}

void SelectKartMI_CpuClearFast(void *destination, u32 size) {
    SelectKartMI_CpuFillFast(destination, 0, size);
}

u16 GetOwnIndexOrZero(void) {
    int index;
    if (gConnectionWork->mConnectionMode == 2) {
        index = gConnectionWork->mOwnIndex;
    } else {
        index = 0;
    }
    return index;
}

u32 GetParticipantEntryIndex(u32 participantIndex) {
    return (gConnectionWork->mParticipantPosByIndex[participantIndex].mEntryIndex);
}

u32 GetOwnEntryIndex(void) {
    u32 value0;
    value0 = GetOwnIndexOrZero();
    value0 = GetParticipantEntryIndex(value0);
    return value0;
}

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
            text = GetBmgEntry(gSelectKart->mKartSelectMessages, data_usa_021537f4[index].mMessageIndex);
            value = data_usa_021537f4[index].mLabelIndex;
            PrintLabelLayoutTextNoFixedAdvance(1, value, cellFileSet->mLabelLayout, text, cellFileSet->mCellLayout,
                                               cellFileSet->mCellTable);
            SetLabelPriority(value, 1, cellFileSet->mLabelLayout, cellFileSet->mCellTable, cellFileSet->mCellLayout);
        }
        text = GetBmgEntry(FindFileInLoadedArchives(gCommonBmgName2), data_usa_021537f4[6].mMessageIndex);
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

u32 GetConnectionState(void) {
    return (gConnectionWork->mState);
}

void SetDataSharingSendByteInState8(u8 sendByte) {
    if (GetConnectionState() == 8) {
        gConnectionWork->mDataSharingSendByte = sendByte;
    }
}

u32 SelectKartGetPairHasPair(InputSlotPair *inputSlotPair) {
    return inputSlotPair->mHasPair;
}

#pragma optimize_for_size on

BOOL SelectKartIsPairRecentlyLost(InputSlotPair *pair) {
    if (SelectKartGetPairHasPair(pair) == 0) {
        if (pair->mNoPairCount < 5) {
            return 1;
        }
    }
    return 0;
}

BOOL SelectKartIsPairNew(InputSlotPair *pair) {
    if (pair->mPrevHasPair == 0 && pair->mHasPair != 0) {
        return 1;
    }
    return 0;
}

BOOL SelectKartIsPairNewUnlessLost(InputSlotPair *pair) {
    if (SelectKartIsPairRecentlyLost(pair) == 0) {
        if (SelectKartIsPairNew(pair) != 0) {
            return 1;
        }
    }
    return 0;
}

BOOL SelectKartIsSlotPairNew(u32 slot) {
    return SelectKartIsPairNewUnlessLost(&gInputSlots[slot].mPair);
}

u32 SelectKartGetPairX(InputSlotPair *inputSlotPair) {
    return inputSlotPair->mPairX;
}

u32 SelectKartGetSlotPairX(u32 slot) {
    return SelectKartGetPairX(&gInputSlots[slot].mPair);
}

u32 SelectKartGetPairY(InputSlotPair *inputSlotPair) {
    return inputSlotPair->mPairY;
}

u32 SelectKartGetSlotPairY(u32 slot) {
    return SelectKartGetPairY(&gInputSlots[slot].mPair);
}

#pragma optimize_for_size on

u16 SelectKartGetInputSlotNewBits(InputSlot *inputSlot, u32 mask) {
    return inputSlot->mPressedBits & mask;
}

u16 SelectKartGetNewBits(u32 slotIndex, u32 mask) {
    return SelectKartGetInputSlotNewBits(&gInputSlots[slotIndex], mask);
}

#pragma thumb on

int AdvanceSelectKart(void) {
    SelectKart *selectKart;
    CellFileSet *selectKartParts;
    s32 oldKartIndex;
    s32 result;
    s32 padInputSlot;
    s32 isReturnTouched;
    CellFileSet *characterParts;
    u32 value;
    selectKart = gSelectKart;
    oldKartIndex = selectKart->mKartIndex;
    isReturnTouched = 0;
    result = 0;
    characterParts = &selectKart->mSelectCharacterGpMParts;
    selectKartParts = &selectKart->mSelectKartSParts;
    padInputSlot = GetPadInputSlot();
    AdvanceInterpolation(&gSelectKart->mInterpolations[0]);
    AdvanceInterpolation(&gSelectKart->mInterpolations[1]);
    AdvanceInterpolation(&gSelectKart->mInterpolations[2]);
    AdvanceInterpolation(&gSelectKart->mInterpolations[3]);
    AdvanceInterpolation(&gSelectKart->mInterpolations[4]);
    SetSelectKartGpMPartsOffsets();
    if (SelectKartMB_IsMultiBootChildWrapper() == 0) {
        AdvancePaletteBlend();
    }
    if (SelectKartMB_IsMultiBootChildWrapper() == 0) {
        gSelectKart->mTouchRect = UpdateSelectKartTouchHold();
    } else {
        gSelectKart->mTouchRect = -1;
    }
    selectKart = gSelectKart;
    switch (selectKart->mState) {
        case 0:
            if (selectKart->mInterpolations[4].mState == 1) {
                selectKart->mStateFrames = 0;
                if (SelectKartMB_IsMultiBootChildWrapper() != 0) {
                    value = 1;
                } else {
                    value = 2;
                }
                gSelectKart->mState = value;
            }
            SetSelectKartSPartsOffsetY();
            break;
        case 1:
            SetDataSharingSendByteInState8(selectKart->mKartIndex | 0x80);
            gSelectKart->mResult = 1;
            gSelectKart->mState = 5;
            break;
        case 2:
            if (SelectKartIsSlotPairNew(padInputSlot) != 0) {
                isReturnTouched = IsSelectReturnState2NoState3Or4RequestAndInRect(SelectKartGetSlotPairX(padInputSlot),
                                                                                  SelectKartGetSlotPairY(padInputSlot));
            }
            if (SelectKartGetNewBits(padInputSlot, PAD_KEY_A) != 0 || gSelectKart->mTouchRect == 2 ||
                IsSelectKartModeAndTimerZero() != 0) {
                gSelectKart->mStateFrames = 0;
                gSelectKart->mResult = 1;
                gSelectKart->mState = 4;
                selectKartParts->mCellTable[18].mVisible = 0;
                SetLabelPaletteIndex(data_usa_02153834[4], 0, selectKartParts->mLabelLayout,
                                     selectKartParts->mCellTable, selectKartParts->mCellLayout);
                StartSeqPair(GetCharacterSeqPairNo(gSelectKart->mCharacterIndex), 1);
                SetKartModelMenuSpinStopped(1);
                StopPaletteBlend();
            } else if (SelectKartGetNewBits(padInputSlot, PAD_KEY_B) != 0 || isReturnTouched != 0) {
                gSelectKart->mStateFrames = 0;
                gSelectKart->mResult = 2;
                StartSelectKartEntryListKindIfUsed(0);
                SetInterpolationStateIfOpposite(&gSelectKart->mInterpolations[1], 2);
                SetInterpolationStateIfOpposite(&gSelectKart->mInterpolations[3], 2);
                SetInterpolationStateIfOpposite(&gSelectKart->mInterpolations[4], 2);
                gSelectKart->mState = 7;
                if (gSelectKart->mMode != 0) {
                    value = 1;
                } else {
                    value = 0;
                }
                RequestSelectReturnState3WithSound(value);
            } else if (GetNewOrRepeatBits(padInputSlot, PAD_KEY_RIGHT) != 0 || IsSelectKartTouchRepeat(1) != 0) {
                MoveSelectKartNext();
                gSelectKart->mSlidingCellIndex = 3;
                selectKartParts->mCellTable[1].mVisible = 0;
                selectKartParts->mCellTable[3].mVisible = 1;
            } else if (GetNewOrRepeatBits(padInputSlot, PAD_KEY_LEFT) != 0 || IsSelectKartTouchRepeat(0) != 0) {
                MoveSelectKartPrev();
                gSelectKart->mSlidingCellIndex = 2;
                selectKartParts->mCellTable[0].mVisible = 0;
                selectKartParts->mCellTable[2].mVisible = 1;
            }
            if (oldKartIndex != gSelectKart->mKartIndex) {
                StartCursorMoveSound();
                PrintSelectKartMessage();
                RefreshKartMenuParamElements();
                gSelectKart->mState = 3;
                gSelectKart->mStateFrames = 0;
            }
            break;
        case 3:
            selectKart->mStateFrames = selectKart->mStateFrames + 1;
            if (gSelectKart->mStateFrames > 6) {
                gSelectKart->mStateFrames = 0;
                gSelectKart->mState = 2;
                selectKartParts->mCellTable[gSelectKart->mSlidingCellIndex].mOffsetX = 0;
                selectKartParts->mCellTable[1].mVisible = 1;
                selectKartParts->mCellTable[0].mVisible = 1;
                selectKartParts->mCellTable[3].mVisible = 0;
                selectKartParts->mCellTable[2].mVisible = 0;
            } else {
                value = LookupFrameOffset(gSelectKart->mStateFrames);
                if (gSelectKart->mSlidingCellIndex == 2) {
                    value = -value;
                }
                selectKartParts->mCellTable[gSelectKart->mSlidingCellIndex].mOffsetX = value;
            }
            break;
        case 4:
            selectKart->mStateFrames = selectKart->mStateFrames + 1;
            selectKart = gSelectKart;
            if (selectKart->mStateFrames >= 5) {
                switch (selectKart->mMode) {
                    case 0:
                        GetRaceSetupCopy()->mEntries[gSelectKart->mEntryIndex].mKartIndex = selectKart->mKartIndex;
                        GetRaceSetupCopy()->mEntries[gSelectKart->mEntryIndex].mKartStored = 1;
                        FillRandomKartIndices();
                        gSelectKart->mState = 6;
                        break;
                    case 1:
                        RequestSelectReturnState4();
                        SetDataSharingSendByteInState8(gSelectKart->mKartIndex | 0x80);
                        gSelectKart->mState = 5;
                        break;
                    case 2:
                        RequestSelectReturnState4();
                        SetWiFiSessionOwnKartIndex(gSelectKart->mKartIndex);
                        gSelectKart->mState = 5;
                        break;
                }
                gSelectKart->mStateFrames = 0;
                selectKartParts->mCellTable[18].mVisible = 1;
                SetLabelPaletteIndex(data_usa_02153834[4], 1, selectKartParts->mLabelLayout,
                                     selectKartParts->mCellTable, selectKartParts->mCellLayout);
            }
            break;
        case 5:
            if (selectKart->mMode == 1 && IsEveryPlayerKartStored() != 0 ||
                gSelectKart->mMode == 2 && IsWiFiSessionStep7Reached() != 0) {
                gSelectKart->mStateFrames = 0;
                gSelectKart->mState = 6;
            }
            break;
        case 6:
            selectKart->mStateFrames = selectKart->mStateFrames + 1;
            if (gSelectKart->mStateFrames > 0x3c) {
                SetInterpolationStateIfOpposite(&gSelectKart->mInterpolations[0], 2);
                SetInterpolationStateIfOpposite(&gSelectKart->mInterpolations[1], 2);
                SetInterpolationStateIfOpposite(&gSelectKart->mInterpolations[2], 2);
                SetInterpolationStateIfOpposite(&gSelectKart->mInterpolations[3], 2);
                SetInterpolationStateIfOpposite(&gSelectKart->mInterpolations[4], 2);
                if (gSelectKart->mMode == 2) {
                    WriteWiFiSessionToRaceSetupCopy();
                    StartSelectKartEntryListKindIfUsed(3);
                } else {
                    StartSelectKartEntryListKindIfUsed(2);
                }
                if (SelectKartMB_IsMultiBootChildWrapper() == 0) {
                    StartKartModelMenuBg0Decrease();
                } else {
                    SlideOutSelectRaceRuleWait();
                }
                gSelectKart->mStateFrames = 0;
                gSelectKart->mState = 7;
            }
            break;
        case 7:
            if (selectKart->mInterpolations[4].mState == 3) {
                GetRaceSetupCopy()->mEntries[gSelectKart->mEntryIndex].mKartStored = selectKart->mResult == 1;
                gSelectKart->mState = 8;
            }
            SetSelectKartSPartsOffsetY();
            break;
        case 8:
            result = selectKart->mResult;
            break;
    }
    if (SelectKartMB_IsMultiBootChildWrapper() == 0) {
        RequestKartModelMenuCharacter(gSelectKart->mCharacterIndex);
        RequestKartModelMenuKart(gSelectKart->mKartIndex);
        AdvanceKartModelMenu(GetRaceSetupCopy()->mMirrorMode);
        DrawKartModelMenu();
    }
    selectKart = gSelectKart;
    if (selectKart->mEntryListUsed != FALSE) {
        AdvancePlayerEntryList();
    } else {
        DrawLayoutTable(characterParts->mCellLayout, characterParts->mCells, NULL, selectKart->mMainOam,
                        characterParts->mCellTable);
    }
    if (SelectKartMB_IsMultiBootChildWrapper() == 0) {
        selectKart = gSelectKart;
        if (selectKart->mState != 8) {
            DrawLayoutTable(selectKartParts->mCellLayout, selectKartParts->mCells, selectKartParts->mLabelLayout,
                            selectKart->mSubOam, selectKartParts->mCellTable);
        }
    } else {
        AdvanceSelectRaceRuleWait();
    }
    switch (result) {
        case 1:
            GetRaceSetupCopy()->mEntryTransition = 0;
            break;
        case 2:
            GetRaceSetupCopy()->mEntryTransition = 2;
            break;
    }
    return result;
}
#pragma thumb off

u32 SelectKartGetConnectionKind(void) {
    return (gStartupWork->mConnectionKind);
}

u16 *SelectKartMB_GetMultiBootParam(void) {
    return &gBootInfo->mBootType;
}

u32 SelectKartMB_IsMultiBootChild(void) {
    if (*SelectKartMB_GetMultiBootParam() == 2) {
        return 1;
    }
    return 0;
}

u32 SelectKartMB_IsMultiBootChildWrapper(void) {
    return SelectKartMB_IsMultiBootChild();
}

#pragma thumb on

void ReleaseSelectKart(void) {
    int result;
    if ((gSelectKart->mResult == 1) && (result = SelectKartGetConnectionKind(), result == 2)) {
        ClearSelectReturnDisplayBitOn();
    }
    result = SelectKartMB_IsMultiBootChildWrapper();
    if (result == 0) {
        ClearPaletteBlendPointer();
    } else {
        ClearSelectRaceRuleWaitPointer();
    }
    HeapDestroy(gSelectKart->mHeap);
    *&gSelectKart = NULL;
}

#pragma thumb off

u32 SelectKartGX_SetVisiblePlane(u32 bits) {
    u32 value = (reg_GX_DISPCNT & ~0x1f00) | (bits << 8);
    reg_GX_DISPCNT = value;
    return value;
}

u32 SelectKartGXS_SetVisiblePlane(u32 bits) {
    u32 value = (reg_GXS_DB_DISPCNT & ~0x1f00) | (bits << 8);
    reg_GXS_DB_DISPCNT = value;
    return value;
}

void SelectKartG2S_SetBG3Offset(u32 offsetX, u32 offsetY) {
    reg_G2S_DB_BG3OFS = (offsetX & 0x1ff) | ((offsetY << 16) & 0x1ff0000);
}

void WriteSubBg3CntBits(u32 bits) {
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & ~3) | bits;
}

void WriteSubBlendAlpha(u32 firstPlane, u32 secondPlane, u32 firstCoefficient, u32 secondCoefficient) {
    G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, firstPlane, secondPlane, firstCoefficient, secondCoefficient);
}

u32 WriteSubWinEnableBits(u32 bits) {
    u32 value = (reg_GXS_DB_DISPCNT & ~0xe000) | (bits << 13);
    reg_GXS_DB_DISPCNT = value;
    return value;
}

void SelectKartG2S_SetWnd0InsidePlane(u32 lowBits, u32 extraBitFlag) {
    u32 value = (reg_G2S_DB_WININ & ~0x3f) | lowBits;
    if (extraBitFlag != 0) {
        value |= 0x20;
    }
    reg_G2S_DB_WININ = value;
}

void SelectKartG2S_SetWndOutsidePlane(u32 lowBits, u32 extraBitFlag) {
    u32 value = (reg_G2S_DB_WINOUT & ~0x3f) | lowBits;
    if (extraBitFlag != 0) {
        value |= 0x20;
    }
    reg_G2S_DB_WINOUT = value;
}

void SelectKartG2S_SetWnd0Position(u32 startX, u32 startY, u32 endX, u32 endY) {
    reg_G2S_DB_WIN0H = ((startX << 8) & 0xff00) | (endX & 0xff);
    reg_G2S_DB_WIN0V = ((startY << 8) & 0xff00) | (endY & 0xff);
}

#pragma thumb on

void WriteSelectKartRegisters(void) {
    u32 displayBits = 0x16;
    s32 interpolatedValue = GetInterpolatedValue(&gSelectKart->mInterpolations[4]);
    if (gSelectKart->mState != 8) {
        displayBits |= 8;
    }
    SelectKartGX_SetVisiblePlane(0x19);
    SelectKartGXS_SetVisiblePlane(displayBits);
    SelectKartG2S_SetBG3Offset(0, -interpolatedValue);
    WriteSubBg3CntBits(2);
    WriteSubBlendAlpha(0, 0x3f, 6, 10);
    if (interpolatedValue != 0 && gSelectKart->mState != 8) {
        WriteSubWinEnableBits(1);
        SelectKartG2S_SetWnd0InsidePlane(0x1f, 1);
        SelectKartG2S_SetWndOutsidePlane(7, 1);
        SelectKartG2S_SetWnd0Position(0, 0, 0xff, interpolatedValue + 0xc0);
    } else {
        WriteSubWinEnableBits(0);
    }
    if (gSelectKart->mEntryListUsed != FALSE) {
        WritePlayerEntryListRegisters();
    }
}
#pragma thumb off

#pragma thumb on

void LoadSelectKartData(void) {
    void *fileData;
    Ncgr *chars;
    Nclr *palette;
    Unk02021dc8 *cells;
    Nscr *screenMap[1];
    chars = NULL;
    palette = NULL;
    cells = NULL;
    screenMap[0] = NULL;
    fileData = FindFileInLoadedArchives(data_02161e64);
    LoadNcgrData(&chars, fileData);
    fileData = FindFileInLoadedArchives(data_02161e7c);
    LoadNcgrData2(&chars, fileData);
    fileData = FindFileInLoadedArchives(data_02161e94);
    LoadNcerData(&cells, fileData);
    fileData = FindFileInLoadedArchives(data_02161eac);
    LoadNclrData(&palette, fileData);
    fileData = FindFileInLoadedArchives(data_02161ec4);
    LoadNclrData(&palette, fileData);
    fileData = FindFileInLoadedArchives(data_02161edc);
    LoadNscrData(screenMap, fileData);
}

#pragma thumb off
