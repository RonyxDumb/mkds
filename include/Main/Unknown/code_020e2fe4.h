#pragma once

#include "types.h"
#include "Main/MapObjects/choropu.h"

void UpdateChoropuState7(Choropu *choropu);
u8 CollideKartWithChoropu(Choropu *choropu, Kart *kart, u8 *firstResponsePtr, u8 *secondResponsePtr);
u8 CollideItemObjectWithChoropu(Choropu *choropu, ItemObject *itemObject, u8 *firstResponsePtr, u8 *secondResponsePtr);
