#pragma once

#include "types.h"

typedef struct Kart Kart;

// The kind passed to driver_addBoost.
typedef enum {
    // The mushroom and the boost surfaces.
    KART_BOOST_ITEM_OR_SURFACE,
    // The release of a fully charged drift.
    KART_BOOST_MINI_TURBO,
    // At the end of the race start sequence.
    KART_BOOST_RACE_START,
    // On landing after a respawn.
    KART_BOOST_RESPAWN
} KartBoostKind;

void driver_addBoost(Kart *kart, KartBoostKind boostKind, int boostFrames);
void func_0206d138(Kart *kart);
void driver_handleItems(Kart *kart);
void driver_handleSlipstream(Kart *kart);
void OtherKartCollide(Kart *pushingKart, Kart *pushedKart, const Vec3 *v, s32 c, Vec3 *out);
BOOL TryStartKartPushDoubleFlip(Kart *killerKart, Kart *hitKart);
BOOL TryStartKartPushFlip(Kart *starKart, Kart *hitKart, const Vec3 *v);
