#include "Main/Unknown/code_02025bb4.h"
#include "Main/Unknown/code_02124094.h"
#include "code_0201ea30.h"
#include "code_0201ea58.h"

#pragma thumb on

void SetCellLayoutEntryXY(int entryId, int x, int y, Unk0201ea30 *cellLayout) {
    short *entry = (func_0201ea30(cellLayout, entryId));
    entry[0] = (entry[0] & 0xfffff000U) | (x & 0xfff);
    entry[1] = (entry[1] & 0xfffff000U) | (y & 0xfff);
}

void CopyCellLayoutEntryPosition(u32 destinationId, u32 sourceId, Unk0201ea30 *cellLayout) {
    u16 *destinationEntry;
    u16 *sourceEntry;
    destinationEntry = func_0201ea30(cellLayout, destinationId);
    sourceEntry = func_0201ea30(cellLayout, sourceId);
    *destinationEntry = *sourceEntry;
    destinationEntry[1] = sourceEntry[1];
}

void CopyCellLayoutEntryCellIndex(u32 destinationId, u32 sourceId, Unk0201ea30 *cellLayout) {
    u32 *destinationEntry;
    u32 *sourceEntry;
    destinationEntry = func_0201ea30(cellLayout, destinationId);
    sourceEntry = func_0201ea30(cellLayout, sourceId);
    destinationEntry[1] = sourceEntry[1];
}

void SetLayoutEntryPositionFromCell(u32 entryId, LayoutTableEntry *output, Unk0201ea30 *cellLayout) {
    short *layoutEntry;
    layoutEntry = func_0201ea30(cellLayout, entryId);
    output->mUsePosition = 1;
    output->mPositionX = ((*layoutEntry << 0x14) >> 0x14);
    output->mPositionY = ((layoutEntry[1] << 0x14) >> 0x14);
}

void SetLayoutEntryPositionFromLabel(u32 entryId, LayoutTableEntry *output, Unk0201ea30 *labelLayout) {
    short *layoutEntry;
    layoutEntry = func_0201ea58(labelLayout, entryId);
    output->mUsePosition = 1;
    output->mPositionX = ((*layoutEntry << 0x14) >> 0x14);
    output->mPositionY = ((layoutEntry[1] << 0x14) >> 0x14);
}

void RectTableSetEntryXY(int id, int x, int y, Unk0201ea30 *graphics) {
    short *entry = (s16 *) RectTableGetEntry(graphics, id);
    entry[0] = (entry[0] & 0xfffff000U) | (x & 0xfff);
    entry[1] = (entry[1] & 0xfffff000U) | (y & 0xfff);
}

#pragma thumb off
