#include "Main/MapObjects/pushed_object_state_1.h"
#include "Main/MapObjects/pushed_object_states_init.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/rock.h"

#include "code_02147cd8.h"
#include "Main/MapObjects/data_02159000.h"
#include "Main/MapObjects/ob_pakkun_sf.h"
#include "Main/MapObjects/attractor.h"

const u8 gPushedObjectTumbleFlag[2] = {1, 0};

void EnterPushedObjectTumble(void *stateObject) {
    MapObject *object = stateObject;
    u16 newSlot;
    object->mFlags = object->mFlags | (*(u16 *) &gPushedObjectTumbleFlag);
    newSlot = FreeCollisionSlot(object->mCollisionSlotIndex);
    object->mCollisionSlotIndex = newSlot;
}

void UpdatePushedObjectTumble(void *stateObject) {
    PushedObject *object = stateObject;
    if (object->mMotion.mAngleIncreasing) {
        object->mMotion.mAngle = object->mMotion.mAngle + object->mMotion.mAngleStep;
    } else {
        object->mMotion.mAngle = object->mMotion.mAngle - object->mMotion.mAngleStep;
    }
    object->mMapObject.mPosStep.y -= object->mMotion.mGravity;
    VEC_Add(&object->mMapObject.mPos, &object->mMapObject.mPosStep, &object->mMapObject.mPos);
    if (object->mMapObject.mPos.y < object->mMotion.mLowestY) {
        object->mMapObject.mStateMachine.mNextState = PUSHED_OBJECT_STATE_PARK;
        object->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterPushedObjectPark(void *stateObject) {
    void *object = stateObject;
    u32 unusedValue;
    ParkMapObject(object);
}
