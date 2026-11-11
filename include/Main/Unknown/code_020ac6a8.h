#pragma once

#include "types.h"
#include "Main/Unknown/code_020ac524.h" // ShineBalloonObject

/* skipped for objects with mFlags & 4 (parked pool objects) */
void UpdateShineBalloon(void *mapObjectList, ShineBalloonObject *shineBalloonObject);
void DrawShineBalloon(void *mapObjectList, ShineBalloonObject *shineBalloonObject);
void SetupDrawShineBalloon(void *mapObjectList);
void CreateShineBalloon(void *mapObjectList);
