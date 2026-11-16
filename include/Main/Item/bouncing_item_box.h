#pragma once

#include "types.h"
#include "Main/Item/item_gesso.h"

// Limit of an OrthoQuad corner coordinate in either direction; the corners are clamped to it.
#define ORTHO_QUAD_COORD_LIMIT 0x3ccd
// OrthoQuad.mTimer & this is 0 once every 16 frames, when the quad picks a new corner.
#define ORTHO_QUAD_CORNER_PICK_MASK 0xf

// The register words and texture sizes DrawOrthoQuadsWithModel uses, filled from one model.
typedef struct {
    /* 00 */ void *mModel;
    /* 04 */ u32 mPolygonAttr;
    /* 08 */ u32 mTeximageParam;
    /* 0c */ u32 mPlttBase;
    /* 10 */ u32 mDifAmb;
    /* 14 */ u32 mSpeEmi;
    // Texture size values computed from mTeximageParam; they go into the texture coordinates of the quads.
    /* 18 */ u32 mTexSizeT;
    /* 1c */ u32 mTexSizeS;
} OrthoQuadModel;

#include "Main/Graphics/ortho_quad_corners.h"
#include "matrix44_concat.h"

// The cream record; gOrthoQuadUseCreamEffect picks which of the two records is drawn.
// GesoSumi: the screen overlay the Gesso item starts for a hit kart.

void SetupItemGessoKarts(ItemGesso *gesso);
void SetupOrthoQuadModel(OrthoQuadModel *quadModel, NsbmdModel *model);
void InitOrthoQuads(void);
void StartOrthoQuadsCreamEffect(u32 kartIndex, u32 count);
void CreateOrthoQuadCreamEffect(const char *fileName);
void StopOrthoQuads(int idx);
void StartOrthoQuadsGesoSumi(u32 kartIndex, u32 count);
void StartOrthoQuads(s32 idx, s32 count, s32 flag);
void SetupOrthoQuad(s32 idx, HalfwordPair startPair, s32 overlap);
u8 MarkOrthoQuadCellsAndGetOverlap(s32 column, s32 row);
void DrawOrthoQuads(void);
void DrawOrthoQuadsWithModel(OrthoQuadModel *model);
void UpdateOrthoQuads(void);
void AdvanceOrthoQuadDelayAndStartSound(OrthoQuad *quad);
void AdvanceOrthoQuadCornersByTable(OrthoQuad *quad);
void AdvanceOrthoQuadCornersByVelocity(OrthoQuad *quad);
void InitBouncingItemBoxTimers(void);
void InitBouncingItemBoxMapObjects(void);

OrthoQuadModel *ClearOrthoQuadCreamEffectPointer(void);

u32 SkipOrthoQuadsHold(u32 kartIndex);

extern const s32 gOrthoQuadTimersByIndex[4];
extern const s32 gOrthoQuadTableScales[13];
extern char g_str_geso_sumi_nsbmd[16];
extern char g_str_geso_sumi_nsbmd_0[16];

extern s32 gOrthoQuadCount;
extern u8 gOrthoQuadCells[8];
extern OrthoQuadModel gOrthoQuadCreamEffect;
extern OrthoQuadModel gOrthoQuadGesoSumi;
extern MtxFx44 g_AnotherMatrix4x4;
