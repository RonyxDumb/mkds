#include "Main/Unknown/code_02124bc8.h"
#include "Main/Unknown/code_02124bf0.h"

#pragma thumb on

void DrawLayoutTableEntry(s32 index, LayoutEntryTable *cellLayout, Unk02021dc8 *cells, LayoutEntryTable *labelLayout,
                          void *oamList, LayoutTableEntry *table) {
    DrawLayoutEntry(index, cells, cellLayout, labelLayout, oamList, &table[index], 1);
}

#pragma thumb off
