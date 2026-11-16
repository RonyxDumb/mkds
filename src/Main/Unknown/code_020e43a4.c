#include "Main/Unknown/code_020e43a4.h"

#include "Main/Unknown/code_020e43a8.h"
#include "Main/Unknown/code_020e4428.h"
#include "Main/Unknown/code_020e4434.h"
#include "Main/Unknown/code_020e4470.h"
#include "Main/Unknown/code_020e4474.h"
#include "Main/Unknown/code_020e44d8.h"

void rotcyl_state0Init(Unk020e44d8 *object) {
    object->field14C = 0x0u;
}

void rotcyl_state0Update(Unk020e43a8 *object) {
    object->field14C = object->field14C + object->field150;
    object->field0.mAngle = object->field0.mAngle + (s16) (((s64) object->field14C * object->field14A) >> 12);
    if (object->field0.mStateMachine.mStateFrames > object->field144) {
        object->field0.mStateMachine.mNextState = 1;
        object->field0.mStateMachine.mNextStateRequested = 1;
    }
}

u32 rotcyl_state1Init(u32 unused) {
    return unused;
}

void rotcyl_state1Update(Unk020e43a8 *object) {
    object->field0.mAngle = object->field0.mAngle + object->field14A;
    if (object->field146 != 0) {
        if (object->field0.mStateMachine.mStateFrames > object->field146) {
            object->field0.mStateMachine.mNextState = 2;
            object->field0.mStateMachine.mNextStateRequested = 1;
        }
    }
}

void rotcyl_state2Init(Unk020e4428 *object) {
    object->field14C = 0x1000u;
}

void rotcyl_state2Update(Unk020e43a8 *object) {
    object->field14C = object->field14C - object->field150;
    object->field0.mAngle = object->field0.mAngle + (s16) (((s64) object->field14C * object->field14A) >> 12);
    if (object->field0.mStateMachine.mStateFrames > object->field144) {
        object->field14A = -object->field14A;
        object->field0.mStateMachine.mNextState = 3;
        object->field0.mStateMachine.mNextStateRequested = 1;
    }
}

u32 rotcyl_state3Init(u32 unused) {
    return unused;
}
