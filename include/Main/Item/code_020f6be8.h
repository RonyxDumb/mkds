#pragma once

#include "types.h"

typedef struct ItemObject ItemObject;

s32 StartItemObjectFadeOut(ItemObject *item, s32 variant, s32 skipPending);
void FadeOutEndedItemObject(ItemObject *item, s32 sendEvent);
void ReplayPendingFadeOut(ItemObject *item);
void FadeOutItemObjectNoCallback(ItemObject *item, s32 sendEvent);
void ReplayPendingNoCallbackFadeOut(ItemObject *item);
void FadeOutUsedUpItemObject(ItemObject *item, s32 sendEvent);
void FadeOutItemObjectHitByKart(ItemObject *item, s32 sendEvent, s32 highPart);
void AdvanceItemObjectFadeOut(ItemObject *item);
void ApplyItemObjectPush(ItemObject *item, Vec3 *otherPos, Vec3 *otherVelocity, Vec3 *normal);
