#pragma once

#include "types.h"

struct Unk0201ca6c;

typedef struct KartFollowEffect {
    /* 00 */ u8 mUnk_00[0x90];
    /* 90 */ void (*mUnk_90)(struct Unk0201ca6c *p, s32 a);
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

#include "Main/Unknown/code_0206bcb0.h"

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
extern KartSurfaceEffectRow rptc_sColEffects[];
extern KartSurfaceEffectRow gKartSurfaceEffectRow1;
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
extern Unk0201ca6c *rptc_sWeatherEmitter1;
extern Unk0201ca6c *rptc_sBoostEmitter;
extern Unk0201ca6c *rptc_sWeatherEmitter2;
extern s32 data_0217ae9c;
extern OtherKartPairs gOtherKartPairsCopy;

void rptc_updateBulletBillEffect(s32 kartIndex, Vec3 *position);
void rptc_startKillerEffect(s32 kartIndex);
void rptc_stopRainbowEffectDirect(s32 kartIndex);
void rptc_stopRainbowEffect(s32 kartIndex);
void rptc_updateRainbowEffect(s32 kartIndex);
void rptc_startRainbowEffect(s32 kartIndex);
void AdvanceKartAheadEffectWithLimit(Unk0201ca6c *effect, s32 a);
void AdvanceKartAheadEffect(Unk0201ca6c *effect, s32 a);
void PlaceEffectAheadAndUpOfKart(Unk0201ca6c *effect, Kart *kart, s32 upDistance, s32 aheadDistance);
void PlaceKartAheadEffect(Unk0201ca6c *effect, Kart *kart, void *a);
void AdvanceKartFollowEffectWithVelocity(Unk0201ca6c *effect, s32 a);
void rptc_2081E3C(KartFollowEffect *effect, unsigned int kartIndex, unsigned int countLimit);
void AdvanceKartFollowEffect(Unk0201ca6c *effect, s32 a);
void rptc_2081F10(KartFollowEffect *effect, unsigned int kartIndex, unsigned int countLimit);
void rptc_2081F30(void);
void rptc_snowCallback1(Unk0201ca6c *effect, s32 a);
void rptc_snowCallback2(Unk0201ca6c *effect, s32 a);
void rptc_snowCallback3(Unk0201ca6c *effect, s32 a);
void rptc_rainCallback3(Unk0201ca6c *effect, s32 a);
void rptc_rainCallback4(Unk0201ca6c *effect, s32 a);
void rptc_rainCallback1(Unk0201ca6c *effect, s32 a);
void rptc_rainCallback2(Unk0201ca6c *effect, s32 a);
void rptc_initWeather(void);
void PlaceOtherKartEffect(Unk0201ca6c *effect, s32 a);
void StartEffectsAtOtherKarts(s32 pairSetIndex);
void AdvanceOtherKartEffect(Unk0201ca6c *effect, s32 a);
void rptc_2082FEC(Unk0201ca6c *effect, s32 a);
void rptc_20831BC(Unk0201ca6c *effect, s32 a);
void rptc_208335C(Unk0201ca6c *effect, s32 a);
void AdvanceKartCurrentEffect(Unk0201ca6c *effect, s32 a);
void rptc_boostEmitterCallback(Unk0201ca6c *effect, s32 a);
void rptc_2083834(Kart *kart);
void rptc_20838DC(Kart *kart);
void rptc_killDriverEffects2(Kart *kart, s32 deleteAtOnce);
void rptc_killDriverEffects_copy(Kart *kart);
BOOL rptc_2083A24(KartEffectIdSet *effectIdSet, s32 velocityFactorIndex, Kart *kart);
s32 rptc_DriveOnGrassSnowWater(KartEffectIdSet *effectIdSet, s32 velocityFactorIndex, Kart *kart);
s32 rptc_DriveOnMud(KartEffectIdSet *effectIdSet, s32 unusedVelocityFactorIndex, Kart *kart);
BOOL rptc_DriveOnSand(KartEffectIdSet *effectIdSet, s32 velocityFactorIndex, Kart *kart);
void rptc_2083DE8(s32 rowIndex, Kart *kart);
void rptc_2083EC4(Kart *kart);
void rptc_collisionParticleRender(s32 functionIndex, Kart *kart);
void rptc_startBoostEffect(u32 effectIdIndex, Kart *kart);
void rptc_startRoadFlowerEffect(Kart *kart);
void rptc_startRoadSnowEffect(Kart *kart);
void rptc_startRoadGBASkyGardenEffect(Kart *kart);
void rptc_startRoadMudEffect(Kart *kart);
void rptc_startRoadWaterEffect(Kart *kart);
void func_02084334(Kart *kart);
void rptc_2084384(Kart *kart);
void func_020843d8(Kart *kart);
void rptc_killDriverEffects(Kart *kart);
// Copies the position source of the Kart into the position of its matrix (Kart.mUnk_174), then computes mSidePositions
// and mSideDirections of the Kart from the model points 2 and 3 and the Kart matrix.
void rptc_updateDriverEffects(Kart *kart);
// Allocates the KartEffects records for a Karts and clears them.
void rptc_initForDrivers(u32 kartCount);
// Returns the KartEffects record of Kart number n.
KartEffects *rptc_getEffectControllerForDriver(int kartIndex);
