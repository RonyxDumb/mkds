#pragma once

#include "types.h"

typedef struct ItemObject ItemObject;

s32 StartItemObjectFadeOut(ItemObject *item, s32 variant, s32 skipPending);
void func_020f7104(ItemObject *item, s32 sendEvent);
void func_020f70f0(ItemObject *item);
void func_020f7070(ItemObject *item, s32 sendEvent);
void func_020f705c(ItemObject *item);
void func_020f6fc4(ItemObject *item, s32 sendEvent);
void func_020f6f10(ItemObject *item, s32 sendEvent, s32 highPart);
void AdvanceItemObjectFadeOut(ItemObject *item);
void ApplyItemObjectPush(ItemObject *item, Vec3 *otherPos, Vec3 *otherVelocity, Vec3 *normal);
