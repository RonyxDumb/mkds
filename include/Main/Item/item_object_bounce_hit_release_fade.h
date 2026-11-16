#pragma once

#include "types.h"

extern const u16 gItemObjectReleasePendingBit;
extern const u16 gItemObjectFadeOutPendingBit;
extern const u16 gItemObjectNoCallbackFadeOutPendingBit;
extern const u16 gItemObjectLaunchNoOwnerBit;
extern const u16 gItemObjectReleaseTimerPendingBit;

typedef struct ItemObject ItemObject;

// Values of gItemHitTypes and the hit type of ApplyItemObjectHitType (0 is no reaction): bounce off what was hit, or be
// pushed away and fade out used up.
#define ITEM_HIT_TYPE_BOUNCE 1
#define ITEM_HIT_TYPE_FADE_OUT 2

extern const u8 gItemHitTypes[196];

u8 GetItemObjectHitType(ItemObject *itemParam, ItemObject *otherParam);
void DeflectItemObjectRandomly(ItemObject *item, Vec3 *otherPos, Vec3 *normal);
