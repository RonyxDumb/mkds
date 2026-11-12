#pragma once

#include "types.h"

typedef struct ItemKouraW ItemKouraW;

void SetItemKouraWKartItems(ItemKouraW *itemKouraW, int kartIndex);

BOOL TrySetItemKouraWKartItems(ItemKouraW *item, s32 kartIndex);
void SteerItemKouraWToKartForward(ItemKouraW *item, s32 gain, s32 lift);
void SteerItemKouraWToNextAnglePoint(ItemKouraW *item, s32 gain, s32 maxStep, s32 radius, u16 angleStep);

void SteerItemKouraWToAnglePoint(ItemKouraW *item, s32 maxStep, s32 angle, s32 radius, s32 gain, s32 oldWeight,
                                 s32 shift);

void SteerItemKouraWAtAngleZero(ItemKouraW *item, u32 gain, u32 maxStep, u32 radius);

void ClearItemKouraWKartItemsAndAngle(ItemKouraW *item);
