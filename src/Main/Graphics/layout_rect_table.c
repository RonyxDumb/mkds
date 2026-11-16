#include "Main/Graphics/layout_rect_table.h"

s32 GetLayoutAxisStartX(LayoutAxis axis, s32 size) {
    s32 start;

    start = axis.mPosition;
    switch (axis.mAlign) {
        case LAYOUT_ALIGN_CENTER:
            start -= (size + 1) / 2;
            break;
        case LAYOUT_ALIGN_END:
            start -= size;
            break;
    }
    return start;
}

s32 GetLayoutAxisStartY(LayoutAxis axis, s32 size) {
    s32 start;

    start = axis.mPosition;
    switch (axis.mAlign) {
        case LAYOUT_ALIGN_CENTER:
            start -= (size + 1) / 2;
            break;
        case LAYOUT_ALIGN_END:
            start -= size;
            break;
    }
    return start;
}

u16 RectTableGetCount(LayoutEntryTable *table) {
    return table->mCount;
}

RectTableEntry *RectTableGetEntry(LayoutEntryTable *table, s32 index) {
    RectTableEntry *entries;

    entries = (RectTableEntry *) (table + 1);
    if (index < 0 || index >= RectTableGetCount(table)) {
        return 0;
    }
    return entries + index;
}

s32 RectTableFindContaining(LayoutEntryTable *table, s32 pointX, s32 pointY) {
    s32 entryIndex;
    RectTableEntry *entry;
    s32 left;
    s32 top;
    s32 right;
    s32 bottom;

    entry = (RectTableEntry *) (table + 1);
    for (entryIndex = 0; entryIndex < RectTableGetCount(table); entryIndex++) {
        left = GetLayoutAxisStartX(entry->mAxisX, entry->mWidth);
        top = GetLayoutAxisStartY(entry->mAxisY, entry->mHeight);
        right = left + entry->mWidth;
        bottom = top + entry->mHeight;
        if (left <= pointX && pointX <= right && top <= pointY && pointY <= bottom) {
            return entryIndex;
        }
        entry++;
    }
    return -1;
}

void *GetLabelLayoutEntry(LayoutEntryTable *table, s32 index) {
    u8 *entries;
    s32 count;

    entries = (u8 *) (table + 1);
    count = table->mCount;
    if (index < 0 || index >= count) {
        return 0;
    }
    return entries + index * 12;
}
