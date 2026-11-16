#include "Main/Graphics/cell_layout.h"

void *GetCellLayoutEntry(LayoutEntryTable *layoutEntryTable, s32 entryIndex) {
    u8 *entries;
    s32 entryCount;

    entries = (u8 *) (layoutEntryTable + 1);
    entryCount = layoutEntryTable->mCount;
    if (entryIndex < 0 || entryIndex >= entryCount) {
        return 0;
    }
    return entries + entryIndex * 8;
}
