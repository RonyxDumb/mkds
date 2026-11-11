#pragma once

#include "types.h"
#include "Main/Unknown/code_0208b484.h"

void AdvanceKartSpinSideEffect(ParticleEmitter *effect, s32 phase);
void AdvanceKartSpinFollowEffect(ParticleEmitter *effect, s32 phase);
void StartKartSpinFollowEffect(u32 kartIndex);
void StartKartSpinSideEffects(s32 kartIndex);
