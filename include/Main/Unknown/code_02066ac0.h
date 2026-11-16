#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h" // Kart
#include "Main/Unknown/code_020653d0.h" // ParticipantKartRecord

// Node of the list at 0x80 of a ParticipantKartRecordState: a halfword at 0x08 and an ParticipantKartRecord at 0x0c.
typedef struct ParticipantKartRecordNode {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ s16 mApplyTimer;
    /* 0a */ u8 mUnk_0a[2];
    /* 0c */ ParticipantKartRecord mRecord;
} ParticipantKartRecordNode;

// Table of 0x5c-byte entries; the code writes the word at 0x00.
typedef struct Unk02175664 {
    /* 00 */ s32 mSourceKind;
    /* 04 */ u8 mUnk_04[0x58];
} Unk02175664;

typedef struct KartSurfaceSoundIds {
    /* 00 */ u32 mSoundIds[3];
} KartSurfaceSoundIds;

extern const u32 gKartSurfaceKind6Effects[];
extern const u32 data_02154a84[];
extern const u32 gKartSurfaceKind17Effects[];
extern const u32 gKartSurfaceKind20Effects[];
extern const u32 gKartSurfaceKind1Effects[];
extern const u32 gKartSurfaceKind10Effects[];
extern const u32 gKartSurfaceKind2Effects[];
extern const u32 gKartSurfaceKind3Effects[];
extern const u32 gKartSurfaceKind5Effects[];
extern const u16 gKartWobbleAnglePerCall;
extern const s32 gKartWobbleAngleFactor;
extern const s32 gKartWobbleEaseFactor;
extern const s32 gKartWobbleAmplitudeDecay;
extern const KartSurfaceSoundIds gKartSurfaceSoundIds;
extern const s32 data_0216559c[];
extern const s32 gKartSurfaceKind12VerticalSpeeds[];
extern Unk02175664 data_02175664[];

void func_02066ac0(Kart *kart);
void AdvanceKartWobble(Kart *kart);
void func_02066fe0(Kart *kart);
void driver_updateEnemy(Kart *kart);
// 1 when the turn start group, the level 3 group or the level 4 group (not while mLevel4StopRequested is TRUE) exists,
// else 0; the level 2 group is not counted.
u32 IsKartTurnEffectsActive(Kart *kart);
// Surface kind 10 (entry 10 of driver_sHandleFloorCollisionFuncs): passes the entry that gKartSurfaceKind10Effects gives for
// mSurfaceVariant to rptc_collisionParticleRender and returns surface group 0, for which driver_handleFloorCollision uses the factor
// 0x1000 instead of an entry of mSurfaceSpeedLimitFactors.
s32 driver_handleOobCollision(Kart *kart);
// Surface kind 19 (entry 19 of driver_sHandleFloorCollisionFuncs): unless mSurfaceGroup is already 0xb and bit 0x80000000 of
// mUnk_44 is clear it runs driver_addBoost and, for the selected kart, calls sfx_21090C4 with 0x1b9; otherwise it sets
// mUnk_238 to 0x3c. Then it sets bits 0x40000001 of mUnk_48, runs rptc_killDriverEffects_copy and returns surface group 0xb.
s32 driver_handleLoopingCollision(Kart *kart);
// Surface kind 17 (entry 17 of driver_sHandleFloorCollisionFuncs): passes the entry that gKartSurfaceKind17Effects gives for
// mSurfaceVariant to rptc_collisionParticleRender and returns surface group 0xa.
s32 driver_handleFallsWaterCollision(Kart *kart);
// Surface kind 15 (entry 15 of driver_sHandleFloorCollisionFuncs): runs rptc_collisionParticleRender with 0; while bit 0x10000 of mUnk_48
// is clear it then runs driver_pipeTeleport with mSurfaceVariant when RaceSetup.mMode is MODE_BATTLE or
// MODE_MISSION_RUN, and in the other modes sets that bit and runs driver_cannonLaunch with 0. Returns surface group 9.
s32 driver_handleCannonCollision(Kart *kart);
// Surface kind 18 (entry 18 of driver_sHandleFloorCollisionFuncs): the body of kind 7, followed by setting bit 0x400000 of mUnk_48;
// returns surface group 8.
s32 driver_handleBoostPad2Collision(Kart *kart);
// Surface kind 12 (entry 12 of driver_sHandleFloorCollisionFuncs): sets bit 0x10000000 of mUnk_48, sets mVerticalSpeed from
// gKartSurfaceKind12VerticalSpeeds and mUnk_4c4 from data_0216559c by mSurfaceVariant, runs rptc_killDriverEffects_copy and
// returns surface group 8; on course 0xc or 0x28, when mSurfaceGroup was not already 8 or bit 0x80000000 of mUnk_44 is
// set, it first calls sfx_21090C4 with 0x15e.
s32 driver_handleJumpPadCollision(Kart *kart);
// Surface kind 7 (entry 7 of driver_sHandleFloorCollisionFuncs): unless mSurfaceGroup is already 8 and bit 0x80000000 of mUnk_44 is
// clear it runs driver_addBoost and, for the selected kart with mSurfaceVariant above 0, calls sfx_21090C4 with the id
// that gKartSurfaceSoundIds gives for mSurfaceVariant minus 1; otherwise it sets mUnk_238 to 0x3c. Then it runs
// rptc_killDriverEffects_copy and returns surface group 8.
s32 driver_handleBoostPadCollision(Kart *kart);
// Surface kind 6 (entry 6 of driver_sHandleFloorCollisionFuncs): passes the entry that gKartSurfaceKind6Effects gives for
// mSurfaceVariant to rptc_collisionParticleRender and returns surface group 6.
s32 driver_handleSlippery2Collision(Kart *kart);
// Surface kind 5 (entry 5 of driver_sHandleFloorCollisionFuncs): runs driver_notifyOffRoad, passes the entry that gKartSurfaceKind5Effects
// gives for mSurfaceVariant to rptc_collisionParticleRender and returns surface group 4.
s32 driver_handleHeavyOffRoadCollision(Kart *kart);
// Surface kind 3 (entry 3 of driver_sHandleFloorCollisionFuncs): runs driver_notifyOffRoad, passes the entry that gKartSurfaceKind3Effects
// gives for mSurfaceVariant to rptc_collisionParticleRender and returns surface group 3.
s32 driver_handleOffRoadCollision(Kart *kart);
// Surface kind 2 (entry 2 of driver_sHandleFloorCollisionFuncs): runs driver_notifyOffRoad, passes the entry that gKartSurfaceKind2Effects
// gives for mSurfaceVariant to rptc_collisionParticleRender and returns surface group 2.
s32 driver_handleWeakOffRoadCollision(Kart *kart);
// Surface kind 1 (entry 1 of driver_sHandleFloorCollisionFuncs): passes the entry that gKartSurfaceKind1Effects gives for
// mSurfaceVariant to rptc_collisionParticleRender and returns surface group 5.
s32 driver_handleSlippery1Collision(Kart *kart);
// Surface kind 20 (entry 20 of driver_sHandleFloorCollisionFuncs): passes the entry that gKartSurfaceKind20Effects gives for
// mSurfaceVariant to rptc_collisionParticleRender and returns surface group 0, for which driver_handleFloorCollision uses the factor
// 0x1000 instead of an entry of mSurfaceSpeedLimitFactors.
s32 driver_handleStickyCollision(Kart *kart);
s32 driver_handleDefaultFloorCollision(Kart *kart);
// Collision response 11 of driver_sColReactionInitTable (indexed by the value mobj_handleDriverCollision returns for the kart
// and the map object): when driver_startDossunFlatEffect holds for the kart, mUnk_44c of the kart is not the object and the kart is
// the selected kart, increments the counter of the record driver_getPlayerStatistics returns. Stores 0 through the second
// parameter and returns 0.
s32 driver_initDossunSmashReaction(Kart *kart, s32 *output, s32 mapObject);
// Collision response 14 of driver_sColReactionInitTable (indexed by the value mobj_handleDriverCollision returns for the kart
// and the map object): stores 0xc through the second parameter, clears bits of mUnk_48 with the mask 0xdfe77fdf, zeroes
// mUnk_238, the mUnk_00 member of mUnk_538 and mUnk_23c, for the selected kart calls cam_resetPlayerCameraTargetFov unless
// bit 0x10000000 of mUnk_4c or bit 0x4000000 of mUnk_48 is set and then runs dce_stopBlur, then runs driver_tryStartSpinOut
// with 1 and, when that succeeds, rptc_startElectricEffect with the kart index. Returns 5.
s32 driver_initSingleSpinElectricityReaction(Kart *kart, s32 *output);
// Collision response 13 of driver_sColReactionInitTable (indexed by the value mobj_handleDriverCollision returns for the kart
// and the map object): stores 0xc through the second parameter, clears bits of mUnk_48 with the mask 0xdfe77fdf, zeroes
// mUnk_238, the mUnk_00 member of mUnk_538 and mUnk_23c, for the selected kart calls cam_resetPlayerCameraTargetFov unless
// bit 0x10000000 of mUnk_4c or bit 0x4000000 of mUnk_48 is set and then runs dce_stopBlur, and sets mForwardSpeed
// to 0. Returns 5.
s32 driver_initReaction13(Kart *kart, s32 *output);
// Declared here until the code that defines them is decompiled.
