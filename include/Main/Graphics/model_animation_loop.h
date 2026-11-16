#pragma once

#include "types.h"

typedef struct ModelAnimationFrameLoop ModelAnimationFrameLoop;

void DrawKartNameTagColorQuad(u32 color);
void ColoredDrawKartNameTagQuadVertices(s32 texWidthFixed, s32 texHeightFixed);
void DrawKartNameTagQuadVertices(s32 texWidthFixed, s32 texHeightFixed, u32 color);
void StructAM_SomeFn_7(ModelAnimationFrameLoop *modelAnimation);
void StructAM_SomeFn(ModelAnimationFrameLoop *modelAnimation);
void StructAM_SomeFn_0(ModelAnimationFrameLoop *modelAnimation, s32 frameCountFixed, u16 loopFlag);

extern const u16 gKartNameTagQuadVertices[12];
extern const u32 gKartNameTagColorQuadTexture[8];
extern const u32 gKartNameTagMaskedPalette[8];
extern const u32 gKartNameTagMaskedTexture[128];
