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

// Fills with 0 through a halfword stack offset of its own.
static inline void func_020338f8_inline(void *buffer, s32 byteCount) {
    volatile u16 fillValue = 0;
    MIi_CpuClear16(fillValue, buffer, byteCount);
}

#pragma thumb on

void bres_2033C80(s32 entryIndex) {
    CellFileSet *subCellFileSet;
    s32 orderIndex;
    BOOL isTeamIndex1;
    BOOL c;
    BOOL d;
    BOOL e;

    subCellFileSet = &bres_sState->mCellFileSets[1];
    if (bres_sState->mOwnEntryIndex == entryIndex) {
        d = TRUE;
    } else {
        d = FALSE;
    }
    orderIndex = bres_sState->mEntries[entryIndex].mOrderIndex;
    if (gRaceMultiConfig->mUseTeams != 0) {
        if (gRaceMultiConfig->mCurrentEntries[(u16) entryIndex].mPlayer.mTeamIndex == 1) {
            isTeamIndex1 = TRUE;
        } else {
            isTeamIndex1 = FALSE;
        }
        e = FALSE;
        if (isTeamIndex1 == FALSE) {
            c = TRUE;
        } else {
            c = FALSE;
        }
        if (c != FALSE && d != FALSE) {
            e = TRUE;
        }
        subCellFileSet->mCellTable[orderIndex + 0x10].mVisible = e;
        if (c != FALSE && d == FALSE) {
            c = TRUE;
        } else {
            c = FALSE;
        }
        subCellFileSet->mCellTable[orderIndex + 0x18].mVisible = c;
        if (isTeamIndex1 != FALSE && d != FALSE) {
            c = TRUE;
        } else {
            c = FALSE;
        }
        subCellFileSet->mCellTable[orderIndex + 0x20].mVisible = c;
        if (isTeamIndex1 != FALSE && d == FALSE) {
            d = TRUE;
        } else {
            d = FALSE;
        }
        subCellFileSet->mCellTable[orderIndex + 0x28].mVisible = d;
        subCellFileSet->mCellTable[orderIndex + 8].mVisible = 0;
        subCellFileSet->mCellTable[orderIndex].mVisible = subCellFileSet->mCellTable[orderIndex + 8].mVisible;
    } else {
        subCellFileSet->mCellTable[orderIndex].mVisible = d;
        if (d == FALSE) {
            d = TRUE;
        } else {
            d = FALSE;
        }
        subCellFileSet->mCellTable[orderIndex + 8].mVisible = d;
        subCellFileSet->mCellTable[orderIndex + 0x28].mVisible = 0;
        subCellFileSet->mCellTable[orderIndex + 0x20].mVisible = subCellFileSet->mCellTable[orderIndex + 0x28].mVisible;
        subCellFileSet->mCellTable[orderIndex + 0x18].mVisible = subCellFileSet->mCellTable[orderIndex + 0x20].mVisible;
        subCellFileSet->mCellTable[orderIndex + 0x10].mVisible = subCellFileSet->mCellTable[orderIndex + 0x18].mVisible;
    }
}

void bres_2033B80(s32 entryIndex) {
    CellFileSet *subCellFileSet;
    s32 r;
    s32 score;
    s32 length;
    u16 scoreText[4];

    subCellFileSet = &bres_sState->mCellFileSets[1];
    r = bres_sState->mEntries[entryIndex].mOrderIndex;
    score = bres_sState->mEntries[entryIndex].mScore;
    if (gRaceMultiConfig->mMode == MODE_BATTLE && gRaceMultiConfig->mUseTeams != 0 && gRaceMultiConfig->mRuleKind == 1) {
        subCellFileSet->mCellTable[r + 0x38].mVisible = 0;
        subCellFileSet->mCellTable[r + 0x48].mVisible = 0;
        return;
    }
    length = 0;
    func_020338f8_inline(scoreText, 8);
    if (score >= 100) {
        scoreText[length++] = 0x30 + (score / 100) % 10;
    }
    if (score >= 10) {
        scoreText[length++] = 0x30 + (score / 10) % 10;
    }
    scoreText[length++] = 0x30 + score % 10;
    scoreText[length] = 0;
    jn_ui_2124224(1, r + 8, subCellFileSet->mLabelLayout, scoreText, subCellFileSet->mCellLayout,
                  subCellFileSet->mCellTable, 6);
    r += 0x38;
    subCellFileSet->mCellTable[r].mVisible = 1;
    func_02025c48(r, bres_sState->mEntries[entryIndex].mRank + 0x40, subCellFileSet->mCellLayout);
}

void bres_2033AB8(s32 cellFileSetIndex, s32 entryIndex, s32 cellIndex, s32 d) {
    CellFileSet *iconCellFileSet;
    CellFileSet *cellFileSet;
    s32 characterIndex;
    Nclr *palette;
    u8 *paletteBlock;
    u8 v;
    u32 shuffledIndex;

    cellFileSet = &bres_sState->mCellFileSets[cellFileSetIndex];
    if (d == 1) {
        iconCellFileSet = &bres_sState->mCellFileSets[2];
    } else {
        iconCellFileSet = &bres_sState->mCellFileSets[3];
    }
    characterIndex = gRaceMultiConfig->mCurrentEntries[(u16) entryIndex].mCharacterIndex;
    QueueCellCharsAndFirstPalette(characterIndex, iconCellFileSet->mCells, iconCellFileSet->mChars,
                                  iconCellFileSet->mPalette, iconCellFileSet->mCellLayout, cellFileSetIndex, cellIndex,
                                  cellFileSet->mCells, cellFileSet->mCellLayout);
    if (characterIndex == 0xc) {
        if (d == 1) {
            palette = bres_sState->fieldC0;
        } else {
            palette = bres_sState->fieldC4;
        }
        v = GetCellPaletteIndex(cellIndex, cellFileSet->mCells, cellFileSet->mCellLayout);
        shuffledIndex = gStruct217B488->mShuffledIndices[entryIndex];
        paletteBlock = shuffledIndex * 0x20 + (u8 *) palette->mData;
        if (cellFileSetIndex == 0) {
            NNS_GfdRegisterNewVramTransferTask(0xe, v << 5, paletteBlock, 0x20);
        } else {
            NNS_GfdRegisterNewVramTransferTask(0x1e, v << 5, paletteBlock, 0x20);
        }
    }
}

void bres_initVictory(void *heap) {
    s32 index;
    u32 remainingObjSize;
    CellFileSet *mainCellFileSet;
    u8 *labelEntry;
    u16 entryName[11];

    remainingObjSize = GX_GetSizeOfOBJ();
    mainCellFileSet = &bres_sState->mCellFileSets[0];
    bres_sState->mTimerDigitCellBase = 1;
    bres_sState->mTimerTensCell = 0xb;
    index = 0;
    if ((s32) mainCellFileSet->mLabelLayout->field6 > 0) {
        labelEntry = data_02153e98;
        do {
            remainingObjSize -= mutil2_initLabel(0, heap, mainCellFileSet, labelEntry, remainingObjSize);
            labelEntry += 8;
            index++;
        } while (index < mainCellFileSet->mLabelLayout->field6);
    }
    func_020338f8_inline(entryName, 0x16);
    CopyKartEntryName((u16) bres_sState->mOwnEntryIndex, entryName, 1);
    jn_ui_212426C(0, 0, mainCellFileSet->mLabelLayout, entryName, mainCellFileSet->mCellLayout,
                  mainCellFileSet->mCellTable);
    bres_2033AB8(0, bres_sState->mOwnEntryIndex, 0, 1);
}

void bres_initLose(void *heap) {
    CellFileSet *mainCellFileSet;
    s32 n;
    s32 j;
    s32 entryIndex;
    s32 cellCount;
    u32 remainingObjSize;
    u8 *labelEntry;
    u16 entryName[11];
    s32 labelCount;
    LayoutTableEntry *cell;

    mainCellFileSet = &bres_sState->mCellFileSets[0];
    remainingObjSize = GX_GetSizeOfOBJ();
    n = 0;
    cellCount = mainCellFileSet->mCellLayout->field6;
    bres_sState->mTimerDigitCellBase = 8;
    bres_sState->mTimerTensCell = 0x12;
    j = 0;
    labelCount = mainCellFileSet->mLabelLayout->field6;
    if (labelCount > 0) {
        labelEntry = data_02153ec0;
        do {
            remainingObjSize -= mutil2_initLabel(n, heap, mainCellFileSet, labelEntry, remainingObjSize);
            labelEntry += 8;
            j++;
        } while (j < mainCellFileSet->mLabelLayout->field6);
    }
    jn_ui_212426C(0, 0, mainCellFileSet->mLabelLayout, jn_msg_getMessage(bres_sState->mCommonMessages, 0x7a),
                  mainCellFileSet->mCellLayout, mainCellFileSet->mCellTable);
    for (entryIndex = 0; entryIndex < bres_sState->mKartCount; entryIndex++) {
        if (bres_sState->mEntries[entryIndex].mRank == 0) {
            func_020338f8_inline(entryName, 0x16);
            CopyKartEntryName((u16) entryIndex, entryName, 1);
            n++;
            jn_ui_212426C(0, n, mainCellFileSet->mLabelLayout, entryName, mainCellFileSet->mCellLayout,
                          mainCellFileSet->mCellTable);
        }
    }
    while (n < 7) {
        n = n + 1;
        mainCellFileSet->mCellTable[n].mVisible = 0;
        n = (u32) n;
        cell = &mainCellFileSet->mCellTable[n + cellCount];
        cell->mVisible = 0;
    }
}

void bres_initDraw(void *heap) {
    CellFileSet *mainCellFileSet;
    s32 count;
    s32 iconCellBase;
    BOOL e;
    s32 i;

    mainCellFileSet = &bres_sState->mCellFileSets[0];
    count = bres_sState->fieldD4;
    iconCellBase = count + data_02153ea0[count - 2];
    if (count > 4) {
        e = FALSE;
    } else {
        e = TRUE;
    }
    bres_sState->mTimerDigitCellBase = 0x46;
    bres_sState->mTimerTensCell = 0x50;
    for (i = 0; i < 0x46; i++) {
        mainCellFileSet->mCellTable[i].mVisible = 0;
    }
    for (i = data_02153ea0[bres_sState->fieldD4 - 2];
         i < data_02153ea0[bres_sState->fieldD4 - 2] + bres_sState->fieldD4 * 2; i++) {
        mainCellFileSet->mCellTable[i].mVisible = 1;
    }
    for (i = 0; i < bres_sState->fieldD4; i++) {
        bres_2033AB8(0, i, iconCellBase + i, e);
    }
}

void bres_initVSTeams(void *heap) {
    ResultsBattle *results;
    CellFileSet *mainCellFileSet;
    s32 teamIndex;
    s32 count;
    s32 iconCellBase;
    s32 f;
    s32 placedCount;
    s32 i;
    BOOL e;
    s32 j;
    s32 k;
    s32 entryIndex;

    results = bres_sState;
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
    count = results->fieldD4;
    iconCellBase = count + data_02153eb0[count - 1];
    if (count <= 5) {
        e = TRUE;
        f = 0x38;
    } else {
        e = FALSE;
        f = 0x39;
    }
    results->mTimerDigitCellBase = 0x3a;
    bres_sState->mTimerTensCell = 0x44;
    for (i = 0; i < 0x38; i++) {
        mainCellFileSet->mCellTable[i].mVisible = 0;
    }
    j = data_02153eb0[bres_sState->fieldD4 - 1];
    j = (u32) j;
    if (j < data_02153eb0[bres_sState->fieldD4 - 1] + bres_sState->fieldD4 * 2) {
        do {
            mainCellFileSet->mCellTable[j].mVisible = 1;
            j++;
        } while (j < data_02153eb0[bres_sState->fieldD4 - 1] + bres_sState->fieldD4 * 2);
    }
    if (bres_sState->mFileSetKind == 3) {
        for (k = data_02153eb0[bres_sState->fieldD4 - 1];
             k < bres_sState->fieldD4 + data_02153eb0[bres_sState->fieldD4 - 1]; k++) {
            func_02025c48(k, f, mainCellFileSet->mCellLayout);
        }
    }
    for (entryIndex = 0; entryIndex < bres_sState->mKartCount; entryIndex++) {
        if (teamIndex == gRaceMultiConfig->mCurrentEntries[(u16) entryIndex].mPlayer.mTeamIndex) {
            bres_2033AB8(0, entryIndex, iconCellBase + placedCount, e);
            placedCount++;
        }
    }
    mainCellFileSet->mCellTable[0x39].mVisible = 0;
    mainCellFileSet->mCellTable[0x38].mVisible = mainCellFileSet->mCellTable[0x39].mVisible;
}

#pragma thumb off
