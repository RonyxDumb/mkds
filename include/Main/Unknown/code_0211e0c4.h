#pragma once

#include "types.h"

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
