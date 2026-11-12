#pragma once

#include "types.h"
#include "Main/Item/code_020f6be8.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Item/code_020f9334.h"

void ApplyItemObjectHitType(ItemObject *itemParam, s32 hitType, Vec3 *otherPos, Vec3 *otherVelocity,
                            MapObject *mapObject);
void StartItemObjectReleaseTimerSynced(ItemObject *item, s32 sendEvent);
void StartItemObjectReleaseTimer(ItemObject *item);
void AdvanceItemObjectReleaseTimer(ItemObject *item);
void StartItemObjectReleaseSynced(ItemObject *item, s32 sendEvent);
void StartItemObjectRelease(ItemObject *item);
