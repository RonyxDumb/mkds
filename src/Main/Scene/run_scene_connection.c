#include "Main/Scene/run_scene_connection.h"
#include "Main/System/heap.h"
#include "Main/Scene/display_settings.h"
#include "Main/Race/race_keys.h"
#include "Main/Race/race_setup_input.h"
#include "Main/System/result_archive_path.h"
#include "reset_interrupts_halt.h"
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
    if (g_GlobalZE == NULL) {
        return 0;
    }
    return g_GlobalZE->mConnectionMode;
}

static inline s32 RunSceneIsConnectionActive(void) {
    BOOL result = FALSE;
    if (RunSceneGetConnectionMode() != CONNECTION_MODE_NONE && g_GlobalZE->mState != CONNECTION_STATE_ENDED) {
        result = TRUE;
    }
    return result;
}

static inline s32 RunSceneIsConnectionActiveNotEnding(void) {
    BOOL result = FALSE;
    if (RunSceneIsConnectionActive() && !(g_GlobalZE->mFlags & CONNECTION_FLAG_ENDING)) {
        result = TRUE;
    }
    return result;
}

static inline s32 RunSceneIsSharingNotUpdatedWhileActive(void) {
    BOOL result = FALSE;
    if (RunSceneIsConnectionActiveNotEnding() && (g_GlobalZE->mFlags & CONNECTION_FLAG_SHARING_NOT_UPDATED)) {
        result = TRUE;
    }
    return result;
}

static inline s32 RunSceneIsWiFiRaceSyncFlagSet(void) {
    BOOL result = FALSE;
    if (g_GlobalAA != NULL && (g_GlobalAA->mFlags & WIFI_RACE_SYNC_FLAG_DATA_SHARING_INCOMPLETE)) {
        result = TRUE;
    }
    return result;
}

static inline s32 RunSceneIsDataSharingIncomplete(void) {
    BOOL result = FALSE;
    if (g_GlobalCO->mMode == MODE_WIFI && RunSceneIsWiFiRaceSyncFlagSet()) {
        result = TRUE;
    }
    if (RunSceneIsSharingNotUpdatedWhileActive()) {
        result = TRUE;
    }
    return result;
}

static inline void RunSceneUpdateInputAndLcdPower(void) {
    u32 savedInterrupts;
    if (Card_IsPulledOut()) {
        if (Pad_DetectFolding() == 1) {
            PM_ForceToPowerOff();
        }
        NotifyError(MESSAGE_KIND_CARD_PULLED_OUT);
    }
    UpdatePadKeysAndTouchMic();
    if (!IsDataSharingIncomplete()) {
        UpdateInputSlots();
    }
    if (Pad_DetectFolding() == 1) {
        if (!ShouldGoSleepMode()) {
            if (PM_GetLCDPower() == 1) {
                savedInterrupts = Os_DisableIrq();
                g_GlobalZM->mLcdOff = TRUE;
                PMi_SetLCDPower(0);
                Os_RestoreIrq(savedInterrupts);
            }
        } else {
            PM_GoSleepMode(12, 0, 0);
        }
    } else {
        if (PM_GetLCDPower() == 0) {
            savedInterrupts = Os_DisableIrq();
            PMi_SetLCDPower(1);
            if (Bright_IsBothScreensFadedIn()) {
                SetTopBrightness(0);
                SetBottomBrightness(0);
            }
            g_GlobalZM->mLcdOff = FALSE;
            Os_RestoreIrq(savedInterrupts);
        }
    }
}

static inline u32 RunSceneGetHalfwordIndex39OrZero(void) {
    if (MaybeIfExpectsReturnToTitleScene()) {
        return 0;
    }
    return GetVolatileHalfwordIndex39();
}

static inline BOOL RunSceneHasActiveConnection(void) {
    return RunSceneGetConnectionMode() != CONNECTION_MODE_NONE && g_GlobalZE->mState != CONNECTION_STATE_ENDED;
}

static inline void RunSceneFinishDisplayFrame(const SceneCallbacks *sceneCallbacks) {
    int currentSceneNumber = GetCurrentSceneId();
    if (currentSceneNumber == 1 || currentSceneNumber == 10) {
        UpdateBrightnessContextsAndMore(!RunSceneHasActiveConnection() || !RunSceneIsDataSharingIncomplete());
    } else {
        FinishDisplayFrameUnlessSpanned(sceneCallbacks->mSkipWhenSpanned);
    }
}

static inline s32 RunSceneIsBackupCommandRunning(void) {
    if (g_SaveDataIoManager->mBackupEnabled) {
        return g_SaveDataIoManager->mCommandRunning;
    }
    return 0;
}

static inline s32 RunSceneIsWiFiSessionHeapCreated(void) {
    BOOL result = FALSE;
    if (g_GlobalB != NULL && g_GlobalB->mHeapCreated != FALSE) {
        result = TRUE;
    }
    return result;
}

static inline BOOL RunSceneIsWiFiSessionStateZero(void) {
    if (RunSceneIsWiFiSessionHeapCreated()) {
        if (g_GlobalB->mStateMachine.mState != 0) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

static inline s32 RunSceneIsBackupBusy(void) {
    if (!g_SaveDataHolder->mBusy) {
        return RunSceneIsBackupCommandRunning();
    }
    return 1;
}

// Entries of the VRAM transfer task array that OnSceneLoop sets up.
#define SCENE_VRAM_TASK_COUNT 0x80

void OnSceneLoop(SceneNumbers *sceneNumbers, const SceneCallbacks *callbacks) {
    u32 exitValue;
    u32 interruptState;
    s32 seqId;
    s32 disconnectHandled;
    BOOL isDone;
    s32 messageKind;

    exitValue = 0;
    g_GlobalZM->mSceneFrames = exitValue;
    g_GlobalZM->mPassCount = exitValue;
    g_GlobalZM->mSceneCallbacks = *callbacks;
    g_GlobalZM->mRunStep = SCENE_RUN_STEP_IDLE;
    g_GlobalZM->mNextScene = 0;
    g_GlobalZM->mMessageKind = MESSAGE_KIND_NONE;
    g_GlobalZM->mMessageInputEnabled = 0;
    interruptState = Os_DisableIrq();
    if (PM_GetLCDPower() == 1) {
        g_GlobalZM->mLcdOff = FALSE;
    } else {
        g_GlobalZM->mLcdOff = TRUE;
    }
    Os_RestoreIrq(interruptState);
    g_GlobalZM->mRunStep = SCENE_RUN_STEP_LOADING;
    SetActiveExecutionContextHeapGroupId_from_thumb(0);
    MountArchivesForScene_from_thumb(sceneNumbers->mScene);
    SetActiveExecutionContextHeapGroupId_from_thumb(9);
    ExecutionContext_GetHeapHandle(GetActiveExecutionContext());
    InitializeGlobalTEQ(
        Mem_AllocateHeap(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), SCENE_VRAM_TASK_COUNT * sizeof(NNSGfdVramTransferTask)),
        SCENE_VRAM_TASK_COUNT);
    if (TryGetSceneSpecialBgmSseqId(sceneNumbers->mScene, &seqId)) {
        SetSomeSceneSseqId(seqId);
    }
    MaybeChangeAudioForMenu(0);
    ResetInputSlotsFromParticipants();
    if (RunSceneIsConnectionActive()) {
        g_GlobalZE->mFlags |= CONNECTION_FLAG_SCENE_RUNNING;
    }
    LoadMA2ContentIfMounted_from_thumb();
    StartInputSlots();
    Card_SetUserCardPulledOutCallback(AnotherUserCardPulledOutCallback);
    g_GlobalP->mUnk_78 = 0;
    if (callbacks->mInit != NULL) {
        callbacks->mInit(sceneNumbers);
    }
    SomeMaskMountDataFlags_from_thumb();
    g_GlobalDisplayConfig->mIrqCallback = DisplayConfig_VblankFn;
    StartSceneSoundSetSeq();
    PlayBgEffectsAndMore();
    EnableGreenSwap();
    g_GlobalZM->mRunStep = SCENE_RUN_STEP_SYNC_WAIT;
    do {
        LoopFn_Some3D();
        RunSceneUpdateInputAndLcdPower();
        LoopFn_Sound();
        RunSceneGetHalfwordIndex39OrZero();
        RunSceneFinishDisplayFrame(callbacks);
        disconnectHandled =
            RunMessageScreenOnDisconnect(sceneNumbers, g_GlobalZM->mRunStep != SCENE_RUN_STEP_CARD_PULLED_OUT);
        HandleAllGlobalTEQSubs();
        if (disconnectHandled) {
            sceneNumbers->mNextScene = g_GlobalZM->mNextScene;
            goto end;
        }
        UpdateWiFiSession();
        g_GlobalZM->mPassCount++;
        LoopFn_DisplayConfig();
    } while (FinishDataSharingSync() != 1);
    ClearInputSlots();
    BrightCtx_SomeFnTopBottom(callbacks->mFadeToClearFrameCount);
    g_GlobalZM->mRunStep = SCENE_RUN_STEP_RUNNING;
    do {
        LoopFn_Some3D();
        RunSceneUpdateInputAndLcdPower();
        if (callbacks->mUpdate != NULL) {
            callbacks->mUpdate(sceneNumbers, g_GlobalZM->mSceneFrames);
        }
        LoopFn_Sound();
        exitValue = RunSceneGetHalfwordIndex39OrZero();
        RunSceneFinishDisplayFrame(callbacks);
        disconnectHandled =
            RunMessageScreenOnDisconnect(sceneNumbers, g_GlobalZM->mRunStep != SCENE_RUN_STEP_CARD_PULLED_OUT);
        HandleAllGlobalTEQSubs();
        if (disconnectHandled) {
            sceneNumbers->mNextScene = g_GlobalZM->mNextScene;
            goto end;
        }
        if (callbacks->mPostUpdate != NULL) {
            callbacks->mPostUpdate(sceneNumbers, g_GlobalZM->mSceneFrames);
        }
        UpdateWiFiSession();
        if (!RunSceneIsDataSharingIncomplete()) {
            g_GlobalZM->mSceneFrames++;
        }
        g_GlobalZM->mPassCount++;
        LoopFn_DisplayConfig();
    } while (sceneNumbers->mNextScene == -1 && exitValue == 0);
    g_GlobalZM->mRunStep = SCENE_RUN_STEP_FADE_OUT;
    StopSceneSounds();
    if (g_GlobalP->mSoundSetSeqPlaying) {
        if (sceneNumbers == NULL || ShouldPauseBgmInSceneChange(sceneNumbers->mScene, sceneNumbers->mNextScene)) {
            StopSceneSoundSetSeq();
        }
    }
    if ((exitValue != 0 || GetNextSceneId() == 0) && gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        NotifyError(0);
    }
    if (g_GlobalP->mConnectionKind == CONNECTION_KIND_WIFI_TOP_MENU) {
        Bright_FadeOutWhite(callbacks->mFadeToFadedFrameCount);
    } else {
        Bright_FadeOutBlack(callbacks->mFadeToFadedFrameCount);
    }
    do {
        LoopFn_Some3D();
        RunSceneUpdateInputAndLcdPower();
        if (callbacks->mUpdate != NULL) {
            callbacks->mUpdate(0, g_GlobalZM->mSceneFrames);
        }
        LoopFn_Sound();
        RunSceneGetHalfwordIndex39OrZero();
        RunSceneFinishDisplayFrame(callbacks);
        RunMessageScreenOnDisconnect(sceneNumbers, g_GlobalZM->mRunStep != SCENE_RUN_STEP_CARD_PULLED_OUT);
        HandleAllGlobalTEQSubs();
        if (callbacks->mPostUpdate != NULL) {
            callbacks->mPostUpdate(0, g_GlobalZM->mSceneFrames);
        }
        UpdateWiFiSession();
        if (!RunSceneIsDataSharingIncomplete()) {
            g_GlobalZM->mSceneFrames++;
        }
        g_GlobalZM->mPassCount++;
        LoopFn_DisplayConfig();
    } while (!Bright_IsBothScreensFadedOut());
end:
    SetNoKeysAndUpdateInputSlots();
    if (RunSceneIsWiFiSessionStateZero() && (exitValue != 0 || GetNextSceneId() == 0)) {
        g_GlobalZM->mRunStep = SCENE_RUN_STEP_CARD_PULLED_OUT;
        g_GlobalP->mConnectionKind = CONNECTION_KIND_NONE;
        isDone = FALSE;
        SendLedPatternNone();
        do {
            LoopFn_Some3D();
            LoopFn_Sound();
            RunSceneGetHalfwordIndex39OrZero();
            RunSceneFinishDisplayFrame(callbacks);
            if (AdvanceConnectionEndStopOnError() == 1) {
                if (!RunSceneIsBackupBusy()) {
                    isDone = TRUE;
                }
            }
            RunMessageScreenOnDisconnect(sceneNumbers, g_GlobalZM->mRunStep != SCENE_RUN_STEP_CARD_PULLED_OUT);
            HandleAllGlobalTEQSubs();
            UpdateWiFiSession();
            LoopFn_DisplayConfig();
        } while (!isDone);
    }
    g_GlobalZM->mRunStep = SCENE_RUN_STEP_RELEASE;
    g_GlobalDisplayConfig->mIrqCallback = NULL;
    if (RunSceneIsConnectionActive()) {
        g_GlobalZE->mFlags &= ~CONNECTION_FLAG_SCENE_RUNNING;
    }
    StartDataSharingSync();
    AdvanceConnection();
    if (callbacks->mRelease != NULL) {
        callbacks->mRelease(sceneNumbers);
    }
    Card_SetUserCardPulledOutCallback(SomeUserCardPulledOutCallback);
    if (g_GlobalDisplayConfig != NULL) {
        ResetDisplayConfig();
    }
    StopTouchAutoSamplingWrapper();
    CleanupPlayerGfxDataFontsEtc_from_thumb();
    SomeVramConfig();
    StopSceneSoundsAtOnce();
    if (g_GlobalP->mSoundSetPlayerInitialized &&
        ShouldPauseBgmInSceneChange(sceneNumbers->mScene, sceneNumbers->mNextScene)) {
        ReleaseSceneSoundSetPlayer();
    }
    Arc_DisposeAllArchives_from_thumb();
    if (exitValue != 0) {
        sceneNumbers->mNextScene = 0;
    } else {
        messageKind = g_GlobalZM->mMessageKind;
        if (messageKind != -1) {
            switch (messageKind) {
                case MESSAGE_KIND_WIFI_ERROR:
                case MESSAGE_KIND_WIFI_NO_INPUT:
                case MESSAGE_KIND_WIFI_OPPONENT_LEFT:
                    sceneNumbers->mNextScene = g_GlobalZM->mNextScene;
                    break;
                default:
                    sceneNumbers->mNextScene = 0;
                    break;
            }
        }
    }
    ResetDTCMFrameHeap();
    g_GlobalZM->mSceneFrames = 0;
    g_GlobalZM->mRunStep = SCENE_RUN_STEP_IDLE;
}
