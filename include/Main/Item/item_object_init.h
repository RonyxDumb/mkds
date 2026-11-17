#pragma once

#include "types.h"
#include "Main/Item/item_objects_and_race_progress.h"

// Sets up a freshly allocated object once: stores its creation number, creates the collision hit link, builds the sound
// source of the kind and releases it again.
void InitItemObject(ItemObject *itemObject, u32 creationNumber, int itemKind);
