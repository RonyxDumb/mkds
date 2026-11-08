#include "Main/Unknown/code_020815a0.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/unk_0217a000.h"

// Lets the Killer effect end by itself and forgets it.
void StopKartKillerEffect(u32 kartIndex) {
    KartEffects *kartEffects = &gKartEffects[kartIndex];
    Unk0201ca6c *effect = kartEffects->mKillerEffect;
    if (effect == NULL) {
        return;
    }
    effect->mUnk_24.mUnk_00_0 = 1;
    kartEffects->mKillerEffect = NULL;
}

void ReleaseKartKillerEffect(u32 kartIndex) {
    KartEffects *kartEffects = &gKartEffects[kartIndex];
    Unk0201ca6c *effect = kartEffects->mKillerEffect;
    if (effect == NULL) {
        return;
    }
    DeleteEffect(effect);
    kartEffects->mKillerEffect = NULL;
}
