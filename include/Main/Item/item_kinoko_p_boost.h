#pragma once

#include "types.h"
#include "Main/Item/item_object_throw.h"
#include "Main/Item/item_objects_and_race_progress.h"

void StartItemKinokoPBoost(ItemInUse *inUse, HeldItem *heldItem);

extern const Vec3 gKouraWGrowStartScale;
extern const ItemInfo gItemInfoKinokoP;
// Default record: its only function pointer is the shared ComputeViewTest hook.
extern const ItemKind gItemKindKinokoP;
