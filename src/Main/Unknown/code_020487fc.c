#include "Main/Unknown/code_020487fc.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_020431e4.h"
#include "Main/Unknown/code_020435c4.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_0200fc8c.h"
#include "code_02016468.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "00/code_021832d8.h"
#include "code_020176b0.h"
#include "Main/Unknown/code_020497f0.h"
#include "Main/Unknown/code_02049000.h"
#include "Main/Unknown/code_0204984c.h"
#include "Main/Unknown/code_0204a52c.h"
#include "Main/Unknown/code_0204aa60.h"
#include "Main/Unknown/code_0204ad24.h"
#include "Main/Unknown/code_0204f7f4.h"
#include "Main/Unknown/code_02053e74.h"
#include "Main/Unknown/code_02054f58.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_0212030c.h"
#include "code_02146af4.h"
#include "pm.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02037000.h"
#include "Main/Unknown/code_02039000.h"
#include "Main/Unknown/code_02043000.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/code_0204a000.h"
#include "Main/Unknown/code_02054000.h"
#include "Main/Unknown/code_02055000.h"
#include "Main/Unknown/code_020b4000.h"

#pragma opt_rebuildconditionals off

static inline u32 RunSceneGetConnectionMode(void) {
    if (gConnectionWork == NULL) {
        return 0;
    }
    return gConnectionWork->mConnectionMode;
}

static inline s32 RunSceneIsConnectionActive(void) {
    BOOL result = FALSE;
    if (RunSceneGetConnectionMode() != 0 && gConnectionWork->mState != 13) {
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
    if (gWiFiRaceSync != NULL && (gWiFiRaceSync->mFlags & 0x10)) {
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
        RunMessageScreenOfKind(3);
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
    return RunSceneGetConnectionMode() != 0 && gConnectionWork->mState != 13;
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
    if (!data_0217aa08->mBusy) {
        return RunSceneIsBackupCommandRunning();
    }
    return 1;
}

void RunScene(SceneNumbers *a, const SceneCallbacks *b) {
    u32 v;
    u32 t;
    s32 n;
    s32 r;
    BOOL c;
    s32 w;

    v = 0;
    gSceneRunState->mSceneFrames = v;
    gSceneRunState->mPassCount = v;
    gSceneRunState->mSceneCallbacks = *b;
    gSceneRunState->mRunStep = SCENE_RUN_STEP_IDLE;
    gSceneRunState->mNextScene = 0;
    gSceneRunState->mMessageKind = -1;
    gSceneRunState->mMessageInputEnabled = 0;
    t = OS_DisableInterrupts();
    if (PM_GetLCDPower() == 1) {
        gSceneRunState->mLcdOff = FALSE;
    } else {
        gSceneRunState->mLcdOff = TRUE;
    }
    OS_RestoreInterrupts(t);
    gSceneRunState->mRunStep = SCENE_RUN_STEP_LOADING;
    SetHeapGroupId(0);
    LoadArchiveSlotsForScene(a->mScene);
    SetHeapGroupId(9);
    GetHeap(GetCurrentHeapCall());
    NNS_GfdInitVramTransferManager(HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x800), 0x80);
    if (TryGetSceneSoundSetSeqId(a->mScene, &n)) {
        InitSceneSoundSetPlayer(n);
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
    if (b->mInit != NULL) {
        b->mInit(a);
    }
    ClearArchiveBuffersBit31();
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
        RunSceneFinishDisplayFrame(b);
        r = RunMessageScreenOnDisconnect(a, gSceneRunState->mRunStep != SCENE_RUN_STEP_CARD_PULLED_OUT);
        NNS_GfdDoVramTransfer();
        if (r) {
            a->mNextScene = gSceneRunState->mNextScene;
            goto end;
        }
        UpdateWiFiSession();
        gSceneRunState->mPassCount++;
        RecordFrameTimes();
    } while (FinishDataSharingSync() != 1);
    ClearInputSlots();
    StartFadeToClear(b->mFadeToClearFrameCount);
    gSceneRunState->mRunStep = SCENE_RUN_STEP_RUNNING;
    do {
        PrepareDisplayFrame();
        RunSceneUpdateInputAndLcdPower();
        if (b->mUpdate != NULL) {
            b->mUpdate(a, gSceneRunState->mSceneFrames);
        }
        UpdateSounds();
        v = RunSceneGetHalfwordIndex39OrZero();
        RunSceneFinishDisplayFrame(b);
        r = RunMessageScreenOnDisconnect(a, gSceneRunState->mRunStep != SCENE_RUN_STEP_CARD_PULLED_OUT);
        NNS_GfdDoVramTransfer();
        if (r) {
            a->mNextScene = gSceneRunState->mNextScene;
            goto end;
        }
        if (b->mPostUpdate != NULL) {
            b->mPostUpdate(a, gSceneRunState->mSceneFrames);
        }
        UpdateWiFiSession();
        if (!RunSceneIsDataSharingIncomplete()) {
            gSceneRunState->mSceneFrames++;
        }
        gSceneRunState->mPassCount++;
        RecordFrameTimes();
    } while (a->mNextScene == -1 && v == 0);
    gSceneRunState->mRunStep = SCENE_RUN_STEP_FADE_OUT;
    StopSceneSounds();
    if (gStartupWork->mSoundSetSeqPlaying) {
        if (a == NULL || ShouldEndSceneSoundSet(a->mScene, a->mNextScene)) {
            StopSceneSoundSetSeq();
        }
    }
    if ((v != 0 || GetNextSceneNumber() == 0) && gBootInfo->mUnk_00 == 2) {
        RunMessageScreenOfKind(0);
    }
    if (gStartupWork->mConnectionKind == 4) {
        StartFadeToFadedPositive(b->mFadeToFadedFrameCount);
    } else {
        StartFadeToFadedNegative(b->mFadeToFadedFrameCount);
    }
    do {
        PrepareDisplayFrame();
        RunSceneUpdateInputAndLcdPower();
        if (b->mUpdate != NULL) {
            b->mUpdate(0, gSceneRunState->mSceneFrames);
        }
        UpdateSounds();
        RunSceneGetHalfwordIndex39OrZero();
        RunSceneFinishDisplayFrame(b);
        RunMessageScreenOnDisconnect(a, gSceneRunState->mRunStep != SCENE_RUN_STEP_CARD_PULLED_OUT);
        NNS_GfdDoVramTransfer();
        if (b->mPostUpdate != NULL) {
            b->mPostUpdate(0, gSceneRunState->mSceneFrames);
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
    if (RunSceneIsWiFiSessionStateZero() && (v != 0 || GetNextSceneNumber() == 0)) {
        gSceneRunState->mRunStep = SCENE_RUN_STEP_CARD_PULLED_OUT;
        gStartupWork->mConnectionKind = 0;
        c = FALSE;
        SendLedPatternNone();
        do {
            PrepareDisplayFrame();
            UpdateSounds();
            RunSceneGetHalfwordIndex39OrZero();
            RunSceneFinishDisplayFrame(b);
            if (AdvanceConnectionEndStopOnError() == 1) {
                if (!RunSceneIsBackupBusy()) {
                    c = TRUE;
                }
            }
            RunMessageScreenOnDisconnect(a, gSceneRunState->mRunStep != SCENE_RUN_STEP_CARD_PULLED_OUT);
            NNS_GfdDoVramTransfer();
            UpdateWiFiSession();
            RecordFrameTimes();
        } while (!c);
    }
    gSceneRunState->mRunStep = SCENE_RUN_STEP_RELEASE;
    gDisplaySettings->mIrqCallback = NULL;
    if (RunSceneIsConnectionActive()) {
        gConnectionWork->mFlags &= ~CONNECTION_FLAG_SCENE_RUNNING;
    }
    StartDataSharingSync();
    AdvanceConnection();
    if (b->mRelease != NULL) {
        b->mRelease(a);
    }
    CARD_SetPulledOutCallback(SceneReturnTerminateForPulledOut);
    if (gDisplaySettings != NULL) {
        DisableAllBanksAndNullDisplaySettings();
    }
    StopTouchAutoSamplingWrapper();
    ClearFontAndPlayerCharacterTables();
    ClearLcdcBankAndStartWvrAndWait();
    StopSceneSoundsAtOnce();
    if (gStartupWork->mSoundSetPlayerInitialized && ShouldEndSceneSoundSet(a->mScene, a->mNextScene)) {
        ReleaseSceneSoundSetPlayer();
    }
    ReleaseArchiveSlots();
    if (v != 0) {
        a->mNextScene = 0;
    } else {
        w = gSceneRunState->mMessageKind;
        if (w != -1) {
            switch (w) {
                case 4:
                case 5:
                case 6:
                    a->mNextScene = gSceneRunState->mNextScene;
                    break;
                default:
                    a->mNextScene = 0;
                    break;
            }
        }
    }
    ResetFrmHeap();
    gSceneRunState->mSceneFrames = 0;
    gSceneRunState->mRunStep = SCENE_RUN_STEP_IDLE;
}
