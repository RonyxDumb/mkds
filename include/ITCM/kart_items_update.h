#pragma once

#include "types.h"
#include "Main/Item/item_pool.h" // KartItems

void ComputeVec3FromDotProducts(s32 normalsDot, s32 secondDot, s32 firstDot, Vec3 *result, const Vec3 *firstVector,
                                const Vec3 *secondVector, s64 *lengthSquared);
void AddKartItemUseFlags(KartItems *kartItems);
// Per-frame step of one record: the key flags, the item in use, the start of use and update of the held item, the
// roulette, and the item point link (if it has one) on the one frame in eight picked by the kart index, followed to the
// Kart only when its point is far; returns early (after clearing
// mKinokoBoostStarted and mTargetedByKouraR) for a removed kart.
void UpdateKartItems(KartItems *kartItems);
