#pragma once

#include "types.h"

// missionTable.mtbl: byte table, mUnk_06 is the row width.
typedef struct MissionTable {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u16 mRowCount;
    /* 06 */ u16 mColumnCount;
    /* 08 */ u8 mValues[];
} MissionTable;

u32 GetMissionTableValue(MissionTable *table, u32 row, u32 column);

unsigned int GetMissionTableColumnCount(MissionTable *table);
unsigned int GetMissionTableRowCount(MissionTable *table);
