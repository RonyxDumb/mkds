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
#include "Main/Sound/sound_seq.h"
#include "Main/Kart/kart_name_tags.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Race/race_setup_input.h"
#include "Main/System/heap_call.h"
#include "Main/Scene/display_settings_descs.h"

SceneCallbacks g_Scene_Menu2 = {Scene_Menu2_Initialize,
                                            Scene_Menu2_Update,
                                            Scene_Menu2_Finalize,
                                            Scene_Menu2_VBlank,
                                            NULL,
                                            NULL,
                                            0xa,
                                            0xa,
                                            0};

void StateDualHandler_SetState(StateMachine *stateMachine, u16 state) {
    stateMachine->mStateFrames = 0;
    stateMachine->mNextStateRequested = 1;
    stateMachine->mState = state;
    stateMachine->mNextState = state;
}

void StateDualHandler_Execute(StateMachine *stateMachine) {
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

void Scene_Menu2_Initialize(void) {
    DisplaySettings *displaySettings;

    displaySettings = CreateDisplayConfig(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), gSecondMenuSceneDisplaySettingsDesc);
    DisplayEngineConfig_SetBg1Config(&displaySettings->mMainBgRecords, 0, 0, 0, 0, 4, 0, 0);
    SetGlobalDisplayConfig(displaySettings);
}

void Scene_Menu2_Finalize(void) {
    Scene_Menu2_FinalizeImpl();
}

void Scene_Menu2_VBlank(void) {}

void Scene_Menu2_Update(void) {}

s32 SceneFn_Menu2(void *sceneNumbers) {
    SceneCallbacks callbacks = g_Scene_Menu2;

    OnSceneLoop(sceneNumbers, &callbacks);
    return 0;
}

void InitializeGlobalCO(void *heap) {
    g_GlobalCO = Mem_AllocateHeap(heap, sizeof(RaceSetup));
    g_GlobalCO->mCourseList = Mem_AllocateHeap(heap, RACE_SETUP_COURSE_LIST_LENGTH * sizeof(*g_GlobalCO->mCourseList));
    InitializeGlobalRE(heap);
    InitializeGlobalLU(heap);
}

void MaybeSetRacerCount(s32 entryCount) {
    u8 teamCounts[2] = {0};
    s32 entryIndex;
    u8 humanAndPeerCount;
    u8 kartCount;

    humanAndPeerCount = 0;
    kartCount = 0;
    for (entryIndex = 0; entryIndex < entryCount; entryIndex++) {
        if (g_GlobalCO->mCurrentEntries[entryIndex].mPlayer.mKind != PLAYER_KIND_NONE) {
            if (g_GlobalCO->mCurrentEntries[entryIndex].mPlayer.mKind == PLAYER_KIND_HUMAN ||
                g_GlobalCO->mCurrentEntries[entryIndex].mPlayer.mKind == PLAYER_KIND_PEER) {
                humanAndPeerCount++;
            }
            kartCount++;
            if (g_GlobalCO->mUseTeams != 0) {
                teamCounts[g_GlobalCO->mCurrentEntries[entryIndex].mPlayer.mTeamIndex]++;
            }
        }
    }
    g_GlobalCO->mKartCount = kartCount;
    g_GlobalCO->mHumanAndPeerKartCount = humanAndPeerCount;
    for (entryIndex = 0; entryIndex < 2; entryIndex++) {
        g_GlobalCO->mTeamKartCounts[entryIndex] = teamCounts[entryIndex];
    }
}

void StructCO_ConfigureRacerDefault(int entryIndex, u32 characterIndex, u32 kartIndex, int playerKind, u32 teamIndex,
                      int listedCpuSlot) {
    g_GlobalCO->mNextEntries[entryIndex].mCharacterIndex = characterIndex;
    g_GlobalCO->mNextEntries[entryIndex].mPlayer.mKind = playerKind;
    g_GlobalCO->mNextEntries[entryIndex].mPlayer.mIndex = entryIndex;
    g_GlobalCO->mNextEntries[entryIndex].mKartIndex = kartIndex;
    g_GlobalCO->mNextEntries[entryIndex].mPlayer.mTeamIndex = teamIndex;
    g_GlobalCO->mNextEntries[entryIndex].mPlayer.mListedCpuSlot = listedCpuSlot;
    g_GlobalCO->mNextEntries[entryIndex].mPlayer.mGhostRecordIndex =
        playerKind == PLAYER_KIND_GHOST ? GHOST_RECORD_INDEX_COURSE : GHOST_RECORD_INDEX_NONE;
    g_GlobalCO->mNextEntries[entryIndex].mPlayer.mListedCpuFlags = 0;
    if (listedCpuSlot != 3) {
        g_GlobalCO->mNextEntries[entryIndex].mPlayer.mListedCpuFlags |= KART_ENTRY_LISTED_CPU_FLAG;
    }
}

s32 GetCourseIdFromInternalId(s32 courseId) {
    s32 rowIndex;
    s32 columnIndex;
    s8 courseIndex;

    courseIndex = -1;
    for (rowIndex = 0; rowIndex < 8; rowIndex++) {
        for (columnIndex = 0; columnIndex < 4; columnIndex++) {
            if (courseId == g_InternalCourseIdOrderedTable[rowIndex][columnIndex]) {
                courseIndex = columnIndex + rowIndex * 4;
                break;
            }
        }
    }
    return courseIndex;
}

u32 GetSomeInternalCourseId(u8 courseIndex) {
    return g_InternalCourseIdOrderedTable[(u32) courseIndex / 4][courseIndex % 4];
}

s32 GetCupForCourse(s32 courseId) {
    s32 cupIndex;
    s32 rowIndex;
    s32 columnIndex;

    cupIndex = 9;
    for (rowIndex = 0; rowIndex < 8; rowIndex++) {
        for (columnIndex = 0; columnIndex < 4; columnIndex++) {
            if (courseId == g_InternalCourseIdOrderedTable[rowIndex][columnIndex]) {
                cupIndex = rowIndex;
            }
        }
    }
    return cupIndex;
}
