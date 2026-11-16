#include "Main/Unknown/code_020cc168.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_02038000.h"
#include "Main/Unknown/code_020cae8c.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Unknown/code_020cae38.h"
#include "Main/Unknown/code_020cae54.h"
#include "Main/Unknown/code_020cc6a4.h"
#include "Main/Unknown/code_020cc6dc.h"
#include "Main/Unknown/code_020cc6f0.h"
#include "Main/Unknown/code_020cc5d8.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020ae5e4.h"
#include "Main/Unknown/code_02077000.h"
#include "Main/Ui/BackScreen.h"
#include "Main/Unknown/code_020cbad0.h"
#include "Main/Unknown/unk_0216a000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "01/code_021804e0.h"
#include "registers.h"

// Returns the mission table row, or -1 outside Mission Run.
s32 RData_GetCurrentMissionLevel(void) {
    if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
        return gRaceMultiConfig->mMissionTableRow;
    }
    return -1;
}

// Returns the mission table column, or -1 outside Mission Run.
s32 RData_GetCurrentMissionIndex(void) {
    if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
        return gRaceMultiConfig->mMissionTableColumn;
    }
    return -1;
}

#pragma thumb on
#pragma optimize_for_size on
// Fills the race setup copy from the current setup; some modes are remapped and the course can be forced.
void menu_loadLastRaceConfig(void) {
    u16 i;

    for (i = 0; i < 8; i++) {
        menu_getRaceConfig()->mEntries[i].mCharacterIndex = GetCurrentCharacterIndex(i);
        menu_getRaceConfig()->mEntries[i].mKartIndex = GetCurrentKartIndex(i);
        menu_getRaceConfig()->mEntries[i].mPlayerKind = GetCurrentPlayerKind(i);
        if (RData_GetCurrentTeamMode() != 0) {
            menu_getRaceConfig()->mEntries[i].mTeamIndex = GetCurrentTeamIndex(i);
        } else {
            menu_getRaceConfig()->mEntries[i].mTeamIndex = -1;
        }
        menu_getRaceConfig()->mEntries[i].field10 = sub_20CC6A4(i);
        menu_getRaceConfig()->mEntries[i].field14 = 0;
    }
    menu_getRaceConfig()->mCupIndex = RData_GetCurrentCup();
    menu_getRaceConfig()->mCpuDifficulty = RData_GetCurrentCPUMode();
    menu_getRaceConfig()->mKartCount = menu_race_getNrDrivers();
    if (menu_sysdat_getOverlayRelatedNum() != 0) {
        u32 currentMode;

        currentMode = RData_GetCurrentRaceMode();
        switch (currentMode) {
            case 0:
            case 1:
            case 4:
                menu_getRaceConfig()->mMode = 3;
                break;
            case 2:
            case 3:
            case 5:
                menu_getRaceConfig()->mMode = currentMode;
                break;
        }
    } else {
        menu_getRaceConfig()->mMode = RData_GetCurrentRaceMode();
    }
    if (menu_sysdat_getIsMBChild() != 0) {
        menu_getRaceConfig()->mCourseId = COURSE_ID_OLD_MARIO_SFC;
    } else {
        menu_getRaceConfig()->mCourseId = RData_GetCurrentCourse();
    }
    menu_getRaceConfig()->mEngineIndex = RData_GetCurrentCCMode();
    menu_getRaceConfig()->mMirrorMode = RData_GetCurrentMirrorMode();
    menu_getRaceConfig()->mUseTeams = RData_GetCurrentTeamMode();
    menu_getRaceConfig()->mBattleKind = RData_GetBattleMode();
    menu_getRaceConfig()->mBattleKind = RData_GetBattleMode();
    menu_getRaceConfig()->mCourseCount = RData_GetNrRacesNrWins();
    menu_getRaceConfig()->mRuleKind = RData_GetRules();
    if (RData_GetCurrentRaceMode() == MODE_MISSION_RUN) {
        menu_getRaceConfig()->mMissionTableRow = RData_GetCurrentMissionLevel();
        menu_getRaceConfig()->mMissionTableColumn = RData_GetCurrentMissionIndex();
    }
}

void menu_setupStates(void) {
    s32 i;

    for (i = 0; i < 0x1e; i++) {
        gMenuSceneState->mScreenCallbacks[i].field0 = menu_sStates[i].field0;
        gMenuSceneState->mScreenCallbacks[i].mUpdate = menu_sStates[i].mUpdate;
    }
}

void menu_vblank(void) {
    if (menu_MB_IsMultiBootChild_22() == 0) {
        AdvanceKartModelMenuLoad();
    }
    gMenuSceneState->mScreenCallbacks[gMenuSceneState->mScreenNumber].field0();
    gmenu_vblank();
    gMenuSceneState->field4 = 0;
    oam_applyBuffers(gMenuSceneState->mMainOam, gMenuSceneState->mSubOam);
}
#pragma thumb off

void SetMainBg0Record(Unk02180774 *displaySettings, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h) {
    dc_setBg0Config(displaySettings->mMainBgRecords, b, c, d, e, f, g, h);
}

void DisplayConfig_SetTopEngineBg1Config_1(Unk02180774 *displaySettings, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h) {
    dc_setBg1Config(displaySettings->mMainBgRecords, b, c, d, e, f, g, h);
}

void DisplayConfig_SetTopEngineBg2Config2(Unk02180774 *displaySettings, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g) {
    dc_setBg2Config(displaySettings->mMainBgRecords, b, c, d, e, f, g);
}

void DisplayConfig_SetTopEngineBg3Config_0(Unk02180774 *displaySettings, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g) {
    dc_setBg3Config(displaySettings->mMainBgRecords, b, c, d, e, f, g);
}

void SetSubBg0Record(Unk02180774 *displaySettings, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h) {
    dc_setBg0Config(displaySettings->mSubBgRecords, b, c, d, e, f, g, h);
}

void SetSubBg1Record(Unk02180774 *displaySettings, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h) {
    dc_setBg1Config(displaySettings->mSubBgRecords, b, c, d, e, f, g, h);
}

void DisplayConfig_SetBottomEngineBg2Config2(Unk02180774 *displaySettings, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g) {
    dc_setBg2Config(displaySettings->mSubBgRecords, b, c, d, e, f, g);
}

void DisplayConfig_SetBottomEngineBg3Config_1(Unk02180774 *displaySettings, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g) {
    dc_setBg3Config(displaySettings->mSubBgRecords, b, c, d, e, f, g);
}

void menu_GX_SetOBJVRamModeChar(u32 bits) {
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffcfffef) | bits;
}

void menu_GXS_SetOBJVRamModeChar(u32 bits) {
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffcfffef) | bits;
}
