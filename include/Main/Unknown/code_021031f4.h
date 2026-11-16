#pragma once

#include "types.h"
#include "Main/Item/ItemGesso.h"

// The register words and texture sizes cspl_renderSplash uses, filled from one model.
typedef struct {
    /* 00 */ void *mModel;
    /* 04 */ u32 mPolygonAttr;
    /* 08 */ u32 mTeximageParam;
    /* 0c */ u32 mPlttBase;
    /* 10 */ u32 mDifAmb;
    /* 14 */ u32 mSpeEmi;
    // Texture size values computed from mTeximageParam; they go into the texture coordinates of the quads.
    /* 18 */ u32 mUnk_18;
    /* 1c */ u32 mUnk_1c;
} OrthoQuadModel;

#include "Main/Unknown/code_021035ac.h"

// The cream record; cspl_sUseCustomSplash picks which of the two records is drawn.
extern OrthoQuadModel cspl_sCustomSplashTex;
// GesoSumi: the screen overlay the Gesso item starts for a hit kart.
extern OrthoQuadModel cspl_sGessoSplashTex;

void itgsso_21031F4(ItemGesso *gesso);
void cspl_initSplashTex(OrthoQuadModel *quadModel, NsbmdModel *model);
void cspl_init(void);
void cspl_emitCustomSplash(u32 kartIndex, u32 count);
void cspl_loadCustomSplashModel(const char *fileName);
void cspl_killSplashes(int idx);
void cspl_emitGessoSplash(u32 kartIndex, u32 count);
void cspl_emitSplashes(s32 idx, s32 count, s32 flag);
void cspl_emitSplash(s32 idx, HalfwordPair startPair, s32 overlap);
u8 MarkOrthoQuadCellsAndGetOverlap(s32 column, s32 row);
void cspl_render(void);
void cspl_renderSplash(OrthoQuadModel *model);
void cspl_update(void);
void cspl_initialWaitUpdate(OrthoQuad *quad);
void cspl_appearUpdate(OrthoQuad *quad);
void cspl_dripUpdate(OrthoQuad *quad);
void InitBouncingItemBoxTimers(void);
void InitBouncingItemBoxMapObjects(void);
