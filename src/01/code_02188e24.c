#include "01/code_02188e24.h"
#include "01/code_02188e88.h"

void SetAnimationFrameCallback(MissionRunMapObject *mapObject, s32 frameIndex, UnkFunc *callback) {
    mapObject->mAnimationFrameCallbackFrameIndex = frameIndex;
    mapObject->mAnimationFrameCallback = callback;
}

void SetTwoAnimationFrameCallbacks(MissionRunMapObject *mapObject, s32 firstFrameIndex,
                                   void (*firstCallback)(MissionRunMapObject *), s32 secondFrameIndex,
                                   void (*secondCallback)(MissionRunMapObject *)) {
    mapObject->mUnk_1e0 = firstFrameIndex;
    mapObject->mUnk_1e4 = firstCallback;
    mapObject->mUnk_1e8 = secondFrameIndex;
    mapObject->mUnk_1ec = secondCallback;
}

void StartStateFrameCountCallback(MissionRunMapObject *mapObject, s32 frameCount,
                                  void (*callback)(MissionRunMapObject *)) {
    mapObject->mStateFrameCount = frameCount;
    mapObject->mStateFrames = 0;
    if (callback == NULL) {
        callback = StopMapObjectState;
    }
    mapObject->mStateFrameCountCallback = callback;
}
