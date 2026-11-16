#pragma once

#include "types.h"
#include "01/code_0219e824.h"
#include "Main/Unknown/unk_02175000.h"

extern SceneCallbacks nicknameEditor_vtable;

// Scene function of scproc_sSceneTable[14] (scene 'Keyboard' in sSceneDefs): copies the callbacks and
// calls scene_runScene. Returns 0.
s32 keyboard_run(void *sceneNumbers);
void nicknameEditor_onDraw(s16 *sceneNumbers);
void nicknameEditor_afterDraw(void);
