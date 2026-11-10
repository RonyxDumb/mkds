#include "Main/Unknown/code_020cbad0.h"
#include "Main/Unknown/code_0202bb80.h"
#include "Main/Unknown/code_0203206c.h"
#include "Main/Unknown/code_02036820.h"
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
#include "Main/Unknown/code_02125960.h"
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
#include "Main/Unknown/code_0211d4a8.h"

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
    func_020629a4();
    SetHeapGroupId(9);
    if (IsDownloadBootWrapper() == 0) {
        InitKartModelMenuWithParamFiles(MenuGetCurrentHeap());
        RequestKartModelMenuCharacter(-1);
        RequestKartModelMenuKart(-1);
    }
    SetHeapGroupId(5);
    if (IsDownloadBootWrapper() == 0) {
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
        func_02124a98(0, 1, menu->mSinglePlaySelectModeSNcer, menu->mSinglePlaySelectModeSBncl);
        menu = gMenuScene;
        func_02124a98(1, 1, menu->mSinglePlaySelectModeSNcer, menu->mSinglePlaySelectModeSBncl);
        menu = gMenuScene;
        func_02124a98(2, 1, menu->mSinglePlaySelectModeSNcer, menu->mSinglePlaySelectModeSBncl);
        menu = gMenuScene;
        func_02124a98(3, 1, menu->mSinglePlaySelectModeSNcer, menu->mSinglePlaySelectModeSBncl);
        menu = gMenuScene;
        func_02124a98(4, 1, menu->mSinglePlaySelectModeSNcer, menu->mSinglePlaySelectModeSBncl);
    }
    LoadPlayerEntryListFiles();
    InitPlayerEntryList(MenuGetCurrentHeap(), gMenuScene->mMainOam);
    gMenuScene->mCharacterKartPicks = CreateCharacterKartPicks(MenuGetCurrentHeap());
    SetMainDispcntBits(0x10);
    SetSubDispcntBits(0x10);
    WriteMainBlendAlpha(0, 0x3f, 6, 10);
    MenuWriteSubBlendAlpha(0, 0x3f, 6, 10);
    MenuWriteMainWinEnableBits(0);
    MenuWriteSubWinEnableBits(0);
    if (IsDownloadBootWrapper() == 0) {
        func_02025f90();
        func_02027df8();
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
    config.mUseTxtSystem = IsDownloadBootWrapper();
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
            if (func_020cc0f8() != 0 || func_020cc0e4() != 0) {
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

u16 *GetBootInfoHalfwordPointer(void) {
    return &gBootInfo->mUnk_00;
}

BOOL IsDownloadBoot(void) {
    return *GetBootInfoHalfwordPointer() == 2;
}

BOOL IsDownloadBootWrapper(void) {
    return IsDownloadBoot();
}
