#pragma once
#include "types.h"
#include "Main/Kart/kart_participant_record.h"

typedef struct Kart Kart;


// The 16 scene functions, indexed by scene number; the names are in gSceneNames.
extern const u32 gSceneFuncs[16];

extern const s32 gKartScaleFactorXTable[KART_SCALE_TABLE_STEPS];

extern const s32 gKartScaleFactorYTable[KART_SCALE_TABLE_STEPS];

extern const s32 gKartScaleFactorZTable[25];

extern Vec3 gCameraVec3UnitY;

extern Vec3 gCameraVec3Zero;

extern const Vec3 gCameraVec3UnitZ;

extern const Vec3 gCameraVec3UnitX;

// Per kart: the side and the forward offset of its respawn position.
extern const s32 gKartRespawnOffsets[8][2];

// 22 handlers indexed by mSurfaceKind: each plays the effect picked by mSurfaceVariant and returns the surface group
// (0, 2..6, 8..0xb). Bits 8..12 can reach 31 but the table ends at 21.
extern int (*const gKartSurfaceFunctions[22])(Kart *);
