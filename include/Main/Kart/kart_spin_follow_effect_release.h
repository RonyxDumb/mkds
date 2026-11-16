#pragma once

#include "types.h"
#include "Main/Graphics/effects.h"

void ReleaseKartSpinFollowEffect(u32 kartIndex);

void AdvanceKartSpinSideEffect(ParticleEmitter *effect, s32 phase);
void AdvanceKartSpinFollowEffect(ParticleEmitter *effect, s32 phase);
void StartKartSpinFollowEffect(u32 kartIndex);
void StartKartSpinSideEffects(s32 kartIndex);

// Steps the spin follow effect runs (mStepLimit), and the steps the spin side effect waits before it starts counting.
#define KART_SPIN_FOLLOW_EFFECT_STEPS 0x78
#define KART_SPIN_SIDE_EFFECT_RAMP_STEPS 7
