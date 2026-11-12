#include "Main/Kart/kart_contact_effect_release.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Graphics/emitters.h"
#include "Main/Graphics/effects.h"
#include "Main/Race/data_020f36d8.h"
#include "code_02147cd8.h"
#include "code_0201c528.h"
#include "Main/Kart/karts.h"
#include "Main/MapObjects/data_0217a000.h"

void SetKartKillerEffectShown(s32 kartIndex, s32 shown) {
    ParticleEmitter *effect = gKartEffects[kartIndex].mKillerEffect;

    if (effect == NULL) {
        return;
    }
    effect->mFlags.mHidden = (shown == 0);
}

void StartAndPlaceKartContactEffect(s32 kartIndex, Vec3 *direction) {
    Vec3s16 directionHalfwords;
    Vec3 effectVelocity;
    Vec3 effectPos;
    Kart *kart = GetKart(kartIndex);
    KartEffects *kartEffects = &gKartEffects[kartIndex];
    ParticleEmitter *effect;

    if ((kart->mEffectFlags & KART_EFFECT_NEAR_PLAYER_RANK) && kartEffects->mContactEffect == NULL &&
        kart->mVelocityLength > 0x1000) {
        effect = StartEffect(0x53, kart->mPosSource);
        effect->mUnk_94 = kart;
        effect->mCallback = AdvanceKartContactEffect;
        kartEffects->mContactEffect = effect;
    }
    if (kartEffects->mContactEffect == NULL) {
        return;
    }
    effectVelocity.x = MUL_FIXED12_NO_ROUND(kart->mEffectVelocity.x, 0xccd);
    effectVelocity.y = MUL_FIXED12_NO_ROUND(kart->mEffectVelocity.y, 0xccd);
    effectVelocity.z = MUL_FIXED12_NO_ROUND(kart->mEffectVelocity.z, 0xccd);
    kartEffects->mContactEffect->mVelocity = effectVelocity;
    VEC_MultAdd(-kart->mRadius, direction, kart->mPosSource, &effectPos);
    PlaceEffect(kartEffects->mContactEffect, &effectPos);
    directionHalfwords.x = direction->x;
    directionHalfwords.y = direction->y;
    directionHalfwords.z = direction->z;
    kartEffects->mContactEffect->mDirection = directionHalfwords;
    kart->mDriveFlags |= KART_DRIVE_CONTACT_EFFECT;
}

void AdvanceKartContactEffect(ParticleEmitter *effect, s32 flag) {
    Kart *kart;
    KartEffects *kartEffects;

    if (flag != 0) {
        return;
    }
    kart = effect->mUnk_94;
    if ((kart->mDriveFlags & KART_DRIVE_CONTACT_EFFECT) && (kart->mMotionFlags & KART_MOTION_COURSE_CONTACT)) {
        if (kart->mVelocityLength >= 0x1333) {
            return;
        }
    }
    kartEffects = &gKartEffects[kart->mIndex];
    if (effect == kartEffects->mContactEffect) {
        effect->mFlags.mEnding = 1;
        kartEffects->mContactEffect = NULL;
    }
}

void ReleaseKartContactEffect(u32 kartIndex) {
    KartEffects *kartEffects = &gKartEffects[kartIndex];
    if (kartEffects->mContactEffect == NULL) {
        return;
    }
    DeleteEffect(kartEffects->mContactEffect);
    kartEffects->mContactEffect = NULL;
}
