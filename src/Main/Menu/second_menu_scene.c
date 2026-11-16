#include "Main/Menu/second_menu_scene.h"

#include "Main/System/heap.h"
#include "Main/Scene/run_scene_connection.h"
#include "Main/Net/participant_kart_map.h"
#include "Main/Race/cup_records.h"
#include "Main/Kart/kart_scale_surface_tables.h"
#include "Main/Kart/kart_effect_param_tables.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "Main/Kart/kart_name_tags.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Race/race_setup_input.h"
#include "Main/System/heap_call.h"
#include "Main/Scene/display_settings_descs.h"

SceneCallbacks gSecondMenuSceneCallbacks = {InitSecondMenuScene,
                                            SecondMenuUpdateNop,
                                            SetNextRaceByModeWrapper,
                                            SecondMenuAfterUpdateNop,
                                            NULL,
                                            NULL,
                                            0xa,
                                            0xa,
                                            0};

void SetStateMachineState(StateMachine *stateMachine, u16 state) {
    stateMachine->mStateFrames = 0;
    stateMachine->mNextStateRequested = 1;
    stateMachine->mState = state;
    stateMachine->mNextState = state;
}

void AdvanceStateMachine(StateMachine *stateMachine) {
    const StateCallbacks *callbacks;

    if (stateMachine->mNextStateRequested != 0) {
        stateMachine->mStateFrames = 0;
        stateMachine->mNextStateRequested = 0;
        stateMachine->mState = stateMachine->mNextState;
        stateMachine->mNextState = 0;
        callbacks = &stateMachine->mStateTable[stateMachine->mState];
        if (callbacks->mEnter != NULL) {
            callbacks->mEnter(stateMachine->mObject);
        }
    } else {
        callbacks = &stateMachine->mStateTable[stateMachine->mState];
    }
    if (callbacks->mUpdate != NULL) {
        callbacks->mUpdate(stateMachine->mObject);
    }
    stateMachine->mStateFrames++;
}

void InitSecondMenuScene(void) {
    DisplaySettings *displaySettings;

    displaySettings = CreateDisplaySettings(GetHeap(GetCurrentHeapCall()), gSecondMenuSceneDisplaySettingsDesc);
    SetBg1Record(&displaySettings->mMainBgRecords, 0, 0, 0, 0, 4, 0, 0);
    InitDisplayFromSettings(displaySettings);
}

void SetNextRaceByModeWrapper(void) {
    SetNextRaceByMode();
}

void SecondMenuAfterUpdateNop(void) {}

void SecondMenuUpdateNop(void) {}

s32 RunSecondMenuScene(void *sceneNumbers) {
    SceneCallbacks callbacks = gSecondMenuSceneCallbacks;

    RunScene(sceneNumbers, &callbacks);
    return 0;
}

void CreateRaceSetupObjects(void *heap) {
    gRaceSetup = HeapAlloc(heap, sizeof(RaceSetup));
    gRaceSetup->mCourseList = HeapAlloc(heap, RACE_SETUP_COURSE_LIST_LENGTH * sizeof(*gRaceSetup->mCourseList));
    CreateParticipantKartMap(heap);
    CreateCupRecords(heap);
}

void RefreshRaceSetupKartCounts(s32 entryCount) {
    u8 teamCounts[2] = {0};
    s32 entryIndex;
    u8 humanAndPeerCount;
    u8 kartCount;

    humanAndPeerCount = 0;
    kartCount = 0;
    for (entryIndex = 0; entryIndex < entryCount; entryIndex++) {
        if (gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mKind != PLAYER_KIND_NONE) {
            if (gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mKind == PLAYER_KIND_HUMAN ||
                gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mKind == PLAYER_KIND_PEER) {
                humanAndPeerCount++;
            }
            kartCount++;
            if (gRaceSetup->mUseTeams != 0) {
                teamCounts[gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mTeamIndex]++;
            }
        }
    }
    gRaceSetup->mKartCount = kartCount;
    gRaceSetup->mHumanAndPeerKartCount = humanAndPeerCount;
    for (entryIndex = 0; entryIndex < 2; entryIndex++) {
        gRaceSetup->mTeamKartCounts[entryIndex] = teamCounts[entryIndex];
    }
}

void SetNextRaceEntry(int entryIndex, u32 characterIndex, u32 kartIndex, int playerKind, u32 teamIndex,
                      int listedCpuSlot) {
    gRaceSetup->mNextEntries[entryIndex].mCharacterIndex = characterIndex;
    gRaceSetup->mNextEntries[entryIndex].mPlayer.mKind = playerKind;
    gRaceSetup->mNextEntries[entryIndex].mPlayer.mIndex = entryIndex;
    gRaceSetup->mNextEntries[entryIndex].mKartIndex = kartIndex;
    gRaceSetup->mNextEntries[entryIndex].mPlayer.mTeamIndex = teamIndex;
    gRaceSetup->mNextEntries[entryIndex].mPlayer.mListedCpuSlot = listedCpuSlot;
    gRaceSetup->mNextEntries[entryIndex].mPlayer.mGhostRecordIndex =
        playerKind == PLAYER_KIND_GHOST ? GHOST_RECORD_INDEX_COURSE : GHOST_RECORD_INDEX_NONE;
    gRaceSetup->mNextEntries[entryIndex].mPlayer.mListedCpuFlags = 0;
    if (listedCpuSlot != 3) {
        gRaceSetup->mNextEntries[entryIndex].mPlayer.mListedCpuFlags |= KART_ENTRY_LISTED_CPU_FLAG;
    }
}

s32 FindCupCourseIndex(s32 courseId) {
    s32 rowIndex;
    s32 columnIndex;
    s8 courseIndex;

    courseIndex = -1;
    for (rowIndex = 0; rowIndex < 8; rowIndex++) {
        for (columnIndex = 0; columnIndex < 4; columnIndex++) {
            if (courseId == gCupCourseIdTable[rowIndex][columnIndex]) {
                courseIndex = columnIndex + rowIndex * 4;
                break;
            }
        }
    }
    return courseIndex;
}

u32 GetCupCourseIdAtIndex(u8 courseIndex) {
    return gCupCourseIdTable[(u32) courseIndex / 4][courseIndex % 4];
}

s32 FindCupIndexOfCourse(s32 courseId) {
    s32 cupIndex;
    s32 rowIndex;
    s32 columnIndex;

    cupIndex = 9;
    for (rowIndex = 0; rowIndex < 8; rowIndex++) {
        for (columnIndex = 0; columnIndex < 4; columnIndex++) {
            if (courseId == gCupCourseIdTable[rowIndex][columnIndex]) {
                cupIndex = rowIndex;
            }
        }
    }
    return cupIndex;
}
