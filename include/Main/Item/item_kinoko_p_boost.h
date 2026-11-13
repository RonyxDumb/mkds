#pragma once

#include "types.h"
#include "Main/Item/item_object_throw.h"
#include "Main/Race/data_020f36d8.h"

void StartItemKinokoPBoost(ItemInUse *inUse, HeldItem *heldItem);

extern const Vec3 gKouraWState7StartScale;
extern const ItemInfo gItemInfoKinokoP;
// Default record: its only function pointer is the shared ComputeViewTest hook.
extern const ItemKind gItemKindKinokoP;
