#pragma once

#include "types.h"
#include "01/Menu/option_nickname_scenes.h"
#include "Main/Menu/data_02175000.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"

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
