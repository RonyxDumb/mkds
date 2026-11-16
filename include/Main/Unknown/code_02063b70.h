#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h" // Kart

BOOL driver_renderKillerItem(Kart *kart);
void driver_render(Kart *kart);
// Slot 2 of the other Karts: stores the squared distance in the sound source and passes it to field518, which keeps its
// change since the previous call.
void SetKartSoundDistanceSquaredAndChange(Kart *kart);
