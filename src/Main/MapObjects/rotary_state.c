#include "Main/MapObjects/rotary_state.h"

#include "Main/MapObjects/choropu.h"

void EnterRotaryState0(Rotary *object) {
    object->mSpeedFraction = 0x0u;
}

void UpdateRotaryState0(Rotary *object) {
    object->mSpeedFraction = object->mSpeedFraction + object->mSpeedFractionPerFrame;
    object->mCollisionMapObject.mMapObject.mAngle =
        object->mCollisionMapObject.mMapObject.mAngle +
        (s16) MUL_FIXED12_NO_ROUND(object->mSpeedFraction, object->mAnglePerFrame);
    if (object->mCollisionMapObject.mMapObject.mStateMachine.mStateFrames > object->mRampFrameCount) {
        object->mCollisionMapObject.mMapObject.mStateMachine.mNextState = ROTARY_STATE_STEADY;
        object->mCollisionMapObject.mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

void RotaryState1Nop(Rotary *object) {}

void UpdateRotaryState1(Rotary *object) {
    object->mCollisionMapObject.mMapObject.mAngle =
        object->mCollisionMapObject.mMapObject.mAngle + object->mAnglePerFrame;
    if (object->mSteadyFrameCount != 0) {
        if (object->mCollisionMapObject.mMapObject.mStateMachine.mStateFrames > object->mSteadyFrameCount) {
            object->mCollisionMapObject.mMapObject.mStateMachine.mNextState = ROTARY_STATE_SLOW_DOWN;
            object->mCollisionMapObject.mMapObject.mStateMachine.mNextStateRequested = 1;
        }
    }
}

void EnterRotaryState2(Rotary *object) {
    object->mSpeedFraction = 0x1000u;
}

void UpdateRotaryState2(Rotary *object) {
    object->mSpeedFraction = object->mSpeedFraction - object->mSpeedFractionPerFrame;
    object->mCollisionMapObject.mMapObject.mAngle =
        object->mCollisionMapObject.mMapObject.mAngle +
        (s16) MUL_FIXED12_NO_ROUND(object->mSpeedFraction, object->mAnglePerFrame);
    if (object->mCollisionMapObject.mMapObject.mStateMachine.mStateFrames > object->mRampFrameCount) {
        object->mAnglePerFrame = -object->mAnglePerFrame;
        object->mCollisionMapObject.mMapObject.mStateMachine.mNextState = ROTARY_STATE_PAUSE;
        object->mCollisionMapObject.mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

void RotaryState3Nop(Rotary *object) {}
