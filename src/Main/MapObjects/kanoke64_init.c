#include "Main/MapObjects/kanoke64_init.h"
#include "Main/MapObjects/shine_balloon.h"
#include "Main/MapObjects/map_object_kind_update_list.h"

void InitKanoke64(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 value12;
    value2 = value0;
    value0 = MAP_OBJECT_KIND_BASABASA;
    value1 = 0xau;
    CreateParkedMapObjects(value0, value1, (void *) value2);
}
