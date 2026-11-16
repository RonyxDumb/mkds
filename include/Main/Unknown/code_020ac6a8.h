#pragma once

#include "types.h"
#include "Main/Course/ShineBalloon.h" // ShineBalloonObject

/* skipped for objects with mFlags & 4 (parked pool objects) */
void sblln_update(void *a, ShineBalloonObject *b);
void sblln_render(void *a, ShineBalloonObject *b);
void sblln_applyMaterial(void *a);
void sblln_loadModel(void *a);
