#include "Main/Scene/scene_connection.h"
#include "Main/System/scene_numbers.h"
#include "Main/System/heap.h"
#include "Main/Scene/display_settings.h"
#include "Main/Scene/run_scene_connection.h"
#include "Main/Net/connect_non_multiboot.h"
#include "Main/Scene/run_scenes.h"
#include "Main/Net/wifi_session.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "Main/Net/wifi_session_login.h"
#include "Main/Menu/select_race_rule_state.h"
#include "Main/Menu/message_screen.h"
#include "Main/Net/player_record.h"
#include "bios_calls.h"
#include "Main/Sound/startup_sound_set_player_back_lights_and_random.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/System/backup_net_camera_work.h"
#include "00/Menu/wi_fi_states.h"
#include "00/Menu/wi_fi_state_machine.h"
#include "00/Menu/wi_fi_vs_matching.h"
#include "01/Menu/ending_scene.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"
#include "thread_scheduler.h"
#include "power_management_commands.h"
#include "fixed_point_graphics_setup.h"
#include "Main/System/input_keys.h"
#include "registers.h"
#include "model_texture_bind.h"
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
    if (gWiFiRaceSync != NULL && (gWiFiRaceSync->mFlags & WIFI_RACE_SYNC_FLAG_DATA_SHARING_INCOMPLETE)) {
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
        case SCENE_NICKNAME:
            *seqId = 4;
            result = TRUE;
            break;
        case SCENE_TITLE:
            *seqId = 0;
            result = TRUE;
            break;
        case SCENE_OPTION:
            *seqId = 4;
            result = TRUE;
            break;
        case SCENE_RACE:
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

// Returns FALSE when the scene sound set sequence keeps playing into the next scene: title to race, nickname to
// keyboard, keyboard to emblem or option, option to emblem or keyboard, emblem to option, race to title or ending.
// Going from the race to the ending also starts the stepped stop itself when GetStaffRollEndedEarly is non-zero.
s32 ShouldEndSceneSoundSet(s32 scene, s32 nextScene) {
    BOOL result = TRUE;

    switch (scene) {
        case SCENE_TITLE:
            if (nextScene == SCENE_RACE) {
                result = FALSE;
            }
            break;
        case SCENE_NICKNAME:
            if (nextScene == SCENE_KEYBOARD) {
                result = FALSE;
            }
            break;
        case SCENE_KEYBOARD:
            if (nextScene == SCENE_EMBLEM || nextScene == SCENE_OPTION) {
                result = FALSE;
            }
            break;
        case SCENE_OPTION:
            if (nextScene == SCENE_EMBLEM || nextScene == SCENE_KEYBOARD) {
                result = FALSE;
            }
            break;
        case SCENE_EMBLEM:
            if (nextScene == SCENE_OPTION) {
                result = FALSE;
            }
            break;
        case SCENE_RACE:
            if (nextScene != SCENE_TITLE) {
                if (nextScene == SCENE_ENDING) {
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
        gSceneRunState->mNextScene = SCENE_TITLE;
        ResetMessageScreen();
        if (gDisplaySettings != NULL) {
            hasDisplaySettings = TRUE;
        }
        ResetKeysInputSlot();
        ReadKeysIntoInputSlot();
        SVC_WaitVBlankIntr();
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
                case MESSAGE_KIND_BACKUP_ERROR_OTHER_STATUS:
                case MESSAGE_KIND_BACKUP_ERROR_WHILE_WRITING:
                case MESSAGE_KIND_CARD_PULLED_OUT:
                case MESSAGE_KIND_WIFI_ERROR:
                case MESSAGE_KIND_WIFI_NO_INPUT:
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
            SVC_WaitVBlankIntr();
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
            SVC_WaitVBlankIntr();
            if (hasDisplaySettings != FALSE) {
                RecordFrameTimes();
            }
        } while (status == -1);
        switch (status) {
            case 1:
                gSceneRunState->mNextScene = SCENE_WIFI_MENU;
                break;
            default:
                gSceneRunState->mNextScene = SCENE_TITLE;
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
    gSceneRunState->mNextScene = SCENE_TITLE;
    ResetMessageScreen();
    if (gDisplaySettings != NULL) {
        hasDisplaySettings = TRUE;
    }
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        OpenMessageScreen(gSceneRunState->mMessageKind, gSceneRunState->mMessageInputEnabled);
    }
    ResetKeysInputSlot();
    ReadKeysIntoInputSlot();
    SVC_WaitVBlankIntr();
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
            case MESSAGE_KIND_BACKUP_ERROR_OTHER_STATUS:
            case MESSAGE_KIND_BACKUP_ERROR_WHILE_WRITING:
            case MESSAGE_KIND_CARD_PULLED_OUT:
            case MESSAGE_KIND_WIFI_ERROR:
            case MESSAGE_KIND_WIFI_NO_INPUT:
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
            sleepAllowed = gWiFiSession->mStateMachine.mState == WIFI_SESSION_STATE_OFF;
        }
        if (sleepAllowed != 0 && ((SYSTEM_WORK->mButtonXY & SYSTEM_BUTTON_XY_CLOSED) >> 15)) {
            PM_GoSleepMode(12, 0, 0);
        }
        screenResult = UpdateMessageScreen();
        UpdateSounds();
        SVC_WaitVBlankIntr();
        if (hasDisplaySettings != FALSE) {
            RecordFrameTimes();
        }
    } while (waitDone == FALSE || screenResult == -1);
    switch (screenResult) {
        case 1:
            gSceneRunState->mNextScene = SCENE_WIFI_MENU;
            break;
        default:
            gSceneRunState->mNextScene = SCENE_TITLE;
            break;
    }
}

void RunMessageScreenOfKind(s32 kind) {
    BOOL hasDisplaySettings;
    BOOL inputEnabled;

    inputEnabled = FALSE;
    hasDisplaySettings = gDisplaySettings != NULL;
    switch (kind) {
        case MESSAGE_KIND_CONNECTION_ERROR:
            if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
                inputEnabled = TRUE;
            }
            break;
        case MESSAGE_KIND_BACKUP_ERROR_OTHER_STATUS:
        case MESSAGE_KIND_BACKUP_ERROR_WHILE_WRITING:
            inputEnabled = FALSE;
            break;
        case MESSAGE_KIND_WIFI_ERROR:
        case MESSAGE_KIND_WIFI_NO_INPUT:
        case MESSAGE_KIND_WIFI_OPPONENT_LEFT:
            inputEnabled = TRUE;
            break;
        case MESSAGE_KIND_CARD_PULLED_OUT:
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
        GXx_SetMasterBrightness_(&reg_GX_MASTER_BRIGHT, BRIGHTNESS_LEVEL_FADED);
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
    gSceneRunState = HeapAlloc(heap, sizeof(SceneRunState));
    gSceneRunState->mThreadStack = HeapAllocAligned(heap, 0x400, HEAP_ALIGN_CACHE_LINE);
    gSceneRunState->mRunStep = SCENE_RUN_STEP_IDLE;
    gSceneRunState->mLcdOff = FALSE;
    gSceneRunState->mMessageKind = MESSAGE_KIND_NONE;
    gSceneRunState->mMessageInputEnabled = 0;
    SceneOS_InitThreadQueue(&gSceneRunState->mThreadQueue);
    OS_CreateThread(&gSceneRunState->mThread, RunMessageScreenThread, NULL, gSceneRunState->mThreadStack + 0x400,
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
        (GetCurrentSceneNumber() == SCENE_WIFI_MENU && IsWiFiSessionOffOutsideLoginWrapper() == FALSE) ||
        (GetCurrentSceneNumber() != SCENE_WIFI_MENU && gWiFiSession->mStateMachine.mState != WIFI_SESSION_STATE_OFF) ||
        GetCurrentSceneNumber() == SCENE_GHOST || GetCurrentSceneNumber() == SCENE_WL_MENU) {
        return FALSE;
    }
    return TRUE;
}

u32 IsVolatileHalfwordIndex39Ignored(void) {
    s32 unused;

    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT || SceneIsConnectionActive() ||
        GetCurrentSceneNumber() == SCENE_WL_MENU || GetCurrentSceneNumber() == SCENE_GHOST ||
        (GetCurrentSceneNumber() == SCENE_WIFI_MENU && IsWiFiSessionOffOutsideLogin() == FALSE) ||
        (GetCurrentSceneNumber() != SCENE_WIFI_MENU && gWiFiSession->mStateMachine.mState != WIFI_SESSION_STATE_OFF)) {
        return 1;
    }
    switch (GetCurrentSceneNumber()) {
        case SCENE_LOGO:
        case SCENE_ENDING:
            return 1;
        case SCENE_RACE:
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

s32 RunMessageScreenOnDisconnect(SceneNumbers *sceneNumbers, s32 messageAllowed) {
    BOOL result;
    s32 value;

    result = FALSE;
    if (SceneIsWiFiSessionHeapCreated()) {
        value = CheckWiFiSessionDisconnect();
        if (messageAllowed != 0 && value != WIFI_DISCONNECT_NONE) {
            switch (value) {
                case WIFI_DISCONNECT_NO_INPUT:
                    value = MESSAGE_KIND_WIFI_NO_INPUT;
                    break;
                case WIFI_DISCONNECT_OPPONENT_LEFT:
                    value = MESSAGE_KIND_WIFI_OPPONENT_LEFT;
                    break;
                case WIFI_DISCONNECT_ERROR:
                default:
                    value = MESSAGE_KIND_WIFI_ERROR;
                    break;
            }
            RunMessageScreenOfKind(value);
            result = TRUE;
        }
    } else if (messageAllowed != 0 && SceneIsConnectionActiveNotEndingWithError()) {
        RunMessageScreenOfKind(MESSAGE_KIND_CONNECTION_ERROR);
        result = TRUE;
        gConnectionWork->mErrorCode = CONNECTION_ERROR_NONE;
    } else {
        AdvanceConnection();
    }
    return result;
}
