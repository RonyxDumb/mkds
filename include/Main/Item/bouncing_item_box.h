#pragma once

#include "types.h"
#include "Main/Item/item_gesso.h"

// Limit of an OrthoQuad corner coordinate: the corners are clamped to plus and minus it by
// AdvanceOrthoQuadCornersByVelocity (the mVelocityMode 0 branch clamps only the negative Y side).
#define ORTHO_QUAD_COORD_LIMIT 0x3ccd
// AdvanceOrthoQuadCornersByVelocity decrements OrthoQuad.mTimer; when mTimer & this is 0 (every 16th call past the move
// start) the quad picks a new mPickedCornerIndex.
#define ORTHO_QUAD_CORNER_PICK_MASK 0xf

// The register words and texture sizes DrawOrthoQuadsWithModel uses; SetupOrthoQuadModel fills them from one model,
// except mPolygonAttr, a fixed value.
typedef struct {
    /* 00 */ void *mModel;
    /* 04 */ u32 mPolygonAttr;
    /* 08 */ u32 mTeximageParam;
    /* 0c */ u32 mPlttBase;
    /* 10 */ u32 mDifAmb;
    /* 14 */ u32 mSpeEmi;
    // Texture size values computed from mTeximageParam; they go into the texture coordinates of the quads.
    /* 18 */ u32 mTexCoordLowSize;
    /* 1c */ u32 mTexCoordHighSize;
} OrthoQuadModel;

#include "Main/Graphics/ortho_quad_corners.h"
#include "matrix44_concat.h"

// gOrthoQuadUseCreamEffect picks which of gOrthoQuadCreamEffect and gOrthoQuadGesoSumi is drawn. GesoSumi: the quads
// the Gesso item starts, only for the local entry. (put it above the two externs,
// include/Main/Item/bouncing_item_box.h:60)

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
extern char gGesoSumiModelNsbmdName[16];
extern char gGesoSumiTextureNsbmdName[16];

extern s32 gOrthoQuadCount;
extern u8 gOrthoQuadCells[8];
extern OrthoQuadModel gOrthoQuadCreamEffect;
extern OrthoQuadModel gOrthoQuadGesoSumi;
extern MtxFx44 gOrthoQuadMatrix;
