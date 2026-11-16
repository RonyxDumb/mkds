#pragma once

#include "types.h"

typedef struct Kart Kart;

// Objects whose layout isn't known yet.
extern const u8 g_SomeNullString[];
extern void *sMBGameRegistry[];
extern u8 aNitrokartGhostDataTest01[];
extern const u8 race_sPlaceToTrophyTable[];
extern const u8 data_02154788[];
extern const u32 aP_main_1[];
extern const u32 data_021540c0[];
extern const u32 data_021540c8[];
extern const u32 BattleStageOrder[];
extern const u32 data_02154108[];
extern const u16 race_sStarEffectToonTable[8];
extern const u16 race_sSlipStreamEffectToonTable[8];
extern u8 logo_sDisplayConfigBase[];
extern u8 DebugMenuDisplayConfig[];
extern u8 data_021547f0[];
extern u8 data_02154818[];
extern const Vec3 driverCore_sForwardVec;
extern u8 scproc_sLanguageToDwcUtil[];
// The 16 scene functions, indexed by scene number; the names are in sSceneDefs
// (data_usa_021541a8).
extern u32 scproc_sSceneTable[];
extern const Vec3 driverCore_sZeroVec;
extern const s16 driver_sStartBoostFrameCount[];
extern const s32 data_02154b64[8];
extern const s32 data_02154b84[8];
extern const s32 data_02154ba4[8];
extern const s32 gKartModelScaleYKind0Table[15];
extern const s32 gKartModelOffsetYKind0And2Table[15];
extern const s32 gKartModelScaleYKind1Table[15];
extern const s32 gKartModelOffsetYKind1Table[15];
extern const s32 gKartModelScaleXKind2Table[15];
extern const s32 gKartModelScaleZKind2Table[15];
extern const Vec3 driverCore_sUpVec;
extern const Vec3 driverCore_sRightVec;
extern u32 sCupDefs[][4];
extern u32 savc_sEncTable2[];
extern u32 savc_sEncTable3[];
extern u32 savc_sEncTable1[];
extern u32 savc_sEncTable0[];
extern u16 savc_sCrcPolynomial;
extern const s32 gKartScaleFactorXTable[25];
extern const s32 gKartScaleFactorYTable[25];
extern const s32 gKartScaleFactorZTable[25];
extern Vec3 cam_sVecUp;
extern Vec3 cam_sVecNull;
extern const s32 cam_sCamParams[][3];
extern const s32 data_02154fa4[][3];
extern const s32 data_02154fa8[][3];
extern const Vec3 cam_sVecForward;
extern const Vec3 cam_sVecRight;

extern u16 g_CharacterMaskTable[];
extern const Vec4 data_02154f14;
extern const Vec4 data_02154f24;
extern const Vec4 data_02154f34;
extern const Vec4 data_02154f44;
extern const Vec4 data_02154f54;
extern const Vec3 driverCore_sOneVec;
extern const s32 driver_sRespawnOffsets[][2];
extern const s32 data_02154d50[][2];
// 22 handlers indexed by mSurfaceKind: each plays the effect picked by mSurfaceVariant and returns the surface group
// (0, 2..6, 8..0xb). Bits 8..12 can reach 31 but the table ends at 21.
extern int (*const driver_sHandleFloorCollisionFuncs[])(Kart *);
