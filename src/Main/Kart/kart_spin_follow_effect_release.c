#include "Main/Kart/kart_spin_follow_effect_release.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Kart/kart_effects.h"
#include "Main/Kart/kart_palette_stem_tables.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/Kart/karts.h"
#include "Main/Graphics/effects.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Graphics/nsbmd_render_obj.h"

void StartKartSpinSideEffects(s32 kartIndex) {
    Kart *kart = GetKart(kartIndex);
    ParticleEmitter *effect;
    u16 effectIndex;

    if (!(kart->mEffectFlags & KART_EFFECT_NEAR_PLAYER_RANK)) {
        return;
    }
    effectIndex = 0;
    do {
        effect = StartEffect(0x58, &gKartEffectVec3Zero);
        effect->mCallbackData = kart;
        effect->mCallbackBytes.mSideIndex = effectIndex;
        effectIndex = effectIndex + 1;
        effect->mCallback = AdvanceKartSpinSideEffect;
    } while (effectIndex < 2);
}

void AdvanceKartSpinSideEffect(ParticleEmitter *effect, s32 phase) {
    if (phase != 0) {
        return;
    }
    AdvanceKartSideEffect(effect, phase);
    if (effect->mVelocityFactorIndex >= KART_SPIN_SIDE_EFFECT_RAMP_STEPS) {
        effect->mCallbackBytes.mCounting = 1;
    } else {
        effect->mVelocityFactorIndex = effect->mVelocityFactorIndex + 1;
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
    effect->mStepCount = 0;
    effect->mStepLimit = KART_SPIN_FOLLOW_EFFECT_STEPS;
    effect->mKartIndex = kartIndex;
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
    kartIndex = effect->mKartIndex;
    elapsedFrames = effect->mStepCount;
    ended = 0;
    kartPosition = GetKart(kartIndex)->mPosSource;
    kartX = kartPosition->x;
    kartY = kartPosition->y;
    kartZ = kartPosition->z;
    effect->mPosition.x = (kartX >> 4) + effect->mResource->mHeader->mPositionOffset.x;
    effect->mPosition.y = (kartY >> 4) + effect->mResource->mHeader->mPositionOffset.y;
    effect->mPosition.z = (kartZ >> 4) + effect->mResource->mHeader->mPositionOffset.z;
    if (elapsedFrames >= effect->mStepLimit) {
        if (elapsedFrames == effect->mStepLimit) {
            ended = 1;
            effect->mFlags.mEnding = 1;
        }
    } else {
        effect->mStepCount = elapsedFrames + 1;
    }
    if (ended != 0) {
        gKartEffects[kartIndex].mSpinFollowEffect = NULL;
        return;
    }
    effect->mSizeScale = (s16) GetKart(kartIndex)->mScale.z;
}

void ReleaseKartSpinFollowEffect(u32 kartIndex) {
    KartEffects *kartEffects = &gKartEffects[kartIndex];
    if (kartEffects->mSpinFollowEffect == NULL) {
        return;
    }
    DeleteEffect(kartEffects->mSpinFollowEffect);
    kartEffects->mSpinFollowEffect = NULL;
}
