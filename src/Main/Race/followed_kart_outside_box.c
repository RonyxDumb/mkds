#include "Main/Race/followed_kart_outside_box.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "model_material_set.h"
#include "Main/Race/race_setup_block.h"
#include "tp.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Race/point_along_line.h"
#include "Main/Kart/karts.h"

BOOL IsFollowedKartOutsideBox(void) {
    s32 isOutside = 1;
    Vec3 position;
    s32 courseId = RaceHudSubScreenGetCurrentCourseId();

    if (courseId == COURSE_ID_CLOCK || courseId == COURSE_ID_AIRSHIP) {
        GetKartPosFromPosSourceCopy(&position, GetFollowedKartOrEntryIndex());
        isOutside = IsPositionOutsideBox(&position);
    }
    return isOutside;
}
