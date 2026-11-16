#pragma once

#include "types.h"
#include "Main/Unknown/code_020f6be8.h"
#include "Main/Unknown/code_0206bcb0.h"

typedef struct MapObject MapObject;

BOOL sub_20F9C08(ItemObject *item);
void sub_20F9BA8(ItemObject *item);
void func_020f9b0c(ItemObject *item);
void it_initInstance(ItemObject *item, s32 kind);
void it_20F99B8(ItemObject *item, s32 kind, u16 ownerAndFlags, Vec3 *pos);
// Releases what the object holds: the collision body, the model entry when flag 0x400000 is set, then calls the
// kind's release hook. Only it_itemsetDestroyItem calls it.
void it_destroy(ItemObject *item);
void it_20F98A0(ItemObject *itemParam, Vec3 *prevPos, Vec3 *normal, u16 *colorBlend, s32 param_5);
s32 sub_20F9880(ItemObject *item);
BOOL it_20F97E0(ItemObject *item, Kart *kart);
BOOL IsItemObjectOverlappingSphere(ItemObject *item, Vec3 *center, s32 radius);
void func_020f95d4(ItemObject *item, ItemObject *other);
void it_20F944C(ItemObject *itemParam, MapObject *mapObjectParam);
void sub_20F9334(void *itemParam, Vec3 *pos, Vec3 *velocity, s32 minFallSpeed, Vec3 *normal);
