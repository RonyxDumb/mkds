#pragma once

#include "types.h"
#include "g2d_Animation.h"

void DrawRaceHudSubScreenCellGroups(void *oamBuffer);
void UpdateRaceHudSubScreenCellGroups(void);
void ClearRaceHudSubScreenCellGroups(void);

// The 49 entries of gRaceHudSubScreenCellGroupFunctions.
typedef struct RaceHudSubScreenCellGroupFunctions {
    /* 00 */ s32 (*mCreate)(void);
    /* 04 */ void (*mClear)(void);
    /* 08 */ void (*mUpdate)(void);
    /* 0c */ void (*mDraw)(void *);
} RaceHudSubScreenCellGroupFunctions;

void InitRaceHudSubScreenCellGroups(void);

typedef struct RaceHudSubScreenCells RaceHudSubScreenCells;

// Second view of an OAM entry: two words, each with a two-bit part at bit 10.
typedef struct RaceHudOamBits {
    /* 0 */ u32 mUnk_00 : 10;
    /* 0 */ u32 mUnk_0a : 2;
    /* 0 */ u32 mUnk_0c : 20;
    /* 4 */ u32 mUnk_04 : 10;
    /* 4 */ u32 mUnk_0e : 2;
    /* 4 */ u32 mUnk_10 : 20;
} RaceHudOamBits;

// Argument of the race HUD draw functions: 0x80 elements of 8 bytes, then a halfword.
typedef struct RaceHudOamBuffer {
    union {
        /* 000 */ GXOamAttr mOams[0x80];
        /* 000 */ RaceHudOamBits mOamBits[0x80];
        /* 000 */ GXOamAffine mMatrices[0x20];
    };
    /* 400 */ u16 mOamCount;
    /* 402 */ u16 mMatrixCount;
} RaceHudOamBuffer;

void DrawRaceHudSubScreenCells(RaceHudOamBuffer *oamBuffer, RaceHudSubScreenCells *cells, s32 useRotation);
void DrawRaceHudSubScreenCellsScaled(RaceHudOamBuffer *oamBuffer, RaceHudSubScreenCells *cells, s32 useRotation);

void ClearRaceHudSubScreenCells(RaceHudSubScreenCells **cellsPointerAddress);

BOOL CreateRaceHudSubScreenCells(RaceHudSubScreenCells **outCells, s32 kind);
BOOL CreateRaceHudSubScreenCellsWithCount(RaceHudSubScreenCells **outCells, s32 objectCount);

unsigned int GetRaceHudSubScreenInverseScale(void);
unsigned int GetRaceHudSubScreenScale(void);
unsigned int GetRaceHudSubScreenMinDrawValue(void);
