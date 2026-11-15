#include "Main/Menu/menu_screen_init.h"
#include "Main/Menu/select_character.h"
#include "Main/Menu/select_game.h"
#include "Main/Menu/single_play_select_screen3.h"
#include "Main/Menu/next.h"
#include "01/Menu/select_engine.h"
#include "Main/Menu/multi_simple.h"
#include "Main/Menu/menu_connection_kind.h"
#include "Main/Menu/menu_heap.h"
#include "Main/Menu/menu_screen_switch.h"
#include "Main/Race/race_setup.h"
#include "01/Menu/select_battle_stage_screen.h"
#include "01/Menu/mission_run_level_select.h"
#include "01/Menu/mission_run_mission_select.h"
#include "01/Menu/time_attack_top_menu.h"
#include "01/Menu/select_ghost.h"
#include "Main/Menu/select_race_rule_wait_slide_out.h"
#include "Main/System/interpolation_value.h"
#include "Main/System/heap_call.h"
#include "code_02022aa8.h"
#include "Main/Graphics/cell_file_set.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Menu/multi_select_member_group.h"
#include "Main/Race/race_setup_block.h"
#include "tp.h"
#include "Main/Save/buddy_record_time.h"
#include "g2d_CellTransferManager.h"
#include "Main/Menu/select_kart_data.h"
#include "Main/Menu/select_cup_grid.h"
#include "Main/Menu/select_cup_course_index.h"
#include "Main/Menu/select_race_rule_state.h"
#include "Main/Menu/select_cup_m.h"

#pragma thumb on
#pragma optimize_for_size on
void InitCurrentMenuScreen(void) {
    MenuScene *menu;
    s32 variant;

    menu = gMenuScene;
    if (menu->mScreenNumber != menu->mPreviousScreenNumber) {
        switch (menu->mScreenNumber) {
            case SCREEN_SELECT_ENGINE:
                InitSelectEngine(MenuGetCurrentHeap(), menu->mMainOam, menu->mSubOam);
                break;
            case SCREEN_SELECT_CHARACTER_GRAND_PRIX:
            case SCREEN_SELECT_CHARACTER_VS:
            case SCREEN_SELECT_CHARACTER_BATTLE:
            case SCREEN_SELECT_CHARACTER_TIME_ATTACK:
                variant = (MenuGetConnectionKind() == CONNECTION_KIND_NONE) ? SELECT_CHARACTER_MODE_NO_CONNECTION
                                                                            : SELECT_CHARACTER_MODE_CONNECTION;
                menu = gMenuScene;
                InitSelectCharacter(MenuGetCurrentHeap(), variant, menu->mMainOam, menu->mSubOam);
                break;
            case SCREEN_SELECT_KART_GRAND_PRIX:
            case SCREEN_SELECT_KART_VS:
            case SCREEN_SELECT_KART_TIME_ATTACK:
                variant = (MenuGetConnectionKind() == CONNECTION_KIND_NONE) ? SELECT_KART_MODE_NO_CONNECTION
                                                                            : SELECT_KART_MODE_CONNECTION;
                menu = gMenuScene;
                InitSelectKart(MenuGetCurrentHeap(), variant, menu->mMainOam, menu->mSubOam);
                break;
            case SCREEN_SELECT_CUP_GRID_GRAND_PRIX:
                InitSelectCupGrid(MenuGetCurrentHeap(), menu->mMainOam, menu->mSubOam,
                                  SELECT_CUP_GRID_MODE_SHOW_RECORDS);
                break;
            case SCREEN_SELECT_CUP_GRID_VS:
                if (MenuGetConnectionKind() == CONNECTION_KIND_NONE) {
                    variant = SELECT_CUP_GRID_MODE_NO_CONNECTION;
                } else if (GetMultiSimple() != 0) {
                    variant = SELECT_CUP_GRID_MODE_MULTI_SIMPLE;
                } else {
                    variant = SELECT_CUP_GRID_MODE_MULTI_OTHER;
                }
                menu = gMenuScene;
                InitSelectCupGrid(MenuGetCurrentHeap(), menu->mMainOam, menu->mSubOam, variant);
                break;
            case SCREEN_SELECT_CUP_GRID_TIME_ATTACK:
                InitSelectCupGrid(MenuGetCurrentHeap(), menu->mMainOam, menu->mSubOam, SELECT_CUP_GRID_MODE_NO_RECORDS);
                break;
            case SCREEN_SELECT_CUP_COURSE_VS:
                if (MenuGetConnectionKind() == CONNECTION_KIND_NONE) {
                    variant = SELECT_CUP_COURSE_MODE_NO_CONNECTION;
                } else if (GetMultiSimple() != 0) {
                    variant = SELECT_CUP_COURSE_MODE_MULTI_SIMPLE;
                } else {
                    variant = SELECT_CUP_COURSE_MODE_MULTI_OTHER;
                }
                menu = gMenuScene;
                InitSelectCupCourse(MenuGetCurrentHeap(), menu->mMainOam, menu->mSubOam, variant);
                break;
            case SCREEN_SELECT_CUP_COURSE_TIME_ATTACK:
                InitSelectCupCourse(MenuGetCurrentHeap(), menu->mMainOam, menu->mSubOam,
                                    SELECT_CUP_COURSE_MODE_WITH_GHOSTS);
                break;
            case SCREEN_SELECT_RACE_RULE_VS:
                if (MenuGetConnectionKind() == CONNECTION_KIND_NONE) {
                    variant = SELECT_RACE_RULE_MODE_VS_NO_CONNECTION;
                } else if (GetMultiSimple() != 0) {
                    variant = SELECT_RACE_RULE_MODE_VS_MULTI_SIMPLE;
                } else {
                    variant = SELECT_RACE_RULE_MODE_VS_MULTI;
                }
                menu = gMenuScene;
                InitSelectRaceRule(MenuGetCurrentHeap(), (s32) menu->mMainOam, menu->mSubOam, variant);
                break;
            case SCREEN_SELECT_RACE_RULE_BATTLE:
                if (MenuGetConnectionKind() == CONNECTION_KIND_NONE) {
                    variant = SELECT_RACE_RULE_MODE_BATTLE_NO_CONNECTION;
                } else if (GetMultiSimple() != 0) {
                    variant = SELECT_RACE_RULE_MODE_BATTLE_MULTI_SIMPLE;
                } else {
                    variant = SELECT_RACE_RULE_MODE_BATTLE_MULTI;
                }
                menu = gMenuScene;
                InitSelectRaceRule(MenuGetCurrentHeap(), (s32) menu->mMainOam, menu->mSubOam, variant);
                break;
            case SCREEN_SELECT_GAME:
                variant = (MenuGetConnectionKind() == CONNECTION_KIND_NONE) ? SELECT_GAME_MODE_NO_CONNECTION
                                                                            : SELECT_GAME_MODE_CONNECTION;
                menu = gMenuScene;
                InitSelectGame(MenuGetCurrentHeap(), variant, menu->mMainOam, menu->mSubOam);
                break;
            case SCREEN_SELECT_BATTLE_STAGE:
                variant = (GetRaceSetupCopy()->mBattleKind == BATTLE_KIND_BALLOON) ? SELECT_BATTLE_STAGE_VARIANT_BALLOON
                                                                                   : SELECT_BATTLE_STAGE_VARIANT_SHINE;
                menu = gMenuScene;
                InitSelectBattleStage(MenuGetCurrentHeap(), variant, menu->mMainOam, menu->mSubOam);
                break;
            case SCREEN_MISSION_RUN_LVSEL:
                InitMissionRunLVsel(MenuGetCurrentHeap(), menu->mMainOam, menu->mSubOam);
                break;
            case SCREEN_MISSION_RUN_MSSEL:
                InitMissionRunMSsel(MenuGetCurrentHeap(), menu->mMainOam, menu->mSubOam);
                break;
            case SCREEN_TIME_ATTACK_TOP_MENU:
                InitTimeAttackTopMenu(MenuGetCurrentHeap(), menu->mMainOam, menu->mSubOam);
                break;
            case SCREEN_SELECT_GHOST:
                InitSelectGhost(MenuGetCurrentHeap(), menu->mMainOam, menu->mSubOam);
                break;
            case SCREEN_SELECT_CUP_M_VS:
            case SCREEN_SELECT_CUP_M_TIME_ATTACK:
                InitSelectCupM(MenuGetCurrentHeap(), menu->mMainOam, menu->mSubOam);
                break;
            case SCREEN_NEXT_RACE_SETUP:
                SetNextRaceSetupFromCopy();
                break;
        }
        switch (gMenuScene->mScreenNumber) {
            case SCREEN_SELECT_RACE_RULE_VS:
            case SCREEN_SELECT_CUP_GRID_VS:
            case SCREEN_SELECT_CUP_M_VS:
            case SCREEN_SELECT_CUP_COURSE_VS:
            case SCREEN_SELECT_GAME:
            case SCREEN_SELECT_RACE_RULE_BATTLE:
            case SCREEN_SELECT_BATTLE_STAGE:
                gMenuScene->mDataSharingSyncStarted = FALSE;
                gMenuScene->mDataSharingSyncFinished = FALSE;
                break;
            case SCREEN_SELECT_CHARACTER_VS:
            case SCREEN_SELECT_CHARACTER_BATTLE:
                if (GetPreviousMenuScreenNumber() == SCREEN_SELECT_GAME) {
                    gMenuScene->mDataSharingSyncStarted = FALSE;
                    gMenuScene->mDataSharingSyncFinished = FALSE;
                }
                break;
        }
    }
}

void ReleasePreviousMenuScreen(void) {
    if (gMenuScene->mScreenNumber != gMenuScene->mPreviousScreenNumber) {
        switch (gMenuScene->mPreviousScreenNumber) {
            case SCREEN_SELECT_ENGINE:
                ReleaseSelectEngine();
                break;
            case SCREEN_SELECT_CHARACTER_GRAND_PRIX:
            case SCREEN_SELECT_CHARACTER_VS:
            case SCREEN_SELECT_CHARACTER_BATTLE:
            case SCREEN_SELECT_CHARACTER_TIME_ATTACK:
                ReleaseSelectCharacter();
                break;
            case SCREEN_SELECT_KART_GRAND_PRIX:
            case SCREEN_SELECT_KART_VS:
            case SCREEN_SELECT_KART_TIME_ATTACK:
                ReleaseSelectKart();
                break;
            case SCREEN_SELECT_CUP_GRID_GRAND_PRIX:
            case SCREEN_SELECT_CUP_GRID_VS:
            case SCREEN_SELECT_CUP_GRID_TIME_ATTACK:
                ReleaseSelectCupGrid();
                break;
            case SCREEN_SELECT_CUP_COURSE_VS:
            case SCREEN_SELECT_CUP_COURSE_TIME_ATTACK:
                ReleaseSelectCupCourse();
                break;
            case SCREEN_SELECT_RACE_RULE_VS:
            case SCREEN_SELECT_RACE_RULE_BATTLE:
                ReleaseSelectRaceRule();
                break;
            case SCREEN_SELECT_GAME:
                ReleaseSelectGame();
                break;
            case SCREEN_SELECT_BATTLE_STAGE:
                ReleaseSelectBattleStage();
                break;
            case SCREEN_MISSION_RUN_LVSEL:
                ReleaseMissionRunLVsel();
                break;
            case SCREEN_MISSION_RUN_MSSEL:
                ReleaseMissionRunMSsel();
                break;
            case SCREEN_TIME_ATTACK_TOP_MENU:
                ReleaseTimeAttackTopMenu();
                break;
            case SCREEN_SELECT_GHOST:
                ReleaseSelectGhost();
                break;
            case SCREEN_SELECT_CUP_M_VS:
            case SCREEN_SELECT_CUP_M_TIME_ATTACK:
                ReleaseSelectCupM();
                break;
        }
    }
}
