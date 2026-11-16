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
    SetGivenCharacterAndKart(g_GlobalB43C->mCharacterKartPicks, 0, GetGlobalCA_from_thumb()->mEntries[0].mCharacterIndex,
                             GetGlobalCA_from_thumb()->mEntries[0].mKartIndex);
    PickRandomCharactersAndKarts(g_GlobalB43C->mCharacterKartPicks);
    StructCO_ConfigureRacerDefault(0, GetGlobalCA_from_thumb()->mEntries[0].mCharacterIndex, GetGlobalCA_from_thumb()->mEntries[0].mKartIndex, 0,
                     -1, 3);
    for (entryIndex = 1; entryIndex < 8; entryIndex++) {
        GetEntryCharacterAndKart(g_GlobalB43C->mCharacterKartPicks, entryIndex, &characterIndex, &kartIndex);
        StructCO_ConfigureRacerDefault(entryIndex, characterIndex, kartIndex, 1, -1,
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
    setupCopy = GetGlobalCA_from_thumb();
    setupCopyForKart = GetGlobalCA_from_thumb();
    StructCO_ConfigureRacerDefault(0, setupCopy->mEntries[0].mCharacterIndex, setupCopyForKart->mEntries[0].mKartIndex, 0, 0xffffffff,
                     3);
    entryIndex = 1;
    do {
        SetNextRaceEntryNone(entryIndex);
        entryIndex = entryIndex + 1;
    } while (entryIndex < 8);
}

#pragma thumb off

void SetNextRaceEntryNone(u32 entryIndex) {
    StructCO_ConfigureRacerDefault(entryIndex, 0xffffffff, 0xffffffff, 4, 0xffffffff, 3);
}

#pragma optimize_for_size on
#pragma thumb on
void SetNextRaceEntriesFromRaceSetupCopy(void) {
    u8 entryIndex;
    s32 teamIndex;

    for (entryIndex = 0; entryIndex < 8; entryIndex++) {
        if (GetGlobalCA_from_thumb()->mCpuDifficulty == 0 && GetGlobalCA_from_thumb()->mEntries[entryIndex].mPlayerKind == 1) {
            SetNextRaceEntryNone(entryIndex);
        } else {
            teamIndex = GetGlobalCA_from_thumb()->mUseTeams != 0 ? GetGlobalCA_from_thumb()->mEntries[entryIndex].mTeamIndex : -1;
            StructCO_ConfigureRacerDefault(entryIndex, GetGlobalCA_from_thumb()->mEntries[entryIndex].mCharacterIndex,
                             GetGlobalCA_from_thumb()->mEntries[entryIndex].mKartIndex,
                             GetGlobalCA_from_thumb()->mEntries[entryIndex].mPlayerKind, teamIndex,
                             GetGlobalCA_from_thumb()->mEntries[entryIndex].mListedCpuSlot);
        }
    }
}
#pragma thumb off

void SetNextCpuMode(u32 cpuDifficulty) {
    g_GlobalCO->mNextHeader.mCpuDifficulty = cpuDifficulty;
}

void SetNextRaceMode(u32 mode) {
    g_GlobalCO->mNextHeader.mMode = mode;
}

void SetNextCupId(u32 cupIndex) {
    g_GlobalCO->mNextHeader.mCupIndex = cupIndex;
}

void SetNextCourse(u32 courseId) {
    g_GlobalCO->mNextHeader.mCourseId = courseId;
}

void SetNextCcMode(u32 engineIndex) {
    g_GlobalCO->mNextHeader.mEngineIndex = engineIndex;
}

void SetNextMirrorMode(u32 mirrorMode) {
    g_GlobalCO->mNextHeader.mMirrorMode = (u8) mirrorMode;
}

void SetNextTimeTrialGhost(u32 ghostRecordIndex) {
    g_GlobalCO->mNextHeader.mGhostRecordIndex = ghostRecordIndex;
}

void SetNextBattleMode(u32 battleKind) {
    g_GlobalCO->mNextHeader.mBattleKind = battleKind;
}

void SetNextTeamMode(u32 useTeams) {
    g_GlobalCO->mNextHeader.mUseTeams = useTeams;
}

void MaybeSetNextRuleParam(u32 courseCount) {
    g_GlobalCO->mCourseCount = courseCount;
}

void SetNextRules(u32 ruleKind) {
    g_GlobalCO->mNextHeader.mRuleKind = ruleKind;
}

void SetNextCourseMode(u32 courseListMode) {
    g_GlobalCO->mNextHeader.mCourseListMode = courseListMode;
}

void SetResultArchiveDl(u32 resultArchiveDl) {
    g_GlobalB488->mResultArchiveDl = resultArchiveDl;
}

u32 GetRaceSetupRequested(void) {
    return (g_GlobalB488->mRaceSetupRequested);
}

#pragma thumb on
#pragma optimize_for_size on
// Copies the menu picks from the race setup copy into the next setup (entry kind 2: only the cup and course), then
// prepares the CPU numbers and course list when a race setup was requested.
void SetNextRaceSetupFromCopy(void) {
    u16 rowIndex;
    u8 tableRowColumn[2];

    if (GetB488_SinglePlayerMenuTarget() != 2) {
        if (GetGlobalCA_from_thumb()->mMode == MODE_GRAND_PRIX) {
            switch (GetGlobalCA_from_thumb()->mEngineIndex) {
                case ENGINE_CLASS_SLOW:
                    GetGlobalCA_from_thumb()->mCpuDifficulty = CPU_DIFFICULTY_EASY;
                    break;
                case ENGINE_CLASS_MEDIUM:
                    GetGlobalCA_from_thumb()->mCpuDifficulty = CPU_DIFFICULTY_NORMAL;
                    break;
                case ENGINE_CLASS_FAST:
                    GetGlobalCA_from_thumb()->mCpuDifficulty = CPU_DIFFICULTY_HARD;
                    break;
            }
        }
        SetNextCpuMode(GetGlobalCA_from_thumb()->mCpuDifficulty);
        if (GetGlobalCA_from_thumb()->mMode != MODE_BATTLE && GetGlobalCA_from_thumb()->mMode != MODE_VS) {
            GetGlobalCA_from_thumb()->mUseTeams = 0;
        }
        switch (GetGlobalCA_from_thumb()->mMode) {
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
        SetNextRaceMode(GetGlobalCA_from_thumb()->mMode);
        SetNextCupId(GetGlobalCA_from_thumb()->mCupIndex);
        if (GetGlobalCA_from_thumb()->mMode == MODE_GRAND_PRIX) {
            GetGlobalCA_from_thumb()->mCourseId = GetCupCourseId(GetGlobalCA_from_thumb()->mCupIndex, 0);
        }
        SetNextCourse(GetGlobalCA_from_thumb()->mCourseId);
        if (GetGlobalCA_from_thumb()->mMode == MODE_TIME_ATTACK) {
            GetGlobalCA_from_thumb()->mEngineIndex = ENGINE_CLASS_FAST;
        } else if (GetGlobalCA_from_thumb()->mMode == MODE_BATTLE) {
            GetGlobalCA_from_thumb()->mEngineIndex = ENGINE_CLASS_SLOW;
        } else if (GetGlobalCA_from_thumb()->mMode == MODE_VS) {
            if (GetPMaybeState_1() != CONNECTION_KIND_NONE && GetMultiSimple() != 0) {
                GetGlobalCA_from_thumb()->mEngineIndex = ENGINE_CLASS_MEDIUM;
            }
        }
        SetNextCcMode(GetGlobalCA_from_thumb()->mEngineIndex);
        SetNextMirrorMode(GetGlobalCA_from_thumb()->mMirrorMode);
        SetNextTimeTrialGhost(GetGlobalCA_from_thumb()->mGhostRecordIndex);
        SetNextBattleMode(GetGlobalCA_from_thumb()->mBattleKind);
        SetNextTeamMode(GetGlobalCA_from_thumb()->mUseTeams);
        MaybeSetNextRuleParam(GetGlobalCA_from_thumb()->mCourseCount);
        SetNextRules(GetGlobalCA_from_thumb()->mRuleKind);
        SetNextCourseMode(GetGlobalCA_from_thumb()->mCourseListMode);
        if (GetGlobalCA_from_thumb()->mMode == MODE_MISSION_RUN && j_IsDwc_0() == 0) {
            rowIndex = GetGlobalCA_from_thumb()->mMissionFileRowIndex;
            FindMissionTableCell(GetGlobalCA_from_thumb()->mMissionFileRows[rowIndex].mMissionTableValue, &tableRowColumn[0],
                                 &tableRowColumn[1]);
            SetNextRaceFromMissionRow(&GetGlobalCA_from_thumb()->mMissionFileRows[rowIndex], tableRowColumn[0],
                                      tableRowColumn[1]);
        }
    } else {
        SetNextCupId(GetGlobalCA_from_thumb()->mCupIndex);
        SetNextCourse(GetGlobalCA_from_thumb()->mCourseId);
    }
    if (GetGlobalCA_from_thumb()->mMode == MODE_GRAND_PRIX) {
        SetResultArchiveDl(0);
    } else {
        SetResultArchiveDl(1);
    }
    if (GetRaceSetupRequested() != 0) {
        AssignCpuNumbersAndSetupFirstCourse();
        SetB488_B2(0);
    }
}
#pragma thumb off
