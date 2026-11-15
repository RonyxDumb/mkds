#pragma once

#include "types.h"
#include "Main/MapObjects/sanbo_pieces.h" // Sanbo
#include "Main/MapObjects/map_object_kind_update_list.h"

#define SANBO_LAUNCH_WAIT_FRAMES 300

void StartSanboLaunch(Sanbo *sanbo);
MapObjectList *CreateCourseSoundObjectUpdateList(void);

extern MapObjectKindDescriptor gCourseSoundObjectKindDescriptor;
