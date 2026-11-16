#pragma once

#include "types.h"
#include "Main/MapObjects/map_object_kind_update_list.h" // MapObjectKindDescriptor
#include "01/MapObjects/map_object_model.h"

#define SMAN_COME_BACK_FRAMES 10

#define SMAN_ANGLE_Z_PER_FRAME 0xf0

#define SMAN_STATE_END_FRAMES 0x12b

#define SMAN_SOUND_ID 0x162

extern struct MapObjectModel *g_SmanTopMapObject;
extern struct MapObjectModel *g_SmanBottomMapObject;
