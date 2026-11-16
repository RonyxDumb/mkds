#include "Main/Unknown/code_020e43a4.h"

#include "Main/Unknown/code_020e43a8.h"
#include "Main/Unknown/code_020e4428.h"
#include "Main/Unknown/code_020e4434.h"
#include "Main/Unknown/code_020e4470.h"
#include "Main/Unknown/code_020e4474.h"
#include "Main/Unknown/code_020e44d8.h"

void rotcyl_state0Init(Unk020e44d8 *object) {
    object->mUnk_14c = 0x0u;
}

void rotcyl_state0Update(Unk020e43a8 *object) {
    object->mUnk_14c = object->mUnk_14c + object->mUnk_150;
    object->mUnk_00.mAngle = object->mUnk_00.mAngle + (s16) (((s64) object->mUnk_14c * object->mUnk_14a) >> 12);
    if (object->mUnk_00.mStateMachine.mStateFrames > object->mUnk_144) {
        object->mUnk_00.mStateMachine.mNextState = 1;
        object->mUnk_00.mStateMachine.mNextStateRequested = 1;
    }
}

u32 rotcyl_state1Init(u32 unused) {
    return unused;
}

void rotcyl_state1Update(Unk020e43a8 *object) {
    object->mUnk_00.mAngle = object->mUnk_00.mAngle + object->mUnk_14a;
    if (object->mUnk_146 != 0) {
        if (object->mUnk_00.mStateMachine.mStateFrames > object->mUnk_146) {
            object->mUnk_00.mStateMachine.mNextState = 2;
            object->mUnk_00.mStateMachine.mNextStateRequested = 1;
        }
    }
}

void rotcyl_state2Init(Unk020e4428 *object) {
    object->mUnk_14c = 0x1000u;
}

void rotcyl_state2Update(Unk020e43a8 *object) {
    object->mUnk_14c = object->mUnk_14c - object->mUnk_150;
    object->mUnk_00.mAngle = object->mUnk_00.mAngle + (s16) (((s64) object->mUnk_14c * object->mUnk_14a) >> 12);
    if (object->mUnk_00.mStateMachine.mStateFrames > object->mUnk_144) {
        object->mUnk_14a = -object->mUnk_14a;
        object->mUnk_00.mStateMachine.mNextState = 3;
        object->mUnk_00.mStateMachine.mNextStateRequested = 1;
    }
}

u32 rotcyl_state3Init(u32 unused) {
    return unused;
}
