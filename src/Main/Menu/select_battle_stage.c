#include "Main/Menu/select_battle_stage.h"
#include "Main/Race/race_setup.h"
#include "Main/Menu/menu_screen_switch.h"
#include "Main/Menu/battle_stage_entry.h"
#include "01/Menu/select_battle_stage_screen.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Menu/menu_entry_kind.h"

#pragma optimize_for_size on
#pragma thumb on
void UpdateSelectBattleStage(void) {
    s32 courseIds[6] = {COURSE_ID_MINI_STAGE1, COURSE_ID_MINI_STAGE2,   COURSE_ID_MINI_STAGE3,
                        COURSE_ID_MINI_STAGE4, COURSE_ID_MINI_BLOCK_64, COURSE_ID_MINI_DOKAN_GC};
    s32 result;

    result = AdvanceSelectBattleStage();
    switch (result) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            GetRaceSetupCopy()->mCourseId = courseIds[result];
            SwitchMenuScreen(SCREEN_NEXT_RACE_SETUP, SCREEN_NONE);
            break;
        case -3:
            SwitchMenuScreen(SCREEN_SELECT_RACE_RULE_BATTLE, SCREEN_NONE);
            break;
        case -2:
            SwitchMenuScreen(SCREEN_SELECT_GAME, SCREEN_NONE);
            BattleStageSetMenuEntryKind(MENU_ENTRY_SINGLE_PLAY_SELECT);
            BattleStageSetRaceSetupRequested(1);
            break;
        case -1:
            SwitchMenuScreen(0x1b, SCREEN_NONE);
            BattleStageSetMenuEntryKind(MENU_ENTRY_SINGLE_PLAY_SELECT);
            BattleStageSetRaceSetupRequested(1);
            break;
    }
}
#pragma thumb off
