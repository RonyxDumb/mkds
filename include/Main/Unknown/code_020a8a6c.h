#pragma once

#include "types.h"
#include "Main/Unknown/code_020a826c.h" // CourseSoundObject

// Array of object pointers: pointer to the array and the number of entries (InitCourseSoundObjects).
typedef struct Unk020a8a6c {
    /* 00 */ CourseSoundObject **mMapObjects;
    /* 04 */ u16 mMapObjectCount;
} Unk020a8a6c;

void InitCourseSoundObjects(MapObjectList *mapObjectList);
