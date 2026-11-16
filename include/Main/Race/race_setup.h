#pragma once

#include "types.h"
#include "Main/Menu/select_kart_ghost_work.h"
#include "Main/System/interpolation_value.h"
#include "Main/System/heap_call.h"
#include "font_glyph_layout.h"
#include "Main/Graphics/cell_file_set.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Menu/multi_select_member_group.h"
#include "touch_panel_sampling.h"
#include "Main/Save/buddy_record_time.h"
#include "cell_transfer_state.h"

void SetSessionKartCount(unsigned int sessionKartCount);
void SetRaceSetupCopyEntryIndex(unsigned int entryIndex);
void SetMissionFileRowIndex(unsigned int missionFileRowIndex);
void SetMissionTableColumn(unsigned int missionTableColumn);
void SetMissionTableRow(unsigned int missionTableRow);
void SetRaceSetupCopyGhostRecordIndex(unsigned int ghostRecordIndex);
void SetKartStored(u16 entryIndex, u32 kartStored);
void SetListedCpuSlot(u16 entryIndex, u32 cpuSlot);
void SetPlayerKind(u16 entryIndex, u32 playerKind);
void SetKartIndex(u16 entryIndex, u32 kartIndex);
void SetCharacterIndex(u16 entryIndex, u32 characterIndex);
void SetTeamIndex(u16 entryIndex, u32 teamIndex);
void ClearUseTeams(void);
void SetUseTeams(void);
void SetRuleKind(unsigned int ruleKind);
void SetRaceSetupCopyCourseCount(u16 courseCount);
void SetCourseListMode(unsigned int courseListMode);
void SetCpuDifficulty(unsigned int cpuDifficulty);
void SetCourseId(unsigned int courseId);
void SetCupIndex(unsigned int cupIndex);
void ClearMirrorMode(void);
void SetMirrorMode(void);
void SetEngineIndex(unsigned int engineIndex);
unsigned int GetSessionKartCount(void);
unsigned int GetRaceSetupCopyEntryIndex(void);
unsigned int GetMissionTableColumn(void);
unsigned int GetMissionTableRow(void);
unsigned int GetTeamIndex(u16 entryIndex);
unsigned int GetUseTeams(void);
unsigned int GetRuleKind(void);
unsigned int GetRaceSetupCopyCourseCount(void);
unsigned int GetCourseListMode(void);
unsigned int GetCpuDifficulty(void);
unsigned int GetMirrorMode(void);
unsigned int GetSelectedCup_from_thumb(void);
unsigned int GetEngineIndex(void);
unsigned int GetPlayerKind(u16 entryIndex);
unsigned int GetKartIndex(u16 entryIndex);
unsigned int GetCharacterIndex(u16 entryIndex);
unsigned int GetCourseId(void);

void CopyEntriesToRaceSetupCopy(void);
void CopyRaceSetupCopyToEntries(void);
void SetNextRaceSetupFromKartMask(void);

typedef struct RaceSetupCopy RaceSetupCopy;

void WiFiSetNextCourseListMode(unsigned int courseListMode);
void WiFiSetNextRuleKind(unsigned int ruleKind);
void WiFiSetNextUseTeams(unsigned int useTeams);
void WiFiSetNextMirrorMode(unsigned int mirrorMode);
void WiFiSetNextEngineIndex(unsigned int engineIndex);
void WiFiSetNextCourseId(unsigned int courseId);
void WiFiSetNextMode(unsigned int mode);
void WiFiSetNextCpuDifficulty(unsigned int cpuDifficulty);
RaceSetupCopy *GetGlobalCA_from_thumb(void);

void DoInitializeGlobalCA_from_thumb(void);
u32 j_IsDwc(void);
u32 IsDwc(void);
u16 *GetBootIndicatorPointer(void);

unsigned int GetPMaybeState(void);
void CpuFastMemoryZero(void *destination, u32 size);
void Mem_CpuFastMemorySet2(void *destination, u32 value, u32 size);
void InitializeGlobalCA_from_thumb(void *heap);

extern RaceSetupCopy *g_GlobalCA;
