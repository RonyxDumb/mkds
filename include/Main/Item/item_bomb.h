#pragma once

#include "types.h"
#include "Main/Menu/second_menu_scene.h" // StateMachine
#include "Main/Item/held_item.h" // BouncingItemObject
#include "Main/MapObjects/pendulum.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_object_throw.h"

typedef struct ItemObject ItemObject;
typedef struct ItemBomb ItemBomb;

// ItemBomb.mStateMachine states, in the order of gItemBombStateTable: BOUNCE bounces after being thrown or dropped,
// REST lies still, EXPLODE grows the scale and ends in release, PARKED has no callbacks.
enum {
    ITEM_BOMB_STATE_BOUNCE,
    ITEM_BOMB_STATE_REST,
    ITEM_BOMB_STATE_EXPLODE,
    ITEM_BOMB_STATE_PARKED,
};

ItemBomb *GetRestingItemBomb(int index);
void ParkItemBomb(void *object);
void PlaceItemBomb(void *object, Vec3 *normal, Vec3 *position);
void ThrowItemBombFromSlot(void **bombSlot, Vec3 *velocity, s32 timerStart);
BOOL IsItemBombGrowing(ItemObject *object);
void ReleaseItemBomb(void **bombSlot);
void *StartItemBomb(void);
void *StartItemBombWithMapObject(void *mapObject, s32 offsetY);
Vec3 *GetItemBombGrowInfo(ItemBomb *bomb, s32 *stateFrames, s32 *scaledScaleZ);
void SetupItemBombKind(void);

unsigned int GetItemBombActiveCount(void);

void ParkItemBombMapObject(ItemBomb *bomb);

struct ModelEffect;

// ItemBomb.mTimer counts down to the explosion (its expiry reaches RequestItemBombGrow through the kind's fade-out
// callback). It starts at ITEM_BOMB_FUSE_FRAMES, at ITEM_BOMB_SHORT_FUSE_FRAMES for a bomb dropped with the down key or
// one that starts falling again, and at the timerStart argument of ThrowItemBombFromSlot. While mTimerEndBlockTimer is
// above 0 a timer that reaches 0 becomes ITEM_BOMB_END_BLOCK_FUSE_FRAMES; below ITEM_BOMB_FLASH_START_FRAMES the model
// flashes; a kart within the explode radius caps mTimer at ITEM_BOMB_FINAL_FUSE_FRAMES and mModelFrameTimer at
// ITEM_BOMB_FINAL_FLASH_FRAMES; below ITEM_BOMB_MAP_OBJECT_DISABLE_FRAMES the map object is disabled.
#define ITEM_BOMB_FUSE_FRAMES 300
#define ITEM_BOMB_SHORT_FUSE_FRAMES 0x5a
#define ITEM_BOMB_END_BLOCK_FUSE_FRAMES 0x10
#define ITEM_BOMB_FLASH_START_FRAMES 0xd2
#define ITEM_BOMB_FINAL_FUSE_FRAMES 4
#define ITEM_BOMB_FINAL_FLASH_FRAMES 3
#define ITEM_BOMB_MAP_OBJECT_DISABLE_FRAMES 0x10
// Frames after a rest request during which the timer cannot end, and during which AdvanceItemBomb skips
// ClampItemBombTimerByDistance (ItemBomb.mTimerEndBlockTimer).
#define ITEM_BOMB_END_BLOCK_FRAMES 0x10e
// ItemBomb.mModelFrameTimer: the flashing model shows its second frame while the timer is above 0 and below
// ITEM_BOMB_FLASH_SHOWN_FRAMES; the timer restarts from a quarter of mTimer but never below ITEM_BOMB_FLASH_MIN_PERIOD.
#define ITEM_BOMB_FLASH_SHOWN_FRAMES 6
#define ITEM_BOMB_FLASH_MIN_PERIOD 8
// ItemBomb.mBouncingItemObject.mBouncesRemaining of a thrown bomb and of a dropped bomb at the start; the bomb looks
// for the nearest kart once it has fewer left than these, that is after its first bounce.
#define ITEM_BOMB_THROWN_BOUNCES 3
#define ITEM_BOMB_DROPPED_BOUNCES 2
// ItemBomb.mNearestKartDistanceSquared before a kart is found, and the value below which it is measured again from the
// kart already found.
#define ITEM_BOMB_NO_KART_DISTANCE_SQUARED 0x5f592e1
#define ITEM_BOMB_NEAREST_REMEASURE_DISTANCE_SQUARED 8
// Largest ItemBomb.mReflectFactor.
#define ITEM_BOMB_MAX_REFLECT_FACTOR 0xccd

// Object of item kind 9, element of gItemPools[9].
typedef struct ItemBomb {
    /* 000 */ BouncingItemObject mBouncingItemObject;
// 1 for a thrown bomb, 0 for one dropped behind it or by a hit kart.
    /* 130 */ s32 mIsThrown;
    /* 134 */ s32 mReflectFactor;
    /* 138 */ struct ModelEffect *mModelEffect;
    /* 13c */ MtxFx43 mMatrix;
    /* 16c */ BOOL mHitSpinsKart;
    /* 170 */ s32 mTimer;
    /* 174 */ s32 mModelFrameTimer;
    /* 178 */ u16 mNearestKartIndex;
    /* 17a */ u8 mUnk_17a[2];
    /* 17c */ s32 mNearestKartDistanceSquared;
    /* 180 */ s32 mTimerEndBlockTimer;
    /* 184 */ StateMachine mStateMachine;
    /* 198 */ ItemBox *mPooledMapObject;
    /* 19c */ s32 mMapObjectOffsetY;
    /* 1a0 */ BOOL mVisible;
} ItemBomb;

void RequestItemBombRest(ItemBomb *bomb);
int RequestItemBombGrow(ItemBomb *bomb);
void DrawItemBomb(ItemBomb *bomb, Vec3 *viewAxis, NsbmdModel *model);
void InitItemBombFromData(ItemBomb *bomb);
void *CopyItemBombData(void *cursor, ItemBomb *bomb, void *toData);
void AdvanceItemBomb(ItemBomb *bomb);
void AdvanceItemBombWithMapObject(ItemBomb *bomb, ItemBomb *bombAlias, ItemBox *pooledMapObject);
void ClampItemBombTimerByDistance(ItemBomb *bomb);
void AdvanceItemBombNearestKart(ItemBomb *bomb);
void UpdateItemBombGrow(void *stateObject);
void EnterItemBombGrow(void *stateObject);
void UpdateItemBombRest(void *stateObject);

void ItemBombRestNop(void *stateObject);

void UpdateItemBombBounce(void *stateObject);

void ItemBombBounceNop(void *stateObject);

s32 InitItemBomb(ItemInUse *inUse, ItemBomb *bomb);

void ResetItemBomb(ItemBomb *bomb);

extern const Vec3 gItemBombExplodeStartScale;
extern const u16 gItemBombDisabledFlag;
extern StateCallbacks gItemBombStateTable[4];
extern const u16 gItemBombSkipListCallbackFlag;
extern const u16 gItemBombNoUpdateListFlag;
extern const u32 gItemObjectDistanceSquaredMask;
extern const u16 gItemBombSkipViewTestFlag;
extern const u16 gItemBombNoOwnerBit;
extern s32 gItemBombExplodeMaxRadiusSquared;
extern s32 gItemBombTimerLimit;
extern s32 gItemBombExplodeInverseLimit;
extern s32 gItemBombExplodeScaleLimit;
extern s32 gItemBombExplodeScaleStep;
