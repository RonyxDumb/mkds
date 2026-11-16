#include "Main/Unknown/code_02093fa4.h"
#include "Main/Course/ShineBalloon.h"
#include "Main/Unknown/code_020d7d80.h"
#include "Main/Unknown/code_020d7da8.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_021000d0.h"

void nsk1_init(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 value4;
    value4 = value0;
    value1 = *(const u32 *) ((value4) + (156));
    value0 = (value4) + (0xacu);
    value2 = 0u;
    pw_initFromObject((GroupFollower *) value0, (CourseMapRow *) value1, value2);
    value0 = (value4) + (0xacu);
    SetStraightSegmentLengths((GroupFollower *) value0);
    value0 = MAP_OBJECT_KIND_NS_KILLER2;
    value2 = value4;
    value1 = 0x14u;
    mobj_createSubObjects(value0, value1, (void *) value2);
    value0 = (u32) &gSfxParams;
    value0 = *(const u32 *) ((value0) + (356));
    *(u32 *) ((value4) + (112)) = value0;
}
