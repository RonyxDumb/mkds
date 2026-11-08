#pragma once

#include "types.h"

typedef struct ItemObject ItemObject;

Vec3 *CreateItemPushVector(void);
void ReleaseItemObjectToItsPool(ItemObject *item);
