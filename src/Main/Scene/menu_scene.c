#include "Main/Scene/menu_scene.h"
#include "Main/System/result_archive_path.h"
#include "Main/System/heap.h"
#include "Main/System/wireless_vram_state.h"
#include "Main/Menu/title_scene.h"
#include "Main/Scene/run_scene_connection.h"
#include "Main/Scene/scene_connection.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "Main/Race/race_setup_input.h"
#include "Main/Race/race_scene.h"
#include "Main/Menu/select_race_rule_state.h"
#include "Main/Race/time_attack_next_scene.h"
#include "Main/System/touch_mic_input.h"
#include "Main/Race/race_keys.h"
#include "Main/Net/wifi_race_sync_advance.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Race/race.h"
#include "Main/Race/race_hud_draw.h"
#include "Main/Menu/choises_s.h"
#include "Main/Menu/menu_screen_update.h"
#include "Main/Menu/menu_release.h"
#include "Main/Menu/menu.h"
#include "Main/Scene/title_no_input_frame_limit.h"
#include "Main/Sound/seq_queue_seq_volume_control_and_seq_variables.h"
#include "Main/Race/race_scene_callbacks.h"
#include "Main/Sound/sound_ortho_quad_and_item_box_timer_globals.h"
#include "sound_player_control.h"
#include "sound_archive_load.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids_on_memory_sdat_and_list_links.h"
#include "Main/Sound/sound_source_types_and_handle_sound_start.h"
#include "01/Menu/ending_scene.h"
#include "expanded_heap_head.h"

SceneCallbacks gMenuSceneCallbacks = {
    InitMenuScene, UpdateMenuScene, ReleaseMenuScene, WriteMenuSceneRegistersCallback, NULL, NULL, 0xa, 0xa, 0};

void UpdateRaceScene(SceneNumbers *sceneNumbers, u32 sceneFrames) {
    RaceSetup *raceSetup;
    u32 value;
    if (IsDataSharingIncomplete() == 0) {
        if (IsInputOpenDuringRace() == 0) {
            if (sceneNumbers != NULL) {
                if (RaceSceneGetCurrentMode() == MODE_WIFI) {
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
                            sceneNumbers->mNextScene = SCENE_TITLE;
                        }
                        break;
                    case RACE_KIND_START_GP:
                    case RACE_KIND_START_BATTLE:
                        if (IsCameraChainEnded() != 0 ||
                            (sceneFrames > 0x5a && (GetDownBits(GetRaceSceneInputSlot(), 0xc0f) != 0 ||
                                                    RaceSceneIsSlotPairNew(GetRaceSceneInputSlot()) != 0))) {
                            sceneNumbers->mNextScene = SCENE_RACE;
                            SetNextRaceKind(RACE_KIND_NORMAL);
                        }
                        break;
                    case RACE_KIND_REPLAY:
                        switch (RaceSceneGetCurrentMode()) {
                            case MODE_GRAND_PRIX:
                            case MODE_TIME_ATTACK:
                                if (ShouldEndReplayRace() != 0) {
                                    sceneNumbers->mNextScene = SCENE_RACE;
                                }
                                break;
                        }
                        break;
                    case RACE_KIND_AWARD:
                        if (ShouldEndAwardRace(sceneFrames) != 0) {
                            sceneNumbers->mNextScene = SCENE_RESULT;
                        }
                        break;
                    case RACE_KIND_STAFF_ROLL:
                        value = 0x2a5a;
                        if (RaceSceneGetCurrentCourseId() == COURSE_ID_STAFFROLLTRUE) {
                            value = 0x2b02;
                        }
                        if (sceneFrames > value) {
                            sceneNumbers->mNextScene = SCENE_ENDING;
                            break;
                        }
                        if (ShouldEndStaffRoll(sceneFrames) != 0) {
                            SetStaffRollEndedEarly();
                            sceneNumbers->mNextScene = SCENE_ENDING;
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
            case RACE_KIND_START_BATTLE:
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
            callbacks.mFadeToFadedFrameCount = STAFF_ROLL_FADE_TO_FADED_FRAMES;
        }
    } else {
        callbacks.mFadeToClearFrameCount = AWARD_FADE_TO_CLEAR_FRAMES;
        callbacks.mFadeToFadedFrameCount = AWARD_FADE_TO_FADED_FRAMES;
    }
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
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
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        *outBackHeap = CreateFrmHeapFromBack(heap, 0x19000);
    } else {
        *outBackHeap = CreateFrmHeapFromBack(heap, 0x1b800);
    }
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        *outFirstFrontHeap = NULL;
        *outSecondFrontHeap = NULL;
        *outThirdFrontHeap = NULL;
    } else {
        *outFirstFrontHeap = CreateFrmHeapFromFront(heap, 0x19000);
        *outSecondFrontHeap = CreateFrmHeapFromFront(heap, 0x4b000);
        *outThirdFrontHeap = CreateFrmHeapFromFront(heap, 0x1b800);
    }
    soundBufferSize = GetSndInitBufferSize(gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT ? 2 : 0);
    *outSoundBuffer = HeapAlloc(heap, soundBufferSize);
    NNS_FndGetTotalFreeSizeForExpHeap(heap);
    return soundBufferSize;
}
