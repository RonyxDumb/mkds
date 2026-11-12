#include "Main/Race/grand_prix_last_course.h"
#include "Main/Menu/choises_s_screen_map.h"
#include "Main/Menu/choises_s_course.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"

#pragma thumb on
#pragma optimize_for_size on
BOOL IsGrandPrixLastCourse(void) {
    return ChoisesSGetCurrentMode() == MODE_GRAND_PRIX && GetCourseNumber() == 4;
}
#pragma thumb off
