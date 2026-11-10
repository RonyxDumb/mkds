#pragma once

#include "types.h"

// Two bytes: a signed 12-bit number, a 2-bit selector at bit 12, and two more bits.
typedef struct LayoutAxis {
    /* 00 */ s16 mUnk_00_0 : 12;
    /* 00 */ u16 mUnk_00_12 : 2;
    /* 00 */ u16 mUnk_00_14 : 2;
} LayoutAxis;

// 6-byte entry of the array RectTableGetEntry indexes: two LayoutAxis and the two sizes added to what
// GetLayoutAxisStartX and GetLayoutAxisStartY return for them.
typedef struct RectTableEntry {
    /* 00 */ LayoutAxis mAxisX;
    /* 02 */ LayoutAxis mAxisY;
    /* 04 */ u8 mWidth;
    /* 05 */ u8 mHeight;
} RectTableEntry;

// Header of an array: a count at 6, then the entries from 8 (GetCellLayoutEntry indexes 8-byte entries,
// GetLabelLayoutEntry 12-byte ones, RectTableGetEntry and RectTableFindContaining 6-byte ones).
typedef struct LayoutEntryTable {
    /* 00 */ u8 mUnk_00[6];
    /* 06 */ u16 mCount;
} LayoutEntryTable;

void *GetLabelLayoutEntry(LayoutEntryTable *a, s32 b);
s32 RectTableFindContaining(LayoutEntryTable *a, s32 b, s32 c);
RectTableEntry *RectTableGetEntry(LayoutEntryTable *a, s32 b);
u16 RectTableGetCount(LayoutEntryTable *a);
s32 GetLayoutAxisStartY(LayoutAxis a, s32 b);
s32 GetLayoutAxisStartX(LayoutAxis a, s32 b);
