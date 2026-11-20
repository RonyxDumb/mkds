#pragma once

#include "types.h"
#include "model_material_set.h" // MtxFx43, NNSG3dResFileHeader
#include "Main/Graphics/nsbmd_render_obj.h"
#include "Main/Graphics/model_animation.h"
#include "sound_archive_load.h"
#include "Main/Kart/kart_ai_item_throw.h"
#include "Main/Graphics/model_effect_kinds.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "Main/Kart/kart_name_tags.h"
#include "Main/Sound/sound_distance_squared_change.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"

// UpdateModelEffectBombcore starts one more effect on the first frame and finishes on the second;
// UpdateModelEffectBombcore2 finishes on the second too.
#define MODEL_EFFECT_BOMBCORE_PARTICLE_FRAME 0x26
#define MODEL_EFFECT_BOMBCORE_END_FRAME 0x37
#define MODEL_EFFECT_BOMBCORE2_END_FRAME 0x37
// ModelEffect.mFinishFrameCount of the Donketu water splash and the Bk wave.
#define MODEL_EFFECT_DONKETU_SPLASH_FINISH_FRAMES 0x20
#define MODEL_EFFECT_BK_WAVE_FINISH_FRAMES 0x27

// A pooled effect object: a model, up to three animations, a position and a Start and an Update function.
typedef struct ModelEffect {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ Nsbmd mNsbmd;
    /* 74 */ Vec3 mPos;
    // Called at each start with the object and a flag; most kinds start particle effects only when it is non-zero.
    /* 80 */ void (*mStart)(struct ModelEffect *, s32);
    /* 84 */ void (*mUpdate)(struct ModelEffect *);
    /* 88 */ s32 mFinished;
    /* 8c */ u32 mKind;
    // [0] .nsbca, [1] .nsbma, [2] .nsbta animation; NULL when the kind row's mUseNsbca, mUseNsbma or mUseNsbta is 0.
    /* 90 */ ModelAnimation *mAnimations[3];
    // Scale on x, y and z (three equal values, 0x1000 = 1.0), passed to the draw call.
    /* 9c */ Vec3 mScale;
    /* a8 */ u32 mSinceStartFrames;
    // Frame count at which mFinished is set; 0 for the kinds whose update uses a fixed frame number.
    /* ac */ u32 mFinishFrameCount;
    /* b0 */ u16 mPolygonId;
    /* b4 */ s32 mVisible;
} ModelEffect;

void StartKartWaterSplashEffects(const Vec3 *position, s32 startModel);
void UpdateModelEffectBombcore2(ModelEffect *modelEffect);
void StartModelEffectBombcore2(ModelEffect *modelEffect, s32 startEffects);
void UpdateModelEffectBkWave(ModelEffect *modelEffect);
void StartModelEffectBkWave(ModelEffect *modelEffect, s32 startEffects);
void UpdateWaterEfctKinds(ModelEffect *modelEffect);
void StartModelEffectDonketuWaterSplash(ModelEffect *modelEffect);
void StartKartWaterSplashModel(ModelEffect *modelEffect);
void UpdateModelEffectBombcore(ModelEffect *modelEffect);
void StartModelEffectBombcore(ModelEffect *modelEffect, s32 startEffects);
void SetupModelEffectKind(void *heap, s32 kind, NNSG3dResFileHeader *modelFile, void *nsbcaFile, void *nsbmaFile,
                          void *nsbtaFile);
void InitModelEffectObjects(void *heap);
void SetupBkWaveKind(void);
void SetupWaterEfctKindRow(ModelEffectKind *kindRow, s32 objectCount);
void DrawModelEffects(void);
void UpdateModelEffects(void);
ModelEffect *StartModelEffect(u32 kind, const Vec3 *position, s32 startEffects);
void InitModelEffects(void *heap);
void SetAwardPosStripDrawEnabled(s32 drawEnabled);
void DrawPosStripQuad(const MtxFx43 *viewMatrix, PosStripPoint *firstPoint, PosStripPoint *secondPoint,
                      PosStripTexture *posStripTexture);
void UpdatePosStrip(PosStrip *posStrip);

extern s32 gKartWaterSplashCreated;
extern s32 gKartWaterSplashEffectIds[2];
extern struct ModelEffects *gModelEffects;

extern ModelEffectKind gModelEffectKinds[MODEL_EFFECT_KIND_COUNT];

extern char gRaceEffectSpaName[15];
extern char gRaceEffectFogOffSpaName[29];
extern char gMissionEffectSpaName[35];
