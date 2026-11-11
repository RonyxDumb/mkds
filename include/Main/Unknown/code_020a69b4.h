#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h" // Kart
#include "Main/Unknown/code_020a3f2c.h"

u32 CollideKartWithShine16(Shine16 *shine16, Kart *kart, u8 *firstResponse, u8 *response);
void CreateShine16(void *mapObjectList);
void SetupDrawShine16(void *mapObjectList);
void DrawShine16(void *mapObjectList, Shine16 *shine16);
