#include "Main/Scene/run_scene_connection.h"
#include "Main/System/heap.h"
#include "Main/Scene/display_settings.h"
#include "Main/Race/race_keys.h"
#include "Main/Race/race_setup_input.h"
#include "Main/System/result_archive_path.h"
#include "reset_interrupt_enable.h"
#include "vram_transfer_queue.h"
#include "Main/System/heap_call.h"
#include "00/Menu/wi_fi_vs_matching.h"
#include "heap_expanded_allocator.h"
#include "Main/Scene/scene_run_step.h"
#include "Main/Scene/scene_connection.h"
#include "Main/Scene/scene_frames.h"
#include "Main/Sound/scene_sound_set.h"
#include "Main/System/frm_heap_reset.h"
#include "Main/Net/led_pattern.h"
#include "Main/Net/connection_sharing.h"
#include "Main/Net/connect_non_multiboot.h"
#include "Main/Scene/run_scenes.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Net/wifi_session.h"
#include "card_removal_handling.h"
#include "power_management_commands.h"
#include "Main/Menu/select_race_rule_state.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/System/backup_net_camera_work.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/System/startup.h"
#include "Main/Save/ghost_record_file.h"

#pragma opt_rebuildconditionals off

static inline u32 RunSceneGetConnectionMode(void) {
    if (gConnectionWork == NULL) {
        return 0;
    }
    return gConnectionWork->mConnectionMode;
}

static inline s32 RunSceneIsConnectionActive(void) {
    BOOL result = FALSE;
    if (RunSceneGetConnectionMode() != CONNECTION_MODE_NONE && gConnectionWork->mState != CONNECTION_STATE_ENDED) {
        result = TRUE;
    }
    return result;
}

static inline s32 RunSceneIsConnectionActiveNotEnding(void) {
    BOOL result = FALSE;
    if (RunSceneIsConnectionActive() && !(gConnectionWork->mFlags & CONNECTION_FLAG_ENDING)) {
        result = TRUE;
    }
    return result;
}

static inline s32 RunSceneIsSharingNotUpdatedWhileActive(void) {
    BOOL result = FALSE;
    if (RunSceneIsConnectionActiveNotEnding() && (gConnectionWork->mFlags & CONNECTION_FLAG_SHARING_NOT_UPDATED)) {
        result = TRUE;
    }
    return result;
}

static inline s32 RunSceneIsWiFiRaceSyncFlagSet(void) {
    BOOL result = FALSE;
    if (gWiFiRaceSync != NULL && (gWiFiRaceSync->mFlags & WIFI_RACE_SYNC_FLAG_DATA_SHARING_INCOMPLETE)) {
        result = TRUE;
    }
    return result;
}

static inline s32 RunSceneIsDataSharingIncomplete(void) {
    BOOL result = FALSE;
    if (gRaceSetup->mMode == MODE_WIFI && RunSceneIsWiFiRaceSyncFlagSet()) {
        result = TRUE;
    }
    if (RunSceneIsSharingNotUpdatedWhileActive()) {
        result = TRUE;
    }
    return result;
}

static inline void RunSceneUpdateInputAndLcdPower(void) {
    u32 savedInterrupts;
    if (CARD_IsPulledOut()) {
        if (SceneRunPAD_DetectFold() == 1) {
            PM_ForceToPowerOff();
        }
        RunMessageScreenOfKind(MESSAGE_KIND_CARD_PULLED_OUT);
    }
    UpdatePadKeysAndTouchMic();
    if (!IsDataSharingIncomplete()) {
        UpdateInputSlots();
    }
    if (SceneRunPAD_DetectFold() == 1) {
        if (!ShouldGoSleepMode()) {
            if (PM_GetLCDPower() == 1) {
                savedInterrupts = OS_DisableInterrupts();
                gSceneRunState->mLcdOff = TRUE;
                PM_SetLCDPower(0);
                OS_RestoreInterrupts(savedInterrupts);
            }
        } else {
            PM_GoSleepMode(12, 0, 0);
        }
    } else {
        if (PM_GetLCDPower() == 0) {
            savedInterrupts = OS_DisableInterrupts();
            PM_SetLCDPower(1);
            if (AreBrightnessFadesClear()) {
                SetMainMasterBrightness(0);
                SetSubMasterBrightness(0);
            }
            gSceneRunState->mLcdOff = FALSE;
            OS_RestoreInterrupts(savedInterrupts);
        }
    }
}

static inline u32 RunSceneGetHalfwordIndex39OrZero(void) {
    if (IsVolatileHalfwordIndex39Ignored()) {
        return 0;
    }
    return GetVolatileHalfwordIndex39();
}

static inline BOOL RunSceneHasActiveConnection(void) {
    return RunSceneGetConnectionMode() != CONNECTION_MODE_NONE && gConnectionWork->mState != CONNECTION_STATE_ENDED;
}

static inline void RunSceneFinishDisplayFrame(const SceneCallbacks *sceneCallbacks) {
    int currentSceneNumber = GetCurrentSceneNumber();
    if (currentSceneNumber == 1 || currentSceneNumber == 10) {
        FinishDisplayFrameSwapIf(!RunSceneHasActiveConnection() || !RunSceneIsDataSharingIncomplete());
    } else {
        FinishDisplayFrameUnlessSpanned(sceneCallbacks->mSkipWhenSpanned);
    }
}

static inline s32 RunSceneIsBackupCommandRunning(void) {
    if (gBackupAccess->mBackupEnabled) {
        return gBackupAccess->mCommandRunning;
    }
    return 0;
}

static inline s32 RunSceneIsWiFiSessionHeapCreated(void) {
    BOOL result = FALSE;
    if (gWiFiSession != NULL && gWiFiSession->mHeapCreated != FALSE) {
        result = TRUE;
    }
    return result;
}

static inline BOOL RunSceneIsWiFiSessionStateZero(void) {
    if (RunSceneIsWiFiSessionHeapCreated()) {
        if (gWiFiSession->mStateMachine.mState != 0) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

static inline s32 RunSceneIsBackupBusy(void) {
    if (!gBackupBuffers->mBusy) {
        return RunSceneIsBackupCommandRunning();
    }
    return 1;
}

// Entries of the VRAM transfer task array that RunScene sets up.
#define SCENE_VRAM_TASK_COUNT 0x80

void RunScene(SceneNumbers *sceneNumbers, const SceneCallbacks *callbacks) {
    u32 exitValue;
    u32 interruptState;
    s32 seqId;
    s32 disconnectHandled;
    BOOL isDone;
    s32 messageKind;

    exitValue = 0;
    gSceneRunState->mSceneFrames = exitValue;
    gSceneRunState->mPassCount = exitValue;
    gSceneRunState->mSceneCallbacks = *callbacks;
    gSceneRunState->mRunStep = SCENE_RUN_STEP_IDLE;
    gSceneRunState->mNextScene = 0;
    gSceneRunState->mMessageKind = MESSAGE_KIND_NONE;
    gSceneRunState->mMessageInputEnabled = 0;
    interruptState = OS_DisableInterrupts();
    if (PM_GetLCDPower() == 1) {
        gSceneRunState->mLcdOff = FALSE;
    } else {
        gSceneRunState->mLcdOff = TRUE;
    }
    OS_RestoreInterrupts(interruptState);
    gSceneRunState->mRunStep = SCENE_RUN_STEP_LOADING;
    SetHeapGroupId(0);
    LoadArchiveSlotsForScene(sceneNumbers->mScene);
    SetHeapGroupId(9);
    GetHeap(GetCurrentHeapCall());
    NNS_GfdInitVramTransferManager(
        HeapAlloc(GetHeap(GetCurrentHeapCall()), SCENE_VRAM_TASK_COUNT * sizeof(NNSGfdVramTransferTask)),
        SCENE_VRAM_TASK_COUNT);
    if (TryGetSceneSoundSetSeqId(sceneNumbers->mScene, &seqId)) {
        InitSceneSoundSetPlayer(seqId);
    }
    InitSceneSounds(0);
    ResetInputSlotsFromParticipants();
    if (RunSceneIsConnectionActive()) {
        gConnectionWork->mFlags |= CONNECTION_FLAG_SCENE_RUNNING;
    }
    LoadFontAndPlayerCharacterData();
    StartInputSlots();
    CARD_SetPulledOutCallback(ReturnNoTerminateForPulledOut);
    gStartupWork->mUnk_78 = 0;
    if (callbacks->mInit != NULL) {
        callbacks->mInit(sceneNumbers);
    }
    ClearArchiveBuffersMap2DLoadFlag();
    gDisplaySettings->mIrqCallback = AdvanceWiFiSessionOnIrqWrapper;
    StartSceneSoundSetSeq();
    StartSceneSounds();
    WaitIrqAndTurnOnDisplays();
    gSceneRunState->mRunStep = SCENE_RUN_STEP_SYNC_WAIT;
    do {
        PrepareDisplayFrame();
        RunSceneUpdateInputAndLcdPower();
        UpdateSounds();
        RunSceneGetHalfwordIndex39OrZero();
        RunSceneFinishDisplayFrame(callbacks);
        disconnectHandled =
            RunMessageScreenOnDisconnect(sceneNumbers, gSceneRunState->mRunStep != SCENE_RUN_STEP_CARD_PULLED_OUT);
        NNS_GfdDoVramTransfer();
        if (disconnectHandled) {
            sceneNumbers->mNextScene = gSceneRunState->mNextScene;
            goto end;
        }
        UpdateWiFiSession();
        gSceneRunState->mPassCount++;
        RecordFrameTimes();
    } while (FinishDataSharingSync() != 1);
    ClearInputSlots();
    StartFadeToClear(callbacks->mFadeToClearFrameCount);
    gSceneRunState->mRunStep = SCENE_RUN_STEP_RUNNING;
    do {
        PrepareDisplayFrame();
        RunSceneUpdateInputAndLcdPower();
        if (callbacks->mUpdate != NULL) {
            callbacks->mUpdate(sceneNumbers, gSceneRunState->mSceneFrames);
        }
        UpdateSounds();
        exitValue = RunSceneGetHalfwordIndex39OrZero();
        RunSceneFinishDisplayFrame(callbacks);
        disconnectHandled =
            RunMessageScreenOnDisconnect(sceneNumbers, gSceneRunState->mRunStep != SCENE_RUN_STEP_CARD_PULLED_OUT);
        NNS_GfdDoVramTransfer();
        if (disconnectHandled) {
            sceneNumbers->mNextScene = gSceneRunState->mNextScene;
            goto end;
        }
        if (callbacks->mPostUpdate != NULL) {
            callbacks->mPostUpdate(sceneNumbers, gSceneRunState->mSceneFrames);
        }
        UpdateWiFiSession();
        if (!RunSceneIsDataSharingIncomplete()) {
            gSceneRunState->mSceneFrames++;
        }
        gSceneRunState->mPassCount++;
        RecordFrameTimes();
    } while (sceneNumbers->mNextScene == -1 && exitValue == 0);
    gSceneRunState->mRunStep = SCENE_RUN_STEP_FADE_OUT;
    StopSceneSounds();
    if (gStartupWork->mSoundSetSeqPlaying) {
        if (sceneNumbers == NULL || ShouldEndSceneSoundSet(sceneNumbers->mScene, sceneNumbers->mNextScene)) {
            StopSceneSoundSetSeq();
        }
    }
    if ((exitValue != 0 || GetNextSceneNumber() == 0) && gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        RunMessageScreenOfKind(0);
    }
    if (gStartupWork->mConnectionKind == CONNECTION_KIND_WIFI_TOP_MENU) {
        StartFadeToFadedPositive(callbacks->mFadeToFadedFrameCount);
    } else {
        StartFadeToFadedNegative(callbacks->mFadeToFadedFrameCount);
    }
    do {
        PrepareDisplayFrame();
        RunSceneUpdateInputAndLcdPower();
        if (callbacks->mUpdate != NULL) {
            callbacks->mUpdate(0, gSceneRunState->mSceneFrames);
        }
        UpdateSounds();
        RunSceneGetHalfwordIndex39OrZero();
        RunSceneFinishDisplayFrame(callbacks);
        RunMessageScreenOnDisconnect(sceneNumbers, gSceneRunState->mRunStep != SCENE_RUN_STEP_CARD_PULLED_OUT);
        NNS_GfdDoVramTransfer();
        if (callbacks->mPostUpdate != NULL) {
            callbacks->mPostUpdate(0, gSceneRunState->mSceneFrames);
        }
        UpdateWiFiSession();
        if (!RunSceneIsDataSharingIncomplete()) {
            gSceneRunState->mSceneFrames++;
        }
        gSceneRunState->mPassCount++;
        RecordFrameTimes();
    } while (!AreBrightnessFadesFaded());
end:
    SetNoKeysAndUpdateInputSlots();
    if (RunSceneIsWiFiSessionStateZero() && (exitValue != 0 || GetNextSceneNumber() == 0)) {
        gSceneRunState->mRunStep = SCENE_RUN_STEP_CARD_PULLED_OUT;
        gStartupWork->mConnectionKind = CONNECTION_KIND_NONE;
        isDone = FALSE;
        SendLedPatternNone();
        do {
            PrepareDisplayFrame();
            UpdateSounds();
            RunSceneGetHalfwordIndex39OrZero();
            RunSceneFinishDisplayFrame(callbacks);
            if (AdvanceConnectionEndStopOnError() == 1) {
                if (!RunSceneIsBackupBusy()) {
                    isDone = TRUE;
                }
            }
            RunMessageScreenOnDisconnect(sceneNumbers, gSceneRunState->mRunStep != SCENE_RUN_STEP_CARD_PULLED_OUT);
            NNS_GfdDoVramTransfer();
            UpdateWiFiSession();
            RecordFrameTimes();
        } while (!isDone);
    }
    gSceneRunState->mRunStep = SCENE_RUN_STEP_RELEASE;
    gDisplaySettings->mIrqCallback = NULL;
    if (RunSceneIsConnectionActive()) {
        gConnectionWork->mFlags &= ~CONNECTION_FLAG_SCENE_RUNNING;
    }
    StartDataSharingSync();
    AdvanceConnection();
    if (callbacks->mRelease != NULL) {
        callbacks->mRelease(sceneNumbers);
    }
    CARD_SetPulledOutCallback(SceneReturnTerminateForPulledOut);
    if (gDisplaySettings != NULL) {
        DisableAllBanksAndNullDisplaySettings();
    }
    StopTouchAutoSamplingWrapper();
    ClearFontAndPlayerCharacterTables();
    ClearLcdcBankAndStartWvrAndWait();
    StopSceneSoundsAtOnce();
    if (gStartupWork->mSoundSetPlayerInitialized &&
        ShouldEndSceneSoundSet(sceneNumbers->mScene, sceneNumbers->mNextScene)) {
        ReleaseSceneSoundSetPlayer();
    }
    ReleaseArchiveSlots();
    if (exitValue != 0) {
        sceneNumbers->mNextScene = 0;
    } else {
        messageKind = gSceneRunState->mMessageKind;
        if (messageKind != -1) {
            switch (messageKind) {
                case MESSAGE_KIND_WIFI_ERROR:
                case MESSAGE_KIND_WIFI_NO_INPUT:
                case MESSAGE_KIND_WIFI_OPPONENT_LEFT:
                    sceneNumbers->mNextScene = gSceneRunState->mNextScene;
                    break;
                default:
                    sceneNumbers->mNextScene = 0;
                    break;
            }
        }
    }
    ResetFrmHeap();
    gSceneRunState->mSceneFrames = 0;
    gSceneRunState->mRunStep = SCENE_RUN_STEP_IDLE;
}
