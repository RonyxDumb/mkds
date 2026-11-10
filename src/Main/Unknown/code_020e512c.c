#include "Main/Unknown/code_020e512c.h"
#include "ITCM/code_01ffdee4.h"

#pragma thumb on

// Whether a course triangle with flag bit 0x2 lies at the position.
u32 HasCourseTriangleFlag2At(Vec3 *position) {
    u32 outValue[1];
    outValue[0] = 0;
    CollideSphereWithCourse(position, NULL, 0, 0x0000a000u, 8, 0xfffffffe, NULL, NULL, NULL, outValue, NULL, NULL, NULL,
                            NULL);
    return outValue[0] & (0x01000000u);
}

#pragma thumb off
