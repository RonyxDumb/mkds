#pragma once

#include "types.h"
#include "Main/Unknown/code_02124094.h" // LayoutTableEntry, Unk02021dc8, Unk0201ea30
#include "Main/Unknown/code_020c06c4.h" // RaceHudOamBuffer

void InitLayoutTable(void *heap, Unk0201ea30 *cellLayout, Unk0201ea30 *labelLayout, LayoutTableEntry **tableOut);
u32 DrawLayoutEntry(s32 index, Unk02021dc8 *cells, Unk0201ea30 *cellLayout, Unk0201ea30 *labelLayout,
                    RaceHudOamBuffer *oamList, LayoutTableEntry *entry, s32 incrementFlag);
void DrawLayoutTable(Unk0201ea30 *cellLayout, Unk02021dc8 *cells, Unk0201ea30 *labelLayout, void *oamList,
                     LayoutTableEntry *table);
void DrawLayoutTableKeepMatrixCount(Unk0201ea30 *cellLayout, Unk02021dc8 *cells, Unk0201ea30 *labelLayout,
                                    void *oamList, LayoutTableEntry *table);
