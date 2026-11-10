#pragma once

#include "types.h"

typedef struct CellFileSet CellFileSet;
typedef struct LayoutEntryTable LayoutEntryTable;

u32 GetOwnEntryIndex(void);
unsigned int GetParticipantEntryIndex(unsigned int participantIndex);
u16 GetOwnIndexOrZero(void);
void SelectKartMI_CpuClearFast(void *destination, u32 size);
void SelectKartMI_CpuFillFast(void *destination, u32 value, u32 size);
void RefreshKartMenuParamElements(void);
void SetKartMenuParamElementOffset(s32 elementIndex, s32 endCellIndex, s32 paramValue, CellFileSet *parts);
void *GetCellLayoutEntrySwapped(s32 index, LayoutEntryTable *cellLayout);
