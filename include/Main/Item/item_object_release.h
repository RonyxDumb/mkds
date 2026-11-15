#pragma once

#include "types.h"
#include "Main/Item/item_object_fade_out.h"
#include "matrix_3x3_basic.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Item/item_object_reset_collide.h"

void ApplyItemObjectHitType(ItemObject *itemParam, s32 hitType, Vec3 *otherPos, Vec3 *otherVelocity,
                            MapObject *mapObject);
void StartItemObjectReleaseTimerSynced(ItemObject *item, s32 sendEvent);
void StartItemObjectReleaseTimer(ItemObject *item);
void AdvanceItemObjectReleaseTimer(ItemObject *item);
void StartItemObjectReleaseSynced(ItemObject *item, s32 sendEvent);
void StartItemObjectRelease(ItemObject *item);
