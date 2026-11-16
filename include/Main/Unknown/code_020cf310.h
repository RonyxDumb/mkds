#pragma once

#include "types.h"

// Halfwords written by UpdateRaceHudSubScreenBgPalette (it writes up to element 0xf5).
typedef struct RaceHudSubScreenBgPalette {
    /* 000 */ u16 field0[0xf6];
} RaceHudSubScreenBgPalette;

s32 mpicn_createExplosionIcon(void);
void UpdateRaceHudSubScreenBgPalette(RaceHudSubScreenBgPalette *palette);
void sub_20CFCA4(void);
