#pragma once

#include "types.h"
#include "Main/System/backup_net_camera_work.h" // GhostRecordHead, GhostListEntry
#include "Main/Menu/menu_screens_work.h"
#include "sound_player_control.h"
#include "sound_player_type.h"
#include "sound_stream_control.h"
#include "sound_capture_effect.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "sound_archive_load.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"

void ReadGhostRecordsForKind(u32 kind);
BOOL HasNoSelectableGhost(void);
BOOL IsGhostRecordSetKindSelectable(u32 kind);
s32 GetGhostRecordSetKartIndex(u32 kind);
s32 GetGhostRecordSetCharacterIndex(u32 kind);
void GetGhostRecordSetName(u32 kind, void *name);
void GetGhostRecordSetTime(u32 kind, void *time);
void SetupGhostRecordSetForCourse(u32 courseId);
void ClearGhostRecordSetPointer(void);
void InitGhostRecordSet(void *heap);

extern struct GhostRecordSet *gGhostRecordSet;

static inline GhostRecordHead *GetGhostRecordSetSlotHead(u8 slotIndex) {
    return &gGhostRecordSet->mSlotGhostRecords[slotIndex].mHead;
}

// Kinds of ghost record the functions of this file take: the record of the course, the record of the slot found for
// this course, the record of the ghost file, and a kind outside the set (always selectable; the getters read nothing
// for it and reading it loads the course record only).
#define GHOST_RECORD_KIND_COURSE 0
#define GHOST_RECORD_KIND_SLOT 1
#define GHOST_RECORD_KIND_GHOST_FILE 2
#define GHOST_RECORD_KIND_OUTSIDE_SET 4
