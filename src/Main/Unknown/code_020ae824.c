#include "Main/Unknown/code_020ae824.h"
#include "Main/Unknown/code_0203be88.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020b33d8.h"
#include "Main/Unknown/code_020b3724.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b9994.h"
#include "Main/Unknown/code_020bb5ec.h"
#include "Main/Unknown/code_020bc11c.h"
#include "Main/Unknown/code_020be950.h"
#include "Main/Unknown/code_020c06c4.h"
#include "Main/Unknown/code_020c2118.h"
#include "Main/Unknown/code_020c3e44.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_02022030.h"
#include "Main/Unknown/code_020c476c.h"
#include "Main/Unknown/code_020c53c4.h"
#include "Main/Unknown/code_020c5e30.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020cffd0.h"
#include "Main/Unknown/code_020d1158.h"
#include "Main/Unknown/code_020d12e0.h"
#include "Main/Unknown/code_020d1298.h"
#include "Main/Unknown/code_020d18d4.h"
#include "Main/Unknown/code_020f36d8.h"
#include "code_0200eddc.h"
#include "code_0214c778.h"
#include "Main/Unknown/code_0203c5f8.h"

void DrawRaceHud(void) {
    u32 raceKindOrMode;
    s32 subScreenState;

    raceKindOrMode = gRaceSetup->mRaceKind;
    if (raceKindOrMode == RACE_KIND_START_GP) {
        DrawRaceStartGp();
        return;
    }
    if (raceKindOrMode == RACE_KIND_AWARD) {
        return;
    }
    if (raceKindOrMode == RACE_KIND_STAFF_ROLL) {
        DrawEndingStaffRoll();
        return;
    }
    if (gRaceHud->mEnabled == FALSE) {
        return;
    }
    UpdateRaceStartSequenceSounds();
    RaceHudDrawNop();
    gRaceHud->mMainOam.mOamCount = 0;
    gRaceHud->mMainOam.mMatrixCount = 0;
    if (gRaceSetup->mRaceKind == RACE_KIND_START_BATTLE) {
        DrawRaceStartBattle(&gRaceHud->mMainOam);
    }
    raceKindOrMode = gRaceSetup->mMode;
    if ((raceKindOrMode == MODE_BATTLE ? gRaceProgress->mRaceDone
         : raceKindOrMode == MODE_MISSION_RUN
             ? IsFramesSinceFinishPastWait()
             : (IsKartEnded(GetFollowedKartOrEntryIndex()) != 0 && gRaceHud->mShowLapTime == 0)) == 0) {
        DrawRaceItemSlot(&gRaceHud->mMainOam);
        DrawRaceLapAndTimeDifference(&gRaceHud->mMainOam);
        DrawRaceMNumberPair(&gRaceHud->mMainOam);
        DrawRaceGoalTimes(&gRaceHud->mMainOam);
        DrawRaceLinkLevel(&gRaceHud->mMainOam);
        DrawRaceModeCount(&gRaceHud->mMainOam);
        DrawRaceGoalM(&gRaceHud->mMainOam);
    } else {
        DrawRaceGoalTimes(&gRaceHud->mMainOam);
        DrawRaceLinkLevel(&gRaceHud->mMainOam);
        DrawRaceGoalM(&gRaceHud->mMainOam);
    }
    DC_FlushRange(&gRaceHud->mMainOam, 0x400);
    MI_DmaFill32(3, &gRaceHud->mMainOam.mOams[gRaceHud->mMainOam.mOamCount], 0xc0,
                 (0x80 - gRaceHud->mMainOam.mOamCount) << 3);
    gRaceHud->mSubOam.mOamCount = 0;
    gRaceHud->mSubOam.mMatrixCount = 0;
    subScreenState = gRaceHud->mSubScreenState;
    if (subScreenState != 4 && subScreenState != 5) {
        DrawRaceTimeDigits(&gRaceHud->mSubOam);
    }
    DrawRaceRankList(&gRaceHud->mSubOam);
    DC_FlushRange(&gRaceHud->mSubOam, 0x400);
    MI_DmaFill32(3, &gRaceHud->mSubOam.mOams[gRaceHud->mSubOam.mOamCount], 0xc0,
                 (0x80 - gRaceHud->mSubOam.mOamCount) << 3);
    switch (gRaceHud->mSubScreenState) {
        case 0:
            DrawRaceHudSubScreenCellGroups(&gRaceHud->mSubOam);
            break;
        case 1:
        case 2:
        case 3:
            DrawRaceHudSubScreenCellGroups(&gRaceHud->mSubOam);
            DrawRaceTaPositions(&gRaceHud->mSubOam);
            break;
        case 4:
        case 5:
            DrawRaceGoalS(&gRaceHud->mSubOam);
            break;
        case 6:
            DrawRaceNewRecordTa(&gRaceHud->mSubOam);
            break;
    }
}
