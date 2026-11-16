#include "Main/Menu/next.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Race/random_pick.h"
#include "Main/Race/entry_character_kart.h"
#include "Main/Graphics/oam.h"
#include "Main/Menu/single_play_select_screen3.h"
#include "Main/Race/race_setup.h"
#include "Main/Menu/select_kart_ghost_work.h"
#include "Main/System/interpolation_value.h"
#include "Main/System/heap_call.h"
#include "font_glyph_layout.h"
#include "Main/Graphics/cell_file_set.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Menu/multi_select_member_group.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Save/buddy_record_time.h"
#include "cell_transfer_state.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/Race/race_setup_input.h"
#include "Main/Menu/menu.h"
#include "Main/Menu/multi_simple.h"
#include "Main/Menu/menu_connection_kind.h"
#include "Main/Menu/menu_shared_clear.h"

#pragma thumb on
void SetNextGrandPrixEntries(void) {
    u8 entryIndex;
    s32 firstPick;
    s32 secondPick;
    u32 characterIndex;
    u32 kartIndex;

    firstPick = NextRandomBelowByConnectionKind(7) + 1;
    secondPick = NextRandomBelowByConnectionKind(6) + 1;
    if (firstPick <= secondPick) {
        secondPick++;
    }
    SetGivenCharacterAndKart(gMenuScene->mCharacterKartPicks, 0, GetRaceSetupCopy()->mEntries[0].mCharacterIndex,
                             GetRaceSetupCopy()->mEntries[0].mKartIndex);
    PickRandomCharactersAndKarts(gMenuScene->mCharacterKartPicks);
    SetNextRaceEntry(0, GetRaceSetupCopy()->mEntries[0].mCharacterIndex, GetRaceSetupCopy()->mEntries[0].mKartIndex,
                     PLAYER_KIND_HUMAN, -1, 3);
    for (entryIndex = 1; entryIndex < 8; entryIndex++) {
        GetEntryCharacterAndKart(gMenuScene->mCharacterKartPicks, entryIndex, &characterIndex, &kartIndex);
        SetNextRaceEntry(entryIndex, characterIndex, kartIndex, PLAYER_KIND_CPU, -1,
                         entryIndex == firstPick    ? 0
                         : entryIndex == secondPick ? 1
                                                    : 3);
    }
}
#pragma thumb off

#pragma thumb on

void SetNextTimeAttackEntries(void) {
    u8 entryIndex;
    RaceSetupCopy *setupCopy;
    RaceSetupCopy *setupCopyForKart;
    setupCopy = GetRaceSetupCopy();
    setupCopyForKart = GetRaceSetupCopy();
    SetNextRaceEntry(0, setupCopy->mEntries[0].mCharacterIndex, setupCopyForKart->mEntries[0].mKartIndex,
                     PLAYER_KIND_HUMAN, 0xffffffff, 3);
    entryIndex = 1;
    do {
        SetNextRaceEntryNone(entryIndex);
        entryIndex = entryIndex + 1;
    } while (entryIndex < 8);
}

#pragma thumb off

void SetNextRaceEntryNone(u32 entryIndex) {
    SetNextRaceEntry(entryIndex, 0xffffffff, 0xffffffff, PLAYER_KIND_NONE, 0xffffffff, 3);
}

#pragma optimize_for_size on
#pragma thumb on
void SetNextRaceEntriesFromRaceSetupCopy(void) {
    u8 entryIndex;
    s32 teamIndex;

    for (entryIndex = 0; entryIndex < 8; entryIndex++) {
        if (GetRaceSetupCopy()->mCpuDifficulty == 0 &&
            GetRaceSetupCopy()->mEntries[entryIndex].mPlayerKind == PLAYER_KIND_CPU) {
            SetNextRaceEntryNone(entryIndex);
        } else {
            teamIndex = GetRaceSetupCopy()->mUseTeams != 0 ? GetRaceSetupCopy()->mEntries[entryIndex].mTeamIndex : -1;
            SetNextRaceEntry(entryIndex, GetRaceSetupCopy()->mEntries[entryIndex].mCharacterIndex,
                             GetRaceSetupCopy()->mEntries[entryIndex].mKartIndex,
                             GetRaceSetupCopy()->mEntries[entryIndex].mPlayerKind, teamIndex,
                             GetRaceSetupCopy()->mEntries[entryIndex].mListedCpuSlot);
        }
    }
}
#pragma thumb off

void SetNextCpuDifficulty(u32 cpuDifficulty) {
    gRaceSetup->mNextHeader.mCpuDifficulty = cpuDifficulty;
}

void SetNextMode(u32 mode) {
    gRaceSetup->mNextHeader.mMode = mode;
}

void SetNextCupIndex(u32 cupIndex) {
    gRaceSetup->mNextHeader.mCupIndex = cupIndex;
}

void SetNextCourseId(u32 courseId) {
    gRaceSetup->mNextHeader.mCourseId = courseId;
}

void SetNextEngineIndex(u32 engineIndex) {
    gRaceSetup->mNextHeader.mEngineIndex = engineIndex;
}

void SetNextMirrorMode(u32 mirrorMode) {
    gRaceSetup->mNextHeader.mMirrorMode = (u8) mirrorMode;
}

void SetNextGhostRecordIndex(u32 ghostRecordIndex) {
    gRaceSetup->mNextHeader.mGhostRecordIndex = ghostRecordIndex;
}

void SetNextBattleKind(u32 battleKind) {
    gRaceSetup->mNextHeader.mBattleKind = battleKind;
}

void SetNextUseTeams(u32 useTeams) {
    gRaceSetup->mNextHeader.mUseTeams = useTeams;
}

void SetCourseCount(u32 courseCount) {
    gRaceSetup->mCourseCount = courseCount;
}

void SetNextRuleKind(u32 ruleKind) {
    gRaceSetup->mNextHeader.mRuleKind = ruleKind;
}

void SetNextCourseListMode(u32 courseListMode) {
    gRaceSetup->mNextHeader.mCourseListMode = courseListMode;
}

void SetResultArchiveDl(u32 resultArchiveDl) {
    gMenuShared->mResultArchiveDl = resultArchiveDl;
}

u32 GetRaceSetupRequested(void) {
    return (gMenuShared->mRaceSetupRequested);
}

#pragma thumb on
#pragma optimize_for_size on
// Copies the menu picks from the race setup copy into the next setup (entry kind 2: only the cup and course), then
// prepares the CPU numbers and course list when a race setup was requested.
void SetNextRaceSetupFromCopy(void) {
    u16 rowIndex;
    u8 tableRowColumn[2];

    if (GetMenuEntryKind() != 2) {
        if (GetRaceSetupCopy()->mMode == MODE_GRAND_PRIX) {
            switch (GetRaceSetupCopy()->mEngineIndex) {
                case ENGINE_CLASS_SLOW:
                    GetRaceSetupCopy()->mCpuDifficulty = CPU_DIFFICULTY_EASY;
                    break;
                case ENGINE_CLASS_MEDIUM:
                    GetRaceSetupCopy()->mCpuDifficulty = CPU_DIFFICULTY_NORMAL;
                    break;
                case ENGINE_CLASS_FAST:
                    GetRaceSetupCopy()->mCpuDifficulty = CPU_DIFFICULTY_HARD;
                    break;
            }
        }
        SetNextCpuDifficulty(GetRaceSetupCopy()->mCpuDifficulty);
        if (GetRaceSetupCopy()->mMode != MODE_BATTLE && GetRaceSetupCopy()->mMode != MODE_VS) {
            GetRaceSetupCopy()->mUseTeams = 0;
        }
        switch (GetRaceSetupCopy()->mMode) {
            case MODE_GRAND_PRIX:
                SetNextGrandPrixEntries();
                break;
            case MODE_TIME_ATTACK:
                SetNextTimeAttackEntries();
                break;
            case MODE_BATTLE:
            case MODE_VS:
            case MODE_MISSION_RUN:
                SetNextRaceEntriesFromRaceSetupCopy();
                break;
        }
        SetNextMode(GetRaceSetupCopy()->mMode);
        SetNextCupIndex(GetRaceSetupCopy()->mCupIndex);
        if (GetRaceSetupCopy()->mMode == MODE_GRAND_PRIX) {
            GetRaceSetupCopy()->mCourseId = GetCupCourseId(GetRaceSetupCopy()->mCupIndex, 0);
        }
        SetNextCourseId(GetRaceSetupCopy()->mCourseId);
        if (GetRaceSetupCopy()->mMode == MODE_TIME_ATTACK) {
            GetRaceSetupCopy()->mEngineIndex = ENGINE_CLASS_FAST;
        } else if (GetRaceSetupCopy()->mMode == MODE_BATTLE) {
            GetRaceSetupCopy()->mEngineIndex = ENGINE_CLASS_SLOW;
        } else if (GetRaceSetupCopy()->mMode == MODE_VS) {
            if (MenuGetConnectionKind() != CONNECTION_KIND_NONE && GetMultiSimple() != 0) {
                GetRaceSetupCopy()->mEngineIndex = ENGINE_CLASS_MEDIUM;
            }
        }
        SetNextEngineIndex(GetRaceSetupCopy()->mEngineIndex);
        SetNextMirrorMode(GetRaceSetupCopy()->mMirrorMode);
        SetNextGhostRecordIndex(GetRaceSetupCopy()->mGhostRecordIndex);
        SetNextBattleKind(GetRaceSetupCopy()->mBattleKind);
        SetNextUseTeams(GetRaceSetupCopy()->mUseTeams);
        SetCourseCount(GetRaceSetupCopy()->mCourseCount);
        SetNextRuleKind(GetRaceSetupCopy()->mRuleKind);
        SetNextCourseListMode(GetRaceSetupCopy()->mCourseListMode);
        if (GetRaceSetupCopy()->mMode == MODE_MISSION_RUN && MenuMB_IsMultiBootChildWrapper() == 0) {
            rowIndex = GetRaceSetupCopy()->mMissionFileRowIndex;
            FindMissionTableCell(GetRaceSetupCopy()->mMissionFileRows[rowIndex].mMissionTableValue, &tableRowColumn[0],
                                 &tableRowColumn[1]);
            SetNextRaceFromMissionRow(&GetRaceSetupCopy()->mMissionFileRows[rowIndex], tableRowColumn[0],
                                      tableRowColumn[1]);
        }
    } else {
        SetNextCupIndex(GetRaceSetupCopy()->mCupIndex);
        SetNextCourseId(GetRaceSetupCopy()->mCourseId);
    }
    if (GetRaceSetupCopy()->mMode == MODE_GRAND_PRIX) {
        SetResultArchiveDl(0);
    } else {
        SetResultArchiveDl(1);
    }
    if (GetRaceSetupRequested() != 0) {
        AssignCpuNumbersAndSetupFirstCourse();
        SetRaceSetupRequested(0);
    }
}
#pragma thumb off
