#pragma once

#include "types.h"
#include "Main/Unknown/code_020a2e4c.h" // Balloon

typedef struct MapObjectList MapObjectList;

void DrawBalloon(void *mapObjectList, Balloon *balloon);
void SetupDrawBalloon(void *mapObjectList);
void CreateBalloon(MapObjectList *mapObjectList); /* also sets word +0x1c of the group record to 1 */
