#include "Main/MapObjects/kanoke64_init.h"
#include "Main/MapObjects/shine_balloon.h"
#include "Main/MapObjects/map_object_kind_update_list.h"

void InitKanoke64(u32 object) {
    u32 objectArg = object;
    u32 count;
    u32 kind;
    u32 unusedScratch;
    kind = MAP_OBJECT_KIND_BASABASA;
    count = 0xau;
    CreateParkedMapObjects(kind, count, (void *) objectArg);
}
