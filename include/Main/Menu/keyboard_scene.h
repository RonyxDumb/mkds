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
#include "Main/Sound/sound_seq.h"
#include "Main/Menu/menu_screens_work.h"

typedef struct RaceHudOamBuffer RaceHudOamBuffer;

RaceHudOamBuffer *GetKeyboardSecondBuffer(void);
RaceHudOamBuffer *GetKeyboardOam_from_thumb(void);

extern SceneCallbacks g_Scene_Keyboard;

// Scene function of g_SceneFnTable[14] (scene 'Keyboard' in g_SceneArchiveNameTable): copies the callbacks and
// calls OnSceneLoop. Returns 0.
s32 SceneFn_Keyboard_from_thumb(void *sceneNumbers);
void Scene_Keyboard_Update_from_thumb(s16 *sceneNumbers);
void Scene_Keyboard_VBlank_from_thumb(void);

// Slot mRelease: calls the state's undo functions and clears the globals; frees nothing itself (the
// scene heap goes with the scene).
void Scene_Keyboard_Finalize_from_thumb(void);

void Scene_Keyboard_Initialize_from_thumb(s16 *sceneNumbers);

extern struct KeyboardScene *g_KeyboardOam;
