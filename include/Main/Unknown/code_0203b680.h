#pragma once

#include "types.h"

// missionTable.mtbl: byte table, mUnk_06 is the row width.
typedef struct Unk0203b680 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u8 mUnk_08[];
} Unk0203b680;

u32 GetMissionTableValue(Unk0203b680 *table, u32 row, u32 column);
