#pragma once

#include "types.h"
#include "Main/Unknown/code_02124094.h" // LayoutTableEntry, Unk02021dc8, LayoutEntryTable
#include "Main/Unknown/code_020c06c4.h" // RaceHudOamBuffer

void InitLayoutTable(void *heap, LayoutEntryTable *cellLayout, LayoutEntryTable *labelLayout,
                     LayoutTableEntry **tableOut);
u32 DrawLayoutEntry(s32 index, Unk02021dc8 *cells, LayoutEntryTable *cellLayout, LayoutEntryTable *labelLayout,
                    RaceHudOamBuffer *oamList, LayoutTableEntry *entry, s32 incrementFlag);
void DrawLayoutTable(LayoutEntryTable *cellLayout, Unk02021dc8 *cells, LayoutEntryTable *labelLayout, void *oamList,
                     LayoutTableEntry *table);
void DrawLayoutTableKeepMatrixCount(LayoutEntryTable *cellLayout, Unk02021dc8 *cells, LayoutEntryTable *labelLayout,
                                    void *oamList, LayoutTableEntry *table);
