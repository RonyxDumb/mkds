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

struct MenuScene *g_GlobalB43C;
const u8 gMenuDisplaySettingsDesc[40] = {1, 0, 0x1f, 0, 0x1f, 0, 1, 0, 0,    0, 1, 0, 0, 0, 4, 0, 0x60, 0, 0, 0,
                                         0, 0, 3,    0, 0x10, 0, 0, 0, 0x80, 0, 0, 1, 0, 0, 0, 0, 8,    0, 0, 0};

// Returns the mission table row, or -1 outside Mission Run.
s32 GetCurrentMissionLevel_1(void) {
    if (g_GlobalCO->mMode == MODE_MISSION_RUN) {
        return g_GlobalCO->mMissionTableRow;
    }
    return -1;
}

// Returns the mission table column, or -1 outside Mission Run.
s32 GetCurrentMissionStage(void) {
    if (g_GlobalCO->mMode == MODE_MISSION_RUN) {
        return g_GlobalCO->mMissionTableColumn;
    }
    return -1;
}

#pragma thumb on
#pragma optimize_for_size on
// Fills the race setup copy from the current setup; some modes are remapped and the course can be forced.
void CopyInfoFromCOtoCA_from_thumb(void) {
    u16 entryIndex;

    for (entryIndex = 0; entryIndex < 8; entryIndex++) {
        GetGlobalCA_from_thumb()->mEntries[entryIndex].mCharacterIndex = GetRacerCharacterId(entryIndex);
        GetGlobalCA_from_thumb()->mEntries[entryIndex].mKartIndex = GetRacerKartId(entryIndex);
        GetGlobalCA_from_thumb()->mEntries[entryIndex].mPlayerKind = GetRacerType_0(entryIndex);
        if (GetIsTeams() != 0) {
            GetGlobalCA_from_thumb()->mEntries[entryIndex].mTeamIndex = GetRacerTeam(entryIndex);
        } else {
            GetGlobalCA_from_thumb()->mEntries[entryIndex].mTeamIndex = -1;
        }
        GetGlobalCA_from_thumb()->mEntries[entryIndex].mListedCpuSlot = GetCurrentListedCpuSlot(entryIndex);
        GetGlobalCA_from_thumb()->mEntries[entryIndex].mKartStored = 0;
    }
    GetGlobalCA_from_thumb()->mCupIndex = GetCurrentCupIndex();
    GetGlobalCA_from_thumb()->mCpuDifficulty = GetCurrentRaceCpuMode();
    GetGlobalCA_from_thumb()->mKartCount = GetRacerCount();
    if (GetPMaybeState_1() != CONNECTION_KIND_NONE) {
        u32 currentMode;

        currentMode = GetCurrentRaceMode();
        switch (currentMode) {
            case MODE_GRAND_PRIX:
            case MODE_TIME_ATTACK:
            case MODE_MISSION_RUN:
                GetGlobalCA_from_thumb()->mMode = MODE_VS;
                break;
            case MODE_BATTLE:
            case MODE_VS:
            case MODE_WIFI:
                GetGlobalCA_from_thumb()->mMode = currentMode;
                break;
        }
    } else {
        GetGlobalCA_from_thumb()->mMode = GetCurrentRaceMode();
    }
    if (GetMultiSimple() != 0) {
        GetGlobalCA_from_thumb()->mCourseId = COURSE_ID_OLD_MARIO_SFC;
    } else {
        GetGlobalCA_from_thumb()->mCourseId = GetCurrentInternalCourseId_1();
    }
    GetGlobalCA_from_thumb()->mEngineIndex = GetCurrrentCcType();
    GetGlobalCA_from_thumb()->mMirrorMode = GetIsMirror();
    GetGlobalCA_from_thumb()->mUseTeams = GetIsTeams();
    GetGlobalCA_from_thumb()->mBattleKind = GetCurrentBattleType();
    GetGlobalCA_from_thumb()->mBattleKind = GetCurrentBattleType();
    GetGlobalCA_from_thumb()->mCourseCount = GetMaybeNextRuleParam();
    GetGlobalCA_from_thumb()->mRuleKind = GetCurrentRaceRules();
    if (GetCurrentRaceMode() == MODE_MISSION_RUN) {
        GetGlobalCA_from_thumb()->mMissionTableRow = GetCurrentMissionLevel_1();
        GetGlobalCA_from_thumb()->mMissionTableColumn = GetCurrentMissionStage();
    }
}

void CopyB43CFunctionTable_from_thumb(void) {
    s32 screenIndex;

    for (screenIndex = 0; screenIndex < 0x1e; screenIndex++) {
        g_GlobalB43C->mScreenCallbacks[screenIndex].mWriteRegisters = gMenuScreenCallbacks[screenIndex].mWriteRegisters;
        g_GlobalB43C->mScreenCallbacks[screenIndex].mUpdate = gMenuScreenCallbacks[screenIndex].mUpdate;
    }
}

void Scene_Menu_VBlankImpl_from_thumb(void) {
    if (j_IsDwc_0() == 0) {
        AdvanceKartModelMenuLoad();
    }
    g_GlobalB43C->mScreenCallbacks[g_GlobalB43C->mScreenNumber].mWriteRegisters();
    NavigationContext_OnSceneVblank_from_thumb();
    g_GlobalB43C->mScreenSwitched = 0;
    CopyOamBuffersToMemory_from_thumb(g_GlobalB43C->mMainOam, g_GlobalB43C->mSubOam);
}
#pragma thumb off

void DisplayConfig_SetTopEngineBg0Config(DisplaySettings *displaySettings, u32 cntLow2, u32 cntMosaic, u32 cntVal14, u32 cntVal7,
                      u32 cntVal8, u32 cntVal2, u32 cntVal13) {
    DisplayEngineConfig_SetBg0Config(&displaySettings->mMainBgRecords, cntLow2, cntMosaic, cntVal14, cntVal7, cntVal8, cntVal2, cntVal13);
}

void DisplayConfig_SetTopEngineBg1Config_1(DisplaySettings *displaySettings, u32 cntLow2, u32 cntMosaic, u32 cntVal14, u32 cntVal7,
                      u32 cntVal8, u32 cntVal2, u32 cntVal13) {
    DisplayEngineConfig_SetBg1Config(&displaySettings->mMainBgRecords, cntLow2, cntMosaic, cntVal14, cntVal7, cntVal8, cntVal2, cntVal13);
}

void DisplayConfig_SetTopEngineBg2Config2(DisplaySettings *displaySettings, u32 cntLow2, u32 cntMosaic, u32 cntVal14, u32 cntVal7Or13,
                            u32 cntVal8, u32 cntVal2) {
    DisplayEngineConfig_SetBg2Config2(&displaySettings->mMainBgRecords, cntLow2, cntMosaic, cntVal14, cntVal7Or13, cntVal8, cntVal2);
}

void DisplayConfig_SetTopEngineBg3Config_0(DisplaySettings *displaySettings, u32 cntLow2, u32 cntMosaic, u32 cntVal14, u32 cntVal7Or13,
                            u32 cntVal8, u32 cntVal2) {
    DisplayEngineConfig_SetBg3Config(&displaySettings->mMainBgRecords, cntLow2, cntMosaic, cntVal14, cntVal7Or13, cntVal8, cntVal2);
}

void DisplayConfig_SetBottomEngineBg0Config(DisplaySettings *displaySettings, u32 cntLow2, u32 cntMosaic, u32 cntVal14, u32 cntVal7,
                     u32 cntVal8, u32 cntVal2, u32 cntVal13) {
    DisplayEngineConfig_SetBg0Config(&displaySettings->mSubBgRecords, cntLow2, cntMosaic, cntVal14, cntVal7, cntVal8, cntVal2, cntVal13);
}

void DisplayConfig_SetBottomEngineBg1Config(DisplaySettings *displaySettings, u32 cntLow2, u32 cntMosaic, u32 cntVal14, u32 cntVal7,
                     u32 cntVal8, u32 cntVal2, u32 cntVal13) {
    DisplayEngineConfig_SetBg1Config(&displaySettings->mSubBgRecords, cntLow2, cntMosaic, cntVal14, cntVal7, cntVal8, cntVal2, cntVal13);
}

void DisplayConfig_SetBottomEngineBg2Config2(DisplaySettings *displaySettings, u32 cntLow2, u32 cntMosaic, u32 cntVal14, u32 cntVal7Or13,
                           u32 cntVal8, u32 cntVal2) {
    DisplayEngineConfig_SetBg2Config2(&displaySettings->mSubBgRecords, cntLow2, cntMosaic, cntVal14, cntVal7Or13, cntVal8, cntVal2);
}

void DisplayConfig_SetBottomEngineBg3Config_1(DisplaySettings *displaySettings, u32 cntLow2, u32 cntMosaic, u32 cntVal14, u32 cntVal7Or13,
                           u32 cntVal8, u32 cntVal2) {
    DisplayEngineConfig_SetBg3Config(&displaySettings->mSubBgRecords, cntLow2, cntMosaic, cntVal14, cntVal7Or13, cntVal8, cntVal2);
}

void SetTopDispcntTileObjMappingRemoveBoundary(u32 bits) {
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~(REG_GX_DISPCNT_EXOBJ_CH_MASK | REG_GX_DISPCNT_OBJMAP_CH_MASK)) | bits;
}

void SetSubDispcntTileObjMappingRemoveBoundary(u32 bits) {
    reg_GXS_DB_DISPCNT =
        (reg_GXS_DB_DISPCNT & ~(REG_GXS_DB_DISPCNT_EXOBJ_CH_MASK | REG_GXS_DB_DISPCNT_OBJMAP_CH_MASK)) | bits;
}

u32 SetDispcntWindows01ObjDisplayFlagsTop(u32 bits) {
    u32 newDispcnt = bits;
    u32 registerValue;
    registerValue = reg_GX_DISPCNT;
    registerValue = (registerValue) & ~(0xe000u);
    newDispcnt = (registerValue) | ((newDispcnt << 13));
    reg_GX_DISPCNT = newDispcnt;
    return newDispcnt;
}

u32 SetDispcntWindows01ObjDisplayFlagsSub(u32 bits) {
    u32 newDispcnt = bits;
    u32 registerValue;
    registerValue = reg_GXS_DB_DISPCNT;
    registerValue = (registerValue) & ~(0xe000u);
    newDispcnt = (registerValue) | ((newDispcnt << 13));
    reg_GXS_DB_DISPCNT = newDispcnt;
    return newDispcnt;
}

u32 GetB488_SinglePlayerMenuTarget(void) {
    return (g_GlobalB488->mMenuEntryKind);
}

void SetB488_B2(u32 requested) {
    g_GlobalB488->mRaceSetupRequested = requested;
}

u32 GetB488_B5(void) {
    return (g_GlobalB488->mUnfilledNotEliminated);
}

u32 GetB488_B6(void) {
    return (g_GlobalB488->mLVselIndex6Requested);
}

#pragma thumb on
#pragma optimize_for_size on
void Scene_Menu_InitializeImpl_from_thumb(void) {
    MenuScene *menu;
    SceneTextInitParams config;
    DisplaySettings *displaySettings;

    g_GlobalB43C = Mem_AllocateHeap(GetActiveExecutionContextHeapHandle(), sizeof(*g_GlobalB43C));
    InitializeGlobalCA_from_thumb(GetActiveExecutionContextHeapHandle());
    displaySettings = CreateDisplayConfig(GetActiveExecutionContextHeapHandle(), gMenuDisplaySettingsDesc);
    DisplayConfig_SetTopEngineBg0Config(displaySettings, 1, 0, 0, 0, 0xd, 2, 0);
    DisplayConfig_SetTopEngineBg1Config_1(displaySettings, 0, 0, 0, 0, 0xc, 0, 0);
    DisplayConfig_SetTopEngineBg2Config2(displaySettings, 0, 0, 0, 0, 0x1e, 6);
    DisplayConfig_SetTopEngineBg3Config_0(displaySettings, 3, 0, 0, 0, 0x1d, 4);
    DisplayConfig_SetBottomEngineBg0Config(displaySettings, 0, 0, 0, 0, 0xb, 0, 0);
    DisplayConfig_SetBottomEngineBg1Config(displaySettings, 3, 0, 0, 0, 0xd, 0, 0);
    DisplayConfig_SetBottomEngineBg2Config2(displaySettings, 0, 0, 0, 0, 0xe, 0);
    DisplayConfig_SetBottomEngineBg3Config_1(displaySettings, 2, 0, 0, 0, 0xf, 0);
    SetGlobalDisplayConfig(displaySettings);
    g_GlobalB43C->mFramesSinceScreenSwitch = 0;
    g_GlobalB43C->mScreenSwitched = 1;
    g_GlobalB43C->mPreviousScreenNumber = SCREEN_NONE;
    g_GlobalB43C->mScreenNumber = SCREEN_NONE;
    g_GlobalB43C->mNextScreenNumber = SCREEN_NONE;
    g_GlobalB43C->mScreenInitPending = TRUE;
    g_GlobalB43C->mDataSharingSyncStarted = TRUE;
    g_GlobalB43C->mDataSharingSyncFinished = TRUE;
    CopyB43CFunctionTable_from_thumb();
    OamBuffer_SomeFn_from_thumb(g_GlobalB43C->mMainOam, g_GlobalB43C->mSubOam);
    SetActiveExecutionContextHeapGroupId_from_thumb(9);
    Init3dEngine();
    SetActiveExecutionContextHeapGroupId_from_thumb(5);
    InitFrmVramManagers();
    SetActiveExecutionContextHeapGroupId_from_thumb(9);
    if (j_IsDwc_0() == 0) {
        CreateGlobalCE_from_thumb(GetActiveExecutionContextHeapHandle());
        RequestKartModelMenuCharacter(-1);
        RequestKartModelMenuKart(-1);
    }
    SetActiveExecutionContextHeapGroupId_from_thumb(5);
    if (j_IsDwc_0() == 0) {
        InitializeGlobalPK_from_thumb(GetActiveExecutionContextHeapHandle());
        InitializeGlobalB4A4_from_thumb();
        Gfx_ReadPalette(&g_GlobalB43C->mSinglePlaySelectModeMONclr,
                     j_FindFileBuffer_K2D_LOC_R2D_R2L("common/single_play_select_mode_m_o.NCLR"));
        Gfx_ReadCharGraphics(&g_GlobalB43C->mSinglePlaySelectModeMNcgr,
                      j_FindFileBuffer_K2D_LOC_R2D_R2L("common/single_play_select_mode_m.nce.ncgr"));
        LoadCellBankFrom(&g_GlobalB43C->mSinglePlaySelectModeMNcer,
                     j_FindFileBuffer_K2D_LOC_R2D_R2L("common/single_play_select_mode_m.nce.ncer"));
        g_GlobalB43C->mSinglePlaySelectModeMBncl = j_FindFileBuffer_K2D_LOC_R2D_R2L("common/single_play_select_mode_m.bncl");
        g_GlobalB43C->mUnk_944 = 0;
        Gfx_ReadPalette(&g_GlobalB43C->mSinglePlaySelectModeSONclr,
                     j_FindFileBuffer_K2D_LOC_R2D_R2L("common/single_play_select_mode_s_o.NCLR"));
        Gfx_ReadCharGraphics(&g_GlobalB43C->mSinglePlaySelectModeSNcgr,
                      j_FindFileBuffer_K2D_LOC_R2D_R2L("common/single_play_select_mode_s.nce.ncgr"));
        LoadCellBankFrom(&g_GlobalB43C->mSinglePlaySelectModeSNcer,
                     j_FindFileBuffer_K2D_LOC_R2D_R2L("common/single_play_select_mode_s.nce.ncer"));
        g_GlobalB43C->mSinglePlaySelectModeSBncl = j_FindFileBuffer_K2D_LOC_R2D_R2L("common/single_play_select_mode_s.bncl");
        g_GlobalB43C->mSinglePlaySelectModeSBnbl = j_FindFileBuffer_K2D_LOC_R2D_R2L("common/single_play_select_mode_s.bnbl");
        menu = g_GlobalB43C;
        InitLayoutTable(GetActiveExecutionContextHeapHandle(), menu->mSinglePlaySelectModeMBncl, NULL,
                        &menu->mSinglePlaySelectModeMLayoutTable);
        menu = g_GlobalB43C;
        InitLayoutTable(GetActiveExecutionContextHeapHandle(), menu->mSinglePlaySelectModeSBncl, NULL,
                        &menu->mSinglePlaySelectModeSLayoutTable);
        menu = g_GlobalB43C;
        CellBank_ResetSomeMetatileObjectsMode_from_thumb(0, 1, menu->mSinglePlaySelectModeSNcer, menu->mSinglePlaySelectModeSBncl);
        menu = g_GlobalB43C;
        CellBank_ResetSomeMetatileObjectsMode_from_thumb(1, 1, menu->mSinglePlaySelectModeSNcer, menu->mSinglePlaySelectModeSBncl);
        menu = g_GlobalB43C;
        CellBank_ResetSomeMetatileObjectsMode_from_thumb(2, 1, menu->mSinglePlaySelectModeSNcer, menu->mSinglePlaySelectModeSBncl);
        menu = g_GlobalB43C;
        CellBank_ResetSomeMetatileObjectsMode_from_thumb(3, 1, menu->mSinglePlaySelectModeSNcer, menu->mSinglePlaySelectModeSBncl);
        menu = g_GlobalB43C;
        CellBank_ResetSomeMetatileObjectsMode_from_thumb(4, 1, menu->mSinglePlaySelectModeSNcer, menu->mSinglePlaySelectModeSBncl);
    }
    VerifySelectMenuFiles_from_thumb();
    AndAnotherAlloc_0_from_thumb(GetActiveExecutionContextHeapHandle(), g_GlobalB43C->mMainOam);
    g_GlobalB43C->mCharacterKartPicks = AllocateKartAppearTableData_from_thumb(GetActiveExecutionContextHeapHandle());
    SetTopDispcntTileObjMappingRemoveBoundary(0x10);
    SetSubDispcntTileObjMappingRemoveBoundary(0x10);
    EnableAlphaSetBldcntBldalphaTop(0, 0x3f, MENU_BLEND_FIRST_COEFFICIENT, MENU_BLEND_SECOND_COEFFICIENT);
    EnableAlphaSetBldcntBldalphaSub(0, 0x3f, MENU_BLEND_FIRST_COEFFICIENT, MENU_BLEND_SECOND_COEFFICIENT);
    SetDispcntWindows01ObjDisplayFlagsTop(0);
    SetDispcntWindows01ObjDisplayFlagsSub(0);
    if (j_IsDwc_0() == 0) {
        VerifySelectCharacterFiles_from_thumb();
        VerifySelectKartFiles_from_thumb();
        LoadTimeAttackTopMenuData();
        LoadSelectGhostAndKartIconData();
        LoadMissionRunLVselData();
        LoadMissionRunMSselAndBossIconData();
        LoadSelectBattleStageData();
        LoadSelectEngineData();
        VerifySelectCupFiles_from_thumb();
        nullsub_20_from_thumb();
        VerifySelectCupCourseFiles_from_thumb();
    }
    VerifyCommonSelectGameFiles_from_thumb();
    VerifyCommonSelectRaceRuleFiles_from_thumb();
    config.mUseTxtSystem = j_IsDwc_0();
    config.mTxtSystemFont = GetLoadedFont_from_thumb(1);
    config.mUseCanvas1 = 0;
    config.mUseCanvas2 = 1;
    config.mUseCanvas3 = 0;
    config.mUseSelectChoises = 1;
    config.mSelectChoisesFont = GetLoadedFont_from_thumb(2);
    config.mUseSelectReturn = 1;
    config.mUseBackScreen = 1;
    config.mBackScreenKind = 0;
    PrepareNavigationContextFiles_from_thumb();
    InitializeNavigationContext_from_thumb(GetActiveExecutionContextHeapHandle(), &config);
    if (GetPMaybeState_1() == CONNECTION_KIND_WL_MENU) {
        ClearSelectReturnDisplayBitOn();
    }
    CreateGlobalNN_from_thumb(GetActiveExecutionContextHeapHandle(), g_GlobalB43C->mMainOam);
    switch (GetB488_SinglePlayerMenuTarget()) {
        case MENU_ENTRY_FIRST_SCREEN:
            SwitchMenuScreen(SCREEN_SINGLE_PLAY_SELECT_SLIDE_IN, SCREEN_NONE);
            SetB488_B2(1);
            break;
        case MENU_ENTRY_CHARACTER_SELECT:
            CopyInfoFromCOtoCA_from_thumb();
            switch (GetGlobalCA_from_thumb()->mMode) {
                case MODE_GRAND_PRIX:
                    SwitchMenuScreen(SCREEN_SELECT_CHARACTER_GRAND_PRIX, SCREEN_NONE);
                    SetSinglePlayerMenuTarget(0);
                    SetB488_B2(1);
                    break;
                case MODE_VS:
                    SwitchMenuScreen(SCREEN_SELECT_CHARACTER_VS, SCREEN_NONE);
                    break;
                case MODE_BATTLE:
                    SwitchMenuScreen(SCREEN_SELECT_CHARACTER_BATTLE, SCREEN_NONE);
                    break;
                case MODE_TIME_ATTACK:
                    SwitchMenuScreen(SCREEN_SELECT_CHARACTER_TIME_ATTACK, SCREEN_NONE);
                    SetSinglePlayerMenuTarget(0);
                    SetB488_B2(1);
                    break;
            }
            break;
        case MENU_ENTRY_COURSE_SELECT:
            CopyInfoFromCOtoCA_from_thumb();
            switch (GetGlobalCA_from_thumb()->mMode) {
                case MODE_VS:
                    SwitchMenuScreen(SCREEN_SELECT_CUP_GRID_VS, SCREEN_NONE);
                    break;
                case MODE_BATTLE:
                    SwitchMenuScreen(SCREEN_SELECT_BATTLE_STAGE, SCREEN_NONE);
                    break;
                case MODE_TIME_ATTACK:
                    SwitchMenuScreen(SCREEN_SELECT_CUP_GRID_TIME_ATTACK, SCREEN_NONE);
                    SetSinglePlayerMenuTarget(0);
                    SetB488_B2(1);
                    break;
            }
            break;
        case MENU_ENTRY_MISSION_SELECT:
            CopyInfoFromCOtoCA_from_thumb();
            if (GetB488_B5() != 0 || GetB488_B6() != 0) {
                SwitchMenuScreen(SCREEN_MISSION_RUN_LVSEL, SCREEN_NONE);
            } else {
                SwitchMenuScreen(SCREEN_MISSION_RUN_MSSEL, SCREEN_NONE);
            }
            SetSinglePlayerMenuTarget(0);
            SetB488_B2(1);
            break;
        case MENU_ENTRY_SELECT_GAME:
            SwitchMenuScreen(SCREEN_SELECT_GAME, SCREEN_NONE);
            break;
        case MENU_ENTRY_TIME_ATTACK_TOP_MENU:
            CopyInfoFromCOtoCA_from_thumb();
            GetGlobalCA_from_thumb()->mMode = 1;
            SwitchMenuScreen(SCREEN_TIME_ATTACK_TOP_MENU, SCREEN_NONE);
            SetSinglePlayerMenuTarget(0);
            SetB488_B2(1);
            break;
    }
    CreateSetGlobalKTB_from_thumb(GetActiveExecutionContextHeapHandle());
    switch (GetGlobalCA_from_thumb()->mMode) {
        case MODE_GRAND_PRIX:
        default:
            g_GlobalB43C->mSinglePlaySelectModeIndex = SINGLE_PLAY_SELECT_GRAND_PRIX;
            break;
        case MODE_TIME_ATTACK:
            g_GlobalB43C->mSinglePlaySelectModeIndex = SINGLE_PLAY_SELECT_TIME_ATTACK;
            break;
        case MODE_BATTLE:
            g_GlobalB43C->mSinglePlaySelectModeIndex = SINGLE_PLAY_SELECT_BATTLE;
            break;
        case MODE_VS:
            g_GlobalB43C->mSinglePlaySelectModeIndex = SINGLE_PLAY_SELECT_VS;
            break;
        case MODE_MISSION_RUN:
            g_GlobalB43C->mSinglePlaySelectModeIndex = SINGLE_PLAY_SELECT_MISSION_RUN;
            break;
    }
    g_GlobalB43C->mSinglePlaySelectStartedOnSelected = FALSE;
    g_GlobalB43C->mSinglePlaySelectModePressOffset = 0;
}
#pragma thumb off

u16 *GetBootIndicatorPointer_0(void) {
    return &gBootInfo->mBootType;
}

BOOL IsDwc_0(void) {
    return *GetBootIndicatorPointer_0() == 2;
}

BOOL j_IsDwc_0(void) {
    return IsDwc_0();
}
