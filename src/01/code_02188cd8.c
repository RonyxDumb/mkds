#include "01/code_02188cd8.h"
#include "01/code_0219b1c4.h"
#include "01/code_0218c000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_020a3000.h"

void SetPointInRangePoint(MissionRunMapObject *mapObject, Vec3 *point) {
    if (point != NULL) {
        mapObject->mPoint = *point;
    }
}

void StartAnimationNoEndCallback(MissionRunMapObject *mapObject, s32 animationEntry, s32 frameStep) {
    StartMapObjectModelNsbcaAnimation(mapObject->mNsbmd, (u16) animationEntry, frameStep, 0);
    mapObject->mAnimationEndCallback = NULL;
}

void StartAnimationWithEndCallback(MissionRunMapObject *mapObject, s32 animationEntry, s32 frameStep,
                                   void (*endCallback)(MissionRunMapObject *)) {
    StartMapObjectModelNsbcaAnimation(mapObject->mNsbmd, (u16) animationEntry, frameStep, 1);
    if (endCallback == NULL) {
        endCallback = StopMapObjectState;
    }
    mapObject->mAnimationEndCallback = endCallback;
}

void SetAlphaLimitTargetAndPerCall(MissionRunMapObject *mapObject, s32 alphaLimitTarget, s32 alphaLimitPerCall) {
    mapObject->mAlphaLimitTarget = alphaLimitTarget;
    mapObject->mAlphaLimitPerCall = alphaLimitPerCall;
}

void SetScaleTargetAndPerCall(MissionRunMapObject *mapObject, s32 scaleTarget, s32 scalePerCall) {
    mapObject->mScaleTarget = scaleTarget;
    mapObject->mScalePerCall = scalePerCall;
}

void SetSpeedAndClearTarget(MissionRunMapObject *mapObject, s32 speed) {
    mapObject->mSpeed = speed;
    mapObject->mSpeedTarget = 0;
    mapObject->mSpeedPerCall = 0;
}

void SetSpeedTargetAndPerCall(MissionRunMapObject *mapObject, s32 speedTarget, s32 speedPerCall) {
    mapObject->mSpeedTarget = speedTarget;
    mapObject->mSpeedPerCall = speedPerCall;
}
