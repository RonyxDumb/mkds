#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"

s32 GetCurrentInternalCourseId_0(void) {
    u32 courseId;
    courseId = g_GlobalCO->mCourseId;
    return courseId;
}
