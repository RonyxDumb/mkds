#include "Main/Race/ghost_list.h"
#include "Main/Menu/ghost_scene.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Save/backup_ghost_head.h"
#include "Main/Race/race.h"
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
#include "Main/System/backup_net_camera_work.h" // GhostRecordHead, GhostListEntry

#pragma opt_arithtransformation off

#pragma thumb on

// Returns 1 when the list position is a slot ghost, 0 for a course ghost.
s32 IsSlotGhostIndex(s32 index) {
    return index < gGhostScene->mCourseGhostCount ? 0 : 1;
}

void GetListedGhostTime(u32 index, void *time) {
    u32 courseId;
    GhostRecordHead *courseRecords;
    s32 cupCourseIndex;
    if (IsSlotGhostIndex(index) == 0) {
        courseId = GhostSceneGetCupCourseIdAtIndex(gGhostScene->mCupCourseIndices[index]);
        courseRecords = gGhostScene->mCourseGhostRecords;
        cupCourseIndex = FindCupCourseIndex(courseId);
        GetGhostRecordTime(&courseRecords[cupCourseIndex], time);
    } else {
        index -= gGhostScene->mCourseGhostCount;
        GetGhostRecordTime(GetSlotGhostRecordHead(gGhostScene->mSlotIndices[index]), time);
    }
}

void GetListedGhostName(u32 index, void *name) {
    u32 courseId;
    GhostRecordHead *courseRecords;
    s32 cupCourseIndex;
    if (IsSlotGhostIndex(index) == 0) {
        courseId = GhostSceneGetCupCourseIdAtIndex(gGhostScene->mCupCourseIndices[index]);
        courseRecords = gGhostScene->mCourseGhostRecords;
        cupCourseIndex = FindCupCourseIndex(courseId);
        GetGhostRecordName(&courseRecords[cupCourseIndex], name);
    } else {
        index -= gGhostScene->mCourseGhostCount;
        GetGhostRecordName(GetSlotGhostRecordHead(gGhostScene->mSlotIndices[index]), name);
    }
}

u32 GetListedGhostCharacterIndex(u32 index) {
    u32 courseId;
    GhostRecordHead *courseRecords;
    s32 cupCourseIndex;
    if (IsSlotGhostIndex(index) == 0) {
        courseId = GhostSceneGetCupCourseIdAtIndex(gGhostScene->mCupCourseIndices[index]);
        courseRecords = gGhostScene->mCourseGhostRecords;
        cupCourseIndex = FindCupCourseIndex(courseId);
        return GetGhostRecordCharacterIndex(&courseRecords[cupCourseIndex]);
    }
    index -= gGhostScene->mCourseGhostCount;
    return GetGhostRecordCharacterIndex(GetSlotGhostRecordHead(gGhostScene->mSlotIndices[index]));
}

u32 GetListedGhostKartIndex(u32 index) {
    u32 courseId;
    GhostRecordHead *courseRecords;
    s32 cupCourseIndex;
    if (IsSlotGhostIndex(index) == 0) {
        courseId = GhostSceneGetCupCourseIdAtIndex(gGhostScene->mCupCourseIndices[index]);
        courseRecords = gGhostScene->mCourseGhostRecords;
        cupCourseIndex = FindCupCourseIndex(courseId);
        return GetGhostRecordKartIndex(&courseRecords[cupCourseIndex]);
    }
    index -= gGhostScene->mCourseGhostCount;
    return GetGhostRecordKartIndex(GetSlotGhostRecordHead(gGhostScene->mSlotIndices[index]));
}

u32 GetListedGhostCourseId(u32 index) {
    if (IsSlotGhostIndex(index) == 0) {
        return GhostSceneGetCupCourseIdAtIndex(gGhostScene->mCupCourseIndices[index]);
    }
    index -= gGhostScene->mCourseGhostCount;
    return GetGhostRecordCourseId(GetSlotGhostRecordHead(gGhostScene->mSlotIndices[index]));
}

void StartReadListedGhost(s32 index) {
    s32 recordIndex;
    if (IsSlotGhostIndex(index) == 0) {
        recordIndex = gGhostScene->mCupCourseIndices[index];
        ReadBackupCourseGhost(recordIndex, GetCourseGhostBuffer());
    } else {
        recordIndex = gGhostScene->mSlotIndices[index - GetCourseGhostCount()];
        ReadBackupSlotGhost((u8) recordIndex, GetSlotGhostBuffer());
    }
}

s32 DoesAnySlotGhostMatchCourse(s32 courseId) {
    s32 slotGhostIndex;
    BOOL found;
    found = FALSE;
    for (slotGhostIndex = 0; slotGhostIndex < (s32) GetSlotGhostCount(); slotGhostIndex++) {
        if (courseId == GetGhostRecordCourseId(GetSlotGhostRecordHead(gGhostScene->mSlotIndices[slotGhostIndex]))) {
            found = TRUE;
            break;
        }
    }
    return found;
}

s32 FindUnfilledGhostSlot(void) {
    s32 slot;
    for (slot = 0; slot < 10; slot++) {
        if (IsGhostRecordFilled(GetSlotGhostRecordHead(slot)) == FALSE) {
            return slot;
        }
    }
    return -1;
}

s32 FindSlotGhostForCourse(s32 courseId) {
    s32 slotGhostIndex;
    s32 slot;
    slot = -1;
    for (slotGhostIndex = 0; slotGhostIndex < (s32) GetSlotGhostCount(); slotGhostIndex++) {
        if (courseId == GetGhostRecordCourseId(GetSlotGhostRecordHead(gGhostScene->mSlotIndices[slotGhostIndex]))) {
            slot = gGhostScene->mSlotIndices[slotGhostIndex];
            break;
        }
    }
    return slot;
}

#pragma thumb off
