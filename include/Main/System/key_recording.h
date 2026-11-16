#pragma once

#include "types.h"

typedef struct SceneNumbers SceneNumbers;

#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "Main/System/input_slots.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Scene/scene_display_archive_work.h"

// Scene function of gSceneFuncs[3] (scene 'Emblem' in gSceneNames): copies the callbacks and calls
// RunScene. Returns 0.
s32 RunEmblemScene(void *sceneNumbers);
void UpdateEmblemScene(SceneNumbers *sceneNumbers);
void WriteEmblemSceneRegistersCallback(void);
void EmblemSceneNop(void);
// Calls StopWvrAndWait, ResetInputSlots and InitEmblem through InitEmblemAndAdvanceKartList (InitEmblem also
// calls InitEmblemChoises).
void InitEmblemScene(void);
BOOL IsKeyRecordingPlaybackNearBufferEnd(KeyRecording *keyRecording);
BOOL IsKeyRecordingFull(KeyRecording *keyRecording);
u16 ReadKeysFromKeyRecording(KeyRecording *keyRecording);
void AppendKeysToKeyRecording(KeyRecording *keyRecording, u16 keys);

extern SceneCallbacks gEmblemSceneCallbacks;
