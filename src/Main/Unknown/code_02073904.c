#include "Main/Unknown/code_02073904.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020f36d8.h"
#include "code_02147cd8.h"

static inline s32 CameraShakeNormalizeLengthOrZero(Vec3 *vector, Vec3 *normalized) {
    if (LENGTH_SQUARED(*vector) < 0x10) {
        return 0;
    }
    return Vec3NormalizeAndGetLengthUnchecked(vector, normalized);
}

void UpdateCameraShake(Camera *camera) {
    RandomState64 *random;
    Vec3 sideOffset;
    Vec3 upOffset;
    Vec3 lookDirection;
    Vec3 counterStep;
    Vec3 posOffsetStep;
    Vec3 lookAtOffsetStep;
    s32 lookDistance;
    s32 posShakeScale;
    s32 randomValue;
    s32 offsetScale;
    s32 scale;
    s32 counterScale;

    if (GetRaceUpdateFramesMod2() == 0) {
        VEC_Subtract(&camera->mPos, &camera->mLookAt, &lookDirection);
        lookDistance = CameraShakeNormalizeLengthOrZero(&lookDirection, &lookDirection);
        if (lookDistance != 0) {
            posShakeScale = data_usa_021656a8;
            random = &gRaceProgress->mLocalRandom;
            random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
            scale = MUL_FIXED12_NO_ROUND(data_usa_021656ac, lookDistance);
            randomValue = (s16) (u16) (random->mValue >> 52);
            scale = MUL_FIXED12_NO_ROUND(scale + 0x1000, data_usa_021656c8);
            offsetScale = MUL_FIXED12_NO_ROUND(scale, (randomValue - 0x800) * 2);
            sideOffset.x = MUL_FIXED12_NO_ROUND(camera->mSide.x, offsetScale);
            sideOffset.y = MUL_FIXED12_NO_ROUND(camera->mSide.y, offsetScale);
            sideOffset.z = MUL_FIXED12_NO_ROUND(camera->mSide.z, offsetScale);
            random = &gRaceProgress->mLocalRandom;
            random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
            randomValue = (s16) (u16) (random->mValue >> 52);
            offsetScale = MUL_FIXED12_NO_ROUND(scale, (randomValue - 0x800) * 2);
            upOffset.x = MUL_FIXED12_NO_ROUND(camera->mUp.x, offsetScale);
            upOffset.y = MUL_FIXED12_NO_ROUND(camera->mUp.y, offsetScale);
            upOffset.z = MUL_FIXED12_NO_ROUND(camera->mUp.z, offsetScale);
            VEC_Add(&sideOffset, &upOffset, &camera->mShakeLookAtOffsetGoal);
            random = &gRaceProgress->mLocalRandom;
            random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
            randomValue = (s16) (u16) (random->mValue >> 52);
            offsetScale = MUL_FIXED12_NO_ROUND(posShakeScale, (randomValue - 0x800) * 2);
            sideOffset.x = MUL_FIXED12_NO_ROUND(camera->mSide.x, offsetScale);
            sideOffset.y = MUL_FIXED12_NO_ROUND(camera->mSide.y, offsetScale);
            sideOffset.z = MUL_FIXED12_NO_ROUND(camera->mSide.z, offsetScale);
            random = &gRaceProgress->mLocalRandom;
            random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
            randomValue = (s16) (u16) (random->mValue >> 52);
            offsetScale = MUL_FIXED12_NO_ROUND(posShakeScale, (randomValue - 0x800) * 2);
            upOffset.x = MUL_FIXED12_NO_ROUND(camera->mUp.x, offsetScale);
            upOffset.y = MUL_FIXED12_NO_ROUND(camera->mUp.y, offsetScale);
            upOffset.z = MUL_FIXED12_NO_ROUND(camera->mUp.z, offsetScale);
            VEC_Add(&sideOffset, &upOffset, &camera->mShakePosOffsetGoal);
        }
    }
    scale = data_usa_021656b0;
    VEC_Subtract(&camera->mShakePosOffsetGoal, &camera->mShakePosOffset, &posOffsetStep);
    posOffsetStep.x = MUL_FIXED12_NO_ROUND(posOffsetStep.x, scale);
    posOffsetStep.y = MUL_FIXED12_NO_ROUND(posOffsetStep.y, scale);
    posOffsetStep.z = MUL_FIXED12_NO_ROUND(posOffsetStep.z, scale);
    VEC_Add(&camera->mShakePosOffset, &posOffsetStep, &camera->mShakePosOffset);
    scale = data_usa_021656a4;
    VEC_Subtract(&camera->mShakeLookAtOffsetGoal, &camera->mShakeLookAtOffset, &lookAtOffsetStep);
    lookAtOffsetStep.x = MUL_FIXED12_NO_ROUND(lookAtOffsetStep.x, scale);
    lookAtOffsetStep.y = MUL_FIXED12_NO_ROUND(lookAtOffsetStep.y, scale);
    lookAtOffsetStep.z = MUL_FIXED12_NO_ROUND(lookAtOffsetStep.z, scale);
    VEC_Add(&camera->mShakeLookAtOffset, &lookAtOffsetStep, &camera->mShakeLookAtOffset);
    counterScale = -data_usa_021656cc[camera->mShakeKind - 1];
    counterStep.x = MUL_FIXED12_NO_ROUND(camera->mShakeLookAtOffset.x, counterScale);
    counterStep.y = MUL_FIXED12_NO_ROUND(camera->mShakeLookAtOffset.y, counterScale);
    counterStep.z = MUL_FIXED12_NO_ROUND(camera->mShakeLookAtOffset.z, counterScale);
    VEC_Add(&counterStep, &camera->mShakeLookAtCounterOffset, &camera->mShakeLookAtCounterOffset);
    scale = data_usa_021656bc;
    camera->mShakeLookAtCounterOffset.x = MUL_FIXED12_NO_ROUND(camera->mShakeLookAtCounterOffset.x, scale);
    camera->mShakeLookAtCounterOffset.y = MUL_FIXED12_NO_ROUND(camera->mShakeLookAtCounterOffset.y, scale);
    camera->mShakeLookAtCounterOffset.z = MUL_FIXED12_NO_ROUND(camera->mShakeLookAtCounterOffset.z, scale);
}
