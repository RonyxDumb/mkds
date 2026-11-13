#include "Main/Menu/select_race_rule_state.h"

#include "Main/Menu/player_entry_list.h"
#include "Main/System/heap.h"
#include "Main/Scene/display_settings.h"
#include "Main/Menu/picks_holder.h"
#include "Main/Menu/select_return.h"
#include "Main/Graphics/palette_blend.h"
#include "Main/Menu/data_0215c000.h"
#include "Main/Menu/data_02175628.h"
#include "Main/Menu/data_02175000.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "player.h"
#include "Main/Menu/data_0217d000.h"
#include "code_0212c7a0.h"
#include "stream.h"
#include "code_0212c9d4.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "code_0212d214.h"
#include "Main/Graphics/oam.h"
#include "code_0212df7c.h"
#include "Main/Menu/select_cup_m.h"
#include "Main/Menu/data_0216d000.h"
#include "Main/MapObjects/data_0217a000.h"
#include "code_0202056c.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Menu/menu_screen_switch.h"
#include "Main/Menu/wait_load.h"
#include "Main/Menu/select_race_rule_load.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "code_02148950.h"
#include "registers.h"
#include "Main/Race/race_setup.h"
#include "Main/System/result_archive_path.h"
#include "Main/Menu/data_02174000.h"
#include "Main/System/interpolation_value.h"
#include "Main/System/heap_call.h"
#include "code_02022aa8.h"
#include "Main/Graphics/cell_file_set.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Menu/multi_select_member_group.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/Save/buddy_record_time.h"
#include "g2d_CellTransferManager.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/code_02196d58.h"
#include "Main/Graphics/text_draw.h"
#include "gfd_VramTransferManager.h"
#include "Main/Sound/sound_system.h"
#include "Main/System/init_after_startup.h"

#pragma thumb on

const u16 gSelectRaceRuleTeamCellsPlain[2] = {0x23, 0x26};
const u16 gSelectRaceRuleTeamCellsHighlighted[2] = {0x22, 0x25};
const u16 gSelectRaceRuleRow4ValueMessageIndices[3] = {0xa, 9, 9};
const u16 gSelectRaceRuleRow3ValueMessageIndices[3] = {0x11, 0x12, 0x13};
const u16 gSelectRaceRuleRow2ValueMessageIndices[3] = {0xe, 0xf, 0x10};
const u16 gSelectRaceRuleCountTeamChangeCells[2][2] = {{0x20, 0x21}, {0x24, 0x27}};
const u16 gSelectRaceRuleRow1ValueMessageIndices[4] = {0xa, 0xb, 0xc, 0xd};
const u32 gSelectRaceRuleTeamsFromSetupCopy[2] = {0, 1};
const u32 gSelectRaceRuleTeamsToSetupCopy[2] = {0, 1};
const u16 gSelectRaceRuleRow0ValueMessageIndices[4] = {5, 6, 7, 8};
const u16 gSelectRaceRuleRowMessageIndices[6] = {0, 1, 2, 3, 4, 0};
const u16 gSelectRaceRuleRowValueCounts[6] = {4, 4, 3, 3, 3, 0};
const u32 gSelectRaceRuleCourseListModeValues[3] = {2, 0, 1};
const u32 gSelectRaceRuleEngineIndexValues[3] = {0, 1, 2};
const u32 gSelectRaceRuleRuleKindValues[3] = {2, 0, 1};
const u32 gSelectRaceRuleCourseListModes[3] = {1, 2, 0};
const u32 gSelectRaceRuleRuleKinds[3] = {1, 2, 0};
const u32 gSelectRaceRuleCpuDifficulties[4] = {0, 1, 2, 3};
const u32 gSelectRaceRuleCpuDifficultyValues[4] = {0, 1, 2, 3};
const u32 gSelectRaceRuleEngineIndices[4] = {0, 1, 2, 1};
const SelectRaceRuleRowEntries gSelectRaceRuleRowEntries[5] = {{{0, 5}}, {{1, 6}}, {{2, 7}}, {{3, 9}}, {{4, 0xb}}};
const u16 gSelectRaceRuleLabelWidths[5][2] = {{0x60, 0x64}, {0x58, 0x64}, {0x58, 0x64}, {0x58, 0x96}, {0x58, 0x64}};
const u16 gSelectRaceRuleLabelHeights[5][2] = {{0xd, 0xf}, {0xd, 0xf}, {0xd, 0xf}, {0xd, 0xf}, {0xd, 0xf}};
const u16 gSelectRaceRuleStepCellsHighlighted[5][2] = {{0, 5}, {1, 6}, {2, 7}, {3, 8}, {4, 9}};
const u32 gSelectRaceRuleRowRectRows[5] = {0, 1, 2, 3, 4};
const u32 gSelectRaceRuleNextRectRows[5] = {0, 1, 2, 3, 4};
char gSelectRaceRuleSBnclPath[] = "common/select_race_rule_s.bncl";
const char *gSelectRaceRuleSBnclName = gSelectRaceRuleSBnclPath;
char gSelectRaceRuleSBNcgrPath[] = "common/select_race_rule_s_b.ncgr";
const char *gSelectRaceRuleSBNcgrName = gSelectRaceRuleSBNcgrPath;
char gSelectRaceRuleMultiSimpleSNscrPath[] = "common/select_race_rule_multi_simple_s.nscr";
const char *gSelectRaceRuleSNcgrName = gSelectRaceRuleSNcgrPath;
char gSelectRaceRuleMultiSimpleSBnclPath[] = "common/select_race_rule_multi_simple_s.bncl";
const char *gSelectRaceRuleMultiSimpleSBnblName = gSelectRaceRuleMultiSimpleSBnblPath;
char gSelectRaceRuleSBNclrPath[] = "common/select_race_rule_s_b.nclr";
const char *gSelectRaceRuleSONclrName = gSelectRaceRuleSONclrPath;
char gSelectRaceRuleSBnllPath[] = "common/select_race_rule_s.bnll";
const char *gSelectRaceRuleSBNclrName = gSelectRaceRuleSBNclrPath;
char gSelectRaceRuleSONclrPath[] = "common/select_race_rule_s_o.nclr";
const char *gSelectRaceRuleMultiSimpleSNscrName = gSelectRaceRuleMultiSimpleSNscrPath;
char gSelectRaceRuleSMenuNscrPath[] = "common/select_race_rule_s_menu.nscr";
const char *gSelectRaceRuleSBnllName = gSelectRaceRuleSBnllPath;
char gSelectRaceRuleSBnblPath[] = "common/select_race_rule_s.bnbl";
const char *gSelectRaceRuleSBnblName = gSelectRaceRuleSBnblPath;
char gSelectRaceRuleSNcgrPath[] = "common/select_race_rule_s.nce.ncgr";
const char *gSelectRaceRuleMultiSimpleSBnllName = gSelectRaceRuleMultiSimpleSBnllPath;
char gSelectRaceRuleMultiSimpleSBnblPath[] = "common/select_race_rule_multi_simple_s.bnbl";
const char *gSelectRaceRuleSMenuNscrName = gSelectRaceRuleSMenuNscrPath;
char gSelectRaceRuleMultiSimpleSBnllPath[] = "common/select_race_rule_multi_simple_s.bnll";
const char *gSelectRaceRuleMultiSimpleSBnclName = gSelectRaceRuleMultiSimpleSBnclPath;
char gSelectRaceRuleSNcerPath[] = "common/select_race_rule_s.nce.ncer";
const char *gSelectRaceRuleMultiSimpleSBNcgrName = gSelectRaceRuleMultiSimpleSBNcgrPath;
char gSelectRaceRuleMultiSimpleSBNcgrPath[] = "common/select_race_rule_multi_simple_s_b.ncgr";
const char *gSelectRaceRuleSNcerName = gSelectRaceRuleSNcerPath;
const u16 *gSelectRaceRuleValueMessageIndices[5] = {
    gSelectRaceRuleRow0ValueMessageIndices, gSelectRaceRuleRow1ValueMessageIndices,
    gSelectRaceRuleRow2ValueMessageIndices, gSelectRaceRuleRow3ValueMessageIndices,
    gSelectRaceRuleRow4ValueMessageIndices};
SelectRaceRule *gSelectRaceRule;

// Copies the rectangle of row b; which table is read depends on the mode's screen file.
void LookupSelectRaceRuleNscrRect(SelectRaceRuleNscrRect *outRect, s32 row) {
    SelectRaceRuleNscrRect rect;

    if (gSelectRaceRule->mMode == SELECT_RACE_RULE_MODE_BATTLE_MULTI_SIMPLE) {
        rect = gSelectRaceRuleMultiSimpleNscrRects[row];
    } else {
        rect = gSelectRaceRuleSMenuNscrRects[row];
    }
    *outRect = rect;
}

void AdvanceSelectRaceRuleHighlight(void) {
    SelectRaceRuleNscrRect nscrRect;
    s32 rowIndex;

    for (rowIndex = 0; rowIndex < 5; rowIndex++) {
        if (gSelectRaceRule->mOnButton == 0 && gSelectRaceRule->mRow == rowIndex) {
            SetLabelPaletteIndex(gSelectRaceRuleRowEntries[rowIndex].mEntryIndices[0], 1, gSelectRaceRule->mBnll,
                                 gSelectRaceRule->mTable, gSelectRaceRule->mBncl);
        } else {
            SetLabelPaletteIndex(gSelectRaceRuleRowEntries[rowIndex].mEntryIndices[0], 0, gSelectRaceRule->mBnll,
                                 gSelectRaceRule->mTable, gSelectRaceRule->mBncl);
        }
    }
    if (gStartupWork->mConnectionKind != 2) {
        if (gSelectRaceRule->mOnButton != 0 && gSelectRaceRule->mButtonHighlightShown != 0) {
            gSelectRaceRule->mTable[0x28].mVisible = 0;
            gSelectRaceRule->mTable[0x29].mVisible = 1;
            SetLabelPaletteIndex(0xd, 1, gSelectRaceRule->mBnll, gSelectRaceRule->mTable, gSelectRaceRule->mBncl);
        } else {
            gSelectRaceRule->mTable[0x28].mVisible = 1;
            gSelectRaceRule->mTable[0x29].mVisible = 0;
            SetLabelPaletteIndex(0xd, 0, gSelectRaceRule->mBnll, gSelectRaceRule->mTable, gSelectRaceRule->mBncl);
        }
    }
    if (gSelectRaceRule->mPrevOnButton == gSelectRaceRule->mOnButton &&
        gSelectRaceRule->mPrevRow == gSelectRaceRule->mRow) {
        return;
    }
    for (rowIndex = 0; rowIndex < 5; rowIndex++) {
        LookupSelectRaceRuleNscrRect(&nscrRect, rowIndex);
        SetScreenMapBlockTopBits(gSelectRaceRule->mNscr->mData, nscrRect.mFirstColumn, nscrRect.mFirstRow,
                                 nscrRect.mColumnCount, nscrRect.mRowCount, nscrRect.mTopBits);
    }
    if (gSelectRaceRule->mOnButton == 0) {
        LookupSelectRaceRuleNscrRect(&nscrRect, gSelectRaceRule->mRow);
        SetScreenMapBlockTopBits(gSelectRaceRule->mNscr->mData, nscrRect.mFirstColumn, nscrRect.mFirstRow,
                                 nscrRect.mColumnCount, nscrRect.mRowCount, nscrRect.mHighlightedTopBits);
    }
    NNS_GfdRegisterNewVramTransferTask(0x1b, 0, gSelectRaceRule->mNscr->mData, 0x600);
}

// Stores the count, kept from 1 to 10, and draws it.
void SetAndPrintSelectRaceRuleWinCount(s16 count) {
    u16 numberText[0x40];
    u16 text[0x40];

    if (count < 1) {
        count = 1;
    }
    if (count > 0xa) {
        count = 0xa;
    }
    gSelectRaceRule->mWinCount = count;
    FormatFullWidthNumber(gSelectRaceRule->mWinCount, text);
    if (gStartupWork->mConnectionKind != 2) {
        PrintLabelLayoutTextNoFixedAdvance(
            1, 9, gSelectRaceRule->mBnll,
            GetBmgEntry(gSelectRaceRule->mRuleMessages, gSelectRaceRuleValueMessageIndices[3][SELECT_RACE_RULE_WIN]),
            gSelectRaceRule->mBncl, gSelectRaceRule->mTable);
        PrintLabelLayoutTextFixedAdvance(1, 8, gSelectRaceRule->mBnll, text, gSelectRaceRule->mBncl,
                                         gSelectRaceRule->mTable, 0xb);
    } else {
        FormatFullWidthNumber(gSelectRaceRule->mWinCount, numberText);
        FormatMessageWithText(numberText, GetBmgEntry(gSelectRaceRule->mRuleMessages, 0x16), text, 0x80);
        PrintLabelLayoutTextNoFixedAdvance(1, 0xa, gSelectRaceRule->mBnll, text, gSelectRaceRule->mBncl,
                                           gSelectRaceRule->mTable);
    }
}

// Stores the count, kept from 1 to 0x20, and draws it.
void SetAndPrintSelectRaceRuleRaceCount(s16 count) {
    u16 numberText[0x40];
    u16 text[0x40];

    if (count < 1) {
        count = 1;
    }
    if (count > 0x20) {
        count = 0x20;
    }
    gSelectRaceRule->mRaceCount = count;
    FormatFullWidthNumber(gSelectRaceRule->mRaceCount, text);
    if (gStartupWork->mConnectionKind != 2) {
        PrintLabelLayoutTextNoFixedAdvance(
            1, 9, gSelectRaceRule->mBnll,
            GetBmgEntry(gSelectRaceRule->mRuleMessages, gSelectRaceRuleValueMessageIndices[3][SELECT_RACE_RULE_RACE]),
            gSelectRaceRule->mBncl, gSelectRaceRule->mTable);
        PrintLabelLayoutTextFixedAdvance(1, 8, gSelectRaceRule->mBnll, text, gSelectRaceRule->mBncl,
                                         gSelectRaceRule->mTable, 0xb);
    } else {
        FormatFullWidthNumber(gSelectRaceRule->mRaceCount, numberText);
        FormatMessageWithText(numberText, GetBmgEntry(gSelectRaceRule->mRuleMessages, 0x17), text, 0x80);
        PrintLabelLayoutTextNoFixedAdvance(1, 0xa, gSelectRaceRule->mBnll, text, gSelectRaceRule->mBncl,
                                           gSelectRaceRule->mTable);
    }
}

void AdvanceSelectRaceRuleValueObjects(void) {
    u16 cellEntryCount = gSelectRaceRule->mBncl->mCount;

    if (gStartupWork->mConnectionKind != 2) {
        switch (gSelectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_RULE_KIND]) {
            case SELECT_RACE_RULE_WIN:
            case SELECT_RACE_RULE_RACE:
                gSelectRaceRule->mTable[cellEntryCount + 9].mVisible = 1;
                gSelectRaceRule->mTable[cellEntryCount + 10].mVisible = 0;
                gSelectRaceRule->mTable[cellEntryCount + 8].mVisible = 1;
                break;
            case SELECT_RACE_RULE_FREE:
                gSelectRaceRule->mTable[cellEntryCount + 9].mVisible = 0;
                gSelectRaceRule->mTable[cellEntryCount + 10].mVisible = 1;
                gSelectRaceRule->mTable[cellEntryCount + 8].mVisible = 0;
                break;
        }
        switch (gSelectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_TEAMS]) {
            case 0:
            case 1:
                gSelectRaceRule->mTable[cellEntryCount + 11].mVisible = 1;
                gSelectRaceRule->mTable[cellEntryCount + 12].mVisible = 0;
                break;
            case 2:
                gSelectRaceRule->mTable[cellEntryCount + 11].mVisible = 0;
                gSelectRaceRule->mTable[cellEntryCount + 12].mVisible = 1;
                break;
        }
    } else {
        gSelectRaceRule->mTable[0x1e].mVisible = 0;
        gSelectRaceRule->mTable[0x1f].mVisible = 0;
        switch (gSelectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_RULE_KIND]) {
            case SELECT_RACE_RULE_WIN:
                gSelectRaceRule->mTable[cellEntryCount + 10].mVisible = 1;
                SetAndPrintSelectRaceRuleWinCount(gSelectRaceRule->mWinCount);
                break;
            case SELECT_RACE_RULE_RACE:
                gSelectRaceRule->mTable[cellEntryCount + 10].mVisible = 1;
                SetAndPrintSelectRaceRuleRaceCount(gSelectRaceRule->mRaceCount);
                break;
            case SELECT_RACE_RULE_FREE:
                gSelectRaceRule->mTable[cellEntryCount + 10].mVisible = 1;
                PrintLabelLayoutTextNoFixedAdvance(
                    1, 0xa, gSelectRaceRule->mBnll,
                    GetBmgEntry(gSelectRaceRule->mRuleMessages,
                                gSelectRaceRuleValueMessageIndices[3][SELECT_RACE_RULE_FREE]),
                    gSelectRaceRule->mBncl, gSelectRaceRule->mTable);
                break;
        }
        switch (gSelectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_TEAMS]) {
            case 0:
            case 1:
                gSelectRaceRule->mTable[cellEntryCount + 11].mVisible = 1;
                gSelectRaceRule->mTable[cellEntryCount + 12].mVisible = 0;
                break;
            case 2:
                gSelectRaceRule->mTable[cellEntryCount + 11].mVisible = 0;
                gSelectRaceRule->mTable[cellEntryCount + 12].mVisible = 1;
                break;
        }
    }
    if (gSelectRaceRule->mMode == SELECT_RACE_RULE_MODE_BATTLE_MULTI_SIMPLE) {
        gSelectRaceRule
            ->mTable[cellEntryCount + gSelectRaceRuleRowEntries[SELECT_RACE_RULE_ROW_ENGINE].mEntryIndices[1]]
            .mVisible = 0;
        gSelectRaceRule
            ->mTable[cellEntryCount + gSelectRaceRuleRowEntries[SELECT_RACE_RULE_ROW_COURSE_LIST].mEntryIndices[1]]
            .mVisible = 0;
    }
}

u16 GetSelectRaceRuleHumanCount(void) {
    return gSelectRaceRule->mTeamHumanCounts[0] + gSelectRaceRule->mTeamHumanCounts[1];
}

#pragma thumb off

#pragma thumb on

u16 GetSelectRaceRuleCpuCount(void) {
    SelectRaceRule *selectRaceRule;
    selectRaceRule = gSelectRaceRule;
    if (selectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_CPU_DIFFICULTY] == 0) {
        return 0;
    }
    return selectRaceRule->mTeamNonHumanCounts[0] + selectRaceRule->mTeamNonHumanCounts[1];
}

#pragma thumb off

#pragma thumb on

// Moves the highlight to the next row, then onto the button, then back to row 0; a row with a zero table entry is
// skipped.
void MoveSelectRaceRuleRowNext(void) {
    u32 value = 1;
    u16 cellEntryCount = gSelectRaceRule->mBncl->mCount;
    BootInfo *bootInfo;

    if (gSelectRaceRule->mOnButton != 0) {
        gSelectRaceRule->mRow = SELECT_RACE_RULE_ROW_ENGINE;
        gSelectRaceRule->mOnButton = 0;
        if (gSelectRaceRule->mTable[cellEntryCount + gSelectRaceRuleRowEntries[gSelectRaceRule->mRow].mEntryIndices[0]]
                    .mVisible == 0 ||
            (GetSelectRaceRuleHumanCount() == 8 && gSelectRaceRule->mRow == SELECT_RACE_RULE_ROW_CPU_DIFFICULTY)) {
            value = 0;
            MoveSelectRaceRuleRowNext();
        }
    } else {
        gSelectRaceRule->mRow++;
        if (gSelectRaceRule->mRow >= 5) {
            gSelectRaceRule->mRow--;
            gSelectRaceRule->mOnButton = value;
            bootInfo = gBootInfo;
            if (bootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
                ResetPaletteBlendCycle();
            }
        } else if (gSelectRaceRule
                           ->mTable[cellEntryCount + gSelectRaceRuleRowEntries[gSelectRaceRule->mRow].mEntryIndices[0]]
                           .mVisible == 0 ||
                   (GetSelectRaceRuleHumanCount() == 8 &&
                    gSelectRaceRule->mRow == SELECT_RACE_RULE_ROW_CPU_DIFFICULTY)) {
            value = 0;
            MoveSelectRaceRuleRowNext();
        }
    }
    if (value != 0) {
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0);
    }
}

// Moves the highlight to the previous row, then onto the button, then to row 4; a row with a zero table entry is
// skipped.
void MoveSelectRaceRuleRowPrevious(void) {
    u32 value = 1;
    u16 cellEntryCount = gSelectRaceRule->mBncl->mCount;
    BootInfo *bootInfo;

    if (gSelectRaceRule->mOnButton != 0) {
        gSelectRaceRule->mRow = SELECT_RACE_RULE_ROW_TEAMS;
        gSelectRaceRule->mOnButton = 0;
        if (gSelectRaceRule->mTable[cellEntryCount + gSelectRaceRuleRowEntries[gSelectRaceRule->mRow].mEntryIndices[0]]
                    .mVisible == 0 ||
            (GetSelectRaceRuleHumanCount() == 8 && gSelectRaceRule->mRow == SELECT_RACE_RULE_ROW_CPU_DIFFICULTY)) {
            value = 0;
            MoveSelectRaceRuleRowPrevious();
        }
    } else {
        gSelectRaceRule->mRow--;
        if (gSelectRaceRule->mRow < 0) {
            gSelectRaceRule->mRow++;
            gSelectRaceRule->mOnButton = value;
            bootInfo = gBootInfo;
            if (bootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
                ResetPaletteBlendCycle();
            }
        } else if (gSelectRaceRule
                           ->mTable[cellEntryCount + gSelectRaceRuleRowEntries[gSelectRaceRule->mRow].mEntryIndices[0]]
                           .mVisible == 0 ||
                   (GetSelectRaceRuleHumanCount() == 8 &&
                    gSelectRaceRule->mRow == SELECT_RACE_RULE_ROW_CPU_DIFFICULTY)) {
            value = 0;
            MoveSelectRaceRuleRowPrevious();
        }
    }
    if (value != 0) {
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0);
    }
}

#pragma thumb off

#pragma thumb on

u16 GetSelectRaceRuleTeamPlayerCount(s32 team) {
    SelectRaceRule *selectRaceRule;
    selectRaceRule = gSelectRaceRule;
    if (selectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_CPU_DIFFICULTY] == 0) {
        return selectRaceRule->mTeamHumanCounts[team];
    }
    return selectRaceRule->mTeamHumanCounts[team] + selectRaceRule->mTeamNonHumanCounts[team];
}

BOOL IsPlayerTeamPlayerCountNotOne(s32 entryIndex) {
    if (GetSelectRaceRuleTeamPlayerCount(gSelectRaceRule->mPlayerTeamIndices[entryIndex]) != 1) {
        return 1;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on

void SetSelectRaceRulePlayerTeam(u16 entryIndex, u32 team) {
    gSelectRaceRule->mPlayerTeamIndices[entryIndex] = team;
    SetEntryTeamIndex(entryIndex, gSelectRaceRuleTeamsToSetupCopy[team]);
}

#pragma thumb off

#pragma thumb on

BOOL IsSelectRaceRuleEntryHuman(u16 entryIndex) {
    u32 humanCount;
    humanCount = GetSelectRaceRuleHumanCount();
    if (humanCount > entryIndex) {
        return 1;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on

u32 GetOtherTeamIndex(u32 team) {
    u32 otherTeam = 2;

    switch (team) {
        case 0:
            otherTeam = 1;
            break;
        case 1:
            otherTeam = 0;
            break;
    }
    return otherTeam;
}

#pragma thumb off

#pragma thumb on

// Returns the team with more players, or 2 when they are equal or row 1 is 0.
u32 GetLargerTeamIndex(void) {
    u32 team0PlayerCount;
    u32 team1PlayerCount;
    if (gSelectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_CPU_DIFFICULTY] != 0) {
        team0PlayerCount = GetSelectRaceRuleTeamPlayerCount(0);
        team1PlayerCount = GetSelectRaceRuleTeamPlayerCount(1);
        if (team0PlayerCount > team1PlayerCount) {
            return 0;
        }
        team0PlayerCount = GetSelectRaceRuleTeamPlayerCount(0);
        team1PlayerCount = GetSelectRaceRuleTeamPlayerCount(1);
        if (team0PlayerCount < team1PlayerCount) {
            return 1;
        }
    }
    return 2;
}

#pragma thumb off

#pragma thumb on

// Picks a random CPU entry; FALSE when there are none.
BOOL PickSelectRaceRuleCpuEntry(u16 *entryOut) {
    RandomState64 *randomState;
    u32 cpuCount;
    u32 humanCount;
    if (GetSelectRaceRuleCpuCount() == 0) {
        *entryOut = 8;
        return FALSE;
    }
    switch (gSelectRaceRule->mMode) {
        case SELECT_RACE_RULE_MODE_VS_NO_CONNECTION:
        case SELECT_RACE_RULE_MODE_BATTLE_NO_CONNECTION:
            humanCount = GetSelectRaceRuleHumanCount();
            *entryOut = humanCount + NextRandomBelowByConnectionKind(GetSelectRaceRuleCpuCount());
            break;
        case SELECT_RACE_RULE_MODE_VS_MULTI_SIMPLE:
        case SELECT_RACE_RULE_MODE_BATTLE_MULTI_SIMPLE:
        case SELECT_RACE_RULE_MODE_VS_MULTI:
        case SELECT_RACE_RULE_MODE_BATTLE_MULTI:
            randomState = &gConnectionWork->mRandomState;
            cpuCount = GetSelectRaceRuleCpuCount();
            randomState->mValue =
                randomState->mIncrement + (u64) ((s64) randomState->mMultiplier * (s64) randomState->mValue);
            *entryOut = GetSelectRaceRuleHumanCount() +
                        (cpuCount == 0 ? (u32) (randomState->mValue >> 32)
                                       : (u32) (((s64) (u32) (randomState->mValue >> 32) * (s64) cpuCount) >> 32));
            break;
    }
    return TRUE;
}

// Moves a player to a team unless it is alone in its team, then moves another player to even the teams.
void ChangeSelectRaceRulePlayerTeam(u16 entryIndex, u32 teamIndex) {
    u16 cpuEntry;
    u16 ownIndex;
    cpuEntry = 8;
    if (teamIndex == gSelectRaceRule->mPlayerTeamIndices[entryIndex]) {
        return;
    }
    if (IsPlayerTeamPlayerCountNotOne(entryIndex) == 0) {
        ownIndex = gConnectionWork->mConnectionMode == CONNECTION_MODE_CHILD ? gConnectionWork->mOwnIndex : 0;
        if (entryIndex == gConnectionWork->mParticipantPosByIndex[ownIndex].mEntryIndex) {
            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x16);
        }
        return;
    }
    SetSelectRaceRulePlayerTeam(entryIndex, teamIndex);
    if (IsSelectRaceRuleEntryHuman(entryIndex) != 0) {
        gSelectRaceRule->mTeamHumanCounts[teamIndex]++;
        gSelectRaceRule->mTeamHumanCounts[GetOtherTeamIndex(teamIndex)]--;
    } else {
        gSelectRaceRule->mTeamNonHumanCounts[teamIndex]++;
        gSelectRaceRule->mTeamNonHumanCounts[GetOtherTeamIndex(teamIndex)]--;
    }
    teamIndex = GetLargerTeamIndex();
    if (teamIndex != 2 && gSelectRaceRule->mTeamNonHumanCounts[teamIndex] != 0) {
        PickSelectRaceRuleCpuEntry(&cpuEntry);
        while (teamIndex != gSelectRaceRule->mPlayerTeamIndices[cpuEntry]) {
            PickSelectRaceRuleCpuEntry(&cpuEntry);
        }
        ChangeSelectRaceRulePlayerTeam(cpuEntry, GetOtherTeamIndex(teamIndex));
    }
    ownIndex = gConnectionWork->mConnectionMode == CONNECTION_MODE_CHILD ? gConnectionWork->mOwnIndex : 0;
    if (entryIndex == gConnectionWork->mParticipantPosByIndex[ownIndex].mEntryIndex) {
        switch (gSelectRaceRule->mPlayerTeamIndices[entryIndex]) {
            case 0:
                gSelectRaceRule->mCountTeamChangeTimers[1][0] = 6;
                break;
            case 1:
                gSelectRaceRule->mCountTeamChangeTimers[1][1] = 6;
                break;
        }
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 4);
    }
}

void AssignSelectRaceRuleHumanTeams(void) {
    s32 team;
    s32 entryIndex;
    u16 humanCount;
    RandomState64 *randomState;
    team = 2;
    humanCount = GetSelectRaceRuleHumanCount();
    gSelectRaceRule->mTeamHumanCounts[0] = 0;
    gSelectRaceRule->mTeamHumanCounts[1] = 0;
    for (entryIndex = 0; entryIndex < humanCount; entryIndex++) {
        switch (gSelectRaceRule->mMode) {
            case SELECT_RACE_RULE_MODE_VS_NO_CONNECTION:
            case SELECT_RACE_RULE_MODE_BATTLE_NO_CONNECTION:
                team = NextRandomBelowByConnectionKind(2);
                break;
            case SELECT_RACE_RULE_MODE_VS_MULTI_SIMPLE:
            case SELECT_RACE_RULE_MODE_BATTLE_MULTI_SIMPLE:
            case SELECT_RACE_RULE_MODE_VS_MULTI:
            case SELECT_RACE_RULE_MODE_BATTLE_MULTI:
                randomState = &gConnectionWork->mRandomState;
                randomState->mValue =
                    randomState->mIncrement + (u64) ((s64) randomState->mMultiplier * (s64) randomState->mValue);
                team = ((u64) (u32) (randomState->mValue >> 32) * 2) >> 32;
                break;
        }
        if (humanCount / 2 <= gSelectRaceRule->mTeamHumanCounts[team]) {
            team = GetOtherTeamIndex(team);
        }
        SetSelectRaceRulePlayerTeam(entryIndex, team);
        gSelectRaceRule->mTeamHumanCounts[team]++;
    }
}

void AssignSelectRaceRuleNonHumanTeams(void) {
    s32 team;
    s32 entryIndex;
    RandomState64 *randomState;
    team = 2;
    GetSelectRaceRuleHumanCount();
    gSelectRaceRule->mTeamNonHumanCounts[0] = 0;
    gSelectRaceRule->mTeamNonHumanCounts[1] = 0;
    for (entryIndex = GetSelectRaceRuleHumanCount(); entryIndex < 8; entryIndex++) {
        switch (gSelectRaceRule->mMode) {
            case SELECT_RACE_RULE_MODE_VS_NO_CONNECTION:
            case SELECT_RACE_RULE_MODE_BATTLE_NO_CONNECTION:
                team = NextRandomBelowByConnectionKind(2);
                break;
            case SELECT_RACE_RULE_MODE_VS_MULTI_SIMPLE:
            case SELECT_RACE_RULE_MODE_BATTLE_MULTI_SIMPLE:
            case SELECT_RACE_RULE_MODE_VS_MULTI:
            case SELECT_RACE_RULE_MODE_BATTLE_MULTI:
                randomState = &gConnectionWork->mRandomState;
                randomState->mValue =
                    randomState->mIncrement + (u64) ((s64) randomState->mMultiplier * (s64) randomState->mValue);
                team = ((u64) (u32) (randomState->mValue >> 32) * 2) >> 32;
                break;
        }
        if (GetSelectRaceRuleTeamPlayerCount(team) >= 4) {
            team = GetOtherTeamIndex(team);
        }
        SetSelectRaceRulePlayerTeam(entryIndex, team);
        gSelectRaceRule->mTeamNonHumanCounts[team]++;
    }
}

// FALSE for a value of the highlighted row that the current mode does not offer.
BOOL IsSelectRaceRuleValueAllowed(void) {
    SelectRaceRule *selectRaceRule;
    selectRaceRule = gSelectRaceRule;
    if (selectRaceRule->mRow == SELECT_RACE_RULE_ROW_ENGINE &&
        selectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_ENGINE] == 3 && IsBitSetInAnyParticipant(0x10) == 0) {
        return FALSE;
    }
    selectRaceRule = gSelectRaceRule;
    switch (selectRaceRule->mMode) {
        case SELECT_RACE_RULE_MODE_VS_NO_CONNECTION:
            if (selectRaceRule->mRow == SELECT_RACE_RULE_ROW_CPU_DIFFICULTY &&
                selectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_CPU_DIFFICULTY] == 0) {
                return FALSE;
            }
            if (selectRaceRule->mRow == SELECT_RACE_RULE_ROW_TEAMS &&
                selectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_TEAMS] == 2) {
                return FALSE;
            }
            break;
        case SELECT_RACE_RULE_MODE_BATTLE_NO_CONNECTION:
            if (selectRaceRule->mRow == SELECT_RACE_RULE_ROW_CPU_DIFFICULTY &&
                selectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_CPU_DIFFICULTY] == 0) {
                return FALSE;
            }
            if (selectRaceRule->mRow == SELECT_RACE_RULE_ROW_RULE_KIND &&
                selectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_RULE_KIND] == SELECT_RACE_RULE_RACE) {
                return FALSE;
            }
            if (selectRaceRule->mRow == SELECT_RACE_RULE_ROW_TEAMS &&
                selectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_TEAMS] == 2) {
                return FALSE;
            }
            break;
        case SELECT_RACE_RULE_MODE_VS_MULTI_SIMPLE:
            if (selectRaceRule->mRow == SELECT_RACE_RULE_ROW_TEAMS &&
                selectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_TEAMS] == 1) {
                return FALSE;
            }
            break;
        case SELECT_RACE_RULE_MODE_BATTLE_MULTI_SIMPLE:
            if (selectRaceRule->mRow == SELECT_RACE_RULE_ROW_RULE_KIND &&
                selectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_RULE_KIND] == SELECT_RACE_RULE_RACE) {
                return FALSE;
            }
            if (selectRaceRule->mRow == SELECT_RACE_RULE_ROW_TEAMS &&
                selectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_TEAMS] == 1) {
                return FALSE;
            }
            break;
        case SELECT_RACE_RULE_MODE_VS_MULTI:
            if (selectRaceRule->mRow == SELECT_RACE_RULE_ROW_TEAMS &&
                selectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_TEAMS] == 1) {
                return FALSE;
            }
            break;
        case SELECT_RACE_RULE_MODE_BATTLE_MULTI:
            if (selectRaceRule->mRow == SELECT_RACE_RULE_ROW_RULE_KIND &&
                selectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_RULE_KIND] == SELECT_RACE_RULE_RACE) {
                return FALSE;
            }
            if (selectRaceRule->mRow == SELECT_RACE_RULE_ROW_TEAMS &&
                selectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_TEAMS] == 1) {
                return FALSE;
            }
            break;
    }
    return TRUE;
}

BOOL DoesSelectRaceRuleHumanCountMatch(void) {
    BOOL usesMask;
    u8 participantCount;
    switch (gSelectRaceRule->mMode) {
        case SELECT_RACE_RULE_MODE_VS_NO_CONNECTION:
        case SELECT_RACE_RULE_MODE_BATTLE_NO_CONNECTION:
            if (GetSelectRaceRuleHumanCount() == 1) {
                return TRUE;
            }
            break;
        case SELECT_RACE_RULE_MODE_VS_MULTI_SIMPLE:
        case SELECT_RACE_RULE_MODE_BATTLE_MULTI_SIMPLE:
        case SELECT_RACE_RULE_MODE_VS_MULTI:
        case SELECT_RACE_RULE_MODE_BATTLE_MULTI:
            usesMask = TRUE;
            if (gConnectionWork->mState != CONNECTION_STATE_SYNCED &&
                gConnectionWork->mState != CONNECTION_STATE_SYNCED_RACE) {
                usesMask = FALSE;
            }
            participantCount = usesMask != FALSE ? CountSetBits(gConnectionWork->mParticipantMask) : 0;
            if (participantCount == GetSelectRaceRuleHumanCount()) {
                return TRUE;
            }
            break;
    }
    return FALSE;
}

BOOL IsSelectRaceRuleTeamsValid(void) {
    BOOL valid;
    valid = TRUE;
    if (GetSelectRaceRuleTeamPlayerCount(0) == 0) {
        valid = FALSE;
    }
    if (GetSelectRaceRuleTeamPlayerCount(1) == 0) {
        valid = FALSE;
    }
    if (GetLargerTeamIndex() != 2) {
        valid = FALSE;
    }
    if (DoesSelectRaceRuleHumanCountMatch() == FALSE) {
        valid = FALSE;
    }
    return valid;
}

void MoveSelectRaceRuleValueNext(s32 playSound) {
    SelectRaceRule *selectRaceRule;
    s32 timerIndex;
    gSelectRaceRule->mRowValues[gSelectRaceRule->mRow]++;
    if (gSelectRaceRuleRowValueCounts[gSelectRaceRule->mRow] <= gSelectRaceRule->mRowValues[gSelectRaceRule->mRow]) {
        gSelectRaceRule->mRowValues[gSelectRaceRule->mRow] = 0;
    }
    if (IsSelectRaceRuleValueAllowed() == FALSE) {
        MoveSelectRaceRuleValueNext(0);
    }
    selectRaceRule = gSelectRaceRule;
    if (selectRaceRule->mRow != SELECT_RACE_RULE_ROW_RULE_KIND) {
        PrintLabelLayoutTextNoFixedAdvance(
            1, gSelectRaceRuleRowEntries[selectRaceRule->mRow].mEntryIndices[1], selectRaceRule->mBnll,
            GetBmgEntry(selectRaceRule->mRuleMessages,
                        gSelectRaceRuleValueMessageIndices[selectRaceRule->mRow]
                                                          [selectRaceRule->mRowValues[selectRaceRule->mRow]]),
            selectRaceRule->mBncl, selectRaceRule->mTable);
    } else {
        switch (selectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_RULE_KIND]) {
            case SELECT_RACE_RULE_WIN:
                SetAndPrintSelectRaceRuleWinCount(selectRaceRule->mWinCount);
                break;
            case SELECT_RACE_RULE_RACE:
                SetAndPrintSelectRaceRuleRaceCount(selectRaceRule->mRaceCount);
                break;
        }
        for (timerIndex = 0; timerIndex < 2; timerIndex++) {
            gSelectRaceRule->mCountTeamChangeTimers[0][timerIndex] = 0;
        }
    }
    if (gSelectRaceRule->mRow == SELECT_RACE_RULE_ROW_TEAMS) {
        for (timerIndex = 0; timerIndex < 2; timerIndex++) {
            gSelectRaceRule->mCountTeamChangeTimers[1][timerIndex] = 0;
        }
    }
    if (gSelectRaceRule->mRow == SELECT_RACE_RULE_ROW_CPU_DIFFICULTY) {
        if (gSelectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_CPU_DIFFICULTY] == 0) {
            if (IsSelectRaceRuleTeamsValid() == 0) {
                AssignSelectRaceRuleHumanTeams();
            }
            SetPlayerEntryListShowAllEntries(0);
        } else {
            if (IsSelectRaceRuleTeamsValid() == 0) {
                AssignSelectRaceRuleNonHumanTeams();
            }
            SetPlayerEntryListShowAllEntries(1);
        }
    }
    gSelectRaceRule->mRowChangeTimers[gSelectRaceRule->mRow][1] = 6;
    if (playSound != 0) {
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 1);
    }
}

void MoveSelectRaceRuleValuePrevious(s32 playSound) {
    SelectRaceRule *selectRaceRule;
    s32 timerIndex;
    gSelectRaceRule->mRowValues[gSelectRaceRule->mRow]--;
    if (gSelectRaceRule->mRowValues[gSelectRaceRule->mRow] < 0) {
        gSelectRaceRule->mRowValues[gSelectRaceRule->mRow] = gSelectRaceRuleRowValueCounts[gSelectRaceRule->mRow] - 1;
    }
    if (IsSelectRaceRuleValueAllowed() == FALSE) {
        MoveSelectRaceRuleValuePrevious(0);
    }
    selectRaceRule = gSelectRaceRule;
    if (selectRaceRule->mRow != SELECT_RACE_RULE_ROW_RULE_KIND) {
        PrintLabelLayoutTextNoFixedAdvance(
            1, gSelectRaceRuleRowEntries[selectRaceRule->mRow].mEntryIndices[1], selectRaceRule->mBnll,
            GetBmgEntry(selectRaceRule->mRuleMessages,
                        gSelectRaceRuleValueMessageIndices[selectRaceRule->mRow]
                                                          [selectRaceRule->mRowValues[selectRaceRule->mRow]]),
            selectRaceRule->mBncl, selectRaceRule->mTable);
    } else {
        switch (selectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_RULE_KIND]) {
            case SELECT_RACE_RULE_WIN:
                SetAndPrintSelectRaceRuleWinCount(selectRaceRule->mWinCount);
                break;
            case SELECT_RACE_RULE_RACE:
                SetAndPrintSelectRaceRuleRaceCount(selectRaceRule->mRaceCount);
                break;
        }
        for (timerIndex = 0; timerIndex < 2; timerIndex++) {
            gSelectRaceRule->mCountTeamChangeTimers[0][timerIndex] = 0;
        }
    }
    if (gSelectRaceRule->mRow == SELECT_RACE_RULE_ROW_TEAMS) {
        for (timerIndex = 0; timerIndex < 2; timerIndex++) {
            gSelectRaceRule->mCountTeamChangeTimers[1][timerIndex] = 0;
        }
    }
    if (gSelectRaceRule->mRow == SELECT_RACE_RULE_ROW_CPU_DIFFICULTY) {
        if (gSelectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_CPU_DIFFICULTY] == 0) {
            if (IsSelectRaceRuleTeamsValid() == 0) {
                AssignSelectRaceRuleHumanTeams();
            }
            SetPlayerEntryListShowAllEntries(0);
        } else {
            if (IsSelectRaceRuleTeamsValid() == 0) {
                AssignSelectRaceRuleNonHumanTeams();
            }
            SetPlayerEntryListShowAllEntries(1);
        }
    }
    gSelectRaceRule->mRowChangeTimers[gSelectRaceRule->mRow][0] = 6;
    if (playSound != 0) {
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 1);
    }
}

void IncrementSelectRaceRuleCourseCount(void) {
    BOOL changed;
    SelectRaceRule *selectRaceRule;
    changed = FALSE;
    selectRaceRule = gSelectRaceRule;
    if (selectRaceRule->mRow == SELECT_RACE_RULE_ROW_RULE_KIND) {
        switch (selectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_RULE_KIND]) {
            case SELECT_RACE_RULE_WIN:
                SetAndPrintSelectRaceRuleWinCount(selectRaceRule->mWinCount + 1);
                gSelectRaceRule->mCountTeamChangeTimers[0][1] = 6;
                changed = TRUE;
                break;
            case SELECT_RACE_RULE_RACE:
                SetAndPrintSelectRaceRuleRaceCount(selectRaceRule->mRaceCount + 1);
                gSelectRaceRule->mCountTeamChangeTimers[0][1] = 6;
                changed = TRUE;
                break;
        }
        if (changed != FALSE) {
            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x17);
        }
    }
}

void DecrementSelectRaceRuleCourseCount(void) {
    BOOL changed;
    SelectRaceRule *selectRaceRule;
    changed = FALSE;
    selectRaceRule = gSelectRaceRule;
    if (selectRaceRule->mRow == SELECT_RACE_RULE_ROW_RULE_KIND) {
        switch (selectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_RULE_KIND]) {
            case SELECT_RACE_RULE_WIN:
                SetAndPrintSelectRaceRuleWinCount(selectRaceRule->mWinCount - 1);
                gSelectRaceRule->mCountTeamChangeTimers[0][0] = 6;
                changed = TRUE;
                break;
            case SELECT_RACE_RULE_RACE:
                SetAndPrintSelectRaceRuleRaceCount(selectRaceRule->mRaceCount - 1);
                gSelectRaceRule->mCountTeamChangeTimers[0][0] = 6;
                changed = TRUE;
                break;
        }
        if (changed != FALSE) {
            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x17);
        }
    }
}

void AdvanceSelectRaceRuleRowObjects(void) {
    s32 rowIndex;
    s32 columnIndex;
    if (gStartupWork->mConnectionKind == 2) {
        for (rowIndex = 0; rowIndex < 5; rowIndex++) {
            for (columnIndex = 0; columnIndex < 2; columnIndex++) {
                gSelectRaceRule->mTable[gSelectRaceRuleStepCellsHighlighted[rowIndex][columnIndex]].mVisible = 0;
                gSelectRaceRule->mTable[gSelectRaceRuleStepCellsChanging[rowIndex][columnIndex]].mVisible = 0;
                gSelectRaceRule->mTable[gSelectRaceRuleStepCellsPlain[rowIndex][columnIndex]].mVisible = 0;
            }
        }
        return;
    }
    for (rowIndex = 0; rowIndex < 5; rowIndex++) {
        if (GetSelectRaceRuleHumanCount() == 8 && rowIndex == 1) {
            for (columnIndex = 0; columnIndex < 2; columnIndex++) {
                gSelectRaceRule->mTable[gSelectRaceRuleStepCellsHighlighted[rowIndex][columnIndex]].mVisible = 0;
                gSelectRaceRule->mTable[gSelectRaceRuleStepCellsChanging[rowIndex][columnIndex]].mVisible = 0;
                gSelectRaceRule->mTable[gSelectRaceRuleStepCellsPlain[rowIndex][columnIndex]].mVisible = 0;
            }
        } else {
            gSelectRaceRule->mTable[gSelectRaceRuleStepCellsChanging[rowIndex][0]].mOffsetX =
                -LookupFrameOffset(6 - gSelectRaceRule->mRowChangeTimers[rowIndex][0]);
            gSelectRaceRule->mTable[gSelectRaceRuleStepCellsChanging[rowIndex][1]].mOffsetX =
                LookupFrameOffset(6 - gSelectRaceRule->mRowChangeTimers[rowIndex][1]);
            for (columnIndex = 0; columnIndex < 2; columnIndex++) {
                if (gSelectRaceRule->mRowChangeTimers[rowIndex][columnIndex] > 0) {
                    gSelectRaceRule->mRowChangeTimers[rowIndex][columnIndex]--;
                    gSelectRaceRule->mTable[gSelectRaceRuleStepCellsHighlighted[rowIndex][columnIndex]].mVisible = 0;
                    gSelectRaceRule->mTable[gSelectRaceRuleStepCellsChanging[rowIndex][columnIndex]].mVisible = 1;
                    gSelectRaceRule->mTable[gSelectRaceRuleStepCellsPlain[rowIndex][columnIndex]].mVisible = 0;
                } else if (gSelectRaceRule->mRow == rowIndex && gSelectRaceRule->mOnButton == 0) {
                    gSelectRaceRule->mTable[gSelectRaceRuleStepCellsHighlighted[rowIndex][columnIndex]].mVisible = 1;
                    gSelectRaceRule->mTable[gSelectRaceRuleStepCellsChanging[rowIndex][columnIndex]].mVisible = 0;
                    gSelectRaceRule->mTable[gSelectRaceRuleStepCellsPlain[rowIndex][columnIndex]].mVisible = 0;
                } else {
                    gSelectRaceRule->mTable[gSelectRaceRuleStepCellsHighlighted[rowIndex][columnIndex]].mVisible = 0;
                    gSelectRaceRule->mTable[gSelectRaceRuleStepCellsChanging[rowIndex][columnIndex]].mVisible = 0;
                    gSelectRaceRule->mTable[gSelectRaceRuleStepCellsPlain[rowIndex][columnIndex]].mVisible = 1;
                }
            }
        }
    }
    if (gSelectRaceRule->mMode == SELECT_RACE_RULE_MODE_BATTLE_MULTI_SIMPLE) {
        for (columnIndex = 0; columnIndex < 2; columnIndex++) {
            gSelectRaceRule->mTable[gSelectRaceRuleStepCellsHighlighted[0][columnIndex]].mVisible = 0;
            gSelectRaceRule->mTable[gSelectRaceRuleStepCellsHighlighted[2][columnIndex]].mVisible = 0;
            gSelectRaceRule->mTable[gSelectRaceRuleStepCellsChanging[0][columnIndex]].mVisible = 0;
            gSelectRaceRule->mTable[gSelectRaceRuleStepCellsChanging[2][columnIndex]].mVisible = 0;
            gSelectRaceRule->mTable[gSelectRaceRuleStepCellsPlain[0][columnIndex]].mVisible = 0;
            gSelectRaceRule->mTable[gSelectRaceRuleStepCellsPlain[2][columnIndex]].mVisible = 0;
        }
    }
}

void SetListedCpuSlotWrapper(u16 entryIndex, u32 value) {
    SetListedCpuSlot(entryIndex, value);
}

void AssignListedCpuSlots(void) {
    u16 cpuEntries[2];
    s32 slotIndex;
    u16 cpuEntry;
    SelectRaceRule *selectRaceRule;
    cpuEntries[0] = 8;
    cpuEntries[1] = 8;
    for (slotIndex = 0; slotIndex < 8; slotIndex++) {
        SetListedCpuSlotWrapper(slotIndex, 3);
    }
    if (GetSelectRaceRuleCpuCount() != 0) {
        selectRaceRule = gSelectRaceRule;
        if (selectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_TEAMS] == 0) {
            PickSelectRaceRuleCpuEntry(&cpuEntries[0]);
            SetListedCpuSlotWrapper(cpuEntries[0], 0);
            if (GetSelectRaceRuleCpuCount() > 1) {
                PickSelectRaceRuleCpuEntry(&cpuEntries[1]);
                while (cpuEntries[0] == cpuEntries[1]) {
                    PickSelectRaceRuleCpuEntry(&cpuEntries[1]);
                }
                SetListedCpuSlotWrapper(cpuEntries[1], 1);
            }
        } else if (selectRaceRule->mTeamNonHumanCounts[GetOtherTeamIndex(selectRaceRule->mPlayerTeamIndices[0])] != 0) {
            PickSelectRaceRuleCpuEntry(&cpuEntries[0]);
            cpuEntry = cpuEntries[0];
            while (gSelectRaceRule->mPlayerTeamIndices[cpuEntry] !=
                   GetOtherTeamIndex(gSelectRaceRule->mPlayerTeamIndices[0])) {
                PickSelectRaceRuleCpuEntry(&cpuEntries[0]);
                cpuEntry = cpuEntries[0];
            }
            SetListedCpuSlotWrapper(cpuEntry, 0);
            if (gSelectRaceRule->mTeamNonHumanCounts[gSelectRaceRule->mPlayerTeamIndices[0]] != 0) {
                PickSelectRaceRuleCpuEntry(&cpuEntries[1]);
                while (gSelectRaceRule->mPlayerTeamIndices[0] != gSelectRaceRule->mPlayerTeamIndices[cpuEntries[1]]) {
                    PickSelectRaceRuleCpuEntry(&cpuEntries[1]);
                }
                SetListedCpuSlotWrapper(cpuEntries[1], 1);
            } else if (gSelectRaceRule->mTeamNonHumanCounts[GetOtherTeamIndex(gSelectRaceRule->mPlayerTeamIndices[0])] >
                       1) {
                PickSelectRaceRuleCpuEntry(&cpuEntries[1]);
                while (gSelectRaceRule->mPlayerTeamIndices[cpuEntries[1]] !=
                           GetOtherTeamIndex(gSelectRaceRule->mPlayerTeamIndices[0]) ||
                       cpuEntries[0] == cpuEntries[1]) {
                    PickSelectRaceRuleCpuEntry(&cpuEntries[1]);
                }
                SetListedCpuSlotWrapper(cpuEntries[1], 1);
            }
        } else if (gSelectRaceRule->mTeamNonHumanCounts[gSelectRaceRule->mPlayerTeamIndices[0]] != 0) {
            PickSelectRaceRuleCpuEntry(&cpuEntries[0]);
            while (gSelectRaceRule->mPlayerTeamIndices[0] != gSelectRaceRule->mPlayerTeamIndices[cpuEntries[0]]) {
                PickSelectRaceRuleCpuEntry(&cpuEntries[0]);
            }
            SetListedCpuSlotWrapper(cpuEntries[0], 0);
            if (gSelectRaceRule->mTeamNonHumanCounts[gSelectRaceRule->mPlayerTeamIndices[0]] > 1) {
                PickSelectRaceRuleCpuEntry(&cpuEntries[1]);
                while (gSelectRaceRule->mPlayerTeamIndices[0] != gSelectRaceRule->mPlayerTeamIndices[cpuEntries[1]] ||
                       cpuEntries[0] == cpuEntries[1]) {
                    PickSelectRaceRuleCpuEntry(&cpuEntries[1]);
                }
                SetListedCpuSlotWrapper(cpuEntries[1], 1);
            }
        }
    }
}

// Stores the rows' values and the kinds and teams of the 8 entries into the race setup copy.
void WriteSelectRaceRuleToRaceSetupCopy(void) {
    s32 entryIndex;
    for (entryIndex = 0; entryIndex < 8; entryIndex++) {
        if (IsSelectRaceRuleEntryHuman(entryIndex) != 0) {
            SetPlayerKind(entryIndex, PLAYER_KIND_HUMAN);
            SetTeamIndex(entryIndex, gSelectRaceRuleTeamsToSetupCopy[gSelectRaceRule->mPlayerTeamIndices[entryIndex]]);
        } else if (gSelectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_CPU_DIFFICULTY] != 0) {
            SetPlayerKind(entryIndex, PLAYER_KIND_CPU);
            SetTeamIndex(entryIndex, gSelectRaceRuleTeamsToSetupCopy[gSelectRaceRule->mPlayerTeamIndices[entryIndex]]);
        } else {
            SetPlayerKind(entryIndex, PLAYER_KIND_NONE);
            SetTeamIndex(entryIndex, gSelectRaceRuleTeamsToSetupCopy[gSelectRaceRule->mPlayerTeamIndices[entryIndex]]);
        }
    }
    if (gSelectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_ENGINE] == 3) {
        SetEngineIndex(gSelectRaceRuleEngineIndices[2]);
        SetMirrorMode();
    } else {
        SetEngineIndex(gSelectRaceRuleEngineIndices[gSelectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_ENGINE]]);
        ClearMirrorMode();
    }
    SetCpuDifficulty(gSelectRaceRuleCpuDifficulties[gSelectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_CPU_DIFFICULTY]]);
    SetCourseListMode(gSelectRaceRuleCourseListModes[gSelectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_COURSE_LIST]]);
    SetRuleKind(gSelectRaceRuleRuleKinds[gSelectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_RULE_KIND]]);
    switch (gSelectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_RULE_KIND]) {
        case SELECT_RACE_RULE_WIN:
            SetRaceSetupCopyCourseCount(gSelectRaceRule->mWinCount);
            break;
        case SELECT_RACE_RULE_RACE:
            SetRaceSetupCopyCourseCount(gSelectRaceRule->mRaceCount);
            break;
    }
    if (gSelectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_TEAMS] == 0) {
        ClearUseTeams();
    } else {
        SetUseTeams();
    }
    AssignListedCpuSlots();
}

void AdvanceSelectRaceRuleChangeObjects(void) {
    s32 columnIndex;
    u16 ownIndex;
    if (gStartupWork->mConnectionKind != 2) {
        if (gSelectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_RULE_KIND] != SELECT_RACE_RULE_FREE) {
            if (gSelectRaceRule->mRow == SELECT_RACE_RULE_ROW_RULE_KIND && gSelectRaceRule->mOnButton == 0) {
                gSelectRaceRule->mTable[30].mVisible = 1;
                gSelectRaceRule->mTable[31].mVisible = 0;
            } else {
                gSelectRaceRule->mTable[30].mVisible = 0;
                gSelectRaceRule->mTable[31].mVisible = 1;
            }
            for (columnIndex = 0; columnIndex < 2; columnIndex++) {
                if (gSelectRaceRule->mCountTeamChangeTimers[0][columnIndex] > 0) {
                    gSelectRaceRule->mCountTeamChangeTimers[0][columnIndex]--;
                    gSelectRaceRule->mTable[gSelectRaceRuleCountTeamChangeCells[0][columnIndex]].mVisible = 1;
                } else {
                    gSelectRaceRule->mTable[gSelectRaceRuleCountTeamChangeCells[0][columnIndex]].mVisible = 0;
                }
            }
        } else {
            gSelectRaceRule->mTable[30].mVisible = 0;
            gSelectRaceRule->mTable[31].mVisible = 0;
            for (columnIndex = 0; columnIndex < 2; columnIndex++) {
                gSelectRaceRule->mTable[gSelectRaceRuleCountTeamChangeCells[0][columnIndex]].mVisible = 0;
            }
        }
        if (gSelectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_TEAMS] == 2) {
            for (columnIndex = 0; columnIndex < 2; columnIndex++) {
                if (gSelectRaceRule->mRow == SELECT_RACE_RULE_ROW_TEAMS && gSelectRaceRule->mOnButton == 0) {
                    ownIndex =
                        gConnectionWork->mConnectionMode == CONNECTION_MODE_CHILD ? gConnectionWork->mOwnIndex : 0;
                    if (IsPlayerTeamPlayerCountNotOne(gConnectionWork->mParticipantPosByIndex[ownIndex].mEntryIndex) !=
                        0) {
                        gSelectRaceRule->mTable[gSelectRaceRuleTeamCellsHighlighted[columnIndex]].mVisible = 1;
                        gSelectRaceRule->mTable[gSelectRaceRuleTeamCellsPlain[columnIndex]].mVisible = 0;
                    } else {
                        gSelectRaceRule->mTable[gSelectRaceRuleTeamCellsHighlighted[columnIndex]].mVisible = 0;
                        gSelectRaceRule->mTable[gSelectRaceRuleTeamCellsPlain[columnIndex]].mVisible = 1;
                    }
                } else {
                    gSelectRaceRule->mTable[gSelectRaceRuleTeamCellsHighlighted[columnIndex]].mVisible = 0;
                    gSelectRaceRule->mTable[gSelectRaceRuleTeamCellsPlain[columnIndex]].mVisible = 1;
                }
                if (gSelectRaceRule->mCountTeamChangeTimers[1][columnIndex] > 0) {
                    gSelectRaceRule->mCountTeamChangeTimers[1][columnIndex]--;
                    gSelectRaceRule->mTable[gSelectRaceRuleCountTeamChangeCells[1][columnIndex]].mVisible = 1;
                } else {
                    gSelectRaceRule->mTable[gSelectRaceRuleCountTeamChangeCells[1][columnIndex]].mVisible = 0;
                }
            }
        } else {
            for (columnIndex = 0; columnIndex < 2; columnIndex++) {
                gSelectRaceRule->mTable[gSelectRaceRuleTeamCellsHighlighted[columnIndex]].mVisible = 0;
                gSelectRaceRule->mTable[gSelectRaceRuleTeamCellsPlain[columnIndex]].mVisible = 0;
                gSelectRaceRule->mTable[gSelectRaceRuleCountTeamChangeCells[1][columnIndex]].mVisible = 0;
            }
        }
    } else {
        gSelectRaceRule->mTable[30].mVisible = 0;
        gSelectRaceRule->mTable[31].mVisible = 0;
        for (columnIndex = 0; columnIndex < 2; columnIndex++) {
            gSelectRaceRule->mTable[gSelectRaceRuleCountTeamChangeCells[0][columnIndex]].mVisible = 0;
        }
        if (gSelectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_TEAMS] == 2) {
            for (columnIndex = 0; columnIndex < 2; columnIndex++) {
                ownIndex = gConnectionWork->mConnectionMode == CONNECTION_MODE_CHILD ? gConnectionWork->mOwnIndex : 0;
                if (IsPlayerTeamPlayerCountNotOne(gConnectionWork->mParticipantPosByIndex[ownIndex].mEntryIndex) != 0) {
                    gSelectRaceRule->mTable[gSelectRaceRuleTeamCellsHighlighted[columnIndex]].mVisible = 1;
                    gSelectRaceRule->mTable[gSelectRaceRuleTeamCellsPlain[columnIndex]].mVisible = 0;
                } else {
                    gSelectRaceRule->mTable[gSelectRaceRuleTeamCellsHighlighted[columnIndex]].mVisible = 1;
                    gSelectRaceRule->mTable[gSelectRaceRuleTeamCellsPlain[columnIndex]].mVisible = 1;
                }
                if (gSelectRaceRule->mCountTeamChangeTimers[1][columnIndex] > 0) {
                    gSelectRaceRule->mCountTeamChangeTimers[1][columnIndex]--;
                    gSelectRaceRule->mTable[gSelectRaceRuleCountTeamChangeCells[1][columnIndex]].mVisible = 1;
                } else {
                    gSelectRaceRule->mTable[gSelectRaceRuleCountTeamChangeCells[1][columnIndex]].mVisible = 0;
                }
            }
        } else {
            for (columnIndex = 0; columnIndex < 2; columnIndex++) {
                gSelectRaceRule->mTable[gSelectRaceRuleTeamCellsHighlighted[columnIndex]].mVisible = 0;
                gSelectRaceRule->mTable[gSelectRaceRuleTeamCellsPlain[columnIndex]].mVisible = 0;
                gSelectRaceRule->mTable[gSelectRaceRuleCountTeamChangeCells[1][columnIndex]].mVisible = 0;
            }
        }
    }
}

void PrintSelectRaceRuleRow4Message(void) {
    SelectRaceRule *selectRaceRule;
    if (gStartupWork->mConnectionKind == 2) {
        gSelectRaceRule->mTable[gSelectRaceRule->mBncl->mCount + 14].mVisible = 1;
        selectRaceRule = gSelectRaceRule;
        if (selectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_TEAMS] == 2) {
            PrintLabelLayoutTextNoFixedAdvance(1, 0xe, gSelectRaceRule->mBnll,
                                               GetBmgEntry(selectRaceRule->mRuleMessages, 0x15), selectRaceRule->mBncl,
                                               selectRaceRule->mTable);
        } else {
            PrintLabelLayoutTextNoFixedAdvance(1, 0xe, gSelectRaceRule->mBnll,
                                               GetBmgEntry(selectRaceRule->mRuleMessages, 0x14), selectRaceRule->mBncl,
                                               selectRaceRule->mTable);
        }
    }
}

void AdvanceSelectRaceRuleTeamInput(void) {
    s32 entryIndex;
    s32 hitRectIndex;
    BOOL newPair;
    BOOL noPairForFewCalls;
    u32 slotIndex;
    InputSlot *inputSlot;
    u16 hasPair;
    if (gSelectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_TEAMS] == 2) {
        for (entryIndex = 0; entryIndex < 8; entryIndex++) {
            slotIndex = gSelectRaceRuleEntryInputSlots[entryIndex];
            hitRectIndex = -1;
            newPair = FALSE;
            noPairForFewCalls = FALSE;
            inputSlot = &gInputSlots[slotIndex];
            hasPair = inputSlot->mPair.mHasPair;
            if (hasPair == 0 && inputSlot->mPair.mNoPairCount < 5) {
                noPairForFewCalls = TRUE;
            }
            if (noPairForFewCalls == FALSE && inputSlot->mPair.mPrevHasPair == 0 && hasPair != 0) {
                newPair = TRUE;
            }
            if (newPair != FALSE) {
                hitRectIndex = RectTableFindContaining(gSelectRaceRule->mBnbl, inputSlot->mPair.mPairX,
                                                       inputSlot->mPair.mPairY - gSelectRaceRule->mOffsetY);
            }
            if (GetNewOrRepeatBits(slotIndex, PAD_KEY_L) != 0 || hitRectIndex == 0x11) {
                if (entryIndex == 0) {
                    if (hitRectIndex == 0x11) {
                        gSelectRaceRule->mRow = SELECT_RACE_RULE_ROW_TEAMS;
                        gSelectRaceRule->mOnButton = 0;
                    }
                    if (gSelectRaceRule->mOnButton == 0 && gSelectRaceRule->mRow == SELECT_RACE_RULE_ROW_TEAMS) {
                        ChangeSelectRaceRulePlayerTeam(entryIndex, 0);
                    }
                } else {
                    ChangeSelectRaceRulePlayerTeam(entryIndex, 0);
                }
            } else if (GetNewOrRepeatBits(slotIndex, PAD_KEY_R) != 0 || hitRectIndex == 0x12) {
                if (entryIndex == 0) {
                    if (hitRectIndex == 0x12) {
                        gSelectRaceRule->mRow = SELECT_RACE_RULE_ROW_TEAMS;
                        gSelectRaceRule->mOnButton = 0;
                    }
                    if (gSelectRaceRule->mOnButton == 0 && gSelectRaceRule->mRow == SELECT_RACE_RULE_ROW_TEAMS) {
                        ChangeSelectRaceRulePlayerTeam(entryIndex, 1);
                    }
                } else {
                    ChangeSelectRaceRulePlayerTeam(entryIndex, 1);
                }
            }
        }
    }
}

// Sets every row to the race setup copy's value and rebuilds the teams from its entries; first clears the copy when
// GetPreviousMenuScreenNumber() returns 8, 9 or 0xf.
void ReadRaceSetupCopyIntoSelectRaceRule(void) {
    s32 teamValue;
    s32 entryIndex;
    u32 value;
    teamValue = 3;
    if (GetPreviousMenuScreenNumber() == 8 || GetPreviousMenuScreenNumber() == 9 ||
        GetPreviousMenuScreenNumber() == 0xf) {
        ClearUseTeams();
        ClearMirrorMode();
        SetEngineIndex(0);
        SetCpuDifficulty(0);
        SetCourseListMode(0);
        SetRuleKind(0);
        SetRaceSetupCopyCourseCount(0);
    }
    if (GetUseTeams() != 0) {
        switch (gSelectRaceRule->mMode) {
            case SELECT_RACE_RULE_MODE_VS_NO_CONNECTION:
            case SELECT_RACE_RULE_MODE_BATTLE_NO_CONNECTION:
                teamValue = 1;
                break;
            case SELECT_RACE_RULE_MODE_VS_MULTI_SIMPLE:
            case SELECT_RACE_RULE_MODE_BATTLE_MULTI_SIMPLE:
            case SELECT_RACE_RULE_MODE_VS_MULTI:
            case SELECT_RACE_RULE_MODE_BATTLE_MULTI:
                teamValue = 2;
                break;
        }
        for (entryIndex = 0; entryIndex < 8; entryIndex++) {
            value = gSelectRaceRuleTeamsFromSetupCopy[GetTeamIndex(entryIndex)];
            SetSelectRaceRulePlayerTeam(entryIndex, value);
            if (GetPlayerKind(entryIndex) == PLAYER_KIND_HUMAN) {
                gSelectRaceRule->mTeamHumanCounts[value]++;
            } else {
                gSelectRaceRule->mTeamNonHumanCounts[value]++;
            }
        }
    } else {
        teamValue = 0;
    }
    gSelectRaceRule->mRow = SELECT_RACE_RULE_ROW_TEAMS;
    while (teamValue != gSelectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_TEAMS]) {
        MoveSelectRaceRuleValueNext(0);
    }
    if (GetMirrorMode() != 0) {
        value = 3;
    } else {
        value = gSelectRaceRuleEngineIndexValues[GetEngineIndex()];
    }
    teamValue = 0;
    gSelectRaceRule->mRow = SELECT_RACE_RULE_ROW_ENGINE;
    while (value != gSelectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_ENGINE]) {
        MoveSelectRaceRuleValueNext(0);
    }
    value = gSelectRaceRuleCpuDifficultyValues[GetCpuDifficulty()];
    gSelectRaceRule->mRow = SELECT_RACE_RULE_ROW_CPU_DIFFICULTY;
    while (value != gSelectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_CPU_DIFFICULTY]) {
        MoveSelectRaceRuleValueNext(0);
    }
    switch (gSelectRaceRule->mMode) {
        case SELECT_RACE_RULE_MODE_VS_NO_CONNECTION:
        case SELECT_RACE_RULE_MODE_BATTLE_NO_CONNECTION:
            if (value == 0 && gSelectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_CPU_DIFFICULTY] != 2) {
                do {
                    MoveSelectRaceRuleValueNext(0);
                } while (gSelectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_CPU_DIFFICULTY] != 2);
            }
            break;
    }
    value = gSelectRaceRuleCourseListModeValues[GetCourseListMode()];
    gSelectRaceRule->mRow = SELECT_RACE_RULE_ROW_COURSE_LIST;
    while (value != gSelectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_COURSE_LIST]) {
        MoveSelectRaceRuleValueNext(0);
    }
    value = gSelectRaceRuleRuleKindValues[GetRuleKind()];
    gSelectRaceRule->mRow = SELECT_RACE_RULE_ROW_RULE_KIND;
    while (value != gSelectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_RULE_KIND]) {
        MoveSelectRaceRuleValueNext(0);
    }
    switch (gSelectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_RULE_KIND]) {
        case SELECT_RACE_RULE_WIN:
            SetAndPrintSelectRaceRuleWinCount(GetRaceSetupCopyCourseCount());
            break;
        case SELECT_RACE_RULE_RACE:
            SetAndPrintSelectRaceRuleRaceCount(GetRaceSetupCopyCourseCount());
            break;
    }
    gSelectRaceRule->mRow = SELECT_RACE_RULE_ROW_ENGINE;
}

void SetSelectRaceRuleHumanCount(void) {
    BOOL usesMask;
    u8 participantCount;
    switch (gSelectRaceRule->mMode) {
        case SELECT_RACE_RULE_MODE_VS_NO_CONNECTION:
        case SELECT_RACE_RULE_MODE_BATTLE_NO_CONNECTION:
            gSelectRaceRule->mTeamHumanCounts[0] = 1;
            break;
        case SELECT_RACE_RULE_MODE_VS_MULTI_SIMPLE:
        case SELECT_RACE_RULE_MODE_BATTLE_MULTI_SIMPLE:
        case SELECT_RACE_RULE_MODE_VS_MULTI:
        case SELECT_RACE_RULE_MODE_BATTLE_MULTI:
            usesMask = TRUE;
            if (gConnectionWork->mState != CONNECTION_STATE_SYNCED &&
                gConnectionWork->mState != CONNECTION_STATE_SYNCED_RACE) {
                usesMask = FALSE;
            }
            participantCount = usesMask != FALSE ? CountSetBits(gConnectionWork->mParticipantMask) : 0;
            gSelectRaceRule->mTeamHumanCounts[0] = participantCount;
            break;
    }
}

void ResetSelectRaceRulePositions(void) {
    s32 rowIndex;
    s32 columnIndex;
    s32 value;
    gSelectRaceRule->mNextState = SELECT_RACE_RULE_STATE_WAIT_FADE;
    gSelectRaceRule->mStateFrames = 0;
    value = gSelectRaceRule->mOffsetY - 0xc0;
    gSelectRaceRule->mBg3Offset = value;
    value = gSelectRaceRule->mOffsetY - 0xc0;
    gSelectRaceRule->mBg3Offset = value;
    value = gSelectRaceRule->mBncl->mCount;
    gSelectRaceRule->mTable[40].mOffsetY = gSelectRaceRule->mOffsetY + 0xc0;
    gSelectRaceRule->mTable[41].mOffsetY = gSelectRaceRule->mOffsetY + 0xc0;
    gSelectRaceRule->mTable[42].mOffsetY = gSelectRaceRule->mOffsetY + 0xc0;
    for (rowIndex = 0; rowIndex < 5; rowIndex++) {
        for (columnIndex = 0; columnIndex < 2; columnIndex++) {
            gSelectRaceRule->mTable[gSelectRaceRuleStepCellsHighlighted[rowIndex][columnIndex]].mOffsetY =
                gSelectRaceRule->mOffsetY - 0xc0;
            gSelectRaceRule->mTable[gSelectRaceRuleStepCellsChanging[rowIndex][columnIndex]].mOffsetY =
                gSelectRaceRule->mOffsetY - 0xc0;
            gSelectRaceRule->mTable[gSelectRaceRuleStepCellsPlain[rowIndex][columnIndex]].mOffsetY =
                gSelectRaceRule->mOffsetY - 0xc0;
        }
        for (columnIndex = 0; columnIndex < 2; columnIndex++) {
            gSelectRaceRule->mTable[value + gSelectRaceRuleRowEntries[rowIndex].mEntryIndices[columnIndex]].mOffsetY =
                gSelectRaceRule->mOffsetY - 0xc0;
        }
    }
    gSelectRaceRule->mTable[value + 10].mOffsetY = gSelectRaceRule->mOffsetY - 0xc0;
    gSelectRaceRule->mTable[value + 12].mOffsetY = gSelectRaceRule->mOffsetY - 0xc0;
    gSelectRaceRule->mTable[30].mOffsetY = gSelectRaceRule->mOffsetY - 0xc0;
    gSelectRaceRule->mTable[31].mOffsetY = gSelectRaceRule->mOffsetY - 0xc0;
    gSelectRaceRule->mTable[34].mOffsetY = gSelectRaceRule->mOffsetY - 0xc0;
    gSelectRaceRule->mTable[37].mOffsetY = gSelectRaceRule->mOffsetY - 0xc0;
    gSelectRaceRule->mTable[35].mOffsetY = gSelectRaceRule->mOffsetY - 0xc0;
    gSelectRaceRule->mTable[38].mOffsetY = gSelectRaceRule->mOffsetY - 0xc0;
    for (rowIndex = 0; rowIndex < 2; rowIndex++) {
        for (columnIndex = 0; columnIndex < 2; columnIndex++) {
            gSelectRaceRule->mTable[gSelectRaceRuleCountTeamChangeCells[rowIndex][columnIndex]].mOffsetY =
                gSelectRaceRule->mOffsetY - 0xc0;
        }
    }
    if (gStartupWork->mConnectionKind != 2) {
        gSelectRaceRule->mTable[value + 13].mOffsetY = gSelectRaceRule->mOffsetY + 0xc0;
        value += 8;
        gSelectRaceRule->mTable[value].mOffsetY = gSelectRaceRule->mOffsetY + 0xc0;
    } else {
        value += 14;
        gSelectRaceRule->mTable[value].mOffsetY = gSelectRaceRule->mOffsetY + 0xc0;
    }
}

// Requests state 1: stores mNextState = 1 and zeroes mStateFrames; the next AdvanceSelectRaceRule call copies it to
// mState and runs AdvanceSelectRaceRuleState1.
void RequestSelectRaceRuleState1(void) {
    gSelectRaceRule->mNextState = SELECT_RACE_RULE_STATE_SLIDE_IN;
    gSelectRaceRule->mStateFrames = 0;
}

void RequestSelectRaceRuleState2(void) {
    gSelectRaceRule->mNextState = SELECT_RACE_RULE_STATE_WAIT_RETURN;
    gSelectRaceRule->mStateFrames = 0;
    switch (gSelectRaceRule->mMode) {
        case SELECT_RACE_RULE_MODE_VS_NO_CONNECTION:
        case SELECT_RACE_RULE_MODE_BATTLE_NO_CONNECTION:
            RequestSelectReturnState1();
            break;
    }
}

// Requests state 3: stores mNextState = 3 and zeroes mStateFrames; the next AdvanceSelectRaceRule call copies it to
// mState and runs AdvanceSelectRaceRuleState3.
void RequestSelectRaceRuleState3(void) {
    gSelectRaceRule->mNextState = SELECT_RACE_RULE_STATE_CHOOSE;
    gSelectRaceRule->mStateFrames = 0;
}

void RequestSelectRaceRuleState4(void) {
    gSelectRaceRule->mNextState = SELECT_RACE_RULE_STATE_WAIT_PRESS;
    gSelectRaceRule->mStateFrames = 0;
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        StopPaletteBlend();
    }
    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 5);
    WriteSelectRaceRuleToRaceSetupCopy();
}

void RequestSelectRaceRuleState5(void) {
    void *message;
    gSelectRaceRule->mNextState = SELECT_RACE_RULE_STATE_WAIT_CONFIRM_OPEN;
    gSelectRaceRule->mStateFrames = 0;
    message = GetBmgEntry(gSelectRaceRule->mCommonMessages, 4);
    StartSelectChoises(message, GetBmgEntry(gSelectRaceRule->mCommonMessages, 2), 0);
}

// Requests state 6: stores mNextState = 6 and zeroes mStateFrames; the next AdvanceSelectRaceRule call copies it to
// mState and runs AdvanceSelectRaceRuleState6.
void RequestSelectRaceRuleState6(void) {
    gSelectRaceRule->mNextState = SELECT_RACE_RULE_STATE_WAIT_CONFIRM_CHOICES;
    gSelectRaceRule->mStateFrames = 0;
}

void RequestSelectRaceRuleState7(void) {
    gSelectRaceRule->mNextState = SELECT_RACE_RULE_STATE_WAIT_CONFIRM_ANSWER;
    gSelectRaceRule->mStateFrames = 0;
    RequestSelectChoisesState0();
}

// Requests state 8: stores mNextState = 8 and zeroes mStateFrames; the next AdvanceSelectRaceRule call copies it to
// mState and runs AdvanceSelectRaceRuleState8.
void RequestSelectRaceRuleState8(void) {
    gSelectRaceRule->mNextState = SELECT_RACE_RULE_STATE_SLIDE_OUT;
    gSelectRaceRule->mStateFrames = 0;
}

void InitSelectRaceRule(void *parentHeap, s32 unusedArg1, void *oamList, s32 mode) {
    void *heap;
    s32 rowIndex;
    s32 columnIndex;
    s32 cellEntryCount;
    s32 remainingSubObjSize;
    SelectRaceRule *selectRaceRule;
    reg_G2S_DB_BG3CNT =
        (reg_G2S_DB_BG3CNT & (REG_G2S_DB_BG3CNT_PRIORITY_MASK | REG_G2S_DB_BG3CNT_MOSAIC_MASK)) | 0x8200;
    heap = CreateFrmHeapFromMaxFree(parentHeap);
    gSelectRaceRule = HeapAlloc(heap, 0xbc);
    gSelectRaceRule->mHeap = heap;
    gSelectRaceRule->mMode = mode;
    gSelectRaceRule->mState = SELECT_RACE_RULE_STATE_WAIT_FADE;
    gSelectRaceRule->mRow = SELECT_RACE_RULE_ROW_ENGINE;
    gSelectRaceRule->mPrevRow = 4;
    gSelectRaceRule->mOffsetY = 0;
    gSelectRaceRule->mOnButton = 0;
    gSelectRaceRule->mPrevOnButton = 0;
    gSelectRaceRule->mButtonHighlightShown = 1;
    gSelectRaceRule->mWinCount = 0;
    gSelectRaceRule->mRaceCount = 0;
    gSelectRaceRule->mOamList = oamList;
    gSelectRaceRule->mResult = 0;
    for (rowIndex = 0; rowIndex < 2; rowIndex++) {
        gSelectRaceRule->mTeamHumanCounts[rowIndex] = 0;
        gSelectRaceRule->mTeamNonHumanCounts[rowIndex] = 0;
    }
    for (rowIndex = 0; rowIndex < 5; rowIndex++) {
        for (columnIndex = 0; columnIndex < 2; columnIndex++) {
            gSelectRaceRule->mRowChangeTimers[rowIndex][columnIndex] = 0;
        }
    }
    for (rowIndex = 0; rowIndex < 2; rowIndex++) {
        for (columnIndex = 0; columnIndex < 2; columnIndex++) {
            gSelectRaceRule->mCountTeamChangeTimers[rowIndex][columnIndex] = 0;
        }
    }
    LocateAndQueueSelectRaceRule();
    InitLayoutTable(gSelectRaceRule->mHeap, gSelectRaceRule->mBncl, gSelectRaceRule->mBnll, &gSelectRaceRule->mTable);
    gSelectRaceRule->mCommonMessages = FindFileInLoadedArchives("common.bmg");
    gSelectRaceRule->mRuleMessages = FindSceneFile("rule.bmg");
    cellEntryCount = gSelectRaceRule->mBncl->mCount;
    remainingSubObjSize = GX_GetSizeOfSubOBJ();
    for (rowIndex = 0; rowIndex < 5; rowIndex++) {
        for (columnIndex = 0; columnIndex < 2; columnIndex++) {
            if (!(rowIndex == 3 && columnIndex == 1)) {
                remainingSubObjSize -= InitLabelCanvas(
                    gSelectRaceRule->mHeap, gSelectRaceRuleRowEntries[rowIndex].mEntryIndices[columnIndex],
                    gSelectRaceRule->mBnll, gSelectRaceRuleLabelWidths[rowIndex][columnIndex],
                    gSelectRaceRuleLabelHeights[rowIndex][columnIndex], rowIndex * 2 + columnIndex,
                    gSelectRaceRule->mNcer, gSelectRaceRule->mBncl, gSelectRaceRule->mTable, remainingSubObjSize);
            }
        }
        selectRaceRule = gSelectRaceRule;
        PrintLabelLayoutTextNoFixedAdvance(
            1, gSelectRaceRuleRowEntries[rowIndex].mEntryIndices[0], gSelectRaceRule->mBnll,
            GetBmgEntry(selectRaceRule->mRuleMessages, gSelectRaceRuleRowMessageIndices[rowIndex]),
            selectRaceRule->mBncl, selectRaceRule->mTable);
        if (rowIndex != 3) {
            selectRaceRule = gSelectRaceRule;
            PrintLabelLayoutTextNoFixedAdvance(
                1, gSelectRaceRuleRowEntries[rowIndex].mEntryIndices[1], gSelectRaceRule->mBnll,
                GetBmgEntry(selectRaceRule->mRuleMessages,
                            gSelectRaceRuleValueMessageIndices[rowIndex][selectRaceRule->mRowValues[rowIndex]]),
                selectRaceRule->mBncl, selectRaceRule->mTable);
        }
    }
    if (gStartupWork->mConnectionKind != 2) {
        selectRaceRule = gSelectRaceRule;
        remainingSubObjSize -=
            InitLabelCanvas(selectRaceRule->mHeap, 9, selectRaceRule->mBnll, 0x96, 0xf, cellEntryCount + 3,
                            selectRaceRule->mNcer, selectRaceRule->mBncl, selectRaceRule->mTable, remainingSubObjSize);
        selectRaceRule = gSelectRaceRule;
        remainingSubObjSize -=
            InitLabelCanvas(selectRaceRule->mHeap, 0xa, selectRaceRule->mBnll, 0xc8, 0xf, cellEntryCount + 9,
                            selectRaceRule->mNcer, selectRaceRule->mBncl, selectRaceRule->mTable, remainingSubObjSize);
        selectRaceRule = gSelectRaceRule;
        PrintLabelLayoutTextNoFixedAdvance(
            1, 0xa, gSelectRaceRule->mBnll,
            GetBmgEntry(selectRaceRule->mRuleMessages, gSelectRaceRuleValueMessageIndices[3][SELECT_RACE_RULE_FREE]),
            selectRaceRule->mBncl, selectRaceRule->mTable);
    } else {
        selectRaceRule = gSelectRaceRule;
        remainingSubObjSize -=
            InitLabelCanvas(selectRaceRule->mHeap, 0xa, selectRaceRule->mBnll, 0xc8, 0xf, cellEntryCount + 3,
                            selectRaceRule->mNcer, selectRaceRule->mBncl, selectRaceRule->mTable, remainingSubObjSize);
        selectRaceRule = gSelectRaceRule;
        PrintLabelLayoutTextNoFixedAdvance(
            1, 0xa, gSelectRaceRule->mBnll,
            GetBmgEntry(selectRaceRule->mRuleMessages, gSelectRaceRuleValueMessageIndices[3][SELECT_RACE_RULE_FREE]),
            selectRaceRule->mBncl, selectRaceRule->mTable);
    }
    selectRaceRule = gSelectRaceRule;
    remainingSubObjSize -=
        InitLabelCanvas(selectRaceRule->mHeap, 0xc, selectRaceRule->mBnll, 0x37, 0xf, cellEntryCount + 0xb,
                        selectRaceRule->mNcer, selectRaceRule->mBncl, selectRaceRule->mTable, remainingSubObjSize);
    selectRaceRule = gSelectRaceRule;
    PrintLabelLayoutTextNoFixedAdvance(
        1, 0xc, gSelectRaceRule->mBnll,
        GetBmgEntry(selectRaceRule->mRuleMessages, gSelectRaceRuleValueMessageIndices[4][2]), selectRaceRule->mBncl,
        selectRaceRule->mTable);
    if (gStartupWork->mConnectionKind != 2) {
        selectRaceRule = gSelectRaceRule;
        remainingSubObjSize -=
            InitLabelCanvas(selectRaceRule->mHeap, 0xd, selectRaceRule->mBnll, 0x32, 0xd, 0x29, selectRaceRule->mNcer,
                            selectRaceRule->mBncl, selectRaceRule->mTable, remainingSubObjSize);
        selectRaceRule = gSelectRaceRule;
        PrintLabelLayoutTextNoFixedAdvance(1, 0xd, gSelectRaceRule->mBnll,
                                           GetBmgEntry(selectRaceRule->mCommonMessages, 4), selectRaceRule->mBncl,
                                           selectRaceRule->mTable);
        selectRaceRule = gSelectRaceRule;
        InitLabelCanvas(selectRaceRule->mHeap, 8, selectRaceRule->mBnll, 0x15, 0xf, 0x1f, selectRaceRule->mNcer,
                        selectRaceRule->mBncl, selectRaceRule->mTable, remainingSubObjSize);
    } else {
        selectRaceRule = gSelectRaceRule;
        InitLabelCanvas(selectRaceRule->mHeap, 0xe, selectRaceRule->mBnll, 0xc8, 0xd, 0x2a, selectRaceRule->mNcer,
                        selectRaceRule->mBncl, selectRaceRule->mTable, remainingSubObjSize);
    }
    SetAndPrintSelectRaceRuleWinCount(0);
    SetAndPrintSelectRaceRuleRaceCount(0);
    switch (gSelectRaceRule->mMode) {
        case SELECT_RACE_RULE_MODE_VS_MULTI_SIMPLE:
        case SELECT_RACE_RULE_MODE_VS_MULTI:
            ClearNonParticipantCharacterIndices();
            FillRandomCharacterIndices();
            ClearNonParticipantKartIndices();
            FillRandomKartIndices();
            break;
        case SELECT_RACE_RULE_MODE_BATTLE_MULTI_SIMPLE:
        case SELECT_RACE_RULE_MODE_BATTLE_MULTI:
            ClearNonParticipantCharacterIndices();
            FillRandomCharacterIndices();
            ClearNonParticipantKartIndices();
            SetKartIndicesFromCharacters();
            break;
    }
    switch (gSelectRaceRule->mMode) {
        case SELECT_RACE_RULE_MODE_VS_NO_CONNECTION:
        case SELECT_RACE_RULE_MODE_BATTLE_NO_CONNECTION:
            SetupPlayerEntryList(0, PLAYER_ENTRY_LIST_RACE_RULE);
            break;
        case SELECT_RACE_RULE_MODE_VS_MULTI_SIMPLE:
        case SELECT_RACE_RULE_MODE_BATTLE_MULTI_SIMPLE:
        case SELECT_RACE_RULE_MODE_VS_MULTI:
        case SELECT_RACE_RULE_MODE_BATTLE_MULTI:
            SetupPlayerEntryList(1, PLAYER_ENTRY_LIST_RACE_RULE);
            break;
    }
    ReadRaceSetupCopyIntoSelectRaceRule();
    if (IsSelectRaceRuleTeamsValid() == 0) {
        SetSelectRaceRuleHumanCount();
        AssignSelectRaceRuleHumanTeams();
        AssignSelectRaceRuleNonHumanTeams();
    }
    selectRaceRule = gSelectRaceRule;
    switch (selectRaceRule->mMode) {
        case SELECT_RACE_RULE_MODE_VS_NO_CONNECTION:
            selectRaceRule->mRow = SELECT_RACE_RULE_ROW_CPU_DIFFICULTY;
            if (gSelectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_CPU_DIFFICULTY] == 0) {
                MoveSelectRaceRuleValueNext(0);
            }
            gSelectRaceRule->mRow = SELECT_RACE_RULE_ROW_ENGINE;
            break;
        case SELECT_RACE_RULE_MODE_BATTLE_NO_CONNECTION:
            selectRaceRule->mOffsetY = -0x1c;
            gSelectRaceRule->mRow = SELECT_RACE_RULE_ROW_CPU_DIFFICULTY;
            if (gSelectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_CPU_DIFFICULTY] == 0) {
                MoveSelectRaceRuleValueNext(0);
            }
            gSelectRaceRule->mRow = SELECT_RACE_RULE_ROW_RULE_KIND;
            if (gSelectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_RULE_KIND] == SELECT_RACE_RULE_RACE) {
                MoveSelectRaceRuleValuePrevious(0);
            }
            gSelectRaceRule->mRow = SELECT_RACE_RULE_ROW_CPU_DIFFICULTY;
            break;
        case SELECT_RACE_RULE_MODE_VS_MULTI_SIMPLE:
            selectRaceRule->mOffsetY = -0x1c;
            gSelectRaceRule->mRow = SELECT_RACE_RULE_ROW_CPU_DIFFICULTY;
            if (GetSelectRaceRuleHumanCount() == 8) {
                gSelectRaceRule->mRow = SELECT_RACE_RULE_ROW_COURSE_LIST;
            }
            break;
        case SELECT_RACE_RULE_MODE_BATTLE_MULTI_SIMPLE:
            selectRaceRule->mRow = SELECT_RACE_RULE_ROW_RULE_KIND;
            if (gSelectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_RULE_KIND] == SELECT_RACE_RULE_RACE) {
                MoveSelectRaceRuleValuePrevious(0);
            }
            gSelectRaceRule->mRow = SELECT_RACE_RULE_ROW_CPU_DIFFICULTY;
            if (GetSelectRaceRuleHumanCount() == 8) {
                gSelectRaceRule->mRow = SELECT_RACE_RULE_ROW_RULE_KIND;
            }
            break;
        case SELECT_RACE_RULE_MODE_BATTLE_MULTI:
            selectRaceRule->mOffsetY = -0x1c;
            gSelectRaceRule->mRow = SELECT_RACE_RULE_ROW_RULE_KIND;
            if (gSelectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_RULE_KIND] == SELECT_RACE_RULE_RACE) {
                MoveSelectRaceRuleValuePrevious(0);
            }
            gSelectRaceRule->mRow = SELECT_RACE_RULE_ROW_CPU_DIFFICULTY;
            if (GetSelectRaceRuleHumanCount() == 8) {
                gSelectRaceRule->mRow = SELECT_RACE_RULE_ROW_COURSE_LIST;
            }
            break;
    }
    switch (gSelectRaceRule->mMode) {
        case SELECT_RACE_RULE_MODE_BATTLE_NO_CONNECTION:
            gSelectRaceRule
                ->mTable[cellEntryCount + gSelectRaceRuleRowEntries[SELECT_RACE_RULE_ROW_ENGINE].mEntryIndices[0]]
                .mVisible = 0;
            break;
        case SELECT_RACE_RULE_MODE_VS_MULTI_SIMPLE:
            gSelectRaceRule
                ->mTable[cellEntryCount + gSelectRaceRuleRowEntries[SELECT_RACE_RULE_ROW_ENGINE].mEntryIndices[0]]
                .mVisible = 0;
            break;
        case SELECT_RACE_RULE_MODE_BATTLE_MULTI_SIMPLE:
            gSelectRaceRule
                ->mTable[cellEntryCount + gSelectRaceRuleRowEntries[SELECT_RACE_RULE_ROW_ENGINE].mEntryIndices[0]]
                .mVisible = 0;
            gSelectRaceRule
                ->mTable[cellEntryCount + gSelectRaceRuleRowEntries[SELECT_RACE_RULE_ROW_COURSE_LIST].mEntryIndices[0]]
                .mVisible = 0;
            gSelectRaceRule
                ->mTable[cellEntryCount + gSelectRaceRuleRowEntries[SELECT_RACE_RULE_ROW_ENGINE].mEntryIndices[1]]
                .mVisible = 0;
            gSelectRaceRule
                ->mTable[cellEntryCount + gSelectRaceRuleRowEntries[SELECT_RACE_RULE_ROW_COURSE_LIST].mEntryIndices[1]]
                .mVisible = 0;
            for (columnIndex = 0; columnIndex < 2; columnIndex++) {
                gSelectRaceRule->mTable[gSelectRaceRuleStepCellsHighlighted[0][columnIndex]].mVisible = 0;
                gSelectRaceRule->mTable[gSelectRaceRuleStepCellsHighlighted[2][columnIndex]].mVisible = 0;
                gSelectRaceRule->mTable[gSelectRaceRuleStepCellsChanging[0][columnIndex]].mVisible = 0;
                gSelectRaceRule->mTable[gSelectRaceRuleStepCellsChanging[2][columnIndex]].mVisible = 0;
                gSelectRaceRule->mTable[gSelectRaceRuleStepCellsPlain[0][columnIndex]].mVisible = 0;
                gSelectRaceRule->mTable[gSelectRaceRuleStepCellsPlain[2][columnIndex]].mVisible = 0;
            }
            break;
        case SELECT_RACE_RULE_MODE_BATTLE_MULTI:
            gSelectRaceRule
                ->mTable[cellEntryCount + gSelectRaceRuleRowEntries[SELECT_RACE_RULE_ROW_ENGINE].mEntryIndices[0]]
                .mVisible = 0;
            break;
    }
    if (GetSelectRaceRuleHumanCount() == 8 && gSelectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_CPU_DIFFICULTY] != 0) {
        do {
            MoveSelectRaceRuleValuePrevious(0);
        } while (gSelectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_CPU_DIFFICULTY] != 0);
    }
    ResetSelectRaceRulePositions();
    selectRaceRule = gSelectRaceRule;
    CreateWait(selectRaceRule->mHeap, selectRaceRule->mNcer, selectRaceRule->mBncl, 0x2a, 0xe, 1);
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        InitPaletteBlend(gSelectRaceRule->mHeap, gSelectRaceRule->mNclr, 9);
    }
    FrmHeapShrinkInParent(gSelectRaceRule->mHeap);
    AdvanceSelectRaceRuleHighlight();
}

void ReleaseSelectRaceRule(void) {
    SelectRaceRule *selectRaceRule;
    u32 dispcntBits8To12;
    u32 bg2Control;
    selectRaceRule = gSelectRaceRule;
    if (selectRaceRule->mResult == 1 && (selectRaceRule->mMode == SELECT_RACE_RULE_MODE_BATTLE_MULTI_SIMPLE ||
                                         selectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_COURSE_LIST] == 1)) {
        dispcntBits8To12 = ((reg_GX_DISPCNT) & REG_GX_DISPCNT_DISPLAY_MASK) >> 8;
        dispcntBits8To12 &= ~3;
        (reg_GX_DISPCNT) = ((reg_GX_DISPCNT) & ~REG_GX_DISPCNT_DISPLAY_MASK) | (dispcntBits8To12 << 8);
    }
    bg2Control = (reg_G2_BG2CNT);
    bg2Control &= ~3;
    (reg_G2_BG2CNT) = bg2Control;
    (reg_G2_BG2CNT) = ((reg_G2_BG2CNT) & (REG_G2_BG2CNT_PRIORITY_MASK | REG_G2_BG2CNT_MOSAIC_MASK)) | 0x9e10;
    ClearWaitPointer();
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        ClearPaletteBlendPointer();
    }
    HeapDestroy(gSelectRaceRule->mHeap);
    gSelectRaceRule = NULL;
}

#pragma thumb off

#pragma thumb on

void AdvanceSelectRaceRuleState0(void) {
    int fadesClear;
    fadesClear = AreBrightnessFadesClear();
    if (fadesClear != 0) {
        RequestSelectRaceRuleState1();
    }
}

#pragma thumb off

#pragma thumb on

void AdvanceSelectRaceRuleState1(void) {
    SelectRaceRule *selectRaceRule;
    s32 rowIndex;
    s16 rowsOffsetY;
    s32 columnIndex;
    s32 value;
    AdvanceSelectRaceRuleRowObjects();
    AdvanceSelectRaceRuleChangeObjects();
    gSelectRaceRule->mStateFrames++;
    selectRaceRule = gSelectRaceRule;
    value = InterpolateS16(1, -192, 0, selectRaceRule->mStateFrames, SELECT_RACE_RULE_SLIDE_STEPS);
    rowsOffsetY = selectRaceRule->mOffsetY + value;
    selectRaceRule->mBg3Offset = rowsOffsetY;
    value = gSelectRaceRule->mBncl->mCount;
    for (rowIndex = 0; rowIndex < 5; rowIndex++) {
        for (columnIndex = 0; columnIndex < 2; columnIndex++) {
            gSelectRaceRule->mTable[gSelectRaceRuleStepCellsHighlighted[rowIndex][columnIndex]].mOffsetY = rowsOffsetY;
            gSelectRaceRule->mTable[gSelectRaceRuleStepCellsChanging[rowIndex][columnIndex]].mOffsetY = rowsOffsetY;
            gSelectRaceRule->mTable[gSelectRaceRuleStepCellsPlain[rowIndex][columnIndex]].mOffsetY = rowsOffsetY;
        }
        for (columnIndex = 0; columnIndex < 2; columnIndex++) {
            gSelectRaceRule->mTable[value + gSelectRaceRuleRowEntries[rowIndex].mEntryIndices[columnIndex]].mOffsetY =
                rowsOffsetY;
        }
    }
    gSelectRaceRule->mTable[value + 10].mOffsetY = rowsOffsetY;
    gSelectRaceRule->mTable[value + 12].mOffsetY = rowsOffsetY;
    gSelectRaceRule->mTable[34].mOffsetY = rowsOffsetY;
    gSelectRaceRule->mTable[37].mOffsetY = rowsOffsetY;
    gSelectRaceRule->mTable[35].mOffsetY = rowsOffsetY;
    gSelectRaceRule->mTable[38].mOffsetY = rowsOffsetY;
    for (rowIndex = 0; rowIndex < 2; rowIndex++) {
        for (columnIndex = 0; columnIndex < 2; columnIndex++) {
            gSelectRaceRule->mTable[gSelectRaceRuleCountTeamChangeCells[rowIndex][columnIndex]].mOffsetY = rowsOffsetY;
        }
    }
    if (gStartupWork->mConnectionKind != 2) {
        value += 8;
        gSelectRaceRule->mTable[value].mOffsetY = rowsOffsetY;
        gSelectRaceRule->mTable[30].mOffsetY = rowsOffsetY;
        gSelectRaceRule->mTable[31].mOffsetY = rowsOffsetY;
    }
    if (gSelectRaceRule->mStateFrames >= SELECT_RACE_RULE_SLIDE_STEPS) {
        RequestSelectRaceRuleState2();
    }
}

void AdvanceSelectRaceRuleState2(void) {
    s16 returnOffsetY;
    s32 cellEntryCount;
    AdvanceSelectRaceRuleRowObjects();
    AdvanceSelectRaceRuleChangeObjects();
    gSelectRaceRule->mStateFrames++;
    returnOffsetY = -LookupSelectReturnState1Bg2Offset(gSelectRaceRule->mStateFrames);
    cellEntryCount = gSelectRaceRule->mBncl->mCount;
    if (gStartupWork->mConnectionKind != 2) {
        gSelectRaceRule->mTable[0x28].mOffsetY = returnOffsetY;
        gSelectRaceRule->mTable[0x29].mOffsetY = returnOffsetY;
        gSelectRaceRule->mTable[cellEntryCount + 13].mOffsetY = returnOffsetY;
    } else {
        gSelectRaceRule->mTable[0x2a].mOffsetY = returnOffsetY;
        gSelectRaceRule->mTable[cellEntryCount + 14].mOffsetY = returnOffsetY;
    }
    switch (gSelectRaceRule->mMode) {
        case SELECT_RACE_RULE_MODE_VS_NO_CONNECTION:
        case SELECT_RACE_RULE_MODE_BATTLE_NO_CONNECTION:
            if (gSelectRaceRule->mStateFrames >= SELECT_RACE_RULE_SLIDE_STEPS &&
                IsSelectReturnState2NoState3Or4Request() != 0) {
                RequestSelectRaceRuleState3();
                return;
            }
            break;
        default:
            if (gSelectRaceRule->mStateFrames >= SELECT_RACE_RULE_SLIDE_STEPS) {
                RequestSelectRaceRuleState3();
            }
            break;
    }
}

void AdvanceSelectRaceRuleState3(void) {
    InputSlotAtHasPair *hasPairSlot;
    InputSlotAtPairX *pairXSlot;
    InputSlotAtPairY *pairYSlot;
    InputSlot *slot;
    u32 hitRectIndex;
    BOOL newPair;
    BOOL noPairForFewCalls;
    InputSlotIndex inputIndex;
    u32 row;
    u16 hasPair;
    hitRectIndex = -1;
    inputIndex = UNK_02175628_INDEX_8;
    AdvanceSelectRaceRuleRowObjects();
    AdvanceSelectRaceRuleChangeObjects();
    newPair = FALSE;
    noPairForFewCalls = FALSE;
    hasPairSlot = &gInputHasPairs[inputIndex];
    hasPair = gInputHasPairs[inputIndex].mHasPair;
    if (hasPair == 0 && gInputNoPairCounts[inputIndex].mNoPairCount < 5) {
        noPairForFewCalls = TRUE;
    }
    if (noPairForFewCalls == FALSE && gInputPrevHasPairs[inputIndex].mPrevHasPair == 0 && hasPair != 0) {
        newPair = TRUE;
    }
    if (newPair != FALSE) {
        pairYSlot = &gInputPairYs[inputIndex];
        pairXSlot = &gInputPairXs[inputIndex];
        hitRectIndex = RectTableFindContaining(gSelectRaceRule->mBnbl, gInputPairXs[inputIndex].mPairX,
                                               gInputPairYs[inputIndex].mPairY);
        if (hitRectIndex != 0x13) {
            hitRectIndex = RectTableFindContaining(gSelectRaceRule->mBnbl, pairXSlot->mPairX,
                                                   pairYSlot->mPairY - gSelectRaceRule->mOffsetY);
            if (hitRectIndex == 0x13) {
                hitRectIndex = -1;
            }
        }
    }
    slot = &gInputSlots[inputIndex];
    if ((u16) (slot->mPressedBits & PAD_KEY_B) == 0) {
        newPair = FALSE;
        noPairForFewCalls = FALSE;
        hasPair = hasPairSlot->mHasPair;
        if (hasPair == 0 && gInputNoPairCounts[inputIndex].mNoPairCount < 5) {
            noPairForFewCalls = TRUE;
        }
        if (noPairForFewCalls == FALSE && gInputPrevHasPairs[inputIndex].mPrevHasPair == 0 && hasPair != 0) {
            newPair = TRUE;
        }
        if (newPair == FALSE || IsSelectReturnState2NoState3Or4RequestAndInRect(gInputPairXs[inputIndex].mPairX,
                                                                                gInputPairYs[inputIndex].mPairY) == 0) {
            goto chain;
        }
    }
    switch (gSelectRaceRule->mMode) {
        case SELECT_RACE_RULE_MODE_VS_NO_CONNECTION:
        case SELECT_RACE_RULE_MODE_BATTLE_NO_CONNECTION:
            SetSelectReturnSoundId(0xe);
            RequestSelectRaceRuleState8();
            gSelectRaceRule->mResult = 2;
            RequestSelectReturnState3WithSound(0);
            StartPlayerEntryListKind(1);
            break;
    }
    goto end;
chain:
    if (hitRectIndex <= 4) {
        row = gSelectRaceRulePreviousRectRows[hitRectIndex];
        if (GetSelectRaceRuleHumanCount() != 8 || row != 1) {
            gSelectRaceRule->mRow = row;
            gSelectRaceRule->mOnButton = 0;
            MoveSelectRaceRuleValuePrevious(1);
        }
    } else if (hitRectIndex - 5 <= 4) {
        row = (gSelectRaceRuleNextRectRows - 5)[hitRectIndex];
        if (GetSelectRaceRuleHumanCount() != 8 || row != 1) {
            gSelectRaceRule->mRow = row;
            gSelectRaceRule->mOnButton = 0;
            MoveSelectRaceRuleValueNext(1);
        }
    } else if (hitRectIndex == 0x13) {
        if (gSelectRaceRule->mOnButton != 0) {
            gSelectRaceRule->mButtonHighlightShown = 0;
        }
        gSelectRaceRule->mOnButton = 1;
        RequestSelectRaceRuleState4();
    } else if (hitRectIndex - 10 <= 4) {
        row = (gSelectRaceRuleRowRectRows - 10)[hitRectIndex];
        if (GetSelectRaceRuleHumanCount() != 8 || row != 1) {
            gSelectRaceRule->mRow = row;
            gSelectRaceRule->mOnButton = 0;
            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0);
        }
    } else if ((u16) (slot->mPressedBits & PAD_KEY_A) != 0) {
        if (gSelectRaceRule->mOnButton != 0) {
            RequestSelectRaceRuleState4();
            gSelectRaceRule->mButtonHighlightShown = 0;
        } else {
            MoveSelectRaceRuleRowNext();
        }
    } else if (hitRectIndex == 0xf) {
        if (gSelectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_RULE_KIND] != SELECT_RACE_RULE_FREE) {
            gSelectRaceRule->mRow = SELECT_RACE_RULE_ROW_RULE_KIND;
            gSelectRaceRule->mOnButton = 0;
            DecrementSelectRaceRuleCourseCount();
        }
    } else if (hitRectIndex == 0x10) {
        if (gSelectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_RULE_KIND] != SELECT_RACE_RULE_FREE) {
            gSelectRaceRule->mRow = SELECT_RACE_RULE_ROW_RULE_KIND;
            gSelectRaceRule->mOnButton = 0;
            IncrementSelectRaceRuleCourseCount();
        }
    } else if (GetNewOrRepeatBits(8, PAD_KEY_UP) != 0) {
        MoveSelectRaceRuleRowPrevious();
    } else if (GetNewOrRepeatBits(8, PAD_KEY_DOWN) != 0) {
        MoveSelectRaceRuleRowNext();
    } else if (GetNewOrRepeatBits(8, PAD_KEY_LEFT) != 0) {
        if (gSelectRaceRule->mOnButton == 0) {
            MoveSelectRaceRuleValuePrevious(1);
        }
    } else if (GetNewOrRepeatBits(8, PAD_KEY_RIGHT) != 0) {
        if (gSelectRaceRule->mOnButton == 0) {
            MoveSelectRaceRuleValueNext(1);
        }
    } else if (GetNewOrRepeatBits(8, PAD_KEY_L) != 0) {
        DecrementSelectRaceRuleCourseCount();
    } else if (GetNewOrRepeatBits(8, PAD_KEY_R) != 0) {
        IncrementSelectRaceRuleCourseCount();
    }
end:
    if (gSelectRaceRule->mNextState != SELECT_RACE_RULE_STATE_WAIT_PRESS) {
        AdvanceSelectRaceRuleTeamInput();
    }
}

void AdvanceSelectRaceRuleState4(void) {
    AdvanceSelectRaceRuleRowObjects();
    AdvanceSelectRaceRuleChangeObjects();
    gSelectRaceRule->mStateFrames++;
    if (gSelectRaceRule->mStateFrames == SELECT_RACE_RULE_HIGHLIGHT_STEP) {
        gSelectRaceRule->mButtonHighlightShown = 1;
    }
    if (gSelectRaceRule->mStateFrames >= SELECT_RACE_RULE_PRESS_STEPS) {
        if (gSelectRaceRule->mMode == SELECT_RACE_RULE_MODE_BATTLE_MULTI_SIMPLE ||
            gSelectRaceRule->mRowValues[SELECT_RACE_RULE_ROW_COURSE_LIST] == 1) {
            RequestSelectRaceRuleState5();
            return;
        }
        RequestSelectRaceRuleState8();
        gSelectRaceRule->mResult = 1;
        StartPlayerEntryListKind(3);
    }
}

#pragma thumb off

#pragma thumb on

void AdvanceSelectRaceRuleState5(void) {
    int state1WithoutRequest;
    state1WithoutRequest = IsSelectChoisesState1NoState0Request();
    if (state1WithoutRequest != 0) {
        RequestSelectRaceRuleState6();
    }
}

#pragma thumb off
