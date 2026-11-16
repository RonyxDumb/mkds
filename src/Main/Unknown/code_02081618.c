#include "Main/Unknown/code_02081618.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_02066ac0.h"
#include "Main/Unknown/code_02081000.h"

#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Item/ItemInUse.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/unk_02165000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "code_0201c528.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Item/ItemGesso.h"
#include "Main/Unknown/code_0203c5e4.h"
#include "Main/Unknown/code_02073eb8.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_02146d78.h"
#include "code_02148538.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02067000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "code_02147288.h"
#include "Main/Unknown/code_02077bc0.h"

KartEffects *rptc_getEffectControllerForDriver(int kartIndex) {
    u32 value0 = kartIndex;
    u32 entrySize;
    u32 value2;
    value2 = (u32) &rptc_sDriverEffects;
    entrySize = 0x58u;
    value2 = *(const u32 *) ((value2) + (0));
    value0 = (entrySize) * (value0) + (value2);
    return (KartEffects *) value0;
}

void rptc_initForDrivers(u32 kartCount) {
    KartEffects *kartEffects;
    u16 i;
    u16 j;

    i = 0;
    rptc_sDriverEffects = heap_alloc(proc_getHeap(proc_getCurrent()), kartCount * 0x58);
    data_0217ae70 = kartCount;
    for (; i < kartCount; i++) {
        kartEffects = &rptc_sDriverEffects[i];
        kartEffects->mCurrentEffect = NULL;
        kartEffects->field28 = NULL;
        kartEffects->mKillerEffect = NULL;
        kartEffects->field30 = NULL;
        kartEffects->mCurrentEffectId = -1;
        kartEffects->mWaterEffect0 = kartEffects->mWaterEffect1 = 0;
        for (j = 0; j < 2; j++) {
            kartEffects->mEffectPairs[j].mEffect0 = kartEffects->mEffectPairs[j].mEffect1 = 0;
            kartEffects->mEffectIds[j] = -1;
        }
    }
    rptc_sBoostEmitter = NULL;
}

void rptc_updateDriverEffects(Kart *kart) {
    u16 i;
    KartEffects *kartEffects;
    Vec3 scaledPoint;
    Vec3 sideDirection;
    Vec3 modelPoint;

    kartEffects = &rptc_sDriverEffects[kart->mIndex];
    kart->field174 = *kart->mPosSource;
    for (i = 0; i < 2; i++) {
        modelPoint = kart->mKartModelsEntry->mKartOffsetData->field14[i + 2];
        modelPoint.y = 0;
        modelPoint.x = modelPoint.x + gKartSideOffsetsX[i];
        scaledPoint.x = ((s64) modelPoint.x * kart->mScale.x) >> 12;
        scaledPoint.y = ((s64) modelPoint.y * kart->mScale.y) >> 12;
        scaledPoint.z = ((s64) modelPoint.z * kart->mScale.z) >> 12;
        MTX_MultVec43(&scaledPoint, &kart->mUnk_150_m, &kartEffects->mSidePositions[i]);
        kartEffects->mSidePositions[i].x = kartEffects->mSidePositions[i].x >> 4;
        kartEffects->mSidePositions[i].y = kartEffects->mSidePositions[i].y >> 4;
        kartEffects->mSidePositions[i].z = kartEffects->mSidePositions[i].z >> 4;
        MTX_MultVec33(&gKartSideDirectionVectors[i], &kart->field150.x, &sideDirection);
        kartEffects->mSideDirections[i].x = sideDirection.x;
        kartEffects->mSideDirections[i].y = sideDirection.y;
        kartEffects->mSideDirections[i].z = sideDirection.z;
    }
}

void rptc_killDriverEffects(Kart *kart) {
    KartEffects *kartEffects;

    kartEffects = &rptc_sDriverEffects[kart->mIndex];
    if (kartEffects->mCurrentEffect != NULL) {
        kartEffects->mCurrentEffect->field98_8 = 1;
        kartEffects->mCurrentEffect = NULL;
        kartEffects->mCurrentEffectId = -1;
    }
    rptc_killDriverEffects2(kart, 0);
}

void func_020843d8(Kart *kart) {
    rptc_sColEffects[0].mStartEffects(
        &rptc_sColEffects[0].mEffectIdSets[rptc_sDriverEffectVariantTable[kart->mIndex]],
        rptc_sColEffects[0].mVelocityFactorIndex, kart);
    rptc_killDriverEffects2(kart, 0);
}

void rptc_2084384(Kart *kart) {
    gKartSurfaceEffectRow1.mStartEffects(&gKartSurfaceEffectRow1.mEffectIdSets[rptc_sDriverEffectVariantTable[kart->mIndex]],
                                         gKartSurfaceEffectRow1.mVelocityFactorIndex, kart);
    rptc_killDriverEffects2(kart, 0);
}

void func_02084334(Kart *kart) {
    KartEffects *kartEffects;

    kartEffects = &rptc_sDriverEffects[kart->mIndex];
    if (kartEffects->mCurrentEffect != NULL) {
        kartEffects->mCurrentEffect->field98_8 = 1;
        kartEffects->mCurrentEffect = NULL;
        kartEffects->mCurrentEffectId = -1;
    }
    rptc_2083DE8(2, kart);
}

void rptc_startRoadWaterEffect(Kart *kart) {
    KartEffects *kartEffects;

    kartEffects = &rptc_sDriverEffects[kart->mIndex];
    if (kartEffects->mCurrentEffect != NULL) {
        kartEffects->mCurrentEffect->field98_8 = 1;
        kartEffects->mCurrentEffect = NULL;
        kartEffects->mCurrentEffectId = -1;
    }
    gKartSurfaceEffectRow3.mStartEffects(&gKartSurfaceEffectRow3.mEffectIdSets[rptc_sDriverEffectVariantTable[kart->mIndex]],
                                         gKartSurfaceEffectRow3.mVelocityFactorIndex, kart);
}

void rptc_startRoadMudEffect(Kart *kart) {
    KartEffects *kartEffects;

    kartEffects = &rptc_sDriverEffects[kart->mIndex];
    if (kartEffects->mCurrentEffect != NULL) {
        kartEffects->mCurrentEffect->field98_8 = 1;
        kartEffects->mCurrentEffect = NULL;
        kartEffects->mCurrentEffectId = -1;
    }
    gKartSurfaceEffectRow4.mStartEffects(&gKartSurfaceEffectRow4.mEffectIdSets[rptc_sDriverEffectVariantTable[kart->mIndex]],
                                         gKartSurfaceEffectRow4.mVelocityFactorIndex, kart);
}

void rptc_startRoadGBASkyGardenEffect(Kart *kart) {
    KartEffects *kartEffects;

    kartEffects = &rptc_sDriverEffects[kart->mIndex];
    if (kartEffects->mCurrentEffect != NULL) {
        kartEffects->mCurrentEffect->field98_8 = 1;
        kartEffects->mCurrentEffect = NULL;
        kartEffects->mCurrentEffectId = -1;
    }
    gKartSurfaceEffectRow5.mStartEffects(&gKartSurfaceEffectRow5.mEffectIdSets[rptc_sDriverEffectVariantTable[kart->mIndex]],
                                         gKartSurfaceEffectRow5.mVelocityFactorIndex, kart);
}

void rptc_startRoadSnowEffect(Kart *kart) {
    KartEffects *kartEffects;

    kartEffects = &rptc_sDriverEffects[kart->mIndex];
    if (kartEffects->mCurrentEffect != NULL) {
        kartEffects->mCurrentEffect->field98_8 = 1;
        kartEffects->mCurrentEffect = NULL;
        kartEffects->mCurrentEffectId = -1;
    }
    gKartSurfaceEffectRow6.mStartEffects(&gKartSurfaceEffectRow6.mEffectIdSets[rptc_sDriverEffectVariantTable[kart->mIndex]],
                                         gKartSurfaceEffectRow6.mVelocityFactorIndex, kart);
}

void rptc_startRoadFlowerEffect(Kart *kart) {
    gKartSurfaceEffectRow7.mStartEffects(&gKartSurfaceEffectRow7.mEffectIdSets[rptc_sDriverEffectVariantTable[kart->mIndex]],
                                         gKartSurfaceEffectRow7.mVelocityFactorIndex, kart);
    rptc_killDriverEffects2(kart, 0);
}

// Starts the boost effect in front of the chase camera; the previous one is told to end.
void rptc_startBoostEffect(u32 effectIdIndex, Kart *kart) {
    Unk0201ca6c *effect;

    if (race_getCameraField250() != 0) {
        return;
    }
    cam_getPlayerCamera();
    if (rptc_sBoostEmitter != NULL) {
        rptc_sBoostEmitter->field24.field0_0 = 1;
    }
    effect = ptcm_createEmitter(gKartBoostCameraEffectIds[effectIdIndex], &rptc_sEmitterPos);
    effect->field98 = 0;
    effect->field94 = kart;
    effect->field90 = rptc_boostEmitterCallback;
    rptc_sBoostEmitter = effect;
}

// Runs entry a of the effect table while the kart flag is set, otherwise ends the kart effects.
void rptc_collisionParticleRender(s32 functionIndex, Kart *kart) {
    KartEffects *kartEffects;

    if (kart->field4C & KART_4C_NEAR_PLAYER_RANK) {
        CollisionParticleRenderArray[functionIndex](kart);
        return;
    }
    kartEffects = &rptc_sDriverEffects[kart->mIndex];
    if (kartEffects->mCurrentEffect != NULL) {
        kartEffects->mCurrentEffect->field98_8 = 1;
        kartEffects->mCurrentEffect = NULL;
        kartEffects->mCurrentEffectId = -1;
    }
    rptc_killDriverEffects2(kart, 0);
    kartEffects = &rptc_sDriverEffects[kart->mIndex];
    if (kartEffects->mWaterEffect0 != 0) {
        kartEffects->mWaterEffect0->field98_8 = 1;
        kartEffects->mWaterEffect0 = 0;
    }
    if (kartEffects->mWaterEffect1 != 0) {
        kartEffects->mWaterEffect1->field98_8 = 1;
        kartEffects->mWaterEffect1 = 0;
    }
}

// Starts the water effects while the kart flag is set, otherwise ends them.
void rptc_2083EC4(Kart *kart) {
    KartEffects *kartEffects;

    if (kart->field4C & KART_4C_NEAR_PLAYER_RANK) {
        rptc_2083A24(&gKartSurfaceEffectRow3.mEffectIdSets[rptc_sDriverEffectVariantTable[kart->mIndex]], 1, kart);
        return;
    }
    kartEffects = &rptc_sDriverEffects[kart->mIndex];
    if (kartEffects->mWaterEffect0 != 0) {
        kartEffects->mWaterEffect0->field98_8 = 1;
        kartEffects->mWaterEffect0 = 0;
    }
    if (kartEffects->mWaterEffect1 != 0) {
        kartEffects->mWaterEffect1->field98_8 = 1;
        kartEffects->mWaterEffect1 = 0;
    }
}

void rptc_2083DE8(s32 rowIndex, Kart *kart) {
    KartSurfaceEffectRow *row;
    KartEffectIdSet *effectIdSet;
    KartEffects *kartEffects;
    u16 i;
    u16 j;

    row = &rptc_sColEffects[rowIndex];
    effectIdSet = &row->mEffectIdSets[rptc_sDriverEffectVariantTable[kart->mIndex]];
    if (row->mStartEffects(effectIdSet, row->mVelocityFactorIndex, kart) == 0) {
        return;
    }
    kartEffects = &rptc_sDriverEffects[kart->mIndex];
    for (i = 0; i < effectIdSet->mCount; i++) {
        for (j = 0; j < 2; j++) {
            if (kartEffects->mEffectPairs[i].mUnk_00_a[j] != 0) {
                kartEffects->mEffectPairs[i].mUnk_00_a[j]->field72 = rptc_sEffectColor;
            }
        }
    }
}

BOOL rptc_DriveOnSand(KartEffectIdSet *effectIdSet, s32 velocityFactorIndex, Kart *kart) {
    KartEffects *kartEffects;
    Unk0201ca6c *effect;

    kartEffects = &rptc_sDriverEffects[kart->mIndex];
    if (effectIdSet->mEffectIds[0] == kartEffects->mCurrentEffectId) {
        return FALSE;
    }
    if (kartEffects->mCurrentEffect != NULL) {
        kartEffects->mCurrentEffect->field98_8 = 1;
    }
    effect = ptcm_createEmitter(effectIdSet->mEffectIds[0], &rptc_sEmitterPos);
    kartEffects->mCurrentEffect = effect;
    kartEffects->mCurrentEffectId = effectIdSet->mEffectIds[0];
    effect->field94 = kart;
    effect->field98_0 = velocityFactorIndex;
    effect->field90 = AdvanceKartCurrentEffect;
    return TRUE;
}

// Starts one effect per side of the kart for each id that is not running yet.
s32 rptc_DriveOnMud(KartEffectIdSet *effectIdSet, s32 unusedVelocityFactorIndex, Kart *kart) {
    KartEffects *kartEffects;
    Unk0201ca6c *effect;
    s32 started;
    u16 i;
    u16 j;

    started = i = 0;
    for (; i < effectIdSet->mCount; i++) {
        kartEffects = &rptc_sDriverEffects[kart->mIndex];
        j = 0;
        if (effectIdSet->mEffectIds[i] != kartEffects->mEffectIds[i]) {
            if (kartEffects->mEffectPairs[i].mEffect0 != 0) {
                kartEffects->mEffectPairs[i].mEffect0->field98_8 = 1;
            }
            if (kartEffects->mEffectPairs[i].mEffect1 != 0) {
                kartEffects->mEffectPairs[i].mEffect1->field98_8 = 1;
            }
            kartEffects->mEffectIds[i] = effectIdSet->mEffectIds[i];
            do {
                effect = ptcm_createEmitter(kartEffects->mEffectIds[i], &rptc_sEmitterPos);
                rptc_sDriverEffects[kart->mIndex].mEffectPairs[i].mUnk_00_a[j] = effect;
                effect->field94 = kart;
                effect->field98_24 = j;
                j++;
                effect->field90 = rptc_208335C;
            } while (j < 2);
            started = 1;
        }
    }
    return started;
}

s32 rptc_DriveOnGrassSnowWater(KartEffectIdSet *effectIdSet, s32 velocityFactorIndex, Kart *kart) {
    KartEffects *kartEffects;
    Unk0201ca6c *effect;
    s32 started;
    u16 i;
    u16 j;

    started = i = 0;
    for (; i < effectIdSet->mCount; i++) {
        kartEffects = &rptc_sDriverEffects[kart->mIndex];
        j = 0;
        if (effectIdSet->mEffectIds[i] != kartEffects->mEffectIds[i]) {
            if (kartEffects->mEffectPairs[i].mEffect0 != 0) {
                kartEffects->mEffectPairs[i].mEffect0->field98_8 = 1;
            }
            if (kartEffects->mEffectPairs[i].mEffect1 != 0) {
                kartEffects->mEffectPairs[i].mEffect1->field98_8 = 1;
            }
            kartEffects->mEffectIds[i] = effectIdSet->mEffectIds[i];
            do {
                effect = ptcm_createEmitter(kartEffects->mEffectIds[i], &rptc_sEmitterPos);
                rptc_sDriverEffects[kart->mIndex].mEffectPairs[i].mUnk_00_a[j] = effect;
                effect->field94 = kart;
                effect->field98_24 = j;
                j++;
                effect->field98_0 = velocityFactorIndex;
                effect->field90 = rptc_20831BC;
            } while (j < 2);
            started = 1;
        }
    }
    return started;
}

BOOL rptc_2083A24(KartEffectIdSet *effectIdSet, s32 velocityFactorIndex, Kart *kart) {
    KartEffects *kartEffects;
    Unk0201ca6c *effect;
    u16 i;

    kartEffects = &rptc_sDriverEffects[kart->mIndex];
    if (kartEffects->mWaterEffect0 != 0 || kartEffects->mWaterEffect1 != 0) {
        return FALSE;
    }
    for (i = 0; i < 2; i++) {
        effect = ptcm_createEmitter(effectIdSet->mEffectIds[0], &rptc_sEmitterPos);
        rptc_sDriverEffects[kart->mIndex].mUnk_20_a[i] = effect;
        effect->field94 = kart;
        effect->field98_24 = i;
        effect->field98_0 = velocityFactorIndex;
        effect->field90 = rptc_2082FEC;
    }
    return TRUE;
}

void rptc_killDriverEffects_copy(Kart *kart) {
    KartEffects *kartEffects;

    kartEffects = &rptc_sDriverEffects[kart->mIndex];
    if (kartEffects->mCurrentEffect != NULL) {
        kartEffects->mCurrentEffect->field98_8 = 1;
        kartEffects->mCurrentEffect = NULL;
        kartEffects->mCurrentEffectId = -1;
    }
    rptc_killDriverEffects2(kart, 0);
}

void rptc_killDriverEffects2(Kart *kart, s32 deleteAtOnce) {
    u16 i;
    KartEffects *kartEffects;

    kartEffects = &rptc_sDriverEffects[kart->mIndex];
    for (i = 0; i < 2; i++) {
        if (kartEffects->mEffectPairs[i].mEffect0 != 0 || kartEffects->mEffectPairs[i].mEffect1 != 0) {
            if (deleteAtOnce == 0) {
                kartEffects->mEffectPairs[i].mEffect0->field98_8 = 1;
                kartEffects->mEffectPairs[i].mEffect1->field98_8 = 1;
            } else {
                ptcm_killEmitterDirect(kartEffects->mEffectPairs[i].mEffect0);
                ptcm_killEmitterDirect(kartEffects->mEffectPairs[i].mEffect1);
            }
            kartEffects->mEffectPairs[i].mEffect0 = kartEffects->mEffectPairs[i].mEffect1 = 0;
            kartEffects->mEffectIds[i] = -1;
        }
    }
}

void rptc_20838DC(Kart *kart) {
    KartEffects *kartEffects;

    kartEffects = &rptc_sDriverEffects[kart->mIndex];
    if (kartEffects->mWaterEffect0 != 0) {
        kartEffects->mWaterEffect0->field98_8 = 1;
        kartEffects->mWaterEffect0 = 0;
    }
    if (kartEffects->mWaterEffect1 != 0) {
        kartEffects->mWaterEffect1->field98_8 = 1;
        kartEffects->mWaterEffect1 = 0;
    }
}

// Deletes the current, side and water effects of the kart at once.
void rptc_2083834(Kart *kart) {
    KartEffects *kartEffects;

    kartEffects = &rptc_sDriverEffects[kart->mIndex];
    if (kartEffects->mCurrentEffect != NULL) {
        ptcm_killEmitterDirect(kartEffects->mCurrentEffect);
        kartEffects->mCurrentEffect = NULL;
        kartEffects->mCurrentEffectId = -1;
    }
    rptc_killDriverEffects2(kart, 1);
    kartEffects = &rptc_sDriverEffects[kart->mIndex];
    if (kartEffects->mWaterEffect0 != 0) {
        ptcm_killEmitterDirect(kartEffects->mWaterEffect0);
        kartEffects->mWaterEffect0 = 0;
    }
    if (kartEffects->mWaterEffect1 == 0) {
        return;
    }
    ptcm_killEmitterDirect(kartEffects->mWaterEffect1);
    kartEffects->mWaterEffect1 = 0;
}

void rptc_boostEmitterCallback(Unk0201ca6c *effect, s32 a) {
    Vec3s16 backwardDirection;
    Vec3 viewPos;
    Vec3 forwardOffset;
    Vec3 effectPos;
    Camera *chaseCamera;
    Kart *kart;

    if (a != 0) {
        return;
    }
    chaseCamera = cam_getPlayerCamera();
    kart = effect->field94;
    if (race_getCameraField250() != 0 ||
        (effect->field24.field0_1 != 0 && (effect->field98 = effect->field98 + 1, effect->field98 > 5))) {
        effect->field24.field0_0 = 1;
        rptc_sBoostEmitter = NULL;
        return;
    }
    if (!(kart->field48 & KART_48_BOOST)) {
        effect->field24.field0_1 = 1;
    }
    viewPos = chaseCamera->mViewPos;
    forwardOffset.x = ((s64) chaseCamera->mForward.x * 0x5000) >> 12;
    forwardOffset.y = ((s64) chaseCamera->mForward.y * 0x5000) >> 12;
    forwardOffset.z = ((s64) chaseCamera->mForward.z * 0x5000) >> 12;
    VEC_Add(&forwardOffset, &viewPos, &effectPos);
    effect->field28.x = effectPos.x + effect->field20->field0->field4.x;
    effect->field28.y = effectPos.y + effect->field20->field0->field4.y;
    effect->field28.z = effectPos.z + effect->field20->field0->field4.z;
    backwardDirection.x = -chaseCamera->mForward.x;
    backwardDirection.y = -chaseCamera->mForward.y;
    backwardDirection.z = -chaseCamera->mForward.z;
    effect->field50 = backwardDirection;
}

void AdvanceKartCurrentEffect(Unk0201ca6c *effect, s32 a) {
    Vec3 effectPos;
    Vec3 velocity;
    Vec3 offsetBehind;
    Kart *kart;
    Vec3 *s;
    u32 stepCount;
    s32 velocityFactor;
    u32 counting;
    u32 f;

    if (a != 0) {
        return;
    }
    kart = effect->field94;
    velocity = kart->mEffectVelocity;
    velocityFactor = gKartEffectVelocityFactors[effect->mUnk_98_b.field0];
    stepCount = effect->mUnk_98_b.field2;
    counting = effect->mUnk_98_b.field1;
    f = 1;
    if (IsKartTurnEffectsActive(kart) == 0) {
        if (kart->mVelocityLength >= 0x119a) {
            f = 0;
        }
    }
    effect->field24.field0_1 = (f != 0);
    s = &kart->field138;
    offsetBehind.x = ((s64) s->x * -0x5000) >> 12;
    offsetBehind.y = ((s64) s->y * -0x5000) >> 12;
    offsetBehind.z = ((s64) s->z * -0x5000) >> 12;
    if (counting != 0) {
        stepCount = (u8) (stepCount + 1);
        if (stepCount == 10) {
            effect->field24.field0_0 = 1;
        }
    }
    effect->mUnk_98_b.field2 = stepCount;
    VEC_Add(kart->mPosSource, &offsetBehind, &effectPos);
    effectPos.x = effectPos.x >> 4;
    effectPos.y = effectPos.y >> 4;
    effectPos.z = effectPos.z >> 4;
    velocity.x = ((s64) velocity.x * velocityFactor) >> 12;
    velocity.y = ((s64) velocity.y * velocityFactor) >> 12;
    velocity.z = ((s64) velocity.z * velocityFactor) >> 12;
    effect->field28.x = effectPos.x + effect->field20->field0->field4.x;
    effect->field28.y = effectPos.y + effect->field20->field0->field4.y;
    effect->field28.z = effectPos.z + effect->field20->field0->field4.z;
    effect->field40 = velocity;
}

void rptc_208335C(Unk0201ca6c *effect, s32 a) {
    s32 x;
    Kart *kart;
    u32 stepCount;
    KartEffects *kartEffects;
    u32 counting;
    u32 sideIndex;
    u32 f;

    if (a != 0) {
        return;
    }
    kart = effect->field94;
    kartEffects = &rptc_sDriverEffects[kart->mIndex];
    stepCount = effect->mUnk_98_b.field2;
    counting = effect->mUnk_98_b.field1;
    sideIndex = effect->mUnk_98_b.field3;
    f = 1;
    if (IsKartTurnEffectsActive(kart) == 0) {
        if (kart->mVelocityLength >= 0x119a) {
            f = 0;
        }
    }
    effect->field24.field0_1 = (f != 0);
    if (counting != 0) {
        stepCount = (u8) (stepCount + 1);
        if (stepCount == 10) {
            effect->field24.field0_0 = 1;
        }
    }
    effect->mUnk_98_b.field2 = stepCount;
    effect->field50 = kartEffects->mSideDirections[sideIndex];
    x = kartEffects->mSidePositions[sideIndex].x;
    effect->field28.x = x + effect->field20->field0->field4.x;
    x = kartEffects->mSidePositions[sideIndex].y;
    effect->field28.y = x + effect->field20->field0->field4.y;
    x = kartEffects->mSidePositions[sideIndex].z;
    effect->field28.z = x + effect->field20->field0->field4.z;
}

void rptc_20831BC(Unk0201ca6c *effect, s32 a) {
    s32 x;
    Vec3 velocity;
    Kart *kart;
    u32 stepCount;
    KartEffects *kartEffects;
    u32 counting;
    u32 sideIndex;
    s32 velocityFactor;
    u32 f;

    if (a != 0) {
        return;
    }
    kart = effect->field94;
    kartEffects = &rptc_sDriverEffects[kart->mIndex];
    velocity = kart->mEffectVelocity;
    stepCount = effect->mUnk_98_b.field2;
    counting = effect->mUnk_98_b.field1;
    sideIndex = effect->mUnk_98_b.field3;
    velocityFactor = gKartEffectVelocityFactors[effect->mUnk_98_b.field0];
    f = 1;
    if (IsKartTurnEffectsActive(kart) == 0) {
        if (kart->mVelocityLength >= 0x119a) {
            f = 0;
        }
    }
    effect->field24.field0_1 = (f != 0);
    if (counting != 0) {
        stepCount = (u8) (stepCount + 1);
        if (stepCount == 10) {
            effect->field24.field0_0 = 1;
        }
    }
    effect->mUnk_98_b.field2 = stepCount;
    effect->field50 = kartEffects->mSideDirections[sideIndex];
    x = kartEffects->mSidePositions[sideIndex].x;
    effect->field28.x = x + effect->field20->field0->field4.x;
    x = kartEffects->mSidePositions[sideIndex].y;
    effect->field28.y = x + effect->field20->field0->field4.y;
    x = kartEffects->mSidePositions[sideIndex].z;
    effect->field28.z = x + effect->field20->field0->field4.z;
    velocity.x = ((s64) velocity.x * velocityFactor) >> 12;
    velocity.y = ((s64) velocity.y * velocityFactor) >> 12;
    velocity.z = ((s64) velocity.z * velocityFactor) >> 12;
    effect->field40 = velocity;
}

// Keeps the water effect at the kart's side, raised by the depth below the water surface.
void rptc_2082FEC(Unk0201ca6c *effect, s32 a) {
    s32 x;
    Vec3 velocity;
    u32 counting;
    Kart *kart;
    u32 stepCount;
    KartEffects *kartEffects;
    u32 f;
    u32 sideIndex;
    s32 velocityFactor;
    u32 g;

    if (a != 0) {
        return;
    }
    kart = effect->field94;
    kartEffects = &rptc_sDriverEffects[kart->mIndex];
    velocity = kart->mEffectVelocity;
    g = 1;
    f = 1;
    stepCount = effect->mUnk_98_b.field2;
    counting = effect->mUnk_98_b.field1;
    sideIndex = effect->mUnk_98_b.field3;
    velocityFactor = gKartEffectVelocityFactors[effect->mUnk_98_b.field0];
    if (IsKartTurnEffectsActive(kart) == 0) {
        if (kart->mVelocityLength >= 0x119a) {
            f = 0;
        }
    }
    if (f == 0) {
        if (kart->mWaterDepth <= 0x5000) {
            g = 0;
        }
    }
    effect->field24.field0_1 = (g != 0);
    if (counting != 0) {
        stepCount = (u8) (stepCount + 1);
        if (stepCount == 10) {
            effect->field24.field0_0 = 1;
        }
    }
    effect->mUnk_98_b.field2 = stepCount;
    effect->field50 = kartEffects->mSideDirections[sideIndex];
    x = kartEffects->mSidePositions[sideIndex].x;
    effect->field28.x = x + effect->field20->field0->field4.x;
    x = kartEffects->mSidePositions[sideIndex].y;
    effect->field28.y = x + effect->field20->field0->field4.y;
    x = kartEffects->mSidePositions[sideIndex].z;
    effect->field28.z = x + effect->field20->field0->field4.z;
    effect->field28.y = effect->field28.y + (kart->mWaterDepth >> 4);
    velocity.x = ((s64) velocity.x * velocityFactor) >> 12;
    velocity.y = ((s64) velocity.y * velocityFactor) >> 12;
    velocity.z = ((s64) velocity.z * velocityFactor) >> 12;
    effect->field40 = velocity;
}

void AdvanceOtherKartEffect(Unk0201ca6c *effect, s32 a) {
    if (a != 0) {
        return;
    }
    PlaceOtherKartEffect(effect, a);
    effect->field98_24 = effect->field98_24 + 1;
    if (effect->field98_24 >= 2) {
        effect->field98_16 = (effect->field98_16 == 0);
        effect->field98_24 = 0;
    }
}

// Starts two effects for each pair of the other karts; each effect switches between the pair's two karts.
void StartEffectsAtOtherKarts(s32 pairSetIndex) {
    OtherKartEffectKind *effectKind;
    s32 kindIndex;
    KartIndexPair *pair;
    s32 startedCount;
    u32 f;
    s32 fullPairCount;
    s32 i;
    s32 oddCount;
    Unk0201ca6c *effect;

    gOtherKartPairsCopy = gOtherKartPairs[pairSetIndex];
    fullPairCount = gOtherKartFullPairCount;
    i = fullPairCount;
    if (i < 4) {
        oddCount = gOtherKartOddCount;
        do {
            if (i != fullPairCount || oddCount == 0) {
                gOtherKartPairsCopy.mPairs[i].mFirst = -1;
            }
            gOtherKartPairsCopy.mPairs[i].mSecond = -1;
            i++;
        } while (i < 4);
    }
    effectKind = gOtherKartEffectKinds;
    for (kindIndex = 0; kindIndex < 2; kindIndex++) {
        f = (kindIndex != 0) ? 1 : 0;
        startedCount = 0;
        pair = gOtherKartPairsCopy.mPairs;
        do {
            if (pair->mFirst < 0) {
                break;
            }
            effect = ptcm_createFogOffEmitter(effectKind->mEffectId, &rptc_sEmitterPos);
            startedCount++;
            effect->field90 = effectKind->mAdvance;
            effect->field98_0 = pair->mFirst;
            effect->field98_8 = (pair->mSecond < 0) ? 0xff : (u8) pair->mSecond;
            pair++;
            effect->field98_16 = f;
            effect->field98_24 = 0;
            effect->mUnk_94_u = 0;
        } while (startedCount < 4);
        effectKind++;
    }
}

void PlaceOtherKartEffect(Unk0201ca6c *effect, s32 a) {
    Unk0201ca6c_98 *s;
    Kart *kart;
    u32 n;
    u32 f;
    u32 x;
    s32 kartIndex;
    s32 pointX;
    s32 pointY;
    s32 pointZ;

    s = &effect->mUnk_98_b;
    kartIndex = s->field2;
    n = effect->mUnk_94_u;
    kartIndex = (kartIndex == 0) ? s->field0 : s->field1;
    x = s->field1;
    f = 1;
    if (x > 8) {
        if (kartIndex > 8) {
            f = 0;
        }
        kartIndex = s->field0;
    }
    kart = driver_getById(kartIndex);
    pointX = kart->mPointAlongUp.x;
    pointY = kart->mPointAlongUp.y;
    pointZ = kart->mPointAlongUp.z;
    effect->field28.x = (pointX >> 4) + effect->field20->field0->field4.x;
    effect->field28.y = (pointY >> 4) + effect->field20->field0->field4.y;
    effect->field28.z = (pointZ >> 4) + effect->field20->field0->field4.z;
    if (kart->field7C & 0x402000) {
        f = 0;
    }
    effect->field24.field0_3 = (f == 0);
    if (n + 1 >= 0x32) {
        effect->field24.field0_0 = 1;
    }
    effect->mUnk_94_u = n + 1;
}

// Sets the effect speed scale, then starts the effects of two courses and ties them to the camera.
void rptc_initWeather(void) {
    s32 engineScale;
    s32 engineIndex;

    engineIndex = gRaceMultiConfig->mEngineIndex;
    engineScale = 0x1000;
    switch (engineIndex) {
        case 1:
            engineScale = 0xd9a;
            break;
        case 0:
            engineScale = 0xb33;
            break;
    }
    data_0217ae9c = FX_Div(0x1000, ((s64) engineScale * 0x779a + 0x800) >> 12);
    rptc_sWeatherEmitter2 = NULL;
    rptc_sWeatherEmitter1 = NULL;
    switch (gRaceMultiConfig->mCourseId) {
        case 0x25: {
            Unk0201ca6c *effect;

            if (gRaceMultiConfig->mRaceKind == RACE_KIND_NORMAL) {
                effect = ptcm_createEmitter(0x24, &rptc_sEmitterPos);
                rptc_sWeatherEmitter1 = effect;
                effect->field90 = rptc_rainCallback1;
                effect = ptcm_createEmitter(0x27, &rptc_sEmitterPos);
                rptc_sWeatherEmitter2 = effect;
                effect->field90 = rptc_rainCallback2;
            } else if (race_isCamAnimMode() != 0) {
                effect = ptcm_createEmitter(0x3d, &rptc_sEmitterPos);
                rptc_sWeatherEmitter1 = effect;
                effect->field90 = rptc_rainCallback3;
                effect = ptcm_createEmitter(0x3f, &rptc_sEmitterPos);
                rptc_sWeatherEmitter2 = effect;
                effect->field90 = rptc_rainCallback4;
            } else {
                effect = ptcm_createEmitter(0x3c, &rptc_sEmitterPos);
                rptc_sWeatherEmitter1 = effect;
                effect->field90 = rptc_rainCallback3;
                effect = ptcm_createEmitter(0x3f, &rptc_sEmitterPos);
                rptc_sWeatherEmitter2 = effect;
                effect->field90 = rptc_rainCallback4;
            }
            break;
        }
        case 0x10: {
            Unk0201ca6c *effect;

            if (race_isCamAnimMode() != 0) {
                effect = ptcm_createEmitter(0x3e, &rptc_sEmitterPos);
                rptc_sWeatherEmitter1 = effect;
                effect->field90 = rptc_snowCallback1;
            } else if (gRaceMultiConfig->mRaceKind == RACE_KIND_NORMAL) {
                effect = ptcm_createEmitter(0x29, &rptc_sEmitterPos);
                rptc_sWeatherEmitter1 = effect;
                effect->field90 = rptc_snowCallback2;
                effect = ptcm_createEmitter(0x25, &rptc_sEmitterPos);
                rptc_sWeatherEmitter2 = effect;
                effect->field90 = rptc_snowCallback3;
            } else {
                effect = ptcm_createEmitter(0x29, &rptc_sEmitterPos);
                rptc_sWeatherEmitter1 = effect;
                effect->field90 = rptc_snowCallback1;
            }
            break;
        }
    }
}

void rptc_rainCallback2(Unk0201ca6c *effect, s32 a) {
    Vec3 forwardFlat;
    Vec3 effectPos;
    Camera *chaseCamera;

    if (a != 0) {
        return;
    }
    chaseCamera = cam_getPlayerCamera();
    forwardFlat = chaseCamera->mForward;
    forwardFlat.y = 0;
    if ((s64) forwardFlat.z * forwardFlat.z +
            ((s64) forwardFlat.x * forwardFlat.x + (s64) forwardFlat.y * forwardFlat.y) >=
        16) {
        vec_normalize(&forwardFlat, &forwardFlat);
    }
    VEC_MultAdd(0x5800, &forwardFlat, &chaseCamera->mViewPos, &effectPos);
    effectPos.y = 0x1f400;
    effect->field28.x = effectPos.x + effect->field20->field0->field4.x;
    effect->field28.y = effectPos.y + effect->field20->field0->field4.y;
    effect->field28.z = effectPos.z + effect->field20->field0->field4.z;
}

void rptc_rainCallback1(Unk0201ca6c *effect, s32 a) {
    Vec3s16 h;
    Vec3 forwardFlat;
    Vec3 axis;
    Vec3 effectPos;
    MtxFx33 rotation;
    Vec3 rotatedVector;
    Camera *chaseCamera;
    Kart *kart;
    s32 speedRatio;
    s32 k;
    s32 s;
    u16 angle;

    if (a != 0) {
        return;
    }
    chaseCamera = cam_getPlayerCamera();
    kart = driver_getById(gRaceMultiConfig->mEntryIndex);
    forwardFlat = chaseCamera->mForward;
    forwardFlat.y = 0;
    if ((s64) forwardFlat.z * forwardFlat.z +
            ((s64) forwardFlat.x * forwardFlat.x + (s64) forwardFlat.y * forwardFlat.y) >=
        16) {
        vec_normalize(&forwardFlat, &forwardFlat);
    }
    VEC_CrossProduct(&data_02155a08, &forwardFlat, &axis);
    speedRatio = ((s64) kart->mVelocityLength * data_0217ae9c + 0x800) >> 12;
    rotatedVector = data_02165984;
    k = 0;
    if (speedRatio > 0x1000) {
        speedRatio = 0x1000;
    }
    if (kart->field44 & 0x100) {
        speedRatio = speedRatio * 0xffffffff;
        k = data_02165938;
    }
    angle = (s32) (((s64) speedRatio * 0x38e3 + 0x800) >> 12);
    MTX_RotAxis33((MtxFx43 *) &rotation, &axis, FX_SinCosTable_[(angle >> 4) * 2], FX_SinCosTable_[(angle >> 4) * 2 + 1]);
    MTX_MultVec33(&rotatedVector, rotation.field0, &rotatedVector);
    h.x = rotatedVector.x;
    h.y = rotatedVector.y;
    h.z = rotatedVector.z;
    effect->field68 = (s16) ((s32) (((s64) (0x1000 - speedRatio) * 0x800 + 0x800) >> 12) + 0x800);
    effect->field50 = h;
    s = data_02165954 + k;
    VEC_MultAdd(data_02165938 + (s32) (((s64) s * (s64) speedRatio + 0x800) >> 12), &forwardFlat,
                &chaseCamera->mViewPos, &effectPos);
    effectPos.y = driver_getById(gRaceMultiConfig->mEntryIndex)->mPosSource->y >> 4;
    effectPos.y = effectPos.y - (s32) (((s64) data_02165934 * speedRatio + 0x800) >> 12);
    effect->field28.x = effectPos.x + effect->field20->field0->field4.x;
    effect->field28.y = effectPos.y + effect->field20->field0->field4.y;
    effect->field28.z = effectPos.z + effect->field20->field0->field4.z;
}

void rptc_rainCallback4(Unk0201ca6c *effect, s32 a) {
    Vec3 forwardFlat;
    Vec3 effectPos;
    Camera *currentCamera;

    if (a != 0) {
        return;
    }
    currentCamera = race_getCamera();
    forwardFlat = currentCamera->mForward;
    forwardFlat.y = 0;
    if ((s64) forwardFlat.z * forwardFlat.z +
            ((s64) forwardFlat.x * forwardFlat.x + (s64) forwardFlat.y * forwardFlat.y) >=
        16) {
        vec_normalize(&forwardFlat, &forwardFlat);
    }
    VEC_MultAdd(data_02165958, &forwardFlat, &currentCamera->mViewPos, &effectPos);
    effectPos.y = 0x1f400;
    effect->field28.x = effectPos.x + effect->field20->field0->field4.x;
    effect->field28.y = effectPos.y + effect->field20->field0->field4.y;
    effect->field28.z = effectPos.z + effect->field20->field0->field4.z;
}

void rptc_rainCallback3(Unk0201ca6c *effect, s32 a) {
    Vec3s16 h;
    Vec3 forwardFlat;
    Vec3 x;
    Vec3 effectPos;
    Vec3 w;
    Camera *currentCamera;

    if (a != 0) {
        return;
    }
    currentCamera = race_getCamera();
    driver_getById(gRaceMultiConfig->mEntryIndex);
    forwardFlat = currentCamera->mForward;
    w = data_02155a08;
    forwardFlat.y = 0;
    if ((s64) forwardFlat.z * forwardFlat.z +
            ((s64) forwardFlat.x * forwardFlat.x + (s64) forwardFlat.y * forwardFlat.y) >=
        16) {
        vec_normalize(&forwardFlat, &forwardFlat);
    }
    VEC_CrossProduct(&data_02155a08, &forwardFlat, &x);
    w.y = w.y * 0xffffffff;
    h.x = w.x;
    h.y = w.y;
    h.z = w.z;
    effect->field68 = 0x1000;
    effect->field50 = h;
    VEC_MultAdd(data_02165964, &forwardFlat, &currentCamera->mViewPos, &effectPos);
    effectPos.y =
        effectPos.y + (data_02165968 + (s32) (((s64) currentCamera->mForward.y * data_02165960 + 0x800) >> 12));
    effect->field28.x = effectPos.x + effect->field20->field0->field4.x;
    effect->field28.y = effectPos.y + effect->field20->field0->field4.y;
    effect->field28.z = effectPos.z + effect->field20->field0->field4.z;
}

void rptc_snowCallback3(Unk0201ca6c *effect, s32 a) {
    Vec3 forwardFlat;
    Vec3 effectPos;
    Camera *chaseCamera;
    Kart *kart;
    s32 speedRatio;

    if (a != 0) {
        return;
    }
    chaseCamera = cam_getPlayerCamera();
    kart = driver_getById(gRaceMultiConfig->mEntryIndex);
    forwardFlat = chaseCamera->mForward;
    forwardFlat.y = 0;
    if ((s64) forwardFlat.z * forwardFlat.z +
            ((s64) forwardFlat.x * forwardFlat.x + (s64) forwardFlat.y * forwardFlat.y) >=
        16) {
        vec_normalize(&forwardFlat, &forwardFlat);
    }
    VEC_MultAdd(0x5800, &forwardFlat, &chaseCamera->mViewPos, &effectPos);
    effectPos.y = driver_getById(gRaceMultiConfig->mEntryIndex)->mPosSource->y >> 4;
    effect->field28.x = effectPos.x + effect->field20->field0->field4.x;
    effect->field28.y = effectPos.y + effect->field20->field0->field4.y;
    effect->field28.z = effectPos.z + effect->field20->field0->field4.z;
    speedRatio = ((s64) kart->mVelocityLength * data_0217ae9c + 0x800) >> 12;
    if (speedRatio > 0x1000) {
        speedRatio = 0x1000;
    }
    effect->field58 = ((s64) (0x1000 - speedRatio) * 0x400 + 0x800) >> 12;
}

void rptc_snowCallback2(Unk0201ca6c *effect, s32 a) {
    Vec3 forwardFlat;
    Vec3 effectPos;
    Camera *chaseCamera;
    s32 k;
    Kart *kart;
    s32 speedRatio;

    if (a != 0) {
        return;
    }
    chaseCamera = cam_getPlayerCamera();
    kart = driver_getById(gRaceMultiConfig->mEntryIndex);
    forwardFlat = chaseCamera->mForward;
    speedRatio = ((s64) kart->mVelocityLength * data_0217ae9c + 0x800) >> 12;
    k = 0;
    forwardFlat.y = 0;
    if (speedRatio > 0x1000) {
        speedRatio = 0x1000;
    }
    if (kart->field44 & 0x100) {
        k = -0x5800;
    }
    if ((s64) forwardFlat.z * forwardFlat.z +
            ((s64) forwardFlat.x * forwardFlat.x + (s64) forwardFlat.y * forwardFlat.y) >=
        16) {
        vec_normalize(&forwardFlat, &forwardFlat);
    }
    k = k * 3;
    VEC_MultAdd((s32) (((s64) k * (s64) speedRatio + 0x800) >> 12) + 0x5800, &forwardFlat, &chaseCamera->mViewPos,
                &effectPos);
    effectPos.y = driver_getById(gRaceMultiConfig->mEntryIndex)->mPosSource->y >> 4;
    effect->field28.x = effectPos.x + effect->field20->field0->field4.x;
    effect->field28.y = effectPos.y + effect->field20->field0->field4.y;
    effect->field28.z = effectPos.z + effect->field20->field0->field4.z;
    effect->field58 = ((s64) 0x800 * speedRatio + 0x800) >> 12;
}

void rptc_snowCallback1(Unk0201ca6c *effect, s32 a) {
    Vec3 forwardFlat;
    Vec3 effectPos;
    Vec3 extraOffset;
    Camera *currentCamera;

    if (a != 0) {
        return;
    }
    currentCamera = race_getCamera();
    forwardFlat = currentCamera->mForward;
    extraOffset = rptc_sEmitterPos;
    if (rstat_getUncontrollable() != 0) {
        FX_Atan2Idx(currentCamera->mHalfFovPairFirst, currentCamera->mHalfFovPairSecond);
        VEC_Subtract(&currentCamera->mPos, &currentCamera->mPrevPos, &extraOffset);
        extraOffset.x = extraOffset.x >> 4;
        extraOffset.y = extraOffset.y >> 4;
        extraOffset.z = extraOffset.z >> 4;
    }
    forwardFlat.y = 0;
    if ((s64) forwardFlat.z * forwardFlat.z +
            ((s64) forwardFlat.x * forwardFlat.x + (s64) forwardFlat.y * forwardFlat.y) >=
        16) {
        vec_normalize(&forwardFlat, &forwardFlat);
    }
    VEC_MultAdd(data_02165958, &forwardFlat, &currentCamera->mViewPos, &effectPos);
    effectPos.y =
        effectPos.y + (data_0216595c + (s32) (((s64) currentCamera->mForward.y * data_02165940 + 0x800) >> 12));
    VEC_Add(&effectPos, &extraOffset, &effectPos);
    effect->field28.x = effectPos.x + effect->field20->field0->field4.x;
    effect->field28.y = effectPos.y + effect->field20->field0->field4.y;
    effect->field28.z = effectPos.z + effect->field20->field0->field4.z;
    effect->field58 = 0x800;
}

void rptc_2081F30(void) {
    Unk0201ca6c *effect;

    switch (gRaceMultiConfig->mCourseId) {
        case COURSE_ID_OLD_LUIGI_AGB:
            if (rptc_sWeatherEmitter1 != NULL) {
                ptcm_killEmitterDirect(rptc_sWeatherEmitter1);
                effect = ptcm_createEmitter(0x3c, &rptc_sEmitterPos);
                rptc_sWeatherEmitter1 = effect;
                effect->field90 = rptc_rainCallback3;
            }
            if (rptc_sWeatherEmitter2 == NULL) {
                return;
            }
            ptcm_killEmitterDirect(rptc_sWeatherEmitter2);
            effect = ptcm_createEmitter(0x3f, &rptc_sEmitterPos);
            rptc_sWeatherEmitter2 = effect;
            effect->field90 = rptc_rainCallback4;
            break;
        case COURSE_ID_OLD_FRAPPE_64:
            if (rptc_sWeatherEmitter1 != NULL) {
                rptc_sWeatherEmitter1->field90 = rptc_snowCallback1;
            }
            if (rptc_sWeatherEmitter2 == NULL) {
                return;
            }
            ptcm_killEmitterDirect(rptc_sWeatherEmitter2);
            rptc_sWeatherEmitter2 = NULL;
            break;
    }
}

void rptc_2081F10(KartFollowEffect *effect, u32 kartIndex, u32 countLimit) {
    effect->mCount = 0x0u;
    effect->mCountLimit = countLimit;
    effect->mKartIndex = kartIndex;
    effect->field90 = AdvanceKartFollowEffect;
}

void AdvanceKartFollowEffect(Unk0201ca6c *effect, s32 a) {
    u8 kartIndex;
    u8 stepCount;
    Vec3 *kartPos;
    Kart *kart;
    s32 posX;
    s32 posY;
    s32 posZ;

    if (a != 0) {
        return;
    }
    kartIndex = effect->field98_24;
    stepCount = effect->field98_16;
    kart = driver_getById(kartIndex);
    kartPos = kart->mPosSource;
    posX = kartPos->x;
    posY = kartPos->y;
    posZ = kartPos->z;
    effect->field28.x = (posX >> 4) + effect->field20->field0->field4.x;
    effect->field28.y = (posY >> 4) + effect->field20->field0->field4.y;
    effect->field28.z = (posZ >> 4) + effect->field20->field0->field4.z;
    if (stepCount >= effect->field98_8) {
        if (stepCount == effect->field98_8) {
            effect->field24.field0_0 = 1;
        }
    } else {
        effect->field98_16 = stepCount + 1;
    }
}

void rptc_2081E3C(KartFollowEffect *effect, u32 kartIndex, u32 countLimit) {
    effect->mCount = 0x0u;
    effect->mCountLimit = countLimit;
    effect->mKartIndex = kartIndex;
    effect->field90 = AdvanceKartFollowEffectWithVelocity;
}

void AdvanceKartFollowEffectWithVelocity(Unk0201ca6c *effect, s32 a) {
    u8 kartIndex;
    u8 stepCount;
    Vec3 *kartPos;
    Kart *kart;
    s32 posX;
    s32 posY;
    s32 posZ;

    if (a != 0) {
        return;
    }
    kartIndex = effect->field98_24;
    stepCount = effect->field98_16;
    kart = driver_getById(kartIndex);
    kartPos = kart->mPosSource;
    posX = kartPos->x;
    posY = kartPos->y;
    posZ = kartPos->z;
    effect->field28.x = (posX >> 4) + effect->field20->field0->field4.x;
    effect->field28.y = (posY >> 4) + effect->field20->field0->field4.y;
    effect->field28.z = (posZ >> 4) + effect->field20->field0->field4.z;
    effect->field40 = kart->mEffectVelocity;
    if (stepCount >= effect->field98_8) {
        if (stepCount == effect->field98_8) {
            effect->field24.field0_0 = 1;
        }
    } else {
        effect->field98_16 = stepCount + 1;
    }
}

void PlaceKartAheadEffect(Unk0201ca6c *effect, Kart *kart, void *a) {
    u32 r;
    u32 f;

    if (a == NULL) {
        PlaceEffectAheadAndUpOfKart(effect, kart, 0x733, 0xb33);
        effect->field5C = (s16) (((s64) kart->mScale.z * 0xb33 + 0x800) >> 12);
    } else {
        r = 1;
        PlaceEffectAheadAndUpOfKart(effect, kart, 0x99a, 0xe66);
        effect->field6C = (s16) kart->mScale.z;
        f = kart->field7C;
        if (!(f & 1)) {
            if (f & 0x402000) {
                r = 0;
            }
        }
        effect->field24.field0_3 = (r == 0);
    }
}

// Puts the effect ahead of the kart by b and above it by a, pointing backward.
void PlaceEffectAheadAndUpOfKart(Unk0201ca6c *effect, Kart *kart, s32 upDistance, s32 aheadDistance) {
    Vec3 position;
    Vec3 w;
    Vec3s16 backwardDirection;
    Vec3 *kartPos = kart->mPosSource;

    position.x = kartPos->x >> 4;
    position.y = kartPos->y >> 4;
    position.z = kartPos->z >> 4;
    VEC_MultAdd(((s64) kart->mScale.z * aheadDistance + 0x800) >> 12, &kart->field138, &position, &position);
    VEC_MultAdd(((s64) kart->mScale.y * upDistance + 0x800) >> 12, &kart->field12C, &position, &position);
    effect->field28.x = position.x + effect->field20->field0->field4.x;
    effect->field28.y = position.y + effect->field20->field0->field4.y;
    effect->field28.z = position.z + effect->field20->field0->field4.z;
    driver_getShadowZDirection(kart, &w);
    w.x = -w.x;
    w.y = -w.y;
    w.z = -w.z;
    backwardDirection.x = w.x;
    backwardDirection.y = w.y;
    backwardDirection.z = w.z;
    effect->field50 = backwardDirection;
}

void AdvanceKartAheadEffect(Unk0201ca6c *effect, s32 a) {
    if (a != 0) {
        return;
    }
    PlaceKartAheadEffect(effect, driver_getById(effect->field98_24), effect->field94);
}

void AdvanceKartAheadEffectWithLimit(Unk0201ca6c *effect, s32 a) {
    u8 kartIndex;
    u8 stepCount;

    if (a != 0) {
        return;
    }
    kartIndex = effect->field98_24;
    stepCount = effect->field98_16;
    PlaceKartAheadEffect(effect, driver_getById(kartIndex), effect->field94);
    if (stepCount >= effect->field98_8) {
        if (stepCount == effect->field98_8) {
            effect->field24.field0_0 = 1;
        }
    } else {
        effect->field98_16 = stepCount + 1;
    }
}

void rptc_startRainbowEffect(s32 kartIndex) {
    KartStarEffects *starEffects = &rptc_sRainbowEffectEmitters[kartIndex];
    u16 i;

    i = 0;
    do {
        if (starEffects->mEffects[i] != NULL) {
            ptcm_killEmitterDirect(starEffects->mEffects[i]);
        }
        starEffects->mEffects[i] = ptcm_createEmitter(rptc_sRainbowEffectEmitterIds[i], &driver_getById(kartIndex)->mPointAlongUp);
        i = i + 1;
    } while (i < 3);
}

static inline s32 func_0208181c_inline(s32 a, s32 b) {
    return ((s64) a * b + 0x800) >> 12;
}

void rptc_updateRainbowEffect(s32 kartIndex) {
    KartStarEffects *starEffects = &rptc_sRainbowEffectEmitters[kartIndex];
    u16 i;
    s16 y;
    s16 x;
    Kart *kart;
    Vec3 velocity;
    Vec3 effectPos;

    kart = driver_getById(kartIndex);
    y = func_0208181c_inline(
        data_0216593c + func_0208181c_inline(kart->mVelocityLengthRatio, data_02165950 - data_0216593c), data_02165948);
    x = func_0208181c_inline(
        data_02165944 + func_0208181c_inline(kart->mVelocityLengthRatio, data_0216594c - data_02165944), data_02165948);
    i = 0;
    do {
        if (starEffects->mEffects[i] != NULL) {
            VEC_MultAdd(((s64) kart->mScale.y * data_02155854[kart->mKartModelsEntry->mCharacterIndex] + 0x800) >> 12,
                        &kart->field12C, &kart->mPos, &effectPos);
            ptcm_setEmitterPosition(starEffects->mEffects[i], &effectPos);
            velocity.x = ((s64) kart->mEffectVelocity.x * 0xc00) >> 12;
            velocity.y = ((s64) kart->mEffectVelocity.y * 0xc00) >> 12;
            velocity.z = ((s64) kart->mEffectVelocity.z * 0xc00) >> 12;
            starEffects->mEffects[i]->field40 = velocity;
            starEffects->mEffects[i]->field68 = y;
            starEffects->mEffects[i]->field64 = x;
            starEffects->mEffects[i]->field5C = (s16) (((s64) kart->mScale.z * 0x614 + 0x800) >> 12);
        }
        i = i + 1;
    } while (i < 3);
}

void rptc_stopRainbowEffect(s32 kartIndex) {
    KartStarEffects *starEffects = &rptc_sRainbowEffectEmitters[kartIndex];
    u16 i;

    i = 0;
    do {
        if (starEffects->mEffects[i] != NULL) {
            starEffects->mEffects[i]->field24.field0_0 = 1;
            starEffects->mEffects[i] = NULL;
        }
        i = i + 1;
    } while (i < 3);
}

void rptc_stopRainbowEffectDirect(s32 kartIndex) {
    KartStarEffects *starEffects = &rptc_sRainbowEffectEmitters[kartIndex];
    u16 i;

    i = 0;
    do {
        if (starEffects->mEffects[i] != NULL) {
            ptcm_killEmitterDirect(starEffects->mEffects[i]);
            starEffects->mEffects[i] = NULL;
        }
        i = i + 1;
    } while (i < 3);
}

void rptc_startKillerEffect(s32 kartIndex) {
    KartEffects *kartEffects = &rptc_sDriverEffects[kartIndex];

    if (kartEffects->mKillerEffect != NULL) {
        ptcm_killEmitterDirect(kartEffects->mKillerEffect);
    }
    kartEffects->mKillerEffect = ptcm_createEmitter(0x63, &rptc_sEmitterPos);
}

// Moves the Killer effect to point b and gives it the kart's velocity.
void rptc_updateBulletBillEffect(s32 kartIndex, Vec3 *position) {
    KartEffects *kartEffects = &rptc_sDriverEffects[kartIndex];
    Unk0201ca6c *effect = kartEffects->mKillerEffect;
    Kart *kart;
    Vec3 *kartVelocity;
    Vec3 velocity;

    if (effect == NULL) {
        return;
    }
    effect->field28.x = position->x + effect->field20->field0->field4.x;
    effect->field28.y = position->y + effect->field20->field0->field4.y;
    effect->field28.z = position->z + effect->field20->field0->field4.z;
    kart = driver_getById(kartIndex);
    kartVelocity = &kart->mEffectVelocity;
    velocity.x = ((s64) kartVelocity->x * 0xe66) >> 12;
    velocity.y = ((s64) kartVelocity->y * 0xe66) >> 12;
    velocity.z = ((s64) kartVelocity->z * 0xe66) >> 12;
    kartEffects->mKillerEffect->field40 = velocity;
}
