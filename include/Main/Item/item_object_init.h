#pragma once

#include "types.h"
#include "Main/Item/item_objects_and_race_progress.h"

// Sets up a freshly allocated object once: allocates the 0x1c-byte record behind mCollisionHitLink, builds the model
// entry of the kind and releases it again.
void InitItemObject(ItemObject *itemObject, u32 creationNumber, int itemKind);
