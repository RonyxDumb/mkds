#pragma once

#include "types.h"
#include "Main/MapObjects/data_020a7000.h" // Sanbo
#include "Main/MapObjects/map_object_kind_update_list.h"

void StartSanboLaunch(Sanbo *sanbo);
MapObjectList *CreateCourseSoundObjectUpdateList(void);

extern MapObjectKindDescriptor gCourseSoundObjectKindDescriptor;
