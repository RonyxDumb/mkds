#pragma once

#include "types.h"
#include "Main/Graphics/nsbmd_render_obj.h" // Nsbmd
#include "Main/Graphics/model_animation.h" // ModelAnimation
#include "Main/Kart/kart_palette_stem_tables.h" // StemSetParams

// A set of models (mNsbmds, mNsbmdCount) with the animations that go with them.
typedef struct StemSet {
    /* 00 */ Nsbmd *mNsbmds;
    /* 04 */ ModelAnimation *mNsbcaNsbmaNsbtp[3];
    /* 10 */ u16 mNsbmdCount;
} StemSet;

void DrawStemSets(void);
void UpdateStemSets(void);
void StartStemSet(s32 setIndex);
void LoadSeveralBMModels(void *heap);
void LoadModelBMFromMD(void *heap, StemSet *stemSet, const StemSetParams *stemSetParams, u16 setIndex);
void CreateGlobalBO(void *heap);
