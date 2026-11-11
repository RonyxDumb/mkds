#pragma once

#include "types.h"
#include "Main/Unknown/code_020f36d8.h" // ItemObject

void CallStandingsKartOffsetCallback(u16 kartIndex, Vec3 *offset);
s32 CallKartCollisionCallbacks(s32 firstKartIndex, s32 secondKartIndex);
void SetKartHitByKartIndexFromItem(s32 kartIndex, ItemObject *itemObject);
