#pragma once

#include "types.h"

typedef struct MissionRunMapObject MissionRunMapObject;
typedef struct ItemObject ItemObject;

void SetHanachanSoundCallbacks(MissionRunMapObject *mapObject);
void HanachanSecondSoundCallback(MissionRunMapObject *mapObject);
void HanachanFirstSoundCallback(MissionRunMapObject *mapObject);
void HanachanItemHitCallback(MissionRunMapObject *mapObject, ItemObject *itemObject);
