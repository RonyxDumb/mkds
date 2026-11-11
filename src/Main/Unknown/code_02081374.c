#include "Main/Unknown/code_02081374.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0208b000.h"
#include "code_02147cd8.h"
#include "code_0201c528.h"
#include "Main/Unknown/code_02077bc0.h"

void SetKartKillerEffectShown(s32 kartIndex, s32 shown) {
    Unk0201ca6c *effect = gKartEffects[kartIndex].mKillerEffect;

    if (effect == NULL) {
        return;
    }
    effect->mUnk_24.mUnk_00_3 = (shown == 0);
}

void StartAndPlaceKartContactEffect(s32 kartIndex, Vec3 *direction) {
    Vec3s16 directionHalfwords;
    Vec3 effectVelocity;
    Vec3 effectPos;
    Kart *kart = GetKart(kartIndex);
    KartEffects *kartEffects = &gKartEffects[kartIndex];
    Unk0201ca6c *effect;

    if ((kart->mUnk_4c & KART_4C_NEAR_PLAYER_RANK) && kartEffects->mContactEffect == NULL &&
        kart->mVelocityLength > 0x1000) {
        effect = StartEffect(0x53, kart->mPosSource);
        effect->mUnk_94 = kart;
        effect->mUnk_90 = AdvanceKartContactEffect;
        kartEffects->mContactEffect = effect;
    }
    if (kartEffects->mContactEffect == NULL) {
        return;
    }
    effectVelocity.x = MUL_FIXED12_NO_ROUND(kart->mEffectVelocity.x, 0xccd);
    effectVelocity.y = MUL_FIXED12_NO_ROUND(kart->mEffectVelocity.y, 0xccd);
    effectVelocity.z = MUL_FIXED12_NO_ROUND(kart->mEffectVelocity.z, 0xccd);
    kartEffects->mContactEffect->mUnk_40 = effectVelocity;
    VEC_MultAdd(-kart->mRadius, direction, kart->mPosSource, &effectPos);
    PlaceEffect(kartEffects->mContactEffect, &effectPos);
    directionHalfwords.x = direction->x;
    directionHalfwords.y = direction->y;
    directionHalfwords.z = direction->z;
    kartEffects->mContactEffect->mUnk_50 = directionHalfwords;
    kart->mUnk_48 |= 0x400;
}

void AdvanceKartContactEffect(Unk0201ca6c *effect, s32 flag) {
    Kart *kart;
    KartEffects *kartEffects;

    if (flag != 0) {
        return;
    }
    kart = effect->mUnk_94;
    if ((kart->mUnk_48 & 0x400) && (kart->mUnk_44 & 0x80)) {
        if (kart->mVelocityLength >= 0x1333) {
            return;
        }
    }
    kartEffects = &gKartEffects[kart->mIndex];
    if (effect == kartEffects->mContactEffect) {
        effect->mUnk_24.mUnk_00_0 = 1;
        kartEffects->mContactEffect = NULL;
    }
}
