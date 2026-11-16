#include "Main/Menu/menu.h"
#include "Main/Scene/display_settings.h"
#include "Main/Menu/single_play_select_screen3.h"
#include "Main/Race/race_setup.h"
#include "Main/Menu/multi_simple.h"
#include "Main/Menu/menu_connection_kind.h"
#include "Main/Menu/current.h"
#include "Main/Graphics/oam_upload.h"
#include "Main/Graphics/scene_text.h"
#include "Main/Menu/menu_screen_callbacks.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "01/Scene/test_scene.h"
#include "registers.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/Menu/player_entry_list.h"
#include "Main/Menu/select_game.h"
#include "Main/System/heap.h"
#include "Main/Menu/title_scene.h"
#include "Main/Race/race.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/System/file_in_loaded.h"
#include "Main/Menu/menu_heap.h"
#include "Main/Menu/menu_entry_kind.h"
#include "Main/Menu/next.h"
#include "Main/Menu/menu_screen_switch.h"
#include "Main/Menu/message_screen.h"
#include "Main/System/interpolation_value.h"
#include "Main/System/heap_call.h"
#include "font_glyph_layout.h"
#include "Main/Graphics/cell_file_set.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Menu/multi_select_member_group.h"
#include "Main/Save/buddy_record_time.h"
#include "cell_transfer_state.h"
#include "heap_expanded_allocator.h"
#include "Main/System/result_archive_path.h"
#include "Main/Race/ghost_record_set.h"
#include "Main/Menu/cup_picture_load.h"
#include "Main/Graphics/back_screen.h"
#include "Main/Graphics/scene_text_init.h"
#include "Main/Menu/select_return.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Menu/picks_holder.h"
#include "Main/Menu/trophy_icon.h"
#include "Main/Menu/select_race_rule_load.h"
#include "Main/Menu/select_cup_course.h"
#include "Main/Menu/select_race_rule.h"
#include "Main/Menu/select_kart_data.h"
#include "01/Menu/time_attack_top_menu.h"
#include "01/Menu/mission_run_level_select.h"
#include "01/Menu/mission_run_mission_select.h"
#include "01/Menu/select_battle_stage_data.h"
#include "01/Menu/select_engine.h"
#include "01/Menu/select_ghost.h"
#include "Main/Menu/keyboard_cursor_targets.h"
#include "Main/Kart/kart_ai_item_use.h"
#include "Main/Menu/select_character.h"
#include "Main/Menu/select_race_rule_state.h"
#include "Main/Menu/menu_shared_clear.h"
#include "01/Menu/mission_run_screen_registers.h"
#include "01/Menu/select_cup_grid_registers.h"
#include "01/Menu/select_cup_grid_update.h"
#include "01/Menu/select_screen_registers.h"
#include "Main/Menu/battle_select_race_rule.h"
#include "Main/Menu/battle_select_race_rule_registers.h"
#include "Main/Menu/battle_stage_entry.h"
#include "Main/Menu/menu_screen27_return.h"
#include "Main/Menu/menu_screen28_return.h"
#include "Main/Menu/menu_screen29_return.h"
#include "Main/Menu/select_battle_stage.h"
#include "Main/Menu/select_game_update.h"
#include "Main/Menu/single_play_select_screen1_registers.h"
#include "Main/Menu/vs_select_cup_m.h"
#include "Main/Scene/request_ghost_scene.h"
#include "Main/Scene/request_race_or_wl_menu.h"
#include "Main/Scene/request_title_scene.h"

ScreenCallbacks gMenuScreenCallbacks[0x1e] = {
    {WriteSinglePlaySelect0Registers, (void (*)(u32)) UpdateSinglePlaySelectMenuScreen0},
    {WriteSinglePlaySelect1Registers, (void (*)(u32)) UpdateSinglePlaySelectInput},
    {WriteSinglePlaySelect2Registers, (void (*)(u32)) UpdateSinglePlaySelectMenuScreen2},
    {WriteSinglePlaySelect3Registers, (void (*)(u32)) UpdateSinglePlaySelectMenuScreen3},
    {WriteSelectEngineScreenRegisters, (void (*)(u32)) UpdateSelectEngine},
    {WriteSelectCharacterScreenRegisters, (void (*)(u32)) UpdateSelectCharacter},
    {WriteSelectKartScreenRegisters, (void (*)(u32)) UpdateSelectKart},
    {WriteSelectCupGridScreenRegisters, (void (*)(u32)) UpdateSelectCupGrid},
    {WriteVsSelectCharacterRegisters, (void (*)(u32)) UpdateVsSelectCharacter},
    {WriteVsSelectKartRegisters, (void (*)(u32)) UpdateVsSelectKart},
    {WriteVsSelectRaceRuleRegisters, (void (*)(u32)) UpdateVsSelectRaceRule},
    {WriteVsSelectCupGridRegisters, (void (*)(u32)) UpdateVsSelectCupGrid},
    {WriteVsSelectCupMRegisters, (void (*)(u32)) UpdateVsSelectCupM},
    {WriteVsSelectCupCourseRegisters, (void (*)(u32)) UpdateVsSelectCupCourse},
    {WriteSelectGameRegisters, (void (*)(u32)) UpdateSelectGame},
    {WriteBattleSelectCharacterRegisters, (void (*)(u32)) UpdateBattleSelectCharacter},
    {WriteBattleSelectRaceRuleRegisters, (void (*)(u32)) UpdateBattleSelectRaceRule},
    {WriteBattleStageScreenRegisters, (void (*)(u32)) UpdateSelectBattleStage},
    {WriteMissionRunLVselScreenRegisters, (void (*)(u32)) UpdateMissionRunLVsel},
    {WriteMissionRunMSselScreenRegisters, (void (*)(u32)) UpdateMissionRunMSsel},
    {WriteTimeAttackTopMenuRegisters, (void (*)(u32)) UpdateTimeAttackTopMenu},
    {WriteTimeAttackCharacterRegisters, (void (*)(u32)) UpdateTimeAttackSelectCharacter},
    {WriteTimeAttackKartRegisters, (void (*)(u32)) UpdateTimeAttackSelectKart},
    {WriteTimeAttackCupGridRegisters, (void (*)(u32)) UpdateTimeAttackSelectCupGrid},
    {WriteSelectCupMScreenRegisters, (void (*)(u32)) UpdateSelectCupM},
    {WriteTimeAttackCupCourseRegisters, (void (*)(u32)) UpdateTimeAttackSelectCupCourse},
    {WriteSelectGhostScreenRegisters, (void (*)(u32)) UpdateSelectGhost},
    {MenuScreen27Nop, (void (*)(u32)) RequestTitleScene},
    {MenuScreen28Nop, (void (*)(u32)) RequestGhostScene},
    {MenuScreen29Nop, (void (*)(u32)) RequestRaceOrWLMenuScene},
};

struct MenuScene *gMenuScene;
const u8 gMenuDisplaySettingsDesc[40] = {1, 0, 0x1f, 0, 0x1f, 0, 1, 0, 0,    0, 1, 0, 0, 0, 4, 0, 0x60, 0, 0, 0,
                                         0, 0, 3,    0, 0x10, 0, 0, 0, 0x80, 0, 0, 1, 0, 0, 0, 0, 8,    0, 0, 0};

// Returns the mission table row, or -1 outside Mission Run.
s32 GetRaceSetupMissionTableRow(void) {
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        return gRaceSetup->mMissionTableRow;
    }
    return -1;
}

// Returns the mission table column, or -1 outside Mission Run.
s32 GetRaceSetupMissionTableColumn(void) {
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        return gRaceSetup->mMissionTableColumn;
    }
    return -1;
}

#pragma thumb on
#pragma optimize_for_size on
// Fills the race setup copy from the current setup; some modes are remapped and the course can be forced.
void CopyCurrentToRaceSetupCopy(void) {
    u16 entryIndex;

    for (entryIndex = 0; entryIndex < 8; entryIndex++) {
        GetRaceSetupCopy()->mEntries[entryIndex].mCharacterIndex = GetCurrentCharacterIndex(entryIndex);
        GetRaceSetupCopy()->mEntries[entryIndex].mKartIndex = GetCurrentKartIndex(entryIndex);
        GetRaceSetupCopy()->mEntries[entryIndex].mPlayerKind = GetCurrentPlayerKind(entryIndex);
        if (GetCurrentUseTeams() != 0) {
            GetRaceSetupCopy()->mEntries[entryIndex].mTeamIndex = GetCurrentTeamIndex(entryIndex);
        } else {
            GetRaceSetupCopy()->mEntries[entryIndex].mTeamIndex = -1;
        }
        GetRaceSetupCopy()->mEntries[entryIndex].mListedCpuSlot = GetCurrentListedCpuSlot(entryIndex);
        GetRaceSetupCopy()->mEntries[entryIndex].mKartStored = 0;
    }
    GetRaceSetupCopy()->mCupIndex = GetCurrentCupIndex();
    GetRaceSetupCopy()->mCpuDifficulty = GetCurrentCpuDifficulty();
    GetRaceSetupCopy()->mKartCount = GetCurrentKartCount();
    if (MenuGetConnectionKind() != CONNECTION_KIND_NONE) {
        u32 currentMode;

        currentMode = GetCurrentMode();
        switch (currentMode) {
            case MODE_GRAND_PRIX:
            case MODE_TIME_ATTACK:
            case MODE_MISSION_RUN:
                GetRaceSetupCopy()->mMode = MODE_VS;
                break;
            case MODE_BATTLE:
            case MODE_VS:
            case MODE_WIFI:
                GetRaceSetupCopy()->mMode = currentMode;
                break;
        }
    } else {
        GetRaceSetupCopy()->mMode = GetCurrentMode();
    }
    if (GetMultiSimple() != 0) {
        GetRaceSetupCopy()->mCourseId = COURSE_ID_OLD_MARIO_SFC;
    } else {
        GetRaceSetupCopy()->mCourseId = GetCurrentCourseId();
    }
    GetRaceSetupCopy()->mEngineIndex = GetCurrentEngineIndex();
    GetRaceSetupCopy()->mMirrorMode = GetCurrentMirrorMode();
    GetRaceSetupCopy()->mUseTeams = GetCurrentUseTeams();
    GetRaceSetupCopy()->mBattleKind = GetCurrentBattleKind();
    GetRaceSetupCopy()->mBattleKind = GetCurrentBattleKind();
    GetRaceSetupCopy()->mCourseCount = GetCurrentCourseCount();
    GetRaceSetupCopy()->mRuleKind = GetCurrentRuleKind();
    if (GetCurrentMode() == MODE_MISSION_RUN) {
        GetRaceSetupCopy()->mMissionTableRow = GetRaceSetupMissionTableRow();
        GetRaceSetupCopy()->mMissionTableColumn = GetRaceSetupMissionTableColumn();
    }
}

void CopyMenuScreenCallbacks(void) {
    s32 screenIndex;

    for (screenIndex = 0; screenIndex < 0x1e; screenIndex++) {
        gMenuScene->mScreenCallbacks[screenIndex].mWriteRegisters = gMenuScreenCallbacks[screenIndex].mWriteRegisters;
        gMenuScene->mScreenCallbacks[screenIndex].mUpdate = gMenuScreenCallbacks[screenIndex].mUpdate;
    }
}

void WriteMenuSceneRegisters(void) {
    if (MenuMB_IsMultiBootChildWrapper() == 0) {
        AdvanceKartModelMenuLoad();
    }
    gMenuScene->mScreenCallbacks[gMenuScene->mScreenNumber].mWriteRegisters();
    WriteSceneTextRegisters();
    gMenuScene->mScreenSwitched = 0;
    UploadOamLists(gMenuScene->mMainOam, gMenuScene->mSubOam);
}
#pragma thumb off

void SetMainBg0Record(DisplaySettings *displaySettings, u32 cntLow2, u32 cntMosaic, u32 cntVal14, u32 cntVal7,
                      u32 cntVal8, u32 cntVal2, u32 cntVal13) {
    SetBg0Record(&displaySettings->mMainBgRecords, cntLow2, cntMosaic, cntVal14, cntVal7, cntVal8, cntVal2, cntVal13);
}

void SetMainBg1Record(DisplaySettings *displaySettings, u32 cntLow2, u32 cntMosaic, u32 cntVal14, u32 cntVal7,
                      u32 cntVal8, u32 cntVal2, u32 cntVal13) {
    SetBg1Record(&displaySettings->mMainBgRecords, cntLow2, cntMosaic, cntVal14, cntVal7, cntVal8, cntVal2, cntVal13);
}

void SetMainBg2RecordParams(DisplaySettings *displaySettings, u32 cntLow2, u32 cntMosaic, u32 cntVal14, u32 cntVal7Or13,
                            u32 cntVal8, u32 cntVal2) {
    SetBg2RecordParams(&displaySettings->mMainBgRecords, cntLow2, cntMosaic, cntVal14, cntVal7Or13, cntVal8, cntVal2);
}

void SetMainBg3RecordParams(DisplaySettings *displaySettings, u32 cntLow2, u32 cntMosaic, u32 cntVal14, u32 cntVal7Or13,
                            u32 cntVal8, u32 cntVal2) {
    SetBg3RecordParams(&displaySettings->mMainBgRecords, cntLow2, cntMosaic, cntVal14, cntVal7Or13, cntVal8, cntVal2);
}

void SetSubBg0Record(DisplaySettings *displaySettings, u32 cntLow2, u32 cntMosaic, u32 cntVal14, u32 cntVal7,
                     u32 cntVal8, u32 cntVal2, u32 cntVal13) {
    SetBg0Record(&displaySettings->mSubBgRecords, cntLow2, cntMosaic, cntVal14, cntVal7, cntVal8, cntVal2, cntVal13);
}

void SetSubBg1Record(DisplaySettings *displaySettings, u32 cntLow2, u32 cntMosaic, u32 cntVal14, u32 cntVal7,
                     u32 cntVal8, u32 cntVal2, u32 cntVal13) {
    SetBg1Record(&displaySettings->mSubBgRecords, cntLow2, cntMosaic, cntVal14, cntVal7, cntVal8, cntVal2, cntVal13);
}

void SetSubBg2RecordParams(DisplaySettings *displaySettings, u32 cntLow2, u32 cntMosaic, u32 cntVal14, u32 cntVal7Or13,
                           u32 cntVal8, u32 cntVal2) {
    SetBg2RecordParams(&displaySettings->mSubBgRecords, cntLow2, cntMosaic, cntVal14, cntVal7Or13, cntVal8, cntVal2);
}

void SetSubBg3RecordParams(DisplaySettings *displaySettings, u32 cntLow2, u32 cntMosaic, u32 cntVal14, u32 cntVal7Or13,
                           u32 cntVal8, u32 cntVal2) {
    SetBg3RecordParams(&displaySettings->mSubBgRecords, cntLow2, cntMosaic, cntVal14, cntVal7Or13, cntVal8, cntVal2);
}

void MenuGX_SetOBJVRamModeChar(u32 bits) {
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~(REG_GX_DISPCNT_EXOBJ_CH_MASK | REG_GX_DISPCNT_OBJMAP_CH_MASK)) | bits;
}

void MenuGXS_SetOBJVRamModeChar(u32 bits) {
    reg_GXS_DB_DISPCNT =
        (reg_GXS_DB_DISPCNT & ~(REG_GXS_DB_DISPCNT_EXOBJ_CH_MASK | REG_GXS_DB_DISPCNT_OBJMAP_CH_MASK)) | bits;
}

u32 MenuWriteMainWinEnableBits(u32 bits) {
    u32 newDispcnt = bits;
    u32 registerValue;
    registerValue = reg_GX_DISPCNT;
    registerValue = (registerValue) & ~(0xe000u);
    newDispcnt = (registerValue) | ((newDispcnt << 13));
    reg_GX_DISPCNT = newDispcnt;
    return newDispcnt;
}

u32 MenuWriteSubWinEnableBits(u32 bits) {
    u32 newDispcnt = bits;
    u32 registerValue;
    registerValue = reg_GXS_DB_DISPCNT;
    registerValue = (registerValue) & ~(0xe000u);
    newDispcnt = (registerValue) | ((newDispcnt << 13));
    reg_GXS_DB_DISPCNT = newDispcnt;
    return newDispcnt;
}

u32 GetMenuEntryKind(void) {
    return (gMenuShared->mMenuEntryKind);
}

void SetRaceSetupRequested(u32 requested) {
    gMenuShared->mRaceSetupRequested = requested;
}

u32 GetUnfilledNotEliminated(void) {
    return (gMenuShared->mUnfilledNotEliminated);
}

u32 GetLVselIndex6Requested(void) {
    return (gMenuShared->mLVselIndex6Requested);
}

#pragma thumb on
#pragma optimize_for_size on
void InitMenu(void) {
    MenuScene *menu;
    SceneTextInitParams config;
    DisplaySettings *displaySettings;

    gMenuScene = HeapAlloc(MenuGetCurrentHeap(), sizeof(*gMenuScene));
    CreateRaceSetupCopy(MenuGetCurrentHeap());
    displaySettings = CreateDisplaySettings(MenuGetCurrentHeap(), gMenuDisplaySettingsDesc);
    SetMainBg0Record(displaySettings, 1, 0, 0, 0, 0xd, 2, 0);
    SetMainBg1Record(displaySettings, 0, 0, 0, 0, 0xc, 0, 0);
    SetMainBg2RecordParams(displaySettings, 0, 0, 0, 0, 0x1e, 6);
    SetMainBg3RecordParams(displaySettings, 3, 0, 0, 0, 0x1d, 4);
    SetSubBg0Record(displaySettings, 0, 0, 0, 0, 0xb, 0, 0);
    SetSubBg1Record(displaySettings, 3, 0, 0, 0, 0xd, 0, 0);
    SetSubBg2RecordParams(displaySettings, 0, 0, 0, 0, 0xe, 0);
    SetSubBg3RecordParams(displaySettings, 2, 0, 0, 0, 0xf, 0);
    InitDisplayFromSettings(displaySettings);
    gMenuScene->mFramesSinceScreenSwitch = 0;
    gMenuScene->mScreenSwitched = 1;
    gMenuScene->mPreviousScreenNumber = SCREEN_NONE;
    gMenuScene->mScreenNumber = SCREEN_NONE;
    gMenuScene->mNextScreenNumber = SCREEN_NONE;
    gMenuScene->mScreenInitPending = TRUE;
    gMenuScene->mDataSharingSyncStarted = TRUE;
    gMenuScene->mDataSharingSyncFinished = TRUE;
    CopyMenuScreenCallbacks();
    ResetOamLists(gMenuScene->mMainOam, gMenuScene->mSubOam);
    SetHeapGroupId(9);
    Init3dEngine();
    SetHeapGroupId(5);
    InitFrmVramManagers();
    SetHeapGroupId(9);
    if (MenuMB_IsMultiBootChildWrapper() == 0) {
        InitKartModelMenuWithParamFiles(MenuGetCurrentHeap());
        RequestKartModelMenuCharacter(-1);
        RequestKartModelMenuKart(-1);
    }
    SetHeapGroupId(5);
    if (MenuMB_IsMultiBootChildWrapper() == 0) {
        InitGhostRecordSet(MenuGetCurrentHeap());
        InitCupPicture();
        LoadNclrData(&gMenuScene->mSinglePlaySelectModeMONclr,
                     FindSceneFileWrapper("common/single_play_select_mode_m_o.NCLR"));
        LoadNcgrData2(&gMenuScene->mSinglePlaySelectModeMNcgr,
                      FindSceneFileWrapper("common/single_play_select_mode_m.nce.ncgr"));
        LoadNcerData(&gMenuScene->mSinglePlaySelectModeMNcer,
                     FindSceneFileWrapper("common/single_play_select_mode_m.nce.ncer"));
        gMenuScene->mSinglePlaySelectModeMBncl = FindSceneFileWrapper("common/single_play_select_mode_m.bncl");
        gMenuScene->mUnk_944 = 0;
        LoadNclrData(&gMenuScene->mSinglePlaySelectModeSONclr,
                     FindSceneFileWrapper("common/single_play_select_mode_s_o.NCLR"));
        LoadNcgrData2(&gMenuScene->mSinglePlaySelectModeSNcgr,
                      FindSceneFileWrapper("common/single_play_select_mode_s.nce.ncgr"));
        LoadNcerData(&gMenuScene->mSinglePlaySelectModeSNcer,
                     FindSceneFileWrapper("common/single_play_select_mode_s.nce.ncer"));
        gMenuScene->mSinglePlaySelectModeSBncl = FindSceneFileWrapper("common/single_play_select_mode_s.bncl");
        gMenuScene->mSinglePlaySelectModeSBnbl = FindSceneFileWrapper("common/single_play_select_mode_s.bnbl");
        menu = gMenuScene;
        InitLayoutTable(MenuGetCurrentHeap(), menu->mSinglePlaySelectModeMBncl, NULL,
                        &menu->mSinglePlaySelectModeMLayoutTable);
        menu = gMenuScene;
        InitLayoutTable(MenuGetCurrentHeap(), menu->mSinglePlaySelectModeSBncl, NULL,
                        &menu->mSinglePlaySelectModeSLayoutTable);
        menu = gMenuScene;
        SetCellOamModeXlu(0, 1, menu->mSinglePlaySelectModeSNcer, menu->mSinglePlaySelectModeSBncl);
        menu = gMenuScene;
        SetCellOamModeXlu(1, 1, menu->mSinglePlaySelectModeSNcer, menu->mSinglePlaySelectModeSBncl);
        menu = gMenuScene;
        SetCellOamModeXlu(2, 1, menu->mSinglePlaySelectModeSNcer, menu->mSinglePlaySelectModeSBncl);
        menu = gMenuScene;
        SetCellOamModeXlu(3, 1, menu->mSinglePlaySelectModeSNcer, menu->mSinglePlaySelectModeSBncl);
        menu = gMenuScene;
        SetCellOamModeXlu(4, 1, menu->mSinglePlaySelectModeSNcer, menu->mSinglePlaySelectModeSBncl);
    }
    LoadPlayerEntryListFiles();
    InitPlayerEntryList(MenuGetCurrentHeap(), gMenuScene->mMainOam);
    gMenuScene->mCharacterKartPicks = CreateCharacterKartPicks(MenuGetCurrentHeap());
    MenuGX_SetOBJVRamModeChar(0x10);
    MenuGXS_SetOBJVRamModeChar(0x10);
    WriteMainBlendAlpha(0, 0x3f, MENU_BLEND_FIRST_COEFFICIENT, MENU_BLEND_SECOND_COEFFICIENT);
    MenuWriteSubBlendAlpha(0, 0x3f, MENU_BLEND_FIRST_COEFFICIENT, MENU_BLEND_SECOND_COEFFICIENT);
    MenuWriteMainWinEnableBits(0);
    MenuWriteSubWinEnableBits(0);
    if (MenuMB_IsMultiBootChildWrapper() == 0) {
        LoadSelectCharacterData();
        LoadSelectKartData();
        LoadTimeAttackTopMenuData();
        LoadSelectGhostAndKartIconData();
        LoadMissionRunLVselData();
        LoadMissionRunMSselAndBossIconData();
        LoadSelectBattleStageData();
        LoadSelectEngineData();
        LoadSelectCupGridData();
        InitMenuNop();
        LoadSelectCupCourseData();
    }
    LoadSelectGameData();
    LoadSelectRaceRuleAndWaitData();
    config.mUseTxtSystem = MenuMB_IsMultiBootChildWrapper();
    config.mTxtSystemFont = GetFontByIndex(1);
    config.mUseCanvas1 = 0;
    config.mUseCanvas2 = 1;
    config.mUseCanvas3 = 0;
    config.mUseSelectChoises = 1;
    config.mSelectChoisesFont = GetFontByIndex(2);
    config.mUseSelectReturn = 1;
    config.mUseBackScreen = 1;
    config.mBackScreenKind = 0;
    LoadTxtSystemAndSelectChoisesAndSelectReturnData();
    InitSceneText(MenuGetCurrentHeap(), &config);
    if (MenuGetConnectionKind() == CONNECTION_KIND_WL_MENU) {
        ClearSelectReturnDisplayBitOn();
    }
    InitLinkLevelIcons(MenuGetCurrentHeap(), gMenuScene->mMainOam);
    switch (GetMenuEntryKind()) {
        case MENU_ENTRY_FIRST_SCREEN:
            SwitchMenuScreen(SCREEN_SINGLE_PLAY_SELECT_SLIDE_IN, SCREEN_NONE);
            SetRaceSetupRequested(1);
            break;
        case MENU_ENTRY_CHARACTER_SELECT:
            CopyCurrentToRaceSetupCopy();
            switch (GetRaceSetupCopy()->mMode) {
                case MODE_GRAND_PRIX:
                    SwitchMenuScreen(SCREEN_SELECT_CHARACTER_GRAND_PRIX, SCREEN_NONE);
                    SetMenuEntryKind(0);
                    SetRaceSetupRequested(1);
                    break;
                case MODE_VS:
                    SwitchMenuScreen(SCREEN_SELECT_CHARACTER_VS, SCREEN_NONE);
                    break;
                case MODE_BATTLE:
                    SwitchMenuScreen(SCREEN_SELECT_CHARACTER_BATTLE, SCREEN_NONE);
                    break;
                case MODE_TIME_ATTACK:
                    SwitchMenuScreen(SCREEN_SELECT_CHARACTER_TIME_ATTACK, SCREEN_NONE);
                    SetMenuEntryKind(0);
                    SetRaceSetupRequested(1);
                    break;
            }
            break;
        case MENU_ENTRY_COURSE_SELECT:
            CopyCurrentToRaceSetupCopy();
            switch (GetRaceSetupCopy()->mMode) {
                case MODE_VS:
                    SwitchMenuScreen(SCREEN_SELECT_CUP_GRID_VS, SCREEN_NONE);
                    break;
                case MODE_BATTLE:
                    SwitchMenuScreen(SCREEN_SELECT_BATTLE_STAGE, SCREEN_NONE);
                    break;
                case MODE_TIME_ATTACK:
                    SwitchMenuScreen(SCREEN_SELECT_CUP_GRID_TIME_ATTACK, SCREEN_NONE);
                    SetMenuEntryKind(0);
                    SetRaceSetupRequested(1);
                    break;
            }
            break;
        case MENU_ENTRY_MISSION_SELECT:
            CopyCurrentToRaceSetupCopy();
            if (GetUnfilledNotEliminated() != 0 || GetLVselIndex6Requested() != 0) {
                SwitchMenuScreen(SCREEN_MISSION_RUN_LVSEL, SCREEN_NONE);
            } else {
                SwitchMenuScreen(SCREEN_MISSION_RUN_MSSEL, SCREEN_NONE);
            }
            SetMenuEntryKind(0);
            SetRaceSetupRequested(1);
            break;
        case MENU_ENTRY_SELECT_GAME:
            SwitchMenuScreen(SCREEN_SELECT_GAME, SCREEN_NONE);
            break;
        case MENU_ENTRY_TIME_ATTACK_TOP_MENU:
            CopyCurrentToRaceSetupCopy();
            GetRaceSetupCopy()->mMode = 1;
            SwitchMenuScreen(SCREEN_TIME_ATTACK_TOP_MENU, SCREEN_NONE);
            SetMenuEntryKind(0);
            SetRaceSetupRequested(1);
            break;
    }
    CreatePicksHolder(MenuGetCurrentHeap());
    switch (GetRaceSetupCopy()->mMode) {
        case MODE_GRAND_PRIX:
        default:
            gMenuScene->mSinglePlaySelectModeIndex = SINGLE_PLAY_SELECT_GRAND_PRIX;
            break;
        case MODE_TIME_ATTACK:
            gMenuScene->mSinglePlaySelectModeIndex = SINGLE_PLAY_SELECT_TIME_ATTACK;
            break;
        case MODE_BATTLE:
            gMenuScene->mSinglePlaySelectModeIndex = SINGLE_PLAY_SELECT_BATTLE;
            break;
        case MODE_VS:
            gMenuScene->mSinglePlaySelectModeIndex = SINGLE_PLAY_SELECT_VS;
            break;
        case MODE_MISSION_RUN:
            gMenuScene->mSinglePlaySelectModeIndex = SINGLE_PLAY_SELECT_MISSION_RUN;
            break;
    }
    gMenuScene->mSinglePlaySelectStartedOnSelected = FALSE;
    gMenuScene->mSinglePlaySelectModePressOffset = 0;
}
#pragma thumb off

u16 *MenuMB_GetMultiBootParam(void) {
    return &gBootInfo->mBootType;
}

BOOL MenuMB_IsMultiBootChild(void) {
    return *MenuMB_GetMultiBootParam() == 2;
}

BOOL MenuMB_IsMultiBootChildWrapper(void) {
    return MenuMB_IsMultiBootChild();
}
