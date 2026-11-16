#include "Main/Race/race_progress_kart.h"
#include "Main/Menu/wl_menu_kind.h"
#include "Main/System/heap.h"
#include "Main/Race/race_end_condition.h"
#include "Main/Race/race_checkpoint_progress.h"
#include "Main/Race/race_setup_input.h"
#include "Main/Race/race_keys.h"
#include "Main/Kart/karts.h"
#include "Main/Race/race_scene_callbacks.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "Main/System/input_slots.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"
#include "Main/System/result_archive_path.h"
#include "Main/System/key_recording_finish.h"
#include "Main/System/thread_function_queue.h"
#include "Main/Scene/run_scenes.h"
#include "Main/Save/emblem_block.h"
#include "Main/Race/race_score.h"
#include "Main/Race/standings_balloons.h"
#include "Main/Sound/race_end_seq.h"
#include "Main/Race/race_hud_lap_time.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/System/backup_net_camera_work.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"
#include "fixed_vector_math.h"
#include "card_rom_backup_access.h"
#include "Main/Race/kart_standing_rank.h"
#include "Main/Menu/menu_shared_clear.h"
#include "Main/Save/ghost_record_file.h"
#include "Main/System/init_after_startup.h"


#pragma opt_rebuildconditionals off

static inline s32 RaceProgressKartIsConnectionActive(ConnectionWork *connectionWork) {
    BOOL result = FALSE;
    if ((connectionWork == NULL ? CONNECTION_MODE_NONE : connectionWork->mConnectionMode) != CONNECTION_MODE_NONE &&
        connectionWork->mState != CONNECTION_STATE_ENDED) {
        result = TRUE;
    }
    return result;
}

static inline void ReplaceDisconnectedHumansWithCpu(void) {
    u16 entryIndex;

    if (g_GlobalCO->mRaceKind == RACE_KIND_NORMAL && GetNextSceneId() != SCENE_RESULT &&
        (GetNextSceneId() != SCENE_WL_MENU || g_GlobalB488->mWLMenuKind != WL_MENU_KIND_TO_RESULT) &&
        RaceProgressKartIsConnectionActive(g_GlobalZE) != 0) {
        for (entryIndex = 0; entryIndex < (u32) g_GlobalCO->mKartCount; entryIndex++) {
            if (g_GlobalCO->mCurrentEntries[entryIndex].mPlayer.mKind == PLAYER_KIND_HUMAN &&
                (g_GlobalZE->mParticipantMask & (1 << g_GlobalZE->mParticipantIndexByPos[entryIndex])) == 0) {
                ReplaceEntryWithCpu(entryIndex);
            }
        }
    }
}

static inline s32 RaceProgressKartIsBackupBusy(void) {
    s32 busy;
    if (g_SaveDataHolder->mBusy == 0) {
        busy = g_SaveDataIoManager->mBackupEnabled != 0 ? g_SaveDataIoManager->mCommandRunning : 0;
    } else {
        busy = 1;
    }
    return busy;
}

static inline u16 GetCheckpointRouteIndex(u16 checkpoint) {
    u16 routeIndex;
    u16 firstEntry;
    u16 endEntry;
    CourseMapRoute *route;

    for (routeIndex = 0; routeIndex < g_GlobalPE->mCheckpointRouteCount; routeIndex++) {
        route = &g_GlobalPE->mCheckpointRoutes[routeIndex];
        firstEntry = route->mFirstEntry;
        endEntry = firstEntry + route->mEntryCount;
        if (checkpoint >= firstEntry && checkpoint < endEntry) {
            return routeIndex;
        }
    }
    return 0;
}

static inline s16 FindKartCheckpoint(RaceProgressKart *kart, s32 *outProgress, Vec3 *position) {
    u16 routeIndex;
    u16 checkpoint;
    u16 lo;
    u16 hi;
    CourseMapRoute *route;

    for (routeIndex = 0; routeIndex < g_GlobalPE->mCheckpointRouteCount; routeIndex++) {
        route = &g_GlobalPE->mCheckpointRoutes[routeIndex];
        lo = route->mFirstEntry;
        hi = lo + route->mEntryCount;
        for (checkpoint = lo; checkpoint < hi; checkpoint++) {
            if (StructRC_SomeFn_0(kart, outProgress, position, routeIndex, checkpoint) != 0) {
                return checkpoint;
            }
        }
    }
    return -1;
}

static inline s32 ComputeRouteLapProgress(CourseMapRoute *route, u16 checkpoint, s32 progress) {
    s32 routeProgress;
    s32 value;

    value = TO_FIXED12(checkpoint - route->mFirstEntry);
    if (route->mEntryCount == 0) {
        routeProgress = 0;
    } else {
        routeProgress = FX_Div(value + progress, TO_FIXED12(route->mEntryCount));
    }
    value = routeProgress + TO_FIXED12(route->mLapProgressBase);
    return MUL_FIXED12_ROUNDED(value, g_GlobalMV->mLapProgressScale);
}

static inline void FinishKartIfMissionRun(s32 kartIndex) {
    if (g_GlobalCO->mMode == MODE_MISSION_RUN) {
        FinishRaceProgressKartWithEndKind(kartIndex, RACE_END_KIND_GOAL);
    }
}

void CompleteRaceProgressKartLap(RaceProgressKart *kart) {
    BOOL flag;
    BOOL missionTestPassed;
    MissionSettings *missionSettings;
    EntryKartCounters *entryKartCounters;

    if (kart->mLap < 0x7fffffff) {
        kart->mLap = kart->mLap + 1;
    }
    kart->mCheckpointNumber = -1;
    kart->mInOrderCheckpointNumber = -1;
    flag = FALSE;
    switch (kart->mStatus) {
        case RACE_PROGRESS_KART_STATUS_GOAL_REACHED:
        case RACE_PROGRESS_KART_STATUS_BATTLE_LOSER:
        case RACE_PROGRESS_KART_STATUS_ENDED_NO_GOAL:
            flag = TRUE;
            break;
    }
    if (flag != FALSE) {
        return;
    }
    if (kart->mLap <= kart->mHighestLap) {
        return;
    }
    if ((kart->mFlags & RACE_PROGRESS_KART_FLAG_LOCAL_ENTRY) != 0) {
        AdvanceSceneSoundLap();
    }
    StoreRaceProgressKartLapTime(kart, kart->mLap > GetCurrentLapCount());
    kart->mHighestLap = kart->mLap;
    if ((kart->mFlags & RACE_PROGRESS_KART_FLAG_LOCAL_ENTRY) != 0) {
        StartRaceHudLapTimeDisplay();
    }
    flag = FALSE;
    if (g_GlobalCO->mMode != MODE_MISSION_RUN) {
        flag = TRUE;
    } else {
        switch (g_GlobalCO->mMissionKind) {
            case MISSION_KIND_LAPS:
            case MISSION_KIND_LAPS_MINI_TURBO_COUNT:
            case MISSION_KIND_LAPS_FIRST_PLACE:
                flag = TRUE;
                break;
        }
    }
    if (flag == FALSE) {
        return;
    }
    if (kart->mHighestLap <= GetCurrentLapCount()) {
        return;
    }
    kart->mHighestLap = GetCurrentLapCount();
    if (g_GlobalCO->mMode == MODE_MISSION_RUN) {
        missionSettings = &g_GlobalCO->mMissionSettings;
        missionTestPassed = TRUE;
        entryKartCounters = GetGlobalRK();
        switch (missionSettings->mMissionKind) {
            case MISSION_KIND_LAPS_MINI_TURBO_COUNT:
                if (missionSettings->mMissionRunCountLimit > (u32) entryKartCounters->mMiniTurboCount) {
                    missionTestPassed = FALSE;
                }
                break;
            case MISSION_KIND_LAPS_FIRST_PLACE:
                if (kart->mRank != 1) {
                    missionTestPassed = FALSE;
                }
                break;
        }
        if (missionTestPassed != FALSE) {
            FinishKartIfMissionRun(kart->mIndex);
        } else {
            FinishRaceProgressKartWithEndKind(kart->mIndex, RACE_END_KIND_FAILED);
        }
    } else {
        if ((kart->mFlags & RACE_PROGRESS_KART_FLAG_LOCAL_ENTRY) == 0 && g_GlobalCO->mMode == MODE_WIFI) {
            return;
        }
        kart->mFlags |= RACE_PROGRESS_KART_FLAG_FINISH_PENDING;
    }
}

void SetRaceProgressKartFinishRequest(u32 kartIndex, u32 flag) {
    RaceProgressKart *kart;
    u16 finishRequest;

    kart = &g_GlobalMV->mKarts[kartIndex];
    finishRequest = flag != 0 ? 1 : 2;
    kart->mRankIndexRequestBits = (kart->mRankIndexRequestBits & ~0x300) | ((finishRequest & 3) << 8);
    if (g_GlobalMV->mHeader.mFinishedCount + g_GlobalMV->mHeader.mRemovedCount >= g_GlobalCO->mKartCount) {
        FinishRaceProgress();
    }
}

void EnterRaceProgressKartCheckpoint(RaceProgressKart *kart, s32 checkpoint) {
    s16 checkpointNumber;

    checkpointNumber = g_GlobalPE->mCheckpoints[kart->mCheckpoint].mNumber;
    if (checkpointNumber != -1) {
        kart->mCheckpointNumber = checkpointNumber;
        if (kart->mInOrderCheckpointNumber + 1 >= checkpointNumber) {
            kart->mInOrderCheckpointNumber = checkpointNumber;
        }
    }
    if (checkpoint == 0 && kart->mInOrderCheckpointNumber >= g_GlobalPE->mNumberedCheckpointCount - 1) {
        CompleteRaceProgressKartLap(kart);
    } else if (kart->mCheckpoint == 0 && checkpoint == g_GlobalPE->mLastCheckpoint) {
        if (kart->mLap > -100) {
            kart->mLap = kart->mLap - 1;
        }
        kart->mCheckpointNumber = g_GlobalPE->mNumberedCheckpointCount - 1;
        kart->mInOrderCheckpointNumber = g_GlobalPE->mNumberedCheckpointCount - 1;
    }
    kart->mCheckpoint = checkpoint;
    kart->mRoute = GetCheckpointRouteIndex(checkpoint);
}

void UpdateRaceProgressKart(Vec3 *position, RaceProgressKart *kart) {
    s32 checkpointProgress;
    u16 checkpoint;
    u16 routeIndex;
    s16 foundCheckpoint;
    s32 lapProgress;
    s32 value;
    CourseMapRoute *route;

    checkpoint = kart->mCheckpoint;
    routeIndex = kart->mRoute;
    foundCheckpoint = checkpoint;
    checkpointProgress = 0;
    if (StructMQHasFlagB_800(kart->mIndex) != 0) {
        return;
    }
    if (StructRC_SomeFn_0(kart, &checkpointProgress, position, routeIndex, checkpoint) == 0) {
        if (checkpointProgress >= 0) {
            foundCheckpoint = StructRC_SomeFn(kart, &checkpointProgress, position, routeIndex, checkpoint, 5);
            if (foundCheckpoint == -1) {
                foundCheckpoint =
                    StructRC_SomeFn_1(kart, &checkpointProgress, position, routeIndex, checkpoint, 5);
            }
        } else {
            foundCheckpoint =
                StructRC_SomeFn_1(kart, &checkpointProgress, position, routeIndex, checkpoint, 5);
            if (foundCheckpoint == -1) {
                foundCheckpoint =
                    StructRC_SomeFn(kart, &checkpointProgress, position, routeIndex, checkpoint, 5);
            }
        }
        if (foundCheckpoint == -1) {
            foundCheckpoint = FindKartCheckpoint(kart, &checkpointProgress, position);
        }
        if (foundCheckpoint == -1) {
            return;
        }
        routeIndex = GetCheckpointRouteIndex(foundCheckpoint);
    }
    route = &g_GlobalPE->mCheckpointRoutes[routeIndex];
    lapProgress = ComputeRouteLapProgress(route, foundCheckpoint, checkpointProgress);
    value = 0;
    if (foundCheckpoint != -1) {
        if (g_GlobalPE->mNumberedCheckpointCount >= 1) {
            value = g_GlobalMV->mCheckpointLapProgress[g_GlobalPE->mNumberedCheckpointCount - 1];
        }
        if (lapProgress <= g_GlobalMV->mCheckpointLapProgress[kart->mInOrderCheckpointNumber + 1]) {
            EnterRaceProgressKartCheckpoint(kart, foundCheckpoint);
        } else if (kart->mCheckpoint == 0 && lapProgress > value) {
            EnterRaceProgressKartCheckpoint(kart, foundCheckpoint);
        } else {
            checkpointProgress = kart->mCheckpointProgress;
            lapProgress = ComputeRouteLapProgress(route, kart->mCheckpoint, checkpointProgress);
        }
    }
    kart->mCheckpointProgress = checkpointProgress;
    kart->mLapProgress = lapProgress;
    value = TO_FIXED12(kart->mLap - 1) + kart->mLapProgress;
    kart->mRaceProgress = MUL_FIXED12_ROUNDED(value, g_GlobalMV->mRaceProgressScale);
}

void UpdateRaceProgressKarts(void) {
    IntPair forwardPair;
    s32 progressByKart[8];
    s32 progressByRank[8];
    s32 lapByRank[8];
    u16 kartByRank[8];
    Vec3 position;
    Vec3 forward;
    u16 kartOrRankIndex;
    s32 testedBitsIndex;
    RaceProgressKart *kart;
    BOOL flag;
    RaceProgress *raceProgress;
    IntPair *checkpointDirection;
    u16 unused;
    s32 finishedCount;
    s32 notRemovedCount;
    s32 insertPos;
    s32 rankIndex;
    s32 progressKey;
    s32 lapKey;
    s32 kartKey;
    u16 rankSlot;
    RaceProgressKart *statusKart;

    for (kartOrRankIndex = 0; kartOrRankIndex < (u32) g_GlobalCO->mKartCount; kartOrRankIndex++) {
        kart = &g_GlobalMV->mKarts[kartOrRankIndex];
        if (kart->mStatus != RACE_PROGRESS_KART_STATUS_REMOVED && g_GlobalCO->mRaceKind != RACE_KIND_STAFF_ROLL) {
            for (testedBitsIndex = 0; testedBitsIndex < 16; testedBitsIndex++) {
                kart->mCheckpointTestedBits[testedBitsIndex] = 0;
            }
            LoadRacerMQVectorB(&position, kartOrRankIndex);
            GetMQRacerVector333(GetRacerMQEntry(kartOrRankIndex), &forward);
            UpdateRaceProgressKart(&position, kart);
            flag = FALSE;
            if (IsKartOnBoostSurface(kart->mIndex) == 0) {
                checkpointDirection = &g_GlobalPE->mCheckpoints[kart->mCheckpoint].mDirection;
                forwardPair.mFirst = forward.x;
                forwardPair.mSecond = forward.z;
                if (ComputeDotOfPairsRounded(&forwardPair, checkpointDirection) < -1394) {
                    flag = TRUE;
                }
            }
            if (flag != FALSE) {
                kart->mFlags |= RACE_PROGRESS_KART_FLAG_AGAINST_CHECKPOINT;
            } else {
                kart->mFlags &= ~RACE_PROGRESS_KART_FLAG_AGAINST_CHECKPOINT;
            }
            progressByKart[kartOrRankIndex] = kart->mRaceProgress;
        }
    }
    if (g_GlobalCO->mKartCount > 1) {
        raceProgress = g_GlobalMV;
        notRemovedCount = g_GlobalCO->mKartCount - raceProgress->mHeader.mRemovedCount;
        finishedCount = raceProgress->mHeader.mFinishedCount;
        for (kartOrRankIndex = 0; kartOrRankIndex < (u32) g_GlobalCO->mKartCount; kartOrRankIndex++) {
            rankIndex = raceProgress->mKarts[kartOrRankIndex].mRank - 1;
            progressByRank[rankIndex] = progressByKart[kartOrRankIndex];
            kartByRank[rankIndex] = kartOrRankIndex;
            lapByRank[rankIndex] = raceProgress->mKarts[kartOrRankIndex].mLap;
        }
        for (kartOrRankIndex = finishedCount + 1; kartOrRankIndex < notRemovedCount; kartOrRankIndex++) {
            progressKey = progressByRank[kartOrRankIndex];
            kartKey = kartByRank[kartOrRankIndex];
            lapKey = lapByRank[kartOrRankIndex];
            for (insertPos = kartOrRankIndex;
                 insertPos > finishedCount &&
                 (lapByRank[insertPos - 1] < lapKey ||
                  (lapKey == lapByRank[insertPos - 1] && progressByRank[insertPos - 1] < progressKey));
                 insertPos--) {
                lapByRank[insertPos] = lapByRank[insertPos - 1];
                progressByRank[insertPos] = progressByRank[insertPos - 1];
                kartByRank[insertPos] = kartByRank[insertPos - 1];
            }
            progressByRank[insertPos] = progressKey;
            kartByRank[insertPos] = kartKey;
        }
        for (kartOrRankIndex = 0; kartOrRankIndex < (u32) g_GlobalCO->mKartCount; kartOrRankIndex++) {
            if (kartByRank[kartOrRankIndex] < 8) {
                g_GlobalMV->mKarts[kartByRank[kartOrRankIndex]].mRank = kartOrRankIndex + 1;
            }
        }
        g_GlobalMV->mKarts[kartByRank[0]].mFirstPlaceFrames++;
        for (rankSlot = 0; rankSlot < (u32) g_GlobalCO->mKartCount; rankSlot++) {
            g_GlobalMV->mKartAtRank[rankSlot] = kartByRank[rankSlot];
        }
        for (; rankSlot < 8; rankSlot++) {
            g_GlobalMV->mKartAtRank[rankSlot] = -1;
        }
    } else {
        g_GlobalMV->mKarts[0].mRank = 1;
        g_GlobalMV->mKarts[0].mFirstPlaceFrames++;
        g_GlobalMV->mKartAtRank[0] = 0;
        for (rankSlot = 1; rankSlot < 8; rankSlot++) {
            g_GlobalMV->mKartAtRank[rankSlot] = -1;
        }
    }
    flag = FALSE;
    switch (g_GlobalCO->mRaceKind) {
        case RACE_KIND_DEMO:
        case RACE_KIND_REPLAY:
        case RACE_KIND_STAFF_ROLL:
            flag = TRUE;
            break;
        case RACE_KIND_NORMAL:
            if (IsEntryRaceEnded() != 0) {
                flag = TRUE;
            }
            break;
    }
    g_GlobalMV->mEntryRaceEnded = flag;
    for (kartOrRankIndex = 0; kartOrRankIndex < (u32) g_GlobalCO->mKartCount; kartOrRankIndex++) {
        statusKart = &g_GlobalMV->mKarts[kartOrRankIndex];
        flag = FALSE;
        switch (statusKart->mStatus) {
            case RACE_PROGRESS_KART_STATUS_GOAL_REACHED:
            case RACE_PROGRESS_KART_STATUS_BATTLE_LOSER:
            case RACE_PROGRESS_KART_STATUS_ENDED_NO_GOAL:
                flag = TRUE;
                break;
        }
        if (flag == FALSE && (statusKart->mFlags & RACE_PROGRESS_KART_FLAG_FINISH_PENDING) != 0) {
            RegisterNewRacer(statusKart, 1);
            if (IsRaceEndConditionMet() != 0) {
                switch (g_GlobalCO->mMode) {
                    case MODE_TIME_ATTACK:
                        break;
                    case MODE_BATTLE:
                        RaceModeBattle_OrMissionRun_SomeFn();
                        break;
                    case MODE_MISSION_RUN:
                        RaceModeMissionRun_SomeFn();
                        break;
                    case MODE_WIFI:
                        RaceModeNet_SomeFn();
                        break;
                    default:
                        RaceModeDefault_SomeFn();
                        break;
                }
            }
            statusKart->mFlags &= ~RACE_PROGRESS_KART_FLAG_FINISH_PENDING;
        }
        if ((statusKart->mFlags & RACE_PROGRESS_KART_FLAG_FINISH_JUST_HAPPENED) != 0) {
            statusKart->mFlags &= ~RACE_PROGRESS_KART_FLAG_FINISH_JUST_HAPPENED;
            if (g_GlobalCO->mMode != MODE_MISSION_RUN) {
                StructMQRacerEntry_SomeFn_21_ById(statusKart->mIndex);
                if ((statusKart->mFlags & RACE_PROGRESS_KART_FLAG_LOCAL_ENTRY) != 0) {
                    MaybePlayCrowdAmbientNoise(0);
                }
            }
        }
    }
}

void LoadCurrentCourseRanktime(RankTimeGp *rankTimeGp) {
    s32 entryIndex;
    RankTimeGpEntry *entry;

    g_GlobalMV->mHeader.mRankTime = 0;
    for (entryIndex = 0; entryIndex < rankTimeGp->mEntryCount; entryIndex++) {
        entry = &rankTimeGp->mEntries[entryIndex];
        if (entry->mCourseId == g_GlobalCO->mCourseId) {
            switch (g_GlobalCO->mEngineIndex) {
                case ENGINE_CLASS_SLOW:
                    g_GlobalMV->mHeader.mRankTime = entry->mRankTimeEngine0;
                    return;
                case ENGINE_CLASS_MEDIUM:
                    g_GlobalMV->mHeader.mRankTime = entry->mRankTimeEngine1;
                    return;
                case ENGINE_CLASS_FAST:
                    g_GlobalMV->mHeader.mRankTime = entry->mRankTimeEngine2;
                    break;
            }
            return;
        }
    }
}

void InitializeGlobalMV(void *heap) {
    g_GlobalMV = Mem_AllocateHeap(heap, sizeof(*g_GlobalMV));
    g_GlobalMV->mCheckpointLapProgress = Mem_AllocateHeap(heap, (g_GlobalPE->mNumberedCheckpointCount + 1) << 2);
    g_GlobalMV->mRankPointFile = FindFileBuffer_MAR_EFT_from_thumb("/rankpoint.rpt");
    g_GlobalMV->mRankTimeGpFile = FindFileBuffer_MAR_EFT_from_thumb("/ranktimeGP.rtt");
    LoadCurrentCourseRanktime(g_GlobalMV->mRankTimeGpFile);
    if (g_GlobalCO->mMode == MODE_MISSION_RUN) {
        SomethingMissionModeType5Areas(heap);
    }
    CreateGlobalMV();
}

void StopRaceInput(void) {
    u16 entryIndex;
    enum { INPUT_SLOT_INDEX_FIRST } inputSlotIndex;

    Struct5624_SetXflag2(0);
    if (RaceProgressKartIsBackupBusy() != 0) {
        WaitForWorkerTask();
        if (g_SaveDataIoManager->mBackupEnabled != 0) {
            j_WaitForPendingCardOperation();
        }
    }
    switch (g_GlobalCO->mMode) {
        case MODE_VS:
            ReplaceDisconnectedHumansWithCpu();
            break;
        case MODE_MISSION_RUN:
            ResetGlobalAR();
            break;
        case MODE_BATTLE:
            ReplaceDisconnectedHumansWithCpu();
            break;
    }
    for (entryIndex = 0; entryIndex < (u32) g_GlobalCO->mKartCount; entryIndex++) {
        inputSlotIndex = g_GlobalCO->mCurrentEntries[entryIndex].mPlayer.mIndex;
        FinishKeyRecording(&g_GlobalCYT[inputSlotIndex].mKeyRecording);
    }
}
