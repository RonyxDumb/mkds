#pragma once

#include "types.h"
#include "Main/Scene/scene_display_archive_work.h" // SceneCallbacks
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"

// The scene numbers: the previous scene, the scene being run and the next scene to run (-1 until set).
typedef struct SceneNumbers {
    /* 00 */ s16 mPreviousScene;
    // Number of the scene being run: the index of gSceneFuncs and of the scene-name table
    // gSceneNames.
    /* 02 */ s16 mScene;
    // Scene to run next, -1 until set. Written by the update slots (also through the other typedef
    // views and as a[2]) and by RunScene when the scene ends;
    // read by RunScene and RunScenes.
    /* 04 */ s16 mNextScene;
} SceneNumbers;

// Runs one scene to its end: loads the scene's archives from a.mScene (LoadArchiveSlotsForScene), generic
// set-up, mInit once, a wait loop without slots, the update loop (mUpdate, then slot 0x0c, every
// frame) until a slot sets a.mNextScene or GetVolatileHalfwordIndex39 is non-zero, the fade-out loop, a wait
// loop, mRelease once, generic tear-down.
void RunScene(SceneNumbers *sceneNumbers, const SceneCallbacks *callbacks);
