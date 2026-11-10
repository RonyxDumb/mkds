#pragma once

#include "types.h"

typedef struct LayoutTableEntry LayoutTableEntry;
typedef struct Unk0201ea30 Unk0201ea30;

void RectTableSetEntryXY(int id, int x, int y, Unk0201ea30 *graphics);
void SetLayoutEntryPositionFromLabel(u32 entryId, LayoutTableEntry *output, Unk0201ea30 *labelLayout);
void SetLayoutEntryPositionFromCell(u32 entryId, LayoutTableEntry *output, Unk0201ea30 *cellLayout);
void CopyCellLayoutEntryCellIndex(u32 destinationId, u32 sourceId, Unk0201ea30 *cellLayout);
void CopyCellLayoutEntryPosition(u32 destinationId, u32 sourceId, Unk0201ea30 *cellLayout);
void SetCellLayoutEntryXY(int entryId, int x, int y, Unk0201ea30 *cellLayout);
