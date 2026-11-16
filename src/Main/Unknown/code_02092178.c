#include "Main/Unknown/code_02092178.h"
#include "Main/Course/ShineBalloon.h"
#include "Main/Unknown/code_021000d0.h"

void kan64_init(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 value12;
    value2 = value0;
    value0 = MAP_OBJECT_KIND_BASABASA;
    value1 = 0xau;
    mobj_createSubObjects(value0, value1, (void *) value2);
}
