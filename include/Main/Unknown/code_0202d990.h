#pragma once

#include "types.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/unk_0217a000.h" // GhostRecordHead, GhostListEntry

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
