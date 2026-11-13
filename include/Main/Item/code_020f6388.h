#pragma once

#include "types.h"

extern const u16 gItemObjectReleasePendingBit;
extern const u16 gItemObjectFadeOutPendingBit;
extern const u16 gItemObjectNoCallbackFadeOutPendingBit;
extern const u16 gItemObjectLaunchNoOwnerBit;
extern const u16 gItemObjectReleaseTimerPendingBit;

typedef struct ItemObject ItemObject;

extern const u8 gItemHitTypes[196];

u8 GetItemObjectHitType(ItemObject *itemParam, ItemObject *otherParam);
void DeflectItemObjectRandomly(ItemObject *item, Vec3 *otherPos, Vec3 *normal);
