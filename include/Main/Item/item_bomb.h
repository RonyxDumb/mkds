#pragma once

#include "types.h"
#include "Main/Menu/second_menu_scene.h" // StateMachine
#include "Main/Item/held_item.h" // BouncingItemObject
#include "Main/MapObjects/pendulum.h"
#include "Main/Race/data_020f36d8.h"
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
void ThrowItemBombFromSlot(void **bombSlot, Vec3 *param_2, s32 param_3);
BOOL IsItemBombState2(ItemObject *object);
void ReleaseItemBomb(void **bombSlot);
void *StartItemBomb(void);
void *StartItemBombWithMapObject(void *mapObject, s32 param_2);
Vec3 *GetItemBombState2Info(ItemBomb *bomb, s32 *stateFrames, s32 *scaledScaleZ);
void SetupItemBombKind(void);

unsigned int GetItemBombActiveCount(void);

void ParkItemBombMapObject(ItemBomb *bomb);

struct ModelEffect;

// Object of item kind 9, element of gItemPools[9].
typedef struct ItemBomb {
    /* 000 */ BouncingItemObject mBouncingItemObject;
// 1 for a thrown bomb, 0 for one dropped behind it or by a hit kart.
    /* 130 */ s32 mIsThrown;
    /* 134 */ s32 mReflectFactor;
    /* 138 */ struct ModelEffect *mModelEffect;
    /* 13c */ MtxFx43 mUnk_13c;
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

void RequestItemBombState1(ItemBomb *bomb);
int RequestItemBombState2(ItemBomb *bomb);
void DrawItemBomb(ItemBomb *bomb, Vec3 *viewAxis, NsbmdModel *model);
void InitItemBombFromData(ItemBomb *bomb);
void *CopyItemBombData(void *cursor, ItemBomb *bomb, void *toData);
void AdvanceItemBomb(ItemBomb *bomb);
void AdvanceItemBombWithMapObject(ItemBomb *bomb, ItemBomb *bombAlias, ItemBox *pooledMapObject);
void ClampItemBombTimerByDistance(ItemBomb *bomb);
void AdvanceItemBombNearestKart(ItemBomb *bomb);
void UpdateItemBombState2(ItemBomb *bomb);
void EnterItemBombState2(ItemBomb *bomb);
void UpdateItemBombState1(ItemBomb *bomb);

void ItemBombState1Nop(ItemBomb *bomb);

void UpdateItemBombState0(ItemBomb *bomb);

void ItemBombState0Nop(ItemBomb *bomb);

s32 InitItemBomb(ItemInUse *inUse, ItemBomb *bomb);

void ResetItemBomb(ItemBomb *bomb);

extern const Vec3 gItemBombState2StartScale;
extern const u16 gItemBombDisabledFlag;
extern StateCallbacks gItemBombStateTable[4];
extern const u16 gItemBombSkipListCallbackFlag;
extern const u16 gItemBombNoUpdateListFlag;
extern const u32 gItemObjectDistanceSquaredMask;
extern const u16 gItemBombSkipViewTestFlag;
extern const u16 gItemBombNoOwnerBit;
extern s32 gItemBombState2MaxRadiusSquared;
extern s32 gItemBombTimerLimit;
extern s32 gItemBombState2InverseLimit;
extern s32 gItemBombState2ScaleLimit;
extern s32 gItemBombState2ScaleStep;
