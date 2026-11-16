#pragma once

#include "types.h"
#include "Main/Kart/kart_drift.h" // Kart

void AdvanceKartCollisionSlot(Kart *kart);
void AdvanceKartDrawState(Kart *kart);

// The blink guard cycles every this many frames, hides the kart from the second frame on, and ends after the third.
#define KART_BLINK_CYCLE_FRAMES 8
#define KART_BLINK_HIDDEN_FROM_FRAME 4
#define KART_BLINK_GUARD_FRAMES 0x5a
