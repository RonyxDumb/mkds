#pragma once

#include "types.h"
#include "Main/Graphics/effects.h"

void ReleaseKartContactEffect(u32 kartIndex);

void AdvanceKartContactEffect(ParticleEmitter *effect, s32 flag);
void StartAndPlaceKartContactEffect(s32 kartIndex, Vec3 *direction);
void SetKartKillerEffectShown(s32 kartIndex, s32 shown);

// Kart.mVelocityLength the kart needs for the contact effect to start, and to be kept running while in contact.
#define KART_CONTACT_EFFECT_START_MIN_SPEED 0x1000
#define KART_CONTACT_EFFECT_KEEP_MIN_SPEED 0x1333
