#pragma once

#include "types.h"
#include "Main/Kart/kart_drift.h" // Kart

BOOL DrawKartKillerItem(Kart *kart);
void DrawKart(Kart *kart);
// Slot 2 of the other Karts: stores the squared distance in the sound source and passes it to
// mSoundDistanceSquaredChange, which keeps its change since the previous call.
void SetKartSoundDistanceSquaredAndChange(Kart *kart);
