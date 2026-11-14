#pragma once

#include "types.h"

// Two bytes: a signed 12-bit number, a 2-bit selector at bit 12, and two more bits.
typedef struct LayoutAxis {
    /* 00 */ s16 mPosition : 12;
    /* 00 */ u16 mAlign : 2;
    /* 00 */ u16 mLineAlign : 2;
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

void *GetLabelLayoutEntry(LayoutEntryTable *table, s32 index);
s32 RectTableFindContaining(LayoutEntryTable *table, s32 pointX, s32 pointY);
RectTableEntry *RectTableGetEntry(LayoutEntryTable *table, s32 index);
u16 RectTableGetCount(LayoutEntryTable *table);
s32 GetLayoutAxisStartY(LayoutAxis axis, s32 size);
s32 GetLayoutAxisStartX(LayoutAxis axis, s32 size);
