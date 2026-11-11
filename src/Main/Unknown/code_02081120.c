#include "Main/Unknown/code_02081120.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_02083000.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_02077bc0.h"

void StartKartSpinSideEffects(s32 kartIndex) {
    Kart *kart = GetKart(kartIndex);
    ParticleEmitter *effect;
    u16 effectIndex;

    if (!(kart->mUnk_4c & KART_4C_NEAR_PLAYER_RANK)) {
        return;
    }
    effectIndex = 0;
    do {
        effect = StartEffect(0x58, &gKartEffectVec3Zero);
        effect->mUnk_94 = kart;
        effect->mUnk_98_24 = effectIndex;
        effectIndex = effectIndex + 1;
        effect->mCallback = AdvanceKartSpinSideEffect;
    } while (effectIndex < 2);
}

void AdvanceKartSpinSideEffect(ParticleEmitter *effect, s32 phase) {
    if (phase != 0) {
        return;
    }
    AdvanceKartSideEffect(effect, phase);
    if (effect->mUnk_98_0 >= 7) {
        effect->mUnk_98_8 = 1;
    } else {
        effect->mUnk_98_0 = effect->mUnk_98_0 + 1;
    }
}

void StartKartSpinFollowEffect(u32 kartIndex) {
    KartEffects *kartEffects = &gKartEffects[kartIndex];
    ParticleEmitter *effect;

    if (kartEffects->mSpinFollowEffect != NULL) {
        DeleteEffect(kartEffects->mSpinFollowEffect);
    }
    kartEffects->mSpinFollowEffect = StartEffect(0x5e, &gKartEffectVec3Zero);
    effect = kartEffects->mSpinFollowEffect;
    effect->mUnk_98_16 = 0;
    effect->mUnk_98_8 = 0x78;
    effect->mUnk_98_24 = kartIndex;
    effect->mCallback = AdvanceKartSpinFollowEffect;
}

void AdvanceKartSpinFollowEffect(ParticleEmitter *effect, s32 phase) {
    u32 ended;
    u8 elapsedFrames;
    u8 kartIndex;
    Vec3 *kartPosition;
    s32 kartX;
    s32 kartY;
    s32 kartZ;

    if (phase != 0) {
        return;
    }
    kartIndex = effect->mUnk_98_24;
    elapsedFrames = effect->mUnk_98_16;
    ended = 0;
    kartPosition = GetKart(kartIndex)->mPosSource;
    kartX = kartPosition->x;
    kartY = kartPosition->y;
    kartZ = kartPosition->z;
    effect->mUnk_28.x = (kartX >> 4) + effect->mUnk_20->mUnk_00->mUnk_04.x;
    effect->mUnk_28.y = (kartY >> 4) + effect->mUnk_20->mUnk_00->mUnk_04.y;
    effect->mUnk_28.z = (kartZ >> 4) + effect->mUnk_20->mUnk_00->mUnk_04.z;
    if (elapsedFrames >= effect->mUnk_98_8) {
        if (elapsedFrames == effect->mUnk_98_8) {
            ended = 1;
            effect->mUnk_24.mEnding = 1;
        }
    } else {
        effect->mUnk_98_16 = elapsedFrames + 1;
    }
    if (ended != 0) {
        gKartEffects[kartIndex].mSpinFollowEffect = NULL;
        return;
    }
    effect->mSizeScale = (s16) GetKart(kartIndex)->mScale.z;
}
