#include "Main/Unknown/code_020ec884.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_020ec538.h"
#include "Main/Unknown/unk_0216c000.h"

void InitPushedObjectStates(PushedObject *object) {
    InitStateMachine(&object->mMapObject.mStateMachine, gPushedObjectStateTable, 3, object);
    object->mMapObject.mStateMachine.mNextState = 0;
    object->mMapObject.mStateMachine.mNextStateRequested = 1;
}
