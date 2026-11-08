#include "Main/Unknown/code_020ec884.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_020e43a8.h"
#include "Main/Unknown/unk_0216c000.h"

void InitPushedObjectStates(Unk020e43a8 *object) {
    InitStateMachine(&object->mUnk_00.mStateMachine, gPushedObjectStateTable, 3, object);
    object->mUnk_00.mStateMachine.mNextState = 0;
    object->mUnk_00.mStateMachine.mNextStateRequested = 1;
}
