#pragma once

#include "types.h"
#include "code_02010c84.h" // NNSG3dJntAnmResult, NNSG3dMatAnmResult, MtxFx44

typedef struct Kart Kart;

typedef struct Unk01ff9940_B {
    /* 00 */ Vec3 mScale;
    /* 0c */ Vec3 mScaleInverse;
} Unk01ff9940_B;

typedef struct Unk01ff9940_C {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mNodeId;
    /* 02 */ u8 mParentId;
    /* 03 */ u8 mOptionFlags;
} Unk01ff9940_C;

void texmtxCalc_flagT_(MtxFx44 *matrix, NNSG3dMatAnmResult *matAnmResult);
void texmtxCalc_flagRS_(MtxFx44 *matrix, NNSG3dMatAnmResult *matAnmResult);
void texmtxCalc_flagR_(MtxFx44 *matrix, NNSG3dMatAnmResult *matAnmResult);
void texmtxCalc_flagS_(MtxFx44 *matrix, NNSG3dMatAnmResult *matAnmResult);
void texmtxCalc_flag_(MtxFx44 *matrix, NNSG3dMatAnmResult *matAnmResult);
void NNSi_G3dGetJointScaleMaya(NNSG3dJntAnmResult *jntAnmResult, Unk01ff9940_B *scaleValues, Unk01ff9940_C *command,
                               u32 srtFlags);
void NNSi_G3dSendJointSRTMaya(NNSG3dJntAnmResult *jntAnmResult);
void AdvanceKartEffects(Kart *p);
void AdvanceKartHop(Kart *p);
void SetKartCourseHitAttributeBit(Kart *kart, u32 hitValue);
void StopKartStillHold(Kart *kart);
void AdvanceKartBoosts(Kart *kart);
void RefreshKartSurface(Kart *p);
void AdvanceKartOrientation(Kart *p, Vec3 *a);
void UpdateKartAirborne(Kart *p);
void AdvanceKartQuaternionBlendFactor(Kart *kart, const Vec3 *a);
BOOL StartKartRespawnWaitIfBelowZero(Kart *kart);
void ClearKartGroundContact(Kart *kart, u32 clearedBits);
BOOL IsLowestOffsetFarOnHitBitOrYAbove(Kart *kart, u32 collisionBits, Vec3 *lowestOffset);
BOOL IsLowestOffsetFarOnHitBitOrKartBit(Kart *kart, u32 collisionBits, Vec3 *lowestOffset);
BOOL IsLowestOffsetFarOnHitBit(Kart *kart, u32 collisionBits, Vec3 *lowestOffset);
