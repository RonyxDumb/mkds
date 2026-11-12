#pragma once

#include "types.h"
#include "Main/Kart/kart_drift.h" // Kart

typedef struct NNSG3dRS NNSG3dRS;

extern const u32 data_02154a2c[];

void PlaceKartKillerEffectCallback(NNSG3dRS *renderState);
void KartAiCallKartSlot6AndToggleFlag(Kart *kart);
void CallKartSlot6AndToggleFlag(Kart *kart);
