#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/unk_021759c0.h"

s32 m2d_race_getCurrentCourse(void) {
    u32 courseId;
    courseId = gRaceMultiConfig->mCourseId;
    return courseId;
}
