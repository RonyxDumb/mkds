#include "Main/MapObjects/rotary_state.h"

#include "Main/MapObjects/choropu.h"

void EnterRotaryRampUp(void *stateObject) {
    Rotary *object = stateObject;
    object->mSpeedFraction = 0x0u;
}

void UpdateRotaryRampUp(void *stateObject) {
    Rotary *object = stateObject;
    object->mSpeedFraction = object->mSpeedFraction + object->mSpeedFractionPerFrame;
    object->mCollisionMapObject.mMapObject.mAngle =
        object->mCollisionMapObject.mMapObject.mAngle +
        (s16) MUL_FIXED12_NO_ROUND(object->mSpeedFraction, object->mAnglePerFrame);
    if (object->mCollisionMapObject.mMapObject.mStateMachine.mStateFrames > object->mRampFrameCount) {
        object->mCollisionMapObject.mMapObject.mStateMachine.mNextState = ROTARY_STATE_STEADY;
        object->mCollisionMapObject.mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

void RotarySteadyNop(void *stateObject) {}

void UpdateRotarySteady(void *stateObject) {
    Rotary *object = stateObject;
    object->mCollisionMapObject.mMapObject.mAngle =
        object->mCollisionMapObject.mMapObject.mAngle + object->mAnglePerFrame;
    if (object->mSteadyFrameCount != 0) {
        if (object->mCollisionMapObject.mMapObject.mStateMachine.mStateFrames > object->mSteadyFrameCount) {
            object->mCollisionMapObject.mMapObject.mStateMachine.mNextState = ROTARY_STATE_SLOW_DOWN;
            object->mCollisionMapObject.mMapObject.mStateMachine.mNextStateRequested = 1;
        }
    }
}

void EnterRotarySlowDown(void *stateObject) {
    Rotary *object = stateObject;
    object->mSpeedFraction = 0x1000u;
}

void UpdateRotarySlowDown(void *stateObject) {
    Rotary *object = stateObject;
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

void RotaryPauseNop(void *stateObject) {}
