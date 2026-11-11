#pragma once

#include "types.h"
#include "Main/Unknown/unk_0217a000.h" // GhostRecordHead, GhostListEntry
#include "Main/Unknown/unk_0217d000.h"

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

static inline GhostRecordHead *GetGhostRecordSetSlotHead(u8 slotIndex) {
    return &gGhostRecordSet->mSlotGhostRecords[slotIndex].mHead;
}
