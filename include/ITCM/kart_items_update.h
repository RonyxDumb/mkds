#pragma once

#include "types.h"
#include "Main/Item/item_pool.h" // KartItems

void ComputeVec3FromDotProducts(s32 normalsDot, s32 secondDot, s32 firstDot, Vec3 *result, const Vec3 *firstVector,
                                const Vec3 *secondVector, s64 *lengthSquared);
void AddKartItemUseFlags(KartItems *kartItems);
// Per-frame step of one record: flags, the roulette, the use of the held item on the button bits, the held item, the
// course reference; early return for a kart in a special state
void UpdateKartItems(KartItems *kartItems);
