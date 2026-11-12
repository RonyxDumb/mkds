#pragma once

#include "types.h"

void *GetChoisesSValueMessage(s32 listIndex, s32 value);
void ClearChoisesSListValueCounts(void);
void AppendChoisesSListValue(s32 listIndex, s32 value);
s32 MoveChoisesSSelectedValue(s32 step);
u32 MoveChoisesSSelectedValueByTouch(void);
void ResetChoisesSSelection(void);
void SetChoisesSOpen(s32 openFlag);
u32 IsMissionRunTableRow6Or7Column9(void);
s8 GetMissionRunTableRow(void);
s8 GetMissionRunTableColumn(void);
BOOL IsAllMissionRecords5To7AtEndKind0(void);
