#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h" // Kart
#include "Main/Unknown/code_020a3f2c.h"

u32 CollideKartWithShine16(Shine16 *shine16, Kart *kart, u8 *a, u8 *b);
void CreateShine16(void *a);
void SetupDrawShine16(void *a);
void DrawShine16(void *a, Shine16 *shine16);
