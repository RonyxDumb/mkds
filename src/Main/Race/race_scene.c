#include "Main/Race/race_scene.h"
#include "Main/Menu/wl_menu_kind.h"

#include "Main/Scene/menu_scene.h"
#include "Main/System/input_slots.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "sound_player_control.h"
#include "sound_archive_load_result.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Race/race_setup_input.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/Menu/menu_entry_kind.h"
#include "Main/Race/results_gp.h"
#include "Main/Race/time_attack_next_scene.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/System/backup_net_camera_work.h"
#include "00/Menu/wi_fi_vs_matching.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"
#include "formatted_text_to_buffer.h"
#include "Main/Race/race_keys.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/System/touch_mic_input.h"
#include "heap_expanded_allocator.h"
#include "Main/System/heap_call.h"
#include "Main/System/result_archive_path.h"
#include "Main/System/wireless_vram_state.h"
#include "Main/System/key_recording.h"
#include "Main/Net/race_connection_flag.h"
#include "Main/Net/connection_sharing.h"
#include "Main/Graphics/disp_cap.h"
#include "Main/Save/backup_first_block_write_wrapper.h"
#include "Main/Save/backup_reset.h"
#include "Main/System/thread_function_queue.h"
#include "Main/Net/slot_result_sync.h"
#include "Main/Save/buddy_record.h"
#include "Main/Race/race.h"
#include "Main/Race/race_hud_draw.h"
#include "Main/Menu/choises_s.h"
#include "Main/Race/race_scene_callbacks.h"
#include "card_rom_backup_access.h"
#include "Main/Race/grand_prix_next_course.h"
#include "registers.h"
#include "Main/Sound/sound_system.h"
#include "Main/Menu/menu_shared_clear.h"
#include "Main/Net/wifi_session.h"
#include "Main/Scene/menu_scene.h"
#include "Main/Scene/display_settings_descs.h"
#include "Main/System/init_after_startup.h"

void *gRaceDisplaySettingsDescs[7] = {(void *) gRaceDisplaySettingsDescNormal, (void *) gRaceDisplaySettingsDescNormal,
                                      (void *) gRaceDisplaySettingsDescNormal, (void *) gRaceDisplaySettingsDescBitmap,
                                      (void *) gRaceDisplaySettingsDescNormal, (void *) gRaceDisplaySettingsDescBitmap,
                                      (void *) gRaceDisplaySettingsDescNormal};
SceneCallbacks g_Scene_Race = {Scene_Race_Initialize,
                                      Scene_Race_Update,
                                      Scene_Race_Finalize,
                                      Scene_Race_VBlank,
                                      Scene_Race_PreSleep,
                                      Scene_Race_PostSleep,
                                      0x1e,
                                      0x1e,
                                      0};

static inline u32 IsPadOrParticipantPairPresentOrRecentlyLost(void) {
    InputSlotIndex slotIndex = INPUT_SLOT_PAD_OR_PARTICIPANT;
    u32 result = 1;
    u32 briefNoPair = 0;
    u16 hasPair = g_GlobalCYT[slotIndex].mPair.mHasPair;
    if (hasPair == 0 && g_GlobalCYT[slotIndex].mPair.mNoPairCount < INPUT_NO_PAIR_BRIEF_FRAMES) {
        briefNoPair = 1;
    }
    if (briefNoPair == 0 && hasPair == 0) {
        result = 0;
    }
    return result;
}

BOOL FindFormatGhostBinPath(u32 courseId, void *buffer, u32 size) {
    int cupCourseIndex = GetCourseIdFromInternalId(courseId);
    if (cupCourseIndex == -1) {
        return FALSE;
    }
    Util_SNPrintF(buffer, size, "/data/ghost/ghost_%03d.bin", cupCourseIndex & 0xff);
    return TRUE;
}

static inline u32 IsAnyGrandPrixRecordFilled(void) {
    u8 cupIndex;
    u8 engineClassIndex;
    for (cupIndex = 0; cupIndex < 8; cupIndex++) {
        for (engineClassIndex = 0; engineClassIndex < 4; engineClassIndex++) {
            if (CupHasRecord(cupIndex, engineClassIndex) != 0) {
                return 1;
            }
        }
    }
    return 0;
}

// The staff roll waits 0x708 frames before the race runs.
u32 ShouldUpdateRace(u32 sceneFrames) {
    if (g_GlobalCO->mRaceKind != RACE_KIND_STAFF_ROLL) {
        return 1;
    }
    return sceneFrames >= 0x708;
}

void SetGlobalDisplayConfigForDisplayMode(void *heap) {
    DisplaySettings *settings;
    settings = CreateDisplayConfig(heap, gRaceDisplaySettingsDescs[g_GlobalCO->mRaceKind]);
    DisplayConfig_SetSwapBufferValues(settings, 1, 1);
    DisplayEngineConfig_SetBg0Config(&settings->mMainBgRecords, 1, 0, 0, 1, 0, 0, 0);
    switch (g_GlobalCO->mRaceKind) {
        case RACE_KIND_NORMAL:
        case RACE_KIND_REPLAY:
        case RACE_KIND_STAFF_ROLL:
            DisplayEngineConfig_SetBg2Config2(&settings->mMainBgRecords, 1, 0, 0, 0, 7, 0);
            DisplayEngineConfig_SetBg0Config(&settings->mSubBgRecords, 0, 0, 0, 0, 0xd, 0, 0);
            DisplayEngineConfig_SetBg1Config(&settings->mSubBgRecords, 1, 0, 0, 0, 0xe, 0, 0);
            DisplayEngineConfig_SetBg2Config2(&settings->mSubBgRecords, 2, 0, 0, 0, 0xf, 0);
            SetDispCapMode(DISP_CAP_MODE_OFF);
            break;
        case RACE_KIND_DEMO:
            DisplayEngineConfig_SetBg2Config2(&settings->mMainBgRecords, 1, 0, 0, 0, 7, 0);
            DisplayEngineConfig_SetBg0Config(&settings->mSubBgRecords, 0, 0, 0, 0, 0xd, 0, 0);
            DisplayEngineConfig_SetBg1Config(&settings->mSubBgRecords, 1, 0, 0, 0, 0xe, 0, 0);
            DisplayEngineConfig_SetBg2Config2(&settings->mSubBgRecords, 2, 0, 0, 0, 0xf, 0);
            SetDispCapMode(DISP_CAP_MODE_OFF);
            break;
        case RACE_KIND_START_GP:
        case RACE_KIND_AWARD:
            DisplayEngineConfig_SetBg2Config2(&settings->mMainBgRecords, 1, 0, 0, 0, 7, 0);
            DisplayEngineConfig_SetBg2Config(&settings->mSubBgRecords, 0, 0, 1, 0, 0);
            DisplayConfig_SetBottomEngineObjVramModeBmp(settings, 0x20);
            SetDispCapMode(DISP_CAP_MODE_BANK_TOGGLE);
            break;
        case RACE_KIND_START_BATTLE:
            DisplayEngineConfig_SetBg2Config2(&settings->mMainBgRecords, 1, 0, 0, 0, 7, 0);
            SetDispCapMode(DISP_CAP_MODE_OFF);
            break;
    }
    SetGlobalDisplayConfig(settings);
    SetupDispCap();
    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~REG_G2_BG0CNT_PRIORITY_MASK) | 2;
}

void Scene_Race_Initialize(void) {
    void *heap;
    s32 mirrorMode;
    WiFiSession *session;
    BOOL sessionHeapCreated;
    heap = ExecutionContext_GetHeapHandle(GetActiveExecutionContext());
    CreateRegionHeapHandleForOverlay1();
    if (g_GlobalCO->mRaceKind == RACE_KIND_START_GP || g_GlobalCO->mRaceKind == RACE_KIND_AWARD) {
        MaybeInitializeSomeWirelessShit();
    } else {
        SomeVramConfig();
        InitRaceConnection();
    }
    Init3dEngine();
    SetActiveExecutionContextHeapGroupId_from_thumb(7);
    InitializeGlobalAA04(heap);
    SetGlobalDisplayConfigForDisplayMode(heap);
    ResetInputSlotsFromRaceSetup();
    SetActiveExecutionContextHeapGroupId_from_thumb(9);
    InitializeGlobalTD();
    SetActiveExecutionContextHeapGroupId_from_thumb(5);
    LoadRaceOptionMenus_from_thumb();
    InitRaceHud();
    if (g_GlobalCO->mRaceKind != RACE_KIND_START_GP) {
        SetupRaceHudScreens();
    }
    SetActiveExecutionContextHeapGroupId_from_thumb(8);
    mirrorMode = g_GlobalCO->mMirrorMode;
    if (mirrorMode == 0 && g_GlobalCO->mMode == MODE_MISSION_RUN) {
        if ((g_GlobalCO->mMissionRunBits & MISSION_RUN_BIT_SWAP_LEFT_RIGHT) != 0) {
            mirrorMode = 1;
        }
    }
    SetLeftRightKeysSwapped(mirrorMode);
    SetActiveExecutionContextHeapGroupId_from_thumb(9);
    if (g_GlobalCO->mMode != MODE_BATTLE) {
        if (g_GlobalCO->mMode == MODE_WIFI) {
            sessionHeapCreated = FALSE;
            session = g_GlobalB;
            if (session != NULL) {
                if (session->mHeapCreated != FALSE) {
                    sessionHeapCreated = TRUE;
                }
            }
            if (sessionHeapCreated != FALSE) {
                StateMachine *stateMachine;
                session->mRaceSyncEnabled = TRUE;
                stateMachine = &g_GlobalB->mStateMachine;
                stateMachine->mNextState = WIFI_SESSION_STATE_RACE;
                stateMachine->mNextStateRequested = 1;
            }
        }
    } else {
        if (g_GlobalCO->mBattleKind == BATTLE_KIND_BALLOON) {
            CreateGlobal59C4Sub(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()));
        }
    }
}

// In the staff roll it also sets a backup flag once and writes the save block.
void Scene_Race_Finalize(void) {
    RaceSetup *raceSetup;
    WiFiSession *session;
    s32 flagIndex;
    BOOL sessionHeapCreated;
    if (g_GlobalCO->mMode == MODE_WIFI) {
        sessionHeapCreated = FALSE;
        session = g_GlobalB;
        if (session != NULL) {
            if (session->mHeapCreated != FALSE) {
                sessionHeapCreated = TRUE;
            }
        }
        if (sessionHeapCreated != FALSE) {
            StateMachine *stateMachine;
            session->mRaceSyncEnabled = FALSE;
            stateMachine = &g_GlobalB->mStateMachine;
            stateMachine->mNextState = WIFI_SESSION_STATE_EXCHANGE;
            stateMachine->mNextStateRequested = 1;
        }
    }
    raceSetup = g_GlobalCO;
    if (raceSetup->mRaceKind == RACE_KIND_STAFF_ROLL) {
        flagIndex = 0x18;
        if (raceSetup->mMode != MODE_GRAND_PRIX) {
            if (raceSetup->mMode == MODE_MISSION_RUN) {
                flagIndex = 0x1a;
            }
        } else {
            if (raceSetup->mCourseId == COURSE_ID_STAFFROLLTRUE) {
                flagIndex = 0x19;
            }
        }
        if (CheckSavedSecretFlag_from_thumb(flagIndex) == 0) {
            SetSavedSecretFlag_from_thumb(flagIndex);
            WriteSaveDataSectionHeaderToSaveData_from_thumb();
            WaitForWorkerTask();
            if (g_SaveDataIoManager->mBackupEnabled != 0) {
                j_WaitForPendingCardOperation();
            }
        }
    }
    ResetGlobal59C4Sub();
    ResetRaceMenuOptions_from_thumb();
    ResetAA();
    ReleaseRaceHud();
    ResetGlobalAA04();
    ClearRaceConnectionFlag();
    DisposeOverlayManagerHeap();
}

void Scene_Race_VBlank(void) {
    AdvanceDispCap(MaybeIsMenuOn_from_thumb());
    nullsub_6();
    UploadRaceHud();
}

// The award scene ends after 0x564 frames, or on a new key press once some Grand Prix record is filled.
u32 ShouldEndAwardRace(u32 sceneFrames) {
    if (sceneFrames > 0x564) {
        return 1;
    }
    if (Bright_IsBothScreensFadedIn() == 0) {
        return 0;
    }
    if (IsAnyGrandPrixRecordFilled() != 0) {
        InputSlotIndex slotIndex = INPUT_SLOT_PAD_OR_PARTICIPANT;
        if ((u16) (g_GlobalCYT[slotIndex].mPressedBits & PAD_KEY_A) != 0) {
            return 1;
        }
    }
    return 0;
}

// The staff roll can end early on input after 0xb4 frames when its flag for the mode is set.
u32 CheckIsEnding(u32 sceneFrames) {
    u32 result;
    s32 flagIndex = 0x18;
    if (g_GlobalCO->mMode != MODE_GRAND_PRIX) {
        if (g_GlobalCO->mMode == MODE_MISSION_RUN) {
            flagIndex = 0x1a;
        }
    } else {
        if (g_GlobalCO->mCourseId == COURSE_ID_STAFFROLLTRUE) {
            flagIndex = 0x19;
        }
    }
    result = 0;
    if (CheckSavedSecretFlag_from_thumb(flagIndex) != 0 && sceneFrames > 0xb4) {
        InputSlotIndex slotIndex = INPUT_SLOT_PAD_OR_PARTICIPANT;
        if ((u16) (g_GlobalCYT[slotIndex].mBits & PAD_KEYS_NO_DIRECTION_OR_SHOULDER) != 0 ||
            IsPadOrParticipantPairPresentOrRecentlyLost() != 0) {
            result = 1;
        }
    }
    return result;
}

u32 GetCurrentRaceMode_1(void) {
    return (g_GlobalCO->mMode);
}

void SetPickedValue(u32 pickedValue) {
    g_GlobalP->mPickedValue = pickedValue;
}

// Turns the value picked on the choice screen into the next scene and the settings that go with it.
void SetNextSceneFromPickedValue(SceneNumbers *sceneNumbers, u32 pickedValue) {
    s32 nextScene;
    g_GlobalB488->mMenuEntryKind = MENU_ENTRY_FIRST_SCREEN;
    nextScene = -1;
    switch (pickedValue) {
        case CHOISES_S_PICK_STAFF_CREDITS:
            SetupStaffRollRace(0);
            nextScene = SCENE_RACE;
            break;
        case CHOISES_S_PICK_QUIT:
            if (g_GlobalCO->mMode != MODE_WIFI) {
                u32 connectionMode;
                u32 connectionActive;
                ConnectionWork *connectionWork;
                connectionActive = 0;
                connectionWork = g_GlobalZE;
                if (connectionWork == NULL) {
                    connectionMode = CONNECTION_MODE_NONE;
                } else {
                    connectionMode = connectionWork->mConnectionMode;
                }
                if (connectionMode != CONNECTION_MODE_NONE) {
                    if (connectionWork->mState != CONNECTION_STATE_ENDED) {
                        connectionActive = 1;
                    }
                }
                if (connectionActive != 0) {
                    if (g_GlobalP->mMultiSimple != 0) {
                        nextScene = SCENE_WL_MENU;
                        g_GlobalB488->mWLMenuKind = WL_MENU_KIND_TO_MENU;
                    } else {
                        nextScene = SCENE_MENU_1;
                    }
                    g_GlobalB488->mMenuEntryKind = MENU_ENTRY_SELECT_GAME;
                    g_GlobalB488->mRaceSetupRequested = 1;
                } else {
                    nextScene = SCENE_TITLE;
                }
                if (g_GlobalCO->mMode == MODE_TIME_ATTACK) {
                    nullsub_4();
                }
            } else {
                nextScene = SCENE_WIFI_MENU;
                g_GlobalB488->mWiFiMenuStartKind = WIFI_MENU_START_TOP_MENU;
            }
            break;
        case CHOISES_S_PICK_RETRY:
        case CHOISES_S_PICK_RESTART:
            nextScene = SCENE_RACE;
            g_GlobalCO->mNextHeader.mRaceKind = RACE_KIND_NORMAL;
            break;
        case CHOISES_S_PICK_REPLAY:
            nextScene = SCENE_RACE;
            g_GlobalCO->mNextHeader.mRaceKind = RACE_KIND_REPLAY;
            break;
        case CHOISES_S_PICK_NEXT:
            switch (g_GlobalCO->mMode) {
                case MODE_GRAND_PRIX:
                    PrepareForCourseIntro();
                    nextScene = SCENE_RACE;
                    break;
                case MODE_VS:
                    if (AdvanceToNextCourseWrapper() != 0) {
                        if (g_GlobalP->mMultiSimple == 0) {
                            nextScene = SCENE_RACE;
                        } else {
                            nextScene = SCENE_WL_MENU;
                            g_GlobalB488->mWLMenuKind = WL_MENU_KIND_TO_RACE;
                        }
                    } else {
                        if (g_GlobalCO->mCourseListMode == COURSE_LIST_MODE_SINGLE) {
                            g_GlobalB488->mMenuEntryKind = MENU_ENTRY_COURSE_SELECT;
                        }
                        if (g_GlobalP->mMultiSimple == 0) {
                            nextScene = SCENE_MENU_1;
                        } else {
                            nextScene = SCENE_WL_MENU;
                            g_GlobalB488->mWLMenuKind = WL_MENU_KIND_TO_MENU;
                        }
                    }
                    break;
                case MODE_WIFI:
                    if (CopyCourseIdAndAdvanceCourseNumber() != FALSE) {
                        nextScene = SCENE_WIFI_MENU;
                        g_GlobalB488->mWiFiMenuStartKind = WIFI_MENU_START_VS_COURSE_SELECT;
                    } else {
                        nextScene = SCENE_RESULT;
                        g_GlobalB488->mWiFiMenuStartKind = WIFI_MENU_START_SELECT_CHARACTER;
                    }
                    break;
                case MODE_BATTLE:
                    if (AdvanceToNextBattleCourse() != 0) {
                        if (g_GlobalP->mMultiSimple == 0) {
                            nextScene = SCENE_RACE;
                        } else {
                            nextScene = SCENE_WL_MENU;
                            g_GlobalB488->mWLMenuKind = WL_MENU_KIND_TO_RACE;
                        }
                    } else {
                        if (g_GlobalCO->mCourseListMode == COURSE_LIST_MODE_SINGLE) {
                            g_GlobalB488->mMenuEntryKind = MENU_ENTRY_COURSE_SELECT;
                        }
                        if (g_GlobalP->mMultiSimple == 0) {
                            nextScene = SCENE_MENU_1;
                        } else {
                            nextScene = SCENE_WL_MENU;
                            g_GlobalB488->mWLMenuKind = WL_MENU_KIND_TO_MENU;
                        }
                    }
                    break;
            }
            break;
        case CHOISES_S_PICK_NEXT_LAST:
            switch (g_GlobalCO->mMode) {
                case MODE_GRAND_PRIX:
                    if (CopyEntryResultAndSetupAwardRace() != FALSE) {
                        nextScene = SCENE_RACE;
                    } else {
                        nextScene = SCENE_RESULT;
                    }
                    break;
                case MODE_MISSION_RUN:
                    nextScene = SCENE_TITLE;
                    break;
                case MODE_BATTLE:
                case MODE_VS:
                    if (g_GlobalP->mMultiSimple != 0) {
                        nextScene = SCENE_WL_MENU;
                        g_GlobalB488->mWLMenuKind = WL_MENU_KIND_TO_RESULT;
                    } else {
                        nextScene = SCENE_RESULT;
                    }
                    break;
            }
            break;
        case CHOISES_S_PICK_CHANGE_CHARACTERS:
            nextScene = SCENE_MENU_1;
            g_GlobalB488->mMenuEntryKind = MENU_ENTRY_CHARACTER_SELECT;
            break;
        case CHOISES_S_PICK_CHANGE_COURSE:
            g_GlobalB488->mMenuEntryKind = MENU_ENTRY_COURSE_SELECT;
            nextScene = SCENE_MENU_1;
            break;
        case CHOISES_S_PICK_SELECT_MISSION:
            g_GlobalB488->mMenuEntryKind = MENU_ENTRY_MISSION_SELECT;
            nextScene = SCENE_MENU_1;
            break;
    }
    if (nextScene != -1) {
        sceneNumbers->mNextScene = nextScene;
    }
}

u32 GetDisplayMode(void) {
    return g_GlobalCO->mRaceKind;
}

void SetGlobalP_BFlagBit1(u32 endedByInput) {
    if (endedByInput != 0) {
        g_GlobalP->mDemoEndedByInput |= 1;
    } else {
        g_GlobalP->mDemoEndedByInput &= ~1;
    }
}

u32 GetSomeCYId_8(void) {
    return 0x8u;
}

u16 TestInputKeys(u32 slotIndex, u32 mask) {
    u32 bits;
    bits = g_GlobalCYT[slotIndex].mBits;
    return bits & mask;
}

u32 MaybePlaySseqFromSarc0(u32 index) {
    return PlaySseqFromSarc(&gSharedSeqHandle, 0u, index);
}

u32 HasTouchPressed(u32 slotIndex) {
    u32 result;
    u32 briefNoPair;
    u16 hasPair;
    result = 1;
    briefNoPair = 0;
    hasPair = g_GlobalCYT[slotIndex].mPair.mHasPair;
    if (hasPair == 0 && g_GlobalCYT[slotIndex].mPair.mNoPairCount < INPUT_NO_PAIR_BRIEF_FRAMES) {
        briefNoPair = 1;
    }
    if (briefNoPair == 0 && hasPair == 0) {
        result = 0;
    }
    return result;
}

u32 IsRaceIntroInFadeOut(void) {
    return g_GlobalMV->mCameraChainEnded;
}

u32 AnotherHasTouchPressed(u32 slotIndex) {
    u32 result;
    u32 briefNoPair;
    result = 0;
    briefNoPair = 0;
    if (g_GlobalCYT[slotIndex].mPair.mHasPair == 0 &&
        g_GlobalCYT[slotIndex].mPair.mNoPairCount < INPUT_NO_PAIR_BRIEF_FRAMES) {
        briefNoPair = 1;
    }
    if (briefNoPair == 0 && g_GlobalCYT[slotIndex].mPair.mPrevHasPair == 0 &&
        g_GlobalCYT[slotIndex].mPair.mHasPair != 0) {
        result = 1;
    }
    return result;
}

void SetNextRaceDisplayMode(u32 raceKind) {
    g_GlobalCO->mNextHeader.mRaceKind = raceKind;
}

u32 GetCurrentInternalCourseId(void) {
    return (g_GlobalCO->mCourseId);
}
