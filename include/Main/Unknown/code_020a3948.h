#pragma once

#include "types.h"
#include "Main/MapObjects/balloon.h" // Balloon

typedef struct MapObjectList MapObjectList;

void DrawBalloon(void *mapObjectList, Balloon *balloon);
void SetupDrawBalloon(void *mapObjectList);
void CreateBalloon(MapObjectList *mapObjectList); /* also sets word +0x1c of the group record to 1 */
