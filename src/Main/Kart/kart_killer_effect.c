#include "Main/Kart/kart_killer_effect.h"
#include "Main/Graphics/effects.h"
#include "Main/MapObjects/data_0217a000.h"

// Lets the Killer effect end by itself and forgets it.
void StopKartKillerEffect(u32 kartIndex) {
    KartEffects *kartEffects = &gKartEffects[kartIndex];
    ParticleEmitter *effect = kartEffects->mKillerEffect;
    if (effect == NULL) {
        return;
    }
    effect->mFlags.mEnding = 1;
    kartEffects->mKillerEffect = NULL;
}

void ReleaseKartKillerEffect(u32 kartIndex) {
    KartEffects *kartEffects = &gKartEffects[kartIndex];
    ParticleEmitter *effect = kartEffects->mKillerEffect;
    if (effect == NULL) {
        return;
    }
    DeleteEffect(effect);
    kartEffects->mKillerEffect = NULL;
}
