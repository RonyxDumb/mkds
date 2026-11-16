#include "Main/Unknown/code_020cb618.h"
#include "Main/Unknown/code_02025f80.h"
#include "Main/Unknown/code_0203206c.h"
#include "Main/Unknown/code_020cae8c.h"
#include "Main/Unknown/code_020cc744.h"
#include "01/code_021a11a4.h"
#include "Main/Unknown/code_020cae38.h"
#include "Main/Unknown/code_020cae54.h"
#include "Main/Unknown/code_020cb99c.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_02029890.h"
#include "01/code_0219c784.h"
#include "01/code_0219eab4.h"
#include "01/code_0219f8ec.h"
#include "01/code_ov001_02197b34.h"
#include "01/code_0219b540.h"
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
#include "Main/Scene/SelectCupM.h"
#include "Main/Unknown/code_02032000.h"
#include "Main/Unknown/code_02028864.h"
#include "Main/Unknown/code_020ccc74.h"

#pragma thumb on
#pragma optimize_for_size on
void menu_initSubMenu(void) {
    MenuScene *menu;
    s32 variant;

    menu = gMenuSceneState;
    if (menu->mScreenNumber != menu->mPreviousScreenNumber) {
        switch (menu->mScreenNumber) {
            case SCREEN_SELECT_ENGINE:
                LoadCCSelectionMenu(menu_process_getCurrentHeapHandle(), menu->mMainOam, menu->mSubOam);
                break;
            case 5:
            case 8:
            case 15:
            case 21:
                variant = (menu_sysdat_getOverlayRelatedNum() == 0) ? UNK_020CB6C0_0 : UNK_020CB6C0_1;
                menu = gMenuSceneState;
                menucs_init(menu_process_getCurrentHeapHandle(), variant, menu->mMainOam, menu->mSubOam);
                break;
            case 6:
            case 9:
            case 22:
                variant = (menu_sysdat_getOverlayRelatedNum() == 0) ? UNK_020CB6C0_0 : UNK_020CB6C0_1;
                menu = gMenuSceneState;
                SPM_LoadKartSelectionMenu(menu_process_getCurrentHeapHandle(), variant, menu->mMainOam, menu->mSubOam);
                break;
            case 7:
                SPM_LoadCupSelectionMenu(menu_process_getCurrentHeapHandle(), menu->mMainOam, menu->mSubOam, 0);
                break;
            case 11:
                if (menu_sysdat_getOverlayRelatedNum() == 0) {
                    variant = 2;
                } else if (menu_sysdat_getIsMBChild() != 0) {
                    variant = 3;
                } else {
                    variant = 4;
                }
                menu = gMenuSceneState;
                SPM_LoadCupSelectionMenu(menu_process_getCurrentHeapHandle(), menu->mMainOam, menu->mSubOam, variant);
                break;
            case 23:
                SPM_LoadCupSelectionMenu(menu_process_getCurrentHeapHandle(), menu->mMainOam, menu->mSubOam, 1);
                break;
            case 13:
                if (menu_sysdat_getOverlayRelatedNum() == 0) {
                    variant = 1;
                } else if (menu_sysdat_getIsMBChild() != 0) {
                    variant = 2;
                } else {
                    variant = 3;
                }
                menu = gMenuSceneState;
                InitSelectCupCourse(menu_process_getCurrentHeapHandle(), menu->mMainOam, menu->mSubOam, variant);
                break;
            case 25:
                InitSelectCupCourse(menu_process_getCurrentHeapHandle(), menu->mMainOam, menu->mSubOam, 0);
                break;
            case 10:
                if (menu_sysdat_getOverlayRelatedNum() == 0) {
                    variant = 0;
                } else if (menu_sysdat_getIsMBChild() != 0) {
                    variant = 2;
                } else {
                    variant = 4;
                }
                menu = gMenuSceneState;
                SPM_LoadRaceRulesMenu(menu_process_getCurrentHeapHandle(), (s32) menu->mMainOam, menu->mSubOam, variant);
                break;
            case 16:
                if (menu_sysdat_getOverlayRelatedNum() == 0) {
                    variant = 1;
                } else if (menu_sysdat_getIsMBChild() != 0) {
                    variant = 3;
                } else {
                    variant = 5;
                }
                menu = gMenuSceneState;
                SPM_LoadRaceRulesMenu(menu_process_getCurrentHeapHandle(), (s32) menu->mMainOam, menu->mSubOam, variant);
                break;
            case 14:
                variant = (menu_sysdat_getOverlayRelatedNum() == 0) ? UNK_020CB6C0_0 : UNK_020CB6C0_1;
                menu = gMenuSceneState;
                SPM_LoadBattleMenu(menu_process_getCurrentHeapHandle(), variant, menu->mMainOam, menu->mSubOam);
                break;
            case SCREEN_SELECT_BATTLE_STAGE:
                variant = (menu_getRaceConfig()->mBattleKind == BATTLE_KIND_BALLOON) ? UNK_020CB6C0_1 : UNK_020CB6C0_0;
                menu = gMenuSceneState;
                SPM_LoadBattleStageSelectionMenu(menu_process_getCurrentHeapHandle(), variant, menu->mMainOam, menu->mSubOam);
                break;
            case SCREEN_MISSION_RUN_LVSEL:
                SPM_LoadMissionRunMenu(menu_process_getCurrentHeapHandle(), menu->mMainOam, menu->mSubOam);
                break;
            case SCREEN_MISSION_RUN_MSSEL:
                SPM_LoadMissionRunLevelMenu(menu_process_getCurrentHeapHandle(), menu->mMainOam, menu->mSubOam);
                break;
            case SCREEN_TIME_ATTACK_TOP_MENU:
                menu_ta_init(menu_process_getCurrentHeapHandle(), menu->mMainOam, (s32) menu->mSubOam);
                break;
            case SCREEN_SELECT_GHOST:
                InitSelectGhost(menu_process_getCurrentHeapHandle(), (u32) menu->mMainOam, (u32) menu->mSubOam);
                break;
            case 12:
            case 24:
                InitSelectCupM(menu_process_getCurrentHeapHandle(), menu->mMainOam, menu->mSubOam);
                break;
            case 29:
                menu_configureRace();
                break;
        }
        switch (gMenuSceneState->mScreenNumber) {
            case 10:
            case 11:
            case 12:
            case 13:
            case 14:
            case 16:
            case SCREEN_SELECT_BATTLE_STAGE:
                gMenuSceneState->field958 = FALSE;
                gMenuSceneState->field95C = FALSE;
                break;
            case 8:
            case 15:
                if (menu_getPrevState() == 0xe) {
                    gMenuSceneState->field958 = FALSE;
                    gMenuSceneState->field95C = FALSE;
                }
                break;
        }
    }
}

void menu_destroySubMenu(void) {
    if (gMenuSceneState->mScreenNumber != gMenuSceneState->mPreviousScreenNumber) {
        switch (gMenuSceneState->mPreviousScreenNumber) {
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
                menu_ta_destroy();
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
