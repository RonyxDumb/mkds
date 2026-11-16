#include "Main/Unknown/code_0203e74c.h"
#include "Main/Unknown/code_0203e000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0203f2b4.h"
#include "Main/Unknown/code_0203f280.h"
#include "Main/Unknown/code_0203f320.h"
#include "Main/Race/RaceProgress.h"
#include "Main/Unknown/code_0204a904.h"
#include "Main/Unknown/code_0204a928.h"
#include "Main/Unknown/code_020401ac.h"
#include "Main/Unknown/code_0205a92c.h"
#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_020a12b8.h"
#include "Main/Unknown/code_020c70ec.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217a000.h"
#include "00/code_0219b580.h"
#include "code_02147cd8.h"
#include "Main/Kart/KartTimes.h"
#include "Main/Unknown/code_02077bc0.h"

s32 rstat_shouldTryFinish(void) {
    BOOL endConditionMet;
    u16 kartIndex;
    s32 s;
    BOOL f;
    s32 v;
    s32 kartCount;
    s32 removedCount;
    RaceSetup *raceSetup;
    RaceProgress *raceProgress;
    raceSetup = gRaceMultiConfig;
    switch (raceSetup->mMode) {
        case MODE_GRAND_PRIX:
            endConditionMet = TRUE;
            for (kartIndex = 0; kartIndex < (u32) gRaceMultiConfig->mKartCount; kartIndex++) {
                f = FALSE;
                s = raceSetup->mCurrentEntries[kartIndex].mPlayer.mKind;
                if ((u32) s <= 3 && ((1 << s) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) != 0) {
                    f = TRUE;
                }
                if (f != FALSE) {
                    s = gRaceStatus->mUnk_000[kartIndex].mStatus;
                    f = FALSE;
                    switch (s) {
                        case 1:
                        case 2:
                        case 3:
                            f = TRUE;
                            break;
                    }
                    if (f == FALSE) {
                        endConditionMet = FALSE;
                        break;
                    }
                }
            }
            break;
        case MODE_VS:
            endConditionMet = TRUE;
            raceProgress = gRaceStatus;
            if (raceProgress->mUnk_000[0].mFinishedCount <
                (s32) rstat_rconf_getDriverCount() - (raceProgress->mUnk_000[0].mRemovedCount + 1)) {
                for (kartIndex = 0; kartIndex < rstat_rconf_getDriverCount(); kartIndex++) {
                    if (rstat_rconf_isDriverValidAndNoEnemy(kartIndex) != FALSE && rstat_hasDriverFinished(kartIndex) == 0) {
                        if (rstat_203F2B4(kartIndex) == FALSE) {
                            endConditionMet = FALSE;
                            break;
                        }
                    }
                }
            }
            if (endConditionMet == FALSE && rstat_rconf_getRules() == 1) {
                if (rstat_hasDriverFinished(rstat_getFirstPlaceDriverId()) != 0) {
                    endConditionMet = TRUE;
                }
            }
            break;
        case 5:
            v = gStruct217AA18->mKartOfParticipant[func_ov000_0219bb50()];
            if (v < 0) {
                endConditionMet = FALSE;
            } else {
                kartCount = gRaceMultiConfig->mKartCount;
                raceProgress = gRaceStatus;
                removedCount = raceProgress->mUnk_000[0].mRemovedCount;
                if (kartCount - removedCount <= 1) {
                    endConditionMet = FALSE;
                } else {
                    s = raceProgress->mUnk_000[(u16) v].mStatus;
                    f = FALSE;
                    switch (s) {
                        case 1:
                        case 2:
                        case 3:
                            f = TRUE;
                            break;
                    }
                    if (f == FALSE) {
                        endConditionMet = raceProgress->mUnk_000[0].mFinishedCount + removedCount >= kartCount - 1;
                    } else {
                        endConditionMet = raceProgress->mUnk_000[0].mFinishedCount + removedCount >= kartCount;
                    }
                }
            }
            break;
        case MODE_TIME_ATTACK:
            endConditionMet = FALSE;
            switch (gRaceStatus->mUnk_000[0].mStatus) {
                case 1:
                case 2:
                case 3:
                    endConditionMet = TRUE;
                    break;
            }
            break;
        case MODE_BATTLE:
            endConditionMet = TRUE;
            for (kartIndex = 0; kartIndex < (u32) raceSetup->mKartCount; kartIndex++) {
                f = FALSE;
                s = raceSetup->mCurrentEntries[kartIndex].mPlayer.mKind;
                if ((u32) s <= 3 && ((1 << s) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) != 0) {
                    f = TRUE;
                }
                if (f != FALSE) {
                    if (mgcnt_isDriverDead(kartIndex) == FALSE) {
                        endConditionMet = FALSE;
                        break;
                    }
                }
                raceSetup = gRaceMultiConfig;
            }
            break;
        case MODE_MISSION_RUN:
            endConditionMet = FALSE;
            if (raceSetup->mMissionKind == 6 && gRaceStatus->mUnk_000[0].mFinishedCount != 0) {
                endConditionMet = TRUE;
            }
            break;
        default:
            endConditionMet = FALSE;
            break;
    }
    return endConditionMet;
}

void rstat_tryFinishGpVs(void) {
    u16 kartIndex;
    RaceProgressKart *raceProgressKart;
    s32 status;
    BOOL ended;
    BOOL u;
    BOOL v;
    Unk0217aa1c_144_00 *finishTime;
    u32 frames;
    u = FALSE;
    v = FALSE;
    for (kartIndex = 0; kartIndex < (u32) gRaceMultiConfig->mKartCount; kartIndex++) {
        status = (OFFSET_PTR(Unk0217561c_000, gRaceStatus, kartIndex * 0x8c))->mStatus;
        ended = FALSE;
        switch (status) {
            case 1:
            case 2:
            case 3:
                ended = TRUE;
                break;
        }
        if (ended == FALSE && status != 4) {
            raceProgressKart = OFFSET_PTR(RaceProgressKart, &gRaceStatus->mKarts[0], kartIndex * 0x8c);
            finishTime = &raceProgressKart->mLapTimes[5];
            frames = gRaceStatus->mUnk_000[0].mElapsedFrames;
            if (gRaceMultiConfig->mMode == MODE_GRAND_PRIX) {
                if (raceProgressKart->mRaceProgress > 0) {
                    frames = (u32) (frames * FX_Inv(raceProgressKart->mRaceProgress)) >> 12;
                    if (frames > 0x57e40) {
                        frames = 0x57e40;
                    }
                } else {
                    frames = 0x57e40;
                }
            }
            rstat_calculateTime(&finishTime->mUnk_02, &finishTime->mUnk_03, &finishTime->mUnk_00, u, frames);
            rstat_finishDriver(raceProgressKart, v);
        }
    }
    gRaceStatus->mUnk_000[0].mFinishedCount = gRaceMultiConfig->mKartCount;
}

void rstat_tryFinishNt(void) {
    u16 kartIndex;
    RaceProgressKart *raceProgressKart;
    s32 status;
    BOOL ended;
    BOOL u;
    BOOL v;
    Unk0217aa1c_144_00 *finishTime;
    u32 frames;
    u = FALSE;
    v = FALSE;
    for (kartIndex = 0; kartIndex < (u32) gRaceMultiConfig->mKartCount; kartIndex++) {
        status = (OFFSET_PTR(Unk0217561c_000, gRaceStatus, kartIndex * 0x8c))->mStatus;
        ended = FALSE;
        switch (status) {
            case 1:
            case 2:
            case 3:
                ended = TRUE;
                break;
        }
        if (ended == FALSE && status != 4) {
            raceProgressKart = OFFSET_PTR(RaceProgressKart, &gRaceStatus->mKarts[0], kartIndex * 0x8c);
            finishTime = &raceProgressKart->mLapTimes[5];
            frames = gRaceStatus->mUnk_000[0].mElapsedFrames;
            if (gRaceMultiConfig->mMode == MODE_GRAND_PRIX) {
                if (raceProgressKart->mRaceProgress > 0) {
                    frames = (u32) (frames * FX_Inv(raceProgressKart->mRaceProgress)) >> 12;
                    if (frames > 0x57e40) {
                        frames = 0x57e40;
                    }
                } else {
                    frames = 0x57e40;
                }
            }
            rstat_calculateTime(&finishTime->mUnk_02, &finishTime->mUnk_03, &finishTime->mUnk_00, u, frames);
            func_0205ae8c(kartIndex);
            rstat_finishDriver(raceProgressKart, v);
        }
    }
    gRaceStatus->mUnk_000[0].mFinishedCount = gRaceMultiConfig->mKartCount;
}

void rstat_tryFinishMr(void) {
    u16 kartIndex;
    RaceProgressKart *raceProgressKart;
    EntryKartCounters *entryKartCounters;
    s32 status;
    BOOL ended;
    u32 succeeded;
    u8 *missionSettings;
    Unk0217aa1c_144_00 *finishTime;
    u32 frames;
    for (kartIndex = 0; kartIndex < (u32) gRaceMultiConfig->mKartCount; kartIndex++) {
        status = (OFFSET_PTR(Unk0217561c_000, gRaceStatus, kartIndex * 0x8c))->mStatus;
        ended = FALSE;
        switch (status) {
            case 1:
            case 2:
            case 3:
                ended = TRUE;
                break;
        }
        if (ended == FALSE) {
            raceProgressKart = OFFSET_PTR(RaceProgressKart, &gRaceStatus->mKarts[0], kartIndex * 0x8c);
            finishTime = &raceProgressKart->mLapTimes[5];
            frames = gRaceStatus->mUnk_000[0].mElapsedFrames;
            if (gRaceMultiConfig->mMode == MODE_GRAND_PRIX) {
                if (raceProgressKart->mRaceProgress > 0) {
                    frames = (u32) (frames * FX_Inv(raceProgressKart->mRaceProgress)) >> 12;
                    if (frames > 0x57e40) {
                        frames = 0x57e40;
                    }
                } else {
                    frames = 0x57e40;
                }
            }
            rstat_calculateTime(&finishTime->mUnk_02, &finishTime->mUnk_03, &finishTime->mUnk_00, 0, frames);
            succeeded = 1;
            missionSettings = (u8 *) &gRaceMultiConfig->mMissionTimeLimitFrameCount;
            entryKartCounters = driver_getPlayerStatistics();
            switch (missionSettings[7]) {
                case 4:
                    if (missionSettings[0xf] > (u32) entryKartCounters->mUnk_04) {
                        succeeded = 0;
                    }
                    break;
                case 6:
                    if (((u32) (raceProgressKart->mUnk_3c << 28) >> 28) != 1) {
                        succeeded = 0;
                    }
                    break;
            }
            if (succeeded != 0) {
                u32 storedKartIndex = (u32) (raceProgressKart->mUnk_3c << 24) >> 28;
                if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
                    rstat_finishMission(storedKartIndex, 0);
                }
            } else {
                rstat_finishMission((u32) (raceProgressKart->mUnk_3c << 24) >> 28, 4);
            }
        }
    }
    gRaceStatus->mUnk_000[0].mFinishedCount = gRaceMultiConfig->mKartCount;
}

void rstat_finishDriver(RaceProgressKart *raceProgressKart, s32 finished) {
    Unk0217aa1c_144_00 *finishTime;
    s32 inputSlotIndex;
    s32 mode;
    s16 score;
    inputSlotIndex = gRaceMultiConfig->mCurrentEntries[(u32) (raceProgressKart->mUnk_3c << 24) >> 28].mPlayer.mIndex;
    if (finished != 0) {
        raceProgressKart->mStatus = 1;
    } else {
        raceProgressKart->mStatus = 3;
    }
    switch (gInputUnits[inputSlotIndex].mSourceKind) {
        case 2:
            irec_stopRecording(&gInputUnits[inputSlotIndex].mUnk_28);
            break;
        case 1:
            irec_stopPlayback((KeyRecording *) &gInputUnits[inputSlotIndex].mUnk_28);
            break;
    }
    raceProgressKart->mFlags |= 8;
    if ((raceProgressKart->mFlags & 1) != 0 && (raceProgressKart->mFlags & 0x10) == 0) {
        r2dtar_20C7164();
    }
    finishTime = &raceProgressKart->mLapTimes[5];
    if (finished != 0) {
        raceProgressKart->mFinishTimeMs =
            (finishTime->mUnk_02 * 0x3c + finishTime->mUnk_03) * 1000 + finishTime->mUnk_00;
    } else if (gRaceMultiConfig->mMode != 5) {
        raceProgressKart->mFinishTimeMs = 0x5b8d80;
    }
    mode = gRaceMultiConfig->mMode;
    if (mode == MODE_GRAND_PRIX || mode == MODE_MISSION_RUN) {
        if ((raceProgressKart->mFlags & 1) != 0) {
            raceProgressKart->mScore = rstat_calculateSkillRankPoints((u32) (raceProgressKart->mUnk_3c << 24) >> 28);
            score = raceProgressKart->mScore;
            if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
                rres_sRaceResults->mUnk_140 = score;
            } else {
                rres_sRaceResults->mUnk_140 += score;
            }
        }
    }
    gRaceStatus->mUnk_000[0].mFinishedCount++;
}

void rstat_finishMission(s32 kartIndex, s32 endKind) {
    Kart *kart;
    Unk0217aa1c_144_00 finishTime;
    s32 status;
    BOOL ended;
    RaceProgressKart *raceProgressKart;
    raceProgressKart = OFFSET_PTR(RaceProgressKart, &gRaceStatus->mKarts[0], kartIndex * 0x8c);
    status = raceProgressKart->mStatus;
    ended = FALSE;
    switch (status) {
        case 1:
        case 2:
        case 3:
            ended = TRUE;
            break;
    }
    if (ended != FALSE) {
        return;
    }
    if ((raceProgressKart->mFlags & 0x10) != 0) {
        return;
    }
    if ((raceProgressKart->mFlags & 0x20) != 0) {
        return;
    }
    kart = driver_getById(kartIndex);
    raceProgressKart = OFFSET_PTR(RaceProgressKart, &gRaceStatus->mKarts[0], kartIndex * 0x8c);
    gRaceStatus->mUnk_000[0].mClockEnabled = 0;
    rstat_calculateTime(&finishTime.mUnk_02, &finishTime.mUnk_03, &finishTime.mUnk_00, 0,
                    gRaceStatus->mUnk_000[0].mElapsedFrames);
    raceProgressKart->mLapTimes[5] = finishTime;
    if ((raceProgressKart->mFlags & 1) != 0) {
        gRaceStatus->mEntryEndKind = endKind;
        kart->mUnk_7c |= 0x20000000;
        kart->mUnk_48 &= ~0x2000000;
        if (endKind == 0) {
            raceProgressKart->mFlags |= 0x10;
            gRaceStatus->mFramesSinceFinish = 0;
            if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
                mgcnt_tryFinish();
            }
        } else {
            raceProgressKart->mFlags |= 0x20;
            gRaceStatus->mFramesSinceFailure = 0;
            if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
                ((void (*)(s32)) mgcnt_killDriver)(kartIndex);
            }
        }
    }
    rstat_finishDriver(raceProgressKart, endKind == 0);
    if (rstat_shouldTryFinish() == 0) {
        return;
    }
    switch (gRaceMultiConfig->mMode) {
        case MODE_BATTLE:
            mgcnt_tryFinish();
            return;
        case MODE_MISSION_RUN:
            rstat_tryFinishMr();
            return;
        case 5:
            rstat_tryFinishNt();
            return;
        default:
            rstat_tryFinishGpVs();
            return;
        case MODE_TIME_ATTACK:
            return;
    }
}

void rstat_winMission(u16 kartIndex) {
    if (gRaceMultiConfig->mMode != MODE_MISSION_RUN) {
        return;
    }
    rstat_finishMission(kartIndex, 0);
}
