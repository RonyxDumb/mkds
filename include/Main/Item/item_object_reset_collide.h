#pragma once

#include "types.h"
#include "Main/Item/item_object_fade_out.h"
#include "Main/Kart/kart_drift.h"

typedef struct MapObject MapObject;
typedef struct CourseColorBlend CourseColorBlend;

BOOL IsItemObjectOldAndResting(ItemObject *item);
void StartItemObjectReleaseIfOldResting(ItemObject *item);
void StartItemObjectReleaseOnTimeout(ItemObject *item);
void ResetItemObject(ItemObject *item, s32 kind);
void ResetItemObjectAtPos(ItemObject *item, s32 kind, u16 ownerAndFlags, Vec3 *pos);
// Releases what the object holds: the collision body, the model entry when flag 0x400000 is set, then calls the
// kind's release hook. Only ReleaseItemPoolObject calls it.
void ReleaseItemObject(ItemObject *item);
void SetItemObjectPlacement(ItemObject *itemParam, Vec3 *prevPos, const Vec3 *normal, CourseColorBlend *colorBlend,
                            s32 flag);
s32 DoesItemObjectHurtKart(ItemObject *item);
BOOL IsItemObjectOverlappingKart(ItemObject *item, Kart *kart);
BOOL IsItemObjectOverlappingSphere(ItemObject *item, Vec3 *center, s32 radius);
void CollideItemObjectWithItemObject(ItemObject *item, ItemObject *other);
void ApplyMapObjectHitToItemObject(ItemObject *itemParam, MapObject *mapObjectParam);
void LandItemObjectIfOnGround(ItemObject *item, Vec3 *pos, Vec3 *velocity, s32 minFallSpeed, Vec3 *normal);
