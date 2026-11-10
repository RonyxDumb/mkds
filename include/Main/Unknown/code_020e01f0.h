#pragma once

#include "types.h"
#include "Main/Unknown/code_020e0680.h"

// Object holding a pointer at 0x0 and two vectors.
typedef struct CollisionHitLink {
    /* 00 */ CollisionMapObject *mObject;
    /* 04 */ Vec3 mLocalPosition;
    /* 10 */ Vec3 mLocalVelocity;
} CollisionHitLink;

// Object holding a pointer at 0x0 and a vector at 0x4.
typedef struct Unk020e0448 {
    /* 00 */ Rotary *mUnk_00;
    /* 04 */ Vec3 mUnk_04;
} Unk020e0448;

void UpdateKoopaBlock(void *unused, KoopaBlock *koopaBlock);
void *CreateKoopaBlockUpdateList(void);
void *CreateKoopaBlockDrawList(void);
void *CreateKoopaBlockKindData(void);
s32 IsHitLinkOutsideGearRadiusOrFlagged(Unk020e0448 *link);
BOOL GetCollisionHitLinkPosAndVelocity(CollisionHitLink *link, Vec3 *outPosition, Vec3 *outVelocity);
void GetCollisionHitLinkPosition(CollisionHitLink *link, Vec3 *outPosition);
void SetCollisionHitLink(CollisionMapObject *object, Vec3 *position, Vec3 *velocity, CollisionHitLink *link);
