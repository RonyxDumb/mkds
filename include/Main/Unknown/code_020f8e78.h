#pragma once

#include "types.h"
#include "Main/Unknown/code_020f6be8.h"

BOOL sub_20F9290(void *itemParam, Vec3 *normal);
void it_20F91FC(void *itemParam, s32 soundId);
BOOL sub_20F91E0(ItemObject *itemParam);
BOOL IsItemObjectFartherFromCameraThan(ItemObject *item, s32 distance);
BOOL sub_20F9160(ItemObject *c);
void sub_20F9114(void *itemParam);
void sub_20F90DC(ItemObject *itemParam);
void sub_20F90BC(ItemObject *itemParam);
void ResetItemObjectFromData(ItemObject *itemParam, s32 kind, void *buffer, s32 d);
void sub_20F8E78(void *itemParam);
