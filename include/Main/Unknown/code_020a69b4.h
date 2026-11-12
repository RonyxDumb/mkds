#pragma once

#include "types.h"
#include "Main/Kart/kart_drift.h" // Kart
#include "Main/MapObjects/shine16.h"

u32 CollideKartWithShine16(Shine16 *shine16, Kart *kart, u8 *firstResponse, u8 *response);
void CreateShine16(void *mapObjectList);
void SetupDrawShine16(void *mapObjectList);
void DrawShine16(void *mapObjectList, Shine16 *shine16);
