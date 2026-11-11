#pragma once

#include "types.h"

typedef struct Kart Kart;

// The kind passed to StartKartBoost.
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

void StartKartBoost(Kart *kart, KartBoostKind boostKind, int boostFrames);
void StartKartSoundAndCharacterAnimation(Kart *kart);
void ApplyItemObjectHitToKart(Kart *kart);
void UpdateKartAheadEffect(Kart *kart);
void ApplyKartPush(Kart *pushingKart, Kart *pushedKart, const Vec3 *contactDirection, s32 storeDirection, Vec3 *out);
BOOL TryStartKartPushDoubleFlip(Kart *killerKart, Kart *hitKart);
BOOL TryStartKartPushFlip(Kart *starKart, Kart *hitKart, const Vec3 *pushDirection);
