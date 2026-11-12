#pragma once

#include "types.h"

typedef struct Camera Camera;


void UpdateCameraShake(Camera *camera);

extern s32 gCameraShakeLookAtScaleFactor;
extern s32 gCameraShakeCounterScales[3];
extern s32 gCameraCollisionRadius;
extern s32 gCameraShakeCounterOffsetScale;
extern u16 gStaffRollLightRotationAngle;
extern s32 gCourseWobbleAmplitude;
extern s32 gCameraShakePosOffsetStepScale;
extern s32 gCameraShakeLookAtDistanceScale;
extern s32 gCameraShakePosScale;
extern s32 gCameraFrustumShiftScale;
extern s32 gCameraShakeLookAtStepScale;
extern s32 gChaseCameraDriftOffsetScale;
extern u16 gDefaultHalfFovAngle;
