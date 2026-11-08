#include "Main/Unknown/code_020f9c40.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/code_020f36d8.h"

void FreeItemObjectCollisionSlot(int object) {
    ItemObject *itemObject = (ItemObject *) object;
    if (itemObject->mCollisionSlotIndex == ~0u) {
    }
    if (itemObject->mCollisionSlotIndex == ~0u) {
        return;
    }
    itemObject->mCollisionSlotIndex = FreeCollisionSlot(itemObject->mCollisionSlotIndex);
}
