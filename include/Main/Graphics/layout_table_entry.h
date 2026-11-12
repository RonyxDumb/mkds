#pragma once

#include "types.h"

typedef struct LayoutTableEntry LayoutTableEntry;

typedef struct Unk02021dc8 Unk02021dc8;

typedef struct LayoutEntryTable LayoutEntryTable;

void DrawLayoutTableEntry(s32 index, LayoutEntryTable *cellLayout, Unk02021dc8 *cells, LayoutEntryTable *labelLayout,
                          void *oamList, LayoutTableEntry *table);
