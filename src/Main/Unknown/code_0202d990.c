#include "Main/Unknown/code_0202d990.h"
#include "Main/Unknown/code_0202dd9c.h"
#include "Main/Unknown/code_0202e43c.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_020578fc.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/unk_0217a000.h" // GhostRecordHead, Unk0206152c

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
        courseId = func_0202e43c(gGhostScene->mCupCourseIndices[index]);
        courseRecords = gGhostScene->mCourseGhostRecords;
        cupCourseIndex = FindCupCourseIndex(courseId);
        GetGhostRecordTime(&courseRecords[cupCourseIndex], time);
    } else {
        index -= gGhostScene->mCourseGhostCount;
        GetGhostRecordTime(&gGhostScene->mSlotGhostRecords[(u8) gGhostScene->mSlotIndices[index]], time);
    }
}

void GetListedGhostName(u32 index, void *name) {
    u32 courseId;
    GhostRecordHead *courseRecords;
    s32 cupCourseIndex;
    if (IsSlotGhostIndex(index) == 0) {
        courseId = func_0202e43c(gGhostScene->mCupCourseIndices[index]);
        courseRecords = gGhostScene->mCourseGhostRecords;
        cupCourseIndex = FindCupCourseIndex(courseId);
        GetGhostRecordName(&courseRecords[cupCourseIndex], name);
    } else {
        index -= gGhostScene->mCourseGhostCount;
        GetGhostRecordName(&gGhostScene->mSlotGhostRecords[(u8) gGhostScene->mSlotIndices[index]], name);
    }
}

u32 GetListedGhostCharacterIndex(u32 index) {
    u32 courseId;
    GhostRecordHead *courseRecords;
    s32 cupCourseIndex;
    if (IsSlotGhostIndex(index) == 0) {
        courseId = func_0202e43c(gGhostScene->mCupCourseIndices[index]);
        courseRecords = gGhostScene->mCourseGhostRecords;
        cupCourseIndex = FindCupCourseIndex(courseId);
        return GetGhostRecordCharacterIndex(&courseRecords[cupCourseIndex]);
    }
    index -= gGhostScene->mCourseGhostCount;
    return GetGhostRecordCharacterIndex(&gGhostScene->mSlotGhostRecords[(u8) gGhostScene->mSlotIndices[index]]);
}

u32 GetListedGhostKartIndex(u32 index) {
    u32 courseId;
    GhostRecordHead *courseRecords;
    s32 cupCourseIndex;
    if (IsSlotGhostIndex(index) == 0) {
        courseId = func_0202e43c(gGhostScene->mCupCourseIndices[index]);
        courseRecords = gGhostScene->mCourseGhostRecords;
        cupCourseIndex = FindCupCourseIndex(courseId);
        return GetGhostRecordKartIndex(&courseRecords[cupCourseIndex]);
    }
    index -= gGhostScene->mCourseGhostCount;
    return GetGhostRecordKartIndex(&gGhostScene->mSlotGhostRecords[(u8) gGhostScene->mSlotIndices[index]]);
}

u32 GetListedGhostCourseId(u32 index) {
    Unk0206152c *slotRecords;
    if (IsSlotGhostIndex(index) == 0) {
        return func_0202e43c(gGhostScene->mCupCourseIndices[index]);
    }
    index -= gGhostScene->mCourseGhostCount;
    slotRecords = gGhostScene->mSlotGhostRecords;
    return GetGhostRecordCourseId(&slotRecords[(u8) gGhostScene->mSlotIndices[index]]);
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
    s32 i;
    BOOL found;
    found = FALSE;
    for (i = 0; i < (s32) GetSlotGhostCount(); i++) {
        if (courseId ==
            GetGhostRecordCourseId(&gGhostScene->mSlotGhostRecords[(u8) gGhostScene->mSlotIndices[i]])) {
            found = TRUE;
            break;
        }
    }
    return found;
}

s32 FindUnfilledGhostSlot(void) {
    s32 slot;
    for (slot = 0; slot < 10; slot++) {
        if (IsGhostRecordFilled(&gGhostScene->mSlotGhostRecords[(u8) slot]) == FALSE) {
            return slot;
        }
    }
    return -1;
}

s32 FindSlotGhostForCourse(s32 courseId) {
    s32 i;
    s32 slot;
    slot = -1;
    for (i = 0; i < (s32) GetSlotGhostCount(); i++) {
        if (courseId ==
            GetGhostRecordCourseId(&gGhostScene->mSlotGhostRecords[(u8) gGhostScene->mSlotIndices[i]])) {
            slot = gGhostScene->mSlotIndices[i];
            break;
        }
    }
    return slot;
}

#pragma thumb off
