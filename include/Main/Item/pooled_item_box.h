#pragma once

#include "types.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Item/item_pool.h"
#include "Main/Item/item_object_throw.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/held_item.h"
#include "Main/Item/item_objects_and_race_progress.h" // ItemKind, ItemInfo
#include "Main/MapObjects/attractor.h"
#include "Main/Item/item_koura_w.h"

// BouncingItemBox.mScaleRatio starts at the start value on reset; while its owner kart is the entry kart and it is
// below the full value, AdvanceBouncingItemBox adds the step each call.
#define BOUNCING_ITEM_BOX_START_SCALE_RATIO 0x666
#define BOUNCING_ITEM_BOX_FULL_SCALE_RATIO 0x1000
#define BOUNCING_ITEM_BOX_SCALE_RATIO_STEP 0xcd

// An item box that bounces (gItemPools[8]): the bouncing item object part and its ItemBox.
typedef struct BouncingItemBox {
    /* 000 */ BouncingItemObject mBouncingItemObject;
    /* 130 */ s32 mThrownForward;
    /* 134 */ ItemBox *mPooledMapObject;
    /* 138 */ s32 mKartIsEntry;
    /* 13c */ Vec3 mMapObjectPos;
    /* 148 */ s32 mScaleRatio;
} BouncingItemBox;


extern const u16 gBouncingItemBoxUntilCourseHitBit;
extern const ItemInfo gItemInfoKiller;
// Default record: its only function pointer is the shared ComputeViewTest hook.
extern const ItemKind gItemKindKiller;

void CreatePooledMapObjects(void);
void StartItemKiller(ItemInUse *itemInUse, HeldItem *heldItem);
void ResetKartActiveItemAfterKiller(s32 kartIndex);
void UpdateBouncingItemBoxTimers(void);
void ReleaseEliminatedKartItems(s32 kartIndex);
void StartBouncingItemBox(BouncingItemBox *box);
void ReleaseBouncingItemBox(BouncingItemBox *box);
void CollideKartWithBouncingItemBox(BouncingItemBox *box, void *kart);
void ResetBouncingItemBox(BouncingItemBox *box);
void AdvanceBouncingItemBoxInUse(ItemInUse *itemInUse, BouncingItemBox *box);
s32 InitBouncingItemBox(ItemInUse *itemInUse, BouncingItemBox *box);
void AdvanceBouncingItemBox(BouncingItemBox *box);

extern s32 gPooledMapObjectCount;
extern struct MapObject **gPooledMapObjects;
extern u32 gPooledMapObjectNextIndex;
extern struct CourseMapRow gPooledMapObjectRow;
