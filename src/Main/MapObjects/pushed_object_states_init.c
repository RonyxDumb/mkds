#include "Main/MapObjects/pushed_object_states_init.h"
#include "Main/System/state_machine_init.h"
#include "Main/MapObjects/pushed_motion.h"
#include "Main/Sound/sound_data_sdat_path.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/MapObjects/pushed_object_state_1.h"

StateCallbacks gPushedObjectStateTable[3] = {
    {NULL, NULL}, {EnterPushedObjectTumble, UpdatePushedObjectTumble}, {EnterPushedObjectPark, NULL}};

void InitPushedObjectStates(PushedObject *object) {
    InitStateMachine(&object->mMapObject.mStateMachine, gPushedObjectStateTable, 3, object);
    object->mMapObject.mStateMachine.mNextState = PUSHED_OBJECT_STATE_IDLE;
    object->mMapObject.mStateMachine.mNextStateRequested = 1;
}
