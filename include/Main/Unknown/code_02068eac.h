#pragma once

#include "types.h"

typedef struct Kart Kart;

BOOL IsKartRemoved(Kart *kart);
BOOL StartKartRemoval(Kart *kart, s32 fromRaceProgress);
void StartKartRemovalFromProgress(Kart *kart);
void StartKartAheadBoost(Kart *kart);
void AdvanceKartGesso(Kart *kart);
void StartKartGesso(Kart *kart, u32 orthoQuadCount);
void AdvanceKartKiller(Kart *kart);
void StartKartKiller(Kart *kart);
void AdvanceKartTeresa(Kart *kart);
void StartKartTeresa(Kart *kart);
void StartKartStar(Kart *kart);
void StartKartKinokoBoost(Kart *kart);
void StartKartThunder(Kart *kart);
void ResetKartScaleEffects(Kart *kart);
void AdvanceKartScaleTableEffect(Kart *kart);
BOOL TryStartKartScaleTableEffect(Kart *kart);
