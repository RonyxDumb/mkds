#include "Main/Unknown/code_02039e08.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_02039774.h"
#include "Main/Unknown/code_0203be88.h"
#include "Main/Unknown/code_020487fc.h"
#include "Main/Unknown/code_0204984c.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_02037000.h"
#include "Main/Unknown/code_02045874.h"
#include "Main/Unknown/code_0203a3a4.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0204673c.h"
#include "Main/Unknown/code_020435c4.h"
#include "Main/Unknown/code_02046c10.h"
#include "Main/Unknown/code_02049000.h"
#include "Main/Unknown/code_020431e4.h"
#include "Main/Unknown/code_0205b0f4.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020ae824.h"
#include "Main/Unknown/code_020aeb7c.h"
#include "Main/Unknown/code_020af66c.h"
#include "Main/Ui/ChoisesS.h"
#include "Main/Unknown/code_020b255c.h"
#include "Main/Unknown/code_020cb4c0.h"
#include "Main/Unknown/code_020cb9b8.h"
#include "Main/Unknown/code_020cbad0.h"
#include "Main/Unknown/code_020cc168.h"
#include "Main/Unknown/code_0210f72c.h"
#include "Main/Unknown/code_0210f744.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "01/code_0219e0a8.h"
#include "code_020176c0.h"
#include "Main/Unknown/code_02044618.h"

void racesc_update(Unk0203a0dc *sceneNumbers, u32 sceneFrames) {
    RaceSetup *raceSetup;
    u32 c;
    if (scene_areUpdatesSuspended() == 0) {
        if (input_getFlagsBit0() == 0) {
            if (sceneNumbers != NULL) {
                if (race_race_getCurrentRaceMode() == 5) {
                    c = func_0205bba8();
                } else {
                    c = rchoi_getActivatedOption();
                }
                if (c != 0) {
                    race_sysdat_setActivatedRaceMenuOption(c);
                    race_handleMenuOption(sceneNumbers, c);
                }
                switch (race_race_getCurrentDisplayMode()) {
                    case RACE_KIND_DEMO:
                        c = 0;
                        if (sceneFrames > sndvar_getDemoRaceMaxDuration()) {
                            if (sndvar_getVarField4IsZero(1) != 0) {
                                c = 1;
                                race_sysdat_setDemoRaceWasCanceled(0);
                            }
                        }
                        if (c == 0) {
                            if (GetDownBits(race_input_getDefaultInputId(), 0x2fff) != 0) {
                                c = 1;
                                func_0203a48c(5);
                                race_sysdat_setDemoRaceWasCanceled(1);
                            } else if (func_0203a440(race_input_getDefaultInputId()) != 0) {
                                c = 1;
                                func_0203a48c(5);
                                race_sysdat_setDemoRaceWasCanceled(1);
                            }
                        }
                        if (c != 0) {
                            sceneNumbers->mNextScene = 0;
                        }
                        break;
                    case RACE_KIND_START_GP:
                    case 4:
                        if (IsCameraChainEnded() != 0 ||
                            (sceneFrames > 0x5a &&
                             (GetDownBits(race_input_getDefaultInputId(), 0xc0f) != 0 || func_0203a3cc(race_input_getDefaultInputId()) != 0))) {
                            sceneNumbers->mNextScene = 2;
                            race_race_setNextDisplayMode(0);
                        }
                        break;
                    case 2:
                        switch (race_race_getCurrentRaceMode()) {
                            case MODE_GRAND_PRIX:
                            case MODE_TIME_ATTACK:
                                if (rstat_203C0BC() != 0) {
                                    sceneNumbers->mNextScene = 2;
                                }
                                break;
                        }
                        break;
                    case RACE_KIND_AWARD:
                        if (ShouldEndAwardRace(sceneFrames) != 0) {
                            sceneNumbers->mNextScene = 0xa;
                        }
                        break;
                    case RACE_KIND_STAFF_ROLL:
                        c = 0x2a5a;
                        if (race_race_getCurrentCourse() == COURSE_ID_STAFFROLLTRUE) {
                            c = 0x2b02;
                        }
                        if (sceneFrames > c) {
                            sceneNumbers->mNextScene = 0xf;
                            break;
                        }
                        if (japdiff_203A908(sceneFrames) != 0) {
                            func_ov001_0219e0c4();
                            sceneNumbers->mNextScene = 0xf;
                        }
                        break;
                }
            }
            if (race_getShouldUpdate(sceneFrames) != 0) {
                race_update();
            }
            race_update2d();
        }
        func_020aeb7c();
        switch (race_race_getCurrentDisplayMode()) {
            case RACE_KIND_NORMAL:
            case 2:
            case RACE_KIND_START_GP:
            case 4:
                rchoi_update();
                break;
        }
        if (rchoi_getIsRacePaused() != 0) {
            input_setFlagsBit0(1);
        } else {
            input_setFlagsBit0(0);
        }
    }
    raceSetup = gRaceMultiConfig;
    if (raceSetup->mRaceKind != RACE_KIND_STAFF_ROLL) {
        c = 1;
    } else {
        if (sceneFrames < 0x708) {
            c = 0;
        } else {
            c = 1;
        }
    }
    if (c != 0) {
        if (raceSetup->mMode != 5 || dc_getFlagsBit1() == 0) {
            race_render();
        }
    }
    r2d_render();
    rchoi_render();
}

void racesc_preSleep(void) {
    gSystemData->mUnk_54 = FALSE;
    if (gRaceMultiConfig->mRaceKind == RACE_KIND_NORMAL) {
        rchoi_handleSleep(1);
    }
    spi_handlePreSleep();
    while ((u32) data_0217c7ac != 0) {
        dc_handleStartOfFrame();
        rchoi_update();
        sound_main();
        dc_2037850();
        rchoi_render();
        dc_handleEndOfFrame();
    }
}

void racesc_postSleep(void) {
    spi_handlePostSleep();
}

u32 race_run(SceneNumbers *sceneNumbers) {
    SceneCallbacks callbacks = gRaceSceneCallbacks;
    rconf_setupNext();
    if (gRaceMultiConfig->mMode == 5) {
        callbacks.mUnk_1c = 1;
    }
    if (gRaceMultiConfig->mRaceKind != RACE_KIND_AWARD) {
        if (gRaceMultiConfig->mRaceKind == RACE_KIND_STAFF_ROLL) {
            callbacks.mFadeToClearFrameCount = 1;
            callbacks.mFadeToFadedFrameCount = 0x78;
        }
    } else {
        callbacks.mFadeToClearFrameCount = 0x3c;
        callbacks.mFadeToFadedFrameCount = 0x78;
    }
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        rconf_loadCharacterSounds(1);
    }
    scene_runScene(sceneNumbers, &callbacks);
    return 0;
}

void menudef_create(void) {
    menu_create();
}

void menudef_finish(void) {
    ReleaseMenu();
    gSystemData->mUnk_50 &= ~1;
    ResetTimeAttackNextEntries();
}

void menudef_vblank(void) {
    menu_vblank();
}

void menudef_render(void) {
    menu_render();
    func_020cb4c0();
}

u32 menu_run(SceneNumbers *sceneNumbers) {
    SceneCallbacks callbacks = menu_sceneDef;
    scene_runScene(sceneNumbers, &callbacks);
    return 0;
}

u32 func_02039e08(NNSiFndHeapHead *heap, void **outBackHeap, void **outSoundBuffer, void **outFirstFrontHeap,
                  void **outSecondFrontHeap, void **outThirdFrontHeap) {
    u32 soundBufferSize;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        *outBackHeap = heap_createSubFrmHeapWithSizeFromTail(heap, 0x19000);
    } else {
        *outBackHeap = heap_createSubFrmHeapWithSizeFromTail(heap, 0x1b800);
    }
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        *outFirstFrontHeap = NULL;
        *outSecondFrontHeap = NULL;
        *outThirdFrontHeap = NULL;
    } else {
        *outFirstFrontHeap = heap_createSubFrmHeapWithSize(heap, 0x19000);
        *outSecondFrontHeap = heap_createSubFrmHeapWithSize(heap, 0x4b000);
        *outThirdFrontHeap = heap_createSubFrmHeapWithSize(heap, 0x1b800);
    }
    soundBufferSize = sound_getSomeSize(((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2 ? 2 : 0);
    *outSoundBuffer = heap_alloc(heap, soundBufferSize);
    NNS_FndGetTotalFreeSizeForExpHeap(heap);
    return soundBufferSize;
}
