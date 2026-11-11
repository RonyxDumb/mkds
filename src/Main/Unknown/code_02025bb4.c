#include "Main/Unknown/code_02025bb4.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_0201ea30.h"
#include "Main/Unknown/code_0201ea58.h"

#pragma thumb on

void SetCellLayoutEntryXY(int entryId, int entryX, int entryY, LayoutEntryTable *cellLayout) {
    short *entry = (GetCellLayoutEntry(cellLayout, entryId));
    entry[0] = (entry[0] & 0xfffff000U) | (entryX & 0xfff);
    entry[1] = (entry[1] & 0xfffff000U) | (entryY & 0xfff);
}

void CopyCellLayoutEntryPosition(u32 destinationId, u32 sourceId, LayoutEntryTable *cellLayout) {
    u16 *destinationEntry;
    u16 *sourceEntry;
    destinationEntry = GetCellLayoutEntry(cellLayout, destinationId);
    sourceEntry = GetCellLayoutEntry(cellLayout, sourceId);
    *destinationEntry = *sourceEntry;
    destinationEntry[1] = sourceEntry[1];
}

void CopyCellLayoutEntryCellIndex(u32 destinationId, u32 sourceId, LayoutEntryTable *cellLayout) {
    u32 *destinationEntry;
    u32 *sourceEntry;
    destinationEntry = GetCellLayoutEntry(cellLayout, destinationId);
    sourceEntry = GetCellLayoutEntry(cellLayout, sourceId);
    destinationEntry[1] = sourceEntry[1];
}

void SetLayoutEntryPositionFromCell(u32 entryId, LayoutTableEntry *output, LayoutEntryTable *cellLayout) {
    short *layoutEntry;
    layoutEntry = GetCellLayoutEntry(cellLayout, entryId);
    output->mUsePosition = 1;
    output->mPositionX = ((*layoutEntry << 0x14) >> 0x14);
    output->mPositionY = ((layoutEntry[1] << 0x14) >> 0x14);
}

void SetLayoutEntryPositionFromLabel(u32 entryId, LayoutTableEntry *output, LayoutEntryTable *labelLayout) {
    short *layoutEntry;
    layoutEntry = GetLabelLayoutEntry(labelLayout, entryId);
    output->mUsePosition = 1;
    output->mPositionX = ((*layoutEntry << 0x14) >> 0x14);
    output->mPositionY = ((layoutEntry[1] << 0x14) >> 0x14);
}

void RectTableSetEntryXY(int id, int entryX, int entryY, LayoutEntryTable *graphics) {
    short *entry = (s16 *) RectTableGetEntry(graphics, id);
    entry[0] = (entry[0] & 0xfffff000U) | (entryX & 0xfff);
    entry[1] = (entry[1] & 0xfffff000U) | (entryY & 0xfff);
}

#pragma thumb off
