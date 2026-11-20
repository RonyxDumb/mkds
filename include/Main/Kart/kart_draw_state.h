#pragma once

#include "types.h"
#include "Main/Kart/kart_drift.h" // Kart

void AdvanceKartCollisionSlot(Kart *kart);
void AdvanceKartDrawState(Kart *kart);

// KART_BLINK_CYCLE_FRAMES: mBlinkCycleFrames returns to 0 once it exceeds it (a cycle of 9 steps).
// KART_BLINK_HIDDEN_FROM_FRAME: the kart is hidden while mBlinkCycleFrames is at least it. KART_BLINK_GUARD_FRAMES:
// the guard ends when mBlinkFrames exceeds it.
#define KART_BLINK_CYCLE_FRAMES 8
#define KART_BLINK_HIDDEN_FROM_FRAME 4
#define KART_BLINK_GUARD_FRAMES 0x5a
