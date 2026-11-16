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

// Scene function of g_SceneFnTable[3] (scene 'Emblem' in g_SceneArchiveNameTable): copies the callbacks and calls
// OnSceneLoop. Returns 0.
s32 SceneFn_Emblem(void *sceneNumbers);
void Scene_Emblem_Update(SceneNumbers *sceneNumbers);
void Scene_Emblem_VBlank(void);
void Scene_Emblem_Finalize(void);
// Calls MaybeInitializeSomeWirelessShit, MaybeResetInput and InitEmblem through InitEmblemAndAdvanceKartList (InitEmblem also
// calls InitEmblemChoises).
void Scene_Emblem_Initialize(void);
BOOL StructCYB_SomeFn_0(KeyRecording *keyRecording);
BOOL IsKeyRecordingFull(KeyRecording *keyRecording);
u16 ReadKeysFromKeyRecording(KeyRecording *keyRecording);
void AppendKeysToKeyRecording(KeyRecording *keyRecording, u16 keys);

extern SceneCallbacks g_Scene_Emblem;
