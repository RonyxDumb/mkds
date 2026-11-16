#include "Main/Unknown/code_020ec484.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d50ec.h"

#include "Main/Unknown/code_020ec490.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020ec504.h"
#include "Main/Unknown/unk_02159000.h"

void rdmo_rotDieStateInit(MapObject *object) {
    u16 newSlot;
    object->mFlags = object->mFlags | (*(u16 *) &data_02159578);
    newSlot = col_deleteColEntry(object->mCollisionSlotIndex);
    object->mCollisionSlotIndex = newSlot;
}

void rdmo_rotDieStateUpdate(Unk020e43a8 *object) {
    if (object->fieldA8) {
        object->fieldAC = object->fieldAC + object->fieldAE;
    } else {
        object->fieldAC = object->fieldAC - object->fieldAE;
    }
    object->field0.field10.y -= object->fieldA4;
    VEC_Add(&object->field0.mPos, &object->field0.field10, &object->field0.mPos);
    if (object->field0.mPos.y < object->fieldA0) {
        object->field0.mStateMachine.mNextState = 2;
        object->field0.mStateMachine.mNextStateRequested = 1;
    }
}

void rdmo_deadStateInit(u32 objectAddress) {
    u32 object = objectAddress;
    u32 value12;
    mobj_setInvisible((void *) object);
}
