#pragma once

#include "types.h"
#include "Main/Graphics/layout_entry_angle.h" // LayoutTableEntry, NNSG2dCellDataBank, LayoutEntryTable
#include "Main/Race/race_hud_sub_screen_cells.h" // RaceHudOamBuffer

typedef struct LayoutTableEntry LayoutTableEntry;

typedef struct NNSG2dCellDataBank NNSG2dCellDataBank;

typedef struct LayoutEntryTable LayoutEntryTable;

void DrawLayoutTableEntry(s32 index, LayoutEntryTable *cellLayout, NNSG2dCellDataBank *cells, LayoutEntryTable *labelLayout,
                          void *oamList, LayoutTableEntry *table);

void InitLayoutTable(void *heap, LayoutEntryTable *cellLayout, LayoutEntryTable *labelLayout,
                     LayoutTableEntry **tableOut);
u32 DrawLayoutEntry(s32 index, NNSG2dCellDataBank *cells, LayoutEntryTable *cellLayout, LayoutEntryTable *labelLayout,
                    RaceHudOamBuffer *oamList, LayoutTableEntry *entry, s32 incrementFlag);
void DrawLayoutTable(LayoutEntryTable *cellLayout, NNSG2dCellDataBank *cells, LayoutEntryTable *labelLayout, void *oamList,
                     LayoutTableEntry *table);
void DrawLayoutTableKeepMatrixCount(LayoutEntryTable *cellLayout, NNSG2dCellDataBank *cells, LayoutEntryTable *labelLayout,
                                    void *oamList, LayoutTableEntry *table);

void InitLayoutTableEntries(LayoutTableEntry *entry, s32 count);
