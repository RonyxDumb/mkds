#include "Main/Unknown/code_020ceb88.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Unknown/code_020ccc74.h"
#include "Main/Unknown/code_02119e14.h"
#include "Main/Unknown/code_020cebe4.h"
#include "Main/Unknown/unk_021759c0.h"

#pragma optimize_for_size on
#pragma thumb on
void menu_state16Render(void) {
    switch (AdvanceSelectRaceRule()) {
        case 1:
            if (func_020cebe4() != 0) {
                menu_getRaceConfig()->mCourseListMode = 2;
            }
            if (menu_getRaceConfig()->mCourseListMode == 2) {
                menu_getRaceConfig()->mCourseId = COURSE_ID_MINI_STAGE1;
                menu_gotoState(0x1d, 0x1f);
            } else {
                menu_gotoState(SCREEN_SELECT_BATTLE_STAGE, 0x1f);
            }
            break;
        case 2:
            menu_gotoState(0xf, 0x1f);
            break;
    }
}
#pragma thumb off
