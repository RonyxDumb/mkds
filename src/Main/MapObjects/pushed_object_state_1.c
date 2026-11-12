#include "Main/MapObjects/pushed_object_state_1.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/rock.h"

#include "Main/Unknown/code_020ec490.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020ec504.h"
#include "Main/Unknown/unk_02159000.h"

void EnterPushedObjectState1(MapObject *object) {
    u16 newSlot;
    object->mFlags = object->mFlags | (*(u16 *) &data_02159578);
    newSlot = FreeCollisionSlot(object->mCollisionSlotIndex);
    object->mCollisionSlotIndex = newSlot;
}

void UpdatePushedObjectState1(PushedObject *object) {
    if (object->mMotion.mAngleIncreasing) {
        object->mMotion.mAngle = object->mMotion.mAngle + object->mMotion.mAngleStep;
    } else {
        object->mMotion.mAngle = object->mMotion.mAngle - object->mMotion.mAngleStep;
    }
    object->mMapObject.mPosStep.y -= object->mMotion.mGravity;
    VEC_Add(&object->mMapObject.mPos, &object->mMapObject.mPosStep, &object->mMapObject.mPos);
    if (object->mMapObject.mPos.y < object->mMotion.mLowestY) {
        object->mMapObject.mStateMachine.mNextState = 2;
        object->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterPushedObjectState2(u32 objectAddress) {
    u32 object = objectAddress;
    u32 value12;
    ParkMapObject((void *) object);
}
