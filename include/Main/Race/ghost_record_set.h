#pragma once

#include "types.h"
#include "Main/System/backup_net_camera_work.h" // GhostRecordHead, GhostListEntry
#include "Main/Menu/menu_screens_work.h"
#include "player.h"
#include "code_0212c7a0.h"
#include "stream.h"
#include "code_0212c9d4.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "code_0212d214.h"
#include "Main/Sound/sound_seq.h"

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

// Kinds of ghost record the functions of this file take: the record of the course, the record of the selected slot, the
// record of the ghost file, and the kind with no record of its own in the set (the getters read nothing for it; reading
// it loads the course record only).
#define GHOST_RECORD_KIND_COURSE 0
#define GHOST_RECORD_KIND_SLOT 1
#define GHOST_RECORD_KIND_GHOST_FILE 2
#define GHOST_RECORD_KIND_OUTSIDE_SET 4
