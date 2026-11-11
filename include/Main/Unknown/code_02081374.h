#pragma once

#include "types.h"
#include "Main/Unknown/code_0208b484.h"

void AdvanceKartContactEffect(ParticleEmitter *effect, s32 flag);
void StartAndPlaceKartContactEffect(s32 kartIndex, Vec3 *direction);
void SetKartKillerEffectShown(s32 kartIndex, s32 shown);
