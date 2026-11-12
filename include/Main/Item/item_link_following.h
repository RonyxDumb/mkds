#pragma once

#include "types.h"
#include "Main/MapObjects/pendulum.h"
#include "Main/Item/item_object_throw.h"
#include "Main/Race/data_020f36d8.h"

// Element of gItemPools[1] and [5] up to 0x228: after the DirectedItemObject part, the ItemPointLinkRef at 0x168 that
// PickNextItemPointLink fills, the SegmentPoints at 0x170, the words at 0x214 and 0x218 and the ItemPointLinkRef at
// 0x21c.
typedef struct LinkFollowingItemObject {
    /* 000 */ DirectedItemObject mDirectedItemObject;
    /* 168 */ ItemPointLinkRef mTargetLink;
    /* 170 */ SegmentPoints mSegmentPoints;
    /* 214 */ s32 mRampTimer;
    /* 218 */ s32 mRampWeightPerCount;
    /* 21c */ ItemPointLinkRef mPreviousLink;
    /* 224 */ s32 mLinkWasBehind;
} LinkFollowingItemObject;

void InitLinkFollowingItem(LinkFollowingItemObject *follower, s32 rampCount, s32 rampWeightPerCount, s32 unused,
                           s32 endsOnFirstHit, s32 reverse, u16 targetKartIndex, s32 flag);
void AdvanceLinkFollowingItem(LinkFollowingItemObject *follower, s32 targetSpeed, s32 speedEase, s32 targetKartIndex,
                              s32 flag);
void AdvanceLinkFollowingItemSegments(LinkFollowingItemObject *follower, s32 targetSpeed, s32 speedEase,
                                      s32 targetKartIndex, s32 flag);
void SteerLinkFollowingItemToLink(LinkFollowingItemObject *follower, s32 targetSpeed, s32 targetKartIndex, s32 flag);
BOOL TryInitLinkFollowingSegments(LinkFollowingItemObject *follower);
void InitLinkFollowingItemFromInUse(LinkFollowingItemObject *follower, ItemInUse *inUse, s32 rampCount,
                                    s32 rampWeightPerCount, s32 throwForward, s32 d, s32 endsOnFirstHit, s32 baseSpeed,
                                    u16 targetKartIndex, s32 flag);
void CreateItemModels(void);
void *CreateItemNsbmd(char *modelName, char *textureName);
NsbmdModel *CreateItemModel(char *modelName, char *animationName, char *textureName);
void *FindItemFile(char *fileName);

// Indexed by object kind; 14 slots, 13 files (kind 8 aliases kind 7)
extern NsbmdModel *gItemModels[14];
