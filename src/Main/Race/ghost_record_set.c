#include "Main/Race/ghost_record_set.h"
#include "Main/System/heap.h"
#include "Main/Race/race_setup_input.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Save/ghost_file_records.h"
#include "Main/Save/slot_ghost_records.h"
#include "Main/Save/course_ghost_records.h"
#include "Main/Race/race.h"
#include "Main/Race/gp_records_killer.h"

#include "01/Menu/record_time_attack.h"
#include "Main/Save/ghost_file_records_create.h"
#include "Main/Menu/data_0217d000.h"
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
#include "Main/MapObjects/data_0217a000.h" // GhostRecordHead, GhostListEntry
#include "code_0214cfe4.h"
#include "code_0214d018.h"

GhostRecordSet *gGhostRecordSet;

#pragma thumb on

void InitGhostRecordSet(void *heap) {
    gGhostRecordSet = HeapAlloc(heap, 0x14);
    gGhostRecordSet->mCourseGhostRecords = CreateCourseGhostRecords(heap);
    StartReadCourseGhostRecords(gGhostRecordSet->mCourseGhostRecords);
    WaitThreadFunctionsDone();
    gGhostRecordSet->mSlotGhostRecords = CreateSlotGhostRecords(heap);
    StartReadSlotGhostRecords(gGhostRecordSet->mSlotGhostRecords);
    WaitThreadFunctionsDone();
    gGhostRecordSet->mGhostFileRecords = CreateGhostFileRecords(heap);
    StartReadGhostFileRecords(gGhostRecordSet->mGhostFileRecords);
    WaitThreadFunctionsDone();
    LoadStaffGhostTime(heap);
}

void ClearGhostRecordSetPointer(void) {
    gGhostRecordSet = NULL;
}

void SetupGhostRecordSetForCourse(u32 courseId) {
    s32 slotIndex;

    gGhostRecordSet->mCourseId = courseId;
    gGhostRecordSet->mSlotIndex = -1;
    for (slotIndex = 0; slotIndex < 0xa; slotIndex++) {
        if (IsGhostRecordFilled(GetGhostRecordSetSlotHead(slotIndex)) != FALSE &&
            GetGhostRecordCourseId(GetGhostRecordSetSlotHead(slotIndex)) == courseId) {
            gGhostRecordSet->mSlotIndex = slotIndex;
            return;
        }
    }
}

void GetGhostRecordSetTime(u32 kind, void *time) {
    GhostRecordHead *courseRecords;
    GhostListEntry *ghostFileRecords;

    switch (kind) {
        case 0:
            courseRecords = gGhostRecordSet->mCourseGhostRecords;
            GetGhostRecordTime(&courseRecords[FindCupCourseIndex(gGhostRecordSet->mCourseId)], time);
            break;
        case 1:
            GetGhostRecordTime(GetGhostRecordSetSlotHead(gGhostRecordSet->mSlotIndex), time);
            break;
        case 2:
            ghostFileRecords = gGhostRecordSet->mGhostFileRecords;
            GetGhostRecordTime(&ghostFileRecords[FindCupCourseIndex(gGhostRecordSet->mCourseId)].mHead, time);
            break;
        case 4:
            break;
    }
}

void GetGhostRecordSetName(u32 kind, void *name) {
    GhostRecordHead *courseRecords;
    GhostListEntry *ghostFileRecords;
    u8 ghostName[0x14];

    switch (kind) {
        case 0:
            courseRecords = gGhostRecordSet->mCourseGhostRecords;
            GetGhostRecordName(&courseRecords[FindCupCourseIndex(gGhostRecordSet->mCourseId)], ghostName);
            break;
        case 1:
            GetGhostRecordName(GetGhostRecordSetSlotHead(gGhostRecordSet->mSlotIndex), ghostName);
            break;
        case 2:
            ghostFileRecords = gGhostRecordSet->mGhostFileRecords;
            GetGhostRecordName(&ghostFileRecords[FindCupCourseIndex(gGhostRecordSet->mCourseId)].mHead, ghostName);
            break;
        case 4:
            break;
    }
    MI_CpuFill8(name, 0, 0x20);
    MIi_CpuCopy16(ghostName, name, 0x14);
}

s32 GetGhostRecordSetCharacterIndex(u32 kind) {
    GhostRecordHead *courseRecords;
    GhostListEntry *ghostFileRecords;
    s32 characterIndex = -1;

    switch (kind) {
        case 4:
            characterIndex = -1;
            break;
        case 0:
            courseRecords = gGhostRecordSet->mCourseGhostRecords;
            characterIndex =
                GetGhostRecordCharacterIndex(&courseRecords[FindCupCourseIndex(gGhostRecordSet->mCourseId)]);
            break;
        case 1:
            characterIndex = GetGhostRecordCharacterIndex(GetGhostRecordSetSlotHead(gGhostRecordSet->mSlotIndex));
            break;
        case 2:
            ghostFileRecords = gGhostRecordSet->mGhostFileRecords;
            characterIndex =
                GetGhostRecordCharacterIndex(&ghostFileRecords[FindCupCourseIndex(gGhostRecordSet->mCourseId)].mHead);
            break;
    }
    return characterIndex;
}

s32 GetGhostRecordSetKartIndex(u32 kind) {
    GhostRecordHead *courseRecords;
    GhostListEntry *ghostFileRecords;
    s32 kartIndex = -1;

    switch (kind) {
        case 4:
            kartIndex = -1;
            break;
        case 0:
            courseRecords = gGhostRecordSet->mCourseGhostRecords;
            kartIndex = GetGhostRecordKartIndex(&courseRecords[FindCupCourseIndex(gGhostRecordSet->mCourseId)]);
            break;
        case 1:
            kartIndex = GetGhostRecordKartIndex(GetGhostRecordSetSlotHead(gGhostRecordSet->mSlotIndex));
            break;
        case 2:
            ghostFileRecords = gGhostRecordSet->mGhostFileRecords;
            kartIndex =
                GetGhostRecordKartIndex(&ghostFileRecords[FindCupCourseIndex(gGhostRecordSet->mCourseId)].mHead);
            break;
    }
    return kartIndex;
}

BOOL IsGhostRecordSetKindSelectable(u32 kind) {
    s32 result = 0;
    GhostRecordHead *courseRecords;

    switch (kind) {
        case 4:
            result = 1;
            break;
        case 0:
            courseRecords = gGhostRecordSet->mCourseGhostRecords;
            result = IsGhostRecordFilled(&courseRecords[FindCupCourseIndex(gGhostRecordSet->mCourseId)]);
            break;
        case 1:
            if (gGhostRecordSet->mSlotIndex != -1) {
                result = 1;
            }
            break;
        case 2:
            if (IsTimeRecordFilled(gGhostRecordSet->mCourseId, 0) != FALSE) {
                MinuteSecondMillisecondTime time;

                GetTimeRecordTime(gGhostRecordSet->mCourseId, 0, &time);
                result = IsTimeLessThanStaffGhostTime(gGhostRecordSet->mCourseId, &time);
            } else {
                result = 0;
            }
            break;
    }
    return result;
}

BOOL HasNoSelectableGhost(void) {
    u32 selectable = 0;

    selectable |= IsGhostRecordSetKindSelectable(selectable);
    selectable |= IsGhostRecordSetKindSelectable(1);
    selectable |= IsGhostRecordSetKindSelectable(2);
    if (selectable == 0) {
        return TRUE;
    }
    return FALSE;
}

void ReadGhostRecordsForKind(u32 kind) {
    switch (kind) {
        case 4:
            SelectGhostReadCourseRecordAndWait(gGhostRecordSet->mCourseId);
            break;
        case 0:
            ReadCourseGhostRecordAndWait(gGhostRecordSet->mCourseId);
            break;
        case 1:
            ReadCourseAndSlotGhostRecords(gGhostRecordSet->mCourseId, (u8) gGhostRecordSet->mSlotIndex);
            break;
        case 2:
            ReadCourseGhostRecordAndLoadFile(gGhostRecordSet->mCourseId);
            break;
    }
}

#pragma thumb off
