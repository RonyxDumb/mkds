#include "Main/Menu/menu_screen_init.h"
#include "Main/Menu/select_character.h"
#include "Main/Menu/select_game.h"
#include "Main/Menu/single_play_select_screen3.h"
#include "Main/Menu/next.h"
#include "01/Menu/select_engine.h"
#include "Main/Menu/multi_simple.h"
#include "Main/Menu/menu_connection_kind.h"
#include "Main/Menu/menu_heap.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_02029890.h"
#include "01/Menu/select_battle_stage_screen.h"
#include "01/Menu/mission_run_level_select.h"
#include "01/Menu/mission_run_mission_select.h"
#include "01/Menu/time_attack_top_menu.h"
#include "01/Menu/select_ghost.h"
#include "Main/Unknown/code_02026000.h"
#include "Main/Unknown/code_02028000.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_0211f498.h"
#include "Main/Unknown/code_02128000.h"
#include "Main/Unknown/code_0212b000.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/code_02027e78.h"
#include "Main/Unknown/code_02117db0.h"
#include "Main/Unknown/code_021196f4.h"
#include "Main/Unknown/code_0211b23c.h"
#include "Main/Menu/select_cup_m.h"
#include "Main/Unknown/code_02032000.h"
#include "Main/Unknown/code_02028864.h"
#include "Main/Menu/menu_screen_switch.h"

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
            case 5:
            case 8:
            case 15:
            case 21:
                variant = (MenuGetConnectionKind() == 0) ? UNK_020CB6C0_0 : UNK_020CB6C0_1;
                menu = gMenuScene;
                InitSelectCharacter(MenuGetCurrentHeap(), variant, menu->mMainOam, menu->mSubOam);
                break;
            case 6:
            case 9:
            case 22:
                variant = (MenuGetConnectionKind() == 0) ? UNK_020CB6C0_0 : UNK_020CB6C0_1;
                menu = gMenuScene;
                InitSelectKart(MenuGetCurrentHeap(), variant, menu->mMainOam, menu->mSubOam);
                break;
            case 7:
                InitSelectCupGrid(MenuGetCurrentHeap(), menu->mMainOam, menu->mSubOam, 0);
                break;
            case 11:
                if (MenuGetConnectionKind() == 0) {
                    variant = 2;
                } else if (GetMultiSimple() != 0) {
                    variant = 3;
                } else {
                    variant = 4;
                }
                menu = gMenuScene;
                InitSelectCupGrid(MenuGetCurrentHeap(), menu->mMainOam, menu->mSubOam, variant);
                break;
            case 23:
                InitSelectCupGrid(MenuGetCurrentHeap(), menu->mMainOam, menu->mSubOam, 1);
                break;
            case 13:
                if (MenuGetConnectionKind() == 0) {
                    variant = 1;
                } else if (GetMultiSimple() != 0) {
                    variant = 2;
                } else {
                    variant = 3;
                }
                menu = gMenuScene;
                InitSelectCupCourse(MenuGetCurrentHeap(), menu->mMainOam, menu->mSubOam, variant);
                break;
            case 25:
                InitSelectCupCourse(MenuGetCurrentHeap(), menu->mMainOam, menu->mSubOam, 0);
                break;
            case 10:
                if (MenuGetConnectionKind() == 0) {
                    variant = 0;
                } else if (GetMultiSimple() != 0) {
                    variant = 2;
                } else {
                    variant = 4;
                }
                menu = gMenuScene;
                InitSelectRaceRule(MenuGetCurrentHeap(), (s32) menu->mMainOam, menu->mSubOam, variant);
                break;
            case 16:
                if (MenuGetConnectionKind() == 0) {
                    variant = 1;
                } else if (GetMultiSimple() != 0) {
                    variant = 3;
                } else {
                    variant = 5;
                }
                menu = gMenuScene;
                InitSelectRaceRule(MenuGetCurrentHeap(), (s32) menu->mMainOam, menu->mSubOam, variant);
                break;
            case 14:
                variant = (MenuGetConnectionKind() == 0) ? UNK_020CB6C0_0 : UNK_020CB6C0_1;
                menu = gMenuScene;
                InitSelectGame(MenuGetCurrentHeap(), variant, menu->mMainOam, menu->mSubOam);
                break;
            case SCREEN_SELECT_BATTLE_STAGE:
                variant = (GetRaceSetupCopy()->mBattleKind == BATTLE_KIND_BALLOON) ? UNK_020CB6C0_1 : UNK_020CB6C0_0;
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
                InitTimeAttackTopMenu(MenuGetCurrentHeap(), menu->mMainOam, (s32) menu->mSubOam);
                break;
            case SCREEN_SELECT_GHOST:
                InitSelectGhost(MenuGetCurrentHeap(), (u32) menu->mMainOam, (u32) menu->mSubOam);
                break;
            case 12:
            case 24:
                InitSelectCupM(MenuGetCurrentHeap(), menu->mMainOam, menu->mSubOam);
                break;
            case 29:
                SetNextRaceSetupFromCopy();
                break;
        }
        switch (gMenuScene->mScreenNumber) {
            case 10:
            case 11:
            case 12:
            case 13:
            case 14:
            case 16:
            case SCREEN_SELECT_BATTLE_STAGE:
                gMenuScene->mDataSharingSyncStarted = FALSE;
                gMenuScene->mDataSharingSyncFinished = FALSE;
                break;
            case 8:
            case 15:
                if (GetPreviousMenuScreenNumber() == 0xe) {
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
            case 5:
            case 8:
            case 15:
            case 21:
                ReleaseSelectCharacter();
                break;
            case 6:
            case 9:
            case 22:
                ReleaseSelectKart();
                break;
            case 7:
            case 11:
            case 23:
                ReleaseSelectCupGrid();
                break;
            case 13:
            case 25:
                ReleaseSelectCupCourse();
                break;
            case 10:
            case 16:
                ReleaseSelectRaceRule();
                break;
            case 14:
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
            case 12:
            case 24:
                ReleaseSelectCupM();
                break;
        }
    }
}
