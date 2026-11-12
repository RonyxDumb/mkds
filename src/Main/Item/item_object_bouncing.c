#include "Main/Item/item_object_bouncing.h"
#include "Main/Item/held_item.h"

void StartItemObjectBouncing(BouncingItemObject *object, u32 bouncesRemaining) {
    object->mBouncesRemaining = bouncesRemaining;
    object->mItemObject.mBounce = BounceItemObject;
}
