#include "Main/Race/race_goal_s_rule.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"

BOOL IsRaceGoalSRuleCourseCountReached(void) {
    u32 courseCountReached = gRaceGoalS->mCourseCountReached;
    RaceSetup *setup = g_GlobalCO;

    if (setup->mMode == MODE_VS || setup->mMode == MODE_WIFI || setup->mMode == MODE_BATTLE) {
        if (setup->mRuleKind != RULE_KIND_FREE) {
            return courseCountReached;
        }
    }
    return 0;
}
