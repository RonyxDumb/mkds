#pragma once

#include "types.h"
#include "01/Menu/option_nickname_scenes.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "Main/Menu/menu_screens_work.h"

typedef struct RaceHudOamBuffer RaceHudOamBuffer;

RaceHudOamBuffer *GetKeyboardSecondBuffer(void);
RaceHudOamBuffer *GetKeyboardFirstBuffer(void);

extern SceneCallbacks gKeyboardSceneCallbacks;

// Scene function of gSceneFuncs[14] (scene 'Keyboard' in gSceneNames): copies the callbacks and
// calls RunScene. Returns 0.
s32 RunKeyboardScene(void *sceneNumbers);
void UpdateKeyboardScene(s16 *sceneNumbers);
void WriteKeyboardSceneRegistersCallback(void);

// Slot mRelease: calls the state's undo functions and clears the globals; frees nothing itself (the
// scene heap goes with the scene).
void ReleaseKeyboardScene(void);

void InitKeyboardScene(s16 *sceneNumbers);

extern struct KeyboardScene *gKeyboardScene;
