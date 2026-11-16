#include "Main/Scene/scene_connection.h"
#include "Main/System/scene_numbers.h"
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
#include "bios_calls.h"
#include "Main/Sound/scene_sound_set.h"
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
    if (g_GlobalZE == NULL) {
        return 0;
    }
    return g_GlobalZE->mConnectionMode;
}

static inline s32 SceneIsConnectionActive(void) {
    BOOL result = FALSE;
    if (SceneGetConnectionMode() != CONNECTION_MODE_NONE && g_GlobalZE->mState != CONNECTION_STATE_ENDED) {
        result = TRUE;
    }
    return result;
}

static inline s32 SceneIsConnectionActiveNotEnding(void) {
    BOOL result = FALSE;
    if (SceneIsConnectionActive() && !(g_GlobalZE->mFlags & CONNECTION_FLAG_ENDING)) {
        result = TRUE;
    }
    return result;
}

static inline s32 SceneIsSharingNotUpdatedWhileActive(void) {
    BOOL result = FALSE;
    if (SceneIsConnectionActiveNotEnding() && (g_GlobalZE->mFlags & CONNECTION_FLAG_SHARING_NOT_UPDATED)) {
        result = TRUE;
    }
    return result;
}

static inline s32 SceneIsWiFiRaceSyncFlagSet(void) {
    BOOL result = FALSE;
    if (g_GlobalAA != NULL && (g_GlobalAA->mFlags & WIFI_RACE_SYNC_FLAG_DATA_SHARING_INCOMPLETE)) {
        result = TRUE;
    }
    return result;
}

static inline s32 SceneIsWiFiSessionHeapCreated(void) {
    BOOL result = FALSE;
    if (g_GlobalB != NULL && g_GlobalB->mHeapCreated != FALSE) {
        result = TRUE;
    }
    return result;
}

static inline s32 SceneIsBackupCommandRunning(void) {
    if (g_SaveDataIoManager->mBackupEnabled) {
        return g_SaveDataIoManager->mCommandRunning;
    }
    return 0;
}

static inline s32 SceneIsBackupBusy(void) {
    if (!g_SaveDataHolder->mBusy) {
        return SceneIsBackupCommandRunning();
    }
    return 1;
}

static inline s32 SceneIsConnectionActiveNotEndingWithError(void) {
    BOOL result = FALSE;
    if (SceneIsConnectionActiveNotEnding() && g_GlobalZE->mErrorCode != CONNECTION_ERROR_NONE) {
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
    if (sceneNumbers == 0 || ShouldPauseBgmInSceneChange(sceneNumbers->mScene, sceneNumbers->mNextScene)) {
        StopSceneSoundSetSeq();
    }
}

s16 GetSceneFadeToClearFrameCount(void) {
    if (g_GlobalZM->mRunStep == SCENE_RUN_STEP_IDLE) {
        return -1;
    }
    return g_GlobalZM->mSceneCallbacks.mFadeToClearFrameCount;
}

u32 GetSceneFadeToFadedFrameCount(void) {
    if (g_GlobalZM->mRunStep == SCENE_RUN_STEP_IDLE) {
        return -1;
    }
    return g_GlobalZM->mSceneCallbacks.mFadeToFadedFrameCount;
}

void DisplayConfig_VblankFn(void) {
    DisplayConfig_VblankFnImpl();
}

s32 TryGetSceneSpecialBgmSseqId(s32 sceneNumber, s32 *seqId) {
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
            if (g_GlobalCO->mRaceKind == RACE_KIND_STAFF_ROLL) {
                if (g_GlobalCO->mCourseId != COURSE_ID_STAFFROLL) {
                    if (g_GlobalCO->mCourseId == COURSE_ID_STAFFROLLTRUE) {
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
s32 ShouldPauseBgmInSceneChange(s32 scene, s32 nextScene) {
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

void ZM_ThreadEntry(void *unused) {
    s32 status;
    BOOL sessionHeapCreated;
    BOOL hasDisplaySettings;

    while (1) {
        sessionHeapCreated = FALSE;
        hasDisplaySettings = FALSE;
        Os_Thread_Sleep(&g_GlobalZM->mThreadQueue);
        g_GlobalZM->mNextScene = 0;
        ResetMultiplayErrors_from_thumb();
        if (g_GlobalDisplayConfig != NULL) {
            hasDisplaySettings = TRUE;
        }
        InitializeGlobalG_2();
        UpdateInput();
        Svc_VblankIntrWait_from_thumb();
        if (SceneIsWiFiSessionHeapCreated()) {
            sessionHeapCreated = TRUE;
        }
        DisplayMultiplayError_from_thumb(g_GlobalZM->mMessageKind, g_GlobalZM->mMessageInputEnabled);
        StopAllSeqPlayers();
        if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
            BootInfoStartMessageScreenSeq();
        } else {
            StartMessageScreenSeq();
        }
        if (sessionHeapCreated != FALSE) {
            switch (g_GlobalZM->mMessageKind) {
                case MESSAGE_KIND_BACKUP_ERROR_OTHER_STATUS:
                case MESSAGE_KIND_BACKUP_ERROR_WHILE_WRITING:
                case MESSAGE_KIND_CARD_PULLED_OUT:
                case MESSAGE_KIND_WIFI_ERROR:
                case MESSAGE_KIND_WIFI_NO_INPUT:
                    OnSomeMultiplayError();
                    break;
            }
        }
        do {
            if (hasDisplaySettings != FALSE) {
                LoopFn_Some3D();
            }
            status = sessionHeapCreated == FALSE ? AdvanceConnectionEndStopOnError() == 1 : 1;
            LoopFn_Sound();
            Svc_VblankIntrWait_from_thumb();
            if (hasDisplaySettings != FALSE) {
                LoopFn_DisplayConfig();
            }
        } while (status == 0);
        do {
            if (hasDisplaySettings != FALSE) {
                LoopFn_Some3D();
            }
            UpdateInput();
            status = UpdateMessageScreen();
            LoopFn_Sound();
            Svc_VblankIntrWait_from_thumb();
            if (hasDisplaySettings != FALSE) {
                LoopFn_DisplayConfig();
            }
        } while (status == -1);
        switch (status) {
            case 1:
                g_GlobalZM->mNextScene = SCENE_WIFI_MENU;
                break;
            default:
                g_GlobalZM->mNextScene = 0;
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
    g_GlobalZM->mNextScene = 0;
    ResetMultiplayErrors_from_thumb();
    if (g_GlobalDisplayConfig != NULL) {
        hasDisplaySettings = TRUE;
    }
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        DisplayMultiplayError_from_thumb(g_GlobalZM->mMessageKind, g_GlobalZM->mMessageInputEnabled);
    }
    InitializeGlobalG_2();
    UpdateInput();
    Svc_VblankIntrWait_from_thumb();
    if (SceneIsWiFiSessionHeapCreated()) {
        sessionHeapCreated = TRUE;
    }
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        DisplayMultiplayError_from_thumb(g_GlobalZM->mMessageKind, g_GlobalZM->mMessageInputEnabled);
    }
    StopAllSeqPlayers();
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        BootInfoStartMessageScreenSeq();
    } else {
        StartMessageScreenSeq();
    }
    PM_DeletePreSleepCallback(&g_GlobalZM->mPreSleepCallback);
    PM_DeletePostSleepCallback(&g_GlobalZM->mPostSleepCallback);
    PMi_SetLCDPower(1);
    if (sessionHeapCreated != FALSE) {
        switch (g_GlobalZM->mMessageKind) {
            case MESSAGE_KIND_BACKUP_ERROR_OTHER_STATUS:
            case MESSAGE_KIND_BACKUP_ERROR_WHILE_WRITING:
            case MESSAGE_KIND_CARD_PULLED_OUT:
            case MESSAGE_KIND_WIFI_ERROR:
            case MESSAGE_KIND_WIFI_NO_INPUT:
                OnSomeMultiplayError();
                break;
        }
    }
    noDisplaySettings = hasDisplaySettings == FALSE;
    do {
        UpdateInput();
        if (noDisplaySettings == FALSE) {
            LoopFn_Some3D();
        }
        if (sessionHeapCreated == FALSE) {
            waitDone = AdvanceConnectionEndStopOnError() == 1;
            sleepAllowed = waitDone;
        } else {
            waitDone = TRUE;
            sleepAllowed = g_GlobalB->mStateMachine.mState == WIFI_SESSION_STATE_OFF;
        }
        if (sleepAllowed != 0 && ((SYSTEM_WORK->mButtonXY & SYSTEM_BUTTON_XY_CLOSED) >> 15)) {
            PM_GoSleepMode(12, 0, 0);
        }
        screenResult = UpdateMessageScreen();
        LoopFn_Sound();
        Svc_VblankIntrWait_from_thumb();
        if (hasDisplaySettings != FALSE) {
            LoopFn_DisplayConfig();
        }
    } while (waitDone == FALSE || screenResult == -1);
    switch (screenResult) {
        case 1:
            g_GlobalZM->mNextScene = SCENE_WIFI_MENU;
            break;
        default:
            g_GlobalZM->mNextScene = 0;
            break;
    }
}

void NotifyError(s32 kind) {
    BOOL hasDisplaySettings;
    BOOL inputEnabled;

    inputEnabled = FALSE;
    hasDisplaySettings = g_GlobalDisplayConfig != NULL;
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
    g_GlobalZM->mMessageKind = kind;
    g_GlobalZM->mMessageInputEnabled = inputEnabled;
    RunMessageScreen();
    StopSceneSounds();
    if (g_GlobalP->mSoundSetSeqPlaying) {
        StopSceneSoundSetSeqIfShouldEnd(0);
    }
    if (hasDisplaySettings != FALSE) {
        Bright_ResetBlackBothScreens();
        Bright_FadeOutBlack(10);
        do {
            LoopFn_Some3D();
            LoopFn_Sound();
            LoopFn_Brightness();
            LoopFn_DisplayConfig();
        } while (Bright_IsBothScreensFadedOut() == 0);
    } else {
        SetBrightness(&reg_GX_MASTER_BRIGHT, 0x10);
    }
}

void ZM_SomeFn(void *arg) {
    BOOL connectionNotDone;
    s32 backupBusy;
    BOOL done;

    do {
        LoopFn_Some3D();
        connectionNotDone = AdvanceConnectionEndStopOnError() != 1;
        backupBusy = SceneIsBackupBusy();
        if (connectionNotDone == FALSE && backupBusy == 0) {
            done = TRUE;
        } else {
            done = FALSE;
        }
        LoopFn_Brightness();
        LoopFn_DisplayConfig();
    } while (done == FALSE);
    if (g_GlobalZM->mSceneCallbacks.mPreSleep != NULL) {
        g_GlobalZM->mSceneCallbacks.mPreSleep();
    }
}

void ZM_SomeFn2(void) {
    if (g_GlobalZM->mSceneCallbacks.mPostSleep != NULL) {
        g_GlobalZM->mSceneCallbacks.mPostSleep();
    }
}

void InitializeGlobalZM(void *heap) {
    g_GlobalZM = Mem_AllocateHeap(heap, sizeof(SceneRunState));
    g_GlobalZM->mThreadStack = Mem_AllocateHeapAligned(heap, 0x400, HEAP_ALIGN_CACHE_LINE);
    g_GlobalZM->mRunStep = SCENE_RUN_STEP_IDLE;
    g_GlobalZM->mLcdOff = FALSE;
    g_GlobalZM->mMessageKind = MESSAGE_KIND_NONE;
    g_GlobalZM->mMessageInputEnabled = 0;
    SceneOS_InitThreadQueue(&g_GlobalZM->mThreadQueue);
    Os_Thread_Create(&g_GlobalZM->mThread, ZM_ThreadEntry, NULL, g_GlobalZM->mThreadStack + 0x400,
                    0x400, 15);
    Os_Thread_WakeUpDirect(&g_GlobalZM->mThread);
    SceneSetSleepCallbackInfoNullArg(&g_GlobalZM->mPreSleepCallback, ZM_SomeFn);
    SceneSetSleepCallbackInfoNullArg(&g_GlobalZM->mPostSleepCallback, (void (*)(void *)) ZM_SomeFn2);
    PM_AppendPreSleepCallback(&g_GlobalZM->mPreSleepCallback);
    PM_AppendPostSleepCallback(&g_GlobalZM->mPostSleepCallback);
}

u32 IsDataSharingIncomplete(void) {
    u32 result = 0;

    if (g_GlobalCO->mMode == MODE_WIFI && SceneIsWiFiRaceSyncFlagSet()) {
        result = 1;
    }
    if (SceneIsSharingNotUpdatedWhileActive()) {
        result = 1;
    }
    return result;
}

BOOL ShouldGoSleepMode(void) {
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT || SceneIsConnectionActive() ||
        (GetCurrentSceneId() == 12 && IsWiFiSessionOffOutsideLoginWrapper() == FALSE) ||
        (GetCurrentSceneId() != 12 && g_GlobalB->mStateMachine.mState != WIFI_SESSION_STATE_OFF) ||
        GetCurrentSceneId() == 13 || GetCurrentSceneId() == 6) {
        return FALSE;
    }
    return TRUE;
}

u32 MaybeIfExpectsReturnToTitleScene(void) {
    s32 unused;

    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT || SceneIsConnectionActive() ||
        GetCurrentSceneId() == SCENE_WL_MENU || GetCurrentSceneId() == SCENE_GHOST ||
        (GetCurrentSceneId() == SCENE_WIFI_MENU && IsWiFiSessionOffOutsideLogin() == FALSE) ||
        (GetCurrentSceneId() != SCENE_WIFI_MENU && g_GlobalB->mStateMachine.mState != WIFI_SESSION_STATE_OFF)) {
        return 1;
    }
    switch (GetCurrentSceneId()) {
        case SCENE_LOGO:
        case SCENE_ENDING:
            return 1;
        case SCENE_RACE:
            if (g_GlobalCO->mRaceKind == RACE_KIND_STAFF_ROLL) {
                return 1;
            }
            break;
    }
    return 0;
}

void j_NotifyError(s32 kind) {
    NotifyError(kind);
}

s32 RunMessageScreenOnDisconnect(SceneNumbers *sceneNumbers, s32 flag) {
    BOOL result;
    s32 value;

    result = FALSE;
    if (SceneIsWiFiSessionHeapCreated()) {
        value = CheckWiFiSessionDisconnect();
        if (flag != 0 && value != WIFI_DISCONNECT_NONE) {
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
            NotifyError(value);
            result = TRUE;
        }
    } else if (flag != 0 && SceneIsConnectionActiveNotEndingWithError()) {
        NotifyError(MESSAGE_KIND_CONNECTION_ERROR);
        result = TRUE;
        g_GlobalZE->mErrorCode = CONNECTION_ERROR_NONE;
    } else {
        AdvanceConnection();
    }
    return result;
}
