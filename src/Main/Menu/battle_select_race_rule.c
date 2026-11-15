#include "Main/Menu/battle_select_race_rule.h"
#include "Main/Race/race_setup.h"
#include "Main/Menu/menu_screen_switch.h"
#include "Main/Menu/select_race_rule.h"
#include "Main/Menu/select_race_rule_multi_simple.h"
#include "Main/Race/race_setup_block.h"
#include "tp.h"

#pragma optimize_for_size on
#pragma thumb on
void UpdateBattleSelectRaceRule(void) {
    switch (AdvanceSelectRaceRule()) {
        case MENU_SCREEN_RESULT_NEXT:
            if (SelectRaceRuleGetMultiSimple() != 0) {
                GetRaceSetupCopy()->mCourseListMode = COURSE_LIST_MODE_SHUFFLED;
            }
            if (GetRaceSetupCopy()->mCourseListMode == COURSE_LIST_MODE_SHUFFLED) {
                GetRaceSetupCopy()->mCourseId = COURSE_ID_MINI_STAGE1;
                SwitchMenuScreen(SCREEN_NEXT_RACE_SETUP, SCREEN_NONE);
            } else {
                SwitchMenuScreen(SCREEN_SELECT_BATTLE_STAGE, SCREEN_NONE);
            }
            break;
        case MENU_SCREEN_RESULT_BACK:
            SwitchMenuScreen(SCREEN_SELECT_CHARACTER_BATTLE, SCREEN_NONE);
            break;
    }
}
#pragma thumb off
