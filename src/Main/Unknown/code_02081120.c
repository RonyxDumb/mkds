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

    if (!(kart->field4C & KART_4C_NEAR_PLAYER_RANK)) {
        return;
    }
    effectIndex = 0;
    do {
        effect = ptcm_createEmitter(0x58, &rptc_sEmitterPos);
        effect->field94 = kart;
        effect->field98_24 = effectIndex;
        effectIndex = effectIndex + 1;
        effect->field90 = rptc_waterEmitterCallback;
    } while (effectIndex < 2);
}

void rptc_waterEmitterCallback(Unk0201ca6c *effect, s32 a) {
    if (a != 0) {
        return;
    }
    rptc_208335C(effect, a);
    if (effect->field98_0 >= 7) {
        effect->field98_8 = 1;
    } else {
        effect->field98_0 = effect->field98_0 + 1;
    }
}

void rptc_startElectricEffect(u32 kartIndex) {
    KartEffects *kartEffects = &rptc_sDriverEffects[kartIndex];
    Unk0201ca6c *effect;

    if (kartEffects->field30 != NULL) {
        ptcm_killEmitterDirect(kartEffects->field30);
    }
    kartEffects->field30 = ptcm_createEmitter(0x5e, &rptc_sEmitterPos);
    effect = kartEffects->field30;
    effect->field98_16 = 0;
    effect->field98_8 = 0x78;
    effect->field98_24 = kartIndex;
    effect->field90 = rptc_electricEmitterCallback;
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
    kartIndex = effect->field98_24;
    elapsedFrames = effect->field98_16;
    ended = 0;
    kartPosition = driver_getById(kartIndex)->mPosSource;
    kartX = kartPosition->x;
    kartY = kartPosition->y;
    kartZ = kartPosition->z;
    effect->field28.x = (kartX >> 4) + effect->field20->field0->field4.x;
    effect->field28.y = (kartY >> 4) + effect->field20->field0->field4.y;
    effect->field28.z = (kartZ >> 4) + effect->field20->field0->field4.z;
    if (elapsedFrames >= effect->field98_8) {
        if (elapsedFrames == effect->field98_8) {
            ended = 1;
            effect->field24.field0_0 = 1;
        }
    } else {
        effect->field98_16 = elapsedFrames + 1;
    }
    if (ended != 0) {
        rptc_sDriverEffects[kartIndex].field30 = NULL;
        return;
    }
    effect->field6C = (s16) driver_getById(kartIndex)->mScale.z;
}
