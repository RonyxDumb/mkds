#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "Main/Race/race_setup_block.h"
#include "tp.h"

s32 RaceHudSubScreenGetCurrentCourseId(void) {
    u32 courseId;
    courseId = gRaceSetup->mCourseId;
    return courseId;
}
