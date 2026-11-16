#pragma once

#include "types.h"
#include "Main/Scene/scene_display_archive_work.h"

typedef struct SceneNumbers SceneNumbers;

void InitializeGlobalPImpl(void);
void InitializeGlobalP(void *heap);
// Scene function of g_SceneFnTable[6] (scene 'WLMenu' in g_SceneArchiveNameTable): copies the callbacks and calls
// OnSceneLoop. Returns 0.
s32 SceneFn_WLMenu(SceneNumbers *sceneNumbers);
void Scene_WLMenu_Update(void *sceneNumbers);
void Scene_WLMenu_Vblank(void);
void Scene_WLMenu_Finalize(void);

extern SceneCallbacks g_Scene_WLMenu;
