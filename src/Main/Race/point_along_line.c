#include "Main/Race/point_along_line.h"
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
#include "Main/Race/race_hud_sub_screen_cells.h"

void ComputePointAlongLine(Vec3 *result, const Vec3 *startPoint, const Vec3 *endPoint) {
    Vec3 point;
    s32 factor;

    if (startPoint->x == endPoint->x && startPoint->z == endPoint->z) {
        *result = *startPoint;
        return;
    }
    factor = MulFixed12NoRound(GetRaceHudSubScreenInverseScale(), 0x3000);
    point.x = startPoint->x + MulFixed12NoRound(factor, endPoint->x - startPoint->x);
    point.y = startPoint->y + MulFixed12NoRound(factor, endPoint->y - startPoint->y);
    point.z = startPoint->z + MulFixed12NoRound(factor, endPoint->z - startPoint->z);
    *result = point;
}

// FALSE inside a fixed box on the clock and airship courses; TRUE outside it and on every other course.
BOOL IsPositionOutsideBox(const Vec3 *position) {
    BOOL isOutside = TRUE;

    switch (RaceHudSubScreenGetCurrentCourseId()) {
        case COURSE_ID_CLOCK:
            if (position->x >= -0x377000 && position->x <= 0x377000 && position->z >= -0x377000 &&
                position->z <= 0x377000 && position->y < 0x2be800) {
                isOutside = FALSE;
            } else {
                isOutside = TRUE;
            }
            break;
        case COURSE_ID_AIRSHIP:
            if (position->x >= -0x640000 && position->x <= 0x992000 && position->z >= -0x1ce8000 &&
                position->z <= -0x17a2000 && position->y < 0x2e2000) {
                isOutside = FALSE;
            } else {
                isOutside = TRUE;
            }
            break;
    }
    return isOutside;
}
