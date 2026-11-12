#pragma once

#include "types.h"
#include "Main/Item/code_020f6be8.h"

BOOL TryFadeOutDeflectedItemObject(ItemObject *item, Vec3 *normal);
void StartItemObjectSoundIfNear(ItemObject *item, s32 soundId);
BOOL IsItemObjectScaleAtSetupSize(ItemObject *itemParam);
BOOL IsItemObjectFartherFromCameraThan(ItemObject *item, s32 distance);
BOOL IsItemObjectTooFarForEffects(ItemObject *itemObject);
void StartItemObjectSoundSource(ItemObject *item);
void StopItemObjectSoundSource(ItemObject *itemParam);
void UpdateItemObjectSoundSource(ItemObject *itemParam);
void ResetItemObjectFromData(ItemObject *itemParam, s32 kind, void *buffer, s32 useGenericCopy);
void SetupItemObjectFromData(ItemObject *item);

void BounceItemVelocityOffSurface(Vec3 *velocity, Vec3 *normal);
typedef struct ItemObject ItemObject;

void ClearItemObjectCollisionBits(ItemObject *item, unsigned int clearBits);

void FreeItemObjectCollisionSlot(ItemObject *itemObject);
