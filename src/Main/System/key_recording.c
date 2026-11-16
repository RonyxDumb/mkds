#include "Main/System/key_recording.h"
#include "Main/System/scene_numbers.h"
#include "Main/System/wireless_vram_state.h"
#include "Main/Race/race_setup_input.h"

#include "Main/Scene/run_scene_connection.h"
#include "Main/Kart/kart_effect_param_tables.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "Main/System/input_slots.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Kart/kart_name_tags.h"
#include "01/Menu/emblem_cursor.h"
#include "Main/System/heap_call.h"
#include "arena_cache_init.h"

SceneCallbacks g_Scene_Emblem = {Scene_Emblem_Initialize,
                                        Scene_Emblem_Update,
                                        Scene_Emblem_Finalize,
                                        Scene_Emblem_VBlank,
                                        NULL,
                                        NULL,
                                        0xa,
                                        0xa,
                                        0};

void AppendKeysToKeyRecording(KeyRecording *keyRecording, u16 keys) {
    BOOL startsNewPair;
    u8 repeatCount;
    u8 *pair;
    u8 packedKeys;
    u16 pairIndex;
    s32 status;
    KeyRecordingBuffer *buffer;

    status = keyRecording->mStatus;
    if (status != KEY_RECORDING_RECORDING) {
        return;
    }
    buffer = keyRecording->mBuffer;
    pairIndex = keyRecording->mPairIndex;
    pair = &buffer->mPairs[pairIndex * 2];
    packedKeys = 0;
    packedKeys |= (keys & 1) ? 1 : 0;
    packedKeys |= (keys & 2) ? 2 : 0;
    packedKeys |= (keys & 0x100) ? 4 : 0;
    packedKeys |= (keys & 0x600) ? 8 : 0;
    packedKeys |= (keys & 0x10) ? 0x10 : 0;
    packedKeys |= (keys & 0x20) ? 0x20 : 0;
    packedKeys |= (keys & 0x80) ? 0x40 : 0;
    packedKeys |= (keys & 0x40) ? 0x80 : 0;
    repeatCount = pair[1];
    startsNewPair = FALSE;
    if (repeatCount != 0 && pair[0] != packedKeys) {
        startsNewPair = TRUE;
    } else if (repeatCount >= 0xff) {
        startsNewPair = TRUE;
    }
    if (startsNewPair != FALSE) {
        if (pairIndex >= 0x6e4) {
            if (status != KEY_RECORDING_RECORDING) {
                return;
            }
            buffer->mPairByteCount = (u32) pairIndex * 2;
            keyRecording->mStatus = KEY_RECORDING_FULL;
            DC_SomeClean(keyRecording->mBuffer, 0xdcc);
            return;
        }
        keyRecording->mPairIndex++;
        pair += 2;
        pair[1] = 0;
    }
    pair[0] = packedKeys;
    pair[1]++;
}

u16 ReadKeysFromKeyRecording(KeyRecording *keyRecording) {
    KeyRecordingBuffer *buffer;
    u8 *pair;
    u16 pairIndex;
    u16 keys;
    u8 packedKeys;

    if (keyRecording->mStatus != KEY_RECORDING_PLAYING) {
        return 0;
    }
    buffer = keyRecording->mBuffer;
    pairIndex = keyRecording->mPairIndex;
    if (pairIndex >= buffer->mPairByteCount) {
        keyRecording->mStatus = KEY_RECORDING_IDLE;
        return 0;
    }
    pair = &buffer->mPairs[pairIndex * 2];
    packedKeys = pair[0];
    keys = 0;
    keys |= (packedKeys & 1) ? 1 : 0;
    keys |= (packedKeys & 2) ? 2 : 0;
    keys |= (packedKeys & 4) ? 0x100 : 0;
    keys |= (packedKeys & 8) ? 0x600 : 0;
    keys |= (packedKeys & 0x10) ? 0x10 : 0;
    keys |= (packedKeys & 0x20) ? 0x20 : 0;
    keys |= (packedKeys & 0x80) ? 0x40 : 0;
    keys |= (packedKeys & 0x40) ? 0x80 : 0;
    keyRecording->mRepeatCount++;
    if (keyRecording->mRepeatCount >= pair[1]) {
        keyRecording->mPairIndex++;
        keyRecording->mRepeatCount = 0;
    }
    return keys;
}

BOOL IsKeyRecordingFull(KeyRecording *keyRecording) {
    return keyRecording->mStatus == KEY_RECORDING_FULL;
}

BOOL StructCYB_SomeFn_0(KeyRecording *keyRecording) {
    if (keyRecording->mStatus != KEY_RECORDING_PLAYING) {
        return FALSE;
    }
    return ((u32) keyRecording->mPairIndex << 1) > 0xd1b;
}

void Scene_Emblem_Initialize(void) {
    ExecutionContext_GetHeapHandle(GetActiveExecutionContext());
    MaybeInitializeSomeWirelessShit();
    MaybeResetInput();
    InitEmblemAndAdvanceKartList();
}

void Scene_Emblem_Finalize(void) {}

void Scene_Emblem_VBlank(void) {
    AdvanceEmblemDisplayWrapper();
}

void Scene_Emblem_Update(SceneNumbers *sceneNumbers) {
    s32 emblemDone;

    emblemDone = AdvanceEmblemAndCheckDone();
    if (sceneNumbers != NULL && emblemDone != 0) {
        switch (sceneNumbers->mPreviousScene) {
            case SCENE_OPTION:
                sceneNumbers->mNextScene = SCENE_OPTION;
                break;
            default:
                sceneNumbers->mNextScene = 0;
                break;
        }
    }
}

s32 SceneFn_Emblem(void *sceneNumbers) {
    SceneCallbacks emblemSceneCallbacks = g_Scene_Emblem;

    OnSceneLoop(sceneNumbers, &emblemSceneCallbacks);
    return 0;
}
