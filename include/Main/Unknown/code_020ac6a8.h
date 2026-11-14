#pragma once

#include "types.h"
#include "Main/Course/ShineBalloon.h" // ShineBalloonObject

/* skipped for objects with mFlags & 4 (parked pool objects) */
void UpdateShineBalloon(void *a, ShineBalloonObject *b);
void DrawShineBalloon(void *a, ShineBalloonObject *b);
void SetupDrawShineBalloon(void *a);
void CreateShineBalloon(void *a);
