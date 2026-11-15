#include "Main/MapObjects/puddle_kind_data.h"
#include "fx_mtx33.h"
#include "Main/Course/course_map_group_entry.h"
#include "tp.h"
#include "Main/MapObjects/bound.h"

const u16 gFireball2InitMapObjectFlag = 0x200;

MapObjectKindData *CreatePuddleKindData(void) {
    return CreateMapObjectKindData(NULL, NULL, NULL, 0, 0);
}
