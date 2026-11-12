#pragma once

#include "types.h"
#include "Main/Unknown/code_020f6be8.h"

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
