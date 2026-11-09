#pragma once

#include "types.h"
#include "Main/Unknown/code_020e0680.h"

void UpdateChoropuState7(Choropu *choropu);
u8 CollideKartWithChoropu(Choropu *choropu, Kart *kart, u8 *firstResponsePtr, u8 *secondResponsePtr);
u8 CollideItemObjectWithChoropu(Choropu *choropu, ItemObject *itemObject, u8 *firstResponsePtr, u8 *secondResponsePtr);
