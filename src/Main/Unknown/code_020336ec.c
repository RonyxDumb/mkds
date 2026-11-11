#include "Main/Unknown/code_020336ec.h"
#include "Main/Unknown/code_0202578c.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02025bb4.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02124bc8.h"
#include "code_02148950.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_02016468.h"
#include "code_0214cfe4.h"

// Fills with 0 using a volatile halfword.
static inline void ResultsBattleEntryMI_CpuClear16(void *buffer, s32 byteCount) {
    volatile u16 fillValue = 0;
    MIi_CpuClear16(fillValue, buffer, byteCount);
}

#pragma thumb on

void SetResultsBattleEntryCellsVisible(s32 entryIndex) {
    CellFileSet *subCellFileSet;
    s32 orderIndex;
    BOOL isTeamIndex1;
    BOOL cellVisible;
    BOOL isOwnEntry;
    BOOL isOwnNotTeam1;

    subCellFileSet = &gResultsBattle->mCellFileSets[1];
    if (gResultsBattle->mOwnEntryIndex == entryIndex) {
        isOwnEntry = TRUE;
    } else {
        isOwnEntry = FALSE;
    }
    orderIndex = gResultsBattle->mEntries[entryIndex].mOrderIndex;
    if (gRaceSetup->mUseTeams != 0) {
        if (GetCurrentEntry(entryIndex)->mPlayer.mTeamIndex == 1) {
            isTeamIndex1 = TRUE;
        } else {
            isTeamIndex1 = FALSE;
        }
        isOwnNotTeam1 = FALSE;
        if (isTeamIndex1 == FALSE) {
            cellVisible = TRUE;
        } else {
            cellVisible = FALSE;
        }
        if (cellVisible != FALSE && isOwnEntry != FALSE) {
            isOwnNotTeam1 = TRUE;
        }
        subCellFileSet->mCellTable[orderIndex + 0x10].mVisible = isOwnNotTeam1;
        if (cellVisible != FALSE && isOwnEntry == FALSE) {
            cellVisible = TRUE;
        } else {
            cellVisible = FALSE;
        }
        subCellFileSet->mCellTable[orderIndex + 0x18].mVisible = cellVisible;
        if (isTeamIndex1 != FALSE && isOwnEntry != FALSE) {
            cellVisible = TRUE;
        } else {
            cellVisible = FALSE;
        }
        subCellFileSet->mCellTable[orderIndex + 0x20].mVisible = cellVisible;
        if (isTeamIndex1 != FALSE && isOwnEntry == FALSE) {
            isOwnEntry = TRUE;
        } else {
            isOwnEntry = FALSE;
        }
        subCellFileSet->mCellTable[orderIndex + 0x28].mVisible = isOwnEntry;
        subCellFileSet->mCellTable[orderIndex + 8].mVisible = 0;
        subCellFileSet->mCellTable[orderIndex].mVisible = subCellFileSet->mCellTable[orderIndex + 8].mVisible;
    } else {
        subCellFileSet->mCellTable[orderIndex].mVisible = isOwnEntry;
        if (isOwnEntry == FALSE) {
            isOwnEntry = TRUE;
        } else {
            isOwnEntry = FALSE;
        }
        subCellFileSet->mCellTable[orderIndex + 8].mVisible = isOwnEntry;
        subCellFileSet->mCellTable[orderIndex + 0x28].mVisible = 0;
        subCellFileSet->mCellTable[orderIndex + 0x20].mVisible = subCellFileSet->mCellTable[orderIndex + 0x28].mVisible;
        subCellFileSet->mCellTable[orderIndex + 0x18].mVisible = subCellFileSet->mCellTable[orderIndex + 0x20].mVisible;
        subCellFileSet->mCellTable[orderIndex + 0x10].mVisible = subCellFileSet->mCellTable[orderIndex + 0x18].mVisible;
    }
}

void PrintResultsBattleScoreAndShowRank(s32 entryIndex) {
    CellFileSet *subCellFileSet;
    s32 orderIndex;
    s32 score;
    s32 length;
    u16 scoreText[4];

    subCellFileSet = &gResultsBattle->mCellFileSets[1];
    orderIndex = gResultsBattle->mEntries[entryIndex].mOrderIndex;
    score = gResultsBattle->mEntries[entryIndex].mScore;
    if (gRaceSetup->mMode == MODE_BATTLE && gRaceSetup->mUseTeams != 0 && gRaceSetup->mRuleKind == 1) {
        subCellFileSet->mCellTable[orderIndex + 0x38].mVisible = 0;
        subCellFileSet->mCellTable[orderIndex + 0x48].mVisible = 0;
        return;
    }
    length = 0;
    ResultsBattleEntryMI_CpuClear16(scoreText, 8);
    if (score >= 100) {
        scoreText[length++] = 0x30 + (score / 100) % 10;
    }
    if (score >= 10) {
        scoreText[length++] = 0x30 + (score / 10) % 10;
    }
    scoreText[length++] = 0x30 + score % 10;
    scoreText[length] = 0;
    PrintLabelLayoutTextFixedDigits(1, orderIndex + 8, subCellFileSet->mLabelLayout, scoreText,
                                    subCellFileSet->mCellLayout, subCellFileSet->mCellTable, 6);
    orderIndex += 0x38;
    subCellFileSet->mCellTable[orderIndex].mVisible = 1;
    CopyCellLayoutEntryCellIndex(orderIndex, gResultsBattle->mEntries[entryIndex].mRank + 0x40,
                                 subCellFileSet->mCellLayout);
}

void QueueResultsBattleCharacterIcon(s32 cellFileSetIndex, s32 entryIndex, s32 cellIndex, s32 iconSetSelector) {
    CellFileSet *iconCellFileSet;
    CellFileSet *cellFileSet;
    s32 characterIndex;
    Nclr *palette;
    u8 *paletteBlock;
    u8 cellPaletteIndex;
    u32 shuffledIndex;

    cellFileSet = &gResultsBattle->mCellFileSets[cellFileSetIndex];
    if (iconSetSelector == 1) {
        iconCellFileSet = &gResultsBattle->mCellFileSets[2];
    } else {
        iconCellFileSet = &gResultsBattle->mCellFileSets[3];
    }
    characterIndex = GetCurrentEntry(entryIndex)->mCharacterIndex;
    QueueCellCharsAndFirstPalette(characterIndex, iconCellFileSet->mCells, iconCellFileSet->mChars,
                                  iconCellFileSet->mPalette, iconCellFileSet->mCellLayout, cellFileSetIndex, cellIndex,
                                  cellFileSet->mCells, cellFileSet->mCellLayout);
    if (characterIndex == 0xc) {
        if (iconSetSelector == 1) {
            palette = gResultsBattle->mCellFileSet2ShyguyPalette;
        } else {
            palette = gResultsBattle->mCellFileSet3ShyguyPalette;
        }
        cellPaletteIndex = GetCellPaletteIndex(cellIndex, cellFileSet->mCells, cellFileSet->mCellLayout);
        shuffledIndex = gMenuShared->mShuffledIndices[entryIndex];
        paletteBlock = shuffledIndex * 0x20 + (u8 *) palette->mData;
        if (cellFileSetIndex == 0) {
            NNS_GfdRegisterNewVramTransferTask(0xe, cellPaletteIndex << 5, paletteBlock, 0x20);
        } else {
            NNS_GfdRegisterNewVramTransferTask(0x1e, cellPaletteIndex << 5, paletteBlock, 0x20);
        }
    }
}

void SetupResultsBattleOwnEntry(void *heap) {
    s32 index;
    u32 remainingObjSize;
    CellFileSet *mainCellFileSet;
    u8 *labelEntry;
    u16 entryName[11];

    remainingObjSize = GX_GetSizeOfOBJ();
    mainCellFileSet = &gResultsBattle->mCellFileSets[0];
    gResultsBattle->mTimerDigitCellBase = 1;
    gResultsBattle->mTimerTensCell = 0xb;
    index = 0;
    if ((s32) mainCellFileSet->mLabelLayout->mCount > 0) {
        labelEntry = gResultsBattleOwnEntryLabelTextRows;
        do {
            remainingObjSize -= SetupLabelCanvas(0, heap, mainCellFileSet, labelEntry, remainingObjSize);
            labelEntry += 8;
            index++;
        } while (index < mainCellFileSet->mLabelLayout->mCount);
    }
    ResultsBattleEntryMI_CpuClear16(entryName, 0x16);
    CopyKartEntryName((u16) gResultsBattle->mOwnEntryIndex, entryName, 1);
    PrintLabelLayoutTextNoFixedAdvance(0, 0, mainCellFileSet->mLabelLayout, entryName, mainCellFileSet->mCellLayout,
                                       mainCellFileSet->mCellTable);
    QueueResultsBattleCharacterIcon(0, gResultsBattle->mOwnEntryIndex, 0, 1);
}

void SetupResultsBattleRankZeroNames(void *heap) {
    CellFileSet *mainCellFileSet;
    s32 rowIndex;
    s32 labelIndex;
    s32 entryIndex;
    s32 cellCount;
    u32 remainingObjSize;
    u8 *labelEntry;
    u16 entryName[11];
    s32 labelCount;
    LayoutTableEntry *cell;

    mainCellFileSet = &gResultsBattle->mCellFileSets[0];
    remainingObjSize = GX_GetSizeOfOBJ();
    rowIndex = 0;
    cellCount = mainCellFileSet->mCellLayout->mCount;
    gResultsBattle->mTimerDigitCellBase = 8;
    gResultsBattle->mTimerTensCell = 0x12;
    labelIndex = 0;
    labelCount = mainCellFileSet->mLabelLayout->mCount;
    if (labelCount > 0) {
        labelEntry = gResultsBattleRankZeroLabelTextRows;
        do {
            remainingObjSize -= SetupLabelCanvas(rowIndex, heap, mainCellFileSet, labelEntry, remainingObjSize);
            labelEntry += 8;
            labelIndex++;
        } while (labelIndex < mainCellFileSet->mLabelLayout->mCount);
    }
    PrintLabelLayoutTextNoFixedAdvance(0, 0, mainCellFileSet->mLabelLayout,
                                       GetBmgEntry(gResultsBattle->mCommonMessages, 0x7a), mainCellFileSet->mCellLayout,
                                       mainCellFileSet->mCellTable);
    for (entryIndex = 0; entryIndex < gResultsBattle->mKartCount; entryIndex++) {
        if (gResultsBattle->mEntries[entryIndex].mRank == 0) {
            ResultsBattleEntryMI_CpuClear16(entryName, 0x16);
            CopyKartEntryName((u16) entryIndex, entryName, 1);
            rowIndex++;
            PrintLabelLayoutTextNoFixedAdvance(0, rowIndex, mainCellFileSet->mLabelLayout, entryName,
                                               mainCellFileSet->mCellLayout, mainCellFileSet->mCellTable);
        }
    }
    while (rowIndex < 7) {
        rowIndex = rowIndex + 1;
        mainCellFileSet->mCellTable[rowIndex].mVisible = 0;
        rowIndex = (u32) rowIndex;
        cell = &mainCellFileSet->mCellTable[rowIndex + cellCount];
        cell->mVisible = 0;
    }
}

void SetupResultsBattleKartIcons(void *heap) {
    CellFileSet *mainCellFileSet;
    s32 count;
    s32 iconCellBase;
    BOOL iconSetSelector;
    s32 index;

    mainCellFileSet = &gResultsBattle->mCellFileSets[0];
    count = gResultsBattle->mIconKartCount;
    iconCellBase = count + gResultsBattleKartFirstCellIndices[count - 2];
    if (count > 4) {
        iconSetSelector = FALSE;
    } else {
        iconSetSelector = TRUE;
    }
    gResultsBattle->mTimerDigitCellBase = 0x46;
    gResultsBattle->mTimerTensCell = 0x50;
    for (index = 0; index < 0x46; index++) {
        mainCellFileSet->mCellTable[index].mVisible = 0;
    }
    for (index = gResultsBattleKartFirstCellIndices[gResultsBattle->mIconKartCount - 2];
         index <
         gResultsBattleKartFirstCellIndices[gResultsBattle->mIconKartCount - 2] + gResultsBattle->mIconKartCount * 2;
         index++) {
        mainCellFileSet->mCellTable[index].mVisible = 1;
    }
    for (index = 0; index < gResultsBattle->mIconKartCount; index++) {
        QueueResultsBattleCharacterIcon(0, index, iconCellBase + index, iconSetSelector);
    }
}

void SetupResultsBattleTeamIcons(void *heap) {
    ResultsBattle *results;
    CellFileSet *mainCellFileSet;
    s32 teamIndex;
    s32 count;
    s32 iconCellBase;
    s32 sourceCellIndex;
    s32 placedCount;
    s32 hiddenCellIndex;
    BOOL iconSetSelector;
    s32 shownCellIndex;
    s32 iconCellIndex;
    s32 entryIndex;

    results = gResultsBattle;
    mainCellFileSet = &results->mCellFileSets[0];
    switch (results->mFileSetKind) {
        case 3:
            teamIndex = 0;
            break;
        default:
            teamIndex = 1;
            break;
    }
    placedCount = 0;
    count = results->mIconKartCount;
    iconCellBase = count + gResultsBattleTeamFirstCellIndices[count - 1];
    if (count <= 5) {
        iconSetSelector = TRUE;
        sourceCellIndex = 0x38;
    } else {
        iconSetSelector = FALSE;
        sourceCellIndex = 0x39;
    }
    results->mTimerDigitCellBase = 0x3a;
    gResultsBattle->mTimerTensCell = 0x44;
    for (hiddenCellIndex = 0; hiddenCellIndex < 0x38; hiddenCellIndex++) {
        mainCellFileSet->mCellTable[hiddenCellIndex].mVisible = 0;
    }
    shownCellIndex = gResultsBattleTeamFirstCellIndices[gResultsBattle->mIconKartCount - 1];
    shownCellIndex = (u32) shownCellIndex;
    if (shownCellIndex <
        gResultsBattleTeamFirstCellIndices[gResultsBattle->mIconKartCount - 1] + gResultsBattle->mIconKartCount * 2) {
        do {
            mainCellFileSet->mCellTable[shownCellIndex].mVisible = 1;
            shownCellIndex++;
        } while (shownCellIndex < gResultsBattleTeamFirstCellIndices[gResultsBattle->mIconKartCount - 1] +
                                      gResultsBattle->mIconKartCount * 2);
    }
    if (gResultsBattle->mFileSetKind == 3) {
        for (iconCellIndex = gResultsBattleTeamFirstCellIndices[gResultsBattle->mIconKartCount - 1];
             iconCellIndex <
             gResultsBattle->mIconKartCount + gResultsBattleTeamFirstCellIndices[gResultsBattle->mIconKartCount - 1];
             iconCellIndex++) {
            CopyCellLayoutEntryCellIndex(iconCellIndex, sourceCellIndex, mainCellFileSet->mCellLayout);
        }
    }
    for (entryIndex = 0; entryIndex < gResultsBattle->mKartCount; entryIndex++) {
        if (teamIndex == GetCurrentEntry(entryIndex)->mPlayer.mTeamIndex) {
            QueueResultsBattleCharacterIcon(0, entryIndex, iconCellBase + placedCount, iconSetSelector);
            placedCount++;
        }
    }
    mainCellFileSet->mCellTable[0x39].mVisible = 0;
    mainCellFileSet->mCellTable[0x38].mVisible = mainCellFileSet->mCellTable[0x39].mVisible;
}

#pragma thumb off
