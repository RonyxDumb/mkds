#pragma once

#include "types.h"
#include "code_02010c84.h" // NNSG3dJntAnmResult, NNSG3dMatAnmResult, MtxFx44

typedef struct Kart Kart;

typedef struct JointScaleValues {
    /* 00 */ Vec3 mScale;
    /* 0c */ Vec3 mScaleInverse;
} JointScaleValues;

typedef struct JointScaleCommand {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mNodeId;
    /* 02 */ u8 mParentId;
    /* 03 */ u8 mOptionFlags;
} JointScaleCommand;

void texmtxCalc_flagT_(MtxFx44 *matrix, NNSG3dMatAnmResult *matAnmResult);
void texmtxCalc_flagRS_(MtxFx44 *matrix, NNSG3dMatAnmResult *matAnmResult);
void texmtxCalc_flagR_(MtxFx44 *matrix, NNSG3dMatAnmResult *matAnmResult);
void texmtxCalc_flagS_(MtxFx44 *matrix, NNSG3dMatAnmResult *matAnmResult);
void texmtxCalc_flag_(MtxFx44 *matrix, NNSG3dMatAnmResult *matAnmResult);
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
