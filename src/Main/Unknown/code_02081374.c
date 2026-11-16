#include "Main/Unknown/code_02081374.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0208b000.h"
#include "code_02147cd8.h"
#include "code_0201c528.h"
#include "Main/Unknown/code_02077bc0.h"

void rptc_setBulletBillEffectVisibility(s32 kartIndex, s32 shown) {
    Unk0201ca6c *effect = rptc_sDriverEffects[kartIndex].mKillerEffect;

    if (effect == NULL) {
        return;
    }
    effect->field24.field0_3 = (shown == 0);
}

void rptc_startWallLeafEffect(s32 kartIndex, Vec3 *direction) {
    Vec3s16 directionHalfwords;
    Vec3 effectVelocity;
    Vec3 effectPos;
    Kart *kart = driver_getById(kartIndex);
    KartEffects *kartEffects = &rptc_sDriverEffects[kartIndex];
    Unk0201ca6c *effect;

    if ((kart->field4C & KART_4C_NEAR_PLAYER_RANK) && kartEffects->field28 == NULL && kart->mVelocityLength > 0x1000) {
        effect = ptcm_createEmitter(0x53, kart->mPosSource);
        effect->field94 = kart;
        effect->field90 = rptc_wallLeafEmitterCallback;
        kartEffects->field28 = effect;
    }
    if (kartEffects->field28 == NULL) {
        return;
    }
    effectVelocity.x = ((s64) kart->mEffectVelocity.x * 0xccd) >> 12;
    effectVelocity.y = ((s64) kart->mEffectVelocity.y * 0xccd) >> 12;
    effectVelocity.z = ((s64) kart->mEffectVelocity.z * 0xccd) >> 12;
    kartEffects->field28->field40 = effectVelocity;
    VEC_MultAdd(-kart->mRadius, direction, kart->mPosSource, &effectPos);
    ptcm_setEmitterPosition(kartEffects->field28, &effectPos);
    directionHalfwords.x = direction->x;
    directionHalfwords.y = direction->y;
    directionHalfwords.z = direction->z;
    kartEffects->field28->field50 = directionHalfwords;
    kart->field48 |= 0x400;
}

void rptc_wallLeafEmitterCallback(Unk0201ca6c *effect, s32 a) {
    Kart *kart;
    KartEffects *kartEffects;

    if (a != 0) {
        return;
    }
    kart = effect->field94;
    if ((kart->field48 & 0x400) && (kart->field44 & 0x80)) {
        if (kart->mVelocityLength >= 0x1333) {
            return;
        }
    }
    kartEffects = &rptc_sDriverEffects[kart->mIndex];
    if (effect == kartEffects->field28) {
        effect->field24.field0_0 = 1;
        kartEffects->field28 = NULL;
    }
}
