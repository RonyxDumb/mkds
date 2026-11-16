#include "Main/Unknown/code_020cbad0.h"
#include "Main/Unknown/code_0202bb80.h"
#include "Main/Unknown/code_0203206c.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_0203be88.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020cae8c.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_020b47b4.h"
#include "Main/Unknown/code_020cae54.h"
#include "Main/Unknown/code_020cb99c.h"
#include "Main/Unknown/code_020cba30.h"
#include "Main/Unknown/code_020cc168.h"
#include "Main/Unknown/code_020cc0e4.h"
#include "Main/Unknown/code_020cc134.h"
#include "Main/Unknown/code_020cc000.h"
#include "Main/Unknown/code_020cc744.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Unknown/code_02029000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020ccc74.h"
#include "Main/Unknown/code_0212a910.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/code_02029a24.h"
#include "Main/Unknown/code_02037000.h"
#include "Main/Unknown/code_02038000.h"
#include "Main/Unknown/code_0203b000.h"
#include "code_020176b0.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0211e0c4.h"
#include "Main/Unknown/code_020d1108.h"
#include "Main/Ui/BackScreen.h"
#include "Main/Unknown/code_02125de0.h"
#include "Main/Unknown/code_021281fc.h"
#include "Main/Unknown/code_0212a000.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02116ec0.h"
#include "Main/Unknown/code_0211f240.h"
#include "Main/Unknown/code_0211db90.h"
#include "Main/Unknown/code_021189f4.h"
#include "Main/Unknown/code_02119e14.h"
#include "Main/Unknown/code_02027df8.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "01/code_ov001_02197b34.h"
#include "01/code_0219eab4.h"
#include "01/code_0219f8ec.h"
#include "01/code_0219d50c.h"
#include "01/code_021a11a4.h"
#include "01/code_0219b540.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_0202b000.h"
#include "Main/Unknown/code_0202c000.h"
#include "Main/Unknown/code_02032000.h"
#include "Main/Unknown/code_02062000.h"
#include "Main/Unknown/code_02078000.h"
#include "Main/Unknown/code_02025f80.h"

#pragma thumb on
#pragma optimize_for_size on
void menu_create(void) {
    MenuScene *menu;
    Unk02125de0Arg config;
    Unk02180774 *displaySettings;

    gMenuSceneState = heap_alloc(menu_process_getCurrentHeapHandle(), 0x960);
    menu_createRaceConfig(menu_process_getCurrentHeapHandle());
    displaySettings = dc_createDisplayConfig(menu_process_getCurrentHeapHandle(), menu_sDisplayConfigBase);
    SetMainBg0Record(displaySettings, 1, 0, 0, 0, 0xd, 2, 0);
    func_020cc2f4(displaySettings, 0, 0, 0, 0, 0xc, 0, 0);
    func_020cc2c0(displaySettings, 0, 0, 0, 0, 0x1e, 6);
    func_020cc28c(displaySettings, 3, 0, 0, 0, 0x1d, 4);
    SetSubBg0Record(displaySettings, 0, 0, 0, 0, 0xb, 0, 0);
    SetSubBg1Record(displaySettings, 3, 0, 0, 0, 0xd, 0, 0);
    func_020cc1e0(displaySettings, 0, 0, 0, 0, 0xe, 0);
    func_020cc1ac(displaySettings, 2, 0, 0, 0, 0xf, 0);
    dc_setDisplayConfig(displaySettings);
    gMenuSceneState->mFramesSinceScreenSwitch = 0;
    gMenuSceneState->mUnk_004 = 1;
    gMenuSceneState->mPreviousScreenNumber = 0x1f;
    gMenuSceneState->mScreenNumber = 0x1f;
    gMenuSceneState->mNextScreenNumber = 0x1f;
    gMenuSceneState->mScreenInitPending = TRUE;
    gMenuSceneState->mUnk_958 = TRUE;
    gMenuSceneState->mUnk_95c = TRUE;
    menu_setupStates();
    oam_clearResetBuffers(gMenuSceneState->mMainOam, gMenuSceneState->mSubOam);
    arc_setHeapGroupId(9);
    race_initG3d();
    arc_setHeapGroupId(5);
    race_initResManagement();
    arc_setHeapGroupId(9);
    if (menu_MB_IsMultiBootChild_22() == 0) {
        SPM_InitCharacterKartSelect(menu_process_getCurrentHeapHandle());
        RequestKartModelMenuCharacter(-1);
        RequestKartModelMenuKart(-1);
    }
    arc_setHeapGroupId(5);
    if (menu_MB_IsMultiBootChild_22() == 0) {
        InitGhostRecordSet(menu_process_getCurrentHeapHandle());
        cpic_init();
        g2du_unpackPaletteData(&gMenuSceneState->mSinglePlaySelectModeMONclr,
                     m2d_getSceneArcFile("common/single_play_select_mode_m_o.NCLR"));
        g2du_unpackCharacterData(&gMenuSceneState->mSinglePlaySelectModeMNcgr,
                      m2d_getSceneArcFile("common/single_play_select_mode_m.nce.ncgr"));
        g2du_unpackCellBankData(&gMenuSceneState->mSinglePlaySelectModeMNcer,
                     m2d_getSceneArcFile("common/single_play_select_mode_m.nce.ncer"));
        gMenuSceneState->mSinglePlaySelectModeMBncl = m2d_getSceneArcFile("common/single_play_select_mode_m.bncl");
        gMenuSceneState->mUnk_944 = 0;
        g2du_unpackPaletteData(&gMenuSceneState->mSinglePlaySelectModeSONclr,
                     m2d_getSceneArcFile("common/single_play_select_mode_s_o.NCLR"));
        g2du_unpackCharacterData(&gMenuSceneState->mSinglePlaySelectModeSNcgr,
                      m2d_getSceneArcFile("common/single_play_select_mode_s.nce.ncgr"));
        g2du_unpackCellBankData(&gMenuSceneState->mSinglePlaySelectModeSNcer,
                     m2d_getSceneArcFile("common/single_play_select_mode_s.nce.ncer"));
        gMenuSceneState->mSinglePlaySelectModeSBncl = m2d_getSceneArcFile("common/single_play_select_mode_s.bncl");
        gMenuSceneState->mSinglePlaySelectModeSBnbl = m2d_getSceneArcFile("common/single_play_select_mode_s.bnbl");
        menu = gMenuSceneState;
        jn_ui_initLayout(menu_process_getCurrentHeapHandle(), menu->mSinglePlaySelectModeMBncl, NULL,
                        &menu->mSinglePlaySelectModeMLayoutTable);
        menu = gMenuSceneState;
        jn_ui_initLayout(menu_process_getCurrentHeapHandle(), menu->mSinglePlaySelectModeSBncl, NULL,
                        &menu->mSinglePlaySelectModeSLayoutTable);
        menu = gMenuSceneState;
        jn_ui_setCellIsTranslucent(0, 1, menu->mSinglePlaySelectModeSNcer, menu->mSinglePlaySelectModeSBncl);
        menu = gMenuSceneState;
        jn_ui_setCellIsTranslucent(1, 1, menu->mSinglePlaySelectModeSNcer, menu->mSinglePlaySelectModeSBncl);
        menu = gMenuSceneState;
        jn_ui_setCellIsTranslucent(2, 1, menu->mSinglePlaySelectModeSNcer, menu->mSinglePlaySelectModeSBncl);
        menu = gMenuSceneState;
        jn_ui_setCellIsTranslucent(3, 1, menu->mSinglePlaySelectModeSNcer, menu->mSinglePlaySelectModeSBncl);
        menu = gMenuSceneState;
        jn_ui_setCellIsTranslucent(4, 1, menu->mSinglePlaySelectModeSNcer, menu->mSinglePlaySelectModeSBncl);
    }
    LoadPlayerEntryListFiles();
    InitPlayerEntryList(menu_process_getCurrentHeapHandle(), gMenuSceneState->mMainOam);
    gMenuSceneState->mUnk_954 = func_0203bedc(menu_process_getCurrentHeapHandle());
    menu_GX_SetOBJVRamModeChar(0x10);
    menu_GXS_SetOBJVRamModeChar(0x10);
    menu_G2_SetBlendAlpha(0, 0x3f, 6, 10);
    menu_G2S_SetBlendAlpha(0, 0x3f, 6, 10);
    menu_GX_SetVisibleWnd(0);
    menu_GXS_SetVisibleWnd(0);
    if (menu_MB_IsMultiBootChild_22() == 0) {
        func_02025f90();
        func_02027df8();
        LoadTimeAttackTopMenuData();
        LoadSelectGhostAndKartIconData();
        LoadMissionRunLVselData();
        LoadMissionRunMSselAndBossIconData();
        LoadSelectBattleStageData();
        LoadSelectEngineData();
        LoadSelectCupGridData();
        func_0211f240();
        LoadSelectCupCourseData();
    }
    LoadSelectGameData();
    LoadSelectRaceRuleAndWaitData();
    config.mUnk_00 = menu_MB_IsMultiBootChild_22();
    config.mUnk_04 = m2d_getFont(1);
    config.mUnk_08 = 0;
    config.mUnk_0c = 1;
    config.mUnk_10 = 0;
    config.mUnk_14 = 1;
    config.mUnk_18 = m2d_getFont(2);
    config.mUnk_1c = 1;
    config.mUnk_20 = 1;
    config.mUnk_24 = 0;
    gmenu_unpackData();
    gmenu_init(menu_process_getCurrentHeapHandle(), &config);
    if (menu_sysdat_getOverlayRelatedNum() == 2) {
        ClearSelectReturnDisplayBitOn();
    }
    InitLinkLevelIcons(menu_process_getCurrentHeapHandle(), gMenuSceneState->mMainOam);
    switch (func_020cc120()) {
        case 0:
            menu_gotoState(0, 0x1f);
            func_020cc10c(1);
            break;
        case 1:
            menu_loadLastRaceConfig();
            switch (menu_getRaceConfig()->mMode) {
                case 0:
                    menu_gotoState(5, 0x1f);
                    func_020cbabc(0);
                    func_020cc10c(1);
                    break;
                case 3:
                    menu_gotoState(8, 0x1f);
                    break;
                case 2:
                    menu_gotoState(0xf, 0x1f);
                    break;
                case 1:
                    menu_gotoState(0x15, 0x1f);
                    func_020cbabc(0);
                    func_020cc10c(1);
                    break;
            }
            break;
        case 2:
            menu_loadLastRaceConfig();
            switch (menu_getRaceConfig()->mMode) {
                case 3:
                    menu_gotoState(0xb, 0x1f);
                    break;
                case 2:
                    menu_gotoState(SCREEN_SELECT_BATTLE_STAGE, 0x1f);
                    break;
                case 1:
                    menu_gotoState(0x17, 0x1f);
                    func_020cbabc(0);
                    func_020cc10c(1);
                    break;
            }
            break;
        case 3:
            menu_loadLastRaceConfig();
            if (func_020cc0f8() != 0 || func_020cc0e4() != 0) {
                menu_gotoState(SCREEN_MISSION_RUN_LVSEL, 0x1f);
            } else {
                menu_gotoState(SCREEN_MISSION_RUN_MSSEL, 0x1f);
            }
            func_020cbabc(0);
            func_020cc10c(1);
            break;
        case 4:
            menu_gotoState(0xe, 0x1f);
            break;
        case 5:
            menu_loadLastRaceConfig();
            menu_getRaceConfig()->mMode = 1;
            menu_gotoState(SCREEN_TIME_ATTACK_TOP_MENU, 0x1f);
            func_020cbabc(0);
            func_020cc10c(1);
            break;
    }
    AllocSinglePlayerMenuInfo(menu_process_getCurrentHeapHandle());
    switch (menu_getRaceConfig()->mMode) {
        case 0:
        default:
            gMenuSceneState->mSinglePlaySelectModeIndex = 0;
            break;
        case 1:
            gMenuSceneState->mSinglePlaySelectModeIndex = 1;
            break;
        case 2:
            gMenuSceneState->mSinglePlaySelectModeIndex = 3;
            break;
        case 3:
            gMenuSceneState->mSinglePlaySelectModeIndex = 2;
            break;
        case 4:
            gMenuSceneState->mSinglePlaySelectModeIndex = 4;
            break;
    }
    gMenuSceneState->mUnk_934 = FALSE;
    gMenuSceneState->mUnk_938 = 0;
}
#pragma thumb off

u16 *menu_MB_GetMultiBootParam2(void) {
    return (u16 *) 0x27ffc40;
}

BOOL menu_MB_IsMultiBootChild2(void) {
    return *menu_MB_GetMultiBootParam2() == 2;
}

s32 menu_MB_IsMultiBootChild_22(void) {
    return menu_MB_IsMultiBootChild2();
}
