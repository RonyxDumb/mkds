#pragma once

#include "types.h"

// Values of LayoutAxis.mAlign: the position is the start edge, the middle, or the end edge of the extent.
enum {
    LAYOUT_ALIGN_START,
    LAYOUT_ALIGN_CENTER,
    LAYOUT_ALIGN_END,
};

// One axis of a layout entry: mPosition, mAlign (how mPosition sits against the extent) and mLineAlign (passed to the
// text drawing as lineAlign), packed in two bytes.
typedef struct LayoutAxis {
    /* 00 */ s16 mPosition : 12;
    /* 00 */ u16 mAlign : 2;
    /* 00 */ u16 mLineAlign : 2;
} LayoutAxis;

// An entry of a rect table: mAxisX and mAxisY place the left and top edges (GetLayoutAxisStartX/Y with mWidth and
// mHeight), and mWidth and mHeight are its size.
typedef struct RectTableEntry {
    /* 00 */ LayoutAxis mAxisX;
    /* 02 */ LayoutAxis mAxisY;
    /* 04 */ u8 mWidth;
    /* 05 */ u8 mHeight;
} RectTableEntry;

// Header of a layout table: mCount, then the entries (cell, label or rect entries, depending on the table).
typedef struct LayoutEntryTable {
    /* 00 */ u8 mUnk_00[6];
    /* 06 */ u16 mCount;
} LayoutEntryTable;

void *GetLabelLayoutEntry(LayoutEntryTable *table, s32 index);
s32 RectTableFindContaining(LayoutEntryTable *table, s32 pointX, s32 pointY);
RectTableEntry *RectTableGetEntry(LayoutEntryTable *table, s32 index);
u16 RectTableGetCount(LayoutEntryTable *table);
s32 GetLayoutAxisStartY(LayoutAxis axis, s32 size);
s32 GetLayoutAxisStartX(LayoutAxis axis, s32 size);
