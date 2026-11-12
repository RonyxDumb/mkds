#include "Main/Menu/menu.h"
#include "Main/Unknown/code_020cc168.h"
#include "Main/Scene/display_settings.h"
#include "Main/Unknown/code_02038000.h"
#include "Main/Menu/single_play_select_screen3.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Menu/multi_simple.h"
#include "Main/Menu/menu_connection_kind.h"
#include "Main/Unknown/code_020cc6a4.h"
#include "Main/Unknown/code_020cc6dc.h"
#include "Main/Unknown/code_020cc6f0.h"
#include "Main/Menu/current.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Graphics/oam_upload.h"
#include "Main/Unknown/code_02077000.h"
#include "Main/Graphics/scene_text.h"
#include "Main/Unknown/unk_0216a000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "01/code_021804e0.h"
#include "registers.h"
#include "Main/Unknown/code_020cc0e4.h"
#include "Main/Unknown/code_020cc134.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_0202bb80.h"
#include "Main/Menu/select_game.h"
#include "Main/System/heap.h"
#include "Main/Menu/title_scene.h"
#include "Main/Race/race.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/System/file_in_loaded.h"
#include "Main/Menu/menu_heap.h"
#include "Main/Menu/menu_entry_kind.h"
#include "Main/Unknown/code_020cc000.h"
#include "Main/Menu/next.h"
#include "Main/Unknown/code_02029000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Menu/menu_screen_switch.h"
#include "Main/Menu/message_screen.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/code_02029a24.h"
#include "Main/Unknown/code_02037000.h"
#include "Main/Unknown/code_0203b000.h"
#include "code_020176b0.h"
#include "Main/System/heap_call.h"
#include "Main/System/result_archive_path.h"
#include "Main/Race/ghost_record_set.h"
#include "Main/Unknown/code_020d1108.h"
#include "Main/Graphics/back_screen.h"
#include "Main/Unknown/code_02125de0.h"
#include "Main/Unknown/code_021281fc.h"
#include "Main/Unknown/code_0212a000.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Menu/picks_holder.h"
#include "Main/Menu/trophy_icon.h"
#include "Main/Menu/select_race_rule_load.h"
#include "Main/Menu/select_cup_course.h"
#include "Main/Menu/select_race_rule.h"
#include "Main/Menu/select_kart_data.h"
#include "Main/Unknown/code_020ccc9c.h"
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
#include "Main/Menu/select_character.h"
#include "Main/Unknown/code_0211d4a8.h"

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
    if (MenuGetConnectionKind() != 0) {
        u32 currentMode;

        currentMode = GetCurrentMode();
        switch (currentMode) {
            case 0:
            case 1:
            case 4:
                GetRaceSetupCopy()->mMode = 3;
                break;
            case 2:
            case 3:
            case 5:
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

void SetMainBg0Record(DisplaySettings *displaySettings, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 cntVal7,
                      u32 cntVal8, u32 cntVal2, u32 cntVal13) {
    SetBg0Record(&displaySettings->mMainBgRecords, cntLow2, cntBit6, cntVal14, cntVal7, cntVal8, cntVal2, cntVal13);
}

void SetMainBg1Record(DisplaySettings *displaySettings, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 cntVal7,
                      u32 cntVal8, u32 cntVal2, u32 cntVal13) {
    SetBg1Record(&displaySettings->mMainBgRecords, cntLow2, cntBit6, cntVal14, cntVal7, cntVal8, cntVal2, cntVal13);
}

void SetMainBg2RecordParams(DisplaySettings *displaySettings, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 cntVal7Or13,
                            u32 cntVal8, u32 cntVal2) {
    SetBg2RecordParams(&displaySettings->mMainBgRecords, cntLow2, cntBit6, cntVal14, cntVal7Or13, cntVal8, cntVal2);
}

void SetMainBg3RecordParams(DisplaySettings *displaySettings, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 cntVal7Or13,
                            u32 cntVal8, u32 cntVal2) {
    SetBg3RecordParams(&displaySettings->mMainBgRecords, cntLow2, cntBit6, cntVal14, cntVal7Or13, cntVal8, cntVal2);
}

void SetSubBg0Record(DisplaySettings *displaySettings, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 cntVal7, u32 cntVal8,
                     u32 cntVal2, u32 cntVal13) {
    SetBg0Record(&displaySettings->mSubBgRecords, cntLow2, cntBit6, cntVal14, cntVal7, cntVal8, cntVal2, cntVal13);
}

void SetSubBg1Record(DisplaySettings *displaySettings, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 cntVal7, u32 cntVal8,
                     u32 cntVal2, u32 cntVal13) {
    SetBg1Record(&displaySettings->mSubBgRecords, cntLow2, cntBit6, cntVal14, cntVal7, cntVal8, cntVal2, cntVal13);
}

void SetSubBg2RecordParams(DisplaySettings *displaySettings, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 cntVal7Or13,
                           u32 cntVal8, u32 cntVal2) {
    SetBg2RecordParams(&displaySettings->mSubBgRecords, cntLow2, cntBit6, cntVal14, cntVal7Or13, cntVal8, cntVal2);
}

void SetSubBg3RecordParams(DisplaySettings *displaySettings, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 cntVal7Or13,
                           u32 cntVal8, u32 cntVal2) {
    SetBg3RecordParams(&displaySettings->mSubBgRecords, cntLow2, cntBit6, cntVal14, cntVal7Or13, cntVal8, cntVal2);
}

void MenuGX_SetOBJVRamModeChar(u32 bits) {
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffcfffef) | bits;
}

void MenuGXS_SetOBJVRamModeChar(u32 bits) {
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffcfffef) | bits;
}

u32 MenuWriteMainWinEnableBits(u32 bits) {
    u32 value0 = bits;
    u32 registerValue;
    registerValue = reg_GX_DISPCNT;
    registerValue = (registerValue) & ~(0xe000u);
    value0 = (registerValue) | ((value0 << 13));
    reg_GX_DISPCNT = value0;
    return value0;
}

u32 MenuWriteSubWinEnableBits(u32 bits) {
    u32 value0 = bits;
    u32 registerValue;
    registerValue = reg_GXS_DB_DISPCNT;
    registerValue = (registerValue) & ~(0xe000u);
    value0 = (registerValue) | ((value0 << 13));
    reg_GXS_DB_DISPCNT = value0;
    return value0;
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

    gMenuScene = HeapAlloc(MenuGetCurrentHeap(), 0x960);
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
    gMenuScene->mPreviousScreenNumber = 0x1f;
    gMenuScene->mScreenNumber = 0x1f;
    gMenuScene->mNextScreenNumber = 0x1f;
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
    WriteMainBlendAlpha(0, 0x3f, 6, 10);
    MenuWriteSubBlendAlpha(0, 0x3f, 6, 10);
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
    if (MenuGetConnectionKind() == 2) {
        ClearSelectReturnDisplayBitOn();
    }
    InitLinkLevelIcons(MenuGetCurrentHeap(), gMenuScene->mMainOam);
    switch (GetMenuEntryKind()) {
        case 0:
            SwitchMenuScreen(0, 0x1f);
            SetRaceSetupRequested(1);
            break;
        case 1:
            CopyCurrentToRaceSetupCopy();
            switch (GetRaceSetupCopy()->mMode) {
                case 0:
                    SwitchMenuScreen(5, 0x1f);
                    SetMenuEntryKind(0);
                    SetRaceSetupRequested(1);
                    break;
                case 3:
                    SwitchMenuScreen(8, 0x1f);
                    break;
                case 2:
                    SwitchMenuScreen(0xf, 0x1f);
                    break;
                case 1:
                    SwitchMenuScreen(0x15, 0x1f);
                    SetMenuEntryKind(0);
                    SetRaceSetupRequested(1);
                    break;
            }
            break;
        case 2:
            CopyCurrentToRaceSetupCopy();
            switch (GetRaceSetupCopy()->mMode) {
                case 3:
                    SwitchMenuScreen(0xb, 0x1f);
                    break;
                case 2:
                    SwitchMenuScreen(SCREEN_SELECT_BATTLE_STAGE, 0x1f);
                    break;
                case 1:
                    SwitchMenuScreen(0x17, 0x1f);
                    SetMenuEntryKind(0);
                    SetRaceSetupRequested(1);
                    break;
            }
            break;
        case 3:
            CopyCurrentToRaceSetupCopy();
            if (GetUnfilledNotEliminated() != 0 || GetLVselIndex6Requested() != 0) {
                SwitchMenuScreen(SCREEN_MISSION_RUN_LVSEL, 0x1f);
            } else {
                SwitchMenuScreen(SCREEN_MISSION_RUN_MSSEL, 0x1f);
            }
            SetMenuEntryKind(0);
            SetRaceSetupRequested(1);
            break;
        case 4:
            SwitchMenuScreen(0xe, 0x1f);
            break;
        case 5:
            CopyCurrentToRaceSetupCopy();
            GetRaceSetupCopy()->mMode = 1;
            SwitchMenuScreen(SCREEN_TIME_ATTACK_TOP_MENU, 0x1f);
            SetMenuEntryKind(0);
            SetRaceSetupRequested(1);
            break;
    }
    CreatePicksHolder(MenuGetCurrentHeap());
    switch (GetRaceSetupCopy()->mMode) {
        case 0:
        default:
            gMenuScene->mSinglePlaySelectModeIndex = 0;
            break;
        case 1:
            gMenuScene->mSinglePlaySelectModeIndex = 1;
            break;
        case 2:
            gMenuScene->mSinglePlaySelectModeIndex = 3;
            break;
        case 3:
            gMenuScene->mSinglePlaySelectModeIndex = 2;
            break;
        case 4:
            gMenuScene->mSinglePlaySelectModeIndex = 4;
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
