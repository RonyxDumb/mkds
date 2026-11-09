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
#include "Main/Unknown/code_021258f0.h"
#include "Main/Unknown/code_020cbad0.h"
#include "Main/Unknown/unk_0216a000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "01/code_021804e0.h"
#include "registers.h"

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
    u16 i;

    for (i = 0; i < 8; i++) {
        GetRaceSetupCopy()->mEntries[i].mCharacterIndex = GetCurrentCharacterIndex(i);
        GetRaceSetupCopy()->mEntries[i].mKartIndex = GetCurrentKartIndex(i);
        GetRaceSetupCopy()->mEntries[i].mPlayerKind = GetCurrentPlayerKind(i);
        if (GetCurrentUseTeams() != 0) {
            GetRaceSetupCopy()->mEntries[i].mTeamIndex = GetCurrentTeamIndex(i);
        } else {
            GetRaceSetupCopy()->mEntries[i].mTeamIndex = -1;
        }
        GetRaceSetupCopy()->mEntries[i].mUnk_10 = GetCurrentListedCpuSlot(i);
        GetRaceSetupCopy()->mEntries[i].mUnk_14 = 0;
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
    s32 i;

    for (i = 0; i < 0x1e; i++) {
        gMenuScene->mScreenCallbacks[i].mWriteRegisters = gMenuScreenCallbacks[i].mWriteRegisters;
        gMenuScene->mScreenCallbacks[i].mUpdate = gMenuScreenCallbacks[i].mUpdate;
    }
}

void WriteMenuSceneRegisters(void) {
    if (IsDownloadBootWrapper() == 0) {
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

void SetMainBg2RecordParams(DisplaySettings *displaySettings, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 e,
                            u32 cntVal8, u32 cntVal2) {
    SetBg2RecordParams(&displaySettings->mMainBgRecords, cntLow2, cntBit6, cntVal14, e, cntVal8, cntVal2);
}

void SetMainBg3RecordParams(DisplaySettings *displaySettings, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 e,
                            u32 cntVal8, u32 cntVal2) {
    SetBg3RecordParams(&displaySettings->mMainBgRecords, cntLow2, cntBit6, cntVal14, e, cntVal8, cntVal2);
}

void SetSubBg0Record(DisplaySettings *displaySettings, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 cntVal7, u32 cntVal8,
                     u32 cntVal2, u32 cntVal13) {
    SetBg0Record(&displaySettings->mSubBgRecords, cntLow2, cntBit6, cntVal14, cntVal7, cntVal8, cntVal2, cntVal13);
}

void SetSubBg1Record(DisplaySettings *displaySettings, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 cntVal7, u32 cntVal8,
                     u32 cntVal2, u32 cntVal13) {
    SetBg1Record(&displaySettings->mSubBgRecords, cntLow2, cntBit6, cntVal14, cntVal7, cntVal8, cntVal2, cntVal13);
}

void SetSubBg2RecordParams(DisplaySettings *displaySettings, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 e, u32 cntVal8,
                           u32 cntVal2) {
    SetBg2RecordParams(&displaySettings->mSubBgRecords, cntLow2, cntBit6, cntVal14, e, cntVal8, cntVal2);
}

void SetSubBg3RecordParams(DisplaySettings *displaySettings, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 e, u32 cntVal8,
                           u32 cntVal2) {
    SetBg3RecordParams(&displaySettings->mSubBgRecords, cntLow2, cntBit6, cntVal14, e, cntVal8, cntVal2);
}

void SetMainDispcntBits(u32 bits) {
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffcfffef) | bits;
}

void SetSubDispcntBits(u32 bits) {
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffcfffef) | bits;
}
