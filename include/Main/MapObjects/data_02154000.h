#pragma once
#include "types.h"

typedef struct Kart Kart;

// Objects whose layout isn't known yet.

extern void *gGameRegistry[];

extern const u32 data_usa_02154ff8[];

extern u8 data_021547f0[];

// The 16 scene functions, indexed by scene number; the names are in gSceneNames
// (data_usa_021541a8).
extern const u32 gSceneFuncs[16];

extern u32 gCupCourseIdTable[][4];

extern const s32 gKartScaleFactorXTable[25];

extern const s32 gKartScaleFactorYTable[25];

extern const s32 gKartScaleFactorZTable[25];

extern Vec3 gCameraVec3UnitY;

extern Vec3 data_usa_02154fdc;

extern const Vec3 data_usa_02154fb8;

extern const Vec3 data_usa_02154fd0;

extern const s32 data_usa_02154d4c[][2];

extern const s32 data_usa_02154d50[][2];

// 22 handlers indexed by mSurfaceKind: each plays the effect picked by mSurfaceVariant and returns the surface group
// (0, 2..6, 8..0xb). Bits 8..12 can reach 31 but the table ends at 21.
extern int (*const gKartSurfaceFunctions[])(Kart *);
