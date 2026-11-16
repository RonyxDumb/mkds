#pragma once

#include "types.h"
#include "sprite_animation_control.h"

typedef struct RaceHudOamBuffer RaceHudOamBuffer;

void DrawRaceHudSubScreenCellGroups(RaceHudOamBuffer *oamBuffer);
void UpdateRaceHudSubScreenCellGroups(void);
void ClearRaceHudSubScreenCellGroups(void);

// One entry of gRaceHudSubScreenCellGroupFunctions: the create, clear, update and draw functions of a cell group.
typedef struct RaceHudSubScreenCellGroupFunctions {
    /* 00 */ s32 (*mCreate)(void);
    /* 04 */ void (*mClear)(void);
    /* 08 */ void (*mUpdate)(void);
    /* 0c */ void (*mDraw)(RaceHudOamBuffer *oamBuffer);
} RaceHudSubScreenCellGroupFunctions;

void InitRaceHudSubScreenCellGroups(void);

typedef struct RaceHudSubScreenCells RaceHudSubScreenCells;

// Values of RaceHudOamBits.mObjMode: the object mode of the OAM entry.
enum {
    RACE_HUD_OBJ_MODE_NORMAL,
    RACE_HUD_OBJ_MODE_TRANSLUCENT,
    RACE_HUD_OBJ_MODE_WINDOW,
    RACE_HUD_OBJ_MODE_BITMAP,
};

// Second view of an OAM entry: two words, each with a two-bit part at bit 10.
typedef struct RaceHudOamBits {
    /* 0 */ u32 mUnk_00 : 10;
    /* 0 */ u32 mObjMode : 2;
    /* 0 */ u32 mUnk_0c : 20;
    /* 4 */ u32 mUnk_04 : 10;
    /* 4 */ u32 mPriority : 2;
    /* 4 */ u32 mUnk_10 : 20;
} RaceHudOamBits;

// Number of OAM entries in a RaceHudOamBuffer.
#define RACE_HUD_OAM_COUNT 0x80
// Bits 10 and 11 of the first word of an OAM entry hold the object mode (DrawRaceItemSlot and DrawRaceModeCount set the
// object window mode); the same bits of the second word hold the priority.
#define RACE_HUD_OAM_MODE_MASK 0xc00
#define RACE_HUD_OAM_MODE_OBJ_WINDOW 0x800
#define RACE_HUD_OAM_PRIORITY_MASK 0xc00
#define RACE_HUD_OAM_PRIORITY_1 0x400

// An OAM buffer: the OAM entries or affine matrices and their counts; the race HUD draw functions fill it.
typedef struct RaceHudOamBuffer {
    union {
        /* 000 */ GXOamAttr mOams[RACE_HUD_OAM_COUNT];
        /* 000 */ RaceHudOamBits mOamBits[RACE_HUD_OAM_COUNT];
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

extern struct RaceHudSubScreenCellGroups *gRaceHudSubScreenCellGroups;

// The burner cells count mSecond up to the cycle and show the first cell below the half; the pakkun cells swap their
// cell with this bit of the frame counter.
#define RACE_HUD_BURNER_CYCLE_FRAMES 8
#define RACE_HUD_BURNER_HALF_FRAMES 4
#define RACE_HUD_PAKKUN_SF_SWAP_FRAME_BIT 0x10
