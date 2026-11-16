#pragma once

#include "types.h"
#include "model_draw_state.h" // NNSG3dJntAnmResult, NNSG3dMatAnmResult, MtxFx44

typedef struct Kart Kart;

// The scale of a joint and its inverse.
typedef struct JointScaleValues {
    /* 00 */ Vec3 mScale;
    /* 0c */ Vec3 mScaleInverse;
} JointScaleValues;

// The node, parent and option flags of one joint scale command.
typedef struct JointScaleCommand {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mNodeDescIndex;
    /* 02 */ u8 mParentId;
    /* 03 */ u8 mScaleCacheFlags;
} JointScaleCommand;

// Frames in the air (mAirborneFrames above this): UpdateKartAirborne sets KART_MOTION_AIRBORNE_LONG,
// AdvanceKartOrientation uses the air tilt and AdvanceKartByVelocity caps the fall speed. KART_STILL_HOLD_STEP_FRAMES:
// collision step frames after which a kart in KART_MOTION_STILL_HOLD with no hit object and no point motion gets
// mQuaternionBlendFactor 0 (tilt no longer blends) when its ground normal is close to the previous one (dot at least
// 0xe66).
#define KART_AIRBORNE_LONG_FRAMES 5
#define KART_STILL_HOLD_STEP_FRAMES 100
// Values for Kart.mHopTiltAngle during a hop: the start value, the limit past which it falls back, and the value it
// falls back to.
#define KART_HOP_TILT_START 0x9c4
#define KART_HOP_TILT_LIMIT 0x6a4
#define KART_HOP_TILT_RESET 0x352

void texmtxCalc_flagT_(MtxFx44 *matrix, const NNSG3dMatAnmResult *matAnmResult);
void texmtxCalc_flagRS_(MtxFx44 *matrix, const NNSG3dMatAnmResult *matAnmResult);
void texmtxCalc_flagR_(MtxFx44 *matrix, const NNSG3dMatAnmResult *matAnmResult);
void texmtxCalc_flagS_(MtxFx44 *matrix, const NNSG3dMatAnmResult *matAnmResult);
void texmtxCalc_flag_(MtxFx44 *matrix, const NNSG3dMatAnmResult *matAnmResult);
void NNSi_G3dGetJointScaleMaya(NNSG3dJntAnmResult *jntAnmResult, JointScaleValues *scaleValues,
                               JointScaleCommand *command, u32 srtFlags);
void NNSi_G3dSendJointSRTMaya(NNSG3dJntAnmResult *jntAnmResult);
void AdvanceKartEffects(Kart *kart);
void AdvanceKartHop(Kart *kart);
void SetKartCourseHitAttributeBit(Kart *kart, u32 hitValue);
void StopKartStillHold(Kart *kart);
void AdvanceKartBoosts(Kart *kart);
void RefreshKartSurface(Kart *kart);
void AdvanceKartOrientation(Kart *kart, Vec3 *direction);
void UpdateKartAirborne(Kart *kart);
void AdvanceKartQuaternionBlendFactor(Kart *kart, const Vec3 *direction);
BOOL StartKartRespawnWaitIfBelowZero(Kart *kart);
void ClearKartGroundContact(Kart *kart, u32 clearedBits);
BOOL IsLowestOffsetFarOnHitBitOrYAbove(Kart *kart, u32 collisionBits, Vec3 *lowestOffset);
BOOL IsLowestOffsetFarOnHitBitOrKartBit(Kart *kart, u32 collisionBits, Vec3 *lowestOffset);
BOOL IsLowestOffsetFarOnHitBit(Kart *kart, u32 collisionBits, Vec3 *lowestOffset);
