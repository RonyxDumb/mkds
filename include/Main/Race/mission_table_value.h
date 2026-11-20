#pragma once

#include "types.h"

// The missionTable.mtbl file: mRowCount and mColumnCount, then one byte per cell in mValues, mColumnCount cells to a
// row.
typedef struct MissionTable {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u16 mRowCount;
    /* 06 */ u16 mColumnCount;
    /* 08 */ u8 mValues[];
} MissionTable;

u32 GetMissionTableValue(MissionTable *table, u32 row, u32 column);

unsigned int GetMissionTableColumnCount(MissionTable *table);
unsigned int GetMissionTableRowCount(MissionTable *table);
