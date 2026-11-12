#include "Main/Race/results_battle_registers.h"
#include "Main/Unknown/code_02033dd0.h"
#include "Main/System/interpolation_value.h"
#include "Main/Race/cup_records.h"
#include "Main/System/low_byte.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "registers.h"
#include "Main/Unknown/code_02033d9c.h"
#include "Main/Unknown/code_021277ac.h"
#include "Main/Unknown/code_020336ec.h"
#include "Main/Graphics/cell_file_set.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Graphics/cell_layout_entry.h"
#include "Main/Graphics/oam.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "code_02148950.h"
#include "gfd_VramTransferManager.h"
#include "code_0214cfe4.h"
#include "Main/Unknown/code_02032ab0.h"
#include "Main/Scene/run_scene_connection.h"
#include "00/Menu/wi_fi_vs_matching.h"
#include "Main/System/heap.h"
#include "Main/Scene/display_settings.h"
#include "Main/Net/connection_sharing.h"
#include "Main/Net/connect_non_multiboot.h"
#include "Main/Race/race.h"
#include "Main/Race/results_battle_frame_limit.h"
#include "Main/Unknown/code_02120610.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Graphics/scene_text_init.h"
#include "Main/Graphics/scene_text.h"
#include "Main/Menu/select_return.h"
#include "Main/MapObjects/trophy.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"
#include "00/Lib/DWC/code_0219b580.h"
#include "Main/Graphics/player_character_cell_file_set.h"
#include "Main/Unknown/code_02033000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02037000.h"
#include "Main/Unknown/code_02038000.h"
#include "Main/System/result_archive_path.h"
#include "Main/Unknown/code_0205d000.h"
#include "Main/Unknown/code_02062000.h"
#include "Main/Unknown/code_020ad000.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Menu/menu.h"
#include "Main/Net/packed_index.h"
#include "Main/Net/wi_fi_session_step.h"
#include "Main/Graphics/back_screen.h"
#include "Main/Unknown/code_02125de0.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02153000.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02164000.h"
#include "01/Scene/test_scene.h"
#include "Main/Graphics/cell_layout.h"
#include "gx_load2d.h"
#include "code_0214d018.h"

// Reads the table of gCupRecords, a row chosen by one call and a column by another.
static inline KartCourseResult *ResultsBattleGetKartCourseResult(u32 entryIndex) {
    return &gCupRecords->mKartResults[GetCourseIndexInCup()][GetLowByte(entryIndex)];
}

#pragma thumb on

void WriteGhostGetScanRegisters(void) {
    s16 offset;
    u32 subWinOutBits;
    u32 subWinInBits;
    s32 negatedOffset;
    s32 mainWinInBits;

    offset = GetInterpolatedValue(&gTimeAttackGhostGetScan->mInterpolation);
    reg_G2_BG0OFS = (offset << 16) & 0x1ff0000;
    negatedOffset = -offset;
    reg_G2S_DB_BG3OFS = (negatedOffset << 16) & 0x1ff0000;
    switch (offset) {
        default:
            reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffff1fff) | 0x2000;
            mainWinInBits = (reg_G2_WININ & ~0x3f) | 0x1f;
            reg_G2_WININ = mainWinInBits | 0x20;
            reg_G2_WINOUT = (u32) ((reg_G2_WINOUT & ~0x3f) | 0xe) | 0x20;
            reg_G2_WIN0H = 0xff;
            reg_G2_WIN0V = ((negatedOffset << 8) & 0xff00) | 0xc0;
            reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffff1fff) | 0x2000;
            subWinInBits = (reg_G2S_DB_WININ & ~0x3f) | 0x1f;
            reg_G2S_DB_WININ = subWinInBits | 0x20;
            subWinOutBits = (reg_G2S_DB_WINOUT & ~0x3f) | 7;
            reg_G2S_DB_WINOUT = subWinOutBits | 0x20;
            reg_G2S_DB_WIN0H = 0xff;
            reg_G2S_DB_WIN0V = (offset + 0xc0) & 0xff;
            break;
        case 0:
            reg_GX_DISPCNT = reg_GX_DISPCNT & 0xffff1fff;
            reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & 0xffff1fff;
            break;
    }
}

void AssignResultsBattleTeamOrder(void) {
    ResultsBattle *resultsBattle;
    s32 nextOrderIndex;
    s32 team1Count;
    s32 entryIndex;

    nextOrderIndex = 0;
    team1Count = 0;
    for (entryIndex = 0; entryIndex < gResultsBattle->mKartCount; entryIndex++) {
        if (GetCurrentEntry(entryIndex)->mPlayer.mTeamIndex == 0) {
            gResultsBattle->mEntries[entryIndex].mOrderIndex = nextOrderIndex;
            nextOrderIndex++;
        }
    }
    for (entryIndex = 0; entryIndex < gResultsBattle->mKartCount; entryIndex++) {
        if (GetCurrentEntry(entryIndex)->mPlayer.mTeamIndex == 1) {
            team1Count++;
        }
    }
    if (nextOrderIndex < 4 && team1Count <= 4) {
        nextOrderIndex = 4;
    }
    for (entryIndex = 0; entryIndex < gResultsBattle->mKartCount; entryIndex++) {
        if (GetCurrentEntry(entryIndex)->mPlayer.mTeamIndex == 1) {
            gResultsBattle->mEntries[entryIndex].mOrderIndex = nextOrderIndex;
            nextOrderIndex++;
        }
    }
}

void AssignResultsBattleTeamOrderByScore(void) {
    ResultsBattle *resultsBattle;
    s32 scores[8];
    s32 team0Entries[8];
    s32 team1Entries[8];
    s32 team0BestIndex;
    s32 nextOrderIndex;
    s32 memberIndex;
    s32 team0Count;
    s32 kartIndex;
    s32 team1Count;
    s32 team1Step;
    s32 team0BestScore;
    s32 team0Step;
    s32 team1BestScore;
    s32 team1BestIndex;

    nextOrderIndex = 0;
    team0Count = 0;
    team1Count = 0;
    for (kartIndex = 0; kartIndex < (resultsBattle = gResultsBattle)->mKartCount; kartIndex++) {
        scores[kartIndex] = resultsBattle->mEntries[kartIndex].mScore;
    }
    for (kartIndex = 0; kartIndex < (resultsBattle = *(ResultsBattle **) &gResultsBattle)->mKartCount; kartIndex++) {
        if (GetCurrentEntry(kartIndex)->mPlayer.mTeamIndex == 0) {
            team0Entries[team0Count] = kartIndex;
            team0Count = team0Count + 1;
        } else {
            team1Entries[team1Count] = kartIndex;
            team1Count = team1Count + 1;
        }
    }
    for (team0Step = 0; team0Step < team0Count; team0Step++) {
        team0BestScore = -1;
        team0BestIndex = -1;
        for (memberIndex = 0; memberIndex < team0Count; memberIndex++) {
            if (team0BestScore < scores[team0Entries[memberIndex]]) {
                team0BestScore = scores[team0Entries[memberIndex]];
                team0BestIndex = memberIndex;
            }
        }
        gResultsBattle->mEntries[team0Entries[team0BestIndex]].mOrderIndex = nextOrderIndex++;
        scores[team0Entries[team0BestIndex]] = -2;
    }
    if (nextOrderIndex < 4 && team1Count <= 4) {
        nextOrderIndex = 4;
    }
    for (team1Step = 0; team1Step < team1Count; team1Step++) {
        team1BestScore = -1;
        team1BestIndex = -1;
        for (memberIndex = 0; memberIndex < team1Count; memberIndex++) {
            if (team1BestScore < scores[team1Entries[memberIndex]]) {
                team1BestScore = scores[team1Entries[memberIndex]];
                team1BestIndex = memberIndex;
            }
        }
        gResultsBattle->mEntries[team1Entries[team1BestIndex]].mOrderIndex = nextOrderIndex++;
        scores[team1Entries[team1BestIndex]] = -2;
    }
}

void FillResultsBattleEntries(void) {
    u16 rankKartIndex;
    u16 kartIndex;
    s32 higherCount;

    for (kartIndex = 0; kartIndex < gResultsBattle->mKartCount; kartIndex++) {
        if (gResultsBattle->mMode == 3 || gRaceSetup->mRuleKind == 2) {
            gResultsBattle->mEntries[kartIndex].mScore =
                ResultsBattleGetKartCourseResult(GetLowByte(kartIndex))->mTotalPoints;
        } else {
            gResultsBattle->mEntries[kartIndex].mScore =
                ResultsBattleGetKartCourseResult(GetLowByte(kartIndex))->mWinCount;
        }
    }
    for (rankKartIndex = 0; rankKartIndex < gResultsBattle->mKartCount; rankKartIndex++) {
        higherCount = 0;
        for (kartIndex = 0; kartIndex < gResultsBattle->mKartCount; kartIndex++) {
            if (rankKartIndex != kartIndex &&
                gResultsBattle->mEntries[rankKartIndex].mScore < gResultsBattle->mEntries[kartIndex].mScore) {
                higherCount++;
            }
        }
        gResultsBattle->mEntries[rankKartIndex].mRank = higherCount;
    }
    if (gRaceSetup->mUseTeams != 0) {
        if (gRaceSetup->mMode == MODE_BATTLE && gRaceSetup->mRuleKind == 1) {
            AssignResultsBattleTeamOrder();
        } else {
            AssignResultsBattleTeamOrderByScore();
        }
    } else if (gRaceSetup->mMode == MODE_BATTLE) {
        for (kartIndex = 0; kartIndex < gResultsBattle->mKartCount; kartIndex++) {
            gResultsBattle->mEntries[kartIndex].mOrderIndex = gMenuShared->mOrderIndices[kartIndex];
        }
    } else {
        for (kartIndex = 0; kartIndex < gResultsBattle->mKartCount; kartIndex++) {
            gResultsBattle->mEntries[kartIndex].mOrderIndex = GetKartCupRank(kartIndex) - 1;
        }
    }
}

s32 AreResultsBattleRanksAllZero(void) {
    s32 allRanksZero;
    s32 kartIndex;

    allRanksZero = 1;
    kartIndex = 0;
    for (; kartIndex < gResultsBattle->mKartCount; kartIndex++) {
        allRanksZero &= gResultsBattle->mEntries[kartIndex].mRank == 0 ? 1 : 0;
    }
    return allRanksZero;
}

s32 IsResultsBattleTimerRunOut(void) {
    BOOL result;

    result = FALSE;
    if (gResultsBattle->mUseTimer != FALSE && gResultsBattle->mTimer == 0) {
        result = TRUE;
    }
    return result;
}

s32 IsResultsBattleTimerBelow300(void) {
    BOOL result;

    result = FALSE;
    if (gResultsBattle->mUseTimer != FALSE && gResultsBattle->mTimer < 0x12c) {
        result = TRUE;
    }
    return result;
}

#pragma thumb off

#pragma thumb on

void StartResultsBattleChoices(void) {
    void *firstText;
    void *secondText;
    firstText = GetBmgEntry(gResultsBattle->mCommonMessages, 0x5d);
    secondText = GetBmgEntry(gResultsBattle->mCommonMessages, 0x5f);
    StartSelectChoises(firstText, secondText, 0);
}

#pragma thumb off

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

#pragma thumb on

// Fills with 0 using a volatile halfword.
static inline void ResultsBattleMI_CpuClear16(void *buffer, s32 byteCount) {
    volatile u16 fillValue = 0;
    MIi_CpuClear16(fillValue, buffer, byteCount);
}

static inline CourseTeamResult *ResultsBattleGetCourseTeamResult(s32 teamIndex) {
    return &gCupRecords->mTeamResults[GetCourseIndexInCup()].mTeams[teamIndex];
}

static inline CourseTeamResults *GetCourseTeamResults(void) {
    return &gCupRecords->mTeamResults[GetCourseIndexInCup()];
}

void InitResultsBattle(void *heap, void *mainOam, void *subOam) {
    DisplaySettings *displaySettings;
    CellFileSet *mainCellFileSet;
    CellFileSet *subCellFileSet;
    ResultsBattle *results;
    ScreenMapFileSet *screenMapFileSet;
    LayoutEntryTable *cellLayout;
    u32 remainingObjSize;
    s32 firstTeamScore;
    s32 value;
    s32 orderIndex;
    u16 itemIndex;
    u16 entryIndex;
    u16 entryName[11];
    SceneTextInitParams sceneTextInitParams;
    s32 orderUsed[8];

    gResultsBattle = HeapAlloc(heap, 0x154);
    MemFillWordsByBlock_inline(gResultsBattle, 0x154);
    gResultsBattle->mOamLists[0] = mainOam;
    gResultsBattle->mOamLists[1] = subOam;
    gResultsBattle->mMode = gStartupWork->mConnectionKind;
    if (gResultsBattle->mMode == 3) {
        SetupWiFiSession(3);
    }
    Init3dEngine();
    displaySettings = CreateDisplaySettings(heap, data_021547f0);
    SetBg0Record(&displaySettings->mMainBgRecords, 3, 0, 0, 0, 0xd, 2, 0);
    SetBg1Record(&displaySettings->mMainBgRecords, 0, 0, 0, 0, 0xc, 0, 0);
    SetBg2RecordParams(&displaySettings->mMainBgRecords, 2, 0, 0, 0, 0x1e, 6);
    SetBg3RecordParams(&displaySettings->mMainBgRecords, 3, 0, 0, 0, 0x1d, 6);
    SetBg3RecordParams(&displaySettings->mSubBgRecords, 3, 0, 0, 0, 1, 6);
    InitDisplayFromSettings(displaySettings);
    sceneTextInitParams.mUseTxtSystem = 0;
    sceneTextInitParams.mTxtSystemFont = NULL;
    sceneTextInitParams.mUseCanvas1 = 0;
    sceneTextInitParams.mUseCanvas2 = 0;
    sceneTextInitParams.mUseCanvas3 = 0;
    sceneTextInitParams.mUseSelectChoises = 1;
    sceneTextInitParams.mSelectChoisesFont = GetFontByIndex(2);
    sceneTextInitParams.mUseSelectReturn = 0;
    sceneTextInitParams.mUseBackScreen = 0;
    sceneTextInitParams.mBackScreenKind = 0;
    LoadTxtSystemAndSelectChoisesAndSelectReturnData();
    InitSceneText(heap, &sceneTextInitParams);
    InitFrmVramManagers();
    gResultsBattle->mCommonMessages = FindFileInLoadedArchives(gCommonBmgName);
    switch (gResultsBattle->mMode) {
        case 0:
            gResultsBattle->mOwnEntryIndex = 0;
            gResultsBattle->mKartCount = gRaceSetup->mKartCount;
            gResultsBattle->mState = 2;
            break;
        case 1:
        case 2:
            SetSelectChoisesSoundId(1, 0xf);
            gResultsBattle->mOwnEntryIndex =
                GetParticipantPosByIndex(gConnectionWork->mConnectionMode == 2 ? gConnectionWork->mOwnIndex : 0)
                    ->mEntryIndex;
            gResultsBattle->mKartCount = gRaceSetup->mKartCount;
            gResultsBattle->mState = 0;
            break;
        case 3:
            gResultsBattle->mOwnEntryIndex = GetPackedIndex(DWC_GetMyAID());
            gResultsBattle->mKartCount = gWiFiSession->mKartCount;
            gResultsBattle->mUseTimer = TRUE;
            gResultsBattle->mTimer = 0x384;
            gResultsBattle->mState = 2;
            break;
    }
    FillResultsBattleEntries();
    if (gRaceSetup->mUseTeams != 0) {
        firstTeamScore = 0;
        value = 0;
        switch (gRaceSetup->mRuleKind) {
            case 1:
                firstTeamScore = ResultsBattleGetCourseTeamResult(0)->mWinCount;
                value = ResultsBattleGetCourseTeamResult(1)->mWinCount;
                break;
            case 2:
                firstTeamScore = GetCourseTeamResults()->mTeams[0].mTotalPoints;
                value = GetCourseTeamResults()->mTeams[1].mTotalPoints;
                break;
        }
        if (firstTeamScore == value) {
            gResultsBattle->mIconKartCount = gResultsBattle->mKartCount;
            gResultsBattle->mFileSetKind = 2;
        } else if (firstTeamScore > value) {
            gResultsBattle->mIconKartCount = gRaceSetup->mTeamKartCounts[0];
            gResultsBattle->mFileSetKind = 3;
        } else if (value > firstTeamScore) {
            gResultsBattle->mIconKartCount = gRaceSetup->mTeamKartCounts[1];
            gResultsBattle->mFileSetKind = 4;
        }
    } else if (AreResultsBattleRanksAllZero() != 0) {
        gResultsBattle->mIconKartCount = gResultsBattle->mKartCount;
        gResultsBattle->mFileSetKind = 2;
    } else if (gResultsBattle->mEntries[gResultsBattle->mOwnEntryIndex].mRank == 0) {
        gResultsBattle->mFileSetKind = 0;
    } else {
        gResultsBattle->mFileSetKind = 1;
    }
    SetPlayerCharacterCellFileSet(1, &gResultsBattle->mCellFileSets[2]);
    SetPlayerCharacterCellFileSet(0, &gResultsBattle->mCellFileSets[3]);
    gResultsBattle->mCellFileSet2ShyguyPalette = GetPlayerCharacterShyguyNclr(1);
    gResultsBattle->mCellFileSet3ShyguyPalette = GetPlayerCharacterShyguyNclr(0);
    screenMapFileSet = &gResultsBattle->mScreenMapFileSets[0];
    LoadScreenMapFileSet(screenMapFileSet, gResultsBattleVictoryMBNcgrName[gResultsBattle->mFileSetKind][0],
                         gResultsBattleVictoryMBNclrName[gResultsBattle->mFileSetKind][0],
                         gResultsBattleVictoryMLowerNscrName[gResultsBattle->mFileSetKind][0], 3, FindSceneFile);
    LoadNscrData(&screenMapFileSet->mScreenMaps[2],
                 FindSceneFile(gResultsBattleVictoryMUpperNscrName[gResultsBattle->mFileSetKind][0]));
    GX_LoadBG3Char(screenMapFileSet->mChars[3]->mData, 0, screenMapFileSet->mChars[3]->mDataSize);
    GX_LoadBGPltt(screenMapFileSet->mPalette->mData, 0, 0x140);
    GX_LoadBG2Scr(screenMapFileSet->mScreenMaps[2]->mData, 0, screenMapFileSet->mScreenMaps[2]->mDataSize);
    GX_LoadBG3Scr(screenMapFileSet->mScreenMaps[3]->mData, 0, screenMapFileSet->mScreenMaps[3]->mDataSize);
    mainCellFileSet = &gResultsBattle->mCellFileSets[0];
    LoadCellFileSet(mainCellFileSet, gResultsBattleVictoryMNcgrName[gResultsBattle->mFileSetKind][0],
                    gResultsBattleVictoryMNcerName[gResultsBattle->mFileSetKind][0],
                    gResultsBattleVictoryMONclrName[gResultsBattle->mFileSetKind][0],
                    gResultsBattleVictoryMBnclName[gResultsBattle->mFileSetKind][0],
                    gResultsBattleVictoryMBnllName[gResultsBattle->mFileSetKind][0], NULL, FindSceneFile);
    SetupCellFileSet(0, heap, mainCellFileSet);
    switch (gResultsBattle->mFileSetKind) {
        case 0:
            SetupResultsBattleOwnEntry(heap);
            break;
        case 1:
            SetupResultsBattleRankZeroNames(heap);
            break;
        case 2:
            SetupResultsBattleKartIcons(heap);
            break;
        case 3:
        case 4:
            SetupResultsBattleTeamIcons(heap);
            break;
    }
    cellLayout = mainCellFileSet->mCellLayout;
    for (itemIndex = 0; itemIndex < cellLayout->mCount; itemIndex++) {
        GetCellLayoutEntry(mainCellFileSet->mCellLayout, itemIndex);
    }
    screenMapFileSet = &gResultsBattle->mScreenMapFileSets[1];
    LoadScreenMapFileSet(screenMapFileSet, gResultsBattleSBNcgrName, gResultsBattleSBNclrName,
                         gResultsBattleSBgNscrName, 3, FindSceneFile);
    GXS_LoadBG3Char(screenMapFileSet->mChars[3]->mData, 0, screenMapFileSet->mChars[3]->mDataSize);
    GXS_LoadBGPltt(screenMapFileSet->mPalette->mData, 0, 0x140);
    GXS_LoadBG3Scr(screenMapFileSet->mScreenMaps[3]->mData, 0, screenMapFileSet->mScreenMaps[3]->mDataSize);
    remainingObjSize = GX_GetSizeOfSubOBJ();
    results = gResultsBattle;
    subCellFileSet = &results->mCellFileSets[1];
    LoadCellFileSet(subCellFileSet, gResultsBattleSNcgrName, gResultsBattleSNcerName, gResultsBattleSONclrName,
                    gResultsBattleSBnclName, gResultsBattleSBnllName, NULL, FindSceneFile);
    InitLayoutTable(heap, subCellFileSet->mCellLayout, subCellFileSet->mLabelLayout, &subCellFileSet->mCellTable);
    GXS_LoadOBJ(results->mCellFileSets[1].mChars->mData, 0, results->mCellFileSets[1].mChars->mDataSize);
    GXS_LoadOBJPltt(subCellFileSet->mPalette->mData, 0, subCellFileSet->mPalette->mDataSize);
    for (itemIndex = 0; itemIndex < subCellFileSet->mLabelLayout->mCount; itemIndex++) {
        remainingObjSize -= SetupLabelCanvas(1, heap, subCellFileSet, data_02153f00[itemIndex], remainingObjSize);
    }
    for (itemIndex = 0; itemIndex < subCellFileSet->mCellLayout->mCount; itemIndex++) {
        SetCellPriority(itemIndex, 2, subCellFileSet->mCells, subCellFileSet->mCellLayout);
    }
    for (itemIndex = 0; itemIndex < 8; itemIndex++) {
        orderUsed[itemIndex] = 0;
    }
    for (entryIndex = 0; entryIndex < 8; entryIndex++) {
        orderIndex = gResultsBattle->mEntries[entryIndex].mOrderIndex;
        value = gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mKind;
        if ((value == PLAYER_KIND_HUMAN || value == PLAYER_KIND_CPU || value == PLAYER_KIND_PEER) &&
            (gResultsBattle->mMode != 3 || gResultsBattle->mEntries[entryIndex].mScore != 0)) {
            QueueResultsBattleCharacterIcon(1, entryIndex, orderIndex + 0x30, 1);
            ResultsBattleMI_CpuClear16(entryName, 0x16);
            CopyKartEntryName(entryIndex, entryName, 0);
            PrintLabelLayoutTextNoFixedAdvance(1, orderIndex, subCellFileSet->mLabelLayout, entryName,
                                               subCellFileSet->mCellLayout, subCellFileSet->mCellTable);
            PrintResultsBattleScoreAndShowRank(entryIndex);
            SetResultsBattleEntryCellsVisible(entryIndex);
            orderUsed[orderIndex] = 1;
        }
    }
    for (itemIndex = 0; itemIndex < 8; itemIndex++) {
        if (orderUsed[itemIndex] == 0) {
            subCellFileSet->mCellTable[itemIndex + 0x48].mVisible = 0;
            subCellFileSet->mCellTable[itemIndex + 0x30].mVisible =
                subCellFileSet->mCellTable[itemIndex + 0x48].mVisible;
            subCellFileSet->mCellTable[itemIndex + 0x38].mVisible =
                subCellFileSet->mCellTable[itemIndex + 0x30].mVisible;
            subCellFileSet->mCellTable[itemIndex + 0x28].mVisible =
                subCellFileSet->mCellTable[itemIndex + 0x38].mVisible;
            subCellFileSet->mCellTable[itemIndex + 0x20].mVisible =
                subCellFileSet->mCellTable[itemIndex + 0x28].mVisible;
            subCellFileSet->mCellTable[itemIndex + 0x18].mVisible =
                subCellFileSet->mCellTable[itemIndex + 0x20].mVisible;
            subCellFileSet->mCellTable[itemIndex + 0x10].mVisible =
                subCellFileSet->mCellTable[itemIndex + 0x18].mVisible;
            subCellFileSet->mCellTable[itemIndex + 0x08].mVisible =
                subCellFileSet->mCellTable[itemIndex + 0x10].mVisible;
            subCellFileSet->mCellTable[itemIndex].mVisible = subCellFileSet->mCellTable[itemIndex + 0x08].mVisible;
        }
    }
    switch (gResultsBattle->mFileSetKind) {
        case 3:
            if (GetCurrentEntry(gResultsBattle->mOwnEntryIndex)->mPlayer.mTeamIndex == 0) {
                value = 0;
            } else {
                value = 7;
            }
            break;
        case 4:
            if (GetCurrentEntry(gResultsBattle->mOwnEntryIndex)->mPlayer.mTeamIndex == 1) {
                value = 0;
            } else {
                value = 7;
            }
            break;
        case 0:
            value = 0;
            break;
        default:
            value = 7;
            break;
    }
    InitTrophy(8, (u16) value);
}

#pragma thumb off

#pragma thumb on

void AdvanceResultsBattle(SceneNumbers *sceneNumbers) {
    CellFileSet *mainCellFileSet;
    CellFileSet *subCellFileSet;
    InputSlotIndex inputSlotIndex;
    s32 shownTimer;
    s32 cellCount;
    void *tensCellLayout;
    void *tensCells;
    void *unitsCellLayout;
    void *unitsCells;
    s32 drawIndex;
    s32 frameLimit;

    subCellFileSet = &gResultsBattle->mCellFileSets[1];
    mainCellFileSet = &gResultsBattle->mCellFileSets[0];
    if (gResultsBattle->mUseTimer != FALSE) {
        if (gResultsBattle->mTimer != 0) {
            gResultsBattle->mTimer = gResultsBattle->mTimer - 1;
            shownTimer = (gResultsBattle->mTimer + 0x3c) / 0x3c;
            mainCellFileSet->mCellTable[gResultsBattle->mTimerTensCell].mVisible = shownTimer >= 10 ? 1 : 0;
            if (gResultsBattle->mTimer == 0) {
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x51);
            } else if ((gResultsBattle->mTimer + 0x3c) % 0x3c == 0 && shownTimer <= 4) {
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x50);
            }
        } else {
            shownTimer = 0;
        }
        tensCellLayout = mainCellFileSet->mCellLayout;
        tensCells = mainCellFileSet->mCells;
        QueueCellChars(gResultsBattle->mTimerDigitCellBase + (shownTimer / 10) % 10, tensCells, mainCellFileSet->mChars,
                       tensCellLayout, 0, gResultsBattle->mTimerTensCell, tensCells, tensCellLayout);
        unitsCellLayout = mainCellFileSet->mCellLayout;
        unitsCells = mainCellFileSet->mCells;
        QueueCellChars(gResultsBattle->mTimerDigitCellBase + shownTimer % 10, unitsCells, mainCellFileSet->mChars,
                       unitsCellLayout, 0, gResultsBattle->mTimerTensCell + 1, unitsCells, unitsCellLayout);
    } else {
        mainCellFileSet->mCellTable[gResultsBattle->mTimerTensCell + 1].mVisible = 0;
        mainCellFileSet->mCellTable[gResultsBattle->mTimerTensCell].mVisible =
            mainCellFileSet->mCellTable[gResultsBattle->mTimerTensCell + 1].mVisible;
    }
    switch (gResultsBattle->mState) {
        case 0:
            gResultsBattle->mState0To2Frames = gResultsBattle->mState0To2Frames + 1;
            if (StartDataSharingSync() == 1) {
                gResultsBattle->mState = 1;
            }
            break;
        case 1:
            gResultsBattle->mState0To2Frames = gResultsBattle->mState0To2Frames + 1;
            if (FinishDataSharingSync() == 1) {
                gResultsBattle->mState = 2;
            }
            break;
        case 2:
            frameLimit = GetResultsBattleFrameLimit();
            gResultsBattle->mState0To2Frames = gResultsBattle->mState0To2Frames + 1;
            if (gResultsBattle->mState0To2Frames > frameLimit) {
                gResultsBattle->mState0To2Frames = 0;
                gResultsBattle->mState = 3;
            }
            break;
        case 3:
            switch (gResultsBattle->mMode) {
                case 0:
                    if ((u16) (gInputSlots[GetPadInputSlot()].mPressedBits & PAD_KEY_A) != 0) {
                        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 5);
                        if (sceneNumbers != NULL) {
                            sceneNumbers->mNextScene = 1;
                        }
                        gResultsBattle->mState = 7;
                    }
                    break;
                case 1:
                case 2:
                    inputSlotIndex = UNK_02175628_INDEX_8;
                    if ((u16) (gInputSlots[inputSlotIndex].mPressedBits & PAD_KEY_A) != 0) {
                        StartResultsBattleChoices();
                        gResultsBattle->mState = 4;
                        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 5);
                    }
                    break;
                case 3:
                    if (IsResultsBattleTimerRunOut() != 0) {
                        SetWiFiSessionOwnContinueChoice(1);
                        gResultsBattle->mState = 5;
                    } else if ((u16) (gInputSlots[GetPadInputSlot()].mPressedBits & PAD_KEY_A) != 0 ||
                               IsResultsBattleTimerBelow300() != 0) {
                        StartResultsBattleChoices();
                        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 5);
                        gResultsBattle->mState = 4;
                    }
                    break;
            }
            break;
        case 4:
            switch (gResultsBattle->mMode) {
                case 1:
                case 2:
                    if (GetSelectChoisesDone() != 0) {
                        switch (GetSelectChoisesIndex()) {
                            case 0:
                                if (gStartupWork->mMultiSimple != 0) {
                                    gMenuShared->mWLMenuKind = 3;
                                    gMenuShared->mMenuEntryKind = 4;
                                    if (sceneNumbers != NULL) {
                                        sceneNumbers->mNextScene = 6;
                                    }
                                } else {
                                    gMenuShared->mMenuEntryKind = 4;
                                    if (sceneNumbers != NULL) {
                                        sceneNumbers->mNextScene = 1;
                                    }
                                }
                                gResultsBattle->mState = 7;
                                break;
                            case 1:
                                gConnectionWork->mFlags = gConnectionWork->mFlags | CONNECTION_FLAG_ENDING;
                                gResultsBattle->mState = 6;
                                break;
                            case -1:
                                gResultsBattle->mState = 3;
                                break;
                        }
                        RequestSelectChoisesState0();
                    }
                    break;
                case 3:
                    if (GetSelectChoisesDone() != 0 || IsResultsBattleTimerRunOut() != 0) {
                        switch (GetSelectChoisesIndex()) {
                            case 0:
                                gResultsBattle->mState = 5;
                                SetWiFiSessionOwnContinueChoice(1);
                                break;
                            case 1:
                                SetWiFiSessionOwnContinueChoice(0);
                                gMenuShared->mWiFiMenuStartKind = 1;
                                if (sceneNumbers != NULL) {
                                    sceneNumbers->mNextScene = 0xc;
                                }
                                gResultsBattle->mState = 7;
                                break;
                            case -1:
                                gResultsBattle->mState = 3;
                                break;
                        }
                        RequestSelectChoisesState0();
                    }
                    break;
            }
            break;
        case 5:
            if (GetWiFiSessionContinueResult() != 0) {
                switch (GetWiFiSessionContinueResult()) {
                    case 1:
                        gMenuShared->mWiFiMenuStartKind = 2;
                        break;
                    case 2:
                        gMenuShared->mWiFiMenuStartKind = 1;
                        break;
                }
                if (sceneNumbers != NULL) {
                    sceneNumbers->mNextScene = 0xc;
                }
                gResultsBattle->mState = 7;
            }
            break;
        case 6:
            if (AdvanceConnectionEndStopOnError() == 1) {
                if (sceneNumbers != NULL) {
                    sceneNumbers->mNextScene = 0;
                }
                gResultsBattle->mState = 7;
            }
            break;
    }
    AdvanceTrophy();
    DrawTrophy();
    for (drawIndex = 0; drawIndex < 2; drawIndex++) {
        DrawLayoutTable(gResultsBattle->mCellFileSets[drawIndex].mCellLayout,
                        gResultsBattle->mCellFileSets[drawIndex].mCells,
                        gResultsBattle->mCellFileSets[drawIndex].mLabelLayout, gResultsBattle->mOamLists[drawIndex],
                        gResultsBattle->mCellFileSets[drawIndex].mCellTable);
    }
    cellCount = subCellFileSet->mCellLayout->mCount;
    for (drawIndex = 0; drawIndex < 8; drawIndex++) {
        subCellFileSet->mCellTable[drawIndex + cellCount].mOffsetY =
            subCellFileSet->mCellTable[drawIndex + cellCount].mOffsetY + 1;
        SetLabelPaletteIndex(drawIndex, 0xe, subCellFileSet->mLabelLayout, subCellFileSet->mCellTable,
                             subCellFileSet->mCellLayout);
        DrawLayoutTableEntry(drawIndex + cellCount, subCellFileSet->mCellLayout, subCellFileSet->mCells,
                             subCellFileSet->mLabelLayout, gResultsBattle->mOamLists[1], subCellFileSet->mCellTable);
        SetLabelPaletteIndex(drawIndex, 0xf, subCellFileSet->mLabelLayout, subCellFileSet->mCellTable,
                             subCellFileSet->mCellLayout);
        subCellFileSet->mCellTable[drawIndex + cellCount].mOffsetY =
            subCellFileSet->mCellTable[drawIndex + cellCount].mOffsetY - 1;
    }
    AdvanceSceneText();
}

void ReleaseResultsBattle(void) {
    gMenuShared->mRaceSetupRequested = 1;
    ReleaseSceneText();
}

#pragma thumb off

#pragma thumb on
void ResultsBattleWriteSceneTextRegistersWrapper(void) {
    u32 unused;
    WriteSceneTextRegisters();
}
#pragma thumb off
