#include "Main/MapObjects/pushed_object_states_init.h"
#include "Main/System/state_machine_init.h"
#include "Main/MapObjects/pushed_motion.h"
#include "Main/Unknown/unk_0216c000.h"

void InitPushedObjectStates(PushedObject *object) {
    InitStateMachine(&object->mMapObject.mStateMachine, gPushedObjectStateTable, 3, object);
    object->mMapObject.mStateMachine.mNextState = 0;
    object->mMapObject.mStateMachine.mNextStateRequested = 1;
}
