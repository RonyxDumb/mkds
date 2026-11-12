#pragma once

#include "types.h"
#include "Main/Menu/data_02174000.h"
#include "Main/System/interpolation_value.h"
#include "Main/System/heap_call.h"
#include "code_02022aa8.h"
#include "Main/Graphics/cell_file_set.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Menu/multi_select_member_group.h"
#include "tp.h"
#include "Main/Save/buddy_record_time.h"
#include "g2d_CellTransferManager.h"
#include "Main/MapObjects/data_0217a000.h" // GhostRecordHead, GhostListEntry

s32 FindSlotGhostForCourse(s32 courseId);
s32 FindUnfilledGhostSlot(void);
s32 DoesAnySlotGhostMatchCourse(s32 courseId);
void StartReadListedGhost(s32 index);
u32 GetListedGhostCourseId(u32 index);
u32 GetListedGhostKartIndex(u32 index);
u32 GetListedGhostCharacterIndex(u32 index);
void GetListedGhostName(u32 index, void *name);
void GetListedGhostTime(u32 index, void *time);
s32 IsSlotGhostIndex(s32 index);

static inline GhostRecordHead *GetSlotGhostRecordHead(u8 slotIndex) {
    return &gGhostScene->mSlotGhostRecords[slotIndex].mHead;
}
