#include "Main/Scene/menu_scene.h"
#include "Main/System/heap.h"
#include "Main/System/wvr_state.h"
#include "Main/Menu/title_scene.h"
#include "Main/Scene/run_scene_connection.h"
#include "Main/Scene/scene_connection.h"
#include "Main/Menu/data_02175000.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Race/course_list.h"
#include "Main/Race/race_scene.h"
#include "Main/Menu/select_race_rule_state.h"
#include "Main/Race/time_attack_next_scene.h"
#include "Main/Race/race_setup_input.h"
#include "Main/System/touch_mic_input.h"
#include "Main/Race/race_keys.h"
#include "Main/Net/wifi_race_sync_advance.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Race/race.h"
#include "Main/Race/race_hud_draw.h"
#include "Main/Menu/choises_s_screen_map.h"
#include "Main/Menu/choises_s_tiles.h"
#include "Main/Menu/menu_screen_update.h"
#include "Main/Menu/menu_release.h"
#include "Main/Menu/menu.h"
#include "Main/Scene/title_no_input_frame_limit.h"
#include "Main/Sound/seq_queue.h"
#include "Main/Race/data_02164000.h"
#include "Main/MapObjects/data_0217c000.h"
#include "player.h"
#include "code_0212d214.h"
#include "code_021479b4.h"
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "01/Menu/ending_scene.h"
#include "code_020176c0.h"
#include "Main/Race/race_entries.h"

void UpdateRaceScene(SceneNumbers *sceneNumbers, u32 sceneFrames) {
    RaceSetup *raceSetup;
    u32 value;
    if (IsDataSharingIncomplete() == 0) {
        if (IsInputOpenDuringRace() == 0) {
            if (sceneNumbers != NULL) {
                if (RaceSceneGetCurrentMode() == 5) {
                    value = GetWiFiRaceSyncPickedValue();
                } else {
                    value = GetChoisesSPickedValue();
                }
                if (value != 0) {
                    SetPickedValue(value);
                    SetNextSceneFromPickedValue(sceneNumbers, value);
                }
                switch (GetCurrentRaceKind()) {
                    case RACE_KIND_DEMO:
                        value = 0;
                        if (sceneFrames > GetDemoRaceFrameLimit()) {
                            if (IsSeqVariableChanged(1) != 0) {
                                value = 1;
                                SetDemoEndedByInput(0);
                            }
                        }
                        if (value == 0) {
                            if (GetDownBits(GetRaceSceneInputSlot(), 0x2fff) != 0) {
                                value = 1;
                                StartRaceSceneSound(5);
                                SetDemoEndedByInput(1);
                            } else if (RaceSceneSlotHasPairOrLost(GetRaceSceneInputSlot()) != 0) {
                                value = 1;
                                StartRaceSceneSound(5);
                                SetDemoEndedByInput(1);
                            }
                        }
                        if (value != 0) {
                            sceneNumbers->mNextScene = 0;
                        }
                        break;
                    case RACE_KIND_START_GP:
                    case 4:
                        if (IsCameraChainEnded() != 0 ||
                            (sceneFrames > 0x5a && (GetDownBits(GetRaceSceneInputSlot(), 0xc0f) != 0 ||
                                                    RaceSceneIsSlotPairNew(GetRaceSceneInputSlot()) != 0))) {
                            sceneNumbers->mNextScene = 2;
                            SetNextRaceKind(0);
                        }
                        break;
                    case RACE_KIND_REPLAY:
                        switch (RaceSceneGetCurrentMode()) {
                            case MODE_GRAND_PRIX:
                            case MODE_TIME_ATTACK:
                                if (ShouldEndReplayRace() != 0) {
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
                        value = 0x2a5a;
                        if (RaceSceneGetCurrentCourseId() == COURSE_ID_STAFFROLLTRUE) {
                            value = 0x2b02;
                        }
                        if (sceneFrames > value) {
                            sceneNumbers->mNextScene = 0xf;
                            break;
                        }
                        if (ShouldEndStaffRoll(sceneFrames) != 0) {
                            SetStaffRollEndedEarly();
                            sceneNumbers->mNextScene = 0xf;
                        }
                        break;
                }
            }
            if (ShouldUpdateRace(sceneFrames) != 0) {
                UpdateRace();
            }
            UpdateRaceHud();
        }
        UpdateRaceHudSubScreen();
        switch (GetCurrentRaceKind()) {
            case RACE_KIND_NORMAL:
            case RACE_KIND_REPLAY:
            case RACE_KIND_START_GP:
            case 4:
                UpdateChoisesS();
                break;
        }
        if (GetChoisesSOpenDuringRace() != 0) {
            SetInputOpenDuringRace(1);
        } else {
            SetInputOpenDuringRace(0);
        }
    }
    raceSetup = gRaceSetup;
    if (raceSetup->mRaceKind != RACE_KIND_STAFF_ROLL) {
        value = 1;
    } else {
        if (sceneFrames < 0x708) {
            value = 0;
        } else {
            value = 1;
        }
    }
    if (value != 0) {
        if (raceSetup->mMode != MODE_WIFI || IsFrameSpanningVBlank() == 0) {
            DrawRace();
        }
    }
    DrawRaceHud();
    UpdateChoisesSScreenMap();
}

void PreSleepRaceScene(void) {
    gStartupWork->mUnk_54 = FALSE;
    if (gRaceSetup->mRaceKind == RACE_KIND_NORMAL) {
        SetChoisesSOpenDuringRace(1);
    }
    PreSleepMicInput();
    while ((u32) gChoisesSSeqHandle != 0) {
        PrepareDisplayFrame();
        UpdateChoisesS();
        UpdateSounds();
        FinishDisplayFrame();
        UpdateChoisesSScreenMap();
        RecordFrameTimes();
    }
}

void PostSleepRaceScene(void) {
    PostSleepMicInput();
}

u32 RunRaceScene(SceneNumbers *sceneNumbers) {
    SceneCallbacks callbacks = gRaceSceneCallbacks;
    SetCurrentRaceFromNext();
    if (gRaceSetup->mMode == MODE_WIFI) {
        callbacks.mSkipWhenSpanned = 1;
    }
    if (gRaceSetup->mRaceKind != RACE_KIND_AWARD) {
        if (gRaceSetup->mRaceKind == RACE_KIND_STAFF_ROLL) {
            callbacks.mFadeToClearFrameCount = 1;
            callbacks.mFadeToFadedFrameCount = 0x78;
        }
    } else {
        callbacks.mFadeToClearFrameCount = 0x3c;
        callbacks.mFadeToFadedFrameCount = 0x78;
    }
    if (gBootInfo->mBootType != 2) {
        LoadSndBanksForCharacters(1);
    }
    RunScene(sceneNumbers, &callbacks);
    return 0;
}

void InitMenuScene(void) {
    InitMenu();
}

void ReleaseMenuScene(void) {
    ReleaseMenu();
    gStartupWork->mDemoEndedByInput &= ~1;
    ResetTimeAttackNextEntries();
}

void WriteMenuSceneRegistersCallback(void) {
    WriteMenuSceneRegisters();
}

void UpdateMenuScene(void) {
    UpdateMenuScreen();
    HideUnusedMenuOams();
}

u32 RunMenuScene(SceneNumbers *sceneNumbers) {
    SceneCallbacks callbacks = gMenuSceneCallbacks;
    RunScene(sceneNumbers, &callbacks);
    return 0;
}

u32 CreateFrmHeapsAndAllocSoundBuffer(NNSiFndHeapHead *heap, void **outBackHeap, void **outSoundBuffer,
                                      void **outFirstFrontHeap, void **outSecondFrontHeap, void **outThirdFrontHeap) {
    u32 soundBufferSize;
    if (gBootInfo->mBootType == 2) {
        *outBackHeap = CreateFrmHeapFromBack(heap, 0x19000);
    } else {
        *outBackHeap = CreateFrmHeapFromBack(heap, 0x1b800);
    }
    if (gBootInfo->mBootType != 2) {
        *outFirstFrontHeap = NULL;
        *outSecondFrontHeap = NULL;
        *outThirdFrontHeap = NULL;
    } else {
        *outFirstFrontHeap = CreateFrmHeapFromFront(heap, 0x19000);
        *outSecondFrontHeap = CreateFrmHeapFromFront(heap, 0x4b000);
        *outThirdFrontHeap = CreateFrmHeapFromFront(heap, 0x1b800);
    }
    soundBufferSize = GetSndInitBufferSize(gBootInfo->mBootType == 2 ? 2 : 0);
    *outSoundBuffer = HeapAlloc(heap, soundBufferSize);
    NNS_FndGetTotalFreeSizeForExpHeap(heap);
    return soundBufferSize;
}
