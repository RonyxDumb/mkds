#pragma once

#include "types.h"
#include "code_02012b30.h" // MtxFx43
#include "code_021479b4.h" // MtxFx44

void G3X_SetFogTable(const void *fogTable);
s32 G3X_GetVectorMtx(void *m);
s32 G3X_GetClipMtx(void *m);
void G3X_SetFog(s32 enable, u32 fogMode, u32 fogSlope, u32 fogOffset);
void G3X_ResetMtxStack(void);
void G3X_InitMtxStack(void);
void G3X_ClearFifo(void);
void G3X_Reset(void);
void G3X_Init(void);
void G3i_LookAt_(const Vec3 *camPos, const Vec3 *camUp, const Vec3 *target, int draw, MtxFx43 *mtx);
void G3i_OrthoW_(s32 top, s32 bottom, s32 left, s32 right, s32 nearPlane, s32 farPlane, s32 scaleW, int draw,
                 MtxFx44 *mtx);
void G3i_FrustumW_(s32 top, s32 bottom, s32 left, s32 right, s32 nearPlane, s32 farPlane, s32 scaleW, int draw,
                   MtxFx44 *mtx);
