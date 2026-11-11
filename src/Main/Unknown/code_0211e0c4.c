#include "Main/Unknown/code_0211e0c4.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020435c4.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_02060cb4.h"
#include "Main/Unknown/code_02061428.h"
#include "Main/Unknown/code_02061540.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02090354.h"

#include "Main/Unknown/code_02043000.h"
#include "Main/Unknown/code_02044000.h"
#include "Main/Unknown/code_02061000.h"
#include "Main/Unknown/code_02090000.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_02061418.h"
#include "Main/Unknown/code_0206152c.h"
#include "Main/Unknown/code_02061644.h"
#include "Main/Unknown/code_02060000.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0217a000.h" // GhostRecordHead, GhostListEntry
#include "code_0214cfe4.h"
#include "code_0214d018.h"

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
    s32 i;

    gGhostRecordSet->mCourseId = courseId;
    gGhostRecordSet->mSlotIndex = -1;
    for (i = 0; i < 0xa; i++) {
        if (IsGhostRecordFilled(&gGhostRecordSet->mSlotGhostRecords[(u8) i].mHead) != FALSE &&
            GetGhostRecordCourseId(&gGhostRecordSet->mSlotGhostRecords[(u8) i].mHead) == courseId) {
            gGhostRecordSet->mSlotIndex = i;
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
    u32 a = 0;

    a |= IsGhostRecordSetKindSelectable(a);
    a |= IsGhostRecordSetKindSelectable(1);
    a |= IsGhostRecordSetKindSelectable(2);
    if (a == 0) {
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
