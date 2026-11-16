#pragma once

#include "types.h"
#include "code_02012b30.h" // MtxFx43, NNSG3dResFileHeader
#include "Main/Unknown/code_020846c0.h"
#include "Main/Unknown/code_02087d0c.h"
#include "Main/Unknown/code_02017000.h"
#include "Main/Unknown/code_0208eb10.h"
#include "Main/Unknown/unk_02166000.h"
#include "Main/Unknown/unk_0217b000.h"

// A pooled effect object: a model, up to three animation objects, a position and a Start and an Update function.
typedef struct ModelEffect {
    /* 00 */ u8 field0[8];
    /* 08 */ Nsbmd mNsbmd;
    /* 74 */ Vec3 mPos;
    // Called at each start with the object and a flag; most kinds start particle effects only when it is non-zero.
    /* 80 */ void (*mStart)(struct ModelEffect *, s32);
    /* 84 */ void (*mUpdate)(struct ModelEffect *);
    /* 88 */ s32 mFinished;
    /* 8c */ u32 mKind;
    // [0] .nsbca, [1] .nsbma, [2] .nsbta animation object; NULL when the kind has no such file.
    /* 90 */ ModelAnimation *mAnimations[3];
    // Scale on x, y and z (three equal values, 0x1000 = 1.0), passed to the draw call.
    /* 9c */ s32 mScale[3];
    /* a8 */ u32 mSinceStartFrames;
    // Frame count at which mFinished is set; 0 for the kinds whose update uses a fixed frame number.
    /* ac */ u32 mFinishFrameCount;
    /* b0 */ u16 mPolygonId;
    /* b4 */ s32 mVisible;
} ModelEffect;

void expl_spawnSplash(const Vec3 *position, s32 startModel);
void expl_updateBombcore2Instance(ModelEffect *modelEffect);
void expl_initBombcore2Instance(ModelEffect *modelEffect, s32 startEffects);
void expl_updateBkWaveInstance(ModelEffect *modelEffect);
void expl_initBkWaveInstance(ModelEffect *modelEffect, s32 startEffects);
void expl_updateSplashInstance(ModelEffect *modelEffect);
void expl_initMissionSplashInstance(ModelEffect *modelEffect);
void expl_initSplashInstance(ModelEffect *modelEffect);
void expl_updateBombcoreInstance(ModelEffect *modelEffect);
void expl_initBombcoreInstance(ModelEffect *modelEffect, s32 startEffects);
void expl_setModel(void *heap, s32 kind, NNSG3dResFileHeader *modelFile, void *nsbcaFile, void *nsbmaFile,
                          void *nsbtaFile);
void expl_initEffects(void *heap);
void expl_initBkWave(void);
void expl_initWaterEffect(ModelEffectKind *kindRow, s32 objectCount);
void expl_render(void);
void expl_update(void);
ModelEffect *expl_spawnEffect(u32 kind, const Vec3 *position, s32 startEffects);
void expl_init(void *heap);
void trl_setVisibleForAward(s32 drawEnabled);
void trl_renderSegment(const MtxFx43 *viewMatrix, PosStripPoint *firstPoint, PosStripPoint *secondPoint,
                      PosStripTexture *posStripTexture);
void trl_updateTrail(PosStrip *posStrip);
