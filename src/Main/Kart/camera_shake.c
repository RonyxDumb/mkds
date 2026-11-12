#include "Main/Kart/camera_shake.h"
#include "Main/Race/race.h"
#include "Main/Race/data_020f36d8.h"
#include "code_02147cd8.h"

s32 gCameraShakeLookAtScaleFactor = 0x9000;
s32 gCameraShakeCounterScales[3] = {0x1400, 0x2000, 0x2c00};
s32 gCameraCollisionRadius = 0xa000;
s32 gCameraShakeCounterOffsetScale = 0x800;
u16 gStaffRollLightRotationAngle = 0x2ee0;
s32 gCourseWobbleAmplitude = 0x5000;
s32 gCameraShakePosOffsetStepScale = 0x52;
s32 gCameraShakeLookAtDistanceScale = 0x21;
s32 gCameraShakePosScale = 0x2000;
s32 gCameraFrustumShiftScale = 0x266;
s32 gCameraShakeLookAtStepScale = 0x52;
s32 gChaseCameraDriftOffsetScale = 0x19000;
u16 gDefaultHalfFovAngle = 0x157c;

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
            posShakeScale = gCameraShakePosScale;
            random = &gRaceProgress->mLocalRandom;
            random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
            scale = MUL_FIXED12_NO_ROUND(gCameraShakeLookAtDistanceScale, lookDistance);
            randomValue = (s16) (u16) (random->mValue >> 52);
            scale = MUL_FIXED12_NO_ROUND(scale + 0x1000, gCameraShakeLookAtScaleFactor);
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
    scale = gCameraShakePosOffsetStepScale;
    VEC_Subtract(&camera->mShakePosOffsetGoal, &camera->mShakePosOffset, &posOffsetStep);
    posOffsetStep.x = MUL_FIXED12_NO_ROUND(posOffsetStep.x, scale);
    posOffsetStep.y = MUL_FIXED12_NO_ROUND(posOffsetStep.y, scale);
    posOffsetStep.z = MUL_FIXED12_NO_ROUND(posOffsetStep.z, scale);
    VEC_Add(&camera->mShakePosOffset, &posOffsetStep, &camera->mShakePosOffset);
    scale = gCameraShakeLookAtStepScale;
    VEC_Subtract(&camera->mShakeLookAtOffsetGoal, &camera->mShakeLookAtOffset, &lookAtOffsetStep);
    lookAtOffsetStep.x = MUL_FIXED12_NO_ROUND(lookAtOffsetStep.x, scale);
    lookAtOffsetStep.y = MUL_FIXED12_NO_ROUND(lookAtOffsetStep.y, scale);
    lookAtOffsetStep.z = MUL_FIXED12_NO_ROUND(lookAtOffsetStep.z, scale);
    VEC_Add(&camera->mShakeLookAtOffset, &lookAtOffsetStep, &camera->mShakeLookAtOffset);
    counterScale = -gCameraShakeCounterScales[camera->mShakeKind - 1];
    counterStep.x = MUL_FIXED12_NO_ROUND(camera->mShakeLookAtOffset.x, counterScale);
    counterStep.y = MUL_FIXED12_NO_ROUND(camera->mShakeLookAtOffset.y, counterScale);
    counterStep.z = MUL_FIXED12_NO_ROUND(camera->mShakeLookAtOffset.z, counterScale);
    VEC_Add(&counterStep, &camera->mShakeLookAtCounterOffset, &camera->mShakeLookAtCounterOffset);
    scale = gCameraShakeCounterOffsetScale;
    camera->mShakeLookAtCounterOffset.x = MUL_FIXED12_NO_ROUND(camera->mShakeLookAtCounterOffset.x, scale);
    camera->mShakeLookAtCounterOffset.y = MUL_FIXED12_NO_ROUND(camera->mShakeLookAtCounterOffset.y, scale);
    camera->mShakeLookAtCounterOffset.z = MUL_FIXED12_NO_ROUND(camera->mShakeLookAtCounterOffset.z, scale);
}
