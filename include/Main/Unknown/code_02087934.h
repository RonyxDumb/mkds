#pragma once

#include "types.h"

typedef struct Unk02087b78 Unk02087b78;

void DrawKartNameTagColorQuad(u32 color);
void ColoredDrawKartNameTagQuadVertices(s32 texWidthFixed, s32 texHeightFixed);
void DrawKartNameTagQuadVertices(s32 texWidthFixed, s32 texHeightFixed);
void AdvanceModelAnimationFrame(Unk02087b78 *modelAnimation);
void ApplyModelAnimationLoopMode(Unk02087b78 *modelAnimation);
void ResetModelAnimationWithLoopFlag(Unk02087b78 *modelAnimation, s32 frameCountFixed, u16 loopFlag);
