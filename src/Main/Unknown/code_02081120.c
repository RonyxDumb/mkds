#include "Main/Unknown/code_02081120.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_02083000.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_02077bc0.h"

void rptc_startWaterEffect(s32 kartIndex) {
    Kart *kart = driver_getById(kartIndex);
    Unk0201ca6c *effect;
    u16 effectIndex;

    if (!(kart->mUnk_4c & KART_4C_NEAR_PLAYER_RANK)) {
        return;
    }
    effectIndex = 0;
    do {
        effect = ptcm_createEmitter(0x58, &rptc_sEmitterPos);
        effect->mUnk_94 = kart;
        effect->mUnk_98_24 = effectIndex;
        effectIndex = effectIndex + 1;
        effect->mUnk_90 = rptc_waterEmitterCallback;
    } while (effectIndex < 2);
}

void rptc_waterEmitterCallback(Unk0201ca6c *effect, s32 a) {
    if (a != 0) {
        return;
    }
    rptc_208335C(effect, a);
    if (effect->mUnk_98_0 >= 7) {
        effect->mUnk_98_8 = 1;
    } else {
        effect->mUnk_98_0 = effect->mUnk_98_0 + 1;
    }
}

void rptc_startElectricEffect(u32 kartIndex) {
    KartEffects *kartEffects = &rptc_sDriverEffects[kartIndex];
    Unk0201ca6c *effect;

    if (kartEffects->mUnk_30 != NULL) {
        ptcm_killEmitterDirect(kartEffects->mUnk_30);
    }
    kartEffects->mUnk_30 = ptcm_createEmitter(0x5e, &rptc_sEmitterPos);
    effect = kartEffects->mUnk_30;
    effect->mUnk_98_16 = 0;
    effect->mUnk_98_8 = 0x78;
    effect->mUnk_98_24 = kartIndex;
    effect->mUnk_90 = rptc_electricEmitterCallback;
}

void rptc_electricEmitterCallback(Unk0201ca6c *effect, s32 a) {
    u32 ended;
    u8 elapsedFrames;
    u8 kartIndex;
    Vec3 *kartPosition;
    s32 kartX;
    s32 kartY;
    s32 kartZ;

    if (a != 0) {
        return;
    }
    kartIndex = effect->mUnk_98_24;
    elapsedFrames = effect->mUnk_98_16;
    ended = 0;
    kartPosition = driver_getById(kartIndex)->mPosSource;
    kartX = kartPosition->x;
    kartY = kartPosition->y;
    kartZ = kartPosition->z;
    effect->mUnk_28.x = (kartX >> 4) + effect->mUnk_20->mUnk_00->mUnk_04.x;
    effect->mUnk_28.y = (kartY >> 4) + effect->mUnk_20->mUnk_00->mUnk_04.y;
    effect->mUnk_28.z = (kartZ >> 4) + effect->mUnk_20->mUnk_00->mUnk_04.z;
    if (elapsedFrames >= effect->mUnk_98_8) {
        if (elapsedFrames == effect->mUnk_98_8) {
            ended = 1;
            effect->mUnk_24.mUnk_00_0 = 1;
        }
    } else {
        effect->mUnk_98_16 = elapsedFrames + 1;
    }
    if (ended != 0) {
        rptc_sDriverEffects[kartIndex].mUnk_30 = NULL;
        return;
    }
    effect->mUnk_6c = (s16) driver_getById(kartIndex)->mScale.z;
}
