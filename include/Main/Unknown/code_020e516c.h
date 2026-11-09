#pragma once

#include "types.h"
#include "code_02012b30.h" // MtxFx43, NNSG3dResShpData
#include "Main/Unknown/code_020846c0.h" // Nsbmd
#include "Main/Unknown/code_0207adf8.h" // ShadowModel

extern ShadowModel *gJgShadow;

extern Nsbmd *gObjShadow;

extern NNSG3dResShpData *gObjShadowShape;

// Destination of RefreshShadowMatrix.
typedef struct ShadowMatrix {
    /* 000 */ MtxFx43 mMatrix;
    /* 030 */ u16 mAlphaCap;
} ShadowMatrix;

void DrawJgShadow(u32 alphaCap, u32 maxAlpha);
void DrawJgShadowWithMatrix(Vec3 *scale, MtxFx43 *matrix, u32 alphaCap, u32 maxAlpha);
void DrawObjShadow(ShadowMatrix *shadow, void *wordPointer, u32 unused, u32 alpha);
void DrawObjShadowAfterMaterial(ShadowMatrix *shadow, void *wordPointer, u32 unused, u32 alpha);
s32 RefreshShadowMatrix(ShadowMatrix *shadowCopy, Vec3 *position, s32 scale, u32 alphaCap);
void CreateObjShadowAndJgShadow(void);
