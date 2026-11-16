#pragma once

#include "types.h"
#include "model_material_set.h" // MtxFx43, NNSG3dResShpData
#include "Main/Graphics/nsbmd_render_obj.h" // Nsbmd
#include "Main/Kart/shadow_model.h" // ShadowModel




// Destination of RefreshShadowMatrix.
typedef struct ShadowMatrix {
    /* 000 */ MtxFx43 mMatrix;
    /* 030 */ u16 mAlphaCap;
} ShadowMatrix;

void DrawJgShadow(u32 alphaCap, u32 maxAlpha);
void DrawJgShadowWithMatrix(Vec3 *scale, MtxFx43 *matrix, u16 alphaCap, u32 maxAlpha);
void DrawObjShadow(ShadowMatrix *shadow, void *wordPointer, u32 unused, u32 alpha);
void DrawObjShadowAfterMaterial(ShadowMatrix *shadow, void *wordPointer, u32 unused, u32 alpha);
s32 RefreshShadowMatrix(ShadowMatrix *shadowCopy, Vec3 *position, s32 scale, u32 alphaCap);
void CreateObjShadowAndJgShadow(void);

void SendObjShadowMaterial(void);

extern NNSG3dResShpData *gObjShadowShape;
extern Nsbmd *gObjShadow;
extern ShadowModel *gJgShadow;
extern struct NNSG3dResMatData *gObjShadowMaterial;
