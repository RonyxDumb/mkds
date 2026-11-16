#include "Main/Unknown/code_0204984c.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_020487fc.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02037000.h"
#include "Main/Unknown/code_02039000.h"
#include "Main/Unknown/code_02054f58.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/code_02120610.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_0211f6cc.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_02108c1c.h"
#include "Main/Unknown/code_0212b0b8.h"
#include "Main/Unknown/code_0212a910.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/code_021200a8.h"
#include "Main/Unknown/code_02000000.h"
#include "Main/Unknown/code_0204aa60.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "00/code_02180600.h"
#include "00/code_02180608.h"
#include "00/code_021832d8.h"
#include "01/code_0219e0a8.h"
#include "01/code_021956dc.h"
#include "os_thread.h"
#include "pm.h"
#include "gx.h"
#include "Main/Unknown/code_02039230.h"
#include "registers.h"

#pragma opt_rebuildconditionals off

static inline u32 func_0204984c_inline(void) {
    if (gStruct217AA00 == NULL) {
        return 0;
    }
    return gStruct217AA00->field0;
}

static inline s32 func_0204984c_inline2(void) {
    BOOL result = FALSE;
    if (func_0204984c_inline() != 0 && gStruct217AA00->field4 != 13) {
        result = TRUE;
    }
    return result;
}

static inline s32 func_0204984c_inline3(void) {
    BOOL result = FALSE;
    if (func_0204984c_inline2() && !(gStruct217AA00->field454 & 0x80)) {
        result = TRUE;
    }
    return result;
}

static inline s32 func_0204984c_inline4(void) {
    BOOL result = FALSE;
    if (func_0204984c_inline3() && (gStruct217AA00->field454 & 0x10)) {
        result = TRUE;
    }
    return result;
}

static inline s32 func_0204984c_inline5(void) {
    BOOL result = FALSE;
    if (gStruct217AA14 != NULL && (gStruct217AA14->field75C & 0x10)) {
        result = TRUE;
    }
    return result;
}

static inline s32 func_0204984c_inline6(void) {
    BOOL result = FALSE;
    if (gStruct217D384 != NULL && gStruct217D384->mHeapCreated != FALSE) {
        result = TRUE;
    }
    return result;
}

static inline s32 func_0204984c_inline7(void) {
    if (gSaveCore->mBackupEnabled) {
        return gSaveCore->mCommandRunning;
    }
    return 0;
}

static inline s32 func_0204984c_inline8(void) {
    if (!gSaveData->mBusy) {
        return func_0204984c_inline7();
    }
    return 1;
}

static inline s32 func_0204984c_inline9(void) {
    BOOL result = FALSE;
    if (func_0204984c_inline3() && gStruct217AA00->field8 != 9) {
        result = TRUE;
    }
    return result;
}

static inline void func_02049c3c_inline(OSThreadQueue *threadQueue) {
    threadQueue->mHead = threadQueue->mTail = NULL;
}

static inline void func_02049c3c_inline2(PMSleepCallbackInfo *callbackInfo, void (*callback)(void *)) {
    callbackInfo->mCallback = callback;
    callbackInfo->mArg = NULL;
}

static inline void func_02049e38_inline(SceneNumbers *sceneNumbers) {
    if (sceneNumbers == 0 || scene_getShouldStopUnloadMusic(sceneNumbers->mScene, sceneNumbers->mNextScene)) {
        sysdat_stopSeq();
    }
}

s16 scene_getFadeInLength(void) {
    if (scene_sSceneState->field10C == 6) {
        return -1;
    }
    return scene_sSceneState->mSceneCallbacks.mFadeToClearFrameCount;
}

u32 scene_getFadeOutLength(void) {
    if (scene_sSceneState->field10C == 6) {
        return -1;
    }
    return scene_sSceneState->mSceneCallbacks.mFadeToFadedFrameCount;
}

void func_0204a4d8(void) {
    func_02120150();
}

s32 scene_getSceneMusicOverride(s32 sceneNumber, s32 *b) {
    BOOL result = FALSE;

    switch (sceneNumber) {
        case 11:
            *b = 4;
            result = TRUE;
            break;
        case 0:
            *b = 0;
            result = TRUE;
            break;
        case 7:
            *b = 4;
            result = TRUE;
            break;
        case 2:
            if (gRaceMultiConfig->mRaceKind == RACE_KIND_STAFF_ROLL) {
                if (gRaceMultiConfig->mCourseId != COURSE_ID_STAFFROLL) {
                    if (gRaceMultiConfig->mCourseId == COURSE_ID_STAFFROLLTRUE) {
                        *b = 0x46;
                    }
                } else {
                    *b = 0x45;
                }
                result = TRUE;
            }
            break;
    }
    return result;
}

s32 scene_getShouldStopUnloadMusic(s32 scene, s32 nextScene) {
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
                    if (func_ov001_0219e0b8()) {
                        sysdat_204AB64(0x78);
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

void scene_threadMain(void *arg) {
    s32 d;
    BOOL sessionHeapCreated;
    BOOL hasDisplaySettings;

    while (1) {
        sessionHeapCreated = FALSE;
        hasDisplaySettings = FALSE;
        OS_SleepThread(&scene_sSceneState->mThreadQueue);
        scene_sSceneState->mNextScene = 0;
        ResetMessageScreen();
        if (gCurDisplayConfig != NULL) {
            hasDisplaySettings = TRUE;
        }
        func_02039478();
        ReadKeysIntoInputSlot();
        VBlankIntrWait();
        if (func_0204984c_inline6()) {
            sessionHeapCreated = TRUE;
        }
        OpenMessageScreen(scene_sSceneState->field118, scene_sSceneState->field11C);
        sound_stopSeqAll();
        if (((Unk027ffc40 *) 0x027ffc40)->field0 == 2) {
            func_02108d00();
        } else {
            func_02108c80();
        }
        if (sessionHeapCreated != FALSE) {
            switch (scene_sSceneState->field118) {
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                    func_0211fd28();
                    break;
            }
        }
        do {
            if (hasDisplaySettings != FALSE) {
                dc_handleStartOfFrame();
            }
            d = sessionHeapCreated == FALSE ? func_02054f58() == 1 : 1;
            sound_main();
            VBlankIntrWait();
            if (hasDisplaySettings != FALSE) {
                dc_handleEndOfFrame();
            }
        } while (d == 0);
        do {
            if (hasDisplaySettings != FALSE) {
                dc_handleStartOfFrame();
            }
            ReadKeysIntoInputSlot();
            d = err_212B0B8();
            sound_main();
            VBlankIntrWait();
            if (hasDisplaySettings != FALSE) {
                dc_handleEndOfFrame();
            }
        } while (d == -1);
        switch (d) {
            case 1:
                scene_sSceneState->mNextScene = 12;
                break;
            default:
                scene_sSceneState->mNextScene = 0;
                break;
        }
    }
}

void scene_displayError(void) {
    s32 g;
    BOOL sessionHeapCreated;
    BOOL hasDisplaySettings;
    BOOL noDisplaySettings;
    BOOL e;
    s32 f;

    sessionHeapCreated = FALSE;
    hasDisplaySettings = FALSE;
    scene_sSceneState->mNextScene = 0;
    ResetMessageScreen();
    if (gCurDisplayConfig != NULL) {
        hasDisplaySettings = TRUE;
    }
    if (((Unk027ffc40 *) 0x027ffc40)->field0 == 2) {
        OpenMessageScreen(scene_sSceneState->field118, scene_sSceneState->field11C);
    }
    func_02039478();
    ReadKeysIntoInputSlot();
    VBlankIntrWait();
    if (func_0204984c_inline6()) {
        sessionHeapCreated = TRUE;
    }
    if (((Unk027ffc40 *) 0x027ffc40)->field0 != 2) {
        OpenMessageScreen(scene_sSceneState->field118, scene_sSceneState->field11C);
    }
    sound_stopSeqAll();
    if (((Unk027ffc40 *) 0x027ffc40)->field0 == 2) {
        func_02108d00();
    } else {
        func_02108c80();
    }
    PM_DeletePreSleepCallback(&scene_sSceneState->mPreSleepCallback);
    PM_DeletePostSleepCallback(&scene_sSceneState->mPostSleepCallback);
    PM_SetLCDPower(1);
    if (sessionHeapCreated != FALSE) {
        switch (scene_sSceneState->field118) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                func_0211fd28();
                break;
        }
    }
    noDisplaySettings = hasDisplaySettings == FALSE;
    do {
        ReadKeysIntoInputSlot();
        if (noDisplaySettings == FALSE) {
            dc_handleStartOfFrame();
        }
        if (sessionHeapCreated == FALSE) {
            e = func_02054f58() == 1;
            f = e;
        } else {
            e = TRUE;
            f = gStruct217D384->field8.mState == 0;
        }
        if (f != 0 && ((*(vu16 *) 0x027fffa8 & 0x8000) >> 15)) {
            PM_GoSleepMode(12, 0, 0);
        }
        g = err_212B0B8();
        sound_main();
        VBlankIntrWait();
        if (hasDisplaySettings != FALSE) {
            dc_handleEndOfFrame();
        }
    } while (e == FALSE || g == -1);
    switch (g) {
        case 1:
            scene_sSceneState->mNextScene = 12;
            break;
        default:
            scene_sSceneState->mNextScene = 0;
            break;
    }
}

void scene_reportErrorIntern(s32 kind) {
    BOOL hasDisplaySettings;
    BOOL c;

    c = FALSE;
    hasDisplaySettings = gCurDisplayConfig != NULL;
    switch (kind) {
        case 0:
            if (((Unk027ffc40 *) 0x027ffc40)->field0 != 2) {
                c = TRUE;
            }
            break;
        case 1:
        case 2:
            c = FALSE;
            break;
        case 4:
        case 5:
        case 6:
            c = TRUE;
            break;
        case 3:
            c = FALSE;
            break;
    }
    scene_sSceneState->field118 = kind;
    scene_sSceneState->field11C = c;
    scene_displayError();
    StopSceneSounds();
    if (gSystemData->mSoundSetSeqPlaying) {
        func_02049e38_inline(0);
    }
    if (hasDisplaySettings != FALSE) {
        SetBrightnessFadesClear();
        mbright_fadeToBlack(10);
        do {
            dc_handleStartOfFrame();
            sound_main();
            dc_2037850();
            dc_handleEndOfFrame();
        } while (mbright_isFadedOut() == 0);
    } else {
        GXx_SetMasterBrightness_(&reg_GX_MASTER_BRIGHT, 0x10);
    }
}

void scene_preSleepCallback(void *arg) {
    BOOL b;
    s32 c;
    BOOL done;

    do {
        dc_handleStartOfFrame();
        b = func_02054f58() != 1;
        c = func_0204984c_inline8();
        if (b == FALSE && c == 0) {
            done = TRUE;
        } else {
            done = FALSE;
        }
        dc_2037850();
        dc_handleEndOfFrame();
    } while (done == FALSE);
    if (scene_sSceneState->mSceneCallbacks.mPreSleep != NULL) {
        scene_sSceneState->mSceneCallbacks.mPreSleep();
    }
}

void scene_postSleepCallback(void) {
    if (scene_sSceneState->mSceneCallbacks.mPostSleep != NULL) {
        scene_sSceneState->mSceneCallbacks.mPostSleep();
    }
}

void scene_init(void *heap) {
    scene_sSceneState = heap_alloc(heap, 0x124);
    scene_sSceneState->mThreadStack = heap_allocEx(heap, 0x400, 0x20);
    scene_sSceneState->field10C = 6;
    scene_sSceneState->mLcdOff = FALSE;
    scene_sSceneState->field118 = -1;
    scene_sSceneState->field11C = 0;
    func_02049c3c_inline(&scene_sSceneState->mThreadQueue);
    OS_CreateThread(&scene_sSceneState->mThread, (void (*)(void *)) scene_threadMain, NULL,
                    (u8 *) scene_sSceneState->mThreadStack + 0x400, 0x400, 15);
    OS_WakeupThreadDirect(&scene_sSceneState->mThread);
    func_02049c3c_inline2(&scene_sSceneState->mPreSleepCallback, scene_preSleepCallback);
    func_02049c3c_inline2(&scene_sSceneState->mPostSleepCallback, (void (*)(void *)) scene_postSleepCallback);
    PM_AppendPreSleepCallback(&scene_sSceneState->mPreSleepCallback);
    PM_AppendPostSleepCallback(&scene_sSceneState->mPostSleepCallback);
}

u32 scene_areUpdatesSuspended(void) {
    u32 result = 0;

    if (gRaceMultiConfig->mMode == 5 && func_0204984c_inline5()) {
        result = 1;
    }
    if (func_0204984c_inline4()) {
        result = 1;
    }
    return result;
}

BOOL scene_isSleepAllowed(void) {
    if (((Unk027ffc40 *) 0x027ffc40)->field0 == 2 || func_0204984c_inline2() ||
        (scproc_getCurrentScene() == 12 && func_ov000_02180600() == FALSE) ||
        (scproc_getCurrentScene() != 12 && gStruct217D384->field8.mState != 0) || scproc_getCurrentScene() == 13 ||
        scproc_getCurrentScene() == 6) {
        return FALSE;
    }
    return TRUE;
}

u32 scene_isResetProhibited(void) {
    s32 v;

    if (((Unk027ffc40 *) 0x027ffc40)->field0 == 2 || func_0204984c_inline2() || scproc_getCurrentScene() == 6 ||
        scproc_getCurrentScene() == 13 || (scproc_getCurrentScene() == 12 && func_ov000_02180608() == FALSE) ||
        (scproc_getCurrentScene() != 12 && gStruct217D384->field8.mState != 0)) {
        return 1;
    }
    switch (scproc_getCurrentScene()) {
        case 9:
        case 15:
            return 1;
        case 2:
            if (gRaceMultiConfig->mRaceKind == RACE_KIND_STAFF_ROLL) {
                return 1;
            }
            break;
    }
    return 0;
}

void scene_reportError(s32 kind) {
    scene_reportErrorIntern(kind);
}

s32 func_0204984c(SceneNumbers *sceneNumbers, s32 b) {
    BOOL result;
    s32 v;

    result = FALSE;
    if (func_0204984c_inline6()) {
        v = func_02120644();
        if (b != 0 && v != 0) {
            switch (v) {
                case 1:
                    v = 5;
                    break;
                case 2:
                    v = 6;
                    break;
                case 3:
                default:
                    v = 4;
                    break;
            }
            scene_reportErrorIntern(v);
            result = TRUE;
        }
    } else if (b != 0 && func_0204984c_inline9()) {
        scene_reportErrorIntern(0);
        result = TRUE;
        gStruct217AA00->field8 = 9;
    } else {
        func_02055340();
    }
    return result;
}
