#pragma once

#include "types.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Item/item_object_throw.h"
#include "Main/Race/data_020f36d8.h"

// Element of gItemPools[2], [3], [7], [8] and [9] up to 0x130: the word at 0x12c that AdvanceBouncingItem,
// InitBouncingItem and ThrowBouncingItem use after the shared part.
typedef struct BouncingItemObject {
    /* 000 */ ItemObject mItemObject;
    /* 12c */ s32 mBouncesRemaining;
} BouncingItemObject;

void BounceItemObject(ItemObject *item, Vec3 *unused, Vec3 *awayDirection);
void AdvanceBouncingItem(BouncingItemObject *item, s32 gravity, s32 velocityFactor, s32 reflectFactor,
                         u32 *collisionHitLink);
void InitBouncingItem(BouncingItemObject *item, s32 bounceCount, Vec3 *velocity);
void ThrowBouncingItem(BouncingItemObject *item, ItemInUse *itemInUse, s32 bounceCount, s32 throwForward,
                       s32 forwardSpeed, s32 forwardUpSpeed, s32 backwardUpSpeed);
void InitItemPointLinkDirections(void);

typedef struct ItemPointLink ItemPointLink;

u32 GetItemPointLinkDirection(ItemPointLink *link, Vec3 *directionOut);

s32 SetItemPointLinkRefFromIndex(u32 index, u32 *ref);

extern const u16 gItemObjectPendingUpdateBit;
extern const ItemSpreadRow gItemSpreadRows[3];
extern s32 gItemPointLinksByIndex[4];
