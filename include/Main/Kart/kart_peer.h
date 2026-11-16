#pragma once

#include "types.h"
#include "Main/Kart/kart_drift.h" // Kart

void InitKart(Kart *kart, void (**slotFunctions)(Kart *));
// Stores the previous collision center from mPrevPos. Slot 5 of Kart.mSlotFunctions for a Kart of player kind 3 in mode
// 5.
void SetKartPrevCollisionCenterFromPrevPos(Kart *kart);
void AdvancePeerKartOrientation(Kart *kart, Vec3 *groundNormal);
void AdvancePeerKartCollision(Kart *kart);
void AdvancePeerKartMotion(Kart *kart);

// A peer kart clears its position offset above this Kart.mForwardSpeed.
#define KART_PEER_OFFSET_CLEAR_SPEED 0x3000
