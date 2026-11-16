#pragma once

#include "types.h"

typedef struct Ncgr Ncgr;
typedef struct Nscr Nscr;
typedef struct Nclr Nclr;

s32 GetRaceGoalSOffsetX(void);
Nscr *GetRaceGoalSNscr(unsigned int index);
// The palette and chars of the file pair at RaceGoalS.mRaceGoalSB.
typedef struct PaletteAndChars {
    /* 00 */ Nclr *mPalette;
    /* 04 */ Ncgr *mChars;
} PaletteAndChars;

PaletteAndChars *GetRaceGoalSBPaletteAndChars(unsigned int index);
