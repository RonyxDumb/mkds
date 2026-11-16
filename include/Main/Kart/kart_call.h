#pragma once

#include "types.h"
#include "Main/Kart/kart_drift.h" // Kart

typedef struct NNSG3dRS NNSG3dRS;


void StructMLFnPtr(NNSG3dRS *renderState);
void KartAiRespawnKartAndToggleEventFlag(Kart *kart);
void RespawnKartAndToggleEventFlag(Kart *kart);

extern const Vec3 gCourseModelDrawScale;
extern const u32 g_str_KillerItem[4];
