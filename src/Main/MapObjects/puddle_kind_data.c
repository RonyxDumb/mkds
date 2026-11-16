#include "Main/MapObjects/puddle_kind_data.h"
#include "matrix_3x3_basic.h"
#include "Main/Course/course_map_group_entry.h"
#include "touch_panel_sampling.h"
#include "Main/MapObjects/bound.h"

const u16 gFireball2InitMapObjectFlag = 0x200;

MapObjectKindData *CreatePuddleKindData(void) {
    return CreateAllocateSomeObject_from_thumb(NULL, NULL, NULL, 0, 0);
}
