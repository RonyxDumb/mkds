#include "Main/Menu/battle_select_race_rule.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Menu/menu_screen_switch.h"
#include "Main/Menu/select_race_rule.h"
#include "Main/Menu/select_race_rule_multi_simple.h"
#include "Main/Unknown/unk_021759c0.h"

#pragma optimize_for_size on
#pragma thumb on
void UpdateBattleSelectRaceRule(void) {
    switch (AdvanceSelectRaceRule()) {
        case 1:
            if (SelectRaceRuleGetMultiSimple() != 0) {
                GetRaceSetupCopy()->mCourseListMode = 2;
            }
            if (GetRaceSetupCopy()->mCourseListMode == 2) {
                GetRaceSetupCopy()->mCourseId = COURSE_ID_MINI_STAGE1;
                SwitchMenuScreen(0x1d, 0x1f);
            } else {
                SwitchMenuScreen(SCREEN_SELECT_BATTLE_STAGE, 0x1f);
            }
            break;
        case 2:
            SwitchMenuScreen(0xf, 0x1f);
            break;
    }
}
#pragma thumb off
