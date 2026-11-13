#include "Main/Scene/scene_connection.h"
#include "Main/System/heap.h"
#include "Main/Scene/display_settings.h"
#include "Main/Scene/run_scene_connection.h"
#include "Main/Net/connect_non_multiboot.h"
#include "Main/Scene/run_scenes.h"
#include "Main/Net/wifi_session.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Net/wifi_session_login.h"
#include "Main/Menu/select_race_rule_state.h"
#include "Main/Menu/message_screen.h"
#include "Main/Net/player_record.h"
#include "code_0200007e.h"
#include "Main/Sound/scene_sound_set.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/MapObjects/data_0217a000.h"
#include "00/Menu/wi_fi_states.h"
#include "00/code_02180608.h"
#include "00/Menu/wi_fi_vs_matching.h"
#include "01/Menu/ending_scene.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/code_02196d58.h"
#include "os_thread.h"
#include "pm.h"
#include "gx.h"
#include "Main/System/input_keys.h"
#include "registers.h"
#include "code_0200fe74.h"
#include "Main/System/startup.h"
#include "Main/Save/ghost_record_file.h"

#pragma opt_rebuildconditionals off

static inline u32 SceneGetConnectionMode(void) {
    if (gConnectionWork == NULL) {
        return 0;
    }
    return gConnectionWork->mConnectionMode;
}

static inline s32 SceneIsConnectionActive(void) {
    BOOL result = FALSE;
    if (SceneGetConnectionMode() != CONNECTION_MODE_NONE && gConnectionWork->mState != CONNECTION_STATE_ENDED) {
        result = TRUE;
    }
    return result;
}

static inline s32 SceneIsConnectionActiveNotEnding(void) {
    BOOL result = FALSE;
    if (SceneIsConnectionActive() && !(gConnectionWork->mFlags & CONNECTION_FLAG_ENDING)) {
        result = TRUE;
    }
    return result;
}

static inline s32 SceneIsSharingNotUpdatedWhileActive(void) {
    BOOL result = FALSE;
    if (SceneIsConnectionActiveNotEnding() && (gConnectionWork->mFlags & CONNECTION_FLAG_SHARING_NOT_UPDATED)) {
        result = TRUE;
    }
    return result;
}

static inline s32 SceneIsWiFiRaceSyncFlagSet(void) {
    BOOL result = FALSE;
    if (gWiFiRaceSync != NULL && (gWiFiRaceSync->mFlags & 0x10)) {
        result = TRUE;
    }
    return result;
}

static inline s32 SceneIsWiFiSessionHeapCreated(void) {
    BOOL result = FALSE;
    if (gWiFiSession != NULL && gWiFiSession->mHeapCreated != FALSE) {
        result = TRUE;
    }
    return result;
}

static inline s32 SceneIsBackupCommandRunning(void) {
    if (gBackupAccess->mBackupEnabled) {
        return gBackupAccess->mCommandRunning;
    }
    return 0;
}

static inline s32 SceneIsBackupBusy(void) {
    if (!gBackupBuffers->mBusy) {
        return SceneIsBackupCommandRunning();
    }
    return 1;
}

static inline s32 SceneIsConnectionActiveNotEndingWithError(void) {
    BOOL result = FALSE;
    if (SceneIsConnectionActiveNotEnding() && gConnectionWork->mErrorCode != CONNECTION_ERROR_NONE) {
        result = TRUE;
    }
    return result;
}

static inline void SceneOS_InitThreadQueue(OSThreadQueue *threadQueue) {
    threadQueue->mHead = threadQueue->mTail = NULL;
}

static inline void SceneSetSleepCallbackInfoNullArg(PMSleepCallbackInfo *callbackInfo, void (*callback)(void *)) {
    callbackInfo->mCallback = callback;
    callbackInfo->mArg = NULL;
}

static inline void StopSceneSoundSetSeqIfShouldEnd(SceneNumbers *sceneNumbers) {
    if (sceneNumbers == 0 || ShouldEndSceneSoundSet(sceneNumbers->mScene, sceneNumbers->mNextScene)) {
        StopSceneSoundSetSeq();
    }
}

s16 GetSceneFadeToClearFrameCount(void) {
    if (gSceneRunState->mRunStep == SCENE_RUN_STEP_IDLE) {
        return -1;
    }
    return gSceneRunState->mSceneCallbacks.mFadeToClearFrameCount;
}

u32 GetSceneFadeToFadedFrameCount(void) {
    if (gSceneRunState->mRunStep == SCENE_RUN_STEP_IDLE) {
        return -1;
    }
    return gSceneRunState->mSceneCallbacks.mFadeToFadedFrameCount;
}

void AdvanceWiFiSessionOnIrqWrapper(void) {
    AdvanceWiFiSessionOnIrq();
}

s32 TryGetSceneSoundSetSeqId(s32 sceneNumber, s32 *seqId) {
    BOOL result = FALSE;

    switch (sceneNumber) {
        case 11:
            *seqId = 4;
            result = TRUE;
            break;
        case 0:
            *seqId = 0;
            result = TRUE;
            break;
        case 7:
            *seqId = 4;
            result = TRUE;
            break;
        case 2:
            if (gRaceSetup->mRaceKind == RACE_KIND_STAFF_ROLL) {
                if (gRaceSetup->mCourseId != COURSE_ID_STAFFROLL) {
                    if (gRaceSetup->mCourseId == COURSE_ID_STAFFROLLTRUE) {
                        *seqId = 0x46;
                    }
                } else {
                    *seqId = 0x45;
                }
                result = TRUE;
            }
            break;
    }
    return result;
}

// On scenes 2 to 15 it also starts the stepped stop itself and returns FALSE when GetStaffRollEndedEarly is non-zero.
s32 ShouldEndSceneSoundSet(s32 scene, s32 nextScene) {
    BOOL result = TRUE;

    switch (scene) {
        case 0:
            if (nextScene == 2) {
                result = FALSE;
            }
            break;
        case 11:
            if (nextScene == 14) {
                result = FALSE;
            }
            break;
        case 14:
            if (nextScene == 3 || nextScene == 7) {
                result = FALSE;
            }
            break;
        case 7:
            if (nextScene == 3 || nextScene == 14) {
                result = FALSE;
            }
            break;
        case 3:
            if (nextScene == 7) {
                result = FALSE;
            }
            break;
        case 2:
            if (nextScene != 0) {
                if (nextScene == 15) {
                    if (GetStaffRollEndedEarly()) {
                        StopSceneSoundSetSeqWithSteps(0x78);
                    }
                    result = FALSE;
                }
            } else {
                result = FALSE;
            }
            break;
    }
    return result;
}

void RunMessageScreenThread(void *unused) {
    s32 status;
    BOOL sessionHeapCreated;
    BOOL hasDisplaySettings;

    while (1) {
        sessionHeapCreated = FALSE;
        hasDisplaySettings = FALSE;
        OS_SleepThread(&gSceneRunState->mThreadQueue);
        gSceneRunState->mNextScene = 0;
        ResetMessageScreen();
        if (gDisplaySettings != NULL) {
            hasDisplaySettings = TRUE;
        }
        ResetKeysInputSlot();
        ReadKeysIntoInputSlot();
        VBlankIntrWait();
        if (SceneIsWiFiSessionHeapCreated()) {
            sessionHeapCreated = TRUE;
        }
        OpenMessageScreen(gSceneRunState->mMessageKind, gSceneRunState->mMessageInputEnabled);
        StopAllSeqPlayers();
        if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
            BootInfoStartMessageScreenSeq();
        } else {
            StartMessageScreenSeq();
        }
        if (sessionHeapCreated != FALSE) {
            switch (gSceneRunState->mMessageKind) {
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                    ReleaseWiFiSession();
                    break;
            }
        }
        do {
            if (hasDisplaySettings != FALSE) {
                PrepareDisplayFrame();
            }
            status = sessionHeapCreated == FALSE ? AdvanceConnectionEndStopOnError() == 1 : 1;
            UpdateSounds();
            VBlankIntrWait();
            if (hasDisplaySettings != FALSE) {
                RecordFrameTimes();
            }
        } while (status == 0);
        do {
            if (hasDisplaySettings != FALSE) {
                PrepareDisplayFrame();
            }
            ReadKeysIntoInputSlot();
            status = UpdateMessageScreen();
            UpdateSounds();
            VBlankIntrWait();
            if (hasDisplaySettings != FALSE) {
                RecordFrameTimes();
            }
        } while (status == -1);
        switch (status) {
            case 1:
                gSceneRunState->mNextScene = 12;
                break;
            default:
                gSceneRunState->mNextScene = 0;
                break;
        }
    }
}

void RunMessageScreen(void) {
    s32 screenResult;
    BOOL sessionHeapCreated;
    BOOL hasDisplaySettings;
    BOOL noDisplaySettings;
    BOOL waitDone;
    s32 sleepAllowed;

    sessionHeapCreated = FALSE;
    hasDisplaySettings = FALSE;
    gSceneRunState->mNextScene = 0;
    ResetMessageScreen();
    if (gDisplaySettings != NULL) {
        hasDisplaySettings = TRUE;
    }
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        OpenMessageScreen(gSceneRunState->mMessageKind, gSceneRunState->mMessageInputEnabled);
    }
    ResetKeysInputSlot();
    ReadKeysIntoInputSlot();
    VBlankIntrWait();
    if (SceneIsWiFiSessionHeapCreated()) {
        sessionHeapCreated = TRUE;
    }
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        OpenMessageScreen(gSceneRunState->mMessageKind, gSceneRunState->mMessageInputEnabled);
    }
    StopAllSeqPlayers();
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        BootInfoStartMessageScreenSeq();
    } else {
        StartMessageScreenSeq();
    }
    PM_DeletePreSleepCallback(&gSceneRunState->mPreSleepCallback);
    PM_DeletePostSleepCallback(&gSceneRunState->mPostSleepCallback);
    PM_SetLCDPower(1);
    if (sessionHeapCreated != FALSE) {
        switch (gSceneRunState->mMessageKind) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                ReleaseWiFiSession();
                break;
        }
    }
    noDisplaySettings = hasDisplaySettings == FALSE;
    do {
        ReadKeysIntoInputSlot();
        if (noDisplaySettings == FALSE) {
            PrepareDisplayFrame();
        }
        if (sessionHeapCreated == FALSE) {
            waitDone = AdvanceConnectionEndStopOnError() == 1;
            sleepAllowed = waitDone;
        } else {
            waitDone = TRUE;
            sleepAllowed = gWiFiSession->mStateMachine.mState == 0;
        }
        if (sleepAllowed != 0 && ((SYSTEM_WORK->mButtonXY & 0x8000) >> 15)) {
            PM_GoSleepMode(12, 0, 0);
        }
        screenResult = UpdateMessageScreen();
        UpdateSounds();
        VBlankIntrWait();
        if (hasDisplaySettings != FALSE) {
            RecordFrameTimes();
        }
    } while (waitDone == FALSE || screenResult == -1);
    switch (screenResult) {
        case 1:
            gSceneRunState->mNextScene = 12;
            break;
        default:
            gSceneRunState->mNextScene = 0;
            break;
    }
}

void RunMessageScreenOfKind(s32 kind) {
    BOOL hasDisplaySettings;
    BOOL inputEnabled;

    inputEnabled = FALSE;
    hasDisplaySettings = gDisplaySettings != NULL;
    switch (kind) {
        case 0:
            if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
                inputEnabled = TRUE;
            }
            break;
        case 1:
        case 2:
            inputEnabled = FALSE;
            break;
        case 4:
        case 5:
        case 6:
            inputEnabled = TRUE;
            break;
        case 3:
            inputEnabled = FALSE;
            break;
    }
    gSceneRunState->mMessageKind = kind;
    gSceneRunState->mMessageInputEnabled = inputEnabled;
    RunMessageScreen();
    StopSceneSounds();
    if (gStartupWork->mSoundSetSeqPlaying) {
        StopSceneSoundSetSeqIfShouldEnd(0);
    }
    if (hasDisplaySettings != FALSE) {
        SetBrightnessFadesClear();
        StartFadeToFadedNegative(10);
        do {
            PrepareDisplayFrame();
            UpdateSounds();
            FinishDisplayFrame();
            RecordFrameTimes();
        } while (AreBrightnessFadesFaded() == 0);
    } else {
        GXx_SetMasterBrightness_(&reg_GX_MASTER_BRIGHT, 0x10);
    }
}

void ScenePreSleepCallback(void *arg) {
    BOOL connectionNotDone;
    s32 backupBusy;
    BOOL done;

    do {
        PrepareDisplayFrame();
        connectionNotDone = AdvanceConnectionEndStopOnError() != 1;
        backupBusy = SceneIsBackupBusy();
        if (connectionNotDone == FALSE && backupBusy == 0) {
            done = TRUE;
        } else {
            done = FALSE;
        }
        FinishDisplayFrame();
        RecordFrameTimes();
    } while (done == FALSE);
    if (gSceneRunState->mSceneCallbacks.mPreSleep != NULL) {
        gSceneRunState->mSceneCallbacks.mPreSleep();
    }
}

void ScenePostSleepCallback(void) {
    if (gSceneRunState->mSceneCallbacks.mPostSleep != NULL) {
        gSceneRunState->mSceneCallbacks.mPostSleep();
    }
}

void InitSceneRunState(void *heap) {
    gSceneRunState = HeapAlloc(heap, 0x124);
    gSceneRunState->mThreadStack = HeapAllocAligned(heap, 0x400, 0x20);
    gSceneRunState->mRunStep = SCENE_RUN_STEP_IDLE;
    gSceneRunState->mLcdOff = FALSE;
    gSceneRunState->mMessageKind = -1;
    gSceneRunState->mMessageInputEnabled = 0;
    SceneOS_InitThreadQueue(&gSceneRunState->mThreadQueue);
    OS_CreateThread(&gSceneRunState->mThread, RunMessageScreenThread, NULL, (u8 *) gSceneRunState->mThreadStack + 0x400,
                    0x400, 15);
    OS_WakeupThreadDirect(&gSceneRunState->mThread);
    SceneSetSleepCallbackInfoNullArg(&gSceneRunState->mPreSleepCallback, ScenePreSleepCallback);
    SceneSetSleepCallbackInfoNullArg(&gSceneRunState->mPostSleepCallback, (void (*)(void *)) ScenePostSleepCallback);
    PM_AppendPreSleepCallback(&gSceneRunState->mPreSleepCallback);
    PM_AppendPostSleepCallback(&gSceneRunState->mPostSleepCallback);
}

u32 IsDataSharingIncomplete(void) {
    u32 result = 0;

    if (gRaceSetup->mMode == MODE_WIFI && SceneIsWiFiRaceSyncFlagSet()) {
        result = 1;
    }
    if (SceneIsSharingNotUpdatedWhileActive()) {
        result = 1;
    }
    return result;
}

BOOL ShouldGoSleepMode(void) {
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT || SceneIsConnectionActive() ||
        (GetCurrentSceneNumber() == 12 && IsWiFiSessionOffOutsideLoginWrapper() == FALSE) ||
        (GetCurrentSceneNumber() != 12 && gWiFiSession->mStateMachine.mState != 0) || GetCurrentSceneNumber() == 13 ||
        GetCurrentSceneNumber() == 6) {
        return FALSE;
    }
    return TRUE;
}

u32 IsVolatileHalfwordIndex39Ignored(void) {
    s32 unused;

    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT || SceneIsConnectionActive() || GetCurrentSceneNumber() == 6 ||
        GetCurrentSceneNumber() == 13 || (GetCurrentSceneNumber() == 12 && IsWiFiSessionOffOutsideLogin() == FALSE) ||
        (GetCurrentSceneNumber() != 12 && gWiFiSession->mStateMachine.mState != 0)) {
        return 1;
    }
    switch (GetCurrentSceneNumber()) {
        case 9:
        case 15:
            return 1;
        case 2:
            if (gRaceSetup->mRaceKind == RACE_KIND_STAFF_ROLL) {
                return 1;
            }
            break;
    }
    return 0;
}

void RunMessageScreenOfKindWrapper(s32 kind) {
    RunMessageScreenOfKind(kind);
}

s32 RunMessageScreenOnDisconnect(SceneNumbers *sceneNumbers, s32 flag) {
    BOOL result;
    s32 value;

    result = FALSE;
    if (SceneIsWiFiSessionHeapCreated()) {
        value = CheckWiFiSessionDisconnect();
        if (flag != 0 && value != 0) {
            switch (value) {
                case 1:
                    value = 5;
                    break;
                case 2:
                    value = 6;
                    break;
                case 3:
                default:
                    value = 4;
                    break;
            }
            RunMessageScreenOfKind(value);
            result = TRUE;
        }
    } else if (flag != 0 && SceneIsConnectionActiveNotEndingWithError()) {
        RunMessageScreenOfKind(0);
        result = TRUE;
        gConnectionWork->mErrorCode = CONNECTION_ERROR_NONE;
    } else {
        AdvanceConnection();
    }
    return result;
}
