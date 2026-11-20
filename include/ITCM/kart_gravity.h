#pragma once

#include "types.h"

typedef struct Kart Kart;

// Takes up to 0x1ec / 0x1000 of *speed off in proportion to the size of mTurnRatio; only for a Kart in
// KART_STATE_NORMAL on the ground, outside a drift, with *speed above 0x3000.
void ReduceKartSpeedByTurnRatio(s32 *speed, Kart *kart);
// Adds mGravity to mVerticalSpeed.
void ApplyKartGravity(Kart *kart);
void ScaleKartForwardSpeed(Kart *kart);
