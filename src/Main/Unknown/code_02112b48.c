#include "Main/Unknown/code_02112b48.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02076cd0.h"

#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0205edcc.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02077000.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_021113f0.h"
#include "Main/Unknown/code_0211130c.h"
#include "Main/Unknown/code_02111450.h"
#include "Main/Unknown/code_02113790.h"
#include "Main/Unknown/code_0211398c.h"
#include "Main/Unknown/code_021139b4.h"
#include "Main/Unknown/code_02113f34.h"
#include "Main/Unknown/code_02114158.h"
#include "Main/Unknown/code_02116a4c.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/code_0212426c.h"
#include "code_02148950.h"
#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/unk_0216d000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "00/code_02181f98.h"
#include "code_0212df7c.h"
#include "code_0214d018.h"
#include "registers.h"
#include "Main/Unknown/code_021137a8.h"
#include "Main/Unknown/code_02113f1c.h"
#include "Main/Unknown/code_021138e4.h"
#include "Main/Unknown/code_02113ef0.h"
#include "code_02016468.h"
#include "Main/Unknown/code_0205e000.h"
#include "Main/Unknown/code_02060000.h"
#include "Main/Unknown/code_02114504.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_0214cfe4.h"
#include "Main/Unknown/code_021144b4.h"
#include "Main/Unknown/code_021144c0.h"
#include "01/code_021956dc.h"

#pragma thumb on

// Combines the entry's three bytes into one number to order entries by.
u16 GetRecordSortKey(u16 listIndex) {
    DateBytes date;

    GetRecordDate((u8) listIndex, &date);
    return date.mYear * 0x1a0 + date.mMonth * 32 + date.mDay;
}

// Orders b entries from index a by descending key.
void SortRecordRange(s32 first, u16 count) {
    s32 i;
    s32 j;
    s32 end;
    u16 maxIndex;
    s32 lastIndex;
    RecordListEntry swapEntry;
    u32 maxKey;
    u16 key;
    RecordListEntry *previousEntry;

    maxIndex = 0;
    end = first + count;
    lastIndex = end - 1;
    for (i = first; i < lastIndex; i++) {
        maxKey = 0;
        for (j = i; j < end; j++) {
            key = GetRecordSortKey(j);
            if (maxKey < key) {
                maxKey = key;
                maxIndex = j;
            }
        }
        for (j = maxIndex; j > i; j--) {
            previousEntry = gRecordList->mEntries + j - 1;
            swapEntry = *previousEntry;
            *previousEntry = gRecordList->mEntries[j];
            gRecordList->mEntries[j] = swapEntry;
        }
    }
}

#pragma thumb off

#pragma thumb on

void CreateRecordList(void *heap) {
    int listAddress;
    void *v2;
    listAddress = ((u32) HeapAlloc(heap, 0x10));
    *(s32 *) &gRecordList = listAddress;
    v2 = HeapAlloc(heap, 0x78);
    gRecordList->mEntries = v2;
    v2 = CreateEmblemBlock(heap);
    gRecordList->mEmblemBlock = v2;
    v2 = FindSceneFile(gEmblem2BinName);
    gRecordList->mEmblem2Bin = v2;
}

#pragma thumb off

#pragma thumb on
void ClearRecordListPointer(void) {
    gRecordList = NULL;
}
#pragma thumb off

#pragma thumb on

// Fills the table with the used slots, flagged ones first, each group ordered by key.
void BuildRecordList(void) {
    s32 i;
    u16 flaggedCount;
    s32 nextFlaggedIndex;
    s32 nextUnflaggedIndex;

    flaggedCount = 0;
    gRecordList->mRecordCount = 0;
    for (i = 0; i < 0x3c; i++) {
        if (IsBuddyRecordFilled(i)) {
            gRecordList->mRecordCount++;
            if (IsBuddyRecordFlagged(i)) {
                flaggedCount++;
            }
        }
    }
    if (gRecordList->mRecordCount != 0) {
        nextFlaggedIndex = 0;
        nextUnflaggedIndex = flaggedCount;
        for (i = 0; i < 0x3c; i++) {
            if (IsBuddyRecordFilled(i)) {
                if (IsBuddyRecordFlagged(i)) {
                    gRecordList->mEntries[nextFlaggedIndex].mRecordIndex = (u8) i;
                    nextFlaggedIndex++;
                } else {
                    gRecordList->mEntries[nextUnflaggedIndex].mRecordIndex = (u8) i;
                    nextUnflaggedIndex++;
                }
            }
        }
        SortRecordRange(0, flaggedCount);
        SortRecordRange(flaggedCount, gRecordList->mRecordCount - flaggedCount);
    }
}

u16 GetRecordCount(void) {
    s32 i;
    u16 count;

    count = 0;
    if (gRecordList == NULL) {
        for (i = 0; i < 0x3c; i++) {
            if (IsBuddyRecordFilled(i)) {
                count++;
            }
        }
        return count;
    }
    return gRecordList->mRecordCount;
}

s32 IsRecordFlagged(u16 listIndex) {
    return IsBuddyRecordFlagged(gRecordList->mEntries[listIndex].mRecordIndex);
}

s32 GetRecordMatchKind0FirstCount(u16 listIndex) {
    return GetBuddyRecordMatchKind0FirstCount(gRecordList->mEntries[listIndex].mRecordIndex);
}

s32 GetRecordMatchKind1FirstCount(u16 listIndex) {
    return GetBuddyRecordMatchKind1FirstCount(gRecordList->mEntries[listIndex].mRecordIndex);
}

s32 GetRecordMatchKind2FirstCount(u16 listIndex) {
    return GetBuddyRecordMatchKind2FirstCount(gRecordList->mEntries[listIndex].mRecordIndex);
}

s32 GetRecordMatchKind0SecondCount(u16 listIndex) {
    return GetBuddyRecordMatchKind0SecondCount(gRecordList->mEntries[listIndex].mRecordIndex);
}

s32 GetRecordMatchKind1SecondCount(u16 listIndex) {
    return GetBuddyRecordMatchKind1SecondCount(gRecordList->mEntries[listIndex].mRecordIndex);
}

s32 GetRecordMatchKind2SecondCount(u16 listIndex) {
    return GetBuddyRecordMatchKind2SecondCount(gRecordList->mEntries[listIndex].mRecordIndex);
}

s32 GetRecordDate(u16 listIndex, void *dateBytes) {
    return GetBuddyRecordDate(gRecordList->mEntries[listIndex].mRecordIndex, dateBytes);
}

void CopyRecordText(u16 listIndex, void *buffer, u32 bufferSize) {
    u8 name[0x14];

    GetBuddyRecordName(gRecordList->mEntries[listIndex].mRecordIndex, name);
    MI_CpuFill8(buffer, 0, bufferSize);
    MIi_CpuCopy16(name, buffer, 0x14);
}

s32 SetRecordFlag(u16 listIndex) {
    return SetBuddyRecordFlag(gRecordList->mEntries[listIndex].mRecordIndex, 1);
}

s32 ClearRecordFlag(u16 listIndex) {
    return SetBuddyRecordFlag(gRecordList->mEntries[listIndex].mRecordIndex, 0);
}

// Reads the slot's emblem into b, uses the emblem2.bin picture when it has none, and converts the pixels into c.
void ReadRecordEmblem(u16 listIndex, EmblemData *emblem, void *tiles) {
    u8 busy;

    SetupEmblemBlock(gRecordList->mEmblemBlock, gRecordList->mEntries[listIndex].mRecordIndex);
    busy = data_0217aa08->mBusy;
    do {
    } while (busy == 0 ? (gBackupAccess->mBackupEnabled != 0 ? gBackupAccess->mCommandRunning : 0) : 1);
    if (!CopyEmblemFromBlock(gRecordList->mEmblemBlock, gRecordList->mEntries[listIndex].mRecordIndex, emblem) ||
        emblem->mHasPixels == 0) {
        emblem->mHasPixels = 1;
        MIi_CpuCopyFast(gRecordList->mEmblem2Bin, emblem, 0x200);
    }
    CopyBytesIntoTiles(emblem, tiles, 0x20);
}

// Empties the slot and rebuilds the list.
void EraseRecord(u16 listIndex) {
    u8 busy;

    RemoveBuddyRecord(gRecordList->mEntries[listIndex].mRecordIndex);
    busy = data_0217aa08->mBusy;
    do {
    } while (busy == 0 ? (gBackupAccess->mBackupEnabled != 0 ? gBackupAccess->mCommandRunning : 0) : 1);
    BuildRecordList();
}

// Writes the entry's friend key as digits into b; returns TRUE only for a used entry with valid friend data.
s32 GetRecordFriendKeyText(u16 listIndex, void *text) {
    return GetBuddyFriendKeyText(gRecordList->mEntries[listIndex].mRecordIndex, text);
}

#pragma thumb off

#pragma thumb on

void LocateAndQueueRecordVS(void) {
    void *file;
    Nclr *emblemPalette;
    u16 *moPaletteData;
    Nclr *moPalette;
    Ncgr *mbChars;
    Nscr *mainScreenMap;
    Nclr *mbPalette;
    Nclr *soPalette;
    moPalette = NULL;
    mbChars = NULL;
    mainScreenMap = NULL;
    mbPalette = NULL;
    soPalette = NULL;
    file = FindSceneFile(gRecordVSMNcgrName);
    LocateNcgr2(&gRecordVS->mRecordVSMNcgr, file);
    file = FindSceneFile(gRecordVSMNcerName);
    LocateNcer(&gRecordVS->mRecordVSMNcer, file);
    file = FindSceneFile(gRecordVSMONclrName);
    LocateNclr(&moPalette, file);
    file = FindSceneFile(gRecordVSMBnclName);
    gRecordVS->mRecordVSMBncl = file;
    file = FindSceneFile(gRecordVSMBnllName);
    gRecordVS->mRecordVSMBnll = file;
    file = FindSceneFile(gRecordVSMTransientBnclName);
    gRecordVS->mRecordVSMTransientBncl = file;
    file = FindSceneFile(gRecordVSMTransientBnllName);
    gRecordVS->mRecordVSMTransientBnll = file;
    file = FindSceneFile(gRecordVSSNcgrName);
    LocateNcgr2(&gRecordVS->mRecordVSSNcgr, file);
    file = FindSceneFile(gRecordVSSNcerName);
    LocateNcer(&gRecordVS->mRecordVSSNcer, file);
    file = FindSceneFile(gRecordVSSONclrName);
    LocateNclr(&soPalette, file);
    file = FindSceneFile(gRecordVSSBnclName);
    gRecordVS->mRecordVSSBncl = file;
    file = FindSceneFile(gRecordVSSBnblName);
    gRecordVS->mRecordVSSBnbl = file;
    file = FindSceneFile(gRecordVSSBnllName);
    gRecordVS->mRecordVSSBnll = file;
    emblemPalette = GetEmblemSBNclr();
    file = FindSceneFile(gRecordVSMBNcgrName);
    LocateNcgr(&mbChars, file);
    file = FindSceneFile(gRecordVSMNscrName);
    LocateNscr(&mainScreenMap, file);
    file = FindSceneFile(gRecordVSM02NscrName);
    LocateNscr(&gRecordVS->mRecordVSM02Nscr, file);
    file = FindSceneFile(gRecordVSM03NscrName);
    LocateNscr(&gRecordVS->mRecordVSM03Nscr, file);
    file = FindSceneFile(gRecordVSMBNclrName);
    LocateNclr(&mbPalette, file);
    moPaletteData = moPalette->mData;
    CallQueueAppend(0x13, 0, (gRecordVS->mRecordVSMNcgr->mData), gRecordVS->mRecordVSMNcgr->mDataSize);
    CallQueueAppend(0xe, 0, moPalette->mData, (0x000001a0u));
    CallQueueAppend(0xe, 0x1c0, moPaletteData + 0xe0, 0x40);
    CallQueueAppend(0x23, 0, (gRecordVS->mRecordVSSNcgr->mData), gRecordVS->mRecordVSSNcgr->mDataSize);
    CallQueueAppend(0x1e, 0, soPalette->mData, soPalette->mDataSize);
    CallQueueAppend(4, 0, mbChars->mData, mbChars->mDataSize);
    CallQueueAppend(8, 0, mainScreenMap->mData, mainScreenMap->mDataSize);
    CallQueueAppend(0xf, 0, mbPalette->mData, 0x40);
    CallQueueAppend(0xe, 0x40, emblemPalette->mData, 0x20);
}

#pragma thumb off

#pragma thumb on

u16 GetRecordVSFirstRecordIndex(void) {
    return gRecordVS->mPageIndex * 5;
}

#pragma thumb off

#pragma thumb on

BOOL IsRecordVSRowFilled(int row) {
    int firstIndex;
    int recordCount;
    firstIndex = GetRecordVSFirstRecordIndex();
    recordCount = GetRecordCount();
    if (recordCount > firstIndex + row) {
        return 1;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on

// Shows or hides the objects of the five rows and of each row's flag.
void AdvanceRecordVSRowObjects(void) {
    s32 i;
    u16 firstIndex;
    u16 subBase;

    subBase = gRecordVS->mRecordVSSBncl->mUnk_06;
    firstIndex = GetRecordVSFirstRecordIndex();
    for (i = 0; i < 5; i++) {
        gRecordVS->mRecordVSSTable[gRecordVSUnhighlightedObjectIndices[i]].mVisible = 0;
        gRecordVS->mRecordVSSTable[gRecordVSHighlightObjectIndices[i]].mVisible = 0;
        gRecordVS->mRecordVSSTable[gRecordVSUnflaggedObjectIndices[i]].mVisible = 0;
        gRecordVS->mRecordVSSTable[gRecordVSFlaggedObjectIndices[i]].mVisible = 0;
        gRecordVS->mRecordVSSTable[subBase + gRecordVSRowLabelIndices[i]].mVisible = 0;
    }
    for (i = 0; i < 5; i++) {
        if (IsRecordVSRowFilled((s16) i)) {
            if (gRecordVS->mIndex == i) {
                gRecordVS->mRecordVSSTable[gRecordVSHighlightObjectIndices[i]].mVisible = 1;
                SetLabelPaletteIndex(gRecordVSRowLabelIndices[i], 0xe, gRecordVS->mRecordVSSBnll,
                                     gRecordVS->mRecordVSSTable, gRecordVS->mRecordVSSBncl);
            } else {
                gRecordVS->mRecordVSSTable[gRecordVSUnhighlightedObjectIndices[i]].mVisible = 1;
                SetLabelPaletteIndex(gRecordVSRowLabelIndices[i], 0xf, gRecordVS->mRecordVSSBnll,
                                     gRecordVS->mRecordVSSTable, gRecordVS->mRecordVSSBncl);
            }
            gRecordVS->mRecordVSSTable[gRecordVSUnflaggedObjectIndices[i]].mVisible = !IsRecordFlagged(firstIndex + i);
            gRecordVS->mRecordVSSTable[gRecordVSFlaggedObjectIndices[i]].mVisible = IsRecordFlagged(firstIndex + i);
            gRecordVS->mRecordVSSTable[subBase + gRecordVSRowLabelIndices[i]].mVisible = 1;
        }
    }
}

void PrintRecordVSShownRecord(void) {
    u16 buf[16];
    u32 counts[3][3] = {0};
    u8 friendKey[0x14];
    DateBytes date;
    RecordVS *recordVS;
    s32 i;
    s32 j;
    s32 firstIndex;

    firstIndex = GetRecordVSFirstRecordIndex();
    if (GetRecordFriendKeyText(firstIndex + gRecordVS->mShownIndex, friendKey)) {
        gRecordVS->mShowsFriendKey = 1;
        CallQueueAppend(9, 0, &gRecordVS->mRecordVSM03Nscr->mData, gRecordVS->mRecordVSM03Nscr->mDataSize);
    } else {
        gRecordVS->mShowsFriendKey = 0;
        CallQueueAppend(9, 0, &gRecordVS->mRecordVSM02Nscr->mData, gRecordVS->mRecordVSM02Nscr->mDataSize);
    }
    switch (gRecordVS->mShowsFriendKey) {
        case 0:
            CopyRecordText(firstIndex + gRecordVS->mShownIndex, buf, 0x20);
            PrintLabelLayoutTextNoFixedAdvance(0, 0, gRecordVS->mRecordVSMBnll, buf, gRecordVS->mRecordVSMBncl,
                                               gRecordVS->mRecordVSMTable);
            counts[1][0] = GetRecordMatchKind0FirstCount(firstIndex + gRecordVS->mShownIndex);
            counts[1][1] = GetRecordMatchKind1FirstCount(firstIndex + gRecordVS->mShownIndex);
            counts[1][2] = GetRecordMatchKind2FirstCount(firstIndex + gRecordVS->mShownIndex);
            counts[2][0] = GetRecordMatchKind0SecondCount(firstIndex + gRecordVS->mShownIndex);
            counts[2][1] = GetRecordMatchKind1SecondCount(firstIndex + gRecordVS->mShownIndex);
            counts[2][2] = GetRecordMatchKind2SecondCount(firstIndex + gRecordVS->mShownIndex);
            for (i = 1; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    if (counts[i][j] > 9999) {
                        counts[i][j] = 9999;
                    }
                }
            }
            FormatAsciiNumber(counts[1][0], buf);
            PrintLabelLayoutTextFixedAdvance(0, gRecordVSGridLabelIndices[1][0], gRecordVS->mRecordVSMBnll, buf,
                                             gRecordVS->mRecordVSMBncl, gRecordVS->mRecordVSMTable, 6);
            FormatAsciiNumber(counts[1][1], buf);
            PrintLabelLayoutTextFixedAdvance(0, gRecordVSGridLabelIndices[1][1], gRecordVS->mRecordVSMBnll, buf,
                                             gRecordVS->mRecordVSMBncl, gRecordVS->mRecordVSMTable, 6);
            FormatAsciiNumber(counts[1][2], buf);
            PrintLabelLayoutTextFixedAdvance(0, gRecordVSGridLabelIndices[1][2], gRecordVS->mRecordVSMBnll, buf,
                                             gRecordVS->mRecordVSMBncl, gRecordVS->mRecordVSMTable, 6);
            FormatAsciiNumber(counts[2][0], buf);
            PrintLabelLayoutTextFixedAdvance(0, gRecordVSGridLabelIndices[2][0], gRecordVS->mRecordVSMBnll, buf,
                                             gRecordVS->mRecordVSMBncl, gRecordVS->mRecordVSMTable, 6);
            FormatAsciiNumber(counts[2][1], buf);
            PrintLabelLayoutTextFixedAdvance(0, gRecordVSGridLabelIndices[2][1], gRecordVS->mRecordVSMBnll, buf,
                                             gRecordVS->mRecordVSMBncl, gRecordVS->mRecordVSMTable, 6);
            FormatAsciiNumber(counts[2][2], buf);
            PrintLabelLayoutTextFixedAdvance(0, gRecordVSGridLabelIndices[2][2], gRecordVS->mRecordVSMBnll, buf,
                                             gRecordVS->mRecordVSMBncl, gRecordVS->mRecordVSMTable, 6);
            GetRecordDate(firstIndex + gRecordVS->mShownIndex, &date);
            FormatDate(&date, buf);
            PrintLabelLayoutTextFixedDigits(0, 0xc, gRecordVS->mRecordVSMBnll, buf, gRecordVS->mRecordVSMBncl,
                                            gRecordVS->mRecordVSMTable, 6);
            ReadRecordEmblem(firstIndex + gRecordVS->mShownIndex, gRecordVS->mEmblem, gRecordVS->mEmblemConverted);
            recordVS = gRecordVS;
            CallQueueAppend(0x13, GetCellCharIndex(3, recordVS->mRecordVSMNcer, recordVS->mRecordVSMBncl) << 5,
                            recordVS->mEmblemConverted, 0x200);
            break;
        case 1:
            CopyRecordText(firstIndex + gRecordVS->mShownIndex, buf, 0x20);
            PrintLabelLayoutTextNoFixedAdvance(0, 0, gRecordVS->mRecordVSMTransientBnll, buf,
                                               gRecordVS->mRecordVSMTransientBncl, gRecordVS->mRecordVSMTransientTable);
            for (i = 0; i < 12; i++) {
                FormatAsciiNumber(friendKey[i] - 0x30, buf);
                PrintLabelLayoutTextNoFixedAdvance(
                    0, gRecordVSFriendKeyLabelIndices[i], gRecordVS->mRecordVSMTransientBnll, buf,
                    gRecordVS->mRecordVSMTransientBncl, gRecordVS->mRecordVSMTransientTable);
            }
            ReadRecordEmblem(firstIndex + gRecordVS->mShownIndex, gRecordVS->mEmblem, gRecordVS->mEmblemConverted);
            recordVS = gRecordVS;
            CallQueueAppend(0x13, GetCellCharIndex(1, recordVS->mRecordVSMNcer, recordVS->mRecordVSMTransientBncl) << 5,
                            recordVS->mEmblemConverted, 0x200);
            break;
    }
}

void RefreshRecordVSPage(void) {
    s32 i;
    s32 firstIndex;
    s32 listIndex;
    u8 buf[0x20];

    firstIndex = GetRecordVSFirstRecordIndex();
    for (i = 0; i < 5; i++) {
        listIndex = firstIndex + i;
        if (GetRecordCount() > listIndex) {
            CopyRecordText(listIndex, buf, 0x20);
            PrintLabelLayoutTextNoFixedAdvance(1, gRecordVSRowLabelIndices[i], gRecordVS->mRecordVSSBnll, buf,
                                               gRecordVS->mRecordVSSBncl, gRecordVS->mRecordVSSTable);
        }
    }
    if (GetRecordCount() <= firstIndex + gRecordVS->mIndex) {
        gRecordVS->mIndex = GetRecordCount() % 5 - 1;
        gRecordVS->mShownIndex = gRecordVS->mIndex;
    }
    PrintRecordVSShownRecord();
}

#pragma thumb off

#pragma thumb on
u32 IncrementRecordVSPageIndex(void) {
    s32 pageIndex = gRecordVS->mPageIndex + 1;
    gRecordVS->mPageIndex = pageIndex;
    return pageIndex;
}
#pragma thumb off

#pragma thumb on
u32 DecrementRecordVSPageIndex(void) {
    s32 pageIndex = gRecordVS->mPageIndex - 1;
    gRecordVS->mPageIndex = pageIndex;
    return pageIndex;
}
#pragma thumb off

#pragma thumb on

void IncrementRecordVSIndex(void) {
    int isFilled;
    int nextIndex;
    nextIndex = (gRecordVS->mIndex + 1) * 0x10000 >> 0x10;
    isFilled = IsRecordVSRowFilled(nextIndex);
    if ((isFilled == 0) || (5 <= nextIndex)) {
        nextIndex = 0;
    }
    if (gRecordVS->mIndex != nextIndex) {
        NNS_SndArcPlayerStartSeqArc((const void *) (((u32) ((u8 *) &data_0217d068))), 0, 0);
    }
    gRecordVS->mIndex = nextIndex;
}

void DecrementRecordVSIndex(void) {
    int isFilled;
    int recordCount;
    int remainder;
    int previousIndex;
    previousIndex = (gRecordVS->mIndex + -1) * 0x10000 >> 0x10;
    if (previousIndex < 0) {
        previousIndex = 4;
        isFilled = IsRecordVSRowFilled(4);
        if (isFilled == 0) {
            recordCount = GetRecordCount();
            remainder = (recordCount) % 5;
            previousIndex = (remainder + -1) * 0x10000 >> 0x10;
        }
    }
    if (gRecordVS->mIndex != previousIndex) {
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0);
    }
    gRecordVS->mIndex = previousIndex;
}

#pragma thumb off

#pragma thumb on

void AdvanceRecordVSOffsetTimers(void) {
    s32 i;
    u16 firstIndex;

    firstIndex = GetRecordVSFirstRecordIndex();
    gRecordVS->mRecordVSSTable[gRecordVSPageButtonPressedIndices[0]].mOffsetX =
        -LookupFrameOffset(6 - gRecordVS->mOffsetTimers[0]);
    gRecordVS->mRecordVSSTable[gRecordVSPageButtonPressedIndices[1]].mOffsetX =
        LookupFrameOffset(6 - gRecordVS->mOffsetTimers[1]);
    for (i = 0; i < 2; i++) {
        if (gRecordVS->mOffsetTimers[i] > 0) {
            gRecordVS->mOffsetTimers[i]--;
            gRecordVS->mRecordVSSTable[gRecordVSPageButtonIndices[i]].mVisible = 0;
            gRecordVS->mRecordVSSTable[gRecordVSPageButtonPressedIndices[i]].mVisible = 1;
        } else {
            gRecordVS->mRecordVSSTable[gRecordVSPageButtonIndices[i]].mVisible = 1;
            gRecordVS->mRecordVSSTable[gRecordVSPageButtonPressedIndices[i]].mVisible = 0;
        }
    }
    if (firstIndex == 0) {
        gRecordVS->mRecordVSSTable[gRecordVSPageButtonIndices[0]].mVisible = 0;
    }
    if (firstIndex + 5 >= GetRecordCount()) {
        gRecordVS->mRecordVSSTable[gRecordVSPageButtonIndices[1]].mVisible = 0;
    }
}

// Flips the flag of the entry in row a of the page and plays the matching sound.
void ToggleRecordVSRowFlag(s32 row) {
    s32 listIndex;

    listIndex = GetRecordVSFirstRecordIndex();
    listIndex += row;
    if (IsRecordFlagged(listIndex)) {
        ClearRecordFlag(listIndex);
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x25);
    } else {
        SetRecordFlag(listIndex);
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x24);
    }
}

#pragma thumb off

#pragma thumb on

BOOL IsRecordVSIndexChangeRunning(void) {
    if (gRecordVS->mIndexChangeTimer != 0) {
        return 1;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on

void AdvanceRecordVSIndexChange(void) {
    u16 mainBase;
    u16 transientBase;
    s16 offset;
    if (IsRecordVSIndexChangeRunning() != 0) {
        if (gRecordVS->mIndexChangeTimer == 7) {
            gRecordVS->mShownIndex = gRecordVS->mIndex;
            PrintRecordVSShownRecord();
        } else {
            mainBase = gRecordVS->mRecordVSMBncl->mUnk_06;
            transientBase = gRecordVS->mRecordVSMTransientBncl->mUnk_06;
            offset = LookupIndexChangeOffset(7 - gRecordVS->mIndexChangeTimer, 0);
            gRecordVS->mBg0OffsetY = offset;
            gRecordVS->mRecordVSMTable[3].mOffsetY = offset;
            gRecordVS->mRecordVSMTable[mainBase].mOffsetY = offset;
            gRecordVS->mRecordVSMTransientTable[1].mOffsetY = offset;
            gRecordVS->mRecordVSMTransientTable[transientBase].mOffsetY = offset;
        }
        gRecordVS->mIndexChangeTimer = gRecordVS->mIndexChangeTimer - 1;
    } else {
        if (gRecordVS->mIndex != 5 && gRecordVS->mIndex != gRecordVS->mShownIndex) {
            gRecordVS->mIndexChangeTimer = 7;
        }
    }
}

void RequestRecordVSState0(void) {
    s32 i;
    u16 transientBase;
    u16 subBase;
    s32 l;
    u16 mainBase;
    s32 j;
    i = 0;
    gRecordVS->mNextState = 0;
    gRecordVS->mStateFrames = 0;
    gRecordVS->mBg0OffsetX = 0;
    gRecordVS->mBg0OffsetY = -192;
    gRecordVS->mBg1OffsetX = 0;
    gRecordVS->mBg1OffsetY = -192;
    mainBase = gRecordVS->mRecordVSMBncl->mUnk_06;
    transientBase = gRecordVS->mRecordVSMTransientBncl->mUnk_06;
    subBase = gRecordVS->mRecordVSSBncl->mUnk_06;
    gRecordVS->mRecordVSMTable[0].mOffsetY = -192;
    gRecordVS->mRecordVSMTable[1].mOffsetY = -192;
    gRecordVS->mRecordVSMTable[2].mOffsetY = -192;
    gRecordVS->mRecordVSMTable[3].mOffsetY = -192;
    gRecordVS->mRecordVSMTable[mainBase].mOffsetY = -192;
    gRecordVS->mRecordVSMTable[mainBase + 1].mOffsetY = -192;
    gRecordVS->mRecordVSMTable[mainBase + 11].mOffsetY = -192;
    gRecordVS->mRecordVSMTable[mainBase + 12].mOffsetY = -192;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            gRecordVS->mRecordVSMTable[mainBase + gRecordVSGridLabelIndices[i][j]].mOffsetY = -192;
        }
    }
    gRecordVS->mRecordVSMTransientTable[1].mOffsetY = -192;
    gRecordVS->mRecordVSMTransientTable[0].mOffsetY = -192;
    gRecordVS->mRecordVSMTransientTable[transientBase].mOffsetY = -192;
    gRecordVS->mRecordVSMTransientTable[transientBase + 1].mOffsetY = -192;
    gRecordVS->mRecordVSMTransientTable[transientBase + 14].mOffsetY = -192;
    for (j = 0; j < 12; j++) {
        gRecordVS->mRecordVSMTransientTable[transientBase + gRecordVSFriendKeyLabelIndices[j]].mOffsetY = -192;
    }
    gRecordVS->mRecordVSSTable[20].mOffsetX = 0x100;
    gRecordVS->mRecordVSSTable[21].mOffsetX = 0x100;
    gRecordVS->mRecordVSSTable[24].mOffsetX = 0x100;
    gRecordVS->mRecordVSSTable[25].mOffsetX = 0x100;
    gRecordVS->mRecordVSSTable[25].mVisible = 0;
    gRecordVS->mRecordVSSTable[26].mOffsetX = 0x100;
    gRecordVS->mRecordVSSTable[subBase + 5].mOffsetX = 0x100;
    for (l = 0; l < 5; l++) {
        gRecordVS->mRecordVSSTable[gRecordVSUnhighlightedObjectIndices[l]].mOffsetX = 0x100;
        gRecordVS->mRecordVSSTable[gRecordVSHighlightObjectIndices[l]].mOffsetX = 0x100;
        gRecordVS->mRecordVSSTable[gRecordVSUnflaggedObjectIndices[l]].mOffsetX = 0x100;
        gRecordVS->mRecordVSSTable[gRecordVSFlaggedObjectIndices[l]].mOffsetX = 0x100;
        gRecordVS->mRecordVSSTable[subBase + gRecordVSRowLabelIndices[l]].mOffsetX = 0x100;
    }
    for (j = 0; j < 2; j++) {
        gRecordVS->mRecordVSSTable[gRecordVSPageButtonPressedIndices[j]].mVisible = 0;
    }
}

void RequestRecordVSState1(void) {
    gRecordVS->mNextState = 1;
    gRecordVS->mStateFrames = 0;
    PrintRecordVSShownRecord();
}

void RequestRecordVSState2AndRefreshPage(void) {
    gRecordVS->mNextState = 2;
    gRecordVS->mStateFrames = 0;
    RefreshRecordVSPage();
}

void RequestRecordVSState3(void) {
    gRecordVS->mNextState = 3;
    gRecordVS->mStateFrames = 0;
    RequestSelectReturnState1();
}

// Requests state 4: stores mNextState = 4 and zeroes mStateFrames; the next AdvanceRecordVS call copies it to mState
// and runs AdvanceRecordVSState4.
void RequestRecordVSState4(void) {
    gRecordVS->mNextState = 4;
    gRecordVS->mStateFrames = 0;
}

// Requests state 5: stores mNextState = 5 and zeroes mStateFrames; the next AdvanceRecordVS call copies it to mState
// and runs AdvanceRecordVSState5.
void RequestRecordVSState5(void) {
    gRecordVS->mNextState = 5;
    gRecordVS->mStateFrames = 0;
}

void RequestRecordVSState6AndChangePage(void) {
    gRecordVS->mNextState = 6;
    gRecordVS->mStateFrames = 0;
    switch (gRecordVS->mPageDecrement) {
        case 0:
            IncrementRecordVSPageIndex();
            break;
        case 1:
            DecrementRecordVSPageIndex();
            break;
    }
    RefreshRecordVSPage();
}

// Requests state 7: stores mNextState = 7 and zeroes mStateFrames; the next AdvanceRecordVS call copies it to mState
// and runs AdvanceRecordVSState7.
void RequestRecordVSState7(void) {
    gRecordVS->mNextState = 7;
    gRecordVS->mStateFrames = 0;
}

void RequestRecordVSState8(void) {
    s32 i;
    u16 subBase;
    gRecordVS->mNextState = 8;
    i = 0;
    gRecordVS->mStateFrames = 0;
    subBase = gRecordVS->mRecordVSSBncl->mUnk_06;
    gRecordVS->mRecordVSSTable[20].mOffsetX = 0x100;
    gRecordVS->mRecordVSSTable[21].mOffsetX = 0x100;
    gRecordVS->mRecordVSSTable[24].mOffsetX = 0x100;
    gRecordVS->mRecordVSSTable[25].mOffsetX = 0x100;
    gRecordVS->mRecordVSSTable[25].mVisible = 0;
    gRecordVS->mRecordVSSTable[26].mOffsetX = 0x100;
    gRecordVS->mRecordVSSTable[subBase + 5].mOffsetX = 0x100;
    for (i = 0; i < 5; i++) {
        gRecordVS->mRecordVSSTable[gRecordVSUnhighlightedObjectIndices[i]].mOffsetX = 0x100;
        gRecordVS->mRecordVSSTable[gRecordVSHighlightObjectIndices[i]].mOffsetX = 0x100;
        gRecordVS->mRecordVSSTable[gRecordVSUnflaggedObjectIndices[i]].mOffsetX = 0x100;
        gRecordVS->mRecordVSSTable[gRecordVSFlaggedObjectIndices[i]].mOffsetX = 0x100;
        gRecordVS->mRecordVSSTable[subBase + gRecordVSRowLabelIndices[i]].mOffsetX = 0x100;
    }
    for (i = 0; i < 2; i++) {
        gRecordVS->mRecordVSSTable[gRecordVSPageButtonPressedIndices[i]].mVisible = 0;
    }
    WriteBackupBuddyRecords();
}

void RequestRecordVSState9(void) {
    gRecordVS->mNextState = 9;
    gRecordVS->mStateFrames = 0;
    gRecordVS->mRecordVSSTable[25].mVisible = 1;
    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 4);
}

void RequestRecordVSState10(void) {
    gRecordVS->mNextState = 10;
    gRecordVS->mStateFrames = 0;
    RequestSelectReturnState4();
}

void RequestRecordVSState11AndRefreshPage(void) {
    s32 i;
    u16 subBase;
    gRecordVS->mNextState = 11;
    i = 0;
    gRecordVS->mStateFrames = 0;
    subBase = gRecordVS->mRecordVSSBncl->mUnk_06;
    gRecordVS->mRecordVSSTable[20].mOffsetX = 0x100;
    gRecordVS->mRecordVSSTable[21].mOffsetX = 0x100;
    gRecordVS->mRecordVSSTable[24].mOffsetX = -256;
    gRecordVS->mRecordVSSTable[25].mOffsetX = -256;
    gRecordVS->mRecordVSSTable[26].mOffsetX = -256;
    gRecordVS->mRecordVSSTable[subBase + 5].mOffsetX = -256;
    for (i = 0; i < 5; i++) {
        gRecordVS->mRecordVSSTable[gRecordVSUnhighlightedObjectIndices[i]].mOffsetX = 0x100;
        gRecordVS->mRecordVSSTable[gRecordVSHighlightObjectIndices[i]].mOffsetX = 0x100;
        gRecordVS->mRecordVSSTable[gRecordVSUnflaggedObjectIndices[i]].mOffsetX = 0x100;
        gRecordVS->mRecordVSSTable[gRecordVSFlaggedObjectIndices[i]].mOffsetX = 0x100;
        gRecordVS->mRecordVSSTable[subBase + gRecordVSRowLabelIndices[i]].mOffsetX = 0x100;
    }
    for (i = 0; i < 2; i++) {
        gRecordVS->mRecordVSSTable[gRecordVSPageButtonPressedIndices[i]].mVisible = 0;
    }
    RefreshRecordVSPage();
}

void InitRecordVS(void *heap) {
    s32 remaining;
    s32 i;
    s32 j;
    u16 objectIndex;
    u16 mainBase;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~3) | 2;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & ~3) | 1;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & 0x43) | 0xc800;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & 0x43) | 0xcc00;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & 0x43) | 0x1018;
    gRecordVS = HeapAlloc(heap, 0x94);
    gRecordVS->mHeap = heap;
    gRecordVS->mPageIndex = GetRecordScenePageIndex();
    gRecordVS->mIndex = GetRecordSceneIndex();
    gRecordVS->mPageDecrement = 0;
    gRecordVS->mIndexChangeTimer = 0;
    gRecordVS->mShownIndex = gRecordVS->mIndex;
    gRecordVS->mShowsFriendKey = 0;
    gRecordVS->mPageDecrementRepeat = FALSE;
    gRecordVS->mPageIncrementRepeat = FALSE;
    for (i = 0; i < 2; i++) {
        gRecordVS->mOffsetTimers[i] = 0;
    }
    LoadEmblemSBNclr(heap);
    LocateAndQueueRecordVS();
    InitLayoutTable(heap, gRecordVS->mRecordVSMBncl, gRecordVS->mRecordVSMBnll, &gRecordVS->mRecordVSMTable);
    InitLayoutTable(heap, gRecordVS->mRecordVSMTransientBncl, gRecordVS->mRecordVSMTransientBnll,
                    &gRecordVS->mRecordVSMTransientTable);
    InitLayoutTable(heap, gRecordVS->mRecordVSSBncl, gRecordVS->mRecordVSSBnll, &gRecordVS->mRecordVSSTable);
    gRecordVS->mRecordMessages = FindSceneFile("record.bmg");
    remaining = 0x8000;
    remaining -= InitLabelCanvas(heap, 0, gRecordVS->mRecordVSMBnll, 0x8c, 0x10, 0, gRecordVS->mRecordVSMNcer,
                                 gRecordVS->mRecordVSMBncl, gRecordVS->mRecordVSMTable, remaining);
    remaining -= InitLabelCanvas(heap, 1, gRecordVS->mRecordVSMBnll, 0xaa, 0xe, 1, gRecordVS->mRecordVSMNcer,
                                 gRecordVS->mRecordVSMBncl, gRecordVS->mRecordVSMTable, remaining);
    PrintLabelLayoutTextNoFixedAdvance(0, 1, gRecordVS->mRecordVSMBnll, GetBmgEntry(gRecordVS->mRecordMessages, 0),
                                       gRecordVS->mRecordVSMBncl, gRecordVS->mRecordVSMTable);
    remaining -= InitLabelCanvas(heap, 0xb, gRecordVS->mRecordVSMBnll, 0x96, 0xe, 2, gRecordVS->mRecordVSMNcer,
                                 gRecordVS->mRecordVSMBncl, gRecordVS->mRecordVSMTable, remaining);
    PrintLabelLayoutTextNoFixedAdvance(0, 0xb, gRecordVS->mRecordVSMBnll, GetBmgEntry(gRecordVS->mRecordMessages, 1),
                                       gRecordVS->mRecordVSMBncl, gRecordVS->mRecordVSMTable);
    remaining -= InitLabelCanvas(heap, 0xc, gRecordVS->mRecordVSMBnll, 0x46, 0x10, 3, gRecordVS->mRecordVSMNcer,
                                 gRecordVS->mRecordVSMBncl, gRecordVS->mRecordVSMTable, remaining);
    objectIndex = 4;
    mainBase = gRecordVS->mRecordVSMBncl->mUnk_06;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            remaining -= InitLabelCanvas(heap, gRecordVSGridLabelIndices[i][j], gRecordVS->mRecordVSMBnll,
                                         gRecordVSGridLabelWidths[i][j], gRecordVSGridLabelHeights[i][j], objectIndex,
                                         gRecordVS->mRecordVSMNcer, gRecordVS->mRecordVSMBncl,
                                         gRecordVS->mRecordVSMTable, remaining);
            objectIndex = mainBase + gRecordVSGridLabelIndices[i][j];
        }
    }
    for (i = 0; i < 3; i++) {
        PrintLabelLayoutTextNoFixedAdvance(0, gRecordVSGridLabelIndices[0][i], gRecordVS->mRecordVSMBnll,
                                           GetBmgEntry(gRecordVS->mRecordMessages, gRecordVSGridRow0MessageIndices[i]),
                                           gRecordVS->mRecordVSMBncl, gRecordVS->mRecordVSMTable);
    }
    remaining -= InitLabelCanvas(heap, 0, gRecordVS->mRecordVSMTransientBnll, 0x8c, 0x10, 0, gRecordVS->mRecordVSMNcer,
                                 gRecordVS->mRecordVSMTransientBncl, gRecordVS->mRecordVSMTransientTable, remaining);
    remaining -= InitLabelCanvas(heap, 1, gRecordVS->mRecordVSMTransientBnll, 0x70, 0x10, 1, gRecordVS->mRecordVSMNcer,
                                 gRecordVS->mRecordVSMTransientBncl, gRecordVS->mRecordVSMTransientTable, remaining);
    PrintLabelLayoutTextNoFixedAdvance(0, 1, gRecordVS->mRecordVSMTransientBnll,
                                       GetBmgEntry(gRecordVS->mRecordMessages, 0xb), gRecordVS->mRecordVSMTransientBncl,
                                       gRecordVS->mRecordVSMTransientTable);
    remaining -=
        InitLabelCanvas(heap, 0xe, gRecordVS->mRecordVSMTransientBnll, 0xe0, 0x38, 2, gRecordVS->mRecordVSMNcer,
                        gRecordVS->mRecordVSMTransientBncl, gRecordVS->mRecordVSMTransientTable, remaining);
    PrintLabelLayoutTextNoFixedAdvance(0, 0xe, gRecordVS->mRecordVSMTransientBnll,
                                       GetBmgEntry(gRecordVS->mRecordMessages, 0xc), gRecordVS->mRecordVSMTransientBncl,
                                       gRecordVS->mRecordVSMTransientTable);
    for (i = 0; i < 12; i++) {
        remaining -= InitLabelCanvas(heap, gRecordVSFriendKeyLabelIndices[i], gRecordVS->mRecordVSMTransientBnll,
                                     gRecordVSFriendKeyLabelWidths[i], gRecordVSFriendKeyLabelHeights[i], i + 3,
                                     gRecordVS->mRecordVSMNcer, gRecordVS->mRecordVSMTransientBncl,
                                     gRecordVS->mRecordVSMTransientTable, remaining);
    }
    remaining = GX_GetSizeOfSubOBJ();
    for (i = 0; i < 5; i++) {
        remaining -=
            InitLabelCanvas(heap, gRecordVSRowLabelIndices[i], gRecordVS->mRecordVSSBnll, gRecordVSRowLabelWidths[i],
                            gRecordVSRowLabelHeights[i], gRecordVSHighlightObjectIndices[i], gRecordVS->mRecordVSSNcer,
                            gRecordVS->mRecordVSSBncl, gRecordVS->mRecordVSSTable, remaining);
    }
    InitLabelCanvas(heap, 5, gRecordVS->mRecordVSSBnll, 0x98, 0x10, 0x19, gRecordVS->mRecordVSSNcer,
                    gRecordVS->mRecordVSSBncl, gRecordVS->mRecordVSSTable, remaining);
    PrintLabelLayoutTextNoFixedAdvance(1, 5, gRecordVS->mRecordVSSBnll, GetBmgEntry(gRecordVS->mRecordMessages, 3),
                                       gRecordVS->mRecordVSSBncl, gRecordVS->mRecordVSSTable);
    for (i = 0; i < 5; i++) {
        SetCellOamModeXlu(gRecordVSUnhighlightedObjectIndices[i], 0, gRecordVS->mRecordVSSNcer,
                          gRecordVS->mRecordVSSBncl);
        SetCellOamModeXlu(gRecordVSHighlightObjectIndices[i], 0, gRecordVS->mRecordVSSNcer, gRecordVS->mRecordVSSBncl);
        SetLabelOamModeXlu(gRecordVSRowLabelIndices[i], 0, gRecordVS->mRecordVSSBnll, gRecordVS->mRecordVSSTable,
                           gRecordVS->mRecordVSSBncl);
    }
    SetCellOamModeXlu(0x18, 0, gRecordVS->mRecordVSSNcer, gRecordVS->mRecordVSSBncl);
    SetCellOamModeXlu(0x19, 0, gRecordVS->mRecordVSSNcer, gRecordVS->mRecordVSSBncl);
    SetLabelOamModeXlu(5, 0, gRecordVS->mRecordVSSBnll, gRecordVS->mRecordVSSTable, gRecordVS->mRecordVSSBncl);
    gRecordVS->mEmblem = HeapAlloc(heap, 0x201);
    gRecordVS->mEmblemConverted = HeapAlloc(heap, 0x200);
    if (GetRecordPrevScreen() == 4) {
        if (GetRecordCount() != 0) {
            gRecordVS->mState = 11;
            RequestRecordVSState11AndRefreshPage();
        } else {
            gRecordVS->mState = 8;
            RequestRecordVSState8();
            if (GetRecordPrevScene() == 12) {
                gRecordVS->mNextScreen = 6;
            } else {
                gRecordVS->mNextScreen = 0;
            }
        }
    } else {
        gRecordVS->mState = 0;
        RequestRecordVSState0();
        ResetOamLists(GetRecordMainOam(), GetRecordSubOam());
    }
    gRecordVS->mRecordVSSTable[24].mVisible = 0;
    gRecordVS->mRecordVSSTable[25].mVisible = 0;
}

void ReleaseRecordVS(void) {
    u32 planeBits;
    if (gRecordVS->mNextScreen == 4) {
        SetRecordScenePageIndex(gRecordVS->mPageIndex);
        SetRecordSceneIndex(gRecordVS->mIndex);
    } else {
        SetRecordScenePageIndex(0);
        SetRecordSceneIndex(0);
        planeBits = (reg_GX_DISPCNT & 0x1f00) >> 8;
        reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | ((planeBits & ~0x13) << 8);
    }
    gRecordVS = NULL;
}

#pragma thumb off
