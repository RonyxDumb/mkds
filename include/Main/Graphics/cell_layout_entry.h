#pragma once

#include "types.h"

typedef struct LayoutTableEntry LayoutTableEntry;
typedef struct LayoutEntryTable LayoutEntryTable;

void RectTableSetEntryXY(int id, int entryX, int entryY, LayoutEntryTable *graphics);
void SetLayoutEntryPositionFromLabel(u32 entryId, LayoutTableEntry *output, LayoutEntryTable *labelLayout);
void SetLayoutEntryPositionFromCell(u32 entryId, LayoutTableEntry *output, LayoutEntryTable *cellLayout);
void CopyCellLayoutEntryCellIndex(u32 destinationId, u32 sourceId, LayoutEntryTable *cellLayout);
void CopyCellLayoutEntryPosition(u32 destinationId, u32 sourceId, LayoutEntryTable *cellLayout);
void SetCellLayoutEntryXY(int entryId, s16 entryX, int entryY, LayoutEntryTable *cellLayout);
