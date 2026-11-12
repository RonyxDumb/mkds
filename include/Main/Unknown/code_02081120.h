#pragma once

#include "types.h"
#include "Main/Graphics/effects.h"

void AdvanceKartSpinSideEffect(ParticleEmitter *effect, s32 phase);
void AdvanceKartSpinFollowEffect(ParticleEmitter *effect, s32 phase);
void StartKartSpinFollowEffect(u32 kartIndex);
void StartKartSpinSideEffects(s32 kartIndex);
