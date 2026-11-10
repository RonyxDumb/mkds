#pragma once

#include "types.h"

typedef struct ItemObject ItemObject;
typedef struct ItemBomb ItemBomb;

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
