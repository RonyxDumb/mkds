#include "Main/Unknown/code_020ce928.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Unknown/code_020ccc74.h"
#include "Main/Unknown/code_02119e14.h"
#include "Main/Unknown/unk_021759c0.h"

#pragma optimize_for_size on
#pragma thumb on
void menu_state10Render(void) {
    switch (AdvanceSelectRaceRule()) {
        case 1:
            if (menu_getRaceConfig()->mCourseListMode == 2) {
                menu_getRaceConfig()->mCourseId = COURSE_ID_CROSS;
                menu_gotoState(0x1d, 0x1f);
            } else {
                menu_gotoState(0xb, 0x1f);
            }
            break;
        case 2:
            menu_gotoState(9, 0x1f);
            break;
    }
}
#pragma thumb off
