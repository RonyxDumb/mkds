#pragma once

#include "types.h"
#include "Main/MapObjects/sanbo_pieces.h"
#include "Main/Item/item_objects_and_race_progress.h"

void CreateSanboHAndSanboB(void *mapObjectList);
u8 CollideItemObjectWithSanbo(Sanbo *sanbo, ItemObject *itemObject, u8 *firstResponse, u8 *response);
u8 CollideKartWithSanbo(Sanbo *sanbo, Kart *kart, u8 *firstResponse, u8 *response);
