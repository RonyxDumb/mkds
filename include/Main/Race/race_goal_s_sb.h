#pragma once

#include "types.h"

typedef struct Ncgr Ncgr;
typedef struct Nscr Nscr;
typedef struct Nclr Nclr;

s32 GetRaceGoalSOffsetX(void);
Nscr *GetRaceGoalSNscr(unsigned int index);
// Two pointers; the elements of 8 bytes at member 0xb8 of the object behind gRaceGoalS.
typedef struct PaletteAndChars {
    /* 00 */ Nclr *mPalette;
    /* 04 */ Ncgr *mChars;
} PaletteAndChars;

PaletteAndChars *GetRaceGoalSBPaletteAndChars(unsigned int index);
