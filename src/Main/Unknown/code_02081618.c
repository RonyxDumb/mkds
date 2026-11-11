#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02066ac0.h"
#include "Main/Unknown/code_02081000.h"

#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/unk_02165000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "code_0201c528.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02102674.h"
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

KartEffects *GetKartEffects(int kartIndex) {
    return &gKartEffects[kartIndex];
}

void InitKartEffects(u32 kartCount) {
    KartEffects *kartEffects;
    u16 i;
    u16 j;

    i = 0;
    gKartEffects = HeapAlloc(GetHeap(GetCurrentHeapCall()), kartCount * 0x58);
    gKartEffectsCount = kartCount;
    for (; i < kartCount; i++) {
        kartEffects = &gKartEffects[i];
        kartEffects->mCurrentEffect = NULL;
        kartEffects->mContactEffect = NULL;
        kartEffects->mKillerEffect = NULL;
        kartEffects->mSpinFollowEffect = NULL;
        kartEffects->mCurrentEffectId = -1;
        kartEffects->mWaterEffect0 = kartEffects->mWaterEffect1 = 0;
        for (j = 0; j < 2; j++) {
            kartEffects->mEffectPairs[j].mEffect0 = kartEffects->mEffectPairs[j].mEffect1 = 0;
            kartEffects->mEffectIds[j] = -1;
        }
    }
    gKartBoostCameraEffect = NULL;
}

void ComputeKartSidePoints(Kart *kart) {
    u16 i;
    KartEffects *kartEffects;
    Vec3 scaledPoint;
    Vec3 sideDirection;
    Vec3 modelPoint;

    kartEffects = &gKartEffects[kart->mIndex];
    kart->mUnk_174 = *kart->mPosSource;
    for (i = 0; i < 2; i++) {
        modelPoint = kart->mKartModelsEntry->mKartOffsetData->mTireOffsets[i + 2];
        modelPoint.y = 0;
        modelPoint.x = modelPoint.x + gKartSideOffsetsX[i];
        scaledPoint.x = MUL_FIXED12_NO_ROUND(modelPoint.x, kart->mScale.x);
        scaledPoint.y = MUL_FIXED12_NO_ROUND(modelPoint.y, kart->mScale.y);
        scaledPoint.z = MUL_FIXED12_NO_ROUND(modelPoint.z, kart->mScale.z);
        MTX_MultVec43(&scaledPoint, &kart->mUnk_150_m, &kartEffects->mSidePositions[i]);
        kartEffects->mSidePositions[i].x = kartEffects->mSidePositions[i].x >> 4;
        kartEffects->mSidePositions[i].y = kartEffects->mSidePositions[i].y >> 4;
        kartEffects->mSidePositions[i].z = kartEffects->mSidePositions[i].z >> 4;
        MTX_MultVec33(&gKartSideDirectionVectors[i], &kart->mUnk_150_m.mAxes, &sideDirection);
        kartEffects->mSideDirections[i].x = sideDirection.x;
        kartEffects->mSideDirections[i].y = sideDirection.y;
        kartEffects->mSideDirections[i].z = sideDirection.z;
    }
}

void SurfaceEffectStopKartCurrentEffects(Kart *kart) {
    KartEffects *kartEffects;

    kartEffects = &gKartEffects[kart->mIndex];
    if (kartEffects->mCurrentEffect != NULL) {
        kartEffects->mCurrentEffect->mUnk_98_8 = 1;
        kartEffects->mCurrentEffect = NULL;
        kartEffects->mCurrentEffectId = -1;
    }
    StopKartEffectPairs(kart, 0);
}

void ApplyKartCurrentEffectRow0(Kart *kart) {
    gKartSurfaceEffectRows[0].mStartEffects(
        &gKartSurfaceEffectRows[0].mEffectIdSets[gKartEffectIdSetIndex[kart->mIndex]],
        gKartSurfaceEffectRows[0].mVelocityFactorIndex, kart);
    StopKartEffectPairs(kart, 0);
}

void ApplyKartCurrentEffectRow1(Kart *kart) {
    gKartSurfaceEffectRow1.mStartEffects(&gKartSurfaceEffectRow1.mEffectIdSets[gKartEffectIdSetIndex[kart->mIndex]],
                                         gKartSurfaceEffectRow1.mVelocityFactorIndex, kart);
    StopKartEffectPairs(kart, 0);
}

void ApplyKartSideEffectsRow2(Kart *kart) {
    KartEffects *kartEffects;

    kartEffects = &gKartEffects[kart->mIndex];
    if (kartEffects->mCurrentEffect != NULL) {
        kartEffects->mCurrentEffect->mUnk_98_8 = 1;
        kartEffects->mCurrentEffect = NULL;
        kartEffects->mCurrentEffectId = -1;
    }
    ApplyKartSurfaceEffectRow(2, kart);
}

void ApplyKartSideEffectsRow3(Kart *kart) {
    KartEffects *kartEffects;

    kartEffects = &gKartEffects[kart->mIndex];
    if (kartEffects->mCurrentEffect != NULL) {
        kartEffects->mCurrentEffect->mUnk_98_8 = 1;
        kartEffects->mCurrentEffect = NULL;
        kartEffects->mCurrentEffectId = -1;
    }
    gKartSurfaceEffectRow3.mStartEffects(&gKartSurfaceEffectRow3.mEffectIdSets[gKartEffectIdSetIndex[kart->mIndex]],
                                         gKartSurfaceEffectRow3.mVelocityFactorIndex, kart);
}

void ApplyKartSideEffectsRow4(Kart *kart) {
    KartEffects *kartEffects;

    kartEffects = &gKartEffects[kart->mIndex];
    if (kartEffects->mCurrentEffect != NULL) {
        kartEffects->mCurrentEffect->mUnk_98_8 = 1;
        kartEffects->mCurrentEffect = NULL;
        kartEffects->mCurrentEffectId = -1;
    }
    gKartSurfaceEffectRow4.mStartEffects(&gKartSurfaceEffectRow4.mEffectIdSets[gKartEffectIdSetIndex[kart->mIndex]],
                                         gKartSurfaceEffectRow4.mVelocityFactorIndex, kart);
}

void ApplyKartSideEffectsRow5(Kart *kart) {
    KartEffects *kartEffects;

    kartEffects = &gKartEffects[kart->mIndex];
    if (kartEffects->mCurrentEffect != NULL) {
        kartEffects->mCurrentEffect->mUnk_98_8 = 1;
        kartEffects->mCurrentEffect = NULL;
        kartEffects->mCurrentEffectId = -1;
    }
    gKartSurfaceEffectRow5.mStartEffects(&gKartSurfaceEffectRow5.mEffectIdSets[gKartEffectIdSetIndex[kart->mIndex]],
                                         gKartSurfaceEffectRow5.mVelocityFactorIndex, kart);
}

void ApplyKartSideEffectsRow6(Kart *kart) {
    KartEffects *kartEffects;

    kartEffects = &gKartEffects[kart->mIndex];
    if (kartEffects->mCurrentEffect != NULL) {
        kartEffects->mCurrentEffect->mUnk_98_8 = 1;
        kartEffects->mCurrentEffect = NULL;
        kartEffects->mCurrentEffectId = -1;
    }
    gKartSurfaceEffectRow6.mStartEffects(&gKartSurfaceEffectRow6.mEffectIdSets[gKartEffectIdSetIndex[kart->mIndex]],
                                         gKartSurfaceEffectRow6.mVelocityFactorIndex, kart);
}

void ApplyKartCurrentEffectRow7(Kart *kart) {
    gKartSurfaceEffectRow7.mStartEffects(&gKartSurfaceEffectRow7.mEffectIdSets[gKartEffectIdSetIndex[kart->mIndex]],
                                         gKartSurfaceEffectRow7.mVelocityFactorIndex, kart);
    StopKartEffectPairs(kart, 0);
}

// Starts the boost effect in front of the chase camera; the previous one is told to end.
void StartKartBoostCameraEffect(u32 effectIdIndex, Kart *kart) {
    Unk0201ca6c *effect;

    if (GetCurrentCameraKind() != 0) {
        return;
    }
    GetChaseCamera();
    if (gKartBoostCameraEffect != NULL) {
        gKartBoostCameraEffect->mUnk_24.mUnk_00_0 = 1;
    }
    effect = StartEffect(gKartBoostCameraEffectIds[effectIdIndex], &data_02155a14);
    effect->mUnk_98 = 0;
    effect->mUnk_94 = kart;
    effect->mUnk_90 = AdvanceKartBoostCameraEffect;
    gKartBoostCameraEffect = effect;
}

// Runs entry a of the effect table while the kart flag is set, otherwise ends the kart effects.
void ApplyKartSurfaceEffect(s32 functionIndex, Kart *kart) {
    KartEffects *kartEffects;

    if (kart->mUnk_4c & KART_4C_NEAR_PLAYER_RANK) {
        gKartSurfaceEffectFunctions[functionIndex](kart);
        return;
    }
    kartEffects = &gKartEffects[kart->mIndex];
    if (kartEffects->mCurrentEffect != NULL) {
        kartEffects->mCurrentEffect->mUnk_98_8 = 1;
        kartEffects->mCurrentEffect = NULL;
        kartEffects->mCurrentEffectId = -1;
    }
    StopKartEffectPairs(kart, 0);
    kartEffects = &gKartEffects[kart->mIndex];
    if (kartEffects->mWaterEffect0 != 0) {
        kartEffects->mWaterEffect0->mUnk_98_8 = 1;
        kartEffects->mWaterEffect0 = 0;
    }
    if (kartEffects->mWaterEffect1 != 0) {
        kartEffects->mWaterEffect1->mUnk_98_8 = 1;
        kartEffects->mWaterEffect1 = 0;
    }
}

// Starts the water effects while the kart flag is set, otherwise ends them.
void ApplyKartWaterEffects(Kart *kart) {
    KartEffects *kartEffects;

    if (kart->mUnk_4c & KART_4C_NEAR_PLAYER_RANK) {
        StartKartWaterEffects(&gKartSurfaceEffectRow3.mEffectIdSets[gKartEffectIdSetIndex[kart->mIndex]], 1, kart);
        return;
    }
    kartEffects = &gKartEffects[kart->mIndex];
    if (kartEffects->mWaterEffect0 != 0) {
        kartEffects->mWaterEffect0->mUnk_98_8 = 1;
        kartEffects->mWaterEffect0 = 0;
    }
    if (kartEffects->mWaterEffect1 != 0) {
        kartEffects->mWaterEffect1->mUnk_98_8 = 1;
        kartEffects->mWaterEffect1 = 0;
    }
}

void ApplyKartSurfaceEffectRow(s32 rowIndex, Kart *kart) {
    KartSurfaceEffectRow *row;
    KartEffectIdSet *effectIdSet;
    KartEffects *kartEffects;
    u16 i;
    u16 j;

    row = &gKartSurfaceEffectRows[rowIndex];
    effectIdSet = &row->mEffectIdSets[gKartEffectIdSetIndex[kart->mIndex]];
    if (row->mStartEffects(effectIdSet, row->mVelocityFactorIndex, kart) == 0) {
        return;
    }
    kartEffects = &gKartEffects[kart->mIndex];
    for (i = 0; i < effectIdSet->mCount; i++) {
        for (j = 0; j < 2; j++) {
            if (kartEffects->mEffectPairs[i].mUnk_00_a[j] != 0) {
                kartEffects->mEffectPairs[i].mUnk_00_a[j]->mUnk_72 = gKartEffectColor;
            }
        }
    }
}

BOOL StartKartCurrentEffect(KartEffectIdSet *effectIdSet, s32 velocityFactorIndex, Kart *kart) {
    KartEffects *kartEffects;
    Unk0201ca6c *effect;

    kartEffects = &gKartEffects[kart->mIndex];
    if (effectIdSet->mEffectIds[0] == kartEffects->mCurrentEffectId) {
        return FALSE;
    }
    if (kartEffects->mCurrentEffect != NULL) {
        kartEffects->mCurrentEffect->mUnk_98_8 = 1;
    }
    effect = StartEffect(effectIdSet->mEffectIds[0], &data_02155a14);
    kartEffects->mCurrentEffect = effect;
    kartEffects->mCurrentEffectId = effectIdSet->mEffectIds[0];
    effect->mUnk_94 = kart;
    effect->mUnk_98_0 = velocityFactorIndex;
    effect->mUnk_90 = AdvanceKartCurrentEffect;
    return TRUE;
}

// Starts one effect per side of the kart for each id that is not running yet.
s32 StartKartSideEffects(KartEffectIdSet *effectIdSet, s32 unusedVelocityFactorIndex, Kart *kart) {
    KartEffects *kartEffects;
    Unk0201ca6c *effect;
    s32 started;
    u16 i;
    u16 j;

    started = i = 0;
    for (; i < effectIdSet->mCount; i++) {
        kartEffects = &gKartEffects[kart->mIndex];
        j = 0;
        if (effectIdSet->mEffectIds[i] != kartEffects->mEffectIds[i]) {
            if (kartEffects->mEffectPairs[i].mEffect0 != 0) {
                kartEffects->mEffectPairs[i].mEffect0->mUnk_98_8 = 1;
            }
            if (kartEffects->mEffectPairs[i].mEffect1 != 0) {
                kartEffects->mEffectPairs[i].mEffect1->mUnk_98_8 = 1;
            }
            kartEffects->mEffectIds[i] = effectIdSet->mEffectIds[i];
            do {
                effect = StartEffect(kartEffects->mEffectIds[i], &data_02155a14);
                gKartEffects[kart->mIndex].mEffectPairs[i].mUnk_00_a[j] = effect;
                effect->mUnk_94 = kart;
                effect->mUnk_98_24 = j;
                j++;
                effect->mUnk_90 = AdvanceKartSideEffect;
            } while (j < 2);
            started = 1;
        }
    }
    return started;
}

s32 StartKartSideEffectsWithVelocity(KartEffectIdSet *effectIdSet, s32 velocityFactorIndex, Kart *kart) {
    KartEffects *kartEffects;
    Unk0201ca6c *effect;
    s32 started;
    u16 i;
    u16 j;

    started = i = 0;
    for (; i < effectIdSet->mCount; i++) {
        kartEffects = &gKartEffects[kart->mIndex];
        j = 0;
        if (effectIdSet->mEffectIds[i] != kartEffects->mEffectIds[i]) {
            if (kartEffects->mEffectPairs[i].mEffect0 != 0) {
                kartEffects->mEffectPairs[i].mEffect0->mUnk_98_8 = 1;
            }
            if (kartEffects->mEffectPairs[i].mEffect1 != 0) {
                kartEffects->mEffectPairs[i].mEffect1->mUnk_98_8 = 1;
            }
            kartEffects->mEffectIds[i] = effectIdSet->mEffectIds[i];
            do {
                effect = StartEffect(kartEffects->mEffectIds[i], &data_02155a14);
                gKartEffects[kart->mIndex].mEffectPairs[i].mUnk_00_a[j] = effect;
                effect->mUnk_94 = kart;
                effect->mUnk_98_24 = j;
                j++;
                effect->mUnk_98_0 = velocityFactorIndex;
                effect->mUnk_90 = AdvanceKartSideEffectWithVelocity;
            } while (j < 2);
            started = 1;
        }
    }
    return started;
}

BOOL StartKartWaterEffects(KartEffectIdSet *effectIdSet, s32 velocityFactorIndex, Kart *kart) {
    KartEffects *kartEffects;
    Unk0201ca6c *effect;
    u16 i;

    kartEffects = &gKartEffects[kart->mIndex];
    if (kartEffects->mWaterEffect0 != 0 || kartEffects->mWaterEffect1 != 0) {
        return FALSE;
    }
    for (i = 0; i < 2; i++) {
        effect = StartEffect(effectIdSet->mEffectIds[0], &data_02155a14);
        gKartEffects[kart->mIndex].mUnk_20_a[i] = effect;
        effect->mUnk_94 = kart;
        effect->mUnk_98_24 = i;
        effect->mUnk_98_0 = velocityFactorIndex;
        effect->mUnk_90 = AdvanceKartWaterEffect;
    }
    return TRUE;
}

void StopKartCurrentEffects(Kart *kart) {
    KartEffects *kartEffects;

    kartEffects = &gKartEffects[kart->mIndex];
    if (kartEffects->mCurrentEffect != NULL) {
        kartEffects->mCurrentEffect->mUnk_98_8 = 1;
        kartEffects->mCurrentEffect = NULL;
        kartEffects->mCurrentEffectId = -1;
    }
    StopKartEffectPairs(kart, 0);
}

void StopKartEffectPairs(Kart *kart, s32 deleteAtOnce) {
    u16 i;
    KartEffects *kartEffects;

    kartEffects = &gKartEffects[kart->mIndex];
    for (i = 0; i < 2; i++) {
        if (kartEffects->mEffectPairs[i].mEffect0 != 0 || kartEffects->mEffectPairs[i].mEffect1 != 0) {
            if (deleteAtOnce == 0) {
                kartEffects->mEffectPairs[i].mEffect0->mUnk_98_8 = 1;
                kartEffects->mEffectPairs[i].mEffect1->mUnk_98_8 = 1;
            } else {
                DeleteEffect(kartEffects->mEffectPairs[i].mEffect0);
                DeleteEffect(kartEffects->mEffectPairs[i].mEffect1);
            }
            kartEffects->mEffectPairs[i].mEffect0 = kartEffects->mEffectPairs[i].mEffect1 = 0;
            kartEffects->mEffectIds[i] = -1;
        }
    }
}

void StopKartWaterEffects(Kart *kart) {
    KartEffects *kartEffects;

    kartEffects = &gKartEffects[kart->mIndex];
    if (kartEffects->mWaterEffect0 != 0) {
        kartEffects->mWaterEffect0->mUnk_98_8 = 1;
        kartEffects->mWaterEffect0 = 0;
    }
    if (kartEffects->mWaterEffect1 != 0) {
        kartEffects->mWaterEffect1->mUnk_98_8 = 1;
        kartEffects->mWaterEffect1 = 0;
    }
}

// Deletes the current, side and water effects of the kart at once.
void ReleaseKartSurfaceEffects(Kart *kart) {
    KartEffects *kartEffects;

    kartEffects = &gKartEffects[kart->mIndex];
    if (kartEffects->mCurrentEffect != NULL) {
        DeleteEffect(kartEffects->mCurrentEffect);
        kartEffects->mCurrentEffect = NULL;
        kartEffects->mCurrentEffectId = -1;
    }
    StopKartEffectPairs(kart, 1);
    kartEffects = &gKartEffects[kart->mIndex];
    if (kartEffects->mWaterEffect0 != 0) {
        DeleteEffect(kartEffects->mWaterEffect0);
        kartEffects->mWaterEffect0 = 0;
    }
    if (kartEffects->mWaterEffect1 == 0) {
        return;
    }
    DeleteEffect(kartEffects->mWaterEffect1);
    kartEffects->mWaterEffect1 = 0;
}

void AdvanceKartBoostCameraEffect(Unk0201ca6c *effect, s32 a) {
    Vec3s16 backwardDirection;
    Vec3 viewPos;
    Vec3 forwardOffset;
    Vec3 effectPos;
    Camera *chaseCamera;
    Kart *kart;

    if (a != 0) {
        return;
    }
    chaseCamera = GetChaseCamera();
    kart = effect->mUnk_94;
    if (GetCurrentCameraKind() != 0 ||
        (effect->mUnk_24.mUnk_00_1 != 0 && (effect->mUnk_98 = effect->mUnk_98 + 1, effect->mUnk_98 > 5))) {
        effect->mUnk_24.mUnk_00_0 = 1;
        gKartBoostCameraEffect = NULL;
        return;
    }
    if (!(kart->mUnk_48 & KART_48_BOOST)) {
        effect->mUnk_24.mUnk_00_1 = 1;
    }
    viewPos = chaseCamera->mViewPos;
    forwardOffset.x = MUL_FIXED12_NO_ROUND(chaseCamera->mForward.x, 0x5000);
    forwardOffset.y = MUL_FIXED12_NO_ROUND(chaseCamera->mForward.y, 0x5000);
    forwardOffset.z = MUL_FIXED12_NO_ROUND(chaseCamera->mForward.z, 0x5000);
    VEC_Add(&forwardOffset, &viewPos, &effectPos);
    effect->mUnk_28.x = effectPos.x + effect->mUnk_20->mUnk_00->mUnk_04.x;
    effect->mUnk_28.y = effectPos.y + effect->mUnk_20->mUnk_00->mUnk_04.y;
    effect->mUnk_28.z = effectPos.z + effect->mUnk_20->mUnk_00->mUnk_04.z;
    backwardDirection.x = -chaseCamera->mForward.x;
    backwardDirection.y = -chaseCamera->mForward.y;
    backwardDirection.z = -chaseCamera->mForward.z;
    effect->mUnk_50 = backwardDirection;
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
    u32 stopsEmission;

    if (a != 0) {
        return;
    }
    kart = effect->mUnk_94;
    velocity = kart->mEffectVelocity;
    velocityFactor = gKartEffectVelocityFactors[effect->mUnk_98_b.mUnk_00];
    stepCount = effect->mUnk_98_b.mUnk_02;
    counting = effect->mUnk_98_b.mUnk_01;
    stopsEmission = 1;
    if (IsKartTurnEffectsActive(kart) == 0) {
        if (kart->mVelocityLength >= 0x119a) {
            stopsEmission = 0;
        }
    }
    effect->mUnk_24.mUnk_00_1 = (stopsEmission != 0);
    s = &kart->mUnk_138;
    offsetBehind.x = MUL_FIXED12_NO_ROUND(s->x, -0x5000);
    offsetBehind.y = MUL_FIXED12_NO_ROUND(s->y, -0x5000);
    offsetBehind.z = MUL_FIXED12_NO_ROUND(s->z, -0x5000);
    if (counting != 0) {
        stepCount = (u8) (stepCount + 1);
        if (stepCount == 10) {
            effect->mUnk_24.mUnk_00_0 = 1;
        }
    }
    effect->mUnk_98_b.mUnk_02 = stepCount;
    VEC_Add(kart->mPosSource, &offsetBehind, &effectPos);
    effectPos.x = effectPos.x >> 4;
    effectPos.y = effectPos.y >> 4;
    effectPos.z = effectPos.z >> 4;
    velocity.x = MUL_FIXED12_NO_ROUND(velocity.x, velocityFactor);
    velocity.y = MUL_FIXED12_NO_ROUND(velocity.y, velocityFactor);
    velocity.z = MUL_FIXED12_NO_ROUND(velocity.z, velocityFactor);
    effect->mUnk_28.x = effectPos.x + effect->mUnk_20->mUnk_00->mUnk_04.x;
    effect->mUnk_28.y = effectPos.y + effect->mUnk_20->mUnk_00->mUnk_04.y;
    effect->mUnk_28.z = effectPos.z + effect->mUnk_20->mUnk_00->mUnk_04.z;
    effect->mUnk_40 = velocity;
}

void AdvanceKartSideEffect(Unk0201ca6c *effect, s32 a) {
    s32 sideCoordinate;
    Kart *kart;
    u32 stepCount;
    KartEffects *kartEffects;
    u32 counting;
    u32 sideIndex;
    u32 stopsEmission;

    if (a != 0) {
        return;
    }
    kart = effect->mUnk_94;
    kartEffects = &gKartEffects[kart->mIndex];
    stepCount = effect->mUnk_98_b.mUnk_02;
    counting = effect->mUnk_98_b.mUnk_01;
    sideIndex = effect->mUnk_98_b.mUnk_03;
    stopsEmission = 1;
    if (IsKartTurnEffectsActive(kart) == 0) {
        if (kart->mVelocityLength >= 0x119a) {
            stopsEmission = 0;
        }
    }
    effect->mUnk_24.mUnk_00_1 = (stopsEmission != 0);
    if (counting != 0) {
        stepCount = (u8) (stepCount + 1);
        if (stepCount == 10) {
            effect->mUnk_24.mUnk_00_0 = 1;
        }
    }
    effect->mUnk_98_b.mUnk_02 = stepCount;
    effect->mUnk_50 = kartEffects->mSideDirections[sideIndex];
    sideCoordinate = kartEffects->mSidePositions[sideIndex].x;
    effect->mUnk_28.x = sideCoordinate + effect->mUnk_20->mUnk_00->mUnk_04.x;
    sideCoordinate = kartEffects->mSidePositions[sideIndex].y;
    effect->mUnk_28.y = sideCoordinate + effect->mUnk_20->mUnk_00->mUnk_04.y;
    sideCoordinate = kartEffects->mSidePositions[sideIndex].z;
    effect->mUnk_28.z = sideCoordinate + effect->mUnk_20->mUnk_00->mUnk_04.z;
}

void AdvanceKartSideEffectWithVelocity(Unk0201ca6c *effect, s32 a) {
    s32 sideCoordinate;
    Vec3 velocity;
    Kart *kart;
    u32 stepCount;
    KartEffects *kartEffects;
    u32 counting;
    u32 sideIndex;
    s32 velocityFactor;
    u32 stopsEmission;

    if (a != 0) {
        return;
    }
    kart = effect->mUnk_94;
    kartEffects = &gKartEffects[kart->mIndex];
    velocity = kart->mEffectVelocity;
    stepCount = effect->mUnk_98_b.mUnk_02;
    counting = effect->mUnk_98_b.mUnk_01;
    sideIndex = effect->mUnk_98_b.mUnk_03;
    velocityFactor = gKartEffectVelocityFactors[effect->mUnk_98_b.mUnk_00];
    stopsEmission = 1;
    if (IsKartTurnEffectsActive(kart) == 0) {
        if (kart->mVelocityLength >= 0x119a) {
            stopsEmission = 0;
        }
    }
    effect->mUnk_24.mUnk_00_1 = (stopsEmission != 0);
    if (counting != 0) {
        stepCount = (u8) (stepCount + 1);
        if (stepCount == 10) {
            effect->mUnk_24.mUnk_00_0 = 1;
        }
    }
    effect->mUnk_98_b.mUnk_02 = stepCount;
    effect->mUnk_50 = kartEffects->mSideDirections[sideIndex];
    sideCoordinate = kartEffects->mSidePositions[sideIndex].x;
    effect->mUnk_28.x = sideCoordinate + effect->mUnk_20->mUnk_00->mUnk_04.x;
    sideCoordinate = kartEffects->mSidePositions[sideIndex].y;
    effect->mUnk_28.y = sideCoordinate + effect->mUnk_20->mUnk_00->mUnk_04.y;
    sideCoordinate = kartEffects->mSidePositions[sideIndex].z;
    effect->mUnk_28.z = sideCoordinate + effect->mUnk_20->mUnk_00->mUnk_04.z;
    velocity.x = MUL_FIXED12_NO_ROUND(velocity.x, velocityFactor);
    velocity.y = MUL_FIXED12_NO_ROUND(velocity.y, velocityFactor);
    velocity.z = MUL_FIXED12_NO_ROUND(velocity.z, velocityFactor);
    effect->mUnk_40 = velocity;
}

// Keeps the water effect at the kart's side, raised by the depth below the water surface.
void AdvanceKartWaterEffect(Unk0201ca6c *effect, s32 a) {
    s32 sideCoordinate;
    Vec3 velocity;
    u32 counting;
    Kart *kart;
    u32 stepCount;
    KartEffects *kartEffects;
    u32 isSlowOrTurning;
    u32 sideIndex;
    s32 velocityFactor;
    u32 stopsEmission;

    if (a != 0) {
        return;
    }
    kart = effect->mUnk_94;
    kartEffects = &gKartEffects[kart->mIndex];
    velocity = kart->mEffectVelocity;
    stopsEmission = 1;
    isSlowOrTurning = 1;
    stepCount = effect->mUnk_98_b.mUnk_02;
    counting = effect->mUnk_98_b.mUnk_01;
    sideIndex = effect->mUnk_98_b.mUnk_03;
    velocityFactor = gKartEffectVelocityFactors[effect->mUnk_98_b.mUnk_00];
    if (IsKartTurnEffectsActive(kart) == 0) {
        if (kart->mVelocityLength >= 0x119a) {
            isSlowOrTurning = 0;
        }
    }
    if (isSlowOrTurning == 0) {
        if (kart->mWaterDepth <= 0x5000) {
            stopsEmission = 0;
        }
    }
    effect->mUnk_24.mUnk_00_1 = (stopsEmission != 0);
    if (counting != 0) {
        stepCount = (u8) (stepCount + 1);
        if (stepCount == 10) {
            effect->mUnk_24.mUnk_00_0 = 1;
        }
    }
    effect->mUnk_98_b.mUnk_02 = stepCount;
    effect->mUnk_50 = kartEffects->mSideDirections[sideIndex];
    sideCoordinate = kartEffects->mSidePositions[sideIndex].x;
    effect->mUnk_28.x = sideCoordinate + effect->mUnk_20->mUnk_00->mUnk_04.x;
    sideCoordinate = kartEffects->mSidePositions[sideIndex].y;
    effect->mUnk_28.y = sideCoordinate + effect->mUnk_20->mUnk_00->mUnk_04.y;
    sideCoordinate = kartEffects->mSidePositions[sideIndex].z;
    effect->mUnk_28.z = sideCoordinate + effect->mUnk_20->mUnk_00->mUnk_04.z;
    effect->mUnk_28.y = effect->mUnk_28.y + (kart->mWaterDepth >> 4);
    velocity.x = MUL_FIXED12_NO_ROUND(velocity.x, velocityFactor);
    velocity.y = MUL_FIXED12_NO_ROUND(velocity.y, velocityFactor);
    velocity.z = MUL_FIXED12_NO_ROUND(velocity.z, velocityFactor);
    effect->mUnk_40 = velocity;
}

void AdvanceOtherKartEffect(Unk0201ca6c *effect, s32 a) {
    if (a != 0) {
        return;
    }
    PlaceOtherKartEffect(effect, a);
    effect->mUnk_98_24 = effect->mUnk_98_24 + 1;
    if (effect->mUnk_98_24 >= 2) {
        effect->mUnk_98_16 = (effect->mUnk_98_16 == 0);
        effect->mUnk_98_24 = 0;
    }
}

// Starts two effects for each pair of the other karts; each effect switches between the pair's two karts.
void StartEffectsAtOtherKarts(s32 pairSetIndex) {
    OtherKartEffectKind *effectKind;
    s32 kindIndex;
    KartIndexPair *pair;
    s32 startedCount;
    u32 initialToggle;
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
        initialToggle = (kindIndex != 0) ? 1 : 0;
        startedCount = 0;
        pair = gOtherKartPairsCopy.mPairs;
        do {
            if (pair->mFirst < 0) {
                break;
            }
            effect = StartRaceFogOffEffect(effectKind->mEffectId, &data_02155a14);
            startedCount++;
            effect->mUnk_90 = effectKind->mAdvance;
            effect->mUnk_98_0 = pair->mFirst;
            effect->mUnk_98_8 = (pair->mSecond < 0) ? 0xff : (u8) pair->mSecond;
            pair++;
            effect->mUnk_98_16 = initialToggle;
            effect->mUnk_98_24 = 0;
            effect->mUnk_94_u = 0;
        } while (startedCount < 4);
        effectKind++;
    }
}

void PlaceOtherKartEffect(Unk0201ca6c *effect, s32 a) {
    Unk0201ca6c_98 *state;
    Kart *kart;
    u32 stepCount;
    u32 isShown;
    u32 secondKart;
    s32 kartIndex;
    s32 pointX;
    s32 pointY;
    s32 pointZ;

    state = &effect->mUnk_98_b;
    kartIndex = state->mUnk_02;
    stepCount = effect->mUnk_94_u;
    kartIndex = (kartIndex == 0) ? state->mUnk_00 : state->mUnk_01;
    secondKart = state->mUnk_01;
    isShown = 1;
    if (secondKart > 8) {
        if (kartIndex > 8) {
            isShown = 0;
        }
        kartIndex = state->mUnk_00;
    }
    kart = GetKart(kartIndex);
    pointX = kart->mPointAlongUp.x;
    pointY = kart->mPointAlongUp.y;
    pointZ = kart->mPointAlongUp.z;
    effect->mUnk_28.x = (pointX >> 4) + effect->mUnk_20->mUnk_00->mUnk_04.x;
    effect->mUnk_28.y = (pointY >> 4) + effect->mUnk_20->mUnk_00->mUnk_04.y;
    effect->mUnk_28.z = (pointZ >> 4) + effect->mUnk_20->mUnk_00->mUnk_04.z;
    if (kart->mUnk_7c & 0x402000) {
        isShown = 0;
    }
    effect->mUnk_24.mUnk_00_3 = (isShown == 0);
    if (stepCount + 1 >= 0x32) {
        effect->mUnk_24.mUnk_00_0 = 1;
    }
    effect->mUnk_94_u = stepCount + 1;
}

// Sets the effect speed scale, then starts the effects of two courses and ties them to the camera.
void InitCourseCameraEffects(void) {
    s32 engineScale;
    s32 engineIndex;

    engineIndex = gRaceSetup->mEngineIndex;
    engineScale = 0x1000;
    switch (engineIndex) {
        case 1:
            engineScale = 0xd9a;
            break;
        case 0:
            engineScale = 0xb33;
            break;
    }
    gCourseCameraEffectSpeedReciprocal = FX_Div(0x1000, MUL_FIXED12_ROUNDED(engineScale, 0x779a));
    gSecondCourseCameraEffect = NULL;
    gFirstCourseCameraEffect = NULL;
    switch (gRaceSetup->mCourseId) {
        case 0x25: {
            Unk0201ca6c *effect;

            if (gRaceSetup->mRaceKind == RACE_KIND_NORMAL) {
                effect = StartEffect(0x24, &data_02155a14);
                gFirstCourseCameraEffect = effect;
                effect->mUnk_90 = AdvanceOldLuigiAgbFirstChaseEffect;
                effect = StartEffect(0x27, &data_02155a14);
                gSecondCourseCameraEffect = effect;
                effect->mUnk_90 = AdvanceOldLuigiAgbSecondChaseEffect;
            } else if (GetRaceUseChainCameras() != 0) {
                effect = StartEffect(0x3d, &data_02155a14);
                gFirstCourseCameraEffect = effect;
                effect->mUnk_90 = AdvanceOldLuigiAgbFirstCurrentCameraEffect;
                effect = StartEffect(0x3f, &data_02155a14);
                gSecondCourseCameraEffect = effect;
                effect->mUnk_90 = AdvanceOldLuigiAgbSecondCurrentCameraEffect;
            } else {
                effect = StartEffect(0x3c, &data_02155a14);
                gFirstCourseCameraEffect = effect;
                effect->mUnk_90 = AdvanceOldLuigiAgbFirstCurrentCameraEffect;
                effect = StartEffect(0x3f, &data_02155a14);
                gSecondCourseCameraEffect = effect;
                effect->mUnk_90 = AdvanceOldLuigiAgbSecondCurrentCameraEffect;
            }
            break;
        }
        case 0x10: {
            Unk0201ca6c *effect;

            if (GetRaceUseChainCameras() != 0) {
                effect = StartEffect(0x3e, &data_02155a14);
                gFirstCourseCameraEffect = effect;
                effect->mUnk_90 = AdvanceOldFrappe64FirstCurrentCameraEffect;
            } else if (gRaceSetup->mRaceKind == RACE_KIND_NORMAL) {
                effect = StartEffect(0x29, &data_02155a14);
                gFirstCourseCameraEffect = effect;
                effect->mUnk_90 = AdvanceOldFrappe64FirstChaseEffect;
                effect = StartEffect(0x25, &data_02155a14);
                gSecondCourseCameraEffect = effect;
                effect->mUnk_90 = AdvanceOldFrappe64SecondChaseEffect;
            } else {
                effect = StartEffect(0x29, &data_02155a14);
                gFirstCourseCameraEffect = effect;
                effect->mUnk_90 = AdvanceOldFrappe64FirstCurrentCameraEffect;
            }
            break;
        }
    }
}

void AdvanceOldLuigiAgbSecondChaseEffect(Unk0201ca6c *effect, s32 a) {
    Vec3 forwardFlat;
    Vec3 effectPos;
    Camera *chaseCamera;

    if (a != 0) {
        return;
    }
    chaseCamera = GetChaseCamera();
    forwardFlat = chaseCamera->mForward;
    forwardFlat.y = 0;
    if ((s64) forwardFlat.z * forwardFlat.z +
            ((s64) forwardFlat.x * forwardFlat.x + (s64) forwardFlat.y * forwardFlat.y) >=
        16) {
        Vec3NormalizeAndGetLengthUnchecked(&forwardFlat, &forwardFlat);
    }
    VEC_MultAdd(0x5800, &forwardFlat, &chaseCamera->mViewPos, &effectPos);
    effectPos.y = 0x1f400;
    effect->mUnk_28.x = effectPos.x + effect->mUnk_20->mUnk_00->mUnk_04.x;
    effect->mUnk_28.y = effectPos.y + effect->mUnk_20->mUnk_00->mUnk_04.y;
    effect->mUnk_28.z = effectPos.z + effect->mUnk_20->mUnk_00->mUnk_04.z;
}

void AdvanceOldLuigiAgbFirstChaseEffect(Unk0201ca6c *effect, s32 a) {
    Vec3s16 directionHalfwords;
    Vec3 forwardFlat;
    Vec3 axis;
    Vec3 effectPos;
    MtxFx33 rotation;
    Vec3 rotatedVector;
    Camera *chaseCamera;
    Kart *kart;
    s32 speedRatio;
    s32 extraDistance;
    s32 distanceSlope;
    u16 angle;

    if (a != 0) {
        return;
    }
    chaseCamera = GetChaseCamera();
    kart = GetKart(gRaceSetup->mEntryIndex);
    forwardFlat = chaseCamera->mForward;
    forwardFlat.y = 0;
    if ((s64) forwardFlat.z * forwardFlat.z +
            ((s64) forwardFlat.x * forwardFlat.x + (s64) forwardFlat.y * forwardFlat.y) >=
        16) {
        Vec3NormalizeAndGetLengthUnchecked(&forwardFlat, &forwardFlat);
    }
    VEC_CrossProduct(&data_02155a08, &forwardFlat, &axis);
    speedRatio = MUL_FIXED12_ROUNDED(kart->mVelocityLength, gCourseCameraEffectSpeedReciprocal);
    rotatedVector = data_02165984;
    extraDistance = 0;
    if (speedRatio > 0x1000) {
        speedRatio = 0x1000;
    }
    if (kart->mUnk_44 & KART_44_REVERSING) {
        speedRatio = speedRatio * 0xffffffff;
        extraDistance = data_02165938;
    }
    angle = MUL_FIXED12_ROUNDED(speedRatio, 0x38e3);
    MTX_RotAxis33(&rotation, &axis, gPairsByAngle[(angle >> 4) * 2], gPairsByAngle[(angle >> 4) * 2 + 1]);
    MTX_MultVec33(&rotatedVector, &rotation, &rotatedVector);
    directionHalfwords.x = rotatedVector.x;
    directionHalfwords.y = rotatedVector.y;
    directionHalfwords.z = rotatedVector.z;
    effect->mUnk_68 = (s16) (MUL_FIXED12_ROUNDED(0x1000 - speedRatio, 0x800) + 0x800);
    effect->mUnk_50 = directionHalfwords;
    distanceSlope = data_02165954 + extraDistance;
    VEC_MultAdd(data_02165938 + (s32) (((s64) distanceSlope * (s64) speedRatio + 0x800) >> 12), &forwardFlat,
                &chaseCamera->mViewPos, &effectPos);
    effectPos.y = GetKart(gRaceSetup->mEntryIndex)->mPosSource->y >> 4;
    effectPos.y = effectPos.y - MUL_FIXED12_ROUNDED(data_02165934, speedRatio);
    effect->mUnk_28.x = effectPos.x + effect->mUnk_20->mUnk_00->mUnk_04.x;
    effect->mUnk_28.y = effectPos.y + effect->mUnk_20->mUnk_00->mUnk_04.y;
    effect->mUnk_28.z = effectPos.z + effect->mUnk_20->mUnk_00->mUnk_04.z;
}

void AdvanceOldLuigiAgbSecondCurrentCameraEffect(Unk0201ca6c *effect, s32 a) {
    Vec3 forwardFlat;
    Vec3 effectPos;
    Camera *currentCamera;

    if (a != 0) {
        return;
    }
    currentCamera = GetCurrentCamera();
    forwardFlat = currentCamera->mForward;
    forwardFlat.y = 0;
    if ((s64) forwardFlat.z * forwardFlat.z +
            ((s64) forwardFlat.x * forwardFlat.x + (s64) forwardFlat.y * forwardFlat.y) >=
        16) {
        Vec3NormalizeAndGetLengthUnchecked(&forwardFlat, &forwardFlat);
    }
    VEC_MultAdd(data_02165958, &forwardFlat, &currentCamera->mViewPos, &effectPos);
    effectPos.y = 0x1f400;
    effect->mUnk_28.x = effectPos.x + effect->mUnk_20->mUnk_00->mUnk_04.x;
    effect->mUnk_28.y = effectPos.y + effect->mUnk_20->mUnk_00->mUnk_04.y;
    effect->mUnk_28.z = effectPos.z + effect->mUnk_20->mUnk_00->mUnk_04.z;
}

void AdvanceOldLuigiAgbFirstCurrentCameraEffect(Unk0201ca6c *effect, s32 a) {
    Vec3s16 directionHalfwords;
    Vec3 forwardFlat;
    Vec3 axis;
    Vec3 effectPos;
    Vec3 negatedUnitY;
    Camera *currentCamera;

    if (a != 0) {
        return;
    }
    currentCamera = GetCurrentCamera();
    GetKart(gRaceSetup->mEntryIndex);
    forwardFlat = currentCamera->mForward;
    negatedUnitY = data_02155a08;
    forwardFlat.y = 0;
    if ((s64) forwardFlat.z * forwardFlat.z +
            ((s64) forwardFlat.x * forwardFlat.x + (s64) forwardFlat.y * forwardFlat.y) >=
        16) {
        Vec3NormalizeAndGetLengthUnchecked(&forwardFlat, &forwardFlat);
    }
    VEC_CrossProduct(&data_02155a08, &forwardFlat, &axis);
    negatedUnitY.y = negatedUnitY.y * 0xffffffff;
    directionHalfwords.x = negatedUnitY.x;
    directionHalfwords.y = negatedUnitY.y;
    directionHalfwords.z = negatedUnitY.z;
    effect->mUnk_68 = 0x1000;
    effect->mUnk_50 = directionHalfwords;
    VEC_MultAdd(data_02165964, &forwardFlat, &currentCamera->mViewPos, &effectPos);
    effectPos.y = effectPos.y + (data_02165968 + MUL_FIXED12_ROUNDED(currentCamera->mForward.y, data_02165960));
    effect->mUnk_28.x = effectPos.x + effect->mUnk_20->mUnk_00->mUnk_04.x;
    effect->mUnk_28.y = effectPos.y + effect->mUnk_20->mUnk_00->mUnk_04.y;
    effect->mUnk_28.z = effectPos.z + effect->mUnk_20->mUnk_00->mUnk_04.z;
}

void AdvanceOldFrappe64SecondChaseEffect(Unk0201ca6c *effect, s32 a) {
    Vec3 forwardFlat;
    Vec3 effectPos;
    Camera *chaseCamera;
    Kart *kart;
    s32 speedRatio;

    if (a != 0) {
        return;
    }
    chaseCamera = GetChaseCamera();
    kart = GetKart(gRaceSetup->mEntryIndex);
    forwardFlat = chaseCamera->mForward;
    forwardFlat.y = 0;
    if ((s64) forwardFlat.z * forwardFlat.z +
            ((s64) forwardFlat.x * forwardFlat.x + (s64) forwardFlat.y * forwardFlat.y) >=
        16) {
        Vec3NormalizeAndGetLengthUnchecked(&forwardFlat, &forwardFlat);
    }
    VEC_MultAdd(0x5800, &forwardFlat, &chaseCamera->mViewPos, &effectPos);
    effectPos.y = GetKart(gRaceSetup->mEntryIndex)->mPosSource->y >> 4;
    effect->mUnk_28.x = effectPos.x + effect->mUnk_20->mUnk_00->mUnk_04.x;
    effect->mUnk_28.y = effectPos.y + effect->mUnk_20->mUnk_00->mUnk_04.y;
    effect->mUnk_28.z = effectPos.z + effect->mUnk_20->mUnk_00->mUnk_04.z;
    speedRatio = MUL_FIXED12_ROUNDED(kart->mVelocityLength, gCourseCameraEffectSpeedReciprocal);
    if (speedRatio > 0x1000) {
        speedRatio = 0x1000;
    }
    effect->mUnk_58 = MUL_FIXED12_ROUNDED(0x1000 - speedRatio, 0x400);
}

void AdvanceOldFrappe64FirstChaseEffect(Unk0201ca6c *effect, s32 a) {
    Vec3 forwardFlat;
    Vec3 effectPos;
    Camera *chaseCamera;
    s32 extraDistance;
    Kart *kart;
    s32 speedRatio;

    if (a != 0) {
        return;
    }
    chaseCamera = GetChaseCamera();
    kart = GetKart(gRaceSetup->mEntryIndex);
    forwardFlat = chaseCamera->mForward;
    speedRatio = MUL_FIXED12_ROUNDED(kart->mVelocityLength, gCourseCameraEffectSpeedReciprocal);
    extraDistance = 0;
    forwardFlat.y = 0;
    if (speedRatio > 0x1000) {
        speedRatio = 0x1000;
    }
    if (kart->mUnk_44 & KART_44_REVERSING) {
        extraDistance = -0x5800;
    }
    if ((s64) forwardFlat.z * forwardFlat.z +
            ((s64) forwardFlat.x * forwardFlat.x + (s64) forwardFlat.y * forwardFlat.y) >=
        16) {
        Vec3NormalizeAndGetLengthUnchecked(&forwardFlat, &forwardFlat);
    }
    extraDistance = extraDistance * 3;
    VEC_MultAdd((s32) (((s64) extraDistance * (s64) speedRatio + 0x800) >> 12) + 0x5800, &forwardFlat,
                &chaseCamera->mViewPos, &effectPos);
    effectPos.y = GetKart(gRaceSetup->mEntryIndex)->mPosSource->y >> 4;
    effect->mUnk_28.x = effectPos.x + effect->mUnk_20->mUnk_00->mUnk_04.x;
    effect->mUnk_28.y = effectPos.y + effect->mUnk_20->mUnk_00->mUnk_04.y;
    effect->mUnk_28.z = effectPos.z + effect->mUnk_20->mUnk_00->mUnk_04.z;
    effect->mUnk_58 = MUL_FIXED12_ROUNDED(0x800, speedRatio);
}

void AdvanceOldFrappe64FirstCurrentCameraEffect(Unk0201ca6c *effect, s32 a) {
    Vec3 forwardFlat;
    Vec3 effectPos;
    Vec3 extraOffset;
    Camera *currentCamera;

    if (a != 0) {
        return;
    }
    currentCamera = GetCurrentCamera();
    forwardFlat = currentCamera->mForward;
    extraOffset = data_02155a14;
    if (GetEntryRaceEnded() != 0) {
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
        Vec3NormalizeAndGetLengthUnchecked(&forwardFlat, &forwardFlat);
    }
    VEC_MultAdd(data_02165958, &forwardFlat, &currentCamera->mViewPos, &effectPos);
    effectPos.y = effectPos.y + (data_0216595c + MUL_FIXED12_ROUNDED(currentCamera->mForward.y, data_02165940));
    VEC_Add(&effectPos, &extraOffset, &effectPos);
    effect->mUnk_28.x = effectPos.x + effect->mUnk_20->mUnk_00->mUnk_04.x;
    effect->mUnk_28.y = effectPos.y + effect->mUnk_20->mUnk_00->mUnk_04.y;
    effect->mUnk_28.z = effectPos.z + effect->mUnk_20->mUnk_00->mUnk_04.z;
    effect->mUnk_58 = 0x800;
}

void SwitchCourseCameraEffectsToCurrentCamera(void) {
    Unk0201ca6c *effect;

    switch (gRaceSetup->mCourseId) {
        case COURSE_ID_OLD_LUIGI_AGB:
            if (gFirstCourseCameraEffect != NULL) {
                DeleteEffect(gFirstCourseCameraEffect);
                effect = StartEffect(0x3c, &data_02155a14);
                gFirstCourseCameraEffect = effect;
                effect->mUnk_90 = AdvanceOldLuigiAgbFirstCurrentCameraEffect;
            }
            if (gSecondCourseCameraEffect == NULL) {
                return;
            }
            DeleteEffect(gSecondCourseCameraEffect);
            effect = StartEffect(0x3f, &data_02155a14);
            gSecondCourseCameraEffect = effect;
            effect->mUnk_90 = AdvanceOldLuigiAgbSecondCurrentCameraEffect;
            break;
        case COURSE_ID_OLD_FRAPPE_64:
            if (gFirstCourseCameraEffect != NULL) {
                gFirstCourseCameraEffect->mUnk_90 = AdvanceOldFrappe64FirstCurrentCameraEffect;
            }
            if (gSecondCourseCameraEffect == NULL) {
                return;
            }
            DeleteEffect(gSecondCourseCameraEffect);
            gSecondCourseCameraEffect = NULL;
            break;
    }
}

void SetupKartFollowEffect(KartFollowEffect *effect, u32 kartIndex, u32 countLimit) {
    effect->mCount = 0x0u;
    effect->mCountLimit = countLimit;
    effect->mKartIndex = kartIndex;
    effect->mUnk_90 = AdvanceKartFollowEffect;
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
    kartIndex = effect->mUnk_98_24;
    stepCount = effect->mUnk_98_16;
    kart = GetKart(kartIndex);
    kartPos = kart->mPosSource;
    posX = kartPos->x;
    posY = kartPos->y;
    posZ = kartPos->z;
    effect->mUnk_28.x = (posX >> 4) + effect->mUnk_20->mUnk_00->mUnk_04.x;
    effect->mUnk_28.y = (posY >> 4) + effect->mUnk_20->mUnk_00->mUnk_04.y;
    effect->mUnk_28.z = (posZ >> 4) + effect->mUnk_20->mUnk_00->mUnk_04.z;
    if (stepCount >= effect->mUnk_98_8) {
        if (stepCount == effect->mUnk_98_8) {
            effect->mUnk_24.mUnk_00_0 = 1;
        }
    } else {
        effect->mUnk_98_16 = stepCount + 1;
    }
}

void SetupKartFollowEffectWithVelocity(KartFollowEffect *effect, u32 kartIndex, u32 countLimit) {
    effect->mCount = 0x0u;
    effect->mCountLimit = countLimit;
    effect->mKartIndex = kartIndex;
    effect->mUnk_90 = AdvanceKartFollowEffectWithVelocity;
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
    kartIndex = effect->mUnk_98_24;
    stepCount = effect->mUnk_98_16;
    kart = GetKart(kartIndex);
    kartPos = kart->mPosSource;
    posX = kartPos->x;
    posY = kartPos->y;
    posZ = kartPos->z;
    effect->mUnk_28.x = (posX >> 4) + effect->mUnk_20->mUnk_00->mUnk_04.x;
    effect->mUnk_28.y = (posY >> 4) + effect->mUnk_20->mUnk_00->mUnk_04.y;
    effect->mUnk_28.z = (posZ >> 4) + effect->mUnk_20->mUnk_00->mUnk_04.z;
    effect->mUnk_40 = kart->mEffectVelocity;
    if (stepCount >= effect->mUnk_98_8) {
        if (stepCount == effect->mUnk_98_8) {
            effect->mUnk_24.mUnk_00_0 = 1;
        }
    } else {
        effect->mUnk_98_16 = stepCount + 1;
    }
}

void PlaceKartAheadEffect(Unk0201ca6c *effect, Kart *kart, void *a) {
    u32 isShown;
    u32 kartFlags;

    if (a == NULL) {
        PlaceEffectAheadAndUpOfKart(effect, kart, 0x733, 0xb33);
        effect->mUnk_5c = (s16) MUL_FIXED12_ROUNDED(kart->mScale.z, 0xb33);
    } else {
        isShown = 1;
        PlaceEffectAheadAndUpOfKart(effect, kart, 0x99a, 0xe66);
        effect->mUnk_6c = (s16) kart->mScale.z;
        kartFlags = kart->mUnk_7c;
        if (!(kartFlags & 1)) {
            if (kartFlags & 0x402000) {
                isShown = 0;
            }
        }
        effect->mUnk_24.mUnk_00_3 = (isShown == 0);
    }
}

// Puts the effect ahead of the kart by b and above it by a, pointing backward.
void PlaceEffectAheadAndUpOfKart(Unk0201ca6c *effect, Kart *kart, s32 upDistance, s32 aheadDistance) {
    Vec3 position;
    Vec3 direction;
    Vec3s16 backwardDirection;
    Vec3 *kartPos = kart->mPosSource;

    position.x = kartPos->x >> 4;
    position.y = kartPos->y >> 4;
    position.z = kartPos->z >> 4;
    VEC_MultAdd(MUL_FIXED12_ROUNDED(kart->mScale.z, aheadDistance), &kart->mUnk_138, &position, &position);
    VEC_MultAdd(MUL_FIXED12_ROUNDED(kart->mScale.y, upDistance), &kart->mUnk_12c, &position, &position);
    effect->mUnk_28.x = position.x + effect->mUnk_20->mUnk_00->mUnk_04.x;
    effect->mUnk_28.y = position.y + effect->mUnk_20->mUnk_00->mUnk_04.y;
    effect->mUnk_28.z = position.z + effect->mUnk_20->mUnk_00->mUnk_04.z;
    GetKartForward(kart, &direction);
    direction.x = -direction.x;
    direction.y = -direction.y;
    direction.z = -direction.z;
    backwardDirection.x = direction.x;
    backwardDirection.y = direction.y;
    backwardDirection.z = direction.z;
    effect->mUnk_50 = backwardDirection;
}

void AdvanceKartAheadEffect(Unk0201ca6c *effect, s32 a) {
    if (a != 0) {
        return;
    }
    PlaceKartAheadEffect(effect, GetKart(effect->mUnk_98_24), effect->mUnk_94);
}

void AdvanceKartAheadEffectWithLimit(Unk0201ca6c *effect, s32 a) {
    u8 kartIndex;
    u8 stepCount;

    if (a != 0) {
        return;
    }
    kartIndex = effect->mUnk_98_24;
    stepCount = effect->mUnk_98_16;
    PlaceKartAheadEffect(effect, GetKart(kartIndex), effect->mUnk_94);
    if (stepCount >= effect->mUnk_98_8) {
        if (stepCount == effect->mUnk_98_8) {
            effect->mUnk_24.mUnk_00_0 = 1;
        }
    } else {
        effect->mUnk_98_16 = stepCount + 1;
    }
}

void StartKartStarEffects(s32 kartIndex) {
    KartStarEffects *starEffects = &gKartStarEffects[kartIndex];
    u16 i;

    i = 0;
    do {
        if (starEffects->mEffects[i] != NULL) {
            DeleteEffect(starEffects->mEffects[i]);
        }
        starEffects->mEffects[i] = StartEffect(gKartStarEffectIds[i], &GetKart(kartIndex)->mPointAlongUp);
        i = i + 1;
    } while (i < 3);
}

static inline s32 MulFixed12Rounded(s32 a, s32 b) {
    return MUL_FIXED12_ROUNDED(a, b);
}

void AdvanceKartStarEffects(s32 kartIndex) {
    KartStarEffects *starEffects = &gKartStarEffects[kartIndex];
    u16 i;
    s16 y;
    s16 x;
    Kart *kart;
    Vec3 velocity;
    Vec3 effectPos;

    kart = GetKart(kartIndex);
    y = MulFixed12Rounded(data_0216593c + MulFixed12Rounded(kart->mVelocityLengthRatio, data_02165950 - data_0216593c),
                          gStarEffectEngineScale);
    x = MulFixed12Rounded(data_02165944 + MulFixed12Rounded(kart->mVelocityLengthRatio, data_0216594c - data_02165944),
                          gStarEffectEngineScale);
    i = 0;
    do {
        if (starEffects->mEffects[i] != NULL) {
            VEC_MultAdd(MUL_FIXED12_ROUNDED(kart->mScale.y, data_02155854[kart->mKartModelsEntry->mCharacterIndex]),
                        &kart->mUnk_12c, &kart->mPos, &effectPos);
            PlaceEffect(starEffects->mEffects[i], &effectPos);
            velocity.x = MUL_FIXED12_NO_ROUND(kart->mEffectVelocity.x, 0xc00);
            velocity.y = MUL_FIXED12_NO_ROUND(kart->mEffectVelocity.y, 0xc00);
            velocity.z = MUL_FIXED12_NO_ROUND(kart->mEffectVelocity.z, 0xc00);
            starEffects->mEffects[i]->mUnk_40 = velocity;
            starEffects->mEffects[i]->mUnk_68 = y;
            starEffects->mEffects[i]->mUnk_64 = x;
            starEffects->mEffects[i]->mUnk_5c = (s16) MUL_FIXED12_ROUNDED(kart->mScale.z, 0x614);
        }
        i = i + 1;
    } while (i < 3);
}

void StopKartStarEffects(s32 kartIndex) {
    KartStarEffects *starEffects = &gKartStarEffects[kartIndex];
    u16 i;

    i = 0;
    do {
        if (starEffects->mEffects[i] != NULL) {
            starEffects->mEffects[i]->mUnk_24.mUnk_00_0 = 1;
            starEffects->mEffects[i] = NULL;
        }
        i = i + 1;
    } while (i < 3);
}

void ReleaseKartStarEffects(s32 kartIndex) {
    KartStarEffects *starEffects = &gKartStarEffects[kartIndex];
    u16 i;

    i = 0;
    do {
        if (starEffects->mEffects[i] != NULL) {
            DeleteEffect(starEffects->mEffects[i]);
            starEffects->mEffects[i] = NULL;
        }
        i = i + 1;
    } while (i < 3);
}

void StartKartKillerEffect(s32 kartIndex) {
    KartEffects *kartEffects = &gKartEffects[kartIndex];

    if (kartEffects->mKillerEffect != NULL) {
        DeleteEffect(kartEffects->mKillerEffect);
    }
    kartEffects->mKillerEffect = StartEffect(0x63, &data_02155a14);
}

// Moves the Killer effect to point b and gives it the kart's velocity.
void PlaceKartKillerEffect(s32 kartIndex, Vec3 *position) {
    KartEffects *kartEffects = &gKartEffects[kartIndex];
    Unk0201ca6c *effect = kartEffects->mKillerEffect;
    Kart *kart;
    Vec3 *kartVelocity;
    Vec3 velocity;

    if (effect == NULL) {
        return;
    }
    effect->mUnk_28.x = position->x + effect->mUnk_20->mUnk_00->mUnk_04.x;
    effect->mUnk_28.y = position->y + effect->mUnk_20->mUnk_00->mUnk_04.y;
    effect->mUnk_28.z = position->z + effect->mUnk_20->mUnk_00->mUnk_04.z;
    kart = GetKart(kartIndex);
    kartVelocity = &kart->mEffectVelocity;
    velocity.x = MUL_FIXED12_NO_ROUND(kartVelocity->x, 0xe66);
    velocity.y = MUL_FIXED12_NO_ROUND(kartVelocity->y, 0xe66);
    velocity.z = MUL_FIXED12_NO_ROUND(kartVelocity->z, 0xe66);
    kartEffects->mKillerEffect->mUnk_40 = velocity;
}
