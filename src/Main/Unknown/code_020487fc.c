#include "Main/Unknown/code_020487fc.h"
#include "Main/System/Heap.h"
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

static inline u32 func_020487fc_inline(void) {
    if (gStruct217AA00 == NULL) {
        return 0;
    }
    return gStruct217AA00->field0;
}

static inline s32 func_020487fc_inline2(void) {
    BOOL r = FALSE;
    if (func_020487fc_inline() != 0 && gStruct217AA00->field4 != 13) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_020487fc_inline3(void) {
    BOOL r = FALSE;
    if (func_020487fc_inline2() && !(gStruct217AA00->field454 & 0x80)) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_020487fc_inline4(void) {
    BOOL r = FALSE;
    if (func_020487fc_inline3() && (gStruct217AA00->field454 & 0x10)) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_020487fc_inline5(void) {
    BOOL r = FALSE;
    if (gStruct217AA14 != NULL && (gStruct217AA14->field75C & 0x10)) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_020487fc_inline6(void) {
    BOOL r = FALSE;
    if (gRaceMultiConfig->mMode == 5 && func_020487fc_inline5()) {
        r = TRUE;
    }
    if (func_020487fc_inline4()) {
        r = TRUE;
    }
    return r;
}

static inline void func_020487fc_inline7(void) {
    u32 t;
    if (CARD_IsPulledOut()) {
        if (scene_PAD_DetectFold() == 1) {
            PM_ForceToPowerOff();
        }
        scene_reportErrorIntern(3);
    }
    input_sample();
    if (!scene_areUpdatesSuspended()) {
        input_update();
    }
    if (scene_PAD_DetectFold() == 1) {
        if (!scene_isSleepAllowed()) {
            if (PM_GetLCDPower() == 1) {
                t = OS_DisableInterrupts();
                scene_sSceneState->mLcdOff = TRUE;
                PM_SetLCDPower(0);
                OS_RestoreInterrupts(t);
            }
        } else {
            PM_GoSleepMode(12, 0, 0);
        }
    } else {
        if (PM_GetLCDPower() == 0) {
            t = OS_DisableInterrupts();
            PM_SetLCDPower(1);
            if (mbright_isFadedIn()) {
                scene_GX_SetMasterBrightness(0);
                scene_GXS_SetMasterBrightness(0);
            }
            scene_sSceneState->mLcdOff = FALSE;
            OS_RestoreInterrupts(t);
        }
    }
}

static inline u32 func_020487fc_inline8(void) {
    if (scene_isResetProhibited()) {
        return 0;
    }
    return input_getIsResetInvoked();
}

static inline BOOL func_020487fc_inline12(void) {
    return func_020487fc_inline() != 0 && gStruct217AA00->field4 != 13;
}

static inline void func_020487fc_inline9(const SceneCallbacks *b) {
    int v = scproc_getCurrentScene();
    if (v == 1 || v == 10) {
        dc_2037498(!func_020487fc_inline12() || !func_020487fc_inline6());
    } else {
        dc_2037658(b->field1C);
    }
}

static inline s32 func_020487fc_inline10(void) {
    if (gSaveCore->mBackupEnabled) {
        return gSaveCore->mCommandRunning;
    }
    return 0;
}

static inline s32 func_020487fc_inline11(void) {
    BOOL r = FALSE;
    if (gStruct217D384 != NULL && gStruct217D384->mHeapCreated != FALSE) {
        r = TRUE;
    }
    return r;
}

static inline BOOL func_020487fc_inline13(void) {
    if (func_020487fc_inline11()) {
        if (gStruct217D384->field8.mState != 0) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

static inline s32 func_020487fc_inline14(void) {
    if (!gSaveData->mBusy) {
        return func_020487fc_inline10();
    }
    return 1;
}

void scene_runScene(SceneNumbers *a, const SceneCallbacks *b) {
    u32 v;
    u32 t;
    s32 n;
    s32 r;
    BOOL c;
    s32 w;

    v = 0;
    scene_sSceneState->mSceneFrames = v;
    scene_sSceneState->mPassCount = v;
    scene_sSceneState->mSceneCallbacks = *b;
    scene_sSceneState->field10C = 6;
    scene_sSceneState->mNextScene = 0;
    scene_sSceneState->field118 = -1;
    scene_sSceneState->field11C = 0;
    t = OS_DisableInterrupts();
    if (PM_GetLCDPower() == 1) {
        scene_sSceneState->mLcdOff = FALSE;
    } else {
        scene_sSceneState->mLcdOff = TRUE;
    }
    OS_RestoreInterrupts(t);
    scene_sSceneState->field10C = 0;
    arc_setHeapGroupId(0);
    arc_loadArchivesForScene(a->mScene);
    arc_setHeapGroupId(9);
    proc_getHeap(proc_getCurrent());
    NNS_GfdInitVramTransferManager(heap_alloc(proc_getHeap(proc_getCurrent()), 0x800), 0x80);
    if (scene_getSceneMusicOverride(a->mScene, &n)) {
        sysdat_loadSeq(n);
    }
    InitSceneSounds(0);
    input_2043410();
    if (func_020487fc_inline2()) {
        gStruct217AA00->field454 |= 4;
    }
    m2d_load();
    input_2043B48();
    CARD_SetPulledOutCallback(scene_cardPulledOutCallbackDontStop);
    gSystemData->field78 = 0;
    if (b->mInit != NULL) {
        b->mInit(a);
    }
    arc_2047274();
    gCurDisplayConfig->mIrqCallback = func_0204a4d8;
    sysdat_startSeq();
    snd_handleRaceStart();
    dc_enableDisplay();
    scene_sSceneState->field10C = 1;
    do {
        dc_handleStartOfFrame();
        func_020487fc_inline7();
        sound_main();
        func_020487fc_inline8();
        func_020487fc_inline9(b);
        r = func_0204984c(a, scene_sSceneState->field10C != 4);
        NNS_GfdDoVramTransfer();
        if (r) {
            a->mNextScene = scene_sSceneState->mNextScene;
            goto end;
        }
        UpdateWiFiSession();
        scene_sSceneState->mPassCount++;
        dc_handleEndOfFrame();
    } while (FinishDataSharingSync() != 1);
    input_clearPads();
    mbright_fadeIn(b->mFadeToClearFrameCount);
    scene_sSceneState->field10C = 2;
    do {
        dc_handleStartOfFrame();
        func_020487fc_inline7();
        if (b->mUpdate != NULL) {
            b->mUpdate(a, scene_sSceneState->mSceneFrames);
        }
        sound_main();
        v = func_020487fc_inline8();
        func_020487fc_inline9(b);
        r = func_0204984c(a, scene_sSceneState->field10C != 4);
        NNS_GfdDoVramTransfer();
        if (r) {
            a->mNextScene = scene_sSceneState->mNextScene;
            goto end;
        }
        if (b->fieldC != NULL) {
            b->fieldC(a, scene_sSceneState->mSceneFrames);
        }
        UpdateWiFiSession();
        if (!func_020487fc_inline6()) {
            scene_sSceneState->mSceneFrames++;
        }
        scene_sSceneState->mPassCount++;
        dc_handleEndOfFrame();
    } while (a->mNextScene == -1 && v == 0);
    scene_sSceneState->field10C = 3;
    StopSceneSounds();
    if (gSystemData->mSoundSetSeqPlaying) {
        if (a == NULL || scene_getShouldStopUnloadMusic(a->mScene, a->mNextScene)) {
            sysdat_stopSeq();
        }
    }
    if ((v != 0 || scproc_getNextScene() == 0) && ((Unk027ffc40 *) 0x027ffc40)->field0 == 2) {
        scene_reportErrorIntern(0);
    }
    if (gSystemData->field20 == 4) {
        mbright_fadeToWhite(b->mFadeToFadedFrameCount);
    } else {
        mbright_fadeToBlack(b->mFadeToFadedFrameCount);
    }
    do {
        dc_handleStartOfFrame();
        func_020487fc_inline7();
        if (b->mUpdate != NULL) {
            b->mUpdate(0, scene_sSceneState->mSceneFrames);
        }
        sound_main();
        func_020487fc_inline8();
        func_020487fc_inline9(b);
        func_0204984c(a, scene_sSceneState->field10C != 4);
        NNS_GfdDoVramTransfer();
        if (b->fieldC != NULL) {
            b->fieldC(0, scene_sSceneState->mSceneFrames);
        }
        UpdateWiFiSession();
        if (!func_020487fc_inline6()) {
            scene_sSceneState->mSceneFrames++;
        }
        scene_sSceneState->mPassCount++;
        dc_handleEndOfFrame();
    } while (!mbright_isFadedOut());
end:
    input_2043AE0();
    if (func_020487fc_inline13() && (v != 0 || scproc_getNextScene() == 0)) {
        scene_sSceneState->field10C = 4;
        gSystemData->field20 = 0;
        c = FALSE;
        LEDBlink_NoPattern();
        do {
            dc_handleStartOfFrame();
            sound_main();
            func_020487fc_inline8();
            func_020487fc_inline9(b);
            if (func_02054f58() == 1) {
                if (!func_020487fc_inline14()) {
                    c = TRUE;
                }
            }
            func_0204984c(a, scene_sSceneState->field10C != 4);
            NNS_GfdDoVramTransfer();
            UpdateWiFiSession();
            dc_handleEndOfFrame();
        } while (!c);
    }
    scene_sSceneState->field10C = 5;
    gCurDisplayConfig->mIrqCallback = NULL;
    if (func_020487fc_inline2()) {
        gStruct217AA00->field454 &= ~4;
    }
    StartDataSharingSync();
    func_02055340();
    if (b->mRelease != NULL) {
        b->mRelease(a);
    }
    CARD_SetPulledOutCallback(scene_cardPulledOutCallbackDoStop);
    if (gCurDisplayConfig != NULL) {
        dc_unsetDisplayConfig();
    }
    input_stopTouchAutoSampling();
    m2d_unload();
    vram_startUpWifiVram();
    StopSceneSoundsAtOnce();
    if (gSystemData->mSoundSetPlayerInitialized && scene_getShouldStopUnloadMusic(a->mScene, a->mNextScene)) {
        sysdat_unloadSeq();
    }
    arc_unloadAllArchives();
    if (v != 0) {
        a->mNextScene = 0;
    } else {
        w = scene_sSceneState->field118;
        if (w != -1) {
            switch (w) {
                case 4:
                case 5:
                case 6:
                    a->mNextScene = scene_sSceneState->mNextScene;
                    break;
                default:
                    a->mNextScene = 0;
                    break;
            }
        }
    }
    sysdat_resetDtcmHeap();
    scene_sSceneState->mSceneFrames = 0;
    scene_sSceneState->field10C = 6;
}
