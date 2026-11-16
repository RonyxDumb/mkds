#include "Main/Save/GhostList.h"
#include "Main/Unknown/code_0202dd9c.h"
#include "Main/Unknown/code_0202e43c.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Save/BackupGhosts.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/unk_02174000.h"

#pragma opt_arithtransformation off

#pragma thumb on

// Returns 1 when the list position is a slot ghost, 0 for a course ghost.
s32 IsSlotGhostIndex(s32 index) {
    return index < sGhostSceneState->mCourseGhostCount ? 0 : 1;
}

void GetListedGhostTime(u32 index, void *time) {
    u32 courseId;
    u8 *courseRecords;
    s32 cupCourseIndex;
    if (IsSlotGhostIndex(index) == 0) {
        courseId = ghost_getCourseId(sGhostSceneState->mCupCourseIndices[index]);
        courseRecords = sGhostSceneState->mCourseGhostRecords;
        cupCourseIndex = rconf_getCourseNumber(courseId);
        ghdat_getGhostTime(courseRecords + cupCourseIndex * 0x30, time);
    } else {
        index -= sGhostSceneState->mCourseGhostCount;
        ghdat_getGhostTime((u8) sGhostSceneState->mSlotIndices[index] * 0x230 + sGhostSceneState->mSlotGhostRecords, time);
    }
}

void GetListedGhostName(u32 index, void *name) {
    u32 courseId;
    u8 *courseRecords;
    s32 cupCourseIndex;
    if (IsSlotGhostIndex(index) == 0) {
        courseId = ghost_getCourseId(sGhostSceneState->mCupCourseIndices[index]);
        courseRecords = sGhostSceneState->mCourseGhostRecords;
        cupCourseIndex = rconf_getCourseNumber(courseId);
        ghdat_getGhostNickName(courseRecords + cupCourseIndex * 0x30, name);
    } else {
        index -= sGhostSceneState->mCourseGhostCount;
        ghdat_getGhostNickName((u8) sGhostSceneState->mSlotIndices[index] * 0x230 + sGhostSceneState->mSlotGhostRecords, name);
    }
}

u32 GetListedGhostCharacterIndex(u32 index) {
    u32 courseId;
    u8 *courseRecords;
    s32 cupCourseIndex;
    if (IsSlotGhostIndex(index) == 0) {
        courseId = ghost_getCourseId(sGhostSceneState->mCupCourseIndices[index]);
        courseRecords = sGhostSceneState->mCourseGhostRecords;
        cupCourseIndex = rconf_getCourseNumber(courseId);
        return ghdat_getGhostCharacter(courseRecords + cupCourseIndex * 0x30);
    }
    index -= sGhostSceneState->mCourseGhostCount;
    return ghdat_getGhostCharacter((u8) sGhostSceneState->mSlotIndices[index] * 0x230 + sGhostSceneState->mSlotGhostRecords);
}

u32 GetListedGhostKartIndex(u32 index) {
    u32 courseId;
    u8 *courseRecords;
    s32 cupCourseIndex;
    if (IsSlotGhostIndex(index) == 0) {
        courseId = ghost_getCourseId(sGhostSceneState->mCupCourseIndices[index]);
        courseRecords = sGhostSceneState->mCourseGhostRecords;
        cupCourseIndex = rconf_getCourseNumber(courseId);
        return ghdat_getGhostKart(courseRecords + cupCourseIndex * 0x30);
    }
    index -= sGhostSceneState->mCourseGhostCount;
    return ghdat_getGhostKart((u8) sGhostSceneState->mSlotIndices[index] * 0x230 + sGhostSceneState->mSlotGhostRecords);
}

u32 GetListedGhostCourseId(u32 index) {
    u8 *slotRecords;
    if (IsSlotGhostIndex(index) == 0) {
        return ghost_getCourseId(sGhostSceneState->mCupCourseIndices[index]);
    }
    index -= sGhostSceneState->mCourseGhostCount;
    slotRecords = sGhostSceneState->mSlotGhostRecords;
    return ghdat_getGhostCourse(slotRecords + (u8) sGhostSceneState->mSlotIndices[index] * 0x230);
}

void StartReadListedGhost(s32 index) {
    s32 recordIndex;
    if (IsSlotGhostIndex(index) == 0) {
        recordIndex = sGhostSceneState->mCupCourseIndices[index];
        savd_readNkpg(recordIndex, GetCourseGhostBuffer());
    } else {
        recordIndex = sGhostSceneState->mSlotIndices[index - ghost_getMyGhostCount()];
        savd_readNkdg((u8) recordIndex, (GhostRecord *) GetSlotGhostBuffer());
    }
}

s32 DoesAnySlotGhostMatchCourse(s32 courseId) {
    s32 i;
    BOOL found;
    found = FALSE;
    for (i = 0; i < (s32) ghost_getDlGhostCount(); i++) {
        if (courseId ==
            ghdat_getGhostCourse((u8) sGhostSceneState->mSlotIndices[i] * 0x230 + sGhostSceneState->mSlotGhostRecords)) {
            found = TRUE;
            break;
        }
    }
    return found;
}

s32 FindUnfilledGhostSlot(void) {
    s32 slot;
    for (slot = 0; slot < 10; slot++) {
        if (ghdat_getIsGhostValid(sGhostSceneState->mSlotGhostRecords + (u8) slot * 0x230) == FALSE) {
            return slot;
        }
    }
    return -1;
}

s32 FindSlotGhostForCourse(s32 courseId) {
    s32 i;
    s32 slot;
    slot = -1;
    for (i = 0; i < (s32) ghost_getDlGhostCount(); i++) {
        if (courseId ==
            ghdat_getGhostCourse((u8) sGhostSceneState->mSlotIndices[i] * 0x230 + sGhostSceneState->mSlotGhostRecords)) {
            slot = sGhostSceneState->mSlotIndices[i];
            break;
        }
    }
    return slot;
}

#pragma thumb off
