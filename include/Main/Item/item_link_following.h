#pragma once

#include "types.h"
#include "Main/MapObjects/pendulum.h"
#include "Main/Item/item_object_throw.h"
#include "Main/Item/item_objects_and_race_progress.h"

// An item object that follows item point links, with the segment points it follows.
typedef struct LinkFollowingItemObject {
    /* 000 */ DirectedItemObject mDirectedItemObject;
    /* 168 */ ItemPointLinkRef mTargetLink;
    /* 170 */ SegmentPoints mSegmentPoints;
    /* 214 */ s32 mRampTimer;
    /* 218 */ s32 mRampWeightPerCount;
    /* 21c */ ItemPointLinkRef mPreviousLink;
    /* 224 */ s32 mLinkWasBehind;
} LinkFollowingItemObject;

void InitLinkFollowingItem(LinkFollowingItemObject *follower, s32 rampCount, s32 rampWeightPerCount, s32 pushOutMode,
                           s32 endsOnFirstHit, s32 reverse, u16 targetKartIndex, s32 flag);
void AdvanceLinkFollowingItem(LinkFollowingItemObject *follower, s32 targetSpeed, s32 speedEase, s32 targetKartIndex,
                              s32 flag);
void AdvanceLinkFollowingItemSegments(LinkFollowingItemObject *follower, s32 targetSpeed, s32 speedEase,
                                      s32 targetKartIndex, s32 flag);
void SteerLinkFollowingItemToLink(LinkFollowingItemObject *follower, s32 targetSpeed, s32 targetKartIndex, s32 flag);
BOOL TryInitLinkFollowingSegments(LinkFollowingItemObject *follower);
void InitLinkFollowingItemFromInUse(LinkFollowingItemObject *follower, ItemInUse *inUse, s32 rampCount,
                                    s32 rampWeightPerCount, s32 throwForward, s32 pushOutMode, s32 endsOnFirstHit,
                                    s32 baseSpeed, u16 targetKartIndex, s32 flag);
void CreateItemModels(void);
void *CreateItemNsbmd(char *modelName, char *textureName);
NsbmdModel *CreateItemModel(char *modelName, char *animationName, char *textureName);
void *FindItemFile(char *fileName);

// Indexed by object kind; 14 slots, 13 files (kind 8 aliases kind 7)
extern NsbmdModel *gItemModels[14];
