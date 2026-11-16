#pragma once

#include "types.h"
#include "Main/Scene/scene_display_archive_work.h" // SceneCallbacks
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"

// The scene numbers: the previous scene, the scene being run and the next scene to run (-1 until set).
typedef struct SceneNumbers {
    /* 00 */ s16 mPreviousScene;
    // Number of the scene being run: the index of gSceneFuncs and of the scene-name table
    // gSceneNames.
    /* 02 */ s16 mScene;
    // Scene to run next, -1 until set. Written by the scene update slots and by RunScene when the scene ends; read by
    // RunScene and RunScenes.
    /* 04 */ s16 mNextScene;
} SceneNumbers;

// Runs one scene to its end: loads the archives of sceneNumbers->mScene (LoadArchiveSlotsForScene), generic set-up,
// mInit once, a loop without slots until FinishDataSharingSync returns 1, the update loop (mUpdate, then mPostUpdate,
// every pass) until sceneNumbers->mNextScene is set or the held-key value of GetVolatileHalfwordIndex39 is non-zero
// (read as 0 when IsVolatileHalfwordIndex39Ignored), the fade-out loop (mUpdate and mPostUpdate with sceneNumbers
// NULL), a loop that ends the connection (only when leaving for scene 0 or on that exit value), mRelease once, generic
// tear-down. A disconnect message in either loop jumps straight to the end step.
void RunScene(SceneNumbers *sceneNumbers, const SceneCallbacks *callbacks);
