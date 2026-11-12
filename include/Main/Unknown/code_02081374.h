#pragma once

#include "types.h"
#include "Main/Graphics/effects.h"

void AdvanceKartContactEffect(ParticleEmitter *effect, s32 flag);
void StartAndPlaceKartContactEffect(s32 kartIndex, Vec3 *direction);
void SetKartKillerEffectShown(s32 kartIndex, s32 shown);
