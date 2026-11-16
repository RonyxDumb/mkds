#include "Main/Unknown/code_020ae824.h"
#include "Main/Unknown/code_0203be88.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Race/RaceStartSequence.h"
#include "Main/Unknown/code_020b3724.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b9994.h"
#include "Main/Unknown/code_020bb5ec.h"
#include "Main/Race/RaceRankList.h"
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
#include "Main/Kart/KartTimes.h"

void r2d_render(void) {
    u32 v;
    s32 subScreenState;

    v = gRaceMultiConfig->mRaceKind;
    if (v == RACE_KIND_START_GP) {
        cint_render2d();
        return;
    }
    if (v == RACE_KIND_AWARD) {
        return;
    }
    if (v == RACE_KIND_STAFF_ROLL) {
        r2d_renderStaffRoll();
        return;
    }
    if (r2d_sStatus->mEnabled == FALSE) {
        return;
    }
    UpdateRaceStartSequenceSounds();
    RaceHudDrawNop();
    r2d_sStatus->mMainOamCount = 0;
    r2d_sStatus->mMainMatrixCount = 0;
    if (gRaceMultiConfig->mRaceKind == 4) {
        r2d_renderBattleIntro((RaceHudOamBuffer *) r2d_sStatus->mMainOam);
    }
    v = gRaceMultiConfig->mMode;
    if ((v == MODE_BATTLE ? gRaceStatus->mRaceDone
         : v == MODE_MISSION_RUN
             ? rstat_isMrWinDelayOver()
             : (rstat_hasDriverFinished(Race_GetPlayerId()) != 0 && r2d_sStatus->mShowLapTime == 0)) == 0) {
        r2d_renderItemSpinner((RaceHudOamBuffer *) r2d_sStatus->mMainOam);
        r2d_renderLapAndTimeDiff((RaceHudOamBuffer *) r2d_sStatus->mMainOam);
        r2d_renderRaceNumber((RaceHudOamBuffer *) r2d_sStatus->mMainOam);
        DrawRaceGoalTimes((RaceHudOamBuffer *) r2d_sStatus->mMainOam);
        DrawRaceLinkLevel((RaceHudOamBuffer *) r2d_sStatus->mMainOam);
        r2d_20B9DFC((RaceHudOamBuffer *) r2d_sStatus->mMainOam);
        DrawRaceGoalM((RaceHudOamBuffer *) r2d_sStatus->mMainOam);
    } else {
        DrawRaceGoalTimes((RaceHudOamBuffer *) r2d_sStatus->mMainOam);
        DrawRaceLinkLevel((RaceHudOamBuffer *) r2d_sStatus->mMainOam);
        DrawRaceGoalM((RaceHudOamBuffer *) r2d_sStatus->mMainOam);
    }
    DC_FlushRange(r2d_sStatus->mMainOam, 0x400);
    MI_DmaFill32(3, r2d_sStatus->mMainOam + r2d_sStatus->mMainOamCount * 8, 0xc0, (0x80 - r2d_sStatus->mMainOamCount) << 3);
    r2d_sStatus->mSubOamCount = 0;
    r2d_sStatus->mSubMatrixCount = 0;
    subScreenState = r2d_sStatus->mSubScreenState;
    if (subScreenState != 4 && subScreenState != 5) {
        DrawRaceTimeDigits((RaceHudOamBuffer *) r2d_sStatus->mSubOam);
    }
    DrawRaceRankList((RaceHudOamBuffer *) r2d_sStatus->mSubOam);
    DC_FlushRange(r2d_sStatus->mSubOam, 0x400);
    MI_DmaFill32(3, r2d_sStatus->mSubOam + r2d_sStatus->mSubOamCount * 8, 0xc0, (0x80 - r2d_sStatus->mSubOamCount) << 3);
    switch (r2d_sStatus->mSubScreenState) {
        case 0:
            mpicn_render(r2d_sStatus->mSubOam);
            break;
        case 1:
        case 2:
        case 3:
            mpicn_render(r2d_sStatus->mSubOam);
            r2d_renderMapPath((RaceHudOamBuffer *) r2d_sStatus->mSubOam);
            break;
        case 4:
        case 5:
            r2dres_render((RaceHudOamBuffer *) r2d_sStatus->mSubOam);
            break;
        case 6:
            r2dtar_render((RaceHudOamBuffer *) r2d_sStatus->mSubOam);
            break;
    }
}
