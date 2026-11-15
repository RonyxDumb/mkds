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

// A peer kart clears its position offset above this Kart.mForwardSpeed, and tilts toward the air after this many
// airborne frames.
#define KART_PEER_OFFSET_CLEAR_SPEED 0x3000
#define KART_PEER_AIR_TILT_AIRBORNE_FRAMES 5
// Kart.mHopTiltAngle of a hop: the start value, the limit above which it drops to the reset value.
#define KART_HOP_TILT_START 0x9c4
#define KART_HOP_TILT_LIMIT 0x6a4
#define KART_HOP_TILT_RESET 0x352
