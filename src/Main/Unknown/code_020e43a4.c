#include "Main/Unknown/code_020e43a4.h"

#include "Main/Unknown/code_020e0680.h"
#include "Main/Unknown/code_020e43a8.h"
#include "Main/Unknown/code_020e4428.h"
#include "Main/Unknown/code_020e4434.h"
#include "Main/Unknown/code_020e4470.h"
#include "Main/Unknown/code_020e4474.h"
#include "Main/Unknown/code_020e44d8.h"

void EnterRotaryState0(Unk020e3ef4 *object) {
    object->mSpeedFraction = 0x0u;
}

void UpdateRotaryState0(Unk020e3ef4 *object) {
    object->mSpeedFraction = object->mSpeedFraction + object->mSpeedFractionPerFrame;
    object->mUnk_000.mMapObject.mAngle =
        object->mUnk_000.mMapObject.mAngle + (s16) MUL_FIXED12_NO_ROUND(object->mSpeedFraction, object->mAnglePerFrame);
    if (object->mUnk_000.mMapObject.mStateMachine.mStateFrames > object->mRampFrameCount) {
        object->mUnk_000.mMapObject.mStateMachine.mNextState = 1;
        object->mUnk_000.mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

u32 RotaryState1ReturnArgument(u32 value) {
    return value;
}

void UpdateRotaryState1(Unk020e3ef4 *object) {
    object->mUnk_000.mMapObject.mAngle = object->mUnk_000.mMapObject.mAngle + object->mAnglePerFrame;
    if (object->mSteadyFrameCount != 0) {
        if (object->mUnk_000.mMapObject.mStateMachine.mStateFrames > object->mSteadyFrameCount) {
            object->mUnk_000.mMapObject.mStateMachine.mNextState = 2;
            object->mUnk_000.mMapObject.mStateMachine.mNextStateRequested = 1;
        }
    }
}

void EnterRotaryState2(Unk020e3ef4 *object) {
    object->mSpeedFraction = 0x1000u;
}

void UpdateRotaryState2(Unk020e3ef4 *object) {
    object->mSpeedFraction = object->mSpeedFraction - object->mSpeedFractionPerFrame;
    object->mUnk_000.mMapObject.mAngle =
        object->mUnk_000.mMapObject.mAngle + (s16) MUL_FIXED12_NO_ROUND(object->mSpeedFraction, object->mAnglePerFrame);
    if (object->mUnk_000.mMapObject.mStateMachine.mStateFrames > object->mRampFrameCount) {
        object->mAnglePerFrame = -object->mAnglePerFrame;
        object->mUnk_000.mMapObject.mStateMachine.mNextState = 3;
        object->mUnk_000.mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

u32 RotaryState3ReturnArgument(u32 value) {
    return value;
}
