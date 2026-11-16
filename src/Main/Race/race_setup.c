#include "Main/Race/race_setup.h"
#include "Main/System/heap.h"
#include "Main/Menu/select_kart_ghost_work.h"
#include "Main/Race/mission_file_row.h"
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
#include "cpu_copy_fill.h"
#include "Main/System/result_archive_path.h"
#include "Main/Graphics/animation_function_pointers.h"
#include "Main/Menu/select_race_rule_state.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Net/wifi_race_sync_advance.h"
#include "Main/Net/packed_index.h"
#include "Main/Net/wifi_session_karts.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/Menu/menu_shared_clear.h"

RaceSetupCopy *g_GlobalCA;

#pragma thumb on

void InitializeGlobalCA_from_thumb(void *heap) {
    g_GlobalCA = Mem_AllocateHeap(heap, (0x00000110u));
    DoInitializeGlobalCA_from_thumb();
}

#pragma thumb off

void Mem_CpuFastMemorySet2(void *destination, u32 value, u32 size) {
    volatile u32 valueCopy = value;
    Mem_CpuFastMemorySet(valueCopy, destination, size);
}

void CpuFastMemoryZero(void *destination, u32 size) {
    Mem_CpuFastMemorySet2(destination, 0, size);
}

u32 GetPMaybeState(void) {
    return (g_GlobalP->mConnectionKind);
}

#pragma optimize_for_size on
u16 *GetBootIndicatorPointer(void) {
    return &gBootInfo->mBootType;
}

u32 IsDwc(void) {
    if (*GetBootIndicatorPointer() == 2) {
        return 1;
    }
    return 0;
}

u32 j_IsDwc(void) {
    return IsDwc();
}

#pragma thumb on

void DoInitializeGlobalCA_from_thumb(void) {
    s32 entryIndex;
    CpuFastMemoryZero(g_GlobalCA, 0x110);
    for (entryIndex = 0; entryIndex < 8; entryIndex++) {
        g_GlobalCA->mEntries[entryIndex].mCharacterIndex = -1;
        g_GlobalCA->mEntries[entryIndex].mKartIndex = -1;
        g_GlobalCA->mEntries[entryIndex].mPlayerKind = PLAYER_KIND_NONE;
        g_GlobalCA->mEntries[entryIndex].mTeamIndex = -1;
        g_GlobalCA->mEntries[entryIndex].mListedCpuSlot = KART_ENTRY_LISTED_CPU_SLOT_NONE;
    }
    g_GlobalCA->mMissionTableRow = 1;
    g_GlobalCA->mMissionTableColumn = 1;
    if (GetPMaybeState() == 0) {
        if (j_IsDwc() == 0) {
            g_GlobalCA->mMissionFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("mission.mr");
        } else {
            g_GlobalCA->mMissionFile = NULL;
        }
        if (g_GlobalCA->mMissionFile != NULL) {
            g_GlobalCA->mMissionFileRows = (MissionFileRow *) (g_GlobalCA->mMissionFile + 8);
        } else {
            g_GlobalCA->mMissionFileRows = NULL;
        }
    }
}
#pragma thumb off

#pragma thumb on

RaceSetupCopy *GetGlobalCA_from_thumb(void) {
    return g_GlobalCA;
}

#pragma thumb off

void WiFiSetNextCpuDifficulty(u32 cpuDifficulty) {
    g_GlobalCO->mNextHeader.mCpuDifficulty = cpuDifficulty;
}

void WiFiSetNextMode(u32 mode) {
    g_GlobalCO->mNextHeader.mMode = mode;
}

void WiFiSetNextCourseId(u32 courseId) {
    g_GlobalCO->mNextHeader.mCourseId = courseId;
}

void WiFiSetNextEngineIndex(u32 engineIndex) {
    g_GlobalCO->mNextHeader.mEngineIndex = engineIndex;
}

void WiFiSetNextMirrorMode(u32 mirrorMode) {
    g_GlobalCO->mNextHeader.mMirrorMode = (u8) mirrorMode;
}

void WiFiSetNextUseTeams(u32 useTeams) {
    g_GlobalCO->mNextHeader.mUseTeams = useTeams;
}

void WiFiSetNextRuleKind(u32 ruleKind) {
    g_GlobalCO->mNextHeader.mRuleKind = ruleKind;
}

void WiFiSetNextCourseListMode(u32 courseListMode) {
    g_GlobalCO->mNextHeader.mCourseListMode = courseListMode;
}

#pragma optimize_for_size on

#pragma thumb on

void SetNextRaceSetupFromKartMask(void) {
    u16 packedIndex;
    u16 nextEntryIndex = 0;
    u8 kartMask;
    u8 index;
    WiFiSetNextCpuDifficulty(0);
    for (packedIndex = 0; packedIndex < 4; packedIndex++) {
        if (GetKartMaskBitOfPackedIndex(packedIndex) != 0) {
            StructCO_ConfigureRacerDefault(nextEntryIndex, g_GlobalCA->mEntries[packedIndex].mCharacterIndex,
                             g_GlobalCA->mEntries[packedIndex].mKartIndex,
                             g_GlobalCA->mEntries[packedIndex].mPlayerKind, -1, 3);
            nextEntryIndex++;
        }
    }
    for (; nextEntryIndex < 8; nextEntryIndex++) {
        StructCO_ConfigureRacerDefault(nextEntryIndex, -1, -1, PLAYER_KIND_NONE, -1, 3);
    }
    WiFiSetNextMode(5);
    WiFiSetNextCourseId(g_GlobalCA->mCourseId);
    WiFiSetNextEngineIndex(1);
    WiFiSetNextMirrorMode(0);
    WiFiSetNextUseTeams(0);
    WiFiSetNextRuleKind(RULE_KIND_FREE);
    WiFiSetNextCourseListMode(0);
    kartMask = 0;
    for (index = 0; index < 4; index++) {
        if (GetKartMaskBit(index) != 0) {
            BIT_SET(kartMask, index);
        }
    }
    SetParticipantKartMapFromMask(kartMask);
}

void CopyRaceSetupCopyToEntries(void) {
    u8 packedIndex;
    s32 index;
    for (packedIndex = 0; packedIndex < 4; packedIndex++) {
        if (GetKartMaskBitOfPackedIndex(packedIndex) != 0) {
            index = GetIndexOfPackedIndex(packedIndex);
            g_GlobalB488->mEntries[index].mCharacterIndex = g_GlobalCA->mEntries[packedIndex].mCharacterIndex;
            g_GlobalB488->mEntries[index].mKartIndex = g_GlobalCA->mEntries[packedIndex].mKartIndex;
            g_GlobalB488->mEntries[index].mPlayerKind = g_GlobalCA->mEntries[packedIndex].mPlayerKind;
        }
    }
}

void CopyEntriesToRaceSetupCopy(void) {
    u8 index;
    s32 packedIndex;
    for (index = 0; index < 4; index++) {
        if (GetKartMaskBit(index) != 0) {
            packedIndex = GetPackedIndex(index);
            g_GlobalCA->mEntries[packedIndex].mCharacterIndex = g_GlobalB488->mEntries[index].mCharacterIndex;
            g_GlobalCA->mEntries[packedIndex].mKartIndex = g_GlobalB488->mEntries[index].mKartIndex;
            g_GlobalCA->mEntries[packedIndex].mPlayerKind = g_GlobalB488->mEntries[index].mPlayerKind;
        }
    }
}

#pragma thumb off

#pragma thumb on

u32 GetCourseId(void) {
    return (g_GlobalCA->mCourseId);
}

u32 GetCharacterIndex(u16 entryIndex) {
    return (g_GlobalCA->mEntries[entryIndex].mCharacterIndex);
}

u32 GetKartIndex(u16 entryIndex) {
    return (g_GlobalCA->mEntries[entryIndex].mKartIndex);
}

u32 GetPlayerKind(u16 entryIndex) {
    return (g_GlobalCA->mEntries[entryIndex].mPlayerKind);
}

u32 GetEngineIndex(void) {
    return (g_GlobalCA->mEngineIndex);
}

u32 GetSelectedCup_from_thumb(void) {
    return (g_GlobalCA->mCupIndex);
}

u32 GetMirrorMode(void) {
    return (g_GlobalCA->mMirrorMode);
}

u32 GetCpuDifficulty(void) {
    return (g_GlobalCA->mCpuDifficulty);
}

u32 GetCourseListMode(void) {
    return (g_GlobalCA->mCourseListMode);
}

u32 GetRaceSetupCopyCourseCount(void) {
    return (g_GlobalCA->mCourseCount);
}

u32 GetRuleKind(void) {
    return (g_GlobalCA->mRuleKind);
}

u32 GetUseTeams(void) {
    return (g_GlobalCA->mUseTeams);
}

u32 GetTeamIndex(u16 entryIndex) {
    return (g_GlobalCA->mEntries[entryIndex].mTeamIndex);
}

u32 GetMissionTableRow(void) {
    return (g_GlobalCA->mMissionTableRow);
}

u32 GetMissionTableColumn(void) {
    return (g_GlobalCA->mMissionTableColumn);
}

u32 GetRaceSetupCopyEntryIndex(void) {
    return (g_GlobalCA->mEntryIndex);
}

u32 GetSessionKartCount(void) {
    return (g_GlobalCA->mSessionKartCount);
}

void SetEngineIndex(u32 engineIndex) {
    g_GlobalCA->mEngineIndex = engineIndex;
}

void SetMirrorMode(void) {
    g_GlobalCA->mMirrorMode = 1;
}

void ClearMirrorMode(void) {
    g_GlobalCA->mMirrorMode = 0;
}

void SetCupIndex(u32 cupIndex) {
    g_GlobalCA->mCupIndex = cupIndex;
}

void SetCourseId(u32 courseId) {
    g_GlobalCA->mCourseId = courseId;
}

void SetCpuDifficulty(u32 cpuDifficulty) {
    g_GlobalCA->mCpuDifficulty = cpuDifficulty;
}

void SetCourseListMode(u32 courseListMode) {
    g_GlobalCA->mCourseListMode = courseListMode;
}

void SetRaceSetupCopyCourseCount(u16 courseCount) {
    g_GlobalCA->mCourseCount = courseCount;
}

void SetRuleKind(u32 ruleKind) {
    g_GlobalCA->mRuleKind = ruleKind;
}

void SetUseTeams(void) {
    g_GlobalCA->mUseTeams = 1;
}

void ClearUseTeams(void) {
    g_GlobalCA->mUseTeams = 0;
}

#pragma thumb off

#pragma thumb on

void SetTeamIndex(u16 entryIndex, u32 teamIndex) {
    g_GlobalCA->mEntries[entryIndex].mTeamIndex = teamIndex;
}

void SetCharacterIndex(u16 entryIndex, u32 characterIndex) {
    g_GlobalCA->mEntries[entryIndex].mCharacterIndex = characterIndex;
}

void SetKartIndex(u16 entryIndex, u32 kartIndex) {
    g_GlobalCA->mEntries[entryIndex].mKartIndex = kartIndex;
}

void SetPlayerKind(u16 entryIndex, u32 playerKind) {
    g_GlobalCA->mEntries[entryIndex].mPlayerKind = playerKind;
}

void SetListedCpuSlot(u16 entryIndex, u32 cpuSlot) {
    g_GlobalCA->mEntries[entryIndex].mListedCpuSlot = cpuSlot;
}

void SetKartStored(u16 entryIndex, u32 kartStored) {
    g_GlobalCA->mEntries[entryIndex].mKartStored = kartStored;
}

#pragma thumb off

#pragma thumb on

void SetRaceSetupCopyGhostRecordIndex(u32 ghostRecordIndex) {
    g_GlobalCA->mGhostRecordIndex = ghostRecordIndex;
}

void SetMissionTableRow(u32 missionTableRow) {
    g_GlobalCA->mMissionTableRow = (u8) missionTableRow;
}

void SetMissionTableColumn(u32 missionTableColumn) {
    g_GlobalCA->mMissionTableColumn = (u8) missionTableColumn;
}

void SetMissionFileRowIndex(u32 missionFileRowIndex) {
    g_GlobalCA->mMissionFileRowIndex = missionFileRowIndex;
}

void SetRaceSetupCopyEntryIndex(u32 entryIndex) {
    g_GlobalCA->mEntryIndex = entryIndex;
}

void SetSessionKartCount(u32 sessionKartCount) {
    g_GlobalCA->mSessionKartCount = sessionKartCount;
}

#pragma thumb off
