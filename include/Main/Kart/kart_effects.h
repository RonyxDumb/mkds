#pragma once

#include "types.h"

struct ParticleEmitter;

typedef struct KartFollowEffect {
    /* 00 */ u8 mUnk_00[0x90];
    /* 90 */ void (*mUnk_90)(struct ParticleEmitter *p, s32 a);
    /* 94 */ u8 mUnk_94[0x5];
    /* 99 */ u8 mCountLimit;
    /* 9a */ u8 mCount;
    /* 9b */ u8 mKartIndex;
} KartFollowEffect;

// Two kart indices, -1 for none.
typedef struct KartIndexPair {
    /* 00 */ s16 mFirst;
    /* 02 */ s16 mSecond;
} KartIndexPair;

// Four pairs; rows of gOtherKartPairs and the value of gOtherKartPairsCopy.
typedef struct OtherKartPairs {
    /* 00 */ KartIndexPair mPairs[4];
} OtherKartPairs;

#include "Main/Kart/kart_drift.h"

// Twelve bytes: a count and two effect ids.
typedef struct KartEffectIdSet {
    /* 00 */ u16 mCount;
    /* 04 */ s32 mEffectIds[2];
} KartEffectIdSet;

// 0x20 bytes: id sets for the entry kart and the others, a start function and a velocity factor index.
typedef struct KartSurfaceEffectRow {
    /* 00 */ KartEffectIdSet mEffectIdSets[2];
    /* 18 */ s32 (*mStartEffects)(KartEffectIdSet *a, s32 b, Kart *p);
    /* 1c */ s32 mVelocityFactorIndex;
} KartSurfaceEffectRow;

#include "Main/Unknown/unk_0217a000.h"
#include "code_0201c528.h"

extern const OtherKartPairs gOtherKartPairs[];
extern KartSurfaceEffectRow gKartSurfaceEffectRows[];
extern KartSurfaceEffectRow gKartSurfaceEffectRow1;
extern KartSurfaceEffectRow gKartSurfaceEffectRow2;
extern KartSurfaceEffectRow gKartSurfaceEffectRow3;
extern KartSurfaceEffectRow gKartSurfaceEffectRow4;
extern KartSurfaceEffectRow gKartSurfaceEffectRow5;
extern KartSurfaceEffectRow gKartSurfaceEffectRow6;
extern KartSurfaceEffectRow gKartSurfaceEffectRow7;
extern s32 data_02165934;
extern s32 data_02165938;
extern s32 data_02165940;
extern s32 data_02165954;
extern s32 data_02165958;
extern s32 data_0216595c;
extern s32 data_02165960;
extern s32 data_02165964;
extern s32 data_02165968;
extern s32 gKartEffectVelocityFactors[];
extern Vec3 data_02165984;
extern ParticleEmitter *gFirstCourseCameraEffect;
extern ParticleEmitter *gKartBoostCameraEffect;
extern ParticleEmitter *gSecondCourseCameraEffect;
extern s32 gCourseCameraEffectSpeedReciprocal;
extern OtherKartPairs gOtherKartPairsCopy;

void PlaceKartKillerEffect(s32 kartIndex, Vec3 *position);
void StartKartKillerEffect(s32 kartIndex);
void ReleaseKartStarEffects(s32 kartIndex);
void StopKartStarEffects(s32 kartIndex);
void AdvanceKartStarEffects(s32 kartIndex);
void StartKartStarEffects(s32 kartIndex);
void AdvanceKartAheadEffectWithLimit(ParticleEmitter *effect, s32 phase);
void AdvanceKartAheadEffect(ParticleEmitter *effect, s32 phase);
void PlaceEffectAheadAndUpOfKart(ParticleEmitter *effect, Kart *kart, s32 upDistance, s32 aheadDistance);
void PlaceKartAheadEffect(ParticleEmitter *effect, Kart *kart, void *target);
void AdvanceKartFollowEffectWithVelocity(ParticleEmitter *effect, s32 phase);
void SetupKartFollowEffectWithVelocity(KartFollowEffect *effect, unsigned int kartIndex, unsigned int countLimit);
void AdvanceKartFollowEffect(ParticleEmitter *effect, s32 phase);
void SetupKartFollowEffect(KartFollowEffect *effect, unsigned int kartIndex, unsigned int countLimit);
void SwitchCourseCameraEffectsToCurrentCamera(void);
void AdvanceOldFrappe64FirstCurrentCameraEffect(ParticleEmitter *effect, s32 phase);
void AdvanceOldFrappe64FirstChaseEffect(ParticleEmitter *effect, s32 phase);
void AdvanceOldFrappe64SecondChaseEffect(ParticleEmitter *effect, s32 phase);
void AdvanceOldLuigiAgbFirstCurrentCameraEffect(ParticleEmitter *effect, s32 phase);
void AdvanceOldLuigiAgbSecondCurrentCameraEffect(ParticleEmitter *effect, s32 phase);
void AdvanceOldLuigiAgbFirstChaseEffect(ParticleEmitter *effect, s32 phase);
void AdvanceOldLuigiAgbSecondChaseEffect(ParticleEmitter *effect, s32 phase);
void InitCourseCameraEffects(void);
void PlaceOtherKartEffect(ParticleEmitter *effect, s32 phase);
void StartEffectsAtOtherKarts(s32 pairSetIndex);
void AdvanceOtherKartEffect(ParticleEmitter *effect, s32 phase);
void AdvanceKartWaterEffect(ParticleEmitter *effect, s32 phase);
void AdvanceKartSideEffectWithVelocity(ParticleEmitter *effect, s32 phase);
void AdvanceKartSideEffect(ParticleEmitter *effect, s32 phase);
void AdvanceKartCurrentEffect(ParticleEmitter *effect, s32 phase);
void AdvanceKartBoostCameraEffect(ParticleEmitter *effect, s32 phase);
void ReleaseKartSurfaceEffects(Kart *kart);
void StopKartWaterEffects(Kart *kart);
void StopKartEffectPairs(Kart *kart, s32 deleteAtOnce);
void StopKartCurrentEffects(Kart *kart);
BOOL StartKartWaterEffects(KartEffectIdSet *effectIdSet, s32 velocityFactorIndex, Kart *kart);
s32 StartKartSideEffectsWithVelocity(KartEffectIdSet *effectIdSet, s32 velocityFactorIndex, Kart *kart);
s32 StartKartSideEffects(KartEffectIdSet *effectIdSet, s32 unusedVelocityFactorIndex, Kart *kart);
BOOL StartKartCurrentEffect(KartEffectIdSet *effectIdSet, s32 velocityFactorIndex, Kart *kart);
void ApplyKartSurfaceEffectRow(s32 rowIndex, Kart *kart);
void ApplyKartWaterEffects(Kart *kart);
void ApplyKartSurfaceEffect(s32 functionIndex, Kart *kart);
void StartKartBoostCameraEffect(u32 effectIdIndex, Kart *kart);
void ApplyKartCurrentEffectRow7(Kart *kart);
void ApplyKartSideEffectsRow6(Kart *kart);
void ApplyKartSideEffectsRow5(Kart *kart);
void ApplyKartSideEffectsRow4(Kart *kart);
void ApplyKartSideEffectsRow3(Kart *kart);
void ApplyKartSideEffectsRow2(Kart *kart);
void ApplyKartCurrentEffectRow1(Kart *kart);
void ApplyKartCurrentEffectRow0(Kart *kart);
void SurfaceEffectStopKartCurrentEffects(Kart *kart);
// Copies the position source of the Kart into the position of its matrix (Kart.mUnk_174), then computes mSidePositions
// and mSideDirections of the Kart from the model points 2 and 3 and the Kart matrix.
void ComputeKartSidePoints(Kart *kart);
// Allocates the KartEffects records for a Karts and clears them.
void InitKartEffects(u32 kartCount);
// Returns the KartEffects record of Kart number n.
KartEffects *GetKartEffects(int kartIndex);
