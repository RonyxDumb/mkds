#pragma once

#include "types.h"
#include "Main/Kart/kart_drift.h" // Kart

typedef struct NNSG3dRS NNSG3dRS;


void PlaceKartKillerEffectCallback(NNSG3dRS *renderState);
void KartAiCallKartSlot6AndToggleFlag(Kart *kart);
void CallKartSlot6AndToggleFlag(Kart *kart);

extern const u32 gCourseModelDrawScale[3];
extern const u32 gKillerItemNodeName[4];
