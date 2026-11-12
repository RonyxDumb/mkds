#pragma once

#include "types.h"
#include "01/Menu/option_nickname_scenes.h"
#include "Main/Unknown/unk_02175000.h"

extern SceneCallbacks gKeyboardSceneCallbacks;

// Scene function of gSceneFuncs[14] (scene 'Keyboard' in gSceneNames): copies the callbacks and
// calls RunScene. Returns 0.
s32 RunKeyboardScene(void *sceneNumbers);
void UpdateKeyboardScene(s16 *sceneNumbers);
void WriteKeyboardSceneRegistersCallback(void);
