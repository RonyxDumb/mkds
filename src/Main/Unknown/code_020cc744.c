#include "Main/Unknown/code_020cc744.h"
#include "Main/Unknown/code_020435c4.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020cc0e4.h"
#include "Main/Unknown/code_020cae38.h"
#include "Main/Unknown/code_020cae54.h"
#include "Main/Unknown/code_020cbad0.h"
#include "Main/Unknown/code_020cc994.h"
#include "Main/Unknown/code_020ccab0.h"
#include "Main/Unknown/code_020ccb78.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Unknown/code_02044000.h"
#include "Main/Unknown/code_02045000.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020cc000.h"
#include "Main/Unknown/code_020ccbb8.h"
#include "Main/Unknown/code_02045874.h"

#pragma thumb on
#pragma optimize_for_size on
void menu_configureRace(void) {
    u16 rowIndex;
    u8 tableRowColumn[2];

    if (func_020cc120() != 2) {
        if (menu_getRaceConfig()->mMode == 0) {
            switch (menu_getRaceConfig()->mEngineIndex) {
                case 0:
                    menu_getRaceConfig()->mCpuDifficulty = 1;
                    break;
                case 1:
                    menu_getRaceConfig()->mCpuDifficulty = 2;
                    break;
                case 2:
                    menu_getRaceConfig()->mCpuDifficulty = 3;
                    break;
            }
        }
        SetNextCPUMode(menu_getRaceConfig()->mCpuDifficulty);
        if (menu_getRaceConfig()->mMode != 2 && menu_getRaceConfig()->mMode != 3) {
            menu_getRaceConfig()->mUseTeams = 0;
        }
        switch (menu_getRaceConfig()->mMode) {
            case 0:
                SetNextGrandPrixEntries();
                break;
            case 1:
                SetNextTimeAttackEntries();
                break;
            case 2:
            case 3:
            case 4:
                SetNextRaceEntriesFromRaceSetupCopy();
                break;
        }
        SetNextRaceMode(menu_getRaceConfig()->mMode);
        SetNextCup(menu_getRaceConfig()->mCupIndex);
        if (menu_getRaceConfig()->mMode == 0) {
            menu_getRaceConfig()->mCourseId = SPM_GetCourseIDByCupIndex(menu_getRaceConfig()->mCupIndex, 0);
        }
        SetNextCourse(menu_getRaceConfig()->mCourseId);
        if (menu_getRaceConfig()->mMode == 1) {
            menu_getRaceConfig()->mEngineIndex = 2;
        } else if (menu_getRaceConfig()->mMode == 2) {
            menu_getRaceConfig()->mEngineIndex = 0;
        } else if (menu_getRaceConfig()->mMode == 3) {
            if (menu_sysdat_getOverlayRelatedNum() != 0 && menu_sysdat_getIsMBChild() != 0) {
                menu_getRaceConfig()->mEngineIndex = 1;
            }
        }
        SetNextCCMode(menu_getRaceConfig()->mEngineIndex);
        SetNextMirrorMode(menu_getRaceConfig()->mMirrorMode);
        SetNextTTGhost(menu_getRaceConfig()->fieldE0);
        SetNextBattleMode(menu_getRaceConfig()->mBattleKind);
        SetNextTeamMode(menu_getRaceConfig()->mUseTeams);
        SetNextNrRacesNrWins(menu_getRaceConfig()->mCourseCount);
        SetNextRules(menu_getRaceConfig()->mRuleKind);
        SetNextCourseMode(menu_getRaceConfig()->mCourseListMode);
        if (menu_getRaceConfig()->mMode == 4 && menu_MB_IsMultiBootChild_22() == 0) {
            rowIndex = menu_getRaceConfig()->mMissionFileRowIndex;
            FindMissionTableCell(menu_getRaceConfig()->mMissionFileRows[rowIndex].mMissionTableValue, &tableRowColumn[0],
                                 &tableRowColumn[1]);
            rconf_setupMissionRace(&menu_getRaceConfig()->mMissionFileRows[rowIndex], tableRowColumn[0], tableRowColumn[1]);
        }
    } else {
        SetNextCup(menu_getRaceConfig()->mCupIndex);
        SetNextCourse(menu_getRaceConfig()->mCourseId);
    }
    if (menu_getRaceConfig()->mMode == 0) {
        func_020cc9a8(0);
    } else {
        func_020cc9a8(1);
    }
    if (func_020cc994() != 0) {
        rconf_2045ED0();
        func_020cc10c(0);
    }
}
