#pragma once

#include "types.h"
#include "Main/Graphics/effects.h"

void ReleaseKartContactEffect(u32 kartIndex);

void AdvanceKartContactEffect(ParticleEmitter *effect, s32 flag);
void StartAndPlaceKartContactEffect(s32 kartIndex, Vec3 *direction);
void SetKartKillerEffectShown(s32 kartIndex, s32 shown);

// Kart.mVelocityLength above the first starts the contact effect (with KART_EFFECT_NEAR_PLAYER_RANK, when none runs);
// at least the second keeps it running while KART_DRIVE_CONTACT_EFFECT and KART_MOTION_COURSE_CONTACT are set.
#define KART_CONTACT_EFFECT_START_MIN_SPEED 0x1000
#define KART_CONTACT_EFFECT_KEEP_MIN_SPEED 0x1333
