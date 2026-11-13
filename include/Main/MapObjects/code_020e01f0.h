#pragma once

#include "types.h"
#include "Main/MapObjects/choropu.h"
#include "Main/MapObjects/data_02158000.h" // MapObjectDrawList
#include "Main/MapObjects/attractor.h" // MapObjectKindData, MapObjectList

// Object holding a pointer at 0x0 and two vectors.
typedef struct CollisionHitLink {
    /* 00 */ CollisionMapObject *mObject;
    /* 04 */ Vec3 mLocalPosition;
    /* 10 */ Vec3 mLocalVelocity;
} CollisionHitLink;

void UpdateKoopaBlock(void *unused, KoopaBlock *koopaBlock);
MapObjectList *CreateKoopaBlockUpdateList(void);
MapObjectDrawList *CreateKoopaBlockDrawList(void);
MapObjectKindData *CreateKoopaBlockKindData(void);
s32 IsHitLinkOutsideGearRadiusOrFlagged(CollisionHitLink *link);
BOOL GetCollisionHitLinkPosAndVelocity(CollisionHitLink *link, Vec3 *outPosition, Vec3 *outVelocity);
void GetCollisionHitLinkPosition(CollisionHitLink *link, Vec3 *outPosition);
void SetCollisionHitLink(CollisionMapObject *object, Vec3 *position, Vec3 *velocity, CollisionHitLink *link);
