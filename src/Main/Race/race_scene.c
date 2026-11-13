#include "Main/Race/race_scene.h"

#include "Main/Scene/menu_scene.h"
#include "Main/Menu/data_02175628.h"
#include "Main/Race/data_020f36d8.h"
#include "player.h"
#include "code_0212df7c.h"
#include "Main/Menu/data_02175000.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Race/race_setup_input.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/Race/results_gp.h"
#include "Main/Race/time_attack_next_scene.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/MapObjects/data_0217a000.h"
#include "00/Menu/wi_fi_vs_matching.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/code_02196d58.h"
#include "os_printf.h"
#include "Main/Race/race_keys.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/System/touch_mic_input.h"
#include "expheap.h"
#include "Main/System/heap_call.h"
#include "Main/System/result_archive_path.h"
#include "Main/System/wvr_state.h"
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
#include "Main/Race/data_02164000.h"
#include "code_021458c4.h"
#include "Main/Race/grand_prix_next_course.h"
#include "registers.h"
#include "Main/Sound/sound_system.h"
#include "Main/Menu/menu_shared_clear.h"
#include "Main/Net/wifi_session.h"
#include "Main/Scene/menu_scene.h"
#include "Main/Scene/display_settings_descs.h"
#include "Main/System/init_after_startup.h"

void *gRaceDisplaySettingsDescs[7] = {(void *) gRaceDisplaySettingsDescNormal, (void *) gRaceDisplaySettingsDescNormal, (void *) gRaceDisplaySettingsDescNormal, (void *) gRaceDisplaySettingsDescBitmap, (void *) gRaceDisplaySettingsDescNormal, (void *) gRaceDisplaySettingsDescBitmap, (void *) gRaceDisplaySettingsDescNormal};
SceneCallbacks gRaceSceneCallbacks = {InitRaceScene, UpdateRaceScene, ReleaseRaceScene, AdvanceDispCapAndUploadRaceHud, PreSleepRaceScene, PostSleepRaceScene, 0x1e, 0x1e, 0};

static inline u32 IsSlot8PairPresentOrRecentlyLost(void) {
    InputSlotIndex slotIndex = UNK_02175628_INDEX_8;
    u32 result = 1;
    u32 briefNoPair = 0;
    u16 hasPair = gInputSlots[slotIndex].mPair.mHasPair;
    if (hasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < 5) {
        briefNoPair = 1;
    }
    if (briefNoPair == 0 && hasPair == 0) {
        result = 0;
    }
    return result;
}

BOOL TryFormatGhostPath(u32 courseId, void *buffer, u32 size) {
    int cupCourseIndex = FindCupCourseIndex(courseId);
    if (cupCourseIndex == -1) {
        return FALSE;
    }
    OS_SNPrintf(buffer, size, "/data/ghost/ghost_%03d.bin", cupCourseIndex & 0xff);
    return TRUE;
}

static inline u32 IsAnyGrandPrixRecordFilled(void) {
    u8 cupIndex;
    u8 engineClassIndex;
    for (cupIndex = 0; cupIndex < 8; cupIndex++) {
        for (engineClassIndex = 0; engineClassIndex < 4; engineClassIndex++) {
            if (IsGrandPrixRecordFilled(cupIndex, engineClassIndex) != 0) {
                return 1;
            }
        }
    }
    return 0;
}

// The staff roll waits 0x708 frames before the race runs.
u32 ShouldUpdateRace(u32 sceneFrames) {
    if (gRaceSetup->mRaceKind != RACE_KIND_STAFF_ROLL) {
        return 1;
    }
    return sceneFrames >= 0x708;
}

void SetupRaceDisplay(void *heap) {
    DisplaySettings *settings;
    settings = CreateDisplaySettings(heap, gRaceDisplaySettingsDescs[gRaceSetup->mRaceKind]);
    SetG3xSwapBits(settings, 1, 1);
    SetBg0Record(&settings->mMainBgRecords, 1, 0, 0, 1, 0, 0, 0);
    switch (gRaceSetup->mRaceKind) {
        case RACE_KIND_NORMAL:
        case RACE_KIND_REPLAY:
        case RACE_KIND_STAFF_ROLL:
            SetBg2RecordParams(&settings->mMainBgRecords, 1, 0, 0, 0, 7, 0);
            SetBg0Record(&settings->mSubBgRecords, 0, 0, 0, 0, 0xd, 0, 0);
            SetBg1Record(&settings->mSubBgRecords, 1, 0, 0, 0, 0xe, 0, 0);
            SetBg2RecordParams(&settings->mSubBgRecords, 2, 0, 0, 0, 0xf, 0);
            SetDispCapMode(0);
            break;
        case RACE_KIND_DEMO:
            SetBg2RecordParams(&settings->mMainBgRecords, 1, 0, 0, 0, 7, 0);
            SetBg0Record(&settings->mSubBgRecords, 0, 0, 0, 0, 0xd, 0, 0);
            SetBg1Record(&settings->mSubBgRecords, 1, 0, 0, 0, 0xe, 0, 0);
            SetBg2RecordParams(&settings->mSubBgRecords, 2, 0, 0, 0, 0xf, 0);
            SetDispCapMode(0);
            break;
        case RACE_KIND_START_GP:
        case RACE_KIND_AWARD:
            SetBg2RecordParams(&settings->mMainBgRecords, 1, 0, 0, 0, 7, 0);
            SetBg2RecordMode5(&settings->mSubBgRecords, 0, 0, 1, 0, 0);
            SetSubObjVRamModeBmp(settings, 0x20);
            SetDispCapMode(1);
            break;
        case 4:
            SetBg2RecordParams(&settings->mMainBgRecords, 1, 0, 0, 0, 7, 0);
            SetDispCapMode(0);
            break;
    }
    InitDisplayFromSettings(settings);
    SetupDispCap();
    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~3) | 2;
}

void InitRaceScene(void) {
    void *heap;
    s32 mirrorMode;
    WiFiSession *session;
    BOOL sessionHeapCreated;
    heap = GetHeap(GetCurrentHeapCall());
    CreateOverlayExpHeap();
    if (gRaceSetup->mRaceKind == RACE_KIND_START_GP || gRaceSetup->mRaceKind == RACE_KIND_AWARD) {
        StopWvrAndWait();
    } else {
        ClearLcdcBankAndStartWvrAndWait();
        InitRaceConnection();
    }
    Init3dEngine();
    SetHeapGroupId(7);
    InitDispCap(heap);
    SetupRaceDisplay(heap);
    ResetInputSlotsFromRaceSetup();
    SetHeapGroupId(9);
    InitRace();
    SetHeapGroupId(5);
    InitChoisesS();
    InitRaceHud();
    if (gRaceSetup->mRaceKind != RACE_KIND_START_GP) {
        SetupRaceHudScreens();
    }
    SetHeapGroupId(8);
    mirrorMode = gRaceSetup->mMirrorMode;
    if (mirrorMode == 0 && gRaceSetup->mMode == MODE_MISSION_RUN) {
        if ((gRaceSetup->mMissionRunBits & MISSION_RUN_BIT_SWAP_LEFT_RIGHT) != 0) {
            mirrorMode = 1;
        }
    }
    SetLeftRightKeysSwapped(mirrorMode);
    SetHeapGroupId(9);
    if (gRaceSetup->mMode != MODE_BATTLE) {
        if (gRaceSetup->mMode == MODE_WIFI) {
            sessionHeapCreated = FALSE;
            session = gWiFiSession;
            if (session != NULL) {
                if (session->mHeapCreated != FALSE) {
                    sessionHeapCreated = TRUE;
                }
            }
            if (sessionHeapCreated != FALSE) {
                StateMachine *stateMachine;
                session->mRaceSyncEnabled = TRUE;
                stateMachine = &gWiFiSession->mStateMachine;
                stateMachine->mNextState = 5;
                stateMachine->mNextStateRequested = 1;
            }
        }
    } else {
        if (gRaceSetup->mBattleKind == BATTLE_KIND_BALLOON) {
            StartMicInput(GetHeap(GetCurrentHeapCall()));
        }
    }
}

// In the staff roll it also sets a backup flag once and writes the save block.
void ReleaseRaceScene(void) {
    RaceSetup *raceSetup;
    WiFiSession *session;
    s32 flagIndex;
    BOOL sessionHeapCreated;
    if (gRaceSetup->mMode == MODE_WIFI) {
        sessionHeapCreated = FALSE;
        session = gWiFiSession;
        if (session != NULL) {
            if (session->mHeapCreated != FALSE) {
                sessionHeapCreated = TRUE;
            }
        }
        if (sessionHeapCreated != FALSE) {
            StateMachine *stateMachine;
            session->mRaceSyncEnabled = FALSE;
            stateMachine = &gWiFiSession->mStateMachine;
            stateMachine->mNextState = 4;
            stateMachine->mNextStateRequested = 1;
        }
    }
    raceSetup = gRaceSetup;
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
        if (IsBackupFlagSet(flagIndex) == 0) {
            SetBackupFlag(flagIndex);
            WriteBackupFirstBlockWrapper();
            WaitThreadFunctionsDone();
            if (gBackupAccess->mBackupEnabled != 0) {
                CARD_WaitBackupAsync();
            }
        }
    }
    StopMicInput();
    ClearChoisesSPointer();
    ReleaseRace();
    ReleaseRaceHud();
    ClearDispCapPointer();
    ClearRaceConnectionFlag();
    FreeOverlayExpHeap();
}

void AdvanceDispCapAndUploadRaceHud(void) {
    AdvanceDispCap(GetChoisesSPrevOpenDuringRace());
    RaceSceneAdvanceNop();
    UploadRaceHud();
}

// The award scene ends after 0x564 frames, or on a new key press once some Grand Prix record is filled.
u32 ShouldEndAwardRace(u32 sceneFrames) {
    if (sceneFrames > 0x564) {
        return 1;
    }
    if (AreBrightnessFadesClear() == 0) {
        return 0;
    }
    if (IsAnyGrandPrixRecordFilled() != 0) {
        InputSlotIndex slotIndex = UNK_02175628_INDEX_8;
        if ((u16) (gInputSlots[slotIndex].mPressedBits & PAD_KEY_A) != 0) {
            return 1;
        }
    }
    return 0;
}

// The staff roll can end early on input after 0xb4 frames when its flag for the mode is set.
u32 ShouldEndStaffRoll(u32 sceneFrames) {
    u32 result;
    s32 flagIndex = 0x18;
    if (gRaceSetup->mMode != MODE_GRAND_PRIX) {
        if (gRaceSetup->mMode == MODE_MISSION_RUN) {
            flagIndex = 0x1a;
        }
    } else {
        if (gRaceSetup->mCourseId == COURSE_ID_STAFFROLLTRUE) {
            flagIndex = 0x19;
        }
    }
    result = 0;
    if (IsBackupFlagSet(flagIndex) != 0 && sceneFrames > 0xb4) {
        InputSlotIndex slotIndex = UNK_02175628_INDEX_8;
        if ((u16) (gInputSlots[slotIndex].mBits & PAD_KEYS_NO_DIRECTION_OR_SHOULDER) != 0 ||
            IsSlot8PairPresentOrRecentlyLost() != 0) {
            result = 1;
        }
    }
    return result;
}

u32 RaceSceneGetCurrentMode(void) {
    return (gRaceSetup->mMode);
}

void SetPickedValue(u32 pickedValue) {
    gStartupWork->mPickedValue = pickedValue;
}

// Turns the value picked on the choice screen into the next scene and the settings that go with it.
void SetNextSceneFromPickedValue(SceneNumbers *sceneNumbers, u32 pickedValue) {
    s32 nextScene;
    gMenuShared->mMenuEntryKind = 0;
    nextScene = -1;
    switch (pickedValue) {
        case 10:
            SetupStaffRollRace(0);
            nextScene = 2;
            break;
        case 9:
            if (gRaceSetup->mMode != MODE_WIFI) {
                u32 connectionMode;
                u32 connectionActive;
                ConnectionWork *connectionWork;
                connectionActive = 0;
                connectionWork = gConnectionWork;
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
                    if (gStartupWork->mMultiSimple != 0) {
                        nextScene = 6;
                        gMenuShared->mWLMenuKind = 3;
                    } else {
                        nextScene = 1;
                    }
                    gMenuShared->mMenuEntryKind = 4;
                    gMenuShared->mRaceSetupRequested = 1;
                } else {
                    nextScene = 0;
                }
                if (gRaceSetup->mMode == MODE_TIME_ATTACK) {
                    TimeAttackNextSceneNop();
                }
            } else {
                nextScene = 0xc;
                gMenuShared->mWiFiMenuStartKind = 0;
            }
            break;
        case 1:
        case 3:
            nextScene = 2;
            gRaceSetup->mNextHeader.mRaceKind = RACE_KIND_NORMAL;
            break;
        case 8:
            nextScene = 2;
            gRaceSetup->mNextHeader.mRaceKind = nextScene;
            break;
        case 2:
            switch (gRaceSetup->mMode) {
                case MODE_GRAND_PRIX:
                    SetNextGrandPrixCourse();
                    nextScene = 2;
                    break;
                case MODE_VS:
                    if (AdvanceToNextCourseWrapper() != 0) {
                        if (gStartupWork->mMultiSimple == 0) {
                            nextScene = 2;
                        } else {
                            nextScene = 6;
                            gMenuShared->mWLMenuKind = 1;
                        }
                    } else {
                        if (gRaceSetup->mCourseListMode == 0) {
                            gMenuShared->mMenuEntryKind = 2;
                        }
                        if (gStartupWork->mMultiSimple == 0) {
                            nextScene = 1;
                        } else {
                            nextScene = 6;
                            gMenuShared->mWLMenuKind = 3;
                        }
                    }
                    break;
                case MODE_WIFI:
                    if (CopyCourseIdAndAdvanceCourseNumber() != FALSE) {
                        nextScene = 0xc;
                        gMenuShared->mWiFiMenuStartKind = 3;
                    } else {
                        nextScene = 0xa;
                        gMenuShared->mWiFiMenuStartKind = 2;
                    }
                    break;
                case MODE_BATTLE:
                    if (AdvanceToNextBattleCourse() != 0) {
                        if (gStartupWork->mMultiSimple == 0) {
                            nextScene = 2;
                        } else {
                            nextScene = 6;
                            gMenuShared->mWLMenuKind = 1;
                        }
                    } else {
                        if (gRaceSetup->mCourseListMode == 0) {
                            gMenuShared->mMenuEntryKind = 2;
                        }
                        if (gStartupWork->mMultiSimple == 0) {
                            nextScene = 1;
                        } else {
                            nextScene = 6;
                            gMenuShared->mWLMenuKind = 3;
                        }
                    }
                    break;
            }
            break;
        case 7:
            switch (gRaceSetup->mMode) {
                case MODE_GRAND_PRIX:
                    if (CopyEntryResultAndSetupAwardRace() != FALSE) {
                        nextScene = 2;
                    } else {
                        nextScene = 0xa;
                    }
                    break;
                case MODE_MISSION_RUN:
                    nextScene = 0;
                    break;
                case MODE_BATTLE:
                case MODE_VS:
                    if (gStartupWork->mMultiSimple != 0) {
                        nextScene = 6;
                        gMenuShared->mWLMenuKind = 2;
                    } else {
                        nextScene = 0xa;
                    }
                    break;
            }
            break;
        case 5:
            nextScene = 1;
            gMenuShared->mMenuEntryKind = nextScene;
            break;
        case 4:
            gMenuShared->mMenuEntryKind = 2;
            nextScene = 1;
            break;
        case 6:
            gMenuShared->mMenuEntryKind = 3;
            nextScene = 1;
            break;
    }
    if (nextScene != -1) {
        sceneNumbers->mNextScene = nextScene;
    }
}

u32 GetCurrentRaceKind(void) {
    return gRaceSetup->mRaceKind;
}

void SetDemoEndedByInput(u32 endedByInput) {
    if (endedByInput != 0) {
        gStartupWork->mDemoEndedByInput |= 1;
    } else {
        gStartupWork->mDemoEndedByInput &= ~1;
    }
}

u32 GetRaceSceneInputSlot(void) {
    return 0x8u;
}

u16 GetDownBits(u32 slotIndex, u32 mask) {
    u32 bits;
    bits = gInputSlots[slotIndex].mBits;
    return bits & mask;
}

u32 StartRaceSceneSound(u32 index) {
    return NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0u, index);
}

u32 RaceSceneSlotHasPairOrLost(u32 slotIndex) {
    u32 result;
    u32 briefNoPair;
    u16 hasPair;
    result = 1;
    briefNoPair = 0;
    hasPair = gInputSlots[slotIndex].mPair.mHasPair;
    if (hasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < 5) {
        briefNoPair = 1;
    }
    if (briefNoPair == 0 && hasPair == 0) {
        result = 0;
    }
    return result;
}

u32 IsCameraChainEnded(void) {
    return gRaceProgress->mCameraChainEnded;
}

u32 RaceSceneIsSlotPairNew(u32 slotIndex) {
    u32 result;
    u32 briefNoPair;
    result = 0;
    briefNoPair = 0;
    if (gInputSlots[slotIndex].mPair.mHasPair == 0 && gInputSlots[slotIndex].mPair.mNoPairCount < 5) {
        briefNoPair = 1;
    }
    if (briefNoPair == 0 && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 &&
        gInputSlots[slotIndex].mPair.mHasPair != 0) {
        result = 1;
    }
    return result;
}

void SetNextRaceKind(u32 raceKind) {
    gRaceSetup->mNextHeader.mRaceKind = raceKind;
}

u32 RaceSceneGetCurrentCourseId(void) {
    return (gRaceSetup->mCourseId);
}
